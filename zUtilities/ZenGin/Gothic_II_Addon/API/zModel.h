// Supported with union (c) 2018-2021 Union team

#ifndef __ZMODEL_H__VER3__
#define __ZMODEL_H__VER3__

#include "zVisual.h"
#include "zProgMesh.h"
#include "zResource.h"
#include "zScanDir.h"
#include "zSound.h"

namespace Gothic_II_Addon {
  const float zMDL_ANI_BLEND_IN_ZERO   = float_MAX;
  const float zMDL_ANI_BLEND_OUT_ZERO  =-float_MAX;
  const int zMDL_ANIEVENT_MAXSTRING    = 4;
  const int zMAN_VERS                  = 12;
  const int zMDL_MAX_ANIS_PARALLEL     = 6;
  const int zMDL_MAX_MESHLIBS_PARALLEL = 4;
  const int zMDL_VELRING_SIZE          = 8;
  const int MAX_ANIHISTORY             = 16;

  enum zTMdl_AniDir {
    zMDL_ANIDIR_FORWARD,
    zMDL_ANIDIR_REVERSE,
    zMDL_ANIDIR_ENDFASTEST
  };

  enum zTMdl_AniEventType {
    zMDL_EVENT_TAG,
    zMDL_EVENT_SOUND,
    zMDL_EVENT_SOUND_GRND,
    zMDL_EVENT_ANIBATCH,
    zMDL_EVENT_SWAPMESH,
    zMDL_EVENT_HEADING,
    zMDL_EVENT_PFX,
    zMDL_EVENT_PFX_GRND,
    zMDL_EVENT_PFX_STOP,
    zMDL_EVENT_SETMESH,
    zMDL_EVENT_MM_STARTANI,
    zMDL_EVENT_CAM_TREMOR
  };

  enum zTMdl_AniType {
    zMDL_ANI_TYPE_NORMAL,
    zMDL_ANI_TYPE_BLEND,
    zMDL_ANI_TYPE_SYNC,
    zMDL_ANI_TYPE_ALIAS,
    zMDL_ANI_TYPE_BATCH,
    zMDL_ANI_TYPE_COMB,
    zMDL_ANI_TYPE_DISABLED
  };

  enum zTModelProtoImportMAXFlags {
    zMDL_MAX_IMPORT_ANI         = 1,
    zMDL_MAX_IMPORT_MESH        = 2,
    zMDL_MAX_IMPORT_TREE        = 4,
    zMDL_MAX_IMPORT_PASS_ZCMESH = 8,
    zMDL_MAX_IMPORT_NO_LOD      = 16
  };

  // sizeof 3Ch
  class zCModelMeshLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCModelMeshLib )

    // sizeof 08h
    struct zTNodeMesh {
    public:
      zCVisual* visual; // sizeof 04h    offset 00h
      int nodeIndex;    // sizeof 04h    offset 04h

      // user API
      #include "zCModelMeshLib_zTNodeMesh.inl"
    };

    zCArray<zTNodeMesh> meshNodeList;          // sizeof 0Ch    offset 24h
    zCArray<zCMeshSoftSkin*> meshSoftSkinList; // sizeof 0Ch    offset 30h

    void zCModelMeshLib_OnInit()                                                            zCall( 0x00593B30 );
    zCModelMeshLib()                                                                        zInit( zCModelMeshLib_OnInit() );
    void ReleaseData()                                                                      zCall( 0x0059F090 );
    void AllocNumNodeVisuals( int )                                                         zCall( 0x0059F100 );
    void AddMeshSoftSkin( zCMeshSoftSkin* )                                                 zCall( 0x0059F170 );
    void AddNodeVisual( int, zCVisual* )                                                    zCall( 0x0059F250 );
    void ApplyToModel( zCModel* )                                                           zCall( 0x0059F350 );
    void ApplyToModel( zCModelPrototype* )                                                  zCall( 0x0059F4C0 );
    void RemoveFromModel( zCModel* )                                                        zCall( 0x0059F620 );
    void BuildFromModel( zCModelPrototype* )                                                zCall( 0x0059F710 );
    void BuildFromModel( zCModel* )                                                         zCall( 0x0059F900 );
    void SaveMDM( zCModelPrototype* )                                                       zCall( 0x0059FB30 );
    void SaveMDM( zCFileBIN&, zCModelPrototype* )                                           zCall( 0x0059FD40 );
    static zCObject* _CreateNewInstance()                                                   zCall( 0x00584870 );
    static unsigned long GetMDMFileVersion()                                                zCall( 0x0059FB00 );
    static int LoadMDM( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** )     zCall( 0x005A01D0 );
    static int LoadMDM_Try( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** ) zCall( 0x005A05A0 );
    static int LoadMDM( zCFileBIN&, zCModelPrototype*, zCModel*, zCModelMeshLib** )         zCall( 0x005A07A0 );
    static int ConvertMDM( zSTRING const&, zCModelPrototype* )                              zCall( 0x005A12E0 );
    virtual zCClassDef* _GetClassDef() const                                                zCall( 0x0057EA30 );
    virtual ~zCModelMeshLib()                                                               zCall( 0x0059EFC0 );

    // user API
    #include "zCModelMeshLib.inl"
  };

  // sizeof 94h
  class zCModelAniEvent {
  public:

    zTMdl_AniEventType aniEventType;            // sizeof 04h    offset 00h
    int frameNr;                                // sizeof 04h    offset 04h
    zSTRING tagString;                          // sizeof 14h    offset 08h
    zSTRING string[zMDL_ANIEVENT_MAXSTRING];    // sizeof 50h    offset 1Ch
    float value1;                               // sizeof 04h    offset 6Ch
    float value2;                               // sizeof 04h    offset 70h
    float value3;                               // sizeof 04h    offset 74h
    float value4;                               // sizeof 04h    offset 78h
    zCArray<zCSoundFX*> soundList;              // sizeof 0Ch    offset 7Ch
    zCArray<zCParticleEmitter*> pfxEmitterList; // sizeof 0Ch    offset 88h

    void zCModelAniEvent_OnInit() zCall( 0x00588280 );
    zCModelAniEvent()             zInit( zCModelAniEvent_OnInit() );
    ~zCModelAniEvent()            zCall( 0x00588320 );
    void Save( zCFileBIN& ) const zCall( 0x00588400 );
    void Load( zCFileBIN& )       zCall( 0x00588560 );

    // user API
    #include "zCModelAniEvent.inl"
  };

  // sizeof C0h
  class zCModelNode {
  public:
    zCModelNode* parentNode;       // sizeof 04h    offset 00h
    zSTRING nodeName;              // sizeof 14h    offset 04h
    zCVisual* visual;              // sizeof 04h    offset 18h
    zMAT4 trafo;                   // sizeof 40h    offset 1Ch
    zVEC3 nodeRotAxis;             // sizeof 0Ch    offset 5Ch
    float nodeRotAngle;            // sizeof 04h    offset 68h
    zVEC3 translation;             // sizeof 0Ch    offset 6Ch
    zMAT4 trafoObjToWorld;         // sizeof 40h    offset 78h
    zMAT4* nodeTrafoList;          // sizeof 04h    offset B8h
    zCModelNodeInst* lastInstNode; // sizeof 04h    offset BCh

    void zCModelNode_OnInit()                     zCall( 0x005849C0 );
    void zCModelNode_OnInit( zCModelNode const& ) zCall( 0x00584B00 );
    zCModelNode()                                 zInit( zCModelNode_OnInit() );
    zCModelNode( zCModelNode const& a0 )          zInit( zCModelNode_OnInit( a0 ));
    ~zCModelNode()                                zCall( 0x00584C90 );
    void SetNodeVisualS( zCVisual* )              zCall( 0x00584D30 );

    // user API
    #include "zCModelNode.inl"
  };

