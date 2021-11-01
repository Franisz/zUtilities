// Supported with union (c) 2018-2021 Union team

#ifndef __OMISSION_H__VER1__
#define __OMISSION_H__VER1__

#include "zVob.h"
#include "oMenu_Status.h"

namespace Gothic_I_Addon {
  const int MIS_NOMISSION   = -1;
  const int MIS_NOTINVOLVED = 0;
  const int MIS_OFFERED     = 1;
  const int MIS_REFUSED     = 2;
  const int MIS_RUNNING     = 3;
  const int MIS_DONE        = 4;
  const int MIS_DONELATE    = 5;
  const int MIS_CANCELED    = 6;
  const int MIS_FAILED      = 7;

  // sizeof 14h
  class oCMissionManager {
  public:
    zCArraySort<oCMission*> missionList; // sizeof 10h    offset 04h

    void oCMissionManager_OnInit()                             zCall( 0x006A1E40 );
    oCMissionManager()                                         zInit( oCMissionManager_OnInit() );
    ~oCMissionManager()                                        zCall( 0x006A1E70 );
    void ClearMissions()                                       zCall( 0x006A1F60 );
    oCMission* GetMission( int )                               zCall( 0x006A1FD0 );
    void CreateAllMissions()                                   zCall( 0x006A2030 );
    oCMission* OfferThisMission( oCNpc*, oCNpc*, int )         zCall( 0x006A2260 );
    oCMission* GetAvailableMission( oCNpc*, oCNpc*, int )      zCall( 0x006A2550 );
    int GetStatus( oCNpc*, int )                               zCall( 0x006A2840 );
    void SetStatus( oCNpc*, int, int )                         zCall( 0x006A2A60 );
    int CancelMission( oCNpc*, int )                           zCall( 0x006A2CA0 );
    void CreateMissionInfoList( oCNpc*, zCArray<oCMission*>& ) zCall( 0x006A2ED0 );
    int TestNextMission()                                      zCall( 0x006A3110 );
    static int SortMissions( void const*, void const* )        zCall( 0x006A1FB0 );
    virtual void Archive( zCArchiver& )                        zCall( 0x006A3150 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x006A3190 );

    // user API
    #include "oCMissionManager.inl"
  };

  // sizeof 80h
  class oCMission {
  public:
    // sizeof 0Ch
    struct TMisStatus {
    public:
      unsigned long vobID; // sizeof 04h    offset 00h
      int status;          // sizeof 04h    offset 04h
      float startTime;     // sizeof 04h    offset 08h

      // user API
      #include "oCMission_TMisStatus.inl"
    };

    group {
      zSTRING name;                  // sizeof 14h    offset 04h
      zSTRING description;           // sizeof 14h    offset 18h
      int duration;                  // sizeof 04h    offset 2Ch
      int important;                 // sizeof 04h    offset 30h
      int offerConditions;           // sizeof 04h    offset 34h
      int offerFunc;                 // sizeof 04h    offset 38h
      int successConditions;         // sizeof 04h    offset 3Ch
      int successFunc;               // sizeof 04h    offset 40h
      int failureConditions;         // sizeof 04h    offset 44h
      int failureFunc;               // sizeof 04h    offset 48h
      int obsoleteConditions;        // sizeof 04h    offset 4Ch
      int obsoleteFunc;              // sizeof 04h    offset 50h
      int runningFunc;               // sizeof 04h    offset 54h
    };
    int instance;                    // sizeof 04h    offset 58h
    oCNpc* npc;                      // sizeof 04h    offset 5Ch
    oCNpc* player;                   // sizeof 04h    offset 60h
    unsigned long curID;             // sizeof 04h    offset 64h
    int available;                   // sizeof 04h    offset 68h
    zCArray<TMisStatus*> statusList; // sizeof 0Ch    offset 6Ch
    TMisStatus* status;              // sizeof 04h    offset 78h
    int deleted;                     // sizeof 04h    offset 7Ch

    oCMission() {}
    void oCMission_OnInit( int )                zCall( 0x006A3370 );
    oCMission( int a0 )                         zInit( oCMission_OnInit( a0 ));
    ~oCMission()                                zCall( 0x006A34C0 );
    void AddEntry( zSTRING const& )             zCall( 0x006A35C0 );
    void SetCurrentUser( oCNpc*, oCNpc* )       zCall( 0x006A36D0 );
    void GetCurrentUser( oCNpc*&, oCNpc*& )     zCall( 0x006A3830 );
    TMisStatus* GetStatusInfo()                 zCall( 0x006A3850 );
    float GetStartTime()                        zCall( 0x006A3990 );
    void SetStartTime( float )                  zCall( 0x006A39B0 );
    int CheckMission()                          zCall( 0x006A39D0 );
    int IsAvailable()                           zCall( 0x006A3A40 );
    int OfferConditions()                       zCall( 0x006A3A50 );
    void Offer()                                zCall( 0x006A3C20 );
    int SuccessConditions()                     zCall( 0x006A3DF0 );
    void Success()                              zCall( 0x006A3FC0 );
    int FailureConditions()                     zCall( 0x006A4190 );
    void Failure()                              zCall( 0x006A4360 );
    int ObsoleteConditions()                    zCall( 0x006A4530 );
    void Obsolete()                             zCall( 0x006A4700 );
    void Running()                              zCall( 0x006A48D0 );
    int GetStatus()                             zCall( 0x006A4AA0 );
    void SetStatus( int )                       zCall( 0x006A4AB0 );
    int OnTime()                                zCall( 0x006A4C10 );
    virtual void Archive( zCArchiver& )         zCall( 0x006A4C70 );
    virtual oCMission* Unarchive( zCArchiver& ) zCall( 0x006A4D50 );

    // user API
    #include "oCMission.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMISSION_H__VER1__