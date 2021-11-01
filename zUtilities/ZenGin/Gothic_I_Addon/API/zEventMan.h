// Supported with union (c) 2018-2021 Union team

#ifndef __ZEVENT_MAN_H__VER1__
#define __ZEVENT_MAN_H__VER1__

#include "zVob.h"
#include "zArchiver.h"

namespace Gothic_I_Addon {

  // sizeof 40h
  class zCEventManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCEventManager )

    int cleared;                         // sizeof 04h    offset 24h
    int active;                          // sizeof 04h    offset 28h
    zCCutscene* cutscene;                // sizeof 04h    offset 2Ch
    zCArray<zCEventMessage*>messageList; // sizeof 0Ch    offset 30h
    zCVob* hostVob;                      // sizeof 04h    offset 3Ch

    void zCEventManager_OnInit()                                        zCall( 0x00714E70 );
    void zCEventManager_OnInit( zCVob* )                                zCall( 0x00714FC0 );
    zCEventManager()                                                    zInit( zCEventManager_OnInit() );
    zCEventManager( zCVob* a0 )                                         zInit( zCEventManager_OnInit( a0 ));
    void KillMessages()                                                 zCall( 0x007151F0 );
    void ShowMessageCommunication( zCVob*, zCVob* )                     zCall( 0x00715E00 );
    void Print_db( zSTRING const&, zCVob* )                             zCall( 0x00716920 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00714C90 );
    static void DoFrameActivity()                                       zCall( 0x00714E30 );
    static void SetShowMessageCommunication( int )                      zCall( 0x00715DE0 );
    static int GetShowMessageCommunication()                            zCall( 0x00715DF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00714DC0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00717090 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x007170D0 );
    virtual ~zCEventManager()                                           zCall( 0x007150F0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00716AE0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x00716BB0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x00716930 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x00716A00 );
    virtual void OnTouchLevel()                                         zCall( 0x00716AD0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x00716C80 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x00715250 );
    virtual void Clear()                                                zCall( 0x00716630 );
    virtual int IsEmpty( int )                                          zCall( 0x00716850 );
    virtual int GetCutsceneMode()                                       zCall( 0x00716620 );
    virtual void SetCutscene( zCCutscene* )                             zCall( 0x007165A0 );
    virtual zCCutscene* GetCutscene()                                   zCall( 0x00716610 );
    virtual int IsRunning( zCEventMessage* )                            zCall( 0x007168B0 );
    virtual void SetActive( int )                                       zCall( 0x00716170 );
    virtual int GetNumMessages()                                        zCall( 0x00459150 );
    virtual zCEventMessage* GetEventMessage( int )                      zCall( 0x00716D60 );
    virtual zCEventMessage* GetActiveMessage()                          zCall( 0x007168E0 );
    virtual void ShowList( int, int )                                   zCall( 0x00716D70 );
    virtual zCNetVobControl* GetNetVobControl( int )                    zCall( 0x00714DD0 );
    virtual void RemoveFromList( zCEventMessage* )                      zCall( 0x00716330 );
    virtual void InsertInList( zCEventMessage* )                        zCall( 0x00716380 );
    virtual void ProcessMessageList()                                   zCall( 0x00716060 );
    virtual void SendMessageToHost( zCEventMessage*, zCVob*, zCVob* )   zCall( 0x00715C10 );
    virtual void Delete( zCEventMessage* )                              zCall( 0x007162F0 );


    // static properties
    static int& disableEventManagers;
    static zCArray<zCEventManager*>& activeEM;
    static int& showMsgCommunication;

    // user API
    #include "zCEventManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZEVENT_MAN_H__VER1__