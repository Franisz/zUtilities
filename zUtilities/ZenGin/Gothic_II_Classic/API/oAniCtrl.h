// Supported with union (c) 2018 Union team

#ifndef __OANI_CTRL_H__VER2__
#define __OANI_CTRL_H__VER2__

#include "zModel.h"
#include "zAiPlayer.h"
#include "zArchiver.h"

namespace Gothic_II_Classic {
  const int WMODE_NONE          = 1;
  const int WMODE_CHOOSE        = 2;
  const int WMODE_STAND         = 3;
  const int ANI_NUM             = 10;
  const int ANI_HITLIMB_MAX     = 4;
  const int ANI_TURN_LAYER      = 20;
  const int ANI_MAX_HIT         = 10;
  const float ANI_TIME_INFINITE = -1000000.0f;

  enum {
    ANI_WALKMODE_RUN,
    ANI_WALKMODE_WALK,
    ANI_WALKMODE_SNEAK,
    ANI_WALKMODE_WATER,
    ANI_WALKMODE_SWIM,
    ANI_WALKMODE_DIVE
  };

  enum {
    ANI_ACTION_STAND,
    ANI_ACTION_WALK,
    ANI_ACTION_SNEAK,
    ANI_ACTION_RUN,
    ANI_ACTION_WATERWALK,
    ANI_ACTION_SWIM,
    ANI_ACTION_DIVE,
    ANI_ACTION_CHOOSEWEAPON
  };

  enum {
    ANI_HITTYPE_NONE,
    ANI_HITTYPE_FORWARD
  };

  class oCAniCtrl_Human : public zCAIPlayer {
  public:
    zCLASS_DECLARATION( oCAniCtrl_Human )

    struct oTComboInfo {
    public:
      int hitAni;
      int hitOptFrame;
      int hitEndFrame;
      int comboStartFrame;
      int comboEndFrame;
      int comboDir;

      // user API
      #include "oCAniCtrl_Human_oTComboInfo.inl"
    };

