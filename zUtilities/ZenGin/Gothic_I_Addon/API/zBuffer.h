// Supported with union (c) 2018 Union team

#ifndef __ZBUFFER_H__VER1__
#define __ZBUFFER_H__VER1__

namespace Gothic_I_Addon {

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

    void zCBuffer_OnInit()                                zCall( 0x00441F10 );
    void zCBuffer_OnInit( unsigned long const& )          zCall( 0x00441F90 );
    void zCBuffer_OnInit( void*, unsigned long const& )   zCall( 0x00442020 );
    void zCBuffer_OnInit( zCBuffer const& )               zCall( 0x00442EA0 );
    zCBuffer()                                            zInit( zCBuffer_OnInit() );
    zCBuffer( unsigned long const& a0 )                   zInit( zCBuffer_OnInit( a0 ));
    zCBuffer( void* a0, unsigned long const& a1 )         zInit( zCBuffer_OnInit( a0, a1 ));
    void Init()                                           zCall( 0x00442070 );
    zTBufferMode SetMode( zTBufferMode )                  zCall( 0x004420D0 );
    void Reset()                                          zCall( 0x004420E0 );
    void Resize( unsigned long )                          zCall( 0x00442100 );
    unsigned long Write( void const*, unsigned long )     zCall( 0x004421A0 );
    unsigned long WriteBits( void const*, unsigned long ) zCall( 0x004421C0 );
    unsigned long WriteBool( int, int )                   zCall( 0x004422C0 );
    unsigned long WriteByte( unsigned char, int )         zCall( 0x004422E0 );
    unsigned long WriteWord( unsigned short, int )        zCall( 0x00442300 );
    unsigned long WriteDWord( unsigned long, int )        zCall( 0x00442320 );
    unsigned long WriteReal( float, int )                 zCall( 0x00442340 );
    unsigned long WriteInt( int, int )                    zCall( 0x00442360 );
    unsigned long WriteFloat( float, int )                zCall( 0x00442380 );
    unsigned long WriteFloatPacked0_16( float )           zCall( 0x004423A0 );
    unsigned long WriteFloatPacked0_8( float )            zCall( 0x004423D0 );
    unsigned long WriteFloatPacked8_8( float )            zCall( 0x00442400 );
    unsigned long WriteString( zSTRING )                  zCall( 0x00442470 );
    void CompleteByte()                                   zCall( 0x00442510 );
    unsigned long Read( void*, unsigned long )            zCall( 0x00442540 );
    unsigned long ReadBits( void*, unsigned long )        zCall( 0x00442560 );
    int ReadBool( int )                                   zCall( 0x00442620 );
    unsigned char ReadByte( int )                         zCall( 0x00442640 );
    unsigned short ReadWord( int )                        zCall( 0x00442660 );
    unsigned long ReadDWord( int )                        zCall( 0x00442690 );
    float ReadReal( int )                                 zCall( 0x004426C0 );
    int ReadInt( int )                                    zCall( 0x004426E0 );
    float ReadFloat( int )                                zCall( 0x00442700 );
    float ReadFloatPacked0_16()                           zCall( 0x00442720 );
    float ReadFloatPacked0_8()                            zCall( 0x00442750 );
    float ReadFloatPacked8_8()                            zCall( 0x00442780 );
    zSTRING ReadString()                                  zCall( 0x004427B0 );
    void SetPos( unsigned long const& )                   zCall( 0x004429C0 );
    void SetBitPos( unsigned long const& )                zCall( 0x004429E0 );
    unsigned long SetPosRel( int )                        zCall( 0x00442A00 );
    unsigned long SetBitPosRel( int )                     zCall( 0x00442A20 );
    void SetPosBegin()                                    zCall( 0x00442A40 );
    void SetPosEnd()                                      zCall( 0x00442A50 );
    unsigned long GetPos() const                          zCall( 0x00442A70 );
    unsigned long GetBitPos() const                       zCall( 0x00442A80 );
    unsigned long GetMaxSize() const                      zCall( 0x00442A90 );
    unsigned long GetBitMaxSize() const                   zCall( 0x00442AA0 );
    unsigned long GetSize() const                         zCall( 0x00442AB0 );
    unsigned long GetBitSize() const                      zCall( 0x00442AC0 );
    unsigned long GetRestSize() const                     zCall( 0x00442AD0 );
    unsigned long GetBitRestSize() const                  zCall( 0x00442AE0 );
    unsigned char* GetBuffer() const                      zCall( 0x00442AF0 );
    unsigned char* GetCursor() const                      zCall( 0x00442B00 );
    void SkipByte()                                       zCall( 0x00442B10 );
    int GetBitSizeToNextByte() const                      zCall( 0x00442B40 );
    bool HasError() const                                 zCall( 0x00442B50 );
    unsigned long WriteObject( zCObject*& )               zCall( 0x00442B90 );
    unsigned long ReadObject( zCObject*& )                zCall( 0x00442CF0 );
    zCBuffer( zCBuffer const& a0 )                        zInit( zCBuffer_OnInit( a0 ));
    zCBuffer& operator =( zCBuffer const& )               zCall( 0x00442EF0 );
    void CopyFrom( zCBuffer const& )                      zCall( 0x00442F10 );
    void ByteFreq_Analyse()                               zCall( 0x00442FC0 );
    static void ByteFreq_Reset()                          zCall( 0x00442FA0 );
    static void ByteFreq_Print()                          zCall( 0x00442FF0 );
    virtual ~zCBuffer()                                   zCall( 0x004420A0 );

    // user API
    #include "zCBuffer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZBUFFER_H__VER1__