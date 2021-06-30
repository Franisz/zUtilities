// Supported with union (c) 2018 Union team

#ifndef __ZPHYSICS_H__VER3__
#define __ZPHYSICS_H__VER3__

namespace Gothic_II_Addon {

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

    void zCRigidBody_OnInit()                                                zCall( 0x005B5660 );
    zCRigidBody()                                                            zInit( zCRigidBody_OnInit() );
    void ComputeForceTorque( float )                                         zCall( 0x005B5730 );
    zMAT3 Star( zVEC3 const& )                                               zCall( 0x005B5740 );
    int SetSliding( zVEC3 const& )                                           zCall( 0x005B57C0 );
    void Integrate( float )                                                  zCall( 0x005B5A50 );
    void RunSimulation()                                                     zCall( 0x005B5CF0 );
    void SetInertiaTensorBlock( float, float, float )                        zCall( 0x005B5D20 );
    void ApplyForceCM( zVEC3 const& )                                        zCall( 0x005B5DB0 );
    void ApplyForce( zVEC3 const&, zVEC3 const& )                            zCall( 0x005B5DF0 );
    zVEC3 GetPointVelocity( zVEC3 const& ) const                             zCall( 0x005B5E30 );
    void ApplyImpulseCM( zVEC3 const& )                                      zCall( 0x005B5EB0 );
    void ApplyImpulse( zVEC3 const&, zVEC3 const& )                          zCall( 0x005B5F20 );
    void CollisionImpulseStatic( zVEC3 const&, zVEC3 const&, float )         zCall( 0x005B5F90 );
    void CollisionImpulseCenterStatic( zVEC3 const&, float )                 zCall( 0x005B60A0 );
    void CollisionImpulse( zVEC3 const&, zVEC3 const&, float, zCRigidBody* ) zCall( 0x005B6290 );
    void StopRotation()                                                      zCall( 0x005B6450 );
    void StopTranslation()                                                   zCall( 0x005B64F0 );
    void StopTransRot()                                                      zCall( 0x005B6590 );
    void SetVelocity( zVEC3 const& )                                         zCall( 0x005B66D0 );
    void SetMode( zTRigidBodyMode const& )                                   zCall( 0x005B6770 );
    int ShouldSlide( zVEC3 const& ) const                                    zCall( 0x005B6790 );
    void Archive( zCArchiver& )                                              zCall( 0x005B6930 );
    void Unarchive( zCArchiver& )                                            zCall( 0x005B69B0 );

    // user API
    #include "zCRigidBody.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPHYSICS_H__VER3__