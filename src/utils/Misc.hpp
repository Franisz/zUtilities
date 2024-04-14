// Supported with union (c) 2020 Union team
// Union SOURCE file

#include <string>

namespace GOTHIC_NAMESPACE
{
  float CoerceInRange(float start, float length, float minValue, float maxValue)
  {
    start -= max(0, start + length - maxValue);
    start += max(0, minValue - start);
    return start;
  }

  bool Intersects(const tagRECT &a, const tagRECT &b)
  {
    return (a.left <= b.right &&
            b.left <= a.right &&
            a.top <= b.bottom &&
            b.top <= a.bottom);
  }

  zSTRING GetArchivePath(zSTRING sav)
  {
    int slotID = saveLoadGameInfo->slotID;
    auto savesDir = zoptions->GetDirString(zTOptionPaths::DIR_SAVEGAMES);
    auto slotDir = saveLoadGameInfo->GetSaveSlotName(slotID);

    return (zSTRING)Union::StringANSI::Format("{0}{1}\\{2}.sav", savesDir, slotDir, sav);
  }

  zSTRING GetAttributeName(int att)
  {
    switch (att)
    {
    case NPC_ATR_HITPOINTSMAX:
      return "HP";
    case NPC_ATR_MANAMAX:
      return "MANA";
    case NPC_ATR_STRENGTH:
      return "STR";
    case NPC_ATR_DEXTERITY:
      return "DEX";
    default:
      return "<Unknown>";
    }
  }
}