// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIDEO__WIN32_H__VER0__
#define __ZVIDEO__WIN32_H__VER0__

namespace Gothic_I_Classic {
  const unsigned int BLIT_COMMANDS = 6;

  // sizeof 30h
  struct VIDEO_INFO {
  public:
    int bOnlyFullScreen;             // sizeof 04h    offset 00h
    int bHideMenu;                   // sizeof 04h    offset 04h
    int bDisableMenuKeys;            // sizeof 04h    offset 08h
    int bDisableAltEnter;            // sizeof 04h    offset 0Ch
    int bDisableCtrlAltDel;          // sizeof 04h    offset 10h
    int bAllowMinimizeWindow;        // sizeof 04h    offset 14h
    unsigned long dwShowBitDepths;   // sizeof 04h    offset 18h
    unsigned long dwEnableBitDepths; // sizeof 04h    offset 1Ch
    unsigned long dwStretch;         // sizeof 04h    offset 20h
    void* fnAltEnter;                // sizeof 04h    offset 24h
    void* fnCheckVMode;              // sizeof 04h    offset 28h
    void* fnSetVideoMode;            // sizeof 04h    offset 2Ch
  };

  // sizeof 10h
  struct VIDMEM_INFO {
  public:
    unsigned long vidMem;     // sizeof 04h    offset 00h
    unsigned long vidMemFree; // sizeof 04h    offset 04h
    unsigned long agpMem;     // sizeof 04h    offset 08h
    unsigned long agpMemFree; // sizeof 04h    offset 0Ch
  };

  // sizeof 20h
  struct SURFACE_INFO {
  public:
    unsigned char MemType;  // sizeof 01h    offset 00h
    unsigned long Width;    // sizeof 04h    offset 04h
    unsigned long Height;   // sizeof 04h    offset 08h
    unsigned char BPP;      // sizeof 01h    offset 0Ch
    int rgbMasksValid;      // sizeof 04h    offset 10h
    unsigned long rgbRMask; // sizeof 04h    offset 14h
    unsigned long rgbGMask; // sizeof 04h    offset 18h
    unsigned long rgbBMask; // sizeof 04h    offset 1Ch
  };

  // sizeof 48h
  struct SURFACE {
  public:
    SURFACE_INFO si;              // sizeof 20h    offset 00h
    unsigned char* Ptr;           // sizeof 04h    offset 20h
    unsigned long Pitch;          // sizeof 04h    offset 24h
    unsigned long APISpecific[5]; // sizeof 14h    offset 28h
    int Lost;                     // sizeof 04h    offset 3Ch
    void* pNext;                  // sizeof 04h    offset 40h
    void* pPrev;                  // sizeof 04h    offset 44h
  };

  // sizeof 3Ch
  struct VIDMODE {
  public:
    SURFACE_INFO si;                       // sizeof 20h    offset 00h
    unsigned char hwModeType;              // sizeof 01h    offset 20h
    unsigned char AccessMode;              // sizeof 01h    offset 21h
    unsigned char VidMemBuffers;           // sizeof 01h    offset 22h
    unsigned char SysMemBuffers;           // sizeof 01h    offset 23h
    unsigned char BlitInfo[BLIT_COMMANDS]; // sizeof 06h    offset 24h
    unsigned long APISpecific[4];          // sizeof 10h    offset 2Ch
  };

  // sizeof 18h
  struct BLIT_CMD {
  public:
    SURFACE* dstSurf;      // sizeof 04h    offset 00h
    RECT* dstRect;         // sizeof 04h    offset 04h
    SURFACE* srcSurf;      // sizeof 04h    offset 08h
    RECT* srcRect;         // sizeof 04h    offset 0Ch
    unsigned long Command; // sizeof 04h    offset 10h
    unsigned long Data;    // sizeof 04h    offset 14h
  };

  // sizeof 2Ch
  struct CUSTOMCAPTION {
  public:
    HICON hIcon;                  // sizeof 04h    offset 00h
    long iButtons;                // sizeof 04h    offset 04h
    HDC hDC;                      // sizeof 04h    offset 08h
    HBITMAP hBmp;                 // sizeof 04h    offset 0Ch
    long iWidth;                  // sizeof 04h    offset 10h
    long winWidth;                // sizeof 04h    offset 14h
    int bActive;                  // sizeof 04h    offset 18h
    int bSizeBorder;              // sizeof 04h    offset 1Ch
    unsigned long bmpWidth;       // sizeof 04h    offset 20h
    unsigned char* bmpData;       // sizeof 04h    offset 24h
    unsigned char* bmpBackground; // sizeof 04h    offset 28h
  };

} // namespace Gothic_I_Classic

#endif // __ZVIDEO__WIN32_H__VER0__