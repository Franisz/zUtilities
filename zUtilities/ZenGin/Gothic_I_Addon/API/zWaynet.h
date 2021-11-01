// Supported with union (c) 2018-2021 Union team

#ifndef __ZWAYNET_H__VER1__
#define __ZWAYNET_H__VER1__

#include "z3d.h"
#include "zVob.h"

namespace Gothic_I_Addon {

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

    void zCVobWaypoint_OnInit()                                         zCall( 0x0073D7B0 );
    zCVobWaypoint()                                                     zInit( zCVobWaypoint_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x007444D0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0073D7D0 );
    virtual ~zCVobWaypoint()                                            zCall( 0x0073D810 );

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

    void zCWaypoint_OnInit()                                            zCall( 0x007405E0 );
    zCWaypoint()                                                        zInit( zCWaypoint_OnInit() );
    void Init( zVEC3& )                                                 zCall( 0x00740720 );
    void Init( float, float, float )                                    zCall( 0x00740780 );
    void Init( zCVobWaypoint* )                                         zCall( 0x007407F0 );
    void Free()                                                         zCall( 0x007408D0 );
    zVEC3& GetPositionWorld()                                           zCall( 0x00740A00 );
    void UpdatePositionWorld()                                          zCall( 0x00740A10 );
    void SetName( zSTRING& )                                            zCall( 0x00740AA0 );
    zSTRING const& GetName()                                            zCall( 0x00740C00 );
    zCVobWaypoint* GetVob()                                             zCall( 0x00740D60 );
    void CalcProperties( zCWorld* )                                     zCall( 0x00740D70 );
    void CorrectHeight( zCWorld* )                                      zCall( 0x00740FA0 );
    void InsertWay( zCWay* )                                            zCall( 0x00741050 );
    void RemoveWay( zCWay* )                                            zCall( 0x00741060 );
    zCWay* HasWay( zCWaypoint* )                                        zCall( 0x007410C0 );
    int GetNumberOfWays()                                               zCall( 0x007410F0 );
    zCList<zCWay>& GetWayList()                                         zCall( 0x00741110 );
    void SetWaypointVob( zCVobWaypoint* )                               zCall( 0x00741120 );
    void Draw()                                                         zCall( 0x00741160 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00744D20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0070C590 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00741170 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x007411D0 );
    virtual ~zCWaypoint()                                               zCall( 0x00740940 );
    virtual int CanBeUsed( zCVob const* )                               zCall( 0x007406E0 );

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

    void zCWay_OnInit()                           zCall( 0x0073F540 );
    void zCWay_OnInit( zCWaypoint*, zCWaypoint* ) zCall( 0x0073F5A0 );
    zCWay()                                       zInit( zCWay_OnInit() );
    zCWay( zCWaypoint* a0, zCWaypoint* a1 )       zInit( zCWay_OnInit( a0, a1 ));
    void Free()                                   zCall( 0x0073F6F0 );
    zCWaypoint* GetGoalWaypoint( zCWaypoint* )    zCall( 0x0073F7B0 );
    void EstimateCost()                           zCall( 0x0073F7C0 );
    float GetLength()                             zCall( 0x0073F830 );
    float GetJumpDistance()                       zCall( 0x0073F8E0 );
    zVEC3 GetDistancePos( float, zCWaypoint* )    zCall( 0x0073F9A0 );
    void Draw( zCCamera* )                        zCall( 0x0073FB40 );
    zVEC3 GetFloor( zCWorld*, zVEC3 const& )      zCall( 0x00740090 );
    virtual ~zCWay()                              zCall( 0x0073F7A0 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x0073F650 );
    virtual void CalcProperties( zCWorld* )       zCall( 0x00740130 );
    virtual float GetChasm()                      zCall( 0x00740460 );
    virtual int CanJump()                         zCall( 0x00740470 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x0073FB30 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x0073F560 );

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

