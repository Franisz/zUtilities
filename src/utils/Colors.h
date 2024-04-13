// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  enum
  {
    CR,
    CG,
    CB,
    CA
  };

  namespace Colors
  {
    const zCOLOR White = zCOLOR(255, 255, 255);
    const zCOLOR Gray = zCOLOR(148, 144, 136);

    zCOLOR GetColorByDamageIndex(oEIndexDamage index)
    {
      switch (index)
      {
      case oEIndexDamage::oEDamageIndex_Edge:
        return zCOLOR(240, 220, 194);
      case oEIndexDamage::oEDamageIndex_Blunt:
        return zCOLOR(255, 218, 121);
      case oEIndexDamage::oEDamageIndex_Point:
        return zCOLOR(211, 255, 117);
      case oEIndexDamage::oEDamageIndex_Fire:
        return zCOLOR(230, 126, 34);
      case oEIndexDamage::oEDamageIndex_Magic:
        return zCOLOR(224, 86, 253);
      case oEIndexDamage::oEDamageIndex_Fly:
        return zCOLOR(107, 244, 255);
      case oEIndexDamage::oEDamageIndex_Fall:
        return zCOLOR(191, 222, 255);
      default:
        return White;
      }
    }
  }
}