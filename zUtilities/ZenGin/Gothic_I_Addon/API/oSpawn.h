// Supported with union (c) 2018 Union team

#ifndef __OSPAWN_H__VER1__
#define __OSPAWN_H__VER1__

#include "zVob.h"

namespace Gothic_I_Addon {

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

    void oCSpawnManager_OnInit()                      zCall( 0x00705EE0 );
    oCSpawnManager()                                  zInit( oCSpawnManager_OnInit() );
    ~oCSpawnManager()                                 zCall( 0x00705F40 );
    void ClearList()                                  zCall( 0x00706040 );
    void InsertInList( oSSpawnNode* )                 zCall( 0x00706090 );
    void RemoveFromList( oSSpawnNode* )               zCall( 0x00706190 );
    int IsSpawningEnabled()                           zCall( 0x00706200 );
    void SetSpawningEnabled( int )                    zCall( 0x00706210 );
    void SpawnImmediately( int )                      zCall( 0x00706220 );
    void CheckInsertNpcs()                            zCall( 0x007063D0 );
    void ShowDebugInfo()                              zCall( 0x00706470 );
    void CheckInsertNpc()                             zCall( 0x00706880 );
    void InitCameraPos()                              zCall( 0x00706CE0 );
    int InsertNpc( oCNpc*, zVEC3 const& )             zCall( 0x00706D40 );
    oCNpc* SummonNpc( int, zVEC3 const&, float )      zCall( 0x00706E40 );
    oCNpc* SpawnNpc( int, zSTRING const&, float )     zCall( 0x00706F40 );
    void SpawnNpc( oCNpc*, zSTRING const&, float )    zCall( 0x00706FB0 );
    void SpawnNpc( oCNpc*, zVEC3 const&, float )      zCall( 0x00707230 );
    void CheckForInvalidDialogCamPos( float, oCNpc* ) zCall( 0x007073C0 );
    int CheckRemoveNpc( oCNpc* )                      zCall( 0x007075C0 );
    void DeleteNpc( oCNpc* )                          zCall( 0x00707950 );
    void DeleteAllSummoned()                          zCall( 0x007079F0 );
    void Archive( zCArchiver& )                       zCall( 0x00707AC0 );
    void Unarchive( zCArchiver& )                     zCall( 0x00707B50 );
    static void SetInsertRange( float )               zCall( 0x00705FE0 );
    static float GetInsertRange()                     zCall( 0x00705FF0 );
    static void SetRemoveRange( float )               zCall( 0x00706000 );
    static float GetRemoveRange()                     zCall( 0x00706010 );
    static void SetSpawnTime( float )                 zCall( 0x00706020 );
    static float GetSpawnTime()                       zCall( 0x00706030 );

    // user API
    #include "oCSpawnManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OSPAWN_H__VER1__