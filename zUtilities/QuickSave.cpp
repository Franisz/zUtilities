// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  bool QuickSave::KeepClosingMenus = false;

  HOOK Hook_zCMenu_HandleFrame PATCH( &zCMenu::HandleFrame, &zCMenu::HandleFrame_Union );
  void zCMenu::HandleFrame_Union( int frame ) {
    if ( QuickSave::KeepClosingMenus ) {
      for ( int i = 0; i < this->m_listItems.GetNum(); i++ )
        this->m_listItems[i]->m_bLeaveItem = true;

      this->m_exitState = zCMenu::BACK;
      return;
    }

    THISCALL( Hook_zCMenu_HandleFrame )( frame );
  }

  HOOK Hook_zCMenu_HandleRun PATCH( &zCMenu::Run, &zCMenu::Run_Union );
  int zCMenu::Run_Union()
  {
    int result = THISCALL( Hook_zCMenu_HandleRun )();

    if ( zCMenu::activeList.GetNum() == 0 )
      QuickSave::KeepClosingMenus = false;

    return result;
  }

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
    if (player->HasBodyStateModifier(BS_MOD_TRANSFORMED)) return false;
    //if ( ogame->game_testmode ) return false;
    //if ( !player->IsInFightMode_S(0) ) return false;

    zSTRING saveMenu = gameMan->menu_save_savegame ? gameMan->menu_save_savegame->name : "MENU_SAVEGAME_SAVE";

    for ( int i = 0; i < zCMenuItem::itemList.GetNum(); i++ ) {
      zCMenuItem* item = zCMenuItem::itemList[i];
      if ( item->m_parOnSelAction_S[0] == saveMenu ) {
        bool cantSave = item->m_parItemFlags & IT_DISABLED || item->m_parItemFlags & IT_ONLY_OUT_GAME;
        return !cantSave;
      }
    }

    return true;
  }

  void QuickSave::CheckSave() {
    if ( !zinput->KeyToggled( Options::KeyQuickSave ) )
      return;

    if ( !CanSave() ) {
      ogame->GetTextView()->Printwin( Options::CantSave );
      return;
    }

    if ( Options::QuickSaveMode == QuickSaveMode::Alternative ) {
      // The algorithm looks very like adding numbers in binary.
      // The idea behind using a binary addition is too use some SaveSlots
      // more frequently then others. for example:
      //     Slot0 -> will be used 50%
      //     Slot1 -> will be used 25%
      //     Slot2 -> will be used 12%
      //     Slot3 -> will be used  6%
      //     Slot4 -> will be used  3%
      //     Slot5 -> will be used  1%
      // Thanks to that, we have Slot5, Slot4 keeping the oldest (in actual date time) Saves
      // Whiles Slot0, Slot1, keeping the newest (in actual date time) Saves
      // This will give the ability to Load old save from Slot5, that was saved (lets say 2 ^ 5 = 32 saves ago)
      // And at the same time, we have Slot1, Slot2 with newest saves (lets say last save)
      //
      // Example of such saving, I will mark a SaveSpot with brackets (numbers are an ID of a save):
      //  -   [1]   1   [3]   3   [5]   5   [7]   7
      //  -    -   [2]   2    2    2   [6]   6    6
      //  -    -    -    -   [4]   4    4    4    4
      //  -    -    -    -    -    -    -    -   [8]
      //
      // And their binary representation (numbers are a binary tree that helps me to determine SaveSpot):
      //  0   [1]   0   [1]   0   [1]   0   [1]   0
      //  0    0   [1]   1    0    0   [1]   1    0
      //  0    0    0    0   [1]   1    1    1    0
      //  0    0    0    0    0    0    0    0   [1]
      //
      // And their decimal representation:
      //  0    1    2    3    4    5    6    7    8
      //
      // As you can see, the SaveSpots (brackets), are in a places where the
      // number changed from 0 -> 1, number changing from 1 -> 0 does not matter.
      //
      //
      // The problem in implementing that, is to create a naming system that
      // can determine the Spot to Save, at any give point in time.
      // Even after exit/restart of the game.

      // We are saving for the first time probably
      if ( iLastSaveNumber == Invalid ) {
        iLastSaveSlot = Options::MinSaveSlot;
        iLastSaveNumber = 1; // I could use ZERO as a first SaveName, it doesn't matter. number ONE is just more pleasant to the eye
      }
      // we need to figure out, on which slot to put next save.
      else {
        int const curName = iLastSaveNumber;
        int const nextName = curName + 1;
        // Now we need to find a change from 0 -> 1 between maxName and nextName
        int changeIndex = -1;
        int mask = ((int)1); // 0...01
        for ( int i = 0; i < (sizeof( int ) * 8) - 1; ++i ) {
          if ( (nextName & mask) > ( curName & mask ) ) {
            changeIndex = i;
            break;
          }
          // this operation moves 1 to the right, and resets first bit to 0, in order to check next bit
          mask = (mask << 1) & (~((int)1)); // 1...10
        }

        if ( changeIndex != -1 ) {
          // We found an index where change happens, but this index is between 0 and 31.
          // We need to cap it between Options::MinSaveSlot and Options::MaxSaveSlot
          // To do it, I will wrap the number system around
          int const slots = Options::MaxSaveSlot - Options::MinSaveSlot;
          while ( changeIndex > slots ) {
            // this operation moves the index one to the left, in order to fit in number of available slots
            changeIndex -= slots;
          }
          iLastSaveSlot = Options::MinSaveSlot + changeIndex;
          iLastSaveNumber++;
        }
      }
    }
    else {
      iLastSaveSlot++;
      iLastSaveNumber++;
      if ( iLastSaveSlot > Options::MaxSaveSlot || iLastSaveSlot < Options::MinSaveSlot )
        iLastSaveSlot = Options::MinSaveSlot;
    }

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

    if ( Options::PrintQuickSaveLoadInfo )
        ogame->GetTextView()->Printwin( Z Options::SaveCompleted + " '" + Z info->m_Name + Z "' #" + Z info->m_SlotNr );
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

    if( Options::PrintQuickSaveLoadInfo )
        ogame->GetTextView()->Printwin( Z Options::LoadCompleted + " '" + Z info->m_Name + Z "' #" + Z info->m_SlotNr );
  }

  void QuickSave::LoadFromMainMenu() const {
    if ( gameMan->menu_load_savegame )
      gameMan->menu_load_savegame->m_selSlot = iLastSaveSlot;

    if ( zCMenu::activeList.GetNum() == 0 ) {
#if ENGINE == Engine_G1A
      ogame->LoadSavegame( iLastSaveSlot, true );
#else
      gameMan->Read_Savegame( iLastSaveSlot );
#endif
      return;
    }

    QuickSave::KeepClosingMenus = true;
    zoptions->WriteString( "internal", "menuAction", "SAVEGAME_LOAD", false );
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
    saveEnd = false;

    if ( disabledStatus ) {
      disabledStatus = false;
      ogame->SetShowPlayerStatus( true );
    }
  }

  void QuickSave::Loop() {
    if ( (isLoading && !ogame->IsOnPause()) || (isSaving && saveEnd) )
      EndSaveLoad();

    if ( !Options::QuickSaveMode ) return;

    if ( ogame->IsOnPause() ) return;

    CheckLoad();
    CheckSave();
  }

  void QuickSave::MenuLoop() {
    if ( !Options::QuickSaveMode || zCMenu::inGameMenu || isLoading ) return;

    if ( ! ( Options::QuickLoadAfterGameStart || zinput->KeyToggled( Options::KeyQuickLoad ) ) ) return;

    oCSavegameInfo* info = gameMan->savegameManager->GetSavegame( iLastSaveSlot );
    if ( !info || !info->DoesSavegameExist() ) return;

    LoadFromMainMenu();    
  }

  QuickSave::QuickSave() {
    SetSaveSlotAndNr();
  }
}