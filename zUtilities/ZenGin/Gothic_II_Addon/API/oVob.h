// Supported with union (c) 2018-2021 Union team

#ifndef __OVOB_H__VER3__
#define __OVOB_H__VER3__

#include "z3d.h"
#include "zVob.h"
#include "zVobMisc.h"
#include "zSoundMan.h"

namespace Gothic_II_Addon {

  enum oTSndMaterial {
    SND_MAT_WOOD,
    SND_MAT_STONE,
    SND_MAT_METAL,
    SND_MAT_LEATHER,
    SND_MAT_CLAY,
    SND_MAT_GLAS
  };

  // sizeof 120h
  class oCVob : public zCVob {
  public:
    zCLASS_DECLARATION( oCVob )

    void oCVob_OnInit()                                                                      zCall( 0x0077B6A0 );
    oCVob()                                                                                  zInit( oCVob_OnInit() );
    int GetShowDebug()                                                                       zCall( 0x0077B7A0 );
    void ToggleShowDebug()                                                                   zCall( 0x0077B7D0 );
    void SetShowDebug( int )                                                                 zCall( 0x0077B850 );
    int HasNpcEnoughSpace( zVEC3& )                                                          zCall( 0x0077C3C0 );
    int HasEnoughSpace( zVEC3& )                                                             zCall( 0x0077C6B0 );
    int SearchNpcPosition( zVEC3& )                                                          zCall( 0x0077C860 );
    int SearchFreePosition( zVEC3&, zCVob* )                                                 zCall( 0x0077CCB0 );
    void SetOnFloor( zVEC3& )                                                                zCall( 0x0077D0E0 );
    int GetFloorPosition( zVEC3& )                                                           zCall( 0x0077D130 );
    int GetFloorPositionWithVob( zVEC3&, zCVob*& )                                           zCall( 0x0077D200 );
    void StartParticleEffects( zCTree<zCVob>* )                                              zCall( 0x0077D3A0 );
    static void ClearDebugList()                                                             zCall( 0x0077B730 );
    static void ShowVobDebugInfo( zCCamera* )                                                zCall( 0x0077B770 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x0077B6C0 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x0077D380 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x0077D390 );
    virtual ~oCVob()                                                                         zCall( 0x0077B710 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x0077D3B0 );
    virtual int GetCSStateFlags()                                                            zCall( 0x00711400 );
    virtual void Init()                                                                      zCall( 0x0077B720 );
    virtual void ShowDebugInfo( zCCamera* )                                                  zCall( 0x0077B8D0 );
    virtual int GetInstance()                                                                zCall( 0x0077D2E0 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x0077D2F0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x0072E300 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x0072E310 );
    virtual int DoFocusCheckBBox()                                                           zCall( 0x007113E0 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x0077D5F0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x0077B6D0 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x007113F0 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x0072E320 );

    // user API
    #include "oCVob.inl"
  };

  // sizeof 134h
  class oCTouchDamage : public zCTouchDamage {
  public:
    zCLASS_DECLARATION( oCTouchDamage )

    oCTouchDamage() {}
    static zCObject* _CreateNewInstance()                     zCall( 0x0077DAF0 );
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x0077DB70 );
    virtual ~oCTouchDamage()                                  zCall( 0x0077DBB0 );
    virtual char const* GetDamageTypeArcEnum( unsigned long ) zCall( 0x0077D6A0 );

    // user API
    #include "oCTouchDamage.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVOB_H__VER3__