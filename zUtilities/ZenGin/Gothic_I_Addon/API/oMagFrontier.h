// Supported with union (c) 2018 Union team

#ifndef __OMAG_FRONTIER_H__VER1__
#define __OMAG_FRONTIER_H__VER1__

namespace Gothic_I_Addon {

  class oCMagFrontier {
  public:
    oCVisualFX* warningFX;
    oCVisualFX* shootFX;
    oCNpc* npc;
    unsigned char isWarning  : 1;
    unsigned char isShooting : 1;

    void oCMagFrontier_OnInit()                       zCall( 0x00475CD0 );
    oCMagFrontier()                                   zInit( oCMagFrontier_OnInit() );
    ~oCMagFrontier()                                  zCall( 0x00475CF0 );
    void SetNPC( oCNpc* )                             zCall( 0x00475D60 );
    void DoCheck()                                    zCall( 0x00475D70 );
    float GetDistance( zVEC3 const&, float&, zVEC3& ) zCall( 0x00476500 );
    void StartLightningAtPos( zVEC3&, zVEC3& )        zCall( 0x00476790 );
    void DoWarningFX( int )                           zCall( 0x00476DB0 );
    void DisposeWarningFX()                           zCall( 0x00476FD0 );
    void DoShootFX( zVEC3 const& )                    zCall( 0x00477010 );
    void DisposeShootFX()                             zCall( 0x00477440 );

    // user API
    #include "oCMagFrontier.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMAG_FRONTIER_H__VER1__