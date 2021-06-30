// Supported with union (c) 2018 Union team

#ifndef __OROUTINE_H__VER3__
#define __OROUTINE_H__VER3__

#include "zVob.h"

namespace Gothic_II_Addon {

  class oCRtnCutscene {
  public:
    oCNpc* npc;
    zSTRING csName;
    zSTRING roleName;
    int ignorePlayState;
    int active;

    void oCRtnCutscene_OnInit() zCall( 0x00774270 );
    void ResetPlayState()       zCall( 0x00774160 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x00774180 );

    // user API
    #include "oCRtnCutscene.inl"
  };

  class oCRtnEntry {
  public:
    int hour1;
    int min1;
    int hour2;
    int min2;
    int f_script;
    zSTRING wpname;
    int instance;
    zCVob* poi;
    oCNpc* npc;
    oCRtnCutscene* cutscene;
    int overlay;

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

  class oCRtnManager {
  public:
    struct TRtn_WayBoxLimit {
    public:
      int begin;
      zTBBox3D bbox;
      float value;
      oCNpc* npc;

      // user API
      #include "oCRtnManager_TRtn_WayBoxLimit.inl"
    };

    struct TRtn_WayBox {
    public:
      zTBBox3D bbox;
      oCNpc* npc;
      int found;

      // user API
      #include "oCRtnManager_TRtn_WayBox.inl"
    };

    int indexStart[3];
    int indexEnd[3];
    zCWorld* world;
    zCListSort<oCRtnEntry>* nextEntryNode;
    zCListSort<oCRtnEntry> rtnList;
    zCListSort<TRtn_WayBox> wayboxListX;
    zCListSort<TRtn_WayBox> wayboxListY;
    zCListSort<TRtn_WayBox> wayboxListZ;
    zCList<oCNpc> activeList;
    zCArraySort<TRtn_WayBoxLimit*> wayboxList[3];

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