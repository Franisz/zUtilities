// Supported with union (c) 2018 Union team

#ifndef __ZCCS_CUTSCENE_H__VER1__
#define __ZCCS_CUTSCENE_H__VER1__

#include "zDisk.h"
#include "zArchiver.h"
#include "zCCsProps.h"
#include "zCsCamera.h"

namespace Gothic_I_Addon {

  struct zTCSBlockPosition {
    zCArray<zCCSBlockBase*> flatData;
    int index;
    int numInList;

    zTCSBlockPosition() {}
    ~zTCSBlockPosition() zCall( 0x00419540 );

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
    void zCEvMsgCutscene_OnInit( TCutsceneSubType )                     zCall( 0x0040D330 );
    zCEvMsgCutscene( TCutsceneSubType a0 )                              zInit( zCEvMsgCutscene_OnInit( a0 ));
    void SetCutsceneName( zSTRING )                                     zCall( 0x00415170 );
    zSTRING GetCutsceneName()                                           zCall( 0x006DB160 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040C540 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040C680 );
    virtual ~zCEvMsgCutscene()                                          zCall( 0x0040D490 );
    virtual int IsHighPriority()                                        zCall( 0x0040C690 );
    virtual void Delete()                                               zCall( 0x0040C6A0 );
    virtual int IsDeleted()                                             zCall( 0x0040C6B0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x0040D500 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x0040D510 );

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

    void zCCSRole_OnInit()                                              zCall( 0x0040C750 );
    void zCCSRole_OnInit( zSTRING& )                                    zCall( 0x0040C8A0 );
    zCCSRole()                                                          zInit( zCCSRole_OnInit() );
    zCCSRole( zSTRING& a0 )                                             zInit( zCCSRole_OnInit( a0 ));
    void SetRoleVob( zCVob* )                                           zCall( 0x0040CCB0 );
    zCVob* GetRoleVob()                                                 zCall( 0x0040D150 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040C1E0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040C330 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0040D160 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0040D1D0 );
    virtual ~zCCSRole()                                                 zCall( 0x0040C9E0 );
    /* for zSTRING num : 0*/
  };

