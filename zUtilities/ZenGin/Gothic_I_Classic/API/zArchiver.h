// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER_H__VER0__
#define __ZARCHIVER_H__VER0__

namespace Gothic_I_Classic {

  enum zTArchiveMode {
    zARC_MODE_BINARY,
    zARC_MODE_ASCII,
    zARC_MODE_ASCII_PROPS,
    zARC_MODE_BINARY_SAFE,
    zARC_MODE_COUNT
  };

  enum zTArchiveFlags {
    zARC_FLAG_WRITE_BRIEF_HEADER = 1,
    zARC_FLAG_NO_SPY_MESSAGES    = 2
  };

  class zCArchiverFactory {
  public:

    zCArchiverFactory() {}
    int EndOfArchive( zCBuffer*, zFILE* )                                              zCall( 0x005097C0 );
    void ReadLine( zSTRING&, zCBuffer*, zFILE* )                                       zCall( 0x00509830 );
    void ReadLineArg( zSTRING&, zSTRING&, zCBuffer*, zFILE* )                          zCall( 0x00509A40 );
    void ReadHeader( int, zCBuffer*, zFILE*, zCArchiver*&, zTArchiveMode&, int& )      zCall( 0x00509CC0 );
    void WriteLine( zSTRING const&, zCBuffer*, zFILE* )                                zCall( 0x0050A420 );
    void WriteLine( char const* const, zCBuffer*, zFILE* )                             zCall( 0x0050A520 );
    void WriteHeader( zCArchiver*, zTArchiveMode, int, int, zCBuffer*, zFILE* )        zCall( 0x0050A620 );
    zCArchiver* CreateArchiverFromMode( zTArchiveMode )                                zCall( 0x0050ACC0 );
    virtual zCArchiver* CreateArchiverRead( zCBuffer*, int )                           zCall( 0x0050A1B0 );
    virtual zCArchiver* CreateArchiverRead( zFILE*, int )                              zCall( 0x0050A240 );
    virtual zCArchiver* CreateArchiverRead( zSTRING const&, int )                      zCall( 0x0050A2B0 );
    virtual zCArchiver* CreateArchiverWrite( zCBuffer*, zTArchiveMode, int, int )      zCall( 0x0050ADD0 );
    virtual zCArchiver* CreateArchiverWrite( zTArchiveMode, int, int )                 zCall( 0x0050AF60 );
    virtual zCArchiver* CreateArchiverWrite( zFILE*, zTArchiveMode, int, int )         zCall( 0x0050B000 );
    virtual zCArchiver* CreateArchiverWrite( zSTRING const&, zTArchiveMode, int, int ) zCall( 0x0050AF80 );

    // user API
    #include "zCArchiverFactory.inl"
  };

  class zCArchiver : public zCObject {
  public:
    zCLASS_DECLARATION( zCArchiver )

    enum zTArchiveMedium {
      zARC_MEDIUM_FILE,
      zARC_MEDIUM_BUFFER
    };

    enum zTAccessMode {
      zARC_CLOSED,
      zARC_READ,
      zARC_WRITE
    };

    struct zTChunkRecord {
      unsigned long startPos;
      unsigned long size;
      unsigned short version;
      unsigned long objectIndex;
      zSTRING name;
      zSTRING className;

      void zTChunkRecord_OnInit()                       zCall( 0x00510FA0 );
      ~zTChunkRecord()                                  zCall( 0x0050DF80 );
      zTChunkRecord& operator =( zTChunkRecord const& ) zCall( 0x0050F3A0 );
      zTChunkRecord()                                   zInit( zTChunkRecord_OnInit() );

      // user API
      #include "zCArchiver_zTChunkRecord.inl"
    };

    zTArchiveMedium medium;
    zTArchiveMode mode;

