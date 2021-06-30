// Supported with union (c) 2018 Union team

#ifndef __OINFORMATION_MANAGER_H__VER2__
#define __OINFORMATION_MANAGER_H__VER2__

namespace Gothic_II_Classic {

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

    void oCInformationManager_OnInit()                   zCall( 0x00776730 );
    void UpdateViewSettings()                            zCall( 0x007765E0 );
    oCInformationManager()                               zInit( oCInformationManager_OnInit() );
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