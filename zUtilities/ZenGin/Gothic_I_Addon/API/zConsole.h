// Supported with union (c) 2018-2021 Union team

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

  // sizeof 3Ch
  class zCConDat {
  public:
    zSTRING hint;   // sizeof 14h    offset 00h
    zSTRING name;   // sizeof 14h    offset 14h
    int type;       // sizeof 04h    offset 28h
    void* adr;      // sizeof 04h    offset 2Ch
    int ele;        // sizeof 04h    offset 30h
    int var;        // sizeof 04h    offset 34h
    zCConDat* next; // sizeof 04h    offset 38h

    zCConDat() {}
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x00710350 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x00710560 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x007149C0 );

    // user API
    #include "zCConDat.inl"
  };

  // sizeof E0h
  class zCConsole : public zCInputCallback {
  public:
    zSTRING id;                                                        // sizeof 14h    offset 04h
    zSTRING instr;                                                     // sizeof 14h    offset 18h
    zSTRING savemsg;                                                   // sizeof 14h    offset 2Ch
    zSTRING lastcommand;                                               // sizeof 14h    offset 40h
    int px;                                                            // sizeof 04h    offset 54h
    int py;                                                            // sizeof 04h    offset 58h
    int lx;                                                            // sizeof 04h    offset 5Ch
    int ly;                                                            // sizeof 04h    offset 60h
    int showmax;                                                       // sizeof 04h    offset 64h
    int skip;                                                          // sizeof 04h    offset 68h
    int dynsize;                                                       // sizeof 04h    offset 6Ch
    int var;                                                           // sizeof 04h    offset 70h
    int autocomplete;                                                  // sizeof 04h    offset 74h
    zList<zCConDat> list;                                              // sizeof 10h    offset 78h
    zCView* conview;                                                   // sizeof 04h    offset 88h
    int evalcount;                                                     // sizeof 04h    offset 8Ch
    int( *evalfunc[zCON_MAX_EVAL] )( const zSTRING &s, zSTRING &msg ); // sizeof 3Ch    offset 90h
    void( *changedfunc )( const zSTRING &s );                          // sizeof 04h    offset CCh
    zCWorld* world;                                                    // sizeof 04h    offset D0h
    zCParser* cparser;                                                 // sizeof 04h    offset D4h
    int edit_index;                                                    // sizeof 04h    offset D8h
    void* edit_adr;                                                    // sizeof 04h    offset DCh

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