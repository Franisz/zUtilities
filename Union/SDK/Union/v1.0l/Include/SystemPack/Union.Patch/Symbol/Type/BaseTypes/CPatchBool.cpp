#include <UnionAfx.h>

namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchBool, "Type:bool");

	CPatchBool::CPatchBool()
	{
		pValue	 = Null;
		eType	 = SYM_TYPE_UNKNOWN;
		bValAnsi = False;
	}

	void CPatchBool::Init(const uint32& address)
	{
		if( address == None )
		{
			eType  = SYM_TYPE_STACK;
			pValue = new bool32;
		}
		else
		{
			eType  = SYM_TYPE_POINTER;
			pValue = (bool32*)address;
		}
	}

	CPatchType*	CPatchBool::Execute()
	{
		return this;
	}

	void32 CPatchBool::GetData()
	{
		return pValue;
	}

	uint32 CPatchBool::GetSize()
	{
		return sizeof(bool32);
	}

	CPatchType* CPatchBool::operator = (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( symInt->GetValue() != 0 );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( symFloat->GetValue() != 0.0f );
				return this;
			}
		}
		// Bool
		{
			CPatchBool* symBool = dynamic_cast<CPatchBool*>( symbol );
			if( symBool )
			{
				SetAnsi ( symBool->GetAnsi() );
				SetValue( symBool->GetValue() != 0 );
				return this;
			}
		}
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				SetValue( *(bool32*)symHex->GetValue() != 0 );
				return this;
			}
		}
		return CallExternalOperators( 0, this, symbol );
	}

	CPatchType* CPatchBool::operator +  (CPatchType* symbol)
	{
		return CallExternalOperators( 1, this, symbol );
	}

	CPatchType* CPatchBool::operator -  (CPatchType* symbol)
	{
		return CallExternalOperators( 2, this, symbol );
	}

	CPatchType* CPatchBool::operator *  (CPatchType* symbol)
	{
		return CallExternalOperators( 3, this, symbol );
	}

	CPatchType* CPatchBool::operator /  (CPatchType* symbol)
	{
		return CallExternalOperators( 4, this, symbol );
	}

	CPatchType* CPatchBool::operator ^ (CPatchType* symbol)
	{
		return CallExternalOperators( 5, this, symbol );
	}

	CPatchType* CPatchBool::operator += (CPatchType* symbol)
	{
		return CallExternalOperators( 6, this, symbol );
	}

	CPatchType* CPatchBool::operator -= (CPatchType* symbol)
	{
		return CallExternalOperators( 7, this, symbol );
	}

	CPatchType* CPatchBool::operator *= (CPatchType* symbol)
	{
		return CallExternalOperators( 8, this, symbol );
	}

	CPatchType* CPatchBool::operator /= (CPatchType* symbol)
	{
		return CallExternalOperators( 9, this, symbol );
	}

	CPatchType* CPatchBool::operator ^= (CPatchType* symbol)
	{
		return CallExternalOperators( 10, this, symbol );
	}

	CPatchType* CPatchBool::operator ! ()
	{
		CPatchBool* resultInt = new CPatchBool;
		resultInt->Init();
		resultInt->SetValue( GetValue() != 0 ? FALSE : TRUE );
		resultInt->SetAnsi ( GetAnsi() );
		return resultInt;
	}

	CPatchType* CPatchBool::operator == (CPatchType* symbol)
	{
		// Bool
		{
			CPatchBool symBool;
			symBool.Init();
			bool32 symIsConverted = (bool32)(symBool = symbol);
			if( symIsConverted )
			{
				CPatchBool* symResult = new CPatchBool;
				symResult->Init();
				symResult->SetValue( GetValue() == symBool.GetValue() );
				return symResult;
			}
		}
		return CallExternalOperators( 11, this, symbol );
	}

	CPatchType* CPatchBool::operator != (CPatchType* symbol)
	{
		{
			CPatchBool symBool;
			symBool.Init();
			bool32 symIsConverted = (bool32)(symBool = symbol);
			if( symIsConverted )
			{
				CPatchBool* symResult = new CPatchBool;
				symResult->Init();
				symResult->SetValue( GetValue() != symBool.GetValue() );
				return symResult;
			}
		}
		return CallExternalOperators( 12, this, symbol );
	}

	CPatchType* CPatchBool::operator <  (CPatchType* symbol)
	{
		return CallExternalOperators( 13, this, symbol );
	}

	CPatchType* CPatchBool::operator <= (CPatchType* symbol)
	{
		return CallExternalOperators( 14, this, symbol );
	}

	CPatchType* CPatchBool::operator >  (CPatchType* symbol)
	{
		return CallExternalOperators( 15, this, symbol );
	}

	CPatchType* CPatchBool::operator >= (CPatchType* symbol)
	{
		return CallExternalOperators( 16, this, symbol );
	}

	void CPatchBool::ReadOption ()
	{
		if( sOptionName.IsEmpty() )
			return;

		CString sValue;
		ReadOptionString( sValue, sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
		if( sValue.IsEmpty() )
		{
			SetValue( False );
		}
		else
		{
				 if( sValue == "TRUE"  )	{ SetValue( TRUE );				bValAnsi = True; }
			else if( sValue == "FALSE" )	{ SetValue( FALSE );			bValAnsi = True; }
			else							{ SetValue( sValue.ToInt32() ); bValAnsi = False; }
		}
	}

	void CPatchBool::WriteOption ()
	{
		if( sOptionName.IsEmpty() )
			return;

		CString sResult = bValAnsi ? (GetValue() ? "True" : "False") : CString(GetValue());
		WriteOptionString( sResult, sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
	}

	void  CPatchBool::SetValue(const bool32& val)
	{
		TMemUnlocker unlock( pValue, 4, eType == SYM_TYPE_POINTER );
		memcpy( pValue, &val, GetSize() );
	}

	bool32 CPatchBool::GetValue()
	{
		return *pValue;
	}

	CPatchBool::~CPatchBool()
	{
		if( eType == SYM_TYPE_STACK && pValue )
			delete pValue;
	}

	void CPatchBool::SetAnsi(bool32 bl)
	{
		bValAnsi = bl;
	}

	bool32 CPatchBool::GetAnsi()
	{
		return bValAnsi;
	}
}