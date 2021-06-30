// Supported with union (c) 2018 Union team

#ifndef __ZMODEL_H__VER0__
#define __ZMODEL_H__VER0__

namespace Gothic_I_Classic {
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

  class zCModelMeshLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCModelMeshLib )

    struct zTNodeMesh {
    public:
      zCVisual* visual;
      int nodeIndex;

      // user API
      #include "zCModelMeshLib_zTNodeMesh.inl"
    };

    zCArray<zTNodeMesh> meshNodeList;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;

    void zCModelMeshLib_OnInit()                                                            zCall( 0x0057F3D0 );
    zCModelMeshLib()                                                                        zInit( zCModelMeshLib_OnInit() );
    void ReleaseData()                                                                      zCall( 0x0057F570 );
    void AllocNumNodeVisuals( int )                                                         zCall( 0x0057F5E0 );
    void AddMeshSoftSkin( zCMeshSoftSkin* )                                                 zCall( 0x0057F660 );
    void AddNodeVisual( int, zCVisual* )                                                    zCall( 0x0057F760 );
    void ApplyToModel( zCModel* )                                                           zCall( 0x0057F880 );
    void ApplyToModel( zCModelPrototype* )                                                  zCall( 0x0057F9E0 );
    void RemoveFromModel( zCModel* )                                                        zCall( 0x0057FB60 );
    void BuildFromModel( zCModelPrototype* )                                                zCall( 0x0057FC50 );
    void BuildFromModel( zCModel* )                                                         zCall( 0x0057FE70 );
    void SaveMDM( zCModelPrototype* )                                                       zCall( 0x005800D0 );
    void SaveMDM( zCFileBIN&, zCModelPrototype* )                                           zCall( 0x005802E0 );
    static zCObject* _CreateNewInstance()                                                   zCall( 0x00569FA0 );
    static unsigned long GetMDMFileVersion()                                                zCall( 0x005800A0 );
    static int LoadMDM( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** )     zCall( 0x00580780 );
    static int LoadMDM_Try( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** ) zCall( 0x00580B00 );
    static int LoadMDM( zCFileBIN&, zCModelPrototype*, zCModel*, zCModelMeshLib** )         zCall( 0x00580D00 );
    static int ConvertMDM( zSTRING const&, zCModelPrototype* )                              zCall( 0x005818E0 );
    virtual zCClassDef* _GetClassDef() const                                                zCall( 0x005649B0 );
    virtual ~zCModelMeshLib()                                                               zCall( 0x0057F4A0 );

    // user API
    #include "zCModelMeshLib.inl"
  };

  class zCModelAniEvent {
  public:

    zTMdl_AniEventType aniEventType;
    int frameNr;
    zSTRING tagString;
    zSTRING string[zMDL_ANIEVENT_MAXSTRING];
    float value1;
    float value2;
    float value3;
    float value4;
    zCArray<zCSoundFX*> soundList;
    zCArray<zCParticleEmitter*> pfxEmitterList;

    void zCModelAniEvent_OnInit() zCall( 0x0056DA80 );
    zCModelAniEvent()             zInit( zCModelAniEvent_OnInit() );
    ~zCModelAniEvent()            zCall( 0x0056DB20 );
    void Save( zCFileBIN& ) const zCall( 0x0056DC00 );
    void Load( zCFileBIN& )       zCall( 0x0056DD60 );

    // user API
    #include "zCModelAniEvent.inl"
  };

  class zCModelNode {
  public:
    zCModelNode* parentNode;
    zSTRING nodeName;
    zCVisual* visual;
    zMAT4 trafo;
    zVEC3 nodeRotAxis;
    float nodeRotAngle;
    zVEC3 translation;
    zMAT4 trafoObjToWorld;
    zMAT4* nodeTrafoList;
    zCModelNodeInst* lastInstNode;

    void zCModelNode_OnInit()                     zCall( 0x0056A110 );
    void zCModelNode_OnInit( zCModelNode const& ) zCall( 0x0056A250 );
    zCModelNode()                                 zInit( zCModelNode_OnInit() );
    zCModelNode( zCModelNode const& a0 )          zInit( zCModelNode_OnInit( a0 ));
    ~zCModelNode()                                zCall( 0x0056A3E0 );
    void SetNodeVisualS( zCVisual* )              zCall( 0x0056A480 );

    // user API
    #include "zCModelNode.inl"
  };

