// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER_GENERIC_H__VER0__
#define __ZARCHIVER_GENERIC_H__VER0__

namespace Gothic_I_Classic {

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

    void zCArchiverGeneric_OnInit()                                                                    zCall( 0x00511AB0 );
    zCArchiverGeneric()                                                                                zInit( zCArchiverGeneric_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x00511F70 );
    void CheckObjectListSize( int )                                                                    zCall( 0x00514EA0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00511930 );
    static void TestClassIntegrity( void( __cdecl* )( zCObject*, int, zCClassDef*, int& ))             zCall( 0x00517140 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00511BD0 );
    virtual ~zCArchiverGeneric()                                                                       zCall( 0x00511E60 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x005129E0 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x00512AA0 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x00512B70 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x00512C40 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x00512D10 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x00512DE0 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x00512E40 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x00513080 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x00513330 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x00513500 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x00513790 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x00514310 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x00514270 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x00514060 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x00513DA0 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x00513940 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x00513DC0 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x00514320 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x00514400 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00516EE0 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x00516880 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00516F30 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x005168A0 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x00516F80 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x005168C0 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x00516E30 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x00516820 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x00516FD0 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x005168E0 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00517030 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x00516900 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00516E80 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x00516840 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00517060 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x005169C0 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x005170F0 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x005169E0 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x00516A00 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x00516C30 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x005161B0 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x005159C0 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x00515840 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x00515410 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x00515960 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x00511BE0 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x00515990 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x00511BF0 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x00512290 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x00512400 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x00512200 );
    virtual void Close()                                                                               zCall( 0x00512080 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x00511C00 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x00511D80 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x005127B0 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x00511DC0 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x00511DD0 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x00511DE0 );
    virtual int InProperties() const                                                                   zCall( 0x00511DF0 );
    virtual int InSaveGame() const                                                                     zCall( 0x00511E00 );
    virtual int InBinaryMode() const                                                                   zCall( 0x00511E10 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x005179E0 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x00512410 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x005125E0 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x00512740 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x00511F90 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x005127F0 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x00512650 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x00512680 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x00512710 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x005126C0 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x005126E0 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x005144E0 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x005146B0 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x00515020 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x00514F50 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x005161C0 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x005151C0 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x005159B0 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x005163C0 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x00514BA0 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x00514720 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x00514750 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x00514B30 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x00514B40 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x00514B60 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x00512270 );

    // user API
    #include "zCArchiverGeneric.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZARCHIVER_GENERIC_H__VER0__