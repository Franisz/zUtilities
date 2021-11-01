// Supported with union (c) 2018-2021 Union team

#ifndef __OVIS_FX__MULTI_TARGET_H__VER3__
#define __OVIS_FX__MULTI_TARGET_H__VER3__

#include "oVisFx.h"

namespace Gothic_II_Addon {

  // sizeof 61Ch
  class oCVisFX_MultiTarget : public oCVisualFX {
  public:
    zCLASS_DECLARATION( oCVisFX_MultiTarget )

    zCArray<oCVisualFX*> visList; // sizeof 0Ch    offset 610h

    void oCVisFX_MultiTarget_OnInit()                      zCall( 0x0049EB40 );
    oCVisFX_MultiTarget()                                  zInit( oCVisFX_MultiTarget_OnInit() );
    static zCObject* _CreateNewInstance()                  zCall( 0x0049F750 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x0049EB80 );
    virtual void Archive( zCArchiver& )                    zCall( 0x0049F540 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x0049F550 );
    virtual ~oCVisFX_MultiTarget()                         zCall( 0x0049EBD0 );
    virtual void Open()                                    zCall( 0x0049ECF0 );
    virtual void Init( zCArray<zCVob*> )                   zCall( 0x0049ED80 );
    virtual void InvestNext()                              zCall( 0x0049F220 );
    virtual void SetLevel( int )                           zCall( 0x0049ED30 );
    virtual void Cast( int )                               zCall( 0x0049F260 );
    virtual void Stop( int )                               zCall( 0x0049F2D0 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* ) zCall( 0x0049EB90 );
    virtual int IsFinished()                               zCall( 0x0049F440 );
    virtual void SetByScript( zSTRING const& )             zCall( 0x0049F340 );
    virtual void Reset()                                   zCall( 0x0049F400 );
    virtual void SetDamage( float )                        zCall( 0x0049F490 );
    virtual void SetDamageType( int )                      zCall( 0x0049F4F0 );

    // user API
    #include "oCVisFX_MultiTarget.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIS_FX__MULTI_TARGET_H__VER3__