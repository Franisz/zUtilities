// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_IDENTIFIER_H__VER0__
#define __ZVOB_IDENTIFIER_H__VER0__

namespace Gothic_I_Classic {
  const unsigned long zVOB_ID_UNDEFINED = 0;

  // sizeof 04h
  class zCVobIdentifier {
  public:
    unsigned long id; // sizeof 04h    offset 00h

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVOB_IDENTIFIER_H__VER0__