  class zCCSBlockBase : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSBlockBase )

    void zCCSBlockBase_OnInit()                                         zCall( 0x0040D6C0 );
    zCCSBlockBase()                                                     zInit( zCCSBlockBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040BD10 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00418410 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00418420 );
    virtual ~zCCSBlockBase()                                            zCall( 0x0040D850 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040D860 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zPureCall;
    virtual zSTRING GetRoleName()                                       zCall( 0x0040D8C0 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040D950 );
    virtual void Play( zCArray<zCEventManager*> const& )                zPureCall;
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zPureCall;
    virtual void Play( zCEventManager* )                                zPureCall;
    virtual void Play( zCEventManager*, float, float )                  zPureCall;
    virtual float GetMinTime()                                          zPureCall;
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zPureCall;
    virtual int IsFinished( zCEventManager* )                           zPureCall;
    virtual zCEventMessage* GetCommand()                                zCall( 0x00405690 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040D870 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040B6B0 );
    virtual void DeleteChild( int )                                     zCall( 0x0040D960 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040D880 );
    virtual int GetRoleNumOfChild( int )                                zCall( 0x0040D890 );
    virtual void BlockCorrection()                                      zCall( 0x0040D8A0 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040D8B0 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040D970 );

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

    void zCCSAtomicBlock_OnInit()                                       zCall( 0x0040D980 );
    zCCSAtomicBlock()                                                   zInit( zCCSAtomicBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040B520 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040B6E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00418430 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00418450 );
    virtual ~zCCSAtomicBlock()                                          zCall( 0x0040DAF0 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040DB90 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040DE10 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040DE30 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040DE50 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040DEE0 );
    virtual float GetMinTime()                                          zCall( 0x0040DEF0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040B6F0 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040DF10 );
    virtual zCEventMessage* GetCommand()                                zCall( 0x0040B700 );

    // user API
    #include "zCCSAtomicBlock.inl"
  };

  class zCCSBlockPosition {
  public:
    float position;
    zCCSBlockBase* block;

    void zCCSBlockPosition_OnInit()                           zCall( 0x00418380 );
    void zCCSBlockPosition_OnInit( zCCSBlockBase* )           zCall( 0x004183A0 );
    void zCCSBlockPosition_OnInit( float, zCCSBlockBase* )    zCall( 0x004183C0 );
    zCCSBlockPosition()                                       zInit( zCCSBlockPosition_OnInit() );
    zCCSBlockPosition( zCCSBlockBase* a0 )                    zInit( zCCSBlockPosition_OnInit( a0 ));
    zCCSBlockPosition( float a0, zCCSBlockBase* a1 )          zInit( zCCSBlockPosition_OnInit( a0, a1 ));
    zCCSBlockPosition& operator =( zCCSBlockPosition const& ) zCall( 0x004183F0 );
    virtual ~zCCSBlockPosition()                              zCall( 0x004183E0 );

    // user API
    #include "zCCSBlockPosition.inl"
  };

  class zCCSBlock : public zCCSBlockBase {
  public:
    zCLASS_DECLARATION( zCCSBlock )

    zCArray<zCCSBlockPosition> blocks;
    zSTRING roleName;

    void zCCSBlock_OnInit()                                             zCall( 0x0040E130 );
    zCCSBlock()                                                         zInit( zCCSBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040B910 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040BA10 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00418480 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00418610 );
    virtual ~zCCSBlock()                                                zCall( 0x0040E200 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040E2F0 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040E810 );
    virtual zSTRING GetRoleName()                                       zCall( 0x0040E850 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040E8A0 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040E4B0 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040E580 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040E3D0 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040E420 );
    virtual float GetMinTime()                                          zCall( 0x0040E650 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040E730 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040E6E0 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040EA80 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040E9E0 );
    virtual void DeleteChild( int )                                     zCall( 0x0040E340 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040E330 );
    virtual void BlockCorrection()                                      zCall( 0x0040EB60 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040EB20 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040E310 );

    // user API
    #include "zCCSBlock.inl"
  };

  class zCCSSyncBlock : public zCCSBlock {
  public:
    zCLASS_DECLARATION( zCCSSyncBlock )

    zCArray<int> roleAss;

    void zCCSSyncBlock_OnInit()                                         zCall( 0x0040EC50 );
    zCCSSyncBlock()                                                     zInit( zCCSSyncBlock_OnInit() );
    void AssignerCorrection( int )                                      zCall( 0x0040F240 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040BC20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040BD40 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00418800 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004189F0 );
    virtual ~zCCSSyncBlock()                                            zCall( 0x0040ED30 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040EE30 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040EED0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040EDE0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040ED90 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040F070 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040EFA0 );
    virtual void DeleteChild( int )                                     zCall( 0x0040F190 );
    virtual int GetRoleNumOfChild( int )                                zCall( 0x0040EF80 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040F140 );

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

    void zCCutscene_OnInit()                                            zCall( 0x0040F270 );
    zCCutscene()                                                        zInit( zCCutscene_OnInit() );
    int IsMember( zCVob* )                                              zCall( 0x0040F670 );
    void SetRoleListForDebugging( zCArray<zCCSRole*>& )                 zCall( 0x0040F6A0 );
    void SaveRolesVobs( zCBuffer& )                                     zCall( 0x0040F850 );
    void RestoreRoleVobs( zCBuffer& )                                   zCall( 0x0040FA90 );
    int CheckMainRole( zCVob* )                                         zCall( 0x0040FD10 );
    int CheckPlayState()                                                zCall( 0x00410D60 );
    zCEventManager* SolveEventManager( int )                            zCall( 0x00415780 );
    int GetActualBlockNum()                                             zCall( 0x004174A0 );
    void ResumeAtBlock( int )                                           zCall( 0x00417860 );
    void NewRole( zSTRING& )                                            zCall( 0x00417DA0 );
    void DeleteRole( int )                                              zCall( 0x00417F90 );
    void RegisterAdditionalVob( zCTree<zCVob>* )                        zCall( 0x00418080 );
    zCVob* FirstRoleUsed()                                              zCall( 0x00418FD0 );
    zTCSCheckResult GetLastCheckResult( zSTRING& )                      zCall( 0x00419090 );
    int TryToCancel()                                                   zCall( 0x00419390 );
    zTCSBlockPosition GetFirstBlockPosition()                           zCall( 0x004193C0 );
    zCEventMessage* GetNextMessage( zTCSBlockPosition& )                zCall( 0x00419560 );
    zCCSBlockBase* GetNextBlock( zTCSBlockPosition& )                   zCall( 0x004195B0 );
    void SerializeCutscene( zCCutscene*, zTCSBlockPosition& )           zCall( 0x004195E0 );
    void SerializeBlock( zCCSBlockBase*, zTCSBlockPosition& )           zCall( 0x00419760 );
    zCCSProps* GetProperties()                                          zCall( 0x0041EBF0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040BF50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040F460 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00418C70 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00418D00 );
    virtual ~zCCutscene()                                               zCall( 0x0040F4B0 );
    virtual int NewBlock( int, int )                                    zCall( 0x004178E0 );
    virtual int AddMainRole( zCVob* )                                   zCall( 0x00411730 );
    virtual void AddRoleOU( zCVob* )                                    zCall( 0x00410EA0 );
    virtual void RemoveRole( zCVob* )                                   zCall( 0x00411FE0 );
    virtual void SetOwnerPlayer( zCCSPlayer* )                          zCall( 0x0040F630 );
    virtual void Reset()                                                zCall( 0x00415300 );
    virtual void ClearCutscene()                                        zCall( 0x00415400 );
    virtual int StartPlaying()                                          zCall( 0x00414430 );
    virtual void Stop()                                                 zCall( 0x004157C0 );
    virtual void StopRole( zCVob* )                                     zCall( 0x00415600 );
    virtual void Interrupt()                                            zCall( 0x00416A30 );
    virtual int ResumeActBlock()                                        zCall( 0x004174B0 );
    virtual int PlaySub( float, float )                                 zCall( 0x00417870 );
    virtual void NewCS( zCCSManager* )                                  zCall( 0x00417AF0 );
    virtual int IsCutscene()                                            zCall( 0x0040F470 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040E730 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040E6E0 );
    virtual int IsFinished()                                            zCall( 0x004178D0 );
    virtual void PrintDebugInfo( zSTRING const& )                       zCall( 0x00419080 );
    virtual int CheckRoles( int& )                                      zCall( 0x00419000 );
    virtual int CSCheck( int& )                                         zCall( 0x00412060 );
    virtual zCVob* GetStage()                                           zCall( 0x00410D50 );
    virtual zCVob* LoadStage()                                          zCall( 0x004180F0 );
    virtual zCVob* CatchPlayer( zCVob* )                                zCall( 0x00418340 );
    virtual void PrepareBlock()                                         zCall( 0x00410E20 );

    // user API
    #include "zCCutscene.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_CUTSCENE_H__VER1__