// Supported with union (c) 2018-2021 Union team

#ifndef __OMENU__STATUS_H__VER3__
#define __OMENU__STATUS_H__VER3__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_II_Addon {

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

    void oSMenuInfoAttribute_OnInit() zCall( 0x004803B0 );
    ~oSMenuInfoAttribute()            zCall( 0x0047FE10 );
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

    void oSMenuInfoTalent_OnInit() zCall( 0x004803F0 );
    ~oSMenuInfoTalent()            zCall( 0x0047FE90 );
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

  // sizeof CE8h
  class oCMenu_Status : public zCMenu {
  public:
    zCArray<oSMenuInfoAttribute> m_listAttributes; // sizeof 0Ch    offset CC4h
    zCArray<oSMenuInfoTalent> m_listTalents;       // sizeof 0Ch    offset CD0h
    zCArray<oSMenuInfoArmor> m_listArmory;         // sizeof 0Ch    offset CDCh

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

  // sizeof 08h
  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu; // sizeof 04h    offset 04h

    void oCStatusScreen_OnInit() zCall( 0x0047E8C0 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x0047ED60 );
    virtual ~oCStatusScreen()    zCall( 0x0047EB50 );

    // user API
    #include "oCStatusScreen.inl"
  };

  // sizeof 08h
  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu; // sizeof 04h    offset 04h

    void oCLogScreen_OnInit() zCall( 0x0047EF80 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x0047F3E0 );
    virtual ~oCLogScreen()    zCall( 0x0047F1F0 );

    // user API
    #include "oCLogScreen.inl"
  };

  // sizeof 04h
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