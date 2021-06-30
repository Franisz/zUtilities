// Supported with union (c) 2018 Union team

#ifndef __ZFFT_H__VER0__
#define __ZFFT_H__VER0__

namespace Gothic_I_Classic {

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

    zCFFT() {}

    // user API
    #include "zCFFT.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFFT_H__VER0__