// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  Array<DamagePopup *> popups;

#if ENGINE >= Engine_G2
  typedef struct _tiddata
  {
    static constexpr size_t _tiddata_size = 0x74;    // 116
    static constexpr size_t _holdrand_offset = 0x14; // 20
#if ENGINE == Engine_G2
    static constexpr size_t __getptd_address = 0x007C9DF1;
#else
    static constexpr size_t __getptd_address = 0x007D62B1;
#endif

    BYTE beginRawMemory[_holdrand_offset];
    unsigned long _holdrand; // rand() seed value
    BYTE endRawMemory[_tiddata_size - _holdrand_offset - sizeof(_holdrand)];
  } *_ptiddata;

  _ptiddata __getptd()
  {
    XCALL(_tiddata::__getptd_address);
  }
#endif

  bool IsCrit(oCNpc::oSDamageDescriptor &desc, int dmgRand = 0)
  {
    if (desc.pNpcAttacker == nullptr || desc.pItemWeapon == nullptr)
      return false;

    if (!desc.pItemWeapon->HasFlag(ITM_CAT_NF))
      return false;

#if ENGINE >= Engine_G2
    int talent = (desc.pItemWeapon->HasFlag(ITM_FLAG_2HD_SWD) || desc.pItemWeapon->HasFlag(ITM_FLAG_2HD_AXE))
                     ? NPC_HITCHANCE_2H
                     : NPC_HITCHANCE_1H;

    return dmgRand < desc.pNpcAttacker->GetHitChance(talent);
#else
    return desc.fDamageMultiplier > 1.0f;
#endif
  }

  void __fastcall oCNpc_OnDamage_Hit(oCNpc *_this, void *vtable, struct oCNpc::oSDamageDescriptor &desc);
  auto Hook_oCNpc_OnDamage_Hit = CreateHook(reinterpret_cast<void *>(zSwitch(0x00731410, 0x007700A0, 0x0077D390, 0x00666610)), &oCNpc_OnDamage_Hit);
  void __fastcall oCNpc_OnDamage_Hit(oCNpc *_this, void *vtable, struct oCNpc::oSDamageDescriptor &desc)
  {
    // Hook_oCNpc_OnDamage_Hit(_this, vtable, desc);

    if (!zUtilitiesOptions->DamagePopupMode)
    {
      Hook_oCNpc_OnDamage_Hit(_this, vtable, desc);
      return;
    }

#if ENGINE >= Engine_G2
    _ptiddata ptd = __getptd();
    unsigned long seed = ptd->_holdrand;
#endif

    bool isCrit = false;
    int initialHp = _this->attribute[NPC_ATR_HITPOINTS];

    oCNpc::oSDamageDescriptor descOld = desc;
    Hook_oCNpc_OnDamage_Hit(_this, vtable, desc);

    int hpDiff = initialHp - _this->attribute[NPC_ATR_HITPOINTS];

#if ENGINE >= Engine_G2
    if (ptd->_holdrand != seed)
    {
      int nextRand = (((seed * 214013L + 2531011L) >> 16) & 0x7fff);
      isCrit = IsCrit(desc, nextRand % 100);
    }
#else
    isCrit = IsCrit(desc);
#endif

    new DamagePopup(_this, descOld, hpDiff, isCrit);
  }

  void DamagePopup::SetMoveMode()
  {
    switch (mode)
    {
    case PopupMode::AlterDamage:
      horizontalMoveTime = 0.3f;
      horizontalMoveDist = GetRandomDist(25.0f, 75, false);
      verticalMoveDist = 100.0f;
      anchorStartPosMultiplier = 0.6f;
      break;
    case PopupMode::NewWorld:
      horizontalMoveTime = prolongationInSecs;
      horizontalMoveDist = GetRandomDist(50.0f, 50, true);
      verticalMoveDist = GetRandomDist(0.0f, 100, true);
      anchorStartPosMultiplier = 0.45f;
      break;
    default:
      horizontalMoveTime = 0.3f;
      horizontalMoveDist = 75.0f;
      verticalMoveDist = 100.0f;
      anchorStartPosMultiplier = 0.6f;
      break;
    }
  }

  void DamagePopup::SetColor()
  {
    if (zUtilitiesOptions->DamagePopupColorDmgTypes)
      switch (dmgIndex)
      {
      case oEIndexDamage::oEDamageIndex_Edge:
        color = zCOLOR(240, 220, 194);
        break;
      case oEIndexDamage::oEDamageIndex_Blunt:
        color = zCOLOR(255, 218, 121);
        break;
      case oEIndexDamage::oEDamageIndex_Point:
        color = zCOLOR(211, 255, 117);
        break;
      case oEIndexDamage::oEDamageIndex_Fire:
        color = zCOLOR(230, 126, 34);
        break;
      case oEIndexDamage::oEDamageIndex_Magic:
        color = zCOLOR(224, 86, 253);
        break;
      case oEIndexDamage::oEDamageIndex_Fly:
        color = zCOLOR(107, 244, 255);
        break;
      case oEIndexDamage::oEDamageIndex_Fall:
        color = zCOLOR(191, 222, 255);
        break;
      }

    if (desc->pNpcAttacker != nullptr)
    {
      if (desc->pNpcAttacker == player)
      {
        if (isCrit)
          color = zCOLOR(231, 76, 60);
      }
      else if (desc->pNpcAttacker->GetAivar("AIV_PARTYMEMBER"))
        color = zCOLOR(51, 235, 255);
    }

    // if ( target == player )
    //   color = zCOLOR( 255, 0, 0 );

    if (dmgAmount < 0)
      color = zCOLOR(148, 144, 136);
    else if (dmgAmount == 0)
      color = zCOLOR(148, 144, 136);
  }

  void DamagePopup::SetIcon()
  {
    switch (dmgIndex)
    {
    case oEIndexDamage::oEDamageIndex_Edge:
      icon = "EDGE"; // https://game-icons.net/1x1/lorc/ragged-wound.html
      break;
    case oEIndexDamage::oEDamageIndex_Blunt:
      icon = "BLUNT"; // https://game-icons.net/1x1/lorc/cross-mark.html
      break;
    case oEIndexDamage::oEDamageIndex_Point:
      icon = "POINT"; // https://game-icons.net/1x1/skoll/bullseye.html
      break;
    case oEIndexDamage::oEDamageIndex_Fire:
      icon = "FIRE"; // https://game-icons.net/1x1/lorc/burning-embers.html
      break;
    case oEIndexDamage::oEDamageIndex_Magic:
      icon = "MAGIC"; // https://game-icons.net/1x1/delapouite/polar-star.html
      break;
    case oEIndexDamage::oEDamageIndex_Fly:
      icon = "FLY"; // https://game-icons.net/1x1/lorc/fluffy-trefoil.html
      break;
    case oEIndexDamage::oEDamageIndex_Fall:
      icon = "FALL"; // https://game-icons.net/1x1/sbed/falling.html
      break;
    default:
      icon = "UNKNOWN"; // https://game-icons.net/1x1/lorc/scar-wound.html
      break;
    }
  }

  void DamagePopup::SetScale()
  {
    scale = (PlayerHelper::GetSysScale()) ? 1.15f : 1.0f;
    scale *= zUtilitiesOptions->DamagePopupScale;

    float baseScale = scale;

    if (dmgAmount > 0)
    {
      scale += scale * (float)dmgAmount / (float)target->attribute[NPC_ATR_HITPOINTSMAX] / 1.75f;

      if (isCrit)
        scale *= 1.4f;
    }

    scale = min(scale, baseScale * 3.5f);
  }

  float DamagePopup::GetRandomDist(float start, int random, bool invertable)
  {
    float dist = start + (float)(randomizer.Random(0, random));

    if (invertable && randomizer.Random(0, 1))
      return -dist;

    return dist;
  }

  bool DamagePopup::WorldToView(const zVEC3 &worldPos, zCView *view, zVEC2 &pos)
  {
    zCCamera *cam = ogame->GetCamera();
    zVEC3 viewPos = cam->GetTransform(zTCamTrafoType::zCAM_TRAFO_VIEW) * worldPos;

    int x, y;
    cam->Project(&viewPos, x, y);
    pos[VX] = view->anx(x + 0.5f);
    pos[VY] = view->any(y + 0.5f);

    return viewPos[VZ] > cam->nearClipZ;
  }

  float DamagePopup::Scale(float p, float max)
  {
    return sqrt(p / max);
  }

  void DamagePopup::CalcOffset(float lifetime)
  {
    const zMAT4 &viewTrafo = ogame->GetCamera()->GetTransform(zTCamTrafoType::zCAM_TRAFO_WORLDVIEW_INV);
    offset = zVEC3(viewTrafo[VX][VX], viewTrafo[VY][VX], viewTrafo[VZ][VX]) * Scale(min(lifetime, horizontalMoveTime), horizontalMoveTime) * horizontalMoveDist;
    offset[VY] += Scale(min(lifetime, timeLimitInSecs), timeLimitInSecs) * verticalMoveDist;
  }

  void DamagePopup::CalcViewport(zSTRING &text, zCView *view, zVEC2 viewPos, const zVEC2 &scaling)
  {
    float width = view->FontSize(text) * scaling[VX];
    float height = view->FontY() * scaling[VY];

    if (zUtilitiesOptions->DamagePopupShowIcons)
      width += height;

    viewPos[VX] = CoerceInRange(viewPos[VX] - width / 2, width, 0, 8191);
    viewPos[VY] = CoerceInRange(viewPos[VY] - height / 2, height, 0, 8191);

    vpPos.left = view->nax(viewPos[VX]) + vpOffset[VX];
    vpPos.top = view->nay(viewPos[VY]) + vpOffset[VY];
    width = view->nax(width);
    height = view->nay(height);
    vpPos.right = vpPos.left + width;
    vpPos.bottom = vpPos.top + height;

    for (int i = 0; popups[i] != this; i++)
      if (Intersects(vpPos, popups[i]->vpPos))
      {
        int deltaY = (popups[i]->vpPos.bottom - vpPos.top) / 3.0f;
        vpPos.top += deltaY;
        vpPos.bottom += deltaY;
        vpOffset[VY] += deltaY;
      }
  }

  void DamagePopup::Update()
  {
    float lifetime = ztimer->totalTimeFloat / 1000.0f - creationTimeInSecs;

    if (!target || !target->globalVobTreeNode)
    {
      delete this;
      return;
    }

    if (lastAnchorUpdate <= creationTimeInSecs)
    {
      lastAnchorUpdate = ztimer->totalTimeFloat / 1000.0f;
      currentLifetimeLimit = max(currentLifetimeLimit, lifetime + prolongationInSecs);
      anchorPos[VX] = target->GetPositionWorld()[VX];
      anchorPos[VZ] = target->GetPositionWorld()[VZ];
    }

    if (lifetime > currentLifetimeLimit)
    {
      delete this;
      return;
    }

    lifetime = min(lifetime, timeLimitInSecs);

    CalcOffset(lifetime);
    float scaling = scale;

    if (lifetime < 0.3f)
      scaling *= Scale(lifetime, 0.3f) * 1.5f;
    else if (lifetime < 0.4f)
      scaling *= 1.5f - (1 - Scale(0.4f - lifetime, 0.4f)) * 0.5f;

    float fadingTime = 0.2f;

    if (lifetime > currentLifetimeLimit - fadingTime)
      alpha = 255.0f * (currentLifetimeLimit - lifetime) * fadingTime * 10.0f;

    Print(screen, anchorPos + offset, zVEC2(scaling));
  }

  void DamagePopup::Print(zCView *view, const zVEC3 &pos, const zVEC2 &scaling)
  {
    if (!ogame->game_drawall)
      return;

    zVEC2 viewPos;
    if (!WorldToView(pos, view, viewPos))
      return;

    color.alpha = alpha;
    zCOLOR textColor = (zUtilitiesOptions->DamagePopupColorOnlyIcon) ? zCOLOR(240, 220, 194, alpha) : color;
    zCOLOR iconColor = color;

    zSTRING text = dmgAmount;
    CalcViewport(text, view, viewPos, scaling);

    zCFont *font = view->GetFont();
    float space = font->GetLetterDistance() * scaling[VX];

    float x = vpPos.left;
    float y = vpPos.top;
    float height = vpPos.bottom - vpPos.top;
    float z = zSwitch(0.9f, 0.9f, 1.1f, 1.1f);

    for (size_t i = 0; text.ToChar()[i] != '\n' && text.ToChar()[i] != '\0'; i++)
    {
      int charWidth;
      zVEC2 from, to;
      font->GetFontData(text[i], charWidth, from, to);
      float fCharWidth = charWidth * scaling[VX];

      zrenderer->DrawTile(font->GetFontTexture(), zVEC2(x, y), zVEC2(x + fCharWidth, y + height), z, from, to, textColor);
      x += fCharWidth + space;
    }

    if (!zUtilitiesOptions->DamagePopupShowIcons)
      return;

    x += space;
    zCTexture *texture = texture->Load("DMGICON_" + icon, true);
    float iconSize = height;
    zrenderer->DrawTile(texture, zVEC2(x, y), zVEC2(x + iconSize, y + iconSize), z, zVEC2(0, 0), zVEC2(1.0f, 1.0f), iconColor);
    x += iconSize + space;
    texture->Release();
  }

  DamagePopup::DamagePopup(oCNpc *targetNpc, oCNpc::oSDamageDescriptor &desc, int dmgAmount, bool isCrit)
  {
    if (desc.pNpcAttacker == nullptr || desc.pNpcAttacker != player && !desc.pNpcAttacker->GetAivar("AIV_PARTYMEMBER"))
    {
      delete this;
      return;
    }

    popups.Insert(this);

    mode = zUtilitiesOptions->DamagePopupMode;
    this->target = targetNpc;
    this->dmgAmount = dmgAmount;
    this->desc = &desc;
    this->isCrit = isCrit;

    int aryDamageEffective[oEDamageIndex::oEDamageIndex_MAX];
    for (int i = 0; i < oEDamageIndex::oEDamageIndex_MAX; i++)
      aryDamageEffective[i] = (int)this->desc->aryDamageEffective[i];

    dmgIndex = GetTopDmgIndex(aryDamageEffective, this->desc->enuModeDamage);
    SetMoveMode();
    SetColor();
    SetIcon();
    SetScale();

    creationTimeInSecs = ztimer->totalTimeFloat / 1000.0f;
    lastAnchorUpdate = creationTimeInSecs;
    anchorPos = target->GetPositionWorld();
    anchorPos[VY] += (target->bbox3D.maxs[VY] - target->bbox3D.mins[VY]) * anchorStartPosMultiplier;
    vpOffset = zVEC2(0, 0);
    CalcOffset(0);
    Update();
  }

  DamagePopup::~DamagePopup()
  {
    popups.Remove(this);
  }
}