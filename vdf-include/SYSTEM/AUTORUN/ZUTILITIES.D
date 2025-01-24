META
{
  Parser = Menu;
  After = zUnionMenu.d;
  Namespace = zUtilities;
};

// Namespace = zUtilities
// Important !!!
// Supporting Unicode symbols.
// File encoding: UTF-8 (without BOM).

// ------ Constants ------
const int Start_PY  = 1400;
const int Title_PY  = 450;
const int Menu_DY   = 550;
// Text
const int Text_PX   = 400;  // Position at left side
const int Text_SX   = 8000; // Size X
const int Text_SY   = 750;  // Size Y
const int Text_DY   = 120;  // Delta alignment
// Slider
const int Slider_PX = 6400; // Position at left side
const int Slider_SX = 1500; // Size X
const int Slider_SY = 600;  // Size Y
const int Slider_DY = 0;    // Delta alignment
// Choice
const int Choice_PX = 6400; // Position at left side
const int Choice_SX = 1500; // Size X
const int Choice_SY = 350;  // Size Y
const int Choice_DY = 120;  // Delta alignment

const string MenuBackPic   = "UnionMenu_BackPic.tga";
const string ItemBackPic   = "";
const string ChoiceBackPic = "MENU_CHOICE_BACK.TGA";
const string SliderBackPic = "MENU_SLIDER_BACK.TGA";
const string SliderPosPic  = "MENU_SLIDER_POS.TGA";
const string FontSmall     = "font_old_10_white.tga";
const string FontBig       = "font_old_20_white.tga";

var int CurrentMenuItem_PY;

// ------ Prototypes ------
func void InitializeBackPicturesAndFonts()
{
  MenuBackPic   = MENU_BACK_PIC;
  ItemBackPic   = MENU_ITEM_BACK_PIC;
  ChoiceBackPic = MENU_CHOICE_BACK_PIC;
  SliderBackPic = MENU_SLIDER_BACK_PIC;
  SliderPosPic  = MENU_SLIDER_POS_PIC;
  FontSmall     = MENU_FONT_SMALL;
  FontBig       = MENU_FONT_DEFAULT;
};

prototype C_EMPTY_MENU_DEF(C_MENU)
{
  InitializeBackPicturesAndFonts();
  C_MENU_DEF();
  backpic    = MenuBackPic;
  items[0]   = "";
  items[100] = "Union_menuitem_back";
  flags      = flags | MENU_SHOW_INFO;
};

instance C_MENU_ITEM_TEXT_BASE(C_MENU_ITEM_DEF)
{
  backpic        = ItemBackPic;
  posx           = Text_PX;
  posy           = Start_PY;
  dimx           = Text_SX;
  dimy           = Text_SY;
  flags          = flags | IT_EFFECTS_NEXT;
  onselaction[0] = SEL_ACTION_UNDEF;
};

instance C_MENUITEM_CHOICE_BASE(C_MENU_ITEM_DEF)
{
  backpic  = ChoiceBackPic;
  type     = MENU_ITEM_CHOICEBOX;
  fontname = FontSmall;
  posx     = Choice_PX;
  posy     = Start_PY + Choice_DY;
  dimx     = Choice_SX;
  dimy     = Choice_SY;
  flags    = flags & ~IT_SELECTABLE;
  flags    = flags | IT_TXT_CENTER;
};

instance C_MENUITEM_SLIDER_BASE(C_MENU_ITEM_DEF)
{
  backpic       = SliderBackPic;
  type          = MENU_ITEM_SLIDER;
  fontname      = FontSmall;
  posx          = Slider_PX;
  posy          = Start_PY + Slider_DY;
  dimx          = Slider_SX;
  dimy          = Slider_SY;
  flags         = flags & ~IT_SELECTABLE;
  flags         = flags | IT_TXT_CENTER;
  userstring[0] = SliderPosPic;
};

