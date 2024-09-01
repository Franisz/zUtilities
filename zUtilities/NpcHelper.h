// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
	struct NpcProtectionStatus {
		bool immune;
		int value;
		oEIndexDamage damageIndex;
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