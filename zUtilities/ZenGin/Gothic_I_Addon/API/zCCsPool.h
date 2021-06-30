// Supported with union (c) 2018 Union team

#ifndef __ZCCS_POOL_H__VER1__
#define __ZCCS_POOL_H__VER1__

#include "zCCsProps.h"

namespace Gothic_I_Addon {
  const int CS_PLAYING = 1<<0;
  const int CS_PLAYED  = 1<<1;

  class zCCSPoolItem : public zSTRING, public zCObject {
  public:
    zCLASS_DECLARATION( zCCSPoolItem )

    int deactivated;
    int runBehaviourValue;
    zCCSProps::zTCSRunBehaviour runBehaviour;
    int numPlayed;
    int playCounter;
    int flags;

    void zCCSPoolItem_OnInit()                                          zCall( 0x00422EC0 );
    void zCCSPoolItem_OnInit( zCCSCutsceneContext* )                    zCall( 0x00423020 );
    zCCSPoolItem()                                                      zInit( zCCSPoolItem_OnInit() );
    zCCSPoolItem( zCCSCutsceneContext* a0 )                             zInit( zCCSPoolItem_OnInit( a0 ));
    void Init()                                                         zCall( 0x004231A0 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour( int& )                 zCall( 0x00423240 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour()                       zCall( 0x00423250 );
    void SetRunBehaviour( zCCSProps::zTCSRunBehaviour, int& )           zCall( 0x00423260 );
    void TestedDeactivation()                                           zCall( 0x004234F0 );
    int IsAllowedToPlay()                                               zCall( 0x00423510 );
    void ClrFlags( long )                                               zCall( 0x00423880 );
    void SetFlags( long )                                               zCall( 0x004238A0 );
    int HasFlags( long )                                                zCall( 0x004238B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00422D70 );
    /* for zSTRING num : 2*/
    virtual ~zCCSPoolItem()                                             zCall( 0x004231B0 );
    virtual void PrintDebugInfo()                                       zCall( 0x00423530 );
    /* for zCObject num : 3*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00422EB0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00423280 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00423300 );
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_POOL_H__VER1__