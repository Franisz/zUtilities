// Supported with union (c) 2018 Union team

#ifndef __ZPLAYER_GROUP_H__VER1__
#define __ZPLAYER_GROUP_H__VER1__

namespace Gothic_I_Addon {

  class zCPlayerGroup {
  public:
    zSTRING name;
    zCListSort<zCPlayerInfo> player_list;

    zCPlayerGroup() {}
    void zCPlayerGroup_OnInit( zSTRING const& )                  zCall( 0x00468910 );
    void AddGroupToList()                                        zCall( 0x00468600 );
    void RemoveGroupFromList()                                   zCall( 0x00468780 );
    zCPlayerGroup( zSTRING const& a0 )                           zInit( zCPlayerGroup_OnInit( a0 ));
    zCPlayerInfo* GetFirstPlayer( int& )                         zCall( 0x00468C40 );
    zCPlayerInfo* GetNextPlayer( int& )                          zCall( 0x00468C80 );
    zCPlayerGroup* GetNextGroup( int& )                          zCall( 0x00468D10 );
    int AddPlayer( zCPlayerInfo* )                               zCall( 0x00468D60 );
    int RemPlayer( zCPlayerInfo* )                               zCall( 0x00468D90 );
    int IsMember( zCPlayerInfo* )                                zCall( 0x00468E00 );
    zCPlayerInfo* GetPlayerByID( unsigned char )                 zCall( 0x00468E30 );
    void ShowDebugInfo()                                         zCall( 0x00468ED0 );
    void ResetPlayerList()                                       zCall( 0x00469610 );
    zCPlayerInfo* GetNearestPlayerToVob( zCVob*, zCPlayerInfo* ) zCall( 0x00469790 );
    static zCPlayerGroup* GetFirstGroup( int& )                  zCall( 0x00468CD0 );
    static void ResetGroupList()                                 zCall( 0x00469660 );
    virtual ~zCPlayerGroup()                                     zCall( 0x00468AD0 );

    // static properties
    static zCPlayerGroup& allPlayerGroup;
    static zCList<zCPlayerGroup>& group_list;

    // user API
    #include "zCPlayerGroup.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPLAYER_GROUP_H__VER1__