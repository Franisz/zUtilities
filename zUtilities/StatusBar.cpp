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
    if ( bar == ogame->hpBar ) {
      talent = NPC_ATR_HITPOINTS;
      talentMax = NPC_ATR_HITPOINTSMAX;
      symbols.Insert( "NAME_BONUS_HP" );
      return true;
    }

    if ( bar == ogame->manaBar ) {
      talent = NPC_ATR_MANA;
      talentMax = NPC_ATR_MANAMAX;
      symbols.Insert( "NAME_BONUS_MANA" );
      return true;
    }

    if ( bar == ogame->focusBar ) {
      talent = NPC_ATR_HITPOINTS;
      talentMax = NPC_ATR_HITPOINTSMAX;
      if ( Options::ShowEnemyBarAboveHim )
        bar->vposy = -screen->FontY() * 2;
      return true;
    }

    return false;
  }

  int StatusBar::GetHealValue() {
    if ( !npc->inventory2.IsOpen() )
      return 0;

    if ( npc->attribute[talent] == npc->attribute[talentMax] )
      return 0;

    oCItem* item = npc->inventory2.GetSelectedItem();
    if ( !item )
      return 0;

    if ( !item->onState[0] )
      return 0;

    if ( talent == NPC_ATR_HITPOINTS )
      return GetValueFromItem( item );

    if ( talent == NPC_ATR_MANA )
      return GetValueFromItem( item );

    return 0;
  }

  void StatusBar::DrawPrediction( int value ) {
    int currentHpPercent = npc->attribute[talent] * 100 / npc->attribute[talentMax];
    int bonusHpPercent = min( value * 100 / npc->attribute[talentMax], 100 );

    if ( bonusHpPercent + currentHpPercent > 100 )
      bonusHpPercent = 100 - currentHpPercent;

    int start = currentHpPercent * 8192 / 100;

    int x1 = max( start, 0 );
    int y1 = bar->range_bar->py1;
    int x2 = min( bonusHpPercent * 8192 / 100 + start, 8192 );
    int y2 = bar->range_bar->py2;

    predictView = new zCView( x1, y1, x2, y2 );
    predictView->InsertBack( bar->texValue );
    predictView->SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
    predictView->SetTransparency( 125 );
    bar->range_bar->InsertItem( predictView );
  }

  void StatusBar::PredictHeal() {
    if ( !Options::RecoveryVisualization )
      return;

    if ( predictView ) {
      bar->range_bar->RemoveItem( predictView );
      predictView = nullptr;
    }

    if ( !IsBarActive() || !npc || npc != player )
      return;

    int value = GetHealValue();
    if ( value <= 0 )
      return;

    DrawPrediction( value );
  }

  void StatusBar::PrintValue() {
    if ( !Options::StatusBarValueMode )
      return;

    zCView* insertView = (Options::StatusBarValueMode == Above) ? screen : bar->range_bar;

    if ( valueView ) {
      valueView->ClrPrintwin();
      insertView->RemoveItem( valueView );
      valueView = nullptr;
    }

    if ( !IsBarActive() || !npc )
      return;

    valueView = new zCView( 0, 0, 8192, 8192 );
    int min = npc->attribute[talent];
    int max = npc->attribute[talentMax];
    zSTRING str = Z min + "/" + Z max;

    insertView->InsertItem( valueView );

    if ( Options::StatusBarValueMode == Above && (Options::ShowEnemyBarAboveHim || bar != ogame->focusBar) ) {
      int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize( str ) / 2;
      int y = bar->vposy + bar->vsizey / 2 - valueView->FontY() * 1.75;
      valueView->Print( x, y, str );
      return;
    }

    valueView->PrintCXY( str );
  }

  void StatusBar::MoveFocusBar( int x, int y, zSTRING text ) {
    if ( !Options::ShowEnemyBarAboveHim )
      return;

    if ( bar != ogame->focusBar )
      return;

    if ( !IsBarActive() )
      return;

    npc = player->GetFocusNpc();
    if ( !npc ) {
      bar->vposy = -screen->FontY() * 2;
      return;
    }

    zSTRING name = npc->name[0];
    if ( text != name + "\n" && text != name )
      return;

    bar->vposx = x + screen->FontSize( name ) / 2 - bar->vsizex / 2;
    bar->vposy = y - screen->FontY() * 2;
  }

  void StatusBar::Loop() {
    if ( !ogame || !player )
      return;

    if ( !bar )
      return;

    if ( bar == ogame->focusBar )
      npc = player->GetFocusNpc();
    else
      npc = player;

    PredictHeal();
    PrintValue();
  }

  StatusBar::StatusBar( oCViewStatusBar* bar ) {
    this->bar = bar;

    if ( !Init() )
      return;

    if ( Options::StatusBarValueMode == Inside && !playerHelper.GetSysScale() )
      this->bar->vsizey *= 1.15;
  }
}