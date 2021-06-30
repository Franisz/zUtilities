// Supported with union (c) 2018 Union team

#ifndef __ZCCS_CONTEXT_H__VER0__
#define __ZCCS_CONTEXT_H__VER0__

#include "zCCsCutscene.h"
#include "zCCsLib.h"

namespace Gothic_I_Classic {

  class zCCSCutsceneContext : public zCCutscene {
  public:
    zCLASS_DECLARATION( zCCSCutsceneContext )

    enum zTCSPlayResult {
      CS_PLAY_STARTEDPLAYING,
      CS_PLAY_STOPPED,
      CS_PLAY_INTERRUPTED,
      CS_PLAY_RESUMED,
      CS_PLAY_CONTINUED,
      CS_PLAY_DISABLED,
      CS_PLAY_STARTFAILED,
      CS_PLAY_RESUMEFAILED,
      CS_PLAY_TOOFAR,
      CS_PLAY_MAXREACHED,
      CS_PLAY_NOTTRIGGERED,
      CS_PLAY_CHECKFAILED,
      CS_PLAY_MAX
    };

    zTCSPlayResult lastPlayResult;
    int allowedToPlay;
    zCVob* alternativeStageVob;
    int wasTriggered;
    int isCutscene;
    int loaded;
    int reference;
    zCVob* stage;
    zCCSPoolItem* poolItem;
    float lastTimeStamp;
    float lastTimePoint;

    void zCCSCutsceneContext_OnInit()                                   zCall( 0x00404EB0 );
    void zCCSCutsceneContext_OnInit( zSTRING& )                         zCall( 0x00404F40 );
    void zCCSCutsceneContext_OnInit( zCCSBlock*, int, int )             zCall( 0x00405630 );
    zCCSCutsceneContext()                                               zInit( zCCSCutsceneContext_OnInit() );
    zCCSCutsceneContext( zSTRING& a0 )                                  zInit( zCCSCutsceneContext_OnInit( a0 ));
    zCCSCutsceneContext( zCCSBlock* a0, int a1, int a2 )                zInit( zCCSCutsceneContext_OnInit( a0, a1, a2 ));
    void UseThisSubBlock( zCCSBlock* )                                  zCall( 0x004058C0 );
    zSTRING GetCSName() const                                           zCall( 0x00405FC0 );
    void HandleTrigger()                                                zCall( 0x00408C60 );
    void HandleUntrigger()                                              zCall( 0x00408F00 );
    float GetLastTimePoint()                                            zCall( 0x00408F10 );
    float GetLastTimeStamp()                                            zCall( 0x00408F20 );
    zTCSPlayResult GetLastPlayResult( zSTRING& )                        zCall( 0x00408F30 );
    int AreU( zSTRING const& )                                          zCall( 0x00409400 );
    int AreU( int )                                                     zCall( 0x004094C0 );
    int IsForcedInterrupted()                                           zCall( 0x004094E0 );
    int ReplayCutscene()                                                zCall( 0x00409550 );
    void ForcedResume()                                                 zCall( 0x00409690 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00404D70 );
    static int DisablePlayCutscenes( int )                              zCall( 0x00404EA0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00404E70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00405BB0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004060E0 );
    virtual ~zCCSCutsceneContext()                                      zCall( 0x00405970 );
    virtual int IsFinished()                                            zCall( 0x00409530 );
    virtual int AddMainRole( zCVob* )                                   zCall( 0x00409C60 );
    virtual int StartPlaying()                                          zCall( 0x004065A0 );
    virtual void Stop()                                                 zCall( 0x00406BF0 );
    virtual void Interrupt()                                            zCall( 0x00407450 );
    virtual int IsCutscene()                                            zCall( 0x00404E80 );
    virtual void PrintDebugInfo( zSTRING const& )                       zCall( 0x00409720 );
    virtual zCVob* GetStage()                                           zCall( 0x00409600 );
    virtual zCVob* CatchPlayer( zCVob* )                                zCall( 0x00409680 );
    virtual void PrepareBlock()                                         zCall( 0x004095C0 );
    virtual void SetPoolItem( zCCSPoolItem* )                           zCall( 0x00409560 );
    virtual void SetStage( zCVob* )                                     zCall( 0x00409620 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040D210 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040D2E0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040D100 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040D150 );
    virtual int Play( zVEC3 )                                           zCall( 0x004079B0 );
    virtual void ForcedInterrupt()                                      zCall( 0x00407700 );
    virtual int CheckRoleReactions()                                    zCall( 0x004096B0 );
    virtual int IsPlaying()                                             zCall( 0x00409500 );
    virtual int IsOutputUnit()                                          zCall( 0x00404E90 );


    // static properties
    static int& playDisabled;

    // user API
    #include "zCCSCutsceneContext.inl"
  };

  class zCCSDebugger {
  public:
    zCArray<zCCSBlockBase*> callstack;
    zCCSSyncBlock* callframe;
    zCCSDebugger* deb;

    zCCSDebugger() {}
    virtual ~zCCSDebugger()                               zCall( 0x0041E9E0 );
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )    zPureCall;
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )    zPureCall;
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )      zPureCall;
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )   zPureCall;
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& ) zPureCall;
    virtual void CSDB_StartPlaying( zCCutscene* )         zPureCall;
    virtual void CSDB_Stop( zCCutscene* )                 zPureCall;

    // user API
    #include "zCCSDebugger.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_CONTEXT_H__VER0__