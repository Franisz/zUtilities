// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC_CTRL_H__VER3__
#define __ZMUSIC_CTRL_H__VER3__

#include "zVobMisc.h"

namespace Gothic_II_Addon {

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
    static zCObject* _CreateNewInstance()                       zCall( 0x00642960 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x00642B20 );
    virtual void Archive( zCArchiver& )                         zCall( 0x00642CE0 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x00642D10 );
    virtual ~zCEventMusicControler()                            zCall( 0x00642B70 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x00642B30 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x00642BC0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x00642CC0 );
    virtual float MD_GetMinTime()                               zCall( 0x00642CD0 );

    // user API
    #include "zCEventMusicControler.inl"
  };

  class zCMusicControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCMusicControler )

    void zCMusicControler_OnInit()                    zCall( 0x00642D40 );
    zCMusicControler()                                zInit( zCMusicControler_OnInit() );
    static zCObject* _CreateNewInstance()             zCall( 0x006426F0 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x00642770 );
    virtual ~zCMusicControler()                       zCall( 0x00642D90 );
    virtual void OnMessage( zCEventMessage*, zCVob* ) zCall( 0x00642DA0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )  zCall( 0x00642E00 );

    // user API
    #include "zCMusicControler.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMUSIC_CTRL_H__VER3__