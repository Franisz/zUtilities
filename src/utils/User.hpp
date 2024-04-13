// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  void zCOption::AddTrivia(zSTRING sectionName, zSTRING entryName, zSTRING trivia)
  {
    zCOption *const &option = this;
    zCOptionSection *section = option->GetSectionByName(sectionName, true);

    if (!section)
      return;

    zCOptionEntry *entry = option->GetEntryByName(section, entryName, true);

    if (!entry)
      return;

    zCOptionEntry *triviaEntry = new zCOptionEntry{zSTRING(""), zSTRING(Union::StringANSI::Format(": {}\r\n\n", trivia))};

    int nextPos = section->entryList.Search(entry) + 1;

    if (nextPos > section->entryList.GetNumInList() - 1)
    {
      section->entryList.InsertEnd(triviaEntry);
      return;
    }

    zSTRING nextLine = section->entryList[nextPos]->varValue;

    if (Union::StringANSI(nextLine).StartsWith("; " + trivia))
    {
      delete triviaEntry;
      return;
    }

    if (Union::StringANSI(nextLine).StartsWith("; "))
    {
      section->entryList[nextPos] = triviaEntry;
      return;
    }

    section->entryList.InsertAtPos(triviaEntry, nextPos);
  }

  zCOLOR *zCOption::ReadColor(zSTRING const &sectionName, zSTRING const &entryName, char const *text)
  {
    auto splitted = Union::StringANSI(zoptions->ReadString(sectionName, entryName, text)).Split("|");
    Union::Array<int> channels;

    for (int i = 0; i < splitted.GetCount(); i++)
    {
      splitted[i].ShrinkToFit();
      if (!splitted[i].IsIntegerDigit())
        return nullptr;

      int value = splitted[i].ConvertToInt();
      if (value < 0 || value > 255)
        return nullptr;

      channels.Insert(value);
    }

    int size = channels.GetCount();
    if (size != 3 && size != 4)
      return nullptr;

    zCOLOR *color = new zCOLOR(channels[CR], channels[CG], channels[CB]);
    if (size == 4)
      color->alpha = channels[CA];
    return color;
  }
}