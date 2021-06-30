// Supported with union (c) 2018 Union team

#ifndef __ZCOLLISION_OBJECT_H__VER3__
#define __ZCOLLISION_OBJECT_H__VER3__

namespace Gothic_II_Addon {

  class zCCollisionObjectDef {
  public:
    zCCollisionObject*( *m_createNewInstance )( void );
    int m_bIsVolatile;
    int m_iIndex;

    zCCollisionObjectDef() {}
    void zCCollisionObjectDef_OnInit( int, zCCollisionObject*( __cdecl* )() ) zCall( 0x0054D250 );
    zCCollisionObjectDef( int a0, zCCollisionObject*( __cdecl* a1 )() )       zInit( zCCollisionObjectDef_OnInit( a0, a1 ));
    ~zCCollisionObjectDef()                                                   zCall( 0x0054D380 );

    // static properties
    static zCArray<zCCollisionObjectDef*>*& s_aoCollObjClassList;

    // user API
    #include "zCCollisionObjectDef.inl"
  };

  class zCCollisionObject {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollisionObject )

    zMAT4 m_oTrafoOld;
    zMAT4 m_oTrafoNew;
    void* m_pvClientData;
    group {
      unsigned char m_bHintTranslation : 1;
      unsigned char m_bHintRotation    : 1;
    };

    zCCollisionObject() {}
    void __fastcall CalcIntermediateTrafo( float, zMAT4& )                                                           zCall( 0x0054D400 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x0054D1A0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x0054D1E0 );
    virtual ~zCCollisionObject()                                                                                     zCall( 0x0054D230 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x0054D1F0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x0054D200 );
    virtual float __fastcall GetAdaptiveStepSize()                                                                   zCall( 0x0054D210 );
    virtual int __fastcall SuppressCollisionResponse()                                                               zCall( 0x0054D220 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x0054D520 );

    // user API
    #include "zCCollisionObject.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCOLLISION_OBJECT_H__VER3__