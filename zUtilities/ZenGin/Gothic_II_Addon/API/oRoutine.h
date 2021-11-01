// Supported with union (c) 2018-2021 Union team

#ifndef __OROUTINE_H__VER3__
#define __OROUTINE_H__VER3__

#include "zVob.h"

namespace Gothic_II_Addon {

  // sizeof 38h
  class oCRtnCutscene {
  public:
    oCNpc* npc;          // sizeof 04h    offset 04h
    zSTRING csName;      // sizeof 14h    offset 08h
    zSTRING roleName;    // sizeof 14h    offset 1Ch
    int ignorePlayState; // sizeof 04h    offset 30h
    int active;          // sizeof 04h    offset 34h

    void oCRtnCutscene_OnInit() zCall( 0x00774270 );
    void ResetPlayState()       zCall( 0x00774160 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x00774180 );

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

    void oCRtnEntry_OnInit()                                                        zCall( 0x007742C0 );
    void oCRtnEntry_OnInit( int, int, int, int, int, zSTRING const&, int )          zCall( 0x00774300 );
    oCRtnEntry()                                                                    zInit( oCRtnEntry_OnInit() );
    oCRtnEntry( int a0, int a1, int a2, int a3, int a4, zSTRING const& a5, int a6 ) zInit( oCRtnEntry_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    ~oCRtnEntry()                                                                   zCall( 0x007744A0 );
    void GetTime( int&, int&, int&, int& )                                          zCall( 0x00774520 );
    void SetTime( int, int, int, int )                                              zCall( 0x00774550 );
    int GetState()                                                                  zCall( 0x00774570 );
    zSTRING GetWaypoint()                                                           zCall( 0x00774580 );

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

    void oCRtnManager_OnInit()                                          zCall( 0x007746D0 );
    oCRtnManager()                                                      zInit( oCRtnManager_OnInit() );
    ~oCRtnManager()                                                     zCall( 0x00774780 );
    void SetWorld( zCWorld* )                                           zCall( 0x00774900 );
    void ShowRoutine( int, int, oCNpc* )                                zCall( 0x00774910 );
    zSTRING GetRoutineString( oCRtnEntry* )                             zCall( 0x00774B80 );
    void Insert( oCNpc*, oCRtnEntry* )                                  zCall( 0x00775000 );
    void UpdateGlobalRoutineEntry()                                     zCall( 0x00775020 );
    void UpdateSingleRoutine( oCNpc* )                                  zCall( 0x00775080 );
    void RestartRoutines()                                              zCall( 0x007751E0 );
    int FindRoutine( oCNpc*, oCRtnEntry*&, oCRtnEntry*& )               zCall( 0x00775580 );
    void CheckRoutines()                                                zCall( 0x007756C0 );
    zVEC3 GetRoutinePos( oCNpc* )                                       zCall( 0x007757D0 );
    void WriteRoutine( zCArchiver&, oCNpc*, int )                       zCall( 0x00775AC0 );
    void ReadRoutine( zCArchiver&, oCNpc* )                             zCall( 0x00775BD0 );
    void RemoveEntry( oCRtnEntry* )                                     zCall( 0x00775E70 );
    void RemoveRoutine( oCNpc* )                                        zCall( 0x00775EF0 );
    void CheckConsistency( oCNpc* )                                     zCall( 0x00776080 );
    void RemoveOverlay( oCNpc* )                                        zCall( 0x00776330 );
    void SetDailyRoutinePos( int )                                      zCall( 0x007764D0 );
    void InitWayBoxes()                                                 zCall( 0x00776530 );
    void InsertWaybox( oCNpc*, zVEC3&, zVEC3& )                         zCall( 0x00776580 );
    void RemoveWayBoxes( oCNpc* )                                       zCall( 0x00776850 );
    void CreateWayBoxes( oCNpc* )                                       zCall( 0x00776960 );
    void DrawWayBoxes()                                                 zCall( 0x00776D20 );
    void CreateActiveList( oCNpc*, zTBBox3D& )                          zCall( 0x00776D60 );
    int CollidesWithWayBox( zTBBox3D&, zCList<oCNpc>& )                 zCall( 0x00776E90 );
    int GetNumOfWayBoxes()                                              zCall( 0x00777090 );
    static int Sort_Routine( oCRtnEntry*, oCRtnEntry* )                 zCall( 0x00774600 );
    static int Sort_WayBoxLimit( TRtn_WayBoxLimit*, TRtn_WayBoxLimit* ) zCall( 0x00774650 );
    static int Sort_WayBoxX( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00774670 );
    static int Sort_WayBoxY( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00774690 );
    static int Sort_WayBoxZ( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x007746B0 );

    // user API
    #include "oCRtnManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OROUTINE_H__VER3__