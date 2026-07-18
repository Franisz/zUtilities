// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool NoGrass;
    bool NoGrassDebugShowHidden;
    bool NoGrassRemoveVobsWithDynamicCollisions;
    std::vector<string> NoGrassVisualNames;
  } // namespace Options

  class NoGrass {
  private:
    std::vector<string> visualsNames;
    std::vector<string> visualsHidden;
    bool IsValidVob( zCVob* vob );

  public:
    void ShowVisualsNames();
    void RestoreVisibility();
    void UpdateVisualsList();
    void UpdateVisuals();
    void Update();
  };

  NoGrass noGrass;
} // namespace GOTHIC_ENGINE
