// Supported with union (c) 2018 Union team

#ifndef __OINFORMATION_MANAGER_H__VER3__
#define __OINFORMATION_MANAGER_H__VER3__

namespace Gothic_II_Addon {

  class oCInformationManager {
  public:
    typedef enum zEInformationManagerMode {
      INFO_MGR_MODE_IMPORTANT,
      INFO_MGR_MODE_INFO,
      INFO_MGR_MODE_CHOICE,
      INFO_MGR_MODE_TRADE
    } zTInfoMgrMode;

    zSTRING LastMethod;
    zCViewDialogChoice* DlgStatus;
    oCViewDialogTrade* DlgTrade;
    zCViewDialogChoice* DlgChoice;
    oCNpc* Npc;
    oCNpc* Player;
    oCInfo* Info;
    int IsDone;
    int IsWaitingForEnd;
    int IsWaitingForScript;
    int IsWaitingForOpen;
    int IsWaitingForClose;
    int IsWaitingForSelection;
    int MustOpen;
    int IndexBye;
    int ImportantCurrent;
    int ImportantMax;
    zTInfoMgrMode Mode;

    void oCInformationManager_OnInit()                   zCall( 0x0065F930 );
    void UpdateViewSettings()                            zCall( 0x0065F7E0 );
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );
    ~oCInformationManager()                              zCall( 0x0065FDD0 );
    void __fastcall ToggleStatus()                       zCall( 0x0065FF20 );
    void __fastcall PrintStatus()                        zCall( 0x0065FF70 );
    int __fastcall HasFinished()                         zCall( 0x006609D0 );
    int __fastcall WaitingForEnd()                       zCall( 0x006609E0 );
    void __fastcall SetNpc( oCNpc* )                     zCall( 0x006609F0 );
    void __fastcall Update()                             zCall( 0x00660BB0 );
    void __fastcall Exit()                               zCall( 0x00661240 );
    void __fastcall CameraStart()                        zCall( 0x006613A0 );
    void __fastcall CameraStop()                         zCall( 0x00661520 );
    void __fastcall CameraRefresh()                      zCall( 0x00661590 );
    void __fastcall ProcessImportant()                   zCall( 0x006615B0 );
    void __fastcall ProcessNextImportant()               zCall( 0x006617B0 );
    void __fastcall InfoWaitForEnd()                     zCall( 0x00661990 );
    void __fastcall CollectInfos()                       zCall( 0x00661AA0 );
    int __fastcall CollectChoices( oCInfo* )             zCall( 0x00661CD0 );
    void __fastcall OnImportantBegin()                   zCall( 0x00661DB0 );
    void __fastcall OnImportantEnd()                     zCall( 0x00661E90 );
    void __fastcall OnInfoBegin()                        zCall( 0x00661FF0 );
    void __fastcall OnInfo( int )                        zCall( 0x006620B0 );
    void __fastcall OnInfo( oCInfo* )                    zCall( 0x00662290 );
    void __fastcall OnChoiceBegin()                      zCall( 0x00662570 );
    void __fastcall OnChoice( int )                      zCall( 0x00662780 );
    void __fastcall OnChoice( oCInfoChoice* )            zCall( 0x006629A0 );
    void __fastcall OnChoiceEnd()                        zCall( 0x00662B90 );
    void __fastcall OnInfoEnd()                          zCall( 0x00662CF0 );
    void __fastcall OnTradeBegin()                       zCall( 0x00662E60 );
    void __fastcall OnTradeEnd()                         zCall( 0x00662F60 );
    void __fastcall OnExit()                             zCall( 0x006630D0 );
    void __fastcall OnTermination()                      zCall( 0x006631A0 );
    static oCInformationManager& GetInformationManager() zCall( 0x0065F790 );

    // user API
    #include "oCInformationManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OINFORMATION_MANAGER_H__VER3__