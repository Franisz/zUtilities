// Supported with union (c) 2018-2021 Union team

#ifndef __OMAG_FRONTIER_H__VER2__
#define __OMAG_FRONTIER_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 10h
  class oCMagFrontier {
  public:
    oCVisualFX* warningFX;        // sizeof 04h    offset 00h
    oCVisualFX* shootFX;          // sizeof 04h    offset 04h
    oCNpc* npc;                   // sizeof 04h    offset 08h
    unsigned char isWarning  : 1; // sizeof 01h    offset bit
    unsigned char isShooting : 1; // sizeof 01h    offset bit

    void oCMagFrontier_OnInit()                                   zCall( 0x00472580 );
    oCMagFrontier()                                               zInit( oCMagFrontier_OnInit() );
    ~oCMagFrontier()                                              zCall( 0x004725A0 );
    void SetNPC( oCNpc* )                                         zCall( 0x00472610 );
    void DoCheck()                                                zCall( 0x00472620 );
    float GetDistanceNewWorld( zVEC3 const&, float&, zVEC3& )     zCall( 0x00472D40 );
    float GetDistanceDragonIsland( zVEC3 const&, float&, zVEC3& ) zCall( 0x00473280 );
    void StartLightningAtPos( zVEC3&, zVEC3& )                    zCall( 0x004733B0 );
    void DoWarningFX( int )                                       zCall( 0x00473910 );
    void DisposeWarningFX()                                       zCall( 0x00473AD0 );
    void DoShootFX( zVEC3 const& )                                zCall( 0x00473B10 );
    void DisposeShootFX()                                         zCall( 0x00473E00 );

    // user API
    #include "oCMagFrontier.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMAG_FRONTIER_H__VER2__