    float angle_slide1;
    float angle_slide2;
    float angle_heading;
    float angle_horiz;
    float angle_ground;
    oCNpc* npc;
    zCVob* targetVob;
    zCVob* stopTurnVob;
    int stopTurnVobSign;
    zCModelNodeInst* hitlimb[ANI_HITLIMB_MAX];
    int actionMode;
    int wmode;
    int wmode_last;
    int wmode_selected;
    int changeweapon;
    int walkmode;
    int nextwalkmode;
    int lastRunWalkSneak;
    int always_walk;
    int do_jump;
    int defaultSurfaceAlign;
    float autoRollDirection;
    float lookTargetx;
    float lookTargety;
    int distance;
    zVEC3 hitpos;
    zSTRING limbname;
    float paradeBeginFrame;
    float paradeEndFrame;
    group {
      unsigned char canEnableNextCombo : 1;
      unsigned char endCombo           : 1;
      unsigned char comboCanHit        : 1;
      unsigned char hitPosUsed         : 1;
      unsigned char hitGraphical       : 1;
      unsigned char canDoCollisionFX   : 1;
    };
    int comboNr;
    int comboMax;
    float lastHitAniFrame;
    int hitAniID;
    zCVob* hitTarget;
    oTComboInfo comboInfo[ANI_MAX_HIT];
    float anioffset_lastper;
    float anioffset_thisper;
    float anioffset;
    int anioffset_ani;
    int s_dead1;
    int s_dead2;
    int s_hang;
    int t_hang_2_stand;
    int s_run[ANI_NUM];
    int t_run_2_runl[ANI_NUM];
    int t_runl_2_run[ANI_NUM];
    int s_runl[ANI_NUM];
    int t_runl_2_runr[ANI_NUM];
    int t_runr_2_runl[ANI_NUM];
    int s_runr[ANI_NUM];
    int t_runr_2_run[ANI_NUM];
    int t_runturnl[ANI_NUM];
    int t_runturnr[ANI_NUM];
    int t_runstrafel[ANI_NUM];
    int t_runstrafer[ANI_NUM];
    int t_run_2_runbl[ANI_NUM];
    int t_runbl_2_run[ANI_NUM];
    int s_runbl[ANI_NUM];
    int t_runbl_2_runbr[ANI_NUM];
    int t_runbr_2_runbl[ANI_NUM];
    int s_runbr[ANI_NUM];
    int t_runbr_2_run[ANI_NUM];
    int t_jumpb[ANI_NUM];
    int t_run_2_walk[ANI_NUM];
    int t_walk_2_run[ANI_NUM];
    int t_run_2_sneak[ANI_NUM];
    int t_sneak_2_run[ANI_NUM];
    int s_walk[ANI_NUM];
    int t_walk_2_walkl[ANI_NUM];
    int t_walkl_2_walk[ANI_NUM];
    int s_walkl[ANI_NUM];
    int t_walkl_2_walkr[ANI_NUM];
    int t_walkr_2_walkl[ANI_NUM];
    int s_walkr[ANI_NUM];
    int t_walkr_2_walk[ANI_NUM];
    int t_walkturnl[ANI_NUM];
    int t_walkturnr[ANI_NUM];
    int t_walkstrafel[ANI_NUM];
    int t_walkstrafer[ANI_NUM];
    int t_walk_2_walkbl[ANI_NUM];
    int t_walkbl_2_walk[ANI_NUM];
    int s_walkbl[ANI_NUM];
    int t_walkbl_2_walkbr[ANI_NUM];
    int t_walkbr_2_walkbl[ANI_NUM];
    int s_walkbr[ANI_NUM];
    int t_walkbr_2_walk[ANI_NUM];
    int t_runl_2_jump[ANI_NUM];
    int t_runr_2_jump[ANI_NUM];
    int t_jump_2_runl[ANI_NUM];
    int t_stand_2_jumpuplow;
    int s_jumpuplow;
    int t_jumpuplow_2_stand;
    int t_stand_2_jumpupmid;
    int s_jumpupmid;
    int t_jumpupmid_2_stand;
    int s_sneak[ANI_NUM];
    int t_sneak_2_sneakl[ANI_NUM];
    int t_sneakl_2_sneak[ANI_NUM];
    int s_sneakl[ANI_NUM];
    int t_sneakl_2_sneakr[ANI_NUM];
    int t_sneakr_2_sneakl[ANI_NUM];
    int s_sneakr[ANI_NUM];
    int t_sneakr_2_sneak[ANI_NUM];
    int t_sneakturnl[ANI_NUM];
    int t_sneakturnr[ANI_NUM];
    int t_sneakstrafel[ANI_NUM];
    int t_sneakstrafer[ANI_NUM];
    int t_sneak_2_sneakbl[ANI_NUM];
    int t_sneakbl_2_sneak[ANI_NUM];
    int s_sneakbl[ANI_NUM];
    int t_sneakbl_2_sneakbr[ANI_NUM];
    int t_sneakbr_2_sneakbl[ANI_NUM];
    int s_sneakbr[ANI_NUM];
    int t_sneakbr_2_sneak[ANI_NUM];
    int t_walkl_2_aim[ANI_NUM];
    int t_walkr_2_aim[ANI_NUM];
    int t_walk_2_aim[ANI_NUM];
    int s_aim[ANI_NUM];
    int t_aim_2_walk[ANI_NUM];
    int t_hitl[ANI_NUM];
    int t_hitr[ANI_NUM];
    int t_hitback[ANI_NUM];
    int t_hitf[ANI_NUM];
    int s_hitf[ANI_NUM];
    int t_aim_2_defend[ANI_NUM];
    int s_defend[ANI_NUM];
    int t_defend_2_aim[ANI_NUM];
    int t_paradeL[ANI_NUM];
    int t_paradeM[ANI_NUM];
    int t_paradeS[ANI_NUM];
    int t_hitfrun[ANI_NUM];
    int t_stumble;
    int t_stumbleb;
    int t_fallen_2_stand;
    int t_fallenb_2_stand;
    int t_walk_2_walkwl;
    int t_walkwl_2_walk;
    int s_walkwl;
    int t_walkwl_2_walkwr;
    int t_walkwr_2_walkwl;
    int s_walkwr;
    int t_walkwr_2_walk;
    int t_walk_2_walkwbl;
    int t_walkwbl_2_walk;
    int s_walkwbl;
    int t_walkwbl_2_walkwbr;
    int t_walkwbr_2_walkwbl;
    int s_walkwbr;
    int t_walkwbr_2_walk;
    int _s_walk;
    int _t_walk_2_walkl;
    int _t_walkl_2_walk;
    int _s_walkl;
    int _t_walkl_2_walkr;
    int _t_walkr_2_walkl;
    int _s_walkr;
    int _t_walkr_2_walk;
    int _t_turnl;
    int _t_turnr;
    int _t_strafel;
    int _t_strafer;
    int _t_walk_2_walkbl;
    int _t_walkbl_2_walk;
    int _s_walkbl;
    int _t_walkbl_2_walkbr;
    int _t_walkbr_2_walkbl;
    int _s_walkbr;
    int _t_walkbr_2_walk;
    int s_jumpstand;
    int t_stand_2_jumpstand;
    int t_jumpstand_2_stand;
    int _t_jumpb;
    int _t_stand_2_jump;
    int _s_jump;
    int t_jump_2_stand;
    int _t_stand_2_jumpup;
    int _s_jumpup;
    int _t_jumpup_2_falldn;
    int _t_jump_2_falldn;
    int t_walkwl_2_swimf;
    int s_swimf;
    int t_swimf_2_walkwl;
    int t_walkwbl_2_swimb;
    int s_swimb;
    int t_swimb_2_walkwbl;
    int t_swimf_2_swim;
    int s_swim;
    int t_swim_2_swimf;
    int t_swim_2_swimb;
    int t_swimb_2_swim;
    int t_warn;
    int t_swim_2_dive;
    int s_dive;
    int t_divef_2_swim;
    int t_dive_2_divef;
    int s_divef;
    int t_divef_2_dive;
    int t_dive_2_drowned;
    int s_drowned;
    int t_swimturnl;
    int t_swimturnr;
    int t_diveturnl;
    int t_diveturnr;
    int _t_walkl_2_aim;
    int _t_walkr_2_aim;
    int _t_walk_2_aim;
    int _s_aim;
    int _t_aim_2_walk;
    int _t_hitl;
    int _t_hitr;
    int _t_hitback;
    int _t_hitf;
    int _t_hitfstep;
    int _s_hitf;
    int _t_aim_2_defend;
    int _s_defend;
    int _t_defend_2_aim;
    int _t_paradeL;
    int _t_paradeM;
    int _t_paradeS;
    int _t_hitfrun;
    int t_stand_2_iaim;
    int s_iaim;
    int t_iaim_2_stand;
    int t_iaim_2_idrop;
    int s_idrop;
    int t_idrop_2_stand;
    int t_iaim_2_ithrow;
    int s_ithrow;
    int t_ithrow_2_stand;
    int t_stand_2_iget;
    int s_iget;
    int t_iget_2_stand;
    int s_oget;
    int _t_stand_2_torch;
    int _s_torch;
    int _t_torch_2_stand;
    int hitani;
    int help;
    int help1;
    int help2;
    int s_fall;
    int s_fallb;
    int s_fallen;
    int s_fallenb;
    int s_falldn;
    int _t_runl_2_jump;
    int _t_runr_2_jump;
    int _t_jump_2_runl;
    int s_look;
    int s_point;
    int dummy1;
    int dummy2;
    int dummy3;
    int dummy4;
    int s_weapon[ANI_NUM];
    int togglewalk;
    int t_stand_2_cast;
    int s_cast;
    int t_cast_2_shoot;
    int t_cast_2_stand;
    int s_shoot;
    int t_shoot_2_stand;
    int dummyLastVar;

