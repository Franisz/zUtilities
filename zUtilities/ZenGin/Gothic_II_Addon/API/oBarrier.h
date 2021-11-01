// Supported with union (c) 2018-2021 Union team

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

  // sizeof F8h
  struct myVert {
  public:
    int vertIndex;         // sizeof 04h    offset 00h
    int vertNeighbours[8]; // sizeof 20h    offset 04h
    int numNeighbours;     // sizeof 04h    offset 24h
    int polyIndices[50];   // sizeof C8h    offset 28h
    int numPolyIndices;    // sizeof 04h    offset F0h
    int active;            // sizeof 04h    offset F4h

    myVert() {}
  };

  // sizeof 4Ch
  struct myThunder {
  public:
    zVEC3 originVec;        // sizeof 0Ch    offset 00h
    myThunder* childs;      // sizeof 04h    offset 0Ch
    int numChilds;          // sizeof 04h    offset 10h
    float startTime[5];     // sizeof 14h    offset 14h
    zCPolyStrip* polyStrip; // sizeof 04h    offset 28h
    int numSegs;            // sizeof 04h    offset 2Ch
    int valid;              // sizeof 04h    offset 30h
    float t0;               // sizeof 04h    offset 34h
    float t1;               // sizeof 04h    offset 38h
    int numSplits;          // sizeof 04h    offset 3Ch
    int dead;               // sizeof 04h    offset 40h
    int isChild;            // sizeof 04h    offset 44h
    zTThunderSector sector; // sizeof 04h    offset 48h

    void myThunder_OnInit() zCall( 0x006B9CD0 );
    ~myThunder()            zCall( 0x006B8F90 );
    myThunder()             zInit( myThunder_OnInit() );
  };

  // sizeof 04h
  struct myPoly {
  public:
    int Alpha; // sizeof 04h    offset 00h

    myPoly() {}
  };

  // sizeof 12Ch
  class oCBarrier {
  public:
    zCMesh* skySphereMesh;      // sizeof 04h    offset 00h
    myPoly* myPolyList;         // sizeof 04h    offset 04h
    myVert* myVertList;         // sizeof 04h    offset 08h
    int numMyVerts;             // sizeof 04h    offset 0Ch
    int numMyPolys;             // sizeof 04h    offset 10h
    myThunder* myThunderList;   // sizeof 04h    offset 14h
    int numMaxThunders;         // sizeof 04h    offset 18h
    int numMyThunders;          // sizeof 04h    offset 1Ch
    int actualIndex;            // sizeof 04h    offset 20h
    int rootBoltIndex;          // sizeof 04h    offset 24h
    int startPointList1[10];    // sizeof 28h    offset 28h
    int numStartPoints1;        // sizeof 04h    offset 50h
    int startPointList2[10];    // sizeof 28h    offset 54h
    int numStartPoints2;        // sizeof 04h    offset 7Ch
    int startPointList3[10];    // sizeof 28h    offset 80h
    int numStartPoints3;        // sizeof 04h    offset A8h
    int startPointList4[10];    // sizeof 28h    offset ACh
    int numStartPoints4;        // sizeof 04h    offset D4h
    int topestPoint;            // sizeof 04h    offset D8h
    int bFadeInOut;             // sizeof 04h    offset DCh
    int fadeState;              // sizeof 04h    offset E0h
    int fadeIn;                 // sizeof 04h    offset E4h
    int fadeOut;                // sizeof 04h    offset E8h
    int bFlashing;              // sizeof 04h    offset ECh
    float fFlashTime;           // sizeof 04h    offset F0h
    zCSoundFX* sfx1;            // sizeof 04h    offset F4h
    int sfxHandle1;             // sizeof 04h    offset F8h
    zCSoundFX* sfx2;            // sizeof 04h    offset FCh
    int sfxHandle2;             // sizeof 04h    offset 100h
    zCSoundFX* sfx3;            // sizeof 04h    offset 104h
    int sfxHandle3;             // sizeof 04h    offset 108h
    zCSoundFX* sfx4;            // sizeof 04h    offset 10Ch
    int sfxHandle4;             // sizeof 04h    offset 110h
    zCDecal* thunderStartDecal; // sizeof 04h    offset 114h
    int activeThunder_Sector1;  // sizeof 04h    offset 118h
    int activeThunder_Sector2;  // sizeof 04h    offset 11Ch
    int activeThunder_Sector3;  // sizeof 04h    offset 120h
    int activeThunder_Sector4;  // sizeof 04h    offset 124h
    zVEC2* originalTexUVList;   // sizeof 04h    offset 128h

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

  // sizeof 6C4h
  class oCSkyControler_Barrier : public zCSkyControler_Outdoor {
  public:
    oCBarrier* barrier; // sizeof 04h    offset 6BCh
    int bFadeInOut;     // sizeof 04h    offset 6C0h

    void oCSkyControler_Barrier_OnInit() zCall( 0x006BB7B0 );
    oCSkyControler_Barrier()             zInit( oCSkyControler_Barrier_OnInit() );
    virtual ~oCSkyControler_Barrier()    zCall( 0x006BB860 );
    virtual void RenderSkyPre()          zCall( 0x006BB8D0 );

    // user API
    #include "oCSkyControler_Barrier.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OBARRIER_H__VER3__