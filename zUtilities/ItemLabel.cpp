// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
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

  bool ItemLabel::CanDrawLabel(zCViewBase* viewBase ) {
    auto list = oCItemContainer::contList.GetNextInList();
    while ( list != nullptr ) {
      oCItemContainer* container = list->GetData();
      list = list->GetNextInList();

      if ( viewBase == container->viewItem
        || viewBase == container->viewItemActive
        || viewBase == container->viewItemHightlighted
        || viewBase == container->viewItemActiveHighlighted )
        return true;
    }
    return false;
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

    // Melee
    if ( item->HasFlag( ITM_CAT_NF ) ) {

      if ( item->HasFlag( ITM_FLAG_2HD_AXE ) || item->HasFlag( ITM_FLAG_2HD_SWD ) ) {
        if ( condAtr == NPC_ATR_MANAMAX ) {
          color = manaBlue;
          texture = "WPN_MANA_2H"; // https://game-icons.net/1x1/lorc/moebius-star.html
          return;
        }

        if ( condAtr == NPC_ATR_DEXTERITY ) {
          color = dexGreen;
          texture = "WPN_DEX_2H"; // https://game-icons.net/1x1/lorc/barbed-spear.html
          return;
        }

        if ( item->damageTypes == oEDamageType_Blunt ) {
          color = bluntYellow;
          texture = "WPN_MACE_2H"; // https://game-icons.net/1x1/lorc/gavel.html
          return;
        }

        if ( item->HasFlag( ITM_FLAG_2HD_AXE ) ) {
          color = strRed;
          texture = "WPN_AXE_2H"; // https://game-icons.net/1x1/lorc/battle-axe.html
          return;
        }

        color = strRed;
        texture = "WPN_SWORD_2H"; // https://game-icons.net/1x1/lorc/shard-sword.html
        return;
      }

      if ( item->HasFlag( ITM_FLAG_SWD ) || item->HasFlag( ITM_FLAG_AXE ) || item->HasFlag( ITM_FLAG_DAG ) ) {
        if ( condAtr == NPC_ATR_MANAMAX ) {
          color = manaBlue;
          texture = "WPN_MANA"; // https://game-icons.net/1x1/lorc/rune-sword.html
          return;
        }

        if ( condAtr == NPC_ATR_DEXTERITY || item->HasFlag( ITM_FLAG_DAG ) ) {
          color = dexGreen;
          texture = "WPN_DEX"; // https://game-icons.net/1x1/lorc/sacrificial-dagger.html
          return;
        }

        if ( item->damageTypes == oEDamageType_Blunt ) {
          color = bluntYellow;
          texture = "WPN_MACE"; // https://game-icons.net/1x1/lorc/spiked-mace.html
          return;
        }

        if ( item->HasFlag( ITM_FLAG_AXE ) ) {
          color = strRed;
          texture = "WPN_AXE"; // https://game-icons.net/1x1/lorc/battered-axe.html
          return;
        }

        color = strRed;
        texture = "WPN_SWORD"; // https://game-icons.net/1x1/skoll/gladius.html
        return;
      }
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

    if ( item->HasFlag( ITM_FLAG_SHIELD ) ) {
      color = zCOLOR( 247, 143, 179 );
      texture = "SHIELD"; // https://game-icons.net/1x1/lorc/checked-shield.html
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
      if ( item->GetInstanceName().StartWith( "ITRU" ) || item->GetInstanceName().StartWith( "ITARRUNE" ) ) {
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
        return;
      }

      if ( item->GetInstanceName().HasWord( "MAP" ) ) {
        color = goldYellow;
        texture = "MAP"; // https://game-icons.net/1x1/lorc/treasure-map.html
        return;
      }

      color = zCOLOR( 153, 128, 250 );
      texture = "DOCS"; // https://game-icons.net/1x1/lorc/tied-scroll.html
      return;
    }

    if ( item->HasFlag( ITM_FLAG_TORCH ) ) {
      color = zCOLOR( 240, 147, 43 );
      texture = "TORCH"; // https://game-icons.net/1x1/delapouite/torch.html
      return;
    }

    if ( item->GetInstanceName().StartWith( "ITKE" ) ) {
      color = zCOLOR( 113, 128, 147 );
      texture = "KEY"; // https://game-icons.net/1x1/lorc/key.html
      return;
    }

    if ( item->GetInstanceName().StartWith( "ITSE" ) ) {
      color = goldYellow;
      texture = "SECRET"; // https://game-icons.net/1x1/lorc/cash.html
      return;
    }

    if ( item->GetInstanceName().StartWith( "ITAT" ) ) {
      color = lightBronze;
      texture = "TROPHY"; // https://game-icons.net/1x1/lorc/flat-paw-print.html
      return;
    }

    if ( auto sym = parser->GetSymbol( "TRADE_CURRENCY_INSTANCE" ) )
      if ( item->GetInstanceName() == sym->stringdata ) {
        color = goldYellow;
        texture = "MONEY"; // https://game-icons.net/1x1/delapouite/two-coins.html
        return;
      }
  }

  ItemLabel::ItemLabel( oCItem* renderedItem, zCViewBase* viewBase ) {
    item = renderedItem;

    if(!CanDrawLabel( viewBase ) )
      return;

    zCView* itemView = dynamic_cast<zCView*>(viewBase);
    if ( !itemView )
      return;

    SetLabelParams();

    int startPos = (item == player->inventory2.GetSelectedItem()) ? 500 : 250;

    int endPos = startPos + 2000 * fLabelScale;

    zCView labelView( startPos, startPos, endPos, endPos );
    labelView.InsertBack( "LABEL_" + texture );
    labelView.SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
    labelView.SetTransparency( 255 );
    labelView.SetColor( color );
    itemView->InsertItem( &labelView );
    labelView.Blit();
    itemView->RemoveItem( &labelView );
  }
}