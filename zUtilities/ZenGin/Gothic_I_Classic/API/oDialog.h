// Supported with union (c) 2018 Union team

#ifndef __ODIALOG_H__VER0__
#define __ODIALOG_H__VER0__

#include "zAi.h"

namespace Gothic_I_Classic {

  class oCAskBox : public zCAIBase {
  public:
    int fadeout;
    int answer;
    int alpha;
    zCVob* askvob;
    oCNpc* npc1;
    oCNpc* npc2;
    zCDecal* thumb[3];

    void oCAskBox_OnInit()            zCall( 0x006322E0 );
    oCAskBox()                        zInit( oCAskBox_OnInit() );
    void Init( oCNpc*, oCNpc* )       zCall( 0x006324D0 );
    void Delete()                     zCall( 0x006327B0 );
    void SetNeutral()                 zCall( 0x00632960 );
    void SetYes()                     zCall( 0x00632A60 );
    void SetNo()                      zCall( 0x00632B60 );
    void SetPosition()                zCall( 0x00632C60 );
    virtual ~oCAskBox()               zCall( 0x00632450 );
    virtual void DoAI( zCVob*, int& ) zCall( 0x006327C0 );

    // user API
    #include "oCAskBox.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ODIALOG_H__VER0__