// Supported with union (c) 2018-2021 Union team

#ifndef __ZBUFFER_H__VER2__
#define __ZBUFFER_H__VER2__

namespace Gothic_II_Classic {

  enum zTBufferMode {
    READ,
    WRITE,
    READWRITE
  };

  // sizeof 28h
  class zCBuffer {
  public:
    zTBufferMode mode;          // sizeof 04h    offset 04h
    unsigned char* buffer;      // sizeof 04h    offset 08h
    unsigned long pos_byte;     // sizeof 04h    offset 0Ch
    unsigned long pos_bit;      // sizeof 04h    offset 10h
    unsigned long maxsize_byte; // sizeof 04h    offset 14h
    unsigned long maxsize_bit;  // sizeof 04h    offset 18h
    unsigned long size_byte;    // sizeof 04h    offset 1Ch
    unsigned long size_bit;     // sizeof 04h    offset 20h
    unsigned char vobNr;        // sizeof 01h    offset 24h
    bool allocated;             // sizeof 01h    offset 25h
    bool bits_written;          // sizeof 01h    offset 26h
    bool buffer_error;          // sizeof 01h    offset 27h

    void zCBuffer_OnInit()                                zCall( 0x004404C0 );
    void zCBuffer_OnInit( unsigned long const& )          zCall( 0x00440540 );
    void zCBuffer_OnInit( void*, unsigned long const& )   zCall( 0x004405C0 );
    void zCBuffer_OnInit( zCBuffer const& )               zCall( 0x004414C0 );
    zCBuffer()                                            zInit( zCBuffer_OnInit() );
    zCBuffer( unsigned long const& a0 )                   zInit( zCBuffer_OnInit( a0 ));
    zCBuffer( void* a0, unsigned long const& a1 )         zInit( zCBuffer_OnInit( a0, a1 ));
    void Init()                                           zCall( 0x00440610 );
    zTBufferMode SetMode( zTBufferMode )                  zCall( 0x00440670 );
    void Reset()                                          zCall( 0x00440680 );
    void Resize( unsigned long )                          zCall( 0x004406A0 );
    unsigned long Write( void const*, unsigned long )     zCall( 0x00440730 );
    unsigned long WriteBits( void const*, unsigned long ) zCall( 0x00440750 );
    unsigned long WriteBool( int, int )                   zCall( 0x004408D0 );
    unsigned long WriteByte( unsigned char, int )         zCall( 0x004408F0 );
    unsigned long WriteWord( unsigned short, int )        zCall( 0x00440910 );
    unsigned long WriteDWord( unsigned long, int )        zCall( 0x00440930 );
    unsigned long WriteReal( float, int )                 zCall( 0x00440950 );
    unsigned long WriteInt( int, int )                    zCall( 0x00440970 );
    unsigned long WriteFloat( float, int )                zCall( 0x00440990 );
    unsigned long WriteFloatPacked0_16( float )           zCall( 0x004409B0 );
    unsigned long WriteFloatPacked0_8( float )            zCall( 0x004409E0 );
    unsigned long WriteFloatPacked8_8( float )            zCall( 0x00440A10 );
    unsigned long WriteString( zSTRING )                  zCall( 0x00440A80 );
    void CompleteByte()                                   zCall( 0x00440B00 );
    unsigned long Read( void*, unsigned long )            zCall( 0x00440B30 );
    unsigned long ReadBits( void*, unsigned long )        zCall( 0x00440B50 );
    int ReadBool( int )                                   zCall( 0x00440C10 );
    unsigned char ReadByte( int )                         zCall( 0x00440C30 );
    unsigned short ReadWord( int )                        zCall( 0x00440C50 );
    unsigned long ReadDWord( int )                        zCall( 0x00440C80 );
    float ReadReal( int )                                 zCall( 0x00440CB0 );
    int ReadInt( int )                                    zCall( 0x00440CD0 );
    float ReadFloat( int )                                zCall( 0x00440CF0 );
    float ReadFloatPacked0_16()                           zCall( 0x00440D10 );
    float ReadFloatPacked0_8()                            zCall( 0x00440D40 );
    float ReadFloatPacked8_8()                            zCall( 0x00440D70 );
    zSTRING ReadString()                                  zCall( 0x00440DA0 );
    void SetPos( unsigned long const& )                   zCall( 0x00440F80 );
    void SetBitPos( unsigned long const& )                zCall( 0x00440FA0 );
    unsigned long SetPosRel( int )                        zCall( 0x00440FC0 );
    unsigned long SetBitPosRel( int )                     zCall( 0x00440FE0 );
    void SetPosBegin()                                    zCall( 0x00441000 );
    void SetPosEnd()                                      zCall( 0x00441010 );
    unsigned long GetPos() const                          zCall( 0x00441030 );
    unsigned long GetBitPos() const                       zCall( 0x00441040 );
    unsigned long GetMaxSize() const                      zCall( 0x00441050 );
    unsigned long GetBitMaxSize() const                   zCall( 0x00441060 );
    unsigned long GetSize() const                         zCall( 0x00441070 );
    unsigned long GetBitSize() const                      zCall( 0x00441080 );
    unsigned long GetRestSize() const                     zCall( 0x00441090 );
    unsigned long GetBitRestSize() const                  zCall( 0x004410A0 );
    unsigned char* GetBuffer() const                      zCall( 0x004410B0 );
    unsigned char* GetCursor() const                      zCall( 0x004410C0 );
    void SkipByte()                                       zCall( 0x004410D0 );
    int GetBitSizeToNextByte() const                      zCall( 0x00441100 );
    bool HasError() const                                 zCall( 0x00441110 );
    unsigned long WriteObject( zCObject*& )               zCall( 0x00441150 );
    unsigned long ReadObject( zCObject*& )                zCall( 0x004412D0 );
    zCBuffer( zCBuffer const& a0 )                        zInit( zCBuffer_OnInit( a0 ));
    zCBuffer& operator =( zCBuffer const& )               zCall( 0x00441510 );
    void CopyFrom( zCBuffer const& )                      zCall( 0x00441530 );
    void ByteFreq_Analyse()                               zCall( 0x004415D0 );
    static void ByteFreq_Reset()                          zCall( 0x004415B0 );
    static void ByteFreq_Print()                          zCall( 0x00441600 );
    virtual ~zCBuffer()                                   zCall( 0x00440640 );

    // user API
    #include "zCBuffer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZBUFFER_H__VER2__