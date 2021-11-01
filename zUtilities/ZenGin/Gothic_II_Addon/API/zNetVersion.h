// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_VERSION_H__VER3__
#define __ZNET_VERSION_H__VER3__

namespace Gothic_II_Addon {
  const short zNET_VERSION = 1;

  // sizeof 0Ch
  class zCNetVersion {
  public:
    long checksum; // sizeof 04h    offset 04h
    long version;  // sizeof 04h    offset 08h

    void zCNetVersion_OnInit()               zCall( 0x0045D290 );
    zCNetVersion()                           zInit( zCNetVersion_OnInit() );
    virtual ~zCNetVersion()                  zCall( 0x0045D2D0 );
    virtual zSTRING GetVersionString() const zCall( 0x0045D310 );
    virtual long GetVersionNumber() const    zCall( 0x0045D2E0 );
    virtual long GetChecksum() const         zCall( 0x0045D2F0 );
    virtual long CreateChecksum()            zCall( 0x0045D300 );
    virtual void Pack( zCBuffer& ) const     zCall( 0x0045D410 );
    virtual void Unpack( zCBuffer& )         zCall( 0x0045D440 );

    // user API
    #include "zCNetVersion.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_VERSION_H__VER3__