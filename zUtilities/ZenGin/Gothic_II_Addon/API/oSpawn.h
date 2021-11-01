// Supported with union (c) 2018-2021 Union team

#ifndef __OSPAWN_H__VER3__
#define __OSPAWN_H__VER3__

#include "zVob.h"

namespace Gothic_II_Addon {

  // sizeof 24h
  class oCSpawnManager {
  public:
    // sizeof 14h
    typedef struct oSSpawnNode {
    public:
      oCNpc* npc;     // sizeof 04h    offset 00h
      zVEC3 spawnPos; // sizeof 0Ch    offset 04h
      float timer;    // sizeof 04h    offset 10h

      oSSpawnNode() {}
    } oTSpawnNode;

    zCArray<oTSpawnNode*> spawnList; // sizeof 0Ch    offset 00h
    int spawningEnabled;             // sizeof 04h    offset 0Ch
    zVEC3 camPos;                    // sizeof 0Ch    offset 10h
    float insertTime;                // sizeof 04h    offset 1Ch
    int spawnFlags;                  // sizeof 04h    offset 20h

    void oCSpawnManager_OnInit()                      zCall( 0x00777730 );
    oCSpawnManager()                                  zInit( oCSpawnManager_OnInit() );
    ~oCSpawnManager()                                 zCall( 0x00777780 );
    void ClearList()                                  zCall( 0x00777880 );
    void InsertInList( oSSpawnNode* )                 zCall( 0x007778D0 );
    void RemoveFromList( oSSpawnNode* )               zCall( 0x007779B0 );
    int IsSpawningEnabled()                           zCall( 0x00777A20 );
    void SetSpawningEnabled( int )                    zCall( 0x00777A30 );
    void SpawnImmediately( int )                      zCall( 0x00777A40 );
    void CheckInsertNpcs()                            zCall( 0x00777BE0 );
    void ShowDebugInfo()                              zCall( 0x00777C70 );
    void CheckInsertNpc()                             zCall( 0x007780B0 );
    void InitCameraPos()                              zCall( 0x007788C0 );
    int InsertNpc( oCNpc*, zVEC3 const& )             zCall( 0x00778920 );
    oCNpc* SummonNpc( int, zVEC3 const&, float )      zCall( 0x00778A20 );
    oCNpc* SpawnNpc( int, zSTRING const&, float )     zCall( 0x00778B20 );
    void SpawnNpc( oCNpc*, zSTRING const&, float )    zCall( 0x00778BA0 );
    void SpawnNpc( oCNpc*, zVEC3 const&, float )      zCall( 0x00778E70 );
    void CheckForInvalidDialogCamPos( float, oCNpc* ) zCall( 0x00778FD0 );
    int UseDeadNpcRoutinePos( oCNpc* )                zCall( 0x007791B0 );
    int CanDeadNpcBeRemoved( oCNpc* )                 zCall( 0x00779260 );
    int CheckRemoveNpc( oCNpc* )                      zCall( 0x007792E0 );
    void DeleteNpc( oCNpc* )                          zCall( 0x00779690 );
    void DeleteAllSummoned()                          zCall( 0x00779720 );
    void Archive( zCArchiver& )                       zCall( 0x007797F0 );
    void Unarchive( zCArchiver& )                     zCall( 0x00779890 );
    static void SetInsertRange( float )               zCall( 0x00777820 );
    static float GetInsertRange()                     zCall( 0x00777830 );
    static void SetRemoveRange( float )               zCall( 0x00777840 );
    static float GetRemoveRange()                     zCall( 0x00777850 );
    static void SetSpawnTime( float )                 zCall( 0x00777860 );
    static float GetSpawnTime()                       zCall( 0x00777870 );

    // user API
    #include "oCSpawnManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OSPAWN_H__VER3__