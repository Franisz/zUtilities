// Supported with union (c) 2018 Union team

#ifndef __OCS_PROPS_H__VER3__
#define __OCS_PROPS_H__VER3__

#include "zCCsProps.h"

namespace Gothic_II_Addon {

  class oCCSProps : public zCCSProps {
  public:
    zCLASS_DECLARATION( oCCSProps )

    int resultReaction;

    void oCCSProps_OnInit()                     zCall( 0x00403F00 );
    oCCSProps()                                 zInit( oCCSProps_OnInit() );
    static zCObject* _CreateNewInstance()       zCall( 0x00403E90 );
    virtual zCClassDef* _GetClassDef() const    zCall( 0x00403EF0 );
    virtual void Archive( zCArchiver& )         zCall( 0x00403F60 );
    virtual void Unarchive( zCArchiver& )       zCall( 0x00403F70 );
    virtual ~oCCSProps()                        zCall( 0x00403F50 );
    virtual int AcceptRole( zCCSRole*, zCVob* ) zCall( 0x00403F80 );
    virtual int CheckRole( zCCSRole*, zCVob* )  zCall( 0x00403F90 );
    virtual int CheckRoleResult()               zCall( 0x00403FE0 );

    // user API
    #include "oCCSProps.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OCS_PROPS_H__VER3__