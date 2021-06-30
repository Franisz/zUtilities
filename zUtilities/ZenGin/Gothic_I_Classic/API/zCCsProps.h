// Supported with union (c) 2018 Union team

#ifndef __ZCCS_PROPS_H__VER0__
#define __ZCCS_PROPS_H__VER0__

namespace Gothic_I_Classic {

  enum zTCS_SCReaction {
    SCR_RESULT_NOTHING,
    SCR_RESULT_END,
    SCR_RESULT_INTERRUPT
  };

  class zCCSProps : public zCObject {
  public:
    zCLASS_DECLARATION( zCCSProps )

    enum zTCSRunBehaviour {
      RUN_ALWAYS,
      RUN_TIMES,
      RUN_PERHOUR,
      RUN_PERDAY
    };

    zSTRING name;
    int csLoop;
    int globalCutscene;
    float distance;
    int hasToBeTriggerd;
    float range;
    int ignore;
    int numLockedBlocks;
    zSTRING stageName;
    zSTRING scriptFuncOnStop;
    zTCSRunBehaviour runBehaviour;
    int runBehaviourValue;

    void zCCSProps_OnInit()                                             zCall( 0x00421720 );
    zSTRING GetName()                                                   zCall( 0x00406090 );
    zSTRING GetScriptFuncOnStop()                                       zCall( 0x00407400 );
    zCCSProps()                                                         zInit( zCCSProps_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x004216B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004218E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004219E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00421AC0 );
    virtual ~zCCSProps()                                                zCall( 0x00421920 );
    virtual int AcceptRole( zCCSRole*, zCVob* )                         zCall( 0x004222B0 );
    virtual int CheckRole( zCCSRole*, zCVob* )                          zCall( 0x004222C0 );
    virtual int GetCheckRoleResult()                                    zCall( 0x00421C20 );
    virtual int CheckDistance( float )                                  zCall( 0x00421BB0 );
    virtual int CheckRange( float )                                     zCall( 0x00421BF0 );
    virtual void PrintDebugInfo()                                       zCall( 0x00421C30 );

    // user API
    #include "zCCSProps.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCCS_PROPS_H__VER0__