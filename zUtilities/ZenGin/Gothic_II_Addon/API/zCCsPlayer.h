// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_PLAYER_H__VER3__
#define __ZCCS_PLAYER_H__VER3__

#include "zCCsCutscene.h"
#include "zCCsLib.h"
#include "zCCsContext.h"

namespace Gothic_II_Addon {

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

    void zCCSPlayer_OnInit()                                                   zCall( 0x0041CB00 );
    zCCSPlayer()                                                               zInit( zCCSPlayer_OnInit() );
    void Interrupt()                                                           zCall( 0x0041DEB0 );
    void Resume()                                                              zCall( 0x0041DF10 );
    int IsAssigned( zSTRING&, zSTRING& )                                       zCall( 0x00420180 );
    void PrintListOfCutscenes( zSTRING const& )                                zCall( 0x004201E0 );
    zCCSCutsceneContext* GetStartedCutscene( zCVob* )                          zCall( 0x004205A0 );
    zCCSCutsceneContext* GetStartedCutscene( zSTRING const& )                  zCall( 0x00420610 );
    zCCSCutsceneContext* GetPlayingGlobalCutscene()                            zCall( 0x00420770 );
    int UpdateCutscenesNow()                                                   zCall( 0x00420810 );
    void DebugResetInfoscreen()                                                zCall( 0x00420860 );
    void DebugAddCutscene( int, zVEC3, int )                                   zCall( 0x00420890 );
    void ToggleDebugInfo()                                                     zCall( 0x00420C60 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0041C9E0 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0041CAF0 );
    virtual void Archive( zCArchiver& )                                        zCall( 0x0041EA10 );
    virtual void Unarchive( zCArchiver& )                                      zCall( 0x0041ED10 );
    virtual ~zCCSPlayer()                                                      zCall( 0x0041CC30 );
    virtual zCCSCutsceneContext* CreateNewOutputUnit( int, zCVob* )            zCall( 0x0041D540 );
    virtual zCCSCutsceneContext* StartOutputUnit( int, zCVob* )                zCall( 0x0041D850 );
    virtual zCCSCutsceneContext* StartCutscene( zSTRING&, zCVob* )             zCall( 0x0041D240 );
    virtual zCCSCutsceneContext* StartCutscene( zCCutscene*, zCVob*, zSTRING ) zCall( 0x0041CDA0 );
    virtual void ForgetCutscene( zCCutscene* )                                 zCall( 0x0041DDB0 );
    virtual void ResetCutscenePlayer()                                         zCall( 0x0041FAE0 );
    virtual int StopAllCutscenes( zCVob* )                                     zCall( 0x0041FB00 );
    virtual int StopAllOutputUnits( zCVob* )                                   zCall( 0x0041FE30 );
    virtual void InsertCutscene( zCCSCutsceneContext* )                        zCall( 0x0041DFB0 );
    virtual void RemoveCutscene( zCCSCutsceneContext* )                        zCall( 0x0041E2C0 );
    virtual void OnCSTrigger( zSTRING&, zCVob* )                               zCall( 0x0041E5E0 );
    virtual void OnCSUntrigger( zSTRING&, zCVob* )                             zCall( 0x0041E880 );
    virtual void SetOwnerWorld( zCWorld* )                                     zCall( 0x0041CD80 );
    virtual void SetOwnerManager( zCCSManager* )                               zCall( 0x0041CD90 );
    virtual void Process()                                                     zCall( 0x004208C0 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )         zCall( 0x00420B60 );
    virtual void ProcessList( zVEC3 const&, int, int, int )                    zCall( 0x00420980 );
    /* for zCCSDebugger num : 7*/
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )                         zCall( 0x0041F110 );
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )                         zCall( 0x0041F210 );
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )                           zCall( 0x0041F450 );
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )                        zCall( 0x0041F660 );
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& )                      zCall( 0x0041F890 );
    virtual void CSDB_StartPlaying( zCCutscene* )                              zCall( 0x0041FAC0 );
    virtual void CSDB_Stop( zCCutscene* )                                      zCall( 0x0041FAD0 );

    // user API
    #include "zCCSPlayer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCCS_PLAYER_H__VER3__