    void oCAniCtrl_Human_OnInit()                                    zCall( 0x00647270 );
    oCAniCtrl_Human()                                                zInit( oCAniCtrl_Human_OnInit() );
    int StartAni( int, int )                                         zCall( 0x00647540 );
    void SetNextAni( int, int )                                      zCall( 0x00647720 );
    void InitAnimations()                                            zCall( 0x00647790 );
    void SearchStandAni( int )                                       zCall( 0x006484A0 );
    void Reset()                                                     zCall( 0x00648800 );
    void InitAngleValuesForConsole()                                 zCall( 0x00648840 );
    void SetScriptValues()                                           zCall( 0x00648890 );
    void SetInterruptFollowAni( int )                                zCall( 0x006491C0 );
    void InitAllAnis()                                               zCall( 0x00649370 );
    void SetWalkMode( int )                                          zCall( 0x0064CFA0 );
    void InitFightAnis( int )                                        zCall( 0x0064D830 );
    void SetFightAnis( int )                                         zCall( 0x0064E1C0 );
    void StartAniWithOffset( int, float )                            zCall( 0x0064E2E0 );
    void DoAniWithOffset()                                           zCall( 0x0064E2F0 );
    void CorrectFightPosition()                                      zCall( 0x0064E300 );
    zSTRING GetWalkModeString()                                      zCall( 0x0064E5C0 );
    void CorrectAniStates()                                          zCall( 0x0064E720 );
    int CheckWaterLevel()                                            zCall( 0x0064E8B0 );
    void SetAlwaysWalk( int )                                        zCall( 0x0064F530 );
    int IsAlwaysWalk()                                               zCall( 0x0064F700 );
    int CanToggleWalkModeTo( int )                                   zCall( 0x0064F730 );
    int CanToggleWalkMode()                                          zCall( 0x00650390 );
    void ToggleWalkMode( int )                                       zCall( 0x00650C80 );
    int IsDead()                                                     zCall( 0x00650CC0 );
    int IsFallen()                                                   zCall( 0x006513B0 );
    int IsAiming()                                                   zCall( 0x006514C0 );
    int IsStateAniActive( int )                                      zCall( 0x00651590 );
    int IsStateAniActive( zCModelAni* )                              zCall( 0x00651610 );
    int IsStanding()                                                 zCall( 0x00651660 );
    int IsJumpStanding()                                             zCall( 0x00651800 );
    int IsWalking()                                                  zCall( 0x00651860 );
    int IsRunning()                                                  zCall( 0x00651980 );
    int IsWalkingBackward()                                          zCall( 0x00651B90 );
    void StopTurnAnis()                                              zCall( 0x00651CB0 );
    float Turn( float, int )                                         zCall( 0x00651CC0 );
    void DoAutoRoll()                                                zCall( 0x006521C0 );
    void TurnDegrees( float, int )                                   zCall( 0x00652290 );
    int WallInFront( float )                                         zCall( 0x00652370 );
    int IsDefending()                                                zCall( 0x00652900 );
    void GetFightLimbs()                                             zCall( 0x00652960 );
    void DoSparks( zVEC3&, zSTRING const& )                          zCall( 0x006533D0 );
    zCModelAniActive* GetLayerAni( int )                             zCall( 0x00653500 );
    int CheckLayerAni( int, zSTRING const& )                         zCall( 0x00653530 );
    int CheckLimbHit( zSTRING const&, zCList<zCModelNodeInst>& )     zCall( 0x00653570 );
    void ShowWeaponTrail()                                           zCall( 0x006535F0 );
    void StartHitCombo( int, zCVob* )                                zCall( 0x00653810 );
    void SetComboHitTarget( zCVob const* )                           zCall( 0x00653870 );
    void StartHitGraphical( int, zCVob* )                            zCall( 0x00653880 );
    int GetStopTurnVobSign()                                         zCall( 0x00653950 );
    int HitCombo( int )                                              zCall( 0x006539B0 );
    zCVob* CheckHitTarget()                                          zCall( 0x00653C80 );
    void CreateHit( zCVob* )                                         zCall( 0x00653EF0 );
    int CheckMeleeWeaponHitsLevel( oCItem* )                         zCall( 0x00654340 );
    void HitInterrupt()                                              zCall( 0x00654810 );
    int HitGraphical()                                               zCall( 0x00654850 );
    int IsInPreHit()                                                 zCall( 0x006549C0 );
    int IsInPostHit()                                                zCall( 0x00654A10 );
    int IsInCombo()                                                  zCall( 0x00654AA0 );
    void FirstPersonDrawWeapon()                                     zCall( 0x00654AF0 );
    zSTRING GetHitDirection()                                        zCall( 0x00654B00 );
    zCModelAniActive* IsParadeRunning()                              zCall( 0x00654BC0 );
    int CanParade( oCNpc* )                                          zCall( 0x00654C20 );
    void StartParadeEffects( oCNpc* )                                zCall( 0x00654D60 );
    void StrafeLeft()                                                zCall( 0x006551B0 );
    void StrafeRight()                                               zCall( 0x006551F0 );
    int GetFootPos()                                                 zCall( 0x00655230 );
    void PC_GoForward()                                              zCall( 0x006553E0 );
    void PC_GoBackward()                                             zCall( 0x00655430 );
    void PC_JumpForward()                                            zCall( 0x00655470 );
    int CanJump( int )                                               zCall( 0x00655650 );
    int CanJumpLedge()                                               zCall( 0x006556C0 );
    int JumpForward()                                                zCall( 0x00655850 );
    int Swim_CanClimbLedge()                                         zCall( 0x00655A70 );
    void Swim_ClimbLedge()                                           zCall( 0x00655AB0 );
    int CanWalkOnPoly( zVEC3 const& )                                zCall( 0x00655C10 );
    int DrawWeapon1( int, int, int )                                 zCall( 0x00655C80 );
    int ChooseNextWeapon2( int )                                     zCall( 0x00655F70 );
    int DrawWeapon2()                                                zCall( 0x00656360 );
    int RemoveWeapon1()                                              zCall( 0x006566B0 );
    int RemoveWeapon2()                                              zCall( 0x00656A20 );
    void StartUp( zCVob* )                                           zCall( 0x00656CD0 );
    void LerpFeetToTarget( int, int, zVEC3 const& )                  zCall( 0x00656CE0 );
    void RelaxHandToTarget( zVEC3 const&, zVEC3 const&, int, float ) zCall( 0x00657020 );
    void CheckSpecialStates()                                        zCall( 0x00657900 );
    void CheckJump()                                                 zCall( 0x00658650 );
    void HackNPCToSwim()                                             zCall( 0x00658B70 );
    void CheckFallStates()                                           zCall( 0x00658E80 );
    float CombineAniLerp( float, float, float, float )               zCall( 0x00659780 );
    int InterpolateCombineAni( float, float, int )                   zCall( 0x006597E0 );
    void LookAtTarget()                                              zCall( 0x00659960 );
    void SetLookAtTarget( float, float )                             zCall( 0x00659980 );
    void SetLookAtTarget( zVEC3& )                                   zCall( 0x006599D0 );
    void SetLookAtTarget( zCVob* )                                   zCall( 0x00659B00 );
    void StopLookAtTarget()                                          zCall( 0x00659CB0 );
    void StartCombineAni( zVEC3&, int, float, float )                zCall( 0x00659E60 );
    void StartCombineAni( zCVob*, int, float, float )                zCall( 0x00659FA0 );
    void StopCombineAni( int )                                       zCall( 0x0065A0F0 );
    int DetectChasm( zVEC3 const&, zVEC3 const&, float&, zVEC3& )    zCall( 0x0065A100 );
    int IsInCriticalAni()                                            zCall( 0x0065A280 );
    void SetActionMode( int )                                        zCall( 0x0065AA80 );
    void _Stand()                                                    zCall( 0x0065AB00 );
    void _Forward()                                                  zCall( 0x0065AF70 );
    void _Backward()                                                 zCall( 0x0065B230 );
    void SetAnimations( int, zSTRING const& )                        zCall( 0x0065B510 );
    int TransitionToInvest()                                         zCall( 0x0065B9C0 );
    int TransitionToCast()                                           zCall( 0x0065BB10 );
    int TransitionToStand()                                          zCall( 0x0065BD10 );
    int IsInCastAni()                                                zCall( 0x0065BED0 );
    int IsInWeaponChoose()                                           zCall( 0x0065BFA0 );
    int GetWaterLevel()                                              zCall( 0x0065C040 );
    int IsInWater()                                                  zCall( 0x0065C0B0 );
    int GetActionMode() const                                        zCall( 0x007914E0 );
    static zSTRING GetWeaponString( int )                            zCall( 0x006523E0 );
    static zSTRING GetWeaponHitString( int )                         zCall( 0x00652670 );
    static zCObject* _CreateNewInstance()                            zCall( 0x0065C330 );
    virtual zCClassDef* _GetClassDef() const                         zCall( 0x006473C0 );
    virtual void Archive( zCArchiver& )                              zCall( 0x0065A8E0 );
    virtual void Unarchive( zCArchiver& )                            zCall( 0x0065A990 );
    virtual ~oCAniCtrl_Human()                                       zCall( 0x00647400 );
    virtual void StartStandAni()                                     zCall( 0x006487E0 );
    virtual void StartFallDownAni()                                  zCall( 0x00658890 );
    virtual void Init( oCNpc* )                                      zCall( 0x006474E0 );

    // user API
    #include "oCAniCtrl_Human.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OANI_CTRL_H__VER2__