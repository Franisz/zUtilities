// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
#if ENGINE >= Engine_G2
  std::vector<oCVisualFX *> vfxs;

  void __fastcall oCVisualFX_InitEffect(oCVisualFX *_this);
  auto Hook_oCVisualFX_InitEffect = CreateHook(reinterpret_cast<void *>(zSwitch(0x0048C290, 0x00497B80, 0x00492950, 0x004943E0)), &oCVisualFX_InitEffect);
  void __fastcall oCVisualFX_InitEffect(oCVisualFX *_this)
  {
    if (_this->visName_S.Search(".SLW", 1) == -1)
    {
      Hook_oCVisualFX_InitEffect(_this);
      return;
    }

    vfxs.push_back(_this);
    playerStatus->ResetTimeMultiplier();
    Hook_oCVisualFX_InitEffect(_this);
  }

  void __fastcall oCVisualFX_EndEffect(oCVisualFX *_this, void *vtable, int kill);
  auto Hook_oCVisualFX_EndEffect = CreateHook(reinterpret_cast<void *>(zSwitch(0x0048C6A0, 0x00498050, 0x004930A0, 0x00494C80)), &oCVisualFX_EndEffect);
  void __fastcall oCVisualFX_EndEffect(oCVisualFX *_this, void *vtable, int kill)
  {
    if (_this->visName_S.Search(".SLW", 1) == -1)
    {
      Hook_oCVisualFX_EndEffect(_this, vtable, kill);
      return;
    }

    auto it = std::find(vfxs.begin(), vfxs.end(), _this);
    if (it != vfxs.end())
    {
      vfxs.erase(std::remove(vfxs.begin(), vfxs.end(), _this), vfxs.end());
    }

    Hook_oCVisualFX_EndEffect(_this, vtable, kill);
  }
