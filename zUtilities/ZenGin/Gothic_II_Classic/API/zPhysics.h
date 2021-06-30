// Supported with union (c) 2018 Union team

#ifndef __ZPHYSICS_H__VER2__
#define __ZPHYSICS_H__VER2__

namespace Gothic_II_Classic {

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

    void zCRigidBody_OnInit()                                                zCall( 0x005AFAF0 );
    zCRigidBody()                                                            zInit( zCRigidBody_OnInit() );
    void ComputeForceTorque( float )                                         zCall( 0x005AFBC0 );
    zMAT3 Star( zVEC3 const& )                                               zCall( 0x005AFBD0 );
    int SetSliding( zVEC3 const& )                                           zCall( 0x005AFC50 );
    void Integrate( float )                                                  zCall( 0x005AFEE0 );
    void RunSimulation()                                                     zCall( 0x005B0180 );
    void SetInertiaTensorBlock( float, float, float )                        zCall( 0x005B01B0 );
    void ApplyForceCM( zVEC3 const& )                                        zCall( 0x005B0240 );
    void ApplyForce( zVEC3 const&, zVEC3 const& )                            zCall( 0x005B0280 );
    zVEC3 GetPointVelocity( zVEC3 const& ) const                             zCall( 0x005B02C0 );
    void ApplyImpulseCM( zVEC3 const& )                                      zCall( 0x005B0340 );
    void ApplyImpulse( zVEC3 const&, zVEC3 const& )                          zCall( 0x005B03B0 );
    void CollisionImpulseStatic( zVEC3 const&, zVEC3 const&, float )         zCall( 0x005B0420 );
    void CollisionImpulseCenterStatic( zVEC3 const&, float )                 zCall( 0x005B0530 );
    void CollisionImpulse( zVEC3 const&, zVEC3 const&, float, zCRigidBody* ) zCall( 0x005B0720 );
    void StopRotation()                                                      zCall( 0x005B08E0 );
    void StopTranslation()                                                   zCall( 0x005B0980 );
    void StopTransRot()                                                      zCall( 0x005B0A20 );
    void SetVelocity( zVEC3 const& )                                         zCall( 0x005B0B60 );
    void SetMode( zTRigidBodyMode const& )                                   zCall( 0x005B0C00 );
    int ShouldSlide( zVEC3 const& ) const                                    zCall( 0x005B0C20 );
    void Archive( zCArchiver& )                                              zCall( 0x005B0DC0 );
    void Unarchive( zCArchiver& )                                            zCall( 0x005B0E40 );

    // user API
    #include "zCRigidBody.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPHYSICS_H__VER2__