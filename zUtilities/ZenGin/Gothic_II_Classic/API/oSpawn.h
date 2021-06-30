// Supported with union (c) 2018 Union team

#ifndef __OSPAWN_H__VER2__
#define __OSPAWN_H__VER2__

#include "zVob.h"

namespace Gothic_II_Classic {

  class oCSpawnManager {
  public:
    typedef struct oSSpawnNode {
    public:
      oCNpc* npc;
      zVEC3 spawnPos;
      float timer;

      oSSpawnNode() {}
    } oTSpawnNode;

    zCArray<oTSpawnNode*> spawnList;
    int spawningEnabled;
    zVEC3 camPos;
    float insertTime;
    int spawnFlags;

    void oCSpawnManager_OnInit()                      zCall( 0x007181A0 );
    oCSpawnManager()                                  zInit( oCSpawnManager_OnInit() );
    ~oCSpawnManager()                                 zCall( 0x007181F0 );
    void ClearList()                                  zCall( 0x007182F0 );
    void InsertInList( oSSpawnNode* )                 zCall( 0x00718340 );
    void RemoveFromList( oSSpawnNode* )               zCall( 0x00718420 );
    int IsSpawningEnabled()                           zCall( 0x00718490 );
    void SetSpawningEnabled( int )                    zCall( 0x007184A0 );
    void SpawnImmediately( int )                      zCall( 0x007184B0 );
    void CheckInsertNpcs()                            zCall( 0x00718650 );
    void ShowDebugInfo()                              zCall( 0x007186E0 );
    void CheckInsertNpc()                             zCall( 0x00718B20 );
    void InitCameraPos()                              zCall( 0x00719000 );
    int InsertNpc( oCNpc*, zVEC3 const& )             zCall( 0x00719060 );
    oCNpc* SummonNpc( int, zVEC3 const&, float )      zCall( 0x00719160 );
    oCNpc* SpawnNpc( int, zSTRING const&, float )     zCall( 0x00719260 );
    void SpawnNpc( oCNpc*, zSTRING const&, float )    zCall( 0x007192E0 );
    void SpawnNpc( oCNpc*, zVEC3 const&, float )      zCall( 0x007195B0 );
    void CheckForInvalidDialogCamPos( float, oCNpc* ) zCall( 0x00719710 );
    int CheckRemoveNpc( oCNpc* )                      zCall( 0x007198F0 );
    void DeleteNpc( oCNpc* )                          zCall( 0x00719C50 );
    void DeleteAllSummoned()                          zCall( 0x00719CE0 );
    void Archive( zCArchiver& )                       zCall( 0x00719DB0 );
    void Unarchive( zCArchiver& )                     zCall( 0x00719E50 );
    static void SetInsertRange( float )               zCall( 0x00718290 );
    static float GetInsertRange()                     zCall( 0x007182A0 );
    static void SetRemoveRange( float )               zCall( 0x007182B0 );
    static float GetRemoveRange()                     zCall( 0x007182C0 );
    static void SetSpawnTime( float )                 zCall( 0x007182D0 );
    static float GetSpawnTime()                       zCall( 0x007182E0 );

    // user API
    #include "oCSpawnManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OSPAWN_H__VER2__