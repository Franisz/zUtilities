// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int RemoveBodies;

    void RemoveEmptyBodies() {
      RemoveBodies = zoptions->ReadInt( PLUGIN_NAME, "RemoveEmptyBodies", 0);
    }
  }
}