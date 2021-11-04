// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_MEM_PAGE_H__
#define __SYSTEMPACK_MEM_PAGE_H__

namespace SystemPack
{
  class ASTAPI CMemPage
  {
    static CArray<CMemPage*> arrPages;

    uint32 ulIndex;
    uint32 ulSize;
    uint32 ulAddress;

    CMemPage();
    ~CMemPage();
  public:

    static CMemPage* GetPage( const uint32& index );
    static CMemPage* Allocate( const uint32& index, const uint32& size );
    static void      Free( const uint32& index );

    uint32 GetIndex();
    uint32 GetSize();
    uint32 GetAddress();
  };
} // namespace SystemPack

#endif // __SYSTEMPACK_MEM_PAGE_H__