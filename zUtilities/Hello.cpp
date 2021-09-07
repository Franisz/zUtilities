// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
#if _DEBUG
  int showHelloOnce;
  zCView* showHelloView = NULL;

  string GetEngineVersionName( TEngineVersion version ) {
    switch ( version ) {
    case Engine_G1:  return "Gothic I Classic";
    case Engine_G1A: return "Gothic I Addon";
    case Engine_G2:  return "Gothic II Classic";
    case Engine_G2A: return "Gothic II Addon";
    }
    return "Unknown";
  }

  void showHello() {
    if ( showHelloOnce ) return;

    if ( !showHelloView )
      screen->InsertItem( showHelloView = zNEW( zCView )(0, 0, 8192, 8192) );

    // We get a pointer to the current plugin and get its name
    const CPlugin* plugin = CPlugin::GetCurrentPlugin();
    string pluginFileName = plugin->GetName();

    // Get the instance version of the union and convert it to a text string.
    TVersion unionVersion = Union.GetUnionVersion();
    string unionVersionName = unionVersion.ToString();

    // Get the version of the engine and its name
    TEngineVersion engineVersion = Union.GetEngineVersion();
    string engineVersionName = GetEngineVersionName( engineVersion );

    // Show a message on the screen
    showHelloView->PrintTimedCX( 1000, pluginFileName + " loaded to " + engineVersionName + " running on Union " + unionVersionName, 4000, &zCOLOR( 255, 100, 0 ) );
    showHelloOnce = true;
  }
#endif
}