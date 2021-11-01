// Supported with union (c) 2018-2021 Union team

#ifndef __OPORTALS_H__VER0__
#define __OPORTALS_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 2Ch
  class oCPortalRoom {
  public:
    zSTRING portalName; // sizeof 14h    offset 00h
    zSTRING ownerNpc;   // sizeof 14h    offset 14h
    int ownerGuild;     // sizeof 04h    offset 28h

    void oCPortalRoom_OnInit()                 zCall( 0x006CA580 );
    void oCPortalRoom_OnInit( zSTRING const& ) zCall( 0x006CA700 );
    oCPortalRoom()                             zInit( oCPortalRoom_OnInit() );
    oCPortalRoom( zSTRING const& a0 )          zInit( oCPortalRoom_OnInit( a0 ));
    ~oCPortalRoom()                            zCall( 0x006CA8D0 );
    oCNpc* GetOwnerNpc()                       zCall( 0x006CA950 );
    int GetOwnerGuild()                        zCall( 0x006CA9A0 );
    zSTRING& GetPortalName()                   zCall( 0x006CA9B0 );
    int IsPortalMyRoom( oCNpc* )               zCall( 0x006CA9C0 );
    void SavePortalData( zCArchiver& )         zCall( 0x006CAB60 );
    void LoadPortalData( zCArchiver& )         zCall( 0x006CABA0 );

    // user API
    #include "oCPortalRoom.inl"
  };

  // sizeof 20h
  class oCPortalRoomManager {
  public:
    zSTRING* oldPlayerPortal;           // sizeof 04h    offset 00h
    zSTRING* curPlayerPortal;           // sizeof 04h    offset 04h
    oCPortalRoom* oldPlayerRoom;        // sizeof 04h    offset 08h
    oCPortalRoom* curPlayerRoom;        // sizeof 04h    offset 0Ch
    zCArraySort<oCPortalRoom*> portals; // sizeof 10h    offset 10h

    void oCPortalRoomManager_OnInit()                        zCall( 0x006CAC50 );
    oCPortalRoomManager()                                    zInit( oCPortalRoomManager_OnInit() );
    void CleanUp()                                           zCall( 0x006CAC80 );
    ~oCPortalRoomManager()                                   zCall( 0x006CACD0 );
    void AssignPortalToNpc( zSTRING const&, zSTRING const& ) zCall( 0x006CAD70 );
    void AssignPortalToGuild( zSTRING const&, int )          zCall( 0x006CAFB0 );
    int GetPortalRoomIndex( zSTRING const& )                 zCall( 0x006CB1E0 );
    int IsPlayerInMyRoom( oCNpc* )                           zCall( 0x006CB380 );
    int WasPlayerInMyRoom( oCNpc* )                          zCall( 0x006CB3C0 );
    int IsPortalMyRoom( zSTRING const&, oCNpc* )             zCall( 0x006CB3F0 );
    oCNpc* GetCurPlayerPortalRoomOwner()                     zCall( 0x006CB550 );
    int GetCurPlayerPortalRoomGuild()                        zCall( 0x006CB5B0 );
    oCNpc* GetFormerPlayerPortalRoomOwner()                  zCall( 0x006CB5C0 );
    int GetFormerPlayerPortalRoomGuild()                     zCall( 0x006CB620 );
    int HasPlayerChangedPortalRoom()                         zCall( 0x006CB630 );
    void ShowDebugInfo()                                     zCall( 0x006CB680 );
    void ShowPortalInfo()                                    zCall( 0x006CBC30 );
    void SavePortalData( zCArchiver& )                       zCall( 0x006CBFC0 );
    void LoadPortalData( zCArchiver& )                       zCall( 0x006CC030 );
    static int SortPortals( void const*, void const* )       zCall( 0x006CABE0 );

    // user API
    #include "oCPortalRoomManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OPORTALS_H__VER0__