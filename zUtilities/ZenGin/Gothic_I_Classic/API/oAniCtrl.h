// Supported with union (c) 2018 Union team

#ifndef __OANI_CTRL_H__VER0__
#define __OANI_CTRL_H__VER0__

#include "zModel.h"
#include "zAiPlayer.h"
#include "zArchiver.h"

namespace Gothic_I_Classic {
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

    void oCAniCtrl_Human_OnInit()                                       zCall( 0x0061B530 );
    oCAniCtrl_Human()                                                   zInit( oCAniCtrl_Human_OnInit() );
    int StartAni( int, int )                                            zCall( 0x0061B7A0 );
    void SetNextAni( int, int )                                         zCall( 0x0061B980 );
    void InitAnimations()                                               zCall( 0x0061B9F0 );
    void SearchStandAni( int )                                          zCall( 0x0061C700 );
    void Reset()                                                        zCall( 0x0061CA60 );
    void InitAngleValuesForConsole()                                    zCall( 0x0061CAA0 );
    void SetScriptValues()                                              zCall( 0x0061CAF0 );
    void SetInterruptFollowAni( int )                                   zCall( 0x0061D400 );
    void InitAllAnis()                                                  zCall( 0x0061D5B0 );
    void SetWalkMode( int )                                             zCall( 0x006211E0 );
    void InitFightAnis( int )                                           zCall( 0x00621A70 );
    void SetFightAnis( int )                                            zCall( 0x00622400 );
    void StartAniWithOffset( int, float )                               zCall( 0x00622520 );
    void DoAniWithOffset()                                              zCall( 0x00622530 );
    void CorrectFightPosition()                                         zCall( 0x00622540 );
    zSTRING GetWalkModeString()                                         zCall( 0x00622730 );
    void CorrectAniStates()                                             zCall( 0x00622890 );
    int CheckWaterLevel()                                               zCall( 0x00622A20 );
    void SetAlwaysWalk( int )                                           zCall( 0x006236E0 );
    int IsAlwaysWalk()                                                  zCall( 0x006238B0 );
    int CanToggleWalkModeTo( int )                                      zCall( 0x006238E0 );
    int CanToggleWalkMode()                                             zCall( 0x00624540 );
    void ToggleWalkMode( int )                                          zCall( 0x00624E30 );
    int IsDead()                                                        zCall( 0x00624E70 );
    int IsFallen()                                                      zCall( 0x00625330 );
    int IsAiming()                                                      zCall( 0x00625440 );
    int IsStateAniActive( int )                                         zCall( 0x00625510 );
    int IsStateAniActive( zCModelAni* )                                 zCall( 0x00625590 );
    int IsStanding()                                                    zCall( 0x006255E0 );
    int IsJumpStanding()                                                zCall( 0x00625780 );
    int IsWalking()                                                     zCall( 0x006257E0 );
    int IsWalkingBackward()                                             zCall( 0x00625900 );
    void StopTurnAnis()                                                 zCall( 0x00625A20 );
    float Turn( float, int )                                            zCall( 0x00625A30 );
    void DoAutoRoll()                                                   zCall( 0x00625EE0 );
    void TurnDegrees( float, int )                                      zCall( 0x00625FB0 );
    int WallInFront( float )                                            zCall( 0x00626090 );
    int IsDefending()                                                   zCall( 0x00626620 );
    void GetFightLimbs()                                                zCall( 0x00626680 );
    void DoSparks( zVEC3&, zSTRING const& )                             zCall( 0x006270F0 );
    zCModelAniActive* GetLayerAni( int )                                zCall( 0x00627240 );
    int CheckLayerAni( int, zSTRING const& )                            zCall( 0x00627270 );
    int CheckLimbHit( zSTRING const&, zCList<zCModelNodeInst>& )        zCall( 0x006272B0 );
    void ShowWeaponTrail()                                              zCall( 0x00627330 );
    void StartHitCombo( int, zCVob* )                                   zCall( 0x00627560 );
    void StartHitGraphical( int, zCVob* )                               zCall( 0x006275C0 );
    int GetStopTurnVobSign()                                            zCall( 0x00627690 );
    int HitCombo( int )                                                 zCall( 0x006276F0 );
    zCVob* CheckHitTarget()                                             zCall( 0x00627A10 );
    void CreateHit( zCVob* )                                            zCall( 0x00627C80 );
    void HitInterrupt()                                                 zCall( 0x006280C0 );
    int HitGraphical()                                                  zCall( 0x00628100 );
    int IsInPreHit()                                                    zCall( 0x00628270 );
    int IsInPostHit()                                                   zCall( 0x006282C0 );
    int IsInCombo()                                                     zCall( 0x00628350 );
    zSTRING GetHitDirection()                                           zCall( 0x006283A0 );
    zCModelAniActive* IsParadeRunning()                                 zCall( 0x00628470 );
    int CanParade( oCNpc* )                                             zCall( 0x006284C0 );
    void StartParadeEffects( oCNpc* )                                   zCall( 0x00628580 );
    void StrafeLeft()                                                   zCall( 0x006289D0 );
    void StrafeRight()                                                  zCall( 0x00628A10 );
    int GetFootPos()                                                    zCall( 0x00628A50 );
    void PC_GoForward()                                                 zCall( 0x00628C00 );
    void PC_GoBackward()                                                zCall( 0x00628C50 );
    void PC_JumpForward()                                               zCall( 0x00628C90 );
    int CanJump( int )                                                  zCall( 0x00628E70 );
    int CanJumpLedge()                                                  zCall( 0x00628EE0 );
    int JumpForward()                                                   zCall( 0x00629070 );
    int Swim_CanClimbLedge()                                            zCall( 0x00629290 );
    void Swim_ClimbLedge()                                              zCall( 0x006292D0 );
    int CanWalkOnPoly( zVEC3 const& )                                   zCall( 0x00629430 );
    int DrawWeapon1( int, int, int )                                    zCall( 0x006294A0 );
    int ChooseNextWeapon2( int )                                        zCall( 0x00629740 );
    int DrawWeapon2()                                                   zCall( 0x00629B70 );
    int RemoveWeapon1()                                                 zCall( 0x00629E50 );
    int RemoveWeapon2()                                                 zCall( 0x0062A050 );
    void StartUp( zCVob* )                                              zCall( 0x0062A300 );
    void LerpFeetToTarget( int, int, zVEC3 const& )                     zCall( 0x0062A310 );
    void RelaxHandToTarget( zVEC3 const&, zVEC3 const&, int, float )    zCall( 0x0062A650 );
    void CheckSpecialStates()                                           zCall( 0x0062AF60 );
    void CheckJump()                                                    zCall( 0x0062BCD0 );
    void CheckFallStates()                                              zCall( 0x0062C1F0 );
    float CombineAniLerp( float, float, float, float )                  zCall( 0x0062CAF0 );
    int InterpolateCombineAni( float, float, int )                      zCall( 0x0062CB50 );
    void LookAtTarget()                                                 zCall( 0x0062CCD0 );
    void SetLookAtTarget( float, float )                                zCall( 0x0062CCF0 );
    void SetLookAtTarget( zVEC3& )                                      zCall( 0x0062CD10 );
    void SetLookAtTarget( zCVob* )                                      zCall( 0x0062CE10 );
    void StopLookAtTarget()                                             zCall( 0x0062CF70 );
    void StartCombineAni( zVEC3&, int, float, float )                   zCall( 0x0062D050 );
    void StartCombineAni( zCVob*, int, float, float )                   zCall( 0x0062D190 );
    void StopCombineAni( int )                                          zCall( 0x0062D2E0 );
    int DetectChasm( zVEC3 const&, zVEC3 const&, float&, zVEC3& )       zCall( 0x0062D2F0 );
    int IsInCriticalAni()                                               zCall( 0x0062D470 );
    void SetActionMode( int )                                           zCall( 0x0062DC70 );
    void _Stand()                                                       zCall( 0x0062DCF0 );
    void _Forward()                                                     zCall( 0x0062E160 );
    void _Backward()                                                    zCall( 0x0062E420 );
    void SetAnimations( int, zSTRING const& )                           zCall( 0x0062E700 );
    int TransitionToInvest()                                            zCall( 0x0062EBB0 );
    int TransitionToCast()                                              zCall( 0x0062ECA0 );
    int TransitionToStand()                                             zCall( 0x0062EEA0 );
    int IsInCastAni()                                                   zCall( 0x0062F060 );
    int IsInWeaponChoose()                                              zCall( 0x0062F130 );
    int GetWaterLevel()                                                 zCall( 0x0062F1D0 );
    int IsInWater()                                                     zCall( 0x0062F240 );
    int GetActionMode() const                                           zCall( 0x00746650 );
    static zSTRING GetWeaponString( int )                               zCall( 0x00626100 );
    static zSTRING GetWeaponHitString( int )                            zCall( 0x00626390 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0062F4C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0061B680 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0062DAD0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0062DB80 );
    virtual ~oCAniCtrl_Human()                                          zCall( 0x0061B6C0 );
    virtual void StartStandAni()                                        zCall( 0x0061CA40 );
    virtual void StartFallDownAni()                                     zCall( 0x0062BF10 );
    virtual void Init( oCNpc* )                                         zCall( 0x0061B740 );

    // user API
    #include "oCAniCtrl_Human.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OANI_CTRL_H__VER0__