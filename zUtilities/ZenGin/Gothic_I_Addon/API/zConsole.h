// Supported with union (c) 2018 Union team

#ifndef __ZCONSOLE_H__VER1__
#define __ZCONSOLE_H__VER1__

#include "zViewBase.h"

namespace Gothic_I_Addon {
  const int zCON_MAX_EVAL = 15;

  enum {
    zCON_TYPE_INT,
    zCON_TYPE_FLOAT,
    zCON_TYPE_STRING,
    zCON_TYPE_STRINGP
  };

  class zCConDat {
  public:
    zSTRING hint;
    zSTRING name;
    int type;
    void* adr;
    int ele;
    int var;
    zCConDat* next;

    zCConDat() {}
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x00710350 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x00710560 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x007149C0 );

    // user API
    #include "zCConDat.inl"
  };

  class zCConsole : public zCInputCallback {
  public:
    zSTRING id;
    zSTRING instr;
    zSTRING savemsg;
    zSTRING lastcommand;
    int px;
    int py;
    int lx;
    int ly;
    int showmax;
    int skip;
    int dynsize;
    int var;
    int autocomplete;
    zList<zCConDat> list;
    zCView* conview;
    int evalcount;
    int( *evalfunc[zCON_MAX_EVAL] )( const zSTRING &s, zSTRING &msg );
    void( *changedfunc )( const zSTRING &s );
    zCWorld* world;
    zCParser* cparser;
    int edit_index;
    void* edit_adr;

    void zCConsole_OnInit()                                           zCall( 0x00710880 );
    void zCConsole_OnInit( int, int, zSTRING const& )                 zCall( 0x00710AD0 );
    zCConsole()                                                       zInit( zCConsole_OnInit() );
    zCConsole( int a0, int a1, zSTRING const& a2 )                    zInit( zCConsole_OnInit( a0, a1, a2 ));
    ~zCConsole()                                                      zCall( 0x00710C40 );
    void SetAutoCompletion( int )                                     zCall( 0x00710E20 );
    int HasAutoCompletion()                                           zCall( 0x00710E30 );
    void SetWorld( zCWorld* )                                         zCall( 0x00710E40 );
    zCWorld* GetWorld()                                               zCall( 0x00710E50 );
    void SetParser( zCParser* )                                       zCall( 0x00710E60 );
    zCParser* GetParser()                                             zCall( 0x00710E70 );
    void AddChar( int, int )                                          zCall( 0x00710E80 );
    void InsertVar( zSTRING const&, zSTRING const&, int, void*, int ) zCall( 0x00711310 );
    void Register( zSTRING const&, zSTRING const&, int )              zCall( 0x00711480 );
    void Register( zSTRING const&, zSTRING const& )                   zCall( 0x007115D0 );
    int AutoCompletion( zSTRING& )                                    zCall( 0x00711720 );
    void SetFocus()                                                   zCall( 0x00711FF0 );
    void RemoveFocus()                                                zCall( 0x00712020 );
    void Show()                                                       zCall( 0x007120D0 );
    void Hide()                                                       zCall( 0x00712350 );
    void Toggle()                                                     zCall( 0x00712430 );
    int IsVisible()                                                   zCall( 0x00712520 );
    void AddSkip( int )                                               zCall( 0x00712540 );
    void Update()                                                     zCall( 0x00712580 );
    void ShowInput()                                                  zCall( 0x00712BF0 );
    zCConDat* Get( zSTRING const& )                                   zCall( 0x00712D80 );
    zCConDat* GetBestMatch( zSTRING const& )                          zCall( 0x00712F60 );
    void Eval( zSTRING const& )                                       zCall( 0x007131B0 );
    int Evaluate( zSTRING const& )                                    zCall( 0x007135D0 );
    void SetPos( int, int )                                           zCall( 0x00713C90 );
    void SetDim( int, int )                                           zCall( 0x00713CB0 );
    void SetFlags( int )                                              zCall( 0x00713CD0 );
    void AddEvalFunc( int( __cdecl* )( zSTRING const&, zSTRING& ))    zCall( 0x00713CF0 );
    void SetChangedFunc( void( __cdecl* )( zSTRING const& ))          zCall( 0x00713D20 );
    void ShowHelp()                                                   zCall( 0x00713D30 );
    void SaveInfoFile( zSTRING const& )                               zCall( 0x00713F90 );
    int EditInstance( zSTRING const&, void* )                         zCall( 0x00714470 );
    int EditInstance( int, void* )                                    zCall( 0x007144A0 );
    static int EditFunc( zSTRING const&, zSTRING& )                   zCall( 0x00714250 );
    virtual int HandleEvent( int )                                    zCall( 0x00710760 );

    // static properties
    static zCList<zCConsole>& active_consoles;
    static zCConsole*& cur_console;

    // user API
    #include "zCConsole.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCONSOLE_H__VER1__