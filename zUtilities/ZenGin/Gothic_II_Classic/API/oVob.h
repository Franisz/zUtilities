// Supported with union (c) 2018-2021 Union team

#ifndef __OVOB_H__VER2__
#define __OVOB_H__VER2__

#include "z3d.h"
#include "zVob.h"
#include "zVobMisc.h"
#include "zSoundMan.h"

namespace Gothic_II_Classic {

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

    void oCVob_OnInit()                                                                      zCall( 0x0071BC60 );
    oCVob()                                                                                  zInit( oCVob_OnInit() );
    int GetShowDebug()                                                                       zCall( 0x0071BD60 );
    void ToggleShowDebug()                                                                   zCall( 0x0071BD90 );
    void SetShowDebug( int )                                                                 zCall( 0x0071BE10 );
    int HasNpcEnoughSpace( zVEC3& )                                                          zCall( 0x0071C980 );
    int HasEnoughSpace( zVEC3& )                                                             zCall( 0x0071CC70 );
    int SearchNpcPosition( zVEC3& )                                                          zCall( 0x0071CE20 );
    int SearchFreePosition( zVEC3&, zCVob* )                                                 zCall( 0x0071D270 );
    void SetOnFloor( zVEC3& )                                                                zCall( 0x0071D6A0 );
    int GetFloorPosition( zVEC3& )                                                           zCall( 0x0071D6F0 );
    int GetFloorPositionWithVob( zVEC3&, zCVob*& )                                           zCall( 0x0071D7C0 );
    void StartParticleEffects( zCTree<zCVob>* )                                              zCall( 0x0071D960 );
    static void ClearDebugList()                                                             zCall( 0x0071BCF0 );
    static void ShowVobDebugInfo( zCCamera* )                                                zCall( 0x0071BD30 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x0071BC80 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x0071D940 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x0071D950 );
    virtual ~oCVob()                                                                         zCall( 0x0071BCD0 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x0071D970 );
    virtual int GetCSStateFlags()                                                            zCall( 0x006B3740 );
    virtual void Init()                                                                      zCall( 0x0071BCE0 );
    virtual void ShowDebugInfo( zCCamera* )                                                  zCall( 0x0071BE90 );
    virtual int GetInstance()                                                                zCall( 0x0071D8A0 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x0071D8B0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006D00D0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x006D00E0 );
    virtual int DoFocusCheckBBox()                                                           zCall( 0x006B3720 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x0071DBB0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x0071BC90 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x006B3730 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x006D00F0 );

    // user API
    #include "oCVob.inl"
  };

  // sizeof 134h
  class oCTouchDamage : public zCTouchDamage {
  public:
    zCLASS_DECLARATION( oCTouchDamage )

    oCTouchDamage() {}
    static zCObject* _CreateNewInstance()                     zCall( 0x0071E0B0 );
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x0071E130 );
    virtual ~oCTouchDamage()                                  zCall( 0x0071E170 );
    virtual char const* GetDamageTypeArcEnum( unsigned long ) zCall( 0x0071DC60 );

    // user API
    #include "oCTouchDamage.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVOB_H__VER2__