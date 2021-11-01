// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_H__VER3__
#define __ZVIEW_H__VER3__

#include "zGrafix.h"
#include "zDisk.h"
#include "zRenderer.h"
#include "zViewBase.h"

namespace Gothic_II_Addon {
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

    void zCInputCallback_OnInit()    zCall( 0x007A53F0 );
    zCInputCallback()                zInit( zCInputCallback_OnInit() );
    ~zCInputCallback()               zCall( 0x007A5400 );
    void SetHandleEventTop()         zCall( 0x007A5470 );
    void SetEnableHandleEvent( int ) zCall( 0x007A54E0 );
    int GetEnableHandleEvent()       zCall( 0x007A5560 );
    static int DoEvents( int )       zCall( 0x007A5590 );
    static void GetInput()           zCall( 0x007A55C0 );
    virtual int HandleEvent( int )   zCall( 0x0043D4E0 );

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
    void zCViewText_OnInit( int, int, zSTRING const& )                                     zCall( 0x007AC220 );
    void zCViewText_OnInit( int, int, zSTRING const&, float&, zCOLOR&, int, int )          zCall( 0x007AC3E0 );
    zCViewText( int a0, int a1, zSTRING const& a2 )                                        zInit( zCViewText_OnInit( a0, a1, a2 ));
    zCViewText( int a0, int a1, zSTRING const& a2, float& a3, zCOLOR& a4, int a5, int a6 ) zInit( zCViewText_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    void Create( int, int, zSTRING const&, float&, zCOLOR&, int, int )                     zCall( 0x007AC580 );
    virtual ~zCViewText()                                                                  zCall( 0x007AC700 );

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

    void zCView_OnInit()                                                            zCall( 0x007A5640 );
    void zCView_OnInit( int, int, int, int, zTviewID )                              zCall( 0x007A5700 );
    zCView()                                                                        zInit( zCView_OnInit() );
    zCView( int a0, int a1, int a2, int a3, zTviewID a4 = zTviewID::VIEW_ITEM )     zInit( zCView_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                                     zCall( 0x007A5990 );
    void Init( int, int, int, int, zTviewID )                                       zCall( 0x007A5B20 );
    void Init( int, int, zSTRING const&, zTviewID )                                 zCall( 0x007A5CC0 );
    void SetAutoScroll( float )                                                     zCall( 0x007A5F20 );
    void CheckAutoScroll()                                                          zCall( 0x007A5F60 );
    void SetTransparency( int )                                                     zCall( 0x007A6060 );
    void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                           zCall( 0x007A6070 );
    void SetColor( zCOLOR const& )                                                  zCall( 0x007A6080 );
    zCOLOR GetColor()                                                               zCall( 0x007A6090 );
    void Setflags( int )                                                            zCall( 0x007A60A0 );
    void ClrFlags( int )                                                            zCall( 0x007A60B0 );
    int HasFlag( int )                                                              zCall( 0x007A60D0 );
    void InsertBack( zCTexture* )                                                   zCall( 0x007A60F0 );
    void InsertBack( zSTRING const& )                                               zCall( 0x007A6130 );
    void InitPrintwin()                                                             zCall( 0x007A6230 );
    void BlitText()                                                                 zCall( 0x007A62A0 );
    void Top()                                                                      zCall( 0x007A6790 );
    void Create( zSTRING const&, zEViewFX, zEViewFX, float, int )                   zCall( 0x007A6810 );
    void ForceOpen()                                                                zCall( 0x007A6990 );
    void Open()                                                                     zCall( 0x007A6C00 );
    void Close()                                                                    zCall( 0x007A6E30 );
    void ApplyOpenClose( zVEC2&, zVEC2& )                                           zCall( 0x007A6F40 );
    void UpdateOpen()                                                               zCall( 0x007A71C0 );
    void UpdateClose()                                                              zCall( 0x007A7210 );
    void UpdateOpenZoom()                                                           zCall( 0x007A72C0 );
    void UpdateCloseZoom()                                                          zCall( 0x007A73C0 );
    void RecalcChildsSize()                                                         zCall( 0x007A74D0 );
    void RecalcChildsPos()                                                          zCall( 0x007A7540 );
    void SetPos( int, int )                                                         zCall( 0x007A75B0 );
    void GetPos( int&, int& )                                                       zCall( 0x007A7660 );
    void CalcPixelPos( int&, int& )                                                 zCall( 0x007A7680 );
    void GetPixelPos( int&, int& )                                                  zCall( 0x007A76C0 );
    void Move( int, int )                                                           zCall( 0x007A76E0 );
    void SetSize( int, int )                                                        zCall( 0x007A77A0 );
    void GetSize( int&, int& )                                                      zCall( 0x007A7810 );
    void GetPixelSize( int&, int& )                                                 zCall( 0x007A7830 );
    void GetExtends( int&, int&, int&, int& )                                       zCall( 0x007A7860 );
    void GetScreenExtends( int&, int&, int&, int& )                                 zCall( 0x007A78A0 );
    void GetPixelExtends( float&, float&, float&, float& )                          zCall( 0x007A7910 );
    int IsIn( int, int )                                                            zCall( 0x007A7960 );
    zCView* GetItem( int, int )                                                     zCall( 0x007A79F0 );
    zCViewText* CreateText( int, int, zSTRING const&, float, zCOLOR&, int, int )    zCall( 0x007A7AB0 );
    void CheckTimedText()                                                           zCall( 0x007A7C50 );
    void PrintTimed( int, int, zSTRING const&, float, zCOLOR* )                     zCall( 0x007A7D20 );
    void PrintTimedCX( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x007A7DB0 );
    void PrintTimedCY( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x007A7F00 );
    void PrintTimedCXY( zSTRING const&, float, zCOLOR* )                            zCall( 0x007A7FC0 );
    void PrintMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )             zCall( 0x007A8140 );
    void PrintMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )          zCall( 0x007A8450 );
    void PrintSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR& )         zCall( 0x007A8BB0 );
    void Dialog( int, int, zSTRING const&, float, zCOLOR* )                         zCall( 0x007A8D40 );
    void DialogCX( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x007A8E10 );
    void DialogCY( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x007A8E70 );
    void DialogCXY( zSTRING const&, float, zCOLOR* )                                zCall( 0x007A8F60 );
    void DialogMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )            zCall( 0x007A8FB0 );
    void DialogMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )         zCall( 0x007A9240 );
    void DialogSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR&, float ) zCall( 0x007A94D0 );
    void SetFont( zCFont* )                                                         zCall( 0x007A98F0 );
    void SetFontColor( zCOLOR const& )                                              zCall( 0x007A9910 );
    void SetFont( zSTRING const& )                                                  zCall( 0x007A9920 );
    zCFont* GetFont()                                                               zCall( 0x007A9950 );
    zSTRING GetFontName()                                                           zCall( 0x007A9960 );
    int FontY()                                                                     zCall( 0x007A99F0 );
    int FontSize( zSTRING& )                                                        zCall( 0x007A9A10 );
    void Print( int, int, zSTRING const& )                                          zCall( 0x007A9A40 );
    void PrintChars( int, int, zSTRING const& )                                     zCall( 0x007A9B10 );
    void PrintCX( int, zSTRING const& )                                             zCall( 0x007A9E50 );
    void PrintCY( int, zSTRING const& )                                             zCall( 0x007A9F40 );
    void PrintCXY( zSTRING const& )                                                 zCall( 0x007AA030 );
    void ClrPrintwin()                                                              zCall( 0x007AA140 );
    zCViewText* CreateText( int, int, zSTRING const& )                              zCall( 0x007AA2B0 );
    zSTRING GetFirstText()                                                          zCall( 0x007AA420 );
    void Nextline( zSTRING const&, float, zCOLOR*, int* )                           zCall( 0x007AA4A0 );
    void DefPrintwin( int, int, int, int )                                          zCall( 0x007AA730 );
    void Printwin( zSTRING const& )                                                 zCall( 0x007AA8D0 );
    zSTRING Input( int )                                                            zCall( 0x007AACC0 );
    zSTRING Input( int, zSTRING& )                                                  zCall( 0x007AAD60 );
    zSTRING Input( int, int, int, zSTRING& )                                        zCall( 0x007AB310 );
    int InputNumber( int, int )                                                     zCall( 0x007AB5E0 );
    void InsertItem( zCView*, int = False )                                         zCall( 0x007ABAD0 );
    void RemoveItem( zCView* )                                                      zCall( 0x007ABD10 );
    void Render()                                                                   zCall( 0x007AC210 );
    zSTRING PatchMenuItemPrintwin()                                                 zCall( 0x007AC750 );
    static void StdPrintwin( zSTRING const& )                                       zCall( 0x007A5F00 );
    static void PrintDebug( zSTRING const& )                                        zCall( 0x007ABA90 );
    static void SetShowDebug( int )                                                 zCall( 0x007ABAB0 );
    static int GetShowDebug()                                                       zCall( 0x007ABAC0 );
    static void ChangeMode()                                                        zCall( 0x007ABD90 );
    static void SetNextMode()                                                       zCall( 0x007ABDA0 );
    static void SetMode( int, int, int, HWND__** )                                  zCall( 0x007ABDB0 );
    /* for zCViewBase num : 12*/
    virtual int anx( int )                                                          zCall( 0x007A5E80 );
    virtual int any( int )                                                          zCall( 0x007A5EC0 );
    virtual int nax( int )                                                          zCall( 0x007A5E00 );
    virtual int nay( int )                                                          zCall( 0x007A5E40 );
    virtual int ClipLine( int&, int&, int&, int& )                                  zCall( 0x007AC060 );
    virtual void Line( int, int, int, int, zCOLOR const& )                          zCall( 0x007ABF70 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )                   zCall( 0x0043D4F0 );
    virtual int GetCode( int, int )                                                 zCall( 0x007AC020 );
    virtual ~zCView()                                                               zCall( 0x007A57C0 );
    virtual void Blit()                                                             zCall( 0x007A63C0 );
    virtual void DrawItems()                                                        zCall( 0x007A6750 );
    /* for zCInputCallback num : 1*/

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

} // namespace Gothic_II_Addon

#endif // __ZVIEW_H__VER3__