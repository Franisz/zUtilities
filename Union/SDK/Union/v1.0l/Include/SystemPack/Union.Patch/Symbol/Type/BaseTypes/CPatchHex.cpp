#include <UnionAfx.h>

namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchHex, "Type:hex");

	CPatchHex::CPatchHex()
	{
		pValue = Null;
		eType  = SYM_TYPE_UNKNOWN;
	}

	void CPatchHex::Init(const uint32& address)
	{
		if( address == None )
		{
			eType  = SYM_TYPE_STACK;
			pValue = shi_malloc(0);
			ulSize = 0;
		}
		else
		{
			eType  = SYM_TYPE_POINTER;
			pValue = (void32)address;
			ulSize = 0;
		}
	}

	CPatchType*	CPatchHex::Execute()
	{
		return this;
	}

	void32 CPatchHex::GetData()
	{
		return pValue;
	}

	uint32 CPatchHex::GetSize()
	{
		return ulSize;
	}

	CPatchType* CPatchHex::operator = (CPatchType* symbol)
	{
		// Integer
		{
			CPatchInteger* symInt = dynamic_cast<CPatchInteger*>( symbol );
			if( symInt )
			{
				SetValue ( symInt->GetData(), symInt->GetSize() );
				return this;
			}
		}
		// Float
		{
			CPatchFloat* symFloat = dynamic_cast<CPatchFloat*>( symbol );
			if( symFloat )
			{
				SetValue ( symFloat->GetData(), symFloat->GetSize() );
				return this;
			}
		}
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				SetValue ( symHex->GetData(), symHex->GetSize() );
				return this;
			}
		}
		// Bool
		{
			CPatchBool* symBool = dynamic_cast<CPatchBool*>( symbol );
			if( symBool )
			{
				SetValue ( symBool->GetData(), symBool->GetSize() );
				return this;
			}
		}
		return CallExternalOperators( 0, this, symbol );
	}

	CPatchType* CPatchHex::operator + (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CPatchHex*	resultHex = new CPatchHex;
				resultHex->Init();
				CString		sLeft  ( (char*)		GetData(),		   GetSize() );
				CString		sRight ( (char*)symHex->GetData(), symHex->GetSize() );

				sLeft += sRight;

				resultHex->SetValue( (void32)sLeft.GetVector(), sLeft.Length() );
				return resultHex;
			}
		}
		return CallExternalOperators( 1, this, symbol );
	}

	CPatchType* CPatchHex::operator -  (CPatchType* symbol)
	{

		return CallExternalOperators( 2, this, symbol );
	}

	CPatchType* CPatchHex::operator *  (CPatchType* symbol)
	{

		return CallExternalOperators( 3, this, symbol );
	}

	CPatchType* CPatchHex::operator /  (CPatchType* symbol)
	{

		return CallExternalOperators( 4, this, symbol );
	}

	CPatchType* CPatchHex::operator ^ (CPatchType* symbol)
	{

		return CallExternalOperators( 5, this, symbol );
	}

	CPatchType* CPatchHex::operator += (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CString		sLeft  ( (char*)		GetData(),		   GetSize() );
				CString		sRight ( (char*)symHex->GetData(), symHex->GetSize() );

				sLeft += sRight;

				SetValue( (void32)sLeft.GetVector(), sLeft.Length() );
				return this;
			}
		}
		return CallExternalOperators( 6, this, symbol );
	}

	CPatchType* CPatchHex::operator -= (CPatchType* symbol)
	{

		return CallExternalOperators( 7, this, symbol );
	}

	CPatchType* CPatchHex::operator *= (CPatchType* symbol)
	{

		return CallExternalOperators( 8, this, symbol );
	}

	CPatchType* CPatchHex::operator /= (CPatchType* symbol)
	{

		return CallExternalOperators( 9, this, symbol );
	}

	CPatchType* CPatchHex::operator ^= (CPatchType* symbol)
	{

		return CallExternalOperators( 10, this, symbol );
	}

	CPatchType* CPatchHex::operator ! ()
	{

		return 0;
	}

	CPatchType* CPatchHex::operator == (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				if( GetSize() == 0 )
				{
					SetSize( symHex->GetSize() );
				}
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				CString		sLeft  ( (char*)		GetData(),		   GetSize() );
				CString		sRight ( (char*)symHex->GetData(), symHex->GetSize() );
				resultInteger->SetValue( sLeft.Compare(sRight) );
				return resultInteger;
			}
		}
		return CallExternalOperators( 11, this, symbol );
	}

	CPatchType* CPatchHex::operator != (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				if( GetSize() == 0 )
				{
					SetSize( symHex->GetSize() );
				}
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				CString		sLeft  ( (char*)		GetData(),		   GetSize() );
				CString		sRight ( (char*)symHex->GetData(), symHex->GetSize() );
				resultInteger->SetValue( !sLeft.Compare(sRight) );
				return resultInteger;
			}
		}
		return CallExternalOperators( 12, this, symbol );
	}

	CPatchType* CPatchHex::operator <  (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				bool32 bCmp = memcmp( GetData(), symHex->GetData(), min(GetSize(), symHex->GetSize()) );

				resultInteger->SetValue( bCmp < 0 );
				return resultInteger;
			}
		}
		return CallExternalOperators( 13, this, symbol );
	}

	CPatchType* CPatchHex::operator <= (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				bool32 bCmp = memcmp( GetData(), symHex->GetData(), min(GetSize(), symHex->GetSize()) );

				resultInteger->SetValue( bCmp <= 0 );
				return resultInteger;
			}
		}
		return CallExternalOperators( 14, this, symbol );
	}

	CPatchType* CPatchHex::operator >  (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				bool32 bCmp = memcmp( GetData(), symHex->GetData(), min(GetSize(), symHex->GetSize()) );

				resultInteger->SetValue( bCmp > 0 );
				return resultInteger;
			}
		}
		return CallExternalOperators( 15, this, symbol );
	}

	CPatchType* CPatchHex::operator >= (CPatchType* symbol)
	{
		// Hex
		{
			CPatchHex* symHex = dynamic_cast<CPatchHex*>( symbol );
			if( symHex )
			{
				CPatchBool*	resultInteger = new CPatchBool;
				resultInteger->Init();
				bool32 bCmp = memcmp( GetData(), symHex->GetData(), min(GetSize(), symHex->GetSize()) );

				resultInteger->SetValue( bCmp >= 0 );
				return resultInteger;
			}
		}
		return CallExternalOperators( 16, this, symbol );
	}

	void CPatchHex::ReadOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		CString sValue;
		ReadOptionString( sValue, sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
		SetValue( (void32)sValue.GetVector(), sValue.Length() );
	}

	void CPatchHex::WriteOption()
	{
		if( sOptionName.IsEmpty() )
			return;

		WriteOptionString( CString( (char*)GetValue(), ulSize ), sOptionName.GetWord(":", -3), sOptionName.GetWord(":", -2), sOptionName.GetWord(":", -1) );
	}

	void CPatchHex::SetValue(void32 val, const uint32& size)
	{
		SetSize( size );
		TMemUnlocker unlock( pValue, size, eType == SYM_TYPE_POINTER );
		if( size )
			memcpy( pValue, val, size );
	}

	void32 CPatchHex::GetValue()
	{
		return pValue;
	}

	void CPatchHex::SetSize(const uint32& size)
	{
		if( eType == SYM_TYPE_STACK )
			pValue = shi_realloc( pValue, size );
		ulSize = size;
	}

	void32 CPatchHex::GetCopy()
	{
		void32 pCopy = shi_malloc( ulSize );
		memcpy( pCopy, pValue, ulSize );
		return pCopy;
	}

	void CPatchHex::AutoSize()
	{
		ulSize = 0;
		char* pSymbols = (char*)pValue;
		
		for (uint32 i = 0;; i++)
		{
			if( pSymbols[i] == 0 )
				break;
			ulSize++;
		}
	}

	CPatchHex::~CPatchHex()
	{
		if( eType == SYM_TYPE_STACK && pValue )
			shi_free( pValue );
	}
}