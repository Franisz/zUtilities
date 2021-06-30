// Supported with union (c) 2018 Union team

#ifndef __OMISSION_H__VER2__
#define __OMISSION_H__VER2__

#include "zVob.h"
#include "oMenu_Status.h"

namespace Gothic_II_Classic {
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

    void oCMissionManager_OnInit()                             zCall( 0x006B6F40 );
    oCMissionManager()                                         zInit( oCMissionManager_OnInit() );
    ~oCMissionManager()                                        zCall( 0x006B6F70 );
    void ClearMissions()                                       zCall( 0x006B7060 );
    oCMission* GetMission( int )                               zCall( 0x006B70E0 );
    void CreateAllMissions()                                   zCall( 0x006B7140 );
    oCMission* OfferThisMission( oCNpc*, oCNpc*, int )         zCall( 0x006B7320 );
    oCMission* GetAvailableMission( oCNpc*, oCNpc*, int )      zCall( 0x006B75F0 );
    int GetStatus( oCNpc*, int )                               zCall( 0x006B78C0 );
    void SetStatus( oCNpc*, int, int )                         zCall( 0x006B7A80 );
    int CancelMission( oCNpc*, int )                           zCall( 0x006B7CB0 );
    void CreateMissionInfoList( oCNpc*, zCArray<oCMission*>& ) zCall( 0x006B7E80 );
    int TestNextMission()                                      zCall( 0x006B80D0 );
    static int SortMissions( void const*, void const* )        zCall( 0x006B70B0 );
    virtual void Archive( zCArchiver& )                        zCall( 0x006B8110 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x006B8150 );

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
    void oCMission_OnInit( int )                zCall( 0x006B8300 );
    oCMission( int a0 )                         zInit( oCMission_OnInit( a0 ));
    ~oCMission()                                zCall( 0x006B8430 );
    void AddEntry( zSTRING const& )             zCall( 0x006B8520 );
    void SetCurrentUser( oCNpc*, oCNpc* )       zCall( 0x006B8630 );
    void GetCurrentUser( oCNpc*&, oCNpc*& )     zCall( 0x006B8770 );
    TMisStatus* GetStatusInfo()                 zCall( 0x006B8790 );
    float GetStartTime()                        zCall( 0x006B88A0 );
    void SetStartTime( float )                  zCall( 0x006B88C0 );
    int CheckMission()                          zCall( 0x006B88E0 );
    int IsAvailable()                           zCall( 0x006B8950 );
    int OfferConditions()                       zCall( 0x006B8960 );
    void Offer()                                zCall( 0x006B8B10 );
    int SuccessConditions()                     zCall( 0x006B8CC0 );
    void Success()                              zCall( 0x006B8E70 );
    int FailureConditions()                     zCall( 0x006B9020 );
    void Failure()                              zCall( 0x006B91D0 );
    int ObsoleteConditions()                    zCall( 0x006B9380 );
    void Obsolete()                             zCall( 0x006B9530 );
    void Running()                              zCall( 0x006B96E0 );
    int GetStatus()                             zCall( 0x006B9890 );
    void SetStatus( int )                       zCall( 0x006B98A0 );
    int OnTime()                                zCall( 0x006B99E0 );
    virtual void Archive( zCArchiver& )         zCall( 0x006B9A40 );
    virtual oCMission* Unarchive( zCArchiver& ) zCall( 0x006B9B20 );

    // user API
    #include "oCMission.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMISSION_H__VER2__