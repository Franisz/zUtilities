// Supported with union (c) 2018 Union team

#ifndef __OMENU__STATUS_H__VER3__
#define __OMENU__STATUS_H__VER3__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_II_Addon {

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

    void oSMenuInfoAttribute_OnInit() zCall( 0x004803B0 );
    ~oSMenuInfoAttribute()            zCall( 0x0047FE10 );
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

    void oSMenuInfoTalent_OnInit() zCall( 0x004803F0 );
    ~oSMenuInfoTalent()            zCall( 0x0047FE90 );
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
    void oCMenu_Log_OnInit( zSTRING const& )          zCall( 0x0047B960 );
    oCMenu_Log( zSTRING const& a0 )                   zInit( oCMenu_Log_OnInit( a0 ));
    void SetDayTime( zSTRING const&, zSTRING const& ) zCall( 0x0047BEF0 );
    void SetLogTopics( zCList<oCLogTopic> const& )    zCall( 0x0047BF90 );
    void SetInfo( zCMenuItem const* )                 zCall( 0x0047C680 );
    void InitForDisplay()                             zCall( 0x0047CDC0 );
    virtual int HandleEvent( int )                    zCall( 0x0047CD60 );
    virtual int HandleEnterItem( zCMenuItem* )        zCall( 0x0047C8E0 );
    virtual int HandleLeaveItem( zCMenuItem* )        zCall( 0x0047CB10 );
    virtual int HandleActivateItem( zCMenuItem* )     zCall( 0x0047CD50 );
    virtual void Activate()                           zCall( 0x0047CDB0 );
    virtual ~oCMenu_Log()                             zCall( 0x0047B9A0 );
    virtual void ScreenInit()                         zCall( 0x0047B9B0 );
    virtual void ScreenDone()                         zCall( 0x0047BDE0 );
    virtual int ExecCommand( zSTRING const& )         zCall( 0x0047C690 );

    // user API
    #include "oCMenu_Log.inl"
  };

  class oCMenu_Status : public zCMenu {
  public:
    zCArray<oSMenuInfoAttribute> m_listAttributes;
    zCArray<oSMenuInfoTalent> m_listTalents;
    zCArray<oSMenuInfoArmor> m_listArmory;

    oCMenu_Status() {}
    void oCMenu_Status_OnInit( zSTRING const& )                       zCall( 0x0047D790 );
    void SetPlayerName( zSTRING const& )                              zCall( 0x0047CFF0 );
    void SetGuild( zSTRING const& )                                   zCall( 0x0047D040 );
    void SetMagicalGuild( zSTRING const& )                            zCall( 0x0047D130 );
    void SetExperience( unsigned long, unsigned long, unsigned long ) zCall( 0x0047D220 );
    void SetLearnPoints( unsigned long )                              zCall( 0x0047D650 );
    oCMenu_Status( zSTRING const& a0 )                                zInit( oCMenu_Status_OnInit( a0 ));
    void AddArmor( oSMenuInfoArmor const& )                           zCall( 0x0047D8E0 );
    void AddAttribute( oSMenuInfoAttribute const& )                   zCall( 0x0047D9F0 );
    void AddTalent( oSMenuInfoTalent const& )                         zCall( 0x0047DBD0 );
    void InitForDisplay()                                             zCall( 0x0047DDC0 );
    virtual int HandleEvent( int )                                    zCall( 0x0047CE00 );
    virtual ~oCMenu_Status()                                          zCall( 0x0047D810 );

    // user API
    #include "oCMenu_Status.inl"
  };

  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu;

    void oCStatusScreen_OnInit() zCall( 0x0047E8C0 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x0047ED60 );
    virtual ~oCStatusScreen()    zCall( 0x0047EB50 );

    // user API
    #include "oCStatusScreen.inl"
  };

  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu;

    void oCLogScreen_OnInit() zCall( 0x0047EF80 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x0047F3E0 );
    virtual ~oCLogScreen()    zCall( 0x0047F1F0 );

    // user API
    #include "oCLogScreen.inl"
  };

  class oCMapScreen {
  public:

    void oCMapScreen_OnInit() zCall( 0x0047F600 );
    oCMapScreen()             zInit( oCMapScreen_OnInit() );
    void Show( int )          zCall( 0x0047F9C0 );
    virtual ~oCMapScreen()    zCall( 0x0047F7F0 );

    // user API
    #include "oCMapScreen.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMENU__STATUS_H__VER3__