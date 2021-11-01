// Supported with union (c) 2018-2021 Union team

#ifndef __OMAG_FRONTIER_H__VER3__
#define __OMAG_FRONTIER_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 10h
  class oCMagFrontier {
  public:
    oCVisualFX* warningFX;        // sizeof 04h    offset 00h
    oCVisualFX* shootFX;          // sizeof 04h    offset 04h
    oCNpc* npc;                   // sizeof 04h    offset 08h
    unsigned char isWarning  : 1; // sizeof 01h    offset bit
    unsigned char isShooting : 1; // sizeof 01h    offset bit

    void oCMagFrontier_OnInit()                                   zCall( 0x004736A0 );
    oCMagFrontier()                                               zInit( oCMagFrontier_OnInit() );
    ~oCMagFrontier()                                              zCall( 0x004736C0 );
    void SetNPC( oCNpc* )                                         zCall( 0x00473730 );
    void DoCheck()                                                zCall( 0x00473740 );
    float GetDistanceNewWorld( zVEC3 const&, float&, zVEC3& )     zCall( 0x00473F20 );
    float GetDistanceDragonIsland( zVEC3 const&, float&, zVEC3& ) zCall( 0x00474460 );
    float GetDistanceAddonWorld( zVEC3 const&, float&, zVEC3& )   zCall( 0x00474620 );
    void StartLightningAtPos( zVEC3&, zVEC3& )                    zCall( 0x00474750 );
    void DoWarningFX( int )                                       zCall( 0x00474CB0 );
    void DisposeWarningFX()                                       zCall( 0x00474E70 );
    void DoShootFX( zVEC3 const& )                                zCall( 0x00474EB0 );
    void DisposeShootFX()                                         zCall( 0x004751A0 );

    // user API
    #include "oCMagFrontier.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMAG_FRONTIER_H__VER3__