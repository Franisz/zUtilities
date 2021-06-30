// Supported with union (c) 2018 Union team

#ifndef __ZCOLLISION_DETECTOR_H__VER3__
#define __ZCOLLISION_DETECTOR_H__VER3__

namespace Gothic_II_Addon {
  const int zNUM_COLL_REPORTS = 16;

  class zCCollisionReport {
  public:
    float m_fTimeStamp;
    zVEC3 m_oContactPoint;
    zVEC3 m_oCollNormal0;
    zVEC3 m_oCollNormal1;
    zCCollisionObject* m_poCollObject0;
    zCCollisionObject* m_poCollObject1;

    void zCCollisionReport_OnInit() zCall( 0x0054C550 );
    zCCollisionReport()             zInit( zCCollisionReport_OnInit() );
    virtual ~zCCollisionReport()    zCall( 0x0054C570 );

    // user API
    #include "zCCollisionReport.inl"
  };

  class zCCollisionDetector {
  public:

    zTStaticIntersectionTest** m_apStaticTestFuncMatrix;
    zTDynamicIntersectionTest** m_apDynamicTestFuncMatrix;

    void zCCollisionDetector_OnInit()                                                                                                                                                                                        zCall( 0x0054C5E0 );
    zCCollisionDetector()                                                                                                                                                                                                    zInit( zCCollisionDetector_OnInit() );
    int __fastcall GetTestFuncIndex( zCCollisionObjectDef*, zCCollisionObjectDef* )                                                                                                                                          zCall( 0x0054C6C0 );
    int( __cdecl* __fastcall GetStaticTestFunc( zCCollisionObjectDef*, zCCollisionObjectDef* ))( float, zCCollisionObject*, zMAT4 const&, zCCollisionObject*, zMAT4 const&, zCCollisionReport** )                            zCall( 0x0054C6E0 );
    int( __cdecl* __fastcall GetDynamicTestFunc( zCCollisionObjectDef*, zCCollisionObjectDef* ))( zCCollisionObject*, zCCollisionObject*, zCCollisionReport** )                                                              zCall( 0x0054C700 );
    void __fastcall DoDynamicIntersectionTests( zCCollisionObject*, zCArray<zCCollisionObject*>&, zCArray<zCCollisionReport*>& )                                                                                             zCall( 0x0054C8B0 );
    void __fastcall DoStaticIntersectionTests( zCCollisionObject*, zCArray<zCCollisionObject*>&, zCArray<zCCollisionReport*>& )                                                                                              zCall( 0x0054CAA0 );
    static void S_ResetFreeCollReportList()                                                                                                                                                                                  zCall( 0x0054C7C0 );
    static zCCollisionReport* S_GetNextFreeCollReport()                                                                                                                                                                      zCall( 0x0054C7D0 );
    virtual ~zCCollisionDetector()                                                                                                                                                                                           zCall( 0x0054C690 );
    virtual void __fastcall DetectCollisions( zCCollisionObject*, zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& )                                                                                         zCall( 0x0054CE50 );
    virtual void __fastcall RegisterStaticIntersectionTest( zCCollisionObjectDef*, zCCollisionObjectDef*, int( __cdecl* )( float, zCCollisionObject*, zMAT4 const&, zCCollisionObject*, zMAT4 const&, zCCollisionReport** )) zCall( 0x0054C720 );
    virtual void __fastcall RegisterDynamicIntersectionTest( zCCollisionObjectDef*, zCCollisionObjectDef*, int( __cdecl* )( zCCollisionObject*, zCCollisionObject*, zCCollisionReport** ))                                   zCall( 0x0054C750 );
    virtual int __fastcall CanCollide( zCCollisionObjectDef*, zCCollisionObjectDef* )                                                                                                                                        zCall( 0x0054C780 );

    // static properties
    static unsigned long& s_iCollisionDetectorFrameCtr;
    static int& s_iCurrentCollReport;
    static zCCollisionReport*& s_aoCollReportList;

    // user API
    #include "zCCollisionDetector.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCOLLISION_DETECTOR_H__VER3__