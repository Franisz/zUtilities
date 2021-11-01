// Supported with union (c) 2018-2021 Union team

#ifndef __OCS_PROPS_H__VER1__
#define __OCS_PROPS_H__VER1__

#include "zCCsProps.h"

namespace Gothic_I_Addon {

  // sizeof 88h
  class oCCSProps : public zCCSProps {
  public:
    zCLASS_DECLARATION( oCCSProps )

    int resultReaction; // sizeof 04h    offset 84h

    void oCCSProps_OnInit()                                             zCall( 0x00404510 );
    oCCSProps()                                                         zInit( oCCSProps_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00404480 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00404500 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00404570 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00404580 );
    virtual ~oCCSProps()                                                zCall( 0x00404560 );
    virtual int AcceptRole( zCCSRole*, zCVob* )                         zCall( 0x00404590 );
    virtual int CheckRole( zCCSRole*, zCVob* )                          zCall( 0x004045B0 );
    virtual int CheckRoleResult()                                       zCall( 0x00404600 );

    // user API
    #include "oCCSProps.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OCS_PROPS_H__VER1__