instance MenuItem_Opt_Headline(C_MENU_ITEM_DEF)
{
  type    = MENU_ITEM_TEXT;
  posx    = 0;
  posy    = Title_PY;
  dimx    = 8100;
  flags   = flags & ~IT_SELECTABLE;
  flags   = flags | IT_TXT_CENTER;
  text[0] = Str_GetLocalizedString(
    "ZUTILITIES ННСТРОЙКИ",
    "ZUTILITIES SETTINGS",
    "ZUTILITIES EINSTELLUNGEN",
    "USTAWIENIA ZUTILITIES"
  );
};

func int Act_OpenWebLink()
{
  Open_Link("https://github.com/Franisz/zUtilities");
  return 0;
};

instance MenuItem_Opt_Open_Link(C_MENU_ITEM_DEF)
{
  C_MENU_ITEM_TEXT_BASE();
  posy += MENU_DY * 8;

  posx             = 64;
  onselaction[0]   = SEL_ACTION_UNDEF;
  oneventaction[1] = Act_OpenWebLink;
  flags            = flags | IT_TXT_CENTER;
  text[0]          = Str_GetLocalizedString(
    "Открыть ѝтраницу проекта",
    "Open project page",
    "Projektseite öffnen",
    "Otwórz stronę projektu"
  );

  text[1]          = "github.com/Franisz/zUtilities";
};

// ------ Menu ------
instance MenuItem_Union_Auto_zUtilities(C_MENU_ITEM_UNION_DEF)
{
  text[0]          = "zUtilities";
  text[1]          = "Configure zUtilities settings";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page0";
};

instance Menu_Opt_Page0(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE0_*");
};

instance Menu_Opt_Page1(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE1_*");
};

instance Menu_Opt_Page2(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE2_*");
};

instance Menu_Opt_Page3(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE3_*");
};

instance Menu_Opt_Page4(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE4_*");
};

instance Menu_Opt_Page5(C_EMPTY_MENU_DEF)
{
  Menu_SearchItems("ZUTILITIES:MENUITEM_OPT_PAGE5_*");
};

// Page 0
instance MenuItem_Opt_Page0_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page0_GoTo_Page1(C_MENU_ITEM_UNION_DEF)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  // fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY;
  posx    = 0;

  flags = flags | IT_TXT_CENTER;

  type    = MENU_ITEM_TEXT;
  dimx    = 8100;

  text[0] = "Miscellaneous 1";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page1";
};

instance MenuItem_Opt_Page0_GoTo_Page2(C_MENU_ITEM_UNION_DEF)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  // fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY;
  posx    = 0;

  flags = flags | IT_TXT_CENTER;

  type    = MENU_ITEM_TEXT;
  dimx    = 8100;

  text[0] = "Miscellaneous 2";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page2";
};

instance MenuItem_Opt_Page0_GoTo_Page3(C_MENU_ITEM_UNION_DEF)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  // fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY;
  posx    = 0;

  flags = flags | IT_TXT_CENTER;

  type    = MENU_ITEM_TEXT;
  dimx    = 8100;

  text[0] = "StatusBars & Focus";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page3";
};

instance MenuItem_Opt_Page0_GoTo_Page4(C_MENU_ITEM_UNION_DEF)
{
  CurrentMenuItem_PY = 4;
  C_MENU_ITEM_TEXT_BASE();
  // fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY;
  posx    = 0;

  flags = flags | IT_TXT_CENTER;

  type    = MENU_ITEM_TEXT;
  dimx    = 8100;

  text[0] = "DamagePopup";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page4";
};

instance MenuItem_Opt_Page0_GoTo_Page5(C_MENU_ITEM_UNION_DEF)
{
  CurrentMenuItem_PY = 5;
  C_MENU_ITEM_TEXT_BASE();
  // fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY;
  posx    = 0;

  flags = flags | IT_TXT_CENTER;

  type    = MENU_ITEM_TEXT;
  dimx    = 8100;

  text[0] = "ProtectionIcon";
  onselaction[0]   = SEL_ACTION_STARTMENU;
  onselaction_s[0] = "zUtilities:Menu_Opt_Page5";
};

