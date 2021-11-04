// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_PATCH_TYPES_H__
#define __SYSTEMPACK_PATCH_TYPES_H__

namespace SystemPack
{
  struct ASTAPI TMemUnlocker
  {
    void32  ulAddress;
    ulong32 ulSize;
    ulong32 ulOldRoot;

    TMemUnlocker( void32 address, const uint32& size, const bool32& condition = True );
    ~TMemUnlocker();
  };

  class ASTAPI CPatchType : public CPatchSymbol
  {
    friend class CPatchSymbol;
    friend class CPatchFile;
    friend class CPatch;
  protected:
    static CArray<CPatchType*> arrVariables;
    ESymType eType;
    CString sObjectName;
    CString sOptionName;
  public:
    virtual void Init( const uint32& address = 0 ) = 0;
    virtual CPatchType* Execute() = 0;
    virtual void32 GetData() = 0;
    virtual uint32 GetSize() = 0;

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
    virtual CPatchType* operator !  () = 0;
    virtual CPatchType* operator == ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator != ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator <  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator <= ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator >  ( CPatchType* symbol ) = 0;
    virtual CPatchType* operator >= ( CPatchType* symbol ) = 0;

    virtual void ReadOption() = 0;
    virtual void WriteOption() = 0;

    void ReadOptionString( CString& result, const CString& optionName, const CString& section, const CString& value );
    void WriteOptionString( const CString& data, const CString& optionName, const CString& section, const CString& value );

    static CPatchType* GetVariable( const CString name );

    void SetObjectName( const CString& objName );
    void SetOption( const CString& objName );
    CString GetObjectName();
    CString GetOption();
    virtual ~CPatchType();
  };
} // namespace SystemPack

#include "CPatchBaseTypes.h"

#endif // __SYSTEMPACK_PARSER_FILTERS_H__
