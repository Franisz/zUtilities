// Supported with union (c) 2018 Union team

#ifndef __OWORLD_H__VER2__
#define __OWORLD_H__VER2__

#include "z3d.h"
#include "oVob.h"

namespace Gothic_II_Classic {
  const float WLD_TICKSPERHOUR = 250000.0f;
  const float WLD_TICKSPERMIN  = WLD_TICKSPERHOUR / 60.0f;
  const float WLD_TICKSPERSEC  = WLD_TICKSPERMIN / 60.0f;
  const float WLD_TICKSPERDAY  = WLD_TICKSPERHOUR * 24.0f;

  class oCWorld : public zCWorld {
  public:
    zCLASS_DECLARATION( oCWorld )

    zSTRING worldFilename;
    zSTRING worldName;
    zCListSort<zCVob>* voblist;
    zCListSort<oCNpc>* voblist_npcs;
    zCListSort<oCItem>* voblist_items;

    void oCWorld_OnInit()                                                zCall( 0x0071F340 );
    zSTRING GetWorldName()                                               zCall( 0x0042A390 );
    zSTRING GetWorldFilename()                                           zCall( 0x00668ED0 );
    oCWorld()                                                            zInit( oCWorld_OnInit() );
    oCVob* CreateVob_novt( zTVobType, zSTRING const& )                   zCall( 0x0071F800 );
    void ClearNpcPerceptionVobLists()                                    zCall( 0x00720E30 );
    void __fastcall InsertInLists( zCVob* )                              zCall( 0x00720E70 );
    void __fastcall RemoveFromLists( zCVob* )                            zCall( 0x00720F50 );
    static zCObject* _CreateNewInstance()                                zCall( 0x0071F2E0 );
    virtual zCClassDef* _GetClassDef() const                             zCall( 0x0071F500 );
    virtual void Archive( zCArchiver& )                                  zCall( 0x0071FBD0 );
    virtual void Unarchive( zCArchiver& )                                zCall( 0x0071FE20 );
    virtual ~oCWorld()                                                   zCall( 0x0071F5A0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )             zCall( 0x00720100 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )   zCall( 0x00720010 );
    virtual void DisposeWorld()                                          zCall( 0x00721310 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )       zCall( 0x007203F0 );
    virtual void RemoveVob( zCVob* )                                     zCall( 0x00720680 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                   zCall( 0x00720B30 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )        zCall( 0x00720B80 );
    virtual zCVob* SearchVobByName( zSTRING const& )                     zCall( 0x00720BD0 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& ) zCall( 0x00720C80 );
    virtual oCVob* CreateVob( zTVobType, int )                           zCall( 0x0071F9B0 );
    virtual void InsertVobInWorld( zCVob* )                              zCall( 0x007208F0 );
    virtual void EnableVob( zCVob*, zCVob* )                             zCall( 0x00720900 );
    virtual void DisableVob( zCVob* )                                    zCall( 0x00720A20 );
    virtual void TraverseVobList( zCVobCallback&, void* )                zCall( 0x00720DF0 );
    virtual int DisposeVobs( zCTree<zCVob>* )                            zCall( 0x0061C1D0 );
    virtual void DisposeVobs()                                           zCall( 0x00721190 );

    // user API
    #include "oCWorld.inl"
  };

  class oCWorldTimer {
  public:
    float worldTime;
    int day;

    void oCWorldTimer_OnInit()                  zCall( 0x00721320 );
    oCWorldTimer()                              zInit( oCWorldTimer_OnInit() );
    ~oCWorldTimer()                             zCall( 0x00721330 );
    void Timer()                                zCall( 0x00721340 );
    int GetDay()                                zCall( 0x00721390 );
    void SetDay( int )                          zCall( 0x007213A0 );
    void GetTime( int&, int& )                  zCall( 0x007213B0 );
    void SetTime( int, int )                    zCall( 0x00721400 );
    float GetFullTime()                         zCall( 0x00721440 );
    void SetFullTime( float )                   zCall( 0x00721450 );
    zSTRING GetTimeString()                     zCall( 0x00721480 );
    int IsLater( int, int )                     zCall( 0x007216D0 );
    int IsLaterEqual( int, int )                zCall( 0x00721710 );
    int IsTimeBetween( int, int, int, int )     zCall( 0x00721750 );
    int GetPassedTime( float )                  zCall( 0x007217E0 );
    float GetSkyTime()                          zCall( 0x00721800 );
    int IsDay()                                 zCall( 0x00721840 );
    int IsNight()                               zCall( 0x007218C0 );
    static void AddTime( int&, int&, int, int ) zCall( 0x00721950 );

    // user API
    #include "oCWorldTimer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OWORLD_H__VER2__