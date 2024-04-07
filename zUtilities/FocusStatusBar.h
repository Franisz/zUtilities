// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
    class FocusStatusBar : public StatusBar {
    private:
        void MoveFocusBar(int x, int y, oCNpc* npc);

    protected:
        virtual bool ShouldReverseValuePos() override;

    public:
        FocusStatusBar();
        bool NeedAdjustPosition(int x, int y, oCNpc* npc);
        virtual void Loop() override;
        virtual bool Init() override;
    };
}