#pragma pack( push, 1 )
  // sizeof 0Ch
  struct zTMdl_AniSample {
  public:
    unsigned short rotation[3]; // sizeof 06h    offset 00h
    unsigned short position[3]; // sizeof 06h    offset 06h

    // static properties
    static float& samplePosScaler;
    static float& samplePosRangeMin;

    // user API
    #include "zTMdl_AniSample.inl"
  };
#pragma pack( pop )

  // sizeof E4h
  class zCModelAni : public zCObject {
  public:
    zCLASS_DECLARATION( zCModelAni )

    enum {
      zMDL_ANI_FLAG_VOB_ROT  = 1,
      zMDL_ANI_FLAG_VOB_POS  = 2,
      zMDL_ANI_FLAG_END_SYNC = 4,
      zMDL_ANI_FLAG_FLY      = 8,
      zMDL_ANI_FLAG_IDLE     = 16
    };

    zSTRING aniName;                  // sizeof 14h    offset 24h
    zSTRING ascName;                  // sizeof 14h    offset 38h
    int aniID;                        // sizeof 04h    offset 4Ch
    zSTRING aliasName;                // sizeof 14h    offset 50h
    zCList<zCModelAni> combAniList;   // sizeof 08h    offset 64h
    int layer;                        // sizeof 04h    offset 6Ch
    float blendInSpeed;               // sizeof 04h    offset 70h
    float blendOutSpeed;              // sizeof 04h    offset 74h
    zTBBox3D aniBBox3DObjSpace;       // sizeof 18h    offset 78h
    float collisionVolumeScale;       // sizeof 04h    offset 90h
    zCModelAni* nextAni;              // sizeof 04h    offset 94h
    zSTRING nextAniName;              // sizeof 14h    offset 98h
    zCModelAniEvent* aniEvents;       // sizeof 04h    offset ACh
    float fpsRate;                    // sizeof 04h    offset B0h
    float fpsRateSource;              // sizeof 04h    offset B4h
    int rootNodeIndex;                // sizeof 04h    offset B8h
    zCArray<int> nodeIndexList;       // sizeof 0Ch    offset BCh
    zCModelNode** nodeList;           // sizeof 04h    offset C8h
    zTMdl_AniSample* aniSampleMatrix; // sizeof 04h    offset CCh
    float samplePosRangeMin;          // sizeof 04h    offset D0h
    float samplePosScaler;            // sizeof 04h    offset D4h
    group {
      int numFrames         : 16;     // sizeof 10h    offset bit
      int numNodes          : 16;     // sizeof 10h    offset bit
      zTMdl_AniType aniType : 6;      // sizeof 06h    offset bit
      zTMdl_AniDir aniDir   : 2;      // sizeof 02h    offset bit
      int numAniEvents      : 6;      // sizeof 06h    offset bit
    };
    group {
      byte flagVobRot      : 1;       // sizeof 01h    offset bit
      byte flagVobPos      : 1;       // sizeof 01h    offset bit
      byte flagEndSync     : 1;       // sizeof 01h    offset bit
      byte flagFly         : 1;       // sizeof 01h    offset bit
      byte flagIdle        : 1;       // sizeof 01h    offset bit
      byte flagInPlace     : 1;       // sizeof 01h    offset bit
      byte flagStaticCycle : 1;       // sizeof 01h    offset bit
	  }
    aniFlags;                         // sizeof 01h    offset E0h

    void zCModelAni_OnInit()                                         zCall( 0x00585120 );
    zCModelAni()                                                     zInit( zCModelAni_OnInit() );
    void PrecacheAniEventData()                                      zCall( 0x00585530 );
    float GetAniVelocity() const                                     zCall( 0x00585600 );
    zVEC3 GetAniTranslation() const                                  zCall( 0x00585780 );
    void AddTrafoMatrix( zMAT4** )                                   zCall( 0x005858C0 );
    zCQuat GetQuat( int, int ) const                                 zCall( 0x00585D60 );
    zVEC3 GetTrans( int, int ) const                                 zCall( 0x00585DC0 );
    void SetTrans( int, int, zVEC3 const& )                          zCall( 0x00585E60 );
    void SetQuat( int, int, zCQuat const& )                          zCall( 0x00585EE0 );
    void AddNodeList( zCTree<zCModelNode>** )                        zCall( 0x00585F80 );
    void SetFlags( zSTRING const& )                                  zCall( 0x00585FF0 );
    void SetBlendingSec( float, float )                              zCall( 0x005860A0 );
    void GetBlendingSec( float&, float& ) const                      zCall( 0x00586100 );
    void CorrectRootNodeIdleMovement()                               zCall( 0x00586160 );
    void CalcInPlaceFlag()                                           zCall( 0x005862C0 );
    int ResolveAlias( zCModelPrototype* )                            zCall( 0x005864A0 );
    int ResolveComb( zCModelPrototype* )                             zCall( 0x00586780 );
    void SaveMAN( zCModelPrototype*, zSTRING const& )                zCall( 0x00586E80 );
    int LoadMAN( zSTRING const&, zCModelPrototype*, zSTRING const& ) zCall( 0x00587740 );
    zSTRING const& GetAniName() const                                zCall( 0x0059D160 );
    zTMdl_AniType GetAniType() const                                 zCall( 0x0059D170 );
    int GetAniID() const                                             zCall( 0x006A9800 );
    static zCObject* _CreateNewInstance()                            zCall( 0x00576980 );
    virtual zCClassDef* _GetClassDef() const                         zCall( 0x005852C0 );
    virtual ~zCModelAni()                                            zCall( 0x00585300 );

    // user API
    #include "zCModelAni.inl"
  };

  // sizeof E4h
  class zCModelPrototype {
  public:
    enum zTFileSourceType {
      zFROM_MDS,
      zFROM_ASC
    };

    zCModelPrototype* next;                    // sizeof 04h    offset 00h
    zCModelPrototype* prev;                    // sizeof 04h    offset 04h
    int refCtr;                                // sizeof 04h    offset 08h
    zSTRING modelProtoName;                    // sizeof 14h    offset 0Ch
    zSTRING modelProtoFileName;                // sizeof 14h    offset 20h
    zCTree<zCModelNode> meshTree;              // sizeof 14h    offset 34h
    zCArraySort<zCModelAni*> protoAnis;        // sizeof 10h    offset 48h
    zCArray<zCModelAniEvent*> modelEvents;     // sizeof 0Ch    offset 58h
    zCArray<zCModelNode*> nodeList;            // sizeof 0Ch    offset 64h
    unsigned long nodeListChecksum;            // sizeof 04h    offset 70h
    zCArray<zCMeshSoftSkin*> meshSoftSkinList; // sizeof 0Ch    offset 74h
    zSTRING hierarchySourceASC;                // sizeof 14h    offset 80h
    zTBBox3D bbox3D;                           // sizeof 18h    offset 94h
    zTBBox3D bbox3DCollDet;                    // sizeof 18h    offset ACh
    zCModelPrototype* baseModelProto;          // sizeof 04h    offset C4h
    zVEC3 rootNodeTrans;                       // sizeof 0Ch    offset C8h
    zTFileSourceType fileSourceType;           // sizeof 04h    offset D4h
    zCArray<zCMesh*> sourceMeshSoftSkinList;   // sizeof 0Ch    offset D8h

    void zCModelPrototype_OnInit()                                                           zCall( 0x00588610 );
    zCModelPrototype()                                                                       zInit( zCModelPrototype_OnInit() );
    void Init()                                                                              zCall( 0x00588850 );
    ~zCModelPrototype()                                                                      zCall( 0x00588A10 );
    void Clear()                                                                             zCall( 0x00588C50 );
    void ReleaseMeshSoftSkinList()                                                           zCall( 0x00588DF0 );
    void ReleaseMeshes()                                                                     zCall( 0x00588E50 );
    int Release()                                                                            zCall( 0x00588EE0 );
    zSTRING const& GetModelProtoFileName() const                                             zCall( 0x00588F30 );
    void SetModelProtoName( zSTRING const& )                                                 zCall( 0x00588F40 );
    void SetFileSourceType( zTFileSourceType )                                               zCall( 0x005890D0 );
    int PrepareAsModelProtoOverlay( zCModelPrototype* )                                      zCall( 0x005894A0 );
    void CalcNodeListChecksum()                                                              zCall( 0x00589870 );
    void CollectNodeMeshes( zCArray<zCModelNode*>& )                                         zCall( 0x005898D0 );
    zCModelNode* SearchNode( zSTRING const& )                                                zCall( 0x00589AF0 );
    zCTree<zCModelNode>* FindMeshTreeNode( zSTRING const&, zCTree<zCModelNode>* )            zCall( 0x00589BA0 );
    int FindMeshTreeNodeIndex( zSTRING const&, zCTree<zCModelNode>* )                        zCall( 0x00589C50 );
    int FindNodeListIndex( zSTRING const& )                                                  zCall( 0x00589D10 );
    void AddAni( zCModelAni* )                                                               zCall( 0x00589DB0 );
    int __fastcall SearchAniIndex( zSTRING const& ) const                                    zCall( 0x00589FC0 );
    zCModelAni* SearchAni( zSTRING const& ) const                                            zCall( 0x0058A090 );
    void DescribeTree( zCTree<zCModelNode>*, int )                                           zCall( 0x0058A0B0 );
    int LoadMDH( zSTRING const& )                                                            zCall( 0x0058A300 );
    int LoadMDH( zCFileBIN& )                                                                zCall( 0x0058A560 );
    void SaveMDH()                                                                           zCall( 0x0058ABC0 );
    void SaveMDH( zCFileBIN& )                                                               zCall( 0x0058ADC0 );
    void ConvertVec3( zVEC3& )                                                               zCall( 0x0058B2E0 );
    void ConvertAngle( float& )                                                              zCall( 0x0058B300 );
    void SkipBlock()                                                                         zCall( 0x0058B310 );
    void SkipBlockCmt()                                                                      zCall( 0x0058B390 );
    void ReadComment()                                                                       zCall( 0x0058B460 );
    void ReadScene( float& )                                                                 zCall( 0x0058B470 );
    zVEC3 ReadTriple()                                                                       zCall( 0x0058B810 );
    zMAT4 ReadNodeTM( zCModelNode* )                                                         zCall( 0x0058BA00 );
    void ReadVertexList( zCMesh*, int )                                                      zCall( 0x0058BEA0 );
    zTMatIDList* ReadFaceList( zCMesh*, int )                                                zCall( 0x0058C0D0 );
    zVEC2* ReadTVertexList( int )                                                            zCall( 0x0058C5D0 );
    void ReadTFaceList( zCMesh*, zVEC2*, int )                                               zCall( 0x0058C7D0 );
    void ReadSoftSkinVertList()                                                              zCall( 0x0058CA40 );
    zCMesh* ReadMesh( int, zCModelNode*, int )                                               zCall( 0x0058DC00 );
    void ReadMeshAnimation( zCModelNode*, int )                                              zCall( 0x0058DFE0 );
    void ReadPosTrack( zMAT4* )                                                              zCall( 0x0058E160 );
    void ReadRotTrack( zMAT4* )                                                              zCall( 0x0058E340 );
    void ReadTMAnimation( zCModelNode*, zMAT4*& )                                            zCall( 0x0058E5F0 );
    void LocalizeTrafos( zCTree<zCModelNode>*, zCTree<zCModelNode>* )                        zCall( 0x0058EC30 );
    void ReadMapDiffuse( zCMaterial* )                                                       zCall( 0x0058ED60 );
    zCMaterial* ReadMaterial()                                                               zCall( 0x0058F1D0 );
    zCMaterial* ReadWireframeColor()                                                         zCall( 0x0058F840 );
    void AssignMeshNodeMaterials( zCMesh*, zTMatIDList*, int )                               zCall( 0x0058FAE0 );
    void TransformNodeVisual( zCModelNode*, zMAT4 const& )                                   zCall( 0x0058FBD0 );
    void ProcessMeshNode( zCModelNode*, zCTree<zCModelNode>*, int, int, int& )               zCall( 0x0058FC30 );
    void ReadGeomobject( zMAT4*&, zCTree<zCModelNode>*& )                                    zCall( 0x00590040 );
    void ReadMaterialList()                                                                  zCall( 0x005915C0 );
    void Load3DSMAXAsc( zCModelAni*&, zSTRING const&, zSTRING const&, int, int, int, float ) zCall( 0x00591850 );
    void CalcAniBBox( zCModelAni* )                                                          zCall( 0x005928D0 );
    void ResolveReferences()                                                                 zCall( 0x00592E00 );
    void SkipBlockMDS( int )                                                                 zCall( 0x00593100 );
    int ReadMeshAndTreeMSB( int&, zCFileBIN& )                                               zCall( 0x00593180 );
    void ReadMeshAndTree( int&, zCFileBIN& )                                                 zCall( 0x005935C0 );
    void RegisterMesh( zCFileBIN& )                                                          zCall( 0x00593C40 );
    int ReadAniEnumMSB( int, zCFileBIN& )                                                    zCall( 0x00593ED0 );
    void ReadAniEnum( int, zCFileBIN& )                                                      zCall( 0x00596C00 );
    int ReadModelMSB( zCFileBIN& )                                                           zCall( 0x0059D250 );
    void ReadModel( zCFileBIN& )                                                             zCall( 0x0059D4C0 );
    int LoadModelScriptMSB( zSTRING const& )                                                 zCall( 0x0059D7B0 );
    int LoadModelScript( zSTRING const& )                                                    zCall( 0x0059DDD0 );
    int LoadModelASC( zSTRING const& )                                                       zCall( 0x0059E760 );
    static int NumInList()                                                                   zCall( 0x00588F10 );
    static zCModelPrototype* Load( zSTRING const&, zCModelPrototype* )                       zCall( 0x00589250 );
    static zCModelPrototype* SearchName( zSTRING )                                           zCall( 0x00589A30 );
    static unsigned long GetMDHFileVersion()                                                 zCall( 0x0058A2F0 );
    static unsigned long GetMDSFileVersion()                                                 zCall( 0x005930F0 );

    // static properties
    static int& s_ignoreAnis;
    static int& s_autoConvertAnis;
    static int& s_autoConvertMeshes;
    static zCModelPrototype*& s_modelRoot;

    // user API
    #include "zCModelPrototype.inl"
  };

  // sizeof 88h
  class zCModelAniActive {
  public:
    zCModelAni* protoAni;           // sizeof 04h    offset 00h
    zCModelAni* nextAni;            // sizeof 04h    offset 04h
    int advanceDir;                 // sizeof 04h    offset 08h
    float actFrame;                 // sizeof 04h    offset 0Ch
    int actAniEvent;                // sizeof 04h    offset 10h
    float combAniX;                 // sizeof 04h    offset 14h
    float combAniY;                 // sizeof 04h    offset 18h
    int isFadingOut;                // sizeof 04h    offset 1Ch
    int isFirstTime;                // sizeof 04h    offset 20h
    zCModelAni* nextAniOverride;    // sizeof 04h    offset 24h
    float blendInOverride;          // sizeof 04h    offset 28h
    float blendOutOverride;         // sizeof 04h    offset 2Ch
    zVEC3 lastPos;                  // sizeof 0Ch    offset 30h
    zVEC3 thisPos;                  // sizeof 0Ch    offset 3Ch
    zCQuat lastRotQuat;             // sizeof 10h    offset 48h
    zCQuat thisRotQuat;             // sizeof 10h    offset 58h
    zCQuat freezeRotQuat;           // sizeof 10h    offset 68h
    int rotFirstTime;               // sizeof 04h    offset 78h
    float transWeight;              // sizeof 04h    offset 7Ch
    zTAniAttachment* aniAttachment; // sizeof 04h    offset 80h
    float randAniTimer;             // sizeof 04h    offset 84h

    void zCModelAniActive_OnInit()          zCall( 0x00576B00 );
    zCModelAniActive()                      zInit( zCModelAniActive_OnInit() );
    ~zCModelAniActive()                     zCall( 0x00576BF0 );
    void SetDirection( zTMdl_AniDir )       zCall( 0x00576C10 );
    float GetProgressPercent() const        zCall( 0x00576C60 );
    void SetProgressPercent( float )        zCall( 0x00576CA0 );
    void SetActFrame( float )               zCall( 0x00576CF0 );
    void DoCombineAni( zCModel*, int, int ) zCall( 0x0057FDB0 );

    // user API
    #include "zCModelAniActive.inl"
  };

  // sizeof 28h
  class zCModelTexAniState {
  public:
    enum {
      zMDL_MAX_ANI_CHANNELS = 2,
      zMDL_MAX_TEX          = 4
    };

    int numNodeTex;                                        // sizeof 04h    offset 00h
    zCTexture** nodeTexList;                               // sizeof 04h    offset 04h
    int actAniFrames[zMDL_MAX_ANI_CHANNELS][zMDL_MAX_TEX]; // sizeof 20h    offset 08h

    void zCModelTexAniState_OnInit()                                      zCall( 0x00576D40 );
    zCModelTexAniState()                                                  zInit( zCModelTexAniState_OnInit() );
    ~zCModelTexAniState()                                                 zCall( 0x00576D60 );
    void DeleteTexList()                                                  zCall( 0x00576D80 );
    void UpdateTexList()                                                  zCall( 0x00576DA0 );
    void SetChannelVariation( int, int, zSTRING* )                        zCall( 0x00576DE0 );
    void BuildTexListFromMeshLib( zCModelMeshLib* )                       zCall( 0x00576E50 );
    void BuildTexListFromMesh( zCMesh* )                                  zCall( 0x00576ED0 );
    void BuildTexListFromProgMesh( zCProgMeshProto* )                     zCall( 0x00577060 );
    void AddTexListFromMeshLib( zCModelMeshLib*, zCArray<zCTexture*>& )   zCall( 0x005771D0 );
    void AddTexListFromMesh( zCMesh*, zCArray<zCTexture*>& )              zCall( 0x00577430 );
    void AddTexListFromProgMesh( zCProgMeshProto*, zCArray<zCTexture*>& ) zCall( 0x00577590 );
    void FinishTexList( zCArray<zCTexture*>& )                            zCall( 0x005776E0 );

    // user API
    #include "zCModelTexAniState.inl"
  };

