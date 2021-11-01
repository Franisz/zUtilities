// Supported with union (c) 2018-2021 Union team

#ifndef __OMENU__STATUS_H__VER1__
#define __OMENU__STATUS_H__VER1__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_I_Addon {

  // sizeof 34h
  struct oSMenuInfoAttribute {
    enum oTMenuAttrib {
      ATTRIB_HP,
      ATTRIB_DEX,
      ATTRIB_MANA,
      ATTRIB_STR
    };

    zSTRING name;      // sizeof 14h    offset 00h
    zSTRING descr;     // sizeof 14h    offset 14h
    int actValue;      // sizeof 04h    offset 28h
    int maxValue;      // sizeof 04h    offset 2Ch
    oTMenuAttrib type; // sizeof 04h    offset 30h

    void oSMenuInfoAttribute_OnInit() zCall( 0x00482BE0 );
    ~oSMenuInfoAttribute()            zCall( 0x004825A0 );
    oSMenuInfoAttribute()             zInit( oSMenuInfoAttribute_OnInit() );

    // user API
    #include "oSMenuInfoAttribute.inl"
  };

  // sizeof 04h
  struct oSMenuInfoArmor {
    enum oTMenuArmor {
      ATTRIB_1H,
      ATTRIB_2H,
      ATTRIB_BOW,
      ATTRIB_CROSSBOW
    };

    int actValue; // sizeof 04h    offset 00h

    oSMenuInfoArmor() {}

    // user API
    #include "oSMenuInfoArmor.inl"
  };

  // sizeof 44h
  struct oSMenuInfoTalent {
    zSTRING name;      // sizeof 14h    offset 00h
    zSTRING desc;      // sizeof 14h    offset 14h
    zSTRING skillEnum; // sizeof 14h    offset 28h
    int value;         // sizeof 04h    offset 3Ch
    int skill;         // sizeof 04h    offset 40h

    void oSMenuInfoTalent_OnInit() zCall( 0x00482C20 );
    ~oSMenuInfoTalent()            zCall( 0x00482640 );
    oSMenuInfoTalent()             zInit( oSMenuInfoTalent_OnInit() );

    // user API
    #include "oSMenuInfoTalent.inl"
  };

  // sizeof CD8h
  class oCMenu_Log : public zCMenu {
  public:
    zCMenuItemList* listItemAct;    // sizeof 04h    offset CC4h
    zCMenuItemList* listItemOld;    // sizeof 04h    offset CC8h
    zCMenuItemList* listItemFailed; // sizeof 04h    offset CCCh
    zCMenuItemList* listItemLog;    // sizeof 04h    offset CD0h
    zCMenuItemText* contentViewer;  // sizeof 04h    offset CD4h

    oCMenu_Log() {}
    void oCMenu_Log_OnInit( zSTRING const& )          zCall( 0x0047DF70 );
    oCMenu_Log( zSTRING const& a0 )                   zInit( oCMenu_Log_OnInit( a0 ));
    void SetDayTime( zSTRING const&, zSTRING const& ) zCall( 0x0047E560 );
    void SetLogTopics( zCList<oCLogTopic> const& )    zCall( 0x0047E600 );
    void SetInfo( zCMenuItem const* )                 zCall( 0x0047ED60 );
    void InitForDisplay()                             zCall( 0x0047F510 );
    virtual int HandleEvent( int )                    zCall( 0x0047F4B0 );
    virtual int HandleEnterItem( zCMenuItem* )        zCall( 0x0047EFF0 );
    virtual int HandleLeaveItem( zCMenuItem* )        zCall( 0x0047F240 );
    virtual int HandleActivateItem( zCMenuItem* )     zCall( 0x0047F4A0 );
    virtual void Activate()                           zCall( 0x0047F500 );
    virtual ~oCMenu_Log()                             zCall( 0x0047DFB0 );
    virtual void ScreenInit()                         zCall( 0x0047DFC0 );
    virtual void ScreenDone()                         zCall( 0x0047E440 );
    virtual int ExecCommand( zSTRING const& )         zCall( 0x0047ED70 );

    // user API
    #include "oCMenu_Log.inl"
  };

  // sizeof CE8h
  class oCMenu_Status : public zCMenu {
  public:
    zCArray<oSMenuInfoAttribute> m_listAttributes; // sizeof 0Ch    offset CC4h
    zCArray<oSMenuInfoTalent> m_listTalents;       // sizeof 0Ch    offset CD0h
    zCArray<oSMenuInfoArmor> m_listArmory;         // sizeof 0Ch    offset CDCh

    oCMenu_Status() {}
    void oCMenu_Status_OnInit( zSTRING const& )                       zCall( 0x0047FD10 );
    void SetPlayerName( zSTRING const& )                              zCall( 0x0047F750 );
    void SetGuild( zSTRING const& )                                   zCall( 0x0047F7A0 );
    void SetExperience( unsigned long, unsigned long, unsigned long ) zCall( 0x0047F890 );
    void SetLearnPoints( unsigned long )                              zCall( 0x0047FC30 );
    oCMenu_Status( zSTRING const& a0 )                                zInit( oCMenu_Status_OnInit( a0 ));
    void AddArmor( oSMenuInfoArmor const& )                           zCall( 0x0047FE60 );
    void AddAttribute( oSMenuInfoAttribute const& )                   zCall( 0x0047FF90 );
    void AddTalent( oSMenuInfoTalent const& )                         zCall( 0x00480170 );
    void InitForDisplay()                                             zCall( 0x00480370 );
    virtual int HandleEvent( int )                                    zCall( 0x0047F550 );
    virtual ~oCMenu_Status()                                          zCall( 0x0047FD90 );

    // user API
    #include "oCMenu_Status.inl"
  };

  // sizeof 08h
  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu; // sizeof 04h    offset 04h

    void oCStatusScreen_OnInit() zCall( 0x00480E80 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x004813D0 );
    virtual ~oCStatusScreen()    zCall( 0x00481180 );

    // user API
    #include "oCStatusScreen.inl"
  };

  // sizeof 08h
  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu; // sizeof 04h    offset 04h

    void oCLogScreen_OnInit() zCall( 0x00481610 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x00481AD0 );
    virtual ~oCLogScreen()    zCall( 0x004818C0 );

    // user API
    #include "oCLogScreen.inl"
  };

  // sizeof 04h
  class oCMapScreen {
  public:

    void oCMapScreen_OnInit() zCall( 0x00481D00 );
    oCMapScreen()             zInit( oCMapScreen_OnInit() );
    void Show()               zCall( 0x00482100 );
    virtual ~oCMapScreen()    zCall( 0x00481F10 );

    // user API
    #include "oCMapScreen.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMENU__STATUS_H__VER1__