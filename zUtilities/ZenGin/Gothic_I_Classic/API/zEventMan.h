// Supported with union (c) 2018 Union team

#ifndef __ZEVENT_MAN_H__VER0__
#define __ZEVENT_MAN_H__VER0__

#include "zVob.h"
#include "zArchiver.h"

namespace Gothic_I_Classic {

  class zCEventManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCEventManager )

    int cleared;
    int active;
    zCCutscene* cutscene;
    zCArray<zCEventMessage*> messageList;
    zCVob* hostVob;

    void zCEventManager_OnInit()                                        zCall( 0x006DCCC0 );
    void zCEventManager_OnInit( zCVob* )                                zCall( 0x006DCE10 );
    zCEventManager()                                                    zInit( zCEventManager_OnInit() );
    zCEventManager( zCVob* a0 )                                         zInit( zCEventManager_OnInit( a0 ));
    void KillMessages()                                                 zCall( 0x006DD030 );
    void ShowMessageCommunication( zCVob*, zCVob* )                     zCall( 0x006DDB30 );
    void Print_db( zSTRING const&, zCVob* )                             zCall( 0x006DE5C0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006DCAE0 );
    static void DoFrameActivity()                                       zCall( 0x006DCC80 );
    static void SetShowMessageCommunication( int )                      zCall( 0x006DDB10 );
    static int GetShowMessageCommunication()                            zCall( 0x006DDB20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006DCC10 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006DEC70 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006DECB0 );
    virtual ~zCEventManager()                                           zCall( 0x006DCF40 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006DE760 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006DE820 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x006DE5D0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x006DE690 );
    virtual void OnTouchLevel()                                         zCall( 0x006DE750 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x006DE8E0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x006DD090 );
    virtual void Clear()                                                zCall( 0x006DE2F0 );
    virtual int IsEmpty( int )                                          zCall( 0x006DE4F0 );
    virtual int GetCutsceneMode()                                       zCall( 0x006DE2E0 );
    virtual void SetCutscene( zCCutscene* )                             zCall( 0x006DE260 );
    virtual zCCutscene* GetCutscene()                                   zCall( 0x006DE2D0 );
    virtual int IsRunning( zCEventMessage* )                            zCall( 0x006DE550 );
    virtual void SetActive( int )                                       zCall( 0x006DDE20 );
    virtual int GetNumMessages()                                        zCall( 0x00452600 );
    virtual zCEventMessage* GetEventMessage( int )                      zCall( 0x006DE9B0 );
    virtual zCEventMessage* GetActiveMessage()                          zCall( 0x006DE580 );
    virtual void ShowList( int, int )                                   zCall( 0x006DE9C0 );
    virtual zCNetVobControl* GetNetVobControl( int )                    zCall( 0x006DCC20 );
    virtual void RemoveFromList( zCEventMessage* )                      zCall( 0x006DDFE0 );
    virtual void InsertInList( zCEventMessage* )                        zCall( 0x006DE030 );
    virtual void ProcessMessageList()                                   zCall( 0x006DDD10 );
    virtual void SendMessageToHost( zCEventMessage*, zCVob*, zCVob* )   zCall( 0x006DD970 );
    virtual void Delete( zCEventMessage* )                              zCall( 0x006DDFA0 );


    // static properties
    static int& disableEventManagers;
    static zCArray<zCEventManager*>& activeEM;
    static int& showMsgCommunication;

    // user API
    #include "zCEventManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZEVENT_MAN_H__VER0__