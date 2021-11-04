// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_UNTYPED_H__
#define __UNION_UNTYPED_H__

namespace UnionCore
{
  typedef struct _tagUntyped
  {
    void32 data;
    ASTAPI _tagUntyped( untyped_ptr );
    ASTAPI operator void32 () const;
  } TInstance;
} // namespace UnionCore

#endif // __UNION_UNTYPED_H__