    zCArchiver() {}
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0050BED0 );
    virtual ~zCArchiver()                                                                              zCall( 0x0050BEE0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zPureCall;
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zPureCall;
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zPureCall;
    virtual void __fastcall WriteFloat( char const*, float )                                           zPureCall;
    virtual void __fastcall WriteBool( char const*, int )                                              zPureCall;
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zPureCall;
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zPureCall;
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zPureCall;
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zPureCall;
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zPureCall;
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zPureCall;
    virtual void __fastcall WriteObject( zCObject* )                                                   zPureCall;
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zPureCall;
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zPureCall;
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zPureCall;
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zPureCall;
    virtual void __fastcall WriteChunkEnd()                                                            zPureCall;
    virtual void __fastcall WriteGroupBegin( char const* )                                             zPureCall;
    virtual void __fastcall WriteGroupEnd( char const* )                                               zPureCall;
    virtual void __fastcall ReadInt( char const*, int& )                                               zPureCall;
    virtual int __fastcall ReadInt( char const* )                                                      zPureCall;
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zPureCall;
    virtual unsigned char __fastcall ReadByte( char const* )                                           zPureCall;
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zPureCall;
    virtual unsigned short __fastcall ReadWord( char const* )                                          zPureCall;
    virtual void __fastcall ReadFloat( char const*, float& )                                           zPureCall;
    virtual float __fastcall ReadFloat( char const* )                                                  zPureCall;
    virtual void __fastcall ReadBool( char const*, int& )                                              zPureCall;
    virtual int __fastcall ReadBool( char const* )                                                     zPureCall;
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zPureCall;
    virtual zSTRING __fastcall ReadString( char const* )                                               zPureCall;
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zPureCall;
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zPureCall;
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zPureCall;
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zPureCall;
    virtual void __fastcall ReadEnum( char const*, int& )                                              zPureCall;
    virtual int __fastcall ReadEnum( char const* )                                                     zPureCall;
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zPureCall;
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zPureCall;
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zPureCall;
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zPureCall;
    virtual zCObject* __fastcall ReadObjectAccount( char const*, int, zCObject* )                      zCall( 0x0050B050 );
    virtual zCObject* __fastcall ReadObjectAccount( char const*, int, char const*, zCObject* )         zCall( 0x0050B080 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zPureCall;
    virtual int __fastcall ReadChunkStart( char const* )                                               zPureCall;
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zPureCall;
    virtual void __fastcall SkipOpenChunk()                                                            zPureCall;
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zPureCall;
    virtual zFILE* GetFile() const                                                                     zPureCall;
    virtual void __fastcall GetBufferString( zSTRING& )                                                zPureCall;
    virtual zCBuffer* __fastcall GetBuffer()                                                           zPureCall;
    virtual int __fastcall EndOfArchive()                                                              zPureCall;
    virtual void Close()                                                                               zPureCall;
    virtual void SetStringEOL( zSTRING const& )                                                        zPureCall;
    virtual zSTRING GetStringEOL() const                                                               zPureCall;
    virtual int IsStringValid( char const* )                                                           zPureCall;
    virtual int GetChecksumEnabled() const                                                             zPureCall;
    virtual void SetChecksumEnabled( int )                                                             zPureCall;
    virtual void SetNoReadSearchCycles( int )                                                          zPureCall;
    virtual int InProperties() const                                                                   zPureCall;
    virtual int InSaveGame() const                                                                     zPureCall;
    virtual int InBinaryMode() const                                                                   zPureCall;
    virtual zCObject* __fastcall GetParentObject()                                                     zPureCall;
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zPureCall;
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zPureCall;
    virtual void __fastcall WriteHeader( int )                                                         zPureCall;
    virtual void __fastcall WriteHeaderNumObj()                                                        zPureCall;
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zPureCall;
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zPureCall;
    virtual void __fastcall StoreString( char const* )                                                 zPureCall;
    virtual void __fastcall StoreStringEOL( char const* )                                              zPureCall;
    virtual unsigned long __fastcall StoreGetPos()                                                     zPureCall;
    virtual void __fastcall StoreSeek( unsigned long )                                                 zPureCall;
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zPureCall;
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zPureCall;
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zPureCall;
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zPureCall;
    virtual void __fastcall SkipChunk( int )                                                           zPureCall;
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zPureCall;
    virtual void __fastcall ReadChunkEnd()                                                             zPureCall;
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zPureCall;
    virtual void __fastcall ReadHeader()                                                               zPureCall;
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zPureCall;
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zPureCall;
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zPureCall;
    virtual unsigned long __fastcall RestoreGetPos()                                                   zPureCall;
    virtual void __fastcall RestoreSeek( unsigned long )                                               zPureCall;
    virtual void __fastcall DeleteBuffer()                                                             zPureCall;

    // static properties
    static zSTRING& stringEOL;

    // user API
    #include "zCArchiver.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZARCHIVER_H__VER0__