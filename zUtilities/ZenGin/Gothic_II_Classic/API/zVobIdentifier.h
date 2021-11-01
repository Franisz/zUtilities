// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_IDENTIFIER_H__VER2__
#define __ZVOB_IDENTIFIER_H__VER2__

namespace Gothic_II_Classic {
  const unsigned long zVOB_ID_UNDEFINED = 0;

  // sizeof 04h
  class zCVobIdentifier {
  public:
    unsigned long id; // sizeof 04h    offset 00h

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVOB_IDENTIFIER_H__VER2__