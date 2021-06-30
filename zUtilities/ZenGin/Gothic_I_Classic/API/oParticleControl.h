// Supported with union (c) 2018 Union team

#ifndef __OPARTICLE_CONTROL_H__VER0__
#define __OPARTICLE_CONTROL_H__VER0__

#include "zVob.h"

namespace Gothic_I_Classic {

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

    void oCParticleControl_OnInit()                           zCall( 0x006C8870 );
    void oCParticleControl_OnInit( zCWorld* )                 zCall( 0x006C8920 );
    oCParticleControl()                                       zInit( oCParticleControl_OnInit() );
    oCParticleControl( zCWorld* a0 )                          zInit( oCParticleControl_OnInit( a0 ));
    ~oCParticleControl()                                      zCall( 0x006C8B30 );
    zCVob* GetPFXVob()                                        zCall( 0x006C8BC0 );
    void SelectActivePFX()                                    zCall( 0x006C8BD0 );
    void EditActivePFX()                                      zCall( 0x006C8F50 );
    void SetStartPos( zVEC3& )                                zCall( 0x006C9AE0 );
    void StartActivePFX( zCVob*, zSTRING& )                   zCall( 0x006C9B00 );
    void StartActivePFX()                                     zCall( 0x006C9D30 );
    void CreateNewPFX( zSTRING& )                             zCall( 0x006C9F10 );
    void SetPFXName( zSTRING& )                               zCall( 0x006CA140 );
    void SetWorld( zCWorld* )                                 zCall( 0x006CA2A0 );
    void BeginEditActive( void( __cdecl* )( zSTRING const& )) zCall( 0x006CA2F0 );
    void DeleteLastPFX()                                      zCall( 0x006CA3D0 );
    void UpdateInternals()                                    zCall( 0x006CA500 );
    void EndEditActive()                                      zCall( 0x006CA510 );

    // user API
    #include "oCParticleControl.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OPARTICLE_CONTROL_H__VER0__