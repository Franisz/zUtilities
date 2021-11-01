// Supported with union (c) 2018-2021 Union team

#ifndef __ZFFT_H__VER2__
#define __ZFFT_H__VER2__

namespace Gothic_II_Classic {

  enum zTFFT {
    zTFFT_NONE,
    zTFFT_SLOW,
    zTFFT_NORMAL,
    zTFFT_FAST
  };

  // sizeof 1Ch
  class zRandom_Gauss {
  public:
    float* u;        // sizeof 04h    offset 00h
    float c;         // sizeof 04h    offset 04h
    float cd;        // sizeof 04h    offset 08h
    float cm;        // sizeof 04h    offset 0Ch
    int i97;         // sizeof 04h    offset 10h
    int j97;         // sizeof 04h    offset 14h
    int m_gaussCall; // sizeof 04h    offset 18h

    zRandom_Gauss() {}
    void zRandom_Gauss_OnInit( int, int ) zCall( 0x00555AC0 );
    zRandom_Gauss( int a0, int a1 )       zInit( zRandom_Gauss_OnInit( a0, a1 ));
    ~zRandom_Gauss()                      zCall( 0x00555C00 );
    float RandomUniform()                 zCall( 0x00555C10 );
    float GetGaussian( float, float )     zCall( 0x00555C90 );
    int GetInt( int, int )                zCall( 0x00555D80 );
    float GetFloat( float, float )        zCall( 0x00555DB0 );
    void StepForward( long )              zCall( 0x00555DD0 );
    float UnRandomUniform()               zCall( 0x00555E50 );
    void StepBack( long )                 zCall( 0x00555F20 );
    unsigned int rand24()                 zCall( 0x00555FE0 );
    unsigned int unRand24()               zCall( 0x00555FF0 );
    float GetGaussAt( long )              zCall( 0x00556000 );

    // user API
    #include "zRandom_Gauss.inl"
  };

  // sizeof 1Ch
  class zCFFT {
  public:
    zComplex** m_h0Map;    // sizeof 04h    offset 04h
    zComplex** m_WaveMap;  // sizeof 04h    offset 08h
    zComplex** m_IWaveMap; // sizeof 04h    offset 0Ch
    float fftSpeed;        // sizeof 04h    offset 10h
    int frameCtr;          // sizeof 04h    offset 14h
    int frameCtrLastUsed;  // sizeof 04h    offset 18h

    void zCFFT_OnInit()                                       zCall( 0x00554C20 );
    zCFFT()                                                   zInit( zCFFT_OnInit() );
    float CalcWave2D( float, float, float )                   zCall( 0x00554DA0 );
    int IsPowerOfTwo( unsigned int )                          zCall( 0x00554F40 );
    unsigned int NumberOfBitsNeeded( unsigned int )           zCall( 0x00554F60 );
    unsigned int ReverseBits( unsigned int, unsigned int )    zCall( 0x00554FB0 );
    float Index_to_frequency( unsigned int, unsigned int )    zCall( 0x00554FE0 );
    void CreateWaveMap( float, zVEC3& )                       zCall( 0x00555050 );
    void FillH0Array( float, zVEC3& )                         zCall( 0x00555090 );
    void AnimateWaveMap( float )                              zCall( 0x00555300 );
    void fft_float( unsigned int, int, zComplex*, zComplex* ) zCall( 0x005554F0 );
    void SetFrameCtr( int )                                   zCall( 0x00555750 );
    void SetSpeed( float )                                    zCall( 0x00555760 );
    zComplex& GetWaveHeight( int, int )                       zCall( 0x00555770 );
    zComplex& GetWaveHeight( float, float, float )            zCall( 0x005557C0 );
    zComplex& GetWaveHeightSmooth( float, float, float )      zCall( 0x00555860 );
    zComplex** CreateArray()                                  zCall( 0x005559E0 );
    void FreeArray( zComplex** )                              zCall( 0x00555A80 );
    static float S_CalcWave2D( float, float, float, zTFFT )   zCall( 0x005545B0 );
    static void S_Init()                                      zCall( 0x00554AA0 );
    static void S_SetFrameCtr( int )                          zCall( 0x00554BB0 );
    static void S_AnimateWaveMap( float )                     zCall( 0x00559DF0 );
    virtual ~zCFFT()                                          zCall( 0x00554BD0 );

    // static properties
    static zCFFT& s_fft;
    static zCFFT& s_fftSlow;
    static zCFFT& s_fftFast;

    // user API
    #include "zCFFT.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZFFT_H__VER2__