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

	struct ProtectionIconRenderData {
		zSTRING text;
		zSTRING texture;
		zCOLOR color;
	};

	enum class ProtectionRenderMode {
		Disabled,
		Immortal,
		Normal
	};

	struct ProtectionModel {
		ProtectionRenderMode renderMode = ProtectionRenderMode::Disabled;
		bool isInFightMode = false;
		TargetProtectionMode targetProtectionMode = TargetProtectionMode::Disabled;
	};

	struct ProtectionLayout {
		FocusStatusProtectionPlacement placement = FocusStatusProtectionPlacement::NONE;
		int startX = 0;
		int startY = 0;
		int size = 0;
		int margin = 0;
		int fontY = 0;
		int totalContentSize = 0;
	};

	class FocusStatusBar : public StatusBar {
	private:
		zSTRING IMMUNE_ABBREVIATION = "IMM";
		const zSTRING crackedShieldTexture = zSTRING("ICON_PROTECTIONS"); // https://game-icons.net/1x1/lorc/cracked-shield.html		
		const int protectionPlacementRightMargin = 250;
		std::vector<oEIndexDamage> activeDamageIndexes;
		std::vector<NpcProtectionStatus> activeStatuses;
		zCView* protView;
		void MoveFocusBar(int x, int y, oCNpc* npc);
		int GetHorizontalProtMargin(int fontY);
		int GetVerticalProtMargin(int fontY);
		FocusStatusProtectionPlacement GetProtPlacement(const std::vector<NpcProtectionStatus>& statuses);
		const zSTRING& GetIconNameByDamageIndex(const oEIndexDamage& index);
		virtual void PrintValueOutside(zSTRING& str) override;
		void RenderProtectionIconsClose(const ProtectionLayout& layout);
		void RenderProtectionIconsTop(const ProtectionLayout& layout);
		void RenderProtectionIconsRight(const ProtectionLayout& layout);

		int valueOffsetY = 0;
		zSTRING iconCache[oEDamageIndex_MAX + 1];
		ProtectionModel protectionModel = {};
		bool BuildProtectionModel(oCNpc* npc);
		void BuildProtectionLayout(ProtectionLayout& layout);
		void RenderProtectionWithLayout(const ProtectionLayout& layout);

		ProtectionIconRenderData BuildIconRenderData(const NpcProtectionStatus& status, unsigned char alpha);

		void FillDamageIndexesBuffer();
		bool CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex) const;
		void BuildFightModeDamage(DamageMask& mask);
		void BuildNoFightModeDamage(DamageMask& mask);

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