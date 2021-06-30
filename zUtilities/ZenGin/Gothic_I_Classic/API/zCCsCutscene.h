// Supported with union (c) 2018 Union team

#ifndef __ZCCS_CUTSCENE_H__VER0__
#define __ZCCS_CUTSCENE_H__VER0__

#include "zDisk.h"
#include "zArchiver.h"
#include "zCCsProps.h"
#include "zCsCamera.h"
#include "zTools.h"

namespace Gothic_I_Classic {

  struct zTCSBlockPosition {
    zCArray<zCCSBlockBase*> flatData;
    int index;
    int numInList;

    zTCSBlockPosition() {}
    ~zTCSBlockPosition() zCall( 0x00417700 );

    // user API
    #include "zTCSBlockPosition.inl"
  };

  class zCEvMsgCutscene : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEvMsgCutscene )

    enum TCutsceneSubType {
      EV_CS_STARTPLAY,
      EV_CS_STOP,
      EV_CS_INTERRUPT,
      EV_CS_RESUME,
      EV_CS_MAX
    };

    zSTRING csName;
    int isOutputUnit;
    int isGlobalCutscene;
    int isMainRole;
    int deleted;

    zCEvMsgCutscene() {}
    void zCEvMsgCutscene_OnInit( TCutsceneSubType )                     zCall( 0x0040C100 );
    zCEvMsgCutscene( TCutsceneSubType a0 )                              zInit( zCEvMsgCutscene_OnInit( a0 ));
    void SetCutsceneName( zSTRING )                                     zCall( 0x004136F0 );
    zSTRING GetCutsceneName()                                           zCall( 0x006A84B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040B410 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040B550 );
    virtual ~zCEvMsgCutscene()                                          zCall( 0x0040C250 );
    virtual int IsHighPriority()                                        zCall( 0x0040B560 );
    virtual void Delete()                                               zCall( 0x0040B570 );
    virtual int IsDeleted()                                             zCall( 0x0040B580 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x0040C2B0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x0040C2C0 );

    // user API
    #include "zCEvMsgCutscene.inl"
  };

  class zCCSRole : public zCObject, public zSTRING {
  public:
    zCLASS_DECLARATION( zCCSRole )

    enum zTCSRoleFlag {
      CSRrequired,
      CSRdelayable,
      CSRnonrequired
    };

    int mustBeAlive;
    zTCSRoleFlag rFlag;
    zCVob* roleVob;

    void zCCSRole_OnInit()                                              zCall( 0x0040B620 );
    void zCCSRole_OnInit( zSTRING& )                                    zCall( 0x0040B770 );
    zCCSRole()                                                          zInit( zCCSRole_OnInit() );
    zCCSRole( zSTRING& a0 )                                             zInit( zCCSRole_OnInit( a0 ));
    void SetRoleVob( zCVob* )                                           zCall( 0x0040BB20 );
    zCVob* GetRoleVob()                                                 zCall( 0x0040BF40 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040B0D0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040B220 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0040BF50 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0040BFB0 );
    virtual ~zCCSRole()                                                 zCall( 0x0040B8B0 );
    /* for zSTRING num : 0*/
  };

  class zCCSBlockBase : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSBlockBase )

    void zCCSBlockBase_OnInit()                                         zCall( 0x0040C470 );
    zCCSBlockBase()                                                     zInit( zCCSBlockBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040AC20 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416680 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416690 );
    virtual ~zCCSBlockBase()                                            zCall( 0x0040C600 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040C610 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zPureCall;
    virtual zSTRING GetRoleName()                                       zCall( 0x0040C670 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040C700 );
    virtual void Play( zCArray<zCEventManager*> const& )                zPureCall;
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zPureCall;
    virtual void Play( zCEventManager* )                                zPureCall;
    virtual void Play( zCEventManager*, float, float )                  zPureCall;
    virtual float GetMinTime()                                          zPureCall;
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zPureCall;
    virtual int IsFinished( zCEventManager* )                           zPureCall;
    virtual zCEventMessage* GetCommand()                                zCall( 0x00404E40 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040C620 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040A610 );
    virtual void DeleteChild( int )                                     zCall( 0x0040C710 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040C630 );
    virtual int GetRoleNumOfChild( int )                                zCall( 0x0040C640 );
    virtual void BlockCorrection()                                      zCall( 0x0040C650 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040C660 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040C720 );

    // user API
    #include "zCCSBlockBase.inl"
  };

  class zCCSAtomicBlock : public zCCSBlockBase {
  public:
    zCLASS_DECLARATION( zCCSAtomicBlock )

    enum zCCSAtomicBlockEnum0 {
      EVCOM_NOTSTARTED,
      EVCOM_PLAYING,
      EVCOM_FINISHED
    };

    zCVob* roleVob;
    zCEventMessage* commandRef;
    zCEventMessage* command;
    zCCSAtomicBlockEnum0 commandState;

    void zCCSAtomicBlock_OnInit()                                       zCall( 0x0040C730 );
    zCCSAtomicBlock()                                                   zInit( zCCSAtomicBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040A470 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040A640 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004166A0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004166C0 );
    virtual ~zCCSAtomicBlock()                                          zCall( 0x0040C890 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040C930 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040CB90 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040CBB0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040CBD0 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040CC50 );
    virtual float GetMinTime()                                          zCall( 0x0040CC60 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040A650 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040CC80 );
    virtual zCEventMessage* GetCommand()                                zCall( 0x0040A660 );

    // user API
    #include "zCCSAtomicBlock.inl"
  };

  class zCCSBlockPosition {
  public:
    float position;
    zCCSBlockBase* block;

    void zCCSBlockPosition_OnInit()                           zCall( 0x004165F0 );
    void zCCSBlockPosition_OnInit( zCCSBlockBase* )           zCall( 0x00416610 );
    void zCCSBlockPosition_OnInit( float, zCCSBlockBase* )    zCall( 0x00416630 );
    zCCSBlockPosition()                                       zInit( zCCSBlockPosition_OnInit() );
    zCCSBlockPosition( zCCSBlockBase* a0 )                    zInit( zCCSBlockPosition_OnInit( a0 ));
    zCCSBlockPosition( float a0, zCCSBlockBase* a1 )          zInit( zCCSBlockPosition_OnInit( a0, a1 ));
    zCCSBlockPosition& operator =( zCCSBlockPosition const& ) zCall( 0x00416660 );
    virtual ~zCCSBlockPosition()                              zCall( 0x00416650 );

    // user API
    #include "zCCSBlockPosition.inl"
  };

  class zCCSBlock : public zCCSBlockBase {
  public:
    zCLASS_DECLARATION( zCCSBlock )

    zCArray<zCCSBlockPosition> blocks;
    zSTRING roleName;

    void zCCSBlock_OnInit()                                             zCall( 0x0040CE70 );
    zCCSBlock()                                                         zInit( zCCSBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040A850 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040A950 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004166F0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416860 );
    virtual ~zCCSBlock()                                                zCall( 0x0040CF40 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040D020 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040D550 );
    virtual zSTRING GetRoleName()                                       zCall( 0x0040D5A0 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040D5F0 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040D210 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040D2E0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040D100 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040D150 );
    virtual float GetMinTime()                                          zCall( 0x0040D3B0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040D490 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040D440 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040D7D0 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040D730 );
    virtual void DeleteChild( int )                                     zCall( 0x0040D070 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040D060 );
    virtual void BlockCorrection()                                      zCall( 0x0040D8B0 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040D870 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040D040 );

    // user API
    #include "zCCSBlock.inl"
  };

  class zCCSSyncBlock : public zCCSBlock {
  public:
    zCLASS_DECLARATION( zCCSSyncBlock )

    zCArray<int> roleAss;

    void zCCSSyncBlock_OnInit()                                         zCall( 0x0040D9B0 );
    zCCSSyncBlock()                                                     zInit( zCCSSyncBlock_OnInit() );
    void AssignerCorrection( int )                                      zCall( 0x0040DFC0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040AB40 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040AC50 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416A20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416BE0 );
    virtual ~zCCSSyncBlock()                                            zCall( 0x0040DA90 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040DB90 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040DC40 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040DB40 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040DAF0 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040DDE0 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040DD10 );
    virtual void DeleteChild( int )                                     zCall( 0x0040DF00 );
    virtual int GetRoleNumOfChild( int )                                zCall( 0x0040DCF0 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040DEB0 );

    // user API
    #include "zCCSSyncBlock.inl"
  };

  class zCCutscene : public zCCSBlock {
  public:
    zCLASS_DECLARATION( zCCutscene )

    enum zTCSCheckResult {
      CS_CHECK_UNKNOWN,
      CS_CHECK_OK,
      CS_CHECK_ROLE_ERROR,
      CS_CHECK_ROLE_MISSING,
      CS_CHECK_PLAYER_MISSING,
      CS_CHECK_PLAYER_ERROR,
      CS_CHECK_ROLECHECK_FAILED,
      CS_CHECK_NOSTAGE,
      CS_CHECK_NOWORLD,
      CS_CHECk_MAX
    };

    zTCSCheckResult lastCheckResult;
    zCArray<zCCSRole*> roleList;
    zCArray<zCEventManager*> roleEvMList;
    zCArray<zCVob*> roleVobList;
    zCVob* mainRoleVob;
    zCCSProps* properties;
    zCCSPlayer* ownerPlayer;
    int actualBlockNum;
    zCCSBlockBase* actualBlock;

    void zCCutscene_OnInit()                                            zCall( 0x0040DFF0 );
    zCCutscene()                                                        zInit( zCCutscene_OnInit() );
    int IsMember( zCVob* )                                              zCall( 0x0040E3E0 );
    void SetRoleListForDebugging( zCArray<zCCSRole*>& )                 zCall( 0x0040E410 );
    void SaveRolesVobs( zCBuffer& )                                     zCall( 0x0040E5C0 );
    void RestoreRoleVobs( zCBuffer& )                                   zCall( 0x0040E7E0 );
    int CheckMainRole( zCVob* )                                         zCall( 0x0040EA20 );
    int CheckPlayState()                                                zCall( 0x0040F870 );
    zCEventManager* SolveEventManager( int )                            zCall( 0x00413CD0 );
    int GetActualBlockNum()                                             zCall( 0x00415770 );
    void ResumeAtBlock( int )                                           zCall( 0x00415B20 );
    void NewRole( zSTRING& )                                            zCall( 0x00416040 );
    void DeleteRole( int )                                              zCall( 0x00416230 );
    void RegisterAdditionalVob( zCTree<zCVob>* )                        zCall( 0x00416320 );
    zCVob* FirstRoleUsed()                                              zCall( 0x00417180 );
    zTCSCheckResult GetLastCheckResult( zSTRING& )                      zCall( 0x00417250 );
    int TryToCancel()                                                   zCall( 0x00417550 );
    zTCSBlockPosition GetFirstBlockPosition()                           zCall( 0x00417580 );
    zCEventMessage* GetNextMessage( zTCSBlockPosition& )                zCall( 0x00417720 );
    zCCSBlockBase* GetNextBlock( zTCSBlockPosition& )                   zCall( 0x00417770 );
    void SerializeCutscene( zCCutscene*, zTCSBlockPosition& )           zCall( 0x004177A0 );
    void SerializeBlock( zCCSBlockBase*, zTCSBlockPosition& )           zCall( 0x00417930 );
    zCCSProps* GetProperties()                                          zCall( 0x0041CCF0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040AE50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040E1E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416E30 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416EC0 );
    virtual ~zCCutscene()                                               zCall( 0x0040E230 );
    virtual int NewBlock( int, int )                                    zCall( 0x00415BA0 );
    virtual int AddMainRole( zCVob* )                                   zCall( 0x00410190 );
    virtual void AddRoleOU( zCVob* )                                    zCall( 0x0040F9B0 );
    virtual void RemoveRole( zCVob* )                                   zCall( 0x004109B0 );
    virtual void SetOwnerPlayer( zCCSPlayer* )                          zCall( 0x0040E3A0 );
    virtual void Reset()                                                zCall( 0x00413860 );
    virtual void ClearCutscene()                                        zCall( 0x00413960 );
    virtual int StartPlaying()                                          zCall( 0x00412AD0 );
    virtual void Stop()                                                 zCall( 0x00413D10 );
    virtual void StopRole( zCVob* )                                     zCall( 0x00413B50 );
    virtual void Interrupt()                                            zCall( 0x00414DB0 );
    virtual int ResumeActBlock()                                        zCall( 0x00415780 );
    virtual int PlaySub( float, float )                                 zCall( 0x00415B30 );
    virtual void NewCS( zCCSManager* )                                  zCall( 0x00415DA0 );
    virtual int IsCutscene()                                            zCall( 0x0040E1F0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040D490 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040D440 );
    virtual int IsFinished()                                            zCall( 0x00415B90 );
    virtual void PrintDebugInfo( zSTRING const& )                       zCall( 0x00417240 );
    virtual int CheckRoles( int& )                                      zCall( 0x004171B0 );
    virtual int CSCheck( int& )                                         zCall( 0x00410A30 );
    virtual zCVob* GetStage()                                           zCall( 0x0040F860 );
    virtual zCVob* LoadStage()                                          zCall( 0x00416390 );
    virtual zCVob* CatchPlayer( zCVob* )                                zCall( 0x004165B0 );
    virtual void PrepareBlock()                                         zCall( 0x0040F930 );

    // user API
    #include "zCCutscene.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_CUTSCENE_H__VER0__