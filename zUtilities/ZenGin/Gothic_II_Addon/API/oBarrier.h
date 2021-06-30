// Supported with union (c) 2018 Union team

#ifndef __OBARRIER_H__VER3__
#define __OBARRIER_H__VER3__

namespace Gothic_II_Addon {

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

    void myThunder_OnInit() zCall( 0x006B9CD0 );
    ~myThunder()            zCall( 0x006B8F90 );
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

    void oCBarrier_OnInit()                             zCall( 0x006B8FC0 );
    oCBarrier()                                         zInit( oCBarrier_OnInit() );
    ~oCBarrier()                                        zCall( 0x006B9190 );
    void Init()                                         zCall( 0x006B9440 );
    void Initialise( int )                              zCall( 0x006B9BF0 );
    void AddTremor( zTRenderContext& )                  zCall( 0x006B9CE0 );
    void RenderLayer( zTRenderContext&, int, int& )     zCall( 0x006B9CF0 );
    int Render( zTRenderContext&, int, int )            zCall( 0x006B9F30 );
    void InitThunder( myThunder* )                      zCall( 0x006BA9C0 );
    void RemoveThunder( myThunder* )                    zCall( 0x006BA9F0 );
    int AddThunderSub( myThunder*, int, int, int, int ) zCall( 0x006BAAA0 );
    int AddThunder( int, int, float, zTThunderSector )  zCall( 0x006BADE0 );
    int RenderThunder( myThunder*, zTRenderContext& )   zCall( 0x006BB4B0 );
    void RenderThunderList( zTRenderContext& )          zCall( 0x006BB770 );

    // user API
    #include "oCBarrier.inl"
  };

  class oCSkyControler_Barrier : public zCSkyControler_Outdoor {
  public:
    oCBarrier* barrier;
    int bFadeInOut;

    void oCSkyControler_Barrier_OnInit() zCall( 0x006BB7B0 );
    oCSkyControler_Barrier()             zInit( oCSkyControler_Barrier_OnInit() );
    virtual ~oCSkyControler_Barrier()    zCall( 0x006BB860 );
    virtual void RenderSkyPre()          zCall( 0x006BB8D0 );

    // user API
    #include "oCSkyControler_Barrier.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OBARRIER_H__VER3__