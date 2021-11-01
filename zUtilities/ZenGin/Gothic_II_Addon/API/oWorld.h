// Supported with union (c) 2018-2021 Union team

#ifndef __OWORLD_H__VER3__
#define __OWORLD_H__VER3__

#include "z3d.h"
#include "oVob.h"

namespace Gothic_II_Addon {
  const float WLD_TICKSPERHOUR = 250000.0f;
  const float WLD_TICKSPERMIN  = WLD_TICKSPERHOUR / 60.0f;
  const float WLD_TICKSPERSEC  = WLD_TICKSPERMIN / 60.0f;
  const float WLD_TICKSPERDAY  = WLD_TICKSPERHOUR * 24.0f;

  // sizeof 628Ch
  class oCWorld : public zCWorld {
  public:
    zCLASS_DECLARATION( oCWorld )

    zSTRING worldFilename;             // sizeof 14h    offset 6258h
    zSTRING worldName;                 // sizeof 14h    offset 626Ch
    zCListSort<zCVob>* voblist;        // sizeof 04h    offset 6280h
    zCListSort<oCNpc>* voblist_npcs;   // sizeof 04h    offset 6284h
    zCListSort<oCItem>* voblist_items; // sizeof 04h    offset 6288h

    void oCWorld_OnInit()                                                zCall( 0x0077ED80 );
    zSTRING GetWorldName()                                               zCall( 0x0042A6B0 );
    zSTRING GetWorldFilename()                                           zCall( 0x0068DE60 );
    oCWorld()                                                            zInit( oCWorld_OnInit() );
    oCVob* CreateVob_novt( zTVobType, zSTRING const& )                   zCall( 0x0077F240 );
    void ClearNpcPerceptionVobLists()                                    zCall( 0x00780870 );
    void __fastcall InsertInLists( zCVob* )                              zCall( 0x007808B0 );
    void __fastcall RemoveFromLists( zCVob* )                            zCall( 0x00780990 );
    static zCObject* _CreateNewInstance()                                zCall( 0x0077ED20 );
    virtual zCClassDef* _GetClassDef() const                             zCall( 0x0077EF40 );
    virtual void Archive( zCArchiver& )                                  zCall( 0x0077F610 );
    virtual void Unarchive( zCArchiver& )                                zCall( 0x0077F860 );
    virtual ~oCWorld()                                                   zCall( 0x0077EFE0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )             zCall( 0x0077FB40 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )   zCall( 0x0077FA50 );
    virtual void DisposeWorld()                                          zCall( 0x00780D50 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )       zCall( 0x0077FE30 );
    virtual void RemoveVob( zCVob* )                                     zCall( 0x007800C0 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                   zCall( 0x00780570 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )        zCall( 0x007805C0 );
    virtual zCVob* SearchVobByName( zSTRING const& )                     zCall( 0x00780610 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& ) zCall( 0x007806C0 );
    virtual oCVob* CreateVob( zTVobType, int )                           zCall( 0x0077F3F0 );
    virtual void InsertVobInWorld( zCVob* )                              zCall( 0x00780330 );
    virtual void EnableVob( zCVob*, zCVob* )                             zCall( 0x00780340 );
    virtual void DisableVob( zCVob* )                                    zCall( 0x00780460 );
    virtual void TraverseVobList( zCVobCallback&, void* )                zCall( 0x00780830 );
    virtual int DisposeVobs( zCTree<zCVob>* )                            zCall( 0x00623960 );
    virtual void DisposeVobs()                                           zCall( 0x00780BD0 );

    // user API
    #include "oCWorld.inl"
  };

  // sizeof 08h
  class oCWorldTimer {
  public:
    float worldTime; // sizeof 04h    offset 00h
    int day;         // sizeof 04h    offset 04h

    void oCWorldTimer_OnInit()                  zCall( 0x00780D60 );
    oCWorldTimer()                              zInit( oCWorldTimer_OnInit() );
    ~oCWorldTimer()                             zCall( 0x00780D70 );
    void Timer()                                zCall( 0x00780D80 );
    int GetDay()                                zCall( 0x00780DD0 );
    void SetDay( int )                          zCall( 0x00780DE0 );
    void GetTime( int&, int& )                  zCall( 0x00780DF0 );
    void SetTime( int, int )                    zCall( 0x00780E40 );
    float GetFullTime()                         zCall( 0x00780E80 );
    void SetFullTime( float )                   zCall( 0x00780E90 );
    zSTRING GetTimeString()                     zCall( 0x00780EC0 );
    int IsLater( int, int )                     zCall( 0x00781110 );
    int IsLaterEqual( int, int )                zCall( 0x00781150 );
    int IsTimeBetween( int, int, int, int )     zCall( 0x00781190 );
    int GetPassedTime( float )                  zCall( 0x00781220 );
    float GetSkyTime()                          zCall( 0x00781240 );
    int IsDay()                                 zCall( 0x00781280 );
    int IsNight()                               zCall( 0x00781300 );
    static void AddTime( int&, int&, int, int ) zCall( 0x00781390 );

    // user API
    #include "oCWorldTimer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OWORLD_H__VER3__