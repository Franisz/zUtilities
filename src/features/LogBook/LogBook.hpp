// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{

  void __fastcall oCLogTopic_AddEntry(oCLogTopic *_this, zSTRING const &entry);
  auto Hook_oCLogTopic_AddEntry = CreateHook(reinterpret_cast<void *>(zSwitch(0x0072EA60, 0x0076D0B0, 0x0077A630, 0x00663870)), &oCLogTopic_AddEntry);
  void __fastcall oCLogTopic_AddEntry(oCLogTopic *_this, zSTRING const &entry)
  {
    Hook_oCLogTopic_AddEntry(_this, entry);
    logBook->AddTopic(_this);
  }

  void __fastcall zCMenuItemList_ShowContent(zCMenuItemList *_this);
  auto Hook_zCMenuItemList_ShowContent = CreateHook(reinterpret_cast<void *>(zSwitch(0x004D98A0, 0x004EA9F0, 0x004E4100, 0x004E6AB0)), &zCMenuItemList_ShowContent);
  void __fastcall zCMenuItemList_ShowContent(zCMenuItemList *_this)
  {
    Hook_zCMenuItemList_ShowContent(_this);

    if (!Options::LogBookColoring || !logBook->CanColorList(_this))
      return;

    logBook->MarkRead(_this->m_list[_this->m_cur_element].title);

    // zCMenuItemList::DrawFront function is not called after closing content so color must be updated here
    logBook->UpdateView(_this->m_pInnerWindow);
  }

  void __fastcall zCMenuItemList_DrawFront(zCMenuItemList *_this);
  auto Hook_zCMenuItemList_DrawFront = CreateHook(reinterpret_cast<void *>(zSwitch(0x004D9330, 0x004EA450, 0x004E3BA0, 0x004E6550)), &zCMenuItemList_DrawFront);
  void __fastcall zCMenuItemList_DrawFront(zCMenuItemList *_this)
  {
    Hook_zCMenuItemList_DrawFront(_this);

    if (!Options::LogBookColoring || !logBook->CanColorList(_this))
      return;

    logBook->UpdateView(_this->m_pInnerWindow);
  }

  void LogBook::UpdateView(zCView *view)
  {
    if (!view)
      return;

    auto list = view->textLines.GetNextInList();

    while (list != nullptr)
    {
      auto item = list->GetData();
      list = list->GetNextInList();

      logBook->UpdateColor(item);
    }
  }

  void LogBook::UpdateColor(zCViewText *view)
  {
    if (!colorOld)
      colorOld = new zCOLOR(view->color);

    zSTRING topic = view->text;
    zCOLOR color = *colorOld;

    if (newTopics.IsInList(topic))
      color = zCOLOR(0, 255, 0);
    else if (unreadTopics.IsInList(topic))
      color = zCOLOR(255, 160, 0);

    view->color = color;
    view->colored = true;
  }

  bool LogBook::CanColorList(zCMenuItemList *list)
  {
    return list->id == "MENU_ITEM_LIST_LOG" || list->id == "MENU_ITEM_LIST_MISSIONS_ACT" || list->id == "MENU_ITEM_LIST_MISSIONS_OLD" || list->id == "MENU_ITEM_LIST_MISSIONS_FAILED";
  }

  void LogBook::AddTopic(oCLogTopic *topic)
  {
    if (unreadTopics.IsInList(topic->m_strDescription) || newTopics.IsInList(topic->m_strDescription))
      return;

    if (topic->m_lstEntries.GetNum() == 1)
    {
      newTopics.Insert(topic->m_strDescription);
      return;
    }

    unreadTopics.Insert(topic->m_strDescription);
  }

  void LogBook::MarkRead(zSTRING topic)
  {
    if (unreadTopics.IsInList(topic))
      unreadTopics.Remove(topic);

    if (newTopics.IsInList(topic))
      newTopics.Remove(topic);
  }

  void LogBook::Archive(zCArchiver *ar)
  {
    ar->WriteInt("unreadTopicsCount", unreadTopics.GetNum());
    for (int i = 0; i < unreadTopics.GetNum(); i++)
      ar->WriteString("unreadTopics", unreadTopics[i]);

    ar->WriteInt("newTopicsCount", newTopics.GetNum());
    for (int i = 0; i < newTopics.GetNum(); i++)
      ar->WriteString("newTopics", newTopics[i]);
  }

  void LogBook::Unarchive(zCArchiver *ar)
  {
    unreadTopics.EmptyList();
    newTopics.EmptyList();

    if (!ar)
      return;

    int unreadTopicsCount = ar->ReadIntSafe("unreadTopicsCount");
    for (int i = 0; i < unreadTopicsCount; i++)
      unreadTopics.Insert(ar->ReadString("unreadTopics"));

    int newTopicsCount = ar->ReadIntSafe("newTopicsCount");
    for (int i = 0; i < newTopicsCount; i++)
      newTopics.Insert(ar->ReadString("newTopics"));
  }
}