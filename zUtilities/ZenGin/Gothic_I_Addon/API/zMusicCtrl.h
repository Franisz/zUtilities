// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC_CTRL_H__VER1__
#define __ZMUSIC_CTRL_H__VER1__

namespace Gothic_I_Addon {

  class zCEventMusicControler : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventMusicControler )

    enum zTEventMusicControlerSubType {
      zEVENT_START_SPECIAL_SGT,
      zEVENT_STOP_SPECIAL_SGT,
      zEVENT_MUSICCONTROLER_COUNT
    };

    zSTRING sgt;

    zCEventMusicControler() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x00748230 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00748410 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x007485E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00748610 );
    virtual ~zCEventMusicControler()                                    zCall( 0x00748460 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x00748420 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x007484C0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x007485C0 );
    virtual float MD_GetMinTime()                                       zCall( 0x007485D0 );

    // user API
    #include "zCEventMusicControler.inl"
  };

  class zCMusicControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCMusicControler )

    void zCMusicControler_OnInit()                                      zCall( 0x00748640 );
    zCMusicControler()                                                  zInit( zCMusicControler_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00747F80 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00748020 );
    virtual ~zCMusicControler()                                         zCall( 0x00748690 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x007486A0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                    zCall( 0x00748700 );

    // user API
    #include "zCMusicControler.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMUSIC_CTRL_H__VER1__