#endif

  bool PlayerStatus::CanChangeZtimer()
  {
#if ENGINE >= Engine_G2
    return vfxs.empty();
#endif
    return true;
  }

  void __fastcall oCMobInter_CallOnStateFunc(oCMobInter *_this, void *vtable, oCNpc *npc, int a1);
  auto Hook_oCMobInter_CallOnStateFunc = CreateHook(reinterpret_cast<void *>(zSwitch(0x0067EF60, 0x006AE040, 0x006C27E0, 0x00720870)), &oCMobInter_CallOnStateFunc);
  void __fastcall oCMobInter_CallOnStateFunc(oCMobInter *_this, void *vtable, oCNpc *npc, int a1)
  {
    Hook_oCMobInter_CallOnStateFunc(_this, vtable, npc, a1);

    if (npc == player)
      playerStatus->TryAddStateFunc(_this);
  }

  int __fastcall oCItem_GetStateEffectFunc(oCItem *_this, void *vtable, int a1);
  auto Hook_oCItem_GetStateEffectFunc = CreateHook(reinterpret_cast<void *>(zSwitch(0x00672420, 0x0069FDE0, 0x006B4D80, 0x00712B80)), &oCItem_GetStateEffectFunc);
  int __fastcall oCItem_GetStateEffectFunc(oCItem *_this, void *vtable, int a1)
  {
    int result = Hook_oCItem_GetStateEffectFunc(_this, vtable, a1);
    playerStatus->stateFuncItem = (a1 == 0) ? _this : nullptr;
    return result;
  }

  int __fastcall oCNpc_EV_UseItemToState(oCNpc *_this, void *vtable, oCMsgManipulate *msg);
  auto Hook_oCNpc_EV_UseItemToState = CreateHook(reinterpret_cast<void *>(zSwitch(0x006AFC70, 0x006E3AF0, 0x006F6AC0, 0x007558F0)), &oCNpc_EV_UseItemToState);
  int __fastcall oCNpc_EV_UseItemToState(oCNpc *_this, void *vtable, oCMsgManipulate *msg)
  {
    int result = Hook_oCNpc_EV_UseItemToState(_this, vtable, msg);

    if (_this == player && msg && msg->targetVob && playerStatus->stateFuncItem && playerStatus->stateFuncItem == msg->targetVob)
    {
      playerStatus->TryAddStateFunc(msg->targetVob);
      playerStatus->stateFuncItem = nullptr;
    }

    return result;
  }

  void PlayerStatus::GetPickpocketInfos()
  {
    auto list = ogame->GetInfoManager()->infoList.next;
    while (list)
    {
      auto info = list->data;
      list = list->next;

      auto name = Union::StringANSI(info->name);

      // Whenever the icon will visible or not is based on the npc dialogue including PICKPOCKET word which seems to be used consistently in mods as well.
      if (!name.Contains("PICKPOCKET") && !name.Contains("_STEAL") && !name.Contains("PICKME"))
        continue;

      if (name.Contains("_DOIT") || name.Contains("_TRY"))
        continue;

      // To avoid targeting possible dialogues related to pickpocketing quests or teach options.
      if (parser->GetIndex(info->name + "_DOIT") == Invalid && parser->GetIndex(info->name + "_TRY") == Invalid)
        continue;

      if (!pickpocketInfos.IsInList(info))
        pickpocketInfos.Insert(info);
    }
  }

  bool PlayerStatus::CanPickpocketNpc(oCNpc *npc)
  {
    // auto sym = parser->GetSymbol( "NPC_TALENT_PICKPOCKET" );
    // if ( !sym )
    //   return false;

    // if ( !player->GetTalentSkill( sym->single_intdata ) )
    //   return false;

    // if ( npc->GetAivar( "AIV_PLAYERHASPICKEDMYPOCKET" ) )
    //   return false;

    if (npc->attribute[NPC_ATR_HITPOINTS] <= 0)
      return false;

    for (int i = 0; i < pickpocketInfos.GetNumInList(); i++)
    {
      auto info = pickpocketInfos[i];

      if (info->GetNpcID() != npc->GetInstance())
        continue;

      parser->SetInstance("SELF", npc);
      parser->SetInstance("OTHER", player);

      return info->InfoConditions();
    }

    return false;
  }

  bool PlayerStatus::KnowStateFunc(zCVob *vob)
  {
    if (!vob)
      return false;

    if (oCItem *item = vob->CastTo<oCItem>())
    {
      if (stateFuncItems.IsInList(item->GetInstanceName()))
        return true;

      int index = item->GetStateFunc();
      if (index == Invalid)
        return true;

      for (int i = 0; i < interStateFuncs.GetNumInList(); i++)
      {
        int idx = parser->GetIndex(interStateFuncs[i] + "_s1");
        if (idx == index)
          return true;
      }
    }
    else if (oCMobInter *inter = vob->CastTo<oCMobInter>())
    {
      if (interStateFuncs.IsInList(inter->onStateFuncName))
        return true;

      int index = parser->GetIndex(inter->onStateFuncName + "_s1");
      if (index == Invalid)
        return true;

      for (int i = 0; i < stateFuncItems.GetNumInList(); i++)
      {
        oCItem *itm = new oCItem(stateFuncItems[i], 1);
        if (!itm)
          continue;
        int idx = itm->GetStateFunc();
        itm->Release();
        if (idx == index)
          return true;
      }
    }

    return false;
  }

  void PlayerStatus::TryAddStateFunc(zCVob *vob)
  {
    if (!vob)
      return;

    if (KnowStateFunc(vob))
      return;

    if (oCItem *item = vob->CastTo<oCItem>())
      stateFuncItems.Insert(item->GetInstanceName());
    else if (oCMobInter *inter = vob->CastTo<oCMobInter>())
      interStateFuncs.Insert(inter->onStateFuncName);
  }

  void PlayerStatus::Archive(zCArchiver *ar)
  {
    ar->WriteInt("interStateFuncsCount", interStateFuncs.GetNum());
    for (int i = 0; i < interStateFuncs.GetNum(); i++)
      ar->WriteString("interStateFuncs", interStateFuncs[i]);

    ar->WriteInt("stateFuncItemsCount", stateFuncItems.GetNum());
    for (int i = 0; i < stateFuncItems.GetNum(); i++)
      ar->WriteString("stateFuncItems", stateFuncItems[i]);
  }

  void PlayerStatus::Unarchive(zCArchiver *ar)
  {
    interStateFuncs.EmptyList();
    stateFuncItems.EmptyList();

    if (!ar)
      return;

    int interStateFuncsCount = ar->ReadIntSafe("interStateFuncsCount");
    for (int i = 0; i < interStateFuncsCount; i++)
      interStateFuncs.Insert(ar->ReadString("interStateFuncs"));

    int stateFuncItemsCount = ar->ReadIntSafe("stateFuncItemsCount");
    for (int i = 0; i < stateFuncItemsCount; i++)
      stateFuncItems.Insert(ar->ReadString("stateFuncItems"));
  }

