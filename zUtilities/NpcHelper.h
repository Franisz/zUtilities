// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
	struct NpcProtectionStatus {
		bool immune;
		int value;
		oEIndexDamage damageIndex;
	};

	// Mapping between oEDamageType bit flags and oEIndexDamage enum values.
	// This is needed because:
	//	- oEDamageType uses bit flags (1, 2, 4, 8, ...)
	//	- oEIndexDamage uses sequential indices (0..7)
	struct DamageMap {
		oEDamageType type;
		oEIndexDamage index;
	};

	class NpcHelper {

	private:
		std::vector<oEIndexDamage> GetDamageIndexes();
		bool CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex);

	public:
		std::vector<NpcProtectionStatus> GetProtectionVisibleStatuses(oCNpc* npc);
		int GetProtectionStatusesVisibleCount(oCNpc* npc);
	};

	NpcHelper npcHelper;
}