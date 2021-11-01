// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_H__VER0__
#define __ZVIEW_H__VER0__

#include "zGrafix.h"
#include "zDisk.h"
#include "zRenderer.h"
#include "zViewBase.h"

namespace Gothic_I_Classic {
  const float VIEW_TIME_PER_CHAR = 100.0f;
  const int VIEW_GROUNDED        = 1<<3;
  const int VIEW_MODAL           = 1<<6;
  const int VIEW_AUTOSCROLL      = 1<<8;
  const int VIEW_TXT_CENTER      = 1<<9;
  const int VIEW_TXT_AUTO        = 1<<10;
  const int VIEW_STAYONTOP       = 1<<11;
  const int VIEW_I_TEXT          = 1;
  const int zInputKeyNext        = 0;
  const int zInputKeyStop        = 1;

  enum zTviewID {
    VIEW_SCREEN,
    VIEW_VIEWPORT,
    VIEW_ITEM
  };

  // sizeof 04h
  class zCInputCallback {
  public:

    void zCInputCallback_OnInit()    zCall( 0x006FB800 );
    zCInputCallback()                zInit( zCInputCallback_OnInit() );
    ~zCInputCallback()               zCall( 0x006FB810 );
    void SetHandleEventTop()         zCall( 0x006FB880 );
    void SetEnableHandleEvent( int ) zCall( 0x006FB8F0 );
    int GetEnableHandleEvent()       zCall( 0x006FB970 );
    static int DoEvents( int )       zCall( 0x006FB9A0 );
    static void GetInput()           zCall( 0x006FB9D0 );
    virtual int HandleEvent( int )   zCall( 0x00439A60 );

    // static properties
    static zCList<zCInputCallback>& inputList;

    // user API
    #include "zCInputCallback.inl"
  };

  // sizeof 38h
  class zCViewText {
  public:
    int posx;       // sizeof 04h    offset 04h
    int posy;       // sizeof 04h    offset 08h
    zSTRING text;   // sizeof 14h    offset 0Ch
    zCFont* font;   // sizeof 04h    offset 20h
    float timer;    // sizeof 04h    offset 24h
    int inPrintWin; // sizeof 04h    offset 28h
    zCOLOR color;   // sizeof 04h    offset 2Ch
    int timed;      // sizeof 04h    offset 30h
    int colored;    // sizeof 04h    offset 34h

    zCViewText() {}
    void zCViewText_OnInit( int, int, zSTRING const& )                                     zCall( 0x00702600 );
    void zCViewText_OnInit( int, int, zSTRING const&, float&, zCOLOR&, int, int )          zCall( 0x007027C0 );
    zCViewText( int a0, int a1, zSTRING const& a2 )                                        zInit( zCViewText_OnInit( a0, a1, a2 ));
    zCViewText( int a0, int a1, zSTRING const& a2, float& a3, zCOLOR& a4, int a5, int a6 ) zInit( zCViewText_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    void Create( int, int, zSTRING const&, float&, zCOLOR&, int, int )                     zCall( 0x00702960 );
    virtual ~zCViewText()                                                                  zCall( 0x00702AE0 );

    // user API
    #include "zCViewText.inl"
  };

  // sizeof FCh
  class zCView : public zCViewBase, public zCInputCallback {
  public:
    typedef enum zEViewFX {
      VIEW_FX_NONE,
      VIEW_FX_ZOOM,
      VIEW_FX_MAX
    } zTViewFX;

