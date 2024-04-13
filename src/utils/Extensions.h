// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  int GetTopDmgIndex(int damageArr[], int damagetype)
  {
    int topDmgAmount = 0, topDmgIndex = 0;

    for (int i = 0; i < (int)oEDamageIndex::oEDamageIndex_MAX; i++)
      if ((oEDamageType)(1 << (oEDamageIndex)i) & damagetype)
        if (damageArr[i] >= topDmgAmount)
        {
          topDmgAmount = damageArr[i];
          topDmgIndex = i;
        }

    return topDmgIndex;
  }

  int oCItem::GetHighestCond()
  {
    int maxCond = 0;
    int maxIndex = -1;

    for (int i = 0; i < ITM_COND_MAX; i++)
      if (this->cond_value[i] > maxCond)
      {
        maxIndex = i;
        maxCond = this->cond_value[i];
      }

    return (maxIndex != -1) ? this->cond_atr[maxIndex] : -1;
  }

  int oCItem::GetStateFunc()
  {
    for (int i = 0; i < ITM_STATE_MAX; i++)
      if (this->onState[i])
        return this->onState[i];

    return Invalid;
  }

  int oCItem::GetLineTextIsIn(zSTRING str)
  {
    for (int i = 0; i < ITM_TEXT_MAX; i++)
      if (text[i] == str)
        return i;

    return Invalid;
  }

  int oCNpc::GetAivar(zSTRING aivar)
  {
    auto sym = parser->GetSymbol(aivar);
    if (!sym)
      return 0;

    return this->aiscriptvars[sym->single_intdata];
  }

  int oCNpc::GetFistDamageIndex()
  {
    return GetTopDmgIndex(this->damage, this->damagetype);
  }

  int oCNpc::GetWeaponDamageIndex()
  {
    oCItem *weapon = this->GetWeapon();

    if (!weapon)
      return Invalid;

    int index = GetTopDmgIndex(weapon->damage, weapon->damageTypes);

    if (!weapon->HasFlag(ITM_CAT_FF) || weapon->munition <= 0)
      return index;

    oCItem *munition = this->GetHandMunition();

    if (!munition)
      return index;

    if (munition->instanz != weapon->munition)
      return index;

    return GetTopDmgIndex(munition->damage, munition->damageTypes);
  }

  int oCNpc::GetSpellDamageIndex()
  {
    oCMag_Book *book = this->mag_book;

    if (!book)
      return Invalid;

    oCSpell *spell = book->GetSelectedSpell();

    if (!spell)
      return Invalid;

    for (int i = 0; i < oEIndexDamage::oEDamageIndex_MAX; i++)
      if ((oETypeDamage)(1 << (oEIndexDamage)i) & spell->damageType)
        return i;

    return Invalid;
  }

  int oCNpc::GetActiveDamageIndex()
  {
    if (this->IsInFightMode_S(NPC_WEAPON_FIST))
      return this->GetFistDamageIndex();

    if (this->IsInFightMode_S(NPC_WEAPON_MAG))
      return this->GetSpellDamageIndex();

    return this->GetWeaponDamageIndex();
  }

  oCPortalRoom *zCVob::GetCurrentPortalRoom()
  {
    oCPortalRoomManager *rooms = ogame->GetPortalRoomManager();

    if (!rooms)
      return nullptr;

    const zSTRING *portalName = this->GetSectorNameVobIsIn();

    if (!portalName)
      return nullptr;

    int portalIndex = rooms->GetPortalRoomIndex(*portalName);

    if (portalIndex == Invalid)
      return nullptr;

    return rooms->portals[portalIndex];
  }

  bool zCVob::IsInRoomWith(zCVob *vob)
  {
    oCPortalRoom *room = this->GetCurrentPortalRoom();
    if (room == nullptr)
      return false;

    return room == vob->GetCurrentPortalRoom();
  }

  float zCVob::GetHeightDifferenceToVob(zCVob *vob)
  {
    return std::abs(this->GetPositionWorld()[VY] - vob->GetPositionWorld()[VY]);
  }

  oCItem *oCNpc::GetHandMunition()
  {
    oCItem *weapon = this->GetWeapon();

    if (!weapon)
      return nullptr;

    if (!weapon->HasFlag(ITM_CAT_FF) || weapon->munition <= 0)
      return nullptr;

    return (weapon->HasFlag(ITM_FLAG_CROSSBOW)) ? this->GetLeftHand()->CastTo<oCItem>() : this->GetRightHand()->CastTo<oCItem>();
  }
}