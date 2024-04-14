// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  bool canDrawLabels;

  void __fastcall oCItemContainer_Draw(oCItemContainer *_this);
  auto Hook_oCItemContainer_Draw = CreateHook(reinterpret_cast<void *>(zSwitch(0x00667660, 0x00695040, 0x006A9BC0, 0x007076B0)), &oCItemContainer_Draw);
  void __fastcall oCItemContainer_Draw(oCItemContainer *_this)
  {
    canDrawLabels = true;
    Hook_oCItemContainer_Draw(_this);
    canDrawLabels = false;
  }

  void __fastcall oCItemContainer_DrawItemInfo(oCItemContainer *_this, void *vtable, oCItem *item, zCWorld *world);
  auto Hook_oCItemContainer_DrawItemInfo = CreateHook(reinterpret_cast<void *>(zSwitch(0x00667220, 0x00694AD0, 0x006A9350, 0x00706E40)), &oCItemContainer_DrawItemInfo);
  void __fastcall oCItemContainer_DrawItemInfo(oCItemContainer *_this, void *vtable, oCItem *item, zCWorld *world)
  {
    canDrawLabels = false;
    Hook_oCItemContainer_DrawItemInfo(_this, vtable, item, world);
    canDrawLabels = true;
  }

  bool ItemLabel::CanDrawLabel()
  {
    return canDrawLabels;
  }

  void ItemLabel::SetLabelParams()
  {
    int condAtr = item->GetHighestCond();

    // Colors https://flatuicolors.com

    zCOLOR manaBlue = zCOLOR(52, 152, 219);
    zCOLOR dexGreen = zCOLOR(76, 209, 55);
    zCOLOR strRed = zCOLOR(231, 76, 60);
    zCOLOR bluntYellow = zCOLOR(255, 218, 121);
    zCOLOR goldYellow = zCOLOR(241, 196, 15);
    zCOLOR grey = zCOLOR(189, 195, 199);
    zCOLOR lightBronze = zCOLOR(205, 127, 50);
    zCOLOR statePink = zCOLOR(255, 171, 243);

    // ITEM_MISSION
    if (zUtilitiesOptions->LabelMissionItems && item->HasFlag(ITM_FLAG_MI))
    {
      color = zCOLOR(243, 104, 224);
      texture = "MISSION"; // https://game-icons.net/1x1/delapouite/pin.html
      return;
    }

    static const zCPar_Symbol *ITEM_ARMREIF = parser->GetSymbol("ITEM_ARMREIF");
    static const int ITM_FLAG_ARMREIF = (ITEM_ARMREIF) ? ITEM_ARMREIF->single_intdata : Invalid;

    if (ITM_FLAG_ARMREIF && item->HasFlag(ITM_CAT_MAGIC))
    {
      if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITBR"))
      {
        color = zCOLOR(83, 64, 214);
        texture = "BRACELET"; // https://game-icons.net/1x1/cathelineau/torc.html
        return;
      }
      else if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITAR"))
      {
        color = zCOLOR(199, 169, 149);
        texture = "SHOES"; // https://game-icons.net/1x1/lorc/tread.html
        return;
      }
    }

    // Melee
    if (item->HasFlag(ITM_CAT_NF) && !item->HasFlag(ITM_FLAG_SHIELD))
    {
      if (condAtr == NPC_ATR_MANAMAX || item->mag_circle)
        color = manaBlue;
      else if (condAtr == NPC_ATR_DEXTERITY)
        color = dexGreen;
      else if (item->damageTypes & oEDamageType_Blunt)
        color = bluntYellow;
      else
        color = strRed;

      if (item->damageTypes & oEDamageType_Magic)
        texture = "WPN_MANA"; // https://game-icons.net/1x1/lorc/barbed-spear.html
      else if (item->damageTypes & oEDamageType_Point)
        texture = "WPN_DEX"; // https://game-icons.net/1x1/lorc/barbed-spear.html
      else if (item->damageTypes & oEDamageType_Blunt)
        texture = "WPN_MACE"; // https://game-icons.net/1x1/lorc/gavel.html
      else if (item->HasFlag(ITM_FLAG_2HD_AXE))
        texture = "WPN_AXE"; // https://game-icons.net/1x1/lorc/battle-axe.html
      else
        texture = "WPN_SWORD"; // https://game-icons.net/1x1/lorc/shard-sword.html

      if (item->HasFlag(ITM_FLAG_2HD_AXE) || item->HasFlag(ITM_FLAG_2HD_SWD))
        texture = texture + "_2H";

      return;
    }

    // Ranged
    if (item->HasFlag(ITM_CAT_FF))
    {
      if (item->HasFlag(ITM_FLAG_BOW))
      {
        color = zCOLOR(26, 188, 156);
        texture = "WPN_BOW"; // https://game-icons.net/1x1/lorc/high-shot.html
        return;
      }

      if (item->HasFlag(ITM_FLAG_CROSSBOW))
      {
        color = zCOLOR(255, 168, 1);
        texture = "WPN_CROSSBOW"; // https://game-icons.net/1x1/carl-olsen/crossbow.html
        return;
      }
    }

    // Munition
    if (item->HasFlag(ITM_CAT_MUN))
    {
      color = grey;

      if (item->HasFlag(ITM_FLAG_BOW))
      {
        texture = "MUN_BOW"; // https://game-icons.net/1x1/lorc/stone-spear.html
        return;
      }

      if (item->HasFlag(ITM_FLAG_CROSSBOW))
      {
        texture = "MUN_CROSSBOW"; // https://game-icons.net/1x1/lorc/arrowhead.html
        return;
      }
    }

    // Shield
    if (item->HasFlag(ITM_FLAG_SHIELD))
    {
      color = zCOLOR(247, 143, 179);
      texture = "SHIELD"; // https://game-icons.net/1x1/lorc/checked-shield.html
      return;
    }

    // Armors
    if (item->HasFlag(ITM_CAT_ARMOR))
    {
      if (item->wear == ITM_WEAR_HEAD)
      {
        color = grey;
        texture = "ARM_HELMET"; // https://game-icons.net/1x1/lorc/visored-helm.html
        return;
      }

      if (condAtr == NPC_ATR_DEXTERITY)
      {
        color = dexGreen;
        texture = "ARM_DEX"; // https://game-icons.net/1x1/delapouite/leather-armor.html
        return;
      }

      if (condAtr == NPC_ATR_MANAMAX)
      {
        color = manaBlue;
        texture = "ARM_MANA"; // https://game-icons.net/1x1/delapouite/ninja-armor.html
        return;
      }

      color = strRed;
      texture = "ARM_STR"; // https://game-icons.net/1x1/lorc/lamellar.html
      return;
    }

    if (item->HasFlag(ITM_FLAG_AMULET) && !item->HasFlag(ITM_CAT_NONE))
    {
      color = zCOLOR(190, 46, 221);
      texture = "AMULET"; // https://game-icons.net/1x1/lorc/gem-chain.html
      return;
    }

    if (item->HasFlag(ITM_FLAG_RING) && !item->HasFlag(ITM_CAT_NONE))
    {
      color = zCOLOR(72, 52, 212);
      texture = "RING"; // https://game-icons.net/1x1/delapouite/power-ring.html
      return;
    }

#if ENGINE == Engine_G2A
    if (item->HasFlag(ITM_FLAG_BELT) && !item->HasFlag(ITM_CAT_NONE))
    {
      color = zCOLOR(61, 193, 211);
      texture = "BELT"; // https://game-icons.net/1x1/lorc/belt-buckles.html
      return;
    }
#endif

    if (item->HasFlag(ITM_CAT_FOOD))
    {
      if (item->GetSoundMaterial() == SND_MAT_GLAS)
      {
        color = lightBronze;
        texture = "FOOD_DRINK"; // https://game-icons.net/1x1/delapouite/magic-potion.html
        return;
      }

      if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITPL") || Union::StringANSI(item->GetInstanceName()).StartsWith("ITFO_PLANTS"))
      {
        color = zCOLOR(46, 204, 113);
        texture = "FOOD_HERB"; // https://game-icons.net/1x1/lorc/tree-branch.html
        return;
      }

      color = lightBronze;
      texture = "FOOD_ELSE"; // https://game-icons.net/1x1/lorc/chicken-leg.html
      return;
    }

    if (item->HasFlag(ITM_CAT_POTION))
    {
      color = zCOLOR(155, 89, 182);
      texture = "POTION"; // https://game-icons.net/1x1/lorc/fire-bottle.html
      return;
    }

    if (item->HasFlag(ITM_CAT_RUNE))
    {
      if (!item->HasFlag(ITM_FLAG_MULTI))
      {
        color = zCOLOR(217, 128, 250);
        texture = "RUNE"; // https://game-icons.net/1x1/lorc/cursed-star.html
        return;
      }

      color = zCOLOR(237, 76, 103);
      texture = "SPELL"; // https://game-icons.net/1x1/skoll/pentacle.html
      return;
    }

    if (item->HasFlag(ITM_CAT_MAGIC))
    {
      color = zCOLOR(253, 167, 223);
      texture = "MAGIC"; // https://game-icons.net/1x1/lorc/triorb.html
      return;
    }

    if (item->HasFlag(ITM_CAT_DOCS))
    {
      if (item->GetSoundMaterial() == SND_MAT_STONE)
      {
        color = grey;
        texture = "TABLET"; // https://game-icons.net/1x1/lorc/stone-tablet.html
      }
      else if (Union::StringANSI(item->GetInstanceName()).Contains("MAP"))
      {
        color = goldYellow;
        texture = "MAP"; // https://game-icons.net/1x1/lorc/treasure-map.html
      }
      else
      {
        color = zCOLOR(153, 128, 250);
        texture = "DOCS"; // https://game-icons.net/1x1/lorc/tied-scroll.html
      }

      color = (!playerStatus->KnowStateFunc(item)) ? statePink : color;
      return;
    }

    if (item->HasFlag(ITM_FLAG_TORCH))
    {
      color = zCOLOR(240, 147, 43);
      texture = "TORCH"; // https://game-icons.net/1x1/delapouite/torch.html
      return;
    }

    static const auto TRADE_CURRENCY_INSTANCE = parser->GetSymbol("TRADE_CURRENCY_INSTANCE");
    if (TRADE_CURRENCY_INSTANCE && TRADE_CURRENCY_INSTANCE->stringdata == &item->GetInstanceName())
    {
      color = goldYellow;
      texture = "MONEY"; // https://game-icons.net/1x1/delapouite/two-coins.html
      return;
    }

    if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITSE"))
    {
      color = goldYellow;
      texture = "SECRET"; // https://game-icons.net/1x1/lorc/cash.html
      return;
    }

    if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITKE"))
    {
      color = zCOLOR(113, 128, 147);
      texture = "KEY"; // https://game-icons.net/1x1/lorc/key.html
    }

    if (Union::StringANSI(item->GetInstanceName()).StartsWith("ITAT"))
    {
      color = lightBronze;
      texture = "TROPHY"; // https://game-icons.net/1x1/lorc/flat-paw-print.html
    }

#if ENGINE >= Engine_G2
    if (Union::StringANSI(item->GetInstanceName()).Contains("SILVER") || Union::StringANSI(item->GetInstanceName()).Contains("GOLD"))
    {
      color = zCOLOR(72, 219, 251);
      texture = "VALUABLES"; // https://game-icons.net/1x1/lorc/cut-diamond.html
    }
#endif

    if (item->GetStateFunc() != Invalid)
      color = statePink;
  }

  ItemLabel::ItemLabel(oCItem *renderedItem, zCViewBase *viewBase)
  {
    item = renderedItem;

    if (!CanDrawLabel())
      return;

    zCView *itemView = dynamic_cast<zCView *>(viewBase);
    if (!itemView)
      return;

    SetLabelParams();

    int startPos = (item == player->inventory2.GetSelectedItem()) ? 500 : 250;

    int endPos = startPos + 2000 * zUtilitiesOptions->LabelScale;

    zCView *labelView = new zCView(startPos, startPos, endPos, endPos);
    labelView->InsertBack("LABEL_" + texture);
    labelView->SetAlphaBlendFunc(zRND_ALPHA_FUNC_BLEND);
    labelView->SetTransparency(255);
    labelView->SetColor(color);
    itemView->InsertItem(labelView);
    labelView->Blit();
    delete labelView;
  }
}