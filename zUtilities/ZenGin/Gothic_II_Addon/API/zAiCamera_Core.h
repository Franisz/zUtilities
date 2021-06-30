// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA__CORE_H__VER3__
#define __ZAI_CAMERA__CORE_H__VER3__

#include "zKbSplines.h"

namespace Gothic_II_Addon {
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

  struct zSEvasionSearchDesc {
    struct zSEvasionSearchOptions {
      zVEC3 scSign;
      zVEC3 scQuality;
      zVEC3 scStart;
      zVEC3 scEnd;
      zSTRING scSequence;
      zSTRING scName;

      void zSEvasionSearchOptions_OnInit()                                zCall( 0x004AB060 );
      ~zSEvasionSearchOptions()                                           zCall( 0x004A7540 );
      zSEvasionSearchOptions()                                            zInit( zSEvasionSearchOptions_OnInit() );
      zSEvasionSearchOptions& operator =( zSEvasionSearchOptions const& ) zCall( 0x004B0EA0 );

      // user API
      #include "zSEvasionSearchDesc_zSEvasionSearchOptions.inl"
    };

    bool32(* searchFunc )( const zSEvasionSearchDesc& );
    zSTRING searchName;
    zCArray<zSEvasionSearchOptions> sphereSearchList;

    void zSEvasionSearchDesc_OnInit()                             zCall( 0x004A8F00 );
    zSEvasionSearchDesc()                                         zInit( zSEvasionSearchDesc_OnInit() );
    ~zSEvasionSearchDesc()                                        zCall( 0x004A8F30 );
    zSEvasionSearchDesc& operator =( zSEvasionSearchDesc const& ) zCall( 0x004B1190 );

    // user API
    #include "zSEvasionSearchDesc.inl"
  };

  struct zSPathSearchResult {
    int foundEvasion;
    zVEC3 p1;
    zVEC3 p2;
    zCQuat r1;
    zCQuat r2;
    zTPathLerpMode bestLerpMode;
    int lerpModes;
    zCArray<zCPositionKey*>resPath;
    float avgScore;
    float bestScore;
    float veloTrans;
    float veloRot;

    void zSPathSearchResult_OnInit() zCall( 0x004A6D60 );
    ~zSPathSearchResult()            zCall( 0x004A40C0 );
    zSPathSearchResult()             zInit( zSPathSearchResult_OnInit() );

    // user API
    #include "zSPathSearchResult.inl"
  };

  struct zSPathSearchState {
    float startAzi;
    float startElev;
    float startRange;
    float endAzi;
    float endElev;
    float endRange;
    float bestAzi;
    float bestElev;
    float bestRange;
    zMAT4 trafoCamToWorld;
    zTPathLerpMode bestLerpMode;
    int lerpModes;
    float totalScore;
    zSTRING sphereSearchName;
    zSTRING sphereSearchSegment;

    zSPathSearchState() {}
    ~zSPathSearchState() zCall( 0x004A5A70 );

    // user API
    #include "zSPathSearchState.inl"
  };

  struct zSPathSearchState_Internal {
    float maxRange;
    zVEC3 foundPos;
    zMAT4 trafoCamToWorld;
    zTPathLerpMode bestLerpMode;
    float scoreLerpMode;
    float scoreDistToIdealPos;
    float scoreFoundNumNpcs;
    float scoreFoundNumBBoxes;
    float scoreFoundNumTargets;
    float scorePlayerVisibility;
    float scoreDistToLastEvasion;
    float totalScore;

    void zSPathSearchState_Internal_OnInit() zCall( 0x004A6A30 );
    zSPathSearchState_Internal()             zInit( zSPathSearchState_Internal_OnInit() );

    // user API
    #include "zSPathSearchState_Internal.inl"
  };

  class zCSphereCoordsCache {
  public:
    struct zSRangeSphereCoord {
      float range;
      zSPathSearchState_Internal searchState;

      zSRangeSphereCoord() {}

      // user API
      #include "zCSphereCoordsCache_zSRangeSphereCoord.inl"
    };

    struct zSElevSphereCoord {
      float elev;
      float maxRange;
      zCArraySort<zSRangeSphereCoord*> rangeCoords;

      zSElevSphereCoord() {}
      ~zSElevSphereCoord() zCall( 0x004A6A10 );

      // user API
      #include "zCSphereCoordsCache_zSElevSphereCoord.inl"
    };

    struct zSAziSphereCoord {
      float azi;
      zCArraySort<zSElevSphereCoord*> elevCoords;

      zSAziSphereCoord() {}
      ~zSAziSphereCoord() zCall( 0x004A69F0 );

      // user API
      #include "zCSphereCoordsCache_zSAziSphereCoord.inl"
    };

    zCArraySort<zSAziSphereCoord*> aziCoords;

