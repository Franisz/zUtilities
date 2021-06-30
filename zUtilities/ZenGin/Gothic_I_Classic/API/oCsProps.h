// Supported with union (c) 2018 Union team

#ifndef __OCS_PROPS_H__VER0__
#define __OCS_PROPS_H__VER0__

#include "zCCsProps.h"

namespace Gothic_I_Classic {

  class oCCSProps : public zCCSProps {
  public:
    zCLASS_DECLARATION( oCCSProps )

    int resultReaction;

    void oCCSProps_OnInit()                                             zCall( 0x00403DA0 );
    oCCSProps()                                                         zInit( oCCSProps_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00403D10 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00403D90 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00403E00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00403E10 );
    virtual ~oCCSProps()                                                zCall( 0x00403DF0 );
    virtual int AcceptRole( zCCSRole*, zCVob* )                         zCall( 0x00403E20 );
    virtual int CheckRole( zCCSRole*, zCVob* )                          zCall( 0x00403E30 );
    virtual int CheckRoleResult()                                       zCall( 0x00403E80 );

    // user API
    #include "oCCSProps.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OCS_PROPS_H__VER0__