// Supported with union (c) 2018-2021 Union team

#ifndef __OMENU__STATUS_H__VER2__
#define __OMENU__STATUS_H__VER2__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_II_Classic {

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

    void oSMenuInfoAttribute_OnInit() zCall( 0x0047EED0 );
    ~oSMenuInfoAttribute()            zCall( 0x0047E930 );
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

    void oSMenuInfoTalent_OnInit() zCall( 0x0047EF10 );
    ~oSMenuInfoTalent()            zCall( 0x0047E9B0 );
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
    void oCMenu_Log_OnInit( zSTRING const& )          zCall( 0x0047A490 );
    oCMenu_Log( zSTRING const& a0 )                   zInit( oCMenu_Log_OnInit( a0 ));
    void SetDayTime( zSTRING const&, zSTRING const& ) zCall( 0x0047AA20 );
    void SetLogTopics( zCList<oCLogTopic> const& )    zCall( 0x0047AAC0 );
    void SetInfo( zCMenuItem const* )                 zCall( 0x0047B1B0 );
    void InitForDisplay()                             zCall( 0x0047B8F0 );
    virtual int HandleEvent( int )                    zCall( 0x0047B890 );
    virtual int HandleEnterItem( zCMenuItem* )        zCall( 0x0047B410 );
    virtual int HandleLeaveItem( zCMenuItem* )        zCall( 0x0047B640 );
    virtual int HandleActivateItem( zCMenuItem* )     zCall( 0x0047B880 );
    virtual void Activate()                           zCall( 0x0047B8E0 );
    virtual ~oCMenu_Log()                             zCall( 0x0047A4D0 );
    virtual void ScreenInit()                         zCall( 0x0047A4E0 );
    virtual void ScreenDone()                         zCall( 0x0047A910 );
    virtual int ExecCommand( zSTRING const& )         zCall( 0x0047B1C0 );

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
    void oCMenu_Status_OnInit( zSTRING const& )                       zCall( 0x0047C2C0 );
    void SetPlayerName( zSTRING const& )                              zCall( 0x0047BB20 );
    void SetGuild( zSTRING const& )                                   zCall( 0x0047BB70 );
    void SetMagicalGuild( zSTRING const& )                            zCall( 0x0047BC60 );
    void SetExperience( unsigned long, unsigned long, unsigned long ) zCall( 0x0047BD50 );
    void SetLearnPoints( unsigned long )                              zCall( 0x0047C180 );
    oCMenu_Status( zSTRING const& a0 )                                zInit( oCMenu_Status_OnInit( a0 ));
    void AddArmor( oSMenuInfoArmor const& )                           zCall( 0x0047C410 );
    void AddAttribute( oSMenuInfoAttribute const& )                   zCall( 0x0047C520 );
    void AddTalent( oSMenuInfoTalent const& )                         zCall( 0x0047C700 );
    void InitForDisplay()                                             zCall( 0x0047C8F0 );
    virtual int HandleEvent( int )                                    zCall( 0x0047B930 );
    virtual ~oCMenu_Status()                                          zCall( 0x0047C340 );

    // user API
    #include "oCMenu_Status.inl"
  };

  // sizeof 08h
  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu; // sizeof 04h    offset 04h

    void oCStatusScreen_OnInit() zCall( 0x0047D3F0 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x0047D890 );
    virtual ~oCStatusScreen()    zCall( 0x0047D680 );

    // user API
    #include "oCStatusScreen.inl"
  };

  // sizeof 08h
  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu; // sizeof 04h    offset 04h

    void oCLogScreen_OnInit() zCall( 0x0047DAB0 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x0047DF10 );
    virtual ~oCLogScreen()    zCall( 0x0047DD20 );

    // user API
    #include "oCLogScreen.inl"
  };

  // sizeof 04h
  class oCMapScreen {
  public:

    void oCMapScreen_OnInit() zCall( 0x0047E130 );
    oCMapScreen()             zInit( oCMapScreen_OnInit() );
    void Show()               zCall( 0x0047E4F0 );
    virtual ~oCMapScreen()    zCall( 0x0047E320 );

    // user API
    #include "oCMapScreen.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMENU__STATUS_H__VER2__