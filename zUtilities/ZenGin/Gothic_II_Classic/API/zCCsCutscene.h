// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_CUTSCENE_H__VER2__
#define __ZCCS_CUTSCENE_H__VER2__

#include "zDisk.h"
#include "zArchiver.h"
#include "zCCsProps.h"
#include "zCsCamera.h"

namespace Gothic_II_Classic {

  // sizeof 14h
  struct zTCSBlockPosition {
    zCArray<zCCSBlockBase*> flatData; // sizeof 0Ch    offset 00h
    int index;                        // sizeof 04h    offset 0Ch
    int numInList;                    // sizeof 04h    offset 10h

    zTCSBlockPosition() {}
    ~zTCSBlockPosition() zCall( 0x00417DB0 );

    // user API
    #include "zTCSBlockPosition.inl"
  };

  // sizeof 50h
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

    zSTRING csName;       // sizeof 14h    offset 2Ch
    int isOutputUnit;     // sizeof 04h    offset 40h
    int isGlobalCutscene; // sizeof 04h    offset 44h
    int isMainRole;       // sizeof 04h    offset 48h
    int deleted;          // sizeof 04h    offset 4Ch

    zCEvMsgCutscene() {}
    void zCEvMsgCutscene_OnInit( TCutsceneSubType ) zCall( 0x0040C4F0 );
    zCEvMsgCutscene( TCutsceneSubType a0 )          zInit( zCEvMsgCutscene_OnInit( a0 ));
    void SetCutsceneName( zSTRING )                 zCall( 0x00413CC0 );
    zSTRING GetCutsceneName()                       zCall( 0x006EDEA0 );
    static zCObject* _CreateNewInstance()           zCall( 0x0040B740 );
    virtual zCClassDef* _GetClassDef() const        zCall( 0x0040B870 );
    virtual ~zCEvMsgCutscene()                      zCall( 0x0040C640 );
    virtual int IsHighPriority()                    zCall( 0x0040B880 );
    virtual void Delete()                           zCall( 0x0040B890 );
    virtual int IsDeleted()                         zCall( 0x0040B8A0 );
    virtual int MD_GetNumOfSubTypes()               zCall( 0x0040C6A0 );
    virtual zSTRING MD_GetSubTypeString( int )      zCall( 0x0040C6B0 );

