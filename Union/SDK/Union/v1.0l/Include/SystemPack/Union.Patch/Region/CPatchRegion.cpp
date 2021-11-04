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
					ASSERT_PATCH_ERROR( "Не найден конец блока '#engine " + sHash + "'" );
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
		// локальные символы и переменные. не удаляются при глобал блоке
		CArray<CPatchSymbol*> arrSymbols;

		for (; iterator < sRegionData.GetNum(); iterator++)
		{
			//
			// бряки на строки
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
			//	Ключ определяет способ чтения строки - создание переменной, выполнение уловных блоков и пр
			//
			CString sKeyWord = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 1 );

			if( TSymBuilder::GetSymbolType( sKeyWord ) == "Type" )
			{
				// переменная делится на 2 типа - простая и ссылка
				CString sKeyType = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 2 );

				if( sKeyType == sOperators[18] ) // @ ссылка
				{
					// имя переменной. должно быть НЕ число и начинаться НЕ с цифры
					CString sKeyName = sLineData.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 3 );

					// целочисленную переменную будем считать не переопределением, а определителем стека
					CPatchInteger* pAddress = dynamic_cast<CPatchInteger*>( CPatchType::GetVariable( sKeyName ));
					if( IsNotNumber(sKeyName) && !pAddress )
					{
						// ни одну ссылку нельзя объявить без определения. проверяем наличие присвоения
						CString sValue = sLineData.GetPattern( sOperators[0], "" );
						ASSERT_PATCH( !sValue.IsEmpty(), "Cылка должна быть определена" );

						CPatchStack*	pStack    = CPatchStack::CreateStack( sValue );
						CPatchSymbol*	pSymbol   = pStack->Execute();
						CPatchInteger*  pInteger  = dynamic_cast<CPatchInteger*>( pSymbol );
						//if( pInteger && !pAddress )
						{
							TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( sKeyWord );
							ASSERT_PATCH( pBuilder, "Не найден синоним к типу '" + sKeyWord + "'" );

							CPatchType* pVariable = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
							ASSERT_PATCH( pVariable, "Невозможно создать ссылку. '" + sKeyWord + "' не является типом" );

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
								ASSERT_PATCH( pSymbol, "Определение ссылки должно быть явным INT или значением конфигурации" );

							pVariable->SetObjectName( sKeyName );
							arrSymbols.Insert( pVariable );
							pStack->Destroy();
							continue;
						}
						//else if( pInteger )
						//	ASSERT_PATCH_ERROR( "Переопределение '" + sKeyName + "'" );
					}
					else if( pAddress )
						REPORT_WARN( "Возможно переопределение line:" + A (iterator + ulEngineOffset) );
				}
				else // простая
				{
					CString& sKeyName = sKeyType;
					if( IsNotNumber(sKeyName) )
					{
						TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( sKeyWord );
						ASSERT_PATCH( pBuilder, "Не найден синоним к типу '" + sKeyWord + "'" );

						CPatchType* pVariable = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
						ASSERT_PATCH( pVariable, "Невозможно создать ссылку. '" + sKeyWord + "' не является типом" );

						pVariable->Init();
						pVariable->SetObjectName( sKeyName );
						arrSymbols.Insert( pVariable );

						CString sValue = sLineData.GetPattern( sOperators[0], "" );
						if( !sValue.IsEmpty() )
						{
							CPatchStack*  pStack  = CPatchStack::CreateStack( sValue );
							CPatchSymbol* pSymbol = pStack->Execute();
							CPatchType*	  pType	  = dynamic_cast<CPatchType*>( pSymbol );
							ASSERT_PATCH( pType, "Невозможно определить переменную. '" + sKeyWord + "' не является типом" );

							(*pVariable) = pType;
							pStack->Destroy();
						}
						continue;
					}
				}
			}

			//
			//	Условный блок
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
				ASSERT( mBool = pType , "Невозможно привести выражение '" + sCond + "' к BOOL");
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
				ASSERT_PATCH( bConditions > 0, "Обнаружен 'END' не имеющий предшествующего оператора 'IF'" + A bConditions );
				break;
			}

			if( sKeyWord == "ELSE" )
			{
				ASSERT_PATCH( bConditions > 0, "Обнаружен 'ELSE' не имеющий предшествующего оператора 'IF'" );
				for (iterator += 1; iterator < sRegionData.GetNum(); iterator++)
				{
					CString& sPostWord = sRegionData[iterator].GetData().GetWord( sDefaultSpace );
					if( sPostWord == "END" )
						break;
				}
				break;
			}

			//
			//	Чистое выполнение стека
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
