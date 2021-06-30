// Supported with union (c) 2018 Union team

#ifndef __ZEIGEN_H__VER0__
#define __ZEIGEN_H__VER0__

namespace Gothic_I_Classic {

  class zCMgcEigenD {
  public:
    int size;
    double** mat;
    double* diag;
    double* subd;

    zCMgcEigenD() {}
    void zCMgcEigenD_OnInit( int )                       zCall( 0x005427B0 );
    zCMgcEigenD( int a0 )                                zInit( zCMgcEigenD_OnInit( a0 ));
    ~zCMgcEigenD()                                       zCall( 0x00542880 );
    void Tridiagonal2( double**, double*, double* )      zCall( 0x005428D0 );
    void Tridiagonal3( double**, double*, double* )      zCall( 0x00542940 );
    void Tridiagonal4( double**, double*, double* )      zCall( 0x00542B00 );
    void TridiagonalN( int, double**, double*, double* ) zCall( 0x005431F0 );
    void QLAlgorithm( int, double*, double*, double** )  zCall( 0x005435E0 );
    void DecreasingSort( int, double*, double** )        zCall( 0x005438B0 );
    void IncreasingSort( int, double*, double** )        zCall( 0x00543960 );
    zCMgcEigenD& Matrix( double** )                      zCall( 0x00543A10 );
    void EigenStuff2()                                   zCall( 0x00543A60 );
    void EigenStuff3()                                   zCall( 0x00543AE0 );
    void EigenStuff4()                                   zCall( 0x00543B10 );
    void EigenStuffN()                                   zCall( 0x00543B40 );
    void EigenStuff()                                    zCall( 0x00543B80 );
    void DecrSortEigenStuff2()                           zCall( 0x00543C50 );
    void DecrSortEigenStuff3()                           zCall( 0x00543CE0 );
    void DecrSortEigenStuff4()                           zCall( 0x00543D20 );
    void DecrSortEigenStuffN()                           zCall( 0x00543D60 );
    void DecrSortEigenStuff()                            zCall( 0x00543DB0 );
    void IncrSortEigenStuff2()                           zCall( 0x00543E90 );
    void IncrSortEigenStuff3()                           zCall( 0x00543F20 );
    void IncrSortEigenStuff4()                           zCall( 0x00543F60 );
    void IncrSortEigenStuffN()                           zCall( 0x00543FA0 );
    void IncrSortEigenStuff()                            zCall( 0x00543FF0 );
    static int Number( unsigned int )                    zCall( 0x005440D0 );
    static void Report( unsigned int )                   zCall( 0x005440F0 );
    static void Report( ostream& )                       zCall( 0x00544260 );

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

} // namespace Gothic_I_Classic

#endif // __ZEIGEN_H__VER0__