// Supported with union (c) 2018-2021 Union team

#ifndef __ZMEMORY__GENERIC_H__VER1__
#define __ZMEMORY__GENERIC_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 04h
  class zCMallocGeneric : public zCMalloc {
  public:

    void zCMallocGeneric_OnInit()                                       zCall( 0x00567070 );
    zCMallocGeneric()                                                   zInit( zCMallocGeneric_OnInit() );
    virtual ~zCMallocGeneric()                                          zCall( 0x00566FF0 );
    virtual void* Malloc( unsigned int )                                zCall( 0x00567120 );
    virtual void* Malloc( unsigned int, char const*, char const*, int ) zCall( 0x00567130 );
    virtual void* Realloc( void*, unsigned int )                        zCall( 0x00567140 );
    virtual void Free( void* )                                          zCall( 0x00567160 );
    virtual int GetStats( zTMallocStats& )                              zCall( 0x00567170 );
    virtual int Init( int )                                             zCall( 0x00567190 );
    virtual int Shutdown()                                              zCall( 0x005671A0 );

    // user API
    #include "zCMallocGeneric.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMEMORY__GENERIC_H__VER1__