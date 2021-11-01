// Supported with union (c) 2018-2021 Union team

#ifndef __ZACCOUNT_H__VER0__
#define __ZACCOUNT_H__VER0__

namespace Gothic_I_Classic {

  class zCAccount {
  public:

    zCAccount() {}
    static void Add( void const*, char const*, int, int ) zCall( 0x00759A90 );
    static void Sum( void const* )                        zCall( 0x00759DE0 );
    static void Clear( void const* )                      zCall( 0x0075A1F0 );
    static void Begin()                                   zCall( 0x0075A220 );
    static void End()                                     zCall( 0x0075A230 );
    static int IsActive()                                 zCall( 0x0075A240 );

    // static properties
    static int& s_actCounter;

    // user API
    #include "zCAccount.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZACCOUNT_H__VER0__