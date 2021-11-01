// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_POOL_H__VER0__
#define __ZCCS_POOL_H__VER0__

#include "zCCsProps.h"

namespace Gothic_I_Classic {
  const int CS_PLAYING = 1<<0;
  const int CS_PLAYED  = 1<<1;

  // sizeof 50h
  class zCCSPoolItem : public zSTRING, public zCObject {
  public:
    zCLASS_DECLARATION( zCCSPoolItem )

    int deactivated;                          // sizeof 04h    offset 38h
    int runBehaviourValue;                    // sizeof 04h    offset 3Ch
    zCCSProps::zTCSRunBehaviour runBehaviour; // sizeof 04h    offset 40h
    int numPlayed;                            // sizeof 04h    offset 44h
    int playCounter;                          // sizeof 04h    offset 48h
    int flags;                                // sizeof 04h    offset 4Ch

    void zCCSPoolItem_OnInit()                                          zCall( 0x00420AF0 );
    void zCCSPoolItem_OnInit( zCCSCutsceneContext* )                    zCall( 0x00420C50 );
    zCCSPoolItem()                                                      zInit( zCCSPoolItem_OnInit() );
    zCCSPoolItem( zCCSCutsceneContext* a0 )                             zInit( zCCSPoolItem_OnInit( a0 ));
    void Init()                                                         zCall( 0x00420DB0 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour( int& )                 zCall( 0x00420E40 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour()                       zCall( 0x00420E50 );
    void SetRunBehaviour( zCCSProps::zTCSRunBehaviour, int& )           zCall( 0x00420E60 );
    void TestedDeactivation()                                           zCall( 0x004210E0 );
    int IsAllowedToPlay()                                               zCall( 0x00421100 );
    void ClrFlags( long )                                               zCall( 0x00421430 );
    void SetFlags( long )                                               zCall( 0x00421450 );
    int HasFlags( long )                                                zCall( 0x00421460 );
    static zCObject* _CreateNewInstance()                               zCall( 0x004209A0 );
    /* for zSTRING num : 2*/
    virtual ~zCCSPoolItem()                                             zCall( 0x00420DC0 );
    virtual void PrintDebugInfo()                                       zCall( 0x00421120 );
    /* for zCObject num : 3*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00420AE0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00420E80 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00420F00 );
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_POOL_H__VER0__