// Supported with union (c) 2018-2021 Union team

#ifndef __ZMODEL_H__VER2__
#define __ZMODEL_H__VER2__

#include "zProgMesh.h"

namespace Gothic_II_Classic {
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

    void zCModelMeshLib_OnInit()                                                            zCall( 0x0058E5D0 );
    zCModelMeshLib()                                                                        zInit( zCModelMeshLib_OnInit() );
    void ReleaseData()                                                                      zCall( 0x00599B30 );
    void AllocNumNodeVisuals( int )                                                         zCall( 0x00599BA0 );
    void AddMeshSoftSkin( zCMeshSoftSkin* )                                                 zCall( 0x00599C10 );
    void AddNodeVisual( int, zCVisual* )                                                    zCall( 0x00599CF0 );
    void ApplyToModel( zCModel* )                                                           zCall( 0x00599DF0 );
    void ApplyToModel( zCModelPrototype* )                                                  zCall( 0x00599F60 );
    void RemoveFromModel( zCModel* )                                                        zCall( 0x0059A0C0 );
    void BuildFromModel( zCModelPrototype* )                                                zCall( 0x0059A1B0 );
    void BuildFromModel( zCModel* )                                                         zCall( 0x0059A3A0 );
    void SaveMDM( zCModelPrototype* )                                                       zCall( 0x0059A5D0 );
    void SaveMDM( zCFileBIN&, zCModelPrototype* )                                           zCall( 0x0059A7E0 );
    static zCObject* _CreateNewInstance()                                                   zCall( 0x0057F310 );
    static unsigned long GetMDMFileVersion()                                                zCall( 0x0059A5A0 );
    static int LoadMDM( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** )     zCall( 0x0059AC70 );
    static int LoadMDM_Try( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** ) zCall( 0x0059B040 );
    static int LoadMDM( zCFileBIN&, zCModelPrototype*, zCModel*, zCModelMeshLib** )         zCall( 0x0059B240 );
    static int ConvertMDM( zSTRING const&, zCModelPrototype* )                              zCall( 0x0059BD80 );
    virtual zCClassDef* _GetClassDef() const                                                zCall( 0x00579510 );
    virtual ~zCModelMeshLib()                                                               zCall( 0x00599A60 );

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

    void zCModelAniEvent_OnInit() zCall( 0x00582D20 );
    zCModelAniEvent()             zInit( zCModelAniEvent_OnInit() );
    ~zCModelAniEvent()            zCall( 0x00582DC0 );
    void Save( zCFileBIN& ) const zCall( 0x00582EA0 );
    void Load( zCFileBIN& )       zCall( 0x00583000 );

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

    void zCModelNode_OnInit()                     zCall( 0x0057F460 );
    void zCModelNode_OnInit( zCModelNode const& ) zCall( 0x0057F5A0 );
    zCModelNode()                                 zInit( zCModelNode_OnInit() );
    zCModelNode( zCModelNode const& a0 )          zInit( zCModelNode_OnInit( a0 ));
    ~zCModelNode()                                zCall( 0x0057F730 );
    void SetNodeVisualS( zCVisual* )              zCall( 0x0057F7D0 );

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

    void zCModelAni_OnInit()                                         zCall( 0x0057FBC0 );
    zCModelAni()                                                     zInit( zCModelAni_OnInit() );
    void PrecacheAniEventData()                                      zCall( 0x0057FFD0 );
    float GetAniVelocity() const                                     zCall( 0x005800A0 );
    zVEC3 GetAniTranslation() const                                  zCall( 0x00580220 );
    void AddTrafoMatrix( zMAT4** )                                   zCall( 0x00580360 );
    zCQuat GetQuat( int, int ) const                                 zCall( 0x00580800 );
    zVEC3 GetTrans( int, int ) const                                 zCall( 0x00580860 );
    void SetTrans( int, int, zVEC3 const& )                          zCall( 0x00580900 );
    void SetQuat( int, int, zCQuat const& )                          zCall( 0x00580980 );
    void AddNodeList( zCTree<zCModelNode>** )                        zCall( 0x00580A20 );
    void SetFlags( zSTRING const& )                                  zCall( 0x00580A90 );
    void SetBlendingSec( float, float )                              zCall( 0x00580B40 );
    void GetBlendingSec( float&, float& ) const                      zCall( 0x00580BA0 );
    void CorrectRootNodeIdleMovement()                               zCall( 0x00580C00 );
    void CalcInPlaceFlag()                                           zCall( 0x00580D60 );
    int ResolveAlias( zCModelPrototype* )                            zCall( 0x00580F40 );
    int ResolveComb( zCModelPrototype* )                             zCall( 0x00581220 );
    void SaveMAN( zCModelPrototype*, zSTRING const& )                zCall( 0x00581920 );
    int LoadMAN( zSTRING const&, zCModelPrototype*, zSTRING const& ) zCall( 0x005821E0 );
    zSTRING const& GetAniName() const                                zCall( 0x00597C00 );
    zTMdl_AniType GetAniType() const                                 zCall( 0x00597C10 );
    int GetAniID() const                                             zCall( 0x0064CF80 );
    static zCObject* _CreateNewInstance()                            zCall( 0x005716D0 );
    virtual zCClassDef* _GetClassDef() const                         zCall( 0x0057FD60 );
    virtual ~zCModelAni()                                            zCall( 0x0057FDA0 );

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

