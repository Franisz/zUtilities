// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
	class SwimStatusBar : public StatusBar {

	protected:
		virtual bool Init() override;
		virtual zSTRING GetBarValue() override;

	public:
		SwimStatusBar();
	};
}