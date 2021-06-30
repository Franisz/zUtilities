// Supported with union (c) 2018 Union team

#ifndef __OAI_HUMAN_H__VER2__
#define __OAI_HUMAN_H__VER2__

#include "oAniCtrl.h"
#include "oSpell.h"
#include "oRoutine.h"
#include "oMusicZone.h"

namespace Gothic_II_Classic {

  class oCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAICamera )

    zCTimer localTimer;

    void oCAICamera_OnInit()                 zCall( 0x00641530 );
    oCAICamera()                             zInit( oCAICamera_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00641F90 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00641670 );
    virtual ~oCAICamera()                    zCall( 0x006416C0 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x006416D0 );
    virtual int HasAIDetectedCollision()     zCall( 0x00641680 );

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
    int thirdPersonFallback  : 1;
    float createFlyDamage;

    void oCAIHuman_OnInit()                  zCall( 0x00638AD0 );
    int CheckActiveSpells()                  zCall( 0x00470FB0 );
    int MagicInvestSpell()                   zCall( 0x00471010 );
    int MagicCheckSpellStates( int )         zCall( 0x00471610 );
    int MagicMode()                          zCall( 0x00471EB0 );
    oCAIHuman()                              zInit( oCAIHuman_OnInit() );
    int DoSimpleAI()                         zCall( 0x00638CE0 );
    int Pressed( int )                       zCall( 0x00638E70 );
    int Toggled( int )                       zCall( 0x00638E90 );
    void SetCamModeMob( oCMobInter* )        zCall( 0x00638EA0 );
    void ChangeCamMode( zSTRING const& )     zCall( 0x006390B0 );
    void InitCamModes( int )                 zCall( 0x006390C0 );
    void SetCamMode( zSTRING const&, int )   zCall( 0x00639390 );
    void WeaponChoose()                      zCall( 0x006393C0 );
    int BowMode( int )                       zCall( 0x00639850 );
    oHEROSTATUS GetEnemyThreat()             zCall( 0x0063A0C0 );
    void CheckFightCamera()                  zCall( 0x0063A5D0 );
    int FightMelee()                         zCall( 0x0063A630 );
    int CheckMobInteraction()                zCall( 0x0063BA40 );
    int CheckItemInteraction()               zCall( 0x0063BE40 );
    int StandActions()                       zCall( 0x0063C630 );
    int PC_CheckSpecialStates()              zCall( 0x0063CCC0 );
    void PC_Diving()                         zCall( 0x0063D410 );
    void PC_Turn( float, int )               zCall( 0x0063D580 );
    int PC_SpecialMove( int )                zCall( 0x0063D5A0 );
    int PC_ActionMove( int )                 zCall( 0x0063D710 );
    int PC_WeaponMove( int )                 zCall( 0x0063D890 );
    int PC_SlowMove( int )                   zCall( 0x0063DB00 );
    int PC_Sneak( int )                      zCall( 0x0063DF40 );
    void PC_Turnings( int )                  zCall( 0x0063E0F0 );
    int PC_Strafe( int )                     zCall( 0x0063E430 );
    void _WalkCycle()                        zCall( 0x0063E5D0 );
    void ResetObserveSuspectCounter()        zCall( 0x0063E910 );
    void CreateObserveSuspect( int )         zCall( 0x0063E920 );
    void CreateFootStepSound( int )          zCall( 0x0063E9B0 );
    void ResetAssessUseMobCounter()          zCall( 0x0063EA80 );
    void CreateAssessUseMob()                zCall( 0x0063EA90 );
    void SetCrawlMode( int )                 zCall( 0x0063EB20 );
    void SetSprintMode( int )                zCall( 0x0063EDA0 );
    int MoveCamera()                         zCall( 0x0063EFB0 );
    void CamMessages()                       zCall( 0x0063EFC0 );
    void CheckFocusVob( int )                zCall( 0x0063EFD0 );
    void Moving()                            zCall( 0x0063F1E0 );
    void ChangeCamModeBySituation()          zCall( 0x00640590 );
    void DoMonsterSpecial()                  zCall( 0x00641080 );
    void SetShowAI( int )                    zCall( 0x00641090 );
    int GetShowAI()                          zCall( 0x006410B0 );
    void StartFlyDamage( float, zVEC3& )     zCall( 0x00641170 );
    static zCObject* _CreateNewInstance()    zCall( 0x00641D30 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00638BB0 );
    virtual void Archive( zCArchiver& )      zCall( 0x006414F0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00641510 );
    virtual ~oCAIHuman()                     zCall( 0x00638BF0 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x0063F2E0 );
    virtual int CanThisCollideWith( zCVob* ) zCall( 0x006410C0 );
    virtual void Init( oCNpc* )              zCall( 0x00638CC0 );
    virtual void AddIgnoreCD( zCVob* )       zCall( 0x00641100 );
    virtual void SubIgnoreCD( zCVob* )       zCall( 0x00641110 );
    virtual void DoHackSpecials()            zCall( 0x0063FBC0 );

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
    void oCAIHuman_Stand_OnInit( zCVob* )    zCall( 0x00641910 );
    oCAIHuman_Stand( zCVob* a0 )             zInit( oCAIHuman_Stand_OnInit( a0 ));
    static zCObject* _CreateNewInstance()    zCall( 0x006422D0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00641A30 );
    virtual ~oCAIHuman_Stand()               zCall( 0x00641A70 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x00641A80 );

    // user API
    #include "oCAIHuman_Stand.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OAI_HUMAN_H__VER2__