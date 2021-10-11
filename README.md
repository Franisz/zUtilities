# zUtilities

This is a simple plugin made in [Union](https://worldofplayers.ru/threads/40376/) **1.0k** for Gothic 1 and 2.

### Features

- Allows to quickly save / load game with `F10` and `F12` keys.

  - Range of save slots used for quick save can be adjusted in `gothic.ini` with `iMinSaveSlot`, `iMaxSaveSlot` options. Default it's 5 bottom slots.
  - Notice strings are set automatically depending on system language but still can be changed manually in `gothic.ini` with `sCantSave`, `sCantLoad` and `sNoSave` options.
  - This feature can be disabled in `gothic.ini` with `bUseQuickSave` option.

- Changes name color of focused npcs, containers, doors and items.

  - Npcs: `Red` - hostile / wants to kill you, `Orange` - angry / pissed off, `Green` - friendly, `Slightly green` - friendly guild, `White` - neutral / dead, `Grey` - dead and looted.
  - Doors: `Red` - locked on key, `Orange` - locked, `White` - open.
  - Containers: `Red` - locked on key, `Orange` - locked, `Green` - open with items, `Grey` - open and empty.
  - Items: `White` - default / item can be taken, `Slightly orange` - someone will catch the hero stealing.
  - Each group can be disabled separately in `gothic.ini` with `bColorNpcs`, `bColorChests`, `bColorDoors` and `bColorItems` options.

- Renders selected inventory item in the center of the screen instead of in the item description box.

  - Camera in inventory will be shifted a bit, so the item doesn't cover the hero.
  - In Gothic 2 item will be animated only if item has `inv_animate` property set to true.
  - In Gothic 1 item will be displayed on the left or right when trading.
  - This feature can be disabled in `gothic.ini` with `bRenderInvItems` option.

- Renders labels for items in the inventory based on item parameters.

  - All icons are made via [Game-icons.net](https://game-icons.net/) website.
  - There is many possible icons to appear when item has right parameters. There are labels even for items that don't exist in original game like shields, helmets, armors requiring attribute and more.
  - Label can be set to render behind item model, so it doesn't cover it. Set `bPutLabelBehind` option to `1` in order to do that.
  - Label scale can be adjusted in `gothic.ini` with `fLabelScale` option.
  - This feature can be disabled in `gothic.ini` with `bLabelItems` option.

- Allows killing meatbugs by stepping on them.

  - This feature can be disabled in `gothic.ini` with `bTrampleMeatbugs` option.

- Also on debug build plugin prints info on the screen about plugin and platform.
