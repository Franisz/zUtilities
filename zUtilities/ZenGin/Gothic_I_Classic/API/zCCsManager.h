// Supported with union (c) 2018 Union team

#ifndef __ZCCS_MANAGER_H__VER0__
#define __ZCCS_MANAGER_H__VER0__

#include "zCCsProps.h"

namespace Gothic_I_Classic {
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
    zCArray<zCCSPlayer*> csPlayerList;
    zCCSLib* src_lib;
    zCCSLib* library;
    int iterator;

    void zCCSManager_OnInit()                                           zCall( 0x00419E70 );
    zCCSManager()                                                       zInit( zCCSManager_OnInit() );
    zCCSCutsceneContext* InitiateCSwithContext( zCCSCutsceneContext* )  zCall( 0x0041A350 );
    zCCSCutsceneContext* InitiateOUwithContext( zCCSCutsceneContext* )  zCall( 0x0041A4C0 );
    zCCSCutsceneContext* CreateNewCutscene( zSTRING& )                  zCall( 0x0041A4F0 );
    zCCSCutsceneContext* CreateNewOutputUnit( int )                     zCall( 0x0041A660 );
    int IsDeactivated( zSTRING& )                                       zCall( 0x0041A710 );
    void PoolCountStart( zSTRING& )                                     zCall( 0x0041A730 );
    void PoolCountStop( zSTRING& )                                      zCall( 0x0041A750 );
    int PoolHasFlags( zSTRING&, int )                                   zCall( 0x0041A770 );
    void PoolClrFlags( zSTRING&, int )                                  zCall( 0x0041A7A0 );
    void PoolSetFlags( zSTRING&, int )                                  zCall( 0x0041A7C0 );
    int PoolNumPlayed( zSTRING& )                                       zCall( 0x0041A7E0 );
    int PoolAllowedToStart( zSTRING& )                                  zCall( 0x0041A800 );
    void PoolResetAll()                                                 zCall( 0x0041AA70 );
    void PoolResetByHour()                                              zCall( 0x0041AAA0 );
    void PoolResetByDay()                                               zCall( 0x0041AAE0 );
    void AddCommand( zSTRING& )                                         zCall( 0x0041AB20 );
    int GetNumOfShortCom()                                              zCall( 0x0041AC90 );
    zSTRING GetShortCom( int )                                          zCall( 0x0041ACA0 );
    void LibForceToLoad()                                               zCall( 0x0041BE70 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00419630 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00419F80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0041AE20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0041AFF0 );
    virtual ~zCCSManager()                                              zCall( 0x00419FE0 );
    virtual zCEventMessage* CreateMessage( int )                        zCall( 0x00419F90 );
    virtual zCEventMessage* CreateOuMessage()                           zCall( 0x00419FA0 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* )                zCall( 0x0041A120 );
    virtual zCCSProps* CreateProperties()                               zCall( 0x0041BE90 );
    virtual void RemoveCutscenePlayer( zCCSPlayer* )                    zCall( 0x0041A1E0 );
    virtual int LibIsLoaded()                                           zCall( 0x0041BE80 );
    virtual zCCSBlock* LibGet( int )                                    zCall( 0x0041BA30 );
    virtual zCCSBlock* LibGetFirst()                                    zCall( 0x0041B8B0 );
    virtual zCCSBlock* LibGetFirst( int& )                              zCall( 0x0041B960 );
    virtual zCCSBlock* LibGetNext()                                     zCall( 0x0041B910 );
    virtual zCCSBlock* LibGetNext( int& )                               zCall( 0x0041B9D0 );
    virtual int LibAddOU( zCCSBlock* )                                  zCall( 0x0041BA60 );
    virtual void LibDelOU( int )                                        zCall( 0x0041BA80 );
    virtual void LibNullOU( int )                                       zCall( 0x0041BAA0 );
    virtual void LibLoad( int )                                         zCall( 0x0041B270 );
    virtual void LibStore( int )                                        zCall( 0x0041BAC0 );
    virtual int LibValidateOU( int )                                    zCall( 0x0041BE20 );
    virtual int LibValidateOU( zSTRING& )                               zCall( 0x0041BE50 );
    virtual zSTRING LibGetSvmModuleName( int )                          zCall( 0x004196C0 );
    virtual int LibIsSvmModuleRunning( int )                            zCall( 0x00419980 );
    virtual int LibSvmModuleStart( int )                                zCall( 0x00419AC0 );
    virtual int LibSvmModuleStop( int )                                 zCall( 0x00419C60 );
    virtual void InsertPlayerInList( zCCSPlayer* )                      zCall( 0x0041A1F0 );
    virtual void RemovePlayerFromList( zCCSPlayer* )                    zCall( 0x0041A2F0 );
    virtual void LibCheckLoaded( int )                                  zCall( 0x0041B890 );
    virtual zCCSPoolItem* PoolFindItem( zSTRING& )                      zCall( 0x0041A920 );
    virtual void PoolInsertItem( zCCSPoolItem* )                        zCall( 0x0041A830 );

    // user API
    #include "zCCSManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_MANAGER_H__VER0__