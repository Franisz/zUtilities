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

    if ( npc->GetInstanceName().HasWord( "MEATBUG" ) ) {
      // Kill
      npc->attribute[NPC_ATR_HITPOINTS] = 0;

      // Sound
      zCSoundFX* snd = zsound->LoadSoundFX( "MEA_Ambient" );
      if ( snd ) 
        zsound->PlaySound( snd, 50 );

      // Exp
#if ENGINE >= Engine_G2
      int index = parser->GetIndex( "B_GivePlayerXP" );
#else
      int index = parser->GetIndex( "B_GiveXP" );
#endif

      if ( index )
        parser->CallFunc( index, npc->level * 10 );
    }

    THISCALL( Hook_oCNpc_OnTouch )(vob);
  }

}