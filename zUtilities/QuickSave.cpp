// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void QuickSave::SetSaveSlotAndNr() {
    zCArray<oCSavegameInfo*> saveList = gameMan->savegameManager->infoList;

    int latestNr = 0;
    int latestSaveSlot = Invalid;

    for ( int i = 0; i < saveList.GetNum(); i++ ) {
      if ( saveList[i]->m_SlotNr < Options::MinSaveSlot || saveList[i]->m_SlotNr > Options::MaxSaveSlot )
        continue;

      if ( !saveList[i]->GetName().HasWord( Options::SaveName ) )
        continue;

      int nr = saveList[i]->GetName().Cut( 0, Options::SaveName.Length() ).ToInt32();
      if ( nr > latestNr ) {
        latestNr = nr;
        latestSaveSlot = saveList[i]->m_SlotNr;
      }
    }

    iLastSaveNumber = latestNr;
    iLastSaveSlot = latestSaveSlot;
  }

  int QuickSave::InInteraction() {
    if ( IsBusy() ) return true;
    if ( playerHelper.IsBusy() ) return true;
    if ( player->bodyState == BS_TAKEITEM ) return true;
    if ( player->bodyState == BS_MOBINTERACT ) return true;
    if ( player->bodyState & BS_FLAG_INTERRUPTABLE && !(player->bodyState & BS_FLAG_FREEHANDS) ) return true;

    return false;
  }

  bool QuickSave::IsBusy() {
    return isSaving || isLoading;
  }

  int QuickSave::CanSave() {
    if ( playerHelper.IsDead() ) return false;
    if ( InInteraction() ) return false;
    if ( player->GetAnictrl()->state != zCAIPlayer::zMV_STATE_STAND ) return false;
    //if ( ogame->game_testmode ) return false;
    //if ( !player->IsInFightMode_S(0) ) return false;

    return true;
  }

  void QuickSave::CheckSave() {
    if ( !zinput->KeyToggled( Options::KeyQuickSave ) )
      return;

    if ( !CanSave() ) {
      ogame->GetTextView()->Printwin( Options::CantSave );
      return;
    }

    iLastSaveSlot++;
    iLastSaveNumber++;
    if ( iLastSaveSlot > Options::MaxSaveSlot || iLastSaveSlot < Options::MinSaveSlot )
      iLastSaveSlot = Options::MinSaveSlot;

    // Thumbnail
    zCTextureConvert* thumb = zrenderer->CreateTextureConvert();
    zrenderer->Vid_GetFrontBufferCopy( *thumb );

    // SaveGame
    isSaving = true;
    StartSaveLoad();
#if ENGINE == Engine_G1A
    ogame->WriteSavegame( iLastSaveSlot, true );
#else
    gameMan->Write_Savegame( iLastSaveSlot );
#endif

    // SaveInfo
    oCSavegameInfo* info = gameMan->savegameManager->GetSavegame( iLastSaveSlot );

    info->m_Name = Z Options::SaveName + Z iLastSaveNumber;
    info->m_WorldName = ogame->GetGameWorld()->GetWorldName();
    int day, hour, min;
    ogame->GetTime( day, hour, min );
    info->m_TimeDay = day + 1;
    info->m_TimeHour = hour;
    info->m_TimeMin = min;
    info->m_PlayTimeSeconds = gameMan->GetPlaytimeSeconds();
    info->UpdateThumbPic( thumb );
    delete thumb;

    gameMan->savegameManager->SetAndWriteSavegame( info->m_SlotNr, info );
  }

  void QuickSave::CheckLoad() {
    if ( !zinput->KeyToggled( Options::KeyQuickLoad ) )
      return;

    if ( InInteraction() ) {
      ogame->GetTextView()->Printwin( Options::CantLoad );
      return;
    }

    oCSavegameInfo* info = gameMan->savegameManager->GetSavegame( iLastSaveSlot );

    if ( !info || !info->DoesSavegameExist() ) {
      ogame->GetTextView()->Printwin( Z Options::NoSave + " (" + Z iLastSaveSlot + ")" );
      return;
    }

    isLoading = true;
    StartSaveLoad();
#if ENGINE == Engine_G1A
    ogame->LoadSavegame( info->m_SlotNr, true );
#else
    gameMan->Read_Savegame( info->m_SlotNr );
#endif
  }

  void QuickSave::StartSaveLoad() {
    if ( ogame->GetShowPlayerStatus() ) {
      disabledStatus = true;
      ogame->SetShowPlayerStatus( false );
    }
  }

  void QuickSave::EndSaveLoad() {
    isSaving = false;
    isLoading = false;

    if ( disabledStatus ) {
      disabledStatus = false;
      ogame->SetShowPlayerStatus( true );
      playerStatus.Loop();
    }
  }

  void QuickSave::Loop() {
    if ( isLoading && !ogame->IsOnPause() )
      EndSaveLoad();

    if ( !Options::UseQuickSave ) return;

    if ( ogame->IsOnPause() ) return;

    CheckLoad();
    CheckSave();
  }

  QuickSave::QuickSave() {
    SetSaveSlotAndNr();
  }
}

