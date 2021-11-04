// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_HOOKINFO_H__
#define __UNION_HOOKINFO_H__

namespace UnionCore
{
  typedef struct
  {
    void32  lpPointer;      // pointer to func
    void32  lpDetour;       // detour func
    void32  lpOriginal;     // original func
    uint32  ulProtected;    // protection

  } THookInfo, THookDescriptor;
} // namespace UnionCore

#endif // __UNION_HOOKINFO_H__