#pragma pack( push, 1 )
  struct zTMdl_AniSample {
  public:
    unsigned short rotation[3];
    unsigned short position[3];

    // static properties
    static float& samplePosScaler;
    static float& samplePosRangeMin;

    // user API
    #include "zTMdl_AniSample.inl"
  };
#pragma pack( pop )

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

    zSTRING aniName;
    zSTRING ascName;
    int aniID;
    zSTRING aliasName;
    zCList<zCModelAni> combAniList;
    int layer;
    float blendInSpeed;
    float blendOutSpeed;
    zTBBox3D aniBBox3DObjSpace;
    float collisionVolumeScale;
    zCModelAni* nextAni;
    zSTRING nextAniName;
    zCModelAniEvent* aniEvents;
    float fpsRate;
    float fpsRateSource;
    int rootNodeIndex;
    zCArray<int> nodeIndexList;
    zCModelNode** nodeList;
    zTMdl_AniSample* aniSampleMatrix;
    float samplePosRangeMin;
    float samplePosScaler;
    group {
      int numFrames         : 16;
      int numNodes          : 16;
      zTMdl_AniType aniType : 6;
      zTMdl_AniDir aniDir   : 2;
      int numAniEvents      : 6;
    };
    group {
      byte flagVobRot      : 1;
      byte flagVobPos      : 1;
      byte flagEndSync     : 1;
      byte flagFly         : 1;
      byte flagIdle        : 1;
      byte flagInPlace     : 1;
      byte flagStaticCycle : 1;
	}
    aniFlags;

    void zCModelAni_OnInit()                                            zCall( 0x0056A870 );
    zCModelAni()                                                        zInit( zCModelAni_OnInit() );
    void PrecacheAniEventData()                                         zCall( 0x0056AC80 );
    float GetAniVelocity() const                                        zCall( 0x0056AD50 );
    zVEC3 GetAniTranslation() const                                     zCall( 0x0056AED0 );
    void AddTrafoMatrix( zMAT4** )                                      zCall( 0x0056B010 );
    zCQuat GetQuat( int, int ) const                                    zCall( 0x0056B4A0 );
    zVEC3 GetTrans( int, int ) const                                    zCall( 0x0056B500 );
    void SetTrans( int, int, zVEC3 const& )                             zCall( 0x0056B5A0 );
    void SetQuat( int, int, zCQuat const& )                             zCall( 0x0056B620 );
    void AddNodeList( zCTree<zCModelNode>** )                           zCall( 0x0056B6C0 );
    void SetFlags( zSTRING const& )                                     zCall( 0x0056B740 );
    void SetBlendingSec( float, float )                                 zCall( 0x0056B7F0 );
    void GetBlendingSec( float&, float& ) const                         zCall( 0x0056B850 );
    void CorrectRootNodeIdleMovement()                                  zCall( 0x0056B8B0 );
    void CalcInPlaceFlag()                                              zCall( 0x0056BA10 );
    int ResolveAlias( zCModelPrototype* )                               zCall( 0x0056BBF0 );
    int ResolveComb( zCModelPrototype* )                                zCall( 0x0056BED0 );
    void SaveMAN( zCModelPrototype*, zSTRING const& )                   zCall( 0x0056C560 );
    int LoadMAN( zSTRING const&, zCModelPrototype*, zSTRING const& )    zCall( 0x0056CEB0 );
    zSTRING const& GetAniName() const                                   zCall( 0x0057E360 );
    zTMdl_AniType GetAniType() const                                    zCall( 0x0057E370 );
    int GetAniID() const                                                zCall( 0x006211C0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0055D1E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0056AA10 );
    virtual ~zCModelAni()                                               zCall( 0x0056AA50 );

    // user API
    #include "zCModelAni.inl"
  };

  class zCModelPrototype {
  public:
    enum zTFileSourceType {
      zFROM_MDS,
      zFROM_ASC
    };

    zCModelPrototype* next;
    zCModelPrototype* prev;
    int refCtr;
    zSTRING modelProtoName;
    zSTRING modelProtoFileName;
    zCTree<zCModelNode> meshTree;
    zCArraySort<zCModelAni*> protoAnis;
    zCArray<zCModelAniEvent*> modelEvents;
    zCArray<zCModelNode*> nodeList;
    unsigned long nodeListChecksum;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;
    zSTRING hierarchySourceASC;
    zTBBox3D bbox3D;
    zTBBox3D bbox3DCollDet;
    zCModelPrototype* baseModelProto;
    zVEC3 rootNodeTrans;
    zTFileSourceType fileSourceType;
    zCArray<zCMesh*> sourceMeshSoftSkinList;

    void zCModelPrototype_OnInit()                                                           zCall( 0x0056DE10 );
    zCModelPrototype()                                                                       zInit( zCModelPrototype_OnInit() );
    void Init()                                                                              zCall( 0x0056E050 );
    ~zCModelPrototype()                                                                      zCall( 0x0056E240 );
    void Clear()                                                                             zCall( 0x0056E480 );
    void ReleaseMeshSoftSkinList()                                                           zCall( 0x0056E620 );
    void ReleaseMeshes()                                                                     zCall( 0x0056E680 );
    int Release()                                                                            zCall( 0x0056E710 );
    zSTRING const& GetModelProtoFileName() const                                             zCall( 0x0056E760 );
    void SetModelProtoName( zSTRING const& )                                                 zCall( 0x0056E770 );
    void SetFileSourceType( zTFileSourceType )                                               zCall( 0x0056E900 );
    int PrepareAsModelProtoOverlay( zCModelPrototype* )                                      zCall( 0x0056ECE0 );
    void CalcNodeListChecksum()                                                              zCall( 0x0056F0C0 );
    void CollectNodeMeshes( zCArray<zCModelNode*>& )                                         zCall( 0x0056F120 );
    zCModelNode* SearchNode( zSTRING const& )                                                zCall( 0x0056F360 );
    zCTree<zCModelNode>* FindMeshTreeNode( zSTRING const&, zCTree<zCModelNode>* )            zCall( 0x0056F410 );
    int FindMeshTreeNodeIndex( zSTRING const&, zCTree<zCModelNode>* )                        zCall( 0x0056F4C0 );
    int FindNodeListIndex( zSTRING const& )                                                  zCall( 0x0056F580 );
    void AddAni( zCModelAni* )                                                               zCall( 0x0056F620 );
    int __fastcall SearchAniIndex( zSTRING const& ) const                                    zCall( 0x0056F850 );
    zCModelAni* SearchAni( zSTRING const& ) const                                            zCall( 0x0056F920 );
    void DescribeTree( zCTree<zCModelNode>*, int )                                           zCall( 0x0056F940 );
    int LoadMDH( zSTRING const& )                                                            zCall( 0x0056FB90 );
    int LoadMDH( zCFileBIN& )                                                                zCall( 0x0056FDF0 );
    void SaveMDH()                                                                           zCall( 0x00570490 );
    void SaveMDH( zCFileBIN& )                                                               zCall( 0x00570690 );
    void ConvertVec3( zVEC3& )                                                               zCall( 0x00570BA0 );
    void ConvertAngle( float& )                                                              zCall( 0x00570BC0 );
    void SkipBlock()                                                                         zCall( 0x00570BD0 );
    void SkipBlockCmt()                                                                      zCall( 0x00570C50 );
    void ReadComment()                                                                       zCall( 0x00570D20 );
    void ReadScene( float& )                                                                 zCall( 0x00570D30 );
    zVEC3 ReadTriple()                                                                       zCall( 0x005710D0 );
    zMAT4 ReadNodeTM( zCModelNode* )                                                         zCall( 0x005712C0 );
    void ReadVertexList( zCMesh*, int )                                                      zCall( 0x00571760 );
    zTMatIDList* ReadFaceList( zCMesh*, int )                                                zCall( 0x00571990 );
    zVEC2* ReadTVertexList( int )                                                            zCall( 0x00571E90 );
    void ReadTFaceList( zCMesh*, zVEC2*, int )                                               zCall( 0x005720A0 );
    void ReadSoftSkinVertList()                                                              zCall( 0x00572310 );
    zCMesh* ReadMesh( int, zCModelNode*, int )                                               zCall( 0x00573480 );
    void ReadMeshAnimation( zCModelNode*, int )                                              zCall( 0x00573870 );
    void ReadPosTrack( zMAT4* )                                                              zCall( 0x005739F0 );
    void ReadRotTrack( zMAT4* )                                                              zCall( 0x00573BD0 );
    void ReadTMAnimation( zCModelNode*, zMAT4*& )                                            zCall( 0x00573E80 );
    void LocalizeTrafos( zCTree<zCModelNode>*, zCTree<zCModelNode>* )                        zCall( 0x005744C0 );
    void ReadMapDiffuse( zCMaterial* )                                                       zCall( 0x005745F0 );
    zCMaterial* ReadMaterial()                                                               zCall( 0x005749F0 );
    zCMaterial* ReadWireframeColor()                                                         zCall( 0x00575070 );
    void AssignMeshNodeMaterials( zCMesh*, zTMatIDList*, int )                               zCall( 0x00575330 );
    void TransformNodeVisual( zCModelNode*, zMAT4 const& )                                   zCall( 0x00575420 );
    void ProcessMeshNode( zCModelNode*, zCTree<zCModelNode>*, int, int, int& )               zCall( 0x00575480 );
    void ReadGeomobject( zMAT4*&, zCTree<zCModelNode>*& )                                    zCall( 0x005758A0 );
    void ReadMaterialList()                                                                  zCall( 0x00576E40 );
    void Load3DSMAXAsc( zCModelAni*&, zSTRING const&, zSTRING const&, int, int, int, float ) zCall( 0x005770D0 );
    void CalcAniBBox( zCModelAni* )                                                          zCall( 0x00577FF0 );
    void ResolveReferences()                                                                 zCall( 0x00578510 );
    void SkipBlockMDS( int )                                                                 zCall( 0x00578800 );
    void ReadMeshAndTree( int& )                                                             zCall( 0x00578880 );
    void RegisterMesh()                                                                      zCall( 0x00578D00 );
    void ReadStartMesh()                                                                     zCall( 0x00578F40 );
    void ReadAniEventTag( zSTRING&, zCModelAniEvent* )                                       zCall( 0x005790E0 );
    void ReadAniEnum( int )                                                                  zCall( 0x00579350 );
    void ReadModel()                                                                         zCall( 0x0057E410 );
    int LoadModelScript( zSTRING const& )                                                    zCall( 0x0057E570 );
    int LoadModelASC( zSTRING const& )                                                       zCall( 0x0057EB20 );
    static int NumInList()                                                                   zCall( 0x0056E740 );
    static zCModelPrototype* Load( zSTRING const&, zCModelPrototype* )                       zCall( 0x0056EA80 );
    static zCModelPrototype* SearchName( zSTRING )                                           zCall( 0x0056F2A0 );
    static unsigned long GetMDHFileVersion()                                                 zCall( 0x0056FB80 );

    // static properties
    static int& s_ignoreAnis;
    static int& s_autoConvertAnis;
    static int& s_autoConvertMeshes;
    static zCModelPrototype*& s_modelRoot;

    // user API
    #include "zCModelPrototype.inl"
  };

  class zCModelAniActive {
  public:
    zCModelAni* protoAni;
    zCModelAni* nextAni;
    int advanceDir;
    float actFrame;
    int actAniEvent;
    float combAniX;
    float combAniY;
    int isFadingOut;
    int isFirstTime;
    zCModelAni* nextAniOverride;
    float blendInOverride;
    float blendOutOverride;
    zVEC3 lastPos;
    zVEC3 thisPos;
    zCQuat lastRotQuat;
    zCQuat thisRotQuat;
    zCQuat freezeRotQuat;
    int rotFirstTime;
    float transWeight;
    zTAniAttachment* aniAttachment;
    float randAniTimer;

    void zCModelAniActive_OnInit()          zCall( 0x0055D370 );
    zCModelAniActive()                      zInit( zCModelAniActive_OnInit() );
    ~zCModelAniActive()                     zCall( 0x0055D460 );
    void SetDirection( zTMdl_AniDir )       zCall( 0x0055D480 );
    float GetProgressPercent() const        zCall( 0x0055D4D0 );
    void SetProgressPercent( float )        zCall( 0x0055D510 );
    void SetActFrame( float )               zCall( 0x0055D560 );
    void DoCombineAni( zCModel*, int, int ) zCall( 0x00565D30 );

    // user API
    #include "zCModelAniActive.inl"
  };

  class zCModelTexAniState {
  public:
    enum {
      zMDL_MAX_ANI_CHANNELS = 2,
      zMDL_MAX_TEX          = 4
    };

    int numNodeTex;
    zCTexture** nodeTexList;
    int actAniFrames[zMDL_MAX_ANI_CHANNELS][zMDL_MAX_TEX];

    void zCModelTexAniState_OnInit()                                      zCall( 0x0055D5B0 );
    zCModelTexAniState()                                                  zInit( zCModelTexAniState_OnInit() );
    ~zCModelTexAniState()                                                 zCall( 0x0055D5D0 );
    void DeleteTexList()                                                  zCall( 0x0055D5F0 );
    void UpdateTexList()                                                  zCall( 0x0055D610 );
    void SetChannelVariation( int, int, zSTRING* )                        zCall( 0x0055D650 );
    void BuildTexListFromMeshLib( zCModelMeshLib* )                       zCall( 0x0055D6C0 );
    void BuildTexListFromMesh( zCMesh* )                                  zCall( 0x0055D740 );
    void BuildTexListFromProgMesh( zCProgMeshProto* )                     zCall( 0x0055D860 );
    void AddTexListFromMeshLib( zCModelMeshLib*, zCArray<zCTexture*>& )   zCall( 0x0055D9E0 );
    void AddTexListFromMesh( zCMesh*, zCArray<zCTexture*>& )              zCall( 0x0055DC70 );
    void AddTexListFromProgMesh( zCProgMeshProto*, zCArray<zCTexture*>& ) zCall( 0x0055DDF0 );
    void FinishTexList( zCArray<zCTexture*>& )                            zCall( 0x0055DF60 );

    // user API
    #include "zCModelTexAniState.inl"
  };

