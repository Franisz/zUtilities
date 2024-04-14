// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  int zCArchiver::ReadIntSafe(char const *text)
  {
    zFILE *file = this->GetFile();
    if (!file)
      return Invalid;

    const long file_pos = file->Pos();
    const bool notValid = !file->SeekText(text).Length();

    file->Seek(file_pos);

    if (notValid)
      return Invalid;

    return this->ReadInt(text);
  }

  void Archive()
  {
    auto path = GetArchivePath(PLUGIN_NAME);
    zCArchiver *ar = zarcFactory->CreateArchiverWrite(GetArchivePath(PLUGIN_NAME), zARC_MODE_ASCII, 0, 0);
    if (!ar)
      return;

    playerStatus->Archive(ar);
    logBook->Archive(ar);

    ar->Close();
    ar->Release();
  }

  void Unarchive()
  {
    auto path = GetArchivePath(PLUGIN_NAME);

    zCArchiver *ar = zarcFactory->CreateArchiverRead(path, 0);

    playerStatus->Unarchive(ar);
    logBook->Unarchive(ar);

    if (!ar)
      return;

    ar->Close();
    ar->Release();
  }
}