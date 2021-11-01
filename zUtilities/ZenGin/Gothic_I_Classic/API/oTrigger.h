// Supported with union (c) 2018-2021 Union team

#ifndef __OTRIGGER_H__VER0__
#define __OTRIGGER_H__VER0__

#include "zVob.h"
#include "zVobMisc.h"
#include "zArchiver.h"

namespace Gothic_I_Classic {

  // sizeof 170h
  class oCTriggerChangeLevel : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerChangeLevel )

    zSTRING levelName; // sizeof 14h    offset 148h
    zSTRING startVob;  // sizeof 14h    offset 15Ch

    void oCTriggerChangeLevel_OnInit()                                       zCall( 0x00438240 );
    oCTriggerChangeLevel()                                                   zInit( oCTriggerChangeLevel_OnInit() );
    void SetLevelName( zSTRING const&, zSTRING const& )                      zCall( 0x004386B0 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x00437E60 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x00437F60 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x004388E0 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x00438920 );
    virtual ~oCTriggerChangeLevel()                                          zCall( 0x004382D0 );
    virtual void TriggerTarget( zCVob* )                                     zCall( 0x00438370 );
    virtual void UntriggerTarget( zCVob* )                                   zCall( 0x004386A0 );

    // user API
    #include "oCTriggerChangeLevel.inl"
  };

  // sizeof 15Ch
  class oCTriggerScript : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerScript )

    zSTRING scriptFunc; // sizeof 14h    offset 148h

    void oCTriggerScript_OnInit()                                       zCall( 0x00438960 );
    oCTriggerScript()                                                   zInit( oCTriggerScript_OnInit() );
    void SetScriptFunc( zSTRING const&, int )                           zCall( 0x00439020 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00438160 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00438230 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00439170 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004391A0 );
    virtual ~oCTriggerScript()                                          zCall( 0x004389D0 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x00438A30 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x00438D90 );

    // user API
    #include "oCTriggerScript.inl"
  };

  // sizeof 118h
  class oCObjectGenerator : public zCVob {
  public:
    float speed;        // sizeof 04h    offset 100h
    zSTRING objectName; // sizeof 14h    offset 104h

    void oCObjectGenerator_OnInit()          zCall( 0x004391D0 );
    oCObjectGenerator()                      zInit( oCObjectGenerator_OnInit() );
    void SetObjectName( zSTRING const& )     zCall( 0x004392E0 );
    void SetObjectSpeed( float )             zCall( 0x00439420 );
    virtual void Archive( zCArchiver& )      zCall( 0x00439720 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00439760 );
    virtual ~oCObjectGenerator()             zCall( 0x00439280 );
    virtual void OnTrigger( zCVob*, zCVob* ) zCall( 0x00439430 );

    // user API
    #include "oCObjectGenerator.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OTRIGGER_H__VER0__