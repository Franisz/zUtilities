#include <UnionAfx.h>




namespace SystemPack
{
	CString		CPatchRegion::sCurrentPatch = "Global";
	uint32		CPatchRegion::ulIterator = 0;
	uint32		CPatchRegion::ulEngineOffset = 0;
	CDocument*	CPatchRegion::pCurrentRegionData = Null;

	CString CPatchRegion::GetLastInfo()
	{
		if( pCurrentRegionData )
			return CString::Combine("Region: %s\nLine: %i%r\"%s\"", 
				sCurrentPatch, 
				ulIterator + ulEngineOffset, 
				(*pCurrentRegionData)[ulIterator].GetData());

		return CString::Combine("Region: %s\nLine: %i", sCurrentPatch, ulIterator + ulEngineOffset);
	}

	CPatchRegion* CPatchRegion::DefineBlock (CDocument& fileData, const uint32& hash)
	{
		//REPORT( ".\tExtracting patch data for current engine version..." );

		if( !fileData.GetNum() )
		{
			return Null;
		}
		CPatchRegion* block = Null;
		CLine* line = &fileData[0];
		while( line )
		{
			CString& lineData = line->GetData();

			if( lineData.GetWord(sDefaultSpace) == sEngineBlock[0] )
			{
				CString sHash = lineData.GetWord(sDefaultSpace, 2).GetPattern( sBrackets_Square[0], sBrackets_Square[1] ).Shrink();
				if( !sHash.IsEmpty() && sHash == CString::Hex32(hash) )
				{
					ulEngineOffset = fileData.GetLineIndex( *line ) + 1;
					//REPORT( ".\tBlock " + sHash + " found. Building information..." );

					block = new CPatchRegion;
					while( line )
					{
						block->sRegionData.InsertLines( line->GetData() );
						if( line->GetData().GetWord(sDefaultSpace) == sEngineBlock[1] )
						{
							REPORT_SUCCESS( ".\tBuilding is done." );

							pCurrentRegionData = &block->sRegionData;
							return block;
						}
						line = line->GetNext();
					}
					ASSERT_PATCH_ERROR( "�� ������ ����� ����� '#engine " + sHash + "'" );
				}
				else
				{
					//REPORT_WARN( ".\tFound other engine block " + sHash );

					while( line )
					{
						if( line->GetData().GetWord( sDefaultSpace ) == sEngineBlock[1] )
						{
							break;
						}
						line = line->GetNext();
					}
				}
			}
			line = line->GetNext();
		}
		//REPORT_ERROR( ".\tBlock " + CString::Hex32(hash) + " not found :(" ) << endl;

		return Null;
	}

	inline bool32 IsNotNumber (const CString& line)
	{
		CString sWord = line[0];
		if( sWord.MatchesMask( sResource_Number ))
		{
			return False;
		}
		return line.MatchesMask( sResource_Local );
	}

	void CPatchRegion::ExecuteRegion ()
	{
		for (ulIterator = 0; ulIterator < sRegionData.GetNum(); ulIterator++)
		{
			CString& sLine = sRegionData[ulIterator];
			
			if( sLine.GetWord( sDefaultSpace ) == sPatchBlock[0])
			{
				CString sPatchName = sLine.GetSymbolEx( Null, 0, &arrBrackets[1], 1);
				CString sName	   = sPatchName.IsEmpty() ? "[Unnamed]" : sPatchName.Shrink();

				//REPORT( ".\tExecuting " + sName + " patch..." );
				sCurrentPatch = sName;

				ExecuteOnLine( ++ulIterator );
			}
		}
		pCurrentRegionData = Null;
	}

