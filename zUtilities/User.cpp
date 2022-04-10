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

    if ( nextLine.StartWith( "; " + trivia ) )
      return;

    if ( nextLine.StartWith( "; " ) ) {
      section->entryList[nextPos] = triviaEntry;
      return;
    }

    section->entryList.InsertAtPos( triviaEntry, nextPos );
  }
}