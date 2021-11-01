// Supported with union (c) 2018-2021 Union team

#ifndef __ZMATH_TOOLS_H__VER2__
#define __ZMATH_TOOLS_H__VER2__

namespace Gothic_II_Classic {
  const int MAX_SAMPLES_POS = 50;
  const int MAX_SAMPLES_ROT = 100;

  // sizeof 38h
  class zCCircleArc3D {
  public:
    float radius; // sizeof 04h    offset 00h
    float angle;  // sizeof 04h    offset 04h
    float time;   // sizeof 04h    offset 08h
    zVEC3 center; // sizeof 0Ch    offset 0Ch
    zVEC3 u;      // sizeof 0Ch    offset 18h
    zVEC3 v;      // sizeof 0Ch    offset 24h
    float b0;     // sizeof 04h    offset 30h
    float b1;     // sizeof 04h    offset 34h

    zCCircleArc3D() {}

    // user API
    #include "zCCircleArc3D.inl"
  };

  // sizeof 8E4h
  class zCPose {
  public:
    zCQuat qRing[MAX_SAMPLES_ROT]; // sizeof 640h   offset 00h
    zVEC3 pRing[MAX_SAMPLES_POS];  // sizeof 258h   offset 640h
    int ringPosTrans;              // sizeof 04h    offset 898h
    int ringPosRot;                // sizeof 04h    offset 89Ch
    zCQuat actRotAbs;              // sizeof 10h    offset 8A0h
    zVEC3 actPosAbs;               // sizeof 0Ch    offset 8B0h
    zCQuat actRot;                 // sizeof 10h    offset 8BCh
    zVEC3 actPos;                  // sizeof 0Ch    offset 8CCh
    int oneTurn;                   // sizeof 04h    offset 8D8h
    int numSamplesPos;             // sizeof 04h    offset 8DCh
    int numSamplesRot;             // sizeof 04h    offset 8E0h

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