    zCView* next;                   // sizeof 04h    offset 08h
    zTviewID viewID;                // sizeof 04h    offset 0Ch
    int flags;                      // sizeof 04h    offset 10h
    int intflags;                   // sizeof 04h    offset 14h
    int ondesk;                     // sizeof 04h    offset 18h
    zTRnd_AlphaBlendFunc alphafunc; // sizeof 04h    offset 1Ch
    zCOLOR color;                   // sizeof 04h    offset 20h
    int alpha;                      // sizeof 04h    offset 24h
    zList<zCView> childs;           // sizeof 10h    offset 28h
    zCView* owner;                  // sizeof 04h    offset 38h
    zCTexture* backTex;             // sizeof 04h    offset 3Ch
    int vposx;                      // sizeof 04h    offset 40h
    int vposy;                      // sizeof 04h    offset 44h
    int vsizex;                     // sizeof 04h    offset 48h
    int vsizey;                     // sizeof 04h    offset 4Ch
    int pposx;                      // sizeof 04h    offset 50h
    int pposy;                      // sizeof 04h    offset 54h
    int psizex;                     // sizeof 04h    offset 58h
    int psizey;                     // sizeof 04h    offset 5Ch
    zCFont* font;                   // sizeof 04h    offset 60h
    zCOLOR fontColor;               // sizeof 04h    offset 64h
    int px1;                        // sizeof 04h    offset 68h
    int py1;                        // sizeof 04h    offset 6Ch
    int px2;                        // sizeof 04h    offset 70h
    int py2;                        // sizeof 04h    offset 74h
    int winx;                       // sizeof 04h    offset 78h
    int winy;                       // sizeof 04h    offset 7Ch
    zCList<zCViewText> textLines;   // sizeof 08h    offset 80h
    float scrollMaxTime;            // sizeof 04h    offset 88h
    float scrollTimer;              // sizeof 04h    offset 8Ch
    zTViewFX fxOpen;                // sizeof 04h    offset 90h
    zTViewFX fxClose;               // sizeof 04h    offset 94h
    float timeDialog;               // sizeof 04h    offset 98h
    float timeOpen;                 // sizeof 04h    offset 9Ch
    float timeClose;                // sizeof 04h    offset A0h
    float speedOpen;                // sizeof 04h    offset A4h
    float speedClose;               // sizeof 04h    offset A8h
    int isOpen;                     // sizeof 04h    offset ACh
    int isClosed;                   // sizeof 04h    offset B0h
    int continueOpen;               // sizeof 04h    offset B4h
    int continueClose;              // sizeof 04h    offset B8h
    int removeOnClose;              // sizeof 04h    offset BCh
    int resizeOnOpen;               // sizeof 04h    offset C0h
    int maxTextLength;              // sizeof 04h    offset C4h
    zSTRING textMaxLength;          // sizeof 14h    offset C8h
    zVEC2 posCurrent[2];            // sizeof 10h    offset DCh
    zVEC2 posOpenClose[2];          // sizeof 10h    offset ECh
    
