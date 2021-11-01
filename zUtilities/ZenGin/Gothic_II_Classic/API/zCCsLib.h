// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_LIB_H__VER2__
#define __ZCCS_LIB_H__VER2__

#include "zCCsCutscene.h"

namespace Gothic_II_Classic {

  // sizeof 40h
  class zCCSLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSLib )

    int loaded;                     // sizeof 04h    offset 24h
    int wasChanged;                 // sizeof 04h    offset 28h
    zCArraySort<zCCSBlock*> ouList; // sizeof 10h    offset 2Ch
    zCCSBlock* searchBlock;         // sizeof 04h    offset 3Ch

    void zCCSLib_OnInit()                    zCall( 0x00419320 );
    zCCSLib()                                zInit( zCCSLib_OnInit() );
    void DeleteLib()                         zCall( 0x00419510 );
    void RemoveFromLib( int, int )           zCall( 0x00419580 );
    int ValidateToken( zSTRING& )            zCall( 0x004195F0 );
    int IsLoaded()                           zCall( 0x00419670 );
    int WasChanged()                         zCall( 0x00419680 );
    int NextFree()                           zCall( 0x00419690 );
    int Add( zCCSBlock* )                    zCall( 0x004196A0 );
    void Change()                            zCall( 0x00419750 );
    zCCSBlock* GetOU( int )                  zCall( 0x00419760 );
    void CompactLib()                        zCall( 0x00419770 );
    static zCObject* _CreateNewInstance()    zCall( 0x00418A00 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00418B40 );
    virtual void Archive( zCArchiver& )      zCall( 0x00418B50 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00418D80 );
    virtual ~zCCSLib()                       zCall( 0x00419430 );

    // user API
    #include "zCCSLib.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCCS_LIB_H__VER2__