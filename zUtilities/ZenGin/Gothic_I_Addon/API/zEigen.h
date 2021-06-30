// Supported with union (c) 2018 Union team

#ifndef __ZEIGEN_H__VER1__
#define __ZEIGEN_H__VER1__

namespace Gothic_I_Addon {

  class zCMgcEigenD {
  public:
    int size;
    double** mat;
    double* diag;
    double* subd;

    zCMgcEigenD() {}
    void zCMgcEigenD_OnInit( int )                       zCall( 0x0055A180 );
    zCMgcEigenD( int a0 )                                zInit( zCMgcEigenD_OnInit( a0 ));
    ~zCMgcEigenD()                                       zCall( 0x0055A250 );
    void Tridiagonal2( double**, double*, double* )      zCall( 0x0055A2A0 );
    void Tridiagonal3( double**, double*, double* )      zCall( 0x0055A310 );
    void Tridiagonal4( double**, double*, double* )      zCall( 0x0055A4C0 );
    void TridiagonalN( int, double**, double*, double* ) zCall( 0x0055ABA0 );
    void QLAlgorithm( int, double*, double*, double** )  zCall( 0x0055AFB0 );
    void DecreasingSort( int, double*, double** )        zCall( 0x0055B2A0 );
    void IncreasingSort( int, double*, double** )        zCall( 0x0055B340 );
    zCMgcEigenD& Matrix( double** )                      zCall( 0x0055B3E0 );
    void EigenStuff2()                                   zCall( 0x0055B430 );
    void EigenStuff3()                                   zCall( 0x0055B4B0 );
    void EigenStuff4()                                   zCall( 0x0055B4E0 );
    void EigenStuffN()                                   zCall( 0x0055B510 );
    void EigenStuff()                                    zCall( 0x0055B550 );
    void DecrSortEigenStuff2()                           zCall( 0x0055B620 );
    void DecrSortEigenStuff3()                           zCall( 0x0055B6B0 );
    void DecrSortEigenStuff4()                           zCall( 0x0055B6F0 );
    void DecrSortEigenStuffN()                           zCall( 0x0055B730 );
    void DecrSortEigenStuff()                            zCall( 0x0055B780 );
    void IncrSortEigenStuff2()                           zCall( 0x0055B870 );
    void IncrSortEigenStuff3()                           zCall( 0x0055B900 );
    void IncrSortEigenStuff4()                           zCall( 0x0055B940 );
    void IncrSortEigenStuffN()                           zCall( 0x0055B980 );
    void IncrSortEigenStuff()                            zCall( 0x0055B9D0 );
    static int Number( unsigned int )                    zCall( 0x0055BAC0 );
    static void Report( unsigned int )                   zCall( 0x0055BAE0 );
    static void Report( ostream& )                       zCall( 0x0055BC50 );

    // static properties
    static int& verbose;
    static unsigned int& error;
    static const unsigned int& invalid_size;
    static const unsigned int& allocation_failed;
    static const unsigned int& ql_exceeded;
    static const char**& message;

    // user API
    #include "zCMgcEigenD.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZEIGEN_H__VER1__