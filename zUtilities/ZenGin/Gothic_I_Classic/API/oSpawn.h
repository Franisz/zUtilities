// Supported with union (c) 2018-2021 Union team

#ifndef __OSPAWN_H__VER0__
#define __OSPAWN_H__VER0__

#include "zVob.h"

namespace Gothic_I_Classic {

  // sizeof 20h
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

    void oCSpawnManager_OnInit()                      zCall( 0x006CF4D0 );
    oCSpawnManager()                                  zInit( oCSpawnManager_OnInit() );
    ~oCSpawnManager()                                 zCall( 0x006CF530 );
    void ClearList()                                  zCall( 0x006CF630 );
    void InsertInList( oSSpawnNode* )                 zCall( 0x006CF680 );
    void RemoveFromList( oSSpawnNode* )               zCall( 0x006CF770 );
    int IsSpawningEnabled()                           zCall( 0x006CF7E0 );
    void SetSpawningEnabled( int )                    zCall( 0x006CF7F0 );
    void SpawnImmediately( int )                      zCall( 0x006CF800 );
    void CheckInsertNpcs()                            zCall( 0x006CF9A0 );
    void ShowDebugInfo()                              zCall( 0x006CFA30 );
    void CheckInsertNpc()                             zCall( 0x006CFDE0 );
    void InitCameraPos()                              zCall( 0x006D01F0 );
    int InsertNpc( oCNpc*, zVEC3 const& )             zCall( 0x006D0250 );
    oCNpc* SummonNpc( int, zVEC3 const&, float )      zCall( 0x006D0350 );
    oCNpc* SpawnNpc( int, zSTRING const&, float )     zCall( 0x006D0450 );
    void SpawnNpc( oCNpc*, zSTRING const&, float )    zCall( 0x006D04C0 );
    void SpawnNpc( oCNpc*, zVEC3 const&, float )      zCall( 0x006D0710 );
    void CheckForInvalidDialogCamPos( float, oCNpc* ) zCall( 0x006D08A0 );
    int CheckRemoveNpc( oCNpc* )                      zCall( 0x006D0A80 );
    void DeleteNpc( oCNpc* )                          zCall( 0x006D0DE0 );
    void DeleteAllSummoned()                          zCall( 0x006D0E70 );
    void Archive( zCArchiver& )                       zCall( 0x006D0F40 );
    void Unarchive( zCArchiver& )                     zCall( 0x006D0FD0 );
    static void SetInsertRange( float )               zCall( 0x006CF5D0 );
    static float GetInsertRange()                     zCall( 0x006CF5E0 );
    static void SetRemoveRange( float )               zCall( 0x006CF5F0 );
    static float GetRemoveRange()                     zCall( 0x006CF600 );
    static void SetSpawnTime( float )                 zCall( 0x006CF610 );
    static float GetSpawnTime()                       zCall( 0x006CF620 );

    // user API
    #include "oCSpawnManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OSPAWN_H__VER0__