// Supported with union (c) 2018-2021 Union team

#ifndef __OITEM_REACT_H__VER1__
#define __OITEM_REACT_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 14h
  class oCTradeManager {
  public:
    zCParser* p;                         // sizeof 04h    offset 00h
    zList<oCItemReactModule> moduleList; // sizeof 10h    offset 04h

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x006A1590 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x006A17C0 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x006A1810 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCTradeManager.inl"
  };

  // sizeof 20h
  class oCItemReactModule {
  public:
    // sizeof 1Ch
    struct oCItemReactModuleDummy0 {
      int trade_npc;      // sizeof 04h    offset 00h
      int trade_instance; // sizeof 04h    offset 04h
      int trade_amount;   // sizeof 04h    offset 08h
      int other_category; // sizeof 04h    offset 0Ch
      int other_instance; // sizeof 04h    offset 10h
      int other_amount;   // sizeof 04h    offset 14h
      int reaction;       // sizeof 04h    offset 18h
    };

    oCItemReactModule* next;    // sizeof 04h    offset 00h
    oCItemReactModuleDummy0 pd; // sizeof 1Ch    offset 04h

    oCItemReactModule() {}
    void oCItemReactModule_OnInit( int )  zCall( 0x006A19F0 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x006A1A30 );
    void Validate()                       zCall( 0x006A1A40 );
    int Conditions( int, int )            zCall( 0x006A1A50 );
    void GetOfferedInstance( int&, int& ) zCall( 0x006A1A80 );
    int StartReaction( int )              zCall( 0x006A1AA0 );
    int GetDataSize()                     zCall( 0x006A1AC0 );
    int GetNpcInstance()                  zCall( 0x006A1AD0 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OITEM_REACT_H__VER1__