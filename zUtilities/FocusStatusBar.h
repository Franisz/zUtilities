// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
    class FocusStatusBar : public StatusBar {
    private:
        zCView* protView;
        void MoveFocusBar(int x, int y, oCNpc* npc);
        void TryShowProt(oCNpc* npc);
        int RenderProtectionIcon(oCNpc* npc, oEIndexDamage damageIndex, int offset);

    protected:
        virtual bool ShouldReverseValuePos() override;

    public:
        FocusStatusBar();
        bool NeedAdjustPosition(int x, int y, oCNpc* npc);
        virtual void Loop() override;
        virtual bool Init() override;
        virtual void Clear() override;
    };
}