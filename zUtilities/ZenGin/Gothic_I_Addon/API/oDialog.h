// Supported with union (c) 2018 Union team

#ifndef __ODIALOG_H__VER1__
#define __ODIALOG_H__VER1__

#include "zAi.h"

namespace Gothic_I_Addon {

  class oCAskBox : public zCAIBase {
  public:
    int fadeout;
    int answer;
    int alpha;
    zCVob* askvob;
    oCNpc* npc1;
    oCNpc* npc2;
    zCDecal* thumb[3];

    void oCAskBox_OnInit()            zCall( 0x006580A0 );
    oCAskBox()                        zInit( oCAskBox_OnInit() );
    void Init( oCNpc*, oCNpc* )       zCall( 0x006582B0 );
    void Delete()                     zCall( 0x00658520 );
    void SetNeutral()                 zCall( 0x006586F0 );
    void SetYes()                     zCall( 0x00658810 );
    void SetNo()                      zCall( 0x00658930 );
    void SetPosition()                zCall( 0x00658A50 );
    virtual ~oCAskBox()               zCall( 0x00658220 );
    virtual void DoAI( zCVob*, int& ) zCall( 0x00658530 );

    // user API
    #include "oCAskBox.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ODIALOG_H__VER1__