#pragma pack( push, 1 )
  // sizeof 198h
  class zCModelNodeInst {
  public:
    enum {
      zMDL_BLEND_STATE_FADEIN,
      zMDL_BLEND_STATE_CONST,
      zMDL_BLEND_STATE_FADEOUT
    };

    // sizeof 20h
    struct zTNodeAni {
      zCModelAniActive* modelAni; // sizeof 04h    offset 00h
      float weight;               // sizeof 04h    offset 04h
      float weightSpeed;          // sizeof 04h    offset 08h
      int blendState;             // sizeof 04h    offset 0Ch
      zCQuat quat;                // sizeof 10h    offset 10h

      zTNodeAni() {}

      // user API
      #include "zCModelNodeInst_zTNodeAni.inl"
    };

    zCModelNodeInst* parentNode;                   // sizeof 04h    offset 00h
    zCModelNode* protoNode;                        // sizeof 04h    offset 04h
    zCVisual* nodeVisual;                          // sizeof 04h    offset 08h
    zMAT4 trafo;                                   // sizeof 40h    offset 0Ch
    zMAT4 trafoObjToCam;                           // sizeof 40h    offset 4Ch
    zTBBox3D bbox3D;                               // sizeof 18h    offset 8Ch
    zCModelTexAniState texAniState;                // sizeof 28h    offset A4h
    zTNodeAni nodeAniList[zMDL_MAX_ANIS_PARALLEL]; // sizeof C0h    offset CCh
    int numNodeAnis;                               // sizeof 04h    offset 18Ch
    int masterAni;                                 // sizeof 04h    offset 190h
    float masterAniSpeed;                          // sizeof 04h    offset 194h

    void zCModelNodeInst_OnInit()                            zCall( 0x00577870 );
    void zCModelNodeInst_OnInit( zCModelNode* )              zCall( 0x00577940 );
    zCModelNodeInst()                                        zInit( zCModelNodeInst_OnInit() );
    zCModelNodeInst( zCModelNode* a0 )                       zInit( zCModelNodeInst_OnInit( a0 ));
    ~zCModelNodeInst()                                       zCall( 0x00577A30 );
    void Init()                                              zCall( 0x00577AB0 );
    void InitByModelProtoNode( zCModelNode* )                zCall( 0x00577B40 );
    void SetNodeVisualS( zCVisual*, int )                    zCall( 0x00577BF0 );
    void AddNodeAni( zCModelAniActive* )                     zCall( 0x0057EAF0 );
    void RemoveAllNodeAnis()                                 zCall( 0x0057ED20 );
    void RemoveNodeAni( zCModelAniActive* )                  zCall( 0x0057ED30 );
    void FindMasterAni()                                     zCall( 0x0057EE20 );
    void FadeOutNodeAni( zCModelAniActive* )                 zCall( 0x0057EE90 );
    void CalcWeights( zCModel* )                             zCall( 0x0057F470 );
    void AddToNodeAniWeight( int, float )                    zCall( 0x0057F6B0 );
    void CalcBlending( zCModel* )                            zCall( 0x0057F720 );
    int GetNodeAniListIndex( zCModelAniActive const* ) const zCall( 0x0057F8B0 );

    // user API
    #include "zCModelNodeInst.inl"
  };
