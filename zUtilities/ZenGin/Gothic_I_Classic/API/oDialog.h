// Supported with union (c) 2018-2021 Union team

#ifndef __ODIALOG_H__VER0__
#define __ODIALOG_H__VER0__

#include "zAi.h"

namespace Gothic_I_Classic {

  // sizeof 48h
  class oCAskBox : public zCAIBase {
  public:
    int fadeout;       // sizeof 04h    offset 24h
    int answer;        // sizeof 04h    offset 28h
    int alpha;         // sizeof 04h    offset 2Ch
    zCVob* askvob;     // sizeof 04h    offset 30h
    oCNpc* npc1;       // sizeof 04h    offset 34h
    oCNpc* npc2;       // sizeof 04h    offset 38h
    zCDecal* thumb[3]; // sizeof 0Ch    offset 3Ch

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