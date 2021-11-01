// Supported with union (c) 2018-2021 Union team

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