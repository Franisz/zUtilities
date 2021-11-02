// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void DebugHelper::InfoNpc( oCNpc* npc ) {
    Print( textView, "Name", npc->GetName( 0 ) );
    Print( textView, "Instance", npc->GetInstanceName() + " (" + Z npc->instanz + ")" );
    Print( textView, "Guild", npc->GetGuildName() + " (" + Z npc->GetGuild() + ")" );
    Print( sideView, "Level", Z npc->level );
    AddSeparator();
  }

  void DebugHelper::InfoInter( oCMobInter* inter ) {
    Print( textView, "Name", Z inter->name );

    if ( oCMobLockable* lockable = inter->CastTo<oCMobLockable>() ) {
      Print( textView, "KeyInstance", Z lockable->keyInstance );
      Print( textView, "LockString", Z lockable->pickLockStr );
      Print( textView, "State", Z lockable->state );
      Print( textView, "Locked", Z lockable->locked );
    }

    if ( oCMobContainer* container = inter->CastTo<oCMobContainer>() ) {
      if ( auto list = container->containList.GetNextInList() ) {
        int itemCount = container->containList.GetNumInList();
        int printedItems = 0;

        AddSeparator( "Items" );
        while ( list != nullptr ) {
          Print( textView, list->GetData()->name, Z list->GetData()->amount );

          printedItems++;
          if ( itemCount > 5 && printedItems >= 5 ) {
            Print( textView, "", "And " + Z( itemCount - printedItems ) + " more..." );
            break;
          }

          list = list->GetNextInList();
        }
        AddSeparator();
      }
    }
  }

  void DebugHelper::InfoItem( oCItem* item ) {
    Print( textView, "Name", Z item->name );
  }

  void DebugHelper::AddSeparator( zSTRING str ) {
    textLines++;

    if ( !str.Length() )
      return;

    textLines++;
    textView->Print( 0, textHeight * textLines, "-- " + str + " --" );
  }

  void DebugHelper::Print( zCView* view, zSTRING name, zSTRING value ) {
    if ( !value.Length() )
      value = "-";

    zSTRING text = (name.Length()) ? name + ": " + value : value;

    if ( view == textView )
      textLines++;

    view->Print( 0, textHeight * textLines, text );
  }

  void DebugHelper::PrintInfo( zCVob* vob ) {
    if ( oCNpc* npc = vob->CastTo<oCNpc>() )
      InfoNpc( npc );
    else if ( oCMobInter* inter = vob->CastTo<oCMobInter>() )
      InfoInter( inter );
    else if ( oCItem* item = vob->CastTo<oCItem>() )
      InfoItem( item );

    if ( zCVisual* visual = vob->visual ) {
      //AddSeparator();
      Print( textView, "Visual", Z visual->GetVisualName() );
    }

    //screen->Print( 100, 100, vob->GetVobInfo() );
  }

  void DebugHelper::Clear() {
    if ( mainView == nullptr ) return;

    mainView->RemoveItem( textView );
    mainView->RemoveItem( sideView );
    screen->RemoveItem( mainView );
    textView = nullptr;
    sideView = nullptr;
    mainView = nullptr;
  }

  void DebugHelper::DebugHelperLoop() {
    if ( !Options::UsingDebugHelper || ogame->pause_screen || zcon->IsVisible() || !ogame->showPlayerStatus ) {
      Clear();
      return;
    }

    if ( mainView == nullptr ) {
      mainView = new zCView( 0, 1024, 2048, 7168 );
      mainView->InsertBack( "BLACKBACK" );
      mainView->SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
      mainView->SetTransparency( 150 );
      screen->InsertItem( mainView );

      textHeight = mainView->FontY();
      margin = textHeight;

      textView = new zCView( margin, 0, 8192 - margin, 8192 );
      sideView = new zCView( margin + 8192 / 2, 0, 8192 - margin, 8192 );
      mainView->InsertItem( textView );
      mainView->InsertItem( sideView );
    }

    textView->ClrPrintwin();
    sideView->ClrPrintwin();
    textLines = 0;

    if ( player->inventory2.IsOpen() && !player->inventory2.GetNextContainerLeft( &player->inventory2 ) ) {
      if ( oCItem* item = player->inventory2.GetSelectedItem() ) {
        InfoItem( item );
        return;
      }
    }

    if ( zCVob* vob = player->GetFocusVob() ) {
      PrintInfo( vob );
      return;
    }

    Clear();
  }
}