// Supported with union (c) 2018 Union team

#ifndef __ZMEMORY__GENERIC_H__VER0__
#define __ZMEMORY__GENERIC_H__VER0__

namespace Gothic_I_Classic {

  class zCMallocGeneric : public zCMalloc {
  public:

    void zCMallocGeneric_OnInit()                                       zCall( 0x0054EB70 );
    zCMallocGeneric()                                                   zInit( zCMallocGeneric_OnInit() );
    virtual ~zCMallocGeneric()                                          zCall( 0x0054EAF0 );
    virtual void* Malloc( unsigned int )                                zCall( 0x0054EC20 );
    virtual void* Malloc( unsigned int, char const*, char const*, int ) zCall( 0x0054EC30 );
    virtual void* Realloc( void*, unsigned int )                        zCall( 0x0054EC40 );
    virtual void Free( void* )                                          zCall( 0x0054EC60 );
    virtual int GetStats( zTMallocStats& )                              zCall( 0x0054EC70 );
    virtual int Init( int )                                             zCall( 0x0054EC90 );
    virtual int Shutdown()                                              zCall( 0x0054ECA0 );

    // user API
    #include "zCMallocGeneric.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMEMORY__GENERIC_H__VER0__