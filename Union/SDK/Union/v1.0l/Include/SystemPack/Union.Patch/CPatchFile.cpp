#include <UnionAfx.h>

namespace SystemPack
{
	CPatchFile::CPatchFile (const CString& fileName)
	{
		REPORT( "Loading file '" + fileName + "'" );

		sFileName = fileName;
		CString sData;
		sData.ReadFromVdf( fileName, VDF_PHYSICAL | VDF_VIRTUAL | VDF_PHYSICALFIRST);

		if( sData.IsEmpty() )
		{
			REPORT_ERROR( ".\tFile is empty!" );
			return;
		}

		REPORT( ".\tData parsing..." );

		uint32	ulIndex  = 0;
		CString	sComment = NullStr;
		do
		{
			static const uint32 ulComLeftLen  = sBrackets_Comment[0].Length();
			static const uint32 ulComRightLen = sBrackets_Comment[1].Length();

			sComment = sData.GetPatternEx( sBrackets_Comment[0], sBrackets_Comment[1], 1, ulIndex, &ulIndex );
			if( ulIndex == Invalid )
			{
				break;
			}
			CString sLines;
			for (uint32 i = ulIndex; i < ulIndex + sComment.Length(); i++)
			{
				if( sData[i] == '\n' )
					sLines += '\n';
			}
			sData.Cut( ulIndex -= ulComLeftLen, sComment.Length() + ulComLeftLen + ulComRightLen );
			sData.Put( sLines, ulIndex );
		}
		while( !sComment.IsEmpty() );
		
		sFileData = sData;
		for (uint32 i = 0; i < sFileData.GetNum(); i++)
		{
			if( sFileData[i].GetData().HasWord( "//" ))
			{
				sFileData[i].GetData() = sFileData[i].GetData().GetPattern( "", "//" );
			}
		}
		REPORT_SUCCESS( ".\tLoading is done." );
	}

	CPatchFile* CPatchFile::LoadFile (const CString& fileName)
	{
		return new CPatchFile( fileName );
	}

	CPatchRegion* CPatchFile::CreateEngineBlock (const uint32& hash)
	{
		if( !sFileData.GetNum() )
		{
			return Null;
		}
		return CPatchRegion::DefineBlock( sFileData, hash );
	}

	void CPatchFile::CloseFile()
	{
		if( sFileName.GetWord("\\", -1) == "Union.patch" )
			return;

		CArray<CPatchType*>& arrVariables = CPatchType::arrVariables;
		while( arrVariables.GetNum() )
		{
			arrVariables[0]->Release();
		}
	}
}










namespace SystemPack
{
	CArray<CPatch*> CPatch::arrPatches;

	CPatch::CPatch(const CString& name)
	{
		sName = name;
		if( name.GetWord("\\", -1) == "Union.patch" )
			arrPatches.InsertFront( this );
		else
			arrPatches.Insert( this );
	}

	void CPatch::Execute()
	{
		CPatchFile* pFile = CPatchFile::LoadFile( sName );
		CPatchRegion* pRegion = pFile->CreateEngineBlock( Union.GetGothicHash() );
		if( pRegion )
		{
			pRegion->ExecuteRegion();
			pFile->CloseFile();
			delete pRegion;
		}
		delete pFile;
	}

	void CPatch::ExecuteAll()
	{
		// new SystemPack::CPatch( "System\\patchExample.patch" );
		for (uint32 i = 0; i < arrPatches.GetNum(); i++)
		{
			arrPatches[i]->Execute();
			delete arrPatches[i];
		}
		arrPatches.Clear();

		// удаляем остатки переменных
		CArray<CPatchType*>& arrVariables = CPatchType::arrVariables;
		while( arrVariables.GetNum() )
			arrVariables[0]->Release();
	}

	bool32 CPatch::HasPatch(const char* fileName)
	{
		for (uint32 i = 0; i < arrPatches.GetNum(); i++)
		{
			if( arrPatches[i]->sName == fileName)
				return True;
		}
		return False;
	}
}








extern "C"
{
	ASTAPI void InitPatch( const char* fileName )
	{
		if( !SystemPack::CPatch::HasPatch( fileName ))
		{
			new SystemPack::CPatch( fileName );
		}
	}
}