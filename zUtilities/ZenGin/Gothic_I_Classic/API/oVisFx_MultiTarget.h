// Supported with union (c) 2018 Union team

#ifndef __OVIS_FX__MULTI_TARGET_H__VER0__
#define __OVIS_FX__MULTI_TARGET_H__VER0__

#include "oVisFx.h"

namespace Gothic_I_Classic {

  class oCVisFX_MultiTarget : public oCVisualFX {
  public:
    zCLASS_DECLARATION( oCVisFX_MultiTarget )

    zCArray<oCVisualFX*> visList;

    void oCVisFX_MultiTarget_OnInit()                                   zCall( 0x00497770 );
    oCVisFX_MultiTarget()                                               zInit( oCVisFX_MultiTarget_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00498320 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004977B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00498110 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00498120 );
    virtual ~oCVisFX_MultiTarget()                                      zCall( 0x00497800 );
    virtual void Open()                                                 zCall( 0x00497920 );
    virtual void Init( zCArray<zCVob*> )                                zCall( 0x004979A0 );
    virtual void InvestNext()                                           zCall( 0x00497DF0 );
    virtual void SetLevel( int )                                        zCall( 0x00497960 );
    virtual void Cast( int )                                            zCall( 0x00497E30 );
    virtual void Stop( int )                                            zCall( 0x00497EA0 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )              zCall( 0x004977C0 );
    virtual int IsFinished()                                            zCall( 0x00498010 );
    virtual void SetByScript( zSTRING const& )                          zCall( 0x00497F10 );
    virtual void Reset()                                                zCall( 0x00497FD0 );
    virtual void SetDamage( float )                                     zCall( 0x00498060 );
    virtual void SetDamageType( int )                                   zCall( 0x004980C0 );

    // user API
    #include "oCVisFX_MultiTarget.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIS_FX__MULTI_TARGET_H__VER0__