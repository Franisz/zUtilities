// Supported with union (c) 2018-2021 Union team

#ifndef __ZARCHIVER2_H__VER0__
#define __ZARCHIVER2_H__VER0__

namespace Gothic_I_Classic {
  const int READ_BUFFER_SIZE = 1024*8;

  enum zTArchiveTypeID {
    zARC2_ID_STRING = 1,
    zARC2_ID_INTEGER,
    zARC2_ID_FLOAT,
    zARC2_ID_HASH = 18,
    zARC2_ID_BYTE = 4,
    zARC2_ID_WORD,
    zARC2_ID_int,
    zARC2_ID_VEC3,
    zARC2_ID_COLOR,
    zARC2_ID_RAW,
    zARC2_ID_RAWFLOAT = 16,
    zARC2_ID_ENUM
  };

  // sizeof 20A4h
  class zCArchiverBinSafe : public zCArchiver {
  public:
    zCLASS_DECLARATION( zCArchiverBinSafe )

    zFILE* file;                             // sizeof 04h    offset 2Ch
    zCBuffer* cbuffer;                       // sizeof 04h    offset 30h
    int owningMedium;                        // sizeof 04h    offset 34h
    int inSaveGame;                          // sizeof 04h    offset 38h
    zTAccessMode accessMode;                 // sizeof 04h    offset 3Ch
    zCArray<zTChunkRecord> chunkStack;       // sizeof 0Ch    offset 40h
    zCArray<zCObject*> objectList;           // sizeof 0Ch    offset 4Ch
    unsigned long posNumObjects;             // sizeof 04h    offset 58h
    unsigned long posChecksum;               // sizeof 04h    offset 5Ch
    unsigned long posHeaderEnd;              // sizeof 04h    offset 60h
    int checksumEnabled;                     // sizeof 04h    offset 64h
    int flags;                               // sizeof 04h    offset 68h
    int debugMessagesOn;                     // sizeof 04h    offset 6Ch
    int noReadSearchCycles;                  // sizeof 04h    offset 70h
    zSTRING tmpResultValue;                  // sizeof 14h    offset 74h
    int deleteFileOnClose;                   // sizeof 04h    offset 88h
    int warnEntrysNotRead;                   // sizeof 04h    offset 8Ch
    int warnEntryNotFound;                   // sizeof 04h    offset 90h
    int warnWrongEntryOrder;                 // sizeof 04h    offset 94h
    void* stringHashMap;                     // sizeof 04h    offset 98h
    unsigned long dummyVal;                  // sizeof 04h    offset 9Ch
    unsigned long posChunkList;              // sizeof 04h    offset A0h
    char m_readTextBuffer[READ_BUFFER_SIZE]; // sizeof 2000h  offset A4h

    void zCArchiverBinSafe_OnInit()                                                                    zCall( 0x0050BDA0 );
    void __fastcall RestoreString( zSTRING& )                                                          zCall( 0x0050B3B0 );
    void __fastcall WriteType( zTArchiveTypeID, void*, unsigned long )                                 zCall( 0x0050B3C0 );
    int __fastcall ReadType( zTArchiveTypeID, void*, unsigned long )                                   zCall( 0x0050B430 );
    void __fastcall ClearChunkList()                                                                   zCall( 0x0050BAC0 );
    unsigned long __fastcall InsertChunkInList( char const* )                                          zCall( 0x0050BC40 );
    unsigned long __fastcall ResolveAndPosEntry( char const* )                                         zCall( 0x0050BCD0 );
    zCArchiverBinSafe()                                                                                zInit( zCArchiverBinSafe_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x0050C2A0 );
    void CheckObjectListSize( int )                                                                    zCall( 0x0050EAE0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0050B2E0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0050BF20 );
    virtual ~zCArchiverBinSafe()                                                                       zCall( 0x0050C1A0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x0050CEB0 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x0050CF90 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x0050D070 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x0050D150 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x0050D230 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x0050D310 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x0050D440 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x0050D680 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x0050D760 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x0050D840 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x0050DA10 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x0050E4E0 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x0050E450 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x0050E260 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x0050E000 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x0050DC30 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x0050E020 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x0050DC10 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x0050DC20 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00510850 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x00510610 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00510880 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x00510630 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x005108B0 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x00510650 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x005107F0 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x005105B0 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x005108E0 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x00510670 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00510910 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x00510690 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00510820 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x005105D0 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00510940 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x00510750 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x00510970 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x00510770 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x00510790 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x005107C0 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x0050FDD0 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x0050F780 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x0050F600 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x0050F060 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x0050F720 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x0050BF30 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x0050F750 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x0050BF40 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x0050C7B0 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x0050C920 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x0050C720 );
    virtual void Close()                                                                               zCall( 0x0050C320 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x0050BF50 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x0050C0D0 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x0050CC90 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x0050C110 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x0050C120 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x0050C130 );
    virtual int InProperties() const                                                                   zCall( 0x0050C140 );
    virtual int InSaveGame() const                                                                     zCall( 0x0050C150 );
    virtual int InBinaryMode() const                                                                   zCall( 0x0050C160 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x005109A0 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x0050C930 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x0050CAF0 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x0050CC10 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x0050C2C0 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x0050CCD0 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x0050CB50 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x0050CB80 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x0050CC00 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x0050CBB0 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x0050CBD0 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x0050E4F0 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x0050E6C0 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x0050EC60 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x0050EB90 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x0050FDE0 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x0050EE00 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x0050F770 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x0050FFB0 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x0050E7D0 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x0050E720 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x0050E750 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x0050E760 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x0050E770 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x0050E790 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x0050C790 );

    // user API
    #include "zCArchiverBinSafe.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZARCHIVER2_H__VER0__