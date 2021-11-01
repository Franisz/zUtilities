// Supported with union (c) 2018-2021 Union team

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

  // sizeof 2Ch
  class zCPositionKey {
  public:
    float t;          // sizeof 04h    offset 00h
    zVEC3 p;          // sizeof 0Ch    offset 04h
    zCQuat rot;       // sizeof 10h    offset 10h
    float tension;    // sizeof 04h    offset 20h
    float continuity; // sizeof 04h    offset 24h
    float bias;       // sizeof 04h    offset 28h

    zCPositionKey() {}
    void SetMat( zMAT4 const& ) zCall( 0x00490F20 );
    zMAT4 GetMat()              zCall( 0x00498AC0 );

    // user API
    #include "zCPositionKey.inl"
  };

  // sizeof 3Ch
  class zCCubicPolynomial {
  public:
    zVEC3 c0;     // sizeof 0Ch    offset 00h
    zVEC3 c1;     // sizeof 0Ch    offset 0Ch
    zVEC3 c2;     // sizeof 0Ch    offset 18h
    zVEC3 c3;     // sizeof 0Ch    offset 24h
    float tmin;   // sizeof 04h    offset 30h
    float tmax;   // sizeof 04h    offset 34h
    float trange; // sizeof 04h    offset 38h

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

  // sizeof 24h
  class zCKBSpline {
  public:
    zCCubicPolynomial* polynom;      // sizeof 04h    offset 00h
    int numPolynomials;              // sizeof 04h    offset 04h
    float* length;                   // sizeof 04h    offset 08h
    float totalLength;               // sizeof 04h    offset 0Ch
    int lastKey;                     // sizeof 04h    offset 10h
    zCArray<zCPositionKey*> keyList; // sizeof 0Ch    offset 14h
    int deleteKeysWhenDone;          // sizeof 04h    offset 20h

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