// Supported with union (c) 2018 Union team

#ifndef __OAI_HUMAN_H__VER1__
#define __OAI_HUMAN_H__VER1__

#include "oAniCtrl.h"
#include "oSpell.h"
#include "oMusicZone.h"
#include "oRoutine.h"

namespace Gothic_I_Addon {

  class oCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAICamera )

    zCTimer localTimer;

    void oCAICamera_OnInit()                                            zCall( 0x00639450 );
    oCAICamera()                                                        zInit( oCAICamera_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00639F50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00639590 );
    virtual ~oCAICamera()                                               zCall( 0x006395E0 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x006395F0 );
    virtual int HasAIDetectedCollision()                                zCall( 0x006395A0 );

    // user API
    #include "oCAICamera.inl"
  };

  class oCAIHuman : public oCAniCtrl_Human {
  public:
    zCLASS_DECLARATION( oCAIHuman )

    zCList<zCVob> ignoreVobList;
    zCAICamera* aiCam;
    int forcejump              : 1;
    int lookedAround           : 1;
    int sprintActive           : 1;
    int crawlActive            : 1;
    int showai                 : 1;
    int startObserveIntruder   : 1;
    int dontKnowAniPlayed      : 1;
    int spellReleased          : 1;
    int spellCastedLastFrame   : 1;
    int eyeBlinkActivated      : 1;
    int hasStartedConversation : 1;
    float createFlyDamage;

    void oCAIHuman_OnInit()                                             zCall( 0x00631FD0 );
    int CheckActiveSpells()                                             zCall( 0x00474650 );
    int MagicInvestSpell()                                              zCall( 0x004746E0 );
    int MagicCheckSpellStates( int )                                    zCall( 0x00474D60 );
    int MagicMode()                                                     zCall( 0x00475710 );
    oCAIHuman()                                                         zInit( oCAIHuman_OnInit() );
    int DoSimpleAI()                                                    zCall( 0x00632210 );
    int Pressed( int )                                                  zCall( 0x006323C0 );
    int Toggled( int )                                                  zCall( 0x006323E0 );
    void SetCamModeMob( oCMobInter* )                                   zCall( 0x00632400 );
    void ChangeCamMode( zSTRING const& )                                zCall( 0x006326C0 );
    void InitCamModes( int )                                            zCall( 0x006326D0 );
    void SetCamMode( zSTRING const&, int )                              zCall( 0x00632AD0 );
    void WeaponChoose()                                                 zCall( 0x00632E20 );
    int BowMode( int )                                                  zCall( 0x00633370 );
    oHEROSTATUS GetEnemyThreat()                                        zCall( 0x00633800 );
    void CheckFightCamera()                                             zCall( 0x00633D70 );
    int FightMelee()                                                    zCall( 0x00633DD0 );
    int CheckMobInteraction()                                           zCall( 0x00634C90 );
    int CheckItemInteraction()                                          zCall( 0x00634FE0 );
    int StandActions()                                                  zCall( 0x006359A0 );
    int PC_DirectActions()                                              zCall( 0x006360C0 );
    int PC_CheckSpecialStates()                                         zCall( 0x006361B0 );
    void PC_Diving()                                                    zCall( 0x006369E0 );
    void PC_Turn( float, int )                                          zCall( 0x00636B20 );
    int PC_SpecialMove( int )                                           zCall( 0x00636B40 );
    int PC_ActionMove( int )                                            zCall( 0x00636C90 );
    int PC_WeaponMove( int )                                            zCall( 0x00636DE0 );
    int PC_SlowMove( int )                                              zCall( 0x00637090 );
    int PC_Sneak( int )                                                 zCall( 0x006374D0 );
    void PC_Turnings( int )                                             zCall( 0x00637660 );
    int PC_Strafe( int )                                                zCall( 0x00637850 );
    void _WalkCycle()                                                   zCall( 0x006379E0 );
    void ResetObserveSuspectCounter()                                   zCall( 0x00637CE0 );
    void CreateObserveSuspect( int )                                    zCall( 0x00637CF0 );
    void CreateFootStepSound( int )                                     zCall( 0x00637D80 );
    void ResetAssessUseMobCounter()                                     zCall( 0x00637E60 );
    void CreateAssessUseMob()                                           zCall( 0x00637E70 );
    void SetCrawlMode( int )                                            zCall( 0x00637F00 );
    void SetSprintMode( int )                                           zCall( 0x00638190 );
    int MoveCamera()                                                    zCall( 0x006383D0 );
    void CamMessages()                                                  zCall( 0x006385C0 );
    void CheckFocusVob()                                                zCall( 0x00638610 );
    void Moving()                                                       zCall( 0x006387D0 );
    void DoMonsterSpecial()                                             zCall( 0x00638F40 );
    void SetShowAI( int )                                               zCall( 0x00638F50 );
    int GetShowAI()                                                     zCall( 0x00638F70 );
    void StartFlyDamage( float, zVEC3& )                                zCall( 0x00639050 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00639CC0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006320E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00639410 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00639430 );
    virtual ~oCAIHuman()                                                zCall( 0x00632120 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00638930 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x00638F80 );
    virtual void Init( oCNpc* )                                         zCall( 0x006321F0 );
    virtual void AddIgnoreCD( zCVob* )                                  zCall( 0x00638FC0 );
    virtual void SubIgnoreCD( zCVob* )                                  zCall( 0x00638FE0 );


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
    void oCAIHuman_Stand_OnInit( zCVob* )                               zCall( 0x00639820 );
    oCAIHuman_Stand( zCVob* a0 )                                        zInit( oCAIHuman_Stand_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x0063A2E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00639950 );
    virtual ~oCAIHuman_Stand()                                          zCall( 0x00639990 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x006399A0 );

    // user API
    #include "oCAIHuman_Stand.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OAI_HUMAN_H__VER1__