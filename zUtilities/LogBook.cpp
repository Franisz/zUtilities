// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  HOOK Hook_oCLogTopic_AddEntry PATCH( &oCLogTopic::AddEntry, &oCLogTopic::AddEntry_Union );
  void oCLogTopic::AddEntry_Union( zSTRING const& entry ) {
    THISCALL( Hook_oCLogTopic_AddEntry )(entry);

    logBook.AddTopic( this );
  }

  HOOK Hook_zCMenuItemList_ShowContent PATCH( &zCMenuItemList::ShowContent, &zCMenuItemList::ShowContent_Union );
  void zCMenuItemList::ShowContent_Union() {
    THISCALL( Hook_zCMenuItemList_ShowContent )();

    if ( !Options::LogBookColoring || !logBook.CanColorList( this ) )
      return;

    logBook.MarkRead( this->m_list[m_cur_element].title );

    // zCMenuItemList::DrawFront function is not called after closing content so color must be updated here
    logBook.UpdateView( this->m_pInnerWindow );
  }

  HOOK Hook_zCMenuItemList_DrawFront PATCH( &zCMenuItemList::DrawFront, &zCMenuItemList::DrawFront_Union );
  void zCMenuItemList::DrawFront_Union() {
    THISCALL( Hook_zCMenuItemList_DrawFront )();

    if ( !Options::LogBookColoring || !logBook.CanColorList( this ) )
      return;

    logBook.UpdateView( this->m_pInnerWindow );
  }

  void LogBook::UpdateView( zCView* view ) {
    if ( !view ) return;

    auto list = view->textLines.GetNextInList();

    while ( list != nullptr ) {
      auto item = list->GetData();
      list = list->GetNextInList();

      logBook.UpdateColor( item );
    }
  }

  void LogBook::UpdateColor( zCViewText* view ) {
    if ( !colorOld ) colorOld = new zCOLOR( view->color );

    zSTRING topic = view->text;
    zCOLOR color = *colorOld;

    if ( newTopics.IsInList( topic ) )
      color = zCOLOR( 0, 255, 0 );
    else if ( unreadTopics.IsInList( topic ) )
      color = zCOLOR( 255, 160, 0 );

    view->color = color;
    view->colored = true;
  }

  bool LogBook::CanColorList( zCMenuItemList* list ) {
    return list->id == "MENU_ITEM_LIST_LOG" || list->id == "MENU_ITEM_LIST_MISSIONS_ACT" || list->id == "MENU_ITEM_LIST_MISSIONS_OLD" || list->id == "MENU_ITEM_LIST_MISSIONS_FAILED";
  }

  void LogBook::AddTopic( oCLogTopic* topic ) {
    if ( unreadTopics.IsInList( topic->m_strDescription ) || newTopics.IsInList( topic->m_strDescription ) )
      return;

    if ( topic->m_lstEntries.GetNum() == 1 ) {
      newTopics.Insert( topic->m_strDescription );
      return;
    }

    unreadTopics.Insert( topic->m_strDescription );
  }

  void LogBook::MarkRead( zSTRING topic ) {
    if ( unreadTopics.IsInList( topic ) )
      unreadTopics.Remove( topic );

    if ( newTopics.IsInList( topic ) )
      newTopics.Remove( topic );
  }

  void LogBook::Archive( zCArchiver* ar ) {
    ar->WriteInt( "unreadTopicsCount", unreadTopics.GetNum() );
    for ( uint i = 0; i < unreadTopics.GetNum(); i++ )
      ar->WriteString( "unreadTopics", unreadTopics[i] );

    ar->WriteInt( "newTopicsCount", newTopics.GetNum() );
    for ( uint i = 0; i < newTopics.GetNum(); i++ )
      ar->WriteString( "newTopics", newTopics[i] );
  }

  void LogBook::Unarchive( zCArchiver* ar ) {
    unreadTopics.EmptyList();
    newTopics.EmptyList();

    if ( !ar )
      return;

    for ( int i = 0; i < ar->ReadIntSafe( "unreadTopicsCount" ); i++ )
      unreadTopics.Insert( ar->ReadString( "unreadTopics" ) );

    for ( int i = 0; i < ar->ReadIntSafe( "newTopicsCount" ); i++ )
      newTopics.Insert( ar->ReadString( "newTopics" ) );
  }
}