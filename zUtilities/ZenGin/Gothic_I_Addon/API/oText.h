// Supported with union (c) 2018 Union team

#ifndef __OTEXT_H__VER1__
#define __OTEXT_H__VER1__

#include "zParser.h"

namespace Gothic_I_Addon {

  class oCText {
  public:

    oCText() {}
    static void InitText() zCall( 0x00708AC0 );

    // static properties
    static zCView*& output;
    static int& TXT_GUILD;
    static int& TXT_ATTRIBUTE;
    static int& TXT_FIGHT_TALENT;
    static int& TXT_TALENT;
    static int& TXT_DAYTIME;
    static int*& TXT_ATR;
    static int& TXT_ATR_HP;
    static int& TXT_SPELL;
    static int& TXT_ATTITUDE;
    static int& TXT_PC_GREETING;
    static int& TXT_PC_FIRST_PHRASE;
    static int& TXT_PC_SECOND_PHRASE;
    static int& TXT_PC_TRADE_PHRASE;
    static int& TXT_NPC_LAST_PHRASE;
    static int& TXT_PC_TRADE_THREAT;
    static int& TXT_NPC_TRADE_THREAT;
    static int& TXT_PC_INFO_THREAT;
    static int& TXT_NPC_INFO_THREAT;
    static int& TXT_NEWS_INTRO;
    static int& TXT_NEWS_STOLE;
    static int& TXT_NEWS_STOLE_10;
    static int& TXT_NEWS_STOLE_30;
    static int& TXT_NEWS_STOLE_50;
    static int& TXT_NEWS_STOLE_70;
    static int& TXT_NEWS_STOLE_90;
    static int& TXT_NEWS_STOLE_100;
    static int& TXT_NEWS_ATTACKED;
    static int& TXT_NEWS_KILLED;
    static int& TXT_YNEWS_INTRO;
    static int& TXT_YNEWS_STOLE;
    static int& TXT_YNEWS_STOLE_10;
    static int& TXT_YNEWS_STOLE_30;
    static int& TXT_YNEWS_STOLE_50;
    static int& TXT_YNEWS_STOLE_70;
    static int& TXT_YNEWS_STOLE_90;
    static int& TXT_YNEWS_STOLE_100;
    static int& TXT_YNEWS_ATTACKED;
    static int& TXT_YNEWS_KILLED;
    static int& TXT_INTIMIDATION;
    static int& TXT_INVCAT;
    static int& TXT_HELP;

    // user API
    #include "oCText.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OTEXT_H__VER1__