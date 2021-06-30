// Supported with union (c) 2018 Union team

#ifndef __ZRND_D3D__INIT_H__VER1__
#define __ZRND_D3D__INIT_H__VER1__

namespace Gothic_I_Addon {

  struct dxDEVICE {
  public:
    char name[256];
    char desc[256];
    char DeviceName[256];
    unsigned long hardware;
    unsigned long number;
    unsigned long dxguidflag;
    GUID guid;
    GUID dxguid;
  };

  struct dxDDMODE {
  public:
    int w;
    int h;
    int bpp;
  };

  struct zD3DTEX {
  public:
    int mode;
    zCTex_D3D* texture;

    // user API
    #include "zD3DTEX.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRND_D3D__INIT_H__VER1__