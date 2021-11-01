// Supported with union (c) 2018-2021 Union team

#ifndef __OCS_TRIGGER_H__VER2__
#define __OCS_TRIGGER_H__VER2__

#include "zVobMisc.h"

namespace Gothic_II_Classic {

  // sizeof 168h
  class oCCSTrigger : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCCSTrigger )

    oCCSTrigger() {}
    static zCObject* _CreateNewInstance()    zCall( 0x00404210 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00404330 );
    virtual void Archive( zCArchiver& )      zCall( 0x00404C30 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00404C40 );
    virtual ~oCCSTrigger()                   zCall( 0x00404370 );
    virtual void TriggerTarget( zCVob* )     zCall( 0x00404380 );
    virtual void UntriggerTarget( zCVob* )   zCall( 0x004049F0 );

    // user API
    #include "oCCSTrigger.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OCS_TRIGGER_H__VER2__