// Supported with union (c) 2018 Union team

#ifndef __ZMATH_TOOLS_H__VER2__
#define __ZMATH_TOOLS_H__VER2__

namespace Gothic_II_Classic {
  const int MAX_SAMPLES_POS = 50;
  const int MAX_SAMPLES_ROT = 100;

  class zCCircleArc3D {
  public:
    float radius;
    float angle;
    float time;
    zVEC3 center;
    zVEC3 u;
    zVEC3 v;
    float b0;
    float b1;

    zCCircleArc3D() {}

    // user API
    #include "zCCircleArc3D.inl"
  };

  class zCPose {
  public:
    zCQuat qRing[MAX_SAMPLES_ROT];
    zVEC3 pRing[MAX_SAMPLES_POS];
    int ringPosTrans;
    int ringPosRot;
    zCQuat actRotAbs;
    zVEC3 actPosAbs;
    zCQuat actRot;
    zVEC3 actPos;
    int oneTurn;
    int numSamplesPos;
    int numSamplesRot;

    void zCPose_OnInit()               zCall( 0x004D7470 );
    ~zCPose()                          zCall( 0x004B24E0 );
    void SetPose( zMAT4& )             zCall( 0x004C1470 );
    void SetInertiaRot( float )        zCall( 0x004D6B20 );
    void SetInertiaPos( float )        zCall( 0x004D6BA0 );
    void SetInertiaSamplesRot( int )   zCall( 0x004D6C10 );
    void SetInertiaSamplesPos( int )   zCall( 0x004D6C80 );
    void CalcAvgRot()                  zCall( 0x004D6CE0 );
    void UpdatePose( zMAT4& )          zCall( 0x004D6EF0 );
    void UpdatePose( zCQuat&, zVEC3& ) zCall( 0x004D70A0 );
    void UpdateRot( zMAT4& )           zCall( 0x004D7240 );
    void UpdateRot( zCQuat& )          zCall( 0x004D72C0 );
    void UpdatePos( zVEC3& )           zCall( 0x004D7340 );
    zCPose()                           zInit( zCPose_OnInit() );
    void SetRot( zMAT4& )              zCall( 0x004D74E0 );
    void SetRot( zCQuat& )             zCall( 0x004D7560 );
    void SetPos( zMAT4& )              zCall( 0x004D75D0 );
    void SetPos( zVEC3& )              zCall( 0x004D7670 );
    void GetPose( zMAT4& )             zCall( 0x004D76D0 );
    zMAT4& GetPose()                   zCall( 0x004D7710 );
    void GetPoseAbs( zMAT4& )          zCall( 0x004D7760 );
    zMAT4& GetRotMatAbs()              zCall( 0x004D77A0 );
    zMAT4& GetRotMat()                 zCall( 0x004D77D0 );

    // static properties
    static zMAT4& tmpMat;

    // user API
    #include "zCPose.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMATH_TOOLS_H__VER2__