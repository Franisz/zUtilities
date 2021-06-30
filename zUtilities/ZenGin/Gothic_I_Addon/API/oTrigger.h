// Supported with union (c) 2018 Union team

#ifndef __OTRIGGER_H__VER1__
#define __OTRIGGER_H__VER1__

#include "zVob.h"
#include "zVobMisc.h"
#include "zArchiver.h"

namespace Gothic_I_Addon {

  class oCTriggerChangeLevel : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerChangeLevel )

    zSTRING levelName;
    zSTRING startVob;

    void oCTriggerChangeLevel_OnInit()                                       zCall( 0x0043CBD0 );
    oCTriggerChangeLevel()                                                   zInit( oCTriggerChangeLevel_OnInit() );
    void SetLevelName( zSTRING const&, zSTRING const& )                      zCall( 0x0043D090 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x0043C7E0 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x0043C8E0 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x0043D2C0 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x0043D300 );
    virtual ~oCTriggerChangeLevel()                                          zCall( 0x0043CC60 );
    virtual void TriggerTarget( zCVob* )                                     zCall( 0x0043CD10 );
    virtual void UntriggerTarget( zCVob* )                                   zCall( 0x0043D080 );

    // user API
    #include "oCTriggerChangeLevel.inl"
  };

  class oCTriggerScript : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerScript )

    zSTRING scriptFunc;

    void oCTriggerScript_OnInit()                                       zCall( 0x0043D340 );
    oCTriggerScript()                                                   zInit( oCTriggerScript_OnInit() );
    void SetScriptFunc( zSTRING const&, int )                           zCall( 0x0043DAA0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0043CAF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0043CBC0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0043DBF0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0043DC20 );
    virtual ~oCTriggerScript()                                          zCall( 0x0043D3B0 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x0043D420 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x0043D7E0 );

    // user API
    #include "oCTriggerScript.inl"
  };

  class oCObjectGenerator : public zCVob {
  public:
    float speed;
    zSTRING objectName;

    void oCObjectGenerator_OnInit()          zCall( 0x0043DC50 );
    oCObjectGenerator()                      zInit( oCObjectGenerator_OnInit() );
    void SetObjectName( zSTRING const& )     zCall( 0x0043DD70 );
    void SetObjectSpeed( float )             zCall( 0x0043DEB0 );
    virtual void Archive( zCArchiver& )      zCall( 0x0043E1F0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0043E230 );
    virtual ~oCObjectGenerator()             zCall( 0x0043DD00 );
    virtual void OnTrigger( zCVob*, zCVob* ) zCall( 0x0043DEC0 );

    // user API
    #include "oCObjectGenerator.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OTRIGGER_H__VER1__