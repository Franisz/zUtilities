// This file is included separately for each engine version

namespace GOTHIC_NAMESPACE
{
    void Game_Loop()
    {
        quickSave->Loop();
    }

    void ApplySettings()
    {
        Options::ReadOptions();
    }

    void __fastcall Game_SaveBegin();
    auto PartialHook_Game_SaveBegin = ::Union::CreatePartialHook((void *)(zSwitch(0x0063AD80 + 8, 0x00661680 + 8, 0x006685D0 + 8, 0x006C5250 + 8)), &Game_SaveBegin);
    void __fastcall Game_SaveBegin()
    {
        quickSave->isSaving = true;
    }

    void __fastcall Game_SaveEnd();
    auto PartialHook_Game_SaveEnd = ::Union::CreatePartialHook((void *)(zSwitch(0x0063B668, 0x0066208D, 0x00668EC1, 0x006C5B41)), &Game_SaveEnd);
    void __fastcall Game_SaveEnd()
    {
        quickSave->saveEnd = true;
    }

    void LoadBegin()
    {
        quickSave->isLoading = true;
    }

    void LoadEnd()
    {
    }

    void __fastcall Game_LoadBegin_NewGame();
    auto PartialHook_Game_LoadBegin_NewGame = ::Union::CreatePartialHook((void *)(zSwitch(0x0063C070 + 9, 0x00662B20 + 9, 0x00669970 + 9, 0x006C65A0 + 9)), &Game_LoadBegin_NewGame);
    void __fastcall Game_LoadBegin_NewGame()
    {
        LoadBegin();
    }

    void __fastcall Game_LoadEnd_NewGame();
    auto PartialHook_Game_ = ::Union::CreatePartialHook((void *)(zSwitch(0x0063C28C, 0x00662D5A, 0x00669B8C, 0x006C67BC)), &Game_LoadEnd_NewGame);
    void __fastcall Game_LoadEnd_NewGame()
    {
        LoadEnd();
    }

    void __fastcall Game_LoadBegin_SaveGame();
    auto PartialHook_Game_LoadBegin_SaveGame = ::Union::CreatePartialHook((void *)(zSwitch(0x0063C2A0 + 7, 0x00662D60 + 7, 0x00669BA0 + 7, 0x006C67D0 + 7)), &Game_LoadBegin_SaveGame);
    void __fastcall Game_LoadBegin_SaveGame()
    {
        LoadBegin();
    }

    void __fastcall Game_LoadEnd_SaveGame();
    auto PartialHook_Game_LoadEnd_SaveGame = ::Union::CreatePartialHook((void *)(zSwitch(0x0063CD50, 0x0066393C, 0x0066A653, 0x006C7283)), &Game_LoadEnd_SaveGame);
    void __fastcall Game_LoadEnd_SaveGame()
    {
        LoadEnd();
    }

    void __fastcall Game_LoadBegin_ChangeLevel();
    auto PartialHook_Game_LoadBegin_ChangeLevel = ::Union::CreatePartialHook((void *)(zSwitch(0x0063CD60 + 7, 0x00663950 + 7, 0x0066A660 + 7, 0x006C7290 + 7)), &Game_LoadBegin_ChangeLevel);
    void __fastcall Game_LoadBegin_ChangeLevel()
    {
        LoadBegin();
    }

    void __fastcall Game_LoadEnd_ChangeLevel();
    auto PartialHook_Game_LoadEnd_ChangeLevel = ::Union::CreatePartialHook((void *)(zSwitch(0x0063D46B, 0x006640F0, 0x0066AD6B, 0x006C7ADD)), &Game_LoadEnd_ChangeLevel);
    void __fastcall Game_LoadEnd_ChangeLevel()
    {
        LoadEnd();
    }

    class oCPluginPerFrameCallback : public zCWorldPerFrameCallback
    {
        virtual void DoWorldPerFrameCallback(zCWorld *world, zCCamera *cam)
        {
            Game_Loop();
        }
    } pluginPerFrameCallback;

    void __fastcall Game_Init();
    auto PartialHook_Game_Init = ::Union::CreatePartialHook((void *)(zSwitch(0x00637BB6, 0x0065DFFA, 0x00665112, 0x006C1BFF)), &Game_Init);
#if ENGINE >= Engine_G2
    auto PartialHook_Game_Init2 = ::Union::CreatePartialHook((void *)(zSwitch(0x00000000, 0x00000000, 0x006650F6, 0x006C1C1B)), &Game_Init);
#endif

    void __fastcall Game_Init()
    {
        quickSave = std::make_unique<QuickSave>();
        ogame->GetWorld()->RegisterPerFrameCallback(&pluginPerFrameCallback);
        ApplySettings();
    }

    void __fastcall Game_Exit();
    auto PartialHook_Game_Exit = ::Union::CreatePartialHook((void *)(zSwitch(0x00424850 + 7, 0x00427310 + 7, 0x004251A0 + 7, 0x004254E0 + 7)), &Game_Exit);
    void __fastcall Game_Exit()
    {
        quickSave.release();
    }
}