// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool RemoveBodies;

    void RemoveEmptyBodies() {
      RemoveBodies = zoptions->ReadBool( PLUGIN_NAME, "RemoveEmptyBodies", false);
    }
  }
}