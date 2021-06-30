// Supported with union (c) 2018 Union team

#ifndef __OROUTINE_H__VER1__
#define __OROUTINE_H__VER1__

#include "zVob.h"

namespace Gothic_I_Addon {

  class oCRtnCutscene {
  public:
    oCNpc* npc;
    zSTRING csName;
    zSTRING roleName;
    int ignorePlayState;
    int active;

    void oCRtnCutscene_OnInit() zCall( 0x00702BA0 );
    void ResetPlayState()       zCall( 0x00702A80 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x00702AA0 );

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

    void oCRtnEntry_OnInit()                                                        zCall( 0x00702BF0 );
    void oCRtnEntry_OnInit( int, int, int, int, int, zSTRING const&, int )          zCall( 0x00702C30 );
    oCRtnEntry()                                                                    zInit( oCRtnEntry_OnInit() );
    oCRtnEntry( int a0, int a1, int a2, int a3, int a4, zSTRING const& a5, int a6 ) zInit( oCRtnEntry_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    ~oCRtnEntry()                                                                   zCall( 0x00702DC0 );
    void GetTime( int&, int&, int&, int& )                                          zCall( 0x00702E50 );
    void SetTime( int, int, int, int )                                              zCall( 0x00702E80 );
    int GetState()                                                                  zCall( 0x00702EA0 );
    zSTRING GetWaypoint()                                                           zCall( 0x00702EB0 );

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

    void oCRtnManager_OnInit()                                          zCall( 0x00703000 );
    oCRtnManager()                                                      zInit( oCRtnManager_OnInit() );
    ~oCRtnManager()                                                     zCall( 0x007030B0 );
    void SetWorld( zCWorld* )                                           zCall( 0x00703230 );
    void ShowRoutine( int, int, oCNpc* )                                zCall( 0x00703240 );
    zSTRING GetRoutineString( oCRtnEntry* )                             zCall( 0x007034C0 );
    void Insert( oCNpc*, oCRtnEntry* )                                  zCall( 0x007038E0 );
    void UpdateGlobalRoutineEntry()                                     zCall( 0x00703900 );
    void UpdateSingleRoutine( oCNpc* )                                  zCall( 0x00703960 );
    void RestartRoutines()                                              zCall( 0x00703B10 );
    int FindRoutine( oCNpc*, oCRtnEntry*&, oCRtnEntry*& )               zCall( 0x00703EF0 );
    void CheckRoutines()                                                zCall( 0x00704020 );
    zVEC3 GetRoutinePos( oCNpc* )                                       zCall( 0x00704130 );
    void WriteRoutine( zCArchiver&, oCNpc*, int )                       zCall( 0x00704450 );
    void ReadRoutine( zCArchiver&, oCNpc* )                             zCall( 0x00704560 );
    void RemoveEntry( oCRtnEntry* )                                     zCall( 0x00704800 );
    void RemoveRoutine( oCNpc* )                                        zCall( 0x00704890 );
    void RemoveOverlay( oCNpc* )                                        zCall( 0x00704A00 );
    void SetDailyRoutinePos( int )                                      zCall( 0x00704B80 );
    void InitWayBoxes()                                                 zCall( 0x00704BE0 );
    void InsertWaybox( oCNpc*, zVEC3&, zVEC3& )                         zCall( 0x00704C30 );
    void RemoveWayBoxes( oCNpc* )                                       zCall( 0x00704F40 );
    void CreateWayBoxes( oCNpc* )                                       zCall( 0x00705030 );
    void DrawWayBoxes()                                                 zCall( 0x00705460 );
    void CreateActiveList( oCNpc*, zTBBox3D& )                          zCall( 0x007054A0 );
    int CollidesWithWayBox( zTBBox3D&, zCList<oCNpc>& )                 zCall( 0x007055D0 );
    int GetNumOfWayBoxes()                                              zCall( 0x007057F0 );
    static int Sort_Routine( oCRtnEntry*, oCRtnEntry* )                 zCall( 0x00702F30 );
    static int Sort_WayBoxLimit( TRtn_WayBoxLimit*, TRtn_WayBoxLimit* ) zCall( 0x00702F80 );
    static int Sort_WayBoxX( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00702FA0 );
    static int Sort_WayBoxY( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00702FC0 );
    static int Sort_WayBoxZ( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00702FE0 );

    // user API
    #include "oCRtnManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OROUTINE_H__VER1__