    void zCWayNet_OnInit()                                              zCall( 0x0073D820 );
    void zCWayNet_OnInit( zCWorld* )                                    zCall( 0x0073D900 );
    zCWayNet()                                                          zInit( zCWayNet_OnInit() );
    zCWayNet( zCWorld* a0 )                                             zInit( zCWayNet_OnInit( a0 ));
    zCWaypoint* HasWaypoint( float, float, float )                      zCall( 0x0073DB00 );
    int HasWaypoint( zCWaypoint* )                                      zCall( 0x0073DB60 );
    zCWaypoint* HasWaypoint( zVEC3& )                                   zCall( 0x0073DB90 );
    zCWaypoint* InsertWaypoint( float, float, float )                   zCall( 0x0073DBE0 );
    void InsertWaypoint( zCWaypoint* )                                  zCall( 0x0073DCE0 );
    void InsertWaypoint( zCWaypoint*, zCWaypoint*, zCWaypoint* )        zCall( 0x0073DD10 );
    void DeleteWaypoint( zCWaypoint* )                                  zCall( 0x0073DE90 );
    void CreateWay( zCWaypoint*, zCWaypoint* )                          zCall( 0x0073E000 );
    void DeleteWay( zCWaypoint*, zCWaypoint* )                          zCall( 0x0073E0C0 );
    zCWaypoint* __fastcall GetNearestWaypoint( zVEC3 const& )           zCall( 0x0073E240 );
    zCWaypoint* GetSecNearestWaypoint( zVEC3& )                         zCall( 0x0073E2D0 );
    void CorrectHeight()                                                zCall( 0x0073E390 );
    void Draw( zCCamera* )                                              zCall( 0x0073E460 );
    void UpdateVobDependencies()                                        zCall( 0x0073E490 );
    void ClearVobDependencies()                                         zCall( 0x0073E6D0 );
    void CreateVobDependencies( zCWorld* )                              zCall( 0x0073E8E0 );
    zSTRING MergeWaypoints()                                            zCall( 0x0073EBB0 );
    zSTRING CheckConsistency( int )                                     zCall( 0x0073EEB0 );
    void AddWays( zCWaypoint*, zCWaypoint* )                            zCall( 0x0073F440 );
    zCWaypoint* __fastcall GetWaypoint( zSTRING const& ) const          zCall( 0x00741240 );
    zCWaypoint* SearchWaypoint( zCVobWaypoint* )                        zCall( 0x007413C0 );
    zCRoute* FindRoute( zVEC3 const&, zVEC3 const&, zCVob const* )      zCall( 0x007413E0 );
    zCRoute* FindRoute( zVEC3 const&, zCWaypoint*, zCVob const* )       zCall( 0x00741470 );
    zCRoute* FindRoute( zVEC3 const&, zSTRING const&, zCVob const* )    zCall( 0x007414E0 );
    zCRoute* FindRoute( zCWaypoint*, zCWaypoint*, zCVob const* )        zCall( 0x00741550 );
    zCRoute* FindRoute( zSTRING const&, zSTRING const&, zCVob const* )  zCall( 0x00741590 );
    void InsertInOpen( zCWaypoint* )                                    zCall( 0x00741610 );
    int IsInOpen( zCWaypoint* )                                         zCall( 0x00741640 );
    void InsertInClosed( zCWaypoint* )                                  zCall( 0x00741660 );
    void RemoveFromClosed( zCWaypoint* )                                zCall( 0x00741680 );
    int IsInClosed( zCWaypoint* )                                       zCall( 0x00741690 );
    int IsInAnyList( zCWaypoint* )                                      zCall( 0x007416B0 );
    int EstimateCost( zCWaypoint*, zCWaypoint* )                        zCall( 0x007416E0 );
    zCRoute* CreateRoute( zCWaypoint* )                                 zCall( 0x00741740 );
    int AStar( zCWaypoint*, zCWaypoint*, zCVob const* )                 zCall( 0x007417F0 );
    void GetWPList( zCList<zVEC3>&, zVEC3&, float, float )              zCall( 0x00741A70 );
    void CreateWPVobList( zCList<zCVobWaypoint>&, zCTree<zCVob>* )      zCall( 0x00741C00 );
    void RemoveUnusedWPVobs()                                           zCall( 0x00741C40 );
    void ArchiveOldFormat( zCArchiver& )                                zCall( 0x00741DA0 );
    void UnarchiveOldFormat( zCArchiver& )                              zCall( 0x00742600 );
    void CalcProperties( zCWorld* )                                     zCall( 0x00743840 );
    static int SortWpList( zCWaypoint*, zCWaypoint* )                   zCall( 0x00740480 );
    static int SortOpenList( zCWaypoint*, zCWaypoint* )                 zCall( 0x007415F0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00744F90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0073D8C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00742100 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x007431E0 );
    virtual ~zCWayNet()                                                 zCall( 0x0073D9B0 );

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

    void zCRoute_OnInit()                             zCall( 0x00743880 );
    zCRoute()                                         zInit( zCRoute_OnInit() );
    void SetStart( zCWaypoint* )                      zCall( 0x00743900 );
    zCWaypoint* GetNextWP()                           zCall( 0x00743910 );
    zCWaypoint* GetTargetWP()                         zCall( 0x00743980 );
    zCWay* GetCurrentWay()                            zCall( 0x00743990 );
    zSTRING GetDesc()                                 zCall( 0x007439A0 );
    zSTRING GetRemainingDesc()                        zCall( 0x00743BE0 );
    int GetNumberOfWaypoints()                        zCall( 0x00743E20 );
    int IsEmpty()                                     zCall( 0x00743E40 );
    int IsLastTarget()                                zCall( 0x00743E60 );
    int GetInterpolatedPosition( float, int, zVEC3& ) zCall( 0x00743E80 );
    virtual ~zCRoute()                                zCall( 0x007438C0 );

    // user API
    #include "zCRoute.inl"
  };

  // sizeof 108h
  class zCVobSpot : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobSpot )

    float timerEnd;  // sizeof 04h    offset 100h
    zCVob* inUseVob; // sizeof 04h    offset 104h

    void zCVobSpot_OnInit()                                             zCall( 0x007440A0 );
    zCVobSpot()                                                         zInit( zCVobSpot_OnInit() );
    int IsAvailable( zCVob* )                                           zCall( 0x00744120 );
    void MarkAsUsed( float, zCVob* )                                    zCall( 0x007442B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00744760 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007440C0 );
    virtual ~zCVobSpot()                                                zCall( 0x00744100 );

    // user API
    #include "zCVobSpot.inl"
  };

  // sizeof 100h
  class zCVobStartpoint : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStartpoint )

    zCVobStartpoint() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x00744A20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00744AD0 );
    virtual ~zCVobStartpoint()                                          zCall( 0x00744B10 );

    // user API
    #include "zCVobStartpoint.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZWAYNET_H__VER1__