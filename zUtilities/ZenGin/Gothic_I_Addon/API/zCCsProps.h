// Supported with union (c) 2018-2021 Union team

#ifndef __ZCCS_PROPS_H__VER1__
#define __ZCCS_PROPS_H__VER1__

namespace Gothic_I_Addon {

  enum zTCS_SCReaction {
    SCR_RESULT_NOTHING,
    SCR_RESULT_END,
    SCR_RESULT_INTERRUPT
  };

  // sizeof 84h
  class zCCSProps : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSProps )

    enum zTCSRunBehaviour {
      RUN_ALWAYS,
      RUN_TIMES,
      RUN_PERHOUR,
      RUN_PERDAY
    };

    zSTRING name;                  // sizeof 14h    offset 24h
    int csLoop;                    // sizeof 04h    offset 38h
    int globalCutscene;            // sizeof 04h    offset 3Ch
    float distance;                // sizeof 04h    offset 40h
    int hasToBeTriggerd;           // sizeof 04h    offset 44h
    float range;                   // sizeof 04h    offset 48h
    int ignore;                    // sizeof 04h    offset 4Ch
    int numLockedBlocks;           // sizeof 04h    offset 50h
    zSTRING stageName;             // sizeof 14h    offset 54h
    zSTRING scriptFuncOnStop;      // sizeof 14h    offset 68h
    zTCSRunBehaviour runBehaviour; // sizeof 04h    offset 7Ch
    int runBehaviourValue;         // sizeof 04h    offset 80h

    void zCCSProps_OnInit()                                             zCall( 0x00423B80 );
    void SetName( zSTRING )                                             zCall( 0x00405F80 );
    zSTRING GetName()                                                   zCall( 0x00406C30 );
    zSTRING GetScriptFuncOnStop()                                       zCall( 0x00408150 );
    zCCSProps()                                                         zInit( zCCSProps_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00423B10 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00423D50 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00423E80 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00423F60 );
    virtual ~zCCSProps()                                                zCall( 0x00423D90 );
    virtual int AcceptRole( zCCSRole*, zCVob* )                         zCall( 0x00424830 );
    virtual int CheckRole( zCCSRole*, zCVob* )                          zCall( 0x00424850 );
    virtual int GetCheckRoleResult()                                    zCall( 0x004240C0 );
    virtual int CheckDistance( float )                                  zCall( 0x00424050 );
    virtual int CheckRange( float )                                     zCall( 0x00424090 );
    virtual void PrintDebugInfo()                                       zCall( 0x004240D0 );

    // user API
    #include "zCCSProps.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_PROPS_H__VER1__