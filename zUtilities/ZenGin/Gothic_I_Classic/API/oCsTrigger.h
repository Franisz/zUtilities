// Supported with union (c) 2018 Union team

#ifndef __OCS_TRIGGER_H__VER0__
#define __OCS_TRIGGER_H__VER0__

#include "zVobMisc.h"

namespace Gothic_I_Classic {

  class oCCSTrigger : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCCSTrigger )

    oCCSTrigger() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x004040B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004041F0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00404AF0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00404B00 );
    virtual ~oCCSTrigger()                                              zCall( 0x00404230 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x00404240 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x004048B0 );

    // user API
    #include "oCCSTrigger.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OCS_TRIGGER_H__VER0__