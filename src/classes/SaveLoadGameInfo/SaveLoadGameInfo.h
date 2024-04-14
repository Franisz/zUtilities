

namespace GOTHIC_NAMESPACE
{
    class SaveLoadGameInfo
    {

    public:
        int slotID{};
        bool changeLevel{};
        zSTRING worldName{};
        zSTRING wayPoint{};

        zSTRING GetSaveSlotName(int id)
        {
            if (id > 0)
                return "savegame" + zSTRING(id);
            if (id == 0)
                return "quicksave";
            return "current";
        }
    };

    std::unique_ptr<SaveLoadGameInfo> saveLoadGameInfo;
}