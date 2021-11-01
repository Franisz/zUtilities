// Supported with union (c) 2018-2021 Union team

#ifndef __ZARCHIVER2_H__VER2__
#define __ZARCHIVER2_H__VER2__

namespace Gothic_II_Classic {
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

    void zCArchiverBinSafe_OnInit()                                                                    zCall( 0x00519100 );
    void __fastcall RestoreString( zSTRING& )                                                          zCall( 0x00518570 );
    void __fastcall WriteType( zTArchiveTypeID, void*, unsigned long )                                 zCall( 0x00518580 );
    int __fastcall ReadType( zTArchiveTypeID, void*, unsigned long )                                   zCall( 0x005185F0 );
    void __fastcall ClearChunkList()                                                                   zCall( 0x00518E20 );
    unsigned long __fastcall InsertChunkInList( char const* )                                          zCall( 0x00518FA0 );
    unsigned long __fastcall ResolveAndPosEntry( char const* )                                         zCall( 0x00519030 );
    zCArchiverBinSafe()                                                                                zInit( zCArchiverBinSafe_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x005195F0 );
    void CheckObjectListSize( int )                                                                    zCall( 0x0051C0F0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x005184B0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00519270 );
    virtual ~zCArchiverBinSafe()                                                                       zCall( 0x005194F0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x0051A250 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x0051A330 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x0051A410 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x0051A4F0 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x0051A5D0 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x0051A6B0 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x0051A7E0 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x0051AB10 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x0051ABF0 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x0051ACD0 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x0051AEF0 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x0051BA60 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x0051B9D0 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x0051B790 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x0051B530 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x0051B110 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x0051B550 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x0051B0F0 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x0051B100 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x0051DEC0 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x0051DC80 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x0051DEF0 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x0051DCA0 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x0051DF20 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x0051DCC0 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x0051DE60 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x0051DC20 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x0051DF50 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x0051DCE0 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x0051DF80 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x0051DD00 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x0051DE90 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x0051DC40 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x0051DFB0 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x0051DDC0 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x0051DFE0 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x0051DDE0 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x0051DE00 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x0051DE30 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x0051D400 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x0051CD80 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x0051CC00 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x0051C660 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x0051CD20 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x00519280 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x0051CD50 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x00519290 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x00519B50 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x00519CC0 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x00519AC0 );
    virtual void Close()                                                                               zCall( 0x00519670 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x005192A0 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x00519420 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x0051A030 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x00519460 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x00519470 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x00519480 );
    virtual int InProperties() const                                                                   zCall( 0x00519490 );
    virtual int InSaveGame() const                                                                     zCall( 0x005194A0 );
    virtual int InBinaryMode() const                                                                   zCall( 0x005194B0 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x0051E010 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x00519CD0 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x00519E90 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x00519FB0 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x00519610 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x0051A070 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x00519EF0 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x00519F20 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x00519FA0 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x00519F50 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x00519F70 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x0051BA70 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x0051BC40 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x0051C260 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x0051C190 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x0051D410 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x0051C400 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x0051CD70 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x0051D5E0 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x0051BD50 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x0051BCA0 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x0051BCD0 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x0051BCE0 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x0051BCF0 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x0051BD10 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x00519B30 );

    // user API
    #include "zCArchiverBinSafe.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZARCHIVER2_H__VER2__