instance MenuItem_Opt_Page0_Open_Link(C_MENU_ITEM)
{
  MenuItem_Opt_Open_Link();
};

// Page 1
instance MenuItem_Opt_Page1_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page1_TrampleMeatbugs(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "TrampleMeatbugs";
  text[1] = "kill meatbugs by stepping on them";
};

instance MenuItem_Opt_Page1_TrampleMeatbugs_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "TrampleMeatbugs";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page1_LogBookColoring(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "LogBookColoring";
  text[1] = "color log book entries";
};

instance MenuItem_Opt_Page1_LogBookColoring_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "LogBookColoring";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page1_UseTimeMultiplier(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "UseTimeMultiplier";
  text[1] = "time speed multiplier feature";
};

instance MenuItem_Opt_Page1_UseTimeMultiplier_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "UseTimeMultiplier";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page1_QuickSaveMode(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 4;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "QuickSaveMode";
  text[1] = "quick save / load";
};

instance MenuItem_Opt_Page1_QuickSaveMode_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "QuickSaveMode";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|Standard|Alternative";
};

instance MenuItem_Opt_Page1_PrintQuickSaveLoadInfo(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 5;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "PrintQuickSaveLoadInfo";
  text[1] = "info which save was quick saved/loaded";
};

instance MenuItem_Opt_Page1_PrintQuickSaveLoadInfo_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "PrintQuickSaveLoadInfo";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page1_ShowSystemTime(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 6;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowSystemTime";
  text[1] = "display system time on the screen";
};

instance MenuItem_Opt_Page1_ShowSystemTime_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowSystemTime";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|HH:MM|HH:MM:SS";
};

instance MenuItem_Opt_Page1_ShowGameTime(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 7;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowGameTime";
  text[1] = "display game time on the screen";
};

instance MenuItem_Opt_Page1_ShowGameTime_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowGameTime";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page1_ShowMunitionAmount(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 8;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowMunitionAmount";
  text[1] = "display used munition amount on the screen";
};

instance MenuItem_Opt_Page1_ShowMunitionAmount_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowMunitionAmount";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

// Page 2
instance MenuItem_Opt_Page2_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page2_RememberLockCombination(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "RememberLockCombination";
  text[1] = "lock combination doesn't reset after fail";
};

instance MenuItem_Opt_Page2_RememberLockCombination_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "RememberLockCombination";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page2_AlternativeDialogueBoxes(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "AlternativeDialogueBoxes";
  text[1] = "alternative style for dialogue boxes";
};

instance MenuItem_Opt_Page2_AlternativeDialogueBoxes_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "AlternativeDialogueBoxes";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page2_CenterInvItems(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "CenterInvItems";
  text[1] = "inventory item rendering in the center";
};

instance MenuItem_Opt_Page2_CenterInvItems_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "CenterInvItems";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page2_ActivateUsedMunition(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 4;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ActivateUsedMunition";
  text[1] = "highlight used munition as equipped";
};

instance MenuItem_Opt_Page2_ActivateUsedMunition_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ActivateUsedMunition";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page2_LabelItems(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 5;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "LabelItems";
  text[1] = "labeling system for inventory items";
};

instance MenuItem_Opt_Page2_LabelItems_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "LabelItems";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page2_LabelMissionItems(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 6;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "LabelMissionItems";
  text[1] = "force special label for mission items";
};

instance MenuItem_Opt_Page2_LabelMissionItems_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "LabelMissionItems";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

// Page 3
instance MenuItem_Opt_Page3_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page3_StatusBarValueMode(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "StatusBarValueMode";
  text[1] = "display numerical values for status bars";
};

instance MenuItem_Opt_Page3_StatusBarValueMode_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "StatusBarValueMode";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|Above|ToCenter|Inside";
};

instance MenuItem_Opt_Page3_ShowEnemyBarAboveHim(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowEnemyBarAboveHim";
  text[1] = "display focused npc health bar above him";
};

