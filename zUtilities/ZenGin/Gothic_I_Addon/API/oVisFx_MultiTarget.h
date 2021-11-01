// Supported with union (c) 2018-2021 Union team

#ifndef __OVIS_FX__MULTI_TARGET_H__VER1__
#define __OVIS_FX__MULTI_TARGET_H__VER1__

#include "oVisFx.h"

namespace Gothic_I_Addon {

  // sizeof 5D4h
  class oCVisFX_MultiTarget : public oCVisualFX {
  public:
    zCLASS_DECLARATION( oCVisFX_MultiTarget )

    zCArray<oCVisualFX*> visList; // sizeof 0Ch    offset 5C8h

    void oCVisFX_MultiTarget_OnInit()                                   zCall( 0x004A47A0 );
    oCVisFX_MultiTarget()                                               zInit( oCVisFX_MultiTarget_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x004A53C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004A47E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004A51A0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004A51B0 );
    virtual ~oCVisFX_MultiTarget()                                      zCall( 0x004A4830 );
    virtual void Open()                                                 zCall( 0x004A4950 );
    virtual void Init( zCArray<zCVob*> )                                zCall( 0x004A49D0 );
    virtual void InvestNext()                                           zCall( 0x004A4E70 );
    virtual void SetLevel( int )                                        zCall( 0x004A4990 );
    virtual void Cast( int )                                            zCall( 0x004A4EB0 );
    virtual void Stop( int )                                            zCall( 0x004A4F20 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )              zCall( 0x004A47F0 );
    virtual int IsFinished()                                            zCall( 0x004A50A0 );
    virtual void SetByScript( zSTRING const& )                          zCall( 0x004A4F90 );
    virtual void Reset()                                                zCall( 0x004A5060 );
    virtual void SetDamage( float )                                     zCall( 0x004A50F0 );
    virtual void SetDamageType( int )                                   zCall( 0x004A5150 );

    // user API
    #include "oCVisFX_MultiTarget.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIS_FX__MULTI_TARGET_H__VER1__