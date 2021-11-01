// Supported with union (c) 2018-2021 Union team

#ifndef __ZPLAYER_GROUP_H__VER3__
#define __ZPLAYER_GROUP_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 24h
  class zCPlayerGroup {
  public:
    zSTRING name;                         // sizeof 14h    offset 04h
    zCListSort<zCPlayerInfo> player_list; // sizeof 0Ch    offset 18h

    zCPlayerGroup() {}
    void zCPlayerGroup_OnInit( zSTRING const& )                  zCall( 0x004665E0 );
    void AddGroupToList()                                        zCall( 0x00466300 );
    void RemoveGroupFromList()                                   zCall( 0x00466460 );
    zCPlayerGroup( zSTRING const& a0 )                           zInit( zCPlayerGroup_OnInit( a0 ));
    zCPlayerInfo* GetFirstPlayer( int& )                         zCall( 0x004668C0 );
    zCPlayerInfo* GetNextPlayer( int& )                          zCall( 0x00466910 );
    zCPlayerGroup* GetNextGroup( int& )                          zCall( 0x004669A0 );
    int AddPlayer( zCPlayerInfo* )                               zCall( 0x004669F0 );
    int RemPlayer( zCPlayerInfo* )                               zCall( 0x00466A20 );
    int IsMember( zCPlayerInfo* )                                zCall( 0x00466AA0 );
    zCPlayerInfo* GetPlayerByID( unsigned char )                 zCall( 0x00466AD0 );
    void ShowDebugInfo()                                         zCall( 0x00466B80 );
    void ResetPlayerList()                                       zCall( 0x00467260 );
    zCPlayerInfo* GetNearestPlayerToVob( zCVob*, zCPlayerInfo* ) zCall( 0x00467400 );
    static zCPlayerGroup* GetFirstGroup( int& )                  zCall( 0x00466960 );
    static void ResetGroupList()                                 zCall( 0x004672C0 );
    virtual ~zCPlayerGroup()                                     zCall( 0x00466760 );

    // static properties
    static zCPlayerGroup& allPlayerGroup;
    static zCList<zCPlayerGroup>& group_list;

    // user API
    #include "zCPlayerGroup.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPLAYER_GROUP_H__VER3__