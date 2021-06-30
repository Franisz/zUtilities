// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_H__VER1__
#define __ZVIEW_H__VER1__

#include "zDisk.h"
#include "zRenderer.h"
#include "zViewBase.h"

namespace Gothic_I_Addon {
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

  class zCInputCallback {
  public:

    void zCInputCallback_OnInit()    zCall( 0x00735C50 );
    zCInputCallback()                zInit( zCInputCallback_OnInit() );
    ~zCInputCallback()               zCall( 0x00735C60 );
    void SetHandleEventTop()         zCall( 0x00735CE0 );
    void SetEnableHandleEvent( int ) zCall( 0x00735D60 );
    int GetEnableHandleEvent()       zCall( 0x00735DF0 );
    static int DoEvents( int )       zCall( 0x00735E10 );
    static void GetInput()           zCall( 0x00735E40 );
    virtual int HandleEvent( int )   zCall( 0x0043E550 );

    static zCList<zCInputCallback>& inputList;

    // user API
    #include "zCInputCallback.inl"
  };

  class zCViewText {
  public:
    int posx;
    int posy;
    zSTRING text;
    zCFont* font;
    float timer;
    int inPrintWin;
    zCOLOR color;
    int timed;
    int colored;

    zCViewText() {}
    void zCViewText_OnInit( int, int, zSTRING const& )                                     zCall( 0x0073CDD0 );
    void zCViewText_OnInit( int, int, zSTRING const&, float&, zCOLOR&, int, int )          zCall( 0x0073CF90 );
    zCViewText( int a0, int a1, zSTRING const& a2 )                                        zInit( zCViewText_OnInit( a0, a1, a2 ));
    zCViewText( int a0, int a1, zSTRING const& a2, float& a3, zCOLOR& a4, int a5, int a6 ) zInit( zCViewText_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    void Create( int, int, zSTRING const&, float&, zCOLOR&, int, int )                     zCall( 0x0073D120 );
    virtual ~zCViewText()                                                                  zCall( 0x0073D290 );

    // user API
    #include "zCViewText.inl"
  };

  class zCView : public zCViewBase, public zCInputCallback {
  public:
    typedef enum zEViewFX {
      VIEW_FX_NONE,
      VIEW_FX_ZOOM,
      VIEW_FX_MAX
    } zTViewFX;

    zCView* next;
    zTviewID viewID;
    int flags;
    int intflags;
    int ondesk;
    zTRnd_AlphaBlendFunc alphafunc;
    zCOLOR color;
    int alpha;
    zList<zCView> childs;
    zCView* owner;
    zCTexture* backTex;
    int vposx;
    int vposy;
    int vsizex;
    int vsizey;
    int pposx;
    int pposy;
    int psizex;
    int psizey;
    zCFont* font;
    zCOLOR fontColor;
    int px1;
    int py1;
    int px2;
    int py2;
    int winx;
    int winy;
    zCList<zCViewText> textLines;
    float scrollMaxTime;
    float scrollTimer;
    zTViewFX fxOpen;
    zTViewFX fxClose;
    float timeDialog;
    float timeOpen;
    float timeClose;
    float speedOpen;
    float speedClose;
    int isOpen;
    int isClosed;
    int continueOpen;
    int continueClose;
    int removeOnClose;
    int resizeOnOpen;
    int maxTextLength;
    zSTRING textMaxLength;
    zVEC2 posCurrent[2];
    zVEC2 posOpenClose[2];

