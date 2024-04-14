// This file is included separately for each engine version

#include "Sources.h"

namespace GOTHIC_NAMESPACE
{

    void __fastcall oCGame_WriteSavegame(oCGame *_this, void *vtable, int slotID, int saveGlobals);
    auto Hook_oCGame_WriteSavegame = CreateHook(reinterpret_cast<void *>(zSwitch(0x0063AD80, 0x00661680, 0x006685D0, 0x006C5250)), &oCGame_WriteSavegame);
    void __fastcall oCGame_WriteSavegame(oCGame *_this, void *vtable, int slotID, int saveGlobals)
    {
        saveLoadGameInfo->slotID = slotID;
        saveLoadGameInfo->changeLevel = slotID == -1;
        Hook_oCGame_WriteSavegame(_this, vtable, slotID, saveGlobals);
    }

    void __fastcall oCGame_LoadGame(oCGame *_this, void *vtable, int slotID, zSTRING const &levelpath);
    auto Hook_oCGame_LoadGame = CreateHook(reinterpret_cast<void *>(zSwitch(0x0063C070, 0x00662B20, 0x00669970, 0x006C65A0)), &oCGame_LoadGame);
    void __fastcall oCGame_LoadGame(oCGame *_this, void *vtable, int slotID, zSTRING const &levelpath)
    {
        Hook_oCGame_LoadGame(_this, vtable, slotID, levelpath);
    }

    void __fastcall oCGame_LoadSavegame(oCGame *_this, void *vtable, int slotID, bool loadGlobals);
    auto Hook_oCGame_LoadSavegame = CreateHook(reinterpret_cast<void *>(zSwitch(0x0063C2A0, 0x00662D60, 0x00669BA0, 0x006C67D0)), &oCGame_LoadSavegame);
    void __fastcall oCGame_LoadSavegame(oCGame *_this, void *vtable, int slotID, bool loadGlobals)
    {
        saveLoadGameInfo->slotID = slotID;
        saveLoadGameInfo->changeLevel = false;
        Hook_oCGame_LoadSavegame(_this, vtable, slotID, loadGlobals);
    }

    void Game_Loop()
    {
        for (uint i = 0; i < popups.GetCount(); i++)
            popups[i]->Update();

        quickSave->Loop();
        playerStatus->Loop();
    }

    void ApplySettings()
    {
        Options::ReadOptions();
        Options::AddTrivias();
    }

    void __fastcall Game_SaveBegin();
    auto PartialHook_Game_SaveBegin = ::Union::CreatePartialHook((void *)(zSwitch(0x0063AD80 + 8, 0x00661680 + 8, 0x006685D0 + 8, 0x006C5250 + 8)), &Game_SaveBegin);
    void __fastcall Game_SaveBegin()
    {
        quickSave->isSaving = true;
        playerStatus->Clear();
    }

    void __fastcall Game_SaveEnd();
    auto PartialHook_Game_SaveEnd = ::Union::CreatePartialHook((void *)(zSwitch(0x0063B668, 0x0066208D, 0x00668EC1, 0x006C5B41)), &Game_SaveEnd);
    void __fastcall Game_SaveEnd()
    {
        quickSave->saveEnd = true;
        Archive();
        playerStatus->ResetSaveReminder();
    }

    void LoadBegin()
    {
        quickSave->isLoading = true;
#if ENGINE >= Engine_G2
        playerStatus->pickpocketInfos.EmptyList();
#endif
        playerStatus->Clear();
        for (uint i = 0; i < popups.GetCount(); i++)
            delete popups[i];
    }

    void __fastcall Game_Unpause();
    auto PartialHook_Game_Unpause = ::Union::CreatePartialHook((void *)(zSwitch(0x0063E2EE, 0x006650A9, 0x0066C0EE, 0x006C8E6E)), &Game_Unpause);
    void __fastcall Game_Unpause()
    {
        Options::ReadOptions();
    }

    void LoadEnd()
    {
        Unarchive();
#if ENGINE >= Engine_G2
        playerStatus->GetPickpocketInfos();
#endif
        playerStatus->ResetSaveReminder();
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
        saveLoadGameInfo->changeLevel = true;
        LoadBegin();
    }

    void __fastcall Game_LoadEnd_ChangeLevel();
    auto PartialHook_Game_LoadEnd_ChangeLevel = ::Union::CreatePartialHook((void *)(zSwitch(0x0063D46B, 0x006640F0, 0x0066AD6B, 0x006C7ADD)), &Game_LoadEnd_ChangeLevel);
    void __fastcall Game_LoadEnd_ChangeLevel()
    {
        LoadEnd();
        saveLoadGameInfo->changeLevel = false;
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
        ApplySettings();
        debugHelper = std::make_unique<DebugHelper>();
        quickSave = std::make_unique<QuickSave>();
        playerStatus = std::make_unique<PlayerStatus>();
        focusColor = std::make_unique<FocusColor>();
        logBook = std::make_unique<LogBook>();
        saveLoadGameInfo = std::make_unique<SaveLoadGameInfo>();
        ogame->GetWorld()->RegisterPerFrameCallback(&pluginPerFrameCallback);
        RegisterCommands();
    }

    void __fastcall Game_Exit();
    auto PartialHook_Game_Exit = ::Union::CreatePartialHook((void *)(zSwitch(0x00424850 + 7, 0x00427310 + 7, 0x004251A0 + 7, 0x004254E0 + 7)), &Game_Exit);
    void __fastcall Game_Exit()
    {
        debugHelper.release();
        quickSave.release();
        playerStatus.release();
        focusColor.release();
        logBook.release();
        saveLoadGameInfo.release();
    }
}