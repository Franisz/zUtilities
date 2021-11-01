// Supported with union (c) 2018-2021 Union team

#ifndef __OAI_HUMAN_H__VER3__
#define __OAI_HUMAN_H__VER3__

#include "z3d.h"
#include "zAi.h"
#include "zCollisionDetector.h"
#include "oAniCtrl.h"
#include "oSpell.h"
#include "oRoutine.h"

namespace Gothic_II_Addon {

  // sizeof 4Ch
  class oCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAICamera )

    zCTimer localTimer; // sizeof 28h    offset 24h

    void oCAICamera_OnInit()                 zCall( 0x0069DD00 );
    oCAICamera()                             zInit( oCAICamera_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x0069E760 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0069DE40 );
    virtual ~oCAICamera()                    zCall( 0x0069DE90 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x0069DEA0 );
    virtual int HasAIDetectedCollision()     zCall( 0x0069DE50 );

    // user API
    #include "oCAICamera.inl"
  };

  // sizeof 120Ch
  class oCAIHuman : public oCAniCtrl_Human {
  public:
    zCLASS_DECLARATION( oCAIHuman )

    zCList<zCVob> ignoreVobList;  // sizeof 08h    offset 11F8h
    zCAICamera* aiCam;            // sizeof 04h    offset 1200h
    int forcejump            : 1; // sizeof 01h    offset bit
    int lookedAround         : 1; // sizeof 01h    offset bit
    int sprintActive         : 1; // sizeof 01h    offset bit
    int crawlActive          : 1; // sizeof 01h    offset bit
    int showai               : 1; // sizeof 01h    offset bit
    int startObserveIntruder : 1; // sizeof 01h    offset bit
    int dontKnowAniPlayed    : 1; // sizeof 01h    offset bit
    int spellReleased        : 1; // sizeof 01h    offset bit
    int spellCastedLastFrame : 1; // sizeof 01h    offset bit
    int eyeBlinkActivated    : 1; // sizeof 01h    offset bit
    int thirdPersonFallback  : 1; // sizeof 01h    offset bit
    float createFlyDamage;        // sizeof 04h    offset 1208h

    void oCAIHuman_OnInit()                  zCall( 0x006951A0 );
    int CheckActiveSpells()                  zCall( 0x00472100 );
    int MagicInvestSpell()                   zCall( 0x00472160 );
    int MagicCheckSpellStates( int )         zCall( 0x00472770 );
    int MagicMode()                          zCall( 0x00472FD0 );
    oCAIHuman()                              zInit( oCAIHuman_OnInit() );
    int DoSimpleAI()                         zCall( 0x006953B0 );
    int Pressed( int )                       zCall( 0x00695540 );
    int Toggled( int )                       zCall( 0x00695560 );
    void SetCamModeMob( oCMobInter* )        zCall( 0x00695570 );
    void ChangeCamMode( zSTRING const& )     zCall( 0x00695780 );
    void InitCamModes( int )                 zCall( 0x00695790 );
    void SetCamMode( zSTRING const&, int )   zCall( 0x00695A60 );
    void WeaponChoose()                      zCall( 0x00695A90 );
    int BowMode( int )                       zCall( 0x00695F00 );
    oHEROSTATUS GetEnemyThreat()             zCall( 0x00696950 );
    void CheckFightCamera()                  zCall( 0x00696E60 );
    int FightMelee()                         zCall( 0x00696EC0 );
    int CheckMobInteraction()                zCall( 0x006982B0 );
    int CheckItemInteraction()               zCall( 0x006986B0 );
    int StandActions()                       zCall( 0x00698EA0 );
    int PC_CheckSpecialStates()              zCall( 0x00699510 );
    void PC_Diving()                         zCall( 0x00699C60 );
    void PC_Turn( float, int )               zCall( 0x00699DD0 );
    int PC_SpecialMove( int )                zCall( 0x00699DF0 );
    int PC_ActionMove( int )                 zCall( 0x00699F60 );
    int PC_WeaponMove( int )                 zCall( 0x0069A0E0 );
    int PC_SlowMove( int )                   zCall( 0x0069A350 );
    int PC_Sneak( int )                      zCall( 0x0069A790 );
    void PC_Turnings( int )                  zCall( 0x0069A940 );
    int PC_Strafe( int )                     zCall( 0x0069AC80 );
    void _WalkCycle()                        zCall( 0x0069AE20 );
    void ResetObserveSuspectCounter()        zCall( 0x0069B0E0 );
    void CreateObserveSuspect( int )         zCall( 0x0069B0F0 );
    void CreateFootStepSound( int )          zCall( 0x0069B180 );
    void ResetAssessUseMobCounter()          zCall( 0x0069B250 );
    void CreateAssessUseMob()                zCall( 0x0069B260 );
    void SetCrawlMode( int )                 zCall( 0x0069B2F0 );
    void SetSprintMode( int )                zCall( 0x0069B570 );
    int MoveCamera()                         zCall( 0x0069B780 );
    void CamMessages()                       zCall( 0x0069B790 );
    void CheckFocusVob( int )                zCall( 0x0069B7A0 );
    void Moving()                            zCall( 0x0069B9B0 );
    void ChangeCamModeBySituation()          zCall( 0x0069CD60 );
    void DoMonsterSpecial()                  zCall( 0x0069D850 );
    void SetShowAI( int )                    zCall( 0x0069D860 );
    int GetShowAI()                          zCall( 0x0069D880 );
    void StartFlyDamage( float, zVEC3& )     zCall( 0x0069D940 );
    static zCObject* _CreateNewInstance()    zCall( 0x0069E500 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00695280 );
    virtual void Archive( zCArchiver& )      zCall( 0x0069DCC0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0069DCE0 );
    virtual ~oCAIHuman()                     zCall( 0x006952C0 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x0069BAB0 );
    virtual int CanThisCollideWith( zCVob* ) zCall( 0x0069D890 );
    virtual void Init( oCNpc* )              zCall( 0x00695390 );
    virtual void AddIgnoreCD( zCVob* )       zCall( 0x0069D8D0 );
    virtual void SubIgnoreCD( zCVob* )       zCall( 0x0069D8E0 );
    virtual void DoHackSpecials()            zCall( 0x0069C390 );

    // static properties
    static zSTRING& Cam_Normal;
    static zSTRING& Cam_Run;
    static zSTRING& Cam_Fight;

    // user API
    #include "oCAIHuman.inl"
  };

  // sizeof 24h
  class oCAIHuman_Stand : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAIHuman_Stand )

    oCAIHuman_Stand() {}
    void oCAIHuman_Stand_OnInit( zCVob* )    zCall( 0x0069E0E0 );
    oCAIHuman_Stand( zCVob* a0 )             zInit( oCAIHuman_Stand_OnInit( a0 ));
    static zCObject* _CreateNewInstance()    zCall( 0x0069EAA0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0069E200 );
    virtual ~oCAIHuman_Stand()               zCall( 0x0069E240 );
    virtual void DoAI( zCVob*, int& )        zCall( 0x0069E250 );

    // user API
    #include "oCAIHuman_Stand.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OAI_HUMAN_H__VER3__