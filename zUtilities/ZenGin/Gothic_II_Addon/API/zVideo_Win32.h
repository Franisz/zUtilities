// Supported with union (c) 2018 Union team

#ifndef __ZVIDEO__WIN32_H__VER3__
#define __ZVIDEO__WIN32_H__VER3__

namespace Gothic_II_Addon {
  const unsigned int BLIT_COMMANDS = 6;

  struct VIDEO_INFO {
  public:
    int bOnlyFullScreen;
    int bHideMenu;
    int bDisableMenuKeys;
    int bDisableAltEnter;
    int bDisableCtrlAltDel;
    int bAllowMinimizeWindow;
    unsigned long dwShowBitDepths;
    unsigned long dwEnableBitDepths;
    unsigned long dwStretch;
    void* fnAltEnter;
    void* fnCheckVMode;
    void* fnSetVideoMode;
  };

  struct VIDMEM_INFO {
  public:
    unsigned long vidMem;
    unsigned long vidMemFree;
    unsigned long agpMem;
    unsigned long agpMemFree;
  };

  struct SURFACE_INFO {
  public:
    unsigned char MemType;
    unsigned long Width;
    unsigned long Height;
    unsigned char BPP;
    int rgbMasksValid;
    unsigned long rgbRMask;
    unsigned long rgbGMask;
    unsigned long rgbBMask;
  };

  struct SURFACE {
  public:
    SURFACE_INFO si;
    unsigned char* Ptr;
    unsigned long Pitch;
    unsigned long APISpecific[5];
    int Lost;
    void* pNext;
    void* pPrev;
  };

  struct VIDMODE {
  public:
    SURFACE_INFO si;
    unsigned char hwModeType;
    unsigned char AccessMode;
    unsigned char VidMemBuffers;
    unsigned char SysMemBuffers;
    unsigned char BlitInfo[BLIT_COMMANDS];
    unsigned long APISpecific[4];
  };

  struct BLIT_CMD {
  public:
    SURFACE* dstSurf;
    RECT* dstRect;
    SURFACE* srcSurf;
    RECT* srcRect;
    unsigned long Command;
    unsigned long Data;
  };

  struct CUSTOMCAPTION {
  public:
    HICON hIcon;
    long iButtons;
    HDC hDC;
    HBITMAP hBmp;
    long iWidth;
    long winWidth;
    int bActive;
    int bSizeBorder;
    unsigned long bmpWidth;
    unsigned char* bmpData;
    unsigned char* bmpBackground;
  };

} // namespace Gothic_II_Addon

#endif // __ZVIDEO__WIN32_H__VER3__