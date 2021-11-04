#include <UnionAfx.h>

namespace SystemPack
{
	void CPatchFunction::PushParameter(CPatchType* sym)
	{
		sym->AddRef();
		arrParameters.Insert(sym);
	}

	void CPatchFunction::CreateParameters(const CString& line)
	{
		if( line.First() != sBrackets_Round[0][0] || line.Last() != sBrackets_Round[1][0] )
		{
			ASSERT_PATCH_ERROR( "Ожидаются параметры функции" );
		}
		CString sNormal = line.Copy( 1, line.Length() - 2 );

		if( sNormal.Shrink().IsEmpty() )
		{
			return;
		}

		CString sCurrentParm;
		uint32 ulLastIndex = 0;
		for (uint32 i = 1, parm_index = 0;; i++)
		{
			CString sWord = sNormal.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 1, &ulLastIndex );
			ulLastIndex += sWord.Length();
			
			if( sWord.IsEmpty() || sWord == "," )
			{
				parm_index++;

				CPatchStack* pStack  = CPatchStack::CreateStack( sCurrentParm );
				CPatchType*	 pSymbol = dynamic_cast<CPatchType*>( pStack->Execute() );

				if( !pSymbol, A i + "-й аргумент функции не представляет ни один тип" )

				pSymbol->AddRef();
				arrParameters.Insert( pSymbol );
				pStack->Destroy();

				if( sWord.IsEmpty() )
				{
					return;
				}
				sCurrentParm.Clear();
			}
			else
			{
				sCurrentParm += sWord + " ";
			}
		}
	}

	CPatchFunction::~CPatchFunction()
	{
		for (uint32 i = 0; i < arrParameters.GetNum(); i++)
		{
			arrParameters[i]->Release();
		}
		arrParameters.Clear();
	}
}