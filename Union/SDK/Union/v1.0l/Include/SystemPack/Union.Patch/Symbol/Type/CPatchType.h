// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_TYPE_H__
#define __PATCH_TYPE_H__

namespace SystemPack {
  struct ASTAPI TMemUnlocker {
    void32 ulAddress;
    ulong32 ulSize;
    ulong32 ulOldRoot;

    TMemUnlocker( void32 address, const uint32& size, const bool32& condition );
    ~TMemUnlocker();
  };

  class ASTAPI CPatchType : public CPatchSymbol {
  protected:
    ESymType eType;
    CString sObjectName;
    CString sOptionName;

    static CArrayOld<CPatchType*> arrVariables;
  public:
    void ReadOptionString( CString& result, const CString& optionName, const CString& section, const CString& value );
    void WriteOptionString( const CString& data, const CString& optionName, const CString& section, const CString& value );
    void SetObjectName( const CString& objName );
    void SetOption( const CString& objName );
    CString GetObjectName();
    CString GetOption();
    
    static CPatchType* GetVariable( const CString name );

    virtual void Init( const uint32& address = 0 )         = 0;
    virtual CPatchType* Execute()                          = 0;
    virtual void32 GetData()                               = 0;
    virtual uint32 GetSize()                               = 0;
    virtual CPatchType* operator =  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator +  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator -  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator *  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator /  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator ^  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator += ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator -= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator *= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator /= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator ^= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator !  ()                     = 0;
    virtual CPatchType* operator == ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator != ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator <  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator <= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator >  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator >= ( CPatchType* symbol ) = 0;
    virtual void ReadOption()                              = 0;
    virtual void WriteOption()                             = 0;
    virtual ~CPatchType();
  };
}

#include "BaseTypes\CPatchBaseTypes.h"

#endif // __PATCH_TYPE_H__