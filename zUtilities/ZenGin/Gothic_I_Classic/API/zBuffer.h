// Supported with union (c) 2018-2021 Union team

#ifndef __ZBUFFER_H__VER0__
#define __ZBUFFER_H__VER0__

namespace Gothic_I_Classic {

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

    void zCBuffer_OnInit()                                zCall( 0x0043CD40 );
    void zCBuffer_OnInit( unsigned long const& )          zCall( 0x0043CDC0 );
    void zCBuffer_OnInit( void*, unsigned long const& )   zCall( 0x0043CE50 );
    void zCBuffer_OnInit( zCBuffer const& )               zCall( 0x0043DC30 );
    zCBuffer()                                            zInit( zCBuffer_OnInit() );
    zCBuffer( unsigned long const& a0 )                   zInit( zCBuffer_OnInit( a0 ));
    zCBuffer( void* a0, unsigned long const& a1 )         zInit( zCBuffer_OnInit( a0, a1 ));
    void Init()                                           zCall( 0x0043CEA0 );
    zTBufferMode SetMode( zTBufferMode )                  zCall( 0x0043CF00 );
    void Reset()                                          zCall( 0x0043CF10 );
    void Resize( unsigned long )                          zCall( 0x0043CF30 );
    unsigned long Write( void const*, unsigned long )     zCall( 0x0043CFD0 );
    unsigned long WriteBits( void const*, unsigned long ) zCall( 0x0043CFF0 );
    unsigned long WriteBool( int, int )                   zCall( 0x0043D100 );
    unsigned long WriteByte( unsigned char, int )         zCall( 0x0043D120 );
    unsigned long WriteWord( unsigned short, int )        zCall( 0x0043D140 );
    unsigned long WriteDWord( unsigned long, int )        zCall( 0x0043D160 );
    unsigned long WriteReal( float, int )                 zCall( 0x0043D180 );
    unsigned long WriteInt( int, int )                    zCall( 0x0043D1A0 );
    unsigned long WriteFloat( float, int )                zCall( 0x0043D1C0 );
    unsigned long WriteFloatPacked0_16( float )           zCall( 0x0043D1E0 );
    unsigned long WriteFloatPacked0_8( float )            zCall( 0x0043D210 );
    unsigned long WriteFloatPacked8_8( float )            zCall( 0x0043D240 );
    unsigned long WriteString( zSTRING )                  zCall( 0x0043D2B0 );
    void CompleteByte()                                   zCall( 0x0043D330 );
    unsigned long Read( void*, unsigned long )            zCall( 0x0043D360 );
    unsigned long ReadBits( void*, unsigned long )        zCall( 0x0043D380 );
    int ReadBool( int )                                   zCall( 0x0043D440 );
    unsigned char ReadByte( int )                         zCall( 0x0043D460 );
    unsigned short ReadWord( int )                        zCall( 0x0043D480 );
    unsigned long ReadDWord( int )                        zCall( 0x0043D4B0 );
    float ReadReal( int )                                 zCall( 0x0043D4E0 );
    int ReadInt( int )                                    zCall( 0x0043D500 );
    float ReadFloat( int )                                zCall( 0x0043D520 );
    float ReadFloatPacked0_16()                           zCall( 0x0043D540 );
    float ReadFloatPacked0_8()                            zCall( 0x0043D570 );
    float ReadFloatPacked8_8()                            zCall( 0x0043D5A0 );
    zSTRING ReadString()                                  zCall( 0x0043D5D0 );
    void SetPos( unsigned long const& )                   zCall( 0x0043D7B0 );
    void SetBitPos( unsigned long const& )                zCall( 0x0043D7D0 );
    unsigned long SetPosRel( int )                        zCall( 0x0043D7F0 );
    unsigned long SetBitPosRel( int )                     zCall( 0x0043D810 );
    void SetPosBegin()                                    zCall( 0x0043D830 );
    void SetPosEnd()                                      zCall( 0x0043D840 );
    unsigned long GetPos() const                          zCall( 0x0043D860 );
    unsigned long GetBitPos() const                       zCall( 0x0043D870 );
    unsigned long GetMaxSize() const                      zCall( 0x0043D880 );
    unsigned long GetBitMaxSize() const                   zCall( 0x0043D890 );
    unsigned long GetSize() const                         zCall( 0x0043D8A0 );
    unsigned long GetBitSize() const                      zCall( 0x0043D8B0 );
    unsigned long GetRestSize() const                     zCall( 0x0043D8C0 );
    unsigned long GetBitRestSize() const                  zCall( 0x0043D8D0 );
    unsigned char* GetBuffer() const                      zCall( 0x0043D8E0 );
    unsigned char* GetCursor() const                      zCall( 0x0043D8F0 );
    void SkipByte()                                       zCall( 0x0043D900 );
    int GetBitSizeToNextByte() const                      zCall( 0x0043D930 );
    bool HasError() const                                 zCall( 0x0043D940 );
    unsigned long WriteObject( zCObject*& )               zCall( 0x0043D980 );
    unsigned long ReadObject( zCObject*& )                zCall( 0x0043DAB0 );
    zCBuffer( zCBuffer const& a0 )                        zInit( zCBuffer_OnInit( a0 ));
    zCBuffer& operator =( zCBuffer const& )               zCall( 0x0043DC80 );
    void CopyFrom( zCBuffer const& )                      zCall( 0x0043DCA0 );
    void ByteFreq_Analyse()                               zCall( 0x0043DD50 );
    static void ByteFreq_Reset()                          zCall( 0x0043DD30 );
    static void ByteFreq_Print()                          zCall( 0x0043DD80 );
    virtual ~zCBuffer()                                   zCall( 0x0043CED0 );

    // user API
    #include "zCBuffer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZBUFFER_H__VER0__