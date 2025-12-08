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
		auto protectionValue = npc->GetProtectionByIndex(damageIndex);
		auto protectionMode = player->IsInFightMode_S(NPC_WEAPON_NONE) ? Options::ShowTargetProtectionNoFight : Options::ShowTargetProtectionInFight;

		if (protectionMode == TargetProtectionMode::AllButZeros && protectionValue == 0) {
			return false;
		}

		return true;
	}

	std::vector<oEIndexDamage> NpcHelper::GetDamageIndexes() {
		int playerDmgIndex = player->GetActiveDamageIndex();
		std::vector<oEIndexDamage> vec;

		bool isInFightMode = !player->IsInFightMode_S(NPC_WEAPON_NONE);
		auto protectionMode = isInFightMode ? Options::ShowTargetProtectionInFight : Options::ShowTargetProtectionNoFight;

		if (protectionMode >= TargetProtectionMode::AllButZeros) {
			return PROTECTION_DAMAGE_INDEXES;
		}

		if (protectionMode == TargetProtectionMode::CurrentWeapon && playerDmgIndex == Invalid) {
			auto equippedWeapon = player->GetEquippedMeleeWeapon();

			if (!equippedWeapon) {
				playerDmgIndex = player->GetFistDamageIndex();
			}
			else {
				playerDmgIndex = GetTopDmgIndex(equippedWeapon->damage, equippedWeapon->damageTypes);
			}

			vec.push_back((oEIndexDamage)playerDmgIndex);

			if (!isInFightMode) { // check for equipped distance weapon and spell when no fight mode
				equippedWeapon = player->GetEquippedRangedWeapon();
				if (equippedWeapon) {
					playerDmgIndex = GetTopDmgIndex(equippedWeapon->damage, equippedWeapon->damageTypes);
					vec.push_back((oEIndexDamage)playerDmgIndex);
				}

				if (player->HasMagic()) {
					vec.push_back(oEDamageIndex_Magic);
				}
			}
		}
		else {
			vec.push_back((oEIndexDamage)playerDmgIndex);
		}

		return vec;
	}

	std::vector<NpcProtectionStatus> NpcHelper::GetProtectionVisibleStatuses(oCNpc* npc) {
		auto vec = std::vector<NpcProtectionStatus>();

		if (playerStatus.focusBar->IsShowTargetProtectionDisabled()) {
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
}