    void zCView_OnInit()                                                            zCall( 0x006FBB60 );
    void zCView_OnInit( int, int, int, int, zTviewID )                              zCall( 0x006FBC20 );
    zCView()                                                                        zInit( zCView_OnInit() );
    zCView( int a0, int a1, int a2, int a3, zTviewID a4 = zTviewID::VIEW_ITEM )     zInit( zCView_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                                     zCall( 0x006FBEB0 );
    void Init( int, int, int, int, zTviewID )                                       zCall( 0x006FC040 );
    void Init( int, int, zSTRING const&, zTviewID )                                 zCall( 0x006FC1E0 );
    void SetAutoScroll( float )                                                     zCall( 0x006FC440 );
    void CheckAutoScroll()                                                          zCall( 0x006FC480 );
    void SetTransparency( int )                                                     zCall( 0x006FC570 );
    void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                           zCall( 0x006FC580 );
    void SetColor( zCOLOR const& )                                                  zCall( 0x006FC590 );
    zCOLOR GetColor()                                                               zCall( 0x006FC5A0 );
    void Setflags( int )                                                            zCall( 0x006FC5B0 );
    void ClrFlags( int )                                                            zCall( 0x006FC5C0 );
    int HasFlag( int )                                                              zCall( 0x006FC5E0 );
    void InsertBack( zCTexture* )                                                   zCall( 0x006FC600 );
    void InsertBack( zSTRING const& )                                               zCall( 0x006FC640 );
    void InitPrintwin()                                                             zCall( 0x006FC740 );
    void BlitText()                                                                 zCall( 0x006FC7B0 );
    void Top()                                                                      zCall( 0x006FCC10 );
    void Create( zSTRING const&, zEViewFX, zEViewFX, float, int )                   zCall( 0x006FCC90 );
    void ForceOpen()                                                                zCall( 0x006FCE10 );
    void Open()                                                                     zCall( 0x006FD070 );
    void Close()                                                                    zCall( 0x006FD290 );
    void ApplyOpenClose( zVEC2&, zVEC2& )                                           zCall( 0x006FD3A0 );
    void UpdateOpen()                                                               zCall( 0x006FD620 );
    void UpdateClose()                                                              zCall( 0x006FD670 );
    void UpdateOpenZoom()                                                           zCall( 0x006FD720 );
    void UpdateCloseZoom()                                                          zCall( 0x006FD820 );
    void RecalcChildsSize()                                                         zCall( 0x006FD930 );
    void RecalcChildsPos()                                                          zCall( 0x006FD9A0 );
    void SetPos( int, int )                                                         zCall( 0x006FDA10 );
    void GetPos( int&, int& )                                                       zCall( 0x006FDAC0 );
    void CalcPixelPos( int&, int& )                                                 zCall( 0x006FDAE0 );
    void GetPixelPos( int&, int& )                                                  zCall( 0x006FDB20 );
    void Move( int, int )                                                           zCall( 0x006FDB40 );
    void SetSize( int, int )                                                        zCall( 0x006FDC00 );
    void GetSize( int&, int& )                                                      zCall( 0x006FDC70 );
    void GetPixelSize( int&, int& )                                                 zCall( 0x006FDC90 );
    void GetExtends( int&, int&, int&, int& )                                       zCall( 0x006FDCC0 );
    void GetScreenExtends( int&, int&, int&, int& )                                 zCall( 0x006FDD00 );
    void GetPixelExtends( float&, float&, float&, float& )                          zCall( 0x006FDD70 );
    int IsIn( int, int )                                                            zCall( 0x006FDDC0 );
    zCView* GetItem( int, int )                                                     zCall( 0x006FDE50 );
    zCViewText* CreateText( int, int, zSTRING const&, float, zCOLOR&, int, int )    zCall( 0x006FDF10 );
    void CheckTimedText()                                                           zCall( 0x006FE0E0 );
    void PrintTimed( int, int, zSTRING const&, float, zCOLOR* )                     zCall( 0x006FE1A0 );
    void PrintTimedCX( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x006FE230 );
    void PrintTimedCY( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x006FE380 );
    void PrintTimedCXY( zSTRING const&, float, zCOLOR* )                            zCall( 0x006FE440 );
    void PrintMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )             zCall( 0x006FE5C0 );
    void PrintMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )          zCall( 0x006FE8D0 );
    void PrintSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR& )         zCall( 0x006FF030 );
    void Dialog( int, int, zSTRING const&, float, zCOLOR* )                         zCall( 0x006FF1B0 );
    void DialogCX( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x006FF280 );
    void DialogCY( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x006FF2E0 );
    void DialogCXY( zSTRING const&, float, zCOLOR* )                                zCall( 0x006FF3D0 );
    void DialogMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )            zCall( 0x006FF420 );
    void DialogMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )         zCall( 0x006FF6B0 );
    void DialogSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR&, float ) zCall( 0x006FF940 );
    void SetFont( zCFont* )                                                         zCall( 0x006FFD60 );
    void SetFontColor( zCOLOR const& )                                              zCall( 0x006FFD80 );
    void SetFont( zSTRING const& )                                                  zCall( 0x006FFD90 );
    zCFont* GetFont()                                                               zCall( 0x006FFDC0 );
    zSTRING GetFontName()                                                           zCall( 0x006FFDD0 );
    int FontY()                                                                     zCall( 0x006FFE60 );
    int FontSize( zSTRING& )                                                        zCall( 0x006FFE80 );
    void Print( int, int, zSTRING const& )                                          zCall( 0x006FFEB0 );
    void PrintChars( int, int, zSTRING const& )                                     zCall( 0x006FFF80 );
    void PrintCX( int, zSTRING const& )                                             zCall( 0x00700280 );
    void PrintCY( int, zSTRING const& )                                             zCall( 0x00700370 );
    void PrintCXY( zSTRING const& )                                                 zCall( 0x00700460 );
    void ClrPrintwin()                                                              zCall( 0x00700570 );
    zCViewText* CreateText( int, int, zSTRING const& )                              zCall( 0x007006E0 );
    zSTRING GetFirstText()                                                          zCall( 0x00700880 );
    void Nextline( zSTRING const&, float, zCOLOR*, int* )                           zCall( 0x00700900 );
    void DefPrintwin( int, int, int, int )                                          zCall( 0x00700B80 );
    void Printwin( zSTRING const& )                                                 zCall( 0x00700D20 );
    zSTRING Input( int )                                                            zCall( 0x00701110 );
    zSTRING Input( int, zSTRING& )                                                  zCall( 0x007011B0 );
    zSTRING Input( int, int, int, zSTRING& )                                        zCall( 0x00701750 );
    int InputNumber( int, int )                                                     zCall( 0x00701A10 );
    void InsertItem( zCView*, int = False )                                         zCall( 0x00701EA0 );
    void RemoveItem( zCView* )                                                      zCall( 0x007020E0 );
    void Render()                                                                   zCall( 0x007025F0 );
    zSTRING PatchMenuItemPrintwin()                                                 zCall( 0x00702B30 );
    static void StdPrintwin( zSTRING const& )                                       zCall( 0x006FC420 );
    static void PrintDebug( zSTRING const& )                                        zCall( 0x00701E60 );
    static void SetShowDebug( int )                                                 zCall( 0x00701E80 );
    static int GetShowDebug()                                                       zCall( 0x00701E90 );
    static void ChangeMode()                                                        zCall( 0x00702160 );
    static void SetNextMode()                                                       zCall( 0x00702170 );
    static void SetMode( int, int, int, HWND__** )                                  zCall( 0x00702180 );
    /* for zCViewBase num : 11*/
    virtual int anx( int )                                                          zCall( 0x006FC3A0 );
    virtual int any( int )                                                          zCall( 0x006FC3E0 );
    virtual int nax( int )                                                          zCall( 0x006FC320 );
    virtual int nay( int )                                                          zCall( 0x006FC360 );
    virtual int ClipLine( int&, int&, int&, int& )                                  zCall( 0x00702440 );
    virtual void Line( int, int, int, int, zCOLOR const& )                          zCall( 0x00702350 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )                   zCall( 0x00439A70 );
    virtual int GetCode( int, int )                                                 zCall( 0x00702400 );
    virtual ~zCView()                                                               zCall( 0x006FBCE0 );
    virtual void Blit()                                                             zCall( 0x006FC8C0 );
    virtual void DrawItems()                                                        zCall( 0x006FCBD0 );
    /* for zCInputCallback num : 1*/

    // static properties
    static zCView*& stdoutput;
    static zCView*& modal;
    static int& showDebug;

    // user API
    #include "zCView.inl"
  };

  extern zCView*& screen;
  inline int PixelToVirtualX( int x ) { return screen->anx( x ); }
  inline int PixelToVirtualY( int y ) { return screen->any( y ); }
  inline int VirtualToPixelX( int x ) { return screen->nax( x ); }
  inline int VirtualToPixelY( int y ) { return screen->nay( y ); }

} // namespace Gothic_I_Classic

#endif // __ZVIEW_H__VER0__