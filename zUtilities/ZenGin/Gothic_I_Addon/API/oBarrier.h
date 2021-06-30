// Supported with union (c) 2018 Union team

#ifndef __OBARRIER_H__VER1__
#define __OBARRIER_H__VER1__

namespace Gothic_I_Addon {

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

    void myThunder_OnInit() zCall( 0x00655E80 );
    ~myThunder()            zCall( 0x006550A0 );
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

    void oCBarrier_OnInit()                             zCall( 0x006550D0 );
    oCBarrier()                                         zInit( oCBarrier_OnInit() );
    ~oCBarrier()                                        zCall( 0x00655AB0 );
    void Initialise( int )                              zCall( 0x00655D90 );
    void AddTremor( zTRenderContext& )                  zCall( 0x00655E90 );
    void RenderLayer( zTRenderContext&, int, int& )     zCall( 0x00655EA0 );
    int Render( zTRenderContext&, int, int )            zCall( 0x006560E0 );
    void InitThunder( myThunder* )                      zCall( 0x00656B70 );
    void RemoveThunder( myThunder* )                    zCall( 0x00656BA0 );
    int AddThunderSub( myThunder*, int, int, int, int ) zCall( 0x00656C50 );
    int AddThunder( int, int, float, zTThunderSector )  zCall( 0x00656FE0 );
    int RenderThunder( myThunder*, zTRenderContext& )   zCall( 0x00657820 );
    void RenderThunderList( zTRenderContext& )          zCall( 0x00657AF0 );

    // user API
    #include "oCBarrier.inl"
  };

  class oCSkyControler_Barrier : public zCSkyControler_Outdoor {
  public:
    oCBarrier* barrier;
    int bFadeInOut;

    void oCSkyControler_Barrier_OnInit() zCall( 0x00657B30 );
    oCSkyControler_Barrier()             zInit( oCSkyControler_Barrier_OnInit() );
    virtual ~oCSkyControler_Barrier()    zCall( 0x00657BF0 );
    virtual void RenderSkyPre()          zCall( 0x00657C60 );

    // user API
    #include "oCSkyControler_Barrier.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OBARRIER_H__VER1__