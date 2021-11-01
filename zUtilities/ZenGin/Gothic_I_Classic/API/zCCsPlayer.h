// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_PLAYER_H__VER0__
#define __ZCCS_PLAYER_H__VER0__

#include "zCCsCutscene.h"
#include "zCCsLib.h"
#include "zCCsContext.h"

namespace Gothic_I_Classic {

  // sizeof 68h
  class zCCSPlayer : public zCObject, public zCCSDebugger {
  public:
    zCLASS_DECLARATION( zCCSPlayer )

    int lastProcessDay;                              // sizeof 04h    offset 3Ch
    int lastProcessHour;                             // sizeof 04h    offset 40h
    zCList<zCCSCutsceneContext>* processingListItem; // sizeof 04h    offset 44h
    int processingCtr;                               // sizeof 04h    offset 48h
    int debugInfoOnScreen;                           // sizeof 04h    offset 4Ch
    zCView* debugInfoScreen;                         // sizeof 04h    offset 50h
    float timerCtr;                                  // sizeof 04h    offset 54h
    zCList<zCCSCutsceneContext> playList;            // sizeof 08h    offset 58h
    zCCSManager* ownerManager;                       // sizeof 04h    offset 60h
    zCWorld* ownerWorld;                             // sizeof 04h    offset 64h

    void zCCSPlayer_OnInit()                                                   zCall( 0x0041C5B0 );
    zCCSPlayer()                                                               zInit( zCCSPlayer_OnInit() );
    void Interrupt()                                                           zCall( 0x0041D8A0 );
    void Resume()                                                              zCall( 0x0041D900 );
    int IsAssigned( zSTRING&, zSTRING& )                                       zCall( 0x0041FA50 );
    void PrintListOfCutscenes( zSTRING const& )                                zCall( 0x0041FAB0 );
    zCCSCutsceneContext* GetStartedCutscene( zCVob* )                          zCall( 0x0041FE50 );
    zCCSCutsceneContext* GetStartedCutscene( zSTRING const& )                  zCall( 0x0041FEC0 );
    zCCSCutsceneContext* GetPlayingGlobalCutscene()                            zCall( 0x00420020 );
    int UpdateCutscenesNow()                                                   zCall( 0x004200C0 );
    void DebugResetInfoscreen()                                                zCall( 0x00420110 );
    void DebugAddCutscene( int, zVEC3, int )                                   zCall( 0x00420140 );
    void ToggleDebugInfo()                                                     zCall( 0x00420510 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0041C480 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0041C5A0 );
    virtual void Archive( zCArchiver& )                                        zCall( 0x0041E380 );
    virtual void Unarchive( zCArchiver& )                                      zCall( 0x0041E650 );
    virtual ~zCCSPlayer()                                                      zCall( 0x0041C6E0 );
    virtual zCCSCutsceneContext* CreateNewOutputUnit( int, zCVob* )            zCall( 0x0041D000 );
    virtual zCCSCutsceneContext* StartOutputUnit( int, zCVob* )                zCall( 0x0041D2E0 );
    virtual zCCSCutsceneContext* StartCutscene( zSTRING&, zCVob* )             zCall( 0x0041CD00 );
    virtual zCCSCutsceneContext* StartCutscene( zCCutscene*, zCVob*, zSTRING ) zCall( 0x0041C850 );
    virtual void ForgetCutscene( zCCutscene* )                                 zCall( 0x0041D7A0 );
    virtual void ResetCutscenePlayer()                                         zCall( 0x0041F3B0 );
    virtual int StopAllCutscenes( zCVob* )                                     zCall( 0x0041F3D0 );
    virtual int StopAllOutputUnits( zCVob* )                                   zCall( 0x0041F700 );
    virtual void InsertCutscene( zCCSCutsceneContext* )                        zCall( 0x0041D9A0 );
    virtual void RemoveCutscene( zCCSCutsceneContext* )                        zCall( 0x0041DC70 );
    virtual void OnCSTrigger( zSTRING&, zCVob* )                               zCall( 0x0041DF50 );
    virtual void OnCSUntrigger( zSTRING&, zCVob* )                             zCall( 0x0041E1F0 );
    virtual void SetOwnerWorld( zCWorld* )                                     zCall( 0x0041C830 );
    virtual void SetOwnerManager( zCCSManager* )                               zCall( 0x0041C840 );
    virtual void Process()                                                     zCall( 0x00420170 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )         zCall( 0x00420410 );
    virtual void ProcessList( zVEC3 const&, int, int, int )                    zCall( 0x00420230 );
    /* for zCCSDebugger num : 7*/
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )                         zCall( 0x0041EA10 );
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )                         zCall( 0x0041EB10 );
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )                           zCall( 0x0041ED30 );
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )                        zCall( 0x0041EF30 );
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& )                      zCall( 0x0041F160 );
    virtual void CSDB_StartPlaying( zCCutscene* )                              zCall( 0x0041F390 );
    virtual void CSDB_Stop( zCCutscene* )                                      zCall( 0x0041F3A0 );

    // user API
    #include "zCCSPlayer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_PLAYER_H__VER0__