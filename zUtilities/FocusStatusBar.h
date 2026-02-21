// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
	struct NpcProtectionStatus {
		bool immune;
		int value;
		oEIndexDamage damageIndex;
	};

	enum FocusStatusProtectionPlacement
	{
		NONE = 0,
		TOP = 1,
		RIGHT = 2,
		CLOSE = 3
	};

	enum TargetProtectionMode {
		Disabled = 0,
		CurrentWeapon = 1,
		All = 2
	};

	struct ProtectionRenderData {
		zSTRING text;
		zSTRING texture;
		zCOLOR color;
	};

	class FocusStatusBar : public StatusBar {
	private:
		const zSTRING IMMUNE_ABBREVIATION = "IMM";
		const zSTRING crackedShieldTexture = zSTRING("ICON_PROTECTIONS"); // https://game-icons.net/1x1/lorc/cracked-shield.html
		const int protectionPlacementRightMargin = 250;
		zCView* protView;
		void MoveFocusBar(int x, int y, oCNpc* npc);
		bool TryShowProt(oCNpc* npc);
		int GetProtMargin();
		int GetProtSize();
		int GetProtStartX(FocusStatusProtectionPlacement placement);
		int GetProtStartY(FocusStatusProtectionPlacement placement);
		int CalcProtRenderWidth(const std::vector<NpcProtectionStatus>& statuses);
		FocusStatusProtectionPlacement GetProtPlacement(oCNpc* npc);
		zSTRING GetIconNameByDamageIndex(const oEIndexDamage& index);
		virtual void PrintValueOutside(zSTRING str, oCNpc* npc) override;
		void RenderProtectionIconsClose(int startX, int startY, int size, int margin, const NpcProtectionStatus& status);
		void RenderProtectionIconsTop(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses);
		void RenderProtectionIconsRight(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses);

		ProtectionRenderData BuildRenderData(const NpcProtectionStatus& status, unsigned char alpha);

		std::vector<oEIndexDamage> GetDamageIndexes();
		bool CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex);
		void BuildFightModeDamage(DamageMask& mask);
		void BuildNoFightModeDamage(DamageMask& mask);
		std::vector<NpcProtectionStatus> GetProtectionVisibleStatuses(oCNpc* npc);
		int GetProtectionStatusesVisibleCount(oCNpc* npc);

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