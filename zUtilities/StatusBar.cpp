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

    return false;
  }

  int StatusBar::GetHealValue() {
    if ( !player->inventory2.IsOpen() )
      return 0;

    if ( player->attribute[talent] == player->attribute[talentMax] )
      return 0;

    oCItem* item = player->inventory2.GetSelectedItem();
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

  void StatusBar::Clear() {
    bar->range_bar->RemoveItem( predictView );
    predictView = nullptr;
  }

  void StatusBar::PredictHeal( int value ) {
    int currentHpPercent = player->attribute[talent] * 100 / player->attribute[talentMax];
    int bonusHpPercent = min( value * 100 / player->attribute[talentMax], 100 );

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

  void StatusBar::Loop() {
    if ( !ogame || !player )
      return;

    if ( !bar )
      return;

    if ( predictView )
      Clear();

    int value = GetHealValue();
    if ( value <= 0 )
      return;

    PredictHeal( value );
  }

  StatusBar::StatusBar( oCViewStatusBar* bar ) {
    this->bar = bar;

    if ( !Init() );
    return;
  }
}