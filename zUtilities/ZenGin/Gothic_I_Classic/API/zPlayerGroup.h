// Supported with union (c) 2018 Union team

#ifndef __ZPLAYER_GROUP_H__VER0__
#define __ZPLAYER_GROUP_H__VER0__

namespace Gothic_I_Classic {

  class zCPlayerGroup {
  public:
    zSTRING name;
    zCListSort<zCPlayerInfo> player_list;

    zCPlayerGroup() {}
    void zCPlayerGroup_OnInit( zSTRING const& )                  zCall( 0x00460FB0 );
    void AddGroupToList()                                        zCall( 0x00460CC0 );
    void RemoveGroupFromList()                                   zCall( 0x00460E30 );
    zCPlayerGroup( zSTRING const& a0 )                           zInit( zCPlayerGroup_OnInit( a0 ));
    zCPlayerInfo* GetFirstPlayer( int& )                         zCall( 0x004612B0 );
    zCPlayerInfo* GetNextPlayer( int& )                          zCall( 0x00461300 );
    zCPlayerGroup* GetNextGroup( int& )                          zCall( 0x00461390 );
    int AddPlayer( zCPlayerInfo* )                               zCall( 0x004613E0 );
    int RemPlayer( zCPlayerInfo* )                               zCall( 0x00461410 );
    int IsMember( zCPlayerInfo* )                                zCall( 0x00461490 );
    zCPlayerInfo* GetPlayerByID( unsigned char )                 zCall( 0x004614C0 );
    void ShowDebugInfo()                                         zCall( 0x00461570 );
    void ResetPlayerList()                                       zCall( 0x00461BF0 );
    zCPlayerInfo* GetNearestPlayerToVob( zCVob*, zCPlayerInfo* ) zCall( 0x00461D90 );
    static zCPlayerGroup* GetFirstGroup( int& )                  zCall( 0x00461350 );
    static void ResetGroupList()                                 zCall( 0x00461C50 );
    virtual ~zCPlayerGroup()                                     zCall( 0x00461150 );

    // static properties
    static zCPlayerGroup& allPlayerGroup;
    static zCList<zCPlayerGroup>& group_list;

    // user API
    #include "zCPlayerGroup.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPLAYER_GROUP_H__VER0__