    void zCSphereCoordsCache_OnInit()                                                                zCall( 0x004A6B90 );
    int GetSphereCoordLazy( float const&, float const&, float const&, zSPathSearchState_Internal*& ) zCall( 0x004A5C70 );
    void GetBestScoredSearch( float&, float&, float&, zSPathSearchState_Internal*& )                 zCall( 0x004A6A40 );
    zCSphereCoordsCache()                                                                            zInit( zCSphereCoordsCache_OnInit() );
    ~zCSphereCoordsCache()                                                                           zCall( 0x004A6BB0 );
    void DeleteList()                                                                                zCall( 0x004A6C10 );

    // user API
    #include "zCSphereCoordsCache.inl"
  };

  class zCPathSearch {
  public:
    struct zSPathSearchOptions {
      int searchFlags;
      zTPoseFailReason poseFailReason;
      zTPathLerpMode minLerpMode;
      float bestScore;
      float minScore;
      float startAzi;
      float startElev;
      float startRange;
      float endAzi;
      float endElev;
      float endRange;
      float quality;

      zSPathSearchOptions() {}

      // user API
      #include "zCPathSearch_zSPathSearchOptions.inl"
    };

    zSPathSearchState bestSearchState;
    zSPathSearchState lastSearchState;
    int ignoreSearchFlags;
    zCAICamera* camai;
    zCVob* camVob;
    zCVob* target;
    zCWorld* world;
    int collisionEnabled;
    zSPathSearchOptions searchOptions;
    zSPathSearchResult evasionSearchReport;
    zCMovementTracker* moveTracker;
    zCSphereCoordsCache searchCache;
    zVEC3 lastTriedPosition;
    zTBSphere3D POISphere;
    zCArray<bool32(* * )( const zSEvasionSearchDesc& )> searchFuncs;

    void zCPathSearch_OnInit()                                                       zCall( 0x004A5890 );
    zCPathSearch()                                                                   zInit( zCPathSearch_OnInit() );
    void CamVobChanged()                                                             zCall( 0x004A5B40 );
    void TargetChanged()                                                             zCall( 0x004A5C40 );
    void SetAICamera( zCAICamera* )                                                  zCall( 0x004A5C60 );
    ~zCPathSearch()                                                                  zCall( 0x004A6DD0 );
    int SphereSearch( zSEvasionSearchDesc const& )                                   zCall( 0x004A6F60 );
    int SwitchSearch( zSEvasionSearchDesc const& )                                   zCall( 0x004A75C0 );
    int ShoulderSearch( zSEvasionSearchDesc const& )                                 zCall( 0x004A75D0 );
    int PanicSearch( zSEvasionSearchDesc const& )                                    zCall( 0x004A79B0 );
    void CalcStateScores( zSPathSearchState& )                                       zCall( 0x004A7EC0 );
    zTPathLerpMode GetBestLerpMode( zSPathSearchState const& )                       zCall( 0x004A81E0 );
    zTPathLerpMode GetBestLerpMode( zVEC3 const&, zVEC3 const& )                     zCall( 0x004A8350 );
    zVEC3 DoSlerpRotQuat( zCQuat const&, zCQuat const&, float const&, float const& ) zCall( 0x004A8430 );
    int FindBestEvasion( zSPathSearchOptions& )                                      zCall( 0x004A8670 );
    int CanEvadeTo( zSPathSearchState& )                                             zCall( 0x004A8B40 );
    int FindEvasionSequence( zCArray<zSEvasionSearchDesc>& )                         zCall( 0x004A8BA0 );
    int FES_PlayerInvisible_Moved( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004A8FD0 );
    int FES_PlayerInvisible_Moved_BW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004AB0A0 );
    int FES_PlayerInvisible_Moved_FW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004AB9E0 );
    int FES_IdealCone( zCArray<zSEvasionSearchDesc>& )                               zCall( 0x004AC340 );
    int FES_PlayerInvisible_Standing( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004AE200 );
    int FES_PlayerInvisible_Rotated( zCArray<zSEvasionSearchDesc>& )                 zCall( 0x004AE250 );
    int FES_PlayerTargetInvisible( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004AEAD0 );
    int FES_CamHitWall( zCArray<zSEvasionSearchDesc>& )                              zCall( 0x004AEB10 );
    int FES_NoEvasionFound( zCArray<zSEvasionSearchDesc>& )                          zCall( 0x004AEB20 );
    int EvasionPossible()                                                            zCall( 0x004AECF0 );
    int IsPointValid( zVEC3 const&, int, zTPoseFailReason& )                         zCall( 0x004AED00 );
    int IsPointNearWall( zVEC3 const& )                                              zCall( 0x004AF5D0 );
    int LineOfSight( zVEC3 const&, zVEC3 const& )                                    zCall( 0x004AF7F0 );
    int CorrectPosForNearClip( zVEC3& )                                              zCall( 0x004AF880 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                            zCall( 0x004AFC70 );
    zVEC3& GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                     zCall( 0x004AFF20 );
    static zSPathSearchResult* GetReport()                                           zCall( 0x004A6D20 );
    static zCPathSearch* GetSearch()                                                 zCall( 0x004A6D80 );

    // user API
    #include "zCPathSearch.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZAI_CAMERA__CORE_H__VER3__