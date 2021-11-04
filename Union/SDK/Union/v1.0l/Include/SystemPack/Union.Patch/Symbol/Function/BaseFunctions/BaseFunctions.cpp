#include <UnionAfx.h>

namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncSqrt, "Function:Sqrt" );

  CPatchFuncSqrt::CPatchFuncSqrt() {

  }

  CPatchType* CPatchFuncSqrt::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "Sqrt ��������� 1 ��������" );

    {
      CPatchFloat* pFloat = dynamic_cast<CPatchFloat*>(arrParameters[0]);
      if( pFloat ) {
        CPatchFloat* pResult = new CPatchFloat;
        pResult->Init();

        pResult->SetValue( sqrt( pFloat->GetValue() ) );
        return pResult;
      }
    }

    {
      CPatchInteger* pInteger = dynamic_cast<CPatchInteger*>(arrParameters[0]);
      if( pInteger ) {
        CPatchInteger* pResult = new CPatchInteger;
        pResult->Init();

        pResult->SetValue( sqrt( (float)pInteger->GetValue() ) );
        return pResult;
      }
    }
    ASSERT_PATCH_ERROR( "���������� ������������� 1-� �������� ������� 'Sqrt' � �����" );
    return Null;
  }

  CPatchFuncSqrt::~CPatchFuncSqrt() {

  }
}



namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncMessageBox, "Function:MessageBox" );

  CPatchFuncMessageBox::CPatchFuncMessageBox() {

  }

  CPatchType* CPatchFuncMessageBox::Execute() {
    CString sWord;
    for( uint32 i = 0; i < arrParameters.GetNum(); i++ ) {
      CPatchInteger* pInteger = dynamic_cast<CPatchInteger*>(arrParameters[i]);
      if( pInteger ) {
        sWord += A pInteger->GetValue();
        continue;
      }

      CPatchFloat* pFloat = dynamic_cast<CPatchFloat*>(arrParameters[i]);
      if( pFloat ) {
        sWord += A pFloat->GetValue();
        continue;
      }

      CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[i]);
      if( pHex ) {
        if( pHex->GetSize() == 0 )
          pHex->AutoSize();
        sWord += CString( (text)pHex->GetValue(), pHex->GetSize() );

        continue;
      }

      CPatchHex mHex;
      mHex.Init();
      pHex = (CPatchHex*)(mHex = arrParameters[i]);
      ASSERT( pHex, "���������� ������������� " + A i + "-� �������� ������� 'MessageBox' � ������� ���. ��������� ���������� � HEX" );

      if( pHex->GetSize() == 0 )
        pHex->AutoSize();
      sWord += CString( (text)pHex->GetValue(), pHex->GetSize() );
    }
    Say::Box( sWord, "Union.patch" );
    return Null;
  }

  CPatchFuncMessageBox::~CPatchFuncMessageBox() {

  }
}



namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncPrintScreen, "Function:PrintScreen" );

  CPatchFuncPrintScreen::CPatchFuncPrintScreen() {

  }

  CPatchType* CPatchFuncPrintScreen::Execute() {
    CString sWord;
    for( uint32 i = 0; i < arrParameters.GetNum(); i++ ) {
      CPatchInteger* pInteger = dynamic_cast<CPatchInteger*>(arrParameters[i]);
      if( pInteger ) {
        sWord += A pInteger->GetValue();
        continue;
      }

      CPatchFloat* pFloat = dynamic_cast<CPatchFloat*>(arrParameters[i]);
      if( pFloat ) {
        sWord += A pFloat->GetValue();
        continue;
      }

      CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[i]);
      if( pHex ) {
        if( pHex->GetSize() == 0 )
          pHex->AutoSize();
        sWord += CString( (text)pHex->GetValue(), pHex->GetSize() );
        continue;
      }

      CPatchHex mHex;
      mHex.Init();
      pHex = (CPatchHex*)(mHex = arrParameters[i]);
      ASSERT( pHex, "���������� ������������� " + A i + "-� �������� ������� 'PrintScreen' � ������� ���. ��������� ���������� � HEX" );

      if( pHex->GetSize() == 0 )
        pHex->AutoSize();
      sWord += CString( (text)pHex->GetValue(), pHex->GetSize() );
    }
    cmd << ".patch >>   " << sWord << endl;
    return Null;
  }

  CPatchFuncPrintScreen::~CPatchFuncPrintScreen() {

  }
}




namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncAllocPage, "Function:AllocPage" );

  CPatchFuncAllocPage::CPatchFuncAllocPage() {

  }

  CPatchType* CPatchFuncAllocPage::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 2, "AllocPage ��������� 2 ���������" );

    CPatchInteger val1;
    CPatchInteger val2;
    val1.Init();
    val2.Init();
    CPatchType* pInteger1 = (val1 = arrParameters[0]);
    CPatchType* pInteger2 = (val2 = arrParameters[1]);

    ASSERT( pInteger1, "���������� ������������� 1-� �������� ������� 'AllocPage' � INT" );
    ASSERT( pInteger2, "���������� ������������� 2-� �������� ������� 'AllocPage' � INT" );

    CMemPage::Allocate( val1.GetValue(), val2.GetValue() );
    return Null;
  }

  CPatchFuncAllocPage::~CPatchFuncAllocPage() {

  }
}




namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncFreePage, "Function:FreePage" );

  CPatchFuncFreePage::CPatchFuncFreePage() {

  }

  CPatchType* CPatchFuncFreePage::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "FreePage ��������� 1 ���������" );

    CPatchInteger val1;
    val1.Init();
    CPatchInteger* pInteger = (CPatchInteger*)(val1 = arrParameters[0]);

    ASSERT( pInteger, "���������� ������������� 1-� �������� ������� 'AllocPage' � INT" );

    CMemPage::Free( pInteger->GetValue() );
    return Null;
  }

  CPatchFuncFreePage::~CPatchFuncFreePage() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncGetHexSize, "Function:GetHexSize" );

  CPatchFuncGetHexSize::CPatchFuncGetHexSize() {

  }

  CPatchType* CPatchFuncGetHexSize::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "GetHexSize ��������� 1 ��������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'GetHexSize' �� �������� HEX" );

    CPatchInteger* pInteger = new CPatchInteger;
    pInteger->Init();
    pInteger->SetValue( pHex->GetSize() );

    return pInteger;
  }

  CPatchFuncGetHexSize::~CPatchFuncGetHexSize() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncSetHexSize, "Function:SetHexSize" );

  CPatchFuncSetHexSize::CPatchFuncSetHexSize() {

  }

  CPatchType* CPatchFuncSetHexSize::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 2, "SetHexSize ��������� 2 ���������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'SetHexSize' �� �������� HEX" );

    CPatchInteger* pInteger = dynamic_cast<CPatchInteger*>(arrParameters[1]);
    ASSERT_PATCH( pHex, "2-� �������� ������� 'SetHexSize' �� �������� INT" );

    pHex->SetSize( pInteger->GetValue() );
    return Null;
  }

  CPatchFuncSetHexSize::~CPatchFuncSetHexSize() {

  }
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncSetHexAutoSize, "Function:SetHexAutoSize" );

  CPatchFuncSetHexAutoSize::CPatchFuncSetHexAutoSize() {

  }

  CPatchType* CPatchFuncSetHexAutoSize::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "SetHexAutoSize ��������� 1 ��������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'SetHexAutoSize' �� �������� HEX" );

    pHex->AutoSize();
    return Null;
  }

  CPatchFuncSetHexAutoSize::~CPatchFuncSetHexAutoSize() {

  }
}








namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncLoadLibrary, "Function:LoadLibrary" );

  CPatchFuncLoadLibrary::CPatchFuncLoadLibrary() {

  }

  CPatchType* CPatchFuncLoadLibrary::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "LoadLibrary ��������� 1 ��������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'LoadLibrary' �� �������� HEX" );

    if( pHex->GetSize() == 0 ) {
      pHex->AutoSize();
    }
    CString libName( (char*)pHex->GetValue(), pHex->GetSize() );
    LoadLibraryAST( libName );
    return Null;
  }

  CPatchFuncLoadLibrary::~CPatchFuncLoadLibrary() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncModuleBase, "Function:ModuleBase" );

  static CString SearchFile( const CString& start, const CString& file ) {
    // Files
    {
      CExplorer explorer( start + "*.*" );
      while( explorer.FindNext() ) {
        if( explorer.IsFile() ) {
          if( file.CompareI( explorer.FileName() ) ) {
            return start + explorer.FileName();
          }
        }
      }
    }
    // Dirs
    {
      CExplorer explorer( start + "*.*" );
      while( explorer.FindNext() ) {
        if( explorer.IsFolder() ) {
          CString sFile = SearchFile( start + explorer.FileName() + "\\", file );
          if( !sFile.IsEmpty() )
            return sFile;
        }
      }
    }
    return NullStr;
  }

  CPatchFuncModuleBase::CPatchFuncModuleBase() {

  }

  CPatchType* CPatchFuncModuleBase::Execute() {
    uint32 ulNum = arrParameters.GetNum();
    ASSERT_PATCH( ulNum == 1 || ulNum == 2, "ModuleBase ��������� 1 ��� 2 ���������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'ModuleBase' �� �������� HEX" );

    MODULEINFO info;
    HANDLE  proc = GetCurrentProcess();
    HMODULE module = Null;
    CString name;
    if( pHex->GetData() == Null ) {
      module = CPlugin::GetGothicModule();
    }
    else {
      if( pHex->GetSize() == 0 ) {
        pHex->AutoSize();
      }
      name = CString( (char*)pHex->GetValue(), pHex->GetSize() );
      module = GetModuleHandle( name );
    }

    if( ulNum == 2 ) {
      CPatchBool* pBool = dynamic_cast<CPatchBool*>(arrParameters[1]);
      CPatchHex*  pHex = dynamic_cast<CPatchHex*> (arrParameters[1]);
      ASSERT_PATCH( pBool || pHex, "2-� �������� ������� 'ModuleBase' �� �������� BOOL ��� HEX" );

      if( pBool ) {
        bool32 ulBool = pBool->GetValue();
        if( ulBool ) {
          GetModuleInformation( proc, module, &info, sizeof( MODULEINFO ) );
          if( info.lpBaseOfDll == 0 ) {
            module = LoadLibraryAST( name );
          }
        }
      }
      else {
        GetModuleInformation( proc, module, &info, sizeof( MODULEINFO ) );
        if( info.lpBaseOfDll == 0 ) {
          //module = LoadLibraryAST( libName );
          if( !module ) {

            if( !module ) {
              CString sPath( (char*)pHex->GetValue(), pHex->GetSize() );
              if( sPath.Last() != '\\' )
                sPath += "\\";

              char buff[260];
              GetWindowsDirectory( buff, 260 );

              const CString WinDir = "%WinDir%";
              while( sPath.HasWordI( WinDir ) ) {
                uint32 ulIdx = sPath.SearchI( WinDir );
                sPath.Cut( ulIdx, WinDir.Length() );
                sPath.Put( buff, ulIdx );
              }
              CString sFullName = SearchFile( sPath, name );
              if( !sFullName.IsEmpty() )
                module = LoadLibraryAST( sFullName );
            }
          }
        }
      }
    }
    GetModuleInformation( proc, module, &info, sizeof( MODULEINFO ) );

    CPatchInteger* pInteger = new CPatchInteger;
    pInteger->Init();
    pInteger->SetValue( (uint32)info.lpBaseOfDll );

    return pInteger;
  }

  CPatchFuncModuleBase::~CPatchFuncModuleBase() {

  }
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncMin, "Function:Min" );

  CPatchFuncMin::CPatchFuncMin() {

  }

  CPatchType* CPatchFuncMin::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 2, "Min ��������� 2 ���������" );

    CPatchInteger* pIntegerMin1 = dynamic_cast<CPatchInteger*>(arrParameters[0]);
    CPatchFloat*   pFloatMin1 = dynamic_cast<CPatchFloat*>  (arrParameters[0]);

    CPatchInteger* pIntegerMin2 = dynamic_cast<CPatchInteger*>(arrParameters[1]);
    CPatchFloat*   pFloatMin2 = dynamic_cast<CPatchFloat*>  (arrParameters[1]);

    ASSERT_PATCH( pIntegerMin1 || pFloatMin1, "1-� �������� ������� 'Min' �� �������� �������� �����" );
    ASSERT_PATCH( pIntegerMin2 || pFloatMin2, "2-� �������� ������� 'Min' �� �������� �������� �����" );

    CPatchType* pMin =
      (pIntegerMin1 ? pIntegerMin1->GetValue() : pFloatMin1->GetValue()) <
      (pIntegerMin2 ? pIntegerMin2->GetValue() : pFloatMin2->GetValue()) ?
      arrParameters[0] : arrParameters[1];

    pMin->AddRef();
    return pMin;
  }

  CPatchFuncMin::~CPatchFuncMin() {

  }
}





namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncMax, "Function:Max" );

  CPatchFuncMax::CPatchFuncMax() {

  }

  CPatchType* CPatchFuncMax::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 2, "Max ��������� 2 ���������" );

    CPatchInteger* pIntegerMin1 = dynamic_cast<CPatchInteger*>(arrParameters[0]);
    CPatchFloat*   pFloatMin1 = dynamic_cast<CPatchFloat*>  (arrParameters[0]);

    CPatchInteger* pIntegerMin2 = dynamic_cast<CPatchInteger*>(arrParameters[1]);
    CPatchFloat*   pFloatMin2 = dynamic_cast<CPatchFloat*>  (arrParameters[1]);

    ASSERT_PATCH( pIntegerMin1 || pFloatMin1, "1-� �������� ������� 'Max' �� �������� �������� �����" );
    ASSERT_PATCH( pIntegerMin2 || pFloatMin2, "2-� �������� ������� 'Max' �� �������� �������� �����" );

    CPatchType* pMin =
      (pIntegerMin1 ? pIntegerMin1->GetValue() : pFloatMin1->GetValue()) >
      (pIntegerMin2 ? pIntegerMin2->GetValue() : pFloatMin2->GetValue()) ?
      arrParameters[0] : arrParameters[1];

    pMin->AddRef();
    return pMin;
  }

  CPatchFuncMax::~CPatchFuncMax() {

  }
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncLim, "Function:Lim" );

  CPatchFuncLim::CPatchFuncLim() {

  }

  CPatchType* CPatchFuncLim::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 3, "Lim ��������� 3 ��������� (����������� ��������, �������� ��������, ������������ ��������)" );

    CPatchInteger* pIntegerMin = dynamic_cast<CPatchInteger*>(arrParameters[0]);
    CPatchFloat*   pFloatMin = dynamic_cast<CPatchFloat*>  (arrParameters[0]);

    CPatchInteger* pIntegerArg = dynamic_cast<CPatchInteger*>(arrParameters[1]);
    CPatchFloat*   pFloatArg = dynamic_cast<CPatchFloat*>  (arrParameters[1]);

    CPatchInteger* pIntegerMax = dynamic_cast<CPatchInteger*>(arrParameters[2]);
    CPatchFloat*   pFloatMax = dynamic_cast<CPatchFloat*>  (arrParameters[2]);

    ASSERT_PATCH( pIntegerMin || pFloatMin, "1-� �������� ������� 'Lim' �� �������� �������� �����" );
    ASSERT_PATCH( pIntegerArg || pFloatArg, "2-� �������� ������� 'Lim' �� �������� �������� �����" );
    ASSERT_PATCH( pIntegerMax || pFloatMax, "3-� �������� ������� 'Lim' �� �������� �������� �����" );

