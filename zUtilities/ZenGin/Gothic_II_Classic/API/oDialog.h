// Supported with union (c) 2018-2021 Union team

#ifndef __ODIALOG_H__VER2__
#define __ODIALOG_H__VER2__

#include "zAi.h"

namespace Gothic_II_Classic {

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

    void oCAskBox_OnInit()            zCall( 0x0065F2F0 );
    oCAskBox()                        zInit( oCAskBox_OnInit() );
    void Init( oCNpc*, oCNpc* )       zCall( 0x0065F4E0 );
    void Delete()                     zCall( 0x0065F7B0 );
    void SetNeutral()                 zCall( 0x0065F960 );
    void SetYes()                     zCall( 0x0065FA60 );
    void SetNo()                      zCall( 0x0065FB60 );
    void SetPosition()                zCall( 0x0065FC60 );
    virtual ~oCAskBox()               zCall( 0x0065F460 );
    virtual void DoAI( zCVob*, int& ) zCall( 0x0065F7C0 );

    // user API
    #include "oCAskBox.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ODIALOG_H__VER2__