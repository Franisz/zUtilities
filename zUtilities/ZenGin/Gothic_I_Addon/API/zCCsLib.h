// Supported with union (c) 2018 Union team

#ifndef __ZCCS_LIB_H__VER1__
#define __ZCCS_LIB_H__VER1__

#include "zCCsCutscene.h"

namespace Gothic_I_Addon {

  class zCCSLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSLib )

    int loaded;
    int wasChanged;
    zCArraySort<zCCSBlock*> ouList;
    zCCSBlock* searchBlock;

    void zCCSLib_OnInit()                                               zCall( 0x0041ACC0 );
    zCCSLib()                                                           zInit( zCCSLib_OnInit() );
    void DeleteLib()                                                    zCall( 0x0041AEC0 );
    void RemoveFromLib( int, int )                                      zCall( 0x0041AF30 );
    int ValidateToken( zSTRING& )                                       zCall( 0x0041AFB0 );
    int IsLoaded()                                                      zCall( 0x0041B040 );
    int WasChanged()                                                    zCall( 0x0041B050 );
    int NextFree()                                                      zCall( 0x0041B060 );
    int Add( zCCSBlock* )                                               zCall( 0x0041B070 );
    void Change()                                                       zCall( 0x0041B130 );
    zCCSBlock* GetOU( int )                                             zCall( 0x0041B140 );
    void CompactLib()                                                   zCall( 0x0041B150 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0041A3A0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0041A510 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0041A520 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0041A700 );
    virtual ~zCCSLib()                                                  zCall( 0x0041ADE0 );

    // user API
    #include "zCCSLib.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_LIB_H__VER1__