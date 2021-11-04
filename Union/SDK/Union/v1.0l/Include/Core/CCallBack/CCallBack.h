// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_CALLBACK_H__
#define __UNION_CALLBACK_H__

#include "CInvoke\CInvoke.h"
#include "PatchCall\CallPatch.h"

namespace UnionCore
{
  class ASTAPI CCallBack
  {
    static CArrayOld <THookInfo*> arrFuncs;

  public:
    static bool32  Attach( THookInfo& );
    static bool32  Detach( THookInfo& );
    static bool32  DetachTree( THookInfo& );
    static bool32  Redefine( THookInfo& );

    static void    Commit();
    static bool32  Commit( THookInfo& );
    static uint32  Auto( const uint32& );
    static void    Protect( THookInfo& );
    static void    Unprotect( THookInfo& );

    static bool32  IsExist( const uint32& );
    static bool32  IsExist( THookInfo& );
    static bool32  IsProtected( const uint32& );
    static bool32  IsHooked( THookInfo& );

    static THookInfo* FindHook( const uint32& );
  };
} // namespace UnionCore

#endif // __UNION_CALLBACK_H__