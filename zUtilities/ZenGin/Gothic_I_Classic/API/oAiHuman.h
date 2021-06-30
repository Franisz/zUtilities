// Supported with union (c) 2018 Union team

#ifndef __OAI_HUMAN_H__VER0__
#define __OAI_HUMAN_H__VER0__

#include "oAniCtrl.h"
#include "oSpell.h"
#include "oMusicZone.h"
#include "oRoutine.h"

namespace Gothic_I_Classic {

  class oCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAICamera )

    zCTimer localTimer;

    void oCAICamera_OnInit()                                            zCall( 0x00616500 );
    oCAICamera()                                                        zInit( oCAICamera_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00616F60 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00616640 );
    virtual ~oCAICamera()                                               zCall( 0x00616690 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x006166A0 );
    virtual int HasAIDetectedCollision()                                zCall( 0x00616650 );

    // user API
    #include "oCAICamera.inl"
  };

  class oCAIHuman : public oCAniCtrl_Human {
  public:
    zCLASS_DECLARATION( oCAIHuman )

    zCList<zCVob> ignoreVobList;
    zCAICamera* aiCam;
    int forcejump            : 1;
    int lookedAround         : 1;
    int sprintActive         : 1;
    int crawlActive          : 1;
    int showai               : 1;
    int startObserveIntruder : 1;
    int dontKnowAniPlayed    : 1;
    int spellReleased        : 1;
    int spellCastedLastFrame : 1;
    int eyeBlinkActivated    : 1;
    float createFlyDamage;

    void oCAIHuman_OnInit()                                             zCall( 0x0060F580 );
    int CheckActiveSpells()                                             zCall( 0x0046C2A0 );
    int MagicInvestSpell()                                              zCall( 0x0046C330 );
    int MagicCheckSpellStates( int )                                    zCall( 0x0046C940 );
    int MagicMode()                                                     zCall( 0x0046D260 );
    oCAIHuman()                                                         zInit( oCAIHuman_OnInit() );
    int DoSimpleAI()                                                    zCall( 0x0060F790 );
    int Pressed( int )                                                  zCall( 0x0060F920 );
    int Toggled( int )                                                  zCall( 0x0060F940 );
    void SetCamModeMob( oCMobInter* )                                   zCall( 0x0060F950 );
    void ChangeCamMode( zSTRING const& )                                zCall( 0x0060FB60 );
    void InitCamModes( int )                                            zCall( 0x0060FB70 );
    void SetCamMode( zSTRING const&, int )                              zCall( 0x0060FE40 );
    void WeaponChoose()                                                 zCall( 0x00610160 );
    int BowMode( int )                                                  zCall( 0x00610690 );
    oHEROSTATUS GetEnemyThreat()                                        zCall( 0x00610AF0 );
    void CheckFightCamera()                                             zCall( 0x00611010 );
    int FightMelee()                                                    zCall( 0x00611070 );
    int CheckMobInteraction()                                           zCall( 0x00611AD0 );
    int CheckItemInteraction()                                          zCall( 0x00611FB0 );
    int StandActions()                                                  zCall( 0x00612840 );
    int PC_CheckSpecialStates()                                         zCall( 0x00612EB0 );
    void PC_Diving()                                                    zCall( 0x00613600 );
    void PC_Turn( float, int )                                          zCall( 0x00613740 );
    int PC_SpecialMove( int )                                           zCall( 0x00613760 );
    int PC_ActionMove( int )                                            zCall( 0x00613A60 );
    int PC_WeaponMove( int )                                            zCall( 0x00613F90 );
    int PC_SlowMove( int )                                              zCall( 0x00614240 );
    int PC_Sneak( int )                                                 zCall( 0x00614670 );
    void PC_Turnings( int )                                             zCall( 0x00614800 );
    int PC_Strafe( int )                                                zCall( 0x00614A40 );
    void _WalkCycle()                                                   zCall( 0x00614BC0 );
    void ResetObserveSuspectCounter()                                   zCall( 0x00614E60 );
    void CreateObserveSuspect( int )                                    zCall( 0x00614E70 );
    void CreateFootStepSound( int )                                     zCall( 0x00614F00 );
    void ResetAssessUseMobCounter()                                     zCall( 0x00614FD0 );
    void CreateAssessUseMob()                                           zCall( 0x00614FE0 );
    void SetCrawlMode( int )                                            zCall( 0x00615070 );
    void SetSprintMode( int )                                           zCall( 0x006152F0 );
    int MoveCamera()                                                    zCall( 0x00615500 );
    void CamMessages()                                                  zCall( 0x006156E0 );
    void CheckFocusVob()                                                zCall( 0x00615730 );
    void Moving()                                                       zCall( 0x006158F0 );
    void DoMonsterSpecial()                                             zCall( 0x00616050 );
    void SetShowAI( int )                                               zCall( 0x00616060 );
    int GetShowAI()                                                     zCall( 0x00616080 );
    void StartFlyDamage( float, zVEC3& )                                zCall( 0x00616140 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00616CF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0060F660 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006164C0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006164E0 );
    virtual ~oCAIHuman()                                                zCall( 0x0060F6A0 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00615A50 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x00616090 );
    virtual void Init( oCNpc* )                                         zCall( 0x0060F770 );
    virtual void AddIgnoreCD( zCVob* )                                  zCall( 0x006160D0 );
    virtual void SubIgnoreCD( zCVob* )                                  zCall( 0x006160E0 );


    // static properties
    static zSTRING& Cam_Normal;
    static zSTRING& Cam_Run;
    static zSTRING& Cam_Fight;

    // user API
    #include "oCAIHuman.inl"
  };

  class oCAIHuman_Stand : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAIHuman_Stand )

    oCAIHuman_Stand() {}
    void oCAIHuman_Stand_OnInit( zCVob* )                               zCall( 0x006168D0 );
    oCAIHuman_Stand( zCVob* a0 )                                        zInit( oCAIHuman_Stand_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006172E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006169F0 );
    virtual ~oCAIHuman_Stand()                                          zCall( 0x00616A30 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00616A40 );

    // user API
    #include "oCAIHuman_Stand.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OAI_HUMAN_H__VER0__