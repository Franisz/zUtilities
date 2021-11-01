// Supported with union (c) 2018-2021 Union team

#ifndef __ZAI_CAMERA__CORE_H__VER1__
#define __ZAI_CAMERA__CORE_H__VER1__

#include "zKbSplines.h"

namespace Gothic_I_Addon {
  const int AZI   = 0;
  const int ELEV  = 1;
  const int RANGE = 2;

  enum zTPoseFailReason {
    zFAILREASON_NONE                    = 0,
    zFAILREASON_PLAYER_INVISIBLE        = 1 << 0,
    zFAILREASON_CAM_INVISIBLE           = 1 << 1,
    zFAILREASON_PLAYER_TARGET_INVISIBLE = 1 << 2,
    zFAILREASON_CAM_HIT_WALL            = 1 << 3,
    zFAILREASON_NO_EVASION_FOUND        = 1 << 4,
    zFAILREASON_BADSCENE_STAND          = 1 << 5,
    zFAILREASON_BADSCENE_MELEE          = 1 << 6,
    zFAILREASON_BADSCENE_RANGED         = 1 << 7,
    zFAILREASON_BADSCENE_MAGIC          = 1 << 8,
    zFAILREASON_BADSCENE_CINEMA         = 1 << 9,
    zFAILREASON_VOB_CROSS_LINEOFSIGHT   = 1 << 10,
    zFAILREASON_NPC_CROSS_LINEOFSIGHT   = 1 << 11,
    zFAILREASON_VOB_HIT_CAM             = 1 << 12,
    zFAILREASON_NPC_HIT_CAM             = 1 << 13,
    zFAILREASON_AZIBOUND_LEFT           = 1 << 14,
    zFAILREASON_ELEVBOUND_LEFT          = 1 << 15,
    zFAILREASON_RANGEBOUND_LEFT         = 1 << 16,
    zFAILREASON_TARGET_NOT_IN_FRUSTUM   = 1 << 17,
    zFAILREASON_PLAYER_BEAMED           = 1 << 18
  };

  enum zTPathLerpMode {
    zPATH_LERP_NONE        = 0,
    zPATH_LERP_CUSTOM_JUMP = 1 << 0,
    zPATH_LERP_JUMP        = 1 << 1,
    zPATH_LERP_CUSTOM      = 1 << 2,
    zPATH_LERP_SPLINE      = 1 << 3,
    zPATH_LERP_LINE        = 1 << 4,
    zPATH_LERP_ARC         = 1 << 5,
    zPATH_LERP_MAX         = 1 << 6
  };

  enum zTPathSearchFlags {
    zPATHSEARCH_INCLUDE_NONE                = 0,
    zPATHSEARCH_INCLUDE_CAM_CHECK           = 1 << 1,
    zPATHSEARCH_INCLUDE_PLAYER_CHECK        = 1 << 2,
    zPATHSEARCH_INCLUDE_PLAYER_TARGET_CHECK = 1 << 3,
    zPATHSEARCH_INCLUDE_NEARWALL_CHECK      = 1 << 4,
    zPATHSEARCH_INCLUDE_VOB_CHECK           = 1 << 5,
    zPATHSEARCH_INCLUDE_NPC_CHECK           = 1 << 6,
    zPATHSEARCH_INCLUDE_INFRUSTUM_CHECK     = 1 << 7,
    zPATHSEARCH_INCLUDE_BOUNDS_CHECK        = 1 << 8,
    zPATHSEARCH_USE_PLAYER_FUTURE_POS       = 1 << 9,
    zPATHSEARCH_USE_PLAYER_MESH             = 1 << 10,
    zPATHSEARCH_USE_DYNCOLLISION            = 1 << 11
  };

  // sizeof 24h
  struct zSEvasionSearchDesc {
    // sizeof 58h
    struct zSEvasionSearchOptions {
      zVEC3 scSign;       // sizeof 0Ch    offset 00h
      zVEC3 scQuality;    // sizeof 0Ch    offset 0Ch
      zVEC3 scStart;      // sizeof 0Ch    offset 18h
      zVEC3 scEnd;        // sizeof 0Ch    offset 24h
      zSTRING scSequence; // sizeof 14h    offset 30h
      zSTRING scName;     // sizeof 14h    offset 44h

