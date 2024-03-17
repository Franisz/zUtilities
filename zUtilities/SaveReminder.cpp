// Supported with union ( c ) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void SaveReminder::ResetTimer( bool update ) {
    if ( SaveLoadGameInfo.changeLevel || !update )
    {
      return;
    }

    lastSaveTime = std::chrono::high_resolution_clock::now();
    Options::ReminderNeedReset = false;
  }

  void SaveReminder::Loop() {
    if ( 
      !ogame
      || !player
      || playerHelper.IsBusy()
      || quickSave->IsBusy()
      //|| playerHelper.IsDead()
      || playerHelper.IsConUp()
      || !ogame->GetShowPlayerStatus()
      || !ogame->game_drawall
      || !Options::ReminderEnabled
       )
    {
      return;
    }

    auto ElapsedTime = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::high_resolution_clock::now() - lastSaveTime );
    if ( ElapsedTime >= Options::ReminderAfterMin )
    {
      int PrintPosY = 3 * screen->FontY();
      auto originalColor = screen->fontColor;
      screen->SetFontColor( GFX_RED );

      if ( playerHelper.IsDead() )
      {
        screen->PrintCX( PrintPosY, Options::ReminderDeadMessage );
      }
      else
      {
        auto PrintText = Options::ReminderMessage;
        PrintText.Replace( "${minutes}", ElapsedTime.count() );

        screen->PrintCX( PrintPosY, PrintText );
        screen->PrintCX( PrintPosY + screen->FontY(), Options::ReminderAdditionalMessage );
      }
      screen->SetFontColor( originalColor );
    }
  }
}