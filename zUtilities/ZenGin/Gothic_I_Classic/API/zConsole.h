// Supported with union (c) 2018-2021 Union team

#ifndef __ZCONSOLE_H__VER0__
#define __ZCONSOLE_H__VER0__

#include "zViewBase.h"
#include "zView.h"

namespace Gothic_I_Classic {
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
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x006D8780 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x006D89A0 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x006DC850 );

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

    void zCConsole_OnInit()                                           zCall( 0x006D8CC0 );
    void zCConsole_OnInit( int, int, zSTRING const& )                 zCall( 0x006D8F00 );
    zCConsole()                                                       zInit( zCConsole_OnInit() );
    zCConsole( int a0, int a1, zSTRING const& a2 )                    zInit( zCConsole_OnInit( a0, a1, a2 ));
    ~zCConsole()                                                      zCall( 0x006D9070 );
    void SetAutoCompletion( int )                                     zCall( 0x006D9210 );
    int HasAutoCompletion()                                           zCall( 0x006D9220 );
    void SetWorld( zCWorld* )                                         zCall( 0x006D9230 );
    zCWorld* GetWorld()                                               zCall( 0x006D9240 );
    void SetParser( zCParser* )                                       zCall( 0x006D9250 );
    zCParser* GetParser()                                             zCall( 0x006D9260 );
    void AddChar( int, int )                                          zCall( 0x006D9270 );
    void InsertVar( zSTRING const&, zSTRING const&, int, void*, int ) zCall( 0x006D96C0 );
    void Register( zSTRING const&, zSTRING const&, int )              zCall( 0x006D9810 );
    void Register( zSTRING const&, zSTRING const& )                   zCall( 0x006D9940 );
    int AutoCompletion( zSTRING& )                                    zCall( 0x006D9A70 );
    void SetFocus()                                                   zCall( 0x006DA1F0 );
    void RemoveFocus()                                                zCall( 0x006DA220 );
    void Show()                                                       zCall( 0x006DA2D0 );
    void Hide()                                                       zCall( 0x006DA530 );
    void Toggle()                                                     zCall( 0x006DA620 );
    int IsVisible()                                                   zCall( 0x006DA710 );
    void AddSkip( int )                                               zCall( 0x006DA730 );
    void Update()                                                     zCall( 0x006DA760 );
    void ShowInput()                                                  zCall( 0x006DACF0 );
    zCConDat* Get( zSTRING const& )                                   zCall( 0x006DAE70 );
    zCConDat* GetBestMatch( zSTRING const& )                          zCall( 0x006DB020 );
    void Eval( zSTRING const& )                                       zCall( 0x006DB220 );
    int Evaluate( zSTRING const& )                                    zCall( 0x006DB5D0 );
    void SetPos( int, int )                                           zCall( 0x006DBC50 );
    void SetDim( int, int )                                           zCall( 0x006DBC70 );
    void SetFlags( int )                                              zCall( 0x006DBC90 );
    void AddEvalFunc( int( __cdecl* )( zSTRING const&, zSTRING& ))    zCall( 0x006DBCA0 );
    void SetChangedFunc( void( __cdecl* )( zSTRING const& ))          zCall( 0x006DBCD0 );
    void ShowHelp()                                                   zCall( 0x006DBCE0 );
    void SaveInfoFile( zSTRING const& )                               zCall( 0x006DBF20 );
    int EditInstance( zSTRING const&, void* )                         zCall( 0x006DC390 );
    int EditInstance( int, void* )                                    zCall( 0x006DC3C0 );
    static int EditFunc( zSTRING const&, zSTRING& )                   zCall( 0x006DC190 );
    virtual int HandleEvent( int )                                    zCall( 0x006D8BA0 );

    // static properties
    static zCList<zCConsole>& active_consoles;
    static zCConsole*& cur_console;

    // user API
    #include "zCConsole.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCONSOLE_H__VER0__