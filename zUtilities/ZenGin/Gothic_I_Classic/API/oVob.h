// Supported with union (c) 2018-2021 Union team

#ifndef __OVOB_H__VER0__
#define __OVOB_H__VER0__

#include "z3d.h"
#include "zVob.h"
#include "zVobMisc.h"
#include "zSoundMan.h"

namespace Gothic_I_Classic {

  enum oTSndMaterial {
    SND_MAT_WOOD,
    SND_MAT_STONE,
    SND_MAT_METAL,
    SND_MAT_LEATHER,
    SND_MAT_CLAY,
    SND_MAT_GLAS
  };

  // sizeof 100h
  class oCVob : public zCVob {
  public:
    zCLASS_DECLARATION( oCVob )

    void oCVob_OnInit()                                                                      zCall( 0x006D2AF0 );
    oCVob()                                                                                  zInit( oCVob_OnInit() );
    int GetShowDebug()                                                                       zCall( 0x006D2BF0 );
    void ToggleShowDebug()                                                                   zCall( 0x006D2C20 );
    void SetShowDebug( int )                                                                 zCall( 0x006D2CA0 );
    int HasNpcEnoughSpace( zVEC3& )                                                          zCall( 0x006D3680 );
    int HasEnoughSpace( zVEC3& )                                                             zCall( 0x006D3960 );
    int SearchNpcPosition( zVEC3& )                                                          zCall( 0x006D3B10 );
    int SearchFreePosition( zVEC3&, zCVob* )                                                 zCall( 0x006D3F90 );
    void SetOnFloor( zVEC3& )                                                                zCall( 0x006D43C0 );
    int GetFloorPosition( zVEC3& )                                                           zCall( 0x006D4410 );
    int GetFloorPositionWithVob( zVEC3&, zCVob*& )                                           zCall( 0x006D44E0 );
    void StartParticleEffects( zCTree<zCVob>* )                                              zCall( 0x006D4680 );
    static void ClearDebugList()                                                             zCall( 0x006D2B80 );
    static void ShowVobDebugInfo( zCCamera* )                                                zCall( 0x006D2BC0 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x006D2B10 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x006D4660 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x006D4670 );
    virtual ~oCVob()                                                                         zCall( 0x006D2B60 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x006D4690 );
    virtual int GetCSStateFlags()                                                            zCall( 0x00670F30 );
    virtual void Init()                                                                      zCall( 0x006D2B70 );
    virtual void ShowDebugInfo( zCCamera* )                                                  zCall( 0x006D2D20 );
    virtual int GetInstance()                                                                zCall( 0x006D45C0 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x006D45D0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x0068BDD0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x0068BDE0 );
    virtual int DoFocusCheckBBox()                                                           zCall( 0x00670F10 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x006D4850 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x006D2B20 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x00670F20 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x0068BDF0 );

    // user API
    #include "oCVob.inl"
  };

  // sizeof 114h
  class oCTouchDamage : public zCTouchDamage {
  public:
    zCLASS_DECLARATION( oCTouchDamage )

    oCTouchDamage() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x006D4D70 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006D4E10 );
    virtual ~oCTouchDamage()                                            zCall( 0x006D4E50 );
    virtual char const* GetDamageTypeArcEnum( unsigned long )           zCall( 0x006D4920 );

    // user API
    #include "oCTouchDamage.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVOB_H__VER0__