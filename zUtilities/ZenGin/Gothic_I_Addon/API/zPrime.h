// Supported with union (c) 2018 Union team

#ifndef __ZPRIME_H__VER1__
#define __ZPRIME_H__VER1__

namespace Gothic_I_Addon {

  class zCPrime {
  public:

    zCPrime() {}
    static int IsPrime( unsigned long )             zCall( 0x005BA2E0 );
    static unsigned short PrimeNo( unsigned short ) zCall( 0x005BA3C0 );
    static unsigned long NextPrime( unsigned long ) zCall( 0x005BA4B0 );

    // user API
    #include "zCPrime.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPRIME_H__VER1__