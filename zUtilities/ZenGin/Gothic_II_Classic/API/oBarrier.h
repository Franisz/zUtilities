// Supported with union (c) 2018 Union team

#ifndef __OBARRIER_H__VER2__
#define __OBARRIER_H__VER2__

namespace Gothic_II_Classic {

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

    void myThunder_OnInit() zCall( 0x0065D340 );
    ~myThunder()            zCall( 0x0065C600 );
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
    int bFlashing;
    float fFlashTime;
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

    void oCBarrier_OnInit()                             zCall( 0x0065C630 );
    oCBarrier()                                         zInit( oCBarrier_OnInit() );
    ~oCBarrier()                                        zCall( 0x0065C800 );
    void Init()                                         zCall( 0x0065CAB0 );
    void Initialise( int )                              zCall( 0x0065D260 );
    void AddTremor( zTRenderContext& )                  zCall( 0x0065D350 );
    void RenderLayer( zTRenderContext&, int, int& )     zCall( 0x0065D360 );
    int Render( zTRenderContext&, int, int )            zCall( 0x0065D5A0 );
    void InitThunder( myThunder* )                      zCall( 0x0065E030 );
    void RemoveThunder( myThunder* )                    zCall( 0x0065E060 );
    int AddThunderSub( myThunder*, int, int, int, int ) zCall( 0x0065E110 );
    int AddThunder( int, int, float, zTThunderSector )  zCall( 0x0065E450 );
    int RenderThunder( myThunder*, zTRenderContext& )   zCall( 0x0065EB20 );
    void RenderThunderList( zTRenderContext& )          zCall( 0x0065EDE0 );

    // user API
    #include "oCBarrier.inl"
  };

  class oCSkyControler_Barrier : public zCSkyControler_Outdoor {
  public:
    oCBarrier* barrier;
    int bFadeInOut;

    void oCSkyControler_Barrier_OnInit() zCall( 0x0065EE20 );
    oCSkyControler_Barrier()             zInit( oCSkyControler_Barrier_OnInit() );
    virtual ~oCSkyControler_Barrier()    zCall( 0x0065EED0 );
    virtual void RenderSkyPre()          zCall( 0x0065EF40 );

    // user API
    #include "oCSkyControler_Barrier.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OBARRIER_H__VER2__