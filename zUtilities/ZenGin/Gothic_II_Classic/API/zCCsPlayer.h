// Supported with union (c) 2018 Union team

#ifndef __ZCCS_PLAYER_H__VER2__
#define __ZCCS_PLAYER_H__VER2__

#include "zCCsCutscene.h"
#include "zCCsLib.h"
#include "zCCsContext.h"

namespace Gothic_II_Classic {

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

    void zCCSPlayer_OnInit()                                                   zCall( 0x0041C7D0 );
    zCCSPlayer()                                                               zInit( zCCSPlayer_OnInit() );
    void Interrupt()                                                           zCall( 0x0041DB80 );
    void Resume()                                                              zCall( 0x0041DBE0 );
    int IsAssigned( zSTRING&, zSTRING& )                                       zCall( 0x0041FE50 );
    void PrintListOfCutscenes( zSTRING const& )                                zCall( 0x0041FEB0 );
    zCCSCutsceneContext* GetStartedCutscene( zCVob* )                          zCall( 0x00420270 );
    zCCSCutsceneContext* GetStartedCutscene( zSTRING const& )                  zCall( 0x004202E0 );
    zCCSCutsceneContext* GetPlayingGlobalCutscene()                            zCall( 0x00420440 );
    int UpdateCutscenesNow()                                                   zCall( 0x004204E0 );
    void DebugResetInfoscreen()                                                zCall( 0x00420530 );
    void DebugAddCutscene( int, zVEC3, int )                                   zCall( 0x00420560 );
    void ToggleDebugInfo()                                                     zCall( 0x00420930 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0041C6B0 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0041C7C0 );
    virtual void Archive( zCArchiver& )                                        zCall( 0x0041E6E0 );
    virtual void Unarchive( zCArchiver& )                                      zCall( 0x0041E9E0 );
    virtual ~zCCSPlayer()                                                      zCall( 0x0041C900 );
    virtual zCCSCutsceneContext* CreateNewOutputUnit( int, zCVob* )            zCall( 0x0041D210 );
    virtual zCCSCutsceneContext* StartOutputUnit( int, zCVob* )                zCall( 0x0041D520 );
    virtual zCCSCutsceneContext* StartCutscene( zSTRING&, zCVob* )             zCall( 0x0041CF10 );
    virtual zCCSCutsceneContext* StartCutscene( zCCutscene*, zCVob*, zSTRING ) zCall( 0x0041CA70 );
    virtual void ForgetCutscene( zCCutscene* )                                 zCall( 0x0041DA80 );
    virtual void ResetCutscenePlayer()                                         zCall( 0x0041F7B0 );
    virtual int StopAllCutscenes( zCVob* )                                     zCall( 0x0041F7D0 );
    virtual int StopAllOutputUnits( zCVob* )                                   zCall( 0x0041FB00 );
    virtual void InsertCutscene( zCCSCutsceneContext* )                        zCall( 0x0041DC80 );
    virtual void RemoveCutscene( zCCSCutsceneContext* )                        zCall( 0x0041DF90 );
    virtual void OnCSTrigger( zSTRING&, zCVob* )                               zCall( 0x0041E2B0 );
    virtual void OnCSUntrigger( zSTRING&, zCVob* )                             zCall( 0x0041E550 );
    virtual void SetOwnerWorld( zCWorld* )                                     zCall( 0x0041CA50 );
    virtual void SetOwnerManager( zCCSManager* )                               zCall( 0x0041CA60 );
    virtual void Process()                                                     zCall( 0x00420590 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )         zCall( 0x00420830 );
    virtual void ProcessList( zVEC3 const&, int, int, int )                    zCall( 0x00420650 );
    /* for zCCSDebugger num : 7*/
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )                         zCall( 0x0041EDE0 );
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )                         zCall( 0x0041EEE0 );
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )                           zCall( 0x0041F120 );
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )                        zCall( 0x0041F330 );
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& )                      zCall( 0x0041F560 );
    virtual void CSDB_StartPlaying( zCCutscene* )                              zCall( 0x0041F790 );
    virtual void CSDB_Stop( zCCutscene* )                                      zCall( 0x0041F7A0 );

    // user API
    #include "zCCSPlayer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCCS_PLAYER_H__VER2__