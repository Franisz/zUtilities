// Supported with union (c) 2018 Union team

#ifndef __ZFFT_H__VER3__
#define __ZFFT_H__VER3__

namespace Gothic_II_Addon {

  enum zTFFT {
    zTFFT_NONE,
    zTFFT_SLOW,
    zTFFT_NORMAL,
    zTFFT_FAST
  };

  class zRandom_Gauss {
  public:
    float* u;
    float c;
    float cd;
    float cm;
    int i97;
    int j97;
    int m_gaussCall;

    zRandom_Gauss() {}
    void zRandom_Gauss_OnInit( int, int ) zCall( 0x0055ACE0 );
    zRandom_Gauss( int a0, int a1 )       zInit( zRandom_Gauss_OnInit( a0, a1 ));
    ~zRandom_Gauss()                      zCall( 0x0055AE20 );
    float RandomUniform()                 zCall( 0x0055AE30 );
    float GetGaussian( float, float )     zCall( 0x0055AEB0 );
    int GetInt( int, int )                zCall( 0x0055AFA0 );
    float GetFloat( float, float )        zCall( 0x0055AFD0 );
    void StepForward( long )              zCall( 0x0055AFF0 );
    float UnRandomUniform()               zCall( 0x0055B070 );
    void StepBack( long )                 zCall( 0x0055B140 );
    unsigned int rand24()                 zCall( 0x0055B200 );
    unsigned int unRand24()               zCall( 0x0055B210 );
    float GetGaussAt( long )              zCall( 0x0055B220 );

    // user API
    #include "zRandom_Gauss.inl"
  };

  class zCFFT {
  public:
    zComplex** m_h0Map;
    zComplex** m_WaveMap;
    zComplex** m_IWaveMap;
    float fftSpeed;
    int frameCtr;
    int frameCtrLastUsed;

    void zCFFT_OnInit()                                       zCall( 0x00559E40 );
    zCFFT()                                                   zInit( zCFFT_OnInit() );
    float CalcWave2D( float, float, float )                   zCall( 0x00559FC0 );
    int IsPowerOfTwo( unsigned int )                          zCall( 0x0055A160 );
    unsigned int NumberOfBitsNeeded( unsigned int )           zCall( 0x0055A180 );
    unsigned int ReverseBits( unsigned int, unsigned int )    zCall( 0x0055A1D0 );
    float Index_to_frequency( unsigned int, unsigned int )    zCall( 0x0055A200 );
    void CreateWaveMap( float, zVEC3& )                       zCall( 0x0055A270 );
    void FillH0Array( float, zVEC3& )                         zCall( 0x0055A2B0 );
    void AnimateWaveMap( float )                              zCall( 0x0055A520 );
    void fft_float( unsigned int, int, zComplex*, zComplex* ) zCall( 0x0055A710 );
    void SetFrameCtr( int )                                   zCall( 0x0055A970 );
    void SetSpeed( float )                                    zCall( 0x0055A980 );
    zComplex& GetWaveHeight( int, int )                       zCall( 0x0055A990 );
    zComplex& GetWaveHeight( float, float, float )            zCall( 0x0055A9E0 );
    zComplex& GetWaveHeightSmooth( float, float, float )      zCall( 0x0055AA80 );
    zComplex** CreateArray()                                  zCall( 0x0055AC00 );
    void FreeArray( zComplex** )                              zCall( 0x0055ACA0 );
    static float S_CalcWave2D( float, float, float, zTFFT )   zCall( 0x005597D0 );
    static void S_Init()                                      zCall( 0x00559CC0 );
    static void S_SetFrameCtr( int )                          zCall( 0x00559DD0 );
    static void S_AnimateWaveMap( float )                     zCall( 0x00559DF0 );
    virtual ~zCFFT()                                          zCall( 0x00559F20 );

    // static properties
    static zCFFT& s_fft;
    static zCFFT& s_fftSlow;
    static zCFFT& s_fftFast;

    // user API
    #include "zCFFT.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZFFT_H__VER3__