    void zCModelPrototype_OnInit()                                                           zCall( 0x005830B0 );
    zCModelPrototype()                                                                       zInit( zCModelPrototype_OnInit() );
    void Init()                                                                              zCall( 0x005832F0 );
    ~zCModelPrototype()                                                                      zCall( 0x005834B0 );
    void Clear()                                                                             zCall( 0x005836F0 );
    void ReleaseMeshSoftSkinList()                                                           zCall( 0x00583890 );
    void ReleaseMeshes()                                                                     zCall( 0x005838F0 );
    int Release()                                                                            zCall( 0x00583980 );
    zSTRING const& GetModelProtoFileName() const                                             zCall( 0x005839D0 );
    void SetModelProtoName( zSTRING const& )                                                 zCall( 0x005839E0 );
    void SetFileSourceType( zTFileSourceType )                                               zCall( 0x00583B70 );
    int PrepareAsModelProtoOverlay( zCModelPrototype* )                                      zCall( 0x00583F40 );
    void CalcNodeListChecksum()                                                              zCall( 0x00584310 );
    void CollectNodeMeshes( zCArray<zCModelNode*>& )                                         zCall( 0x00584370 );
    zCModelNode* SearchNode( zSTRING const& )                                                zCall( 0x00584590 );
    zCTree<zCModelNode>* FindMeshTreeNode( zSTRING const&, zCTree<zCModelNode>* )            zCall( 0x00584640 );
    int FindMeshTreeNodeIndex( zSTRING const&, zCTree<zCModelNode>* )                        zCall( 0x005846F0 );
    int FindNodeListIndex( zSTRING const& )                                                  zCall( 0x005847B0 );
    void AddAni( zCModelAni* )                                                               zCall( 0x00584850 );
    int __fastcall SearchAniIndex( zSTRING const& ) const                                    zCall( 0x00584A60 );
    zCModelAni* SearchAni( zSTRING const& ) const                                            zCall( 0x00584B30 );
    void DescribeTree( zCTree<zCModelNode>*, int )                                           zCall( 0x00584B50 );
    int LoadMDH( zSTRING const& )                                                            zCall( 0x00584DA0 );
    int LoadMDH( zCFileBIN& )                                                                zCall( 0x00585000 );
    void SaveMDH()                                                                           zCall( 0x00585660 );
    void SaveMDH( zCFileBIN& )                                                               zCall( 0x00585860 );
    void ConvertVec3( zVEC3& )                                                               zCall( 0x00585D80 );
    void ConvertAngle( float& )                                                              zCall( 0x00585DA0 );
    void SkipBlock()                                                                         zCall( 0x00585DB0 );
    void SkipBlockCmt()                                                                      zCall( 0x00585E30 );
    void ReadComment()                                                                       zCall( 0x00585F00 );
    void ReadScene( float& )                                                                 zCall( 0x00585F10 );
    zVEC3 ReadTriple()                                                                       zCall( 0x005862B0 );
    zMAT4 ReadNodeTM( zCModelNode* )                                                         zCall( 0x005864A0 );
    void ReadVertexList( zCMesh*, int )                                                      zCall( 0x00586940 );
    zTMatIDList* ReadFaceList( zCMesh*, int )                                                zCall( 0x00586B70 );
    zVEC2* ReadTVertexList( int )                                                            zCall( 0x00587070 );
    void ReadTFaceList( zCMesh*, zVEC2*, int )                                               zCall( 0x00587270 );
    void ReadSoftSkinVertList()                                                              zCall( 0x005874E0 );
    zCMesh* ReadMesh( int, zCModelNode*, int )                                               zCall( 0x005886A0 );
    void ReadMeshAnimation( zCModelNode*, int )                                              zCall( 0x00588A80 );
    void ReadPosTrack( zMAT4* )                                                              zCall( 0x00588C00 );
    void ReadRotTrack( zMAT4* )                                                              zCall( 0x00588DE0 );
    void ReadTMAnimation( zCModelNode*, zMAT4*& )                                            zCall( 0x00589090 );
    void LocalizeTrafos( zCTree<zCModelNode>*, zCTree<zCModelNode>* )                        zCall( 0x005896D0 );
    void ReadMapDiffuse( zCMaterial* )                                                       zCall( 0x00589800 );
    zCMaterial* ReadMaterial()                                                               zCall( 0x00589C70 );
    zCMaterial* ReadWireframeColor()                                                         zCall( 0x0058A2E0 );
    void AssignMeshNodeMaterials( zCMesh*, zTMatIDList*, int )                               zCall( 0x0058A580 );
    void TransformNodeVisual( zCModelNode*, zMAT4 const& )                                   zCall( 0x0058A670 );
    void ProcessMeshNode( zCModelNode*, zCTree<zCModelNode>*, int, int, int& )               zCall( 0x0058A6D0 );
    void ReadGeomobject( zMAT4*&, zCTree<zCModelNode>*& )                                    zCall( 0x0058AAE0 );
    void ReadMaterialList()                                                                  zCall( 0x0058C060 );
    void Load3DSMAXAsc( zCModelAni*&, zSTRING const&, zSTRING const&, int, int, int, float ) zCall( 0x0058C2F0 );
    void CalcAniBBox( zCModelAni* )                                                          zCall( 0x0058D370 );
    void ResolveReferences()                                                                 zCall( 0x0058D8A0 );
    void SkipBlockMDS( int )                                                                 zCall( 0x0058DBA0 );
    int ReadMeshAndTreeMSB( int&, zCFileBIN& )                                               zCall( 0x0058DC20 );
    void ReadMeshAndTree( int&, zCFileBIN& )                                                 zCall( 0x0058E060 );
    void RegisterMesh( zCFileBIN& )                                                          zCall( 0x0058E6E0 );
    int ReadAniEnumMSB( int, zCFileBIN& )                                                    zCall( 0x0058E970 );
    void ReadAniEnum( int, zCFileBIN& )                                                      zCall( 0x005916A0 );
    int ReadModelMSB( zCFileBIN& )                                                           zCall( 0x00597CF0 );
    void ReadModel( zCFileBIN& )                                                             zCall( 0x00597F60 );
    int LoadModelScriptMSB( zSTRING const& )                                                 zCall( 0x00598250 );
    int LoadModelScript( zSTRING const& )                                                    zCall( 0x00598870 );
    int LoadModelASC( zSTRING const& )                                                       zCall( 0x00599200 );
    static int NumInList()                                                                   zCall( 0x005839B0 );
    static zCModelPrototype* Load( zSTRING const&, zCModelPrototype* )                       zCall( 0x00583CF0 );
    static zCModelPrototype* SearchName( zSTRING )                                           zCall( 0x005844D0 );
    static unsigned long GetMDHFileVersion()                                                 zCall( 0x00584D90 );
    static unsigned long GetMDSFileVersion()                                                 zCall( 0x0058DB90 );

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

