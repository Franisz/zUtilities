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
    if ( isSaving ) return true;
    if ( playerHelper.IsBusy() ) return true;
    if ( player->bodyState == BS_TAKEITEM ) return true;
    if ( player->bodyState == BS_MOBINTERACT ) return true;
    if ( player->bodyState & BS_FLAG_INTERRUPTABLE && !(player->bodyState & BS_FLAG_FREEHANDS) ) return true;

    return false;
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
    ToggleShowStatus();
    ogame->WriteSavegame( iLastSaveSlot, true );

    // SaveInfo
    auto info = ogame->savegameManager->GetSavegame( iLastSaveSlot );

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

    ogame->savegameManager->SetAndWriteSavegame( iLastSaveSlot, info );
  }

  void QuickSave::CheckLoad() {
    if ( !zinput->KeyToggled( Options::KeyQuickLoad ) )
      return;

    if ( InInteraction() ) {
      ogame->GetTextView()->Printwin( Options::CantLoad );
      return;
    }

    if ( !ogame->savegameManager->GetSavegame( iLastSaveSlot )->DoesSavegameExist() ) {
      ogame->GetTextView()->Printwin( Z Options::NoSave + " (" + Z iLastSaveSlot + ")" );
      return;
    }

    ToggleShowStatus();
    ogame->LoadSavegame( iLastSaveSlot, true );
  }

  void QuickSave::ToggleShowStatus() {
    if ( !oldShowStatus ) return;

    isSaving = (isSaving) ? false : true;
    ogame->SetShowPlayerStatus( toggledShowStatus );
    toggledShowStatus = !toggledShowStatus;
  }

  void QuickSave::Loop() {
    if ( !Options::UseQuickSave ) return;

    if ( !toggledShowStatus )
      oldShowStatus = ogame->GetShowPlayerStatus();
    else
      ToggleShowStatus();

    CheckLoad();
    CheckSave();
  }

  QuickSave::QuickSave() {
    SetSaveSlotAndNr();
  }
}

