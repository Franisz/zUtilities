// Supported with union (c) 2018 Union team

#ifndef __ZVOB_IDENTIFIER_H__VER0__
#define __ZVOB_IDENTIFIER_H__VER0__

namespace Gothic_I_Classic {
  const unsigned long zVOB_ID_UNDEFINED = 0;

  class zCVobIdentifier {
  public:
    unsigned long id;

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVOB_IDENTIFIER_H__VER0__