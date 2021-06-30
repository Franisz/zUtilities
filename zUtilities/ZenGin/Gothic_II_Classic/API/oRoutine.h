// Supported with union (c) 2018 Union team

#ifndef __OROUTINE_H__VER2__
#define __OROUTINE_H__VER2__

#include "zVob.h"

namespace Gothic_II_Classic {

  class oCRtnCutscene {
  public:
    oCNpc* npc;
    zSTRING csName;
    zSTRING roleName;
    int ignorePlayState;
    int active;

    void oCRtnCutscene_OnInit() zCall( 0x00714CE0 );
    void ResetPlayState()       zCall( 0x00714BD0 );
    oCRtnCutscene()             zInit( oCRtnCutscene_OnInit() );
    virtual ~oCRtnCutscene()    zCall( 0x00714BF0 );

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

    void oCRtnEntry_OnInit()                                                        zCall( 0x00714D30 );
    void oCRtnEntry_OnInit( int, int, int, int, int, zSTRING const&, int )          zCall( 0x00714D70 );
    oCRtnEntry()                                                                    zInit( oCRtnEntry_OnInit() );
    oCRtnEntry( int a0, int a1, int a2, int a3, int a4, zSTRING const& a5, int a6 ) zInit( oCRtnEntry_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    ~oCRtnEntry()                                                                   zCall( 0x00714F10 );
    void GetTime( int&, int&, int&, int& )                                          zCall( 0x00714F90 );
    void SetTime( int, int, int, int )                                              zCall( 0x00714FC0 );
    int GetState()                                                                  zCall( 0x00714FE0 );
    zSTRING GetWaypoint()                                                           zCall( 0x00714FF0 );

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

    void oCRtnManager_OnInit()                                          zCall( 0x00715140 );
    oCRtnManager()                                                      zInit( oCRtnManager_OnInit() );
    ~oCRtnManager()                                                     zCall( 0x007151F0 );
    void SetWorld( zCWorld* )                                           zCall( 0x00715370 );
    void ShowRoutine( int, int, oCNpc* )                                zCall( 0x00715380 );
    zSTRING GetRoutineString( oCRtnEntry* )                             zCall( 0x007155F0 );
    void Insert( oCNpc*, oCRtnEntry* )                                  zCall( 0x00715A70 );
    void UpdateGlobalRoutineEntry()                                     zCall( 0x00715A90 );
    void UpdateSingleRoutine( oCNpc* )                                  zCall( 0x00715AF0 );
    void RestartRoutines()                                              zCall( 0x00715C50 );
    int FindRoutine( oCNpc*, oCRtnEntry*&, oCRtnEntry*& )               zCall( 0x00715FF0 );
    void CheckRoutines()                                                zCall( 0x00716130 );
    zVEC3 GetRoutinePos( oCNpc* )                                       zCall( 0x00716240 );
    void WriteRoutine( zCArchiver&, oCNpc*, int )                       zCall( 0x00716530 );
    void ReadRoutine( zCArchiver&, oCNpc* )                             zCall( 0x00716640 );
    void RemoveEntry( oCRtnEntry* )                                     zCall( 0x007168E0 );
    void RemoveRoutine( oCNpc* )                                        zCall( 0x00716960 );
    void CheckConsistency( oCNpc* )                                     zCall( 0x00716AF0 );
    void RemoveOverlay( oCNpc* )                                        zCall( 0x00716DA0 );
    void SetDailyRoutinePos( int )                                      zCall( 0x00716F40 );
    void InitWayBoxes()                                                 zCall( 0x00716FA0 );
    void InsertWaybox( oCNpc*, zVEC3&, zVEC3& )                         zCall( 0x00716FF0 );
    void RemoveWayBoxes( oCNpc* )                                       zCall( 0x007172C0 );
    void CreateWayBoxes( oCNpc* )                                       zCall( 0x007173D0 );
    void DrawWayBoxes()                                                 zCall( 0x00717790 );
    void CreateActiveList( oCNpc*, zTBBox3D& )                          zCall( 0x007177D0 );
    int CollidesWithWayBox( zTBBox3D&, zCList<oCNpc>& )                 zCall( 0x00717900 );
    int GetNumOfWayBoxes()                                              zCall( 0x00717B00 );
    static int Sort_Routine( oCRtnEntry*, oCRtnEntry* )                 zCall( 0x00715070 );
    static int Sort_WayBoxLimit( TRtn_WayBoxLimit*, TRtn_WayBoxLimit* ) zCall( 0x007150C0 );
    static int Sort_WayBoxX( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x007150E0 );
    static int Sort_WayBoxY( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00715100 );
    static int Sort_WayBoxZ( TRtn_WayBox*, TRtn_WayBox* )               zCall( 0x00715120 );

    // user API
    #include "oCRtnManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OROUTINE_H__VER2__