      void zSEvasionSearchOptions_OnInit()                                zCall( 0x004B1030 );
      ~zSEvasionSearchOptions()                                           zCall( 0x004AD4D0 );
      zSEvasionSearchOptions()                                            zInit( zSEvasionSearchOptions_OnInit() );
      zSEvasionSearchOptions& operator =( zSEvasionSearchOptions const& ) zCall( 0x004B6B10 );

      // user API
      #include "zSEvasionSearchDesc_zSEvasionSearchOptions.inl"
    };

    bool32(* searchFunc )( const zSEvasionSearchDesc& ); // sizeof 04h    offset 00h
    zSTRING searchName;                                  // sizeof 14h    offset 04h
    zCArray<zSEvasionSearchOptions> sphereSearchList;    // sizeof 0Ch    offset 18h

    void zSEvasionSearchDesc_OnInit()                             zCall( 0x004AEF30 );
    zSEvasionSearchDesc()                                         zInit( zSEvasionSearchDesc_OnInit() );
    ~zSEvasionSearchDesc()                                        zCall( 0x004AEF60 );
    zSEvasionSearchDesc& operator =( zSEvasionSearchDesc const& ) zCall( 0x004B6E00 );

    // user API
    #include "zSEvasionSearchDesc.inl"
  };

  // sizeof 60h
  struct zSPathSearchResult {
    int foundEvasion;               // sizeof 04h    offset 00h
    zVEC3 p1;                       // sizeof 0Ch    offset 04h
    zVEC3 p2;                       // sizeof 0Ch    offset 10h
    zCQuat r1;                      // sizeof 10h    offset 1Ch
    zCQuat r2;                      // sizeof 10h    offset 2Ch
    zTPathLerpMode bestLerpMode;    // sizeof 04h    offset 3Ch
    int lerpModes;                  // sizeof 04h    offset 40h
    zCArray<zCPositionKey*>resPath; // sizeof 0Ch    offset 44h
    float avgScore;                 // sizeof 04h    offset 50h
    float bestScore;                // sizeof 04h    offset 54h
    float veloTrans;                // sizeof 04h    offset 58h
    float veloRot;                  // sizeof 04h    offset 5Ch

    void zSPathSearchResult_OnInit() zCall( 0x004ACC80 );
    ~zSPathSearchResult()            zCall( 0x004A9E10 );
    zSPathSearchResult()             zInit( zSPathSearchResult_OnInit() );

    // user API
    #include "zSPathSearchResult.inl"
  };

  // sizeof 98h
  struct zSPathSearchState {
    float startAzi;              // sizeof 04h    offset 00h
    float startElev;             // sizeof 04h    offset 04h
    float startRange;            // sizeof 04h    offset 08h
    float endAzi;                // sizeof 04h    offset 0Ch
    float endElev;               // sizeof 04h    offset 10h
    float endRange;              // sizeof 04h    offset 14h
    float bestAzi;               // sizeof 04h    offset 18h
    float bestElev;              // sizeof 04h    offset 1Ch
    float bestRange;             // sizeof 04h    offset 20h
    zMAT4 trafoCamToWorld;       // sizeof 40h    offset 24h
    zTPathLerpMode bestLerpMode; // sizeof 04h    offset 64h
    int lerpModes;               // sizeof 04h    offset 68h
    float totalScore;            // sizeof 04h    offset 6Ch
    zSTRING sphereSearchName;    // sizeof 14h    offset 70h
    zSTRING sphereSearchSegment; // sizeof 14h    offset 84h

    zSPathSearchState() {}
    ~zSPathSearchState() zCall( 0x004AB960 );

    // user API
    #include "zSPathSearchState.inl"
  };

  // sizeof 74h
  struct zSPathSearchState_Internal {
    float maxRange;               // sizeof 04h    offset 00h
    zVEC3 foundPos;               // sizeof 0Ch    offset 04h
    zMAT4 trafoCamToWorld;        // sizeof 40h    offset 10h
    zTPathLerpMode bestLerpMode;  // sizeof 04h    offset 50h
    float scoreLerpMode;          // sizeof 04h    offset 54h
    float scoreDistToIdealPos;    // sizeof 04h    offset 58h
    float scoreFoundNumNpcs;      // sizeof 04h    offset 5Ch
    float scoreFoundNumBBoxes;    // sizeof 04h    offset 60h
    float scoreFoundNumTargets;   // sizeof 04h    offset 64h
    float scorePlayerVisibility;  // sizeof 04h    offset 68h
    float scoreDistToLastEvasion; // sizeof 04h    offset 6Ch
    float totalScore;             // sizeof 04h    offset 70h