    // user API
    #include "zCEvMsgCutscene.inl"
  };

  // sizeof 44h
  class zCCSRole : public zCObject, public zSTRING {
  public:
    zCLASS_DECLARATION( zCCSRole )

    enum zTCSRoleFlag {
      CSRrequired,
      CSRdelayable,
      CSRnonrequired
    };

    int mustBeAlive;    // sizeof 04h    offset 38h
    zTCSRoleFlag rFlag; // sizeof 04h    offset 3Ch
    zCVob* roleVob;     // sizeof 04h    offset 40h

    void zCCSRole_OnInit()                   zCall( 0x0040B940 );
    void zCCSRole_OnInit( zSTRING& )         zCall( 0x0040BA90 );
    zCCSRole()                               zInit( zCCSRole_OnInit() );
    zCCSRole( zSTRING& a0 )                  zInit( zCCSRole_OnInit( a0 ));
    void SetRoleVob( zCVob* )                zCall( 0x0040BE80 );
    zCVob* GetRoleVob()                      zCall( 0x0040C330 );
    static zCObject* _CreateNewInstance()    zCall( 0x0040B3E0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const zCall( 0x0040B550 );
    virtual void Archive( zCArchiver& )      zCall( 0x0040C340 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0040C3A0 );
    virtual ~zCCSRole()                      zCall( 0x0040BBD0 );
    /* for zSTRING num : 0*/
  };

  // sizeof 24h
  class zCCSBlockBase : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSBlockBase )

    void zCCSBlockBase_OnInit()                                         zCall( 0x0040C860 );
    zCCSBlockBase()                                                     zInit( zCCSBlockBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040AF40 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416C00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416C10 );
    virtual ~zCCSBlockBase()                                            zCall( 0x0040C9F0 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040CA00 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zPureCall;
    virtual zSTRING GetRoleName()                                       zCall( 0x0040CA60 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040CAF0 );
    virtual void Play( zCArray<zCEventManager*> const& )                zPureCall;
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zPureCall;
    virtual void Play( zCEventManager* )                                zPureCall;
    virtual void Play( zCEventManager*, float, float )                  zPureCall;
    virtual float GetMinTime()                                          zPureCall;
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zPureCall;
    virtual int IsFinished( zCEventManager* )                           zPureCall;
    virtual zCEventMessage* GetCommand()                                zCall( 0x00404F70 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040CA10 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040A950 );
    virtual void DeleteChild( int )                                     zCall( 0x0040CB00 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040CA20 );
    virtual int GetRoleNumOfChild( int )                                zCall( 0x0040CA30 );
    virtual void BlockCorrection()                                      zCall( 0x0040CA40 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040CA50 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040CB10 );

    // user API
    #include "zCCSBlockBase.inl"
  };

  // sizeof 34h
  class zCCSAtomicBlock : public zCCSBlockBase {
  public:
    zCLASS_DECLARATION( zCCSAtomicBlock )

    enum zCCSAtomicBlockEnum0 {
      EVCOM_NOTSTARTED,
      EVCOM_PLAYING,
      EVCOM_FINISHED
    };

    zCVob* roleVob;                    // sizeof 04h    offset 24h
    zCEventMessage* commandRef;        // sizeof 04h    offset 28h
    zCEventMessage* command;           // sizeof 04h    offset 2Ch
    zCCSAtomicBlockEnum0 commandState; // sizeof 04h    offset 30h

    void zCCSAtomicBlock_OnInit()                                       zCall( 0x0040CB20 );
    zCCSAtomicBlock()                                                   zInit( zCCSAtomicBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040A820 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040A980 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416C20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416C40 );
    virtual ~zCCSAtomicBlock()                                          zCall( 0x0040CC80 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040CD20 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040CF80 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040CFA0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040CFC0 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040D040 );
    virtual float GetMinTime()                                          zCall( 0x0040D050 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040A990 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040D070 );
    virtual zCEventMessage* GetCommand()                                zCall( 0x0040A9A0 );

    // user API
    #include "zCCSAtomicBlock.inl"
  };

  // sizeof 0Ch
  class zCCSBlockPosition {
  public:
    float position;       // sizeof 04h    offset 04h
    zCCSBlockBase* block; // sizeof 04h    offset 08h

    void zCCSBlockPosition_OnInit()                           zCall( 0x00416B70 );
    void zCCSBlockPosition_OnInit( zCCSBlockBase* )           zCall( 0x00416B90 );
    void zCCSBlockPosition_OnInit( float, zCCSBlockBase* )    zCall( 0x00416BB0 );
    zCCSBlockPosition()                                       zInit( zCCSBlockPosition_OnInit() );
    zCCSBlockPosition( zCCSBlockBase* a0 )                    zInit( zCCSBlockPosition_OnInit( a0 ));
    zCCSBlockPosition( float a0, zCCSBlockBase* a1 )          zInit( zCCSBlockPosition_OnInit( a0, a1 ));
    zCCSBlockPosition& operator =( zCCSBlockPosition const& ) zCall( 0x00416BE0 );
    virtual ~zCCSBlockPosition()                              zCall( 0x00416BD0 );

    // user API
    #include "zCCSBlockPosition.inl"
  };

  // sizeof 44h
  class zCCSBlock : public zCCSBlockBase {
  public:
    zCLASS_DECLARATION( zCCSBlock )

    zCArray<zCCSBlockPosition> blocks; // sizeof 0Ch    offset 24h
    zSTRING roleName;                  // sizeof 14h    offset 30h

    void zCCSBlock_OnInit()                                             zCall( 0x0040D260 );
    zCCSBlock()                                                         zInit( zCCSBlock_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0040AB90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0040AC80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00416C70 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00416E50 );
    virtual ~zCCSBlock()                                                zCall( 0x0040D330 );
    virtual zCCSBlockBase* GetChild( int )                              zCall( 0x0040D410 );
    virtual void OrganizeRoles( zCArray<zCVob*>&, zCArray<zCCSRole*>& ) zCall( 0x0040D940 );
    virtual zSTRING GetRoleName()                                       zCall( 0x0040D990 );
    virtual void SetRoleName( zSTRING& )                                zCall( 0x0040D9E0 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040D600 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040D6D0 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040D4F0 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040D540 );
    virtual float GetMinTime()                                          zCall( 0x0040D7A0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )           zCall( 0x0040D880 );
    virtual int IsFinished( zCEventManager* )                           zCall( 0x0040D830 );
    virtual int NewBlock( int, int )                                    zCall( 0x0040DBC0 );
    virtual void InsertBlock( zCCSBlockBase*, int )                     zCall( 0x0040DB20 );
    virtual void DeleteChild( int )                                     zCall( 0x0040D460 );
    virtual int GetNumOfChilds()                                        zCall( 0x0040D450 );
    virtual void BlockCorrection()                                      zCall( 0x0040DCA0 );
    virtual void BlockAsFocus( int )                                    zCall( 0x0040DC60 );
    virtual zCCSBlockPosition* GetChildPos( int )                       zCall( 0x0040D430 );

    // user API
    #include "zCCSBlock.inl"
  };

  // sizeof 50h
  class zCCSSyncBlock : public zCCSBlock {
  public:
    zCLASS_DECLARATION( zCCSSyncBlock )

    zCArray<int> roleAss; // sizeof 0Ch    offset 44h

    void zCCSSyncBlock_OnInit()                                        zCall( 0x0040DDA0 );
    zCCSSyncBlock()                                                    zInit( zCCSSyncBlock_OnInit() );
    void AssignerCorrection( int )                                     zCall( 0x0040E3B0 );
    static zCObject* _CreateNewInstance()                              zCall( 0x0040AE70 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x0040AF70 );
    virtual void Archive( zCArchiver& )                                zCall( 0x00417090 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x004172C0 );
    virtual ~zCCSSyncBlock()                                           zCall( 0x0040DE80 );
    virtual void Play( zCArray<zCEventManager*> const& )               zCall( 0x0040DF80 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float ) zCall( 0x0040E030 );
    virtual void Play( zCEventManager* )                               zCall( 0x0040DF30 );
    virtual int IsFinished( zCArray<zCEventManager*> const& )          zCall( 0x0040DEE0 );
    virtual int NewBlock( int, int )                                   zCall( 0x0040E1D0 );
    virtual void InsertBlock( zCCSBlockBase*, int )                    zCall( 0x0040E100 );
    virtual void DeleteChild( int )                                    zCall( 0x0040E2F0 );
    virtual int GetRoleNumOfChild( int )                               zCall( 0x0040E0E0 );
    virtual void BlockAsFocus( int )                                   zCall( 0x0040E2A0 );

    // user API
    #include "zCCSSyncBlock.inl"
  };

  // sizeof 80h
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

    zTCSCheckResult lastCheckResult;      // sizeof 04h    offset 44h
    zCArray<zCCSRole*> roleList;          // sizeof 0Ch    offset 48h
    zCArray<zCEventManager*> roleEvMList; // sizeof 0Ch    offset 54h
    zCArray<zCVob*> roleVobList;          // sizeof 0Ch    offset 60h
    zCVob* mainRoleVob;                   // sizeof 04h    offset 6Ch
    zCCSProps* properties;                // sizeof 04h    offset 70h
    zCCSPlayer* ownerPlayer;              // sizeof 04h    offset 74h
    int actualBlockNum;                   // sizeof 04h    offset 78h
    zCCSBlockBase* actualBlock;           // sizeof 04h    offset 7Ch

    void zCCutscene_OnInit()                                  zCall( 0x0040E3E0 );
    zCCutscene()                                              zInit( zCCutscene_OnInit() );
    int IsMember( zCVob* )                                    zCall( 0x0040E7C0 );
    void SetRoleListForDebugging( zCArray<zCCSRole*>& )       zCall( 0x0040E7F0 );
    void SaveRolesVobs( zCBuffer& )                           zCall( 0x0040E9B0 );
    void RestoreRoleVobs( zCBuffer& )                         zCall( 0x0040EC40 );
    int CheckMainRole( zCVob* )                               zCall( 0x0040EEB0 );
    int CheckPlayState()                                      zCall( 0x0040FD00 );
    zCEventManager* SolveEventManager( int )                  zCall( 0x00414280 );
    int GetActualBlockNum()                                   zCall( 0x00415D30 );
    void ResumeAtBlock( int )                                 zCall( 0x004160F0 );
    void NewRole( zSTRING& )                                  zCall( 0x00416600 );
    void DeleteRole( int )                                    zCall( 0x004167B0 );
    void RegisterAdditionalVob( zCTree<zCVob>* )              zCall( 0x004168A0 );
    zCVob* FirstRoleUsed()                                    zCall( 0x00417840 );
    zTCSCheckResult GetLastCheckResult( zSTRING& )            zCall( 0x00417910 );
    int TryToCancel()                                         zCall( 0x00417C10 );
    zTCSBlockPosition GetFirstBlockPosition()                 zCall( 0x00417C40 );
    zCEventMessage* GetNextMessage( zTCSBlockPosition& )      zCall( 0x00417DD0 );
    zCCSBlockBase* GetNextBlock( zTCSBlockPosition& )         zCall( 0x00417E20 );
    void SerializeCutscene( zCCutscene*, zTCSBlockPosition& ) zCall( 0x00417E50 );
    void SerializeBlock( zCCSBlockBase*, zTCSBlockPosition& ) zCall( 0x00417FC0 );
    zCCSProps* GetProperties()                                zCall( 0x0041CF00 );
    static zCObject* _CreateNewInstance()                     zCall( 0x0040B170 );
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x0040E5C0 );
    virtual void Archive( zCArchiver& )                       zCall( 0x00417500 );
    virtual void Unarchive( zCArchiver& )                     zCall( 0x00417590 );
    virtual ~zCCutscene()                                     zCall( 0x0040E610 );
    virtual int NewBlock( int, int )                          zCall( 0x00416170 );
    virtual int AddMainRole( zCVob* )                         zCall( 0x00410670 );
    virtual void AddRoleOU( zCVob* )                          zCall( 0x0040FE40 );
    virtual void RemoveRole( zCVob* )                         zCall( 0x00410EC0 );
    virtual void SetOwnerPlayer( zCCSPlayer* )                zCall( 0x0040E780 );
    virtual void Reset()                                      zCall( 0x00413E30 );
    virtual void ClearCutscene()                              zCall( 0x00413F30 );
    virtual int StartPlaying()                                zCall( 0x004130C0 );
    virtual void Stop()                                       zCall( 0x004142C0 );
    virtual void StopRole( zCVob* )                           zCall( 0x00414120 );
    virtual void Interrupt()                                  zCall( 0x00415390 );
    virtual int ResumeActBlock()                              zCall( 0x00415D40 );
    virtual int PlaySub( float, float )                       zCall( 0x00416100 );
    virtual void NewCS( zCCSManager* )                        zCall( 0x00416350 );
    virtual int IsCutscene()                                  zCall( 0x0040E5D0 );
    virtual int IsFinished( zCArray<zCEventManager*> const& ) zCall( 0x0040D880 );
    virtual int IsFinished( zCEventManager* )                 zCall( 0x0040D830 );
    virtual int IsFinished()                                  zCall( 0x00416160 );
    virtual void PrintDebugInfo( zSTRING const& )             zCall( 0x00417900 );
    virtual int CheckRoles( int& )                            zCall( 0x00417870 );
    virtual int CSCheck( int& )                               zCall( 0x00410F40 );
    virtual zCVob* GetStage()                                 zCall( 0x0040FCF0 );
    virtual zCVob* LoadStage()                                zCall( 0x00416910 );
    virtual zCVob* CatchPlayer( zCVob* )                      zCall( 0x00416B30 );
    virtual void PrepareBlock()                               zCall( 0x0040FDC0 );

    // user API
    #include "zCCutscene.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCCS_CUTSCENE_H__VER2__