    void zCModelAniActive_OnInit()          zCall( 0x00571850 );
    zCModelAniActive()                      zInit( zCModelAniActive_OnInit() );
    ~zCModelAniActive()                     zCall( 0x00571940 );
    void SetDirection( zTMdl_AniDir )       zCall( 0x00571960 );
    float GetProgressPercent() const        zCall( 0x005719B0 );
    void SetProgressPercent( float )        zCall( 0x005719F0 );
    void SetActFrame( float )               zCall( 0x00571A40 );
    void DoCombineAni( zCModel*, int, int ) zCall( 0x0057A890 );

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

    void zCModelTexAniState_OnInit()                                      zCall( 0x00571A90 );
    zCModelTexAniState()                                                  zInit( zCModelTexAniState_OnInit() );
    ~zCModelTexAniState()                                                 zCall( 0x00571AB0 );
    void DeleteTexList()                                                  zCall( 0x00571AD0 );
    void UpdateTexList()                                                  zCall( 0x00571AF0 );
    void SetChannelVariation( int, int, zSTRING* )                        zCall( 0x00571B30 );
    void BuildTexListFromMeshLib( zCModelMeshLib* )                       zCall( 0x00571BA0 );
    void BuildTexListFromMesh( zCMesh* )                                  zCall( 0x00571C20 );
    void BuildTexListFromProgMesh( zCProgMeshProto* )                     zCall( 0x00571DB0 );
    void AddTexListFromMeshLib( zCModelMeshLib*, zCArray<zCTexture*>& )   zCall( 0x00571F20 );
    void AddTexListFromMesh( zCMesh*, zCArray<zCTexture*>& )              zCall( 0x00572180 );
    void AddTexListFromProgMesh( zCProgMeshProto*, zCArray<zCTexture*>& ) zCall( 0x005722E0 );
    void FinishTexList( zCArray<zCTexture*>& )                            zCall( 0x00572430 );

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

