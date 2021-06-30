// Supported with union (c) 2018 Union team

#ifndef __OBARRIER_H__VER0__
#define __OBARRIER_H__VER0__

namespace Gothic_I_Classic {

  enum zTThunderSector {
    zTThunderSector_None,
    zTThunderSector_1,
    zTThunderSector_2,
    zTThunderSector_3,
    zTThunderSector_4
  };

  struct myVert {
  public:
    int vertIndex;
    int vertNeighbours[8];
    int numNeighbours;
    int polyIndices[50];
    int numPolyIndices;
    int active;

    myVert() {}
  };

  struct myThunder {
  public:
    zVEC3 originVec;
    myThunder* childs;
    int numChilds;
    float startTime[5];
    zCPolyStrip* polyStrip;
    int numSegs;
    int valid;
    float t0;
    float t1;
    int numSplits;
    int dead;
    int isChild;
    zTThunderSector sector;

    void myThunder_OnInit() zCall( 0x00630560 );
    ~myThunder()            zCall( 0x0062F7B0 );
    myThunder()             zInit( myThunder_OnInit() );
  };

  struct myPoly {
  public:
    int Alpha;

    myPoly() {}
  };

  class oCBarrier {
  public:
    zCMesh* skySphereMesh;
    myPoly* myPolyList;
    myVert* myVertList;
    int numMyVerts;
    int numMyPolys;
    myThunder* myThunderList;
    int numMaxThunders;
    int numMyThunders;
    int actualIndex;
    int rootBoltIndex;
    int startPointList1[10];
    int numStartPoints1;
    int startPointList2[10];
    int numStartPoints2;
    int startPointList3[10];
    int numStartPoints3;
    int startPointList4[10];
    int numStartPoints4;
    int topestPoint;
    int bFadeInOut;
    int fadeState;
    int fadeIn;
    int fadeOut;
    zCSoundFX* sfx1;
    int sfxHandle1;
    zCSoundFX* sfx2;
    int sfxHandle2;
    zCSoundFX* sfx3;
    int sfxHandle3;
    zCSoundFX* sfx4;
    int sfxHandle4;
    zCDecal* thunderStartDecal;
    int activeThunder_Sector1;
    int activeThunder_Sector2;
    int activeThunder_Sector3;
    int activeThunder_Sector4;
    zVEC2* originalTexUVList;

    void oCBarrier_OnInit()                             zCall( 0x0062F7E0 );
    oCBarrier()                                         zInit( oCBarrier_OnInit() );
    ~oCBarrier()                                        zCall( 0x006301C0 );
    void Initialise( int )                              zCall( 0x00630470 );
    void AddTremor( zTRenderContext& )                  zCall( 0x00630570 );
    void RenderLayer( zTRenderContext&, int, int& )     zCall( 0x00630580 );
    int Render( zTRenderContext&, int, int )            zCall( 0x006307C0 );
    void InitThunder( myThunder* )                      zCall( 0x006311F0 );
    void RemoveThunder( myThunder* )                    zCall( 0x00631220 );
    int AddThunderSub( myThunder*, int, int, int, int ) zCall( 0x006312D0 );
    int AddThunder( int, int, float, zTThunderSector )  zCall( 0x00631620 );
    int RenderThunder( myThunder*, zTRenderContext& )   zCall( 0x00631D10 );
    void RenderThunderList( zTRenderContext& )          zCall( 0x00631FD0 );

    // user API
    #include "oCBarrier.inl"
  };

  class oCSkyControler_Barrier : public zCSkyControler_Outdoor {
  public:
    oCBarrier* barrier;
    int bFadeInOut;

    void oCSkyControler_Barrier_OnInit() zCall( 0x00632010 );
    oCSkyControler_Barrier()             zInit( oCSkyControler_Barrier_OnInit() );
    virtual ~oCSkyControler_Barrier()    zCall( 0x006320D0 );
    virtual void RenderSkyPre()          zCall( 0x00632140 );

    // user API
    #include "oCSkyControler_Barrier.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OBARRIER_H__VER0__