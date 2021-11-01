// Supported with union (c) 2018-2021 Union team

#ifndef __ZKB_SPLINES_H__VER1__
#define __ZKB_SPLINES_H__VER1__

#include "z3d.h"
#include "zMathTools.h"

namespace Gothic_I_Addon {

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
    zMAT4 GetMat() zCall( 0x004997F0 );

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

    void zCCubicPolynomial_OnInit()    zCall( 0x004D9940 );
    zCCubicPolynomial()                zInit( zCCubicPolynomial_OnInit() );
    ~zCCubicPolynomial()               zCall( 0x004D9950 );
    float Speed( float )               zCall( 0x004DA680 );
    float Length( float )              zCall( 0x004DA7D0 );
    void Interpolate0( float, zVEC3& ) zCall( 0x004DC340 );

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
    void InitVars()                                      zCall( 0x0048B160 );
    ~zCKBSpline()                                        zCall( 0x0048B9F0 );
    void InterpolateN( float, zMAT4&, zTSplLerpMode )    zCall( 0x0049AEA0 );
    void Initialize( zCArray<zCPositionKey*>&, int )     zCall( 0x004D9130 );
    void Changed()                                       zCall( 0x004D99B0 );
    void Terminate()                                     zCall( 0x004D9A00 );
    void ComputeIAndU( float, int&, float& )             zCall( 0x004D9A80 );
    void Interpolate0( float, zVEC3& )                   zCall( 0x004D9B40 );
    void Interpolate0( float, zMAT4&, zTSplLerpMode )    zCall( 0x004D9D30 );
    void Interpolate1( float, zMAT4&, zTSplLerpMode )    zCall( 0x004DA0E0 );
    void Interpolate1( float, zVEC3& )                   zCall( 0x004DA3C0 );
    void Interpolate2( float, zVEC3& )                   zCall( 0x004DA550 );
    void ComputeArcLength()                              zCall( 0x004DA940 );
    void InvertIntegral( float, int&, float& )           zCall( 0x004DAB40 );
    void Interpolate0_AL( float, zVEC3& )                zCall( 0x004DAF00 );
    void Interpolate0_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004DB0E0 );
    void Interpolate1_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004DB410 );
    void Interpolate1_AL( float, zVEC3& )                zCall( 0x004DB6F0 );
    void Interpolate2_AL( float, zVEC3& )                zCall( 0x004DB880 );
    float Length( float )                                zCall( 0x004DB9B0 );
    void DrawControlPolygon( zCOLOR )                    zCall( 0x004DBB80 );
    void Draw( zCOLOR, float )                           zCall( 0x004DBDF0 );
    float GetTime( float )                               zCall( 0x004DC4F0 );

    // user API
    #include "zCKBSpline.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZKB_SPLINES_H__VER1__