    void zSPathSearchState_Internal_OnInit() zCall( 0x004AC930 );
    zSPathSearchState_Internal()             zInit( zSPathSearchState_Internal_OnInit() );

    // user API
    #include "zSPathSearchState_Internal.inl"
  };

  // sizeof 10h
  class zCSphereCoordsCache {
  public:
    // sizeof 78h
    struct zSRangeSphereCoord {
      float range;                            // sizeof 04h    offset 00h
      zSPathSearchState_Internal searchState; // sizeof 74h    offset 04h

      zSRangeSphereCoord() {}

      // user API
      #include "zCSphereCoordsCache_zSRangeSphereCoord.inl"
    };

    // sizeof 18h
    struct zSElevSphereCoord {
      float elev;                                   // sizeof 04h    offset 00h
      float maxRange;                               // sizeof 04h    offset 04h
      zCArraySort<zSRangeSphereCoord*> rangeCoords; // sizeof 10h    offset 08h

      zSElevSphereCoord() {}
      ~zSElevSphereCoord() zCall( 0x004AC910 );

      // user API
      #include "zCSphereCoordsCache_zSElevSphereCoord.inl"
    };

    // sizeof 14h
    struct zSAziSphereCoord {
      float azi;                                  // sizeof 04h    offset 00h
      zCArraySort<zSElevSphereCoord*> elevCoords; // sizeof 10h    offset 04h

      zSAziSphereCoord() {}
      ~zSAziSphereCoord() zCall( 0x004AC8F0 );

      // user API
      #include "zCSphereCoordsCache_zSAziSphereCoord.inl"
    };

    zCArraySort<zSAziSphereCoord*> aziCoords; // sizeof 10h    offset 00h

    void zCSphereCoordsCache_OnInit()                                                                zCall( 0x004ACA90 );
    int GetSphereCoordLazy( float const&, float const&, float const&, zSPathSearchState_Internal*& ) zCall( 0x004ABB70 );
    void GetBestScoredSearch( float&, float&, float&, zSPathSearchState_Internal*& )                 zCall( 0x004AC940 );
    zCSphereCoordsCache()                                                                            zInit( zCSphereCoordsCache_OnInit() );
    ~zCSphereCoordsCache()                                                                           zCall( 0x004ACAB0 );
    void DeleteList()                                                                                zCall( 0x004ACB10 );

    // user API
    #include "zCSphereCoordsCache.inl"
  };

  // sizeof 214h
  class zCPathSearch {
  public:
    // sizeof 30h
    struct zSPathSearchOptions {
      int searchFlags;                 // sizeof 04h    offset 00h
      zTPoseFailReason poseFailReason; // sizeof 04h    offset 04h
      zTPathLerpMode minLerpMode;      // sizeof 04h    offset 08h
      float bestScore;                 // sizeof 04h    offset 0Ch
      float minScore;                  // sizeof 04h    offset 10h
      float startAzi;                  // sizeof 04h    offset 14h
      float startElev;                 // sizeof 04h    offset 18h
      float startRange;                // sizeof 04h    offset 1Ch
      float endAzi;                    // sizeof 04h    offset 20h
      float endElev;                   // sizeof 04h    offset 24h
      float endRange;                  // sizeof 04h    offset 28h
      float quality;                   // sizeof 04h    offset 2Ch

      zSPathSearchOptions() {}
      void SetDefaults() zCall( 0x004AB320 );

      // user API
      #include "zCPathSearch_zSPathSearchOptions.inl"
    };

