// Supported with union (c) 2018 Union team

#ifndef __ZPLAYER_GROUP_H__VER2__
#define __ZPLAYER_GROUP_H__VER2__

namespace Gothic_II_Classic {

  class zCPlayerGroup {
  public:
    zSTRING name;
    zCListSort<zCPlayerInfo> player_list;

    zCPlayerGroup() {}
    void zCPlayerGroup_OnInit( zSTRING const& )                  zCall( 0x004659B0 );
    void AddGroupToList()                                        zCall( 0x004656D0 );
    void RemoveGroupFromList()                                   zCall( 0x00465830 );
    zCPlayerGroup( zSTRING const& a0 )                           zInit( zCPlayerGroup_OnInit( a0 ));
    zCPlayerInfo* GetFirstPlayer( int& )                         zCall( 0x00465C90 );
    zCPlayerInfo* GetNextPlayer( int& )                          zCall( 0x00465CE0 );
    zCPlayerGroup* GetNextGroup( int& )                          zCall( 0x00465D70 );
    int AddPlayer( zCPlayerInfo* )                               zCall( 0x00465DC0 );
    int RemPlayer( zCPlayerInfo* )                               zCall( 0x00465DF0 );
    int IsMember( zCPlayerInfo* )                                zCall( 0x00465E70 );
    zCPlayerInfo* GetPlayerByID( unsigned char )                 zCall( 0x00465EA0 );
    void ShowDebugInfo()                                         zCall( 0x00465F50 );
    void ResetPlayerList()                                       zCall( 0x00466630 );
    zCPlayerInfo* GetNearestPlayerToVob( zCVob*, zCPlayerInfo* ) zCall( 0x004667D0 );
    static zCPlayerGroup* GetFirstGroup( int& )                  zCall( 0x00465D30 );
    static void ResetGroupList()                                 zCall( 0x00466690 );
    virtual ~zCPlayerGroup()                                     zCall( 0x00465B30 );

    // static properties
    static zCPlayerGroup& allPlayerGroup;
    static zCList<zCPlayerGroup>& group_list;

    // user API
    #include "zCPlayerGroup.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPLAYER_GROUP_H__VER2__