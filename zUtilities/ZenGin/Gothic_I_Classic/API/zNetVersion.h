// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_VERSION_H__VER0__
#define __ZNET_VERSION_H__VER0__

namespace Gothic_I_Classic {
  const short zNET_VERSION = 1;

  // sizeof 0Ch
  class zCNetVersion {
  public:
    long checksum; // sizeof 04h    offset 04h
    long version;  // sizeof 04h    offset 08h

    void zCNetVersion_OnInit()               zCall( 0x00458170 );
    zCNetVersion()                           zInit( zCNetVersion_OnInit() );
    virtual ~zCNetVersion()                  zCall( 0x004581B0 );
    virtual zSTRING GetVersionString() const zCall( 0x004581F0 );
    virtual long GetVersionNumber() const    zCall( 0x004581C0 );
    virtual long GetChecksum() const         zCall( 0x004581D0 );
    virtual long CreateChecksum()            zCall( 0x004581E0 );
    virtual void Pack( zCBuffer& ) const     zCall( 0x00458210 );
    virtual void Unpack( zCBuffer& )         zCall( 0x00458240 );

    // user API
    #include "zCNetVersion.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_VERSION_H__VER0__