// Supported with union (c) 2018-2021 Union team

#ifndef __OINFORMATION_MANAGER_H__VER2__
#define __OINFORMATION_MANAGER_H__VER2__

namespace Gothic_II_Classic {

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

    void oCInformationManager_OnInit()                   zCall( 0x00776730 );
    void UpdateViewSettings()                            zCall( 0x007765E0 );

  private:
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );

  public:
    ~oCInformationManager()                              zCall( 0x00776BB0 );
    void __fastcall ToggleStatus()                       zCall( 0x00776D00 );
    void __fastcall PrintStatus()                        zCall( 0x00776D50 );
    int __fastcall HasFinished()                         zCall( 0x007777B0 );
    int __fastcall WaitingForEnd()                       zCall( 0x007777C0 );
    void __fastcall SetNpc( oCNpc* )                     zCall( 0x007777D0 );
    void __fastcall Update()                             zCall( 0x00777990 );
    void __fastcall Exit()                               zCall( 0x00778020 );
    void __fastcall CameraStart()                        zCall( 0x00778180 );
    void __fastcall CameraStop()                         zCall( 0x00778300 );
    void __fastcall CameraRefresh()                      zCall( 0x00778370 );
    void __fastcall ProcessImportant()                   zCall( 0x00778390 );
    void __fastcall ProcessNextImportant()               zCall( 0x00778590 );
    void __fastcall InfoWaitForEnd()                     zCall( 0x00778770 );
    void __fastcall CollectInfos()                       zCall( 0x00778880 );
    int __fastcall CollectChoices( oCInfo* )             zCall( 0x00778AB0 );
    void __fastcall OnImportantBegin()                   zCall( 0x00778B90 );
    void __fastcall OnImportantEnd()                     zCall( 0x00778C70 );
    void __fastcall OnInfoBegin()                        zCall( 0x00778DD0 );
    void __fastcall OnInfo( int )                        zCall( 0x00778E90 );
    void __fastcall OnInfo( oCInfo* )                    zCall( 0x00779070 );
    void __fastcall OnChoiceBegin()                      zCall( 0x00779350 );
    void __fastcall OnChoice( int )                      zCall( 0x00779560 );
    void __fastcall OnChoice( oCInfoChoice* )            zCall( 0x00779780 );
    void __fastcall OnChoiceEnd()                        zCall( 0x00779970 );
    void __fastcall OnInfoEnd()                          zCall( 0x00779AD0 );
    void __fastcall OnTradeBegin()                       zCall( 0x00779C40 );
    void __fastcall OnTradeEnd()                         zCall( 0x00779D40 );
    void __fastcall OnExit()                             zCall( 0x00779EB0 );
    void __fastcall OnTermination()                      zCall( 0x00779F80 );
    static oCInformationManager& GetInformationManager() zCall( 0x00776590 );

    // user API
    #include "oCInformationManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OINFORMATION_MANAGER_H__VER2__