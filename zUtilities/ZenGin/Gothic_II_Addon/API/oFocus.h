// Supported with union (c) 2018 Union team

#ifndef __OFOCUS_H__VER3__
#define __OFOCUS_H__VER3__

#include "oNpc.h"

namespace Gothic_II_Addon {
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

    void oCNpcFocus_OnInit()                   zCall( 0x006BEDD0 );
    oCNpcFocus()                               zInit( oCNpcFocus_OnInit() );
    ~oCNpcFocus()                              zCall( 0x006BEDF0 );
    void Init( zSTRING& )                      zCall( 0x006BEE40 );
    void Init( int )                           zCall( 0x006BEE70 );
    int IsValid( int )                         zCall( 0x006BEF20 );
    float GetMaxRange()                        zCall( 0x006BEF70 );
    float GetRange2()                          zCall( 0x006BEF80 );
    float GetItemThrowRange()                  zCall( 0x006BEF90 );
    float GetMobThrowRange()                   zCall( 0x006BEFA0 );
    int HasLowerPriority( int, int )           zCall( 0x006BEFB0 );
    int GetPriority( int )                     zCall( 0x006BF030 );
    int IsInRange( int, float )                zCall( 0x006BF070 );
    int IsInAngle( int, float, float )         zCall( 0x006BF100 );
    int IsNpcInRange( float )                  zCall( 0x006BF1E0 );
    int IsNpcInAngle( float, float )           zCall( 0x006BF230 );
    int IsItemInRange( float )                 zCall( 0x006BF280 );
    int IsItemInAngle( float, float )          zCall( 0x006BF2B0 );
    int IsMobInRange( float )                  zCall( 0x006BF300 );
    int IsMobInAngle( float, float )           zCall( 0x006BF330 );
    float GetAzi()                             zCall( 0x006BF380 );
    static void InitFocusModes()               zCall( 0x006BEA80 );
    static void ExitFocusModes()               zCall( 0x006BEBB0 );
    static void SetFocusMode( int )            zCall( 0x006BEC20 );
    static zSTRING GetFocusName()              zCall( 0x006BED00 );
    static void StartHighlightningFX( oCNpc* ) zCall( 0x006BF390 );
    static void StopHighlightningFX()          zCall( 0x006BF4C0 );

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

} // namespace Gothic_II_Addon

#endif // __OFOCUS_H__VER3__