// Supported with union (c) 2018-2021 Union team

#ifndef __ZMATH_TOOLS_H__VER0__
#define __ZMATH_TOOLS_H__VER0__

namespace Gothic_I_Classic {
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

    void zCPose_OnInit()               zCall( 0x004CCE40 );
    ~zCPose()                          zCall( 0x004AC0A0 );
    void SetPose( zMAT4& )             zCall( 0x004BA610 );
    void SetInertiaRot( float )        zCall( 0x004CC4F0 );
    void SetInertiaPos( float )        zCall( 0x004CC570 );
    void SetInertiaSamplesRot( int )   zCall( 0x004CC5E0 );
    void SetInertiaSamplesPos( int )   zCall( 0x004CC650 );
    void CalcAvgRot()                  zCall( 0x004CC6B0 );
    void UpdatePose( zMAT4& )          zCall( 0x004CC8C0 );
    void UpdatePose( zCQuat&, zVEC3& ) zCall( 0x004CCA70 );
    void UpdateRot( zMAT4& )           zCall( 0x004CCC10 );
    void UpdateRot( zCQuat& )          zCall( 0x004CCC90 );
    void UpdatePos( zVEC3& )           zCall( 0x004CCD10 );
    zCPose()                           zInit( zCPose_OnInit() );
    void SetRot( zMAT4& )              zCall( 0x004CCEB0 );
    void SetRot( zCQuat& )             zCall( 0x004CCF30 );
    void SetPos( zMAT4& )              zCall( 0x004CCFA0 );
    void SetPos( zVEC3& )              zCall( 0x004CD040 );
    void GetPose( zMAT4& )             zCall( 0x004CD0A0 );
    zMAT4& GetPose()                   zCall( 0x004CD0E0 );
    void GetPoseAbs( zMAT4& )          zCall( 0x004CD130 );
    zMAT4& GetRotMatAbs()              zCall( 0x004CD170 );
    zMAT4& GetRotMat()                 zCall( 0x004CD1A0 );

    // static properties
    static zMAT4& tmpMat;

    // user API
    #include "zCPose.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMATH_TOOLS_H__VER0__