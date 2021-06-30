// Supported with union (c) 2018 Union team

#ifndef __ZEIGEN_H__VER3__
#define __ZEIGEN_H__VER3__

namespace Gothic_II_Addon {

  class zCMgcEigenD {
  public:
    int size;
    double** mat;
    double* diag;
    double* subd;

    zCMgcEigenD() {}
    void zCMgcEigenD_OnInit( int )                       zCall( 0x00557080 );
    zCMgcEigenD( int a0 )                                zInit( zCMgcEigenD_OnInit( a0 ));
    ~zCMgcEigenD()                                       zCall( 0x00557120 );
    void Tridiagonal2( double**, double*, double* )      zCall( 0x00557170 );
    void Tridiagonal3( double**, double*, double* )      zCall( 0x005571E0 );
    void Tridiagonal4( double**, double*, double* )      zCall( 0x005573A0 );
    void TridiagonalN( int, double**, double*, double* ) zCall( 0x00557A90 );
    void QLAlgorithm( int, double*, double*, double** )  zCall( 0x00557E80 );
    void DecreasingSort( int, double*, double** )        zCall( 0x00558150 );
    void IncreasingSort( int, double*, double** )        zCall( 0x00558200 );
    zCMgcEigenD& Matrix( double** )                      zCall( 0x005582B0 );
    void EigenStuff2()                                   zCall( 0x00558300 );
    void EigenStuff3()                                   zCall( 0x00558380 );
    void EigenStuff4()                                   zCall( 0x005583B0 );
    void EigenStuffN()                                   zCall( 0x005583E0 );
    void EigenStuff()                                    zCall( 0x00558420 );
    void DecrSortEigenStuff2()                           zCall( 0x005584F0 );
    void DecrSortEigenStuff3()                           zCall( 0x00558580 );
    void DecrSortEigenStuff4()                           zCall( 0x005585C0 );
    void DecrSortEigenStuffN()                           zCall( 0x00558600 );
    void DecrSortEigenStuff()                            zCall( 0x00558650 );
    void IncrSortEigenStuff2()                           zCall( 0x00558730 );
    void IncrSortEigenStuff3()                           zCall( 0x005587C0 );
    void IncrSortEigenStuff4()                           zCall( 0x00558800 );
    void IncrSortEigenStuffN()                           zCall( 0x00558840 );
    void IncrSortEigenStuff()                            zCall( 0x00558890 );
    static int Number( unsigned int )                    zCall( 0x00558970 );
    static void Report( unsigned int )                   zCall( 0x00558990 );
    static void Report( ostream& )                       zCall( 0x00558B00 );

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

} // namespace Gothic_II_Addon

#endif // __ZEIGEN_H__VER3__