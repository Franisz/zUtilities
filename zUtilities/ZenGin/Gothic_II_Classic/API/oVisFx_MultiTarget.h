// Supported with union (c) 2018 Union team

#ifndef __OVIS_FX__MULTI_TARGET_H__VER2__
#define __OVIS_FX__MULTI_TARGET_H__VER2__

#include "oVisFx.h"

namespace Gothic_II_Classic {

  class oCVisFX_MultiTarget : public oCVisualFX {
  public:
    zCLASS_DECLARATION( oCVisFX_MultiTarget )

    zCArray<oCVisualFX*> visList;

    void oCVisFX_MultiTarget_OnInit()                      zCall( 0x0049C7F0 );
    oCVisFX_MultiTarget()                                  zInit( oCVisFX_MultiTarget_OnInit() );
    static zCObject* _CreateNewInstance()                  zCall( 0x0049D3F0 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x0049C830 );
    virtual void Archive( zCArchiver& )                    zCall( 0x0049D1E0 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x0049D1F0 );
    virtual ~oCVisFX_MultiTarget()                         zCall( 0x0049C880 );
    virtual void Open()                                    zCall( 0x0049C9A0 );
    virtual void Init( zCArray<zCVob*> )                   zCall( 0x0049CA20 );
    virtual void InvestNext()                              zCall( 0x0049CEC0 );
    virtual void SetLevel( int )                           zCall( 0x0049C9E0 );
    virtual void Cast( int )                               zCall( 0x0049CF00 );
    virtual void Stop( int )                               zCall( 0x0049CF70 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* ) zCall( 0x0049C840 );
    virtual int IsFinished()                               zCall( 0x0049D0E0 );
    virtual void SetByScript( zSTRING const& )             zCall( 0x0049CFE0 );
    virtual void Reset()                                   zCall( 0x0049D0A0 );
    virtual void SetDamage( float )                        zCall( 0x0049D130 );
    virtual void SetDamageType( int )                      zCall( 0x0049D190 );

    // user API
    #include "oCVisFX_MultiTarget.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIS_FX__MULTI_TARGET_H__VER2__