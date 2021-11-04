// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ALLOCATOR_32_H__
#define __UNION_ALLOCATOR_32_H__

namespace Common
{
  template <unsigned __int32 __size_l, typename __type>
  struct allocator32
  {
    struct mem_pool {
      typedef struct mem_page {
        uint32 ufree;
        uint32 uorder[__size_l];
        void32 page;
        void init();
      } PAGE, *HPAGE, **HPAGELIST;

      HPAGELIST hpagelist;
      uint32  ucount;

      mem_pool();
      void32 hold_mem();
      void free_mem( void32 );

    } static pool;

    void32 operator new  ( size_t _Size );
    void operator delete ( void32 _Dst );
  };


  template <unsigned __int32 __size_l, typename __type>
  inline void32 allocator32<__size_l, __type>::operator new ( size_t _Size ) {
    return pool.hold_mem();
  };

  template <unsigned __int32 __size_l, typename __type>
  inline void allocator32<__size_l, __type>::operator delete ( void32 _Dst ) {
    pool.free_mem( _Dst );
  };

  template <unsigned __int32 __size_l, typename __type>
  inline void allocator32<__size_l, __type>::mem_pool::mem_page::init()
  {
    ufree = __size_l;
    uint32 usize = sizeof( __type );
    for( uint32 i = 0; i < __size_l; i++ )
      uorder[i] = i * usize;
    page = shi_malloc( __size_l * usize );
  }

  template <unsigned __int32 __size_l, typename __type>
  inline allocator32<__size_l, __type>::mem_pool::mem_pool()
  {
    hpagelist = reinterpret_cast<HPAGELIST>( shi_malloc( 0 ) );
    ucount = 0;
  }

  template <unsigned __int32 __size_l, typename __type>
  inline void32 allocator32<__size_l, __type>::mem_pool::hold_mem()
  {
    for( uint32 i = 0; i < ucount; i++ ) {
      if( hpagelist[i]->ufree > 0 ) {
        HPAGE& hpage = hpagelist[i];
        uint32 offset = hpage->uorder[--hpage->ufree];
        return reinterpret_cast<void32>( reinterpret_cast<uint32>( hpage->page ) + offset );
      }
    }

    hpagelist = reinterpret_cast<HPAGELIST> ( shi_realloc( hpagelist, ++ucount * 4 ) );
    hpagelist[ucount - 1] = reinterpret_cast<HPAGE>  ( shi_malloc( sizeof( PAGE ) ) );
    hpagelist[ucount - 1]->init();

    return hold_mem();
  }

  template <unsigned __int32 __size_l, typename __type>
  inline void allocator32<__size_l, __type>::mem_pool::free_mem( void32 _Dst )
  {
    for( uint32 i = 0; i < ucount; i++ ) {
      uint32 uidx = ( reinterpret_cast<uint32>( _Dst ) - reinterpret_cast<uint32>( hpagelist[i]->page ) ) / sizeof( __type );
      if( uidx >= 0 && uidx < __size_l ) {
        hpagelist[i]->uorder[hpagelist[i]->ufree] = uidx;
        if( ++hpagelist[i]->ufree >= __size_l ) {
          shi_free( hpagelist[i]->page );
          shi_free( hpagelist[i] );
          if( i != ucount )
            hpagelist[i] = hpagelist[--ucount];
        }
        return;
      }
    }
  }
} // namespace Common

#endif // __UNION_ALLOCATOR_32_H__