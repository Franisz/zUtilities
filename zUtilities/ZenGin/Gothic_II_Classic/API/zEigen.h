// Supported with union (c) 2018-2021 Union team

#ifndef __ZEIGEN_H__VER2__
#define __ZEIGEN_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 10h
  class zCMgcEigenD {
  public:
    int size;     // sizeof 04h    offset 00h
    double** mat; // sizeof 04h    offset 04h
    double* diag; // sizeof 04h    offset 08h
    double* subd; // sizeof 04h    offset 0Ch

    zCMgcEigenD() {}
    void zCMgcEigenD_OnInit( int )                       zCall( 0x00551E60 );
    zCMgcEigenD( int a0 )                                zInit( zCMgcEigenD_OnInit( a0 ));
    ~zCMgcEigenD()                                       zCall( 0x00551F00 );
    void Tridiagonal2( double**, double*, double* )      zCall( 0x00551F50 );
    void Tridiagonal3( double**, double*, double* )      zCall( 0x00551FC0 );
    void Tridiagonal4( double**, double*, double* )      zCall( 0x00552180 );
    void TridiagonalN( int, double**, double*, double* ) zCall( 0x00552870 );
    void QLAlgorithm( int, double*, double*, double** )  zCall( 0x00552C60 );
    void DecreasingSort( int, double*, double** )        zCall( 0x00552F30 );
    void IncreasingSort( int, double*, double** )        zCall( 0x00552FE0 );
    zCMgcEigenD& Matrix( double** )                      zCall( 0x00553090 );
    void EigenStuff2()                                   zCall( 0x005530E0 );
    void EigenStuff3()                                   zCall( 0x00553160 );
    void EigenStuff4()                                   zCall( 0x00553190 );
    void EigenStuffN()                                   zCall( 0x005531C0 );
    void EigenStuff()                                    zCall( 0x00553200 );
    void DecrSortEigenStuff2()                           zCall( 0x005532D0 );
    void DecrSortEigenStuff3()                           zCall( 0x00553360 );
    void DecrSortEigenStuff4()                           zCall( 0x005533A0 );
    void DecrSortEigenStuffN()                           zCall( 0x005533E0 );
    void DecrSortEigenStuff()                            zCall( 0x00553430 );
    void IncrSortEigenStuff2()                           zCall( 0x00553510 );
    void IncrSortEigenStuff3()                           zCall( 0x005535A0 );
    void IncrSortEigenStuff4()                           zCall( 0x005535E0 );
    void IncrSortEigenStuffN()                           zCall( 0x00553620 );
    void IncrSortEigenStuff()                            zCall( 0x00553670 );
    static int Number( unsigned int )                    zCall( 0x00553750 );
    static void Report( unsigned int )                   zCall( 0x00553770 );
    static void Report( ostream& )                       zCall( 0x005538E0 );

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

} // namespace Gothic_II_Classic

#endif // __ZEIGEN_H__VER2__