// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_MANAGER_H__VER3__
#define __ZCCS_MANAGER_H__VER3__

#include "zCCsProps.h"

namespace Gothic_II_Addon {
  const int zLIB_STORE_ASCII = 1;
  const int zLIB_STORE_BIN   = 2;
  const int zLIB_LOAD_ASCII  = 1;
  const int zLIB_LOAD_BIN    = 2;

  // sizeof 70h
  class zCCSManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSManager )

    zCArray<zSTRING> libSvmModuleList; // sizeof 0Ch    offset 24h
    zCCutscene* iteration;             // sizeof 04h    offset 30h
    zCCSBlockBase* iter;               // sizeof 04h    offset 34h
    int iterA;                         // sizeof 04h    offset 38h
    int iterB;                         // sizeof 04h    offset 3Ch
    zCArray<zCCSPoolItem*> csPool;     // sizeof 0Ch    offset 40h
    zCArray<zSTRING> commandStrings;   // sizeof 0Ch    offset 4Ch
    zCArray<zCCSPlayer*>csPlayerList;  // sizeof 0Ch    offset 58h
    zCCSLib* src_lib;                  // sizeof 04h    offset 64h
    zCCSLib* library;                  // sizeof 04h    offset 68h
    int iterator;                      // sizeof 04h    offset 6Ch

    void zCCSManager_OnInit()                                          zCall( 0x0041A370 );
    zCCSManager()                                                      zInit( zCCSManager_OnInit() );
    zCCSCutsceneContext* InitiateCSwithContext( zCCSCutsceneContext* ) zCall( 0x0041A800 );
    zCCSCutsceneContext* InitiateOUwithContext( zCCSCutsceneContext* ) zCall( 0x0041A950 );
    zCCSCutsceneContext* CreateNewCutscene( zSTRING& )                 zCall( 0x0041A980 );
    zCCSCutsceneContext* CreateNewOutputUnit( int )                    zCall( 0x0041AAC0 );
    int IsDeactivated( zSTRING& )                                      zCall( 0x0041AB50 );
    void PoolCountStart( zSTRING& )                                    zCall( 0x0041AB70 );
    void PoolCountStop( zSTRING& )                                     zCall( 0x0041AB90 );
    int PoolHasFlags( zSTRING&, int )                                  zCall( 0x0041ABB0 );
    void PoolClrFlags( zSTRING&, int )                                 zCall( 0x0041ABE0 );
    void PoolSetFlags( zSTRING&, int )                                 zCall( 0x0041AC00 );
    int PoolNumPlayed( zSTRING& )                                      zCall( 0x0041AC20 );
    int PoolAllowedToStart( zSTRING& )                                 zCall( 0x0041AC40 );
    void PoolResetAll()                                                zCall( 0x0041AEA0 );
    void PoolResetByHour()                                             zCall( 0x0041AED0 );
    void PoolResetByDay()                                              zCall( 0x0041AF10 );
    void AddCommand( zSTRING& )                                        zCall( 0x0041AF50 );
    int GetNumOfShortCom()                                             zCall( 0x0041B0C0 );
    zSTRING GetShortCom( int )                                         zCall( 0x0041B0D0 );
    void LibForceToLoad()                                              zCall( 0x0041C400 );
    static zCObject* _CreateNewInstance()                              zCall( 0x00419B40 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x0041A470 );
    virtual void Archive( zCArchiver& )                                zCall( 0x0041B250 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x0041B4A0 );
    virtual ~zCCSManager()                                             zCall( 0x0041A4D0 );
    virtual zCEventMessage* CreateMessage( int )                       zCall( 0x0041A480 );
    virtual zCEventMessage* CreateOuMessage()                          zCall( 0x0041A490 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* )               zCall( 0x0041A610 );
    virtual zCCSProps* CreateProperties()                              zCall( 0x0041C420 );
    virtual void RemoveCutscenePlayer( zCCSPlayer* )                   zCall( 0x0041A6B0 );
    virtual int LibIsLoaded()                                          zCall( 0x0041C410 );
    virtual zCCSBlock* LibGet( int )                                   zCall( 0x0041BF20 );
    virtual zCCSBlock* LibGetFirst()                                   zCall( 0x0041BDA0 );
    virtual zCCSBlock* LibGetFirst( int& )                             zCall( 0x0041BE50 );
    virtual zCCSBlock* LibGetNext()                                    zCall( 0x0041BE00 );
    virtual zCCSBlock* LibGetNext( int& )                              zCall( 0x0041BEC0 );
    virtual int LibAddOU( zCCSBlock* )                                 zCall( 0x0041BF50 );
    virtual void LibDelOU( int )                                       zCall( 0x0041BF70 );
    virtual void LibNullOU( int )                                      zCall( 0x0041BF90 );
    virtual void LibLoad( int )                                        zCall( 0x0041B700 );
    virtual void LibStore( int )                                       zCall( 0x0041BFB0 );
    virtual int LibValidateOU( int )                                   zCall( 0x0041C3B0 );
    virtual int LibValidateOU( zSTRING& )                              zCall( 0x0041C3E0 );
    virtual zSTRING LibGetSvmModuleName( int )                         zCall( 0x00419BC0 );
    virtual int LibIsSvmModuleRunning( int )                           zCall( 0x00419E80 );
    virtual int LibSvmModuleStart( int )                               zCall( 0x00419FC0 );
    virtual int LibSvmModuleStop( int )                                zCall( 0x0041A160 );
    virtual void InsertPlayerInList( zCCSPlayer* )                     zCall( 0x0041A6C0 );
    virtual void RemovePlayerFromList( zCCSPlayer* )                   zCall( 0x0041A7A0 );
    virtual void LibCheckLoaded( int )                                 zCall( 0x0041BD80 );
    virtual zCCSPoolItem* PoolFindItem( zSTRING& )                     zCall( 0x0041AD50 );
    virtual void PoolInsertItem( zCCSPoolItem* )                       zCall( 0x0041AC70 );

    // user API
    #include "zCCSManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCCS_MANAGER_H__VER3__