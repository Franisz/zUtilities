// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_REGION_H__
#define __PATCH_REGION_H__

namespace SystemPack {
  class ASTAPI CPatchRegion {
    static CString sCurrentPatch;
    static uint32 ulIterator;
    static uint32 ulEngineOffset;
    static CDocument* pCurrentRegionData;
  protected:
    uint32 ulOffset;
    CDocument sRegionData;
  public:
    void ExecuteRegion();
    uint32 ExecuteOnLine( uint32& iterator );
    ~CPatchRegion();

    static CString GetLastInfo();
    static CPatchRegion* DefineBlock( CDocument& fileData, const uint32& hash );
  };
}

#endif // __PATCH_REGION_H__