    zSPathSearchState bestSearchState;                               // sizeof 98h    offset 00h
    zSPathSearchState lastSearchState;                               // sizeof 98h    offset 98h
    int ignoreSearchFlags;                                           // sizeof 04h    offset 130h
    zCAICamera* camai;                                               // sizeof 04h    offset 134h
    zCVob* camVob;                                                   // sizeof 04h    offset 138h
    zCVob* target;                                                   // sizeof 04h    offset 13Ch
    zCWorld* world;                                                  // sizeof 04h    offset 140h
    int collisionEnabled;                                            // sizeof 04h    offset 144h
    zSPathSearchOptions searchOptions;                               // sizeof 30h    offset 148h
    zSPathSearchResult evasionSearchReport;                          // sizeof 60h    offset 178h
    zCMovementTracker* moveTracker;                                  // sizeof 04h    offset 1D8h
    zCSphereCoordsCache searchCache;                                 // sizeof 10h    offset 1DCh
    zVEC3 lastTriedPosition;                                         // sizeof 0Ch    offset 1ECh
    zTBSphere3D POISphere;                                           // sizeof 10h    offset 1F8h
    zCArray<bool32(* * )( const zSEvasionSearchDesc& )> searchFuncs; // sizeof 0Ch    offset 208h

    void zCPathSearch_OnInit()                                                       zCall( 0x004AB780 );

  private:
    zCPathSearch()                                                                   zInit( zCPathSearch_OnInit() );

  public:
    void CamVobChanged()                                                             zCall( 0x004ABA40 );
    void TargetChanged()                                                             zCall( 0x004ABB40 );
    void SetAICamera( zCAICamera* )                                                  zCall( 0x004ABB60 );
    ~zCPathSearch()                                                                  zCall( 0x004ACCF0 );
    int SphereSearch( zSEvasionSearchDesc const& )                                   zCall( 0x004ACE90 );
    int SwitchSearch( zSEvasionSearchDesc const& )                                   zCall( 0x004AD570 );
    int ShoulderSearch( zSEvasionSearchDesc const& )                                 zCall( 0x004AD580 );
    int PanicSearch( zSEvasionSearchDesc const& )                                    zCall( 0x004AD960 );
    void CalcStateScores( zSPathSearchState& )                                       zCall( 0x004ADE80 );
    zTPathLerpMode GetBestLerpMode( zSPathSearchState const& )                       zCall( 0x004AE200 );
    zTPathLerpMode GetBestLerpMode( zVEC3 const&, zVEC3 const& )                     zCall( 0x004AE3B0 );
    zVEC3 DoSlerpRotQuat( zCQuat const&, zCQuat const&, float const&, float const& ) zCall( 0x004AE470 );
    int FindBestEvasion( zSPathSearchOptions& )                                      zCall( 0x004AE6B0 );
    int CanEvadeTo( zSPathSearchState& )                                             zCall( 0x004AEB60 );
    int FindEvasionSequence( zCArray<zSEvasionSearchDesc>& )                         zCall( 0x004AEBC0 );
    int FES_PlayerInvisible_Moved( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004AF000 );
    int FES_PlayerInvisible_Moved_BW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004B1070 );
    int FES_PlayerInvisible_Moved_FW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004B19B0 );
    int FES_IdealCone( zCArray<zSEvasionSearchDesc>& )                               zCall( 0x004B2300 );
    int FES_PlayerInvisible_Standing( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004B41F0 );
    int FES_PlayerInvisible_Rotated( zCArray<zSEvasionSearchDesc>& )                 zCall( 0x004B4240 );
    int FES_PlayerTargetInvisible( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004B4AC0 );
    int FES_CamHitWall( zCArray<zSEvasionSearchDesc>& )                              zCall( 0x004B4B00 );
    int FES_NoEvasionFound( zCArray<zSEvasionSearchDesc>& )                          zCall( 0x004B4B10 );
    int EvasionPossible()                                                            zCall( 0x004B4CF0 );
    int IsPointValid( zVEC3 const&, int, zTPoseFailReason& )                         zCall( 0x004B4D00 );
    int IsPointNearWall( zVEC3 const& )                                              zCall( 0x004B57A0 );
    int LineOfSight( zVEC3 const&, zVEC3 const& )                                    zCall( 0x004B59E0 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                            zCall( 0x004B5A50 );
    zVEC3& GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                     zCall( 0x004B5D10 );
    static zSPathSearchResult* GetReport()                                           zCall( 0x004ACC40 );
    static zCPathSearch* GetSearch()                                                 zCall( 0x004ACCA0 );

    // user API
    #include "zCPathSearch.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZAI_CAMERA__CORE_H__VER1__