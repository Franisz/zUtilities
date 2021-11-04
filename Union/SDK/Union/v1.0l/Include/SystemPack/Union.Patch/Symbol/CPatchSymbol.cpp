#include <UnionAfx.h>

namespace SystemPack
{
	CPatchSymbol::CPatchSymbol()
	{
		ulRef = 1;
	}

	CPatchSymbol* CPatchSymbol::CreateSymbol(const CString& str)
	{
		
		//
		//	Поиск переменной
		//
		for( uint32 i = 0; i < CPatchType::arrVariables.GetNum(); i++ )
		{
			if( CPatchType::arrVariables[i]->sObjectName == str)
			{
				CPatchType::arrVariables[i]->AddRef();
				return CPatchType::arrVariables[i];
			}
		}

		//
		//	Решение скобок
		//
		if( str.First() == sBrackets_Round[0][0] && str.Last() == sBrackets_Round[1][0] )
		{
			CString strNormalize = str.Copy( 1, str.Length() - 2 );

			CPatchStack*  pStack = CPatchStack::CreateStack( strNormalize );
			CPatchSymbol* pSymbol = pStack->Execute();

			pSymbol->AddRef();
			pStack->Destroy();

			return pSymbol;
		}

		//
		//	Операторы преобразования типов и функции
		//
		CArray<TSymBuilder*>& arrBuilders = TSymBuilder::arrBuilders;
		for (uint32 i = 0; i < arrBuilders.GetNum(); i++)
		{
			CString& sSynonym = arrBuilders[i]->sSynonym;
			CString  sType	  = sSynonym.GetWord(":", 1);
			CString	 sSymbol  = sSynonym.GetWord(":", 2);

			if( sSymbol == str )
			{
				if( sType == "Type" )
				{
					ASSERT( !sSymbol.IsEmpty(), "Отсутствует имя синонима, следующего за меткой Type:<name>" );

					CPatchOperator* pOperator = new CPatchOperator;
					pOperator->Init( sSymbol );
					return pOperator;
				}
				else if( sType == "Function" )
				{
					ASSERT( !sSymbol.IsEmpty(), "Отсутствует имя синонима, следующего за меткой Function:<name>" );
					CPatchFunction* pFunction = dynamic_cast<CPatchFunction*>(arrBuilders[i]->CreateSymbol());
					ASSERT( pFunction, "Родительский класс функции '" + sSymbol + "' не является CPatchFunction" );
					return pFunction;
				}
			}
		}


		//
		//	Математические операторы
		//
		for (uint32 i = ulOperatorNum - 1; i != Invalid ; i--)
		{			
			if( sOperators[i] == str )
			{
				//Say::Box( A i + " " + str, CPatchRegion::ulIterator );
				CPatchOperator* pOperator = new CPatchOperator;
				pOperator->Init( str );
				return pOperator;
			}
		}

		//
		//	Значения сопоставимые с типами
		//
		if( str.First() == sBrackets_TextLine[0][0] && str.Last() == sBrackets_TextLine[1][0] )
		{
			CString sLine = str.Copy( 1, str.Length()-2 );
			CString sKeys	[5] = { "\\\\", "\\0", "\\n", "\\t", "\\\"" };
			char    sResults[5] = { '\\',	'\0',  '\n',  '\t',   '"'   };
			for (uint32 i = 0; i < 5; i++)
			{
				while (true)
				{
					uint32 idx = sLine.Search( sKeys[i] );
					if( idx == Invalid )
						break;
					sLine.Cut(idx+1, 1);
					sLine[idx] = sResults[i];
				}
			}
			sLine = "\"" + sLine + "\"";

			CPatchHex* pHex = new CPatchHex;
			pHex->Init();
			uint32 ulSize = sLine.Length() - 2;
			CString sCopied = sLine.Copy( 1, ulSize );
			pHex->SetValue( (void32)sCopied.GetVector(), ulSize );
			return pHex;
		}
		if( str.First() == sBrackets_HexLine[0][0] && str.Last() == sBrackets_HexLine[1][0] )
		{
			CArray<byte> arrBytes;
			for (uint32 i = 1;; i++)
			{
				CString sByte = str.GetWord(" '", i);
			
				if (sByte.IsEmpty())
					break;
				arrBytes.Insert( (sByte).ToInt32(16) );
			}
			void32 pPtr = arrBytes.CopyAtBounds(0, arrBytes.GetNum());
			uint32 ulSize = arrBytes.GetNum();
			
			CPatchHex* pHex = new CPatchHex;
			pHex->Init();
			pHex->SetValue( arrBytes.CopyAtBounds(0, arrBytes.GetNum()), arrBytes.GetNum() );
			return pHex;
		}
		if( str.MatchesMask(sNumber_PureHex) && str.HasWordI("x") == 1 )
		{
			CString sPage	= str.GetWord( "x", 1 );
			CString sOffset	= str.GetWord( "x", 2);

			uint32 ulPage	= sPage.ToInt32	 ( 10 );
			uint32 ulOffset	= sOffset.ToInt32( 16 );

			if( ulPage != 0 )
			{
				CMemPage* pPage = CMemPage::GetPage( ulPage );

				ASSERT_PATCH( pPage, "Страница памяти index[" + A ulPage + "] не существует!" );
				
				ulOffset += pPage->GetAddress();
			}

			CPatchInteger* pSymbol = new CPatchInteger;
			pSymbol->Init();
			pSymbol->SetValue( ulOffset );
			return pSymbol;
		}
		if( str.MatchesMask(sNumber_Integer) )
		{
			CPatchInteger* pSymbol = new CPatchInteger;
			pSymbol->Init();
			int32 val = str.ToInt32();
			pSymbol->SetValue( val );
			return pSymbol;
		}
		if( str.MatchesMask(sNumber_Float) )
		{
			CPatchFloat* pSymbol = new CPatchFloat;
			pSymbol->Init();
			real32 val = str.ToReal32();
			pSymbol->SetValue( val );
			return pSymbol;
		}

		//
		//	Оператор указателя на ini
		//
		uint32 ulSep = str.HasWord(":");
		if( ulSep == 1 || ulSep == 2 )
		{
			CPatchOperator* pOperator = new CPatchOperator;
			pOperator->Init( str );
			return pOperator;
		}

		//
		//	Численные синонимы
		//
		if( str == "NULL" )
		{
			CPatchHex* pHex = new CPatchHex;
			pHex->Init();
			pHex->SetValue( Null, 0 );
			return pHex;
		}
		if( str == "TRUE" )
		{
			CPatchBool* pBool = new CPatchBool;
			pBool->Init();
			pBool->SetValue( True );
			pBool->SetAnsi ( True );
			return pBool;
		}
		if( str == "FALSE" )
		{
			CPatchBool* pBool = new CPatchBool;
			pBool->Init();
			pBool->SetValue( False );
			pBool->SetAnsi ( True  );
			return pBool;
		}

		ASSERT_PATCH_ERROR( "Не найден ни один синоним к '" + str + "'" );
		return Null;
	}

