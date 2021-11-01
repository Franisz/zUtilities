// Supported with union (c) 2018-2021 Union team

#ifndef __OITEM_REACT_H__VER0__
#define __OITEM_REACT_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 14h
  class oCTradeManager {
  public:
    zCParser* p;                         // sizeof 04h    offset 00h
    zList<oCItemReactModule> moduleList; // sizeof 10h    offset 04h

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x00673810 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x00673A10 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x00673A60 );

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
    void oCItemReactModule_OnInit( int )  zCall( 0x00673C20 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x00673C60 );
    void Validate()                       zCall( 0x00673C70 );
    int Conditions( int, int )            zCall( 0x00673C80 );
    void GetOfferedInstance( int&, int& ) zCall( 0x00673CB0 );
    int StartReaction( int )              zCall( 0x00673CD0 );
    int GetDataSize()                     zCall( 0x00673CF0 );
    int GetNpcInstance()                  zCall( 0x00673D00 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OITEM_REACT_H__VER0__