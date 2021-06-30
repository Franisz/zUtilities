// Supported with union (c) 2018 Union team

#ifndef __OVOB_H__VER1__
#define __OVOB_H__VER1__

#include "z3d.h"
#include "zVob.h"
#include "zVobMisc.h"
#include "zSoundMan.h"

namespace Gothic_I_Addon {

  enum oTSndMaterial {
    SND_MAT_WOOD,
    SND_MAT_STONE,
    SND_MAT_METAL,
    SND_MAT_LEATHER,
    SND_MAT_CLAY,
    SND_MAT_GLAS
  };

  class oCVob : public zCVob {
  public:
    zCLASS_DECLARATION( oCVob )

    void oCVob_OnInit()                                                                      zCall( 0x00709BB0 );
    oCVob()                                                                                  zInit( oCVob_OnInit() );
    int GetShowDebug()                                                                       zCall( 0x00709CB0 );
    void ToggleShowDebug()                                                                   zCall( 0x00709CD0 );
    void SetShowDebug( int )                                                                 zCall( 0x00709D50 );
    int HasNpcEnoughSpace( zVEC3& )                                                          zCall( 0x0070A730 );
    int HasEnoughSpace( zVEC3& )                                                             zCall( 0x0070AA70 );
    int SearchNpcPosition( zVEC3& )                                                          zCall( 0x0070AC20 );
    int SearchFreePosition( zVEC3&, zCVob* )                                                 zCall( 0x0070B150 );
    void SetOnFloor( zVEC3& )                                                                zCall( 0x0070B650 );
    int GetFloorPosition( zVEC3& )                                                           zCall( 0x0070B6A0 );
    int GetFloorPositionWithVob( zVEC3&, zCVob*& )                                           zCall( 0x0070B790 );
    void StartParticleEffects( zCTree<zCVob>* )                                              zCall( 0x0070B950 );
    static void ClearDebugList()                                                             zCall( 0x00709C40 );
    static void ShowVobDebugInfo( zCCamera* )                                                zCall( 0x00709C80 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00709BD0 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x0070B930 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x0070B940 );
    virtual ~oCVob()                                                                         zCall( 0x00709C20 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x0070B960 );
    virtual int GetCSStateFlags()                                                            zCall( 0x0069E800 );
    virtual void Init()                                                                      zCall( 0x00709C30 );
    virtual void ShowDebugInfo( zCCamera* )                                                  zCall( 0x00709DE0 );
    virtual int GetInstance()                                                                zCall( 0x0070B890 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x0070B8A0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006BC4A0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x006BC4B0 );
    virtual int DoFocusCheckBBox()                                                           zCall( 0x0069E7E0 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x0070BB30 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x00709BE0 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x0069E7F0 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x006BC4C0 );

    // user API
    #include "oCVob.inl"
  };

  class oCTouchDamage : public zCTouchDamage {
  public:
    zCLASS_DECLARATION( oCTouchDamage )

    oCTouchDamage() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0070C080 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0070C120 );
    virtual ~oCTouchDamage()                                            zCall( 0x0070C160 );
    virtual char const* GetDamageTypeArcEnum( unsigned long )           zCall( 0x0070BC00 );

    // user API
    #include "oCTouchDamage.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVOB_H__VER1__