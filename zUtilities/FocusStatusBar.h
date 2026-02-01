// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
	enum FocusStatusProtectionPlacement
	{
		NONE = 0,
		TOP = 1,
		RIGHT = 2
	};

	enum TargetProtectionMode {
		Disabled = 0,
		CurrentWeapon = 1,
		AllButZeros = 2,
		All = 3
	};

	class FocusStatusBar : public StatusBar {
	private:
		const zSTRING IMMUNE_ABBREVIATION = "IMM";
		zCView* protView;
		void MoveFocusBar(int x, int y, oCNpc* npc);
		bool TryShowProt(oCNpc* npc);
		int GetProtMargin();
		int GetProtSize();
		int GetProtStartX(FocusStatusProtectionPlacement placement);
		int GetProtStartY(FocusStatusProtectionPlacement placement);
		int CalcProtRenderWidth(std::vector<NpcProtectionStatus> statuses);
		FocusStatusProtectionPlacement GetProtPlacement(oCNpc* npc);
		zSTRING GetIconNameByDamageIndex(const oEIndexDamage& index);
		virtual void PrintValueOutside(zSTRING str, oCNpc* npc) override;

	public:
		static bool IsDistanceWeaponDamageTypeOverwritten;
		FocusStatusBar();
		bool IsShowTargetProtectionDisabled();
		bool NeedAdjustPosition(int x, int y, oCNpc* npc);
		virtual void Loop() override;
		virtual bool Init() override;
		virtual void Clear() override;
	};
}