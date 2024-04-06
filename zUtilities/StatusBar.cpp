// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int oCItem::GetLineTextIsIn( zSTRING str ) {
    for ( int i = 0; i < ITM_TEXT_MAX; i++ )
      if ( text[i] == str )
        return i;

    return Invalid;
  }

  int StatusBar::GetValueFromItem( oCItem* item, int atr ) {
    int healValue = 0;

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

      if ( symbols[i].EndWith( "_FULL" ) ) {
        return player->GetAttribute( atr );
      }
      else if ( symbols[i].EndWith( "_PERC" ) ) {
        healValue += player->GetAttribute( atr ) * item->count[line] / 100;
      }
      else {
        healValue += item->count[line];
      }
    }

    return healValue;
  }

  bool StatusBar::IsBarActive() {
    return bar->owner;
  }

  bool StatusBar::Init() {
   return false;
  }

  int StatusBar::GetRestoreValue() {
	  if (restoreAttribute == -1)
		  return 0;

	  if (!player->inventory2.IsOpen())
		  return 0;

	  if ((int)bar->currentValue == (int)bar->maxHigh)
		  return 0;

	  oCItem* item = player->inventory2.GetSelectedItem();
	  if (!item)
		  return 0;

	  if (!item->onState[0])
		  return 0;

	  if (!item->HasFlag(ITM_CAT_FOOD) && !item->HasFlag(ITM_CAT_POTION))
		  return 0;

	  return GetValueFromItem(item, restoreAttribute);
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

  void StatusBar::PredictRestore() {
    if ( !Options::RecoveryVisualization )
      return;

    del( predictView );

    if ( !IsBarActive() )
      return;

    int value = GetRestoreValue();
    if ( value <= 0 )
      return;

    DrawPrediction( value );
  }

  zSTRING StatusBar::GetBarValue() {
	  return Z(int)bar->currentValue + "/" + Z(int)bar->maxHigh;
  }

  void StatusBar::PrintValue( oCNpc* npc ) {
    if ( !Options::StatusBarValueMode )
      return;

    del( valueView );

    if ( !IsBarActive() )
      return;

    valueView = new zCView( 0, 0, 8192, 8192 );

    auto str =  GetBarValue();


    if (name && name.Length()) {
        str = name + ": " + str;
    }

    zCView* ownerView = (Options::StatusBarValueMode == Inside) ? bar->range_bar : screen;
    ownerView->InsertItem( valueView );

    if ( Options::StatusBarValueMode != Inside ) {
      int offsetY = bar->vsizey / 2 + valueView->FontY();
      int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize( str ) / 2;
      int y = bar->vposy;
      bool center = false;

      if (ShouldReverseValuePos())
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
  
  bool StatusBar::ShouldReverseValuePos() {
      return false;
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

  void StatusBar::Clear() {
    if ( !bar )
      return;

    del( valueView );
    del( predictView );
  }

  bool StatusBar::CanLoop() {
      return ogame && player && bar;
  }

  void StatusBar::Loop() {
    if (!CanLoop())
      return;

    ChangeBarPos();
    PredictRestore();
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