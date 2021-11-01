// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_H__VER2__
#define __ZVIEW_H__VER2__

#include "zString.h"
#include "zGrafix.h"
#include "zDisk.h"
#include "zList.h"
#include "zRenderer.h"
#include "zViewBase.h"

namespace Gothic_II_Classic {
  const int VIEW_GROUNDED   = 1<<3;
  const int VIEW_MODAL      = 1<<6;
  const int VIEW_AUTOSCROLL = 1<<8;
  const int VIEW_TXT_CENTER = 1<<9;
  const int VIEW_TXT_AUTO   = 1<<10;
  const int VIEW_STAYONTOP  = 1<<11;
  const int VIEW_I_TEXT     = 1;
  const int zInputKeyNext   = 0;
  const int zInputKeyStop   = 1;

  enum zTviewID {
    VIEW_SCREEN,
    VIEW_VIEWPORT,
    VIEW_ITEM
  };

  // sizeof 04h
  class zCInputCallback {
  public:

    void zCInputCallback_OnInit()    zCall( 0x007458F0 );
    zCInputCallback()                zInit( zCInputCallback_OnInit() );
    ~zCInputCallback()               zCall( 0x00745900 );
    void SetHandleEventTop()         zCall( 0x00745970 );
    void SetEnableHandleEvent( int ) zCall( 0x007459E0 );
    int GetEnableHandleEvent()       zCall( 0x00745A60 );
    static int DoEvents( int )       zCall( 0x00745A90 );
    static void GetInput()           zCall( 0x00745AC0 );
    virtual int HandleEvent( int )   zCall( 0x0043CEB0 );

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
    void zCViewText_OnInit( int, int, zSTRING const& )                                     zCall( 0x0074C720 );
    void zCViewText_OnInit( int, int, zSTRING const&, float&, zCOLOR&, int, int )          zCall( 0x0074C8E0 );
    zCViewText( int a0, int a1, zSTRING const& a2 )                                        zInit( zCViewText_OnInit( a0, a1, a2 ));
    zCViewText( int a0, int a1, zSTRING const& a2, float& a3, zCOLOR& a4, int a5, int a6 ) zInit( zCViewText_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    void Create( int, int, zSTRING const&, float&, zCOLOR&, int, int )                     zCall( 0x0074CA80 );
    virtual ~zCViewText()                                                                  zCall( 0x0074CC00 );

    // user API
    #include "zCViewText.inl"
  };

  // sizeof 100h
  class zCView : public zCViewBase, public zCInputCallback {
  public:
    typedef enum zEViewFX {
      VIEW_FX_NONE,
      VIEW_FX_ZOOM,
      VIEW_FX_MAX
    } zTViewFX;

    int m_bFillZ;                   // sizeof 04h    offset 08h
    zCView* next;                   // sizeof 04h    offset 0Ch
    zTviewID viewID;                // sizeof 04h    offset 10h
    int flags;                      // sizeof 04h    offset 14h
    int intflags;                   // sizeof 04h    offset 18h
    int ondesk;                     // sizeof 04h    offset 1Ch
    zTRnd_AlphaBlendFunc alphafunc; // sizeof 04h    offset 20h
    zCOLOR color;                   // sizeof 04h    offset 24h
    int alpha;                      // sizeof 04h    offset 28h
    zList<zCView> childs;           // sizeof 10h    offset 2Ch
    zCView* owner;                  // sizeof 04h    offset 3Ch
    zCTexture* backTex;             // sizeof 04h    offset 40h
    int vposx;                      // sizeof 04h    offset 44h
    int vposy;                      // sizeof 04h    offset 48h
    int vsizex;                     // sizeof 04h    offset 4Ch
    int vsizey;                     // sizeof 04h    offset 50h
    int pposx;                      // sizeof 04h    offset 54h
    int pposy;                      // sizeof 04h    offset 58h
    int psizex;                     // sizeof 04h    offset 5Ch
    int psizey;                     // sizeof 04h    offset 60h
    zCFont* font;                   // sizeof 04h    offset 64h
    zCOLOR fontColor;               // sizeof 04h    offset 68h
    int px1;                        // sizeof 04h    offset 6Ch
    int py1;                        // sizeof 04h    offset 70h
    int px2;                        // sizeof 04h    offset 74h
    int py2;                        // sizeof 04h    offset 78h
    int winx;                       // sizeof 04h    offset 7Ch
    int winy;                       // sizeof 04h    offset 80h
    zCList<zCViewText> textLines;   // sizeof 08h    offset 84h
    float scrollMaxTime;            // sizeof 04h    offset 8Ch
    float scrollTimer;              // sizeof 04h    offset 90h
    zTViewFX fxOpen;                // sizeof 04h    offset 94h
    zTViewFX fxClose;               // sizeof 04h    offset 98h
    float timeDialog;               // sizeof 04h    offset 9Ch
    float timeOpen;                 // sizeof 04h    offset A0h
    float timeClose;                // sizeof 04h    offset A4h
    float speedOpen;                // sizeof 04h    offset A8h
    float speedClose;               // sizeof 04h    offset ACh
    int isOpen;                     // sizeof 04h    offset B0h
    int isClosed;                   // sizeof 04h    offset B4h
    int continueOpen;               // sizeof 04h    offset B8h
    int continueClose;              // sizeof 04h    offset BCh
    int removeOnClose;              // sizeof 04h    offset C0h
    int resizeOnOpen;               // sizeof 04h    offset C4h
    int maxTextLength;              // sizeof 04h    offset C8h
    zSTRING textMaxLength;          // sizeof 14h    offset CCh
    zVEC2 posCurrent[2];            // sizeof 10h    offset E0h
    zVEC2 posOpenClose[2];          // sizeof 10h    offset F0h