#if ENGINE < Engine_G2

  void __fastcall zCAICamera_CheckKeys(zCAICamera *_this);
  auto Hook_zCAICamera_CheckKeys = CreateHook(reinterpret_cast<void *>(zSwitch(0x0049CD10, 0x004AA2C0, 0x004A20E0, 0x004A45C0)), &zCAICamera_CheckKeys);
  void __fastcall zCAICamera_CheckKeys(zCAICamera *_this)
  {
    if (!Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f || !playerStatus->CanChangeZtimer())
    {
      Hook_zCAICamera_CheckKeys(_this);
      return;
    }

    float frameTimeOld = ztimer->frameTimeFloat;
    float motionFactorOld = ztimer->factorMotion;
    ztimer->frameTimeFloat = frameTimeOld / motionFactorOld;
    ztimer->factorMotion = 1.0f;
    Hook_zCAICamera_CheckKeys(_this);
    ztimer->frameTimeFloat = frameTimeOld;
    ztimer->factorMotion = motionFactorOld;
  }

  void __fastcall oCAIHuman_PC_Turnings(oCAIHuman *_this, void *vtable, int forceRotation);
  auto Hook_oCAIHuman_PC_Turnings = CreateHook(reinterpret_cast<void *>(zSwitch(0x00614800, 0x00637660, 0x0063E0F0, 0x0069A940)), &oCAIHuman_PC_Turnings);
  void __fastcall oCAIHuman_PC_Turnings(oCAIHuman *_this, void *vtable, int forceRotation)
  {
    if (!Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f || _this->Pressed(GAME_LEFT) || _this->Pressed(GAME_RIGHT) || !playerStatus->CanChangeZtimer())
    {
      Hook_oCAIHuman_PC_Turnings(_this, vtable, forceRotation);
      return;
    }

    float frameTimeOld = ztimer->frameTimeFloat;
    float motionFactorOld = ztimer->factorMotion;
    ztimer->frameTimeFloat = frameTimeOld / motionFactorOld;
    ztimer->factorMotion = 1.0f;
    Hook_oCAIHuman_PC_Turnings(_this, vtable, forceRotation);
    ztimer->frameTimeFloat = frameTimeOld;
    ztimer->factorMotion = motionFactorOld;
  };
