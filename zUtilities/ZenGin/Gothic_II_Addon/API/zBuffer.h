// Supported with union (c) 2018 Union team

#ifndef __ZBUFFER_H__VER3__
#define __ZBUFFER_H__VER3__

namespace Gothic_II_Addon {

  enum zTBufferMode {
    READ,
    WRITE,
    READWRITE
  };

  class zCBuffer {
  public:
    zTBufferMode mode;
    unsigned char* buffer;
    unsigned long pos_byte;
    unsigned long pos_bit;
    unsigned long maxsize_byte;
    unsigned long maxsize_bit;
    unsigned long size_byte;
    unsigned long size_bit;
    unsigned char vobNr;
    bool allocated;
    bool bits_written;
    bool buffer_error;

    void zCBuffer_OnInit()                                zCall( 0x00440AF0 );
    void zCBuffer_OnInit( unsigned long const& )          zCall( 0x00440B70 );
    void zCBuffer_OnInit( void*, unsigned long const& )   zCall( 0x00440BF0 );
    void zCBuffer_OnInit( zCBuffer const& )               zCall( 0x00441AF0 );
    zCBuffer()                                            zInit( zCBuffer_OnInit() );
    zCBuffer( unsigned long const& a0 )                   zInit( zCBuffer_OnInit( a0 ));
    zCBuffer( void* a0, unsigned long const& a1 )         zInit( zCBuffer_OnInit( a0, a1 ));
    void Init()                                           zCall( 0x00440C40 );
    zTBufferMode SetMode( zTBufferMode )                  zCall( 0x00440CA0 );
    void Reset()                                          zCall( 0x00440CB0 );
    void Resize( unsigned long )                          zCall( 0x00440CD0 );
    unsigned long Write( void const*, unsigned long )     zCall( 0x00440D60 );
    unsigned long WriteBits( void const*, unsigned long ) zCall( 0x00440D80 );
    unsigned long WriteBool( int, int )                   zCall( 0x00440F00 );
    unsigned long WriteByte( unsigned char, int )         zCall( 0x00440F20 );
    unsigned long WriteWord( unsigned short, int )        zCall( 0x00440F40 );
    unsigned long WriteDWord( unsigned long, int )        zCall( 0x00440F60 );
    unsigned long WriteReal( float, int )                 zCall( 0x00440F80 );
    unsigned long WriteInt( int, int )                    zCall( 0x00440FA0 );
    unsigned long WriteFloat( float, int )                zCall( 0x00440FC0 );
    unsigned long WriteFloatPacked0_16( float )           zCall( 0x00440FE0 );
    unsigned long WriteFloatPacked0_8( float )            zCall( 0x00441010 );
    unsigned long WriteFloatPacked8_8( float )            zCall( 0x00441040 );
    unsigned long WriteString( zSTRING )                  zCall( 0x004410B0 );
    void CompleteByte()                                   zCall( 0x00441130 );
    unsigned long Read( void*, unsigned long )            zCall( 0x00441160 );
    unsigned long ReadBits( void*, unsigned long )        zCall( 0x00441180 );
    int ReadBool( int )                                   zCall( 0x00441240 );
    unsigned char ReadByte( int )                         zCall( 0x00441260 );
    unsigned short ReadWord( int )                        zCall( 0x00441280 );
    unsigned long ReadDWord( int )                        zCall( 0x004412B0 );
    float ReadReal( int )                                 zCall( 0x004412E0 );
    int ReadInt( int )                                    zCall( 0x00441300 );
    float ReadFloat( int )                                zCall( 0x00441320 );
    float ReadFloatPacked0_16()                           zCall( 0x00441340 );
    float ReadFloatPacked0_8()                            zCall( 0x00441370 );
    float ReadFloatPacked8_8()                            zCall( 0x004413A0 );
    zSTRING ReadString()                                  zCall( 0x004413D0 );
    void SetPos( unsigned long const& )                   zCall( 0x004415B0 );
    void SetBitPos( unsigned long const& )                zCall( 0x004415D0 );
    unsigned long SetPosRel( int )                        zCall( 0x004415F0 );
    unsigned long SetBitPosRel( int )                     zCall( 0x00441610 );
    void SetPosBegin()                                    zCall( 0x00441630 );
    void SetPosEnd()                                      zCall( 0x00441640 );
    unsigned long GetPos() const                          zCall( 0x00441660 );
    unsigned long GetBitPos() const                       zCall( 0x00441670 );
    unsigned long GetMaxSize() const                      zCall( 0x00441680 );
    unsigned long GetBitMaxSize() const                   zCall( 0x00441690 );
    unsigned long GetSize() const                         zCall( 0x004416A0 );
    unsigned long GetBitSize() const                      zCall( 0x004416B0 );
    unsigned long GetRestSize() const                     zCall( 0x004416C0 );
    unsigned long GetBitRestSize() const                  zCall( 0x004416D0 );
    unsigned char* GetBuffer() const                      zCall( 0x004416E0 );
    unsigned char* GetCursor() const                      zCall( 0x004416F0 );
    void SkipByte()                                       zCall( 0x00441700 );
    int GetBitSizeToNextByte() const                      zCall( 0x00441730 );
    bool HasError() const                                 zCall( 0x00441740 );
    unsigned long WriteObject( zCObject*& )               zCall( 0x00441780 );
    unsigned long ReadObject( zCObject*& )                zCall( 0x00441900 );
    zCBuffer( zCBuffer const& a0 )                        zInit( zCBuffer_OnInit( a0 ));
    zCBuffer& operator =( zCBuffer const& )               zCall( 0x00441B40 );
    void CopyFrom( zCBuffer const& )                      zCall( 0x00441B60 );
    void ByteFreq_Analyse()                               zCall( 0x00441C00 );
    static void ByteFreq_Reset()                          zCall( 0x00441BE0 );
    static void ByteFreq_Print()                          zCall( 0x00441C30 );
    virtual ~zCBuffer()                                   zCall( 0x00440C70 );

    // user API
    #include "zCBuffer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZBUFFER_H__VER3__