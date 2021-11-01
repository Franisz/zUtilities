// Supported with union (c) 2018-2021 Union team

#ifndef __ODAMAGE_H__VER2__
#define __ODAMAGE_H__VER2__

namespace Gothic_II_Classic {

  typedef enum oEIndexDamage {
    oEDamageIndex_Barrier,
    oEDamageIndex_Blunt,
    oEDamageIndex_Edge,
    oEDamageIndex_Fire,
    oEDamageIndex_Fly,
    oEDamageIndex_Magic,
    oEDamageIndex_Point,
    oEDamageIndex_Fall,
    oEDamageIndex_MAX
  } oEDamageIndex, oEProtectionIndex;

  typedef enum oETypeDamage {
    oEDamageType_Unknown    = 0,
    oEDamageType_Barrier    = 1,
    oEDamageType_Blunt      = oEDamageType_Barrier << 1,
    oEDamageType_Edge       = oEDamageType_Blunt << 1,
    oEDamageType_Fire       = oEDamageType_Edge << 1,
    oEDamageType_Fly        = oEDamageType_Fire << 1,
    oEDamageType_Magic      = oEDamageType_Fly << 1,
    oEDamageType_Point      = oEDamageType_Magic << 1,
    oEDamageType_Fall       = oEDamageType_Point << 1,
    oEDamageType_ForceDWORD = 0xffffffff
  } oEDamageType;

  typedef enum oETypeWeapon {
    oETypeWeapon_Unknown    = 0,
    oETypeWeapon_Fist       = 1,
    oETypeWeapon_Melee      = oETypeWeapon_Fist << 1,
    oETypeWeapon_Range      = oETypeWeapon_Melee << 1,
    oETypeWeapon_Magic      = oETypeWeapon_Range << 1,
    oETypeWeapon_Special    = oETypeWeapon_Magic << 1,
    oETypeWeapon_ForceDWORD = 0xffffffff
  } oEWeaponType;

} // namespace Gothic_II_Classic

#endif // __ODAMAGE_H__VER2__