#endif

  void PlayerStatus::ResetTimeMultiplier()
  {
    if (!ztimer)
      return;

    ztimer->factorMotion = 1.0f;
  }

  void PlayerStatus::ResetSaveReminder()
  {
    // TODO: Handle last SaveLoadGameInfo
    // if (SaveLoadGameInfo.changeLevel)
    // {
    //   return;
    // }

    lastSaveTime = std::chrono::high_resolution_clock::now();
  }

  void PlayerStatus::FactorMotion()
  {
    if (!Options::UseTimeMultiplier)
      return;

    if (!Options::TimeMultipliers.GetCount() || PlayerHelper::IsConUp())
      return;

    if (!CanChangeZtimer())
      return;

    if (PlayerHelper::IsDead() || PlayerHelper::IsInInfo() || ogame->IsOnPause())
    {
      if (ztimer->factorMotion != 1.0f)
        ztimer->factorMotion = 1.0f;
      return;
    }

    if (!zinput->KeyToggled(Options::KeyTimeMultiplier))
    {
      if (ztimer->factorMotion != Options::TimeMultipliers[multiplierIndex])
        ztimer->factorMotion = Options::TimeMultipliers[multiplierIndex];
      return;
    }

    multiplierIndex++;
    if (multiplierIndex < 0 || multiplierIndex >= Options::TimeMultipliers.GetCount())
      multiplierIndex = 0;

    ztimer->factorMotion = Options::TimeMultipliers[multiplierIndex];
  }

  void PlayerStatus::ShowGameTime()
  {
    if (!Options::ShowGameTime && !Options::UseTimeMultiplier)
      return;

    if (PlayerHelper::LeftInvOpen() || PlayerHelper::IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->hpBar)
      return;

    zSTRING str = "";
    zCOLOR color = zCOLOR(255, 255, 255);

    if (Options::ShowGameTime)
    {
      int day, hour, min;
      ogame->GetTime(day, hour, min);
      str = (min > 9) ? Union::StringANSI::Format("{0}:{1}", hour, min) : Union::StringANSI::Format("{0}:0{1}", hour, min);
    }

    if (Options::UseTimeMultiplier && ztimer->factorMotion != 1.0f)
    {
      color = zCOLOR(255, 0, 0);
      if (str.Length())
        str = str + " ";

      str = Union::StringANSI::Format("{0}x{1}", str, ztimer->factorMotion);
    }

    if (!str.Length())
      return;

    zSTRING texture = "ICON_CLOCK"; // https://game-icons.net/1x1/lorc/empty-hourglass.html

    infoIcons++;
    color.alpha = ogame->hpBar->alpha;
    IconInfo icon = IconInfo(screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, color, texture, str);
  }

  void PlayerStatus::ShowMunitionAmount()
  {
    if (!Options::ShowMunitionAmount)
      return;

    if (PlayerHelper::LeftInvOpen() || PlayerHelper::IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->hpBar)
      return;

    oCItem *weapon = player->GetEquippedRangedWeapon();

    if (!weapon)
      weapon = player->GetWeapon();

    if (!weapon || !weapon->HasFlag(ITM_CAT_FF) || weapon->munition <= 0)
      return;

    int amount = 0;
    zCOLOR color = zCOLOR(255, 255, 255);

    player->inventory2.UnpackAllItems();
    if (oCItem *munition = player->IsInInv(weapon->munition, 1))
      amount += munition->amount;

    if (oCItem *munition = player->GetHandMunition())
      amount += munition->instanz == weapon->munition;

    if (amount == 0)
      color = zCOLOR(255, 0, 0);
    else if (amount < 10)
      color = zCOLOR(231, 76, 60);
    else if (amount < 25)
      color = zCOLOR(255, 175, 0);
    else if (amount < 50)
      color = zCOLOR(255, 218, 121);

    zSTRING texture = (weapon->HasFlag(ITM_FLAG_BOW)) ? "LABEL_MUN_BOW" : "LABEL_MUN_CROSSBOW";

    infoIcons++;
    color.alpha = ogame->hpBar->alpha;
    IconInfo icon = IconInfo(screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, color, texture, zSTRING(amount));
  }

  void PlayerStatus::ShowSaveReminder()
  {
    if (
        Options::SaveReminder == Invalid || !ogame || !player || PlayerHelper::IsBusy() || quickSave->IsBusy() || PlayerHelper::IsDead() || PlayerHelper::IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->game_drawall)
    {
      return;
    }

    auto ElapsedTime = std::chrono::high_resolution_clock::now() - lastSaveTime;
    auto ElapsedMins = std::chrono::duration_cast<std::chrono::minutes>(ElapsedTime);
    auto ElapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(ElapsedTime - ElapsedMins);
    if (ElapsedTime >= static_cast<std::chrono::minutes>(Options::SaveReminder))
    {
      zSTRING str = (ElapsedMins.count() < 10 ? "0" : "") + Union::StringANSI::Format("{0}:{1}", ElapsedMins.count(), (ElapsedSeconds.count() < 10 ? "0" : "")) + zSTRING(static_cast<int>(ElapsedSeconds.count()));

      zSTRING texture = "ICON_SAVE"; // https://game-icons.net/1x1/lorc/disc.html

      infoIcons++;
      IconInfo icon = IconInfo(screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, GFX_RED, texture, str);
    }
  }

  void PlayerStatus::StatusBars()
  {
    if (!hpBar)
      hpBar = new StatusBar(ogame->hpBar);

    if (!manaBar)
      manaBar = new StatusBar(ogame->manaBar);

    if (!focusBar)
      focusBar = new StatusBar(ogame->focusBar);

    if (!swimBar)
      swimBar = new StatusBar(ogame->swimBar);

    hpBar->Loop();
    manaBar->Loop();
    focusBar->Loop();
    swimBar->Loop();
  }

  void PlayerStatus::Clear()
  {
    focusColor->Clear();
    debugHelper->Clear();

    if (hpBar)
      hpBar->Clear();

    if (manaBar)
      manaBar->Clear();

    if (focusBar)
      focusBar->Clear();

    if (swimBar)
      swimBar->Clear();
  }

  void PlayerStatus::Loop()
  {
    if (!ogame || !player)
      return;

    if (quickSave->IsBusy())
    {
      Clear();
      return;
    }

    infoIcons = 0;

    debugHelper->Loop();
    focusColor->Loop();
    StatusBars();
    FactorMotion();
    ShowGameTime();
    ShowMunitionAmount();
    ShowSaveReminder();
    HandleMunitionLoop();
    RenderSelectedItem();
  }
}