#pragma pack( push, 1 )
  class zCModelNodeInst {
  public:
    enum {
      zMDL_BLEND_STATE_FADEIN,
      zMDL_BLEND_STATE_CONST,
      zMDL_BLEND_STATE_FADEOUT
    };

    struct zTNodeAni {
      zCModelAniActive* modelAni;
      float weight;
      float weightSpeed;
      int blendState;
      zCQuat quat;

      zTNodeAni() {}

      // user API
      #include "zCModelNodeInst_zTNodeAni.inl"
    };

    zCModelNodeInst* parentNode;
    zCModelNode* protoNode;
    zCVisual* nodeVisual;
    zMAT4 trafo;
    zMAT4 trafoObjToCam;
    zTBBox3D bbox3D;
    zCModelTexAniState texAniState;
    zTNodeAni nodeAniList[zMDL_MAX_ANIS_PARALLEL];
    int numNodeAnis;
    int masterAni;
    float masterAniSpeed;

    void zCModelNodeInst_OnInit()                            zCall( 0x0055E0A0 );
    void zCModelNodeInst_OnInit( zCModelNode* )              zCall( 0x0055E170 );
    zCModelNodeInst()                                        zInit( zCModelNodeInst_OnInit() );
    zCModelNodeInst( zCModelNode* a0 )                       zInit( zCModelNodeInst_OnInit( a0 ));
    ~zCModelNodeInst()                                       zCall( 0x0055E260 );
    void Init()                                              zCall( 0x0055E2E0 );
    void InitByModelProtoNode( zCModelNode* )                zCall( 0x0055E370 );
    void SetNodeVisualS( zCVisual*, int )                    zCall( 0x0055E420 );
    void AddNodeAni( zCModelAniActive* )                     zCall( 0x00564A70 );
    void RemoveAllNodeAnis()                                 zCall( 0x00564CA0 );
    void RemoveNodeAni( zCModelAniActive* )                  zCall( 0x00564CB0 );
    void FindMasterAni()                                     zCall( 0x00564DA0 );
    void FadeOutNodeAni( zCModelAniActive* )                 zCall( 0x00564E10 );
    void CalcWeights( zCModel* )                             zCall( 0x005653F0 );
    void AddToNodeAniWeight( int, float )                    zCall( 0x00565630 );
    void CalcBlending( zCModel* )                            zCall( 0x005656A0 );
    int GetNodeAniListIndex( zCModelAniActive const* ) const zCall( 0x00565830 );

    // user API
    #include "zCModelNodeInst.inl"
  };
