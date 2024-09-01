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


	bool NpcHelper::CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex)
	{
		if (Options::ShowProtAllDamageTypes || Options::ShowCurrWeapProtOnly) {
			return true;
		}

		return npc->GetProtectionByIndex(damageIndex) != 0;
	}

	std::vector<oEIndexDamage> NpcHelper::GetDamageIndexes() {
		if (player->IsInFightMode_S(0) && (Options::ShowProtOnlyInFight || Options::ShowCurrWeapProtOnly)) {
			return std::vector<oEIndexDamage>();
		}

		if (!Options::ShowCurrWeapProtOnly) {
			return PROTECTION_DAMAGE_INDEXES;
		}

		int playerDmgIndex = player->GetActiveDamageIndex();
		if (!playerDmgIndex)
		{
			return std::vector<oEIndexDamage>();
		}

		auto vec = std::vector<oEIndexDamage>();
		vec.push_back((oEIndexDamage)playerDmgIndex);
		return vec;
	}

	std::vector<NpcProtectionStatus> NpcHelper::GetProtectionVisibleStatuses(oCNpc* npc) {
		auto vec = std::vector<NpcProtectionStatus>();

		if (!Options::ShowTargetProtection) {
			return vec;
		}

		if (npc->HasFlag(NPC_FLAG_IMMORTAL))
		{
			NpcProtectionStatus status;
			status.immune = true;
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
		if (!Options::ShowTargetProtection) {
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
}