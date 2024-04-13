// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void zCOption::AddTrivia( const string sectionName, const string entryName, string trivia ) {
    zCOption* const& option = this;
    zCOptionSection* section = option->GetSectionByName( sectionName, true );

    if ( !section ) return;

    zCOptionEntry* entry = option->GetEntryByName( section, entryName, true );

    if ( !entry ) return;

    zCOptionEntry* triviaEntry = new zCOptionEntry{ "", (A"; " + trivia + "\r\n\n") };

    int nextPos = section->entryList.Search( entry ) + 1;

    if ( nextPos > section->entryList.GetNumInList() - 1 ) {
      section->entryList.InsertEnd( triviaEntry );
      return;
    }

    zSTRING nextLine = section->entryList[nextPos]->varValue;

    if ( nextLine.StartWith( "; " + trivia ) ) {
      delete triviaEntry;
      return;
    }

    if ( nextLine.StartWith( "; " ) ) {
      section->entryList[nextPos] = triviaEntry;
      return;
    }

    section->entryList.InsertAtPos( triviaEntry, nextPos );
  }

  zCOLOR* zCOption::ReadColor( zSTRING const& sectionName, zSTRING const& entryName, char const* text ) {
    Array<string> splitted = (A zoptions->ReadString( sectionName, entryName, text )).Split( "|" );
    Array<int> channels;

    for ( int i = 0; i < splitted.GetNum(); i++ ) {
      splitted[i] = splitted[i].Shrink();
      if ( !splitted[i].IsNumber() ) return nullptr;

      int value = splitted[i].ToInt32();
      if ( value < 0 || value > 255 ) return nullptr;

      channels.Insert( value );
    }

    int size = channels.GetNum();
    if ( size != 3 && size != 4 )
      return nullptr;

    zCOLOR* color = new zCOLOR( channels[CR], channels[CG], channels[CB] );
    if ( size == 4 ) color->alpha = channels[CA];
    return color;
  }
}