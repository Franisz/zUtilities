// Supported with union (c) 2018 Union team

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
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int, void*, int )    zCall( 0x006D8780 );
    void zCConDat_OnInit( zSTRING const&, zSTRING const&, int )                zCall( 0x006D89A0 );
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2, void* a3, int a4 ) zInit( zCConDat_OnInit( a0, a1, a2, a3, a4 ));
    zCConDat( zSTRING const& a0, zSTRING const& a1, int a2 )                   zInit( zCConDat_OnInit( a0, a1, a2 ));
    ~zCConDat()                                                                zCall( 0x006DC850 );

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