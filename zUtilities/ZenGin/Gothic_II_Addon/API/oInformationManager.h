// Supported with union (c) 2018-2021 Union team

#ifndef __OINFORMATION_MANAGER_H__VER3__
#define __OINFORMATION_MANAGER_H__VER3__

namespace Gothic_II_Addon {

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

    void oCInformationManager_OnInit()                   zCall( 0x0065F930 );
    void UpdateViewSettings()                            zCall( 0x0065F7E0 );

  private:
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );

  public:
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