    void zCModelNodeInst_OnInit()                            zCall( 0x005725C0 );
    void zCModelNodeInst_OnInit( zCModelNode* )              zCall( 0x00572690 );
    zCModelNodeInst()                                        zInit( zCModelNodeInst_OnInit() );
    zCModelNodeInst( zCModelNode* a0 )                       zInit( zCModelNodeInst_OnInit( a0 ));
    ~zCModelNodeInst()                                       zCall( 0x00572780 );
    void Init()                                              zCall( 0x00572800 );
    void InitByModelProtoNode( zCModelNode* )                zCall( 0x00572890 );
    void SetNodeVisualS( zCVisual*, int )                    zCall( 0x00572940 );
    void AddNodeAni( zCModelAniActive* )                     zCall( 0x005795D0 );
    void RemoveAllNodeAnis()                                 zCall( 0x00579800 );
    void RemoveNodeAni( zCModelAniActive* )                  zCall( 0x00579810 );
    void FindMasterAni()                                     zCall( 0x00579900 );
    void FadeOutNodeAni( zCModelAniActive* )                 zCall( 0x00579970 );
    void CalcWeights( zCModel* )                             zCall( 0x00579F50 );
    void AddToNodeAniWeight( int, float )                    zCall( 0x0057A190 );
    void CalcBlending( zCModel* )                            zCall( 0x0057A200 );
    int GetNodeAniListIndex( zCModelAniActive const* ) const zCall( 0x0057A390 );

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

