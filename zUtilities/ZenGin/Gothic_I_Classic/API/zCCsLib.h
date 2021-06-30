// Supported with union (c) 2018 Union team

#ifndef __ZCCS_LIB_H__VER0__
#define __ZCCS_LIB_H__VER0__

#include "zCCsCutscene.h"

namespace Gothic_I_Classic {

  class zCCSLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSLib )

    int loaded;
    int wasChanged;
    zCArraySort<zCCSBlock*> ouList;
    zCCSBlock* searchBlock;

    void zCCSLib_OnInit()                                               zCall( 0x00418DC0 );
    zCCSLib()                                                           zInit( zCCSLib_OnInit() );
    void DeleteLib()                                                    zCall( 0x00418FC0 );
    void RemoveFromLib( int, int )                                      zCall( 0x00419030 );
    int ValidateToken( zSTRING& )                                       zCall( 0x004190A0 );
    int IsLoaded()                                                      zCall( 0x00419120 );
    int WasChanged()                                                    zCall( 0x00419130 );
    int NextFree()                                                      zCall( 0x00419140 );
    int Add( zCCSBlock* )                                               zCall( 0x00419150 );
    void Change()                                                       zCall( 0x00419210 );
    zCCSBlock* GetOU( int )                                             zCall( 0x00419220 );
    void CompactLib()                                                   zCall( 0x00419230 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00418530 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004186A0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004186B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00418860 );
    virtual ~zCCSLib()                                                  zCall( 0x00418EE0 );

    // user API
    #include "zCCSLib.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_LIB_H__VER0__