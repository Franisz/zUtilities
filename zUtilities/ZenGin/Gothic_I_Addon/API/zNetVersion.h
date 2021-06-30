// Supported with union (c) 2018 Union team

#ifndef __ZNET_VERSION_H__VER1__
#define __ZNET_VERSION_H__VER1__

namespace Gothic_I_Addon {
  const short zNET_VERSION = 1;

  class zCNetVersion {
  public:
    long checksum;
    long version;

    void zCNetVersion_OnInit()               zCall( 0x0045F230 );
    zCNetVersion()                           zInit( zCNetVersion_OnInit() );
    virtual ~zCNetVersion()                  zCall( 0x0045F270 );
    virtual zSTRING GetVersionString() const zCall( 0x0045F2B0 );
    virtual long GetVersionNumber() const    zCall( 0x0045F280 );
    virtual long GetChecksum() const         zCall( 0x0045F290 );
    virtual long CreateChecksum()            zCall( 0x0045F2A0 );
    virtual void Pack( zCBuffer& ) const     zCall( 0x0045F2D0 );
    virtual void Unpack( zCBuffer& )         zCall( 0x0045F300 );

    // user API
    #include "zCNetVersion.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_VERSION_H__VER1__