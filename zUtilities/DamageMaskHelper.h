// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	using DamageMask = std::bitset<oEDamageIndex::oEDamageIndex_MAX>;

	// Mapping between oEDamageType bit flags and oEIndexDamage enum values.
	// This is needed because:
	//	- oEDamageType uses bit flags (1, 2, 4, 8, ...)
	//	- oEIndexDamage uses sequential indices (0..7)
	struct DamageMap {
		oEDamageType type;
		oEIndexDamage index;
	};

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

	class DamageMaskHelper {
	public:
		static void MarkIntDamageType(const int& damageTypeMask, DamageMask& mask);
		static void MarkMunitionDamage(const oCItem* weapon, DamageMask& mask);
		static void MarkWeaponDamage(const oCItem* weapon, DamageMask& mask);
		static bool ItemHasDistanceOrMunitionCategoryFlag(const oCItem* item);
		static void FixupSpellDamageMask(DamageMask& mask);
	};
}