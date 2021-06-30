// Supported with union (c) 2018 Union team

#ifndef __OFOCUS_H__VER2__
#define __OFOCUS_H__VER2__

#include "oNpc.h"

namespace Gothic_II_Classic {
  const int FOCUS_MAX = 6;

  enum {
    FOCUS_NORMAL,
    FOCUS_MELEE,
    FOCUS_RANGED,
    FOCUS_THROW_ITEM,
    FOCUS_THROW_MOB,
    FOCUS_MAGIC
  };

  class oCNpcFocus {
  public:
    group {
      float n_range3;
      float n_range1;
      float n_range2;
      float n_azi;
      float n_elev1;
      float n_elev2;
      int n_prio;
      float i_range1;
      float i_range2;
      float i_azi;
      float i_elev1;
      float i_elev2;
      int i_prio;
      float m_range1;
      float m_range2;
      float m_azi;
      float m_elev1;
      float m_elev2;
      int m_prio;
      float max_range;
    };

    void oCNpcFocus_OnInit()                   zCall( 0x00662440 );
    oCNpcFocus()                               zInit( oCNpcFocus_OnInit() );
    ~oCNpcFocus()                              zCall( 0x00662460 );
    void Init( zSTRING& )                      zCall( 0x006624B0 );
    void Init( int )                           zCall( 0x006624E0 );
    int IsValid( int )                         zCall( 0x00662590 );
    float GetMaxRange()                        zCall( 0x006625E0 );
    float GetRange2()                          zCall( 0x006625F0 );
    float GetItemThrowRange()                  zCall( 0x00662600 );
    float GetMobThrowRange()                   zCall( 0x00662610 );
    int HasLowerPriority( int, int )           zCall( 0x00662620 );
    int GetPriority( int )                     zCall( 0x006626A0 );
    int IsInRange( int, float )                zCall( 0x006626E0 );
    int IsInAngle( int, float, float )         zCall( 0x00662770 );
    int IsNpcInRange( float )                  zCall( 0x00662850 );
    int IsNpcInAngle( float, float )           zCall( 0x006628A0 );
    int IsItemInRange( float )                 zCall( 0x006628F0 );
    int IsItemInAngle( float, float )          zCall( 0x00662920 );
    int IsMobInRange( float )                  zCall( 0x00662970 );
    int IsMobInAngle( float, float )           zCall( 0x006629A0 );
    float GetAzi()                             zCall( 0x006629F0 );
    static void InitFocusModes()               zCall( 0x006620F0 );
    static void ExitFocusModes()               zCall( 0x00662220 );
    static void SetFocusMode( int )            zCall( 0x00662290 );
    static zSTRING GetFocusName()              zCall( 0x00662370 );
    static void StartHighlightningFX( oCNpc* ) zCall( 0x00662A00 );
    static void StopHighlightningFX()          zCall( 0x00662B30 );

    // static properties
    static oCNpcFocus*& focus;
    static oCNpcFocus**& focuslist;
    static int& s_iHightlightMeleeFocus;
    static int& s_bHighlightInteractFocus;
    static oCVisualFX*& highLightFX;
    static int& isHighLighted;

    // user API
    #include "oCNpcFocus.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OFOCUS_H__VER2__