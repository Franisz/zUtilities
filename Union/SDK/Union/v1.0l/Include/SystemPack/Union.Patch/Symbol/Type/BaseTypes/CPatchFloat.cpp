#include <UnionAfx.h>

namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchFloat, "Type:float");

	CPatchFloat::CPatchFloat()
	{
		pValue = Null;
		eType  = SYM_TYPE_UNKNOWN;
	}

	void CPatchFloat::Init(const uint32& address)
	{
		if( address == None )
		{
			eType  = SYM_TYPE_STACK;
			pValue = new real32;
		}
		else
		{
			eType  = SYM_TYPE_POINTER;
			pValue = (real32*)address;
		}
	}

	CPatchType*	CPatchFloat::Execute()
	{
		return this;
	}

	void32 CPatchFloat::GetData()
	{
		return pValue;
	}

	uint32 CPatchFloat::GetSize()
	{
		return sizeof(real32);
	}

	CPatchType* CPatchFloat::operator = (CPatchType* symbol)
	{
		// Int
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
				SetValue( symFloat->GetValue() );
				return this;
			}
		}
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				SetValue( *(real32*)symHex->GetValue() );
				return this;
			}
		}
		return CallExternalOperators( 0, this, symbol );
	}

	CPatchType* CPatchFloat::operator +  (CPatchType* symbol)
	{
		// Int
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() + symInt->GetValue() );
				return resultFloat;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() + symFloat->GetValue() );
				return resultFloat;
			}
		}
		return CallExternalOperators( 1, this, symbol );
	}

	CPatchType* CPatchFloat::operator -  (CPatchType* symbol)
	{
		// Int
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() - symInt->GetValue() );
				return resultFloat;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() - symFloat->GetValue() );
				return resultFloat;
			}
		}
		return CallExternalOperators( 2, this, symbol );
	}

	CPatchType* CPatchFloat::operator *  (CPatchType* symbol)
	{
		// Int
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() * symInt->GetValue() );
				return resultFloat;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() * symFloat->GetValue() );
				return resultFloat;
			}
		}
		return CallExternalOperators( 3, this, symbol );
	}
	
	CPatchType* CPatchFloat::operator /  (CPatchType* symbol)
	{
		// Int
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() / symInt->GetValue() );
				return resultFloat;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( GetValue() / symFloat->GetValue() );
				return resultFloat;
			}
		}
		return CallExternalOperators( 4, this, symbol );
	}

	CPatchType* CPatchFloat::operator ^ (CPatchType* symbol)
	{
		// Int
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( pow( GetValue(), symInt->GetValue() ));
				return resultFloat;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				CPatchFloat* resultFloat = new CPatchFloat;
				resultFloat->Init();
				resultFloat->SetValue( pow( GetValue(), symFloat->GetValue() ));
				return resultFloat;
			}
		}
		return CallExternalOperators( 5, this, symbol );
	}

	CPatchType* CPatchFloat::operator += (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator -= (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator *= (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator /= (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator ^= (CPatchType* symbol)
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
				SetValue( pow( GetValue(), symFloat->GetValue() ));
				return this;
			}
		}
		return CallExternalOperators( 10, this, symbol );
	}

	CPatchType* CPatchFloat::operator ! ()
	{
		CPatchBool* resultInt = new CPatchBool;
		resultInt->Init();
		resultInt->SetValue( GetValue() != 0.0f ? FALSE : TRUE );
		return resultInt;
	}
	
	CPatchType* CPatchFloat::operator == (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator != (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator <  (CPatchType* symbol)
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
	
	CPatchType* CPatchFloat::operator <= (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator >  (CPatchType* symbol)
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

	CPatchType* CPatchFloat::operator >= (CPatchType* symbol)
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

	void CPatchFloat::ReadOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		CString sValue;
		ReadOptionString( sValue, sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
		SetValue( sValue.ToReal32() );
	}

	void CPatchFloat::WriteOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		WriteOptionString( A GetValue(), sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
	}

	void CPatchFloat::SetValue(const real32& val)
	{
		TMemUnlocker unlock( pValue, 4, eType == SYM_TYPE_POINTER );
		memcpy( pValue, &val, GetSize() );
	}

	real32 CPatchFloat::GetValue()
	{
		return *pValue;
	}

	CPatchFloat::~CPatchFloat()
	{
		if( eType == SYM_TYPE_STACK && pValue )
			delete pValue;
	}
}