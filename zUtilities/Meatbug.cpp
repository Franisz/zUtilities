// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

  // Inspiration @G2-Ucieczka - https://github.com/TheKetrab/G2-Ucieczka

  HOOK Hook_oCNpc_OnTouch PATCH( &oCNpc::OnTouch, &oCNpc::OnChrzonszcz );
  void oCNpc::OnChrzonszcz( zCVob* vob ) {

    oCNpc* npc = vob->CastTo<oCNpc>();

    if ( !npc || !this->IsSelfPlayer() || !bTrampleMeatbugs ) {
      THISCALL( Hook_oCNpc_OnTouch )(vob);
      return;
    }

    if ( npc->guild == NPC_GIL_MEATBUG && npc->GetInstanceName().HasWord( "MEATBUG" ) && npc->attribute[NPC_ATR_HITPOINTSMAX] <= 25 ) {
      // Kill
      npc->attribute[NPC_ATR_HITPOINTS] = 0;

      // Sound
      if ( zCSoundFX* snd = zsound->LoadSoundFX( "MEA_Ambient" ) ) {
        zsound->PlaySound( snd, 50 );
        snd->Release();
        snd = nullptr;
      }

      // Exp
      int index, exp;
#if ENGINE >= Engine_G2
      if ( parser->GetSymbol( "XP_PER_VICTORY" ) )
        exp = parser->GetSymbol( "XP_PER_VICTORY" )->single_intdata;

      index = parser->GetIndex( "B_GivePlayerXP" );
#else
      if ( parser->GetSymbol( "XP_PER_LEVEL_DEAD" ) )
        exp = parser->GetSymbol( "XP_PER_LEVEL_DEAD" )->single_intdata;

      index = parser->GetIndex( "B_GiveXP" );
#endif
      if ( !exp ) exp = 10;

      if ( index )
        parser->CallFunc( index, npc->level * exp );
    }

    THISCALL( Hook_oCNpc_OnTouch )(vob);
  }

}