#pragma pack( pop )

  struct zTRandAni {
    int randAniProtoID;
    int prob;

    zTRandAni() {}

    // user API
    #include "zTRandAni.inl"
  };

  struct zTAniAttachment {
    int aniID;
    zCArray<zTRandAni> randAniList;
    float randAniFreq;
    int randAniProbSum;

    void zTAniAttachment_OnInit() zCall( 0x00568AB0 );
    ~zTAniAttachment()            zCall( 0x00568A90 );
    zTAniAttachment()             zInit( zTAniAttachment_OnInit() );

    // user API
    #include "zTAniAttachment.inl"
  };

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

    struct zTMdl_NodeVobAttachment {
    public:
      zCVob* vob;
      zCModelNodeInst* mnode;

      // user API
      #include "zCModel_zTMdl_NodeVobAttachment.inl"
    };

    struct zTMdl_StartedVobFX {
    public:
      zCVob* vob;
      float vobFXHandle;

      // user API
      #include "zCModel_zTMdl_StartedVobFX.inl"
    };

    struct zTAniMeshLibEntry {
    public:
      zCModelAniActive* ani;
      zCModelMeshLib* meshLib;

      // user API
      #include "zCModel_zTAniMeshLibEntry.inl"
    };

    struct zTMeshLibEntry {
    public:
      zCModelTexAniState texAniState;
      zCModelMeshLib* meshLib;

      // user API
      #include "zCModel_zTMeshLibEntry.inl"
    };

    int numActiveAnis;
    zCModelAniActive* aniChannels[zMDL_MAX_ANIS_PARALLEL];
    zCModelAniActive* activeAniList;
    zCVob* homeVob;
    zCArray<zCModelPrototype*> modelProtoList;
    zCArray<zCModelNodeInst*> nodeList;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;
    zCArraySort<zTAniAttachment*> aniAttachList;
    zCArray<zTMdl_NodeVobAttachment>attachedVobList;
    zCArray<zTMdl_StartedVobFX> startedVobFX;
    zCArray<zTAniMeshLibEntry> aniMeshLibList;
    zCArray<zTMeshLibEntry*> meshLibList;
    int lastTimeBBox3DTreeUpdate;
    zCArray<zCModelAniEvent*> occuredAniEvents;
    zTBBox3D bbox3D;
    zTBBox3D bbox3DLocalFixed;
    zTBBox3D bbox3DCollDet;
    float modelDistanceToCam;
    float fatness;
    zVEC3 modelScale;
    zVEC3 aniTransScale;
    zVEC3 rootPosLocal;
    zVEC3 vobTrans;
    zCQuat vobRot;
    zVEC3 modelVelocity;
    int actVelRingPos;
    zVEC3 modelVelRing[zMDL_VELRING_SIZE];
    group {
      unsigned char isVisible         : 1;
      unsigned char isFlying          : 1;
      unsigned char randAnisEnabled   : 1;
      unsigned char lerpSamples       : 1;
      unsigned char modelScaleOn      : 1;
      unsigned char doVobRot          : 1;
      unsigned char nodeShadowEnabled : 1;
      unsigned char dynLightMode      : 1;
    };
    float timeScale;
    zCModelAni** aniHistoryList;

    zCModel() {}
    void zCModel_OnInit( zCModelPrototype* )                                                                        zCall( 0x0055E9F0 );
    zCModelAni* GetAniFromAniID( int ) const                                                                        zCall( 0x0046D1E0 );
    int IsAniActive( zCModelAni* )                                                                                  zCall( 0x0046D220 );
    int GetAniIDFromAniName( zSTRING const& ) const                                                                 zCall( 0x0047EC50 );
    void Init()                                                                                                     zCall( 0x0055E7D0 );
    zCModel( zCModelPrototype* a0 )                                                                                 zInit( zCModel_OnInit( a0 ));
    void CopyProtoNodeList()                                                                                        zCall( 0x0055EB90 );
    int ApplyModelProtoOverlay( zSTRING const& )                                                                    zCall( 0x0055EFB0 );
    int ApplyModelProtoOverlay( zCModelPrototype* )                                                                 zCall( 0x0055F000 );
    int HasAppliedModelProtoOverlay( zCModelPrototype* ) const                                                      zCall( 0x0055F210 );
    int HasAppliedModelProtoOverlay( zSTRING const& ) const                                                         zCall( 0x0055F240 );
    void RemoveModelProtoOverlay( zSTRING const& )                                                                  zCall( 0x0055F3C0 );
    void RemoveModelProtoOverlay( zCModelPrototype* )                                                               zCall( 0x0055F5C0 );
    void CalcNodeListBBoxWorld()                                                                                    zCall( 0x0055F740 );
    zTBBox3D GetBBox3DNodeWorld( zCModelNodeInst* )                                                                 zCall( 0x0055F870 );
    zVEC3 GetNodePositionWorld( zCModelNodeInst* )                                                                  zCall( 0x0055F8C0 );
    void CalcModelBBox3DWorld()                                                                                     zCall( 0x0055F8F0 );
    void SetNodeVisual( zCModelNodeInst*, zCVisual*, int )                                                          zCall( 0x0055FA00 );
    void SetDynLightMode( int )                                                                                     zCall( 0x0055FA30 );
    void __fastcall RenderNodeList( zTRenderContext&, zCArray<zMAT4*>&, zCRenderLightContainer&, zTPMLightingMode ) zCall( 0x0055FA50 );
    void CheckNodeCollisionList( zCOBBox3D const&, zMAT4& )                                                         zCall( 0x00560A10 );
    void CheckNodeCollision( zCModel*, zCModelNodeInst*, zMAT4&, zCList<zCModelNodeInst>& )                         zCall( 0x00560AB0 );
    zMAT4 GetTrafoNodeToModel( zCModelNodeInst* )                                                                   zCall( 0x00560BF0 );
    void SetRandAnisEnabled( int )                                                                                  zCall( 0x00560D20 );
    zCModelAniActive* GetActiveAni( int ) const                                                                     zCall( 0x00560D90 );
    zCModelAniActive* GetActiveAni( zCModelAni* ) const                                                             zCall( 0x00560DD0 );
    void StopAni( int )                                                                                             zCall( 0x00560E10 );
    void StopAni( zCModelAni* )                                                                                     zCall( 0x00560E90 );
    void StopAni( zCModelAniActive* )                                                                               zCall( 0x00560EE0 );
    zVEC3 GetAniTransLerp( zCModelAni*, float, int ) const                                                          zCall( 0x005610A0 );
    void StartAni( zSTRING const&, int )                                                                            zCall( 0x005611A0 );
    void StartAni( int, int )                                                                                       zCall( 0x005612A0 );
    void StartAni( zCModelAni*, int )                                                                               zCall( 0x005612F0 );
    void AssertActiveAniListAlloced()                                                                               zCall( 0x005619C0 );
    void DoAniEvents( zCModelAniActive* )                                                                           zCall( 0x00561AF0 );
    void __fastcall AdvanceAni( zCModelAniActive*, int& )                                                           zCall( 0x00562A10 );
    void AdvanceAnis()                                                                                              zCall( 0x00562CD0 );
    void SetModelScale( zVEC3 const& )                                                                              zCall( 0x00563BC0 );
    int IsStateActive( zCModelAni const* ) const                                                                    zCall( 0x00563D30 );
    zCModelNodeInst* SearchNode( zSTRING const& )                                                                   zCall( 0x00563F80 );
    int SetNodeMeshTexture( zSTRING const&, int, int, zSTRING* )                                                    zCall( 0x00564030 );
    int SetMeshLibTexture( zSTRING const&, int, int, zSTRING* )                                                     zCall( 0x00564150 );
    void RemoveMeshLibAll()                                                                                         zCall( 0x00564350 );
    int RemoveMeshLib( zSTRING const& )                                                                             zCall( 0x00564380 );
    int ApplyMeshLib( zSTRING const& )                                                                              zCall( 0x00564590 );
    void UpdateMeshLibTexAniState()                                                                                 zCall( 0x005649F0 );
    void FadeOutAni( int )                                                                                          zCall( 0x00564ED0 );
    void FadeOutAni( zCModelAni* )                                                                                  zCall( 0x00564F60 );
    void FadeOutAni( zCModelAniActive* )                                                                            zCall( 0x00564FA0 );
    void FadeOutAnisLayerRange( int, int )                                                                          zCall( 0x00565170 );
    void StopAnisLayerRange( int, int )                                                                             zCall( 0x005651C0 );
    float GetProgressPercent( zSTRING const& ) const                                                                zCall( 0x00565210 );
    float GetProgressPercent( int ) const                                                                           zCall( 0x005652C0 );
    void SetCombineAniXY( int, float, float ) const                                                                 zCall( 0x00565330 );
    int GetCombineAniXY( int, float&, float& ) const                                                                zCall( 0x00565380 );
    void CalcNodeListAniBlending()                                                                                  zCall( 0x00565800 );
    void CalcTransBlending()                                                                                        zCall( 0x00565860 );
    void AttachChildVobToNode( zCVob*, zCModelNodeInst* )                                                           zCall( 0x005665B0 );
    void RemoveChildVobFromNode( zCVob* )                                                                           zCall( 0x00566720 );
    void RemoveAllChildVobsFromNode()                                                                               zCall( 0x005667A0 );
    void UpdateAttachedVobs()                                                                                       zCall( 0x005667F0 );
    void RemoveStartedVobFX( zCVob* )                                                                               zCall( 0x00566940 );
    zVEC3 GetVelocityRing() const                                                                                   zCall( 0x005669F0 );
    void ResetVelocity()                                                                                            zCall( 0x00566A50 );
    void GetAniMinMaxWeight( zCModelAniActive*, float&, float& )                                                    zCall( 0x00566AE0 );
    void PrintStatus( int, int )                                                                                    zCall( 0x00566D10 );
    void psb_WriteAniBlock( zCBuffer&, int, int ) const                                                             zCall( 0x00567360 );
    void psb_ReadAniBlock( zCBuffer&, int, zCModelAniActive* )                                                      zCall( 0x005674F0 );
    void PackStateBinary( zCBuffer& )                                                                               zCall( 0x00567740 );
    void UnpackStateBinary( zCBuffer& )                                                                             zCall( 0x00567AB0 );
    void ShowAniListAdd( zCModelAni* )                                                                              zCall( 0x00568240 );
    void ShowAniList( int )                                                                                         zCall( 0x005682C0 );
    zTAniAttachment* SearchAniAttachList( int ) const                                                               zCall( 0x00568AF0 );
    void RemoveAniAttachment( int )                                                                                 zCall( 0x00568B70 );
    void RemoveAllAniAttachments()                                                                                  zCall( 0x00568CB0 );
    zTAniAttachment* GetCreateAniAttachment( int )                                                                  zCall( 0x00568D00 );
    void DeleteRandAniList( int )                                                                                   zCall( 0x00568EC0 );
    void InsertRandAni( int, int, int )                                                                             zCall( 0x00568F40 );
    float GetRandAniFreq( int ) const                                                                               zCall( 0x00569060 );
    void SetRandAniFreq( int, float )                                                                               zCall( 0x005690F0 );
    void __fastcall RecalcRootPosLocal( int )                                                                       zCall( 0x00569110 );
    static zCObject* _CreateNewInstance()                                                                           zCall( 0x0055CC90 );
    static int AniAttachmentCompare( void const*, void const* )                                                     zCall( 0x00568AC0 );
    virtual zCClassDef* _GetClassDef() const                                                                        zCall( 0x0055CE10 );
    virtual ~zCModel()                                                                                              zCall( 0x0055E4F0 );
    virtual int Render( zTRenderContext& )                                                                          zCall( 0x00560770 );
    virtual int IsBBox3DLocal()                                                                                     zCall( 0x0055CE20 );
    virtual zTBBox3D GetBBox3D()                                                                                    zCall( 0x00563EB0 );
    virtual zSTRING GetVisualName()                                                                                 zCall( 0x00563EF0 );
    virtual void SetVisualUsedBy( zCVob* )                                                                          zCall( 0x0055EE80 );
    virtual unsigned long GetRenderSortKey() const                                                                  zCall( 0x00568330 );
    virtual int CanTraceRay() const                                                                                 zCall( 0x0055CE30 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                      zCall( 0x00568350 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                                                        zCall( 0x00561A40 );
    virtual zSTRING const* GetFileExtension( int )                                                                  zCall( 0x0055EEF0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                     zCall( 0x0055EF10 );
    virtual void StartAnimation( zSTRING const& )                                                                   zCall( 0x0055CE40 );
    virtual void StopAnimation( zSTRING const& )                                                                    zCall( 0x0055CE50 );
    virtual int IsAnimationActive( zSTRING const& )                                                                 zCall( 0x0055CEF0 );
    virtual zSTRING const* GetAnyAnimation()                                                                        zCall( 0x00561050 );


    // static properties
    static int& s_drawSkeleton;

    // user API
    #include "zCModel.inl"
  };

  class zCModelConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCModelConvertFileHandler_OnInit()                            zCall( 0x00581C00 );
    zCModelConvertFileHandler()                                        zInit( zCModelConvertFileHandler_OnInit() );
    virtual ~zCModelConvertFileHandler()                               zCall( 0x00424090 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x00581D30 );

    // user API
    #include "zCModelConvertFileHandler.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMODEL_H__VER0__