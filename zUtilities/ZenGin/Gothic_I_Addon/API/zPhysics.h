// Supported with union (c) 2018 Union team

#ifndef __ZPHYSICS_H__VER1__
#define __ZPHYSICS_H__VER1__

namespace Gothic_I_Addon {

  enum zTRigidBodyMode {
    zPHY_RBMODE_FLY   = 0,
    zPHY_RBMODE_SLIDE = 1
  };

  class zCRigidBody {
  public:
    float mass;
    float massInv;
    zMAT3 iBody;
    zMAT3 iBodyInv;
    zVEC3 xPos;
    zMAT3 RDir;
    zVEC3 PLinMom;
    zVEC3 LAngMom;
    zMAT3 iInv;
    zVEC3 v;
    zVEC3 omega;
    zVEC3 force;
    zVEC3 torque;
    float gravityScale;
    zVEC3 slideDir;
    float slideAngle;
    group {
      unsigned char gravityOn      : 1;
      unsigned char collisionHad   : 1;
      unsigned char mode           : 1;
      unsigned char justSetSliding : 4;
    };

    void zCRigidBody_OnInit()                                                zCall( 0x005B0070 );
    zCRigidBody()                                                            zInit( zCRigidBody_OnInit() );
    void ComputeForceTorque( float )                                         zCall( 0x005B0150 );
    zMAT3 Star( zVEC3 const& )                                               zCall( 0x005B0160 );
    int SetSliding( zVEC3 const& )                                           zCall( 0x005B01E0 );
    void Integrate( float )                                                  zCall( 0x005B0470 );
    void RunSimulation()                                                     zCall( 0x005B0730 );
    void SetInertiaTensorBlock( float, float, float )                        zCall( 0x005B0760 );
    void ApplyForceCM( zVEC3 const& )                                        zCall( 0x005B0800 );
    void ApplyForce( zVEC3 const&, zVEC3 const& )                            zCall( 0x005B0840 );
    zVEC3 GetPointVelocity( zVEC3 const& ) const                             zCall( 0x005B0880 );
    void ApplyImpulseCM( zVEC3 const& )                                      zCall( 0x005B0920 );
    void ApplyImpulse( zVEC3 const&, zVEC3 const& )                          zCall( 0x005B09A0 );
    void CollisionImpulseStatic( zVEC3 const&, zVEC3 const&, float )         zCall( 0x005B0A20 );
    void CollisionImpulseCenterStatic( zVEC3 const&, float )                 zCall( 0x005B0B60 );
    void CollisionImpulse( zVEC3 const&, zVEC3 const&, float, zCRigidBody* ) zCall( 0x005B0DA0 );
    void StopRotation()                                                      zCall( 0x005B0FA0 );
    void StopTranslation()                                                   zCall( 0x005B1040 );
    void StopTransRot()                                                      zCall( 0x005B10E0 );
    void SetVelocity( zVEC3 const& )                                         zCall( 0x005B1220 );
    void SetMode( zTRigidBodyMode const& )                                   zCall( 0x005B12D0 );
    int ShouldSlide( zVEC3 const& ) const                                    zCall( 0x005B12F0 );
    void Archive( zCArchiver& )                                              zCall( 0x005B14C0 );
    void Unarchive( zCArchiver& )                                            zCall( 0x005B1540 );

    // user API
    #include "zCRigidBody.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPHYSICS_H__VER1__