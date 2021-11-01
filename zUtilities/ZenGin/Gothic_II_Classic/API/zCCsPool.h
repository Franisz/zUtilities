// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_POOL_H__VER2__
#define __ZCCS_POOL_H__VER2__

#include "zCCsProps.h"

namespace Gothic_II_Classic {
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

    void zCCSPoolItem_OnInit()                                zCall( 0x00420F00 );
    void zCCSPoolItem_OnInit( zCCSCutsceneContext* )          zCall( 0x00421060 );
    zCCSPoolItem()                                            zInit( zCCSPoolItem_OnInit() );
    zCCSPoolItem( zCCSCutsceneContext* a0 )                   zInit( zCCSPoolItem_OnInit( a0 ));
    void Init()                                               zCall( 0x004211C0 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour( int& )       zCall( 0x00421250 );
    zCCSProps::zTCSRunBehaviour GetRunBehaviour()             zCall( 0x00421260 );
    void SetRunBehaviour( zCCSProps::zTCSRunBehaviour, int& ) zCall( 0x00421270 );
    void TestedDeactivation()                                 zCall( 0x004214F0 );
    int IsAllowedToPlay()                                     zCall( 0x00421510 );
    void ClrFlags( long )                                     zCall( 0x00421890 );
    void SetFlags( long )                                     zCall( 0x004218B0 );
    int HasFlags( long )                                      zCall( 0x004218C0 );
    static zCObject* _CreateNewInstance()                     zCall( 0x00420DC0 );
    /* for zSTRING num : 2*/
    virtual ~zCCSPoolItem()                                   zCall( 0x004211D0 );
    virtual void PrintDebugInfo()                             zCall( 0x00421530 );
    /* for zCObject num : 3*/
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x00420EF0 );
    virtual void Archive( zCArchiver& )                       zCall( 0x00421290 );
    virtual void Unarchive( zCArchiver& )                     zCall( 0x00421310 );
  };

} // namespace Gothic_II_Classic

#endif // __ZCCS_POOL_H__VER2__