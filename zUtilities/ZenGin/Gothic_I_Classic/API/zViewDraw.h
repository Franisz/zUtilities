// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_DRAW_H__VER0__
#define __ZVIEW_DRAW_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 7Ch
  class zCViewDraw : public zCViewObject {
  public:
    zCLASS_DECLARATION( zCViewDraw )

    zTRnd_AlphaBlendFunc TextureFuncAlpha; // sizeof 04h    offset 5Ch
    zCTexture* Texture;                    // sizeof 04h    offset 60h
    zCOLOR TextureColor;                   // sizeof 04h    offset 64h
    int TextureAlpha;                      // sizeof 04h    offset 68h
    zVEC2 TexturePosition[2];              // sizeof 10h    offset 6Ch

    void zCViewDraw_OnInit()                                                zCall( 0x00753250 );
    zCViewDraw()                                                            zInit( zCViewDraw_OnInit() );
    void __fastcall RemoveChild( zSTRING& )                                 zCall( 0x00753390 );
    void __fastcall SetTextureAlphaBlendFunc( zTRnd_AlphaBlendFunc const& ) zCall( 0x00753480 );
    void __fastcall SetTexture( zSTRING const& )                            zCall( 0x00753490 );
    void __fastcall SetTexture( zCTexture* )                                zCall( 0x00753570 );
    void __fastcall SetTextureColor( zCOLOR const& )                        zCall( 0x007535B0 );
    void __fastcall SetTextureAlpha( int )                                  zCall( 0x007535C0 );
    void __fastcall Render()                                                zCall( 0x007535D0 );
    void __fastcall Draw()                                                  zCall( 0x007536D0 );
    void __fastcall DrawChildren()                                          zCall( 0x007537D0 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x00753120 );
    static zCViewDraw& GetScreen()                                          zCall( 0x00753A60 );
    static void CleanupScreen()                                             zCall( 0x00753BA0 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x00753240 );
    virtual ~zCViewDraw()                                                   zCall( 0x00753310 );
    virtual void __fastcall EvaluateTexturePosition()                       zCall( 0x007539E0 );
    virtual void __fastcall BlitTexture()                                   zCall( 0x00753950 );
    virtual void __fastcall Blit()                                          zCall( 0x007538F0 );
    /* for zCViewBase num : 8*/

    // user API
    #include "zCViewDraw.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_DRAW_H__VER0__