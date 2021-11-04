#include <UnionAfx.h>

namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchInteger, "Type:int");

	CPatchInteger::CPatchInteger()
	{
		pValue = Null;
		eType  = SYM_TYPE_UNKNOWN;
	}

	void CPatchInteger::Init(const uint32& address)
	{
		if( address == None )
		{
			eType  = SYM_TYPE_STACK;
			pValue = new int32;
		}
		else
		{
			eType  = SYM_TYPE_POINTER;
			pValue = (int32*)address;
		}
	}

	CPatchType*	CPatchInteger::Execute()
	{
		return this;
	}

	void32 CPatchInteger::GetData()
	{
		return pValue;
	}

	uint32 CPatchInteger::GetSize()
	{
		return sizeof(int32);
	}

	CPatchType* CPatchInteger::operator = (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( symInt->GetValue() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( (int32)symFloat->GetValue() );
				return this;
			}
		}
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				SetValue( *(int32*)symHex->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 0, this, symbol );
	}

	CPatchType* CPatchInteger::operator +  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() + symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() + (int32)symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 1, this, symbol );
	}

	CPatchType* CPatchInteger::operator -  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() - symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() - symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 2, this, symbol );
	}

	CPatchType* CPatchInteger::operator *  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() * symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() * symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 3, this, symbol );
	}

	CPatchType* CPatchInteger::operator /  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() / symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( GetValue() / symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 4, this, symbol );
	}

	CPatchType* CPatchInteger::operator ^ (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( pow( GetValue(), symInt->GetValue() ));
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchInteger* resultInt = new CPatchInteger;
				resultInt->Init();
				resultInt->SetValue( pow( (real32)GetValue(), symFloat->GetValue() ));
				return resultInt;
			}
		}
		return CallExternalOperators( 5, this, symbol );
	}

	CPatchType* CPatchInteger::operator += (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( GetValue() + symInt->GetValue() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( GetValue() + symFloat->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 6, this, symbol );
	}

	CPatchType* CPatchInteger::operator -= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( GetValue() - symInt->GetValue() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( GetValue() - symFloat->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 7, this, symbol );
	}
	
	CPatchType* CPatchInteger::operator *= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( GetValue() * symInt->GetValue() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( GetValue() * symFloat->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 8, this, symbol );
	}
	
	CPatchType* CPatchInteger::operator /= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( GetValue() / symInt->GetValue() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( GetValue() / symFloat->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 9, this, symbol );
	}

	CPatchType* CPatchInteger::operator ^= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue( pow( GetValue(), symInt->GetValue() ));
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue( pow( GetValue(), (int32)symFloat->GetValue() ));
				return this;
			}
		}
		return CallExternalOperators( 10, this, symbol );
	}
	
	CPatchType* CPatchInteger::operator ! ()
	{
		CPatchBool* resultInt = new CPatchBool;
		resultInt->Init();
		resultInt->SetValue( GetValue() != 0 ? FALSE : TRUE );
		return resultInt;
	}

	CPatchType* CPatchInteger::operator == (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() == symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() == symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 11, this, symbol );
	}

	CPatchType* CPatchInteger::operator != (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() != symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() != symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 12, this, symbol );
	}

	CPatchType* CPatchInteger::operator <  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() < symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() < symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 13, this, symbol );
	}

	CPatchType* CPatchInteger::operator <= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() <= symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() <= symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 14, this, symbol );
	}

	CPatchType* CPatchInteger::operator >  (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() > symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() > symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 15, this, symbol );
	}

	CPatchType* CPatchInteger::operator >= (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() >= symInt->GetValue() );
				return resultInt;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchBool* resultInt = new CPatchBool;
				resultInt->Init();
				resultInt->SetValue( GetValue() >= symFloat->GetValue() );
				return resultInt;
			}
		}
		return CallExternalOperators( 16, this, symbol );
	}

	void CPatchInteger::ReadOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		CString sValue;
		ReadOptionString( sValue, sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
		SetValue( sValue.ToInt32() );
	}

	void CPatchInteger::WriteOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		WriteOptionString( A GetValue(), sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
	}

	void  CPatchInteger::SetValue(const int32& val)
	{
		TMemUnlocker unlock( pValue, 4, eType == SYM_TYPE_POINTER );
		memcpy( pValue, &val, GetSize() );
	}

	int32 CPatchInteger::GetValue()
	{
		return *pValue;
	}

	CPatchInteger::~CPatchInteger()
	{
		if( eType == SYM_TYPE_STACK && pValue )
			delete pValue;
	}
}