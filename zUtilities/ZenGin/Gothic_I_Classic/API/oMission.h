// Supported with union (c) 2018 Union team

#ifndef __OMISSION_H__VER0__
#define __OMISSION_H__VER0__

#include "zVob.h"
#include "oMenu_Status.h"

namespace Gothic_I_Classic {
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

    void oCMissionManager_OnInit()                             zCall( 0x00673DD0 );
    oCMissionManager()                                         zInit( oCMissionManager_OnInit() );
    ~oCMissionManager()                                        zCall( 0x00673E00 );
    void ClearMissions()                                       zCall( 0x00673F00 );
    oCMission* GetMission( int )                               zCall( 0x00673F80 );
    void CreateAllMissions()                                   zCall( 0x00673FE0 );
    oCMission* OfferThisMission( oCNpc*, oCNpc*, int )         zCall( 0x006741D0 );
    oCMission* GetAvailableMission( oCNpc*, oCNpc*, int )      zCall( 0x006744B0 );
    int GetStatus( oCNpc*, int )                               zCall( 0x00674790 );
    void SetStatus( oCNpc*, int, int )                         zCall( 0x006749B0 );
    int CancelMission( oCNpc*, int )                           zCall( 0x00674BF0 );
    void CreateMissionInfoList( oCNpc*, zCArray<oCMission*>& ) zCall( 0x00674E30 );
    int TestNextMission()                                      zCall( 0x00675080 );
    static int SortMissions( void const*, void const* )        zCall( 0x00673F50 );
    virtual void Archive( zCArchiver& )                        zCall( 0x006750C0 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x00675100 );

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
    void oCMission_OnInit( int )                zCall( 0x006752E0 );
    oCMission( int a0 )                         zInit( oCMission_OnInit( a0 ));
    ~oCMission()                                zCall( 0x00675420 );
    void AddEntry( zSTRING const& )             zCall( 0x00675510 );
    void SetCurrentUser( oCNpc*, oCNpc* )       zCall( 0x00675620 );
    void GetCurrentUser( oCNpc*&, oCNpc*& )     zCall( 0x00675790 );
    TMisStatus* GetStatusInfo()                 zCall( 0x006757B0 );
    float GetStartTime()                        zCall( 0x006758F0 );
    void SetStartTime( float )                  zCall( 0x00675910 );
    int CheckMission()                          zCall( 0x00675930 );
    int IsAvailable()                           zCall( 0x006759A0 );
    int OfferConditions()                       zCall( 0x006759B0 );
    void Offer()                                zCall( 0x00675B60 );
    int SuccessConditions()                     zCall( 0x00675D10 );
    void Success()                              zCall( 0x00675EC0 );
    int FailureConditions()                     zCall( 0x00676070 );
    void Failure()                              zCall( 0x00676220 );
    int ObsoleteConditions()                    zCall( 0x006763D0 );
    void Obsolete()                             zCall( 0x00676580 );
    void Running()                              zCall( 0x00676730 );
    int GetStatus()                             zCall( 0x006768E0 );
    void SetStatus( int )                       zCall( 0x006768F0 );
    int OnTime()                                zCall( 0x00676A30 );
    virtual void Archive( zCArchiver& )         zCall( 0x00676A90 );
    virtual oCMission* Unarchive( zCArchiver& ) zCall( 0x00676B70 );

    // user API
    #include "oCMission.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMISSION_H__VER0__