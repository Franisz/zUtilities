// Supported with union (c) 2018 Union team

#ifndef __ZKB_SPLINES_H__VER2__
#define __ZKB_SPLINES_H__VER2__

#include "z3d.h"
#include "zMathTools.h"

namespace Gothic_II_Classic {

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
    void SetMat( zMAT4 const& ) zCall( 0x0048F580 );
    zMAT4 GetMat()              zCall( 0x00496E10 );

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

    void zCCubicPolynomial_OnInit()    zCall( 0x004D3C10 );
    zCCubicPolynomial()                zInit( zCCubicPolynomial_OnInit() );
    ~zCCubicPolynomial()               zCall( 0x004D3C20 );
    void Interpolate1( float, zVEC3& ) zCall( 0x004D3D50 );
    float Speed( float )               zCall( 0x004D4850 );
    float Length( float )              zCall( 0x004D4970 );
    void Interpolate0( float, zVEC3& ) zCall( 0x004D63B0 );

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
    void InitVars()                                      zCall( 0x00486670 );
    ~zCKBSpline()                                        zCall( 0x00486F10 );
    void InterpolateN( float, zMAT4&, zTSplLerpMode )    zCall( 0x00496E90 );
    void Initialize( zCArray<zCPositionKey*>&, int )     zCall( 0x004D3570 );
    void Changed()                                       zCall( 0x004D3C80 );
    void Terminate()                                     zCall( 0x004D3CD0 );
    void ComputeIAndU( float, int&, float& )             zCall( 0x004D3E30 );
    void Interpolate0( float, zVEC3& )                   zCall( 0x004D3EE0 );
    void Interpolate0( float, zMAT4&, zTSplLerpMode )    zCall( 0x004D4000 );
    void Interpolate1( float, zMAT4&, zTSplLerpMode )    zCall( 0x004D43B0 );
    void Interpolate1( float, zVEC3& )                   zCall( 0x004D4670 );
    void Interpolate2( float, zVEC3& )                   zCall( 0x004D4770 );
    void ComputeArcLength()                              zCall( 0x004D4B00 );
    void InvertIntegral( float, int&, float& )           zCall( 0x004D4CD0 );
    void Interpolate0_AL( float, zVEC3& )                zCall( 0x004D5070 );
    void Interpolate0_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004D5180 );
    void Interpolate1_AL( float, zMAT4&, zTSplLerpMode ) zCall( 0x004D54B0 );
    void Interpolate1_AL( float, zVEC3& )                zCall( 0x004D57A0 );
    void Interpolate2_AL( float, zVEC3& )                zCall( 0x004D58A0 );
    float Length( float )                                zCall( 0x004D5980 );
    void DrawControlPolygon( zCOLOR )                    zCall( 0x004D5B10 );
    void Draw( zCOLOR, float )                           zCall( 0x004D5DC0 );
    float GetTime( float )                               zCall( 0x004D6490 );

    // user API
    #include "zCKBSpline.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZKB_SPLINES_H__VER2__