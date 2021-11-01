// Supported with union (c) 2018-2021 Union team

#ifndef __OPARTICLE_CONTROL_H__VER1__
#define __OPARTICLE_CONTROL_H__VER1__

#include "zVob.h"

namespace Gothic_I_Addon {

  // sizeof 38h
  class oCParticleControl {
  public:
    zCParticleFX* partFX;   // sizeof 04h    offset 00h
    zCVob* pfxVob;          // sizeof 04h    offset 04h
    unsigned long pfxVobID; // sizeof 04h    offset 08h
    zSTRING pfxName;        // sizeof 14h    offset 0Ch
    zVEC3 startpos;         // sizeof 0Ch    offset 20h
    int IsInEditMode;       // sizeof 04h    offset 2Ch
    zCWorld* rnd_world;     // sizeof 04h    offset 30h
    zCConsole* part_edit;   // sizeof 04h    offset 34h

    void oCParticleControl_OnInit()                           zCall( 0x006FE6D0 );
    void oCParticleControl_OnInit( zCWorld* )                 zCall( 0x006FE790 );
    oCParticleControl()                                       zInit( oCParticleControl_OnInit() );
    oCParticleControl( zCWorld* a0 )                          zInit( oCParticleControl_OnInit( a0 ));
    ~oCParticleControl()                                      zCall( 0x006FE9B0 );
    zCVob* GetPFXVob()                                        zCall( 0x006FEA50 );
    void SelectActivePFX()                                    zCall( 0x006FEA60 );
    void EditActivePFX()                                      zCall( 0x006FEE00 );
    void SetStartPos( zVEC3& )                                zCall( 0x006FFA00 );
    void StartActivePFX( zCVob*, zSTRING& )                   zCall( 0x006FFA20 );
    void StartActivePFX()                                     zCall( 0x006FFC60 );
    void CreateNewPFX( zSTRING& )                             zCall( 0x006FFE40 );
    void SetPFXName( zSTRING& )                               zCall( 0x007000B0 );
    void SetWorld( zCWorld* )                                 zCall( 0x00700210 );
    void BeginEditActive( void( __cdecl* )( zSTRING const& )) zCall( 0x00700260 );
    void DeleteLastPFX()                                      zCall( 0x00700340 );
    void UpdateInternals()                                    zCall( 0x00700470 );
    void EndEditActive()                                      zCall( 0x00700480 );

    // user API
    #include "oCParticleControl.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OPARTICLE_CONTROL_H__VER1__