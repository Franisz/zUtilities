// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  oCNpc *playerTrfCopy = nullptr;

  void __fastcall oCNpc_CopyTransformSpellInvariantValuesTo(oCNpc *_this, void *vtable, oCNpc *npc);
  auto Hook_oCNpc_CopyTransformSpellInvariantValuesTo = CreateHook(reinterpret_cast<void *>(zSwitch(0x0069A000, 0x006CBF40, 0x006DEBB0, 0x0073D3D0)), &oCNpc_CopyTransformSpellInvariantValuesTo);
  void __fastcall oCNpc_CopyTransformSpellInvariantValuesTo(oCNpc *_this, void *vtable, oCNpc *npc)
  {
    if (_this == player)
      playerTrfCopy = _this;

    Hook_oCNpc_CopyTransformSpellInvariantValuesTo(_this, vtable, npc);
  }

  void __fastcall oCNpc_OnTouch(oCNpc *_this, void *vtable, zCVob *vob);
  auto Hook_oCNpc_OnTouch = CreateHook(reinterpret_cast<void *>(zSwitch(0x006A68E0, 0x006D94C0, 0x006EC260, 0x0074AF20)), &oCNpc_OnTouch);
  void __fastcall oCNpc_OnTouch(oCNpc *_this, void *vtable, zCVob *vob)
  {
    // Hook_oCNpc_OnTouch(_this, vtable, vob);
    oCNpc *npc = vob->CastTo<oCNpc>();
    zCVisual *visual = vob->GetVisual();

    if (!npc || !visual || !_this->IsSelfPlayer() || !_this->IsHuman() || vob == playerTrfCopy || npc->guild != NPC_GIL_MEATBUG || npc->HasFlag(NPC_FLAG_IMMORTAL) || !zUtilitiesOptions->TrampleMeatbugs)
    {
      Hook_oCNpc_OnTouch(_this, vtable, vob);
      return;
    }

    bool largeMdlScale = false;
    for (auto i = 0; i < npc->model_scale.Length(); i++)
      if (npc->model_scale[i] > 1.0)
        largeMdlScale = true;

    if (visual->GetVisualName() != "MEATBUG.MDS" || largeMdlScale)
    {
      Hook_oCNpc_OnTouch(_this, vtable, vob);
      return;
    }

    // Kill and Exp
    npc->DoDie(_this);
    if (npc->attribute[NPC_ATR_HITPOINTS] > 0)
      npc->attribute[NPC_ATR_HITPOINTS] = 0;

    // Sound
    if (zCSoundFX *snd = zsound->LoadSoundFX("CS_IAM_UD_FLX_0" + zSTRING(randomizer.Random(1, 5)) + ".WAV"))
    {
      zCSoundSystem::zTSound3DParams params;
      zsound->GetSound3DProps(0, params);
      zsound->PlaySound3D(snd, vob, 0, &params);
      snd->Release();
    }

    //// Blood
    // oCVisualFX::CreateAndPlay( "BFX_PRESET2", npc, nullptr, 0, 0, 0, 0 );

    Hook_oCNpc_OnTouch(_this, vtable, vob);
  }

}