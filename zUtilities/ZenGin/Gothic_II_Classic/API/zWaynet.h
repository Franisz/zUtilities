// Supported with union (c) 2018-2021 Union team

#ifndef __ZWAYNET_H__VER2__
#define __ZWAYNET_H__VER2__

#include "z3d.h"
#include "zVob.h"

namespace Gothic_II_Classic {

  enum {
    zWAY_JUMP  = 1,
    zWAY_CLIMB = 2,
    zWAY_SWIM  = 4,
    zWAY_DIVE  = 8,
    zWAY_FREE  = 16
  };

  // sizeof 120h
  class zCVobWaypoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobWaypoint )

    void zCVobWaypoint_OnInit()              zCall( 0x0074D0C0 );
    zCVobWaypoint()                          zInit( zCVobWaypoint_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x007538B0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0074D0E0 );
    virtual ~zCVobWaypoint()                 zCall( 0x0074D120 );

    // user API
    #include "zCVobWaypoint.inl"
  };

  // sizeof 7Ch
  class zCWaypoint : public zCObject {
  public:
    zCLASS_DECLARATION( zCWaypoint )

    int routeCtr;          // sizeof 04h    offset 24h
    int curCost;           // sizeof 04h    offset 28h
    int estCost;           // sizeof 04h    offset 2Ch
    int score;             // sizeof 04h    offset 30h
    int curList;           // sizeof 04h    offset 34h
    zCWay* parent;         // sizeof 04h    offset 38h
    int waterDepth;        // sizeof 04h    offset 3Ch
    int underWater;        // sizeof 04h    offset 40h
    zVEC3 pos;             // sizeof 0Ch    offset 44h
    zVEC3 dir;             // sizeof 0Ch    offset 50h
    zSTRING name;          // sizeof 14h    offset 5Ch
    zCVobWaypoint* wpvob;  // sizeof 04h    offset 70h
    zCList<zCWay> wayList; // sizeof 08h    offset 74h

    void zCWaypoint_OnInit()                 zCall( 0x0074FC70 );
    zCWaypoint()                             zInit( zCWaypoint_OnInit() );
    void Init( zVEC3& )                      zCall( 0x0074FDA0 );
    void Init( float, float, float )         zCall( 0x0074FE00 );
    void Init( zCVobWaypoint* )              zCall( 0x0074FE70 );
    void Free()                              zCall( 0x0074FF10 );
    zVEC3& GetPositionWorld()                zCall( 0x00750030 );
    void UpdatePositionWorld()               zCall( 0x00750040 );
    void SetName( zSTRING& )                 zCall( 0x007500B0 );
    zSTRING const& GetName()                 zCall( 0x00750210 );
    zCVobWaypoint* GetVob()                  zCall( 0x00750370 );
    void CalcProperties( zCWorld* )          zCall( 0x00750380 );
    void CorrectHeight( zCWorld* )           zCall( 0x007505A0 );
    void InsertWay( zCWay* )                 zCall( 0x00750640 );
    void RemoveWay( zCWay* )                 zCall( 0x00750650 );
    zCWay* HasWay( zCWaypoint* )             zCall( 0x007506B0 );
    int GetNumberOfWays()                    zCall( 0x007506E0 );
    zCList<zCWay>& GetWayList()              zCall( 0x00750700 );
    void SetWaypointVob( zCVobWaypoint* )    zCall( 0x00750710 );
    void Draw()                              zCall( 0x00750750 );
    static zCObject* _CreateNewInstance()    zCall( 0x00754070 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0071E4D0 );
    virtual void Archive( zCArchiver& )      zCall( 0x00750760 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x007507C0 );
    virtual ~zCWaypoint()                    zCall( 0x0074FF80 );
    virtual int CanBeUsed( zCVob const* )    zCall( 0x0074FD60 );

    // user API
    #include "zCWaypoint.inl"
  };

  // sizeof 20h
  class zCWay {
  public:
    int cost;          // sizeof 04h    offset 04h
    int usedCtr;       // sizeof 04h    offset 08h
    float chasmDepth;  // sizeof 04h    offset 0Ch
    int chasm;         // sizeof 04h    offset 10h
    int jump;          // sizeof 04h    offset 14h
    zCWaypoint* left;  // sizeof 04h    offset 18h
    zCWaypoint* right; // sizeof 04h    offset 1Ch

    void zCWay_OnInit()                           zCall( 0x0074ED30 );
    void zCWay_OnInit( zCWaypoint*, zCWaypoint* ) zCall( 0x0074ED90 );
    zCWay()                                       zInit( zCWay_OnInit() );
    zCWay( zCWaypoint* a0, zCWaypoint* a1 )       zInit( zCWay_OnInit( a0, a1 ));
    void Free()                                   zCall( 0x0074EEE0 );
    zCWaypoint* GetGoalWaypoint( zCWaypoint* )    zCall( 0x0074EF90 );
    void EstimateCost()                           zCall( 0x0074EFA0 );
    float GetLength()                             zCall( 0x0074F010 );
    float GetJumpDistance()                       zCall( 0x0074F0C0 );
    zVEC3 GetDistancePos( float, zCWaypoint* )    zCall( 0x0074F180 );
    void Draw( zCCamera* )                        zCall( 0x0074F290 );
    zVEC3 GetFloor( zCWorld*, zVEC3 const& )      zCall( 0x0074F770 );
    virtual ~zCWay()                              zCall( 0x0074EF80 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x0074EE40 );
    virtual void CalcProperties( zCWorld* )       zCall( 0x0074F810 );
    virtual float GetChasm()                      zCall( 0x0074FB00 );
    virtual int CanJump()                         zCall( 0x0074FB10 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x0074F280 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x0074ED50 );

    // user API
    #include "zCWay.inl"
  };

  // sizeof 4Ch
  class zCWayNet : public zCObject {
  public:
    zCLASS_DECLARATION( zCWayNet )

    enum {
      WAY_LIST_NONE,
      WAY_LIST_OPEN,
      WAY_LIST_CLOSED
    };

    zCWorld* world;                  // sizeof 04h    offset 24h
    zCListSort<zCWaypoint> wplist;   // sizeof 0Ch    offset 28h
    zCList<zCWay> waylist;           // sizeof 08h    offset 34h
    zCListSort<zCWaypoint> openList; // sizeof 0Ch    offset 3Ch
    int routeCtr;                    // sizeof 04h    offset 48h

    void zCWayNet_OnInit()                                             zCall( 0x0074D130 );
    void zCWayNet_OnInit( zCWorld* )                                   zCall( 0x0074D210 );
    zCWayNet()                                                         zInit( zCWayNet_OnInit() );
    zCWayNet( zCWorld* a0 )                                            zInit( zCWayNet_OnInit( a0 ));
    zCWaypoint* HasWaypoint( float, float, float )                     zCall( 0x0074D400 );
    int HasWaypoint( zCWaypoint* )                                     zCall( 0x0074D470 );
    zCWaypoint* HasWaypoint( zVEC3& )                                  zCall( 0x0074D4A0 );
    zCWaypoint* InsertWaypoint( float, float, float )                  zCall( 0x0074D4F0 );
    void InsertWaypoint( zCWaypoint* )                                 zCall( 0x0074D600 );
    void InsertWaypoint( zCWaypoint*, zCWaypoint*, zCWaypoint* )       zCall( 0x0074D630 );
    void DeleteWaypoint( zCWaypoint* )                                 zCall( 0x0074D7B0 );
    void CreateWay( zCWaypoint*, zCWaypoint* )                         zCall( 0x0074D920 );
    void DeleteWay( zCWaypoint*, zCWaypoint* )                         zCall( 0x0074D9F0 );
    zCWaypoint* __fastcall GetNearestWaypoint( zVEC3 const& )          zCall( 0x0074DB60 );
    zCWaypoint* GetSecNearestWaypoint( zVEC3& )                        zCall( 0x0074DBF0 );
    void CorrectHeight()                                               zCall( 0x0074DCB0 );
    void Draw( zCCamera* )                                             zCall( 0x0074DD70 );
    void UpdateVobDependencies()                                       zCall( 0x0074DDA0 );
    void ClearVobDependencies()                                        zCall( 0x0074DFF0 );
    void CreateVobDependencies( zCWorld* )                             zCall( 0x0074E1F0 );
    zSTRING MergeWaypoints()                                           zCall( 0x0074E470 );
    zSTRING CheckConsistency( int )                                    zCall( 0x0074E730 );
    void AddWays( zCWaypoint*, zCWaypoint* )                           zCall( 0x0074EC30 );
    zCWaypoint* __fastcall GetWaypoint( zSTRING const& ) const         zCall( 0x00750830 );
    zCWaypoint* SearchWaypoint( zCVobWaypoint* )                       zCall( 0x007509A0 );
    zCRoute* FindRoute( zVEC3 const&, zVEC3 const&, zCVob const* )     zCall( 0x007509D0 );
    zCRoute* FindRoute( zVEC3 const&, zCWaypoint*, zCVob const* )      zCall( 0x00750A60 );
    zCRoute* FindRoute( zVEC3 const&, zSTRING const&, zCVob const* )   zCall( 0x00750AD0 );
    zCRoute* FindRoute( zCWaypoint*, zCWaypoint*, zCVob const* )       zCall( 0x00750B40 );
    zCRoute* FindRoute( zSTRING const&, zSTRING const&, zCVob const* ) zCall( 0x00750B80 );
    void InsertInOpen( zCWaypoint* )                                   zCall( 0x00750C00 );
    int IsInOpen( zCWaypoint* )                                        zCall( 0x00750C30 );
    void InsertInClosed( zCWaypoint* )                                 zCall( 0x00750C50 );
    void RemoveFromClosed( zCWaypoint* )                               zCall( 0x00750C70 );
    int IsInClosed( zCWaypoint* )                                      zCall( 0x00750C80 );
    int IsInAnyList( zCWaypoint* )                                     zCall( 0x00750CA0 );
    int EstimateCost( zCWaypoint*, zCWaypoint* )                       zCall( 0x00750CD0 );
    zCRoute* CreateRoute( zCWaypoint* )                                zCall( 0x00750D30 );
    int AStar( zCWaypoint*, zCWaypoint*, zCVob const* )                zCall( 0x00750DD0 );
    void GetWPList( zCList<zVEC3>&, zVEC3&, float, float )             zCall( 0x00751050 );
    void CreateWPVobList( zCList<zCVobWaypoint>&, zCTree<zCVob>* )     zCall( 0x007511B0 );
    void RemoveUnusedWPVobs()                                          zCall( 0x007511F0 );
    void ArchiveOldFormat( zCArchiver& )                               zCall( 0x00751340 );
    void UnarchiveOldFormat( zCArchiver& )                             zCall( 0x00751BF0 );
    void CalcProperties( zCWorld* )                                    zCall( 0x00752D20 );
    static int SortWpList( zCWaypoint*, zCWaypoint* )                  zCall( 0x0074FB20 );
    static int SortOpenList( zCWaypoint*, zCWaypoint* )                zCall( 0x00750BE0 );
    static zCObject* _CreateNewInstance()                              zCall( 0x007542B0 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x0074D1D0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x007516D0 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x00752700 );
    virtual ~zCWayNet()                                                zCall( 0x0074D2B0 );

    // user API
    #include "zCWayNet.inl"
  };

  // sizeof 1Ch
  class zCRoute {
  public:
    zCList<zCWay> wayList;  // sizeof 08h    offset 04h
    zCWaypoint* startwp;    // sizeof 04h    offset 0Ch
    zCWaypoint* target;     // sizeof 04h    offset 10h
    zCWay* way;             // sizeof 04h    offset 14h
    zCList<zCWay>* waynode; // sizeof 04h    offset 18h

    void zCRoute_OnInit()                             zCall( 0x00752D60 );
    zCRoute()                                         zInit( zCRoute_OnInit() );
    void SetStart( zCWaypoint* )                      zCall( 0x00752DE0 );
    zCWaypoint* GetNextWP()                           zCall( 0x00752DF0 );
    zCWaypoint* GetTargetWP()                         zCall( 0x00752E60 );
    zCWay* GetCurrentWay()                            zCall( 0x00752E70 );
    zSTRING GetDesc()                                 zCall( 0x00752E80 );
    zSTRING GetRemainingDesc()                        zCall( 0x00753060 );
    int GetNumberOfWaypoints()                        zCall( 0x00753240 );
    int IsEmpty()                                     zCall( 0x00753260 );
    int IsLastTarget()                                zCall( 0x00753280 );
    int GetInterpolatedPosition( float, int, zVEC3& ) zCall( 0x007532A0 );
    virtual ~zCRoute()                                zCall( 0x00752DA0 );

    // user API
    #include "zCRoute.inl"
  };

  // sizeof 128h
  class zCVobSpot : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobSpot )

    float timerEnd;  // sizeof 04h    offset 120h
    zCVob* inUseVob; // sizeof 04h    offset 124h

    void zCVobSpot_OnInit()                  zCall( 0x007534A0 );
    zCVobSpot()                              zInit( zCVobSpot_OnInit() );
    int IsAvailable( zCVob* )                zCall( 0x00753520 );
    void MarkAsUsed( float, zCVob* )         zCall( 0x007536A0 );
    static zCObject* _CreateNewInstance()    zCall( 0x00753B10 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x007534C0 );
    virtual ~zCVobSpot()                     zCall( 0x00753500 );

    // user API
    #include "zCVobSpot.inl"
  };

  // sizeof 120h
  class zCVobStartpoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStartpoint )

    zCVobStartpoint() {}
    static zCObject* _CreateNewInstance()    zCall( 0x00753DB0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00753E40 );
    virtual ~zCVobStartpoint()               zCall( 0x00753E80 );

    // user API
    #include "zCVobStartpoint.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZWAYNET_H__VER2__