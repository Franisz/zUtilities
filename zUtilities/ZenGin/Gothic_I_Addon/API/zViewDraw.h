// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_DRAW_H__VER1__
#define __ZVIEW_DRAW_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 7Ch
  class zCViewDraw : public zCViewObject {
  public:
    zCLASS_DECLARATION( zCViewDraw )

    zTRnd_AlphaBlendFunc TextureFuncAlpha; // sizeof 04h    offset 5Ch
    zCTexture* Texture;                    // sizeof 04h    offset 60h
    zCOLOR TextureColor;                   // sizeof 04h    offset 64h
    int TextureAlpha;                      // sizeof 04h    offset 68h
    zVEC2 TexturePosition[2];              // sizeof 10h    offset 6Ch

    void zCViewDraw_OnInit()                                                zCall( 0x007956F0 );
    zCViewDraw()                                                            zInit( zCViewDraw_OnInit() );
    void __fastcall RemoveChild( zSTRING& )                                 zCall( 0x00795830 );
    void __fastcall SetTextureAlphaBlendFunc( zTRnd_AlphaBlendFunc const& ) zCall( 0x00795920 );
    void __fastcall SetTexture( zSTRING const& )                            zCall( 0x00795930 );
    void __fastcall SetTexture( zCTexture* )                                zCall( 0x00795A20 );
    void __fastcall SetTextureColor( zCOLOR const& )                        zCall( 0x00795A60 );
    void __fastcall SetTextureAlpha( int )                                  zCall( 0x00795A70 );
    void __fastcall Render()                                                zCall( 0x00795A80 );
    void __fastcall Draw()                                                  zCall( 0x00795B80 );
    void __fastcall DrawChildren()                                          zCall( 0x00795C80 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x007955C0 );
    static zCViewDraw& GetScreen()                                          zCall( 0x00795F10 );
    static void CleanupScreen()                                             zCall( 0x00796050 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x007956E0 );
    virtual ~zCViewDraw()                                                   zCall( 0x007957B0 );
    virtual void __fastcall EvaluateTexturePosition()                       zCall( 0x00795E90 );
    virtual void __fastcall BlitTexture()                                   zCall( 0x00795E00 );
    virtual void __fastcall Blit()                                          zCall( 0x00795DA0 );
    /* for zCViewBase num : 8*/

    // user API
    #include "zCViewDraw.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_DRAW_H__VER1__