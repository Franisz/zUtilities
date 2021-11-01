// Supported with union (c) 2018-2021 Union team

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

  // sizeof 11F8h
  class oCAniCtrl_Human : public zCAIPlayer {
  public:
    zCLASS_DECLARATION( oCAniCtrl_Human )

    // sizeof 18h
    struct oTComboInfo {
    public:
      int hitAni;          // sizeof 04h    offset 00h
      int hitOptFrame;     // sizeof 04h    offset 04h
      int hitEndFrame;     // sizeof 04h    offset 08h
      int comboStartFrame; // sizeof 04h    offset 0Ch
      int comboEndFrame;   // sizeof 04h    offset 10h
      int comboDir;        // sizeof 04h    offset 14h

      // user API
      #include "oCAniCtrl_Human_oTComboInfo.inl"
    };

    float angle_slide1;                        // sizeof 04h    offset 118h
    float angle_slide2;                        // sizeof 04h    offset 11Ch
    float angle_heading;                       // sizeof 04h    offset 120h
    float angle_horiz;                         // sizeof 04h    offset 124h
    float angle_ground;                        // sizeof 04h    offset 128h
    oCNpc* npc;                                // sizeof 04h    offset 12Ch
    zCVob* targetVob;                          // sizeof 04h    offset 130h
    zCVob* stopTurnVob;                        // sizeof 04h    offset 134h
    int stopTurnVobSign;                       // sizeof 04h    offset 138h
    zCModelNodeInst* hitlimb[ANI_HITLIMB_MAX]; // sizeof 10h    offset 13Ch
    int actionMode;                            // sizeof 04h    offset 14Ch
    int wmode;                                 // sizeof 04h    offset 150h
    int wmode_last;                            // sizeof 04h    offset 154h
    int wmode_selected;                        // sizeof 04h    offset 158h
    int changeweapon;                          // sizeof 04h    offset 15Ch
    int walkmode;                              // sizeof 04h    offset 160h
    int nextwalkmode;                          // sizeof 04h    offset 164h
    int lastRunWalkSneak;                      // sizeof 04h    offset 168h
    int always_walk;                           // sizeof 04h    offset 16Ch
    int do_jump;                               // sizeof 04h    offset 170h
    int defaultSurfaceAlign;                   // sizeof 04h    offset 174h
    float autoRollDirection;                   // sizeof 04h    offset 178h
    float lookTargetx;                         // sizeof 04h    offset 17Ch
    float lookTargety;                         // sizeof 04h    offset 180h
    int distance;                              // sizeof 04h    offset 184h
    zVEC3 hitpos;                              // sizeof 0Ch    offset 188h
    zSTRING limbname;                          // sizeof 14h    offset 194h
    float paradeBeginFrame;                    // sizeof 04h    offset 1A8h
    float paradeEndFrame;                      // sizeof 04h    offset 1ACh
    group {
      unsigned char canEnableNextCombo : 1;    // sizeof 01h    offset bit
      unsigned char endCombo           : 1;    // sizeof 01h    offset bit
      unsigned char comboCanHit        : 1;    // sizeof 01h    offset bit
      unsigned char hitPosUsed         : 1;    // sizeof 01h    offset bit
      unsigned char hitGraphical       : 1;    // sizeof 01h    offset bit
      unsigned char canDoCollisionFX   : 1;    // sizeof 01h    offset bit
    };
    int comboNr;                               // sizeof 04h    offset 1B4h
    int comboMax;                              // sizeof 04h    offset 1B8h
    float lastHitAniFrame;                     // sizeof 04h    offset 1BCh
    int hitAniID;                              // sizeof 04h    offset 1C0h
    zCVob* hitTarget;                          // sizeof 04h    offset 1C4h
    oTComboInfo comboInfo[ANI_MAX_HIT];        // sizeof F0h    offset 1C8h
    float anioffset_lastper;                   // sizeof 04h    offset 2B8h
    float anioffset_thisper;                   // sizeof 04h    offset 2BCh
    float anioffset;                           // sizeof 04h    offset 2C0h
    int anioffset_ani;                         // sizeof 04h    offset 2C4h
    int s_dead1;                               // sizeof 04h    offset 2C8h
    int s_dead2;                               // sizeof 04h    offset 2CCh
    int s_hang;                                // sizeof 04h    offset 2D0h
    int t_hang_2_stand;                        // sizeof 04h    offset 2D4h
    int s_run[ANI_NUM];                        // sizeof 28h    offset 2D8h
    int t_run_2_runl[ANI_NUM];                 // sizeof 28h    offset 300h
    int t_runl_2_run[ANI_NUM];                 // sizeof 28h    offset 328h
    int s_runl[ANI_NUM];                       // sizeof 28h    offset 350h
    int t_runl_2_runr[ANI_NUM];                // sizeof 28h    offset 378h
    int t_runr_2_runl[ANI_NUM];                // sizeof 28h    offset 3A0h
    int s_runr[ANI_NUM];                       // sizeof 28h    offset 3C8h
    int t_runr_2_run[ANI_NUM];                 // sizeof 28h    offset 3F0h
    int t_runturnl[ANI_NUM];                   // sizeof 28h    offset 418h
    int t_runturnr[ANI_NUM];                   // sizeof 28h    offset 440h
    int t_runstrafel[ANI_NUM];                 // sizeof 28h    offset 468h
    int t_runstrafer[ANI_NUM];                 // sizeof 28h    offset 490h
    int t_run_2_runbl[ANI_NUM];                // sizeof 28h    offset 4B8h
    int t_runbl_2_run[ANI_NUM];                // sizeof 28h    offset 4E0h
    int s_runbl[ANI_NUM];                      // sizeof 28h    offset 508h
    int t_runbl_2_runbr[ANI_NUM];              // sizeof 28h    offset 530h
    int t_runbr_2_runbl[ANI_NUM];              // sizeof 28h    offset 558h
    int s_runbr[ANI_NUM];                      // sizeof 28h    offset 580h
    int t_runbr_2_run[ANI_NUM];                // sizeof 28h    offset 5A8h
    int t_jumpb[ANI_NUM];                      // sizeof 28h    offset 5D0h
    int t_run_2_walk[ANI_NUM];                 // sizeof 28h    offset 5F8h
    int t_walk_2_run[ANI_NUM];                 // sizeof 28h    offset 620h
    int t_run_2_sneak[ANI_NUM];                // sizeof 28h    offset 648h
    int t_sneak_2_run[ANI_NUM];                // sizeof 28h    offset 670h
    int s_walk[ANI_NUM];                       // sizeof 28h    offset 698h
    int t_walk_2_walkl[ANI_NUM];               // sizeof 28h    offset 6C0h
    int t_walkl_2_walk[ANI_NUM];               // sizeof 28h    offset 6E8h
    int s_walkl[ANI_NUM];                      // sizeof 28h    offset 710h
    int t_walkl_2_walkr[ANI_NUM];              // sizeof 28h    offset 738h
    int t_walkr_2_walkl[ANI_NUM];              // sizeof 28h    offset 760h
    int s_walkr[ANI_NUM];                      // sizeof 28h    offset 788h
    int t_walkr_2_walk[ANI_NUM];               // sizeof 28h    offset 7B0h
    int t_walkturnl[ANI_NUM];                  // sizeof 28h    offset 7D8h
    int t_walkturnr[ANI_NUM];                  // sizeof 28h    offset 800h
    int t_walkstrafel[ANI_NUM];                // sizeof 28h    offset 828h
    int t_walkstrafer[ANI_NUM];                // sizeof 28h    offset 850h
    int t_walk_2_walkbl[ANI_NUM];              // sizeof 28h    offset 878h
    int t_walkbl_2_walk[ANI_NUM];              // sizeof 28h    offset 8A0h
    int s_walkbl[ANI_NUM];                     // sizeof 28h    offset 8C8h
    int t_walkbl_2_walkbr[ANI_NUM];            // sizeof 28h    offset 8F0h
    int t_walkbr_2_walkbl[ANI_NUM];            // sizeof 28h    offset 918h
    int s_walkbr[ANI_NUM];                     // sizeof 28h    offset 940h
    int t_walkbr_2_walk[ANI_NUM];              // sizeof 28h    offset 968h
    int t_runl_2_jump[ANI_NUM];                // sizeof 28h    offset 990h
    int t_runr_2_jump[ANI_NUM];                // sizeof 28h    offset 9B8h
    int t_jump_2_runl[ANI_NUM];                // sizeof 28h    offset 9E0h
    int t_stand_2_jumpuplow;                   // sizeof 04h    offset A08h
    int s_jumpuplow;                           // sizeof 04h    offset A0Ch
    int t_jumpuplow_2_stand;                   // sizeof 04h    offset A10h
    int t_stand_2_jumpupmid;                   // sizeof 04h    offset A14h
    int s_jumpupmid;                           // sizeof 04h    offset A18h
    int t_jumpupmid_2_stand;                   // sizeof 04h    offset A1Ch
    int s_sneak[ANI_NUM];                      // sizeof 28h    offset A20h
    int t_sneak_2_sneakl[ANI_NUM];             // sizeof 28h    offset A48h
    int t_sneakl_2_sneak[ANI_NUM];             // sizeof 28h    offset A70h
    int s_sneakl[ANI_NUM];                     // sizeof 28h    offset A98h
    int t_sneakl_2_sneakr[ANI_NUM];            // sizeof 28h    offset AC0h
    int t_sneakr_2_sneakl[ANI_NUM];            // sizeof 28h    offset AE8h
    int s_sneakr[ANI_NUM];                     // sizeof 28h    offset B10h
    int t_sneakr_2_sneak[ANI_NUM];             // sizeof 28h    offset B38h
    int t_sneakturnl[ANI_NUM];                 // sizeof 28h    offset B60h
    int t_sneakturnr[ANI_NUM];                 // sizeof 28h    offset B88h
    int t_sneakstrafel[ANI_NUM];               // sizeof 28h    offset BB0h
    int t_sneakstrafer[ANI_NUM];               // sizeof 28h    offset BD8h
    int t_sneak_2_sneakbl[ANI_NUM];            // sizeof 28h    offset C00h
    int t_sneakbl_2_sneak[ANI_NUM];            // sizeof 28h    offset C28h
    int s_sneakbl[ANI_NUM];                    // sizeof 28h    offset C50h
    int t_sneakbl_2_sneakbr[ANI_NUM];          // sizeof 28h    offset C78h
    int t_sneakbr_2_sneakbl[ANI_NUM];          // sizeof 28h    offset CA0h
    int s_sneakbr[ANI_NUM];                    // sizeof 28h    offset CC8h
    int t_sneakbr_2_sneak[ANI_NUM];            // sizeof 28h    offset CF0h
    int t_walkl_2_aim[ANI_NUM];                // sizeof 28h    offset D18h
    int t_walkr_2_aim[ANI_NUM];                // sizeof 28h    offset D40h
    int t_walk_2_aim[ANI_NUM];                 // sizeof 28h    offset D68h
    int s_aim[ANI_NUM];                        // sizeof 28h    offset D90h
    int t_aim_2_walk[ANI_NUM];                 // sizeof 28h    offset DB8h
    int t_hitl[ANI_NUM];                       // sizeof 28h    offset DE0h
    int t_hitr[ANI_NUM];                       // sizeof 28h    offset E08h
    int t_hitback[ANI_NUM];                    // sizeof 28h    offset E30h
    int t_hitf[ANI_NUM];                       // sizeof 28h    offset E58h
    int s_hitf[ANI_NUM];                       // sizeof 28h    offset E80h
    int t_aim_2_defend[ANI_NUM];               // sizeof 28h    offset EA8h
    int s_defend[ANI_NUM];                     // sizeof 28h    offset ED0h
    int t_defend_2_aim[ANI_NUM];               // sizeof 28h    offset EF8h
    int t_paradeL[ANI_NUM];                    // sizeof 28h    offset F20h
    int t_paradeM[ANI_NUM];                    // sizeof 28h    offset F48h
    int t_paradeS[ANI_NUM];                    // sizeof 28h    offset F70h
    int t_hitfrun[ANI_NUM];                    // sizeof 28h    offset F98h
    int t_stumble;                             // sizeof 04h    offset FC0h
    int t_stumbleb;                            // sizeof 04h    offset FC4h
    int t_fallen_2_stand;                      // sizeof 04h    offset FC8h
    int t_fallenb_2_stand;                     // sizeof 04h    offset FCCh
    int t_walk_2_walkwl;                       // sizeof 04h    offset FD0h
    int t_walkwl_2_walk;                       // sizeof 04h    offset FD4h
    int s_walkwl;                              // sizeof 04h    offset FD8h
    int t_walkwl_2_walkwr;                     // sizeof 04h    offset FDCh
    int t_walkwr_2_walkwl;                     // sizeof 04h    offset FE0h
    int s_walkwr;                              // sizeof 04h    offset FE4h
    int t_walkwr_2_walk;                       // sizeof 04h    offset FE8h
    int t_walk_2_walkwbl;                      // sizeof 04h    offset FECh
    int t_walkwbl_2_walk;                      // sizeof 04h    offset FF0h
    int s_walkwbl;                             // sizeof 04h    offset FF4h
    int t_walkwbl_2_walkwbr;                   // sizeof 04h    offset FF8h
    int t_walkwbr_2_walkwbl;                   // sizeof 04h    offset FFCh
    int s_walkwbr;                             // sizeof 04h    offset 1000h
    int t_walkwbr_2_walk;                      // sizeof 04h    offset 1004h
    int _s_walk;                               // sizeof 04h    offset 1008h
    int _t_walk_2_walkl;                       // sizeof 04h    offset 100Ch
    int _t_walkl_2_walk;                       // sizeof 04h    offset 1010h
    int _s_walkl;                              // sizeof 04h    offset 1014h
    int _t_walkl_2_walkr;                      // sizeof 04h    offset 1018h
    int _t_walkr_2_walkl;                      // sizeof 04h    offset 101Ch
    int _s_walkr;                              // sizeof 04h    offset 1020h
    int _t_walkr_2_walk;                       // sizeof 04h    offset 1024h
    int _t_turnl;                              // sizeof 04h    offset 1028h
    int _t_turnr;                              // sizeof 04h    offset 102Ch
    int _t_strafel;                            // sizeof 04h    offset 1030h
    int _t_strafer;                            // sizeof 04h    offset 1034h
    int _t_walk_2_walkbl;                      // sizeof 04h    offset 1038h
    int _t_walkbl_2_walk;                      // sizeof 04h    offset 103Ch
    int _s_walkbl;                             // sizeof 04h    offset 1040h
    int _t_walkbl_2_walkbr;                    // sizeof 04h    offset 1044h
    int _t_walkbr_2_walkbl;                    // sizeof 04h    offset 1048h
    int _s_walkbr;                             // sizeof 04h    offset 104Ch
    int _t_walkbr_2_walk;                      // sizeof 04h    offset 1050h
    int s_jumpstand;                           // sizeof 04h    offset 1054h
    int t_stand_2_jumpstand;                   // sizeof 04h    offset 1058h
    int t_jumpstand_2_stand;                   // sizeof 04h    offset 105Ch
    int _t_jumpb;                              // sizeof 04h    offset 1060h
    int _t_stand_2_jump;                       // sizeof 04h    offset 1064h
    int _s_jump;                               // sizeof 04h    offset 1068h
    int t_jump_2_stand;                        // sizeof 04h    offset 106Ch
    int _t_stand_2_jumpup;                     // sizeof 04h    offset 1070h
    int _s_jumpup;                             // sizeof 04h    offset 1074h
    int _t_jumpup_2_falldn;                    // sizeof 04h    offset 1078h
    int _t_jump_2_falldn;                      // sizeof 04h    offset 107Ch
    int t_walkwl_2_swimf;                      // sizeof 04h    offset 1080h
    int s_swimf;                               // sizeof 04h    offset 1084h
    int t_swimf_2_walkwl;                      // sizeof 04h    offset 1088h
    int t_walkwbl_2_swimb;                     // sizeof 04h    offset 108Ch
    int s_swimb;                               // sizeof 04h    offset 1090h
    int t_swimb_2_walkwbl;                     // sizeof 04h    offset 1094h
    int t_swimf_2_swim;                        // sizeof 04h    offset 1098h
    int s_swim;                                // sizeof 04h    offset 109Ch
    int t_swim_2_swimf;                        // sizeof 04h    offset 10A0h
    int t_swim_2_swimb;                        // sizeof 04h    offset 10A4h
    int t_swimb_2_swim;                        // sizeof 04h    offset 10A8h
    int t_warn;                                // sizeof 04h    offset 10ACh
    int t_swim_2_dive;                         // sizeof 04h    offset 10B0h
    int s_dive;                                // sizeof 04h    offset 10B4h
    int t_divef_2_swim;                        // sizeof 04h    offset 10B8h
    int t_dive_2_divef;                        // sizeof 04h    offset 10BCh
    int s_divef;                               // sizeof 04h    offset 10C0h
    int t_divef_2_dive;                        // sizeof 04h    offset 10C4h
    int t_dive_2_drowned;                      // sizeof 04h    offset 10C8h
    int s_drowned;                             // sizeof 04h    offset 10CCh
    int t_swimturnl;                           // sizeof 04h    offset 10D0h
    int t_swimturnr;                           // sizeof 04h    offset 10D4h
    int t_diveturnl;                           // sizeof 04h    offset 10D8h
    int t_diveturnr;                           // sizeof 04h    offset 10DCh
    int _t_walkl_2_aim;                        // sizeof 04h    offset 10E0h
    int _t_walkr_2_aim;                        // sizeof 04h    offset 10E4h
    int _t_walk_2_aim;                         // sizeof 04h    offset 10E8h
    int _s_aim;                                // sizeof 04h    offset 10ECh
    int _t_aim_2_walk;                         // sizeof 04h    offset 10F0h
    int _t_hitl;                               // sizeof 04h    offset 10F4h
    int _t_hitr;                               // sizeof 04h    offset 10F8h
    int _t_hitback;                            // sizeof 04h    offset 10FCh
    int _t_hitf;                               // sizeof 04h    offset 1100h
    int _t_hitfstep;                           // sizeof 04h    offset 1104h
    int _s_hitf;                               // sizeof 04h    offset 1108h
    int _t_aim_2_defend;                       // sizeof 04h    offset 110Ch
    int _s_defend;                             // sizeof 04h    offset 1110h
    int _t_defend_2_aim;                       // sizeof 04h    offset 1114h
    int _t_paradeL;                            // sizeof 04h    offset 1118h
    int _t_paradeM;                            // sizeof 04h    offset 111Ch
    int _t_paradeS;                            // sizeof 04h    offset 1120h
    int _t_hitfrun;                            // sizeof 04h    offset 1124h
    int t_stand_2_iaim;                        // sizeof 04h    offset 1128h
    int s_iaim;                                // sizeof 04h    offset 112Ch
    int t_iaim_2_stand;                        // sizeof 04h    offset 1130h
    int t_iaim_2_idrop;                        // sizeof 04h    offset 1134h
    int s_idrop;                               // sizeof 04h    offset 1138h
    int t_idrop_2_stand;                       // sizeof 04h    offset 113Ch
    int t_iaim_2_ithrow;                       // sizeof 04h    offset 1140h
    int s_ithrow;                              // sizeof 04h    offset 1144h
    int t_ithrow_2_stand;                      // sizeof 04h    offset 1148h
    int t_stand_2_iget;                        // sizeof 04h    offset 114Ch
    int s_iget;                                // sizeof 04h    offset 1150h
    int t_iget_2_stand;                        // sizeof 04h    offset 1154h
    int s_oget;                                // sizeof 04h    offset 1158h
    int _t_stand_2_torch;                      // sizeof 04h    offset 115Ch
    int _s_torch;                              // sizeof 04h    offset 1160h
    int _t_torch_2_stand;                      // sizeof 04h    offset 1164h
    int hitani;                                // sizeof 04h    offset 1168h
    int help;                                  // sizeof 04h    offset 116Ch
    int help1;                                 // sizeof 04h    offset 1170h
    int help2;                                 // sizeof 04h    offset 1174h
    int s_fall;                                // sizeof 04h    offset 1178h
    int s_fallb;                               // sizeof 04h    offset 117Ch
    int s_fallen;                              // sizeof 04h    offset 1180h
    int s_fallenb;                             // sizeof 04h    offset 1184h
    int s_falldn;                              // sizeof 04h    offset 1188h
    int _t_runl_2_jump;                        // sizeof 04h    offset 118Ch
    int _t_runr_2_jump;                        // sizeof 04h    offset 1190h
    int _t_jump_2_runl;                        // sizeof 04h    offset 1194h
    int s_look;                                // sizeof 04h    offset 1198h
    int s_point;                               // sizeof 04h    offset 119Ch
    int dummy1;                                // sizeof 04h    offset 11A0h
    int dummy2;                                // sizeof 04h    offset 11A4h
    int dummy3;                                // sizeof 04h    offset 11A8h
    int dummy4;                                // sizeof 04h    offset 11ACh
    int s_weapon[ANI_NUM];                     // sizeof 28h    offset 11B0h
    int togglewalk;                            // sizeof 04h    offset 11D8h
    int t_stand_2_cast;                        // sizeof 04h    offset 11DCh
    int s_cast;                                // sizeof 04h    offset 11E0h
    int t_cast_2_shoot;                        // sizeof 04h    offset 11E4h
    int t_cast_2_stand;                        // sizeof 04h    offset 11E8h
    int s_shoot;                               // sizeof 04h    offset 11ECh
    int t_shoot_2_stand;                       // sizeof 04h    offset 11F0h
    int dummyLastVar;                          // sizeof 04h    offset 11F4h

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