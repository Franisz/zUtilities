// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_PATCH_OPERATOR_H__
#define __SYSTEMPACK_PATCH_OPERATOR_H__

namespace SystemPack
{
  class CPatchStack;
  class ASTAPI CPatchOperator : public CPatchSymbol
  {
    friend class CPatchStack;

    CString sOperator;
    CPatchStack* pOnStack;

    PATCH_CLASS_DECLARATION( CPatchOperator );
  public:
    void Init( const CString& opName );
    CString GetOperator();
    virtual CPatchType* Execute();
  };
} // namespace SystemPack

#endif // __SYSTEMPACK_PATCH_OPERATOR_H__