    void zTAniAttachment_OnInit() zCall( 0x0057DE00 );
    ~zTAniAttachment()            zCall( 0x0057DDE0 );
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
    void zCModel_OnInit( zCModelPrototype* )                                                                        zCall( 0x00572F90 );
    zCModelAni* GetAniFromAniID( int ) const                                                                        zCall( 0x00471E30 );
    int IsAniActive( zCModelAni* )                                                                                  zCall( 0x00471E70 );
    void Init()                                                                                                     zCall( 0x00572D20 );
    zCModel( zCModelPrototype* a0 )                                                                                 zInit( zCModel_OnInit( a0 ));
    void CopyProtoNodeList()                                                                                        zCall( 0x00573150 );
    int ApplyModelProtoOverlay( zSTRING const& )                                                                    zCall( 0x00573540 );
    int ApplyModelProtoOverlay( zCModelPrototype* )                                                                 zCall( 0x00573590 );
    int HasAppliedModelProtoOverlay( zCModelPrototype* ) const                                                      zCall( 0x005737E0 );
    int HasAppliedModelProtoOverlay( zSTRING const& ) const                                                         zCall( 0x00573810 );
    void RemoveModelProtoOverlay( zSTRING const& )                                                                  zCall( 0x00573990 );
    void RemoveModelProtoOverlay( zCModelPrototype* )                                                               zCall( 0x00573B90 );
    void CalcNodeListBBoxWorld()                                                                                    zCall( 0x00573D10 );
    zTBBox3D GetBBox3DNodeWorld( zCModelNodeInst* )                                                                 zCall( 0x00573E40 );
    zVEC3 GetNodePositionWorld( zCModelNodeInst* )                                                                  zCall( 0x00573E90 );
    void CalcModelBBox3DWorld()                                                                                     zCall( 0x00573EC0 );
    void SetNodeVisual( zCModelNodeInst*, zCVisual*, int )                                                          zCall( 0x00573FF0 );
    void SetDynLightMode( int )                                                                                     zCall( 0x00574020 );
    void __fastcall RenderNodeList( zTRenderContext&, zCArray<zMAT4*>&, zCRenderLightContainer&, zTPMLightingMode ) zCall( 0x00574040 );
    void CheckNodeCollisionList( zCOBBox3D const&, zMAT4& )                                                         zCall( 0x005752B0 );
    void CheckNodeCollision( zCModel*, zCModelNodeInst*, zMAT4&, zCList<zCModelNodeInst>& )                         zCall( 0x00575350 );
    zMAT4 GetTrafoNodeToModel( zCModelNodeInst* )                                                                   zCall( 0x005754A0 );
    void SetRandAnisEnabled( int )                                                                                  zCall( 0x005755D0 );
    zCModelAniActive* GetActiveAni( int ) const                                                                     zCall( 0x00575640 );
    zCModelAniActive* GetActiveAni( zCModelAni* ) const                                                             zCall( 0x00575680 );
    void StopAni( int )                                                                                             zCall( 0x005756C0 );
    void StopAni( zCModelAni* )                                                                                     zCall( 0x00575740 );
    void StopAni( zCModelAniActive* )                                                                               zCall( 0x00575790 );
    zVEC3 GetAniTransLerp( zCModelAni*, float, int ) const                                                          zCall( 0x00575950 );
    void StartAni( zSTRING const&, int )                                                                            zCall( 0x00575A50 );
    void StartAni( int, int )                                                                                       zCall( 0x00575B50 );
    void StartAni( zCModelAni*, int )                                                                               zCall( 0x00575BA0 );
    void AssertActiveAniListAlloced()                                                                               zCall( 0x00576250 );
    void DoAniEvents( zCModelAniActive* )                                                                           zCall( 0x00576370 );
    void __fastcall AdvanceAni( zCModelAniActive*, int& )                                                           zCall( 0x005772B0 );
    void AdvanceAnis()                                                                                              zCall( 0x00577570 );
    void SetModelScale( zVEC3 const& )                                                                              zCall( 0x00578710 );
    int IsStateActive( zCModelAni const* ) const                                                                    zCall( 0x00578880 );
    zCModelNodeInst* SearchNode( zSTRING const& )                                                                   zCall( 0x00578AD0 );
    int SetNodeMeshTexture( zSTRING const&, int, int, zSTRING* )                                                    zCall( 0x00578B80 );
    int SetMeshLibTexture( zSTRING const&, int, int, zSTRING* )                                                     zCall( 0x00578CB0 );
    void RemoveMeshLibAll()                                                                                         zCall( 0x00578EB0 );
    int RemoveMeshLib( zSTRING const& )                                                                             zCall( 0x00578EE0 );
    int ApplyMeshLib( zSTRING const& )                                                                              zCall( 0x005790F0 );
    void UpdateMeshLibTexAniState()                                                                                 zCall( 0x00579550 );
    void FadeOutAni( int )                                                                                          zCall( 0x00579A30 );
    void FadeOutAni( zCModelAni* )                                                                                  zCall( 0x00579AC0 );
    void FadeOutAni( zCModelAniActive* )                                                                            zCall( 0x00579B00 );
    void FadeOutAnisLayerRange( int, int )                                                                          zCall( 0x00579CD0 );
    void StopAnisLayerRange( int, int )                                                                             zCall( 0x00579D20 );
    float GetProgressPercent( zSTRING const& ) const                                                                zCall( 0x00579D70 );
    float GetProgressPercent( int ) const                                                                           zCall( 0x00579E20 );
    void SetCombineAniXY( int, float, float ) const                                                                 zCall( 0x00579E90 );
    int GetCombineAniXY( int, float&, float& ) const                                                                zCall( 0x00579EE0 );
    void CalcNodeListAniBlending()                                                                                  zCall( 0x0057A360 );
    void CalcTransBlending()                                                                                        zCall( 0x0057A3C0 );
    void AttachChildVobToNode( zCVob*, zCModelNodeInst* )                                                           zCall( 0x0057B180 );
    void RemoveChildVobFromNode( zCVob* )                                                                           zCall( 0x0057B2D0 );
    void RemoveAllChildVobsFromNode()                                                                               zCall( 0x0057B350 );
    void UpdateAttachedVobs()                                                                                       zCall( 0x0057B3A0 );
    void RemoveStartedVobFX( zCVob* )                                                                               zCall( 0x0057B4F0 );
    zVEC3 GetVelocityRing() const                                                                                   zCall( 0x0057B5A0 );
    void ResetVelocity()                                                                                            zCall( 0x0057B600 );
    void GetAniMinMaxWeight( zCModelAniActive*, float&, float& )                                                    zCall( 0x0057B690 );
    void PrintStatus( int, int )                                                                                    zCall( 0x0057B930 );
    int CorrectAniFreezer()                                                                                         zCall( 0x0057C080 );
    void psb_WriteAniBlock( zCBuffer&, int, int ) const                                                             zCall( 0x0057C2F0 );
    void psb_ReadAniBlock( zCBuffer&, int, zCModelAniActive* )                                                      zCall( 0x0057C480 );
    void PackStateBinary( zCBuffer& )                                                                               zCall( 0x0057C6D0 );
    void UnpackStateBinary( zCBuffer& )                                                                             zCall( 0x0057CA20 );
    void ShowAniListAdd( zCModelAni* )                                                                              zCall( 0x0057D1A0 );
    void ShowAniList( int )                                                                                         zCall( 0x0057D210 );
    zTAniAttachment* SearchAniAttachList( int ) const                                                               zCall( 0x0057DE40 );
    void RemoveAniAttachment( int )                                                                                 zCall( 0x0057DEC0 );
    void RemoveAllAniAttachments()                                                                                  zCall( 0x0057E010 );
    void RemoveAllVobFX()                                                                                           zCall( 0x0057E060 );
    zTAniAttachment* GetCreateAniAttachment( int )                                                                  zCall( 0x0057E0F0 );
    void DeleteRandAniList( int )                                                                                   zCall( 0x0057E340 );
    void InsertRandAni( int, int, int )                                                                             zCall( 0x0057E3D0 );
    float GetRandAniFreq( int ) const                                                                               zCall( 0x0057E4D0 );
    void SetRandAniFreq( int, float )                                                                               zCall( 0x0057E560 );
    void __fastcall RecalcRootPosLocal( int )                                                                       zCall( 0x0057E580 );
    int GetAniIDFromAniName( zSTRING const& ) const                                                                 zCall( 0x0060A9B0 );
    static zCObject* _CreateNewInstance()                                                                           zCall( 0x00571170 );
    static int AniAttachmentCompare( void const*, void const* )                                                     zCall( 0x0057DE10 );
    virtual zCClassDef* _GetClassDef() const                                                                        zCall( 0x00571300 );
    virtual ~zCModel()                                                                                              zCall( 0x00572A10 );
    virtual int Render( zTRenderContext& )                                                                          zCall( 0x00574FC0 );
    virtual int IsBBox3DLocal()                                                                                     zCall( 0x00571310 );
    virtual zTBBox3D GetBBox3D()                                                                                    zCall( 0x00578A00 );
    virtual zSTRING GetVisualName()                                                                                 zCall( 0x00578A40 );
    virtual void SetVisualUsedBy( zCVob* )                                                                          zCall( 0x00573410 );
    virtual unsigned long GetRenderSortKey() const                                                                  zCall( 0x0057D280 );
    virtual int CanTraceRay() const                                                                                 zCall( 0x00571320 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                      zCall( 0x0057D2A0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                                                        zCall( 0x005762C0 );
    virtual zSTRING const* GetFileExtension( int )                                                                  zCall( 0x00573490 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                     zCall( 0x005734B0 );
    virtual void StartAnimation( zSTRING const& )                                                                   zCall( 0x00571330 );
    virtual void StopAnimation( zSTRING const& )                                                                    zCall( 0x00571340 );
    virtual int IsAnimationActive( zSTRING const& )                                                                 zCall( 0x005713E0 );
    virtual zSTRING const* GetAnyAnimation()                                                                        zCall( 0x00575900 );

    // static properties
    static int& s_drawSkeleton;
    static int& s_bSmoothRootNode;

    // user API
    #include "zCModel.inl"
  };

  // sizeof 30h
  class zCModelConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCModelConvertFileHandler_OnInit()                            zCall( 0x0059C0B0 );
    zCModelConvertFileHandler()                                        zInit( zCModelConvertFileHandler_OnInit() );
    virtual ~zCModelConvertFileHandler()                               zCall( 0x00424910 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x0059C1E0 );

    // user API
    #include "zCModelConvertFileHandler.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMODEL_H__VER2__