// Supported with union (c) 2020 Union team

// User API for oCNpc
// Add your methods here

void __thiscall OnChrzonszcz( zCVob* );
void OnDamage_Hit_Union( oSDamageDescriptor& );
void OnDamage_Hit_DistanceWeapon( oSDamageDescriptor& );
void EquipItem_Union( oCItem* );
int GetAivar( zSTRING aivar );
int EV_UseItemToState_Union( oCMsgManipulate* );
int GetFistDamageIndex();
int GetWeaponDamageIndex();
int GetSpellDamageIndex();
int GetActiveDamageIndex();
void CopyTransformSpellInvariantValuesTo_Union( oCNpc* );
oCItem* GetHandMunition();