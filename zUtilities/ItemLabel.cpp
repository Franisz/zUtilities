// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  bool canDrawLabels;

  HOOK Hook_oCItemContainer_Draw PATCH( &oCItemContainer::Draw, &oCItemContainer::Draw_Union );
  void oCItemContainer::Draw_Union() {
    canDrawLabels = true;
    THISCALL( Hook_oCItemContainer_Draw )();
    canDrawLabels = false;
  }

  HOOK Hook_oCItemContainer_DrawItemInfo PATCH( &oCItemContainer::DrawItemInfo, &oCItemContainer::DrawItemInfo_Union );
  void oCItemContainer::DrawItemInfo_Union( oCItem* item, zCWorld* world ) {
    canDrawLabels = false;
    THISCALL( Hook_oCItemContainer_DrawItemInfo )(item, world);
    canDrawLabels = true;
  }

  int oCItem::GetHighestCond() {
    int maxCond = 0;
    int maxIndex = -1;

    for ( int i = 0; i < ITM_COND_MAX; i++ )
      if ( this->cond_value[i] > maxCond ) {
        maxIndex = i;
        maxCond = this->cond_value[i];
      }

    return (maxIndex != -1) ? this->cond_atr[maxIndex] : -1;
  }

  int oCItem::GetStateFunc() {
    for ( int i = 0; i < ITM_STATE_MAX; i++ )
      if ( this->onState[i] )
        return this->onState[i];

    return Invalid;
  }

  bool ItemLabel::CanDrawLabel() {
    return canDrawLabels;
  }

  void ItemLabel::SetLabelParams() {
    int condAtr = item->GetHighestCond();

    // Colors https://flatuicolors.com

    zCOLOR manaBlue = zCOLOR( 52, 152, 219 );
    zCOLOR dexGreen = zCOLOR( 76, 209, 55 );
    zCOLOR strRed = zCOLOR( 231, 76, 60 );
    zCOLOR bluntYellow = zCOLOR( 255, 218, 121 );
    zCOLOR goldYellow = zCOLOR( 241, 196, 15 );
    zCOLOR grey = zCOLOR( 189, 195, 199 );
    zCOLOR lightBronze = zCOLOR( 205, 127, 50 );
    zCOLOR statePink = zCOLOR( 255, 171, 243 );

    // ITEM_MISSION
    if ( Options::LabelMissionItems && item->HasFlag( ITM_FLAG_MI ) ) {
      color = zCOLOR( 243, 104, 224 );
      texture = "MISSION"; // https://game-icons.net/1x1/delapouite/pin.html
      return;
    }

    // Melee
    if ( item->HasFlag( ITM_CAT_NF ) && !item->HasFlag( ITM_FLAG_SHIELD ) ) {
      if ( condAtr == NPC_ATR_MANAMAX || item->mag_circle )
        color = manaBlue;
      else if ( condAtr == NPC_ATR_DEXTERITY )
        color = dexGreen;
      else if ( item->damageTypes & oEDamageType_Blunt )
        color = bluntYellow;
      else
        color = strRed;

      if ( item->damageTypes & oEDamageType_Magic )
        texture = "WPN_MANA"; // https://game-icons.net/1x1/lorc/barbed-spear.html
      else if ( item->damageTypes & oEDamageType_Point )
        texture = "WPN_DEX"; // https://game-icons.net/1x1/lorc/barbed-spear.html
      else if ( item->damageTypes & oEDamageType_Blunt )
        texture = "WPN_MACE"; // https://game-icons.net/1x1/lorc/gavel.html
      else if ( item->HasFlag( ITM_FLAG_2HD_AXE ) )
        texture = "WPN_AXE"; // https://game-icons.net/1x1/lorc/battle-axe.html
      else
        texture = "WPN_SWORD"; // https://game-icons.net/1x1/lorc/shard-sword.html

      if ( item->HasFlag( ITM_FLAG_2HD_AXE ) || item->HasFlag( ITM_FLAG_2HD_SWD ) )
        texture = texture + "_2H";

      return;
    }

    // Ranged
    if ( item->HasFlag( ITM_CAT_FF ) ) {
      if ( item->HasFlag( ITM_FLAG_BOW ) ) {
        color = zCOLOR( 26, 188, 156 );
        texture = "WPN_BOW"; // https://game-icons.net/1x1/lorc/high-shot.html
        return;
      }

      if ( item->HasFlag( ITM_FLAG_CROSSBOW ) ) {
        color = zCOLOR( 255, 168, 1 );
        texture = "WPN_CROSSBOW"; // https://game-icons.net/1x1/carl-olsen/crossbow.html
        return;
      }
    }

    // Munition
    if ( item->HasFlag( ITM_CAT_MUN ) ) {
      color = grey;

      if ( item->HasFlag( ITM_FLAG_BOW ) ) {
        texture = "MUN_BOW"; // https://game-icons.net/1x1/lorc/stone-spear.html
        return;
      }

      if ( item->HasFlag( ITM_FLAG_CROSSBOW ) ) {
        texture = "MUN_CROSSBOW"; // https://game-icons.net/1x1/lorc/arrowhead.html
        return;
      }
    }

    // Shield
    if ( item->HasFlag( ITM_FLAG_SHIELD ) ) {
      color = zCOLOR( 247, 143, 179 );
      texture = "SHIELD"; // https://game-icons.net/1x1/lorc/checked-shield.html
      return;
    }

    // Armors
    if ( item->HasFlag( ITM_CAT_ARMOR ) ) {
      if ( item->wear == ITM_WEAR_HEAD ) {
        color = grey;
        texture = "ARM_HELMET"; // https://game-icons.net/1x1/lorc/visored-helm.html
        return;
      }

      if ( condAtr == NPC_ATR_DEXTERITY ) {
        color = dexGreen;
        texture = "ARM_DEX"; // https://game-icons.net/1x1/delapouite/leather-armor.html
        return;
      }

      if ( condAtr == NPC_ATR_MANAMAX ) {
        color = manaBlue;
        texture = "ARM_MANA"; // https://game-icons.net/1x1/delapouite/ninja-armor.html
        return;
      }

      color = strRed;
      texture = "ARM_STR"; // https://game-icons.net/1x1/lorc/lamellar.html
      return;
    }

    if ( item->HasFlag( ITM_FLAG_AMULET ) && !item->HasFlag( ITM_CAT_NONE ) ) {
      color = zCOLOR( 190, 46, 221 );
      texture = "AMULET"; // https://game-icons.net/1x1/lorc/gem-chain.html
      return;
    }

    if ( item->HasFlag( ITM_FLAG_RING ) && !item->HasFlag( ITM_CAT_NONE ) ) {
      color = zCOLOR( 72, 52, 212 );
      texture = "RING"; // https://game-icons.net/1x1/delapouite/power-ring.html
      return;
    }

#if ENGINE == Engine_G2A
    if ( item->HasFlag( ITM_FLAG_BELT ) && !item->HasFlag( ITM_CAT_NONE ) ) {
      color = zCOLOR( 61, 193, 211 );
      texture = "BELT"; // https://game-icons.net/1x1/lorc/belt-buckles.html
      return;
    }
#endif

    if ( item->HasFlag( ITM_CAT_FOOD ) ) {
      if ( item->GetSoundMaterial() == SND_MAT_GLAS ) {
        color = lightBronze;
        texture = "FOOD_DRINK"; // https://game-icons.net/1x1/delapouite/magic-potion.html
        return;
      }

      if ( item->GetInstanceName().StartWith( "ITPL" ) || item->GetInstanceName().StartWith( "ITFO_PLANTS" ) ) {
        color = zCOLOR( 46, 204, 113 );
        texture = "FOOD_HERB"; // https://game-icons.net/1x1/lorc/tree-branch.html
        return;
      }

      color = lightBronze;
      texture = "FOOD_ELSE"; // https://game-icons.net/1x1/lorc/chicken-leg.html
      return;
    }

    if ( item->HasFlag( ITM_CAT_POTION ) ) {
      color = zCOLOR( 155, 89, 182 );
      texture = "POTION"; // https://game-icons.net/1x1/lorc/fire-bottle.html
      return;
    }

    if ( item->HasFlag( ITM_CAT_RUNE ) ) {
      if ( !item->HasFlag( ITM_FLAG_MULTI ) ) {
        color = zCOLOR( 217, 128, 250 );
        texture = "RUNE"; // https://game-icons.net/1x1/lorc/cursed-star.html
        return;
      }

      color = zCOLOR( 237, 76, 103 );
      texture = "SPELL"; // https://game-icons.net/1x1/skoll/pentacle.html
      return;
    }

    if ( item->HasFlag( ITM_CAT_MAGIC ) ) {
      color = zCOLOR( 253, 167, 223 );
      texture = "MAGIC"; // https://game-icons.net/1x1/lorc/triorb.html
      return;
    }

    if ( item->HasFlag( ITM_CAT_DOCS ) ) {
      if ( item->GetSoundMaterial() == SND_MAT_STONE ) {
        color = grey;
        texture = "TABLET"; // https://game-icons.net/1x1/lorc/stone-tablet.html
      }
      else if ( item->GetInstanceName().HasWord( "MAP" ) ) {
        color = goldYellow;
        texture = "MAP"; // https://game-icons.net/1x1/lorc/treasure-map.html
      }
      else {
        color = zCOLOR( 153, 128, 250 );
        texture = "DOCS"; // https://game-icons.net/1x1/lorc/tied-scroll.html
      }

      color = (!playerStatus.KnowStateFunc( item )) ? statePink : color;
      return;
    }

    if ( item->HasFlag( ITM_FLAG_TORCH ) ) {
      color = zCOLOR( 240, 147, 43 );
      texture = "TORCH"; // https://game-icons.net/1x1/delapouite/torch.html
      return;
    }

    if ( auto sym = parser->GetSymbol( "TRADE_CURRENCY_INSTANCE" ) )
      if ( item->GetInstanceName() == sym->stringdata ) {
        color = goldYellow;
        texture = "MONEY"; // https://game-icons.net/1x1/delapouite/two-coins.html
        return;
      }

    if ( item->GetInstanceName().StartWith( "ITSE" ) ) {
      color = goldYellow;
      texture = "SECRET"; // https://game-icons.net/1x1/lorc/cash.html
      return;
    }

    if ( item->GetInstanceName().StartWith( "ITKE" ) ) {
      color = zCOLOR( 113, 128, 147 );
      texture = "KEY"; // https://game-icons.net/1x1/lorc/key.html
    }

    if ( item->GetInstanceName().StartWith( "ITAT" ) ) {
      color = lightBronze;
      texture = "TROPHY"; // https://game-icons.net/1x1/lorc/flat-paw-print.html
    }

#if ENGINE >= Engine_G2
    if ( item->GetInstanceName().HasWord( "SILVER" ) || item->GetInstanceName().HasWord( "GOLD" ) ) {
      color = zCOLOR( 72, 219, 251 );
      texture = "VALUABLES"; // https://game-icons.net/1x1/lorc/cut-diamond.html
    }
#endif

    if ( item->GetStateFunc() != Invalid )
      color = statePink;
  }

  ItemLabel::ItemLabel( oCItem* renderedItem, zCViewBase* viewBase ) {
    item = renderedItem;

    if ( !CanDrawLabel() )
      return;

    zCView* itemView = dynamic_cast<zCView*>(viewBase);
    if ( !itemView )
      return;

    SetLabelParams();

    int startPos = (item == player->inventory2.GetSelectedItem()) ? 500 : 250;

    int endPos = startPos + 2000 * Options::LabelScale;

    zCView labelView( startPos, startPos, endPos, endPos );
    labelView.InsertBack( "LABEL_" + texture );
    labelView.SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
    labelView.SetTransparency( 255 );
    labelView.SetColor( color );
    itemView->InsertItem( &labelView );
    labelView.Blit();
    delete& labelView;
  }
}