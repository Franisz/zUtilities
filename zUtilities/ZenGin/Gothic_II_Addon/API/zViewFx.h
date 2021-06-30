// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_FX_H__VER3__
#define __ZVIEW_FX_H__VER3__

namespace Gothic_II_Addon {

  class zCViewFX : public zCViewDraw {
  public:
    zCLASS_DECLARATION( zCViewFX )

    typedef enum zEViewFX {
      VIEW_FX_NONE        = 0,
      VIEW_FX_ZOOM        = 1,
      VIEW_FX_FADE        = VIEW_FX_ZOOM << 1,
      VIEW_FX_BOUNCE      = VIEW_FX_FADE << 1,
      VIEW_FX_FORCE_DWORD = 0xffffffff
    } zTViewFX;

    int HasOpened;
    int HasClosed;
    float TimeOpen;
    float TimeClose;
    float DurationOpen;
    float DurationClose;
    unsigned long ModeOpen;
    unsigned long ModeClose;
    zVEC2 TextureOffset[2];

    void zCViewFX_OnInit()                                                                           zCall( 0x00690A60 );
    zCViewFX()                                                                                       zInit( zCViewFX_OnInit() );
    void __fastcall Init( zCViewObject*, int, unsigned long, unsigned long, float, float, zSTRING& ) zCall( 0x00690B60 );
    void __fastcall Open()                                                                           zCall( 0x00690BE0 );
    void __fastcall OpenSafe()                                                                       zCall( 0x00690C10 );
    void __fastcall OpenImmediately()                                                                zCall( 0x00690C90 );
    void __fastcall Close()                                                                          zCall( 0x00690CB0 );
    void __fastcall CloseSafe()                                                                      zCall( 0x00690D00 );
    void __fastcall CloseImmediately()                                                               zCall( 0x00690D90 );
    void __fastcall ApplyOpenCloseFX()                                                               zCall( 0x00690DB0 );
    void __fastcall ApplyOpenFX()                                                                    zCall( 0x00691060 );
    void __fastcall ApplyCloseFX()                                                                   zCall( 0x006911A0 );
    void __fastcall ApplyOpenFade()                                                                  zCall( 0x006912E0 );
    void __fastcall ApplyOpenZoom()                                                                  zCall( 0x00691330 );
    void __fastcall ApplyCloseFade()                                                                 zCall( 0x006913C0 );
    void __fastcall ApplyCloseZoom()                                                                 zCall( 0x00691420 );
    static zCObject* _CreateNewInstance()                                                            zCall( 0x00690940 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                                         zCall( 0x00690A50 );
    virtual ~zCViewFX()                                                                              zCall( 0x00690B40 );
    virtual void __fastcall EvaluateTexturePosition()                                                zCall( 0x006915E0 );
    virtual void __fastcall Blit()                                                                   zCall( 0x006914B0 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewFX.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_FX_H__VER3__