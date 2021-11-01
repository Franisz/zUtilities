// Supported with union (c) 2018-2021 Union team

#ifndef __OINFORMATION_MANAGER_H__VER1__
#define __OINFORMATION_MANAGER_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 58h
  class oCInformationManager {
  public:
    typedef enum zEInformationManagerMode {
      INFO_MGR_MODE_IMPORTANT,
      INFO_MGR_MODE_INFO,
      INFO_MGR_MODE_CHOICE,
      INFO_MGR_MODE_TRADE
    } zTInfoMgrMode;

    zSTRING LastMethod;            // sizeof 14h    offset 00h
    zCViewDialogChoice* DlgStatus; // sizeof 04h    offset 14h
    oCViewDialogTrade* DlgTrade;   // sizeof 04h    offset 18h
    zCViewDialogChoice* DlgChoice; // sizeof 04h    offset 1Ch
    oCNpc* Npc;                    // sizeof 04h    offset 20h
    oCNpc* Player;                 // sizeof 04h    offset 24h
    oCInfo* Info;                  // sizeof 04h    offset 28h
    int IsDone;                    // sizeof 04h    offset 2Ch
    int IsWaitingForEnd;           // sizeof 04h    offset 30h
    int IsWaitingForScript;        // sizeof 04h    offset 34h
    int IsWaitingForOpen;          // sizeof 04h    offset 38h
    int IsWaitingForClose;         // sizeof 04h    offset 3Ch
    int IsWaitingForSelection;     // sizeof 04h    offset 40h
    int MustOpen;                  // sizeof 04h    offset 44h
    int IndexBye;                  // sizeof 04h    offset 48h
    int ImportantCurrent;          // sizeof 04h    offset 4Ch
    int ImportantMax;              // sizeof 04h    offset 50h
    zTInfoMgrMode Mode;            // sizeof 04h    offset 54h

    void oCInformationManager_OnInit()                   zCall( 0x00769110 );
    void UpdateViewSettings()                            zCall( 0x00768FC0 );

  private:
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );

  public:
    ~oCInformationManager()                              zCall( 0x007695E0 );
    void __fastcall ToggleStatus()                       zCall( 0x00769740 );
    void __fastcall PrintStatus()                        zCall( 0x00769790 );
    int __fastcall HasFinished()                         zCall( 0x0076A210 );
    int __fastcall WaitingForEnd()                       zCall( 0x0076A220 );
    void __fastcall SetNpc( oCNpc* )                     zCall( 0x0076A230 );
    void __fastcall Update()                             zCall( 0x0076A3E0 );
    void __fastcall Exit()                               zCall( 0x0076AA80 );
    void __fastcall CameraStart()                        zCall( 0x0076ABE0 );
    void __fastcall CameraStop()                         zCall( 0x0076ADE0 );
    void __fastcall CameraRefresh()                      zCall( 0x0076AE50 );
    void __fastcall ProcessImportant()                   zCall( 0x0076AE70 );
    void __fastcall ProcessNextImportant()               zCall( 0x0076B070 );
    void __fastcall InfoWaitForEnd()                     zCall( 0x0076B250 );
    void __fastcall CollectInfos()                       zCall( 0x0076B360 );
    int __fastcall CollectChoices( oCInfo* )             zCall( 0x0076B590 );
    void __fastcall OnImportantBegin()                   zCall( 0x0076B670 );
    void __fastcall OnImportantEnd()                     zCall( 0x0076B750 );
    void __fastcall OnInfoBegin()                        zCall( 0x0076B8A0 );
    void __fastcall OnInfo( int )                        zCall( 0x0076B960 );
    void __fastcall OnInfo( oCInfo* )                    zCall( 0x0076BB30 );
    void __fastcall OnChoiceBegin()                      zCall( 0x0076BE70 );
    void __fastcall OnChoice( int )                      zCall( 0x0076C080 );
    void __fastcall OnChoice( oCInfoChoice* )            zCall( 0x0076C2A0 );
    void __fastcall OnChoiceEnd()                        zCall( 0x0076C4B0 );
    void __fastcall OnInfoEnd()                          zCall( 0x0076C600 );
    void __fastcall OnTradeBegin()                       zCall( 0x0076C770 );
    void __fastcall OnTradeEnd()                         zCall( 0x0076C840 );
    void __fastcall OnExit()                             zCall( 0x0076C990 );
    void __fastcall OnTermination()                      zCall( 0x0076CA60 );
    static oCInformationManager& GetInformationManager() zCall( 0x00768F70 );

    // user API
    #include "oCInformationManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OINFORMATION_MANAGER_H__VER1__