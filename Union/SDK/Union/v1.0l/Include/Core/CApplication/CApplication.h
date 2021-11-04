// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_APPLICATION_H__
#define __UNION_APPLICATION_H__

namespace UnionCore
{
  typedef void( _cdecl * TAppFunc )( );

  enum EGameEvents
  {
    GAME_ENTRY,
    GAME_INIT,
    GAME_EXIT,
    GAME_LOOP,
    GAME_SAVE_BEGIN,
    GAME_SAVE_END,
    GAME_LOAD_BEGIN_NEWGAME,
    GAME_LOAD_END_NEWGAME,
    GAME_LOAD_BEGIN_SAVEGAME,
    GAME_LOAD_END_SAVEGAME,
    GAME_LOAD_BEGIN_CHANGELEVEL,
    GAME_LOAD_END_CHANGELEVEL,
    GAME_LOAD_BEGIN_TRIGGER,
    GAME_LOAD_END_TRIGGER,
    GAME_PAUSE,
    GAME_UNPAUSE,
    GAME_DEFINE_EXTERNALS,
    GAME_EVENTS_MAX
  };

  class ASTAPI CApplication
  {
  public:
    static CList <CApplication> lstApps;

    TAppFunc* lpEvents;

    CApplication( TAppFunc* );

  public:

    TAppFunc* GetEvents();

    // 1.0a
    static CApplication* CreateRefApplication(
      TAppFunc entry,
      TAppFunc init,
      TAppFunc exit,
      TAppFunc loop,
      TAppFunc save_begin,
      TAppFunc save_end,
      TAppFunc load_begin_newgame,
      TAppFunc load_end_newgame,
      TAppFunc load_begin_savegame,
      TAppFunc load_end_savegame,
      TAppFunc load_begin_changelevel,
      TAppFunc load_end_changelevel,
      TAppFunc load_begin_trigger,
      TAppFunc load_end_trigger,
      TAppFunc pause,
      TAppFunc unpause,
      TAppFunc define_externals );

    // 1.0h
    static CApplication* CreateRefApplication(
      TAppFunc entry,
      TAppFunc init,
      TAppFunc exit,
      TAppFunc preloop,
      TAppFunc loop,
      TAppFunc postloop,
      TAppFunc menuloop,
      TAppFunc save_begin,
      TAppFunc save_end,
      TAppFunc load_begin_newgame,
      TAppFunc load_end_newgame,
      TAppFunc load_begin_savegame,
      TAppFunc load_end_savegame,
      TAppFunc load_begin_changelevel,
      TAppFunc load_end_changelevel,
      TAppFunc load_begin_trigger,
      TAppFunc load_end_trigger,
      TAppFunc pause,
      TAppFunc unpause,
      TAppFunc define_externals );

    // 1.0k
    static CApplication* CreateRefApplication(
      TAppFunc entry,
      TAppFunc init,
      TAppFunc exit,
      TAppFunc preloop,
      TAppFunc loop,
      TAppFunc postloop,
      TAppFunc menuloop,
      TAppFunc save_begin,
      TAppFunc save_end,
      TAppFunc load_begin_newgame,
      TAppFunc load_end_newgame,
      TAppFunc load_begin_savegame,
      TAppFunc load_end_savegame,
      TAppFunc load_begin_changelevel,
      TAppFunc load_end_changelevel,
      TAppFunc load_begin_trigger,
      TAppFunc load_end_trigger,
      TAppFunc pause,
      TAppFunc unpause,
      TAppFunc define_externals,
      TAppFunc apply_options );
  };
} // namespace UnionCore

#endif // __UNION_APPLICATION_H__