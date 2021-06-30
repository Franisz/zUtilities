// Supported with union (c) 2018 Union team

#ifndef __ZMATH_TOOLS_H__VER3__
#define __ZMATH_TOOLS_H__VER3__

namespace Gothic_II_Addon {
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

    void zCPose_OnInit()               zCall( 0x004D9A30 );
    ~zCPose()                          zCall( 0x004B4A10 );
    void SetPose( zMAT4& )             zCall( 0x004C39E0 );
    void SetInertiaRot( float )        zCall( 0x004D90E0 );
    void SetInertiaPos( float )        zCall( 0x004D9160 );
    void SetInertiaSamplesRot( int )   zCall( 0x004D91D0 );
    void SetInertiaSamplesPos( int )   zCall( 0x004D9240 );
    void CalcAvgRot()                  zCall( 0x004D92A0 );
    void UpdatePose( zMAT4& )          zCall( 0x004D94B0 );
    void UpdatePose( zCQuat&, zVEC3& ) zCall( 0x004D9660 );
    void UpdateRot( zMAT4& )           zCall( 0x004D9800 );
    void UpdateRot( zCQuat& )          zCall( 0x004D9880 );
    void UpdatePos( zVEC3& )           zCall( 0x004D9900 );
    zCPose()                           zInit( zCPose_OnInit() );
    void SetRot( zMAT4& )              zCall( 0x004D9AA0 );
    void SetRot( zCQuat& )             zCall( 0x004D9B20 );
    void SetPos( zMAT4& )              zCall( 0x004D9B90 );
    void SetPos( zVEC3& )              zCall( 0x004D9C30 );
    void GetPose( zMAT4& )             zCall( 0x004D9C90 );
    zMAT4& GetPose()                   zCall( 0x004D9CD0 );
    void GetPoseAbs( zMAT4& )          zCall( 0x004D9D20 );
    zMAT4& GetRotMatAbs()              zCall( 0x004D9D60 );
    zMAT4& GetRotMat()                 zCall( 0x004D9D90 );

    // static properties
    static zMAT4& tmpMat;

    // user API
    #include "zCPose.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMATH_TOOLS_H__VER3__