// Supported with union (c) 2018 Union team

#ifndef __ZARCHIVER_GENERIC_H__VER1__
#define __ZARCHIVER_GENERIC_H__VER1__

namespace Gothic_I_Addon {

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

    void zCArchiverGeneric_OnInit()                                                                    zCall( 0x00526DD0 );
    zCArchiverGeneric()                                                                                zInit( zCArchiverGeneric_OnInit() );
    void DebugMessage( zSTRING const& )                                                                zCall( 0x005272C0 );
    void CheckObjectListSize( int )                                                                    zCall( 0x0052A5E0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00526C50 );
    static void TestClassIntegrity( void( __cdecl* )( zCObject*, int, zCClassDef*, int& ))             zCall( 0x0052CB60 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00526F00 );
    virtual ~zCArchiverGeneric()                                                                       zCall( 0x005271A0 );
    virtual void __fastcall WriteInt( char const*, int )                                               zCall( 0x00527DC0 );
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zCall( 0x00527E90 );
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zCall( 0x00527F60 );
    virtual void __fastcall WriteFloat( char const*, float )                                           zCall( 0x00528030 );
    virtual void __fastcall WriteBool( char const*, int )                                              zCall( 0x00528100 );
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zCall( 0x005281D0 );
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zCall( 0x00528230 );
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zCall( 0x005284C0 );
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zCall( 0x005287E0 );
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zCall( 0x005289B0 );
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zCall( 0x00528C90 );
    virtual void __fastcall WriteObject( zCObject* )                                                   zCall( 0x00529920 );
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zCall( 0x00529880 );
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zCall( 0x00529650 );
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zCall( 0x00529350 );
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zCall( 0x00528E50 );
    virtual void __fastcall WriteChunkEnd()                                                            zCall( 0x00529370 );
    virtual void __fastcall WriteGroupBegin( char const* )                                             zCall( 0x00529930 );
    virtual void __fastcall WriteGroupEnd( char const* )                                               zCall( 0x00529A10 );
    virtual void __fastcall ReadInt( char const*, int& )                                               zCall( 0x0052C8F0 );
    virtual int __fastcall ReadInt( char const* )                                                      zCall( 0x0052C1F0 );
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zCall( 0x0052C940 );
    virtual unsigned char __fastcall ReadByte( char const* )                                           zCall( 0x0052C210 );
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zCall( 0x0052C990 );
    virtual unsigned short __fastcall ReadWord( char const* )                                          zCall( 0x0052C230 );
    virtual void __fastcall ReadFloat( char const*, float& )                                           zCall( 0x0052C840 );
    virtual float __fastcall ReadFloat( char const* )                                                  zCall( 0x0052C190 );
    virtual void __fastcall ReadBool( char const*, int& )                                              zCall( 0x0052C9E0 );
    virtual int __fastcall ReadBool( char const* )                                                     zCall( 0x0052C250 );
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zCall( 0x0052CA50 );
    virtual zSTRING __fastcall ReadString( char const* )                                               zCall( 0x0052C270 );
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zCall( 0x0052C890 );
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zCall( 0x0052C1B0 );
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zCall( 0x0052CA80 );
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zCall( 0x0052C350 );
    virtual void __fastcall ReadEnum( char const*, int& )                                              zCall( 0x0052CB10 );
    virtual int __fastcall ReadEnum( char const* )                                                     zCall( 0x0052C370 );
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zCall( 0x0052C390 );
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zCall( 0x0052C610 );
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zCall( 0x0052BA50 );
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zCall( 0x0052B240 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zCall( 0x0052B0A0 );
    virtual int __fastcall ReadChunkStart( char const* )                                               zCall( 0x0052ABF0 );
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zCall( 0x0052B1E0 );
    virtual void __fastcall SkipOpenChunk()                                                            zCall( 0x00526F10 );
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zCall( 0x0052B210 );
    virtual zFILE* GetFile() const                                                                     zCall( 0x00526F20 );
    virtual void __fastcall GetBufferString( zSTRING& )                                                zCall( 0x00527600 );
    virtual zCBuffer* __fastcall GetBuffer()                                                           zCall( 0x00527780 );
    virtual int __fastcall EndOfArchive()                                                              zCall( 0x00527570 );
    virtual void Close()                                                                               zCall( 0x005273D0 );
    virtual void SetStringEOL( zSTRING const& )                                                        zCall( 0x00526F30 );
    virtual zSTRING GetStringEOL() const                                                               zCall( 0x005270B0 );
    virtual int IsStringValid( char const* )                                                           zCall( 0x00527B50 );
    virtual int GetChecksumEnabled() const                                                             zCall( 0x00527100 );
    virtual void SetChecksumEnabled( int )                                                             zCall( 0x00527110 );
    virtual void SetNoReadSearchCycles( int )                                                          zCall( 0x00527120 );
    virtual int InProperties() const                                                                   zCall( 0x00527130 );
    virtual int InSaveGame() const                                                                     zCall( 0x00527140 );
    virtual int InBinaryMode() const                                                                   zCall( 0x00527150 );
    virtual zCObject* __fastcall GetParentObject()                                                     zCall( 0x0052D3E0 );
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zCall( 0x00527790 );
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zCall( 0x00527980 );
    virtual void __fastcall WriteHeader( int )                                                         zCall( 0x00527AE0 );
    virtual void __fastcall WriteHeaderNumObj()                                                        zCall( 0x005272E0 );
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zCall( 0x00527B90 );
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zCall( 0x005279F0 );
    virtual void __fastcall StoreString( char const* )                                                 zCall( 0x00527A20 );
    virtual void __fastcall StoreStringEOL( char const* )                                              zCall( 0x00527AB0 );
    virtual unsigned long __fastcall StoreGetPos()                                                     zCall( 0x00527A60 );
    virtual void __fastcall StoreSeek( unsigned long )                                                 zCall( 0x00527A80 );
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zCall( 0x00529AF0 );
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zCall( 0x00529CF0 );
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zCall( 0x0052A770 );
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zCall( 0x0052A690 );
    virtual void __fastcall SkipChunk( int )                                                           zCall( 0x0052BA60 );
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zCall( 0x0052A940 );
    virtual void __fastcall ReadChunkEnd()                                                             zCall( 0x0052B230 );
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zCall( 0x0052BC80 );
    virtual void __fastcall ReadHeader()                                                               zCall( 0x0052A270 );
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zCall( 0x00529D60 );
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zCall( 0x00529D90 );
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zCall( 0x0052A200 );
    virtual unsigned long __fastcall RestoreGetPos()                                                   zCall( 0x0052A210 );
    virtual void __fastcall RestoreSeek( unsigned long )                                               zCall( 0x0052A230 );
    virtual void __fastcall DeleteBuffer()                                                             zCall( 0x005275E0 );

    // user API
    #include "zCArchiverGeneric.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZARCHIVER_GENERIC_H__VER1__