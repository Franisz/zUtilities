// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER_GENERIC_H__VER3__
#define __ZARCHIVER_GENERIC_H__VER3__

#include "zArchiver.h"

namespace Gothic_II_Addon {

  class zCArchiverGeneric : public zCArchiver {
  public:
    zCLASS_DECLARATION( zCArchiverGeneric )

    struct zTWriteObjectEntry {
      zCObject* object;
      int objectIndex;

      zTWriteObjectEntry() {}

      // user API
      #include "zCArchiverGeneric_zTWriteObjectEntry.inl"
    };

    zFILE* file;
    zCBuffer* cbuffer;
    int owningMedium;
    int inSaveGame;
    int binaryMode;
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
    zCSparseArray<zCObject*, zTWriteObjectEntry> writeObjectList;
    int warnEntrysNotRead;
    int warnEntryNotFound;
    int warnWrongEntryOrder;

    void zCArchiverGeneric_OnInit()                                                                    zCall( 0x00521E30 );
    zCArchiverGeneric()                                                                                zInit( zCArchiverGeneric_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x005222F0 );
    void CheckObjectListSize( int )                                                                    zCall( 0x00525A50 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00521CC0 );
    static void TestClassIntegrity( void( __cdecl* )( zCObject*, int, zCClassDef*, int& ))             zCall( 0x00527DE0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00521F50 );
    virtual ~zCArchiverGeneric()                                                                       zCall( 0x005221E0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x00522E30 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x00522FD0 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x00523170 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x00523310 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x005234D0 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x00523670 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x005236D0 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x00523A10 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x00523D80 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x00523F50 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x00524220 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x00524EC0 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x00524E20 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x00524C10 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x00524950 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x00524490 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x00524970 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x00524ED0 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x00524FB0 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00527B80 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x005274C0 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00527BD0 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x005274E0 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x00527C20 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x00527500 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x00527AD0 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x00527460 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x00527C70 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x00527520 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00527CD0 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x00527540 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00527B20 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x00527480 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00527D00 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x00527600 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x00527D90 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x00527620 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x00527640 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x005278D0 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x00526DF0 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x00526560 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x005263E0 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x00525FB0 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x00526500 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x00521F60 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x00526530 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x00521F70 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x005226E0 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x00522850 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x00522650 );
    virtual void Close()                                                                               zCall( 0x00522470 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x00521F80 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x00522100 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x00522C00 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x00522140 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x00522150 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x00522160 );
    virtual int InProperties() const                                                                   zCall( 0x00522170 );
    virtual int InSaveGame() const                                                                     zCall( 0x00522180 );
    virtual int InBinaryMode() const                                                                   zCall( 0x00522190 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x00528800 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x00522860 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x00522A30 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x00522B90 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x00522310 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x00522C40 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x00522AA0 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x00522AD0 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x00522B60 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x00522B10 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x00522B30 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x00525090 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x00525260 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x00525BC0 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x00525AF0 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x00526E00 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x00525D60 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x00526550 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x00527000 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x00525750 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x005252D0 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x00525300 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x005256E0 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x005256F0 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x00525710 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x005226C0 );

    // user API
    #include "zCArchiverGeneric.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZARCHIVER_GENERIC_H__VER3__