#define TYPE_VAL(sym1, sym2) ( sym1 ? sym1->GetValue() : sym2->GetValue() )
    CPatchType* pVal =
      TYPE_VAL( pIntegerMin, pFloatMin ) > TYPE_VAL( pIntegerArg, pFloatArg ) ?		// A > B ?
      arrParameters[0] :																// A :
      TYPE_VAL( pIntegerMax, pFloatMax ) < TYPE_VAL( pIntegerArg, pFloatArg ) ?		// C < B ?
      arrParameters[2] :																// C :
      arrParameters[1];															  	// B
#undef TYPE_VAL

    pVal->AddRef();
    return pVal;
  }

  CPatchFuncLim::~CPatchFuncLim() {

  }
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncHexViewBox, "Function:HexViewBox" );

  CPatchFuncHexViewBox::CPatchFuncHexViewBox() {

  }

  CPatchType* CPatchFuncHexViewBox::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() != 0, "HexViewBox ��������� ��� ������� 1 ��������" );
    ASSERT_PATCH( arrParameters.GetNum() <= 2, "HexViewBox ��������� �� ����� 2-� ����������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'HexViewBox' �� �������� HEX" );

    if( pHex->GetSize() == 0 ) {
      pHex->AutoSize();
    }
    uint32 ulBytes = pHex->GetSize();

    if( arrParameters.GetNum() == 2 ) {
      CPatchInteger* pInteger = dynamic_cast<CPatchInteger*>(arrParameters[1]);
      ASSERT_PATCH( pInteger, "2-� �������� ������� 'HexViewBox' �� �������� INT" );

      ulBytes = pInteger->GetValue();
    }


    CString	sHexView;
    byte*	pBuff = (byte*)pHex->GetValue();
    for( uint32 i = 0; i < ulBytes; i++ ) {
      byte& mByte = pBuff[i];
      sHexView += CString( mByte, 16 ) + " ";
    }
    Say::Info( sHexView + "\n(Ctrl + C for copy)", "Hex view" );

    return Null;
  }

  CPatchFuncHexViewBox::~CPatchFuncHexViewBox() {

  }
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncFindAndReplace, "Function:FindAndReplace" );

  inline bool32 memcmp( byte* dst, byte* src, uint32& len ) {
    for( uint32 i = 0; i < len; i++ ) {
      if( dst[i] != src[i] )
        return False;
    }
    return True;
  }

  CPatchFuncFindAndReplace::CPatchFuncFindAndReplace() {

  }

  CPatchType* CPatchFuncFindAndReplace::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 4, "FindAndReplace ��������� 4 ���������" );

    CPatchHex* pRequired = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pRequired, "1-� �������� ������� 'FindAndReplace' �� �������� HEX" );

    CPatchHex* pReplacement = dynamic_cast<CPatchHex*>(arrParameters[1]);
    ASSERT_PATCH( pReplacement, "2-� �������� ������� 'FindAndReplace' �� �������� HEX" );

    CPatchInteger* pBase = dynamic_cast<CPatchInteger*>(arrParameters[2]);
    ASSERT_PATCH( pBase, "3-� �������� ������� 'FindAndReplace' �� �������� INT" );

    CPatchInteger* pLength = dynamic_cast<CPatchInteger*>(arrParameters[3]);
    ASSERT_PATCH( pLength, "4-� �������� ������� 'FindAndReplace' �� �������� INT" );

    byte*  pBytes = (byte*)pRequired->GetData();
    uint32 ulSize = pRequired->GetSize();
    uint32 ulLength = pBase->GetValue() + pLength->GetValue() - ulSize;

    for( uint32 i = pBase->GetValue(); i < ulLength; i++ ) {
      if( memcmp( (byte*)i, pBytes, ulSize ) ) {
        byte*  pNewBytes = (byte*)pReplacement->GetValue();
        uint32 ulNewSize = pReplacement->GetSize();

        TMemUnlocker unlock( (byte*)i, ulNewSize, True );
        memcpy( (byte*)i, pNewBytes, ulNewSize );
      }
    }
    return Null;
  }

  CPatchFuncFindAndReplace::~CPatchFuncFindAndReplace() {

  }
}








namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncOptionDef, "Function:OptionDef" );

  CPatchFuncOptionDef::CPatchFuncOptionDef() {

  }

  CPatchType* CPatchFuncOptionDef::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 2, "OptionDef ��������� 2 ���������" );

    CPatchType* pType = arrParameters[0];
    CPatchType* pValue = arrParameters[1];
    CString sOption = pType->GetOption();

    ASSERT_PATCH( !sOption.IsEmpty(), "1-� �������� ������� OptionDef ������ ��������� �� �������� ini �����" );

    uint32 ulWords = sOption.HasWord( ":" );

    if( ulWords == 1 || ulWords == 2 ) {
      CString sParms[3] = {
        sOption.GetWord( ":", -3 ),
        sOption.GetWord( ":", -2 ),
        sOption.GetWord( ":", -1 )
      };

      if( ulWords == 1 ) {
        if( !Union.OptionIsExists( sParms[1], sParms[2] ) ) {
          ASSERT_PATCH( (*pType) = pValue, "���������� �������� [" + pValue->GetSymbolName() + "] � [" + pType->GetSymbolName() + "] � ������� OptionDef" );
          pType->WriteOption();
        }
        return Null;
      }
      else {
        if( sParms[0] == "UNION" ) {
          if( !Union.GetUnionOption().IsExists( sParms[1], sParms[2] ) ) {
            ASSERT_PATCH( (*pType) = pValue, "���������� �������� [" + pValue->GetSymbolName() + "] � [" + pType->GetSymbolName() + "] � ������� OptionDef" );
            pType->WriteOption();
          }
          return Null;
        }
        else if( sParms[0] == "SYSTEMPACK" ) {
          if( !Union.GetSysPackOption().IsExists( sParms[1], sParms[2] ) ) {
            ASSERT_PATCH( (*pType) = pValue, "���������� �������� [" + pValue->GetSymbolName() + "] � [" + pType->GetSymbolName() + "] � ������� OptionDef" );
            pType->WriteOption();
          }
          return Null;
        }
        else if( sParms[0] == "MOD" ) {
          if( !Union.GetGameOption().IsExists( sParms[1], sParms[2] ) ) {
            ASSERT_PATCH( (*pType) = pValue, "���������� �������� [" + pValue->GetSymbolName() + "] � [" + pType->GetSymbolName() + "] � ������� OptionDef" );
            pType->WriteOption();
          }
          return Null;
        }
        else if( sParms[0] == "GAME" ) {
          if( !Union.GetDefaultOption().IsExists( sParms[1], sParms[2] ) ) {
            ASSERT_PATCH( (*pType) = pValue, "���������� �������� [" + pValue->GetSymbolName() + "] � [" + pType->GetSymbolName() + "] � ������� OptionDef" );
            pType->WriteOption();
          }
          return Null;
        }
      }
    }

    ASSERT_PATCH_ERROR( "������������ ������ ini ���������" );
    return Null;
  }

  CPatchFuncOptionDef::~CPatchFuncOptionDef() {

  }
}











namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncModuleSize, "Function:ModuleSize" );

  CPatchFuncModuleSize::CPatchFuncModuleSize() {

  }

  CPatchType* CPatchFuncModuleSize::Execute() {
    ASSERT_PATCH( arrParameters.GetNum() == 1, "ModuleSize ��������� 1 ��������" );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pHex, "1-� �������� ������� 'ModuleSize' �� �������� HEX" );

    MODULEINFO info;
    HANDLE  proc = GetCurrentProcess();
    HMODULE module = Null;
    CString name;
    if( pHex->GetData() == Null ) {
      module = CPlugin::GetGothicModule();
    }
    else {
      if( pHex->GetSize() == 0 ) {
        pHex->AutoSize();
      }
      name = CString( (char*)pHex->GetValue(), pHex->GetSize() );
      module = GetModuleHandle( name );
    }

    GetModuleInformation( proc, module, &info, sizeof( MODULEINFO ) );

    CPatchInteger* pInteger = new CPatchInteger;
    pInteger->Init();
    pInteger->SetValue( (uint32)info.SizeOfImage );

    return pInteger;
  }

  CPatchFuncModuleSize::~CPatchFuncModuleSize() {

  }
}












namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncShowCmd, "Function:ShowCmd" );

  CPatchFuncShowCmd::CPatchFuncShowCmd() {

  }

  CPatchType* CPatchFuncShowCmd::Execute() {
    CCmd::Show();
    return Null;
  }

  CPatchFuncShowCmd::~CPatchFuncShowCmd() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncHideCmd, "Function:HideCmd" );

  CPatchFuncHideCmd::CPatchFuncHideCmd() {

  }

  CPatchType* CPatchFuncHideCmd::Execute() {
    CCmd::Release();
    return Null;
  }

  CPatchFuncHideCmd::~CPatchFuncHideCmd() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncImportSymbol, "Function:ImportSymbol" );

  CPatchFuncImportSymbol::CPatchFuncImportSymbol() {

  }

  extern "C" static uint32 ImportSymbolC( HMODULE module, const char* symbol ) {
    return (uint32)GetProcAddress( module, symbol );
  }

  extern "C++" static uint32 ImportSymbolCPP( HMODULE module, const char* symbol ) {
    return (uint32)GetProcAddress( module, symbol );
  }

  CPatchType* CPatchFuncImportSymbol::Execute() {
    uint32 ulNum = arrParameters.GetNum();
    ASSERT_PATCH( ulNum == 2 || ulNum == 3, "ModuleBase ��������� 2 ��� 3 ���������" );

    CPatchHex* pModule = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pModule, "1-� �������� ������� 'ImportSymbol' �� �������� HEX" );
    HMODULE hModule = GetModuleHandle( CString( (char*)pModule->GetValue(), pModule->GetSize() ) );

    CPatchHex* pHex = dynamic_cast<CPatchHex*>(arrParameters[1]);
    ASSERT_PATCH( pHex, "2-� �������� ������� 'ImportSymbol' �� �������� HEX" );
    CString sSymbolName( (char*)pHex->GetValue(), pHex->GetSize() );

    CPatchInteger* rtn = new CPatchInteger;
    rtn->Init();

    if( ulNum == 3 ) {
      CPatchHex* pMangleType = dynamic_cast<CPatchHex*>(arrParameters[2]);
      ASSERT_PATCH( pMangleType, "3-� �������� ������� 'ImportSymbol' �� �������� HEX" );

      CString sMangleType( (char*)pMangleType->GetValue(), pMangleType->GetSize() );

      if( sMangleType == "C" )
        rtn->SetValue( ImportSymbolC( hModule, sSymbolName ) );
      else if( sMangleType == "C++" )
        rtn->SetValue( ImportSymbolCPP( hModule, sSymbolName ) );
      else
        ASSERT_PATCH_ERROR( "3-� �������� ������� �� ������������ �� ���� ��� �����������" );
    }
    else {
      rtn->SetValue( ImportSymbolC( hModule, sSymbolName ) );
    }
    return rtn;
  }

  CPatchFuncImportSymbol::~CPatchFuncImportSymbol() {

  }
}






namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncMemSet, "Function:MemSet" );

  CPatchFuncMemSet::CPatchFuncMemSet() {

  }

  CPatchType* CPatchFuncMemSet::Execute() {
    uint32 ulNum = arrParameters.GetNum();
    ASSERT_PATCH( ulNum == 3, "MemSet ��������� 3 ���������" );

    CPatchInteger* pTo = dynamic_cast<CPatchInteger*>(arrParameters[0]);
    ASSERT_PATCH( pTo, "1-� �������� ������� 'MemSet' �� �������� INT" );

    CPatchHex* pPtr = dynamic_cast<CPatchHex*>(arrParameters[1]);
    ASSERT_PATCH( pPtr, "2-� �������� ������� 'MemSet' �� �������� HEX" );

    CPatchInteger* pLength = dynamic_cast<CPatchInteger*>(arrParameters[2]);
    ASSERT_PATCH( pLength, "3-� �������� ������� 'MemSet' �� �������� INT" );

    HBuffer hMemPtr = (HBuffer)pTo->GetValue();

    uint32 caret = 0;
    while( true ) {
      uint32 canCopy = min( pLength->GetValue() - caret, pPtr->GetSize() );
      TMemUnlocker unlock( hMemPtr + caret, canCopy, True );
      memcpy( hMemPtr + caret, pPtr->GetValue(), canCopy );
      caret += canCopy;
      if( caret >= pLength->GetValue() ) {
        break;
      }
    }
    return Null;
  }

  CPatchFuncMemSet::~CPatchFuncMemSet() {

  }
}






namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchFuncMemCopy, "Function:MemCopy");

	CPatchFuncMemCopy::CPatchFuncMemCopy()
	{
		
	}

	CPatchType* CPatchFuncMemCopy::Execute()
	{
		uint32 ulNum = arrParameters.GetNum();
		ASSERT_PATCH( ulNum == 3, "MemCopy ��������� 3 ���������"  );

		CPatchInteger* pFrom = dynamic_cast<CPatchInteger*>( arrParameters[0] );
		ASSERT_PATCH( pFrom, "1-� �������� ������� 'MemCopy' �� �������� INT" );

		CPatchInteger* pTo = dynamic_cast<CPatchInteger*>( arrParameters[1] );
		ASSERT_PATCH( pTo, "2-� �������� ������� 'MemCopy' �� �������� INT" );
		
		CPatchInteger* pLength = dynamic_cast<CPatchInteger*>( arrParameters[2] );
		ASSERT_PATCH( pLength, "3-� �������� ������� 'MemCopy' �� �������� INT" );

    TMemUnlocker unlock( (void32)pTo->GetValue(), pLength->GetValue(), True );
    void32 memResult = memcpy( (void32)pTo->GetValue(), (void32)pFrom->GetValue(), pLength->GetValue() );
    CPatchInteger* rtn = new CPatchInteger;
    rtn->Init();
    rtn->SetValue( (int)memResult );

		return rtn;
	}

	CPatchFuncMemCopy::~CPatchFuncMemCopy()
	{
		
	}
}







namespace SystemPack {
  PATCH_CLASS_DEFINITION( CPatchFuncFindWindowHandle, "Function:FindWindow" );

  CPatchFuncFindWindowHandle::CPatchFuncFindWindowHandle() {

  }

  CPatchType* CPatchFuncFindWindowHandle::Execute() {
    uint32 ulNum = arrParameters.GetNum();
    ASSERT_PATCH( ulNum == 2, "MemCopy ��������� 2 ���������" );

    CPatchHex* pClassName = dynamic_cast<CPatchHex*>(arrParameters[0]);
    ASSERT_PATCH( pClassName, "1-� �������� ������� 'MemCopy' �� �������� HEX" );

    CPatchHex* pWindowName = dynamic_cast<CPatchHex*>(arrParameters[1]);
    ASSERT_PATCH( pWindowName, "2-� �������� ������� 'MemCopy' �� �������� HEX" );

    CString sClassName(  (char*)pClassName->GetValue(),  pClassName->GetSize()  );
    CString sWindowName( (char*)pWindowName->GetValue(), pWindowName->GetSize() );

    HWND hWindow = FindWindow( sClassName.Length() ?
                               sClassName : Null,

                               sWindowName.Length() ?
                               sWindowName : Null );

    CPatchInteger* rtn = new CPatchInteger;
    rtn->Init();
    rtn->SetValue( (int)hWindow );

    return rtn;
  }

  CPatchFuncFindWindowHandle::~CPatchFuncFindWindowHandle() {

  }
}