// Supported with union (c) 2018-2021 Union team

#ifndef __ZFFT_H__VER0__
#define __ZFFT_H__VER0__

namespace Gothic_I_Classic {

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

    // user API
    #include "zRandom_Gauss.inl"
  };

  // sizeof 18h
  class zCFFT {
  public:
    zComplex** m_h0Map;    // sizeof 04h    offset 00h
    zComplex** m_WaveMap;  // sizeof 04h    offset 04h
    zComplex** m_IWaveMap; // sizeof 04h    offset 08h
    float fftSpeed;        // sizeof 04h    offset 0Ch
    int frameCtr;          // sizeof 04h    offset 10h
    int frameCtrLastUsed;  // sizeof 04h    offset 14h

    zCFFT() {}

    // user API
    #include "zCFFT.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFFT_H__VER0__