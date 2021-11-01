// Supported with union (c) 2018-2021 Union team

#ifndef __ZRND_D3D__INIT_H__VER1__
#define __ZRND_D3D__INIT_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 32Ch
  struct dxDEVICE {
  public:
    char name[256];           // sizeof 100h   offset 00h
    char desc[256];           // sizeof 100h   offset 100h
    char DeviceName[256];     // sizeof 100h   offset 200h
    unsigned long hardware;   // sizeof 04h    offset 300h
    unsigned long number;     // sizeof 04h    offset 304h
    unsigned long dxguidflag; // sizeof 04h    offset 308h
    GUID guid;                // sizeof 10h    offset 30Ch
    GUID dxguid;              // sizeof 10h    offset 31Ch
  };

  // sizeof 0Ch
  struct dxDDMODE {
  public:
    int w;   // sizeof 04h    offset 00h
    int h;   // sizeof 04h    offset 04h
    int bpp; // sizeof 04h    offset 08h
  };

  // sizeof 08h
  struct zD3DTEX {
  public:
    int mode;           // sizeof 04h    offset 00h
    zCTex_D3D* texture; // sizeof 04h    offset 04h

    // user API
    #include "zD3DTEX.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRND_D3D__INIT_H__VER1__