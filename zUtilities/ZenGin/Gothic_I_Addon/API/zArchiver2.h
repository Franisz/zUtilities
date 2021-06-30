// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER2_H__VER1__
#define __ZARCHIVER2_H__VER1__

namespace Gothic_I_Addon {
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

  class zCArchiverBinSafe : public zCArchiver {
  public:
    zCLASS_DECLARATION( zCArchiverBinSafe )

    zFILE* file;
    zCBuffer* cbuffer;
    int owningMedium;
    int inSaveGame;
    zTAccessMode accessMode;
    zCArray<zTChunkRecord> chunkStack;
    zCArray<zCObject*> objectList;
    unsigned long posNumObjects;
    unsigned long posChecksum;
    unsigned long posHeaderEnd;
    int checksumEnabled;
    int flags;
    int debugMessagesOn;
    int noReadSearchCycles;
    zSTRING tmpResultValue;
    int deleteFileOnClose;
    int warnEntrysNotRead;
    int warnEntryNotFound;
    int warnWrongEntryOrder;
    void* stringHashMap;
    unsigned long dummyVal;
    unsigned long posChunkList;
    char m_readTextBuffer[READ_BUFFER_SIZE];

    void zCArchiverBinSafe_OnInit()                                                                    zCall( 0x00520B00 );
    void __fastcall RestoreString( zSTRING& )                                                          zCall( 0x00520170 );
    void __fastcall WriteType( zTArchiveTypeID, void*, unsigned long )                                 zCall( 0x00520180 );
    int __fastcall ReadType( zTArchiveTypeID, void*, unsigned long )                                   zCall( 0x005201F0 );
    void __fastcall ClearChunkList()                                                                   zCall( 0x00520820 );
    unsigned long __fastcall InsertChunkInList( char const* )                                          zCall( 0x00520980 );
    unsigned long __fastcall ResolveAndPosEntry( char const* )                                         zCall( 0x00520A10 );
    zCArchiverBinSafe()                                                                                zInit( zCArchiverBinSafe_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x00521020 );
    void CheckObjectListSize( int )                                                                    zCall( 0x00523B30 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x005200A0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00520C80 );
    virtual ~zCArchiverBinSafe()                                                                       zCall( 0x00520F10 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x00521CC0 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x00521DB0 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x00521EA0 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x00521F90 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x00522080 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x00522170 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x005222B0 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x00522550 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x00522640 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x00522730 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x00522930 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x005234F0 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x00523460 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x00523250 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x00522FB0 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x00522B60 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x00522FD0 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x00522B40 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x00522B50 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00525AB0 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x00525850 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00525AE0 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x00525870 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x00525B10 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x00525890 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x00525A50 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x005257F0 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x00525B40 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x005258B0 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00525B70 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x005258D0 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00525A80 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x00525810 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00525BA0 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x005259B0 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x00525BD0 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x005259D0 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x005259F0 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x00525A20 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x00524F30 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x00524900 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x00524760 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x00524160 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x005248A0 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x00520C90 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x005248D0 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x00520CA0 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x00521560 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x005216E0 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x005214D0 );
    virtual void Close()                                                                               zCall( 0x005210A0 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x00520CB0 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x00520E30 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x00521A70 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x00520E80 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x00520E90 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x00520EA0 );
    virtual int InProperties() const                                                                   zCall( 0x00520EB0 );
    virtual int InSaveGame() const                                                                     zCall( 0x00520EC0 );
    virtual int InBinaryMode() const                                                                   zCall( 0x00520ED0 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x00525C00 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x005216F0 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x005218D0 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x005219F0 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x00521040 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x00521AB0 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x00521930 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x00521960 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x005219E0 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x00521990 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x005219B0 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x00523500 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x00523700 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x00523CC0 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x00523BE0 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x00524F40 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x00523E90 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x005248F0 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x00525150 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x00523810 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x00523760 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x00523790 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x005237A0 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x005237B0 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x005237D0 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x00521540 );

    // user API
    #include "zCArchiverBinSafe.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZARCHIVER2_H__VER1__