#pragma pack( pop )

  // sizeof 08h
  struct zTRandAni {
    int randAniProtoID; // sizeof 04h    offset 00h
    int prob;           // sizeof 04h    offset 04h

    zTRandAni() {}

    // user API
    #include "zTRandAni.inl"
  };

  // sizeof 18h
  struct zTAniAttachment {
    int aniID;                      // sizeof 04h    offset 00h
    zCArray<zTRandAni> randAniList; // sizeof 0Ch    offset 04h
    float randAniFreq;              // sizeof 04h    offset 10h
    int randAniProbSum;             // sizeof 04h    offset 14h

    void zTAniAttachment_OnInit() zCall( 0x00583360 );
    ~zTAniAttachment()            zCall( 0x00583340 );
    zTAniAttachment()             zInit( zTAniAttachment_OnInit() );

    // user API
    #include "zTAniAttachment.inl"
  };

  // sizeof 204h
  class zCModel : public zCVisualAnimate {
  public:
    zCLASS_DECLARATION( zCModel )

    enum {
      zMDL_DYNLIGHT_SCALEPRELIT = 0,
      zMDL_DYNLIGHT_EXACT       = 1
    };

    enum {
      zMDL_STARTANI_DEFAULT,
      zMDL_STARTANI_ISNEXTANI,
      zMDL_STARTANI_FORCE
    };

    // sizeof 08h
    struct zTMdl_NodeVobAttachment {
    public:
      zCVob* vob;             // sizeof 04h    offset 00h
      zCModelNodeInst* mnode; // sizeof 04h    offset 04h

      // user API
      #include "zCModel_zTMdl_NodeVobAttachment.inl"
    };

    // sizeof 08h
    struct zTMdl_StartedVobFX {
    public:
      zCVob* vob;        // sizeof 04h    offset 00h
      float vobFXHandle; // sizeof 04h    offset 04h

      // user API
      #include "zCModel_zTMdl_StartedVobFX.inl"
    };

    // sizeof 08h
    struct zTAniMeshLibEntry {
    public:
      zCModelAniActive* ani;   // sizeof 04h    offset 00h
      zCModelMeshLib* meshLib; // sizeof 04h    offset 04h

      // user API
      #include "zCModel_zTAniMeshLibEntry.inl"
    };

    // sizeof 2Ch
    struct zTMeshLibEntry {
    public:
      zCModelTexAniState texAniState; // sizeof 28h    offset 00h
      zCModelMeshLib* meshLib;        // sizeof 04h    offset 28h

      // user API
      #include "zCModel_zTMeshLibEntry.inl"
    };

    int numActiveAnis;                                     // sizeof 04h    offset 34h
    zCModelAniActive* aniChannels[zMDL_MAX_ANIS_PARALLEL]; // sizeof 18h    offset 38h
    zCModelAniActive* activeAniList;                       // sizeof 04h    offset 50h
    zCArray<int> m_listOfVoiceHandles;                     // sizeof 0Ch    offset 54h
    zCVob* homeVob;                                        // sizeof 04h    offset 60h
    zCArray<zCModelPrototype*> modelProtoList;             // sizeof 0Ch    offset 64h
    zCArray<zCModelNodeInst*> nodeList;                    // sizeof 0Ch    offset 70h
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;             // sizeof 0Ch    offset 7Ch
    zCArraySort<zTAniAttachment*> aniAttachList;           // sizeof 10h    offset 88h
    zCArray<zTMdl_NodeVobAttachment>attachedVobList;       // sizeof 0Ch    offset 98h
    zCArray<zTMdl_StartedVobFX> startedVobFX;              // sizeof 0Ch    offset A4h
    zCArray<zTAniMeshLibEntry> aniMeshLibList;             // sizeof 0Ch    offset B0h
    zCArray<zTMeshLibEntry*> meshLibList;                  // sizeof 0Ch    offset BCh
    int lastTimeBBox3DTreeUpdate;                          // sizeof 04h    offset C8h
    zCArray<zCModelAniEvent*> occuredAniEvents;            // sizeof 0Ch    offset CCh
    zTBBox3D bbox3D;                                       // sizeof 18h    offset D8h
    zTBBox3D bbox3DLocalFixed;                             // sizeof 18h    offset F0h
    zTBBox3D bbox3DCollDet;                                // sizeof 18h    offset 108h
    float modelDistanceToCam;                              // sizeof 04h    offset 120h
    int n_bIsInMobInteraction;                             // sizeof 04h    offset 124h
    float fatness;                                         // sizeof 04h    offset 128h
    zVEC3 modelScale;                                      // sizeof 0Ch    offset 12Ch
    zVEC3 aniTransScale;                                   // sizeof 0Ch    offset 138h
    zVEC3 rootPosLocal;                                    // sizeof 0Ch    offset 144h
    zVEC3 vobTrans;                                        // sizeof 0Ch    offset 150h
    zVEC3 vobTransRing;                                    // sizeof 0Ch    offset 15Ch
    int newAniStarted;                                     // sizeof 04h    offset 168h
    int m_bSmoothRootNode;                                 // sizeof 04h    offset 16Ch
    float relaxWeight;                                     // sizeof 04h    offset 170h
    int m_bDrawHandVisualsOnly;                            // sizeof 04h    offset 174h
    zCQuat vobRot;                                         // sizeof 10h    offset 178h
    zVEC3 modelVelocity;                                   // sizeof 0Ch    offset 188h
    int actVelRingPos;                                     // sizeof 04h    offset 194h
    zVEC3 modelVelRing[zMDL_VELRING_SIZE];                 // sizeof 60h    offset 198h
    group {
      unsigned char isVisible         : 1;                 // sizeof 01h    offset bit
      unsigned char isFlying          : 1;                 // sizeof 01h    offset bit
      unsigned char randAnisEnabled   : 1;                 // sizeof 01h    offset bit
      unsigned char lerpSamples       : 1;                 // sizeof 01h    offset bit
      unsigned char modelScaleOn      : 1;                 // sizeof 01h    offset bit
      unsigned char doVobRot          : 1;                 // sizeof 01h    offset bit
      unsigned char nodeShadowEnabled : 1;                 // sizeof 01h    offset bit
      unsigned char dynLightMode      : 1;                 // sizeof 01h    offset bit
    };
    float timeScale;                                       // sizeof 04h    offset 1FCh
    zCModelAni** aniHistoryList;                           // sizeof 04h    offset 200h

    zCModel() {}
    void zCModel_OnInit( zCModelPrototype* )                                                                        zCall( 0x00578240 );
    zCModelAni* GetAniFromAniID( int ) const                                                                        zCall( 0x00472F50 );
    int IsAniActive( zCModelAni* )                                                                                  zCall( 0x00472F90 );
    void Init()                                                                                                     zCall( 0x00577FD0 );
    zCModel( zCModelPrototype* a0 )                                                                                 zInit( zCModel_OnInit( a0 ));
    void CopyProtoNodeList()                                                                                        zCall( 0x00578400 );
    int ApplyModelProtoOverlay( zSTRING const& )                                                                    zCall( 0x005787F0 );
    int ApplyModelProtoOverlay( zCModelPrototype* )                                                                 zCall( 0x00578840 );
    int HasAppliedModelProtoOverlay( zCModelPrototype* ) const                                                      zCall( 0x00578A90 );
    int HasAppliedModelProtoOverlay( zSTRING const& ) const                                                         zCall( 0x00578AC0 );
    void RemoveModelProtoOverlay( zSTRING const& )                                                                  zCall( 0x00578C40 );
    void RemoveModelProtoOverlay( zCModelPrototype* )                                                               zCall( 0x00578E40 );
    void CalcNodeListBBoxWorld()                                                                                    zCall( 0x00578FC0 );
    zTBBox3D GetBBox3DNodeWorld( zCModelNodeInst* )                                                                 zCall( 0x005790F0 );
    zVEC3 GetNodePositionWorld( zCModelNodeInst* )                                                                  zCall( 0x00579140 );
    void CalcModelBBox3DWorld()                                                                                     zCall( 0x00579170 );
    void SetNodeVisual( zCModelNodeInst*, zCVisual*, int )                                                          zCall( 0x005792A0 );
    void SetDynLightMode( int )                                                                                     zCall( 0x005792D0 );
    void __fastcall SetupLowestLOD( zTRenderContext& )                                                              zCall( 0x005792F0 );
    int GetLowestLODNumPolys()                                                                                      zCall( 0x00579490 );
    zVEC3* GetLowestLODPoly( int, zVEC3*& )                                                                         zCall( 0x005794B0 );
    zCMaterial* GetMaterial( int )                                                                                  zCall( 0x005794F0 );
    int GetNumMaterials() const                                                                                     zCall( 0x00579530 );
    void __fastcall RenderNodeList( zTRenderContext&, zCArray<zMAT4*>&, zCRenderLightContainer&, zTPMLightingMode ) zCall( 0x00579560 );
    void CheckNodeCollisionList( zCOBBox3D const&, zMAT4& )                                                         zCall( 0x0057A7D0 );
    void CheckNodeCollision( zCModel*, zCModelNodeInst*, zMAT4&, zCList<zCModelNodeInst>& )                         zCall( 0x0057A870 );
    zMAT4 GetTrafoNodeToModel( zCModelNodeInst* )                                                                   zCall( 0x0057A9C0 );
    void SetRandAnisEnabled( int )                                                                                  zCall( 0x0057AAF0 );
    zCModelAniActive* GetActiveAni( int ) const                                                                     zCall( 0x0057AB60 );
    zCModelAniActive* GetActiveAni( zCModelAni* ) const                                                             zCall( 0x0057ABA0 );
    void StopAni( int )                                                                                             zCall( 0x0057ABE0 );
    void StopAni( zCModelAni* )                                                                                     zCall( 0x0057AC60 );
    void StopAni( zCModelAniActive* )                                                                               zCall( 0x0057ACB0 );
    zVEC3 GetAniTransLerp( zCModelAni*, float, int ) const                                                          zCall( 0x0057AE70 );
    void StartAni( zSTRING const&, int )                                                                            zCall( 0x0057AF70 );
    void StartAni( int, int )                                                                                       zCall( 0x0057B070 );
    void StartAni( zCModelAni*, int )                                                                               zCall( 0x0057B0C0 );
    void AssertActiveAniListAlloced()                                                                               zCall( 0x0057B770 );
    void DoAniEvents( zCModelAniActive* )                                                                           zCall( 0x0057B890 );
    void __fastcall AdvanceAni( zCModelAniActive*, int& )                                                           zCall( 0x0057C7D0 );
    void AdvanceAnis()                                                                                              zCall( 0x0057CA90 );
    void SetModelScale( zVEC3 const& )                                                                              zCall( 0x0057DC30 );
    int IsStateActive( zCModelAni const* ) const                                                                    zCall( 0x0057DDA0 );
    zCModelNodeInst* SearchNode( zSTRING const& )                                                                   zCall( 0x0057DFF0 );
    int SetNodeMeshTexture( zSTRING const&, int, int, zSTRING* )                                                    zCall( 0x0057E0A0 );
    int SetMeshLibTexture( zSTRING const&, int, int, zSTRING* )                                                     zCall( 0x0057E1D0 );
    void RemoveMeshLibAll()                                                                                         zCall( 0x0057E3D0 );
    int RemoveMeshLib( zSTRING const& )                                                                             zCall( 0x0057E400 );
    int ApplyMeshLib( zSTRING const& )                                                                              zCall( 0x0057E610 );
    void UpdateMeshLibTexAniState()                                                                                 zCall( 0x0057EA70 );
    void FadeOutAni( int )                                                                                          zCall( 0x0057EF50 );
    void FadeOutAni( zCModelAni* )                                                                                  zCall( 0x0057EFE0 );
    void FadeOutAni( zCModelAniActive* )                                                                            zCall( 0x0057F020 );
    void FadeOutAnisLayerRange( int, int )                                                                          zCall( 0x0057F1F0 );
    void StopAnisLayerRange( int, int )                                                                             zCall( 0x0057F240 );
    float GetProgressPercent( zSTRING const& ) const                                                                zCall( 0x0057F290 );
    float GetProgressPercent( int ) const                                                                           zCall( 0x0057F340 );
    void SetCombineAniXY( int, float, float ) const                                                                 zCall( 0x0057F3B0 );
    int GetCombineAniXY( int, float&, float& ) const                                                                zCall( 0x0057F400 );
    void CalcNodeListAniBlending()                                                                                  zCall( 0x0057F880 );
    void CalcTransBlending()                                                                                        zCall( 0x0057F8E0 );
    void AttachChildVobToNode( zCVob*, zCModelNodeInst* )                                                           zCall( 0x005806A0 );
    void RemoveChildVobFromNode( zCVob* )                                                                           zCall( 0x005807F0 );
    zCVob* GetAttachedNodeVob( zCModelNodeInst* )                                                                   zCall( 0x00580870 );
    void RemoveAllChildVobsFromNode()                                                                               zCall( 0x005808B0 );
    void UpdateAttachedVobs()                                                                                       zCall( 0x00580900 );
    void RemoveStartedVobFX( zCVob* )                                                                               zCall( 0x00580A50 );
    zVEC3 GetVelocityRing() const                                                                                   zCall( 0x00580B00 );
    void ResetVelocity()                                                                                            zCall( 0x00580B60 );
    void GetAniMinMaxWeight( zCModelAniActive*, float&, float& )                                                    zCall( 0x00580BF0 );
    void PrintStatus( int, int )                                                                                    zCall( 0x00580E90 );
    int CorrectAniFreezer()                                                                                         zCall( 0x005815E0 );
    void psb_WriteAniBlock( zCBuffer&, int, int ) const                                                             zCall( 0x00581850 );
    void psb_ReadAniBlock( zCBuffer&, int, zCModelAniActive* )                                                      zCall( 0x005819E0 );
    void PackStateBinary( zCBuffer& )                                                                               zCall( 0x00581C30 );
    void UnpackStateBinary( zCBuffer& )                                                                             zCall( 0x00581F80 );
    void ShowAniListAdd( zCModelAni* )                                                                              zCall( 0x00582700 );
    void ShowAniList( int )                                                                                         zCall( 0x00582770 );
    zTAniAttachment* SearchAniAttachList( int ) const                                                               zCall( 0x005833A0 );
    void RemoveAniAttachment( int )                                                                                 zCall( 0x00583420 );
    void RemoveAllAniAttachments()                                                                                  zCall( 0x00583570 );
    void RemoveAllVobFX()                                                                                           zCall( 0x005835C0 );
    zTAniAttachment* GetCreateAniAttachment( int )                                                                  zCall( 0x00583650 );
    void DeleteRandAniList( int )                                                                                   zCall( 0x005838A0 );
    void InsertRandAni( int, int, int )                                                                             zCall( 0x00583930 );
    float GetRandAniFreq( int ) const                                                                               zCall( 0x00583A30 );
    void SetRandAniFreq( int, float )                                                                               zCall( 0x00583AC0 );
    void __fastcall RecalcRootPosLocal( int )                                                                       zCall( 0x00583AE0 );
    int GetAniIDFromAniName( zSTRING const& ) const                                                                 zCall( 0x00612070 );
    static zCObject* _CreateNewInstance()                                                                           zCall( 0x00576420 );
    static int AniAttachmentCompare( void const*, void const* )                                                     zCall( 0x00583370 );
    virtual zCClassDef* _GetClassDef() const                                                                        zCall( 0x005765B0 );
    virtual ~zCModel()                                                                                              zCall( 0x00577CC0 );
    virtual int Render( zTRenderContext& )                                                                          zCall( 0x0057A4E0 );
    virtual int IsBBox3DLocal()                                                                                     zCall( 0x005765C0 );
    virtual zTBBox3D GetBBox3D()                                                                                    zCall( 0x0057DF20 );
    virtual zSTRING GetVisualName()                                                                                 zCall( 0x0057DF60 );
    virtual void SetVisualUsedBy( zCVob* )                                                                          zCall( 0x005786C0 );
    virtual unsigned long GetRenderSortKey() const                                                                  zCall( 0x005827E0 );
    virtual int CanTraceRay() const                                                                                 zCall( 0x005765D0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                      zCall( 0x00582800 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                                                        zCall( 0x0057B7E0 );
    virtual zSTRING const* GetFileExtension( int )                                                                  zCall( 0x00578740 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                     zCall( 0x00578760 );
    virtual void StartAnimation( zSTRING const& )                                                                   zCall( 0x005765E0 );
    virtual void StopAnimation( zSTRING const& )                                                                    zCall( 0x005765F0 );
    virtual int IsAnimationActive( zSTRING const& )                                                                 zCall( 0x00576690 );
    virtual zSTRING const* GetAnyAnimation()                                                                        zCall( 0x0057AE20 );

    // static properties
    static int& s_drawSkeleton;
    static int& s_bSmoothRootNode;
    static int*& s_iNumSoftSkinPoly;

    // user API
    #include "zCModel.inl"
  };

  // sizeof 30h
  class zCModelConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCModelConvertFileHandler_OnInit()                            zCall( 0x005A1610 );
    zCModelConvertFileHandler()                                        zInit( zCModelConvertFileHandler_OnInit() );
    virtual ~zCModelConvertFileHandler()                               zCall( 0x00424C40 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005A1740 );

    // user API
    #include "zCModelConvertFileHandler.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMODEL_H__VER3__