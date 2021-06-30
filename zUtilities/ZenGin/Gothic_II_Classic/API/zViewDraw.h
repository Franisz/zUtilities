// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DRAW_H__VER2__
#define __ZVIEW_DRAW_H__VER2__

namespace Gothic_II_Classic {

  class zCViewDraw : public zCViewObject {
  public:
    zCLASS_DECLARATION( zCViewDraw )

    zTRnd_AlphaBlendFunc TextureFuncAlpha;
    zCTexture* Texture;
    zCOLOR TextureColor;
    int TextureAlpha;
    zVEC2 TexturePosition[2];

    void zCViewDraw_OnInit()                                                zCall( 0x0079FF70 );
    zCViewDraw()                                                            zInit( zCViewDraw_OnInit() );
    void __fastcall RemoveChild( zSTRING& )                                 zCall( 0x007A00B0 );
    void __fastcall SetTextureAlphaBlendFunc( zTRnd_AlphaBlendFunc const& ) zCall( 0x007A01A0 );
    void __fastcall SetTexture( zSTRING const& )                            zCall( 0x007A01B0 );
    void __fastcall SetTexture( zCTexture* )                                zCall( 0x007A0290 );
    void __fastcall SetTextureColor( zCOLOR const& )                        zCall( 0x007A02D0 );
    void __fastcall SetTextureAlpha( int )                                  zCall( 0x007A02E0 );
    void __fastcall TextureCacheIn( float )                                 zCall( 0x007A02F0 );
    void __fastcall Render()                                                zCall( 0x007A0330 );
    void __fastcall Draw()                                                  zCall( 0x007A0440 );
    void __fastcall DrawChildren()                                          zCall( 0x007A0550 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x0079FE50 );
    static zCViewDraw& GetScreen()                                          zCall( 0x007A0810 );
    static void CleanupScreen()                                             zCall( 0x007A0940 );
    /* for zCObject num : 7*/
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x0079FF60 );
    virtual ~zCViewDraw()                                                   zCall( 0x007A0030 );
    virtual void __fastcall EvaluateTexturePosition()                       zCall( 0x007A0790 );
    virtual void __fastcall BlitTexture()                                   zCall( 0x007A06E0 );
    virtual void __fastcall Blit()                                          zCall( 0x007A0680 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewDraw.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_DRAW_H__VER2__