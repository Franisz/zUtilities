// Supported with union (c) 2018-2021 Union team

#ifndef __ZMATH_TOOLS_H__VER1__
#define __ZMATH_TOOLS_H__VER1__

namespace Gothic_I_Addon {
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

    void zCPose_OnInit()               zCall( 0x004DD5A0 );
    ~zCPose()                          zCall( 0x004B9FC0 );
    void SetPose( zMAT4& )             zCall( 0x004C9970 );
    void SetInertiaRot( float )        zCall( 0x004DCC10 );
    void SetInertiaPos( float )        zCall( 0x004DCC90 );
    void SetInertiaSamplesRot( int )   zCall( 0x004DCD10 );
    void SetInertiaSamplesPos( int )   zCall( 0x004DCD70 );
    void CalcAvgRot()                  zCall( 0x004DCDD0 );
    void UpdatePose( zMAT4& )          zCall( 0x004DCFE0 );
    void UpdatePose( zCQuat&, zVEC3& ) zCall( 0x004DD1B0 );
    void UpdateRot( zMAT4& )           zCall( 0x004DD360 );
    void UpdateRot( zCQuat& )          zCall( 0x004DD3E0 );
    void UpdatePos( zVEC3& )           zCall( 0x004DD460 );
    zCPose()                           zInit( zCPose_OnInit() );
    void SetRot( zMAT4& )              zCall( 0x004DD610 );
    void SetRot( zCQuat& )             zCall( 0x004DD690 );
    void SetPos( zMAT4& )              zCall( 0x004DD700 );
    void SetPos( zVEC3& )              zCall( 0x004DD7B0 );
    void GetPose( zMAT4& )             zCall( 0x004DD810 );
    zMAT4& GetPose()                   zCall( 0x004DD850 );
    void GetPoseAbs( zMAT4& )          zCall( 0x004DD8A0 );
    zMAT4& GetRotMatAbs()              zCall( 0x004DD8E0 );
    zMAT4& GetRotMat()                 zCall( 0x004DD910 );

    // static properties
    static zMAT4& tmpMat;

    // user API
    #include "zCPose.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMATH_TOOLS_H__VER1__