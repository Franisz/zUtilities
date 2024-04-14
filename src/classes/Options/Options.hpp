namespace GOTHIC_NAMESPACE
{

    void ZUtilitiesOptions::Misc()
    {
        TrampleMeatbugs = zoptions->ReadBool(PLUGIN_NAME, "TrampleMeatbugs", true);
        CenterInvItems = zoptions->ReadBool(PLUGIN_NAME, "CenterInvItems", true);
        RememberLockCombination = zoptions->ReadBool(PLUGIN_NAME, "RememberLockCombination", false);
        ActivateUsedMunition = zoptions->ReadBool(PLUGIN_NAME, "ActivateUsedMunition", true);
        AlternativeDialogueBoxes = zoptions->ReadBool(PLUGIN_NAME, "AlternativeDialogueBoxes", false);

        if (SelectedDialogueColor)
            delete SelectedDialogueColor;

        SelectedDialogueColor = zoptions->ReadColor(PLUGIN_NAME, "SelectedDialogueColor", "");

        if (SelectedDialogueColor)
        {
            oCInformationManager::GetInformationManager().DlgChoice->ColorSelected = *SelectedDialogueColor;
            oCInformationManager::GetInformationManager().DlgStatus->ColorSelected = *SelectedDialogueColor;
#if ENGINE < Engine_G2
            oCInformationManager::GetInformationManager().DlgTrade->DlgChoice->ColorSelected = *SelectedDialogueColor;
#endif
        }
    }

    void ZUtilitiesOptions::QuickSave()
    {
        QuickSaveMode = zoptions->ReadInt(PLUGIN_NAME, "QuickSaveMode", 1);

        KeyQuickSave = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyQuickSave", "KEY_F10"));
        KeyQuickLoad = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyQuickLoad", "KEY_F12"));

#if ENGINE >= Engine_G2
        MinSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MinSaveSlot", 15);
        MaxSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MaxSaveSlot", 20);
#else
        MinSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MinSaveSlot", 10);
        MaxSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MaxSaveSlot", 15);
#endif

        switch (Union::Locale::GetUserLocale().Language)
        {
        case Union::LANGUAGE::RUSSIAN:
            CantSave = "���� �� ����� ���� ��������� ������!";
            CantLoad = "���� �� ����� ���� ���������!";
            NoSave = "������ ���������� �� ����������!";
            break;
        case Union::LANGUAGE::GERMAN:
            CantSave = "Das Spiel kann jetzt nicht gespeichert werden!";
            CantLoad = "Das Spiel kann jetzt nicht geladen werden!";
            NoSave = "Ein solches Speichern gibt es nicht!";
            break;
        case Union::LANGUAGE::POLISH:
            CantSave = "Nie mo�na teraz zapisa� rozgrywki!";
            CantLoad = "Nie mo�na teraz wczyta� rozgrywki!";
            NoSave = "Taki zapis nie istnieje!";
            break;
        default:
            CantSave = "The game cannot be saved now!";
            CantLoad = "The game cannot be loaded now!";
            NoSave = "Such a save does not exist!";
            break;
        }

        CantSave = zoptions->ReadString(PLUGIN_NAME, "CantSave", CantSave);
        CantLoad = zoptions->ReadString(PLUGIN_NAME, "CantLoad", CantLoad);
        NoSave = zoptions->ReadString(PLUGIN_NAME, "NoSave", NoSave);
        SaveName = zoptions->ReadString(PLUGIN_NAME, "SaveName", "QuickSave");
    }

    void ZUtilitiesOptions::LogBook()
    {
        LogBookColoring = zoptions->ReadBool(PLUGIN_NAME, "LogBookColoring", true);
    }

    void ZUtilitiesOptions::PlayerStatus()
    {
        ShowGameTime = zoptions->ReadBool(PLUGIN_NAME, "ShowGameTime", false);
        ShowMunitionAmount = zoptions->ReadBool(PLUGIN_NAME, "ShowMunitionAmount", false);
        ShowTargetProtection = zoptions->ReadBool(PLUGIN_NAME, "ShowTargetProtection", true);
#if ENGINE >= Engine_G2
        ShowPickpocketIcon = zoptions->ReadBool(PLUGIN_NAME, "ShowPickpocketIcon", true);
#endif
        UseTimeMultiplier = zoptions->ReadBool(PLUGIN_NAME, "UseTimeMultiplier", false);
        KeyTimeMultiplier = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyTimeMultiplier", "KEY_Z"));
        auto MulString = zoptions->ReadString(PLUGIN_NAME, "TimeMultipliers", "1.0|2.5");

        auto MulStrings = Union::StringANSI(MulString).Split("|");
        TimeMultipliers.Clear();
        for (int i = 0; i < MulStrings.GetCount(); i++)
        {
            MulStrings[i].ShrinkToFit();
            TimeMultipliers.Insert(MulStrings[i].ConvertToDouble());
        }
        SaveReminder = zoptions->ReadInt(PLUGIN_NAME, "SaveReminder", 5);
    }

    void ZUtilitiesOptions::StatusBar()
    {
        RecoveryVisualization = zoptions->ReadBool(PLUGIN_NAME, "RecoveryVisualization", true);
        StatusBarValueMode = zoptions->ReadInt(PLUGIN_NAME, "StatusBarValueMode", 1);
        ShowEnemyBarAboveHim = zoptions->ReadBool(PLUGIN_NAME, "ShowEnemyBarAboveHim", true);
        StatusBarNames = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "StatusBarNames", "")).Split("|");
        HealthBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "HealthBarPos", "")).Split("|");
        ManaBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "ManaBarPos", "")).Split("|");
        SwimBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "SwimBarPos", "")).Split("|");
    }

    void ZUtilitiesOptions::FocusColor()
    {
        ColorNpcs = zoptions->ReadBool(PLUGIN_NAME, "ColorNpcs", true);
        ColorLockables = zoptions->ReadBool(PLUGIN_NAME, "ColorLockables", true);
        ColorItems = zoptions->ReadBool(PLUGIN_NAME, "ColorItems", true);
        ColorInter = zoptions->ReadBool(PLUGIN_NAME, "ColorInter", true);
    }

    void ZUtilitiesOptions::ItemLabel()
    {
        LabelItems = zoptions->ReadBool(PLUGIN_NAME, "LabelItems", true);
        LabelScale = zoptions->ReadReal(PLUGIN_NAME, "LabelScale", 1.25f);
        LabelMissionItems = zoptions->ReadBool(PLUGIN_NAME, "LabelMissionItems", false);
        PutLabelBehind = zoptions->ReadBool(PLUGIN_NAME, "PutLabelBehind", false);
    }

    void ZUtilitiesOptions::DamagePopup()
    {
        DamagePopupMode = zoptions->ReadInt(PLUGIN_NAME, "DamagePopupMode", 1);
        DamagePopupScale = zoptions->ReadReal(PLUGIN_NAME, "DamagePopupScale", 1.1f);
        DamagePopupShowIcons = zoptions->ReadBool(PLUGIN_NAME, "DamagePopupShowIcons", true);
        DamagePopupColorDmgTypes = zoptions->ReadBool(PLUGIN_NAME, "DamagePopupColorDmgTypes", true);
        DamagePopupColorOnlyIcon = zoptions->ReadBool(PLUGIN_NAME, "DamagePopupColorOnlyIcon", false);
    }

    void ZUtilitiesOptions::ReadOptions()
    {
        Misc();
        LogBook();
        PlayerStatus();
        StatusBar();
        QuickSave();
        FocusColor();
        ItemLabel();
        DamagePopup();
    }

    void ZUtilitiesOptions::AddTrivias()
    {
        const zSTRING nline = zSTRING("\r\n; ");

        zoptions->AddTrivia(PLUGIN_NAME, "LogBookColoring", "... enables (1) or disables (0) coloring of new and unread topics in logbook");

        zoptions->AddTrivia(PLUGIN_NAME, "RecoveryVisualization", "... enables (1) or disables (0) visualization of healing that hovered in the inventory item gives");
        zoptions->AddTrivia(PLUGIN_NAME, "StatusBarValueMode", "... specifies mode of showing status bar value, (0) - 'Disabled', (1) - 'Above', (2) - 'PointToCenter', (3) - 'Inside'");
        zoptions->AddTrivia(PLUGIN_NAME, "ShowEnemyBarAboveHim", "... enables (1) or disables (0) showing enemy hp bar above his head");
        zoptions->AddTrivia(PLUGIN_NAME, "StatusBarNames", "... defines text label for status bars like so: 'Health|Mana|Stamina', leave empty if text is unwanted");
        zoptions->AddTrivia(PLUGIN_NAME, "HealthBarPos", "... defines position of health bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '43|7873|1122|8085' and for scale 0: '43|7964|811|8116'" + nline + "... leave empty to use default position");
        zoptions->AddTrivia(PLUGIN_NAME, "ManaBarPos", "... defines position of mana bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '7053|7873|8132|8085' and for scale 0: '7381|7964|8149|8116'" + nline + "... leave empty to use default position");
        zoptions->AddTrivia(PLUGIN_NAME, "SwimBarPos", "... defines position of swim bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '3556|7873|4635|8085' and for scale 0: '3712|7964|4480|8116'" + nline + "... leave empty to use default position");

        zoptions->AddTrivia(PLUGIN_NAME, "ShowGameTime", "... enables (1) or disables (0) on screen display of in game time");
        zoptions->AddTrivia(PLUGIN_NAME, "ShowMunitionAmount", "... enables (1) or disables (0) on screen display of currently used munition amount");
        zoptions->AddTrivia(PLUGIN_NAME, "ShowTargetProtection", "... enables (1) or disables (0) protection icon and value next to the focused npc hp bar");
#if ENGINE >= Engine_G2
        zoptions->AddTrivia(PLUGIN_NAME, "ShowPickpocketIcon", "... enables (1) or disables (0) coin icon next to the focused npc name when it can be pickpocketed");
#endif
        zoptions->AddTrivia(PLUGIN_NAME, "UseTimeMultiplier", "... enables (1) or disables (0) time speed multiplier");
        zoptions->AddTrivia(PLUGIN_NAME, "KeyTimeMultiplier", "... key for cycling time speed");
        zoptions->AddTrivia(PLUGIN_NAME, "TimeMultipliers", "... defines time multipliers");

        zoptions->AddTrivia(PLUGIN_NAME, "QuickSaveMode", "... specifies QuickSave mode, (0) - 'Disabled', (1) - 'Standard', (2) - 'Alternative'" + nline + "... QuickSave with [F10] and QuickLoad with [F12]");
        zoptions->AddTrivia(PLUGIN_NAME, "KeyQuickSave", "... key for QuickSave");
        zoptions->AddTrivia(PLUGIN_NAME, "KeyQuickLoad", "... key for QuickLoad");
        zoptions->AddTrivia(PLUGIN_NAME, "MinSaveSlot", "... defines min range of used save slots");
        zoptions->AddTrivia(PLUGIN_NAME, "MaxSaveSlot", "... defines max range of used save slots");
        zoptions->AddTrivia(PLUGIN_NAME, "CantSave", "... text appearing when game cannot be saved");
        zoptions->AddTrivia(PLUGIN_NAME, "CantLoad", "... text appearing when game cannot be loaded");
        zoptions->AddTrivia(PLUGIN_NAME, "NoSave", "... text appearing when something went wrong and incorrect save slot tried to be loaded");
        zoptions->AddTrivia(PLUGIN_NAME, "SaveName", "... name used for quicksaves");

        zoptions->AddTrivia(PLUGIN_NAME, "ColorNpcs", "... enables (1) or disables (0) coloring of focused npcs");
        zoptions->AddTrivia(PLUGIN_NAME, "ColorLockables", "... enables (1) or disables (0) coloring of focused chests, doors and other lockables");
        zoptions->AddTrivia(PLUGIN_NAME, "ColorItems", "... enables (1) or disables (0) coloring of focused items");
        zoptions->AddTrivia(PLUGIN_NAME, "ColorInter", "... enables (1) or disables (0) coloring of interactive bookstands");

        zoptions->AddTrivia(PLUGIN_NAME, "LabelItems", "... enables (1) or disables (0) inventory item labeling");
        zoptions->AddTrivia(PLUGIN_NAME, "LabelScale", "... defines scale of the label");
        zoptions->AddTrivia(PLUGIN_NAME, "LabelMissionItems", "... enables (1) or disables (0) labeling of item missions, this will overwrite previous label on any item with ITEM_MISSION flag");
        zoptions->AddTrivia(PLUGIN_NAME, "PutLabelBehind", "... specifies if the label should be rendered behind the item");

        zoptions->AddTrivia(PLUGIN_NAME, "DamagePopupMode", "... specifies DamagePopup mode, (0) - 'Disabled', (1) - 'Alter Damage', (2) - 'New World'");
        zoptions->AddTrivia(PLUGIN_NAME, "DamagePopupScale", "... defines base scale of the popup");
        zoptions->AddTrivia(PLUGIN_NAME, "DamagePopupShowIcons", "... enables (1) or disables (0) icons for the popup");
        zoptions->AddTrivia(PLUGIN_NAME, "DamagePopupColorDmgTypes", "... enables (1) or disables (0) popup coloring by the damage type");
        zoptions->AddTrivia(PLUGIN_NAME, "DamagePopupColorOnlyIcon", "... enables (1) or disables (0) coloring only the popup icon");

        zoptions->AddTrivia(PLUGIN_NAME, "TrampleMeatbugs", "... enables (1) or disables (0) a way of killing meatbugs by stepping on them");
        zoptions->AddTrivia(PLUGIN_NAME, "CenterInvItems", "... enables (1) or disables (0) inventory item rendering in the center of the screen instead of the item description box");
        zoptions->AddTrivia(PLUGIN_NAME, "RememberLockCombination", "... enables (1) or disables (0) alternative way of opening locks, where discovered combination doesn't reset after fail");
        zoptions->AddTrivia(PLUGIN_NAME, "ActivateUsedMunition", "... enables (1) or disables (0) highlighting currently used ranged weapon munition in the inventory");
        zoptions->AddTrivia(PLUGIN_NAME, "AlternativeDialogueBoxes", "... enables (1) or disables (0) alternative dialogue boxes style");
        zoptions->AddTrivia(PLUGIN_NAME, "SelectedDialogueColor", "... defines color of selected line in dialogues" + nline + "... use 'R|G|B' or 'R|G|B|A' format" + nline + "... leave empty to use default color");

        zoptions->AddTrivia(PLUGIN_NAME, "SaveReminder", "... Time in minutes after which the reminder to save the game appears on the screen" + nline + "... set to -1 to disable");
    }
}