// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_IDENTIFIER_H__VER3__
#define __ZVOB_IDENTIFIER_H__VER3__

namespace Gothic_II_Addon {
  const unsigned long zVOB_ID_UNDEFINED = 0;

  // sizeof 04h
  class zCVobIdentifier {
  public:
    unsigned long id; // sizeof 04h    offset 00h

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVOB_IDENTIFIER_H__VER3__