#include <UnionAfx.h>

namespace SystemPack
{

	/*TMemUnlocker::TMemUnlocker( void32 address, const uint32& size, const bool32& condition )
	{
		if( condition && address && size )
		{
			Say::Box( "Unlock" );
			ulAddress = address;
			ulSize	  = size;
			ulOldRoot = PAGE_EXECUTE_READWRITE;
			ulOldRoot = VirtualProtect( ulAddress, ulSize, ulOldRoot, &ulOldRoot );
		}
		else
		{
			ulAddress = Null;
			ulSize	  = 0;
		}
	}
	TMemUnlocker::~TMemUnlocker()
	{
		if( ulAddress )
		{
			Say::Box( "Lock" );
			ulong32 lg;
			VirtualProtect( ulAddress, ulSize, ulOldRoot, &ulOldRoot );
		}
	}*/

	TMemUnlocker::TMemUnlocker( void32 address, const uint32& size, const bool32& condition )
	{
		if( address && size && condition )
		{
			ulAddress = address;
			ulSize	  = size;
			VirtualProtect( ulAddress, ulSize, PAGE_EXECUTE_READWRITE, &ulOldRoot );
		}
		else
		{
			ulAddress = Null;
			ulSize	  = 0;
		}
	}
	TMemUnlocker::~TMemUnlocker()
	{
		if( ulAddress && ulSize )
		{
			VirtualProtect( ulAddress, ulSize, ulOldRoot, &ulOldRoot );
		}
	}

	int32 pow( int32 _val, int32 _pow )
	{
		if( _pow == 0 )
			return 1;

		int32 newVal = _val;
		for (int32 i = 1; i < _pow; i++)
		{
			newVal *= _val;
		}
		return newVal;
	}

	CPatchType* CallExternalOperators( const uint32& idx, CPatchType* left, CPatchType* right )
	{
		ASSERT_PATCH_ERROR( "Не существует оператора [" + left->GetSymbolName() + "] " + sOperators[idx] + " [" + right->GetSymbolName() + "]" );
		return Null;
	}
}

namespace SystemPack
{
	CArray<CPatchType*> CPatchType::arrVariables;

	CPatchType* CPatchType::GetVariable(const CString name)
	{
		for (uint32 i = 0; i < arrVariables.GetNum(); i++)
		{
			if( arrVariables[i]->sObjectName == name)
				return arrVariables[i];
		}
		return Null;
	}

	void CPatchType::SetObjectName(const CString& objName)
	{
		ASSERT_PATCH( !TSymBuilder::GetBySynonym( objName) , "Невозможно создать переменную, поскольку имя '" + objName + "' зарезервировано" );

		for (uint32 i = 0; i < arrVariables.GetNum(); i++)
		{
			if( arrVariables[i]->sObjectName == objName )
			{
				ASSERT_PATCH_ERROR( objName + " уже объявлена" );
			}
		}

		sObjectName = objName;
		if( !sObjectName.IsEmpty() && !arrVariables.IsIn(this) )
			arrVariables.Insert( this );
		else
			arrVariables.Remove( this );
	}

	void CPatchType::SetOption(const CString& objName)
	{
		sOptionName = objName;
	}

	CString	CPatchType::GetObjectName()
	{
		return sObjectName;
	}

	CString	CPatchType::GetOption()
	{
		return sOptionName;
	}

	void CPatchType::ReadOptionString (CString& result, const CString& optionName, const CString& section, const CString& value)
	{
		if( !optionName.IsEmpty() )
		{
			if (optionName == "UNION")
			{
				if( Union.GetUnionOption().IsExists( section, value ) )
					return Union.GetUnionOption().Read( result, section, value );
				result = NullStr;
				return;
			}
			else if (optionName == "SYSTEMPACK")
			{
				if( Union.GetSysPackOption().IsExists( section, value ) )
					return Union.GetSysPackOption().Read( result, section, value );
				result = NullStr;
				return;
			}
			else if (optionName == "MOD")
			{
				if( Union.GetGameOption().IsExists( section, value ) )
					return Union.GetGameOption().Read( result, section, value );
				result = NullStr;
				return;
			}
			else if (optionName == "GAME")
			{
				if( Union.GetDefaultOption().IsExists( section, value ) )
					return Union.GetDefaultOption().Read( result, section, value );
				result = NullStr;
				return;
			}
			ASSERT_PATCH_ERROR( "Некорректный параметр '" + optionName + "' в определении ссылки" );
		}
		else
		{
			if( Union.OptionIsExists( section, value ))
				result = Union.OptionReadString( section, value );
		}
		result = NullStr;
	}

	void CPatchType::WriteOptionString (const CString& data, const CString& optionName, const CString& section, const CString& value)
	{
		if( !optionName.IsEmpty() )
		{
			if (optionName == "UNION")
				return Union.GetUnionOption().Write( data, section, value );

			else if (optionName == "SYSTEMPACK")
			{
				return Union.GetSysPackOption().Write( data, section, value );
			}
			else if (optionName == "MOD")
				return Union.GetGameOption().Write( data, section, value );

			else if (optionName == "GAME")
				return Union.GetDefaultOption().Write( data, section, value );

			ASSERT_PATCH_ERROR( "Некорректный параметр '" + optionName + "' в определении ссылки" );
		}
		else
		{
			Union.OptionWriteString( data, section, value );
		}
	}

	CPatchType::~CPatchType()
	{
		arrVariables.Remove( this );
	}
}