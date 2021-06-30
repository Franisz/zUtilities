// Supported with union (c) 2018 Union team

#ifndef __ZPHYSICS_H__VER0__
#define __ZPHYSICS_H__VER0__

namespace Gothic_I_Classic {

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