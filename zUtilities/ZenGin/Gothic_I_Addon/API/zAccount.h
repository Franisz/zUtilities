// Supported with union (c) 2018 Union team

#ifndef __ZACCOUNT_H__VER1__
#define __ZACCOUNT_H__VER1__

namespace Gothic_I_Addon {

  class zCAccount {
  public:

    zCAccount() {}
    static void Add( void const*, char const*, int, int ) zCall( 0x0079C080 );
    static void Sum( void const* )                        zCall( 0x0079C3F0 );
    static void Clear( void const* )                      zCall( 0x0079C830 );
    static void Begin()                                   zCall( 0x0079C860 );
    static void End()                                     zCall( 0x0079C870 );
    static int IsActive()                                 zCall( 0x0079C880 );

    // static properties
    static int& s_actCounter;

    // user API
    #include "zCAccount.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZACCOUNT_H__VER1__