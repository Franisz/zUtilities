// Supported with union (c) 2018 Union team

#ifndef __OPORTALS_H__VER3__
#define __OPORTALS_H__VER3__

namespace Gothic_II_Addon {

  class oCPortalRoom {
  public:
    zSTRING portalName;
    zSTRING ownerNpc;
    int ownerGuild;

    void oCPortalRoom_OnInit()                 zCall( 0x00771F00 );
    void oCPortalRoom_OnInit( zSTRING const& ) zCall( 0x00772080 );
    oCPortalRoom()                             zInit( oCPortalRoom_OnInit() );
    oCPortalRoom( zSTRING const& a0 )          zInit( oCPortalRoom_OnInit( a0 ));
    ~oCPortalRoom()                            zCall( 0x00772250 );
    oCNpc* GetOwnerNpc()                       zCall( 0x007722D0 );
    int GetOwnerGuild()                        zCall( 0x00772320 );
    zSTRING& GetPortalName()                   zCall( 0x00772330 );
    int IsPortalMyRoom( oCNpc* )               zCall( 0x00772340 );
    void SavePortalData( zCArchiver& )         zCall( 0x007725A0 );
    void LoadPortalData( zCArchiver& )         zCall( 0x007725E0 );

    // user API
    #include "oCPortalRoom.inl"
  };

  class oCPortalRoomManager {
  public:
    zSTRING* oldPlayerPortal;
    zSTRING* curPlayerPortal;
    oCPortalRoom* oldPlayerRoom;
    oCPortalRoom* curPlayerRoom;
    zCArraySort<oCPortalRoom*> portals;

    void oCPortalRoomManager_OnInit()                        zCall( 0x00772690 );
    oCPortalRoomManager()                                    zInit( oCPortalRoomManager_OnInit() );
    void CleanUp()                                           zCall( 0x007726C0 );
    ~oCPortalRoomManager()                                   zCall( 0x00772710 );
    void AssignPortalToNpc( zSTRING const&, zSTRING const& ) zCall( 0x007727B0 );
    void AssignPortalToGuild( zSTRING const&, int )          zCall( 0x007729E0 );
    int GetPortalRoomIndex( zSTRING const& )                 zCall( 0x00772BE0 );
    int IsPlayerInMyRoom( oCNpc* )                           zCall( 0x00772D80 );
    int IsNSCInPlayerRoom( oCNpc* )                          zCall( 0x00772DC0 );
    int WasPlayerInMyRoom( oCNpc* )                          zCall( 0x00772E00 );
    int IsPortalMyRoom( zSTRING const&, oCNpc* )             zCall( 0x00772E30 );
    oCNpc* GetCurPlayerPortalRoomOwner()                     zCall( 0x00772F90 );
    int GetCurPlayerPortalRoomGuild()                        zCall( 0x00772FF0 );
    oCNpc* GetFormerPlayerPortalRoomOwner()                  zCall( 0x00773000 );
    int GetFormerPlayerPortalRoomGuild()                     zCall( 0x00773060 );
    int HasPlayerChangedPortalRoom()                         zCall( 0x00773070 );
    oCNpc* GetCurNpcPortalRoomOwner( oCNpc* )                zCall( 0x007730C0 );
    int GetCurNpcPortalRoomGuild( oCNpc* )                   zCall( 0x00773160 );
    void ShowDebugInfo()                                     zCall( 0x007731A0 );
    void ShowPortalInfo()                                    zCall( 0x007737E0 );
    void SavePortalData( zCArchiver& )                       zCall( 0x00773B70 );
    void LoadPortalData( zCArchiver& )                       zCall( 0x00773BE0 );
    static int SortPortals( void const*, void const* )       zCall( 0x00772620 );

    // user API
    #include "oCPortalRoomManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OPORTALS_H__VER3__