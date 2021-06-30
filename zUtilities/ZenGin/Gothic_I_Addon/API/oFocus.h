// Supported with union (c) 2018 Union team

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