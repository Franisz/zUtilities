// Supported with union (c) 2018-2021 Union team

#ifndef __OTRIGGER_H__VER2__
#define __OTRIGGER_H__VER2__

#include "zVob.h"
#include "zVobMisc.h"
#include "zArchiver.h"

namespace Gothic_II_Classic {

  // sizeof 190h
  class oCTriggerChangeLevel : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerChangeLevel )

    zSTRING levelName; // sizeof 14h    offset 168h
    zSTRING startVob;  // sizeof 14h    offset 17Ch

    void oCTriggerChangeLevel_OnInit()                  zCall( 0x0043B6C0 );
    oCTriggerChangeLevel()                              zInit( oCTriggerChangeLevel_OnInit() );
    void SetLevelName( zSTRING const&, zSTRING const& ) zCall( 0x0043BB10 );
    static zCObject* _CreateNewInstance()               zCall( 0x0043B310 );
    virtual zCClassDef* _GetClassDef() const            zCall( 0x0043B3F0 );
    virtual void Archive( zCArchiver& )                 zCall( 0x0043BD40 );
    virtual void Unarchive( zCArchiver& )               zCall( 0x0043BD80 );
    virtual ~oCTriggerChangeLevel()                     zCall( 0x0043B750 );
    virtual void TriggerTarget( zCVob* )                zCall( 0x0043B7F0 );
    virtual void UntriggerTarget( zCVob* )              zCall( 0x0043BB00 );

    // user API
    #include "oCTriggerChangeLevel.inl"
  };

  // sizeof 17Ch
  class oCTriggerScript : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCTriggerScript )

    zSTRING scriptFunc; // sizeof 14h    offset 168h

    void oCTriggerScript_OnInit()             zCall( 0x0043BDC0 );
    oCTriggerScript()                         zInit( oCTriggerScript_OnInit() );
    void SetScriptFunc( zSTRING const&, int ) zCall( 0x0043C480 );
    static zCObject* _CreateNewInstance()     zCall( 0x0043B5F0 );
    virtual zCClassDef* _GetClassDef() const  zCall( 0x0043B6B0 );
    virtual void Archive( zCArchiver& )       zCall( 0x0043C5D0 );
    virtual void Unarchive( zCArchiver& )     zCall( 0x0043C600 );
    virtual ~oCTriggerScript()                zCall( 0x0043BE30 );
    virtual void TriggerTarget( zCVob* )      zCall( 0x0043BE90 );
    virtual void UntriggerTarget( zCVob* )    zCall( 0x0043C1F0 );

    // user API
    #include "oCTriggerScript.inl"
  };

  // sizeof 138h
  class oCObjectGenerator : public zCVob {
  public:
    float speed;        // sizeof 04h    offset 120h
    zSTRING objectName; // sizeof 14h    offset 124h

    void oCObjectGenerator_OnInit()          zCall( 0x0043C630 );
    oCObjectGenerator()                      zInit( oCObjectGenerator_OnInit() );
    void SetObjectName( zSTRING const& )     zCall( 0x0043C740 );
    void SetObjectSpeed( float )             zCall( 0x0043C880 );
    virtual void Archive( zCArchiver& )      zCall( 0x0043CB70 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0043CBB0 );
    virtual ~oCObjectGenerator()             zCall( 0x0043C6E0 );
    virtual void OnTrigger( zCVob*, zCVob* ) zCall( 0x0043C890 );

    // user API
    #include "oCObjectGenerator.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OTRIGGER_H__VER2__