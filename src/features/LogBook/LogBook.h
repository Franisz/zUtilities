// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  class LogBook
  {
  private:
    zCOLOR *colorOld = {};
    zCArray<zSTRING> unreadTopics = {};
    zCArray<zSTRING> newTopics = {};

    void UpdateColor(zCViewText *view);

  public:
    void UpdateView(zCView *view);
    bool CanColorList(zCMenuItemList *list);
    void AddTopic(oCLogTopic *topic);
    void MarkRead(zSTRING topic);
    void Archive(zCArchiver *ar);
    void Unarchive(zCArchiver *ar);
  };

  std::unique_ptr<LogBook> logBook;
}