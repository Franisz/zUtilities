// Supported with union (c) 2018 Union team

#ifndef __ZCCS_PLAYER_H__VER1__
#define __ZCCS_PLAYER_H__VER1__

#include "zCCsCutscene.h"
#include "zCCsLib.h"
#include "zCCsContext.h"

namespace Gothic_I_Addon {

  class zCCSPlayer : public zCObject, public zCCSDebugger {
  public:
    zCLASS_DECLARATION( zCCSPlayer )

    int lastProcessDay;
    int lastProcessHour;
    zCList<zCCSCutsceneContext>* processingListItem;
    int processingCtr;
    int debugInfoOnScreen;
    zCView* debugInfoScreen;
    float timerCtr;
    zCList<zCCSCutsceneContext> playList;
    zCCSManager* ownerManager;
    zCWorld* ownerWorld;

    void zCCSPlayer_OnInit()                                                   zCall( 0x0041E430 );
    zCCSPlayer()                                                               zInit( zCCSPlayer_OnInit() );
    void Interrupt()                                                           zCall( 0x0041F8D0 );
    void Resume()                                                              zCall( 0x0041F930 );
    int IsAssigned( zSTRING&, zSTRING& )                                       zCall( 0x00421DB0 );
    void PrintListOfCutscenes( zSTRING const& )                                zCall( 0x00421E20 );
    zCCSCutsceneContext* GetStartedCutscene( zCVob* )                          zCall( 0x004221D0 );
    zCCSCutsceneContext* GetStartedCutscene( zSTRING const& )                  zCall( 0x00422240 );
    zCCSCutsceneContext* GetPlayingGlobalCutscene()                            zCall( 0x004223E0 );
    int UpdateCutscenesNow()                                                   zCall( 0x00422480 );
    void DebugResetInfoscreen()                                                zCall( 0x004224D0 );
    void DebugAddCutscene( int, zVEC3, int )                                   zCall( 0x00422500 );
    void ToggleDebugInfo()                                                     zCall( 0x004228C0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0041E2F0 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0041E420 );
    virtual void Archive( zCArchiver& )                                        zCall( 0x00420480 );
    virtual void Unarchive( zCArchiver& )                                      zCall( 0x00420790 );
    virtual ~zCCSPlayer()                                                      zCall( 0x0041E560 );
    virtual zCCSCutsceneContext* CreateNewOutputUnit( int, zCVob* )            zCall( 0x0041EF20 );
    virtual zCCSCutsceneContext* StartOutputUnit( int, zCVob* )                zCall( 0x0041F250 );
    virtual zCCSCutsceneContext* StartCutscene( zSTRING&, zCVob* )             zCall( 0x0041EC00 );
    virtual zCCSCutsceneContext* StartCutscene( zCCutscene*, zCVob*, zSTRING ) zCall( 0x0041E6E0 );
    virtual void ForgetCutscene( zCCutscene* )                                 zCall( 0x0041F7C0 );
    virtual void ResetCutscenePlayer()                                         zCall( 0x00421670 );
    virtual int StopAllCutscenes( zCVob* )                                     zCall( 0x00421690 );
    virtual int StopAllOutputUnits( zCVob* )                                   zCall( 0x00421A10 );
    virtual void InsertCutscene( zCCSCutsceneContext* )                        zCall( 0x0041F9C0 );
    virtual void RemoveCutscene( zCCSCutsceneContext* )                        zCall( 0x0041FCE0 );
    virtual void OnCSTrigger( zSTRING&, zCVob* )                               zCall( 0x00420010 );
    virtual void OnCSUntrigger( zSTRING&, zCVob* )                             zCall( 0x004202E0 );
    virtual void SetOwnerWorld( zCWorld* )                                     zCall( 0x0041E6C0 );
    virtual void SetOwnerManager( zCCSManager* )                               zCall( 0x0041E6D0 );
    virtual void Process()                                                     zCall( 0x00422530 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )         zCall( 0x004227C0 );
    virtual void ProcessList( zVEC3 const&, int, int, int )                    zCall( 0x00422600 );
    /* for zCCSDebugger num : 7*/
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )                         zCall( 0x00420BA0 );
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )                         zCall( 0x00420CA0 );
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )                           zCall( 0x00420F10 );
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )                        zCall( 0x00421110 );
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& )                      zCall( 0x004213A0 );
    virtual void CSDB_StartPlaying( zCCutscene* )                              zCall( 0x00421630 );
    virtual void CSDB_Stop( zCCutscene* )                                      zCall( 0x00421650 );

    // user API
    #include "zCCSPlayer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_PLAYER_H__VER1__