// Supported with union (c) 2018 Union team

#ifndef __ZVOB_IDENTIFIER_H__VER2__
#define __ZVOB_IDENTIFIER_H__VER2__

namespace Gothic_II_Classic {
  const unsigned long zVOB_ID_UNDEFINED = 0;

  class zCVobIdentifier {
  public:
    unsigned long id;

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVOB_IDENTIFIER_H__VER2__