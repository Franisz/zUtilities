// Supported with union ( c ) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  void DebugHelper::InfoNpc(oCNpc *npc)
  {
    // LEFT SIDE
    Print(leftView, "--- " + npc->_GetClassDef()->className, (zSTRING)Union::StringANSI::Format("{0} ({1})", npc->GetInstanceName(), npc->instanz));
    Print(leftView, "Name", npc->GetName(0));
    Print(leftView, "Level", npc->level);
    Print(leftView, "Guild", (zSTRING)Union::StringANSI::Format("{0} ({1})", npc->GetGuildName(), npc->GetGuild()));
    Print(leftView, "Voice", npc->voice);
    Print(leftView, "Flags", npc->variousFlags);
    Print(leftView, "NpcType", npc->npcType);
    Print(leftView, "Attitude", npc->GetAttitude(player));
    Print(leftView, "PermAttitude", npc->GetPermAttitude(player));
    Print(leftView, "SensesRange", npc->senses_range);
    Print(leftView, "DetectedPlayer", npc->HasVobDetected(player));
    Print(leftView, "DistToPlayer", (int)npc->GetDistanceToVob(*player));

    AddSeparator(leftView, "Fight AI");
    Print(leftView, "FightMode", npc->fmode);
    Print(leftView, "FightTactic", npc->fighttactic);
    Print(leftView, "FightRangeBase", npc->GetFightRangeBase());
    Print(leftView, "FightRangeFist", npc->GetFightRangeFist());
    Print(leftView, "FightRangeDynamic", npc->GetFightRangeDynamic());
    Print(leftView, "FightRange", npc->GetFightRange());
    if (npc->enemy != nullptr)
      Print(leftView, "Enemy", npc->enemy->GetInstanceName());

    AddSeparator(leftView, "Visual/Armor");
    if (zCVisual *visual = npc->GetVisual())
    {
      Print(leftView, "VisualFile", visual->GetVisualName());
      Print(leftView, "ModelScale", (zSTRING)Union::StringANSI::Format("{0} {1} {2}", npc->model_scale[VX], npc->model_scale[VY], npc->model_scale[VZ]));
      Print(leftView, "BodyName", npc->GetVisualBody());
      Print(leftView, "HeadName", npc->GetVisualHead());
#if ENGINE == Engine_G2A
      Print(leftView, "EffectName", npc->effect);
#endif
    }

    if (oCItem *armor = npc->GetEquippedArmor())
    {
      Print(leftView, "VisualChange", armor->GetVisualChange());
#if ENGINE == Engine_G2A
      Print(leftView, "EffectName", armor->GetEffectName());
#endif
    }

    AddSeparator(leftView, "Routine");
    Print(leftView, "Waypoint", npc->wpname);
    if (auto sym = parser->GetSymbol(npc->GetAIState()))
    {
      Print(leftView, "AIState", sym->name);
    }
    else
    {
      Print(leftView, "AIState", npc->GetAIState());
    }
    if (auto sym = parser->GetSymbol(npc->daily_routine))
    {
      Print(leftView, "DailyRoutine", sym->name);
    }
    else
    {
      Print(leftView, "DailyRoutine", npc->daily_routine);
    }

    // RIGHT SIDE
    AddSeparator(rightView, "Attributes");
    Print(rightView, "HP", (zSTRING)Union::StringANSI::Format("{0}/{1}", npc->GetAttribute(NPC_ATR_HITPOINTS), npc->GetAttribute(NPC_ATR_HITPOINTSMAX)));
    Print(rightView, "MANA", (zSTRING)Union::StringANSI::Format("{0}/{1}", npc->GetAttribute(NPC_ATR_MANA), npc->GetAttribute(NPC_ATR_MANAMAX)));
    Print(rightView, "STR", npc->GetAttribute(NPC_ATR_STRENGTH));
    Print(rightView, "DEX", npc->GetAttribute(NPC_ATR_DEXTERITY));

    AddSeparator(rightView, "Fight talents");
#if ENGINE >= Engine_G2
    Print(rightView, "1H", npc->GetHitChance(NPC_HITCHANCE_1H));
    Print(rightView, "2H", npc->GetHitChance(NPC_HITCHANCE_2H));
    Print(rightView, "BOW", npc->GetHitChance(NPC_HITCHANCE_BOW));
    Print(rightView, "CBOW", npc->GetHitChance(NPC_HITCHANCE_CROSSBOW));
#else
    Print(rightView, "1H", npc->GetTalentValue(NPC_HITCHANCE_1H));
    Print(rightView, "2H", npc->GetTalentValue(NPC_HITCHANCE_2H));
    Print(rightView, "BOW", npc->GetTalentValue(NPC_HITCHANCE_BOW));
    Print(rightView, "CBOW", npc->GetTalentValue(NPC_HITCHANCE_CROSSBOW));
#endif

    AddSeparator(rightView, "Damage");
    Print(rightView, "DAM_EDGE", npc->GetDamageByIndex(oEDamageIndex_Edge));
    Print(rightView, "DAM_BLUNT", npc->GetDamageByIndex(oEDamageIndex_Blunt));
    Print(rightView, "DAM_POINT", npc->GetDamageByIndex(oEDamageIndex_Point));
    Print(rightView, "DAM_FIRE", npc->GetDamageByIndex(oEDamageIndex_Fire));
    Print(rightView, "DAM_MAGIC", npc->GetDamageByIndex(oEDamageIndex_Magic));
    Print(rightView, "DAM_FLY", npc->GetDamageByIndex(oEDamageIndex_Fly));
    Print(rightView, "DAM_FALL", npc->GetDamageByIndex(oEDamageIndex_Fall));
    Print(rightView, "DamageType", npc->damagetype);

    AddSeparator(rightView, "Protection");
    Print(rightView, "PROT_EDGE", npc->GetProtectionByIndex(oEDamageIndex_Edge));
    Print(rightView, "PROT_BLUNT", npc->GetProtectionByIndex(oEDamageIndex_Blunt));
    Print(rightView, "PROT_POINT", npc->GetProtectionByIndex(oEDamageIndex_Point));
    Print(rightView, "PROT_FIRE", npc->GetProtectionByIndex(oEDamageIndex_Fire));
    Print(rightView, "PROT_MAGIC", npc->GetProtectionByIndex(oEDamageIndex_Magic));
    Print(rightView, "PROT_FLY", npc->GetProtectionByIndex(oEDamageIndex_Fly));
    Print(rightView, "PROT_FALL", npc->GetProtectionByIndex(oEDamageIndex_Fall));
  }

  void DebugHelper::InfoItem(oCItem *item)
  {
    Print(leftView, "--- " + item->_GetClassDef()->className, (zSTRING)Union::StringANSI::Format("{0} ({1})", item->GetInstanceName(), item->instanz));
    Print(leftView, "Name", item->name);
    Print(leftView, "Description", item->GetDescription());
    Print(leftView, "Value", item->GetValue());
    Print(leftView, "Owner", item->owner);
    if (item->ownerGuild)
      Print(leftView, "OwnerGuild", (zSTRING)Union::StringANSI::Format("{0} ({1})", ogame->GetGuilds()->GetGuildName(item->ownerGuild), item->ownerGuild));
    Print(leftView, "SchemeName", item->GetSchemeName());
    Print(leftView, "Material", item->GetSoundMaterial());
    if (auto symbol = parser->GetSymbol(item->GetStateFunc()))
      Print(leftView, "onState", symbol->name);

    if (item->HasFlag(ITM_CAT_ARMOR) || item->HasFlag(ITM_CAT_NF) || item->HasFlag(ITM_CAT_FF) || item->HasFlag(ITM_CAT_MUN))
    {
      Print(leftView, "Range", item->range);

      AddSeparator(rightView, "Damage");
      Print(rightView, "DAM_EDGE", item->GetDamageByIndex(oEDamageIndex_Edge));
      Print(rightView, "DAM_BLUNT", item->GetDamageByIndex(oEDamageIndex_Blunt));
      Print(rightView, "DAM_POINT", item->GetDamageByIndex(oEDamageIndex_Point));
      Print(rightView, "DAM_FIRE", item->GetDamageByIndex(oEDamageIndex_Fire));
      Print(rightView, "DAM_MAGIC", item->GetDamageByIndex(oEDamageIndex_Magic));
      Print(rightView, "DAM_FLY", item->GetDamageByIndex(oEDamageIndex_Fly));
      Print(rightView, "DAM_FALL", item->GetDamageByIndex(oEDamageIndex_Fall));
      Print(rightView, "TotalDamage", item->damageTotal);
      Print(rightView, "DamageTypes", item->damageTypes);

      AddSeparator(rightView, "Protection");
      Print(rightView, "PROT_EDGE", item->GetProtectionByIndex(oEDamageIndex_Edge));
      Print(rightView, "PROT_BLUNT", item->GetProtectionByIndex(oEDamageIndex_Blunt));
      Print(rightView, "PROT_POINT", item->GetProtectionByIndex(oEDamageIndex_Point));
      Print(rightView, "PROT_FIRE", item->GetProtectionByIndex(oEDamageIndex_Fire));
      Print(rightView, "PROT_MAGIC", item->GetProtectionByIndex(oEDamageIndex_Magic));
      Print(rightView, "PROT_FLY", item->GetProtectionByIndex(oEDamageIndex_Fly));
      Print(rightView, "PROT_FALL", item->GetProtectionByIndex(oEDamageIndex_Fall));
    }
    else if (item->spell)
    {
      AddSeparator(rightView, "Spell");
      Print(rightView, "SpellID", item->spell);
      Print(rightView, "Circle", item->mag_circle);

      oCSpell *spl = new oCSpell(item->spell);
      Print(rightView, "SpellName", spl->GetName());
      spl->Release();
    }

    AddSeparator(leftView, "Flags");
    Print(leftView, "Mainflag", item->mainflag);
    Print(leftView, "Flags", item->flags);

    AddSeparator(leftView, "Requirements");
    for (int i = 0; i < ITM_COND_MAX; i++)
    {
      if (!item->cond_atr[i])
        continue;
      Print(leftView, GetAttributeName(item->cond_atr[i]), item->cond_value[i]);
    }

    if (zCVisual *visual = item->GetVisual())
    {
      AddSeparator(leftView, "Visual");
      Print(leftView, "VisualFile", visual->GetVisualName());
      Print(leftView, "VisualChange", item->GetVisualChange());
#if ENGINE == Engine_G2A
      Print(leftView, "EffectName", item->GetEffectName());
#endif
    }
  }

  void DebugHelper::InfoMob(oCMOB *mob)
  {
    Print(leftView, "--- " + mob->_GetClassDef()->className, mob->name);
    Print(leftView, "Name", mob->GetName());
    Print(leftView, "Owner", mob->ownerStr);
    Print(leftView, "ScemeName", mob->GetScemeName());

    if (oCMobInter *inter = mob->CastTo<oCMobInter>())
    {
      AddSeparator(leftView, "Inter");
      Print(leftView, "TriggerTarget", inter->triggerTarget);
      Print(leftView, "UseItem", inter->useWithItem);
      Print(leftView, "ConditionFuncName", inter->conditionFunc);
      Print(leftView, "OnStateFuncName", inter->onStateFuncName);
    }

    if (oCMobLockable *lockable = mob->CastTo<oCMobLockable>())
    {
      AddSeparator(rightView, "Lockable");
      Print(rightView, "KeyInstance", lockable->keyInstance);
      Print(rightView, "LockString", lockable->pickLockStr);
      Print(rightView, "Locked", zSTRING(lockable->locked));
    }

    if (zCVisual *visual = mob->GetVisual())
    {
      AddSeparator(leftView, "Visual");
      Print(leftView, "VisualFile", visual->GetVisualName());
    }

    if (oCMobContainer *container = mob->CastTo<oCMobContainer>())
    {
      if (auto list = container->containList.GetNextInList())
      {
        int itemCount = container->containList.GetNumInList();
        int printedItems = 0;

        AddSeparator(leftView, "Container");
        while (list != nullptr)
        {
          Print(leftView, list->GetData()->name, zSTRING(list->GetData()->amount));

          printedItems++;
          if (itemCount > 15 && printedItems >= 15)
          {
            Print(leftView, "", "And " + zSTRING(itemCount - printedItems) + " more...");
            break;
          }

          list = list->GetNextInList();
        }
      }
    }
  }

  void DebugHelper::AddSeparator(zCView *view, zSTRING str)
  {
    int textLines;

    if (view == leftView)
      textLinesLeft++;
    else if (view == rightView)
      textLinesRight++;

    if (!str.Length())
      return;

    if (view == rightView)
    {
      textLinesRight++;

      textLines = textLinesRight;
    }
    else
    {
      textLinesLeft++;

      textLines = textLinesLeft;
    }

    view->Print(0, textHeight * textLines, "--- " + str);
  }

  void DebugHelper::Print(zCView *view, zSTRING name, zSTRING value)
  {
    if (!value.Length())
      value = "-";

    zSTRING text = (name.Length()) ? name + ": " + value : value;
    int textLines;
    if (view == rightView)
    {
      textLinesRight++;
      textLines = textLinesRight;
    }
    else
    {
      textLinesLeft++;
      textLines = textLinesLeft;
    }

    view->Print(0, textHeight * textLines, text);
  }

  bool DebugHelper::TryPrintInfo()
  {
    if (player->inventory2.IsOpen())
      if (oCItem *item = player->inventory2.GetSelectedItem())
      {
        InfoItem(item);
        return true;
      }

    zCVob *vob = player->GetFocusVob();
    if (!vob)
      return false;

    if (oCNpc *npc = vob->CastTo<oCNpc>())
      InfoNpc(npc);
    else if (oCItem *item = vob->CastTo<oCItem>())
      InfoItem(item);
    else if (oCMOB *mob = vob->CastTo<oCMOB>())
      InfoMob(mob);

    return true;
  }

  void DebugHelper::Clear()
  {
    if (mainView == nullptr)
      return;

    del(leftView);
    del(rightView);
    del(mainView);
  }

  void DebugHelper::ShowTriggerBoxes()
  {
    if (!Options::ShowTriggers)
    {
      return;
    }

    zCArray<zCVob *> listVobs;
    player->CreateVobList(listVobs, 5000.0f);
    for (int i = 0; i < listVobs.GetNumInList(); i++)
    {
      auto vob = listVobs[i];

      if (!vob)
        continue;

      auto trigger = vob->CastTo<zCTrigger>();
      if (!trigger)
        continue;

      trigger->bbox3D.Draw(GFX_RED);
    }
  }

  void DebugHelper::Loop()
  {
    if (!Options::UsingDebugHelper || ogame->pause_screen || PlayerHelper::IsConUp() || quickSave->IsBusy() || !ogame->game_drawall || PlayerHelper::LeftInvOpen())
    {
      Clear();
      return;
    }

    if (mainView == nullptr)
    {
      int offset = 512 * PlayerHelper::GetSysScale();

      mainView = new zCView(0, 1024 - offset, 3456 + offset, 7168 + offset);
      mainView->InsertBack("BLACKBACK");
      mainView->SetAlphaBlendFunc(zRND_ALPHA_FUNC_BLEND);
      mainView->SetTransparency(150);
      screen->InsertItem(mainView);

      textHeight = mainView->FontY();
      margin = textHeight;

      leftView = new zCView(margin, 0, 8192 - margin, 8192);
      rightView = new zCView(margin + 8192 * 0.6f, 0, 8192 - margin, 8192);
      mainView->InsertItem(leftView);
      mainView->InsertItem(rightView);
    }

    leftView->ClrPrintwin();
    rightView->ClrPrintwin();
    textLinesLeft = 0;
    textLinesRight = 0;

    ShowTriggerBoxes();

    if (TryPrintInfo())
      return;

    Clear();
  }
}