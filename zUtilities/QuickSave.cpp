// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

  void QuickSave::SetStringsByLanguage() {
    switch ( Union.GetSystemLanguage() )
    {
    case Lang_Rus:
      sCantSave = "Игра не может быть сохранена сейчас!";
      sCantLoad = "Игра не может быть загружена!";
      sNoSave = "Такого сохранения не существует!";
      break;
    case Lang_Eng:
      sCantSave = "The game cannot be saved now!";
      sCantLoad = "The game cannot be loaded now!";
      sNoSave = "Such a save does not exist!";
      break;
    case Lang_Ger:
      sCantSave = "Das Spiel kann jetzt nicht gespeichert werden!";
      sCantLoad = "Das Spiel kann jetzt nicht geladen werden!";
      sNoSave = "Ein solches Speichern gibt es nicht!";
      break;
    case Lang_Pol:
      sCantSave = "Nie moїna teraz zapisaж rozgrywki!";
      sCantLoad = "Nie moїna teraz wczytaж rozgrywki!";
      sNoSave = "Taki zapis nie istnieje!";
      break;
    default:
      sCantSave = "The game cannot be saved now!";
      sCantLoad = "The game cannot be loaded now!";
      sNoSave = "Such a save does not exist!";
      break;
    }

    sCantSave = zoptions->ReadString( pluginName, "sCantSave", sCantSave );
    sCantLoad = zoptions->ReadString( pluginName, "sCantLoad", sCantLoad );
    sNoSave = zoptions->ReadString( pluginName, "sNoSave", sNoSave );
    sSaveName = zoptions->ReadString( pluginName, "sSaveName", "QuickSave" );
  }

  void QuickSave::SetSaveSlotAndNr() {
    zCArray<oCSavegameInfo*> saveList = gameMan->savegameManager->infoList;

    int latestNr = 0;
    int latestSaveSlot = Invalid;

    for ( int i = 0; i < saveList.GetNum(); i++ ) {
      if ( saveList[i]->m_SlotNr < iMinSaveSlot || saveList[i]->m_SlotNr > iMaxSaveSlot )
        continue;

      if ( !saveList[i]->GetName().HasWord( sSaveName ) )
        continue;

      int nr = saveList[i]->GetName().Cut( 0, sSaveName.Length() ).ToInt32();
      if ( nr > latestNr ) {
        latestNr = nr;
        latestSaveSlot = saveList[i]->m_SlotNr;
      }
    }

    iLastSaveNumber = latestNr;
    iLastSaveSlot = latestSaveSlot;
  }

  int QuickSave::InInteraction() {
    if ( playerHelper.IsSaving() ) return true;
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
    if ( !zinput->KeyToggled( KEY_F10 ) )
      return;

    if ( !CanSave() ) {
      ogame->GetTextView()->Printwin( sCantSave );
      return;
    }

    iLastSaveSlot++;
    iLastSaveNumber++;
    if ( iLastSaveSlot > iMaxSaveSlot || iLastSaveSlot < iMinSaveSlot )
      iLastSaveSlot = iMinSaveSlot;

    // Thumbnail
    zCTextureConvert* thumb = zrenderer->CreateTextureConvert();
    zrenderer->Vid_GetFrontBufferCopy( *thumb );

    // SaveGame
    ToggleShowStatus();
    ogame->WriteSavegame( iLastSaveSlot, true );

    // SaveInfo
    auto info = ogame->savegameManager->GetSavegame( iLastSaveSlot );

    info->m_Name = sSaveName + Z iLastSaveNumber;
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
    if ( !zinput->KeyToggled( KEY_F12 ) )
      return;

    if ( InInteraction() ) {
      ogame->GetTextView()->Printwin( sCantLoad );
      return;
    }

    if ( !ogame->savegameManager->GetSavegame( iLastSaveSlot )->DoesSavegameExist() ) {
      ogame->GetTextView()->Printwin( sNoSave + " (" + Z iLastSaveSlot + ")" );
      return;
    }

    ToggleShowStatus();
    ogame->LoadSavegame( iLastSaveSlot, true );
  }

  void QuickSave::ToggleShowStatus() {
    if ( !oldShowStatus ) return;

    ogame->SetShowPlayerStatus( toggledShowStatus );
    toggledShowStatus = !toggledShowStatus;
  }

  void QuickSave::QuickSaveLoop() {
    if ( !bUseQuickSave ) return;

    if ( !toggledShowStatus )
      oldShowStatus = ogame->GetShowPlayerStatus();
    else
      ToggleShowStatus();

    CheckLoad();
    CheckSave();
  }

  QuickSave::QuickSave() {
#if ENGINE >= Engine_G2
    iMinSaveSlot = zoptions->ReadInt( pluginName, "iMinSaveSlot", 15 );
    iMaxSaveSlot = zoptions->ReadInt( pluginName, "iMaxSaveSlot", 20 );
#else
    iMinSaveSlot = zoptions->ReadInt( pluginName, "iMinSaveSlot", 10 );
    iMaxSaveSlot = zoptions->ReadInt( pluginName, "iMaxSaveSlot", 15 );
#endif

    SetStringsByLanguage();
    SetSaveSlotAndNr();
  }
}

