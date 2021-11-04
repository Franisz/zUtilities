// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_MEMPAGE_H__
#define __PATCH_MEMPAGE_H__

namespace SystemPack {
  class ASTAPI CMemPage {
    static CArrayOld<CMemPage*> arrPages;

    uint32 ulIndex;
    uint32 ulSize;
    uint32 ulAddress;

    CMemPage();
    ~CMemPage();
  public:

    static CMemPage* GetPage( const uint32& index );
    static CMemPage* Allocate( const uint32& index, const uint32& size );
    static void Free( const uint32& index );

    uint32 GetIndex();
    uint32 GetSize();
    uint32 GetAddress();
  };
}

#endif // __PATCH_MEMPAGE_H__