// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int ConsoleEval( const zSTRING& command, zSTRING& message )
  {
    zSTRING w1 = command.PickWord_Old( 1, " " );
    zSTRING w2 = command.PickWord_Old( 2, " " );

    if ( w1 != "zUtilities" ) return 0;

    if ( w2 == "Version" ) {
      message = "Currently using zUtilities v" + Z VERSION_NUMBER;
      return 1;
    }

    return 0;
  };

  void RegisterCommands() {
    zcon->Register( "zUtilities Version", "Shows version number" );
    zcon->AddEvalFunc( ConsoleEval );
  }
}