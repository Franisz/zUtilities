// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  oCItem *lastActiveMunition;

  void HandleMunition(oCItem *weapon)
  {
    if (weapon == nullptr)
    {
      if (lastActiveMunition)
      {
        lastActiveMunition->ClearFlag(ITM_FLAG_ACTIVE);
        lastActiveMunition = nullptr;
      }
      return;
    }

    player->inventory2.UnpackAllItems();
    oCItem *munition = player->IsInInv(weapon->munition, 1);

    if (!munition)
      return;

    if (munition->HasFlag(ITM_FLAG_ACTIVE))
      return;

    munition->SetFlag(ITM_FLAG_ACTIVE);

    if (lastActiveMunition)
      if (lastActiveMunition != munition)
        lastActiveMunition->ClearFlag(ITM_FLAG_ACTIVE);

    lastActiveMunition = munition;
  }

  void HandleMunitionLoop()
  {
    if (!Options::ActivateUsedMunition)
      return;

    if (!player->inventory2.IsOpen())
      return;

    if (lastActiveMunition)
    {
      if (player->inventory2.IsIn(lastActiveMunition, 1) == nullptr && player->GetLeftHand() != lastActiveMunition && player->GetRightHand() != lastActiveMunition)
      {
        lastActiveMunition = nullptr;
      }
    }

    if (playerStatus->traderNpc)
    {
      HandleMunition(nullptr);
      return;
    }

    oCItem *weapon = player->GetEquippedRangedWeapon();

    if (!weapon)
      weapon = player->GetWeapon();

    if (!weapon || !weapon->HasFlag(ITM_CAT_FF) || !weapon->munition)
    {
      HandleMunition(nullptr);
      return;
    }

    if (lastActiveMunition && weapon->munition == lastActiveMunition->instanz)
      return;

    HandleMunition(weapon);
  }

  void __fastcall oCInformationManager_OnTradeBegin(oCInformationManager *_this);
  auto Hook_oCInformationManager_OnTradeBegin = CreateHook(reinterpret_cast<void *>(zSwitch(0x0072E130, 0x0076C770, 0x00779C40, 0x00662E60)), &oCInformationManager_OnTradeBegin);
  void __fastcall oCInformationManager_OnTradeBegin(oCInformationManager *_this)
  {
    Hook_oCInformationManager_OnTradeBegin(_this);

    playerStatus->traderNpc = _this->Npc;
  }

  // void __fastcall oCItemContainer_Close(oCItemContainer *_this);
  // auto Hook_oCItemContainer_Close = CreateHook(reinterpret_cast<void *>(zSwitch(0x00668C10, 0x00696770, 0x006AB440, 0x00708F30)), &oCItemContainer_Close);
  // void __fastcall oCItemContainer_Close(oCItemContainer *_this)
  // {
  //   playerStatus->traderNpc = nullptr;
  //   Hook_oCItemContainer_Close(_this);
  // }
}