instance MenuItem_Opt_Page3_ShowEnemyBarAboveHim_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowEnemyBarAboveHim";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_RecoveryVisualization(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "RecoveryVisualization";
  text[1] = "visualization of healing that hovered item gives";
};

instance MenuItem_Opt_Page3_RecoveryVisualization_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "RecoveryVisualization";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_ShowPickpocketIcon(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 4;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowPickpocketIcon";
  text[1] = "coin icon next to npc name when it can be pickpocketed";
};

instance MenuItem_Opt_Page3_ShowPickpocketIcon_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowPickpocketIcon";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_ColorNpcs(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 5;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ColorNpcs";
  text[1] = "name coloring of focused npcs";
};

instance MenuItem_Opt_Page3_ColorNpcs_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ColorNpcs";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_ColorLockables(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 6;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ColorLockables";
  text[1] = "name coloring of focused chests, doors and other lockables";
};

instance MenuItem_Opt_Page3_ColorLockables_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ColorLockables";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_ColorItems(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 7;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ColorItems";
  text[1] = "name coloring of focused items";
};

instance MenuItem_Opt_Page3_ColorItems_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ColorItems";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page3_ColorInter(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 8;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ColorInter";
  text[1] = "name coloring of interactive bookstands";
};

instance MenuItem_Opt_Page3_ColorInter_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ColorInter";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

// Page 4
instance MenuItem_Opt_Page4_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page4_DamagePopupMode(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "DamagePopupMode";
  text[1] = "damage popup style";
};

instance MenuItem_Opt_Page4_DamagePopupMode_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "DamagePopupMode";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|Style 1|Style 2";
};

instance MenuItem_Opt_Page4_DamagePopupShowIcons(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "DamagePopupShowIcons";
  text[1] = "damage type icons for the popup";
};

instance MenuItem_Opt_Page4_DamagePopupShowIcons_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "DamagePopupShowIcons";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page4_DamagePopupColorDmgTypes(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "DamagePopupColorDmgTypes";
  text[1] = "popup coloring by the damage type";
};

instance MenuItem_Opt_Page4_DamagePopupColorDmgTypes_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "DamagePopupColorDmgTypes";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page4_DamagePopupColorOnlyIcon(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 4;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "DamagePopupColorOnlyIcon";
  text[1] = "color only the popup icon";
};

instance MenuItem_Opt_Page4_DamagePopupColorOnlyIcon_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "DamagePopupColorOnlyIcon";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

// Page 5
instance MenuItem_Opt_Page5_Headline(C_MENU_ITEM)
{
  MenuItem_Opt_Headline();
};

instance MenuItem_Opt_Page5_ShowTargetProtection(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 1;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowTargetProtection";
  text[1] = "protection icon and value next to the focused npc hp bar";
};

instance MenuItem_Opt_Page5_ShowTargetProtection_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowTargetProtection";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|Weapon|All";
};

instance MenuItem_Opt_Page5_ShowProtOnlyInFight(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 2;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowProtOnlyInFight";
  text[1] = "shows icons only if hero is in fight mode";
};

instance MenuItem_Opt_Page5_ShowProtOnlyInFight_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowProtOnlyInFight";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};

instance MenuItem_Opt_Page5_ShowProtAllDamageTypes(C_MENU_ITEM)
{
  CurrentMenuItem_PY = 3;
  C_MENU_ITEM_TEXT_BASE();
  fontname = FontSmall;
  posy += Menu_DY * CurrentMenuItem_PY + Text_DY;
  
  text[0] = "ShowProtAllDamageTypes";
  text[1] = "shows icons for all damage types, even if 0 protection";
};

instance MenuItem_Opt_Page5_ShowProtAllDamageTypes_Choice(C_MENU_ITEM_DEF)
{
  C_MENUITEM_CHOICE_BASE();
  posy += Menu_DY * CurrentMenuItem_PY;
  
  onchgsetoption        = "ShowProtAllDamageTypes";
  onchgsetoptionsection = "zUtilities";
  text[0]               = "Off|On";
};
