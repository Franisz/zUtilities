// Supported with union (c) 2018 Union team

#ifndef __OROUTINE_H__VER0__
#define __OROUTINE_H__VER0__

#include "zVob.h"

namespace Gothic_I_Classic {

  class oCRtnCutscene {
  public:
    oCNpc* npc;
    zSTRING csName;
    zSTRING roleName;
    int ignorePlayState;
    int active;

    void oCRtnCutscene_OnInit() zCall( 0x006CC510 );
    void ResetPlayState()       zCall( 0x006CC400 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x006CC420 );

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