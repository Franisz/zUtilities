// Supported with union (c) 2018-2021 Union team

#ifndef __ZARCHIVER2_H__VER3__
#define __ZARCHIVER2_H__VER3__

#include "zArchiver.h"

namespace Gothic_II_Addon {
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

    void zCArchiverBinSafe_OnInit()                                                                    zCall( 0x0051BED0 );
    void __fastcall RestoreString( zSTRING& )                                                          zCall( 0x0051B340 );
    void __fastcall WriteType( zTArchiveTypeID, void*, unsigned long )                                 zCall( 0x0051B350 );
    int __fastcall ReadType( zTArchiveTypeID, void*, unsigned long )                                   zCall( 0x0051B3C0 );
    void __fastcall ClearChunkList()                                                                   zCall( 0x0051BBF0 );
    unsigned long __fastcall InsertChunkInList( char const* )                                          zCall( 0x0051BD70 );
    unsigned long __fastcall ResolveAndPosEntry( char const* )                                         zCall( 0x0051BE00 );
    zCArchiverBinSafe()                                                                                zInit( zCArchiverBinSafe_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x0051C3C0 );
    void CheckObjectListSize( int )                                                                    zCall( 0x0051EEC0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0051B280 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0051C040 );
    virtual ~zCArchiverBinSafe()                                                                       zCall( 0x0051C2C0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x0051D020 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x0051D100 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x0051D1E0 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x0051D2C0 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x0051D3A0 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x0051D480 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x0051D5B0 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x0051D8E0 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x0051D9C0 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x0051DAA0 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x0051DCC0 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x0051E830 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x0051E7A0 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x0051E560 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x0051E300 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x0051DEE0 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x0051E320 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x0051DEC0 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x0051DED0 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00520C90 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x00520A50 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00520CC0 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x00520A70 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x00520CF0 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x00520A90 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x00520C30 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x005209F0 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x00520D20 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x00520AB0 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00520D50 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x00520AD0 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00520C60 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x00520A10 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00520D80 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x00520B90 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x00520DB0 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x00520BB0 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x00520BD0 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x00520C00 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x005201D0 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x0051FB50 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x0051F9D0 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x0051F430 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x0051FAF0 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x0051C050 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x0051FB20 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x0051C060 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x0051C920 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x0051CA90 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x0051C890 );
    virtual void Close()                                                                               zCall( 0x0051C440 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x0051C070 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x0051C1F0 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x0051CE00 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x0051C230 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x0051C240 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x0051C250 );
    virtual int InProperties() const                                                                   zCall( 0x0051C260 );
    virtual int InSaveGame() const                                                                     zCall( 0x0051C270 );
    virtual int InBinaryMode() const                                                                   zCall( 0x0051C280 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x00520DE0 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x0051CAA0 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x0051CC60 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x0051CD80 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x0051C3E0 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x0051CE40 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x0051CCC0 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x0051CCF0 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x0051CD70 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x0051CD20 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x0051CD40 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x0051E840 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x0051EA10 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x0051F030 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x0051EF60 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x005201E0 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x0051F1D0 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x0051FB40 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x005203B0 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x0051EB20 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x0051EA70 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x0051EAA0 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x0051EAB0 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x0051EAC0 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x0051EAE0 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x0051C900 );

    // user API
    #include "zCArchiverBinSafe.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZARCHIVER2_H__VER3__