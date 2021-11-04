// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_TYPES_H__
#define __UNION_TYPES_H__

namespace Common {
  typedef char              int8;
  typedef unsigned char     uint8;
  typedef short             int16;
  typedef unsigned short    uint16, *bytecode;
  typedef int               int32, int_t;
  typedef unsigned int      uint32, bool32, uint, bool_t, uint_t;
  typedef long              long32;
  typedef unsigned long     ulong, ulong32, uflag32;
  typedef __int64           int64, long64;
  typedef unsigned __int64  uint64, ulong64, uflag64;
  typedef float             real32;
  typedef double            real64;
  typedef void              *void32;
  typedef void              *void64;
  typedef char              *text, *HBuffer;
  typedef wchar_t           wchar, *wtext, *HWBuffer;
  typedef HINSTANCE         HPLUGIN;

  template <typename T>
  T& const_ptr( const T& _Dst_ ) {
    return const_cast<T&>(_Dst_);
  }

  template <typename T>
  inline void _swap( T& arg1, T& arg2 ) {
    T tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
  }

} // namespace Common

#endif // __UNION_ALLOCATOR_32_H__