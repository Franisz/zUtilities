// Supported with union (c) 2018-2021 Union team

#ifndef __OWORLD_H__VER0__
#define __OWORLD_H__VER0__

#include "z3d.h"
#include "zWorld.h"
#include "oVob.h"

namespace Gothic_I_Classic {
  const float WLD_TICKSPERHOUR = 250000.0f;
  const float WLD_TICKSPERMIN  = WLD_TICKSPERHOUR / 60.0f;
  const float WLD_TICKSPERSEC  = WLD_TICKSPERMIN / 60.0f;
  const float WLD_TICKSPERDAY  = WLD_TICKSPERHOUR * 24.0f;

  // sizeof 6274h
  class oCWorld : public zCWorld {
  public:
    zCLASS_DECLARATION( oCWorld )

    zSTRING worldFilename;             // sizeof 14h    offset 6240h
    zSTRING worldName;                 // sizeof 14h    offset 6254h
    zCListSort<zCVob>* voblist;        // sizeof 04h    offset 6268h
    zCListSort<oCNpc>* voblist_npcs;   // sizeof 04h    offset 626Ch
    zCListSort<oCItem>* voblist_items; // sizeof 04h    offset 6270h

    void oCWorld_OnInit()                                                zCall( 0x006D5C80 );
    zSTRING GetWorldName()                                               zCall( 0x00428B00 );
    zSTRING GetWorldFilename()                                           zCall( 0x0063B680 );
    oCWorld()                                                            zInit( oCWorld_OnInit() );
    oCVob* CreateVob_novt( zTVobType, zSTRING const& )                   zCall( 0x006D6190 );
    void ClearNpcPerceptionVobLists()                                    zCall( 0x006D7630 );
    void __fastcall InsertInLists( zCVob* )                              zCall( 0x006D7670 );
    void __fastcall RemoveFromLists( zCVob* )                            zCall( 0x006D7750 );
    static zCObject* _CreateNewInstance()                                zCall( 0x006D5C10 );
    virtual zCClassDef* _GetClassDef() const                             zCall( 0x006D5EA0 );
    virtual void Archive( zCArchiver& )                                  zCall( 0x006D64D0 );
    virtual void Unarchive( zCArchiver& )                                zCall( 0x006D6700 );
    virtual ~oCWorld()                                                   zCall( 0x006D5F30 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )             zCall( 0x006D69B0 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )   zCall( 0x006D68C0 );
    virtual void DisposeWorld()                                          zCall( 0x006D7B10 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )       zCall( 0x006D6CA0 );
    virtual void RemoveVob( zCVob* )                                     zCall( 0x006D6EF0 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                   zCall( 0x006D7360 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )        zCall( 0x006D73B0 );
    virtual zCVob* SearchVobByName( zSTRING const& )                     zCall( 0x006D7400 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& ) zCall( 0x006D74B0 );
    virtual oCVob* CreateVob( zTVobType, int )                           zCall( 0x006D6340 );
    virtual void InsertVobInWorld( zCVob* )                              zCall( 0x006D7120 );
    virtual void EnableVob( zCVob*, zCVob* )                             zCall( 0x006D7130 );
    virtual void DisableVob( zCVob* )                                    zCall( 0x006D7250 );
    virtual void TraverseVobList( zCVobCallback&, void* )                zCall( 0x006D75F0 );
    virtual int DisposeVobs( zCTree<zCVob>* )                            zCall( 0x005F55F0 );
    virtual void DisposeVobs()                                           zCall( 0x006D7990 );

    // user API
    #include "oCWorld.inl"
  };

  // sizeof 08h
  class oCWorldTimer {
  public:
    float worldTime; // sizeof 04h    offset 00h
    int day;         // sizeof 04h    offset 04h

    void oCWorldTimer_OnInit()                  zCall( 0x006D7B20 );
    oCWorldTimer()                              zInit( oCWorldTimer_OnInit() );
    ~oCWorldTimer()                             zCall( 0x006D7B30 );
    void Timer()                                zCall( 0x006D7B40 );
    int GetDay()                                zCall( 0x006D7B90 );
    void SetDay( int )                          zCall( 0x006D7BA0 );
    void GetTime( int&, int& )                  zCall( 0x006D7BB0 );
    void SetTime( int, int )                    zCall( 0x006D7C00 );
    float GetFullTime()                         zCall( 0x006D7C40 );
    void SetFullTime( float )                   zCall( 0x006D7C50 );
    zSTRING GetTimeString()                     zCall( 0x006D7C80 );
    int IsLater( int, int )                     zCall( 0x006D7E60 );
    int IsLaterEqual( int, int )                zCall( 0x006D7EA0 );
    int IsTimeBetween( int, int, int, int )     zCall( 0x006D7EE0 );
    int GetPassedTime( float )                  zCall( 0x006D7F70 );
    float GetSkyTime()                          zCall( 0x006D7F90 );
    int IsDay()                                 zCall( 0x006D7FD0 );
    int IsNight()                               zCall( 0x006D8050 );
    static void AddTime( int&, int&, int, int ) zCall( 0x006D80E0 );

    // user API
    #include "oCWorldTimer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OWORLD_H__VER0__