// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE
{
	const std::vector<oEIndexDamage> DamageMaskHelper::PROTECTION_DAMAGE_INDEXES = std::vector<oEIndexDamage>({
		oEIndexDamage::oEDamageIndex_Edge,
		oEIndexDamage::oEDamageIndex_Blunt,
		oEIndexDamage::oEDamageIndex_Point,
		oEIndexDamage::oEDamageIndex_Fire,
		oEIndexDamage::oEDamageIndex_Magic,
		oEIndexDamage::oEDamageIndex_Fly,
		oEIndexDamage::oEDamageIndex_Fall
		});

	void DamageMaskHelper::MarkIntDamageType(const int& damageTypeMask, DamageMask& mask)
	{
		for (const auto& mapItem : DAMAGE_MAP) {
			if (damageTypeMask & mapItem.type) {
				mask.set(mapItem.index);
			}
		}
	}

	void DamageMaskHelper::MarkWeaponDamage(const oCItem* weapon, DamageMask& mask)
	{
		for (int i = 0; i < oEDamageIndex::oEDamageIndex_MAX; ++i) {
			if (weapon->damage[i] > 0) {
				mask.set(i);
			}
		}
	}

	void DamageMaskHelper::MarkMunitionDamage(const oCItem* weapon, DamageMask& mask)
	{
		const bool hasMunition = weapon->munition != 0;
		const bool isCrossbow = (weapon->flags & ITM_FLAG_CROSSBOW) != 0;

		const oCItem* leftHand = player->GetLeftHand()->CastTo<oCItem>();
		const oCItem* rightHand = player->GetRightHand()->CastTo<oCItem>();
		const oCItem* handItem = isCrossbow ? leftHand : rightHand;

		const int handInstanz =
			reinterpret_cast<int>(handItem)
			? handItem->instanz
			: 0;

		const bool useMunition =
			static_cast<bool>(
				hasMunition &
				(handItem != nullptr) &
				(handInstanz == weapon->munition)
				);

		const oCItem* damageSource = useMunition ? handItem : weapon;

		MarkWeaponDamage(damageSource, mask);
	}

	std::vector<oEIndexDamage> DamageMaskHelper::BuildOrderedDamageIndexes(const DamageMask& mask)
	{
		std::vector<oEIndexDamage> result;
		result.reserve(PROTECTION_DAMAGE_INDEXES.size());

		for (auto index : PROTECTION_DAMAGE_INDEXES) {
			if (mask.test(index)) {
				result.push_back(index);
			}
		}
		return result;
	}

	bool DamageMaskHelper::ItemHasDistanceOrMunitionCategoryFlag(const oCItem* item) {
		return item->mainflag & (ITM_CAT_FF | ITM_CAT_MUN);
	}

	/* In G1 default damageType for spell is `oEDamageType_Blunt` so for summon/transformation etc. spells
it's best to reset this flag in mask to hide incorrect protection icon.
In G2 default damageType for spell is `oEDamageType_Magic` so it's left untouched.*/
	void DamageMaskHelper::FixupSpellDamageMask(DamageMask& mask)
	{
#if ENGINE <= Engine_G1A
		mask.reset(oEDamageIndex_Blunt);
#endif
	}
}