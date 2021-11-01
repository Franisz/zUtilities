// Supported with union (c) 2018-2021 Union team

#ifndef __ZMUSIC_CTRL_H__VER0__
#define __ZMUSIC_CTRL_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 40h
  class zCEventMusicControler : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventMusicControler )

    enum zTEventMusicControlerSubType {
      zEVENT_START_SPECIAL_SGT,
      zEVENT_STOP_SPECIAL_SGT,
      zEVENT_MUSICCONTROLER_COUNT
    };

    zSTRING sgt; // sizeof 14h    offset 2Ch

    zCEventMusicControler() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0070D0F0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0070D2D0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0070D490 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0070D4C0 );
    virtual ~zCEventMusicControler()                                    zCall( 0x0070D320 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x0070D2E0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x0070D370 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x0070D470 );
    virtual float MD_GetMinTime()                                       zCall( 0x0070D480 );

    // user API
    #include "zCEventMusicControler.inl"
  };

  // sizeof 100h
  class zCMusicControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCMusicControler )

    void zCMusicControler_OnInit()                                      zCall( 0x0070D4F0 );
    zCMusicControler()                                                  zInit( zCMusicControler_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0070CE60 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0070CF00 );
    virtual ~zCMusicControler()                                         zCall( 0x0070D540 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x0070D550 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                    zCall( 0x0070D5B0 );

    // user API
    #include "zCMusicControler.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMUSIC_CTRL_H__VER0__