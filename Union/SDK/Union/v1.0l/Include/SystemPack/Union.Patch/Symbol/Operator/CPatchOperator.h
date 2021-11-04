#pragma once

namespace SystemPack {
  class CPatchStack;

  class ASTAPI CPatchOperator : public CPatchSymbol {
    PATCH_CLASS_DECLARATION( CPatchOperator );

    CString sOperator;
    CPatchStack* pOnStack;
  public:
    void Init( const CString& opName );
    CString GetOperator();

    virtual CPatchType* Execute();
  };
}