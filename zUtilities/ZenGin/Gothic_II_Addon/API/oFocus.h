// Supported with union (c) 2018-2021 Union team

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

  // sizeof 50h
  class oCNpcFocus {
  public:
    group {
      float n_range3;  // sizeof 04h    offset 00h
      float n_range1;  // sizeof 04h    offset 04h
      float n_range2;  // sizeof 04h    offset 08h
      float n_azi;     // sizeof 04h    offset 0Ch
      float n_elev1;   // sizeof 04h    offset 10h
      float n_elev2;   // sizeof 04h    offset 14h
      int n_prio;      // sizeof 04h    offset 18h
      float i_range1;  // sizeof 04h    offset 1Ch
      float i_range2;  // sizeof 04h    offset 20h
      float i_azi;     // sizeof 04h    offset 24h
      float i_elev1;   // sizeof 04h    offset 28h
      float i_elev2;   // sizeof 04h    offset 2Ch
      int i_prio;      // sizeof 04h    offset 30h
      float m_range1;  // sizeof 04h    offset 34h
      float m_range2;  // sizeof 04h    offset 38h
      float m_azi;     // sizeof 04h    offset 3Ch
      float m_elev1;   // sizeof 04h    offset 40h
      float m_elev2;   // sizeof 04h    offset 44h
      int m_prio;      // sizeof 04h    offset 48h
      float max_range; // sizeof 04h    offset 4Ch
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