	uint32 CPatchRegion::ExecuteOnLine (uint32& iterator)
	{
		// ��������� ������� � ����������. �� ��������� ��� ������ �����
		CArray<CPatchSymbol*> arrSymbols;

		for (; iterator < sRegionData.GetNum(); iterator++)
		{
			//
			// ����� �� ������
			//
			CString& sLineData = sRegionData[iterator];
			if( sLineData.Shrink() == sPatchBlock[1] )
			{
				break;
			}
			if( sLineData.IsEmpty() )
			{
				continue;
			}
			//REPORT( ".\t\t" + sRegionData[i] );

			//
			//	���� ���������� ������ ������ ������ - �������� ����������, ���������� ������� ������ � ��
			//
			CString sKeyWord = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 1 );

			if( TSymBuilder::GetSymbolType( sKeyWord ) == "Type" )
			{
				// ���������� ������� �� 2 ���� - ������� � ������
				CString sKeyType = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 2 );

				if( sKeyType == sOperators[18] ) // @ ������
				{
					// ��� ����������. ������ ���� �� ����� � ���������� �� � �����
					CString sKeyName = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 3 );

					// ������������� ���������� ����� ������� �� ����������������, � ������������� �����
					CPatchInteger* pAddress = dynamic_cast<CPatchInteger*>( CPatchType::GetVariable( sKeyName ));
					if( IsNotNumber(sKeyName) && !pAddress )
					{
						// �� ���� ������ ������ �������� ��� �����������. ��������� ������� ����������
						CString sValue = sLineData.GetPattern( sOperators[0], "" );
						ASSERT_PATCH( !sValue.IsEmpty(), "C���� ������ ���� ����������" );

						CPatchStack*	pStack    = CPatchStack::CreateStack( sValue );
						CPatchSymbol*	pSymbol   = pStack->Execute();
						CPatchInteger*  pInteger  = dynamic_cast<CPatchInteger*>( pSymbol );
						//if( pInteger && !pAddress )
						{
							TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( sKeyWord );
							ASSERT_PATCH( pBuilder, "�� ������ ������� � ���� '" + sKeyWord + "'" );

							CPatchType* pVariable = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
							ASSERT_PATCH( pVariable, "���������� ������� ������. '" + sKeyWord + "' �� �������� �����" );

							CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>( pSymbol );
							if( pOperator )
							{
								CString sINI = pOperator->GetOperator();
								uint32 ulSep = sINI.HasWord(":");
								if( ulSep == 1 || ulSep == 2 )
								{
									pVariable->Init();
									pVariable->SetOption( sINI );
									pVariable->ReadOption();
								}
							}
							else if( pInteger )
							{
								pVariable->Init( pInteger->GetValue() );
							}
							else
								ASSERT_PATCH( pSymbol, "����������� ������ ������ ���� ����� INT ��� ��������� ������������" );

							pVariable->SetObjectName( sKeyName );
							arrSymbols.Insert( pVariable );
							pStack->Destroy();
							continue;
						}
						//else if( pInteger )
						//	ASSERT_PATCH_ERROR( "��������������� '" + sKeyName + "'" );
					}
					else if( pAddress )
						REPORT_WARN( "�������� ��������������� line:" + A (iterator + ulEngineOffset) );
				}
				else // �������
				{
					CString& sKeyName = sKeyType;
					if( IsNotNumber(sKeyName) )
					{
						TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( sKeyWord );
						ASSERT_PATCH( pBuilder, "�� ������ ������� � ���� '" + sKeyWord + "'" );

						CPatchType* pVariable = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
						ASSERT_PATCH( pVariable, "���������� ������� ������. '" + sKeyWord + "' �� �������� �����" );

						pVariable->Init();
						pVariable->SetObjectName( sKeyName );
						arrSymbols.Insert( pVariable );

						CString sValue = sLineData.GetPattern( sOperators[0], "" );
						if( !sValue.IsEmpty() )
						{
							CPatchStack*  pStack  = CPatchStack::CreateStack( sValue );
							CPatchSymbol* pSymbol = pStack->Execute();
							CPatchType*	  pType	  = dynamic_cast<CPatchType*>( pSymbol );
							ASSERT_PATCH( pType, "���������� ���������� ����������. '" + sKeyWord + "' �� �������� �����" );

							(*pVariable) = pType;
							pStack->Destroy();
						}
						continue;
					}
				}
			}

			//
			//	�������� ����
			//
			static bool32 bConditions = 0;
			if( sKeyWord == "IF" )
			{
				bConditions++;

				CString sCond = sLineData.Copy( sKeyWord.Length(), sLineData.Length() - sKeyWord.Length() );
				CPatchStack* pStack = CPatchStack::CreateStack( sCond );
				CPatchType*  pType  = dynamic_cast<CPatchType*>( pStack->Execute() );
				CPatchBool	 mBool;
				mBool.Init();
				ASSERT( mBool = pType , "���������� �������� ��������� '" + sCond + "' � BOOL");
				pStack->Destroy();

				bool32 bCond = mBool.GetValue();
				if( bCond )
				{
					ExecuteOnLine( ++iterator );
					//Say::Box("##1");
					bConditions--;
					continue;
				}
				else
				{
					for (iterator += 1; iterator < sRegionData.GetNum(); iterator++)
					{
						CString& sPostWord = sRegionData[iterator].GetData().GetWord( sDefaultSpace );
						if( sPostWord == "ELSE" )
						{
							ExecuteOnLine( ++iterator );
							bConditions--;
							break;
						}
						else if( sPostWord == "END" )
						{
							break;
						}
					}
					//Say::Box("##2");
					//bConditions--;
					continue;
				}
			}

			if( sKeyWord == "END" )
			{
				ASSERT_PATCH( bConditions > 0, "��������� 'END' �� ������� ��������������� ��������� 'IF'" + A bConditions );
				break;
			}

			if( sKeyWord == "ELSE" )
			{
				ASSERT_PATCH( bConditions > 0, "��������� 'ELSE' �� ������� ��������������� ��������� 'IF'" );
				for (iterator += 1; iterator < sRegionData.GetNum(); iterator++)
				{
					CString& sPostWord = sRegionData[iterator].GetData().GetWord( sDefaultSpace );
					if( sPostWord == "END" )
						break;
				}
				break;
			}

			//
			//	������ ���������� �����
			//
			CPatchStack* pStack  = CPatchStack::CreateStack( sLineData );
			pStack->Execute();
			pStack->Destroy();
		}

		if( !sCurrentPatch.CompareI( "[GLOBAL DATA]" ))
		{
			for (uint32 i = 0; i < arrSymbols.GetNum(); i++)
			{
				arrSymbols[i]->Release();
			}
			arrSymbols.Clear();
		}
		return iterator;
	}

	CPatchRegion::~CPatchRegion()
	{
		//cmd << "before #1" << endl;
		//sRegionData.Clear();
		//cmd << "after #1" << endl;
	}
}
