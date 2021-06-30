// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_FX_H__VER2__
#define __ZVIEW_FX_H__VER2__

namespace Gothic_II_Classic {

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

    void zCViewFX_OnInit()                                                                           zCall( 0x007A0CB0 );
    zCViewFX()                                                                                       zInit( zCViewFX_OnInit() );
    void __fastcall Init( zCViewObject*, int, unsigned long, unsigned long, float, float, zSTRING& ) zCall( 0x007A0DB0 );
    void __fastcall Open()                                                                           zCall( 0x007A0E30 );
    void __fastcall OpenSafe()                                                                       zCall( 0x007A0E60 );
    void __fastcall OpenImmediately()                                                                zCall( 0x007A0EE0 );
    void __fastcall Close()                                                                          zCall( 0x007A0F00 );
    void __fastcall CloseSafe()                                                                      zCall( 0x007A0F50 );
    void __fastcall CloseImmediately()                                                               zCall( 0x007A0FE0 );
    void __fastcall ApplyOpenCloseFX()                                                               zCall( 0x007A1000 );
    void __fastcall ApplyOpenFX()                                                                    zCall( 0x007A12B0 );
    void __fastcall ApplyCloseFX()                                                                   zCall( 0x007A13F0 );
    void __fastcall ApplyOpenFade()                                                                  zCall( 0x007A1530 );
    void __fastcall ApplyOpenZoom()                                                                  zCall( 0x007A1580 );
    void __fastcall ApplyCloseFade()                                                                 zCall( 0x007A1610 );
    void __fastcall ApplyCloseZoom()                                                                 zCall( 0x007A1670 );
    static zCObject* _CreateNewInstance()                                                            zCall( 0x007A0B90 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                                         zCall( 0x007A0CA0 );
    virtual ~zCViewFX()                                                                              zCall( 0x007A0D90 );
    virtual void __fastcall EvaluateTexturePosition()                                                zCall( 0x007A1830 );
    virtual void __fastcall Blit()                                                                   zCall( 0x007A1700 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewFX.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_FX_H__VER2__