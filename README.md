# zUtilities

This is a plugin with a set of many quality-of-life and utility features made for [Union](https://worldofplayers.ru/threads/40376/) **1.0m** for Gothic 1 and 2 games. Plugin can also be found on [Steam Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=2792434617).

### Features

> Plugin options can be changed in `gothic.ini`.

> Some of the options can also be changed via ingame menu. (Requires Union 1.0m or higher.)

- Quickly save / load game with `F10` and `F12` keys.

  - Shortcuts can be changed with `KeyQuickSave` and `KeyQuickLoad` options. A full list of available keys to choose from is [there](https://github.com/Franisz/zUtilities/blob/master/zUtilities/KeyCode.h).
  - Range of save slots used for quick save can be adjusted in `gothic.ini` with `MinSaveSlot`, `MaxSaveSlot` options. Default, it's 6 bottom slots.
  - Print information about the save name and slot number after a quick save/load action is performed by setting the `PrintQuickSaveLoadInfo` option to `1`.
  - Notice strings are set automatically depending on system language but still can be changed manually in `gothic.ini` with `CantSave`, `CantLoad`, `NoSave`, `SaveCompleted` and `LoadCompleted` options.
  - This feature can be disabled in `gothic.ini` with `QuickSaveMode` option.
  - Change `QuickSaveMode` option for different style or disable: `0` - _Disabled_, `1` - _Standard_, `2` - _Alternative_.
  - Game can also be quick loaded from main menu by pressing `KeyQuickLoad`.
  - Save can be automatically loaded after game start when `QuickLoadAfterGameStart` is set to `1`.

- Changes name color of focused npcs, containers, doors and items.

  - Npcs: `Red` - hostile / wants to kill you, `Orange` - angry / pissed off, `Cyan` - partymember, `Green` - friendly, `Slightly green` - friendly guild, `White` - neutral / dead, `Grey` - dead and looted.
  - Lockables: `Red` - locked on key, `Orange` - locked, `Light red` - can be opened with a key or lockpick, `Green` - open with items, `Grey` - permanently closed or opened and empty.
  - Items: `White` - default / item can be taken, `Slightly orange` - someone will catch the hero stealing.
  - Intractable book stands: `Green` - unread, `White` - default / read.
  - Each group can be disabled separately in `gothic.ini` with `ColorNpcs`, `ColorLockables`, `ColorItems` and `ColorInter` options.

- Renders the selected inventory item in the center of the screen instead of in the item description box.

  - Camera in inventory will be shifted a bit, so the item doesn't cover the hero.
  - In Gothic 2 item will be animated only if item has `inv_animate` property set to true.
  - In Gothic 1 item will be displayed on the left or right when trading.
  - This feature can be disabled in `gothic.ini` with `CenterInvItems` option.

- Renders labels for items in the inventory based on item parameters.

  - All icons are made via [Game-icons.net](https://game-icons.net/) website.
  - There are many possible icons to appear when item has right parameters. There are labels even for items that don't exist in original game like shields, helmets, armors requiring attribute and more.
  - Label can be set to render behind item model, so it doesn't cover it. Set `PutLabelBehind` option to `1` in order to do that.
  - `LabelMissionItems` option allows items with `ITEM_MISSION` flag to have special mission flag. This option is disabled by default.
  - Label scale can be adjusted in `gothic.ini` with `LabelScale` option.
  - This feature can be disabled in `gothic.ini` with `LabelItems` option.

- Displays a popup when dealing damage.

  - This feature is inspired by [New World](https://www.newworld.com/)'s damage label and based on [AlterDamage](https://github.com/UnresolvedExternal/Union_AlterDamage) popup code.
  - Set `DamagePopupMode` option to `1` for _Alter Damage_ style, `2` for _New World_ style and `0` to disable this feature completely.
  - Popup scale depends on the amount of damage dealt compared to the target's max hp, the fact if the hit was critical or not and `Scale` option from `SystemPack.ini`. Base scale can also be adjusted in `gothic.ini` with `DamagePopupScale`.
  - Icons and base colors are unique for every damage type and each can be separately disabled in `gothic.ini` with `DamagePopupShowIcons` and, `DamagePopupColorDmgTypes` options.
  - By default the number has the same color as the icon, but it can be disabled in `gothic.ini` with `DamagePopupColorOnlyIcon` option.

- Adds few features for status bars.

  - Focused npc hp bar is displayed right above his name. This can be disabled with `ShowEnemyBarAboveHim` option.
  - Added option to show numeric values of status bars. Change `StatusBarValueMode` option for different style or disable: `0` - _Disabled_, `1` - _Above_, `2` - _PointToCenter_, `3` - _Inside_. By default, option to show value above bar is active.
  - Optionally, text labels can be set to be displayed right next to the bar value. Set `StatusBarNames` like so: `Health|Mana|Stamina`. Leave empty and no text will appear.
  - Health, mana and swim status bars position can be changed with `HealthBarPos`, `ManaBarPos` and `SwimBarPos` options.
    - Four positions need to be defined in a form `x1|y1|x2|y2` that reflects a virtual position in `0|0|8192|8192` scope.
    - Default health bar position for systempack `Scale=1` is: `43|7873|1122|8085` and for `Scale=0`: `43|7964|811|8116`
    - Default mana bar position for systempack `Scale=1` is: `7053|7873|8132|8085` and for `Scale=0`: `7381|7964|8149|8116`
    - Default swim bar position for systempack `Scale=1` is: `3556|7873|4635|8085` and for `Scale=0`: `3712|7964|4480|8116`
    - Leave options empty to use default positions.

- Allows to change world speed multiplier.

  - This feature is completely disabled by default and can be enabled with `UseTimeMultiplier` option.
  - Time multipliers can be changed with `TimeMultipliers` option like so: `0.65|1.0|2.7|3.5`.
  - World speed will cycle in the order of set multipliers after pressing `Z`. Shortcut can also be changed with `KeyTimeMultiplier` option.
  - Currently used multiplier will be shown next to the time icon.

- Displays protection icon and value next to the focused npc hp bar.

  - Setting `ShowTargetProtection` option to `0` disables this feature, `1` displays the protection that matches currently used weapon and `2` shows all protection stats.
  - `ShowProtOnlyInFight` and `ShowProtAllDamageTypes` are extra options that can be used, to alter what is displayed.

- Displays coin icon next to the focused npc name if player can pickpocket him.

  - This feature can be disabled in `gothic.ini` with `ShowPickpocketIcon` option.
  - Works in G2/G2A only.

- Changes color of log entry titles in player's log book.

  - New log entries will appear green and updated ones will be orange.
  - This feature can be disabled in `gothic.ini` with `LogBookColoring` option.

- Allows to change color of selected text line in dialogues with `SelectedDialogueColor` option.

  - Enter any color in `R|G|B` or `R|G|B|A` format, e.g.: `30|200|60|255`
  - Leave option empty to keep using default color.

- Allows to use alternative way of opening locks with lockpicks.

  - Essentially, the combination doesn't reset after fail. The player can keep going forward without the need to reenter the already discovered combination over again after every fail.
  - This is disabled by default and can be enabled with `RememberLockCombination` option.

- Allows to display current system time in 24H format.

  - This is disabled by default and can be enabled in two ways. Set `ShowSystemTime` option to `1` for `Hour:Minute` format, `2` for `Hour:Minute:Second` format.

- Allows to display current in game time.

  - This is disabled by default and can be enabled with `ShowGameTime` option.

- Allows to display currently used munition amount.

  - This is disabled by default and can be enabled with `ShowMunitionAmount` option.

- Reminds the player to save the game by displaying an icon with a timer after playing without saving the game for too long.

  - By default, it reminds the player after 5 minutes since the last save game. Timer can be changed in `gothic.ini` with `SaveReminder` option. Feature can be turned off completely by setting `SaveReminder` to `-1`.

- Allows killing meatbugs by stepping on them.

  - This feature can be disabled in `gothic.ini` with `TrampleMeatbugs` option.

- Highlights munition used by currently equipped ranged weapon.

  - This feature can be disabled in `gothic.ini` with `ActivateUsedMunition` option.

- Displays on the status bars how much hovered item will heal.

  - Heal value is based on the `count` value of the item associated with the `text` that is equal to the original recovery string variables `NAME_BONUS_HP` and `NAME_BONUS_MANA`.
  - This feature can be disabled in `gothic.ini` with `RecoveryVisualization` option.

- Allows to use alternative dialogue boxes when talking.

  - This is disabled by default and can be enabled with `AlternativeDialogueBoxes` option.

- Display debug info data about focused vob or selected in the inventory item.

  - Use `zutilities debug` command to toggle on/off.
  - While debug command is active, `zutilities showtriggers` command can be toggled to display invisible triggers.

- Insert all items into inventory with `zutilities giveallitems` command.

- Check currently used plugin version through in game console with `zutilities version` command.

### Options

<details>
  <summary>Automatically generated plugin section with default settings.</summary>

```ini
[ZUTILITIES]
TrampleMeatbugs=1
; ... enables (1) or disables (0) a way of killing meatbugs by stepping on them

CenterInvItems=1
; ... enables (1) or disables (0) inventory item rendering in the center of the screen instead of the item description box

RememberLockCombination=0
; ... enables (1) or disables (0) alternative way of opening locks, where discovered combination doesn't reset after fail

ActivateUsedMunition=1
; ... enables (1) or disables (0) highlighting currently used ranged weapon munition in the inventory

AlternativeDialogueBoxes=0
; ... enables (1) or disables (0) alternative dialogue boxes style

SelectedDialogueColor=
; ... defines color of selected line in dialogues
; ... use 'R|G|B' or 'R|G|B|A' format
; ... leave empty to use default color

LogBookColoring=1
; ... enables (1) or disables (0) coloring of new and unread topics in logbook

ShowSystemTime=0
; ... on screen display of system time (24H format), (0) - 'Disabled', (1) - 'Hour:Minute format', (2) - 'Hour:Minute:Second format

ShowGameTime=0
; ... enables (1) or disables (0) on screen display of in game time

ShowMunitionAmount=0
; ... enables (1) or disables (0) on screen display of currently used munition amount

ShowPickpocketIcon=1
; ... enables (1) or disables (0) coin icon next to the focused npc name when it can be pickpocketed

UseTimeMultiplier=0
; ... enables (1) or disables (0) time speed multiplier

KeyTimeMultiplier=KEY_Z
; ... key for cycling time speed

TimeMultipliers=1.0|2.5
; ... defines time multipliers

SaveReminder=5
; ... Time in minutes after which the reminder to save the game appears on the screen
; ... set to -1 to disable

ShowTargetProtection=1
; ... enables for currently equipped weapon (1) or shows all protection stats (2) or disables (0) protection icon and value next to the focused npc hp bar

ShowProtOnlyInFight=1
; ... enables (1) or disables (0) showing protection stats only during combat

ShowProtAllDamageTypes=0
; ... enables (1) or disables (0) showing all protection stats, even if they are 0

RecoveryVisualization=1
; ... enables (1) or disables (0) visualization of healing that hovered in the inventory item gives

StatusBarValueMode=1
; ... specifies mode of showing status bar value, (0) - 'Disabled', (1) - 'Above', (2) - 'PointToCenter', (3) - 'Inside'

ShowEnemyBarAboveHim=1
; ... enables (1) or disables (0) showing enemy hp bar above his head

StatusBarNames=
; ... defines text label for status bars like so: 'Health|Mana|Stamina', leave empty if text is unwanted

HealthBarPos=
; ... defines position of health bar like so: 'x1|y1|x2|y2'
; ... default position for scale 1 is: '43|7873|1122|8085' and for scale 0: '43|7964|811|8116'
; ... leave empty to use default position

ManaBarPos=
; ... defines position of mana bar like so: 'x1|y1|x2|y2'
; ... default position for scale 1 is: '7053|7873|8132|8085' and for scale 0: '7381|7964|8149|8116'
; ... leave empty to use default position

SwimBarPos=
; ... defines position of swim bar like so: 'x1|y1|x2|y2'
; ... default position for scale 1 is: '3556|7873|4635|8085' and for scale 0: '3712|7964|4480|8116'
; ... leave empty to use default position

QuickSaveMode=1
; ... specifies QuickSave mode, (0) - 'Disabled', (1) - 'Standard', (2) - 'Alternative'
; ... QuickSave with [F10] and QuickLoad with [F12]

QuickLoadAfterGameStart=0
; ... enables (1) or disables (0) load last quicksave immediately after game starts

PrintQuickSaveLoadInfo=0
; ... enables (1) or disables (0) printing information which save and slot number has been quick saved/loaded

KeyQuickSave=KEY_F10
; ... key for QuickSave

KeyQuickLoad=KEY_F12
; ... key for QuickLoad

MinSaveSlot=15
; ... defines min range of used save slots

MaxSaveSlot=20
; ... defines max range of used save slots

CantSave=The game cannot be saved now!
; ... text appearing when game cannot be saved

CantLoad=The game cannot be loaded now!
; ... text appearing when game cannot be loaded

NoSave=Such a save does not exist!
; ... text appearing when something went wrong and incorrect save slot tried to be loaded

SaveCompleted=Game saved.
;... text appearing when game was quick saved

LoadCompleted=Game loaded.
;... text appearing when game was quick loaded

SaveName=QuickSave
; ... name used for quicksaves

ColorNpcs=1
; ... enables (1) or disables (0) coloring of focused npcs

ColorLockables=1
; ... enables (1) or disables (0) coloring of focused chests, doors and other lockables

ColorItems=1
; ... enables (1) or disables (0) coloring of focused items

ColorInter=1
; ... enables (1) or disables (0) coloring of interactive bookstands

LabelItems=1
; ... enables (1) or disables (0) inventory item labeling

LabelScale=1.25
; ... defines scale of the label

LabelMissionItems=0
; ... enables (1) or disables (0) labeling of item missions, this will overwrite previous label on any item with ITEM_MISSION flag

PutLabelBehind=0
; ... specifies if the label should be rendered behind the item

DamagePopupMode=1
; ... specifies DamagePopup mode, (0) - 'Disabled', (1) - 'Alter Damage', (2) - 'New World'

DamagePopupScale=1.10000002
; ... defines base scale of the popup

DamagePopupShowIcons=1
; ... enables (1) or disables (0) icons for the popup

DamagePopupColorDmgTypes=1
; ... enables (1) or disables (0) popup coloring by the damage type

DamagePopupColorOnlyIcon=0
; ... enables (1) or disables (0) coloring only the popup icon
```

</details>
