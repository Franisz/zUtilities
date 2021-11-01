// Supported with union (c) 2018-2021 Union team

#ifndef __ZKB_SPLINES_H__VER0__
#define __ZKB_SPLINES_H__VER0__

#include "z3d.h"
#include "zView.h"
#include "zMathTools.h"

namespace Gothic_I_Classic {

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
    void SetMat( zMAT4 const& ) zCall( 0x004890E0 );

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

    void zCCubicPolynomial_OnInit()    zCall( 0x004C95A0 );
    zCCubicPolynomial()                zInit( zCCubicPolynomial_OnInit() );
    ~zCCubicPolynomial()               zCall( 0x004C95B0 );
    void Interpolate1( float, zVEC3& ) zCall( 0x004C96E0 );
    float Speed( float )               zCall( 0x004CA1E0 );
    float Length( float )              zCall( 0x004CA300 );
    void Interpolate0( float, zVEC3& ) zCall( 0x004CBD50 );

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
    void InitVars()                                      zCall( 0x00480300 );
    ~zCKBSpline()                                        zCall( 0x00480B80 );
    void InterpolateN( float, zMAT4&, zTSplLerpMode )    zCall( 0x0048F0E0 );
    void Initialize( zCArray<zCPositionKey*>&, int )     zCall( 0x004C8F00 );
    void Changed()                                       zCall( 0x004C9610 );
    void Terminate()                                     zCall( 0x004C9660 );
    void ComputeIAndU( float, int&, float& )             zCall( 0x004C97C0 );
    void Interpolate0( float, zVEC3& )                   zCall( 0x004C9870 );
    void Interpolate0( float, zMAT4&, zTSplLerpMode )    zCall( 0x004C9990 );
    void Interpolate1( float, zMAT4&, zTSplLerpMode )    zCall( 0x004C9D40 );
    void Interpolate1( float, zVEC3& )                   zCall( 0x004CA000 );
    void Interpolate2( float, zVEC3& )                   zCall( 0x004CA100 );
    void ComputeArcLength()                              zCall( 0x004CA490 );
    void InvertIntegral( float, int&, float& )           zCall( 0x004CA670 );
    void Interpolate0_AL( float, zVEC3& )                zCall( 0x004CAA10 );
    void Interpolate0_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004CAB20 );
    void Interpolate1_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004CAE50 );
    void Interpolate1_AL( float, zVEC3& )                zCall( 0x004CB140 );
    void Interpolate2_AL( float, zVEC3& )                zCall( 0x004CB240 );
    float Length( float )                                zCall( 0x004CB320 );
    void DrawControlPolygon( zCOLOR )                    zCall( 0x004CB4B0 );
    void Draw( zCOLOR, float )                           zCall( 0x004CB760 );
    float GetTime( float )                               zCall( 0x004CBE30 );

    // user API
    #include "zCKBSpline.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZKB_SPLINES_H__VER0__