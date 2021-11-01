// Supported with union (c) 2018-2021 Union team

#ifndef __OINFORMATION_MANAGER_H__VER0__
#define __OINFORMATION_MANAGER_H__VER0__

namespace Gothic_I_Classic {

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

    void oCInformationManager_OnInit()                   zCall( 0x0072AD70 );
    void UpdateViewSettings()                            zCall( 0x0072AC20 );

  private:
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );

  public:
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