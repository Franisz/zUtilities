// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int oCItem::GetLineTextIsIn( zSTRING str ) {
    for ( int i = 0; i < ITM_TEXT_MAX; i++ )
      if ( text[i] == str )
        return i;

    return Invalid;
  }

  int StatusBar::GetValueFromItem( oCItem* item ) {
    for ( int i = 0; i < symbols.GetNumInList(); i++ ) {
      auto sym = parser->GetSymbol( symbols[i] );
      if ( !sym )
        continue;

      zSTRING symStr = sym->stringdata;
      if ( !symStr.Length() )
        continue;

      int line = item->GetLineTextIsIn( symStr );
      if ( line == Invalid )
        continue;

      return item->count[line];
    }

    return 0;
  }

  bool StatusBar::IsBarActive() {
    return bar->owner;
  }

  bool StatusBar::Init() {
    if ( bar == ogame->focusBar )
      return true;

    if ( bar == ogame->hpBar ) {
      symbols.Insert( "NAME_BONUS_HP" );
      if ( Options::StatusBarNames.GetNum() >= 1 )
        name = Z Options::StatusBarNames[0];

      if ( Options::HealthBarPos.GetNum() == 4 )
        userPos = Options::HealthBarPos;

      return true;
    }

    if ( bar == ogame->manaBar ) {
      symbols.Insert( "NAME_BONUS_MANA" );
      if ( Options::StatusBarNames.GetNum() >= 2 )
        name = Z Options::StatusBarNames[1];

      if ( Options::ManaBarPos.GetNum() == 4 )
        userPos = Options::ManaBarPos;

      return true;
    }

    if ( bar == ogame->swimBar ) {
      if ( Options::StatusBarNames.GetNum() >= 3 )
        name = Z Options::StatusBarNames[2];

      if ( Options::SwimBarPos.GetNum() == 4 )
        userPos = Options::SwimBarPos;

      return true;
    }

    return false;
  }

  int StatusBar::GetHealValue() {
    if ( !player->inventory2.IsOpen() )
      return 0;

    if ( (int)bar->currentValue == (int)bar->maxHigh )
      return 0;

    oCItem* item = player->inventory2.GetSelectedItem();
    if ( !item )
      return 0;

    if ( !item->onState[0] )
      return 0;

    if ( !item->HasFlag( ITM_CAT_FOOD ) && !item->HasFlag( ITM_CAT_POTION ) )
      return 0;

    if ( bar == ogame->hpBar )
      return GetValueFromItem( item );

    if ( bar == ogame->manaBar )
      return GetValueFromItem( item );

    return 0;
  }

  void StatusBar::DrawPrediction( int value ) {
    int current = (int)bar->currentValue * 100 / (int)bar->maxHigh;
    int bonus = min( value * 100 / (int)bar->maxHigh, 100 );

    if ( bonus + current > 100 )
      bonus = 100 - current;

    int start = current * 8192 / 100;

    int x1 = max( start, 0 );
    int y1 = bar->range_bar->py1;
    int x2 = min( bonus * 8192 / 100 + start, 8192 );
    int y2 = bar->range_bar->py2;

    predictView = new zCView( x1, y1, x2, y2 );
    predictView->InsertBack( bar->texValue );
    predictView->SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
    predictView->SetTransparency( 85 );
    bar->range_bar->InsertItem( predictView );
  }

  void StatusBar::PredictHeal() {
    if ( !Options::RecoveryVisualization )
      return;

    if ( predictView ) {
      bar->range_bar->RemoveItem( predictView );
      predictView = nullptr;
    }

    if ( !IsBarActive() )
      return;

    int value = GetHealValue();
    if ( value <= 0 )
      return;

    DrawPrediction( value );
  }

  void StatusBar::PrintValue( oCNpc* npc ) {
    if ( !Options::StatusBarValueMode )
      return;

    zCView* insertView = (Options::StatusBarValueMode == Inside) ? bar->range_bar : screen;

    if ( valueView ) {
      valueView->ClrPrintwin();
      insertView->RemoveItem( valueView );
      valueView = nullptr;
    }

    if ( !IsBarActive() )
      return;

    valueView = new zCView( 0, 0, 8192, 8192 );

    zSTRING str;
    if ( bar == ogame->swimBar )
      str = Z( int )(bar->currentValue / 100) + "/" + Z( int )(bar->maxHigh / 100);
    else
      str = Z( int )bar->currentValue + "/" + Z( int )bar->maxHigh;

    if ( name && name.Length() )
      str = name + ": " + str;

    insertView->InsertItem( valueView );

    if ( Options::StatusBarValueMode != Inside ) {
      int offsetY = bar->vsizey / 2 + valueView->FontY();
      int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize( str ) / 2;
      int y = bar->vposy;
      bool center = false;

      if ( bar == ogame->focusBar && Options::ShowEnemyBarAboveHim )
        y -= offsetY;
      else if ( Options::StatusBarValueMode == Above )
        center = true;
      else if ( bar->vposx + bar->vsizex < 3072 )
        x = bar->vposx + bar->vsizex + valueView->FontY() / 2;
      else if ( bar->vposx > 5120 )
        x = bar->vposx - valueView->FontSize( str ) - valueView->FontY() / 2;
      else
        center = true;

      if ( center )
        if ( bar->vposy + bar->vsizey > 4092 )
          y -= offsetY;
        else
          y += offsetY;

      valueView->SetFontColor( zCOLOR( valueView->color.r, valueView->color.g, valueView->color.b, bar->alpha ) );
      valueView->Print( x, y, str );
      return;
    }

    valueView->PrintCXY( str );
  }

  void StatusBar::MoveFocusBar( int x, int y, oCNpc* npc ) {
    if ( !Options::ShowEnemyBarAboveHim )
      return;

    if ( bar != ogame->focusBar )
      return;

    if ( !IsBarActive() )
      return;

    zCCamera* cam = ogame->GetCamera();
    zVEC3 viewPos = cam->GetTransform( zTCamTrafoType::zCAM_TRAFO_VIEW ) * npc->GetPositionWorld();
    int posx, posy;
    cam->Project( &viewPos, posx, posy );
    if ( viewPos[2] <= cam->nearClipZ )
      return;

    x = x + screen->FontSize( npc->name[0] ) / 2 - bar->vsizex / 2;
    if ( x + bar->vsizex > 8192 )
      x = 8192 - bar->vsizex;

    x = max( 0, x );
    y = max( 0, y - screen->FontY() * 1.75 );

    bar->SetPos( x, y );
  }

  void StatusBar::ChangeBarPos() {
    if ( userPos.GetNum() != 4 )
      return;

    if ( !IsBarActive() )
      return;

    int x1 = userPos[0].ToInt32();
    int y1 = userPos[1].ToInt32();

    if ( x1 < 0 || x1 > 8192 || y1 < 0 || y1 > 8192 )
      return;

    int x2 = userPos[2].ToInt32() - x1;
    int y2 = userPos[3].ToInt32() - y1;

    if ( x2 <= 0 || y2 <= 0 )
      return;

    bar->SetPos( x1, y1 );
    bar->SetSize( x2, y2 );
  }

  bool StatusBar::NeedAdjustPosition( int x, int y, oCNpc* npc ) {
    if ( !ogame->focusBar || !npc || npc->attribute[NPC_ATR_HITPOINTS] <= 0 )
      return false;

    playerStatus.focusBar->MoveFocusBar( x, y, npc );
    playerStatus.focusBar->PrintValue( npc );
    return Options::ShowEnemyBarAboveHim;
  }

  void StatusBar::Clear() {
    if ( !bar )
      return;

    if ( valueView ) {
      zCView* insertView = (Options::StatusBarValueMode == Inside) ? bar->range_bar : screen;
      valueView->ClrPrintwin();
      insertView->RemoveItem( valueView );
      valueView = nullptr;
    }

    if ( predictView ) {
      bar->range_bar->RemoveItem( predictView );
      predictView = nullptr;
    }
  }

  void StatusBar::Loop() {
    if ( !ogame || !player )
      return;

    if ( !bar )
      return;

    if ( bar == ogame->focusBar ) {
      if ( valueView )
        valueView->ClrPrintwin();

      return;
    }

    ChangeBarPos();
    PredictHeal();
    PrintValue( player );
  }

  StatusBar::StatusBar( oCViewStatusBar* bar ) {
    this->bar = bar;

    if ( !Init() )
      return;

    if ( Options::StatusBarValueMode == Inside && !playerHelper.GetSysScale() )
      this->bar->vsizey *= 1.15;
  }
}