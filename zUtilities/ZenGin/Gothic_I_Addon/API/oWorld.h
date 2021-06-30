// Supported with union (c) 2018 Union team

#ifndef __OWORLD_H__VER1__
#define __OWORLD_H__VER1__

#include "z3d.h"
#include "zWorld.h"
#include "oVob.h"

namespace Gothic_I_Addon {
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

    void oCWorld_OnInit()                                                zCall( 0x0070D630 );
    zSTRING GetWorldName()                                               zCall( 0x0042B950 );
    zSTRING GetWorldFilename()                                           zCall( 0x006620A0 );
    oCWorld()                                                            zInit( oCWorld_OnInit() );
    oCVob* CreateVob_novt( zTVobType, zSTRING const& )                   zCall( 0x0070DB60 );
    void ClearNpcPerceptionVobLists()                                    zCall( 0x0070F180 );
    void __fastcall InsertInLists( zCVob* )                              zCall( 0x0070F1C0 );
    void __fastcall RemoveFromLists( zCVob* )                            zCall( 0x0070F2B0 );
    static zCObject* _CreateNewInstance()                                zCall( 0x0070D5C0 );
    virtual zCClassDef* _GetClassDef() const                             zCall( 0x0070D850 );
    virtual void Archive( zCArchiver& )                                  zCall( 0x0070DEE0 );
    virtual void Unarchive( zCArchiver& )                                zCall( 0x0070E120 );
    virtual ~oCWorld()                                                   zCall( 0x0070D8E0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )             zCall( 0x0070E400 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )   zCall( 0x0070E300 );
    virtual void DisposeWorld()                                          zCall( 0x0070F690 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )       zCall( 0x0070E740 );
    virtual void RemoveVob( zCVob* )                                     zCall( 0x0070E9D0 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                   zCall( 0x0070EEB0 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )        zCall( 0x0070EF00 );
    virtual zCVob* SearchVobByName( zSTRING const& )                     zCall( 0x0070EF50 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& ) zCall( 0x0070F000 );
    virtual oCVob* CreateVob( zTVobType, int )                           zCall( 0x0070DD30 );
    virtual void InsertVobInWorld( zCVob* )                              zCall( 0x0070EC40 );
    virtual void EnableVob( zCVob*, zCVob* )                             zCall( 0x0070EC50 );
    virtual void DisableVob( zCVob* )                                    zCall( 0x0070ED90 );
    virtual void TraverseVobList( zCVobCallback&, void* )                zCall( 0x0070F140 );
    virtual int DisposeVobs( zCTree<zCVob>* )                            zCall( 0x00616570 );
    virtual void DisposeVobs()                                           zCall( 0x0070F520 );

    // user API
    #include "oCWorld.inl"
  };

  class oCWorldTimer {
  public:
    float worldTime;
    int day;

    void oCWorldTimer_OnInit()                  zCall( 0x0070F6B0 );
    oCWorldTimer()                              zInit( oCWorldTimer_OnInit() );
    ~oCWorldTimer()                             zCall( 0x0070F6C0 );
    void Timer()                                zCall( 0x0070F6D0 );
    int GetDay()                                zCall( 0x0070F720 );
    void SetDay( int )                          zCall( 0x0070F730 );
    void GetTime( int&, int& )                  zCall( 0x0070F740 );
    void SetTime( int, int )                    zCall( 0x0070F790 );
    float GetFullTime()                         zCall( 0x0070F7D0 );
    void SetFullTime( float )                   zCall( 0x0070F7E0 );
    zSTRING GetTimeString()                     zCall( 0x0070F810 );
    int IsLater( int, int )                     zCall( 0x0070FA20 );
    int IsLaterEqual( int, int )                zCall( 0x0070FA60 );
    int IsTimeBetween( int, int, int, int )     zCall( 0x0070FAA0 );
    int GetPassedTime( float )                  zCall( 0x0070FB30 );
    float GetSkyTime()                          zCall( 0x0070FB50 );
    int IsDay()                                 zCall( 0x0070FB90 );
    int IsNight()                               zCall( 0x0070FC10 );
    static void AddTime( int&, int&, int, int ) zCall( 0x0070FCA0 );

    // user API
    #include "oCWorldTimer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OWORLD_H__VER1__