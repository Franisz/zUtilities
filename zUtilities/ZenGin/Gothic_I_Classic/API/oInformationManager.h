// Supported with union (c) 2018 Union team

#ifndef __OINFORMATION_MANAGER_H__VER0__
#define __OINFORMATION_MANAGER_H__VER0__

namespace Gothic_I_Classic {

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

    void oCInformationManager_OnInit()                   zCall( 0x0072AD70 );
    void UpdateViewSettings()                            zCall( 0x0072AC20 );
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );
    ~oCInformationManager()                              zCall( 0x0072B210 );
    void __fastcall ToggleStatus()                       zCall( 0x0072B360 );
    void __fastcall PrintStatus()                        zCall( 0x0072B3B0 );
    int __fastcall HasFinished()                         zCall( 0x0072BCC0 );
    int __fastcall WaitingForEnd()                       zCall( 0x0072BCD0 );
    void __fastcall SetNpc( oCNpc* )                     zCall( 0x0072BCE0 );
    void __fastcall Update()                             zCall( 0x0072BE90 );
    void __fastcall Exit()                               zCall( 0x0072C530 );
    void __fastcall CameraStart()                        zCall( 0x0072C690 );
    void __fastcall CameraStop()                         zCall( 0x0072C810 );
    void __fastcall CameraRefresh()                      zCall( 0x0072C880 );
    void __fastcall ProcessImportant()                   zCall( 0x0072C8A0 );
    void __fastcall ProcessNextImportant()               zCall( 0x0072CAA0 );
    void __fastcall InfoWaitForEnd()                     zCall( 0x0072CC80 );
    void __fastcall CollectInfos()                       zCall( 0x0072CD90 );
    int __fastcall CollectChoices( oCInfo* )             zCall( 0x0072CFC0 );
    void __fastcall OnImportantBegin()                   zCall( 0x0072D0A0 );
    void __fastcall OnImportantEnd()                     zCall( 0x0072D180 );
    void __fastcall OnInfoBegin()                        zCall( 0x0072D2E0 );
    void __fastcall OnInfo( int )                        zCall( 0x0072D3A0 );
    void __fastcall OnInfo( oCInfo* )                    zCall( 0x0072D560 );
    void __fastcall OnChoiceBegin()                      zCall( 0x0072D840 );
    void __fastcall OnChoice( int )                      zCall( 0x0072DA50 );
    void __fastcall OnChoice( oCInfoChoice* )            zCall( 0x0072DC70 );
    void __fastcall OnChoiceEnd()                        zCall( 0x0072DE60 );
    void __fastcall OnInfoEnd()                          zCall( 0x0072DFC0 );
    void __fastcall OnTradeBegin()                       zCall( 0x0072E130 );
    void __fastcall OnTradeEnd()                         zCall( 0x0072E200 );
    void __fastcall OnExit()                             zCall( 0x0072E360 );
    void __fastcall OnTermination()                      zCall( 0x0072E430 );
    static oCInformationManager& GetInformationManager() zCall( 0x0072ABD0 );

    // user API
    #include "oCInformationManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OINFORMATION_MANAGER_H__VER0__