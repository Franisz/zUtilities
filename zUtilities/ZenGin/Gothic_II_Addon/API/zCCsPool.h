// Supported with union (c) 2018 Union team

#ifndef __ZCCS_POOL_H__VER3__
#define __ZCCS_POOL_H__VER3__

#include "zCCsProps.h"

namespace Gothic_II_Addon {
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

    void zCCSPoolItem_OnInit()                                zCall( 0x00421230 );
    void zCCSPoolItem_OnInit( zCCSCutsceneContext* )          zCall( 0x00421390 );
    zCCSPoolItem()                                            zInit( zCCSPoolItem_OnInit() );
    zCCSPoolItem( zCCSCutsceneContext* a0 )                   zInit( zCCSPoolItem_OnInit( a0 ));
    void Init()                                               zCall( 0x004214F0 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour( int& )       zCall( 0x00421580 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour()             zCall( 0x00421590 );
    void SetRunBehaviour( zCCSProps::zTCSRunBehaviour, int& ) zCall( 0x004215A0 );
    void TestedDeactivation()                                 zCall( 0x00421820 );
    int IsAllowedToPlay()                                     zCall( 0x00421840 );
    void ClrFlags( long )                                     zCall( 0x00421BC0 );
    void SetFlags( long )                                     zCall( 0x00421BE0 );
    int HasFlags( long )                                      zCall( 0x00421BF0 );
    static zCObject* _CreateNewInstance()                     zCall( 0x004210F0 );
    /* for zSTRING num : 2*/
    virtual ~zCCSPoolItem()                                   zCall( 0x00421500 );
    virtual void PrintDebugInfo()                             zCall( 0x00421860 );
    /* for zCObject num : 3*/
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x00421220 );
    virtual void Archive( zCArchiver& )                       zCall( 0x004215C0 );
    virtual void Unarchive( zCArchiver& )                     zCall( 0x00421640 );
  };

} // namespace Gothic_II_Addon

#endif // __ZCCS_POOL_H__VER3__