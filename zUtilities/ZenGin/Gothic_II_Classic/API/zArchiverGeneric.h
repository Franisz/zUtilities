// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER_GENERIC_H__VER2__
#define __ZARCHIVER_GENERIC_H__VER2__

namespace Gothic_II_Classic {

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

    void zCArchiverGeneric_OnInit()                                                                    zCall( 0x0051F060 );
    zCArchiverGeneric()                                                                                zInit( zCArchiverGeneric_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x0051F520 );
    void CheckObjectListSize( int )                                                                    zCall( 0x00522C80 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0051EEF0 );
    static void TestClassIntegrity( void( __cdecl* )( zCObject*, int, zCClassDef*, int& ))             zCall( 0x00525010 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0051F180 );
    virtual ~zCArchiverGeneric()                                                                       zCall( 0x0051F410 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x00520060 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x00520200 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x005203A0 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x00520540 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x00520700 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x005208A0 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x00520900 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x00520C40 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x00520FB0 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x00521180 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x00521450 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x005220F0 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x00522050 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x00521E40 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x00521B80 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x005216C0 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x00521BA0 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x00522100 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x005221E0 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x00524DB0 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x005246F0 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x00524E00 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x00524710 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x00524E50 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x00524730 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x00524D00 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x00524690 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x00524EA0 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x00524750 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x00524F00 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x00524770 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x00524D50 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x005246B0 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x00524F30 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x00524830 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x00524FC0 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x00524850 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x00524870 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x00524B00 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x00524020 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x00523790 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x00523610 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x005231E0 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x00523730 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x0051F190 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x00523760 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x0051F1A0 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x0051F910 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x0051FA80 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x0051F880 );
    virtual void Close()                                                                               zCall( 0x0051F6A0 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x0051F1B0 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x0051F330 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x0051FE30 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x0051F370 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x0051F380 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x0051F390 );
    virtual int InProperties() const                                                                   zCall( 0x0051F3A0 );
    virtual int InSaveGame() const                                                                     zCall( 0x0051F3B0 );
    virtual int InBinaryMode() const                                                                   zCall( 0x0051F3C0 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x00525A30 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x0051FA90 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x0051FC60 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x0051FDC0 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x0051F540 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x0051FE70 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x0051FCD0 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x0051FD00 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x0051FD90 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x0051FD40 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x0051FD60 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x005222C0 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x00522490 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x00522DF0 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x00522D20 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x00524030 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x00522F90 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x00523780 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x00524230 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x00522980 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x00522500 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x00522530 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x00522910 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x00522920 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x00522940 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x0051F8F0 );

    // user API
    #include "zCArchiverGeneric.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZARCHIVER_GENERIC_H__VER2__