// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  HOOK Ivk_CheckRemoveNpc_Union PATCH( &oCSpawnManager::CheckRemoveNpc, &oCSpawnManager::CheckRemoveNpc_Union );
  int oCSpawnManager::CheckRemoveNpc_Union( oCNpc* npc ) {
    if ( !Options::RemoveBodies && !npc->IsFadingAway() ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }

    if ( !npc || !npc->GetHomeWorld() ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }

    if ( npc->GetEM()->GetCutsceneMode() || npc->IsAPlayer() || ( !npc->IsConditionValid() && npc->attribute[NPC_ATR_HITPOINTS] > 0 ) ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }

    if ( npc->attribute[NPC_ATR_HITPOINTS] > 0 ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }

#if ENGINE >= Engine_G2
    if ( npc->GetGuild() == NPC_GIL_DRAGON ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }
#endif

    auto InventoryEmpty = false;
#if ENGINE <= Engine_G2
    InventoryEmpty = npc->IsInventoryEmpty (true, false );
#else
    InventoryEmpty = npc->IsInventoryEmpty (true, true );
#endif

    if ( !InventoryEmpty || npc->HasMissionItem() ) {
      return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
    }

    if ( !npc->human_ai->IsDead() ) {
      return TRUE;
    }

    if ( npc->IsFadingAway() ) {
      this->InitCameraPos();
      auto dist = ( npc->GetPositionWorld() - this->camPos ).LengthApprox();

      if ( dist > this->GetRemoveRange() ) {
        this->DeleteNpc( npc );
      }
      else {
        npc->FadeAway();
      }

      return TRUE;
    }
    else {
      if ( Options::RemoveBodies == 1 ) {
        npc->StartFadeAway();
      }
      else if ( Options::RemoveBodies == 2 )  {
        this->DeleteNpc( npc );
      }
      else {
        return THISCALL( Ivk_CheckRemoveNpc_Union )( npc );
      }

      return TRUE;
    }

    return FALSE;
  }
}