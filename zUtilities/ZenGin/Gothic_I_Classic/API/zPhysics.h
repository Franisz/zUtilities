// Supported with union (c) 2018-2021 Union team

#ifndef __ZPHYSICS_H__VER0__
#define __ZPHYSICS_H__VER0__

namespace Gothic_I_Classic {

  enum zTRigidBodyMode {
    zPHY_RBMODE_FLY   = 0,
    zPHY_RBMODE_SLIDE = 1
  };

  // sizeof 104h
  class zCRigidBody {
  public:
    float mass;                         // sizeof 04h    offset 00h
    float massInv;                      // sizeof 04h    offset 04h
    zMAT3 iBody;                        // sizeof 24h    offset 08h
    zMAT3 iBodyInv;                     // sizeof 24h    offset 2Ch
    zVEC3 xPos;                         // sizeof 0Ch    offset 50h
    zMAT3 RDir;                         // sizeof 24h    offset 5Ch
    zVEC3 PLinMom;                      // sizeof 0Ch    offset 80h
    zVEC3 LAngMom;                      // sizeof 0Ch    offset 8Ch
    zMAT3 iInv;                         // sizeof 24h    offset 98h
    zVEC3 v;                            // sizeof 0Ch    offset BCh
    zVEC3 omega;                        // sizeof 0Ch    offset C8h
    zVEC3 force;                        // sizeof 0Ch    offset D4h
    zVEC3 torque;                       // sizeof 0Ch    offset E0h
    float gravityScale;                 // sizeof 04h    offset ECh
    zVEC3 slideDir;                     // sizeof 0Ch    offset F0h
    float slideAngle;                   // sizeof 04h    offset FCh
    group {
      unsigned char gravityOn      : 1; // sizeof 01h    offset bit
      unsigned char collisionHad   : 1; // sizeof 01h    offset bit
      unsigned char mode           : 1; // sizeof 01h    offset bit
      unsigned char justSetSliding : 4; // sizeof 04h    offset bit
    };

    void zCRigidBody_OnInit()                                                zCall( 0x00594310 );
    zCRigidBody()                                                            zInit( zCRigidBody_OnInit() );
    void ComputeForceTorque( float )                                         zCall( 0x005943E0 );
    zMAT3 Star( zVEC3 const& )                                               zCall( 0x005943F0 );
    int SetSliding( zVEC3 const& )                                           zCall( 0x00594470 );
    void Integrate( float )                                                  zCall( 0x00594700 );
    void RunSimulation()                                                     zCall( 0x005949A0 );
    void SetInertiaTensorBlock( float, float, float )                        zCall( 0x005949D0 );
    void ApplyForceCM( zVEC3 const& )                                        zCall( 0x00594A60 );
    void ApplyForce( zVEC3 const&, zVEC3 const& )                            zCall( 0x00594AA0 );
    zVEC3 GetPointVelocity( zVEC3 const& ) const                             zCall( 0x00594AE0 );
    void ApplyImpulseCM( zVEC3 const& )                                      zCall( 0x00594B60 );
    void ApplyImpulse( zVEC3 const&, zVEC3 const& )                          zCall( 0x00594BD0 );
    void CollisionImpulseStatic( zVEC3 const&, zVEC3 const&, float )         zCall( 0x00594C40 );
    void CollisionImpulseCenterStatic( zVEC3 const&, float )                 zCall( 0x00594D50 );
    void CollisionImpulse( zVEC3 const&, zVEC3 const&, float, zCRigidBody* ) zCall( 0x00594F40 );
    void StopRotation()                                                      zCall( 0x00595100 );
    void StopTranslation()                                                   zCall( 0x005951A0 );
    void StopTransRot()                                                      zCall( 0x00595240 );
    void SetVelocity( zVEC3 const& )                                         zCall( 0x00595380 );
    void SetMode( zTRigidBodyMode const& )                                   zCall( 0x00595420 );
    int ShouldSlide( zVEC3 const& ) const                                    zCall( 0x00595440 );
    void Archive( zCArchiver& )                                              zCall( 0x005955E0 );
    void Unarchive( zCArchiver& )                                            zCall( 0x00595660 );

    // user API
    #include "zCRigidBody.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPHYSICS_H__VER0__