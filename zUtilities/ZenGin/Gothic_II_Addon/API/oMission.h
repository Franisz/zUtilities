// Supported with union (c) 2018 Union team

#ifndef __OMISSION_H__VER3__
#define __OMISSION_H__VER3__

#include "zVob.h"
#include "oMenu_Status.h"

namespace Gothic_II_Addon {
  const int MIS_NOMISSION   = -1;
  const int MIS_NOTINVOLVED = 0;
  const int MIS_OFFERED     = 1;
  const int MIS_REFUSED     = 2;
  const int MIS_RUNNING     = 3;
  const int MIS_DONE        = 4;
  const int MIS_DONELATE    = 5;
  const int MIS_CANCELED    = 6;
  const int MIS_FAILED      = 7;

  class oCMissionManager {
  public:
    zCArraySort<oCMission*> missionList;

    void oCMissionManager_OnInit()                             zCall( 0x00714FD0 );
    oCMissionManager()                                         zInit( oCMissionManager_OnInit() );
    ~oCMissionManager()                                        zCall( 0x00715000 );
    void ClearMissions()                                       zCall( 0x007150F0 );
    oCMission* GetMission( int )                               zCall( 0x00715170 );
    void CreateAllMissions()                                   zCall( 0x007151D0 );
    oCMission* OfferThisMission( oCNpc*, oCNpc*, int )         zCall( 0x007153B0 );
    oCMission* GetAvailableMission( oCNpc*, oCNpc*, int )      zCall( 0x00715680 );
    int GetStatus( oCNpc*, int )                               zCall( 0x00715950 );
    void SetStatus( oCNpc*, int, int )                         zCall( 0x00715B10 );
    int CancelMission( oCNpc*, int )                           zCall( 0x00715D40 );
    void CreateMissionInfoList( oCNpc*, zCArray<oCMission*>& ) zCall( 0x00715F10 );
    int TestNextMission()                                      zCall( 0x00716160 );
    static int SortMissions( void const*, void const* )        zCall( 0x00715140 );
    virtual void Archive( zCArchiver& )                        zCall( 0x007161A0 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x007161E0 );

    // user API
    #include "oCMissionManager.inl"
  };

  class oCMission {
  public:
    struct TMisStatus {
    public:
      unsigned long vobID;
      int status;
      float startTime;

      // user API
      #include "oCMission_TMisStatus.inl"
    };

    group {
      zSTRING name;
      zSTRING description;
      int duration;
      int important;
      int offerConditions;
      int offerFunc;
      int successConditions;
      int successFunc;
      int failureConditions;
      int failureFunc;
      int obsoleteConditions;
      int obsoleteFunc;
      int runningFunc;
    };
    int instance;
    oCNpc* npc;
    oCNpc* player;
    unsigned long curID;
    int available;
    zCArray<TMisStatus*> statusList;
    TMisStatus* status;
    int deleted;

    oCMission() {}
    void oCMission_OnInit( int )                zCall( 0x00716390 );
    oCMission( int a0 )                         zInit( oCMission_OnInit( a0 ));
    ~oCMission()                                zCall( 0x007164C0 );
    void AddEntry( zSTRING const& )             zCall( 0x007165B0 );
    void SetCurrentUser( oCNpc*, oCNpc* )       zCall( 0x007166C0 );
    void GetCurrentUser( oCNpc*&, oCNpc*& )     zCall( 0x00716800 );
    TMisStatus* GetStatusInfo()                 zCall( 0x00716820 );
    float GetStartTime()                        zCall( 0x00716930 );
    void SetStartTime( float )                  zCall( 0x00716950 );
    int CheckMission()                          zCall( 0x00716970 );
    int IsAvailable()                           zCall( 0x007169E0 );
    int OfferConditions()                       zCall( 0x007169F0 );
    void Offer()                                zCall( 0x00716BA0 );
    int SuccessConditions()                     zCall( 0x00716D50 );
    void Success()                              zCall( 0x00716F00 );
    int FailureConditions()                     zCall( 0x007170B0 );
    void Failure()                              zCall( 0x00717260 );
    int ObsoleteConditions()                    zCall( 0x00717410 );
    void Obsolete()                             zCall( 0x007175C0 );
    void Running()                              zCall( 0x00717770 );
    int GetStatus()                             zCall( 0x00717920 );
    void SetStatus( int )                       zCall( 0x00717930 );
    int OnTime()                                zCall( 0x00717A70 );
    virtual void Archive( zCArchiver& )         zCall( 0x00717AD0 );
    virtual oCMission* Unarchive( zCArchiver& ) zCall( 0x00717BB0 );

    // user API
    #include "oCMission.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMISSION_H__VER3__