// Supported with union (c) 2018 Union team

#ifndef __ZCCS_MANAGER_H__VER1__
#define __ZCCS_MANAGER_H__VER1__

#include "zCCsProps.h"

namespace Gothic_I_Addon {
  const int zLIB_STORE_ASCII = 1;
  const int zLIB_STORE_BIN   = 2;
  const int zLIB_LOAD_ASCII  = 1;
  const int zLIB_LOAD_BIN    = 2;

  class zCCSManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSManager )

    zCArray<zSTRING> libSvmModuleList;
    zCCutscene* iteration;
    zCCSBlockBase* iter;
    int iterA;
    int iterB;
    zCArray<zCCSPoolItem*> csPool;
    zCArray<zSTRING> commandStrings;
    zCArray<zCCSPlayer*>csPlayerList;
    zCCSLib* src_lib;
    zCCSLib* library;
    int iterator;

    void zCCSManager_OnInit()                                           zCall( 0x0041BE50 );
    zCCSManager()                                                       zInit( zCCSManager_OnInit() );
    zCCSCutsceneContext* InitiateCSwithContext( zCCSCutsceneContext* )  zCall( 0x0041C340 );
    zCCSCutsceneContext* InitiateOUwithContext( zCCSCutsceneContext* )  zCall( 0x0041C4C0 );
    zCCSCutsceneContext* CreateNewCutscene( zSTRING& )                  zCall( 0x0041C4F0 );
    zCCSCutsceneContext* CreateNewOutputUnit( int )                     zCall( 0x0041C660 );
    int IsDeactivated( zSTRING& )                                       zCall( 0x0041C710 );
    void PoolCountStart( zSTRING& )                                     zCall( 0x0041C730 );
    void PoolCountStop( zSTRING& )                                      zCall( 0x0041C750 );
    int PoolHasFlags( zSTRING&, int )                                   zCall( 0x0041C770 );
    void PoolClrFlags( zSTRING&, int )                                  zCall( 0x0041C7A0 );
    void PoolSetFlags( zSTRING&, int )                                  zCall( 0x0041C7C0 );
    int PoolNumPlayed( zSTRING& )                                       zCall( 0x0041C7E0 );
    int PoolAllowedToStart( zSTRING& )                                  zCall( 0x0041C800 );
    void PoolResetAll()                                                 zCall( 0x0041CA70 );
    void PoolResetByHour()                                              zCall( 0x0041CA90 );
    void PoolResetByDay()                                               zCall( 0x0041CAD0 );
    void AddCommand( zSTRING& )                                         zCall( 0x0041CB10 );
    int GetNumOfShortCom()                                              zCall( 0x0041CC80 );
    zSTRING GetShortCom( int )                                          zCall( 0x0041CC90 );
    void LibForceToLoad()                                               zCall( 0x0041DCD0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0041B560 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0041BF70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0041CE20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0041D000 );
    virtual ~zCCSManager()                                              zCall( 0x0041BFD0 );
    virtual zCEventMessage* CreateMessage( int )                        zCall( 0x0041BF80 );
    virtual zCEventMessage* CreateOuMessage()                           zCall( 0x0041BF90 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* )                zCall( 0x0041C110 );
    virtual zCCSProps* CreateProperties()                               zCall( 0x0041DCF0 );
    virtual void RemoveCutscenePlayer( zCCSPlayer* )                    zCall( 0x0041C1D0 );
    virtual int LibIsLoaded()                                           zCall( 0x0041DCE0 );
    virtual zCCSBlock* LibGet( int )                                    zCall( 0x0041D900 );
    virtual zCCSBlock* LibGetFirst()                                    zCall( 0x0041D7A0 );
    virtual zCCSBlock* LibGetFirst( int& )                              zCall( 0x0041D840 );
    virtual zCCSBlock* LibGetNext()                                     zCall( 0x0041D7F0 );
    virtual zCCSBlock* LibGetNext( int& )                               zCall( 0x0041D8A0 );
    virtual int LibAddOU( zCCSBlock* )                                  zCall( 0x0041D930 );
    virtual void LibDelOU( int )                                        zCall( 0x0041D950 );
    virtual void LibNullOU( int )                                       zCall( 0x0041D970 );
    virtual void LibLoad( int )                                         zCall( 0x0041D290 );
    virtual void LibStore( int )                                        zCall( 0x0041D990 );
    virtual int LibValidateOU( int )                                    zCall( 0x0041DC80 );
    virtual int LibValidateOU( zSTRING& )                               zCall( 0x0041DCB0 );
    virtual zSTRING LibGetSvmModuleName( int )                          zCall( 0x0041B5F0 );
    virtual int LibIsSvmModuleRunning( int )                            zCall( 0x0041B900 );
    virtual int LibSvmModuleStart( int )                                zCall( 0x0041BA90 );
    virtual int LibSvmModuleStop( int )                                 zCall( 0x0041BC30 );
    virtual void InsertPlayerInList( zCCSPlayer* )                      zCall( 0x0041C1E0 );
    virtual void RemovePlayerFromList( zCCSPlayer* )                    zCall( 0x0041C2E0 );
    virtual void LibCheckLoaded( int )                                  zCall( 0x0041D780 );
    virtual zCCSPoolItem* PoolFindItem( zSTRING& )                      zCall( 0x0041C920 );
    virtual void PoolInsertItem( zCCSPoolItem* )                        zCall( 0x0041C830 );

    // user API
    #include "zCCSManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_MANAGER_H__VER1__