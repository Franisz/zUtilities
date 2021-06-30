// Supported with union (c) 2018 Union team

#ifndef __OPARTICLE_CONTROL_H__VER3__
#define __OPARTICLE_CONTROL_H__VER3__

#include "zParticle.h"
#include "zVob.h"

namespace Gothic_II_Addon {

  class oCParticleControl {
  public:
    zCParticleFX* partFX;
    zCVob* pfxVob;
    unsigned long pfxVobID;
    zSTRING pfxName;
    zVEC3 startpos;
    int IsInEditMode;
    zCWorld* rnd_world;
    zCConsole* part_edit;

    void oCParticleControl_OnInit()                           zCall( 0x0076FF90 );
    void oCParticleControl_OnInit( zCWorld* )                 zCall( 0x00770040 );
    oCParticleControl()                                       zInit( oCParticleControl_OnInit() );
    oCParticleControl( zCWorld* a0 )                          zInit( oCParticleControl_OnInit( a0 ));
    ~oCParticleControl()                                      zCall( 0x00770230 );
    zCVob* GetPFXVob()                                        zCall( 0x007702C0 );
    void SelectActivePFX()                                    zCall( 0x007702D0 );
    void EditActivePFX()                                      zCall( 0x00770660 );
    void SetStartPos( zVEC3& )                                zCall( 0x00771330 );
    void StartActivePFX( zCVob*, zSTRING& )                   zCall( 0x00771350 );
    void StartActivePFX()                                     zCall( 0x00771550 );
    void CreateNewPFX( zSTRING& )                             zCall( 0x00771700 );
    void SetPFXName( zSTRING& )                               zCall( 0x00771930 );
    void SetWorld( zCWorld* )                                 zCall( 0x00771A90 );
    void BeginEditActive( void( __cdecl* )( zSTRING const& )) zCall( 0x00771AE0 );
    void DeleteLastPFX()                                      zCall( 0x00771BB0 );
    void UpdateInternals()                                    zCall( 0x00771CA0 );
    void EndEditActive()                                      zCall( 0x00771CB0 );

    // user API
    #include "oCParticleControl.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OPARTICLE_CONTROL_H__VER3__