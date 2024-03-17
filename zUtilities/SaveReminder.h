// Supported with union ( c ) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool ReminderEnabled;
    bool ReminderNeedReset;
    std::chrono::minutes ReminderAfterMin;
    string ReminderMessage, ReminderAdditionalMessage, ReminderDeadMessage;

    void SaveReminder() {
      bool ReminderEnabledPrev = ReminderEnabled;
      ReminderEnabled = zoptions->ReadBool( PLUGIN_NAME, "ReminderEnabled", true );
      ReminderAfterMin = static_cast<std::chrono::minutes>( zoptions->ReadInt( PLUGIN_NAME, "ReminderAfterMin", 15 ) );

      switch ( Union.GetSystemLanguage() )
      {
      case Lang_Rus:
        ReminderMessage = "Âđĺě˙ ń ěîěĺíňŕ ďîńëĺäíĺăî ńîőđŕíĺíč˙ čăđű: ${minutes} ěčí.";
        ReminderAdditionalMessage = "Íĺ çŕáűâŕéňĺ ńîőđŕí˙ňü čăđó ÷ŕńňî č íŕ íĺńęîëüęčő ńëîňŕő!";
        ReminderDeadMessage = "ß ďđĺäóďđĺćäŕë, ÷ňî íóćíî ńîőđŕíčňü čăđó!";
        break;
      case Lang_Ger:
        ReminderMessage = "Zeit seit dem letzten Speichern des Spiels: ${minutes} min.";
        ReminderAdditionalMessage = "Denken Sie daran, Ihr Spiel oft und auf mehreren Speicherplätzen zu speichern!";
        ReminderDeadMessage = "Ich habe gewarnt, das Spiel zu speichern!";
        break;
      case Lang_Pol:
        ReminderMessage = "Czas od ostatniego zapisu gry: ${minutes} min.";
        ReminderAdditionalMessage = "Pamiętaj, aby zapisywać grę często oraz na wielu slotach!";
        ReminderDeadMessage = "Ostrzegałem, żeby zapisać grę!";
        break;
      default:
        ReminderMessage = "Time since last save game: ${minutes} min.";
        ReminderAdditionalMessage = "Remember to save the game frequently and on multiple slots!";
        ReminderDeadMessage = "I warned you to save the game!";
      }

      ReminderMessage = A zoptions->ReadString( PLUGIN_NAME, "ReminderMessage", ReminderMessage );
      ReminderAdditionalMessage = A zoptions->ReadString( PLUGIN_NAME, "ReminderAdditionalMessage", ReminderAdditionalMessage );
      ReminderDeadMessage = A zoptions->ReadString( PLUGIN_NAME, "ReminderDeadMessage", ReminderDeadMessage );

      if ( ReminderEnabledPrev != ReminderEnabled )
      {
        ReminderNeedReset = true;
      }
      else
      {
        ReminderNeedReset = false;
      }
    }
  }

  class SaveReminder {
  private:
    std::chrono::high_resolution_clock::time_point lastSaveTime;
  public:
    void Loop();
    void ResetTimer( bool update );
  };

  SaveReminder saveReminder;
}