    void zCView_OnInit()                                                            zCall( 0x00735EC0 );
    void zCView_OnInit( int, int, int, int, zTviewID )                              zCall( 0x00735F80 );
    zCView()                                                                        zInit( zCView_OnInit() );
    zCView( int a0, int a1, int a2, int a3, zTviewID a4 = zTviewID::VIEW_ITEM )     zInit( zCView_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                                     zCall( 0x00736230 );
    void Init( int, int, int, int, zTviewID )                                       zCall( 0x007363C0 );
    void Init( int, int, zSTRING const&, zTviewID )                                 zCall( 0x00736560 );
    void SetAutoScroll( float )                                                     zCall( 0x007367C0 );
    void CheckAutoScroll()                                                          zCall( 0x00736800 );
    void SetTransparency( int )                                                     zCall( 0x00736910 );
    void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                           zCall( 0x00736920 );
    void SetColor( zCOLOR const& )                                                  zCall( 0x00736930 );
    zCOLOR GetColor()                                                               zCall( 0x00736940 );
    void Setflags( int )                                                            zCall( 0x00736950 );
    void ClrFlags( int )                                                            zCall( 0x00736960 );
    int HasFlag( int )                                                              zCall( 0x00736980 );
    void InsertBack( zCTexture* )                                                   zCall( 0x007369A0 );
    void InsertBack( zSTRING const& )                                               zCall( 0x007369E0 );
    void InitPrintwin()                                                             zCall( 0x00736AF0 );
    void BlitText()                                                                 zCall( 0x00736B70 );
    void Top()                                                                      zCall( 0x00736FD0 );
    void Create( zSTRING const&, zEViewFX, zEViewFX, float, int )                   zCall( 0x00737050 );
    void ForceOpen()                                                                zCall( 0x007371D0 );
    void Open()                                                                     zCall( 0x00737440 );
    void Close()                                                                    zCall( 0x00737660 );
    void ApplyOpenClose( zVEC2&, zVEC2& )                                           zCall( 0x00737780 );
    void UpdateOpen()                                                               zCall( 0x00737A00 );
    void UpdateClose()                                                              zCall( 0x00737A50 );
    void UpdateOpenZoom()                                                           zCall( 0x00737B00 );
    void UpdateCloseZoom()                                                          zCall( 0x00737C00 );
    void RecalcChildsSize()                                                         zCall( 0x00737D20 );
    void RecalcChildsPos()                                                          zCall( 0x00737DA0 );
    void SetPos( int, int )                                                         zCall( 0x00737E00 );
    void GetPos( int&, int& )                                                       zCall( 0x00737EB0 );
    void CalcPixelPos( int&, int& )                                                 zCall( 0x00737ED0 );
    void GetPixelPos( int&, int& )                                                  zCall( 0x00737F10 );
    void Move( int, int )                                                           zCall( 0x00737F30 );
    void SetSize( int, int )                                                        zCall( 0x00737FF0 );
    void GetSize( int&, int& )                                                      zCall( 0x00738060 );
    void GetPixelSize( int&, int& )                                                 zCall( 0x00738080 );
    void GetExtends( int&, int&, int&, int& )                                       zCall( 0x007380B0 );
    void GetScreenExtends( int&, int&, int&, int& )                                 zCall( 0x007380F0 );
    void GetPixelExtends( float&, float&, float&, float& )                          zCall( 0x00738160 );
    int IsIn( int, int )                                                            zCall( 0x007381B0 );
    zCView* GetItem( int, int )                                                     zCall( 0x00738240 );
    zCViewText* CreateText( int, int, zSTRING const&, float, zCOLOR&, int, int )    zCall( 0x00738300 );
    void CheckTimedText()                                                           zCall( 0x007384E0 );
    void PrintTimed( int, int, zSTRING const&, float, zCOLOR* )                     zCall( 0x007385A0 );
    void PrintTimedCX( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x00738630 );
    void PrintTimedCY( int, zSTRING const&, float, zCOLOR* )                        zCall( 0x007387B0 );
    void PrintTimedCXY( zSTRING const&, float, zCOLOR* )                            zCall( 0x00738870 );
    void PrintMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )             zCall( 0x00738A10 );
    void PrintMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )          zCall( 0x00738DD0 );
    void PrintSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR& )         zCall( 0x007395D0 );
    void Dialog( int, int, zSTRING const&, float, zCOLOR* )                         zCall( 0x00739750 );
    void DialogCX( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x00739820 );
    void DialogCY( int, zSTRING const&, float, zCOLOR* )                            zCall( 0x00739880 );
    void DialogCXY( zSTRING const&, float, zCOLOR* )                                zCall( 0x00739970 );
    void DialogMessage( zSTRING const&, zSTRING const&, float, zCOLOR& )            zCall( 0x007399C0 );
    void DialogMessageCXY( zSTRING const&, zSTRING const&, float, zCOLOR& )         zCall( 0x00739C70 );
    void DialogSelection( zSTRING const&, zSTRING const&, zCOLOR&, zCOLOR&, float ) zCall( 0x00739F20 );
    void SetFont( zCFont* )                                                         zCall( 0x0073A360 );
    void SetFontColor( zCOLOR const& )                                              zCall( 0x0073A380 );
    void SetFont( zSTRING const& )                                                  zCall( 0x0073A390 );
    zCFont* GetFont()                                                               zCall( 0x0073A3C0 );
    zSTRING GetFontName()                                                           zCall( 0x0073A3D0 );
    int FontY()                                                                     zCall( 0x0073A460 );
    int FontSize( zSTRING& )                                                        zCall( 0x0073A480 );
    void Print( int, int, zSTRING const& )                                          zCall( 0x0073A4B0 );
    void PrintChars( int, int, zSTRING const& )                                     zCall( 0x0073A580 );
    void PrintCX( int, zSTRING const& )                                             zCall( 0x0073A890 );
    void PrintCY( int, zSTRING const& )                                             zCall( 0x0073A990 );
    void PrintCXY( zSTRING const& )                                                 zCall( 0x0073AA90 );
    void ClrPrintwin()                                                              zCall( 0x0073ABB0 );
    zCViewText* CreateText( int, int, zSTRING const& )                              zCall( 0x0073AD20 );
    zSTRING GetFirstText()                                                          zCall( 0x0073AED0 );
    void Nextline( zSTRING const&, float, zCOLOR*, int* )                           zCall( 0x0073AF40 );
    void DefPrintwin( int, int, int, int )                                          zCall( 0x0073B1E0 );
    void Printwin( zSTRING const& )                                                 zCall( 0x0073B380 );
    zSTRING Input( int )                                                            zCall( 0x0073B810 );
    zSTRING Input( int, zSTRING& )                                                  zCall( 0x0073B8C0 );
    zSTRING Input( int, int, int, zSTRING& )                                        zCall( 0x0073BE90 );
    int InputNumber( int, int )                                                     zCall( 0x0073C190 );
    void InsertItem( zCView*, int = False )                                         zCall( 0x0073C660 );
    void RemoveItem( zCView* )                                                      zCall( 0x0073C8B0 );
    void Render()                                                                   zCall( 0x0073CDC0 );
    zSTRING PatchMenuItemPrintwin()                                                 zCall( 0x0073D2F0 );
    static void StdPrintwin( zSTRING const& )                                       zCall( 0x007367A0 );
    static void PrintDebug( zSTRING const& )                                        zCall( 0x0073C620 );
    static void SetShowDebug( int )                                                 zCall( 0x0073C640 );
    static int GetShowDebug()                                                       zCall( 0x0073C650 );
    static void ChangeMode()                                                        zCall( 0x0073C930 );
    static void SetNextMode()                                                       zCall( 0x0073C940 );
    static void SetMode( int, int, int, HWND__** )                                  zCall( 0x0073C950 );
    /* for zCViewBase num : 11*/
    virtual int anx( int )                                                          zCall( 0x00736720 );
    virtual int any( int )                                                          zCall( 0x00736760 );
    virtual int nax( int )                                                          zCall( 0x007366A0 );
    virtual int nay( int )                                                          zCall( 0x007366E0 );
    virtual int ClipLine( int&, int&, int&, int& )                                  zCall( 0x0073CC10 );
    virtual void Line( int, int, int, int, zCOLOR const& )                          zCall( 0x0073CB20 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )                   zCall( 0x0043E560 );
    virtual int GetCode( int, int )                                                 zCall( 0x0073CBD0 );
    virtual ~zCView()                                                               zCall( 0x00736040 );
    virtual void Blit()                                                             zCall( 0x00736C80 );
    virtual void DrawItems()                                                        zCall( 0x00736F90 );
    /* for zCInputCallback num : 1*/

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

} // namespace Gothic_I_Addon

#endif // __ZVIEW_H__VER1__