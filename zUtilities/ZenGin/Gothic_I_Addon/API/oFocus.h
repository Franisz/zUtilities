// Supported with union (c) 2018-2021 Union team

#ifndef __OFOCUS_H__VER1__
#define __OFOCUS_H__VER1__

namespace Gothic_I_Addon {
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

    void oCNpcFocus_OnInit()           zCall( 0x0065B1B0 );
    oCNpcFocus()                       zInit( oCNpcFocus_OnInit() );
    ~oCNpcFocus()                      zCall( 0x0065B1D0 );
    void Init( zSTRING& )              zCall( 0x0065B1E0 );
    void Init( int )                   zCall( 0x0065B210 );
    int IsValid( int )                 zCall( 0x0065B2C0 );
    float GetMaxRange()                zCall( 0x0065B310 );
    float GetRange2()                  zCall( 0x0065B320 );
    float GetItemThrowRange()          zCall( 0x0065B330 );
    float GetMobThrowRange()           zCall( 0x0065B340 );
    int HasLowerPriority( int, int )   zCall( 0x0065B350 );
    int GetPriority( int )             zCall( 0x0065B3D0 );
    int IsInRange( int, float )        zCall( 0x0065B410 );
    int IsInAngle( int, float, float ) zCall( 0x0065B4A0 );
    int IsNpcInRange( float )          zCall( 0x0065B580 );
    int IsNpcInAngle( float, float )   zCall( 0x0065B5D0 );
    int IsItemInRange( float )         zCall( 0x0065B620 );
    int IsItemInAngle( float, float )  zCall( 0x0065B650 );
    int IsMobInRange( float )          zCall( 0x0065B6A0 );
    int IsMobInAngle( float, float )   zCall( 0x0065B6D0 );
    float GetAzi()                     zCall( 0x0065B720 );
    static void InitFocusModes()       zCall( 0x0065AE80 );
    static void ExitFocusModes()       zCall( 0x0065AFB0 );
    static void SetFocusMode( int )    zCall( 0x0065AFF0 );
    static zSTRING GetFocusName()      zCall( 0x0065B0D0 );

    // static properties
    static oCNpcFocus*& focus;
    static oCNpcFocus**& focuslist;

    // user API
    #include "oCNpcFocus.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OFOCUS_H__VER1__