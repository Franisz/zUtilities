// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int (*innerEvalFunc)(const zSTRING&, zSTRING&);

  int ConsoleEvalFunc( const zSTRING& inpstr, zSTRING& msg ) {
    if ( innerEvalFunc && innerEvalFunc( inpstr, msg ) )
      return true;

    zSTRING w1 = inpstr.PickWord_Old( 1, " " );
    if ( w1 != "zUtilities" ) return false;

    zSTRING w2 = inpstr.PickWord_Old( 2, " " );
    if ( w2 == "Version" ) {
      msg = "Currently using zUtilities v" + Z VERSION_NUMBER;
      return true;
    }

    return false;
  }

  void RegisterEvalFunc() {
    int evalNum = 0;

    for ( int i = 1; i < zCON_MAX_EVAL; i++ )
      if ( zcon->evalfunc[i] )
        evalNum = i;

    innerEvalFunc = zcon->evalfunc[evalNum];
    zcon->evalfunc[evalNum] = &ConsoleEvalFunc;
  }

  void RegisterCommands() {
    RegisterEvalFunc();
    zcon->Register( "zUtilities Version", "Shows version number" );
  }
}