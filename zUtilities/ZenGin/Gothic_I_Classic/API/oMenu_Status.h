// Supported with union (c) 2018 Union team

#ifndef __OMENU__STATUS_H__VER0__
#define __OMENU__STATUS_H__VER0__

#include "zMenu.h"
#include "oLogManager.h"

namespace Gothic_I_Classic {

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

    void oSMenuInfoAttribute_OnInit() zCall( 0x00478EB0 );
    ~oSMenuInfoAttribute()            zCall( 0x004788F0 );
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

    void oSMenuInfoTalent_OnInit() zCall( 0x00478EF0 );
    ~oSMenuInfoTalent()            zCall( 0x00478970 );
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
    void oCMenu_Log_OnInit( zSTRING const& )          zCall( 0x004747F0 );
    oCMenu_Log( zSTRING const& a0 )                   zInit( oCMenu_Log_OnInit( a0 ));
    void SetDayTime( zSTRING const&, zSTRING const& ) zCall( 0x00474D80 );
    void SetLogTopics( zCList<oCLogTopic> const& )    zCall( 0x00474E20 );
    void SetInfo( zCMenuItem const* )                 zCall( 0x00475510 );
    void InitForDisplay()                             zCall( 0x00475C50 );
    virtual int HandleEvent( int )                    zCall( 0x00475BF0 );
    virtual int HandleEnterItem( zCMenuItem* )        zCall( 0x00475770 );
    virtual int HandleLeaveItem( zCMenuItem* )        zCall( 0x004759A0 );
    virtual int HandleActivateItem( zCMenuItem* )     zCall( 0x00475BE0 );
    virtual void Activate()                           zCall( 0x00475C40 );
    virtual ~oCMenu_Log()                             zCall( 0x00474830 );
    virtual void ScreenInit()                         zCall( 0x00474840 );
    virtual void ScreenDone()                         zCall( 0x00474C70 );
    virtual int ExecCommand( zSTRING const& )         zCall( 0x00475520 );

    // user API
    #include "oCMenu_Log.inl"
  };

  class oCMenu_Status : public zCMenu {
  public:
    zCArray<oSMenuInfoAttribute> m_listAttributes;
    zCArray<oSMenuInfoTalent> m_listTalents;
    zCArray<oSMenuInfoArmor> m_listArmory;

    oCMenu_Status() {}
    void oCMenu_Status_OnInit( zSTRING const& )                       zCall( 0x004763D0 );
    void SetPlayerName( zSTRING const& )                              zCall( 0x00475E80 );
    void SetGuild( zSTRING const& )                                   zCall( 0x00475ED0 );
    void SetExperience( unsigned long, unsigned long, unsigned long ) zCall( 0x00475FC0 );
    void SetLearnPoints( unsigned long )                              zCall( 0x00476300 );
    oCMenu_Status( zSTRING const& a0 )                                zInit( oCMenu_Status_OnInit( a0 ));
    void AddArmor( oSMenuInfoArmor const& )                           zCall( 0x00476520 );
    void AddAttribute( oSMenuInfoAttribute const& )                   zCall( 0x00476650 );
    void AddTalent( oSMenuInfoTalent const& )                         zCall( 0x00476830 );
    void InitForDisplay()                                             zCall( 0x00476A20 );
    virtual int HandleEvent( int )                                    zCall( 0x00475C90 );
    virtual ~oCMenu_Status()                                          zCall( 0x00476450 );

    // user API
    #include "oCMenu_Status.inl"
  };

  class oCStatusScreen {
  public:
    oCMenu_Status* m_pStatusMenu;

    void oCStatusScreen_OnInit() zCall( 0x00477380 );
    oCStatusScreen()             zInit( oCStatusScreen_OnInit() );
    void Show()                  zCall( 0x00477830 );
    virtual ~oCStatusScreen()    zCall( 0x00477620 );

    // user API
    #include "oCStatusScreen.inl"
  };

  class oCLogScreen {
  public:
    oCMenu_Log* m_pLogMenu;

    void oCLogScreen_OnInit() zCall( 0x00477A50 );
    oCLogScreen()             zInit( oCLogScreen_OnInit() );
    void Show()               zCall( 0x00477EC0 );
    virtual ~oCLogScreen()    zCall( 0x00477CD0 );

    // user API
    #include "oCLogScreen.inl"
  };

  class oCMapScreen {
  public:

    void oCMapScreen_OnInit() zCall( 0x004780D0 );
    oCMapScreen()             zInit( oCMapScreen_OnInit() );
    void Show()               zCall( 0x00478490 );
    virtual ~oCMapScreen()    zCall( 0x004782C0 );

    // user API
    #include "oCMapScreen.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMENU__STATUS_H__VER0__