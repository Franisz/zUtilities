// Supported with union (c) 2018-2021 Union team

#ifndef __ZWAYNET_H__VER0__
#define __ZWAYNET_H__VER0__

#include "z3d.h"
#include "zVob.h"

namespace Gothic_I_Classic {

  enum {
    zWAY_JUMP  = 1,
    zWAY_CLIMB = 2,
    zWAY_SWIM  = 4,
    zWAY_DIVE  = 8,
    zWAY_FREE  = 16
  };

  // sizeof 100h
  class zCVobWaypoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobWaypoint )

    void zCVobWaypoint_OnInit()                                         zCall( 0x00702FB0 );
    zCVobWaypoint()                                                     zInit( zCVobWaypoint_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x007096B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00702FD0 );
    virtual ~zCVobWaypoint()                                            zCall( 0x00703010 );

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

    void zCWaypoint_OnInit()                                            zCall( 0x00705B70 );
    zCWaypoint()                                                        zInit( zCWaypoint_OnInit() );
    void Init( zVEC3& )                                                 zCall( 0x00705CA0 );
    void Init( float, float, float )                                    zCall( 0x00705D00 );
    void Init( zCVobWaypoint* )                                         zCall( 0x00705D70 );
    void Free()                                                         zCall( 0x00705E10 );
    zVEC3& GetPositionWorld()                                           zCall( 0x00705F30 );
    void UpdatePositionWorld()                                          zCall( 0x00705F40 );
    void SetName( zSTRING& )                                            zCall( 0x00705FB0 );
    zSTRING const& GetName()                                            zCall( 0x00706110 );
    zCVobWaypoint* GetVob()                                             zCall( 0x00706270 );
    void CalcProperties( zCWorld* )                                     zCall( 0x00706280 );
    void CorrectHeight( zCWorld* )                                      zCall( 0x007064A0 );
    void InsertWay( zCWay* )                                            zCall( 0x00706540 );
    void RemoveWay( zCWay* )                                            zCall( 0x00706550 );
    zCWay* HasWay( zCWaypoint* )                                        zCall( 0x007065B0 );
    int GetNumberOfWays()                                               zCall( 0x007065E0 );
    zCList<zCWay>& GetWayList()                                         zCall( 0x00706600 );
    void SetWaypointVob( zCVobWaypoint* )                               zCall( 0x00706610 );
    void Draw()                                                         zCall( 0x00706650 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00709EC0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006D4FE0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00706660 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x007066C0 );
    virtual ~zCWaypoint()                                               zCall( 0x00705E80 );
    virtual int CanBeUsed( zCVob const* )                               zCall( 0x00705C60 );

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

    void zCWay_OnInit()                           zCall( 0x00704C40 );
    void zCWay_OnInit( zCWaypoint*, zCWaypoint* ) zCall( 0x00704CA0 );
    zCWay()                                       zInit( zCWay_OnInit() );
    zCWay( zCWaypoint* a0, zCWaypoint* a1 )       zInit( zCWay_OnInit( a0, a1 ));
    void Free()                                   zCall( 0x00704DF0 );
    zCWaypoint* GetGoalWaypoint( zCWaypoint* )    zCall( 0x00704EA0 );
    void EstimateCost()                           zCall( 0x00704EB0 );
    float GetLength()                             zCall( 0x00704F20 );
    float GetJumpDistance()                       zCall( 0x00704FD0 );
    zVEC3 GetDistancePos( float, zCWaypoint* )    zCall( 0x00705090 );
    void Draw( zCCamera* )                        zCall( 0x007051A0 );
    zVEC3 GetFloor( zCWorld*, zVEC3 const& )      zCall( 0x00705670 );
    virtual ~zCWay()                              zCall( 0x00704E90 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x00704D50 );
    virtual void CalcProperties( zCWorld* )       zCall( 0x00705710 );
    virtual float GetChasm()                      zCall( 0x00705A00 );
    virtual int CanJump()                         zCall( 0x00705A10 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x00705190 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x00704C60 );

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

    void zCWayNet_OnInit()                                              zCall( 0x00703020 );
    void zCWayNet_OnInit( zCWorld* )                                    zCall( 0x00703100 );
    zCWayNet()                                                          zInit( zCWayNet_OnInit() );
    zCWayNet( zCWorld* a0 )                                             zInit( zCWayNet_OnInit( a0 ));
    zCWaypoint* HasWaypoint( float, float, float )                      zCall( 0x007032F0 );
    int HasWaypoint( zCWaypoint* )                                      zCall( 0x00703360 );
    zCWaypoint* HasWaypoint( zVEC3& )                                   zCall( 0x00703390 );
    zCWaypoint* InsertWaypoint( float, float, float )                   zCall( 0x007033E0 );
    void InsertWaypoint( zCWaypoint* )                                  zCall( 0x007034F0 );
    void InsertWaypoint( zCWaypoint*, zCWaypoint*, zCWaypoint* )        zCall( 0x00703520 );
    void DeleteWaypoint( zCWaypoint* )                                  zCall( 0x007036A0 );
    void CreateWay( zCWaypoint*, zCWaypoint* )                          zCall( 0x00703810 );
    void DeleteWay( zCWaypoint*, zCWaypoint* )                          zCall( 0x007038E0 );
    zCWaypoint* __fastcall GetNearestWaypoint( zVEC3 const& )           zCall( 0x00703A50 );
    zCWaypoint* GetSecNearestWaypoint( zVEC3& )                         zCall( 0x00703AE0 );
    void CorrectHeight()                                                zCall( 0x00703BA0 );
    void Draw( zCCamera* )                                              zCall( 0x00703C60 );
    void UpdateVobDependencies()                                        zCall( 0x00703C90 );
    void ClearVobDependencies()                                         zCall( 0x00703EE0 );
    void CreateVobDependencies( zCWorld* )                              zCall( 0x007040E0 );
    zSTRING MergeWaypoints()                                            zCall( 0x00704380 );
    zSTRING CheckConsistency( int )                                     zCall( 0x00704640 );
    void AddWays( zCWaypoint*, zCWaypoint* )                            zCall( 0x00704B40 );
    zCWaypoint* __fastcall GetWaypoint( zSTRING const& ) const          zCall( 0x00706730 );
    zCWaypoint* SearchWaypoint( zCVobWaypoint* )                        zCall( 0x007068A0 );
    zCRoute* FindRoute( zVEC3 const&, zVEC3 const&, zCVob const* )      zCall( 0x007068D0 );
    zCRoute* FindRoute( zVEC3 const&, zCWaypoint*, zCVob const* )       zCall( 0x00706960 );
    zCRoute* FindRoute( zVEC3 const&, zSTRING const&, zCVob const* )    zCall( 0x007069D0 );
    zCRoute* FindRoute( zCWaypoint*, zCWaypoint*, zCVob const* )        zCall( 0x00706A40 );
    zCRoute* FindRoute( zSTRING const&, zSTRING const&, zCVob const* )  zCall( 0x00706A80 );
    void InsertInOpen( zCWaypoint* )                                    zCall( 0x00706B00 );
    int IsInOpen( zCWaypoint* )                                         zCall( 0x00706B30 );
    void InsertInClosed( zCWaypoint* )                                  zCall( 0x00706B50 );
    void RemoveFromClosed( zCWaypoint* )                                zCall( 0x00706B70 );
    int IsInClosed( zCWaypoint* )                                       zCall( 0x00706B80 );
    int IsInAnyList( zCWaypoint* )                                      zCall( 0x00706BA0 );
    int EstimateCost( zCWaypoint*, zCWaypoint* )                        zCall( 0x00706BD0 );
    zCRoute* CreateRoute( zCWaypoint* )                                 zCall( 0x00706C30 );
    int AStar( zCWaypoint*, zCWaypoint*, zCVob const* )                 zCall( 0x00706CF0 );
    void GetWPList( zCList<zVEC3>&, zVEC3&, float, float )              zCall( 0x00706F70 );
    void CreateWPVobList( zCList<zCVobWaypoint>&, zCTree<zCVob>* )      zCall( 0x00707100 );
    void RemoveUnusedWPVobs()                                           zCall( 0x00707140 );
    void ArchiveOldFormat( zCArchiver& )                                zCall( 0x007072A0 );
    void UnarchiveOldFormat( zCArchiver& )                              zCall( 0x00707A30 );
    void CalcProperties( zCWorld* )                                     zCall( 0x00708B20 );
    static int SortWpList( zCWaypoint*, zCWaypoint* )                   zCall( 0x00705A20 );
    static int SortOpenList( zCWaypoint*, zCWaypoint* )                 zCall( 0x00706AE0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0070A110 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007030C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x007075B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00708530 );
    virtual ~zCWayNet()                                                 zCall( 0x007031A0 );

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

    void zCRoute_OnInit()                             zCall( 0x00708B60 );
    zCRoute()                                         zInit( zCRoute_OnInit() );
    void SetStart( zCWaypoint* )                      zCall( 0x00708BE0 );
    zCWaypoint* GetNextWP()                           zCall( 0x00708BF0 );
    zCWaypoint* GetTargetWP()                         zCall( 0x00708C60 );
    zCWay* GetCurrentWay()                            zCall( 0x00708C70 );
    zSTRING GetDesc()                                 zCall( 0x00708C80 );
    zSTRING GetRemainingDesc()                        zCall( 0x00708E60 );
    int GetNumberOfWaypoints()                        zCall( 0x00709040 );
    int IsEmpty()                                     zCall( 0x00709060 );
    int IsLastTarget()                                zCall( 0x00709080 );
    int GetInterpolatedPosition( float, int, zVEC3& ) zCall( 0x007090A0 );
    virtual ~zCRoute()                                zCall( 0x00708BA0 );

    // user API
    #include "zCRoute.inl"
  };

  // sizeof 108h
  class zCVobSpot : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobSpot )

    float timerEnd;  // sizeof 04h    offset 100h
    zCVob* inUseVob; // sizeof 04h    offset 104h

    void zCVobSpot_OnInit()                                             zCall( 0x007092A0 );
    zCVobSpot()                                                         zInit( zCVobSpot_OnInit() );
    int IsAvailable( zCVob* )                                           zCall( 0x00709320 );
    void MarkAsUsed( float, zCVob* )                                    zCall( 0x007094A0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00709930 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007092C0 );
    virtual ~zCVobSpot()                                                zCall( 0x00709300 );

    // user API
    #include "zCVobSpot.inl"
  };

  // sizeof 100h
  class zCVobStartpoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStartpoint )

    zCVobStartpoint() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x00709BE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00709C90 );
    virtual ~zCVobStartpoint()                                          zCall( 0x00709CD0 );

    // user API
    #include "zCVobStartpoint.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZWAYNET_H__VER0__