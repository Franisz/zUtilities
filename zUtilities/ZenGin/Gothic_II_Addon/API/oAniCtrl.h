// Supported with union (c) 2018 Union team

#ifndef __OANI_CTRL_H__VER3__
#define __OANI_CTRL_H__VER3__

#include "zModel.h"
#include "zAiPlayer.h"
#include "zArchiver.h"

namespace Gothic_II_Addon {
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

    void oCAniCtrl_Human_OnInit()                                    zCall( 0x006A3AF0 );
    int GetActionMode() const                                        zCall( 0x0067A890 );
    oCAniCtrl_Human()                                                zInit( oCAniCtrl_Human_OnInit() );
    int StartAni( int, int )                                         zCall( 0x006A3DC0 );
    void SetNextAni( int, int )                                      zCall( 0x006A3FA0 );
    void InitAnimations()                                            zCall( 0x006A4010 );
    void SearchStandAni( int )                                       zCall( 0x006A4D20 );
    void Reset()                                                     zCall( 0x006A5080 );
    void InitAngleValuesForConsole()                                 zCall( 0x006A50C0 );
    void SetScriptValues()                                           zCall( 0x006A5110 );
    void SetInterruptFollowAni( int )                                zCall( 0x006A5A40 );
    void InitAllAnis()                                               zCall( 0x006A5BF0 );
    void SetWalkMode( int )                                          zCall( 0x006A9820 );
    void InitFightAnis( int )                                        zCall( 0x006AA0B0 );
    void SetFightAnis( int )                                         zCall( 0x006AAA40 );
    void StartAniWithOffset( int, float )                            zCall( 0x006AAB60 );
    void DoAniWithOffset()                                           zCall( 0x006AAB70 );
    void CorrectFightPosition()                                      zCall( 0x006AAB80 );
    zSTRING GetWalkModeString()                                      zCall( 0x006AAE40 );
    void CorrectAniStates()                                          zCall( 0x006AAFA0 );
    int CheckWaterLevel()                                            zCall( 0x006AB130 );
    void SetAlwaysWalk( int )                                        zCall( 0x006ABDB0 );
    int IsAlwaysWalk()                                               zCall( 0x006ABF80 );
    int CanToggleWalkModeTo( int )                                   zCall( 0x006ABFB0 );
    int CanToggleWalkMode()                                          zCall( 0x006ACC10 );
    void ToggleWalkMode( int )                                       zCall( 0x006AD500 );
    int IsDead()                                                     zCall( 0x006AD540 );
    int IsFallen()                                                   zCall( 0x006ADC30 );
    int IsAiming()                                                   zCall( 0x006ADD40 );
    int IsStateAniActive( int )                                      zCall( 0x006ADE10 );
    int IsStateAniActive( zCModelAni* )                              zCall( 0x006ADE90 );
    int IsStanding()                                                 zCall( 0x006ADEE0 );
    int IsJumpStanding()                                             zCall( 0x006AE080 );
    int IsWalking()                                                  zCall( 0x006AE0E0 );
    int IsRunning()                                                  zCall( 0x006AE200 );
    int IsWalkingBackward()                                          zCall( 0x006AE410 );
    void StopTurnAnis()                                              zCall( 0x006AE530 );
    float Turn( float, int )                                         zCall( 0x006AE540 );
    void DoAutoRoll()                                                zCall( 0x006AEA40 );
    void TurnDegrees( float, int )                                   zCall( 0x006AEB10 );
    int WallInFront( float )                                         zCall( 0x006AEBF0 );
    int IsDefending()                                                zCall( 0x006AF180 );
    void GetFightLimbs()                                             zCall( 0x006AF1E0 );
    void DoSparks( zVEC3&, zSTRING const& )                          zCall( 0x006AFC50 );
    zCModelAniActive* GetLayerAni( int )                             zCall( 0x006AFD80 );
    int CheckLayerAni( int, zSTRING const& )                         zCall( 0x006AFDB0 );
    int CheckLimbHit( zSTRING const&, zCList<zCModelNodeInst>& )     zCall( 0x006AFDF0 );
    void ShowWeaponTrail()                                           zCall( 0x006AFE70 );
    void StartHitCombo( int, zCVob* )                                zCall( 0x006B00C0 );
    void SetComboHitTarget( zCVob const* )                           zCall( 0x006B0120 );
    void StartHitGraphical( int, zCVob* )                            zCall( 0x006B0130 );
    int GetStopTurnVobSign()                                         zCall( 0x006B0200 );
    int HitCombo( int )                                              zCall( 0x006B0260 );
    zCVob* CheckHitTarget()                                          zCall( 0x006B05C0 );
    void CreateHit( zCVob* )                                         zCall( 0x006B0830 );
    int CheckMeleeWeaponHitsLevel( oCItem* )                         zCall( 0x006B0CD0 );
    void HitInterrupt()                                              zCall( 0x006B11A0 );
    int HitGraphical()                                               zCall( 0x006B11E0 );
    int IsInPreHit()                                                 zCall( 0x006B1350 );
    int IsInPostHit()                                                zCall( 0x006B13A0 );
    int IsInCombo()                                                  zCall( 0x006B1430 );
    void FirstPersonDrawWeapon()                                     zCall( 0x006B1480 );
    zSTRING GetHitDirection()                                        zCall( 0x006B1490 );
    zCModelAniActive* IsParadeRunning()                              zCall( 0x006B1550 );
    int CanParade( oCNpc* )                                          zCall( 0x006B15B0 );
    void StartParadeEffects( oCNpc* )                                zCall( 0x006B16F0 );
    void StrafeLeft()                                                zCall( 0x006B1B40 );
    void StrafeRight()                                               zCall( 0x006B1B80 );
    int GetFootPos()                                                 zCall( 0x006B1BC0 );
    void PC_GoForward()                                              zCall( 0x006B1D70 );
    void PC_GoBackward()                                             zCall( 0x006B1DC0 );
    void PC_JumpForward()                                            zCall( 0x006B1E00 );
    int CanJump( int )                                               zCall( 0x006B1FE0 );
    int CanJumpLedge()                                               zCall( 0x006B2050 );
    int JumpForward()                                                zCall( 0x006B21E0 );
    int Swim_CanClimbLedge()                                         zCall( 0x006B2400 );
    void Swim_ClimbLedge()                                           zCall( 0x006B2440 );
    int CanWalkOnPoly( zVEC3 const& )                                zCall( 0x006B25A0 );
    int DrawWeapon1( int, int, int )                                 zCall( 0x006B2610 );
    int ChooseNextWeapon2( int )                                     zCall( 0x006B2900 );
    int DrawWeapon2()                                                zCall( 0x006B2CF0 );
    int RemoveWeapon1()                                              zCall( 0x006B3040 );
    int RemoveWeapon2()                                              zCall( 0x006B33B0 );
    void StartUp( zCVob* )                                           zCall( 0x006B3660 );
    void LerpFeetToTarget( int, int, zVEC3 const& )                  zCall( 0x006B3670 );
    void RelaxHandToTarget( zVEC3 const&, zVEC3 const&, int, float ) zCall( 0x006B39B0 );
    void CheckSpecialStates()                                        zCall( 0x006B4290 );
    void CheckJump()                                                 zCall( 0x006B4FE0 );
    void HackNPCToSwim()                                             zCall( 0x006B5500 );
    void CheckFallStates()                                           zCall( 0x006B5810 );
    float CombineAniLerp( float, float, float, float )               zCall( 0x006B6110 );
    int InterpolateCombineAni( float, float, int )                   zCall( 0x006B6170 );
    void LookAtTarget()                                              zCall( 0x006B62F0 );
    void SetLookAtTarget( float, float )                             zCall( 0x006B6310 );
    void SetLookAtTarget( zVEC3& )                                   zCall( 0x006B6360 );
    void SetLookAtTarget( zCVob* )                                   zCall( 0x006B6490 );
    void StopLookAtTarget()                                          zCall( 0x006B6640 );
    void StartCombineAni( zVEC3&, int, float, float )                zCall( 0x006B67F0 );
    void StartCombineAni( zCVob*, int, float, float )                zCall( 0x006B6930 );
    void StopCombineAni( int )                                       zCall( 0x006B6A80 );
    int DetectChasm( zVEC3 const&, zVEC3 const&, float&, zVEC3& )    zCall( 0x006B6A90 );
    int IsInCriticalAni()                                            zCall( 0x006B6C10 );
    void SetActionMode( int )                                        zCall( 0x006B7410 );
    void _Stand()                                                    zCall( 0x006B7490 );
    void _Forward()                                                  zCall( 0x006B7900 );
    void _Backward()                                                 zCall( 0x006B7BC0 );
    void SetAnimations( int, zSTRING const& )                        zCall( 0x006B7EA0 );
    int TransitionToInvest()                                         zCall( 0x006B8350 );
    int TransitionToCast()                                           zCall( 0x006B84A0 );
    int TransitionToStand()                                          zCall( 0x006B86A0 );
    int IsInCastAni()                                                zCall( 0x006B8860 );
    int IsInWeaponChoose()                                           zCall( 0x006B8930 );
    int GetWaterLevel()                                              zCall( 0x006B89D0 );
    int IsInWater()                                                  zCall( 0x006B8A40 );
    static zSTRING GetWeaponString( int )                            zCall( 0x006AEC60 );
    static zSTRING GetWeaponHitString( int )                         zCall( 0x006AEEF0 );
    static zCObject* _CreateNewInstance()                            zCall( 0x006B8CC0 );
    virtual zCClassDef* _GetClassDef() const                         zCall( 0x006A3C40 );
    virtual void Archive( zCArchiver& )                              zCall( 0x006B7270 );
    virtual void Unarchive( zCArchiver& )                            zCall( 0x006B7320 );
    virtual ~oCAniCtrl_Human()                                       zCall( 0x006A3C80 );
    virtual void StartStandAni()                                     zCall( 0x006A5060 );
    virtual void StartFallDownAni()                                  zCall( 0x006B5220 );
    virtual void Init( oCNpc* )                                      zCall( 0x006A3D60 );

    // user API
    #include "oCAniCtrl_Human.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OANI_CTRL_H__VER3__