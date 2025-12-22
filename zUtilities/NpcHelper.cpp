// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	const std::vector<oEIndexDamage> PROTECTION_DAMAGE_INDEXES = std::vector<oEIndexDamage>({
		oEIndexDamage::oEDamageIndex_Edge,
		oEIndexDamage::oEDamageIndex_Blunt,
		oEIndexDamage::oEDamageIndex_Point,
		oEIndexDamage::oEDamageIndex_Fire,
		oEIndexDamage::oEDamageIndex_Magic,
		oEIndexDamage::oEDamageIndex_Fly,
		oEIndexDamage::oEDamageIndex_Fall
		});

	static constexpr DamageMap DAMAGE_MAP[] = {
	{ oEDamageType_Barrier, oEDamageIndex_Barrier },
	{ oEDamageType_Blunt,   oEDamageIndex_Blunt   },
	{ oEDamageType_Edge,    oEDamageIndex_Edge    },
	{ oEDamageType_Fire,    oEDamageIndex_Fire    },
	{ oEDamageType_Fly,     oEDamageIndex_Fly     },
	{ oEDamageType_Magic,   oEDamageIndex_Magic   },
	{ oEDamageType_Point,   oEDamageIndex_Point   },
	{ oEDamageType_Fall,    oEDamageIndex_Fall    }
	};

	inline static void MarkWeaponDamage(const oCItem* weapon, DamageMask& mask)
	{
		for (int i = 0; i < oEDamageIndex::oEDamageIndex_MAX; ++i) {
			if (weapon->damage[i] > 0) {
				mask.set(i);
			}
		}
	}

	inline static void MarkSpellDamage(int damageTypeMask, DamageMask& mask)
	{
		for (const auto& mapItem : DAMAGE_MAP) {
			if (damageTypeMask & mapItem.type) {
				mask.set(mapItem.index);
			}
		}
	}

	/* In G1 default damageType for spell is `oEDamageType_Blunt` so for summon/transformation etc. spells
	it's best to reset this flag in mask to hide incorrect protection icon.
	In G2 default damageType for spell is `oEDamageType_Magic` so it's left untouched.*/
	inline static void FixupSpellDamageMask(DamageMask& mask)
	{
#if ENGINE <= Engine_G1A
		mask.reset(oEDamageIndex_Blunt);
#endif
	}

	inline static std::vector<oEIndexDamage> BuildOrderedDamageIndexes(const DamageMask& mask)
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

	bool NpcHelper::CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex)
	{
		auto protectionValue = npc->GetProtectionByIndex(damageIndex);
		auto protectionMode = player->IsInFightMode_S(NPC_WEAPON_NONE) ? Options::ShowTargetProtectionNoFight : Options::ShowTargetProtectionInFight;

		if (protectionMode == TargetProtectionMode::AllButZeros && protectionValue == 0) {
			return false;
		}

		return true;
	}

	std::vector<oEIndexDamage> NpcHelper::GetDamageIndexes()
	{
		bool isInFightMode = !player->IsInFightMode_S(NPC_WEAPON_NONE);
		auto protectionMode = isInFightMode
			? Options::ShowTargetProtectionInFight
			: Options::ShowTargetProtectionNoFight;

		if (protectionMode >= TargetProtectionMode::AllButZeros) {
			return PROTECTION_DAMAGE_INDEXES;
		}

		DamageMask mask;
		mask.reset();

		if (isInFightMode) {
			BuildFightModeDamage(mask);
		}
		else {
			BuildNoFightModeDamage(mask);
		}

		return BuildOrderedDamageIndexes(mask);
	}

	std::vector<NpcProtectionStatus> NpcHelper::GetProtectionVisibleStatuses(oCNpc* npc) {
		auto vec = std::vector<NpcProtectionStatus>();

		if (playerStatus.focusBar->IsShowTargetProtectionDisabled()) {
			return vec;
		}

		if (npc->HasFlag(NPC_FLAG_IMMORTAL))
		{
			NpcProtectionStatus status;
			vec.push_back(status);
			return vec;
		}

		auto damageIndexes = GetDamageIndexes();
		for (auto damageIndex : damageIndexes)
		{
			if (!CanRenderProtectionStatus(npc, damageIndex)) {
				continue;
			}

			NpcProtectionStatus status;
			status.value = npc->GetProtectionByIndex(damageIndex);
			status.damageIndex = damageIndex;
			status.immune = status.value < 0;
			vec.push_back(status);
		}

		return vec;
	}

	int NpcHelper::GetProtectionStatusesVisibleCount(oCNpc* npc) {
		if (playerStatus.focusBar->IsShowTargetProtectionDisabled()) {
			return 0;
		}

		if (npc->HasFlag(NPC_FLAG_IMMORTAL)) {
			return 1;
		}

		int count = 0;
		auto damageIndexes = GetDamageIndexes();
		for (auto damageIndex : damageIndexes)
		{
			if (!CanRenderProtectionStatus(npc, damageIndex)) {
				continue;
			}

			count++;
		}

		return count;
	}

	void NpcHelper::BuildFightModeDamage(DamageMask& mask)
	{
		// Check for active spell
		if (player->IsInFightMode_S(NPC_WEAPON_MAG)) {
			auto spell = player->mag_book->GetSelectedSpell();
			MarkSpellDamage(spell->damageType, mask);
			FixupSpellDamageMask(mask);
			return;
		}

		// Check for active melee/distance weapon
		if (auto weapon = player->GetWeapon()) {
			MarkWeaponDamage(weapon, mask);
		}
		else {
			mask.set(oEDamageIndex_Blunt); // Fist damage
		}
	}

	void NpcHelper::BuildNoFightModeDamage(DamageMask& mask)
	{
		// Check for all selected spells
		if (player->mag_book) {
			auto& spells = player->mag_book->spells;
			for (int i = 0; i < spells.GetNum(); ++i) {
				MarkSpellDamage(spells[i]->damageType, mask);
			}
			FixupSpellDamageMask(mask);
		}

		// Check for melee weapon
		auto weapon = player->GetEquippedMeleeWeapon();
		if (weapon) {
			MarkWeaponDamage(weapon, mask);
		}
		else {
			mask.set(oEDamageIndex_Blunt); // Fist damage
		}

		// Check for distance weapon
		weapon = player->GetEquippedRangedWeapon();
		if (weapon) {
			MarkWeaponDamage(weapon, mask);
		}
	}
}