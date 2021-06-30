// Supported with union (c) 2018 Union team

#ifndef __ZWAYNET_H__VER3__
#define __ZWAYNET_H__VER3__

#include "z3d.h"
#include "zVob.h"

namespace Gothic_II_Addon {

  enum {
    zWAY_JUMP  = 1,
    zWAY_CLIMB = 2,
    zWAY_SWIM  = 4,
    zWAY_DIVE  = 8,
    zWAY_FREE  = 16
  };

  class zCVobWaypoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobWaypoint )

    void zCVobWaypoint_OnInit()              zCall( 0x007ACBC0 );
    zCVobWaypoint()                          zInit( zCVobWaypoint_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x007B33B0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x007ACBE0 );
    virtual ~zCVobWaypoint()                 zCall( 0x007ACC20 );

    // user API
    #include "zCVobWaypoint.inl"
  };

  class zCWaypoint : public zCObject {
  public:
    zCLASS_DECLARATION( zCWaypoint )

    int routeCtr;
    int curCost;
    int estCost;
    int score;
    int curList;
    zCWay* parent;
    int waterDepth;
    int underWater;
    zVEC3 pos;
    zVEC3 dir;
    zSTRING name;
    zCVobWaypoint* wpvob;
    zCList<zCWay> wayList;

    void zCWaypoint_OnInit()                 zCall( 0x007AF770 );
    zCWaypoint()                             zInit( zCWaypoint_OnInit() );
    void Init( zVEC3& )                      zCall( 0x007AF8A0 );
    void Init( float, float, float )         zCall( 0x007AF900 );
    void Init( zCVobWaypoint* )              zCall( 0x007AF970 );
    void Free()                              zCall( 0x007AFA10 );
    zVEC3& GetPositionWorld()                zCall( 0x007AFB30 );
    void UpdatePositionWorld()               zCall( 0x007AFB40 );
    void SetName( zSTRING& )                 zCall( 0x007AFBB0 );
    zSTRING const& GetName()                 zCall( 0x007AFD10 );
    zCVobWaypoint* GetVob()                  zCall( 0x007AFE70 );
    void CalcProperties( zCWorld* )          zCall( 0x007AFE80 );
    void CorrectHeight( zCWorld* )           zCall( 0x007B00A0 );
    void InsertWay( zCWay* )                 zCall( 0x007B0140 );
    void RemoveWay( zCWay* )                 zCall( 0x007B0150 );
    zCWay* HasWay( zCWaypoint* )             zCall( 0x007B01B0 );
    int GetNumberOfWays()                    zCall( 0x007B01E0 );
    zCList<zCWay>& GetWayList()              zCall( 0x007B0200 );
    void SetWaypointVob( zCVobWaypoint* )    zCall( 0x007B0210 );
    void Draw()                              zCall( 0x007B0250 );
    static zCObject* _CreateNewInstance()    zCall( 0x007B3B70 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0077DF10 );
    virtual void Archive( zCArchiver& )      zCall( 0x007B0260 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x007B02C0 );
    virtual ~zCWaypoint()                    zCall( 0x007AFA80 );
    virtual int CanBeUsed( zCVob const* )    zCall( 0x007AF860 );

    // user API
    #include "zCWaypoint.inl"
  };

  class zCWay {
  public:
    int cost;
    int usedCtr;
    float chasmDepth;
    int chasm;
    int jump;
    zCWaypoint* left;
    zCWaypoint* right;

    void zCWay_OnInit()                           zCall( 0x007AE830 );
    void zCWay_OnInit( zCWaypoint*, zCWaypoint* ) zCall( 0x007AE890 );
    zCWay()                                       zInit( zCWay_OnInit() );
    zCWay( zCWaypoint* a0, zCWaypoint* a1 )       zInit( zCWay_OnInit( a0, a1 ));
    void Free()                                   zCall( 0x007AE9E0 );
    zCWaypoint* GetGoalWaypoint( zCWaypoint* )    zCall( 0x007AEA90 );
    void EstimateCost()                           zCall( 0x007AEAA0 );
    float GetLength()                             zCall( 0x007AEB10 );
    float GetJumpDistance()                       zCall( 0x007AEBC0 );
    zVEC3 GetDistancePos( float, zCWaypoint* )    zCall( 0x007AEC80 );
    void Draw( zCCamera* )                        zCall( 0x007AED90 );
    zVEC3 GetFloor( zCWorld*, zVEC3 const& )      zCall( 0x007AF270 );
    virtual ~zCWay()                              zCall( 0x007AEA80 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x007AE940 );
    virtual void CalcProperties( zCWorld* )       zCall( 0x007AF310 );
    virtual float GetChasm()                      zCall( 0x007AF600 );
    virtual int CanJump()                         zCall( 0x007AF610 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x007AED80 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x007AE850 );

    // user API
    #include "zCWay.inl"
  };

  class zCWayNet : public zCObject {
  public:
    zCLASS_DECLARATION( zCWayNet )

    enum {
      WAY_LIST_NONE,
      WAY_LIST_OPEN,
      WAY_LIST_CLOSED
    };

    zCWorld* world;
    zCListSort<zCWaypoint> wplist;
    zCList<zCWay> waylist;
    zCListSort<zCWaypoint> openList;
    int routeCtr;

    void zCWayNet_OnInit()                                             zCall( 0x007ACC30 );
    void zCWayNet_OnInit( zCWorld* )                                   zCall( 0x007ACD10 );
    zCWayNet()                                                         zInit( zCWayNet_OnInit() );
    zCWayNet( zCWorld* a0 )                                            zInit( zCWayNet_OnInit( a0 ));
    zCWaypoint* HasWaypoint( float, float, float )                     zCall( 0x007ACF00 );
    int HasWaypoint( zCWaypoint* )                                     zCall( 0x007ACF70 );
    zCWaypoint* HasWaypoint( zVEC3& )                                  zCall( 0x007ACFA0 );
    zCWaypoint* InsertWaypoint( float, float, float )                  zCall( 0x007ACFF0 );
    void InsertWaypoint( zCWaypoint* )                                 zCall( 0x007AD100 );
    void InsertWaypoint( zCWaypoint*, zCWaypoint*, zCWaypoint* )       zCall( 0x007AD130 );
    void DeleteWaypoint( zCWaypoint* )                                 zCall( 0x007AD2B0 );
    void CreateWay( zCWaypoint*, zCWaypoint* )                         zCall( 0x007AD420 );
    void DeleteWay( zCWaypoint*, zCWaypoint* )                         zCall( 0x007AD4F0 );
    zCWaypoint* __fastcall GetNearestWaypoint( zVEC3 const& )          zCall( 0x007AD660 );
    zCWaypoint* GetSecNearestWaypoint( zVEC3& )                        zCall( 0x007AD6F0 );
    void CorrectHeight()                                               zCall( 0x007AD7B0 );
    void Draw( zCCamera* )                                             zCall( 0x007AD870 );
    void UpdateVobDependencies()                                       zCall( 0x007AD8A0 );
    void ClearVobDependencies()                                        zCall( 0x007ADAF0 );
    void CreateVobDependencies( zCWorld* )                             zCall( 0x007ADCF0 );
    zSTRING MergeWaypoints()                                           zCall( 0x007ADF70 );
    zSTRING CheckConsistency( int )                                    zCall( 0x007AE230 );
    void AddWays( zCWaypoint*, zCWaypoint* )                           zCall( 0x007AE730 );
    zCWaypoint* __fastcall GetWaypoint( zSTRING const& ) const         zCall( 0x007B0330 );
    zCWaypoint* SearchWaypoint( zCVobWaypoint* )                       zCall( 0x007B04A0 );
    zCRoute* FindRoute( zVEC3 const&, zVEC3 const&, zCVob const* )     zCall( 0x007B04D0 );
    zCRoute* FindRoute( zVEC3 const&, zCWaypoint*, zCVob const* )      zCall( 0x007B0560 );
    zCRoute* FindRoute( zVEC3 const&, zSTRING const&, zCVob const* )   zCall( 0x007B05D0 );
    zCRoute* FindRoute( zCWaypoint*, zCWaypoint*, zCVob const* )       zCall( 0x007B0640 );
    zCRoute* FindRoute( zSTRING const&, zSTRING const&, zCVob const* ) zCall( 0x007B0680 );
    void InsertInOpen( zCWaypoint* )                                   zCall( 0x007B0700 );
    int IsInOpen( zCWaypoint* )                                        zCall( 0x007B0730 );
    void InsertInClosed( zCWaypoint* )                                 zCall( 0x007B0750 );
    void RemoveFromClosed( zCWaypoint* )                               zCall( 0x007B0770 );
    int IsInClosed( zCWaypoint* )                                      zCall( 0x007B0780 );
    int IsInAnyList( zCWaypoint* )                                     zCall( 0x007B07A0 );
    int EstimateCost( zCWaypoint*, zCWaypoint* )                       zCall( 0x007B07D0 );
    zCRoute* CreateRoute( zCWaypoint* )                                zCall( 0x007B0830 );
    int AStar( zCWaypoint*, zCWaypoint*, zCVob const* )                zCall( 0x007B08D0 );
    void GetWPList( zCList<zVEC3>&, zVEC3&, float, float )             zCall( 0x007B0B50 );
    void CreateWPVobList( zCList<zCVobWaypoint>&, zCTree<zCVob>* )     zCall( 0x007B0CB0 );
    void RemoveUnusedWPVobs()                                          zCall( 0x007B0CF0 );
    void ArchiveOldFormat( zCArchiver& )                               zCall( 0x007B0E40 );
    void UnarchiveOldFormat( zCArchiver& )                             zCall( 0x007B16F0 );
    void CalcProperties( zCWorld* )                                    zCall( 0x007B2820 );
    static int SortWpList( zCWaypoint*, zCWaypoint* )                  zCall( 0x007AF620 );
    static int SortOpenList( zCWaypoint*, zCWaypoint* )                zCall( 0x007B06E0 );
    static zCObject* _CreateNewInstance()                              zCall( 0x007B3DB0 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x007ACCD0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x007B11D0 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x007B2200 );
    virtual ~zCWayNet()                                                zCall( 0x007ACDB0 );

    // user API
    #include "zCWayNet.inl"
  };

  class zCRoute {
  public:
    zCList<zCWay> wayList;
    zCWaypoint* startwp;
    zCWaypoint* target;
    zCWay* way;
    zCList<zCWay>* waynode;

    void zCRoute_OnInit()                             zCall( 0x007B2860 );
    zCRoute()                                         zInit( zCRoute_OnInit() );
    void SetStart( zCWaypoint* )                      zCall( 0x007B28E0 );
    zCWaypoint* GetNextWP()                           zCall( 0x007B28F0 );
    zCWaypoint* GetTargetWP()                         zCall( 0x007B2960 );
    zCWay* GetCurrentWay()                            zCall( 0x007B2970 );
    zSTRING GetDesc()                                 zCall( 0x007B2980 );
    zSTRING GetRemainingDesc()                        zCall( 0x007B2B60 );
    int GetNumberOfWaypoints()                        zCall( 0x007B2D40 );
    int IsEmpty()                                     zCall( 0x007B2D60 );
    int IsLastTarget()                                zCall( 0x007B2D80 );
    int GetInterpolatedPosition( float, int, zVEC3& ) zCall( 0x007B2DA0 );
    virtual ~zCRoute()                                zCall( 0x007B28A0 );

    // user API
    #include "zCRoute.inl"
  };

  class zCVobSpot : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobSpot )

    float timerEnd;
    zCVob* inUseVob;

    void zCVobSpot_OnInit()                  zCall( 0x007B2FA0 );
    zCVobSpot()                              zInit( zCVobSpot_OnInit() );
    int IsAvailable( zCVob* )                zCall( 0x007B3020 );
    void MarkAsUsed( float, zCVob* )         zCall( 0x007B31A0 );
    static zCObject* _CreateNewInstance()    zCall( 0x007B3610 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x007B2FC0 );
    virtual ~zCVobSpot()                     zCall( 0x007B3000 );

    // user API
    #include "zCVobSpot.inl"
  };

  class zCVobStartpoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStartpoint )

    zCVobStartpoint() {}
    static zCObject* _CreateNewInstance()    zCall( 0x007B38B0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x007B3940 );
    virtual ~zCVobStartpoint()               zCall( 0x007B3980 );

    // user API
    #include "zCVobStartpoint.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZWAYNET_H__VER3__