	void CPatchSymbol::AddRef()
	{
		ulRef++;
	}

	void CPatchSymbol::Release()
	{
		if( ulRef == 0 )
		{
			ASSERT_ERROR( "Попытка удалить уже удаленный объект" );
		}
		if( --ulRef == 0 )
			delete this;
	}

	CPatchSymbol::~CPatchSymbol()
	{
		//cmd << "~" << endl;
	}
}





namespace SystemPack
{
	CArray<TSymBuilder*> TSymBuilder::arrBuilders;

	TSymBuilder::TSymBuilder(const CString& className, const CString& synonym, TObjectCreator func)
	{
		for (uint32 i = 0; i < arrBuilders.GetNum(); i++)
		{
			if( arrBuilders[i]->sClassName == className )
				ASSERT_ERROR( "Переопределение. Класс '" + className + "' уже зарегистрирован." );
		}
		sClassName = className;
		sSynonym   = synonym;
		pFunction  = func;
		arrBuilders.Insert( this );
	}

	CPatchSymbol* TSymBuilder::CreateSymbol()
	{
		return pFunction();
	}

	CString TSymBuilder::GetClass()
	{
		return sClassName;
	}

	CString TSymBuilder::GetSynonym()
	{
		return sSynonym;
	}

	TSymBuilder* TSymBuilder::GetByClassName(const CString& className)
	{
		for (uint32 i = 0; i < arrBuilders.GetNum(); i++)
		{
			if( arrBuilders[i]->sClassName == className )
				return arrBuilders[i];
		}
		return Null;
	}

	TSymBuilder* TSymBuilder::GetBySynonym(const CString& synonym)
	{
		for (uint32 i = 0; i < arrBuilders.GetNum(); i++)
		{
			CString sSynonym = arrBuilders[i]->sSynonym.GetWord(":", 2);
			if( sSynonym == synonym )
				return arrBuilders[i];
		}
		return Null;
	}

	CString TSymBuilder::GetSymbolType(const CString& synonym)
	{
		for (uint32 i = 0; i < arrBuilders.GetNum(); i++)
		{
			CString sSynonym = arrBuilders[i]->sSynonym.GetWord(":", 2);
			if( sSynonym == synonym )
				return arrBuilders[i]->sSynonym.GetWord(":", 1);
		}
		return NullStr;
	}
}