// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_SYMBOL_H__
#define __PATCH_SYMBOL_H__

namespace SystemPack {
  class CPatchType;

  enum ESymType {
    SYM_TYPE_UNKNOWN,
    SYM_TYPE_STACK,
    SYM_TYPE_POINTER
  };

  class ASTAPI CPatchSymbol {
  protected:
    uint32 ulRef;
    CPatchSymbol();
  public:
    static CPatchSymbol* CreateSymbol( const CString& str );

    void AddRef();
    void Release();

    virtual CPatchType* Execute() = 0;
    virtual CString GetSymbolName() = 0;
    virtual ~CPatchSymbol();
  };



  typedef CPatchSymbol*(*TObjectCreator)();
  class ASTAPI TSymBuilder {
    static CArrayOld<TSymBuilder*> arrBuilders;

    CString sClassName;
    CString sSynonym;
    TObjectCreator pFunction;
  public:
    TSymBuilder( const CString& className, const CString& synonym, TObjectCreator func );
    CPatchSymbol* CreateSymbol();
    CString GetClass();
    CString GetSynonym();

    static TSymBuilder* GetByClassName( const CString& className );
    static TSymBuilder* GetBySynonym( const CString& synonym );
    static CString GetSymbolType( const CString& synonym );
  };
}



#define PATCH_CLASS_DECLARATION(className) \
public:                                    \
 className();                              \
 virtual ~className();                     \
 static CPatchSymbol* CreateObject();      \
 static TSymBuilder mSymBuilder;           \
 virtual CString GetSymbolName();


#define PATCH_CLASS_DEFINITION(className, synonym) \
 CPatchSymbol* className::CreateObject()           \
 {                                                 \
 return new className;                             \
 }                                                 \
 CString className::GetSymbolName()                \
 {                                                 \
 return mSymBuilder.GetSynonym();                  \
 }                                                 \
 TSymBuilder className::mSymBuilder(#className, synonym, className::CreateObject);



#include "Type\CPatchType.h"
#include "Operator\CPatchOperator.h"
#include "Function\CPatchFunction.h"

#endif // __PATCH_SYMBOL_H__