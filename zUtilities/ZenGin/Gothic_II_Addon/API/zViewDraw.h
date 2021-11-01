// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_DRAW_H__VER3__
#define __ZVIEW_DRAW_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 7Ch
  class zCViewDraw : public zCViewObject {
  public:
    zCLASS_DECLARATION( zCViewDraw )

    zTRnd_AlphaBlendFunc TextureFuncAlpha; // sizeof 04h    offset 5Ch
    zCTexture* Texture;                    // sizeof 04h    offset 60h
    zCOLOR TextureColor;                   // sizeof 04h    offset 64h
    int TextureAlpha;                      // sizeof 04h    offset 68h
    zVEC2 TexturePosition[2];              // sizeof 10h    offset 6Ch

    void zCViewDraw_OnInit()                                                zCall( 0x0068FD20 );
    zCViewDraw()                                                            zInit( zCViewDraw_OnInit() );
    void __fastcall RemoveChild( zSTRING& )                                 zCall( 0x0068FE60 );
    void __fastcall SetTextureAlphaBlendFunc( zTRnd_AlphaBlendFunc const& ) zCall( 0x0068FF50 );
    void __fastcall SetTexture( zSTRING const& )                            zCall( 0x0068FF60 );
    void __fastcall SetTexture( zCTexture* )                                zCall( 0x00690040 );
    void __fastcall SetTextureColor( zCOLOR const& )                        zCall( 0x00690080 );
    void __fastcall SetTextureAlpha( int )                                  zCall( 0x00690090 );
    void __fastcall TextureCacheIn( float )                                 zCall( 0x006900A0 );
    void __fastcall Render()                                                zCall( 0x006900E0 );
    void __fastcall Draw()                                                  zCall( 0x006901F0 );
    void __fastcall DrawChildren()                                          zCall( 0x00690300 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x0068FC00 );
    static zCViewDraw& GetScreen()                                          zCall( 0x006905C0 );
    static void CleanupScreen()                                             zCall( 0x006906F0 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x0068FD10 );
    virtual ~zCViewDraw()                                                   zCall( 0x0068FDE0 );
    virtual void __fastcall EvaluateTexturePosition()                       zCall( 0x00690540 );
    virtual void __fastcall BlitTexture()                                   zCall( 0x00690490 );
    virtual void __fastcall Blit()                                          zCall( 0x00690430 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewDraw.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_DRAW_H__VER3__