    void zCView_OnInit()                                                            zCall( 0x00745B40 );
    void zCView_OnInit( int, int, int, int, zTviewID )                              zCall( 0x00745C00 );
    zCView()                                                                        zInit( zCView_OnInit() );
    zCView( int a0, int a1, int a2, int a3, zTviewID a4 = zTviewID::VIEW_ITEM  )    zInit( zCView_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                                     zCall( 0x00745E90 );
    void Init( int, int, int, int, zTviewID )                                       zCall( 0x00746020 );
    void Init( int, int, zSTRING const&, zTviewID )                                 zCall( 0x007461C0 );
    void SetAutoScroll( float )                                                     zCall( 0x00746420 );
    void CheckAutoScroll()                                                          zCall( 0x00746460 );
    void SetTransparency( int )                                                     zCall( 0x00746560 );
    void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                           zCall( 0x00746570 );
    void SetColor( zCOLOR const& )                                                  zCall( 0x00746580 );
    zCOLOR GetColor()                                                               zCall( 0x00746590 );
    void Setflags( int )                                                            zCall( 0x007465A0 );
    void ClrFlags( int )                                                            zCall( 0x007465B0 );
    int HasFlag( int )                                                              zCall( 0x007465D0 );
    void InsertBack( zCTexture* )                                                   zCall( 0x007465F0 );
    void InsertBack( zSTRING const& )                                               zCall( 0x00746630 );
    void InitPrintwin()                                                             zCall( 0x00746730 );
    void BlitText()                                                                 zCall( 0x007467A0 );
    void Top()                                                                      zCall( 0x00746C90 );
    void Create( zSTRING const&, zEViewFX, zEViewFX, float, int )                   zCall( 0x00746D10 );
    void ForceOpen()                                                                zCall( 0x00746E90 );
    void Open()                                                                     zCall( 0x00747100 );
    void Close()                                                                    zCall( 0x00747330 );
    void ApplyOpenClose( zVEC2&, zVEC2& )                                           zCall( 0x00747440 );
    void UpdateOpen()                                                               zCall( 0x007476C0 );
    void UpdateClose()                                                              zCall( 0x00747710 );
    void UpdateOpenZoom()                                                           zCall( 0x007477C0 );
    void UpdateCloseZoom()                                                          zCall( 0x007478C0 );
    void RecalcChildsSize()                                                         zCall( 0x007479D0 );
    void RecalcChildsPos()                                                          zCall( 0x00747A40 );
    void SetPos( int, int )                                                         zCall( 0x00747AB0 );
    void GetPos( int&, int& )                                                       zCall( 0x00747B60 );
    void CalcPixelPos( int&, int& )                                                 zCall( 0x00747B80 );
    void GetPixelPos( int&, int& )                                                  zCall( 0x00747BC0 );
    void Move( int, int )                                                           zCall( 0x00747BE0 );
    void SetSize( int, int )                                                        zCall( 0x00747CA0 );
    void GetSize( int&, int& )                                                      zCall( 0x00747D10 );
    void GetPixelSize( int&, int& )                                                 zCall( 0x00747D30 );
    void GetExtends( int&, int&, int&, int& )                                       zCall( 0x00747D60 );
    void GetScreenExtends( int&, int&, int&, int& )                                 zCall( 0x00747DA0 );
    void GetPixelExtends( float&, float&, float&, float& )                          zCall( 0x00747E10 );
    int IsIn( int, int )                                                            zCall( 0x00747E60 );
    zCView* GetItem( int, int )                                                     zCall( 0x00747EF0 );
    zCViewText* CreateText( int, int, zSTRING const&, float, zCOLOR&, int, int )    zCall( 0x00747FB0 );
    void CheckTimedText()                                                           zCall( 0x00748150 );
    void PrintTimed( int, int, zSTRING const&, float, zCOLOR* )                     zCall( 0x00748220 );
    void PrintTimedCX( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x007482B0 );
    void PrintTimedCY( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x00748400 );
    void PrintTimedCXY( zSTRING const&, float, zCOLOR* )                            zCall( 0x007484C0 );
    void PrintMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )             zCall( 0x00748640 );
    void PrintMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )          zCall( 0x00748950 );
    void PrintSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR& )         zCall( 0x007490B0 );
    void Dialog( int, int, zSTRING const&, float, zCOLOR* )                         zCall( 0x00749240 );
    void DialogCX( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x00749310 );
    void DialogCY( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x00749370 );
    void DialogCXY( zSTRING const&, float, zCOLOR* )                                zCall( 0x00749460 );
    void DialogMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )            zCall( 0x007494B0 );
    void DialogMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )         zCall( 0x00749740 );
    void DialogSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR&, float ) zCall( 0x007499D0 );
    void SetFont( zCFont* )                                                         zCall( 0x00749DF0 );
    void SetFontColor( zCOLOR const& )                                              zCall( 0x00749E10 );
    void SetFont( zSTRING const& )                                                  zCall( 0x00749E20 );
    zCFont* GetFont()                                                               zCall( 0x00749E50 );
    zSTRING GetFontName()                                                           zCall( 0x00749E60 );
    int FontY()                                                                     zCall( 0x00749EF0 );
    int FontSize( zSTRING& )                                                        zCall( 0x00749F10 );
    void Print( int, int, zSTRING const& )                                          zCall( 0x00749F40 );
    void PrintChars( int, int, zSTRING const& )                                     zCall( 0x0074A010 );
    void PrintCX( int, zSTRING const& )                                             zCall( 0x0074A350 );
    void PrintCY( int, zSTRING const& )                                             zCall( 0x0074A440 );
    void PrintCXY( zSTRING const& )                                                 zCall( 0x0074A530 );
    void ClrPrintwin()                                                              zCall( 0x0074A640 );
    zCViewText* CreateText( int, int, zSTRING const& )                              zCall( 0x0074A7B0 );
    zSTRING GetFirstText()                                                          zCall( 0x0074A920 );
    void Nextline( zSTRING const&, float, zCOLOR*, int* )                           zCall( 0x0074A9A0 );
    void DefPrintwin( int, int, int, int )                                          zCall( 0x0074AC30 );
    void Printwin( zSTRING const& )                                                 zCall( 0x0074ADD0 );
    zSTRING Input( int )                                                            zCall( 0x0074B1C0 );
    zSTRING Input( int, zSTRING& )                                                  zCall( 0x0074B260 );
    zSTRING Input( int, int, int, zSTRING& )                                        zCall( 0x0074B810 );
    int InputNumber( int, int )                                                     zCall( 0x0074BAE0 );
    void InsertItem( zCView*, int = False )                                         zCall( 0x0074BFD0 );
    void RemoveItem( zCView* )                                                      zCall( 0x0074C210 );
    void Render()                                                                   zCall( 0x0074C710 );
    zSTRING PatchMenuItemPrintwin()                                                 zCall( 0x0074CC50 );
    static void StdPrintwin( zSTRING const& )                                       zCall( 0x00746400 );
    static void PrintDebug( zSTRING const& )                                        zCall( 0x0074BF90 );
    static void SetShowDebug( int )                                                 zCall( 0x0074BFB0 );
    static int GetShowDebug()                                                       zCall( 0x0074BFC0 );
    static void ChangeMode()                                                        zCall( 0x0074C290 );
    static void SetNextMode()                                                       zCall( 0x0074C2A0 );
    static void SetMode( int, int, int, HWND__** )                                  zCall( 0x0074C2B0 );
    /* for zCViewBase num : 12*/
    virtual int anx( int )                                                          zCall( 0x00746380 );
    virtual int any( int )                                                          zCall( 0x007463C0 );
    virtual int nax( int )                                                          zCall( 0x00746300 );
    virtual int nay( int )                                                          zCall( 0x00746340 );
    virtual int ClipLine( int&, int&, int&, int& )                                  zCall( 0x0074C560 );
    virtual void Line( int, int, int, int, zCOLOR const& )                          zCall( 0x0074C470 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )                   zCall( 0x0043CEC0 );
    virtual int GetCode( int, int )                                                 zCall( 0x0074C520 );
    virtual ~zCView()                                                               zCall( 0x00745CC0 );
    virtual void Blit()                                                             zCall( 0x007468C0 );
    virtual void DrawItems()                                                        zCall( 0x00746C50 );
    /* for zCInputCallback num : 1*/

    // static properties
    static zCView*& stdoutput;
    static zCView*& modal;
    static int& showDebug;
    static float& s_fViewTimePerChar;

    // user API
    #include "zCView.inl"
  };

  extern zCView*& screen;
  inline int PixelToVirtualX( int x ) { return screen->anx( x ); }
  inline int PixelToVirtualY( int y ) { return screen->any( y ); }
  inline int VirtualToPixelX( int x ) { return screen->nax( x ); }
  inline int VirtualToPixelY( int y ) { return screen->nay( y ); }

} // namespace Gothic_II_Classic

#endif // __ZVIEW_H__VER2__