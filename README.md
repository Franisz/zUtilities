# zUtilities

This is a simple plugin made in [Union](https://worldofplayers.ru/threads/40376/) **1.0k** for Gothic 1 and 2.

### Features

- Allows to quickly save / load game with `F10` and `F12` keys.

  - Range of save slots used for quick save can be adjusted in `gothic.ini` with `iMinSaveSlot`, `iMaxSaveSlot` options.
  - Notice strings are set automatically depending on system language but still can be changed manually in `gothic.ini` with `sCantSave`, `sCantLoad` and `sNoSave` options.
  - This feature can be disabled in `gothic.ini` with `bUseQuickSave` option.

- Changes name color of focused npcs, containers and doors.

  - Npcs: `Red - hostile / wants to kill you`, `Orange - angry / pissed off`, `Green - friendly`, `White - neutral / dead`, `Grey - dead and looted`.
  - Doors: `Red - locked on key`, `Orange - locked`, `White - open`.
  - Containers: `Red - locked on key`, `Orange - locked`, `Green - open with items`, `Grey - open and empty`.
  - Each group can be disabled separately in `gothic.ini` with `bColorNpcs`, `bColorChests` and `bColorDoors` options.

- Stepping on meatbugs kills them and give player exp.
  - This can be disabled in `gothic.ini` with `bTrampleMeatbugs` option.

- Also on debug build prints info on the screen about plugin and platform.
