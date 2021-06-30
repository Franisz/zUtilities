// Supported with union (c) 2018 Union team

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

  class zCPositionKey {
  public:
    float t;
    zVEC3 p;
    zCQuat rot;
    float tension;
    float continuity;
    float bias;

    zCPositionKey() {}
    zMAT4 GetMat() zCall( 0x004997F0 );

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

    void zCCubicPolynomial_OnInit()    zCall( 0x004D9940 );
    zCCubicPolynomial()                zInit( zCCubicPolynomial_OnInit() );
    ~zCCubicPolynomial()               zCall( 0x004D9950 );
    float Speed( float )               zCall( 0x004DA680 );
    float Length( float )              zCall( 0x004DA7D0 );
    void Interpolate0( float, zVEC3& ) zCall( 0x004DC340 );

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