// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  float CoerceInRange( float start, float length, float minValue, float maxValue ) {
    start -= max( 0, start + length - maxValue );
    start += max( 0, minValue - start );
    return start;
  }

  bool Intersects( const tagRECT& a, const tagRECT& b ) {
    return (a.left <= b.right &&
      b.left <= a.right &&
      a.top <= b.bottom &&
      b.top <= a.bottom);
  }

  string GetSlotNameByID( uint ID ) {
    if ( ID > 0 )
      return "savegame" + A ID;

    if ( ID == 0 )
      return "quicksave";

    return "current";
  }

  string GetArchivePath( string sav ) {
    int slotID = SaveLoadGameInfo.slotID;
    string savesDir = zoptions->GetDirString( zTOptionPaths::DIR_SAVEGAMES );
    string slotDir = GetSlotNameByID( SaveLoadGameInfo.slotID );
    string archivePath = string::Combine( "%s\\%s\\%s\.sav", savesDir, slotDir, sav );
    return archivePath;
  }
}