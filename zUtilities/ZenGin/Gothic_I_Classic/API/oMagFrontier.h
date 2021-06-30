// Supported with union (c) 2018 Union team

#ifndef __OMAG_FRONTIER_H__VER0__
#define __OMAG_FRONTIER_H__VER0__

namespace Gothic_I_Classic {

  class oCMagFrontier {
  public:
    oCVisualFX* warningFX;
    oCVisualFX* shootFX;
    oCNpc* npc;
    unsigned char isWarning  : 1;
    unsigned char isShooting : 1;

    void oCMagFrontier_OnInit()                       zCall( 0x0046D590 );
    oCMagFrontier()                                   zInit( oCMagFrontier_OnInit() );
    ~oCMagFrontier()                                  zCall( 0x0046D5B0 );
    void SetNPC( oCNpc* )                             zCall( 0x0046D620 );
    void DoCheck()                                    zCall( 0x0046D630 );
    float GetDistance( zVEC3 const&, float&, zVEC3& ) zCall( 0x0046DC00 );
    void StartLightningAtPos( zVEC3&, zVEC3& )        zCall( 0x0046DDA0 );
    void DoWarningFX( int )                           zCall( 0x0046E380 );
    void DisposeWarningFX()                           zCall( 0x0046E550 );
    void DoShootFX( zVEC3 const& )                    zCall( 0x0046E590 );
    void DisposeShootFX()                             zCall( 0x0046E8A0 );

    // user API
    #include "oCMagFrontier.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMAG_FRONTIER_H__VER0__