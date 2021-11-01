// Supported with union (c) 2018-2021 Union team

#ifndef __ZCONSOLE_H__VER2__
#define __ZCONSOLE_H__VER2__

#include "zViewBase.h"

namespace Gothic_II_Classic {
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
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x00721F50 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x00722170 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x007260E0 );

    // user API
    #include "zCConDat.inl"
  };

  // sizeof DCh
  class zCConsole : public zCInputCallback {
  public:
    zSTRING id;                                                        // sizeof 14h    offset 04h
    zSTRING instr;                                                     // sizeof 14h    offset 18h
    zSTRING savemsg;                                                   // sizeof 14h    offset 2Ch
    zCArray<zSTRING> lastcommand;                                      // sizeof 0Ch    offset 40h
    int lastCommandPos;                                                // sizeof 04h    offset 4Ch
    int px;                                                            // sizeof 04h    offset 50h
    int py;                                                            // sizeof 04h    offset 54h
    int lx;                                                            // sizeof 04h    offset 58h
    int ly;                                                            // sizeof 04h    offset 5Ch
    int showmax;                                                       // sizeof 04h    offset 60h
    int skip;                                                          // sizeof 04h    offset 64h
    int dynsize;                                                       // sizeof 04h    offset 68h
    int var;                                                           // sizeof 04h    offset 6Ch
    int autocomplete;                                                  // sizeof 04h    offset 70h
    zList<zCConDat> list;                                              // sizeof 10h    offset 74h
    zCView* conview;                                                   // sizeof 04h    offset 84h
    int evalcount;                                                     // sizeof 04h    offset 88h
    int( *evalfunc[zCON_MAX_EVAL] )( const zSTRING &s, zSTRING &msg ); // sizeof 3Ch    offset 8Ch
    void( *changedfunc )( const zSTRING &s );                          // sizeof 04h    offset C8h
    zCWorld* world;                                                    // sizeof 04h    offset CCh
    zCParser* cparser;                                                 // sizeof 04h    offset D0h
    int edit_index;                                                    // sizeof 04h    offset D4h
    void* edit_adr;                                                    // sizeof 04h    offset D8h

    void zCConsole_OnInit()                                           zCall( 0x00722460 );
    void zCConsole_OnInit( int, int, zSTRING const& )                 zCall( 0x00722670 );
    zCConsole()                                                       zInit( zCConsole_OnInit() );
    zCConsole( int a0, int a1, zSTRING const& a2 )                    zInit( zCConsole_OnInit( a0, a1, a2 ));
    ~zCConsole()                                                      zCall( 0x007227C0 );
    void SetAutoCompletion( int )                                     zCall( 0x00722970 );
    int HasAutoCompletion()                                           zCall( 0x00722980 );
    void SetWorld( zCWorld* )                                         zCall( 0x00722990 );
    zCWorld* GetWorld()                                               zCall( 0x007229A0 );
    void SetParser( zCParser* )                                       zCall( 0x007229B0 );
    zCParser* GetParser()                                             zCall( 0x007229C0 );
    void AddChar( int, int )                                          zCall( 0x007229D0 );
    void InsertVar( zSTRING const&, zSTRING const&, int, void*, int ) zCall( 0x00722E50 );
    void Register( zSTRING const&, zSTRING const&, int )              zCall( 0x00722F80 );
    void Register( zSTRING const&, zSTRING const& )                   zCall( 0x007230A0 );
    int AutoCompletion( zSTRING& )                                    zCall( 0x007231C0 );
    void SetFocus()                                                   zCall( 0x00723940 );
    void RemoveFocus()                                                zCall( 0x00723970 );
    void Show()                                                       zCall( 0x00723A20 );
    void Hide()                                                       zCall( 0x00723C70 );
    void Toggle()                                                     zCall( 0x00723D60 );
    int IsVisible()                                                   zCall( 0x00723E50 );
    void AddSkip( int )                                               zCall( 0x00723E70 );
    void Update()                                                     zCall( 0x00723EA0 );
    void ShowInput()                                                  zCall( 0x00724540 );
    zCConDat* Get( zSTRING const& )                                   zCall( 0x007246C0 );
    zCConDat* GetBestMatch( zSTRING const& )                          zCall( 0x00724870 );
    void Eval( zSTRING const& )                                       zCall( 0x00724A70 );
    int Evaluate( zSTRING const& )                                    zCall( 0x00724E20 );
    void SetPos( int, int )                                           zCall( 0x007254F0 );
    void SetDim( int, int )                                           zCall( 0x00725510 );
    void SetFlags( int )                                              zCall( 0x00725530 );
    void AddEvalFunc( int( __cdecl* )( zSTRING const&, zSTRING& ))    zCall( 0x00725540 );
    void SetChangedFunc( void( __cdecl* )( zSTRING const& ))          zCall( 0x00725570 );
    void ShowHelp()                                                   zCall( 0x00725580 );
    void SaveInfoFile( zSTRING const& )                               zCall( 0x007257C0 );
    int EditInstance( zSTRING const&, void* )                         zCall( 0x00725C30 );
    int EditInstance( int, void* )                                    zCall( 0x00725C60 );
    static int EditFunc( zSTRING const&, zSTRING& )                   zCall( 0x00725A30 );
    virtual int HandleEvent( int )                                    zCall( 0x00722370 );

    // static properties
    static zCList<zCConsole>& active_consoles;
    static zCConsole*& cur_console;

    // user API
    #include "zCConsole.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCONSOLE_H__VER2__