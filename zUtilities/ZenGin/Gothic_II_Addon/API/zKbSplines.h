// Supported with union (c) 2018 Union team

#ifndef __ZKB_SPLINES_H__VER3__
#define __ZKB_SPLINES_H__VER3__

#include "z3d.h"
#include "zMathTools.h"

namespace Gothic_II_Addon {

  enum zTSplLerpMode {
    zTSPL_LERP_UNDEF,
    zTSPL_LERP_PATH,
    zTSPL_LERP_PATH_IGNOREROLL,
    zTSPL_LERP_PATH_ROTvoidS
  };

  class zCPositionKey {
  public:
    float t;
    zVEC3 p;
    zCQuat rot;
    float tension;
    float continuity;
    float bias;

    zCPositionKey() {}
    void SetMat( zMAT4 const& ) zCall( 0x00490F20 );
    zMAT4 GetMat()              zCall( 0x00498AC0 );

    // user API
    #include "zCPositionKey.inl"
  };

  class zCCubicPolynomial {
  public:
    zVEC3 c0;
    zVEC3 c1;
    zVEC3 c2;
    zVEC3 c3;
    float tmin;
    float tmax;
    float trange;

    void zCCubicPolynomial_OnInit()    zCall( 0x004D61D0 );
    zCCubicPolynomial()                zInit( zCCubicPolynomial_OnInit() );
    ~zCCubicPolynomial()               zCall( 0x004D61E0 );
    void Interpolate1( float, zVEC3& ) zCall( 0x004D6310 );
    float Speed( float )               zCall( 0x004D6E10 );
    float Length( float )              zCall( 0x004D6F30 );
    void Interpolate0( float, zVEC3& ) zCall( 0x004D8970 );

    // user API
    #include "zCCubicPolynomial.inl"
  };

  class zCKBSpline {
  public:
    zCCubicPolynomial* polynom;
    int numPolynomials;
    float* length;
    float totalLength;
    int lastKey;
    zCArray<zCPositionKey*> keyList;
    int deleteKeysWhenDone;

    zCKBSpline() {}
    void InitVars()                                      zCall( 0x00487CD0 );
    ~zCKBSpline()                                        zCall( 0x00488570 );
    void InterpolateN( float, zMAT4&, zTSplLerpMode )    zCall( 0x00498B40 );
    void Initialize( zCArray<zCPositionKey*>&, int )     zCall( 0x004D5B30 );
    void Changed()                                       zCall( 0x004D6240 );
    void Terminate()                                     zCall( 0x004D6290 );
    void ComputeIAndU( float, int&, float& )             zCall( 0x004D63F0 );
    void Interpolate0( float, zVEC3& )                   zCall( 0x004D64A0 );
    void Interpolate0( float, zMAT4&, zTSplLerpMode )    zCall( 0x004D65C0 );
    void Interpolate1( float, zMAT4&, zTSplLerpMode )    zCall( 0x004D6970 );
    void Interpolate1( float, zVEC3& )                   zCall( 0x004D6C30 );
    void Interpolate2( float, zVEC3& )                   zCall( 0x004D6D30 );
    void ComputeArcLength()                              zCall( 0x004D70C0 );
    void InvertIntegral( float, int&, float& )           zCall( 0x004D7290 );
    void Interpolate0_AL( float, zVEC3& )                zCall( 0x004D7630 );
    void Interpolate0_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004D7740 );
    void Interpolate1_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004D7A70 );
    void Interpolate1_AL( float, zVEC3& )                zCall( 0x004D7D60 );
    void Interpolate2_AL( float, zVEC3& )                zCall( 0x004D7E60 );
    float Length( float )                                zCall( 0x004D7F40 );
    void DrawControlPolygon( zCOLOR )                    zCall( 0x004D80D0 );
    void Draw( zCOLOR, float )                           zCall( 0x004D8380 );
    float GetTime( float )                               zCall( 0x004D8A50 );

    // user API
    #include "zCKBSpline.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZKB_SPLINES_H__VER3__