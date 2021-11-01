// Supported with union (c) 2018-2021 Union team

#ifndef __ZCONSOLE_H__VER3__
#define __ZCONSOLE_H__VER3__

#include "zViewBase.h"

namespace Gothic_II_Addon {
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
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x00781990 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x00781BB0 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x00785B20 );

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

    void zCConsole_OnInit()                                           zCall( 0x00781EA0 );
    void zCConsole_OnInit( int, int, zSTRING const& )                 zCall( 0x007820B0 );
    zCConsole()                                                       zInit( zCConsole_OnInit() );
    zCConsole( int a0, int a1, zSTRING const& a2 )                    zInit( zCConsole_OnInit( a0, a1, a2 ));
    ~zCConsole()                                                      zCall( 0x00782200 );
    void SetAutoCompletion( int )                                     zCall( 0x007823B0 );
    int HasAutoCompletion()                                           zCall( 0x007823C0 );
    void SetWorld( zCWorld* )                                         zCall( 0x007823D0 );
    zCWorld* GetWorld()                                               zCall( 0x007823E0 );
    void SetParser( zCParser* )                                       zCall( 0x007823F0 );
    zCParser* GetParser()                                             zCall( 0x00782400 );
    void AddChar( int, int )                                          zCall( 0x00782410 );
    void InsertVar( zSTRING const&, zSTRING const&, int, void*, int ) zCall( 0x00782890 );
    void Register( zSTRING const&, zSTRING const&, int )              zCall( 0x007829C0 );
    void Register( zSTRING const&, zSTRING const& )                   zCall( 0x00782AE0 );
    int AutoCompletion( zSTRING& )                                    zCall( 0x00782C00 );
    void SetFocus()                                                   zCall( 0x00783380 );
    void RemoveFocus()                                                zCall( 0x007833B0 );
    void Show()                                                       zCall( 0x00783460 );
    void Hide()                                                       zCall( 0x007836B0 );
    void Toggle()                                                     zCall( 0x007837A0 );
    int IsVisible()                                                   zCall( 0x00783890 );
    void AddSkip( int )                                               zCall( 0x007838B0 );
    void Update()                                                     zCall( 0x007838E0 );
    void ShowInput()                                                  zCall( 0x00783F80 );
    zCConDat* Get( zSTRING const& )                                   zCall( 0x00784100 );
    zCConDat* GetBestMatch( zSTRING const& )                          zCall( 0x007842B0 );
    void Eval( zSTRING const& )                                       zCall( 0x007844B0 );
    int Evaluate( zSTRING const& )                                    zCall( 0x00784860 );
    void SetPos( int, int )                                           zCall( 0x00784F30 );
    void SetDim( int, int )                                           zCall( 0x00784F50 );
    void SetFlags( int )                                              zCall( 0x00784F70 );
    void AddEvalFunc( int( __cdecl* )( zSTRING const&, zSTRING& ))    zCall( 0x00784F80 );
    void SetChangedFunc( void( __cdecl* )( zSTRING const& ))          zCall( 0x00784FB0 );
    void ShowHelp()                                                   zCall( 0x00784FC0 );
    void SaveInfoFile( zSTRING const& )                               zCall( 0x00785200 );
    int EditInstance( zSTRING const&, void* )                         zCall( 0x00785670 );
    int EditInstance( int, void* )                                    zCall( 0x007856A0 );
    static int EditFunc( zSTRING const&, zSTRING& )                   zCall( 0x00785470 );
    virtual int HandleEvent( int )                                    zCall( 0x00781DB0 );

    // static properties
    static zCList<zCConsole>& active_consoles;
    static zCConsole*& cur_console;

    // user API
    #include "zCConsole.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCONSOLE_H__VER3__