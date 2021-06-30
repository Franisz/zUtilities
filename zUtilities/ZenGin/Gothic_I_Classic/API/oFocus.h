// Supported with union (c) 2018 Union team

#ifndef __OFOCUS_H__VER0__
#define __OFOCUS_H__VER0__

namespace Gothic_I_Classic {
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

    void oCNpcFocus_OnInit()           zCall( 0x00635010 );
    oCNpcFocus()                       zInit( oCNpcFocus_OnInit() );
    ~oCNpcFocus()                      zCall( 0x00635030 );
    void Init( zSTRING& )              zCall( 0x00635040 );
    void Init( int )                   zCall( 0x00635070 );
    int IsValid( int )                 zCall( 0x00635120 );
    float GetMaxRange()                zCall( 0x00635170 );
    float GetRange2()                  zCall( 0x00635180 );
    float GetItemThrowRange()          zCall( 0x00635190 );
    float GetMobThrowRange()           zCall( 0x006351A0 );
    int HasLowerPriority( int, int )   zCall( 0x006351B0 );
    int GetPriority( int )             zCall( 0x00635230 );
    int IsInRange( int, float )        zCall( 0x00635270 );
    int IsInAngle( int, float, float ) zCall( 0x00635300 );
    int IsNpcInRange( float )          zCall( 0x006353E0 );
    int IsNpcInAngle( float, float )   zCall( 0x00635430 );
    int IsItemInRange( float )         zCall( 0x00635480 );
    int IsItemInAngle( float, float )  zCall( 0x006354B0 );
    int IsMobInRange( float )          zCall( 0x00635500 );
    int IsMobInAngle( float, float )   zCall( 0x00635530 );
    float GetAzi()                     zCall( 0x00635580 );
    static void InitFocusModes()       zCall( 0x00634CF0 );
    static void ExitFocusModes()       zCall( 0x00634E20 );
    static void SetFocusMode( int )    zCall( 0x00634E60 );
    static zSTRING GetFocusName()      zCall( 0x00634F40 );

    // static properties
    static oCNpcFocus*& focus;
    static oCNpcFocus**& focuslist;

    // user API
    #include "oCNpcFocus.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OFOCUS_H__VER0__