// Supported with union (c) 2018-2021 Union team

#ifndef __ODIALOG_H__VER1__
#define __ODIALOG_H__VER1__

#include "zAi.h"

namespace Gothic_I_Addon {

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