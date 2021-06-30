// Supported with union (c) 2018 Union team

#ifndef __ODIALOG_H__VER3__
#define __ODIALOG_H__VER3__

#include "zAi.h"

namespace Gothic_II_Addon {

  class oCAskBox : public zCAIBase {
  public:
    int fadeout;
    int answer;
    int alpha;
    zCVob* askvob;
    oCNpc* npc1;
    oCNpc* npc2;
    zCDecal* thumb[3];

    void oCAskBox_OnInit()            zCall( 0x006BBC80 );
    oCAskBox()                        zInit( oCAskBox_OnInit() );
    void Init( oCNpc*, oCNpc* )       zCall( 0x006BBE70 );
    void Delete()                     zCall( 0x006BC140 );
    void SetNeutral()                 zCall( 0x006BC2F0 );
    void SetYes()                     zCall( 0x006BC3F0 );
    void SetNo()                      zCall( 0x006BC4F0 );
    void SetPosition()                zCall( 0x006BC5F0 );
    virtual ~oCAskBox()               zCall( 0x006BBDF0 );
    virtual void DoAI( zCVob*, int& ) zCall( 0x006BC150 );

    // user API
    #include "oCAskBox.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ODIALOG_H__VER3__