// Supported with union (c) 2018-2021 Union team

#ifndef __OROUTINE_H__VER0__
#define __OROUTINE_H__VER0__

#include "zVob.h"

namespace Gothic_I_Classic {

  // sizeof 38h
  class oCRtnCutscene {
  public:
    oCNpc* npc;          // sizeof 04h    offset 04h
    zSTRING csName;      // sizeof 14h    offset 08h
    zSTRING roleName;    // sizeof 14h    offset 1Ch
    int ignorePlayState; // sizeof 04h    offset 30h
    int active;          // sizeof 04h    offset 34h

    void oCRtnCutscene_OnInit() zCall( 0x006CC510 );
    void ResetPlayState()       zCall( 0x006CC400 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x006CC420 );

    // user API
    #include "oCRtnCutscene.inl"
  };

  // sizeof 3Ch
  class oCRtnEntry {
  public:
    int hour1;               // sizeof 04h    offset 00h
    int min1;                // sizeof 04h    offset 04h
    int hour2;               // sizeof 04h    offset 08h
    int min2;                // sizeof 04h    offset 0Ch
    int f_script;            // sizeof 04h    offset 10h
    zSTRING wpname;          // sizeof 14h    offset 14h
    int instance;            // sizeof 04h    offset 28h
    zCVob* poi;              // sizeof 04h    offset 2Ch
    oCNpc* npc;              // sizeof 04h    offset 30h
    oCRtnCutscene* cutscene; // sizeof 04h    offset 34h
    int overlay;             // sizeof 04h    offset 38h

    void oCRtnEntry_OnInit()                                                        zCall( 0x006CC560 );
    void oCRtnEntry_OnInit( int, int, int, int, int, zSTRING const&, int )          zCall( 0x006CC5A0 );
    oCRtnEntry()                                                                    zInit( oCRtnEntry_OnInit() );
    oCRtnEntry( int a0, int a1, int a2, int a3, int a4, zSTRING const& a5, int a6 ) zInit( oCRtnEntry_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    ~oCRtnEntry()                                                                   zCall( 0x006CC740 );
    void GetTime( int&, int&, int&, int& )                                          zCall( 0x006CC7C0 );
    void SetTime( int, int, int, int )                                              zCall( 0x006CC7F0 );
    int GetState()                                                                  zCall( 0x006CC810 );
    zSTRING GetWaypoint()                                                           zCall( 0x006CC820 );

    // user API
    #include "oCRtnEntry.inl"
  };

  // sizeof 88h
  class oCRtnManager {
  public:
    // sizeof 24h
    struct TRtn_WayBoxLimit {
    public:
      int begin;     // sizeof 04h    offset 00h
      zTBBox3D bbox; // sizeof 18h    offset 04h
      float value;   // sizeof 04h    offset 1Ch
      oCNpc* npc;    // sizeof 04h    offset 20h

      // user API
      #include "oCRtnManager_TRtn_WayBoxLimit.inl"
    };

    // sizeof 20h
    struct TRtn_WayBox {
    public:
      zTBBox3D bbox; // sizeof 18h    offset 00h
      oCNpc* npc;    // sizeof 04h    offset 18h
      int found;     // sizeof 04h    offset 1Ch

      // user API
      #include "oCRtnManager_TRtn_WayBox.inl"
    };

    int indexStart[3];                            // sizeof 0Ch    offset 00h
    int indexEnd[3];                              // sizeof 0Ch    offset 0Ch
    zCWorld* world;                               // sizeof 04h    offset 18h
    zCListSort<oCRtnEntry>* nextEntryNode;        // sizeof 04h    offset 1Ch
    zCListSort<oCRtnEntry> rtnList;               // sizeof 0Ch    offset 20h
    zCListSort<TRtn_WayBox> wayboxListX;          // sizeof 0Ch    offset 2Ch
    zCListSort<TRtn_WayBox> wayboxListY;          // sizeof 0Ch    offset 38h
    zCListSort<TRtn_WayBox> wayboxListZ;          // sizeof 0Ch    offset 44h
    zCList<oCNpc> activeList;                     // sizeof 08h    offset 50h
    zCArraySort<TRtn_WayBoxLimit*> wayboxList[3]; // sizeof 30h    offset 58h

    void oCRtnManager_OnInit()                                          zCall( 0x006CC970 );
    oCRtnManager()                                                      zInit( oCRtnManager_OnInit() );
    ~oCRtnManager()                                                     zCall( 0x006CCA20 );
    void SetWorld( zCWorld* )                                           zCall( 0x006CCBA0 );
    void ShowRoutine( int, int, oCNpc* )                                zCall( 0x006CCBB0 );
    zSTRING GetRoutineString( oCRtnEntry* )                             zCall( 0x006CCE30 );
    void Insert( oCNpc*, oCRtnEntry* )                                  zCall( 0x006CD1C0 );
    void UpdateGlobalRoutineEntry()                                     zCall( 0x006CD1E0 );
    void UpdateSingleRoutine( oCNpc* )                                  zCall( 0x006CD240 );
    void RestartRoutines()                                              zCall( 0x006CD390 );
    int FindRoutine( oCNpc*, oCRtnEntry*&, oCRtnEntry*& )               zCall( 0x006CD720 );
    void CheckRoutines()                                                zCall( 0x006CD860 );
    zVEC3 GetRoutinePos( oCNpc* )                                       zCall( 0x006CD970 );
    void WriteRoutine( zCArchiver&, oCNpc*, int )                       zCall( 0x006CDC60 );
    void ReadRoutine( zCArchiver&, oCNpc* )                             zCall( 0x006CDD70 );
    void RemoveEntry( oCRtnEntry* )                                     zCall( 0x006CE040 );
    void RemoveRoutine( oCNpc* )                                        zCall( 0x006CE0C0 );
    void RemoveOverlay( oCNpc* )                                        zCall( 0x006CE250 );
    void SetDailyRoutinePos( int )                                      zCall( 0x006CE3F0 );
    void InitWayBoxes()                                                 zCall( 0x006CE450 );
    void InsertWaybox( oCNpc*, zVEC3&, zVEC3& )                         zCall( 0x006CE4A0 );
    void RemoveWayBoxes( oCNpc* )                                       zCall( 0x006CE7A0 );
    void CreateWayBoxes( oCNpc* )                                       zCall( 0x006CE8B0 );
    void DrawWayBoxes()                                                 zCall( 0x006CECC0 );
    void CreateActiveList( oCNpc*, zTBBox3D& )                          zCall( 0x006CED00 );
    int CollidesWithWayBox( zTBBox3D&, zCList<oCNpc>& )                 zCall( 0x006CEE30 );
    int GetNumOfWayBoxes()                                              zCall( 0x006CF060 );
    static int Sort_Routine( oCRtnEntry*, oCRtnEntry* )                 zCall( 0x006CC8A0 );
    static int Sort_WayBoxLimit( TRtn_WayBoxLimit*, TRtn_WayBoxLimit* ) zCall( 0x006CC8F0 );
    static int Sort_WayBoxX( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x006CC910 );
    static int Sort_WayBoxY( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x006CC930 );
    static int Sort_WayBoxZ( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x006CC950 );

    // user API
    #include "oCRtnManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OROUTINE_H__VER0__