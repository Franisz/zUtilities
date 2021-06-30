// Supported with union (c) 2018 Union team

#ifndef __OPARTICLE_CONTROL_H__VER2__
#define __OPARTICLE_CONTROL_H__VER2__

#include "zVob.h"

namespace Gothic_II_Classic {

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

    void oCParticleControl_OnInit()                           zCall( 0x00710A20 );
    void oCParticleControl_OnInit( zCWorld* )                 zCall( 0x00710AD0 );
    oCParticleControl()                                       zInit( oCParticleControl_OnInit() );
    oCParticleControl( zCWorld* a0 )                          zInit( oCParticleControl_OnInit( a0 ));
    ~oCParticleControl()                                      zCall( 0x00710CC0 );
    zCVob* GetPFXVob()                                        zCall( 0x00710D50 );
    void SelectActivePFX()                                    zCall( 0x00710D60 );
    void EditActivePFX()                                      zCall( 0x007110F0 );
    void SetStartPos( zVEC3& )                                zCall( 0x00711DA0 );
    void StartActivePFX( zCVob*, zSTRING& )                   zCall( 0x00711DC0 );
    void StartActivePFX()                                     zCall( 0x00711FC0 );
    void CreateNewPFX( zSTRING& )                             zCall( 0x00712170 );
    void SetPFXName( zSTRING& )                               zCall( 0x007123A0 );
    void SetWorld( zCWorld* )                                 zCall( 0x00712500 );
    void BeginEditActive( void( __cdecl* )( zSTRING const& )) zCall( 0x00712550 );
    void DeleteLastPFX()                                      zCall( 0x00712620 );
    void UpdateInternals()                                    zCall( 0x00712710 );
    void EndEditActive()                                      zCall( 0x00712720 );

    // user API
    #include "oCParticleControl.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OPARTICLE_CONTROL_H__VER2__