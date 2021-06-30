// Supported with union (c) 2018 Union team

#ifndef __OMENU__STATUS_H__VER1__
#define __OMENU__STATUS_H__VER1__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_I_Addon {

  struct oSMenuInfoAttribute {
    enum oTMenuAttrib {
      ATTRIB_HP,
      ATTRIB_DEX,
      ATTRIB_MANA,
      ATTRIB_STR
    };

    zSTRING name;
    zSTRING descr;
    int actValue;
    int maxValue;
    oTMenuAttrib type;

    void oSMenuInfoAttribute_OnInit() zCall( 0x00482BE0 );
    ~oSMenuInfoAttribute()            zCall( 0x004825A0 );
    oSMenuInfoAttribute()             zInit( oSMenuInfoAttribute_OnInit() );

    // user API
    #include "oSMenuInfoAttribute.inl"
  };

  struct oSMenuInfoArmor {
    enum oTMenuArmor {
      ATTRIB_1H,
      ATTRIB_2H,
      ATTRIB_BOW,
      ATTRIB_CROSSBOW
    };

    int actValue;

    oSMenuInfoArmor() {}

    // user API
    #include "oSMenuInfoArmor.inl"
  };

  struct oSMenuInfoTalent {
    zSTRING name;
    zSTRING desc;
    zSTRING skillEnum;
    int value;
    int skill;

    void oSMenuInfoTalent_OnInit() zCall( 0x00482C20 );
    ~oSMenuInfoTalent()            zCall( 0x00482640 );
    oSMenuInfoTalent()             zInit( oSMenuInfoTalent_OnInit() );

    // user API
    #include "oSMenuInfoTalent.inl"
  };

  class oCMenu_Log : public zCMenu {
  public:
    zCMenuItemList* listItemAct;
    zCMenuItemList* listItemOld;
    zCMenuItemList* listItemFailed;
    zCMenuItemList* listItemLog;
    zCMenuItemText* contentViewer;

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

  class oCMenu_Status : public zCMenu {
  public:
    zCArray<oSMenuInfoAttribute> m_listAttributes;
    zCArray<oSMenuInfoTalent> m_listTalents;
    zCArray<oSMenuInfoArmor> m_listArmory;

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

  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu;

    void oCStatusScreen_OnInit() zCall( 0x00480E80 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x004813D0 );
    virtual ~oCStatusScreen()    zCall( 0x00481180 );

    // user API
    #include "oCStatusScreen.inl"
  };

  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu;

    void oCLogScreen_OnInit() zCall( 0x00481610 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x00481AD0 );
    virtual ~oCLogScreen()    zCall( 0x004818C0 );

    // user API
    #include "oCLogScreen.inl"
  };

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