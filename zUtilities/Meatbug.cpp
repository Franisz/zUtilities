// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  // Inspiration @G2-Ucieczka - https://github.com/TheKetrab/G2-Ucieczka
  HOOK Hook_oCNpc_OnTouch PATCH( &oCNpc::OnTouch, &oCNpc::OnChrzonszcz );
  void oCNpc::OnChrzonszcz( zCVob* vob ) {
    oCNpc* npc = vob->CastTo<oCNpc>();

    if ( !npc || !this->IsSelfPlayer() || !this->IsHuman() || this->idx == npc->idx || !Options::TrampleMeatbugs ) {
      THISCALL( Hook_oCNpc_OnTouch )(vob);
      return;
    }

    if ( npc->guild == NPC_GIL_MEATBUG && npc->GetInstanceName().HasWord( "MEATBUG" ) && npc->attribute[NPC_ATR_HITPOINTSMAX] <= 25 ) {
      // Kill and Exp
      npc->DoDie( this );
      if ( npc->attribute[NPC_ATR_HITPOINTS] > 0 )
        npc->attribute[NPC_ATR_HITPOINTS] = 0;

      // Sound
      if ( zCSoundFX* snd = zsound->LoadSoundFX( "CS_IAM_UD_FLX_0" + Z randomizer.Random( 1, 5 ) + ".WAV" ) ) {
        zCSoundSystem::zTSound3DParams params;
        zsound->GetSound3DProps( 0, params );
        zsound->PlaySound3D( snd, vob, 0, &params );
        snd->Release();
      }

      //// Blood
      //oCVisualFX::CreateAndPlay( "BFX_PRESET2", npc, nullptr, 0, 0, 0, 0 );
    }

    THISCALL( Hook_oCNpc_OnTouch )(vob);
  }
}