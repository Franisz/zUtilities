// Supported with union (c) 2018-2021 Union team

#ifdef __G2A
#ifndef __VFTABLE_STRUCTS_H__VER3__
#define __VFTABLE_STRUCTS_H__VER3__

// permanent memory unlocker
#define MemUnlock static SystemPack::TMemUnlocker unlocker( (void*)GetAddress(), GetFuncsNum() * 4, True )

namespace Gothic_II_Addon {
  struct vfunc {
    union {
      uint address;
      void* pointer;
    };

    vfunc& operator = ( const TInstance& instance ) {
      pointer = instance;
      return *this;
    }

    operator uint () {
      return address;
    }

    operator void* () {
      return pointer;
    }
  };


  struct vftable_zSTRING {
    union {
      vfunc array[1];
      group {
        vfunc f00_vector_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082E6F0;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zSTRING& GetTable() {
      MemUnlock;
      return *(vftable_zSTRING*)GetAddress();
    }
  };


  struct vftable_zCCSCamera_EventMsgActivate {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCCSCamera_EventMsgActivate  ?_GetClassDef@zCCSCamera_EventMsgActivate@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCCSCamera_EventMsgActivate  ?Archive@zCCSCamera_EventMsgActivate@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCCSCamera_EventMsgActivate  ?Unarchive@zCCSCamera_EventMsgActivate@@MAEXAAVzCArchiver@@@Z
        vfunc f03_vector_destructor;     // from base                         
        vfunc f04_IsOverlay;             // from zCEventMessage               ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage               ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage               ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage               ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage               ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCCSCamera_EventMsgActivate  ?Delete@zCCSCamera_EventMsgActivate@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage               ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCCSCamera_EventMsgActivate  ?IsDeleted@zCCSCamera_EventMsgActivate@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage               ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage               ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCCSCamera_EventMsgActivate  ?MD_GetNumOfSubTypes@zCCSCamera_EventMsgActivate@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCCSCamera_EventMsgActivate  ?MD_GetSubTypeString@zCCSCamera_EventMsgActivate@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCCSCamera_EventMsgActivate  ?MD_GetVobRefName@zCCSCamera_EventMsgActivate@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCCSCamera_EventMsgActivate  ?MD_SetVobRefName@zCCSCamera_EventMsgActivate@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCCSCamera_EventMsgActivate  ?MD_SetVobParam@zCCSCamera_EventMsgActivate@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage               ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage               ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage               ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage               ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E6FC;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCCSCamera_EventMsgActivate& GetTable() {
      MemUnlock;
      return *(vftable_zCCSCamera_EventMsgActivate*)GetAddress();
    }
  };


  struct vftable_zCEventMessage {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventMessage  ?_GetClassDef@zCEventMessage@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMessage  ?Archive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMessage  ?Unarchive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from zCEventMessage  ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage  ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage  ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage  ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage  ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage  ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage  ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage  ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventMessage  ?MD_GetNumOfSubTypes@zCEventMessage@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventMessage  ?MD_GetSubTypeString@zCEventMessage@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E75C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventMessage& GetTable() {
      MemUnlock;
      return *(vftable_zCEventMessage*)GetAddress();
    }
  };


  struct vftable_zCEventCore {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventCore     ?_GetClassDef@zCEventCore@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventCore     ?Archive@zCEventCore@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventCore     ?Unarchive@zCEventCore@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from zCEventMessage  ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventCore     ?IsNetRelevant@zCEventCore@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage  ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage  ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage  ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage  ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage  ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage  ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventCore     ?MD_GetNumOfSubTypes@zCEventCore@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventCore     ?MD_GetSubTypeString@zCEventCore@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventCore     ?Pack@zCEventCore@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventCore     ?Unpack@zCEventCore@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E7BC;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventCore& GetTable() {
      MemUnlock;
      return *(vftable_zCEventCore*)GetAddress();
    }
  };


  struct vftable_oCCSManager {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;           // from oCCSManager  ?_GetClassDef@oCCSManager@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCCSManager  ?Archive@zCCSManager@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCCSManager  ?Unarchive@zCCSManager@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base         
        vfunc f04_CreateMessage;         // from oCCSManager  ?CreateMessage@oCCSManager@@UAEPAVzCEventMessage@@H@Z
        vfunc f05_CreateOuMessage;       // from oCCSManager  ?CreateOuMessage@oCCSManager@@UAEPAVzCEventMessage@@XZ
        vfunc f06_CreateCutscenePlayer;  // from oCCSManager  ?CreateCutscenePlayer@oCCSManager@@UAEPAVzCCSPlayer@@PAVzCWorld@@@Z
        vfunc f07_CreateProperties;      // from oCCSManager  ?CreateProperties@oCCSManager@@UAEPAVzCCSProps@@XZ
        vfunc f08_RemoveCutscenePlayer;  // from zCCSManager  ?RemoveCutscenePlayer@zCCSManager@@UAEXPAVzCCSPlayer@@@Z
        vfunc f09_LibIsLoaded;           // from zCCSManager  ?LibIsLoaded@zCCSManager@@UAEHXZ
        vfunc f10_LibGet;                // from zCCSManager  ?LibGet@zCCSManager@@UAEPAVzCCSBlock@@H@Z
        vfunc f11_LibGetFirst;           // from zCCSManager  ?LibGetFirst@zCCSManager@@UAEPAVzCCSBlock@@AAH@Z
        vfunc f12_LibGetFirst;           // from zCCSManager  ?LibGetFirst@zCCSManager@@UAEPAVzCCSBlock@@XZ
        vfunc f13_LibGetNext;            // from zCCSManager  ?LibGetNext@zCCSManager@@UAEPAVzCCSBlock@@AAH@Z
        vfunc f14_LibGetNext;            // from zCCSManager  ?LibGetNext@zCCSManager@@UAEPAVzCCSBlock@@XZ
        vfunc f15_LibAddOU;              // from zCCSManager  ?LibAddOU@zCCSManager@@UAEHPAVzCCSBlock@@@Z
        vfunc f16_LibDelOU;              // from zCCSManager  ?LibDelOU@zCCSManager@@UAEXH@Z
        vfunc f17_LibNullOU;             // from zCCSManager  ?LibNullOU@zCCSManager@@UAEXH@Z
        vfunc f18_LibLoad;               // from zCCSManager  ?LibLoad@zCCSManager@@UAEXH@Z
        vfunc f19_LibStore;              // from zCCSManager  ?LibStore@zCCSManager@@UAEXH@Z
        vfunc f20_LibValidateOU;         // from zCCSManager  ?LibValidateOU@zCCSManager@@UAEHAAVzSTRING@@@Z
        vfunc f21_LibValidateOU;         // from zCCSManager  ?LibValidateOU@zCCSManager@@UAEHH@Z
        vfunc f22_LibGetSvmModuleName;   // from zCCSManager  ?LibGetSvmModuleName@zCCSManager@@UAE?AVzSTRING@@H@Z
        vfunc f23_LibIsSvmModuleRunning; // from zCCSManager  ?LibIsSvmModuleRunning@zCCSManager@@UAEHH@Z
        vfunc f24_LibSvmModuleStart;     // from zCCSManager  ?LibSvmModuleStart@zCCSManager@@UAEHH@Z
        vfunc f25_LibSvmModuleStop;      // from zCCSManager  ?LibSvmModuleStop@zCCSManager@@UAEHH@Z
        vfunc f26_InsertPlayerInList;    // from zCCSManager  ?InsertPlayerInList@zCCSManager@@MAEXPAVzCCSPlayer@@@Z
        vfunc f27_RemovePlayerFromList;  // from zCCSManager  ?RemovePlayerFromList@zCCSManager@@MAEXPAVzCCSPlayer@@@Z
        vfunc f28_LibCheckLoaded;        // from zCCSManager  ?LibCheckLoaded@zCCSManager@@MAEXH@Z
        vfunc f29_PoolFindItem;          // from zCCSManager  ?PoolFindItem@zCCSManager@@MAEPAVzCCSPoolItem@@AAVzSTRING@@@Z
        vfunc f30_PoolInsertItem;        // from zCCSManager  ?PoolInsertItem@zCCSManager@@MAEXPAVzCCSPoolItem@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E81C;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_oCCSManager& GetTable() {
      MemUnlock;
      return *(vftable_oCCSManager*)GetAddress();
    }
  };


  struct vftable_zCObject {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCObject  ?_GetClassDef@zCObject@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base      
      } names;
    };

    static uint GetAddress() {
      return 0x0082E89C;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCObject*)GetAddress();
    }
  };


  struct vftable_oCCSPlayer_for_zCCSDebugger {
    union {
      vfunc array[8];
      group {
        vfunc f00_vector_destructor;   // from base        
        vfunc f01_CSDB_BeginSyncBlock; // from zCCSPlayer  ?CSDB_BeginSyncBlock@zCCSPlayer@@UAEXPAVzCCSSyncBlock@@@Z
        vfunc f02_CSDB_BeginAtomBlock; // from zCCSPlayer  ?CSDB_BeginAtomBlock@zCCSPlayer@@UAEXPAVzCCSBlockBase@@@Z
        vfunc f03_CSDB_EndAtomBlock;   // from zCCSPlayer  ?CSDB_EndAtomBlock@zCCSPlayer@@UAEXPAVzCCSBlockBase@@@Z
        vfunc f04_CSDB_Error;          // from zCCSPlayer  ?CSDB_Error@zCCSPlayer@@UAEXPAVzCCSBlockBase@@AAVzSTRING@@@Z
        vfunc f05_CSDB_Warning;        // from zCCSPlayer  ?CSDB_Warning@zCCSPlayer@@UAEXPAVzCCSBlockBase@@AAVzSTRING@@@Z
        vfunc f06_CSDB_StartPlaying;   // from zCCSPlayer  ?CSDB_StartPlaying@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
        vfunc f07_CSDB_Stop;           // from zCCSPlayer  ?CSDB_Stop@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E8DC;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_oCCSPlayer_for_zCCSDebugger& GetTable() {
      MemUnlock;
      return *(vftable_oCCSPlayer_for_zCCSDebugger*)GetAddress();
    }
  };


  struct vftable_oCCSPlayer_for_zCObject {
    union {
      vfunc array[21];
      group {
        vfunc f00_GetClassDef;         // from oCCSPlayer  ?_GetClassDef@oCCSPlayer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCCSPlayer  ?Archive@zCCSPlayer@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCCSPlayer  ?Unarchive@zCCSPlayer@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base        
        vfunc f04_CreateNewOutputUnit; // from zCCSPlayer  ?CreateNewOutputUnit@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@HPAVzCVob@@@Z
        vfunc f05_StartOutputUnit;     // from zCCSPlayer  ?StartOutputUnit@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@HPAVzCVob@@@Z
        vfunc f06_StartCutscene;       // from zCCSPlayer  ?StartCutscene@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@PAVzCCutscene@@PAVzCVob@@VzSTRING@@@Z
        vfunc f07_StartCutscene;       // from zCCSPlayer  ?StartCutscene@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@AAVzSTRING@@PAVzCVob@@@Z
        vfunc f08_ForgetCutscene;      // from zCCSPlayer  ?ForgetCutscene@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
        vfunc f09_ResetCutscenePlayer; // from zCCSPlayer  ?ResetCutscenePlayer@zCCSPlayer@@UAEXXZ
        vfunc f10_StopAllCutscenes;    // from zCCSPlayer  ?StopAllCutscenes@zCCSPlayer@@UAEHPAVzCVob@@@Z
        vfunc f11_StopAllOutputUnits;  // from zCCSPlayer  ?StopAllOutputUnits@zCCSPlayer@@UAEHPAVzCVob@@@Z
        vfunc f12_InsertCutscene;      // from zCCSPlayer  ?InsertCutscene@zCCSPlayer@@UAEXPAVzCCSCutsceneContext@@@Z
        vfunc f13_RemoveCutscene;      // from zCCSPlayer  ?RemoveCutscene@zCCSPlayer@@UAEXPAVzCCSCutsceneContext@@@Z
        vfunc f14_OnCSTrigger;         // from zCCSPlayer  ?OnCSTrigger@zCCSPlayer@@UAEXAAVzSTRING@@PAVzCVob@@@Z
        vfunc f15_OnCSUntrigger;       // from zCCSPlayer  ?OnCSUntrigger@zCCSPlayer@@UAEXAAVzSTRING@@PAVzCVob@@@Z
        vfunc f16_SetOwnerWorld;       // from zCCSPlayer  ?SetOwnerWorld@zCCSPlayer@@UAEXPAVzCWorld@@@Z
        vfunc f17_SetOwnerManager;     // from zCCSPlayer  ?SetOwnerManager@zCCSPlayer@@UAEXPAVzCCSManager@@@Z
        vfunc f18_Process;             // from zCCSPlayer  ?Process@zCCSPlayer@@UAEXXZ
        vfunc f19_ProcessCutscene;     // from oCCSPlayer  ?ProcessCutscene@oCCSPlayer@@MAEXPAVzCCSCutsceneContext@@ABVzVEC3@@@Z
        vfunc f20_ProcessList;         // from zCCSPlayer  ?ProcessList@zCCSPlayer@@MAEXABVzVEC3@@HHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E904;
    }

    static uint GetFuncsNum() {
      return 21;
    }

    static vftable_oCCSPlayer_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCCSPlayer_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCCSProps {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;        // from oCCSProps  ?_GetClassDef@oCCSProps@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;            // from oCCSProps  ?Archive@oCCSProps@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;          // from oCCSProps  ?Unarchive@oCCSProps@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;  // from base       
        vfunc f04_AcceptRole;         // from oCCSProps  ?AcceptRole@oCCSProps@@UAEHPAVzCCSRole@@PAVzCVob@@@Z
        vfunc f05_CheckRole;          // from oCCSProps  ?CheckRole@oCCSProps@@UAEHPAVzCCSRole@@PAVzCVob@@@Z
        vfunc f06_GetCheckRoleResult; // from zCCSProps  ?GetCheckRoleResult@zCCSProps@@UAEHXZ
        vfunc f07_CheckDistance;      // from zCCSProps  ?CheckDistance@zCCSProps@@UAEHM@Z
        vfunc f08_CheckRange;         // from zCCSProps  ?CheckRange@zCCSProps@@UAEHM@Z
        vfunc f09_PrintDebugInfo;     // from zCCSProps  ?PrintDebugInfo@zCCSProps@@UAEXXZ
        vfunc f10_CheckRoleResult;    // from oCCSProps  ?CheckRoleResult@oCCSProps@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082E970;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_oCCSProps& GetTable() {
      MemUnlock;
      return *(vftable_oCCSProps*)GetAddress();
    }
  };


  struct vftable_oCCSTrigger {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from oCCSTrigger    ?_GetClassDef@oCCSTrigger@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCCSTrigger    ?Archive@oCCSTrigger@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCCSTrigger    ?Unarchive@oCCSTrigger@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCTrigger      ?OnTrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTrigger      ?OnUntrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTrigger      ?OnTouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger      ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger      ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger      ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger      ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase  ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from oCCSTrigger    ?TriggerTarget@oCCSTrigger@@UAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from oCCSTrigger    ?UntriggerTarget@oCCSTrigger@@UAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger      ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082E9B4;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_oCCSTrigger& GetTable() {
      MemUnlock;
      return *(vftable_oCCSTrigger*)GetAddress();
    }
  };


  struct vftable_zCCSCutsceneContext {
    union {
      vfunc array[53];
      group {
        vfunc f00_GetClassDef;        // from zCCSCutsceneContext  ?_GetClassDef@zCCSCutsceneContext@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;            // from zCCSCutsceneContext  ?Archive@zCCSCutsceneContext@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;          // from zCCSCutsceneContext  ?Unarchive@zCCSCutsceneContext@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;  // from base                 
        vfunc f04_GetChild;           // from zCCSBlock            ?GetChild@zCCSBlock@@UAEPAVzCCSBlockBase@@H@Z
        vfunc f05_OrganizeRoles;      // from zCCSBlock            ?OrganizeRoles@zCCSBlock@@UAEXAAV?$zCArray@PAVzCVob@@@@AAV?$zCArray@PAVzCCSRole@@@@@Z
        vfunc f06_GetRoleName;        // from zCCSBlock            ?GetRoleName@zCCSBlock@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;        // from zCCSBlock            ?SetRoleName@zCCSBlock@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;               // from zCCSBlock            ?Play@zCCSBlock@@UAEXPAVzCEventManager@@MM@Z
        vfunc f09_Play;               // from zCCSBlock            ?Play@zCCSBlock@@UAEXPAVzCEventManager@@@Z
        vfunc f10_Play;               // from zCCSBlock            ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@MM@Z
        vfunc f11_Play;               // from zCCSBlock            ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f12_GetMinTime;         // from zCCSBlock            ?GetMinTime@zCCSBlock@@UAEMXZ
        vfunc f13_IsFinished;         // from zCCSBlock            ?IsFinished@zCCSBlock@@UAEHPAVzCEventManager@@@Z
        vfunc f14_IsFinished;         // from zCCSBlock            ?IsFinished@zCCSBlock@@UAEHABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f15_GetCommand;         // from zCCSBlockBase        ?GetCommand@zCCSBlockBase@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;           // from zCCutscene           ?NewBlock@zCCutscene@@UAEHHH@Z
        vfunc f17_InsertBlock;        // from zCCSBlock            ?InsertBlock@zCCSBlock@@UAEXPAVzCCSBlockBase@@H@Z
        vfunc f18_DeleteChild;        // from zCCSBlock            ?DeleteChild@zCCSBlock@@UAEXH@Z
        vfunc f19_GetNumOfChilds;     // from zCCSBlock            ?GetNumOfChilds@zCCSBlock@@UAEHXZ
        vfunc f20_GetRoleNumOfChild;  // from zCCSBlockBase        ?GetRoleNumOfChild@zCCSBlockBase@@UAEHH@Z
        vfunc f21_BlockCorrection;    // from zCCSBlock            ?BlockCorrection@zCCSBlock@@UAEXXZ
        vfunc f22_BlockAsFocus;       // from zCCSBlock            ?BlockAsFocus@zCCSBlock@@UAEXH@Z
        vfunc f23_GetChildPos;        // from zCCSBlock            ?GetChildPos@zCCSBlock@@UAEPAVzCCSBlockPosition@@H@Z
        vfunc f24_AddMainRole;        // from zCCSCutsceneContext  ?AddMainRole@zCCSCutsceneContext@@UAEHPAVzCVob@@@Z
        vfunc f25_AddRoleOU;          // from zCCutscene           ?AddRoleOU@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f26_RemoveRole;         // from zCCutscene           ?RemoveRole@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f27_SetOwnerPlayer;     // from zCCutscene           ?SetOwnerPlayer@zCCutscene@@UAEXPAVzCCSPlayer@@@Z
        vfunc f28_Reset;              // from zCCutscene           ?Reset@zCCutscene@@UAEXXZ
        vfunc f29_ClearCutscene;      // from zCCutscene           ?ClearCutscene@zCCutscene@@UAEXXZ
        vfunc f30_StartPlaying;       // from zCCSCutsceneContext  ?StartPlaying@zCCSCutsceneContext@@UAEHXZ
        vfunc f31_Stop;               // from zCCSCutsceneContext  ?Stop@zCCSCutsceneContext@@UAEXXZ
        vfunc f32_StopRole;           // from zCCutscene           ?StopRole@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f33_Interrupt;          // from zCCSCutsceneContext  ?Interrupt@zCCSCutsceneContext@@UAEXXZ
        vfunc f34_ResumeActBlock;     // from zCCutscene           ?ResumeActBlock@zCCutscene@@UAEHXZ
        vfunc f35_PlaySub;            // from zCCutscene           ?PlaySub@zCCutscene@@UAEHMM@Z
        vfunc f36_NewCS;              // from zCCutscene           ?NewCS@zCCutscene@@UAEXPAVzCCSManager@@@Z
        vfunc f37_IsCutscene;         // from zCCSCutsceneContext  ?IsCutscene@zCCSCutsceneContext@@UAEHXZ
        vfunc f38_IsFinished;         // from zCCSCutsceneContext  ?IsFinished@zCCSCutsceneContext@@UAEHXZ
        vfunc f39_PrintDebugInfo;     // from zCCSCutsceneContext  ?PrintDebugInfo@zCCSCutsceneContext@@UAEXABVzSTRING@@@Z
        vfunc f40_CheckRoles;         // from zCCutscene           ?CheckRoles@zCCutscene@@MAEHAAH@Z
        vfunc f41_CSCheck;            // from zCCutscene           ?CSCheck@zCCutscene@@MAEHAAH@Z
        vfunc f42_GetStage;           // from zCCSCutsceneContext  ?GetStage@zCCSCutsceneContext@@MAEPAVzCVob@@XZ
        vfunc f43_LoadStage;          // from zCCutscene           ?LoadStage@zCCutscene@@MAEPAVzCVob@@XZ
        vfunc f44_CatchPlayer;        // from zCCSCutsceneContext  ?CatchPlayer@zCCSCutsceneContext@@EAEPAVzCVob@@PAV2@@Z
        vfunc f45_PrepareBlock;       // from zCCSCutsceneContext  ?PrepareBlock@zCCSCutsceneContext@@MAEXXZ
        vfunc f46_SetPoolItem;        // from zCCSCutsceneContext  ?SetPoolItem@zCCSCutsceneContext@@UAEXPAVzCCSPoolItem@@@Z
        vfunc f47_SetStage;           // from zCCSCutsceneContext  ?SetStage@zCCSCutsceneContext@@UAEXPAVzCVob@@@Z
        vfunc f48_Play;               // from zCCSCutsceneContext  ?Play@zCCSCutsceneContext@@UAEHVzVEC3@@@Z
        vfunc f49_ForcedInterrupt;    // from zCCSCutsceneContext  ?ForcedInterrupt@zCCSCutsceneContext@@UAEXXZ
        vfunc f50_CheckRoleReactions; // from zCCSCutsceneContext  ?CheckRoleReactions@zCCSCutsceneContext@@UAEHXZ
        vfunc f51_IsPlaying;          // from zCCSCutsceneContext  ?IsPlaying@zCCSCutsceneContext@@UAEHXZ
        vfunc f52_IsOutputUnit;       // from zCCSCutsceneContext  ?IsOutputUnit@zCCSCutsceneContext@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082EA4C;
    }

    static uint GetFuncsNum() {
      return 53;
    }

    static vftable_zCCSCutsceneContext& GetTable() {
      MemUnlock;
      return *(vftable_zCCSCutsceneContext*)GetAddress();
    }
  };


  struct vftable_zCCSAtomicBlock {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;       // from zCCSAtomicBlock  ?_GetClassDef@zCCSAtomicBlock@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSAtomicBlock  ?Archive@zCCSAtomicBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSAtomicBlock  ?Unarchive@zCCSAtomicBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base             
        vfunc f04_GetChild;          // from zCCSBlockBase    ?GetChild@zCCSBlockBase@@UAEPAV1@H@Z
        vfunc f05_OrganizeRoles;     // from zCCSAtomicBlock  ?OrganizeRoles@zCCSAtomicBlock@@UAEXAAV?$zCArray@PAVzCVob@@@@AAV?$zCArray@PAVzCCSRole@@@@@Z
        vfunc f06_GetRoleName;       // from zCCSBlockBase    ?GetRoleName@zCCSBlockBase@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;       // from zCCSBlockBase    ?SetRoleName@zCCSBlockBase@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;              // from zCCSAtomicBlock  ?Play@zCCSAtomicBlock@@UAEXPAVzCEventManager@@MM@Z
        vfunc f09_Play;              // from zCCSAtomicBlock  ?Play@zCCSAtomicBlock@@UAEXPAVzCEventManager@@@Z
        vfunc f10_Play;              // from zCCSAtomicBlock  ?Play@zCCSAtomicBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@MM@Z
        vfunc f11_Play;              // from zCCSAtomicBlock  ?Play@zCCSAtomicBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f12_GetMinTime;        // from zCCSAtomicBlock  ?GetMinTime@zCCSAtomicBlock@@UAEMXZ
        vfunc f13_IsFinished;        // from zCCSAtomicBlock  ?IsFinished@zCCSAtomicBlock@@UAEHPAVzCEventManager@@@Z
        vfunc f14_IsFinished;        // from zCCSAtomicBlock  ?IsFinished@zCCSAtomicBlock@@UAEHABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f15_GetCommand;        // from zCCSAtomicBlock  ?GetCommand@zCCSAtomicBlock@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;          // from zCCSBlockBase    ?NewBlock@zCCSBlockBase@@UAEHHH@Z
        vfunc f17_InsertBlock;       // from zCCSBlockBase    ?InsertBlock@zCCSBlockBase@@UAEXPAV1@H@Z
        vfunc f18_DeleteChild;       // from zCCSBlockBase    ?DeleteChild@zCCSBlockBase@@UAEXH@Z
        vfunc f19_GetNumOfChilds;    // from zCCSBlockBase    ?GetNumOfChilds@zCCSBlockBase@@UAEHXZ
        vfunc f20_GetRoleNumOfChild; // from zCCSBlockBase    ?GetRoleNumOfChild@zCCSBlockBase@@UAEHH@Z
        vfunc f21_BlockCorrection;   // from zCCSBlockBase    ?BlockCorrection@zCCSBlockBase@@UAEXXZ
        vfunc f22_BlockAsFocus;      // from zCCSBlockBase    ?BlockAsFocus@zCCSBlockBase@@UAEXH@Z
        vfunc f23_GetChildPos;       // from zCCSBlockBase    ?GetChildPos@zCCSBlockBase@@UAEPAVzCCSBlockPosition@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EB5C;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCCSAtomicBlock& GetTable() {
      MemUnlock;
      return *(vftable_zCCSAtomicBlock*)GetAddress();
    }
  };


  struct vftable_zCCSBlock {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;       // from zCCSBlock      ?_GetClassDef@zCCSBlock@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSBlock      ?Archive@zCCSBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSBlock      ?Unarchive@zCCSBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base           
        vfunc f04_GetChild;          // from zCCSBlock      ?GetChild@zCCSBlock@@UAEPAVzCCSBlockBase@@H@Z
        vfunc f05_OrganizeRoles;     // from zCCSBlock      ?OrganizeRoles@zCCSBlock@@UAEXAAV?$zCArray@PAVzCVob@@@@AAV?$zCArray@PAVzCCSRole@@@@@Z
        vfunc f06_GetRoleName;       // from zCCSBlock      ?GetRoleName@zCCSBlock@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;       // from zCCSBlock      ?SetRoleName@zCCSBlock@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXPAVzCEventManager@@MM@Z
        vfunc f09_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXPAVzCEventManager@@@Z
        vfunc f10_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@MM@Z
        vfunc f11_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f12_GetMinTime;        // from zCCSBlock      ?GetMinTime@zCCSBlock@@UAEMXZ
        vfunc f13_IsFinished;        // from zCCSBlock      ?IsFinished@zCCSBlock@@UAEHPAVzCEventManager@@@Z
        vfunc f14_IsFinished;        // from zCCSBlock      ?IsFinished@zCCSBlock@@UAEHABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f15_GetCommand;        // from zCCSBlockBase  ?GetCommand@zCCSBlockBase@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;          // from zCCSBlock      ?NewBlock@zCCSBlock@@UAEHHH@Z
        vfunc f17_InsertBlock;       // from zCCSBlock      ?InsertBlock@zCCSBlock@@UAEXPAVzCCSBlockBase@@H@Z
        vfunc f18_DeleteChild;       // from zCCSBlock      ?DeleteChild@zCCSBlock@@UAEXH@Z
        vfunc f19_GetNumOfChilds;    // from zCCSBlock      ?GetNumOfChilds@zCCSBlock@@UAEHXZ
        vfunc f20_GetRoleNumOfChild; // from zCCSBlockBase  ?GetRoleNumOfChild@zCCSBlockBase@@UAEHH@Z
        vfunc f21_BlockCorrection;   // from zCCSBlock      ?BlockCorrection@zCCSBlock@@UAEXXZ
        vfunc f22_BlockAsFocus;      // from zCCSBlock      ?BlockAsFocus@zCCSBlock@@UAEXH@Z
        vfunc f23_GetChildPos;       // from zCCSBlock      ?GetChildPos@zCCSBlock@@UAEPAVzCCSBlockPosition@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EBC4;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCCSBlock& GetTable() {
      MemUnlock;
      return *(vftable_zCCSBlock*)GetAddress();
    }
  };


  struct vftable_zCCSSyncBlock {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;       // from zCCSSyncBlock  ?_GetClassDef@zCCSSyncBlock@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSSyncBlock  ?Archive@zCCSSyncBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSSyncBlock  ?Unarchive@zCCSSyncBlock@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base           
        vfunc f04_GetChild;          // from zCCSBlock      ?GetChild@zCCSBlock@@UAEPAVzCCSBlockBase@@H@Z
        vfunc f05_OrganizeRoles;     // from zCCSBlock      ?OrganizeRoles@zCCSBlock@@UAEXAAV?$zCArray@PAVzCVob@@@@AAV?$zCArray@PAVzCCSRole@@@@@Z
        vfunc f06_GetRoleName;       // from zCCSBlock      ?GetRoleName@zCCSBlock@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;       // from zCCSBlock      ?SetRoleName@zCCSBlock@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXPAVzCEventManager@@MM@Z
        vfunc f09_Play;              // from zCCSSyncBlock  ?Play@zCCSSyncBlock@@UAEXPAVzCEventManager@@@Z
        vfunc f10_Play;              // from zCCSSyncBlock  ?Play@zCCSSyncBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@MM@Z
        vfunc f11_Play;              // from zCCSSyncBlock  ?Play@zCCSSyncBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f12_GetMinTime;        // from zCCSBlock      ?GetMinTime@zCCSBlock@@UAEMXZ
        vfunc f13_IsFinished;        // from zCCSBlock      ?IsFinished@zCCSBlock@@UAEHPAVzCEventManager@@@Z
        vfunc f14_IsFinished;        // from zCCSSyncBlock  ?IsFinished@zCCSSyncBlock@@UAEHABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f15_GetCommand;        // from zCCSBlockBase  ?GetCommand@zCCSBlockBase@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;          // from zCCSSyncBlock  ?NewBlock@zCCSSyncBlock@@UAEHHH@Z
        vfunc f17_InsertBlock;       // from zCCSSyncBlock  ?InsertBlock@zCCSSyncBlock@@UAEXPAVzCCSBlockBase@@H@Z
        vfunc f18_DeleteChild;       // from zCCSSyncBlock  ?DeleteChild@zCCSSyncBlock@@UAEXH@Z
        vfunc f19_GetNumOfChilds;    // from zCCSBlock      ?GetNumOfChilds@zCCSBlock@@UAEHXZ
        vfunc f20_GetRoleNumOfChild; // from zCCSSyncBlock  ?GetRoleNumOfChild@zCCSSyncBlock@@UAEHH@Z
        vfunc f21_BlockCorrection;   // from zCCSBlock      ?BlockCorrection@zCCSBlock@@UAEXXZ
        vfunc f22_BlockAsFocus;      // from zCCSSyncBlock  ?BlockAsFocus@zCCSSyncBlock@@UAEXH@Z
        vfunc f23_GetChildPos;       // from zCCSBlock      ?GetChildPos@zCCSBlock@@UAEPAVzCCSBlockPosition@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EC2C;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCCSSyncBlock& GetTable() {
      MemUnlock;
      return *(vftable_zCCSSyncBlock*)GetAddress();
    }
  };


  struct vftable_zCCSBlockBase {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;       // from zCCSBlockBase  ?_GetClassDef@zCCSBlockBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSBlockBase  ?Archive@zCCSBlockBase@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSBlockBase  ?Unarchive@zCCSBlockBase@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base           
        vfunc f04_GetChild;          // from zCCSBlockBase  ?GetChild@zCCSBlockBase@@UAEPAV1@H@Z
        vfunc f05_OrganizeRoles;     // from base           purecall
        vfunc f06_GetRoleName;       // from zCCSBlockBase  ?GetRoleName@zCCSBlockBase@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;       // from zCCSBlockBase  ?SetRoleName@zCCSBlockBase@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;              // from base           purecall
        vfunc f09_Play;              // from base           purecall
        vfunc f10_Play;              // from base           purecall
        vfunc f11_Play;              // from base           purecall
        vfunc f12_GetMinTime;        // from base           purecall
        vfunc f13_IsFinished;        // from base           purecall
        vfunc f14_IsFinished;        // from base           purecall
        vfunc f15_GetCommand;        // from zCCSBlockBase  ?GetCommand@zCCSBlockBase@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;          // from zCCSBlockBase  ?NewBlock@zCCSBlockBase@@UAEHHH@Z
        vfunc f17_InsertBlock;       // from zCCSBlockBase  ?InsertBlock@zCCSBlockBase@@UAEXPAV1@H@Z
        vfunc f18_DeleteChild;       // from zCCSBlockBase  ?DeleteChild@zCCSBlockBase@@UAEXH@Z
        vfunc f19_GetNumOfChilds;    // from zCCSBlockBase  ?GetNumOfChilds@zCCSBlockBase@@UAEHXZ
        vfunc f20_GetRoleNumOfChild; // from zCCSBlockBase  ?GetRoleNumOfChild@zCCSBlockBase@@UAEHH@Z
        vfunc f21_BlockCorrection;   // from zCCSBlockBase  ?BlockCorrection@zCCSBlockBase@@UAEXXZ
        vfunc f22_BlockAsFocus;      // from zCCSBlockBase  ?BlockAsFocus@zCCSBlockBase@@UAEXH@Z
        vfunc f23_GetChildPos;       // from zCCSBlockBase  ?GetChildPos@zCCSBlockBase@@UAEPAVzCCSBlockPosition@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EC94;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCCSBlockBase& GetTable() {
      MemUnlock;
      return *(vftable_zCCSBlockBase*)GetAddress();
    }
  };


  struct vftable_zCCSRole_for_zSTRING {
    union {
      vfunc array[1];
      group {
        vfunc f00_vector_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082ECF8;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCCSRole_for_zSTRING& GetTable() {
      MemUnlock;
      return *(vftable_zCCSRole_for_zSTRING*)GetAddress();
    }
  };


  struct vftable_zCCSRole_for_zCObject {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCCSRole  ?_GetClassDef@zCCSRole@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSRole  ?Archive@zCCSRole@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSRole  ?Unarchive@zCCSRole@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base      
      } names;
    };

    static uint GetAddress() {
      return 0x0082ED00;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCCSRole_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCCSRole_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCEvMsgCutscene {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEvMsgCutscene  ?_GetClassDef@zCEvMsgCutscene@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMessage   ?Archive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMessage   ?Unarchive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base             
        vfunc f04_IsOverlay;             // from zCEventMessage   ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage   ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEvMsgCutscene  ?IsHighPriority@zCEvMsgCutscene@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage   ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage   ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEvMsgCutscene  ?Delete@zCEvMsgCutscene@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage   ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEvMsgCutscene  ?IsDeleted@zCEvMsgCutscene@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage   ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage   ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEvMsgCutscene  ?MD_GetNumOfSubTypes@zCEvMsgCutscene@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEvMsgCutscene  ?MD_GetSubTypeString@zCEvMsgCutscene@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage   ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage   ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage   ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage   ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage   ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage   ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage   ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082ED14;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEvMsgCutscene& GetTable() {
      MemUnlock;
      return *(vftable_zCEvMsgCutscene*)GetAddress();
    }
  };


  struct vftable_zCCSBlockPosition {
    union {
      vfunc array[1];
      group {
        vfunc f00_vector_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082ED78;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCCSBlockPosition& GetTable() {
      MemUnlock;
      return *(vftable_zCCSBlockPosition*)GetAddress();
    }
  };


  struct vftable_zCCutscene {
    union {
      vfunc array[46];
      group {
        vfunc f00_GetClassDef;       // from zCCutscene     ?_GetClassDef@zCCutscene@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCutscene     ?Archive@zCCutscene@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCutscene     ?Unarchive@zCCutscene@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base           
        vfunc f04_GetChild;          // from zCCSBlock      ?GetChild@zCCSBlock@@UAEPAVzCCSBlockBase@@H@Z
        vfunc f05_OrganizeRoles;     // from zCCSBlock      ?OrganizeRoles@zCCSBlock@@UAEXAAV?$zCArray@PAVzCVob@@@@AAV?$zCArray@PAVzCCSRole@@@@@Z
        vfunc f06_GetRoleName;       // from zCCSBlock      ?GetRoleName@zCCSBlock@@UAE?AVzSTRING@@XZ
        vfunc f07_SetRoleName;       // from zCCSBlock      ?SetRoleName@zCCSBlock@@UAEXAAVzSTRING@@@Z
        vfunc f08_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXPAVzCEventManager@@MM@Z
        vfunc f09_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXPAVzCEventManager@@@Z
        vfunc f10_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@MM@Z
        vfunc f11_Play;              // from zCCSBlock      ?Play@zCCSBlock@@UAEXABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f12_GetMinTime;        // from zCCSBlock      ?GetMinTime@zCCSBlock@@UAEMXZ
        vfunc f13_IsFinished;        // from zCCSBlock      ?IsFinished@zCCSBlock@@UAEHPAVzCEventManager@@@Z
        vfunc f14_IsFinished;        // from zCCSBlock      ?IsFinished@zCCSBlock@@UAEHABV?$zCArray@PAVzCEventManager@@@@@Z
        vfunc f15_GetCommand;        // from zCCSBlockBase  ?GetCommand@zCCSBlockBase@@UAEPAVzCEventMessage@@XZ
        vfunc f16_NewBlock;          // from zCCutscene     ?NewBlock@zCCutscene@@UAEHHH@Z
        vfunc f17_InsertBlock;       // from zCCSBlock      ?InsertBlock@zCCSBlock@@UAEXPAVzCCSBlockBase@@H@Z
        vfunc f18_DeleteChild;       // from zCCSBlock      ?DeleteChild@zCCSBlock@@UAEXH@Z
        vfunc f19_GetNumOfChilds;    // from zCCSBlock      ?GetNumOfChilds@zCCSBlock@@UAEHXZ
        vfunc f20_GetRoleNumOfChild; // from zCCSBlockBase  ?GetRoleNumOfChild@zCCSBlockBase@@UAEHH@Z
        vfunc f21_BlockCorrection;   // from zCCSBlock      ?BlockCorrection@zCCSBlock@@UAEXXZ
        vfunc f22_BlockAsFocus;      // from zCCSBlock      ?BlockAsFocus@zCCSBlock@@UAEXH@Z
        vfunc f23_GetChildPos;       // from zCCSBlock      ?GetChildPos@zCCSBlock@@UAEPAVzCCSBlockPosition@@H@Z
        vfunc f24_AddMainRole;       // from zCCutscene     ?AddMainRole@zCCutscene@@UAEHPAVzCVob@@@Z
        vfunc f25_AddRoleOU;         // from zCCutscene     ?AddRoleOU@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f26_RemoveRole;        // from zCCutscene     ?RemoveRole@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f27_SetOwnerPlayer;    // from zCCutscene     ?SetOwnerPlayer@zCCutscene@@UAEXPAVzCCSPlayer@@@Z
        vfunc f28_Reset;             // from zCCutscene     ?Reset@zCCutscene@@UAEXXZ
        vfunc f29_ClearCutscene;     // from zCCutscene     ?ClearCutscene@zCCutscene@@UAEXXZ
        vfunc f30_StartPlaying;      // from zCCutscene     ?StartPlaying@zCCutscene@@UAEHXZ
        vfunc f31_Stop;              // from zCCutscene     ?Stop@zCCutscene@@UAEXXZ
        vfunc f32_StopRole;          // from zCCutscene     ?StopRole@zCCutscene@@UAEXPAVzCVob@@@Z
        vfunc f33_Interrupt;         // from zCCutscene     ?Interrupt@zCCutscene@@UAEXXZ
        vfunc f34_ResumeActBlock;    // from zCCutscene     ?ResumeActBlock@zCCutscene@@UAEHXZ
        vfunc f35_PlaySub;           // from zCCutscene     ?PlaySub@zCCutscene@@UAEHMM@Z
        vfunc f36_NewCS;             // from zCCutscene     ?NewCS@zCCutscene@@UAEXPAVzCCSManager@@@Z
        vfunc f37_IsCutscene;        // from zCCutscene     ?IsCutscene@zCCutscene@@UAEHXZ
        vfunc f38_IsFinished;        // from zCCutscene     ?IsFinished@zCCutscene@@UAEHXZ
        vfunc f39_PrintDebugInfo;    // from zCCutscene     ?PrintDebugInfo@zCCutscene@@UAEXABVzSTRING@@@Z
        vfunc f40_CheckRoles;        // from zCCutscene     ?CheckRoles@zCCutscene@@MAEHAAH@Z
        vfunc f41_CSCheck;           // from zCCutscene     ?CSCheck@zCCutscene@@MAEHAAH@Z
        vfunc f42_GetStage;          // from zCCutscene     ?GetStage@zCCutscene@@MAEPAVzCVob@@XZ
        vfunc f43_LoadStage;         // from zCCutscene     ?LoadStage@zCCutscene@@MAEPAVzCVob@@XZ
        vfunc f44_CatchPlayer;       // from zCCutscene     ?CatchPlayer@zCCutscene@@MAEPAVzCVob@@PAV2@@Z
        vfunc f45_PrepareBlock;      // from zCCutscene     ?PrepareBlock@zCCutscene@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082ED8C;
    }

    static uint GetFuncsNum() {
      return 46;
    }

    static vftable_zCCutscene& GetTable() {
      MemUnlock;
      return *(vftable_zCCutscene*)GetAddress();
    }
  };


  struct vftable_zCCSLib {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCCSLib  ?_GetClassDef@zCCSLib@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSLib  ?Archive@zCCSLib@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSLib  ?Unarchive@zCCSLib@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base     
      } names;
    };

    static uint GetAddress() {
      return 0x0082EE60;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCCSLib& GetTable() {
      MemUnlock;
      return *(vftable_zCCSLib*)GetAddress();
    }
  };


  struct vftable_zCCSManager {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;           // from zCCSManager  ?_GetClassDef@zCCSManager@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCCSManager  ?Archive@zCCSManager@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCCSManager  ?Unarchive@zCCSManager@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base         
        vfunc f04_CreateMessage;         // from zCCSManager  ?CreateMessage@zCCSManager@@UAEPAVzCEventMessage@@H@Z
        vfunc f05_CreateOuMessage;       // from zCCSManager  ?CreateOuMessage@zCCSManager@@UAEPAVzCEventMessage@@XZ
        vfunc f06_CreateCutscenePlayer;  // from zCCSManager  ?CreateCutscenePlayer@zCCSManager@@UAEPAVzCCSPlayer@@PAVzCWorld@@@Z
        vfunc f07_CreateProperties;      // from zCCSManager  ?CreateProperties@zCCSManager@@UAEPAVzCCSProps@@XZ
        vfunc f08_RemoveCutscenePlayer;  // from zCCSManager  ?RemoveCutscenePlayer@zCCSManager@@UAEXPAVzCCSPlayer@@@Z
        vfunc f09_LibIsLoaded;           // from zCCSManager  ?LibIsLoaded@zCCSManager@@UAEHXZ
        vfunc f10_LibGet;                // from zCCSManager  ?LibGet@zCCSManager@@UAEPAVzCCSBlock@@H@Z
        vfunc f11_LibGetFirst;           // from zCCSManager  ?LibGetFirst@zCCSManager@@UAEPAVzCCSBlock@@AAH@Z
        vfunc f12_LibGetFirst;           // from zCCSManager  ?LibGetFirst@zCCSManager@@UAEPAVzCCSBlock@@XZ
        vfunc f13_LibGetNext;            // from zCCSManager  ?LibGetNext@zCCSManager@@UAEPAVzCCSBlock@@AAH@Z
        vfunc f14_LibGetNext;            // from zCCSManager  ?LibGetNext@zCCSManager@@UAEPAVzCCSBlock@@XZ
        vfunc f15_LibAddOU;              // from zCCSManager  ?LibAddOU@zCCSManager@@UAEHPAVzCCSBlock@@@Z
        vfunc f16_LibDelOU;              // from zCCSManager  ?LibDelOU@zCCSManager@@UAEXH@Z
        vfunc f17_LibNullOU;             // from zCCSManager  ?LibNullOU@zCCSManager@@UAEXH@Z
        vfunc f18_LibLoad;               // from zCCSManager  ?LibLoad@zCCSManager@@UAEXH@Z
        vfunc f19_LibStore;              // from zCCSManager  ?LibStore@zCCSManager@@UAEXH@Z
        vfunc f20_LibValidateOU;         // from zCCSManager  ?LibValidateOU@zCCSManager@@UAEHAAVzSTRING@@@Z
        vfunc f21_LibValidateOU;         // from zCCSManager  ?LibValidateOU@zCCSManager@@UAEHH@Z
        vfunc f22_LibGetSvmModuleName;   // from zCCSManager  ?LibGetSvmModuleName@zCCSManager@@UAE?AVzSTRING@@H@Z
        vfunc f23_LibIsSvmModuleRunning; // from zCCSManager  ?LibIsSvmModuleRunning@zCCSManager@@UAEHH@Z
        vfunc f24_LibSvmModuleStart;     // from zCCSManager  ?LibSvmModuleStart@zCCSManager@@UAEHH@Z
        vfunc f25_LibSvmModuleStop;      // from zCCSManager  ?LibSvmModuleStop@zCCSManager@@UAEHH@Z
        vfunc f26_InsertPlayerInList;    // from zCCSManager  ?InsertPlayerInList@zCCSManager@@MAEXPAVzCCSPlayer@@@Z
        vfunc f27_RemovePlayerFromList;  // from zCCSManager  ?RemovePlayerFromList@zCCSManager@@MAEXPAVzCCSPlayer@@@Z
        vfunc f28_LibCheckLoaded;        // from zCCSManager  ?LibCheckLoaded@zCCSManager@@MAEXH@Z
        vfunc f29_PoolFindItem;          // from zCCSManager  ?PoolFindItem@zCCSManager@@MAEPAVzCCSPoolItem@@AAVzSTRING@@@Z
        vfunc f30_PoolInsertItem;        // from zCCSManager  ?PoolInsertItem@zCCSManager@@MAEXPAVzCCSPoolItem@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EE8C;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_zCCSManager& GetTable() {
      MemUnlock;
      return *(vftable_zCCSManager*)GetAddress();
    }
  };


  struct vftable_zCCSPlayer_for_zCCSDebugger {
    union {
      vfunc array[8];
      group {
        vfunc f00_vector_destructor;   // from base        
        vfunc f01_CSDB_BeginSyncBlock; // from zCCSPlayer  ?CSDB_BeginSyncBlock@zCCSPlayer@@UAEXPAVzCCSSyncBlock@@@Z
        vfunc f02_CSDB_BeginAtomBlock; // from zCCSPlayer  ?CSDB_BeginAtomBlock@zCCSPlayer@@UAEXPAVzCCSBlockBase@@@Z
        vfunc f03_CSDB_EndAtomBlock;   // from zCCSPlayer  ?CSDB_EndAtomBlock@zCCSPlayer@@UAEXPAVzCCSBlockBase@@@Z
        vfunc f04_CSDB_Error;          // from zCCSPlayer  ?CSDB_Error@zCCSPlayer@@UAEXPAVzCCSBlockBase@@AAVzSTRING@@@Z
        vfunc f05_CSDB_Warning;        // from zCCSPlayer  ?CSDB_Warning@zCCSPlayer@@UAEXPAVzCCSBlockBase@@AAVzSTRING@@@Z
        vfunc f06_CSDB_StartPlaying;   // from zCCSPlayer  ?CSDB_StartPlaying@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
        vfunc f07_CSDB_Stop;           // from zCCSPlayer  ?CSDB_Stop@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EF20;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCCSPlayer_for_zCCSDebugger& GetTable() {
      MemUnlock;
      return *(vftable_zCCSPlayer_for_zCCSDebugger*)GetAddress();
    }
  };


  struct vftable_zCCSPlayer_for_zCObject {
    union {
      vfunc array[21];
      group {
        vfunc f00_GetClassDef;         // from zCCSPlayer  ?_GetClassDef@zCCSPlayer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCCSPlayer  ?Archive@zCCSPlayer@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCCSPlayer  ?Unarchive@zCCSPlayer@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base        
        vfunc f04_CreateNewOutputUnit; // from zCCSPlayer  ?CreateNewOutputUnit@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@HPAVzCVob@@@Z
        vfunc f05_StartOutputUnit;     // from zCCSPlayer  ?StartOutputUnit@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@HPAVzCVob@@@Z
        vfunc f06_StartCutscene;       // from zCCSPlayer  ?StartCutscene@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@PAVzCCutscene@@PAVzCVob@@VzSTRING@@@Z
        vfunc f07_StartCutscene;       // from zCCSPlayer  ?StartCutscene@zCCSPlayer@@UAEPAVzCCSCutsceneContext@@AAVzSTRING@@PAVzCVob@@@Z
        vfunc f08_ForgetCutscene;      // from zCCSPlayer  ?ForgetCutscene@zCCSPlayer@@UAEXPAVzCCutscene@@@Z
        vfunc f09_ResetCutscenePlayer; // from zCCSPlayer  ?ResetCutscenePlayer@zCCSPlayer@@UAEXXZ
        vfunc f10_StopAllCutscenes;    // from zCCSPlayer  ?StopAllCutscenes@zCCSPlayer@@UAEHPAVzCVob@@@Z
        vfunc f11_StopAllOutputUnits;  // from zCCSPlayer  ?StopAllOutputUnits@zCCSPlayer@@UAEHPAVzCVob@@@Z
        vfunc f12_InsertCutscene;      // from zCCSPlayer  ?InsertCutscene@zCCSPlayer@@UAEXPAVzCCSCutsceneContext@@@Z
        vfunc f13_RemoveCutscene;      // from zCCSPlayer  ?RemoveCutscene@zCCSPlayer@@UAEXPAVzCCSCutsceneContext@@@Z
        vfunc f14_OnCSTrigger;         // from zCCSPlayer  ?OnCSTrigger@zCCSPlayer@@UAEXAAVzSTRING@@PAVzCVob@@@Z
        vfunc f15_OnCSUntrigger;       // from zCCSPlayer  ?OnCSUntrigger@zCCSPlayer@@UAEXAAVzSTRING@@PAVzCVob@@@Z
        vfunc f16_SetOwnerWorld;       // from zCCSPlayer  ?SetOwnerWorld@zCCSPlayer@@UAEXPAVzCWorld@@@Z
        vfunc f17_SetOwnerManager;     // from zCCSPlayer  ?SetOwnerManager@zCCSPlayer@@UAEXPAVzCCSManager@@@Z
        vfunc f18_Process;             // from zCCSPlayer  ?Process@zCCSPlayer@@UAEXXZ
        vfunc f19_ProcessCutscene;     // from zCCSPlayer  ?ProcessCutscene@zCCSPlayer@@MAEXPAVzCCSCutsceneContext@@ABVzVEC3@@@Z
        vfunc f20_ProcessList;         // from zCCSPlayer  ?ProcessList@zCCSPlayer@@MAEXABVzVEC3@@HHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082EF44;
    }

    static uint GetFuncsNum() {
      return 21;
    }

    static vftable_zCCSPlayer_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCCSPlayer_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCCSDebugger {
    union {
      vfunc array[8];
      group {
        vfunc f00_scalar_destructor;   // from base  purecall
        vfunc f01_CSDB_BeginSyncBlock; // from base  purecall
        vfunc f02_CSDB_BeginAtomBlock; // from base  purecall
        vfunc f03_CSDB_EndAtomBlock;   // from base  purecall
        vfunc f04_CSDB_Error;          // from base  purecall
        vfunc f05_CSDB_Warning;        // from base  purecall
        vfunc f06_CSDB_StartPlaying;   // from base  purecall
        vfunc f07_CSDB_Stop;           // from base  purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0082EF9C;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCCSDebugger& GetTable() {
      MemUnlock;
      return *(vftable_zCCSDebugger*)GetAddress();
    }
  };


  struct vftable_zCCSPoolItem_for_zCObject {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCCSPoolItem  ?_GetClassDef@zCCSPoolItem@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCCSPoolItem  ?Archive@zCCSPoolItem@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCCSPoolItem  ?Unarchive@zCCSPoolItem@@UAEXAAVzCArchiver@@@Z
        vfunc f03_vector_destructor; // from base          
      } names;
    };

    static uint GetAddress() {
      return 0x0082EFD8;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCCSPoolItem_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCCSPoolItem_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCCSPoolItem_for_zSTRING {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_PrintDebugInfo;    // from zCCSPoolItem  ?PrintDebugInfo@zCCSPoolItem@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082EFEC;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCCSPoolItem_for_zSTRING& GetTable() {
      MemUnlock;
      return *(vftable_zCCSPoolItem_for_zSTRING*)GetAddress();
    }
  };


  struct vftable_zCCSProps {
    union {
      vfunc array[10];
      group {
        vfunc f00_GetClassDef;        // from zCCSProps  ?_GetClassDef@zCCSProps@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;            // from zCCSProps  ?Archive@zCCSProps@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;          // from zCCSProps  ?Unarchive@zCCSProps@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;  // from base       
        vfunc f04_AcceptRole;         // from zCCSProps  ?AcceptRole@zCCSProps@@UAEHPAVzCCSRole@@PAVzCVob@@@Z
        vfunc f05_CheckRole;          // from zCCSProps  ?CheckRole@zCCSProps@@UAEHPAVzCCSRole@@PAVzCVob@@@Z
        vfunc f06_GetCheckRoleResult; // from zCCSProps  ?GetCheckRoleResult@zCCSProps@@UAEHXZ
        vfunc f07_CheckDistance;      // from zCCSProps  ?CheckDistance@zCCSProps@@UAEHM@Z
        vfunc f08_CheckRange;         // from zCCSProps  ?CheckRange@zCCSProps@@UAEHM@Z
        vfunc f09_PrintDebugInfo;     // from zCCSProps  ?PrintDebugInfo@zCCSProps@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082F00C;
    }

    static uint GetFuncsNum() {
      return 10;
    }

    static vftable_zCCSProps& GetTable() {
      MemUnlock;
      return *(vftable_zCCSProps*)GetAddress();
    }
  };


  struct vftable_oCBinkPlayer {
    union {
      vfunc array[15];
      group {
        vfunc f00_scalar_destructor; // from base           
        vfunc f01_OpenVideo;         // from oCBinkPlayer   ?OpenVideo@oCBinkPlayer@@UAEHVzSTRING@@@Z
        vfunc f02_CloseVideo;        // from zCBinkPlayer   ?CloseVideo@zCBinkPlayer@@UAEHXZ
        vfunc f03_PlayInit;          // from oCBinkPlayer   ?PlayInit@oCBinkPlayer@@UAEHH@Z
        vfunc f04_PlayFrame;         // from oCBinkPlayer   ?PlayFrame@oCBinkPlayer@@UAEHXZ
        vfunc f05_PlayDeinit;        // from oCBinkPlayer   ?PlayDeinit@oCBinkPlayer@@UAEHXZ
        vfunc f06_Pause;             // from zCBinkPlayer   ?Pause@zCBinkPlayer@@UAEHXZ
        vfunc f07_Unpause;           // from zCBinkPlayer   ?Unpause@zCBinkPlayer@@UAEHXZ
        vfunc f08_Stop;              // from zCVideoPlayer  ?Stop@zCVideoPlayer@@UAEHXZ
        vfunc f09_IsPlaying;         // from zCBinkPlayer   ?IsPlaying@zCBinkPlayer@@UAEHXZ
        vfunc f10_ToggleSound;       // from zCBinkPlayer   ?ToggleSound@zCBinkPlayer@@UAEHXZ
        vfunc f11_SetSoundVolume;    // from zCBinkPlayer   ?SetSoundVolume@zCBinkPlayer@@UAEMM@Z
        vfunc f12_PlayGotoNextFrame; // from zCBinkPlayer   ?PlayGotoNextFrame@zCBinkPlayer@@MAEHXZ
        vfunc f13_PlayWaitNextFrame; // from zCBinkPlayer   ?PlayWaitNextFrame@zCBinkPlayer@@MAEHXZ
        vfunc f14_PlayHandleEvents;  // from oCBinkPlayer   ?PlayHandleEvents@oCBinkPlayer@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082F044;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCBinkPlayer& GetTable() {
      MemUnlock;
      return *(vftable_oCBinkPlayer*)GetAddress();
    }
  };


  struct vftable_oCGameInfo {
    union {
      vfunc array[12];
      group {
        vfunc f00_scalar_destructor;     // from base        
        vfunc f01_Init;                  // from oCGameInfo  ?Init@oCGameInfo@@UAEXXZ
        vfunc f02_Reset;                 // from zCGameInfo  ?Reset@zCGameInfo@@UAEXXZ
        vfunc f03_SetName;               // from zCGameInfo  ?SetName@zCGameInfo@@UAEXABVzSTRING@@@Z
        vfunc f04_GetName;               // from zCGameInfo  ?GetName@zCGameInfo@@UBE?AVzSTRING@@XZ
        vfunc f05_AddPlayer;             // from zCGameInfo  ?AddPlayer@zCGameInfo@@UAEHPAVzCPlayerInfo@@@Z
        vfunc f06_RemPlayer;             // from zCGameInfo  ?RemPlayer@zCGameInfo@@UAEHPAVzCPlayerInfo@@@Z
        vfunc f07_GetPlayerByID;         // from zCGameInfo  ?GetPlayerByID@zCGameInfo@@UAEPAVzCPlayerInfo@@H@Z
        vfunc f08_GetPlayerByVobID;      // from zCGameInfo  ?GetPlayerByVobID@zCGameInfo@@UAEPAVzCPlayerInfo@@K@Z
        vfunc f09_GetPlayerByNetAddress; // from zCGameInfo  ?GetPlayerByNetAddress@zCGameInfo@@UAEPAVzCPlayerInfo@@AAUzTNetAddress@@@Z
        vfunc f10_Pack;                  // from oCGameInfo  ?Pack@oCGameInfo@@MAEXAAVzCBuffer@@E@Z
        vfunc f11_Unpack;                // from oCGameInfo  ?Unpack@oCGameInfo@@MAEXAAVzCBuffer@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F09C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCGameInfo& GetTable() {
      MemUnlock;
      return *(vftable_oCGameInfo*)GetAddress();
    }
  };


  struct vftable_CGameManager {
    union {
      vfunc array[2];
      group {
        vfunc f00_HandleEvent;       // from CGameManager  ?HandleEvent@CGameManager@@MAEHH@Z
        vfunc f01_scalar_destructor; // from base          
      } names;
    };

    static uint GetAddress() {
      return 0x0082F0EC;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_CGameManager& GetTable() {
      MemUnlock;
      return *(vftable_CGameManager*)GetAddress();
    }
  };


  struct vftable_zCTextureFileHandler {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base                  
        vfunc f01_HandleFile;        // from zCTextureFileHandler  ?HandleFile@zCTextureFileHandler@@UAEHABVzSTRING@@PBDU_finddata_t@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F0F8;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCTextureFileHandler& GetTable() {
      MemUnlock;
      return *(vftable_zCTextureFileHandler*)GetAddress();
    }
  };


  struct vftable_oCObjectFactory {
    union {
      vfunc array[16];
      group {
        vfunc f00_GetClassDef;         // from oCObjectFactory  ?_GetClassDef@oCObjectFactory@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base             
        vfunc f04_CreateEventManager;  // from oCObjectFactory  ?CreateEventManager@oCObjectFactory@@UAEPAVzCEventManager@@PAVzCVob@@@Z
        vfunc f05_CreateZFile;         // from zCObjectFactory  ?CreateZFile@zCObjectFactory@@UAEPAVzFILE@@ABVzSTRING@@@Z
        vfunc f06_CreateSession;       // from zCObjectFactory  ?CreateSession@zCObjectFactory@@UAEPAVzCSession@@XZ
        vfunc f07_CreateCSManager;     // from oCObjectFactory  ?CreateCSManager@oCObjectFactory@@UAEPAVzCCSManager@@XZ
        vfunc f08_CreateNetVobControl; // from zCObjectFactory  ?CreateNetVobControl@zCObjectFactory@@UAEPAVzCNetVobControl@@PAVzCVob@@@Z
        vfunc f09_CreateGameInfo;      // from oCObjectFactory  ?CreateGameInfo@oCObjectFactory@@UAEPAVzCGameInfo@@XZ
        vfunc f10_CreatePlayerInfo;    // from oCObjectFactory  ?CreatePlayerInfo@oCObjectFactory@@UAEPAVzCPlayerInfo@@XZ
        vfunc f11_CreateWorld;         // from oCObjectFactory  ?CreateWorld@oCObjectFactory@@UAEPAVzCWorld@@XZ
        vfunc f12_CreateWaypoint;      // from oCObjectFactory  ?CreateWaypoint@oCObjectFactory@@UAEPAVzCWaypoint@@XZ
        vfunc f13_CreateWay;           // from oCObjectFactory  ?CreateWay@oCObjectFactory@@UAEPAVzCWay@@XZ
        vfunc f14_CreateNpc;           // from oCObjectFactory  ?CreateNpc@oCObjectFactory@@UAEPAVoCNpc@@H@Z
        vfunc f15_CreateItem;          // from oCObjectFactory  ?CreateItem@oCObjectFactory@@UAEPAVoCItem@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F104;
    }

    static uint GetFuncsNum() {
      return 16;
    }

    static vftable_oCObjectFactory& GetTable() {
      MemUnlock;
      return *(vftable_oCObjectFactory*)GetAddress();
    }
  };


  struct vftable_zCObjectFactory {
    union {
      vfunc array[14];
      group {
        vfunc f00_GetClassDef;         // from zCObjectFactory  ?_GetClassDef@zCObjectFactory@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base             
        vfunc f04_CreateEventManager;  // from zCObjectFactory  ?CreateEventManager@zCObjectFactory@@UAEPAVzCEventManager@@PAVzCVob@@@Z
        vfunc f05_CreateZFile;         // from zCObjectFactory  ?CreateZFile@zCObjectFactory@@UAEPAVzFILE@@ABVzSTRING@@@Z
        vfunc f06_CreateSession;       // from zCObjectFactory  ?CreateSession@zCObjectFactory@@UAEPAVzCSession@@XZ
        vfunc f07_CreateCSManager;     // from zCObjectFactory  ?CreateCSManager@zCObjectFactory@@UAEPAVzCCSManager@@XZ
        vfunc f08_CreateNetVobControl; // from zCObjectFactory  ?CreateNetVobControl@zCObjectFactory@@UAEPAVzCNetVobControl@@PAVzCVob@@@Z
        vfunc f09_CreateGameInfo;      // from zCObjectFactory  ?CreateGameInfo@zCObjectFactory@@UAEPAVzCGameInfo@@XZ
        vfunc f10_CreatePlayerInfo;    // from zCObjectFactory  ?CreatePlayerInfo@zCObjectFactory@@UAEPAVzCPlayerInfo@@XZ
        vfunc f11_CreateWorld;         // from zCObjectFactory  ?CreateWorld@zCObjectFactory@@UAEPAVzCWorld@@XZ
        vfunc f12_CreateWaypoint;      // from zCObjectFactory  ?CreateWaypoint@zCObjectFactory@@UAEPAVzCWaypoint@@XZ
        vfunc f13_CreateWay;           // from zCObjectFactory  ?CreateWay@zCObjectFactory@@UAEPAVzCWay@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082F148;
    }

    static uint GetFuncsNum() {
      return 14;
    }

    static vftable_zCObjectFactory& GetTable() {
      MemUnlock;
      return *(vftable_zCObjectFactory*)GetAddress();
    }
  };


  struct vftable_oCMenuSavegame {
    union {
      vfunc array[20];
      group {
        vfunc f00_HandleEvent;        // from oCMenuSavegame  ?HandleEvent@oCMenuSavegame@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from zCMenu          ?HandleEnterItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from zCMenu          ?HandleLeaveItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from zCMenu          ?HandleActivateItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu          ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu          ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from zCMenu          ?Leave@zCMenu@@UAEXXZ
        vfunc f07_Render;             // from zCMenu          ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu          ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu          ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from oCMenuSavegame  ?Activate@oCMenuSavegame@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base            
        vfunc f12_ScreenInit;         // from oCMenuSavegame  ?ScreenInit@oCMenuSavegame@@UAEXXZ
        vfunc f13_ScreenDone;         // from oCMenuSavegame  ?ScreenDone@oCMenuSavegame@@UAEXXZ
        vfunc f14_HandleAction;       // from zCMenu          ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu          ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu          ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from zCMenu          ?ExecCommand@zCMenu@@MAEHABVzSTRING@@@Z
        vfunc f18_HandleSlotChange;   // from oCMenuSavegame  ?HandleSlotChange@oCMenuSavegame@@UAEXH@Z
        vfunc f19_GetSelectedSlot;    // from oCMenuSavegame  ?GetSelectedSlot@oCMenuSavegame@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082F1EC;
    }

    static uint GetFuncsNum() {
      return 20;
    }

    static vftable_oCMenuSavegame& GetTable() {
      MemUnlock;
      return *(vftable_oCMenuSavegame*)GetAddress();
    }
  };


  struct vftable_oCPlayerInfo {
    union {
      vfunc array[14];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_Init;              // from zCPlayerInfo  ?Init@zCPlayerInfo@@UAEXABVzSTRING@@PAX@Z
        vfunc f02_Init;              // from oCPlayerInfo  ?Init@oCPlayerInfo@@UAEXABVzSTRING@@0@Z
        vfunc f03_SetName;           // from zCPlayerInfo  ?SetName@zCPlayerInfo@@UAEXABVzSTRING@@@Z
        vfunc f04_SetPlayerVob;      // from zCPlayerInfo  ?SetPlayerVob@zCPlayerInfo@@UAEXPAVzCVob@@@Z
        vfunc f05_Reset;             // from oCPlayerInfo  ?Reset@oCPlayerInfo@@UAEXXZ
        vfunc f06_Deactivate;        // from zCPlayerInfo  ?Deactivate@zCPlayerInfo@@UAEXH@Z
        vfunc f07_IsDeactivated;     // from zCPlayerInfo  ?IsDeactivated@zCPlayerInfo@@UBEHXZ
        vfunc f08_SetReady;          // from zCPlayerInfo  ?SetReady@zCPlayerInfo@@UAEXH@Z
        vfunc f09_IsReady;           // from zCPlayerInfo  ?IsReady@zCPlayerInfo@@UBEHXZ
        vfunc f10_Pack;              // from oCPlayerInfo  ?Pack@oCPlayerInfo@@MAEXAAVzCBuffer@@@Z
        vfunc f11_Unpack;            // from oCPlayerInfo  ?Unpack@oCPlayerInfo@@MAEXAAVzCBuffer@@@Z
        vfunc f12_SetInstance;       // from oCPlayerInfo  ?SetInstance@oCPlayerInfo@@UAEXW4TPlayerInstance@@@Z
        vfunc f13_SetInstanceByName; // from oCPlayerInfo  ?SetInstanceByName@oCPlayerInfo@@UAEXABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F278;
    }

    static uint GetFuncsNum() {
      return 14;
    }

    static vftable_oCPlayerInfo& GetTable() {
      MemUnlock;
      return *(vftable_oCPlayerInfo*)GetAddress();
    }
  };


  struct vftable_oCSavegameInfo {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from oCSavegameInfo  ?_GetClassDef@oCSavegameInfo@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from oCSavegameInfo  ?Archive@oCSavegameInfo@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from oCSavegameInfo  ?Unarchive@oCSavegameInfo@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base            
      } names;
    };

    static uint GetAddress() {
      return 0x0082F2D8;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_oCSavegameInfo& GetTable() {
      MemUnlock;
      return *(vftable_oCSavegameInfo*)GetAddress();
    }
  };


  struct vftable_oCSavegameManager {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082F2EC;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCSavegameManager& GetTable() {
      MemUnlock;
      return *(vftable_oCSavegameManager*)GetAddress();
    }
  };


  struct vftable_oCSystemInfo {
    union {
      vfunc array[4];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_AnalyseNow;        // from oCSystemInfo  ?AnalyseNow@oCSystemInfo@@UAEXXZ
        vfunc f02_ScoreNow;          // from oCSystemInfo  ?ScoreNow@oCSystemInfo@@UAEXXZ
        vfunc f03_ResetSettings;     // from oCSystemInfo  ?ResetSettings@oCSystemInfo@@UAEXM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F300;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_oCSystemInfo& GetTable() {
      MemUnlock;
      return *(vftable_oCSystemInfo*)GetAddress();
    }
  };


  struct vftable_oCTriggerChangeLevel {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from oCTriggerChangeLevel  ?_GetClassDef@oCTriggerChangeLevel@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCTriggerChangeLevel  ?Archive@oCTriggerChangeLevel@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCTriggerChangeLevel  ?Unarchive@oCTriggerChangeLevel@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                  
        vfunc f04_OnTrigger;               // from zCTrigger             ?OnTrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTrigger             ?OnUntrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTrigger             ?OnTouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger             ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                 ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger             ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger             ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob                 ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger             ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob                 ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                 ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                 ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob                 ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                 ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                 ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob                 ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob                 ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                 ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                 ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                 ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                 ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase         ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob                 ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob                 ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from oCTriggerChangeLevel  ?TriggerTarget@oCTriggerChangeLevel@@UAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from oCTriggerChangeLevel  ?UntriggerTarget@oCTriggerChangeLevel@@UAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger             ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F384;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_oCTriggerChangeLevel& GetTable() {
      MemUnlock;
      return *(vftable_oCTriggerChangeLevel*)GetAddress();
    }
  };


  struct vftable_oCTriggerScript {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from oCTriggerScript  ?_GetClassDef@oCTriggerScript@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCTriggerScript  ?Archive@oCTriggerScript@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCTriggerScript  ?Unarchive@oCTriggerScript@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_OnTrigger;               // from zCTrigger        ?OnTrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTrigger        ?OnUntrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTrigger        ?OnTouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger        ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob            ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger        ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger        ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob            ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger        ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob            ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob            ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob            ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob            ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob            ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob            ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob            ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob            ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob            ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob            ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase    ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob            ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob            ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from oCTriggerScript  ?TriggerTarget@oCTriggerScript@@UAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from oCTriggerScript  ?UntriggerTarget@oCTriggerScript@@UAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger        ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F404;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_oCTriggerScript& GetTable() {
      MemUnlock;
      return *(vftable_oCTriggerScript*)GetAddress();
    }
  };


  struct vftable_oCObjectGenerator {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVob              ?_GetClassDef@zCVob@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCObjectGenerator  ?Archive@oCObjectGenerator@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCObjectGenerator  ?Unarchive@oCObjectGenerator@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from oCObjectGenerator  ?OnTrigger@oCObjectGenerator@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVob              ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob              ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob              ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob              ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob              ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob              ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob              ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob              ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob              ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob              ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F484;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_oCObjectGenerator& GetTable() {
      MemUnlock;
      return *(vftable_oCObjectGenerator*)GetAddress();
    }
  };


  struct vftable_oCViewStatusBar_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F520;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewStatusBar_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_oCViewStatusBar_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_oCViewStatusBar_for_zCViewBase {
    union {
      vfunc array[16];
      group {
        vfunc f00_anx;               // from zCView           ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView           ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView           ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView           ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView           ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView           ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView           ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase       ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView           ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base             
        vfunc f10_Blit;              // from zCView           ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView           ?DrawItems@zCView@@UAEXXZ
        vfunc f12_SetMaxRange;       // from oCViewStatusBar  ?SetMaxRange@oCViewStatusBar@@UAEXMM@Z
        vfunc f13_SetRange;          // from oCViewStatusBar  ?SetRange@oCViewStatusBar@@UAEXMM@Z
        vfunc f14_SetPreview;        // from oCViewStatusBar  ?SetPreview@oCViewStatusBar@@UAEXM@Z
        vfunc f15_SetValue;          // from oCViewStatusBar  ?SetValue@oCViewStatusBar@@UAEXM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F52C;
    }

    static uint GetFuncsNum() {
      return 16;
    }

    static vftable_oCViewStatusBar_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewStatusBar_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCBinkPlayer {
    union {
      vfunc array[15];
      group {
        vfunc f00_scalar_destructor; // from base           
        vfunc f01_OpenVideo;         // from zCBinkPlayer   ?OpenVideo@zCBinkPlayer@@UAEHVzSTRING@@@Z
        vfunc f02_CloseVideo;        // from zCBinkPlayer   ?CloseVideo@zCBinkPlayer@@UAEHXZ
        vfunc f03_PlayInit;          // from zCBinkPlayer   ?PlayInit@zCBinkPlayer@@UAEHH@Z
        vfunc f04_PlayFrame;         // from zCBinkPlayer   ?PlayFrame@zCBinkPlayer@@UAEHXZ
        vfunc f05_PlayDeinit;        // from zCBinkPlayer   ?PlayDeinit@zCBinkPlayer@@UAEHXZ
        vfunc f06_Pause;             // from zCBinkPlayer   ?Pause@zCBinkPlayer@@UAEHXZ
        vfunc f07_Unpause;           // from zCBinkPlayer   ?Unpause@zCBinkPlayer@@UAEHXZ
        vfunc f08_Stop;              // from zCVideoPlayer  ?Stop@zCVideoPlayer@@UAEHXZ
        vfunc f09_IsPlaying;         // from zCBinkPlayer   ?IsPlaying@zCBinkPlayer@@UAEHXZ
        vfunc f10_ToggleSound;       // from zCBinkPlayer   ?ToggleSound@zCBinkPlayer@@UAEHXZ
        vfunc f11_SetSoundVolume;    // from zCBinkPlayer   ?SetSoundVolume@zCBinkPlayer@@UAEMM@Z
        vfunc f12_PlayGotoNextFrame; // from zCBinkPlayer   ?PlayGotoNextFrame@zCBinkPlayer@@MAEHXZ
        vfunc f13_PlayWaitNextFrame; // from zCBinkPlayer   ?PlayWaitNextFrame@zCBinkPlayer@@MAEHXZ
        vfunc f14_PlayHandleEvents;  // from zCBinkPlayer   ?PlayHandleEvents@zCBinkPlayer@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082F594;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_zCBinkPlayer& GetTable() {
      MemUnlock;
      return *(vftable_zCBinkPlayer*)GetAddress();
    }
  };


  struct vftable_zCBuffer {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082F5F0;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCBuffer& GetTable() {
      MemUnlock;
      return *(vftable_zCBuffer*)GetAddress();
    }
  };


  struct vftable_zFILE {
    union {
      vfunc array[58];
      group {
        vfunc f00_scalar_destructor; // from base   
        vfunc f01_SetMode;           // from base   purecall
        vfunc f02_GetMode;           // from base   purecall
        vfunc f03_SetPath;           // from base   purecall
        vfunc f04_SetDrive;          // from base   purecall
        vfunc f05_SetDir;            // from base   purecall
        vfunc f06_SetFile;           // from base   purecall
        vfunc f07_SetFilename;       // from base   purecall
        vfunc f08_SetExt;            // from base   purecall
        vfunc f09_GetFileHandle;     // from base   purecall
        vfunc f10_GetFullPath;       // from base   purecall
        vfunc f11_GetPath;           // from base   purecall
        vfunc f12_GetDirectoryPath;  // from base   purecall
        vfunc f13_GetDrive;          // from base   purecall
        vfunc f14_GetDir;            // from base   purecall
        vfunc f15_GetFile;           // from base   purecall
        vfunc f16_GetFilename;       // from base   purecall
        vfunc f17_GetExt;            // from base   purecall
        vfunc f18_SetCurrentDir;     // from base   purecall
        vfunc f19_ChangeDir;         // from base   purecall
        vfunc f20_SearchFile;        // from base   purecall
        vfunc f21_FindFirst;         // from base   purecall
        vfunc f22_FindNext;          // from base   purecall
        vfunc f23_DirCreate;         // from base   purecall
        vfunc f24_DirRemove;         // from base   purecall
        vfunc f25_DirExists;         // from base   purecall
        vfunc f26_FileMove;          // from base   purecall
        vfunc f27_FileMove;          // from base   purecall
        vfunc f28_FileCopy;          // from base   purecall
        vfunc f29_FileCopy;          // from base   purecall
        vfunc f30_FileDelete;        // from base   purecall
        vfunc f31_IsOpened;          // from base   purecall
        vfunc f32_Create;            // from base   purecall
        vfunc f33_Create;            // from base   purecall
        vfunc f34_Open;              // from base   purecall
        vfunc f35_Open;              // from base   purecall
        vfunc f36_Exists;            // from base   purecall
        vfunc f37_Exists;            // from base   purecall
        vfunc f38_Close;             // from base   purecall
        vfunc f39_Reset;             // from base   purecall
        vfunc f40_Append;            // from base   purecall
        vfunc f41_Size;              // from base   purecall
        vfunc f42_Pos;               // from base   purecall
        vfunc f43_Seek;              // from base   purecall
        vfunc f44_Eof;               // from base   purecall
        vfunc f45_GetStats;          // from base   purecall
        vfunc f46_Write;             // from base   purecall
        vfunc f47_Write;             // from base   purecall
        vfunc f48_Write;             // from base   purecall
        vfunc f49_Read;              // from base   purecall
        vfunc f50_Read;              // from base   purecall
        vfunc f51_Read;              // from base   purecall
        vfunc f52_ReadChar;          // from base   purecall
        vfunc f53_SeekText;          // from base   purecall
        vfunc f54_ReadBlock;         // from base   purecall
        vfunc f55_UpdateBlock;       // from base   purecall
        vfunc f56_GetFreeDiskSpace;  // from zFILE  ?GetFreeDiskSpace@zFILE@@UAEJXZ
        vfunc f57_FlushBuffer;       // from base   purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0082F61C;
    }

    static uint GetFuncsNum() {
      return 58;
    }

    static vftable_zFILE& GetTable() {
      MemUnlock;
      return *(vftable_zFILE*)GetAddress();
    }
  };


  struct vftable_zFILE_FILE {
    union {
      vfunc array[61];
      group {
        vfunc f00_scalar_destructor; // from base        
        vfunc f01_SetMode;           // from zFILE_FILE  ?SetMode@zFILE_FILE@@UAEXJ@Z
        vfunc f02_GetMode;           // from zFILE_FILE  ?GetMode@zFILE_FILE@@UAEJXZ
        vfunc f03_SetPath;           // from zFILE_FILE  ?SetPath@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f04_SetDrive;          // from zFILE_FILE  ?SetDrive@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f05_SetDir;            // from zFILE_FILE  ?SetDir@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f06_SetFile;           // from zFILE_FILE  ?SetFile@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f07_SetFilename;       // from zFILE_FILE  ?SetFilename@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f08_SetExt;            // from zFILE_FILE  ?SetExt@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f09_GetFileHandle;     // from zFILE_FILE  ?GetFileHandle@zFILE_FILE@@UAEPAU_iobuf@@XZ
        vfunc f10_GetFullPath;       // from zFILE_FILE  ?GetFullPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f11_GetPath;           // from zFILE_FILE  ?GetPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f12_GetDirectoryPath;  // from zFILE_FILE  ?GetDirectoryPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f13_GetDrive;          // from zFILE_FILE  ?GetDrive@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f14_GetDir;            // from zFILE_FILE  ?GetDir@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f15_GetFile;           // from zFILE_FILE  ?GetFile@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f16_GetFilename;       // from zFILE_FILE  ?GetFilename@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f17_GetExt;            // from zFILE_FILE  ?GetExt@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f18_SetCurrentDir;     // from zFILE_FILE  ?SetCurrentDir@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f19_ChangeDir;         // from zFILE_FILE  ?ChangeDir@zFILE_FILE@@UAEH_N@Z
        vfunc f20_SearchFile;        // from zFILE_FILE  ?SearchFile@zFILE_FILE@@UAEHABVzSTRING@@0H@Z
        vfunc f21_FindFirst;         // from zFILE_FILE  ?FindFirst@zFILE_FILE@@UAE_NABVzSTRING@@@Z
        vfunc f22_FindNext;          // from zFILE_FILE  ?FindNext@zFILE_FILE@@UAE_NXZ
        vfunc f23_DirCreate;         // from zFILE_FILE  ?DirCreate@zFILE_FILE@@UAE_NXZ
        vfunc f24_DirRemove;         // from zFILE_FILE  ?DirRemove@zFILE_FILE@@UAE_NXZ
        vfunc f25_DirExists;         // from zFILE_FILE  ?DirExists@zFILE_FILE@@UAE_NXZ
        vfunc f26_FileMove;          // from zFILE_FILE  ?FileMove@zFILE_FILE@@UAE_NPAVzFILE@@@Z
        vfunc f27_FileMove;          // from zFILE_FILE  ?FileMove@zFILE_FILE@@UAE_NVzSTRING@@_N@Z
        vfunc f28_FileCopy;          // from zFILE_FILE  ?FileCopy@zFILE_FILE@@UAE_NPAVzFILE@@@Z
        vfunc f29_FileCopy;          // from zFILE_FILE  ?FileCopy@zFILE_FILE@@UAE_NVzSTRING@@_N@Z
        vfunc f30_FileDelete;        // from zFILE_FILE  ?FileDelete@zFILE_FILE@@UAE_NXZ
        vfunc f31_IsOpened;          // from zFILE_FILE  ?IsOpened@zFILE_FILE@@UAE_NXZ
        vfunc f32_Create;            // from zFILE_FILE  ?Create@zFILE_FILE@@UAEHABVzSTRING@@@Z
        vfunc f33_Create;            // from zFILE_FILE  ?Create@zFILE_FILE@@UAEHXZ
        vfunc f34_Open;              // from zFILE_FILE  ?Open@zFILE_FILE@@UAEHABVzSTRING@@_N@Z
        vfunc f35_Open;              // from zFILE_FILE  ?Open@zFILE_FILE@@UAEH_N@Z
        vfunc f36_Exists;            // from zFILE_FILE  ?Exists@zFILE_FILE@@UAE_NABVzSTRING@@@Z
        vfunc f37_Exists;            // from zFILE_FILE  ?Exists@zFILE_FILE@@UAE_NXZ
        vfunc f38_Close;             // from zFILE_FILE  ?Close@zFILE_FILE@@UAEHXZ
        vfunc f39_Reset;             // from zFILE_FILE  ?Reset@zFILE_FILE@@UAEHXZ
        vfunc f40_Append;            // from zFILE_FILE  ?Append@zFILE_FILE@@UAEXXZ
        vfunc f41_Size;              // from zFILE_FILE  ?Size@zFILE_FILE@@UAEJXZ
        vfunc f42_Pos;               // from zFILE_FILE  ?Pos@zFILE_FILE@@UAEJXZ
        vfunc f43_Seek;              // from zFILE_FILE  ?Seek@zFILE_FILE@@UAEHJ@Z
        vfunc f44_Eof;               // from zFILE_FILE  ?Eof@zFILE_FILE@@UAE_NXZ
        vfunc f45_GetStats;          // from zFILE_FILE  ?GetStats@zFILE_FILE@@UAEHAAVzFILE_STATS@@@Z
        vfunc f46_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEJPBXJ@Z
        vfunc f47_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEHABVzSTRING@@@Z
        vfunc f48_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEHPBD@Z
        vfunc f49_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEHAAVzSTRING@@@Z
        vfunc f50_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEHPAD@Z
        vfunc f51_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEJPAXJ@Z
        vfunc f52_ReadChar;          // from zFILE_FILE  ?ReadChar@zFILE_FILE@@UAEHAAD@Z
        vfunc f53_SeekText;          // from zFILE_FILE  ?SeekText@zFILE_FILE@@UAE?AVzSTRING@@ABV2@@Z
        vfunc f54_ReadBlock;         // from zFILE_FILE  ?ReadBlock@zFILE_FILE@@UAE?AVzSTRING@@JJ@Z
        vfunc f55_UpdateBlock;       // from zFILE_FILE  ?UpdateBlock@zFILE_FILE@@UAEHABVzSTRING@@JJ@Z
        vfunc f56_GetFreeDiskSpace;  // from zFILE       ?GetFreeDiskSpace@zFILE@@UAEJXZ
        vfunc f57_FlushBuffer;       // from zFILE_FILE  ?FlushBuffer@zFILE_FILE@@UAEJXZ
        vfunc f58_ReadCodeline;      // from zFILE_FILE  ?ReadCodeline@zFILE_FILE@@UAEHAAVzSTRING@@@Z
        vfunc f59_ReadLines;         // from zFILE_FILE  ?ReadLines@zFILE_FILE@@UAEHAAVzSTRING@@J@Z
        vfunc f60_DirStepInto;       // from zFILE_FILE  ?DirStepInto@zFILE_FILE@@UAE?AVzSTRING@@V2@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F70C;
    }

    static uint GetFuncsNum() {
      return 61;
    }

    static vftable_zFILE_FILE& GetTable() {
      MemUnlock;
      return *(vftable_zFILE_FILE*)GetAddress();
    }
  };


  struct vftable_zPATH {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082F80C;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zPATH& GetTable() {
      MemUnlock;
      return *(vftable_zPATH*)GetAddress();
    }
  };


  struct vftable_zFILE_VDFS {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082F814;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zFILE_VDFS& GetTable() {
      MemUnlock;
      return *(vftable_zFILE_VDFS*)GetAddress();
    }
  };


  struct vftable_zERROR {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082F924;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zERROR& GetTable() {
      MemUnlock;
      return *(vftable_zERROR*)GetAddress();
    }
  };


  struct vftable_zCFileCSV {
    union {
      vfunc array[61];
      group {
        vfunc f00_scalar_destructor; // from base        
        vfunc f01_SetMode;           // from zFILE_FILE  ?SetMode@zFILE_FILE@@UAEXJ@Z
        vfunc f02_GetMode;           // from zFILE_FILE  ?GetMode@zFILE_FILE@@UAEJXZ
        vfunc f03_SetPath;           // from zFILE_FILE  ?SetPath@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f04_SetDrive;          // from zFILE_FILE  ?SetDrive@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f05_SetDir;            // from zFILE_FILE  ?SetDir@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f06_SetFile;           // from zFILE_FILE  ?SetFile@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f07_SetFilename;       // from zFILE_FILE  ?SetFilename@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f08_SetExt;            // from zFILE_FILE  ?SetExt@zFILE_FILE@@UAEXVzSTRING@@@Z
        vfunc f09_GetFileHandle;     // from zFILE_FILE  ?GetFileHandle@zFILE_FILE@@UAEPAU_iobuf@@XZ
        vfunc f10_GetFullPath;       // from zFILE_FILE  ?GetFullPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f11_GetPath;           // from zFILE_FILE  ?GetPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f12_GetDirectoryPath;  // from zFILE_FILE  ?GetDirectoryPath@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f13_GetDrive;          // from zFILE_FILE  ?GetDrive@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f14_GetDir;            // from zFILE_FILE  ?GetDir@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f15_GetFile;           // from zFILE_FILE  ?GetFile@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f16_GetFilename;       // from zFILE_FILE  ?GetFilename@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f17_GetExt;            // from zFILE_FILE  ?GetExt@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f18_SetCurrentDir;     // from zFILE_FILE  ?SetCurrentDir@zFILE_FILE@@UAE?AVzSTRING@@XZ
        vfunc f19_ChangeDir;         // from zFILE_FILE  ?ChangeDir@zFILE_FILE@@UAEH_N@Z
        vfunc f20_SearchFile;        // from zFILE_FILE  ?SearchFile@zFILE_FILE@@UAEHABVzSTRING@@0H@Z
        vfunc f21_FindFirst;         // from zFILE_FILE  ?FindFirst@zFILE_FILE@@UAE_NABVzSTRING@@@Z
        vfunc f22_FindNext;          // from zFILE_FILE  ?FindNext@zFILE_FILE@@UAE_NXZ
        vfunc f23_DirCreate;         // from zFILE_FILE  ?DirCreate@zFILE_FILE@@UAE_NXZ
        vfunc f24_DirRemove;         // from zFILE_FILE  ?DirRemove@zFILE_FILE@@UAE_NXZ
        vfunc f25_DirExists;         // from zFILE_FILE  ?DirExists@zFILE_FILE@@UAE_NXZ
        vfunc f26_FileMove;          // from zFILE_FILE  ?FileMove@zFILE_FILE@@UAE_NPAVzFILE@@@Z
        vfunc f27_FileMove;          // from zFILE_FILE  ?FileMove@zFILE_FILE@@UAE_NVzSTRING@@_N@Z
        vfunc f28_FileCopy;          // from zFILE_FILE  ?FileCopy@zFILE_FILE@@UAE_NPAVzFILE@@@Z
        vfunc f29_FileCopy;          // from zFILE_FILE  ?FileCopy@zFILE_FILE@@UAE_NVzSTRING@@_N@Z
        vfunc f30_FileDelete;        // from zFILE_FILE  ?FileDelete@zFILE_FILE@@UAE_NXZ
        vfunc f31_IsOpened;          // from zFILE_FILE  ?IsOpened@zFILE_FILE@@UAE_NXZ
        vfunc f32_Create;            // from zFILE_FILE  ?Create@zFILE_FILE@@UAEHABVzSTRING@@@Z
        vfunc f33_Create;            // from zFILE_FILE  ?Create@zFILE_FILE@@UAEHXZ
        vfunc f34_Open;              // from zFILE_FILE  ?Open@zFILE_FILE@@UAEHABVzSTRING@@_N@Z
        vfunc f35_Open;              // from zFILE_FILE  ?Open@zFILE_FILE@@UAEH_N@Z
        vfunc f36_Exists;            // from zFILE_FILE  ?Exists@zFILE_FILE@@UAE_NABVzSTRING@@@Z
        vfunc f37_Exists;            // from zFILE_FILE  ?Exists@zFILE_FILE@@UAE_NXZ
        vfunc f38_Close;             // from zFILE_FILE  ?Close@zFILE_FILE@@UAEHXZ
        vfunc f39_Reset;             // from zFILE_FILE  ?Reset@zFILE_FILE@@UAEHXZ
        vfunc f40_Append;            // from zFILE_FILE  ?Append@zFILE_FILE@@UAEXXZ
        vfunc f41_Size;              // from zFILE_FILE  ?Size@zFILE_FILE@@UAEJXZ
        vfunc f42_Pos;               // from zFILE_FILE  ?Pos@zFILE_FILE@@UAEJXZ
        vfunc f43_Seek;              // from zFILE_FILE  ?Seek@zFILE_FILE@@UAEHJ@Z
        vfunc f44_Eof;               // from zFILE_FILE  ?Eof@zFILE_FILE@@UAE_NXZ
        vfunc f45_GetStats;          // from zFILE_FILE  ?GetStats@zFILE_FILE@@UAEHAAVzFILE_STATS@@@Z
        vfunc f46_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEJPBXJ@Z
        vfunc f47_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEHABVzSTRING@@@Z
        vfunc f48_Write;             // from zFILE_FILE  ?Write@zFILE_FILE@@UAEHPBD@Z
        vfunc f49_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEHAAVzSTRING@@@Z
        vfunc f50_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEHPAD@Z
        vfunc f51_Read;              // from zFILE_FILE  ?Read@zFILE_FILE@@UAEJPAXJ@Z
        vfunc f52_ReadChar;          // from zFILE_FILE  ?ReadChar@zFILE_FILE@@UAEHAAD@Z
        vfunc f53_SeekText;          // from zFILE_FILE  ?SeekText@zFILE_FILE@@UAE?AVzSTRING@@ABV2@@Z
        vfunc f54_ReadBlock;         // from zFILE_FILE  ?ReadBlock@zFILE_FILE@@UAE?AVzSTRING@@JJ@Z
        vfunc f55_UpdateBlock;       // from zFILE_FILE  ?UpdateBlock@zFILE_FILE@@UAEHABVzSTRING@@JJ@Z
        vfunc f56_GetFreeDiskSpace;  // from zFILE       ?GetFreeDiskSpace@zFILE@@UAEJXZ
        vfunc f57_FlushBuffer;       // from zFILE_FILE  ?FlushBuffer@zFILE_FILE@@UAEJXZ
        vfunc f58_ReadCodeline;      // from zFILE_FILE  ?ReadCodeline@zFILE_FILE@@UAEHAAVzSTRING@@@Z
        vfunc f59_ReadLines;         // from zFILE_FILE  ?ReadLines@zFILE_FILE@@UAEHAAVzSTRING@@J@Z
        vfunc f60_DirStepInto;       // from zFILE_FILE  ?DirStepInto@zFILE_FILE@@UAE?AVzSTRING@@V2@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082F92C;
    }

    static uint GetFuncsNum() {
      return 61;
    }

    static vftable_zCFileCSV& GetTable() {
      MemUnlock;
      return *(vftable_zCFileCSV*)GetAddress();
    }
  };


  struct vftable_zCGameInfo {
    union {
      vfunc array[12];
      group {
        vfunc f00_scalar_destructor;     // from base        
        vfunc f01_Init;                  // from zCGameInfo  ?Init@zCGameInfo@@UAEXXZ
        vfunc f02_Reset;                 // from zCGameInfo  ?Reset@zCGameInfo@@UAEXXZ
        vfunc f03_SetName;               // from zCGameInfo  ?SetName@zCGameInfo@@UAEXABVzSTRING@@@Z
        vfunc f04_GetName;               // from zCGameInfo  ?GetName@zCGameInfo@@UBE?AVzSTRING@@XZ
        vfunc f05_AddPlayer;             // from zCGameInfo  ?AddPlayer@zCGameInfo@@UAEHPAVzCPlayerInfo@@@Z
        vfunc f06_RemPlayer;             // from zCGameInfo  ?RemPlayer@zCGameInfo@@UAEHPAVzCPlayerInfo@@@Z
        vfunc f07_GetPlayerByID;         // from zCGameInfo  ?GetPlayerByID@zCGameInfo@@UAEPAVzCPlayerInfo@@H@Z
        vfunc f08_GetPlayerByVobID;      // from zCGameInfo  ?GetPlayerByVobID@zCGameInfo@@UAEPAVzCPlayerInfo@@K@Z
        vfunc f09_GetPlayerByNetAddress; // from zCGameInfo  ?GetPlayerByNetAddress@zCGameInfo@@UAEPAVzCPlayerInfo@@AAUzTNetAddress@@@Z
        vfunc f10_Pack;                  // from zCGameInfo  ?Pack@zCGameInfo@@MAEXAAVzCBuffer@@E@Z
        vfunc f11_Unpack;                // from zCGameInfo  ?Unpack@zCGameInfo@@MAEXAAVzCBuffer@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FA38;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCGameInfo& GetTable() {
      MemUnlock;
      return *(vftable_zCGameInfo*)GetAddress();
    }
  };


  struct vftable_zCNet {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FA80;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCNet& GetTable() {
      MemUnlock;
      return *(vftable_zCNet*)GetAddress();
    }
  };


  struct vftable_zCNetStatistics {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FA88;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCNetStatistics& GetTable() {
      MemUnlock;
      return *(vftable_zCNetStatistics*)GetAddress();
    }
  };


  struct vftable_zCNetEventManager {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;        // from zCNetEventManager  ?_GetClassDef@zCNetEventManager@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;            // from zCNetEventManager  ?Archive@zCNetEventManager@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;          // from zCNetEventManager  ?Unarchive@zCNetEventManager@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;  // from base               
        vfunc f04_OnTrigger;          // from zCEventManager     ?OnTrigger@zCEventManager@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;        // from zCEventManager     ?OnUntrigger@zCEventManager@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;            // from zCEventManager     ?OnTouch@zCEventManager@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;          // from zCEventManager     ?OnUntouch@zCEventManager@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;       // from zCEventManager     ?OnTouchLevel@zCEventManager@@UAEXXZ
        vfunc f09_OnDamage;           // from zCEventManager     ?OnDamage@zCEventManager@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;          // from zCNetEventManager  ?OnMessage@zCNetEventManager@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_Clear;              // from zCEventManager     ?Clear@zCEventManager@@UAEXXZ
        vfunc f12_IsEmpty;            // from zCEventManager     ?IsEmpty@zCEventManager@@UAEHH@Z
        vfunc f13_GetCutsceneMode;    // from zCEventManager     ?GetCutsceneMode@zCEventManager@@UAEHXZ
        vfunc f14_SetCutscene;        // from zCEventManager     ?SetCutscene@zCEventManager@@UAEXPAVzCCutscene@@@Z
        vfunc f15_GetCutscene;        // from zCEventManager     ?GetCutscene@zCEventManager@@UAEPAVzCCutscene@@XZ
        vfunc f16_IsRunning;          // from zCEventManager     ?IsRunning@zCEventManager@@UAEHPAVzCEventMessage@@@Z
        vfunc f17_SetActive;          // from zCEventManager     ?SetActive@zCEventManager@@UAEXH@Z
        vfunc f18_GetNumMessages;     // from zCEventManager     ?GetNumMessages@zCEventManager@@UAEHXZ
        vfunc f19_GetEventMessage;    // from zCEventManager     ?GetEventMessage@zCEventManager@@UAEPAVzCEventMessage@@H@Z
        vfunc f20_GetActiveMessage;   // from zCEventManager     ?GetActiveMessage@zCEventManager@@UAEPAVzCEventMessage@@XZ
        vfunc f21_ShowList;           // from zCEventManager     ?ShowList@zCEventManager@@UAEXHH@Z
        vfunc f22_GetNetVobControl;   // from zCNetEventManager  ?GetNetVobControl@zCNetEventManager@@UAEPAVzCNetVobControl@@H@Z
        vfunc f23_RemoveFromList;     // from zCEventManager     ?RemoveFromList@zCEventManager@@MAEXPAVzCEventMessage@@@Z
        vfunc f24_InsertInList;       // from zCEventManager     ?InsertInList@zCEventManager@@MAEXPAVzCEventMessage@@@Z
        vfunc f25_ProcessMessageList; // from zCEventManager     ?ProcessMessageList@zCEventManager@@MAEXXZ
        vfunc f26_SendMessageToHost;  // from zCEventManager     ?SendMessageToHost@zCEventManager@@MAEXPAVzCEventMessage@@PAVzCVob@@1@Z
        vfunc f27_Delete;             // from zCEventManager     ?Delete@zCEventManager@@MAEXPAVzCEventMessage@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FACC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCNetEventManager& GetTable() {
      MemUnlock;
      return *(vftable_zCNetEventManager*)GetAddress();
    }
  };


  struct vftable_zCNetHost {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FB54;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCNetHost& GetTable() {
      MemUnlock;
      return *(vftable_zCNetHost*)GetAddress();
    }
  };


  struct vftable_zCNetManager {
    union {
      vfunc array[8];
      group {
        vfunc f00_GetClassDef;       // from zCNetManager  ?_GetClassDef@zCNetManager@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject      ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject      ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base          
        vfunc f04_Process;           // from zCNetManager  ?Process@zCNetManager@@UAEXXZ
        vfunc f05_CreateNetMessage;  // from zCNetManager  ?CreateNetMessage@zCNetManager@@UAEPAVzCNetMessage@@ABGPAVzCObject@@@Z
        vfunc f06_HandleNetMessage;  // from zCNetManager  ?HandleNetMessage@zCNetManager@@UAEHPAVzCNetMessage@@ABGPAVzCClassDef@@PAVzCWorld@@@Z
        vfunc f07_ProcessMessages;   // from zCNetManager  ?ProcessMessages@zCNetManager@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082FB70;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCNetManager& GetTable() {
      MemUnlock;
      return *(vftable_zCNetManager*)GetAddress();
    }
  };


  struct vftable_zCNetMessage {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FBA8;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCNetMessage& GetTable() {
      MemUnlock;
      return *(vftable_zCNetMessage*)GetAddress();
    }
  };


  struct vftable_zCNetSession {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FBB0;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCNetSession& GetTable() {
      MemUnlock;
      return *(vftable_zCNetSession*)GetAddress();
    }
  };


  struct vftable_zCNetVersion {
    union {
      vfunc array[7];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_GetVersionString;  // from zCNetVersion  ?GetVersionString@zCNetVersion@@UBE?AVzSTRING@@XZ
        vfunc f02_GetVersionNumber;  // from zCNetVersion  ?GetVersionNumber@zCNetVersion@@UBEJXZ
        vfunc f03_GetChecksum;       // from zCNetVersion  ?GetChecksum@zCNetVersion@@UBEJXZ
        vfunc f04_CreateChecksum;    // from zCNetVersion  ?CreateChecksum@zCNetVersion@@UAEJXZ
        vfunc f05_Pack;              // from zCNetVersion  ?Pack@zCNetVersion@@UBEXAAVzCBuffer@@@Z
        vfunc f06_Unpack;            // from zCNetVersion  ?Unpack@zCNetVersion@@UAEXAAVzCBuffer@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FBB8;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCNetVersion& GetTable() {
      MemUnlock;
      return *(vftable_zCNetVersion*)GetAddress();
    }
  };


  struct vftable_zCNetVobControl {
    union {
      vfunc array[14];
      group {
        vfunc f00_GetClassDef;       // from zCNetVobControl  ?_GetClassDef@zCNetVobControl@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCNetVobControl  ?Archive@zCNetVobControl@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCNetVobControl  ?Unarchive@zCNetVobControl@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base             
        vfunc f04_Init;              // from zCNetVobControl  ?Init@zCNetVobControl@@UAEXPAVzCVob@@@Z
        vfunc f05_IsLocalChained;    // from zCNetVobControl  ?IsLocalChained@zCNetVobControl@@UAEHXZ
        vfunc f06_IsLocalControlled; // from zCNetVobControl  ?IsLocalControlled@zCNetVobControl@@UAEHXZ
        vfunc f07_IsPlayerVob;       // from zCNetVobControl  ?IsPlayerVob@zCNetVobControl@@UAEHXZ
        vfunc f08_SetLocalChained;   // from zCNetVobControl  ?SetLocalChained@zCNetVobControl@@UAEXH@Z
        vfunc f09_SetCtrlPlayer;     // from zCNetVobControl  ?SetCtrlPlayer@zCNetVobControl@@UAEXPAVzCPlayerInfo@@@Z
        vfunc f10_CopyCtrlState;     // from zCNetVobControl  ?CopyCtrlState@zCNetVobControl@@UAEXPAVzCVob@@@Z
        vfunc f11_Process;           // from zCNetVobControl  ?Process@zCNetVobControl@@UAEHXZ
        vfunc f12_HandOverToPlayer;  // from zCNetVobControl  ?HandOverToPlayer@zCNetVobControl@@UAEHPAVzCPlayerInfo@@@Z
        vfunc f13_CreateNetMessage;  // from zCNetVobControl  ?CreateNetMessage@zCNetVobControl@@UAEPAVzCNetMessage@@ABG@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FBEC;
    }

    static uint GetFuncsNum() {
      return 14;
    }

    static vftable_zCNetVobControl& GetTable() {
      MemUnlock;
      return *(vftable_zCNetVobControl*)GetAddress();
    }
  };


  struct vftable_zCOption {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FC30;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCOption& GetTable() {
      MemUnlock;
      return *(vftable_zCOption*)GetAddress();
    }
  };


  struct vftable_zCPlayerGroup {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FC50;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCPlayerGroup& GetTable() {
      MemUnlock;
      return *(vftable_zCPlayerGroup*)GetAddress();
    }
  };


  struct vftable_zCPlayerInfo {
    union {
      vfunc array[12];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_Init;              // from zCPlayerInfo  ?Init@zCPlayerInfo@@UAEXABVzSTRING@@PAX@Z
        vfunc f02_Init;              // from zCPlayerInfo  ?Init@zCPlayerInfo@@UAEXABVzSTRING@@0@Z
        vfunc f03_SetName;           // from zCPlayerInfo  ?SetName@zCPlayerInfo@@UAEXABVzSTRING@@@Z
        vfunc f04_SetPlayerVob;      // from zCPlayerInfo  ?SetPlayerVob@zCPlayerInfo@@UAEXPAVzCVob@@@Z
        vfunc f05_Reset;             // from zCPlayerInfo  ?Reset@zCPlayerInfo@@UAEXXZ
        vfunc f06_Deactivate;        // from zCPlayerInfo  ?Deactivate@zCPlayerInfo@@UAEXH@Z
        vfunc f07_IsDeactivated;     // from zCPlayerInfo  ?IsDeactivated@zCPlayerInfo@@UBEHXZ
        vfunc f08_SetReady;          // from zCPlayerInfo  ?SetReady@zCPlayerInfo@@UAEXH@Z
        vfunc f09_IsReady;           // from zCPlayerInfo  ?IsReady@zCPlayerInfo@@UBEHXZ
        vfunc f10_Pack;              // from zCPlayerInfo  ?Pack@zCPlayerInfo@@MAEXAAVzCBuffer@@@Z
        vfunc f11_Unpack;            // from zCPlayerInfo  ?Unpack@zCPlayerInfo@@MAEXAAVzCBuffer@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FC6C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCPlayerInfo& GetTable() {
      MemUnlock;
      return *(vftable_zCPlayerInfo*)GetAddress();
    }
  };


  struct vftable_zCScanDirFileHandler {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base  
        vfunc f01_HandleFile;        // from base  purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0082FCA0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCScanDirFileHandler& GetTable() {
      MemUnlock;
      return *(vftable_zCScanDirFileHandler*)GetAddress();
    }
  };


  struct vftable_zCScanDir {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor;   // from base       
        vfunc f01_RegisterFileHandler; // from zCScanDir  ?RegisterFileHandler@zCScanDir@@UAEXPAVzCScanDirFileHandler@@ABVzSTRING@@@Z
        vfunc f02_Scan;                // from zCScanDir  ?Scan@zCScanDir@@UAEXABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FCAC;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCScanDir& GetTable() {
      MemUnlock;
      return *(vftable_zCScanDir*)GetAddress();
    }
  };


  struct vftable_zCSystemInfo {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_AnalyseNow;        // from zCSystemInfo  ?AnalyseNow@zCSystemInfo@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082FED0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCSystemInfo& GetTable() {
      MemUnlock;
      return *(vftable_zCSystemInfo*)GetAddress();
    }
  };


  struct vftable_zCVideoPlayer {
    union {
      vfunc array[14];
      group {
        vfunc f00_scalar_destructor; // from base           
        vfunc f01_OpenVideo;         // from zCVideoPlayer  ?OpenVideo@zCVideoPlayer@@UAEHVzSTRING@@@Z
        vfunc f02_CloseVideo;        // from zCVideoPlayer  ?CloseVideo@zCVideoPlayer@@UAEHXZ
        vfunc f03_PlayInit;          // from zCVideoPlayer  ?PlayInit@zCVideoPlayer@@UAEHH@Z
        vfunc f04_PlayFrame;         // from zCVideoPlayer  ?PlayFrame@zCVideoPlayer@@UAEHXZ
        vfunc f05_PlayDeinit;        // from zCVideoPlayer  ?PlayDeinit@zCVideoPlayer@@UAEHXZ
        vfunc f06_Pause;             // from zCVideoPlayer  ?Pause@zCVideoPlayer@@UAEHXZ
        vfunc f07_Unpause;           // from zCVideoPlayer  ?Unpause@zCVideoPlayer@@UAEHXZ
        vfunc f08_Stop;              // from zCVideoPlayer  ?Stop@zCVideoPlayer@@UAEHXZ
        vfunc f09_IsPlaying;         // from zCVideoPlayer  ?IsPlaying@zCVideoPlayer@@UAEHXZ
        vfunc f10_ToggleSound;       // from zCVideoPlayer  ?ToggleSound@zCVideoPlayer@@UAEHXZ
        vfunc f11_SetSoundVolume;    // from zCVideoPlayer  ?SetSoundVolume@zCVideoPlayer@@UAEMM@Z
        vfunc f12_PlayGotoNextFrame; // from zCVideoPlayer  ?PlayGotoNextFrame@zCVideoPlayer@@MAEHXZ
        vfunc f13_PlayWaitNextFrame; // from zCVideoPlayer  ?PlayWaitNextFrame@zCVideoPlayer@@MAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082FEDC;
    }

    static uint GetFuncsNum() {
      return 14;
    }

    static vftable_zCVideoPlayer& GetTable() {
      MemUnlock;
      return *(vftable_zCVideoPlayer*)GetAddress();
    }
  };


  struct vftable_zCViewProgressBar_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FF24;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewProgressBar_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCViewProgressBar_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCViewProgressBar_for_zCViewBase {
    union {
      vfunc array[15];
      group {
        vfunc f00_anx;               // from zCView             ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView             ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView             ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView             ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView             ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView             ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView             ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase         ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView             ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base               
        vfunc f10_Blit;              // from zCView             ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView             ?DrawItems@zCView@@UAEXXZ
        vfunc f12_Init;              // from zCViewProgressBar  ?Init@zCViewProgressBar@@UAEXXZ
        vfunc f13_HandleChange;      // from zCViewProgressBar  ?HandleChange@zCViewProgressBar@@UAEXXZ
        vfunc f14_Draw;              // from zCViewProgressBar  ?Draw@zCViewProgressBar@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0082FF2C;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_zCViewProgressBar_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewProgressBar_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewStatusBar_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FF78;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewStatusBar_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCViewStatusBar_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCViewStatusBar_for_zCViewBase {
    union {
      vfunc array[16];
      group {
        vfunc f00_anx;               // from zCView           ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView           ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView           ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView           ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView           ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView           ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView           ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase       ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView           ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base             
        vfunc f10_Blit;              // from zCView           ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView           ?DrawItems@zCView@@UAEXXZ
        vfunc f12_SetMaxRange;       // from zCViewStatusBar  ?SetMaxRange@zCViewStatusBar@@UAEXMM@Z
        vfunc f13_SetRange;          // from zCViewStatusBar  ?SetRange@zCViewStatusBar@@UAEXMM@Z
        vfunc f14_SetPreview;        // from zCViewStatusBar  ?SetPreview@zCViewStatusBar@@UAEXM@Z
        vfunc f15_SetValue;          // from zCViewStatusBar  ?SetValue@zCViewStatusBar@@UAEXM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0082FF84;
    }

    static uint GetFuncsNum() {
      return 16;
    }

    static vftable_zCViewStatusBar_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewStatusBar_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCWorldInfo {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0082FFDC;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCWorldInfo& GetTable() {
      MemUnlock;
      return *(vftable_zCWorldInfo*)GetAddress();
    }
  };


  struct vftable_oCMenu_Main {
    union {
      vfunc array[18];
      group {
        vfunc f00_HandleEvent;        // from oCMenu_Main  ?HandleEvent@oCMenu_Main@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from zCMenu       ?HandleEnterItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from zCMenu       ?HandleLeaveItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from zCMenu       ?HandleActivateItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu       ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu       ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from zCMenu       ?Leave@zCMenu@@UAEXXZ
        vfunc f07_Render;             // from zCMenu       ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu       ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu       ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from zCMenu       ?Activate@zCMenu@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base         
        vfunc f12_ScreenInit;         // from oCMenu_Main  ?ScreenInit@oCMenu_Main@@MAEXXZ
        vfunc f13_ScreenDone;         // from oCMenu_Main  ?ScreenDone@oCMenu_Main@@MAEXXZ
        vfunc f14_HandleAction;       // from zCMenu       ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu       ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu       ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from zCMenu       ?ExecCommand@zCMenu@@MAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008300B4;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCMenu_Main& GetTable() {
      MemUnlock;
      return *(vftable_oCMenu_Main*)GetAddress();
    }
  };


  struct vftable_oCMenu_ChgKeys {
    union {
      vfunc array[18];
      group {
        vfunc f00_HandleEvent;        // from oCMenu_ChgKeys  ?HandleEvent@oCMenu_ChgKeys@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from zCMenu          ?HandleEnterItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from zCMenu          ?HandleLeaveItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from zCMenu          ?HandleActivateItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu          ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu          ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from oCMenu_ChgKeys  ?Leave@oCMenu_ChgKeys@@UAEXXZ
        vfunc f07_Render;             // from zCMenu          ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu          ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu          ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from zCMenu          ?Activate@zCMenu@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base            
        vfunc f12_ScreenInit;         // from oCMenu_ChgKeys  ?ScreenInit@oCMenu_ChgKeys@@UAEXXZ
        vfunc f13_ScreenDone;         // from zCMenu          ?ScreenDone@zCMenu@@MAEXXZ
        vfunc f14_HandleAction;       // from zCMenu          ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu          ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu          ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from oCMenu_ChgKeys  ?ExecCommand@oCMenu_ChgKeys@@UAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830104;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCMenu_ChgKeys& GetTable() {
      MemUnlock;
      return *(vftable_oCMenu_ChgKeys*)GetAddress();
    }
  };


  struct vftable_oCMenu_Log {
    union {
      vfunc array[18];
      group {
        vfunc f00_HandleEvent;        // from oCMenu_Log  ?HandleEvent@oCMenu_Log@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from oCMenu_Log  ?HandleEnterItem@oCMenu_Log@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from oCMenu_Log  ?HandleLeaveItem@oCMenu_Log@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from oCMenu_Log  ?HandleActivateItem@oCMenu_Log@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu      ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu      ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from zCMenu      ?Leave@zCMenu@@UAEXXZ
        vfunc f07_Render;             // from zCMenu      ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu      ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu      ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from oCMenu_Log  ?Activate@oCMenu_Log@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base        
        vfunc f12_ScreenInit;         // from oCMenu_Log  ?ScreenInit@oCMenu_Log@@UAEXXZ
        vfunc f13_ScreenDone;         // from oCMenu_Log  ?ScreenDone@oCMenu_Log@@UAEXXZ
        vfunc f14_HandleAction;       // from zCMenu      ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu      ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu      ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from oCMenu_Log  ?ExecCommand@oCMenu_Log@@UAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083016C;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCMenu_Log& GetTable() {
      MemUnlock;
      return *(vftable_oCMenu_Log*)GetAddress();
    }
  };


  struct vftable_oCMenu_Status {
    union {
      vfunc array[18];
      group {
        vfunc f00_HandleEvent;        // from oCMenu_Status  ?HandleEvent@oCMenu_Status@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from zCMenu         ?HandleEnterItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from zCMenu         ?HandleLeaveItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from zCMenu         ?HandleActivateItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu         ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu         ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from zCMenu         ?Leave@zCMenu@@UAEXXZ
        vfunc f07_Render;             // from zCMenu         ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu         ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu         ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from zCMenu         ?Activate@zCMenu@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base           
        vfunc f12_ScreenInit;         // from zCMenu         ?ScreenInit@zCMenu@@MAEXXZ
        vfunc f13_ScreenDone;         // from zCMenu         ?ScreenDone@zCMenu@@MAEXXZ
        vfunc f14_HandleAction;       // from zCMenu         ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu         ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu         ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from zCMenu         ?ExecCommand@zCMenu@@MAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008301BC;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCMenu_Status& GetTable() {
      MemUnlock;
      return *(vftable_oCMenu_Status*)GetAddress();
    }
  };


  struct vftable_oCStatusScreen {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00830208;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCStatusScreen& GetTable() {
      MemUnlock;
      return *(vftable_oCStatusScreen*)GetAddress();
    }
  };


  struct vftable_oCLogScreen {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00830210;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCLogScreen& GetTable() {
      MemUnlock;
      return *(vftable_oCLogScreen*)GetAddress();
    }
  };


  struct vftable_oCMapScreen {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00830218;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCMapScreen& GetTable() {
      MemUnlock;
      return *(vftable_oCMapScreen*)GetAddress();
    }
  };


  struct vftable_oCSpell {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from oCSpell  ?_GetClassDef@oCSpell@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from oCSpell  ?Archive@oCSpell@@EAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from oCSpell  ?Unarchive@oCSpell@@EAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base     
      } names;
    };

    static uint GetAddress() {
      return 0x00830260;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_oCSpell& GetTable() {
      MemUnlock;
      return *(vftable_oCSpell*)GetAddress();
    }
  };


  struct vftable_oCVisualFX {
    union {
      vfunc array[78];
      group {
        vfunc f00_GetClassDef;               // from oCVisualFX  ?_GetClassDef@oCVisualFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                   // from oCVisualFX  ?Archive@oCVisualFX@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                 // from oCVisualFX  ?Unarchive@oCVisualFX@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;         // from base        
        vfunc f04_OnTrigger;                 // from zCVob       ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;               // from zCVob       ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                   // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                 // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;              // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                  // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                 // from zCVob       ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                    // from oCVisualFX  ?OnTick@oCVisualFX@@UAEXXZ
        vfunc f12_OnTimer;                   // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                  // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;         // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;           // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;               // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;        // from oCVisualFX  ?CanThisCollideWith@oCVisualFX@@UAEHPAVzCVob@@@Z
        vfunc f18_Render;                    // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                 // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                 // from zCVob       ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;         // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;       // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;           // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                  // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;          // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;       // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;   // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Open;                      // from oCVisualFX  ?Open@oCVisualFX@@UAEXXZ
        vfunc f29_SetOrigin;                 // from oCVisualFX  ?SetOrigin@oCVisualFX@@UAEXPAVzCVob@@H@Z
        vfunc f30_SetTarget;                 // from oCVisualFX  ?SetTarget@oCVisualFX@@UAEXAAVzVEC3@@H@Z
        vfunc f31_SetTarget;                 // from oCVisualFX  ?SetTarget@oCVisualFX@@UAEXPAVzCVob@@H@Z
        vfunc f32_SetInflictor;              // from oCVisualFX  ?SetInflictor@oCVisualFX@@UAEXPAVzCVob@@@Z
        vfunc f33_GetOrigin;                 // from oCVisualFX  ?GetOrigin@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f34_GetTarget;                 // from oCVisualFX  ?GetTarget@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f35_GetInflictor;              // from oCVisualFX  ?GetInflictor@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f36_Init;                      // from oCVisualFX  ?Init@oCVisualFX@@UAEXABV?$zCArray@PAVzCVob@@@@@Z
        vfunc f37_Init;                      // from oCVisualFX  ?Init@oCVisualFX@@UAEXPBVzCVob@@00@Z
        vfunc f38_Init;                      // from oCVisualFX  ?Init@oCVisualFX@@UAEXPBVzCVob@@ABVzVEC3@@@Z
        vfunc f39_InvestNext;                // from oCVisualFX  ?InvestNext@oCVisualFX@@UAEXXZ
        vfunc f40_SetLevel;                  // from oCVisualFX  ?SetLevel@oCVisualFX@@UAEXHH@Z
        vfunc f41_GetLevel;                  // from oCVisualFX  ?GetLevel@oCVisualFX@@UBEHXZ
        vfunc f42_Cast;                      // from oCVisualFX  ?Cast@oCVisualFX@@UAEXH@Z
        vfunc f43_Stop;                      // from oCVisualFX  ?Stop@oCVisualFX@@UAEXH@Z
        vfunc f44_Kill;                      // from oCVisualFX  ?Kill@oCVisualFX@@UAEXXZ
        vfunc f45_Play;                      // from oCVisualFX  ?Play@oCVisualFX@@UAEXMPBVzMAT4@@0@Z
        vfunc f46_CanBeDeleted;              // from oCVisualFX  ?CanBeDeleted@oCVisualFX@@UAEHXZ
        vfunc f47_IsFinished;                // from oCVisualFX  ?IsFinished@oCVisualFX@@UAEHXZ
        vfunc f48_IsLooping;                 // from oCVisualFX  ?IsLooping@oCVisualFX@@UAEHXZ
        vfunc f49_SetByScript;               // from oCVisualFX  ?SetByScript@oCVisualFX@@UAEXABVzSTRING@@@Z
        vfunc f50_SetDuration;               // from oCVisualFX  ?SetDuration@oCVisualFX@@UAEXM@Z
        vfunc f51_Reset;                     // from oCVisualFX  ?Reset@oCVisualFX@@UAEXXZ
        vfunc f52_ResetForEditing;           // from oCVisualFX  ?ResetForEditing@oCVisualFX@@UAEXXZ
        vfunc f53_ReportCollision;           // from oCVisualFX  ?ReportCollision@oCVisualFX@@UAEXABVzCCollisionReport@@@Z
        vfunc f54_SetCollisionEnabled;       // from oCVisualFX  ?SetCollisionEnabled@oCVisualFX@@UAEXH@Z
        vfunc f55_SetCollisionCandidates;    // from oCVisualFX  ?SetCollisionCandidates@oCVisualFX@@UAEXV?$zCArray@PAVzCVob@@@@@Z
        vfunc f56_GetCollisionCandidates;    // from oCVisualFX  ?GetCollisionCandidates@oCVisualFX@@UAEXAAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f57_GetNumCollisionCandidates; // from oCVisualFX  ?GetNumCollisionCandidates@oCVisualFX@@UAEHXZ
        vfunc f58_GetCollidedCandidates;     // from oCVisualFX  ?GetCollidedCandidates@oCVisualFX@@UAEHAAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f59_SetDamage;                 // from oCVisualFX  ?SetDamage@oCVisualFX@@UAEXM@Z
        vfunc f60_SetDamageType;             // from oCVisualFX  ?SetDamageType@oCVisualFX@@UAEXH@Z
        vfunc f61_GetDamage;                 // from oCVisualFX  ?GetDamage@oCVisualFX@@UBEMXZ
        vfunc f62_GetDamageType;             // from oCVisualFX  ?GetDamageType@oCVisualFX@@UBEHXZ
        vfunc f63_IsASpell;                  // from oCVisualFX  ?IsASpell@oCVisualFX@@UAEHXZ
        vfunc f64_SetSpellType;              // from oCVisualFX  ?SetSpellType@oCVisualFX@@UAEXH@Z
        vfunc f65_GetSpellType;              // from oCVisualFX  ?GetSpellType@oCVisualFX@@UBEHXZ
        vfunc f66_SetSpellCat;               // from oCVisualFX  ?SetSpellCat@oCVisualFX@@UAEXH@Z
        vfunc f67_GetSpellCat;               // from oCVisualFX  ?GetSpellCat@oCVisualFX@@UBEHXZ
        vfunc f68_GetSpellTargetTypes;       // from oCVisualFX  ?GetSpellTargetTypes@oCVisualFX@@UBEHXZ
        vfunc f69_SetSpellTargetTypes;       // from oCVisualFX  ?SetSpellTargetTypes@oCVisualFX@@UAEXH@Z
        vfunc f70_GetSendsAssessMagic;       // from oCVisualFX  ?GetSendsAssessMagic@oCVisualFX@@UAEHXZ
        vfunc f71_SetSendsAssessMagic;       // from oCVisualFX  ?SetSendsAssessMagic@oCVisualFX@@UAEXH@Z
        vfunc f72_GetIsProjectile;           // from oCVisualFX  ?GetIsProjectile@oCVisualFX@@UAEHXZ
        vfunc f73_SetIsProjectile;           // from oCVisualFX  ?SetIsProjectile@oCVisualFX@@UAEXH@Z
        vfunc f74_SetVisualByString;         // from oCVisualFX  ?SetVisualByString@oCVisualFX@@MAEXABVzSTRING@@@Z
        vfunc f75_CalcTrajectory;            // from oCVisualFX  ?CalcTrajectory@oCVisualFX@@MAEXABH@Z
        vfunc f76_Collide;                   // from oCVisualFX  ?Collide@oCVisualFX@@MAEXH@Z
        vfunc f77_CollisionResponse;         // from oCVisualFX  ?CollisionResponse@oCVisualFX@@MAEXABVzVEC3@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083029C;
    }

    static uint GetFuncsNum() {
      return 78;
    }

    static vftable_oCVisualFX& GetTable() {
      MemUnlock;
      return *(vftable_oCVisualFX*)GetAddress();
    }
  };


  struct vftable_zCEffect {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCEffect  ?_GetClassDef@zCEffect@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob     ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob     ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_OnTrigger;               // from zCVob     ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob     ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob     ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob     ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob     ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob     ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob     ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob     ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob     ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob     ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob     ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob     ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob     ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob     ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob     ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob     ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob     ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob     ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob     ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob     ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob     ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob     ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob     ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob     ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008303DC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCEffect& GetTable() {
      MemUnlock;
      return *(vftable_zCEffect*)GetAddress();
    }
  };


  struct vftable_oCVisualFXAI {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from zCAIBase      ?_GetClassDef@zCAIBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject      ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject      ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base          
        vfunc f04_DoAI;                            // from oCVisualFXAI  ?DoAI@oCVisualFXAI@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase      ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCVisualFXAI  ?ReportCollisionToAI@oCVisualFXAI@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase      ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase      ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase      ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from oCVisualFXAI  ?HostVobAddedToWorld@oCVisualFXAI@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from oCVisualFXAI  ?GetIsProjectile@oCVisualFXAI@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830450;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCVisualFXAI& GetTable() {
      MemUnlock;
      return *(vftable_oCVisualFXAI*)GetAddress();
    }
  };


  struct vftable_zCAIBase {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from zCAIBase  ?_GetClassDef@zCAIBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base      
        vfunc f04_DoAI;                            // from base      purecall
        vfunc f05_CanThisCollideWith;              // from zCAIBase  ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase  ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase  ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase  ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase  ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase  ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase  ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830484;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCAIBase& GetTable() {
      MemUnlock;
      return *(vftable_zCAIBase*)GetAddress();
    }
  };


  struct vftable_oCVisFX_MultiTarget {
    union {
      vfunc array[80];
      group {
        vfunc f00_GetClassDef;               // from oCVisFX_MultiTarget  ?_GetClassDef@oCVisFX_MultiTarget@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                   // from oCVisFX_MultiTarget  ?Archive@oCVisFX_MultiTarget@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                 // from oCVisFX_MultiTarget  ?Unarchive@oCVisFX_MultiTarget@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;         // from base                 
        vfunc f04_OnTrigger;                 // from zCVob                ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;               // from zCVob                ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                   // from zCVob                ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                 // from zCVob                ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;              // from zCVob                ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                  // from zCVob                ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                 // from zCVob                ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                    // from oCVisualFX           ?OnTick@oCVisualFX@@UAEXXZ
        vfunc f12_OnTimer;                   // from zCVob                ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                  // from zCVob                ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;         // from zCVob                ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;           // from zCVob                ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;               // from zCVob                ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;        // from oCVisualFX           ?CanThisCollideWith@oCVisualFX@@UAEHPAVzCVob@@@Z
        vfunc f18_Render;                    // from zCVob                ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                 // from zCVob                ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                 // from zCVob                ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;         // from zCVob                ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;       // from zCVob                ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;           // from zCVob                ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                  // from zCVob                ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;          // from zCVob                ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;       // from zCVob                ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;   // from zCVob                ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Open;                      // from oCVisFX_MultiTarget  ?Open@oCVisFX_MultiTarget@@UAEXXZ
        vfunc f29_SetOrigin;                 // from oCVisualFX           ?SetOrigin@oCVisualFX@@UAEXPAVzCVob@@H@Z
        vfunc f30_SetTarget;                 // from oCVisualFX           ?SetTarget@oCVisualFX@@UAEXAAVzVEC3@@H@Z
        vfunc f31_SetTarget;                 // from oCVisualFX           ?SetTarget@oCVisualFX@@UAEXPAVzCVob@@H@Z
        vfunc f32_SetInflictor;              // from oCVisualFX           ?SetInflictor@oCVisualFX@@UAEXPAVzCVob@@@Z
        vfunc f33_GetOrigin;                 // from oCVisualFX           ?GetOrigin@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f34_GetTarget;                 // from oCVisualFX           ?GetTarget@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f35_GetInflictor;              // from oCVisualFX           ?GetInflictor@oCVisualFX@@UAEPAVzCVob@@XZ
        vfunc f36_Init;                      // from oCVisualFX           ?Init@oCVisualFX@@UAEXABV?$zCArray@PAVzCVob@@@@@Z
        vfunc f37_Init;                      // from oCVisualFX           ?Init@oCVisualFX@@UAEXPBVzCVob@@00@Z
        vfunc f38_Init;                      // from oCVisualFX           ?Init@oCVisualFX@@UAEXPBVzCVob@@ABVzVEC3@@@Z
        vfunc f39_InvestNext;                // from oCVisFX_MultiTarget  ?InvestNext@oCVisFX_MultiTarget@@UAEXXZ
        vfunc f40_SetLevel;                  // from oCVisualFX           ?SetLevel@oCVisualFX@@UAEXHH@Z
        vfunc f41_GetLevel;                  // from oCVisualFX           ?GetLevel@oCVisualFX@@UBEHXZ
        vfunc f42_Cast;                      // from oCVisFX_MultiTarget  ?Cast@oCVisFX_MultiTarget@@UAEXH@Z
        vfunc f43_Stop;                      // from oCVisFX_MultiTarget  ?Stop@oCVisFX_MultiTarget@@UAEXH@Z
        vfunc f44_Kill;                      // from oCVisualFX           ?Kill@oCVisualFX@@UAEXXZ
        vfunc f45_Play;                      // from oCVisFX_MultiTarget  ?Play@oCVisFX_MultiTarget@@UAEXMPBVzMAT4@@0@Z
        vfunc f46_CanBeDeleted;              // from oCVisualFX           ?CanBeDeleted@oCVisualFX@@UAEHXZ
        vfunc f47_IsFinished;                // from oCVisFX_MultiTarget  ?IsFinished@oCVisFX_MultiTarget@@UAEHXZ
        vfunc f48_IsLooping;                 // from oCVisualFX           ?IsLooping@oCVisualFX@@UAEHXZ
        vfunc f49_SetByScript;               // from oCVisFX_MultiTarget  ?SetByScript@oCVisFX_MultiTarget@@UAEXABVzSTRING@@@Z
        vfunc f50_SetDuration;               // from oCVisualFX           ?SetDuration@oCVisualFX@@UAEXM@Z
        vfunc f51_Reset;                     // from oCVisFX_MultiTarget  ?Reset@oCVisFX_MultiTarget@@UAEXXZ
        vfunc f52_ResetForEditing;           // from oCVisualFX           ?ResetForEditing@oCVisualFX@@UAEXXZ
        vfunc f53_ReportCollision;           // from oCVisualFX           ?ReportCollision@oCVisualFX@@UAEXABVzCCollisionReport@@@Z
        vfunc f54_SetCollisionEnabled;       // from oCVisualFX           ?SetCollisionEnabled@oCVisualFX@@UAEXH@Z
        vfunc f55_SetCollisionCandidates;    // from oCVisualFX           ?SetCollisionCandidates@oCVisualFX@@UAEXV?$zCArray@PAVzCVob@@@@@Z
        vfunc f56_GetCollisionCandidates;    // from oCVisualFX           ?GetCollisionCandidates@oCVisualFX@@UAEXAAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f57_GetNumCollisionCandidates; // from oCVisualFX           ?GetNumCollisionCandidates@oCVisualFX@@UAEHXZ
        vfunc f58_GetCollidedCandidates;     // from oCVisualFX           ?GetCollidedCandidates@oCVisualFX@@UAEHAAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f59_SetDamage;                 // from oCVisFX_MultiTarget  ?SetDamage@oCVisFX_MultiTarget@@UAEXM@Z
        vfunc f60_SetDamageType;             // from oCVisFX_MultiTarget  ?SetDamageType@oCVisFX_MultiTarget@@UAEXH@Z
        vfunc f61_GetDamage;                 // from oCVisualFX           ?GetDamage@oCVisualFX@@UBEMXZ
        vfunc f62_GetDamageType;             // from oCVisualFX           ?GetDamageType@oCVisualFX@@UBEHXZ
        vfunc f63_IsASpell;                  // from oCVisualFX           ?IsASpell@oCVisualFX@@UAEHXZ
        vfunc f64_SetSpellType;              // from oCVisualFX           ?SetSpellType@oCVisualFX@@UAEXH@Z
        vfunc f65_GetSpellType;              // from oCVisualFX           ?GetSpellType@oCVisualFX@@UBEHXZ
        vfunc f66_SetSpellCat;               // from oCVisualFX           ?SetSpellCat@oCVisualFX@@UAEXH@Z
        vfunc f67_GetSpellCat;               // from oCVisualFX           ?GetSpellCat@oCVisualFX@@UBEHXZ
        vfunc f68_GetSpellTargetTypes;       // from oCVisualFX           ?GetSpellTargetTypes@oCVisualFX@@UBEHXZ
        vfunc f69_SetSpellTargetTypes;       // from oCVisualFX           ?SetSpellTargetTypes@oCVisualFX@@UAEXH@Z
        vfunc f70_GetSendsAssessMagic;       // from oCVisualFX           ?GetSendsAssessMagic@oCVisualFX@@UAEHXZ
        vfunc f71_SetSendsAssessMagic;       // from oCVisualFX           ?SetSendsAssessMagic@oCVisualFX@@UAEXH@Z
        vfunc f72_GetIsProjectile;           // from oCVisualFX           ?GetIsProjectile@oCVisualFX@@UAEHXZ
        vfunc f73_SetIsProjectile;           // from oCVisualFX           ?SetIsProjectile@oCVisualFX@@UAEXH@Z
        vfunc f74_SetVisualByString;         // from oCVisualFX           ?SetVisualByString@oCVisualFX@@MAEXABVzSTRING@@@Z
        vfunc f75_CalcTrajectory;            // from oCVisualFX           ?CalcTrajectory@oCVisualFX@@MAEXABH@Z
        vfunc f76_Collide;                   // from oCVisualFX           ?Collide@oCVisualFX@@MAEXH@Z
        vfunc f77_CollisionResponse;         // from oCVisualFX           ?CollisionResponse@oCVisualFX@@MAEXABVzVEC3@@H@Z
        vfunc f78_Init;                      // from oCVisFX_MultiTarget  ?Init@oCVisFX_MultiTarget@@UAEXV?$zCArray@PAVzCVob@@@@@Z
        vfunc f79_SetLevel;                  // from oCVisFX_MultiTarget  ?SetLevel@oCVisFX_MultiTarget@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830534;
    }

    static uint GetFuncsNum() {
      return 80;
    }

    static vftable_oCVisFX_MultiTarget& GetTable() {
      MemUnlock;
      return *(vftable_oCVisFX_MultiTarget*)GetAddress();
    }
  };


  struct vftable_zCAICamera {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from zCAICamera  ?_GetClassDef@zCAICamera@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base        
        vfunc f04_DoAI;                            // from zCAICamera  ?DoAI@zCAICamera@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase    ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase    ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase    ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase    ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase    ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase    ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase    ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830690;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCAICamera& GetTable() {
      MemUnlock;
      return *(vftable_zCAICamera*)GetAddress();
    }
  };


  struct vftable_zCCamTrj_KeyFrame {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCCamTrj_KeyFrame  ?_GetClassDef@zCCamTrj_KeyFrame@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCCamTrj_KeyFrame  ?Archive@zCCamTrj_KeyFrame@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCCamTrj_KeyFrame  ?Unarchive@zCCamTrj_KeyFrame@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from zCVob              ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob              ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob              ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob              ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob              ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob              ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob              ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob              ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob              ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCCamTrj_KeyFrame  ?ThisVobAddedToWorld@zCCamTrj_KeyFrame@@MAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCCamTrj_KeyFrame  ?ThisVobRemovedFromWorld@zCCamTrj_KeyFrame@@MAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830874;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCCamTrj_KeyFrame& GetTable() {
      MemUnlock;
      return *(vftable_zCCamTrj_KeyFrame*)GetAddress();
    }
  };


  struct vftable_zCCSCamera {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCCSCamera  ?_GetClassDef@zCCSCamera@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCCSCamera  ?Archive@zCCSCamera@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCCSCamera  ?Unarchive@zCCSCamera@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_OnTrigger;               // from zCCSCamera  ?OnTrigger@zCCSCamera@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCCSCamera  ?OnUntrigger@zCCSCamera@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCCSCamera  ?OnMessage@zCCSCamera@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCCSCamera  ?OnTick@zCCSCamera@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob       ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCCSCamera  ?ThisVobAddedToWorld@zCCSCamera@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCCSCamera  ?ThisVobRemovedFromWorld@zCCSCamera@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008308EC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCCSCamera& GetTable() {
      MemUnlock;
      return *(vftable_zCCSCamera*)GetAddress();
    }
  };


  struct vftable_zCCSCamera_EventMsg {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCCSCamera_EventMsg  ?_GetClassDef@zCCSCamera_EventMsg@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCCSCamera_EventMsg  ?Archive@zCCSCamera_EventMsg@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCCSCamera_EventMsg  ?Unarchive@zCCSCamera_EventMsg@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base                 
        vfunc f04_IsOverlay;             // from zCEventMessage       ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage       ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCCSCamera_EventMsg  ?IsHighPriority@zCCSCamera_EventMsg@@UAEHXZ
        vfunc f07_IsJob;                 // from zCCSCamera_EventMsg  ?IsJob@zCCSCamera_EventMsg@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage       ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCCSCamera_EventMsg  ?Delete@zCCSCamera_EventMsg@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage       ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCCSCamera_EventMsg  ?IsDeleted@zCCSCamera_EventMsg@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage       ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage       ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCCSCamera_EventMsg  ?MD_GetNumOfSubTypes@zCCSCamera_EventMsg@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCCSCamera_EventMsg  ?MD_GetSubTypeString@zCCSCamera_EventMsg@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage       ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage       ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage       ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCCSCamera_EventMsg  ?MD_GetTimeBehavior@zCCSCamera_EventMsg@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from zCCSCamera_EventMsg  ?MD_GetMinTime@zCCSCamera_EventMsg@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage       ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage       ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083096C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCCSCamera_EventMsg& GetTable() {
      MemUnlock;
      return *(vftable_zCCSCamera_EventMsg*)GetAddress();
    }
  };


  struct vftable_zCFlash_zCBolt {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;             // from zCPolyStrip  ?_GetClassDef@zCPolyStrip@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_Render;                  // from zCFlash      ?Render@zCBolt@zCFlash@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCPolyStrip  ?IsBBox3DLocal@zCPolyStrip@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCPolyStrip  ?GetBBox3D@zCPolyStrip@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual     ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCPolyStrip  ?GetVisualName@zCPolyStrip@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual     ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCPolyStrip  ?SetVisualUsedBy@zCPolyStrip@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual     ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual     ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual     ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual     ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual     ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual     ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual     ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual     ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual     ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual     ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual     ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
        vfunc f22_FreeResources;           // from zCFlash      ?FreeResources@zCBolt@zCFlash@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830A04;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCFlash_zCBolt& GetTable() {
      MemUnlock;
      return *(vftable_zCFlash_zCBolt*)GetAddress();
    }
  };


  struct vftable_zCFlash {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCVisual  ?_GetClassDef@zCVisual@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_Render;                  // from zCFlash   ?Render@zCFlash@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCFlash   ?IsBBox3DLocal@zCFlash@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCFlash   ?GetBBox3D@zCFlash@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual  ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCFlash   ?GetVisualName@zCFlash@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCFlash   ?GetVisualDied@zCFlash@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCFlash   ?SetVisualUsedBy@zCFlash@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCFlash   ?DynLightVisual@zCFlash@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual  ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual  ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual  ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual  ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual  ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual  ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual  ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual  ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual  ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual  ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830A64;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCFlash& GetTable() {
      MemUnlock;
      return *(vftable_zCFlash*)GetAddress();
    }
  };


  struct vftable_zCInput {
    union {
      vfunc array[30];
      group {
        vfunc f00_scalar_destructor;          // from base     
        vfunc f01_GetState;                   // from zCInput  ?GetState@zCInput@@UAEMG@Z
        vfunc f02_SetState;                   // from zCInput  ?SetState@zCInput@@UAEHGH@Z
        vfunc f03_GetToggled;                 // from zCInput  ?GetToggled@zCInput@@UAEHG@Z
        vfunc f04_SetDeviceEnabled;           // from zCInput  ?SetDeviceEnabled@zCInput@@UAEXW4zTInputDevice@@H@Z
        vfunc f05_GetDeviceEnabled;           // from zCInput  ?GetDeviceEnabled@zCInput@@UAEHW4zTInputDevice@@@Z
        vfunc f06_GetDeviceConnected;         // from zCInput  ?GetDeviceConnected@zCInput@@UAEHW4zTInputDevice@@@Z
        vfunc f07_KeyPressed;                 // from zCInput  ?KeyPressed@zCInput@@UAEHH@Z
        vfunc f08_KeyToggled;                 // from zCInput  ?KeyToggled@zCInput@@UAEHH@Z
        vfunc f09_AnyKeyPressed;              // from zCInput  ?AnyKeyPressed@zCInput@@UAEHXZ
        vfunc f10_ResetRepeatKey;             // from zCInput  ?ResetRepeatKey@zCInput@@UAEXH@Z
        vfunc f11_GetKey;                     // from zCInput  ?GetKey@zCInput@@UAEGHH@Z
        vfunc f12_SetKey;                     // from zCInput  ?SetKey@zCInput@@UAEXHH@Z
        vfunc f13_GetChar;                    // from zCInput  ?GetChar@zCInput@@UAEEXZ
        vfunc f14_ClearKeyBuffer;             // from zCInput  ?ClearKeyBuffer@zCInput@@UAEXXZ
        vfunc f15_GetNumJoysConnected;        // from zCInput  ?GetNumJoysConnected@zCInput@@UAEHXZ
        vfunc f16_SetJoyDigitalEmu;           // from zCInput  ?SetJoyDigitalEmu@zCInput@@UAEXH@Z
        vfunc f17_SetJoyEnabled;              // from zCInput  ?SetJoyEnabled@zCInput@@UAEXH@Z
        vfunc f18_JoyState;                   // from zCInput  ?JoyState@zCInput@@UAEMHH@Z
        vfunc f19_JoyState;                   // from zCInput  ?JoyState@zCInput@@UAEMH@Z
        vfunc f20_GetMousePos;                // from zCInput  ?GetMousePos@zCInput@@UAEXAAM00@Z
        vfunc f21_GetMouseButtonPressedLeft;  // from zCInput  ?GetMouseButtonPressedLeft@zCInput@@UAEHXZ
        vfunc f22_GetMouseButtonPressedMid;   // from zCInput  ?GetMouseButtonPressedMid@zCInput@@UAEHXZ
        vfunc f23_GetMouseButtonPressedRight; // from zCInput  ?GetMouseButtonPressedRight@zCInput@@UAEHXZ
        vfunc f24_SetMouseSensitivity;        // from zCInput  ?SetMouseSensitivity@zCInput@@UAEXMM@Z
        vfunc f25_GetMouseSensitivity;        // from zCInput  ?GetMouseSensitivity@zCInput@@UAEXAAM0@Z
        vfunc f26_GetMouseIdle;               // from zCInput  ?GetMouseIdle@zCInput@@UBEHXZ
        vfunc f27_SetMouseFlipXY;             // from zCInput  ?SetMouseFlipXY@zCInput@@UAEXHH@Z
        vfunc f28_GetMouseFlipXY;             // from zCInput  ?GetMouseFlipXY@zCInput@@UAEXAAH0@Z
        vfunc f29_ProcessInputEvents;         // from base     purecall
      } names;
    };

    static uint GetAddress() {
      return 0x00830AD4;
    }

    static uint GetFuncsNum() {
      return 30;
    }

    static vftable_zCInput& GetTable() {
      MemUnlock;
      return *(vftable_zCInput*)GetAddress();
    }
  };


  struct vftable_zCInput_Win32 {
    union {
      vfunc array[30];
      group {
        vfunc f00_scalar_destructor;          // from base           
        vfunc f01_GetState;                   // from zCInput_Win32  ?GetState@zCInput_Win32@@UAEMG@Z
        vfunc f02_SetState;                   // from zCInput_Win32  ?SetState@zCInput_Win32@@UAEHGH@Z
        vfunc f03_GetToggled;                 // from zCInput_Win32  ?GetToggled@zCInput_Win32@@UAEHG@Z
        vfunc f04_SetDeviceEnabled;           // from zCInput_Win32  ?SetDeviceEnabled@zCInput_Win32@@UAEXW4zTInputDevice@@H@Z
        vfunc f05_GetDeviceEnabled;           // from zCInput_Win32  ?GetDeviceEnabled@zCInput_Win32@@UAEHW4zTInputDevice@@@Z
        vfunc f06_GetDeviceConnected;         // from zCInput_Win32  ?GetDeviceConnected@zCInput_Win32@@UAEHW4zTInputDevice@@@Z
        vfunc f07_KeyPressed;                 // from zCInput_Win32  ?KeyPressed@zCInput_Win32@@UAEHH@Z
        vfunc f08_KeyToggled;                 // from zCInput_Win32  ?KeyToggled@zCInput_Win32@@UAEHH@Z
        vfunc f09_AnyKeyPressed;              // from zCInput_Win32  ?AnyKeyPressed@zCInput_Win32@@UAEHXZ
        vfunc f10_ResetRepeatKey;             // from zCInput_Win32  ?ResetRepeatKey@zCInput_Win32@@UAEXH@Z
        vfunc f11_GetKey;                     // from zCInput_Win32  ?GetKey@zCInput_Win32@@UAEGHH@Z
        vfunc f12_SetKey;                     // from zCInput_Win32  ?SetKey@zCInput_Win32@@UAEXHH@Z
        vfunc f13_GetChar;                    // from zCInput_Win32  ?GetChar@zCInput_Win32@@UAEEXZ
        vfunc f14_ClearKeyBuffer;             // from zCInput_Win32  ?ClearKeyBuffer@zCInput_Win32@@UAEXXZ
        vfunc f15_GetNumJoysConnected;        // from zCInput        ?GetNumJoysConnected@zCInput@@UAEHXZ
        vfunc f16_SetJoyDigitalEmu;           // from zCInput        ?SetJoyDigitalEmu@zCInput@@UAEXH@Z
        vfunc f17_SetJoyEnabled;              // from zCInput        ?SetJoyEnabled@zCInput@@UAEXH@Z
        vfunc f18_JoyState;                   // from zCInput        ?JoyState@zCInput@@UAEMHH@Z
        vfunc f19_JoyState;                   // from zCInput        ?JoyState@zCInput@@UAEMH@Z
        vfunc f20_GetMousePos;                // from zCInput_Win32  ?GetMousePos@zCInput_Win32@@UAEXAAM00@Z
        vfunc f21_GetMouseButtonPressedLeft;  // from zCInput_Win32  ?GetMouseButtonPressedLeft@zCInput_Win32@@UAEHXZ
        vfunc f22_GetMouseButtonPressedMid;   // from zCInput_Win32  ?GetMouseButtonPressedMid@zCInput_Win32@@UAEHXZ
        vfunc f23_GetMouseButtonPressedRight; // from zCInput_Win32  ?GetMouseButtonPressedRight@zCInput_Win32@@UAEHXZ
        vfunc f24_SetMouseSensitivity;        // from zCInput_Win32  ?SetMouseSensitivity@zCInput_Win32@@UAEXMM@Z
        vfunc f25_GetMouseSensitivity;        // from zCInput_Win32  ?GetMouseSensitivity@zCInput_Win32@@UAEXAAM0@Z
        vfunc f26_GetMouseIdle;               // from zCInput_Win32  ?GetMouseIdle@zCInput_Win32@@UBEHXZ
        vfunc f27_SetMouseFlipXY;             // from zCInput_Win32  ?SetMouseFlipXY@zCInput_Win32@@UAEXHH@Z
        vfunc f28_GetMouseFlipXY;             // from zCInput_Win32  ?GetMouseFlipXY@zCInput_Win32@@UAEXAAH0@Z
        vfunc f29_ProcessInputEvents;         // from zCInput_Win32  ?ProcessInputEvents@zCInput_Win32@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830B64;
    }

    static uint GetFuncsNum() {
      return 30;
    }

    static vftable_zCInput_Win32& GetTable() {
      MemUnlock;
      return *(vftable_zCInput_Win32*)GetAddress();
    }
  };


  struct vftable_zCMenu {
    union {
      vfunc array[18];
      group {
        vfunc f00_HandleEvent;        // from zCMenu  ?HandleEvent@zCMenu@@UAEHH@Z
        vfunc f01_HandleEnterItem;    // from zCMenu  ?HandleEnterItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f02_HandleLeaveItem;    // from zCMenu  ?HandleLeaveItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f03_HandleActivateItem; // from zCMenu  ?HandleActivateItem@zCMenu@@UAEHPAVzCMenuItem@@@Z
        vfunc f04_Run;                // from zCMenu  ?Run@zCMenu@@UAEHXZ
        vfunc f05_Enter;              // from zCMenu  ?Enter@zCMenu@@UAEXXZ
        vfunc f06_Leave;              // from zCMenu  ?Leave@zCMenu@@UAEXXZ
        vfunc f07_Render;             // from zCMenu  ?Render@zCMenu@@UAEXXZ
        vfunc f08_RedrawItems;        // from zCMenu  ?RedrawItems@zCMenu@@UAEXXZ
        vfunc f09_HandleFrame;        // from zCMenu  ?HandleFrame@zCMenu@@UAEXH@Z
        vfunc f10_Activate;           // from zCMenu  ?Activate@zCMenu@@UAEXXZ
        vfunc f11_scalar_destructor;  // from base    
        vfunc f12_ScreenInit;         // from zCMenu  ?ScreenInit@zCMenu@@MAEXXZ
        vfunc f13_ScreenDone;         // from zCMenu  ?ScreenDone@zCMenu@@MAEXXZ
        vfunc f14_HandleAction;       // from zCMenu  ?HandleAction@zCMenu@@MAEHXZ
        vfunc f15_HandleSelAction;    // from zCMenu  ?HandleSelAction@zCMenu@@MAEHW4zTMenuItemSelAction@@ABVzSTRING@@PAVzCMenuItem@@@Z
        vfunc f16_SetByScript;        // from zCMenu  ?SetByScript@zCMenu@@MAEXABVzSTRING@@@Z
        vfunc f17_ExecCommand;        // from zCMenu  ?ExecCommand@zCMenu@@MAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830C3C;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_zCMenu& GetTable() {
      MemUnlock;
      return *(vftable_zCMenu*)GetAddress();
    }
  };


  struct vftable_zCMenuItemButton_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItem  ?HandleEvent@zCMenuItem@@MAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830CA4;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemButton_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemButton_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemButton_for_zCViewBase {
    union {
      vfunc array[33];
      group {
        vfunc f00_anx;               // from zCView            ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView            ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView            ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView            ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView            ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView            ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView            ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase        ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView            ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base              
        vfunc f10_Blit;              // from zCView            ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem        ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemButton  ?InitMenuItem@zCMenuItemButton@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItem        ?ToggleValue@zCMenuItem@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItemButton  ?Run@zCMenuItemButton@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem        ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem        ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem        ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItem        ?Enter@zCMenuItem@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItem        ?Leave@zCMenuItem@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem        ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItem        ?DrawFront@zCMenuItem@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem        ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem        ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem        ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem        ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem        ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItemButton  ?InsertInWin@zCMenuItemButton@@MAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItemButton  ?RemoveFromWin@zCMenuItemButton@@MAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem        ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem        ?UpdateFX@zCMenuItem@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830CAC;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCMenuItemButton_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemButton_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItemList_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItemList  ?HandleEvent@zCMenuItemList@@EAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830D34;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemList_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemList_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemList_for_zCViewBase {
    union {
      vfunc array[33];
      group {
        vfunc f00_anx;               // from zCView          ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView          ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView          ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView          ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView          ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView          ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView          ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase      ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView          ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base            
        vfunc f10_Blit;              // from zCView          ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem      ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemList  ?InitMenuItem@zCMenuItemList@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItem      ?ToggleValue@zCMenuItem@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItemList  ?Run@zCMenuItemList@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem      ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem      ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem      ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem      ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem      ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItemList  ?Enter@zCMenuItemList@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItemList  ?Leave@zCMenuItemList@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem      ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItemList  ?DrawFront@zCMenuItemList@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItemList  ?Show@zCMenuItemList@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItemList  ?Hide@zCMenuItemList@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem      ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem      ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem      ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItemList  ?InsertInWin@zCMenuItemList@@EAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItemList  ?RemoveFromWin@zCMenuItemList@@EAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItemList  ?UpdateContent@zCMenuItemList@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem      ?UpdateFX@zCMenuItem@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830D3C;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCMenuItemList_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemList_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItemChoice_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItem  ?HandleEvent@zCMenuItem@@MAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830DC4;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemChoice_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemChoice_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemChoice_for_zCViewBase {
    union {
      vfunc array[33];
      group {
        vfunc f00_anx;               // from zCView            ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView            ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView            ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView            ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView            ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView            ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView            ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase        ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView            ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base              
        vfunc f10_Blit;              // from zCView            ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem        ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemChoice  ?InitMenuItem@zCMenuItemChoice@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItemChoice  ?ToggleValue@zCMenuItemChoice@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItem        ?Run@zCMenuItem@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItemChoice  ?GetText@zCMenuItemChoice@@EAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem        ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem        ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItem        ?Enter@zCMenuItem@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItem        ?Leave@zCMenuItem@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItemChoice  ?Draw@zCMenuItemChoice@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItemChoice  ?DrawFront@zCMenuItemChoice@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem        ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem        ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem        ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem        ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem        ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItemChoice  ?InsertInWin@zCMenuItemChoice@@UAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItemChoice  ?RemoveFromWin@zCMenuItemChoice@@UAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem        ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem        ?UpdateFX@zCMenuItem@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830DCC;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCMenuItemChoice_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemChoice_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItemSlider_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItemSlider  ?HandleEvent@zCMenuItemSlider@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830E54;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemSlider_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemSlider_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemSlider_for_zCViewBase {
    union {
      vfunc array[34];
      group {
        vfunc f00_anx;               // from zCView            ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView            ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView            ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView            ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView            ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView            ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView            ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase        ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView            ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base              
        vfunc f10_Blit;              // from zCView            ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem        ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemSlider  ?InitMenuItem@zCMenuItemSlider@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItemSlider  ?ToggleValue@zCMenuItemSlider@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItem        ?Run@zCMenuItem@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem        ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem        ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem        ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem        ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItem        ?Enter@zCMenuItem@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItem        ?Leave@zCMenuItem@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem        ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItem        ?DrawFront@zCMenuItem@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem        ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem        ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem        ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem        ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem        ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItemSlider  ?InsertInWin@zCMenuItemSlider@@MAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItemSlider  ?RemoveFromWin@zCMenuItemSlider@@MAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem        ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem        ?UpdateFX@zCMenuItem@@MAEXXZ
        vfunc f33_SetIsActive;       // from zCMenuItemSlider  ?SetIsActive@zCMenuItemSlider@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830E5C;
    }

    static uint GetFuncsNum() {
      return 34;
    }

    static vftable_zCMenuItemSlider_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemSlider_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItemInput_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItemInput  ?HandleEvent@zCMenuItemInput@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830EE8;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemInput_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemInput_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemInput_for_zCViewBase {
    union {
      vfunc array[33];
      group {
        vfunc f00_anx;               // from zCView           ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView           ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView           ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView           ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView           ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView           ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView           ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase       ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView           ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base             
        vfunc f10_Blit;              // from zCView           ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem       ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemInput  ?InitMenuItem@zCMenuItemInput@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItem       ?ToggleValue@zCMenuItem@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItemInput  ?Run@zCMenuItemInput@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem       ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem       ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem       ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem       ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem       ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItemInput  ?Enter@zCMenuItemInput@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItemInput  ?Leave@zCMenuItemInput@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem       ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItem       ?DrawFront@zCMenuItem@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem       ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem       ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItemInput  ?HasBeenCanceled@zCMenuItemInput@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem       ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem       ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItemInput  ?InsertInWin@zCMenuItemInput@@MAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItem       ?RemoveFromWin@zCMenuItem@@MAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem       ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem       ?UpdateFX@zCMenuItem@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00830EF4;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCMenuItemInput_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemInput_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItemText_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItemText  ?HandleEvent@zCMenuItemText@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830F7C;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItemText_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemText_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItemText_for_zCViewBase {
    union {
      vfunc array[34];
      group {
        vfunc f00_anx;               // from zCView          ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView          ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView          ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView          ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView          ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView          ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView          ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase      ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView          ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base            
        vfunc f10_Blit;              // from zCView          ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem      ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItemText  ?InitMenuItem@zCMenuItemText@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItem      ?ToggleValue@zCMenuItem@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItem      ?Run@zCMenuItem@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem      ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItemText  ?SetText@zCMenuItemText@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItemText  ?SetText@zCMenuItemText@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem      ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem      ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItem      ?Enter@zCMenuItem@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItem      ?Leave@zCMenuItem@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem      ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItemText  ?DrawFront@zCMenuItemText@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem      ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem      ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem      ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem      ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem      ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItem      ?InsertInWin@zCMenuItem@@MAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItem      ?RemoveFromWin@zCMenuItem@@MAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem      ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem      ?UpdateFX@zCMenuItem@@MAEXXZ
        vfunc f33_SetEnum;           // from zCMenuItemText  ?SetEnum@zCMenuItemText@@UAEXABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00830F84;
    }

    static uint GetFuncsNum() {
      return 34;
    }

    static vftable_zCMenuItemText_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItemText_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMenuItem_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCMenuItem  ?HandleEvent@zCMenuItem@@MAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831010;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCMenuItem_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItem_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCMenuItem_for_zCViewBase {
    union {
      vfunc array[33];
      group {
        vfunc f00_anx;               // from zCView      ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView      ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView      ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView      ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView      ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView      ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView      ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase  ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView      ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base        
        vfunc f10_Blit;              // from zCView      ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCMenuItem  ?DrawItems@zCMenuItem@@MAEXXZ
        vfunc f12_InitMenuItem;      // from zCMenuItem  ?InitMenuItem@zCMenuItem@@UAEXXZ
        vfunc f13_ToggleValue;       // from zCMenuItem  ?ToggleValue@zCMenuItem@@UAEHHH@Z
        vfunc f14_Run;               // from zCMenuItem  ?Run@zCMenuItem@@UAEHXZ
        vfunc f15_GetText;           // from zCMenuItem  ?GetText@zCMenuItem@@UAE?AVzSTRING@@H@Z
        vfunc f16_SetText;           // from zCMenuItem  ?SetText@zCMenuItem@@UAEXV?$zCArray@VzSTRING@@@@H@Z
        vfunc f17_SetText;           // from zCMenuItem  ?SetText@zCMenuItem@@UAEXABVzSTRING@@HH@Z
        vfunc f18_SetMinValue;       // from zCMenuItem  ?SetMinValue@zCMenuItem@@UAEXM@Z
        vfunc f19_SetMaxValue;       // from zCMenuItem  ?SetMaxValue@zCMenuItem@@UAEXM@Z
        vfunc f20_Enter;             // from zCMenuItem  ?Enter@zCMenuItem@@UAEXXZ
        vfunc f21_Leave;             // from zCMenuItem  ?Leave@zCMenuItem@@UAEXXZ
        vfunc f22_Draw;              // from zCMenuItem  ?Draw@zCMenuItem@@UAEXXZ
        vfunc f23_DrawFront;         // from zCMenuItem  ?DrawFront@zCMenuItem@@UAEXXZ
        vfunc f24_Show;              // from zCMenuItem  ?Show@zCMenuItem@@UAEHXZ
        vfunc f25_Hide;              // from zCMenuItem  ?Hide@zCMenuItem@@UAEHXZ
        vfunc f26_HasBeenCanceled;   // from zCMenuItem  ?HasBeenCanceled@zCMenuItem@@UAEHXZ
        vfunc f27_Open;              // from zCMenuItem  ?Open@zCMenuItem@@MAEXXZ
        vfunc f28_Input;             // from zCMenuItem  ?Input@zCMenuItem@@MAEHHAAVzSTRING@@@Z
        vfunc f29_InsertInWin;       // from zCMenuItem  ?InsertInWin@zCMenuItem@@MAEXPAVzCView@@@Z
        vfunc f30_RemoveFromWin;     // from zCMenuItem  ?RemoveFromWin@zCMenuItem@@MAEXXZ
        vfunc f31_UpdateContent;     // from zCMenuItem  ?UpdateContent@zCMenuItem@@MAEXXZ
        vfunc f32_UpdateFX;          // from zCMenuItem  ?UpdateFX@zCMenuItem@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083101C;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCMenuItem_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCMenuItem_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCMusicTheme {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base          
        vfunc f01_IsActive;          // from zCMusicTheme  ?IsActive@zCMusicTheme@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008310C4;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCMusicTheme& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicTheme*)GetAddress();
    }
  };


  struct vftable_zCMusicTheme_DM {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base             
        vfunc f01_IsActive;          // from zCMusicTheme_DM  ?IsActive@zCMusicTheme_DM@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008310D0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCMusicTheme_DM& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicTheme_DM*)GetAddress();
    }
  };


  struct vftable_zCMusicSys_DirectMusic {
    union {
      vfunc array[21];
      group {
        vfunc f00_scalar_destructor;       // from base                    
        vfunc f01_PlayThemeByScript;       // from zCMusicSys_DirectMusic  ?PlayThemeByScript@zCMusicSys_DirectMusic@@UAEXABVzSTRING@@HPAH@Z
        vfunc f02_LoadThemeByScript;       // from zCMusicSys_DirectMusic  ?LoadThemeByScript@zCMusicSys_DirectMusic@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f03_LoadTheme;               // from zCMusicSys_DirectMusic  ?LoadTheme@zCMusicSys_DirectMusic@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f04_PlayTheme;               // from zCMusicSys_DirectMusic  ?PlayTheme@zCMusicSys_DirectMusic@@UAEXPAVzCMusicTheme@@ABMABW4zTMus_TransType@@ABW4zTMus_TransSubType@@@Z
        vfunc f05_GetActiveTheme;          // from zCMusicSys_DirectMusic  ?GetActiveTheme@zCMusicSys_DirectMusic@@UAEPAVzCMusicTheme@@XZ
        vfunc f06_PlayJingleByScript;      // from zCMusicSys_DirectMusic  ?PlayJingleByScript@zCMusicSys_DirectMusic@@UAEHABVzSTRING@@@Z
        vfunc f07_StopJingleByScript;      // from zCMusicSys_DirectMusic  ?StopJingleByScript@zCMusicSys_DirectMusic@@UAEXABVzSTRING@@@Z
        vfunc f08_LoadJingleByScript;      // from zCMusicSys_DirectMusic  ?LoadJingleByScript@zCMusicSys_DirectMusic@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f09_LoadJingle;              // from zCMusicSys_DirectMusic  ?LoadJingle@zCMusicSys_DirectMusic@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f10_PlayJingle;              // from zCMusicSys_DirectMusic  ?PlayJingle@zCMusicSys_DirectMusic@@UAEHPBVzCMusicJingle@@ABMABW4zTMus_TransSubType@@@Z
        vfunc f11_StopJingle;              // from zCMusicSys_DirectMusic  ?StopJingle@zCMusicSys_DirectMusic@@UAEXABH@Z
        vfunc f12_IsJingleActive;          // from zCMusicSys_DirectMusic  ?IsJingleActive@zCMusicSys_DirectMusic@@UAEHABH@Z
        vfunc f13_DoMusicUpdate;           // from zCMusicSys_DirectMusic  ?DoMusicUpdate@zCMusicSys_DirectMusic@@UAEXXZ
        vfunc f14_AddEventCallBackFunc;    // from zCMusicSystem           ?AddEventCallBackFunc@zCMusicSystem@@UAEXABW4zTMus_EventType@@P6AX0@Z@Z
        vfunc f15_RemoveEventCallBackFunc; // from zCMusicSystem           ?RemoveEventCallBackFunc@zCMusicSystem@@UAEXP6AXABW4zTMus_EventType@@@Z@Z
        vfunc f16_Mute;                    // from zCMusicSys_DirectMusic  ?Mute@zCMusicSys_DirectMusic@@UAEXXZ
        vfunc f17_Stop;                    // from zCMusicSys_DirectMusic  ?Stop@zCMusicSys_DirectMusic@@UAEXXZ
        vfunc f18_SetVolume;               // from zCMusicSys_DirectMusic  ?SetVolume@zCMusicSys_DirectMusic@@UAEXM@Z
        vfunc f19_GetVolume;               // from zCMusicSys_DirectMusic  ?GetVolume@zCMusicSys_DirectMusic@@UBEMXZ
        vfunc f20_IsAvailable;             // from zCMusicSys_DirectMusic  ?IsAvailable@zCMusicSys_DirectMusic@@UAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008310E4;
    }

    static uint GetFuncsNum() {
      return 21;
    }

    static vftable_zCMusicSys_DirectMusic& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicSys_DirectMusic*)GetAddress();
    }
  };


  struct vftable_zCMusicJingle {
    union {
      vfunc array[7];
      group {
        vfunc f00_scalar_destructor; // from base           
        vfunc f01_AddRef;            // from zCMusicJingle  ?AddRef@zCMusicJingle@@UAEPAV1@XZ
        vfunc f02_Release;           // from zCMusicJingle  ?Release@zCMusicJingle@@UAEHXZ
        vfunc f03_IsPlaying;         // from zCMusicJingle  ?IsPlaying@zCMusicJingle@@UBEHXZ
        vfunc f04_StopPlaying;       // from zCMusicJingle  ?StopPlaying@zCMusicJingle@@UAEXXZ
        vfunc f05_CacheIn;           // from zCMusicJingle  ?CacheIn@zCMusicJingle@@UAEXXZ
        vfunc f06_CacheOut;          // from zCMusicJingle  ?CacheOut@zCMusicJingle@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083113C;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCMusicJingle& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicJingle*)GetAddress();
    }
  };


  struct vftable_zCMusicSystem {
    union {
      vfunc array[21];
      group {
        vfunc f00_scalar_destructor;       // from base           
        vfunc f01_PlayThemeByScript;       // from zCMusicSystem  ?PlayThemeByScript@zCMusicSystem@@UAEXABVzSTRING@@HPAH@Z
        vfunc f02_LoadThemeByScript;       // from zCMusicSystem  ?LoadThemeByScript@zCMusicSystem@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f03_LoadTheme;               // from zCMusicSystem  ?LoadTheme@zCMusicSystem@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f04_PlayTheme;               // from zCMusicSystem  ?PlayTheme@zCMusicSystem@@UAEXPAVzCMusicTheme@@ABMABW4zTMus_TransType@@ABW4zTMus_TransSubType@@@Z
        vfunc f05_GetActiveTheme;          // from zCMusicSystem  ?GetActiveTheme@zCMusicSystem@@UAEPAVzCMusicTheme@@XZ
        vfunc f06_PlayJingleByScript;      // from zCMusicSystem  ?PlayJingleByScript@zCMusicSystem@@UAEHABVzSTRING@@@Z
        vfunc f07_StopJingleByScript;      // from zCMusicSystem  ?StopJingleByScript@zCMusicSystem@@UAEXABVzSTRING@@@Z
        vfunc f08_LoadJingleByScript;      // from zCMusicSystem  ?LoadJingleByScript@zCMusicSystem@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f09_LoadJingle;              // from zCMusicSystem  ?LoadJingle@zCMusicSystem@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f10_PlayJingle;              // from zCMusicSystem  ?PlayJingle@zCMusicSystem@@UAEHPBVzCMusicJingle@@ABMABW4zTMus_TransSubType@@@Z
        vfunc f11_StopJingle;              // from zCMusicSystem  ?StopJingle@zCMusicSystem@@UAEXABH@Z
        vfunc f12_IsJingleActive;          // from zCMusicSystem  ?IsJingleActive@zCMusicSystem@@UAEHABH@Z
        vfunc f13_DoMusicUpdate;           // from base           purecall
        vfunc f14_AddEventCallBackFunc;    // from zCMusicSystem  ?AddEventCallBackFunc@zCMusicSystem@@UAEXABW4zTMus_EventType@@P6AX0@Z@Z
        vfunc f15_RemoveEventCallBackFunc; // from zCMusicSystem  ?RemoveEventCallBackFunc@zCMusicSystem@@UAEXP6AXABW4zTMus_EventType@@@Z@Z
        vfunc f16_Mute;                    // from zCMusicSystem  ?Mute@zCMusicSystem@@UAEXXZ
        vfunc f17_Stop;                    // from zCMusicSystem  ?Stop@zCMusicSystem@@UAEXXZ
        vfunc f18_SetVolume;               // from zCMusicSystem  ?SetVolume@zCMusicSystem@@UAEXM@Z
        vfunc f19_GetVolume;               // from zCMusicSystem  ?GetVolume@zCMusicSystem@@UBEMXZ
        vfunc f20_IsAvailable;             // from zCMusicSystem  ?IsAvailable@zCMusicSystem@@UAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083115C;
    }

    static uint GetFuncsNum() {
      return 21;
    }

    static vftable_zCMusicSystem& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicSystem*)GetAddress();
    }
  };


  struct vftable_zCSndDebugCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_DoWorldPerFrameCallback; // from zCSndDebugCallback  ?DoWorldPerFrameCallback@zCSndDebugCallback@@UAEXPAVzCWorld@@PAVzCCamera@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831200;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCSndDebugCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCSndDebugCallback*)GetAddress();
    }
  };


  struct vftable_zCSndSys_MSS {
    union {
      vfunc array[32];
      group {
        vfunc f00_scalar_destructor;       // from base           
        vfunc f01_LoadSoundFX;             // from zCSndSys_MSS   ?LoadSoundFX@zCSndSys_MSS@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f02_LoadSoundFXScript;       // from zCSndSys_MSS   ?LoadSoundFXScript@zCSndSys_MSS@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f03_GetSFXParser;            // from zCSndSys_MSS   ?GetSFXParser@zCSndSys_MSS@@UAEPAVzCParser@@XZ
        vfunc f04_GetPlayingTimeMSEC;      // from zCSndSys_MSS   ?GetPlayingTimeMSEC@zCSndSys_MSS@@UAEMABVzSTRING@@@Z
        vfunc f05_SetSound3DDefaultRadius; // from zCSoundSystem  ?SetSound3DDefaultRadius@zCSoundSystem@@UAEXM@Z
        vfunc f06_GetSound3DDefaultRadius; // from zCSoundSystem  ?GetSound3DDefaultRadius@zCSoundSystem@@UBEMXZ
        vfunc f07_SetMasterVolume;         // from zCSndSys_MSS   ?SetMasterVolume@zCSndSys_MSS@@UAEXM@Z
        vfunc f08_GetMasterVolume;         // from zCSndSys_MSS   ?GetMasterVolume@zCSndSys_MSS@@UAEMXZ
        vfunc f09_PlaySound;               // from zCSndSys_MSS   ?PlaySound@zCSndSys_MSS@@UAEHPAVzCSoundFX@@HHMM@Z
        vfunc f10_PlaySound;               // from zCSndSys_MSS   ?PlaySound@zCSndSys_MSS@@UAEHPAVzCSoundFX@@H@Z
        vfunc f11_PlaySound3D;             // from zCSndSys_MSS   ?PlaySound3D@zCSndSys_MSS@@UAEHABVzSTRING@@PAVzCVob@@HPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f12_PlaySound3D;             // from zCSndSys_MSS   ?PlaySound3D@zCSndSys_MSS@@UAEHPAVzCSoundFX@@PAVzCVob@@HPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f13_StopSound;               // from zCSndSys_MSS   ?StopSound@zCSndSys_MSS@@UAEXABH@Z
        vfunc f14_StopAllSounds;           // from zCSndSys_MSS   ?StopAllSounds@zCSndSys_MSS@@UAEXXZ
        vfunc f15_GetSound3DProps;         // from zCSndSys_MSS   ?GetSound3DProps@zCSndSys_MSS@@UAEHABHAAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f16_UpdateSound3D;           // from zCSndSys_MSS   ?UpdateSound3D@zCSndSys_MSS@@UAEHABHPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f17_GetSoundProps;           // from zCSndSys_MSS   ?GetSoundProps@zCSndSys_MSS@@UAEXABHAAHAAM2@Z
        vfunc f18_UpdateSoundProps;        // from zCSndSys_MSS   ?UpdateSoundProps@zCSndSys_MSS@@UAEXABHHMM@Z
        vfunc f19_IsSoundActive;           // from zCSndSys_MSS   ?IsSoundActive@zCSndSys_MSS@@UAEHABH@Z
        vfunc f20_DoSoundUpdate;           // from zCSndSys_MSS   ?DoSoundUpdate@zCSndSys_MSS@@UAEXXZ
        vfunc f21_SetListener;             // from zCSndSys_MSS   ?SetListener@zCSndSys_MSS@@UAEXPAVzCVob@@@Z
        vfunc f22_SetGlobalReverbPreset;   // from zCSndSys_MSS   ?SetGlobalReverbPreset@zCSndSys_MSS@@UAEXHM@Z
        vfunc f23_SetReverbEnabled;        // from zCSndSys_MSS   ?SetReverbEnabled@zCSndSys_MSS@@UAEXH@Z
        vfunc f24_GetReverbEnabled;        // from zCSndSys_MSS   ?GetReverbEnabled@zCSndSys_MSS@@UAEHXZ
        vfunc f25_GetNumProvider;          // from zCSndSys_MSS   ?GetNumProvider@zCSndSys_MSS@@UAEHXZ
        vfunc f26_GetProviderName;         // from zCSndSys_MSS   ?GetProviderName@zCSndSys_MSS@@UAEPBVzSTRING@@H@Z
        vfunc f27_SetProvider;             // from zCSndSys_MSS   ?SetProvider@zCSndSys_MSS@@UAEHH@Z
        vfunc f28_SetSpeakerType;          // from zCSndSys_MSS   ?SetSpeakerType@zCSndSys_MSS@@UAEXW4zTSpeakerType@zCSoundSystem@@@Z
        vfunc f29_GetSpeakerType;          // from zCSndSys_MSS   ?GetSpeakerType@zCSndSys_MSS@@UAE?AW4zTSpeakerType@zCSoundSystem@@XZ
        vfunc f30_SetGlobalOcclusion;      // from zCSndSys_MSS   ?SetGlobalOcclusion@zCSndSys_MSS@@UAEXM@Z
        vfunc f31_GetCPULoad;              // from zCSndSys_MSS   ?GetCPULoad@zCSndSys_MSS@@UAEMXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083120C;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCSndSys_MSS& GetTable() {
      MemUnlock;
      return *(vftable_zCSndSys_MSS*)GetAddress();
    }
  };


  struct vftable_zCSoundSystem {
    union {
      vfunc array[32];
      group {
        vfunc f00_scalar_destructor;       // from base           
        vfunc f01_LoadSoundFX;             // from zCSoundSystem  ?LoadSoundFX@zCSoundSystem@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f02_LoadSoundFXScript;       // from zCSoundSystem  ?LoadSoundFXScript@zCSoundSystem@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f03_GetSFXParser;            // from zCSoundSystem  ?GetSFXParser@zCSoundSystem@@UAEPAVzCParser@@XZ
        vfunc f04_GetPlayingTimeMSEC;      // from zCSoundSystem  ?GetPlayingTimeMSEC@zCSoundSystem@@UAEMABVzSTRING@@@Z
        vfunc f05_SetSound3DDefaultRadius; // from zCSoundSystem  ?SetSound3DDefaultRadius@zCSoundSystem@@UAEXM@Z
        vfunc f06_GetSound3DDefaultRadius; // from zCSoundSystem  ?GetSound3DDefaultRadius@zCSoundSystem@@UBEMXZ
        vfunc f07_SetMasterVolume;         // from zCSoundSystem  ?SetMasterVolume@zCSoundSystem@@UAEXM@Z
        vfunc f08_GetMasterVolume;         // from zCSoundSystem  ?GetMasterVolume@zCSoundSystem@@UAEMXZ
        vfunc f09_PlaySound;               // from base           purecall
        vfunc f10_PlaySound;               // from base           purecall
        vfunc f11_PlaySound3D;             // from base           purecall
        vfunc f12_PlaySound3D;             // from base           purecall
        vfunc f13_StopSound;               // from zCSoundSystem  ?StopSound@zCSoundSystem@@UAEXABH@Z
        vfunc f14_StopAllSounds;           // from zCSoundSystem  ?StopAllSounds@zCSoundSystem@@UAEXXZ
        vfunc f15_GetSound3DProps;         // from base           purecall
        vfunc f16_UpdateSound3D;           // from base           purecall
        vfunc f17_GetSoundProps;           // from zCSoundSystem  ?GetSoundProps@zCSoundSystem@@UAEXABHAAHAAM2@Z
        vfunc f18_UpdateSoundProps;        // from zCSoundSystem  ?UpdateSoundProps@zCSoundSystem@@UAEXABHHMM@Z
        vfunc f19_IsSoundActive;           // from zCSoundSystem  ?IsSoundActive@zCSoundSystem@@UAEHABH@Z
        vfunc f20_DoSoundUpdate;           // from base           purecall
        vfunc f21_SetListener;             // from zCSoundSystem  ?SetListener@zCSoundSystem@@UAEXPAVzCVob@@@Z
        vfunc f22_SetGlobalReverbPreset;   // from zCSoundSystem  ?SetGlobalReverbPreset@zCSoundSystem@@UAEXHM@Z
        vfunc f23_SetReverbEnabled;        // from zCSoundSystem  ?SetReverbEnabled@zCSoundSystem@@UAEXH@Z
        vfunc f24_GetReverbEnabled;        // from zCSoundSystem  ?GetReverbEnabled@zCSoundSystem@@UAEHXZ
        vfunc f25_GetNumProvider;          // from zCSoundSystem  ?GetNumProvider@zCSoundSystem@@UAEHXZ
        vfunc f26_GetProviderName;         // from zCSoundSystem  ?GetProviderName@zCSoundSystem@@UAEPBVzSTRING@@H@Z
        vfunc f27_SetProvider;             // from zCSoundSystem  ?SetProvider@zCSoundSystem@@UAEHH@Z
        vfunc f28_SetSpeakerType;          // from zCSoundSystem  ?SetSpeakerType@zCSoundSystem@@UAEXW4zTSpeakerType@1@@Z
        vfunc f29_GetSpeakerType;          // from zCSoundSystem  ?GetSpeakerType@zCSoundSystem@@UAE?AW4zTSpeakerType@1@XZ
        vfunc f30_SetGlobalOcclusion;      // from base           purecall
        vfunc f31_GetCPULoad;              // from zCSoundSystem  ?GetCPULoad@zCSoundSystem@@UAEMXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831294;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCSoundSystem& GetTable() {
      MemUnlock;
      return *(vftable_zCSoundSystem*)GetAddress();
    }
  };


  struct vftable_zCSndFX_MSS {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;         // from zCSoundFX    ?_GetClassDef@zCSoundFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base         
        vfunc f04_LoadResourceData;    // from zCSndFX_MSS  ?LoadResourceData@zCSndFX_MSS@@UAEHXZ
        vfunc f05_ReleaseResourceData; // from zCSndFX_MSS  ?ReleaseResourceData@zCSndFX_MSS@@UAEHXZ
        vfunc f06_GetResSizeBytes;     // from zCSndFX_MSS  ?GetResSizeBytes@zCSndFX_MSS@@UAEKXZ
        vfunc f07_GetCacheConfig;      // from zCSoundFX    ?GetCacheConfig@zCSoundFX@@UAEXAAK0@Z
        vfunc f08_GetNumChannels;      // from zCSndFX_MSS  ?GetNumChannels@zCSndFX_MSS@@UBEHXZ
        vfunc f09_GetNumChannelFrames; // from zCSndFX_MSS  ?GetNumChannelFrames@zCSndFX_MSS@@UBEHH@Z
        vfunc f10_GetChannelFrame;     // from zCSndFX_MSS  ?GetChannelFrame@zCSndFX_MSS@@UBEXHH@Z
        vfunc f11_SetChannelFrame;     // from zCSndFX_MSS  ?SetChannelFrame@zCSndFX_MSS@@UAEXHH@Z
        vfunc f12_GetPlayingTimeMSEC;  // from zCSndFX_MSS  ?GetPlayingTimeMSEC@zCSndFX_MSS@@UBEMXZ
        vfunc f13_GetPan;              // from zCSndFX_MSS  ?GetPan@zCSndFX_MSS@@UBEMXZ
        vfunc f14_SetPan;              // from zCSndFX_MSS  ?SetPan@zCSndFX_MSS@@UAEXM@Z
        vfunc f15_GetVolume;           // from zCSndFX_MSS  ?GetVolume@zCSndFX_MSS@@UBEMXZ
        vfunc f16_SetVolume;           // from zCSndFX_MSS  ?SetVolume@zCSndFX_MSS@@UAEXM@Z
        vfunc f17_GetFrequency;        // from zCSndFX_MSS  ?GetFrequency@zCSndFX_MSS@@UBEHXZ
        vfunc f18_SetFrequency;        // from zCSndFX_MSS  ?SetFrequency@zCSndFX_MSS@@UAEXH@Z
        vfunc f19_SetLooping;          // from zCSndFX_MSS  ?SetLooping@zCSndFX_MSS@@UAEXH@Z
        vfunc f20_IsLooping;           // from zCSndFX_MSS  ?IsLooping@zCSndFX_MSS@@UBEHXZ
        vfunc f21_SetIsFixed;          // from zCSndFX_MSS  ?SetIsFixed@zCSndFX_MSS@@UAEXH@Z
        vfunc f22_GetIsFixed;          // from zCSndFX_MSS  ?GetIsFixed@zCSndFX_MSS@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083131C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCSndFX_MSS& GetTable() {
      MemUnlock;
      return *(vftable_zCSndFX_MSS*)GetAddress();
    }
  };


  struct vftable_zCSoundFX {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;         // from zCSoundFX   ?_GetClassDef@zCSoundFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base        
        vfunc f04_LoadResourceData;    // from zCResource  ?LoadResourceData@zCResource@@UAEHXZ
        vfunc f05_ReleaseResourceData; // from zCResource  ?ReleaseResourceData@zCResource@@UAEHXZ
        vfunc f06_GetResSizeBytes;     // from zCResource  ?GetResSizeBytes@zCResource@@UAEKXZ
        vfunc f07_GetCacheConfig;      // from zCSoundFX   ?GetCacheConfig@zCSoundFX@@UAEXAAK0@Z
        vfunc f08_GetNumChannels;      // from zCSoundFX   ?GetNumChannels@zCSoundFX@@UBEHXZ
        vfunc f09_GetNumChannelFrames; // from zCSoundFX   ?GetNumChannelFrames@zCSoundFX@@UBEHH@Z
        vfunc f10_GetChannelFrame;     // from zCSoundFX   ?GetChannelFrame@zCSoundFX@@UBEXHH@Z
        vfunc f11_SetChannelFrame;     // from zCSoundFX   ?SetChannelFrame@zCSoundFX@@UAEXHH@Z
        vfunc f12_GetPlayingTimeMSEC;  // from zCSoundFX   ?GetPlayingTimeMSEC@zCSoundFX@@UBEMXZ
        vfunc f13_GetPan;              // from zCSoundFX   ?GetPan@zCSoundFX@@UBEMXZ
        vfunc f14_SetPan;              // from zCSoundFX   ?SetPan@zCSoundFX@@UAEXM@Z
        vfunc f15_GetVolume;           // from zCSoundFX   ?GetVolume@zCSoundFX@@UBEMXZ
        vfunc f16_SetVolume;           // from zCSoundFX   ?SetVolume@zCSoundFX@@UAEXM@Z
        vfunc f17_GetFrequency;        // from zCSoundFX   ?GetFrequency@zCSoundFX@@UBEHXZ
        vfunc f18_SetFrequency;        // from zCSoundFX   ?SetFrequency@zCSoundFX@@UAEXH@Z
        vfunc f19_SetLooping;          // from zCSoundFX   ?SetLooping@zCSoundFX@@UAEXH@Z
        vfunc f20_IsLooping;           // from zCSoundFX   ?IsLooping@zCSoundFX@@UBEHXZ
        vfunc f21_SetIsFixed;          // from zCSoundFX   ?SetIsFixed@zCSoundFX@@UAEXH@Z
        vfunc f22_GetIsFixed;          // from zCSoundFX   ?GetIsFixed@zCSoundFX@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083137C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCSoundFX& GetTable() {
      MemUnlock;
      return *(vftable_zCSoundFX*)GetAddress();
    }
  };


  struct vftable_zCViewWindow_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831404;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewWindow_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCViewWindow_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCViewWindow_for_zCViewBase {
    union {
      vfunc array[12];
      group {
        vfunc f00_anx;               // from zCView      ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView      ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView      ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView      ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView      ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView      ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView      ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase  ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView      ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base        
        vfunc f10_Blit;              // from zCView      ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView      ?DrawItems@zCView@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083140C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCViewWindow_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewWindow_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCAIPlayer {
    union {
      vfunc array[14];
      group {
        vfunc f00_GetClassDef;                     // from zCAIPlayer  ?_GetClassDef@zCAIPlayer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCAIPlayer  ?Archive@zCAIPlayer@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCAIPlayer  ?Unarchive@zCAIPlayer@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base        
        vfunc f04_DoAI;                            // from zCAIPlayer  ?DoAI@zCAIPlayer@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase    ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase    ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase    ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase    ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIPlayer  ?HostVobRemovedFromWorld@zCAIPlayer@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase    ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase    ?GetIsProjectile@zCAIBase@@UAEHXZ
        vfunc f12_StartStandAni;                   // from zCAIPlayer  ?StartStandAni@zCAIPlayer@@UAEXXZ
        vfunc f13_StartFallDownAni;                // from zCAIPlayer  ?StartFallDownAni@zCAIPlayer@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083151C;
    }

    static uint GetFuncsNum() {
      return 14;
    }

    static vftable_zCAIPlayer& GetTable() {
      MemUnlock;
      return *(vftable_zCAIPlayer*)GetAddress();
    }
  };


  struct vftable_zCArchiverFactory {
    union {
      vfunc array[7];
      group {
        vfunc f00_CreateArchiverRead;  // from zCArchiverFactory  ?CreateArchiverRead@zCArchiverFactory@@UAEPAVzCArchiver@@ABVzSTRING@@H@Z
        vfunc f01_CreateArchiverRead;  // from zCArchiverFactory  ?CreateArchiverRead@zCArchiverFactory@@UAEPAVzCArchiver@@PAVzFILE@@H@Z
        vfunc f02_CreateArchiverRead;  // from zCArchiverFactory  ?CreateArchiverRead@zCArchiverFactory@@UAEPAVzCArchiver@@PAVzCBuffer@@H@Z
        vfunc f03_CreateArchiverWrite; // from zCArchiverFactory  ?CreateArchiverWrite@zCArchiverFactory@@UAEPAVzCArchiver@@ABVzSTRING@@W4zTArchiveMode@@HH@Z
        vfunc f04_CreateArchiverWrite; // from zCArchiverFactory  ?CreateArchiverWrite@zCArchiverFactory@@UAEPAVzCArchiver@@PAVzFILE@@W4zTArchiveMode@@HH@Z
        vfunc f05_CreateArchiverWrite; // from zCArchiverFactory  ?CreateArchiverWrite@zCArchiverFactory@@UAEPAVzCArchiver@@W4zTArchiveMode@@HH@Z
        vfunc f06_CreateArchiverWrite; // from zCArchiverFactory  ?CreateArchiverWrite@zCArchiverFactory@@UAEPAVzCArchiver@@PAVzCBuffer@@W4zTArchiveMode@@HH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008316A8;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCArchiverFactory& GetTable() {
      MemUnlock;
      return *(vftable_zCArchiverFactory*)GetAddress();
    }
  };


  struct vftable_zCArchiverBinSafe {
    union {
      vfunc array[92];
      group {
        vfunc f00_GetClassDef;            // from zCArchiverBinSafe  ?_GetClassDef@zCArchiverBinSafe@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                // from zCObject           ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;              // from zCObject           ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;      // from base               
        vfunc f04_WriteInt;               // from zCArchiverBinSafe  ?WriteInt@zCArchiverBinSafe@@UAIXPBDH@Z
        vfunc f05_WriteByte;              // from zCArchiverBinSafe  ?WriteByte@zCArchiverBinSafe@@UAIXPBDE@Z
        vfunc f06_WriteWord;              // from zCArchiverBinSafe  ?WriteWord@zCArchiverBinSafe@@UAIXPBDG@Z
        vfunc f07_WriteFloat;             // from zCArchiverBinSafe  ?WriteFloat@zCArchiverBinSafe@@UAIXPBDM@Z
        vfunc f08_WriteBool;              // from zCArchiverBinSafe  ?WriteBool@zCArchiverBinSafe@@UAIXPBDH@Z
        vfunc f09_WriteString;            // from zCArchiverBinSafe  ?WriteString@zCArchiverBinSafe@@UAIXPBDABVzSTRING@@@Z
        vfunc f10_WriteVec3;              // from zCArchiverBinSafe  ?WriteVec3@zCArchiverBinSafe@@UAIXPBDABVzVEC3@@@Z
        vfunc f11_WriteColor;             // from zCArchiverBinSafe  ?WriteColor@zCArchiverBinSafe@@UAIXPBDABUzCOLOR@@@Z
        vfunc f12_WriteRaw;               // from zCArchiverBinSafe  ?WriteRaw@zCArchiverBinSafe@@UAIXPBDPAXK@Z
        vfunc f13_WriteRawFloat;          // from zCArchiverBinSafe  ?WriteRawFloat@zCArchiverBinSafe@@UAIXPBDPAXK@Z
        vfunc f14_WriteEnum;              // from zCArchiverBinSafe  ?WriteEnum@zCArchiverBinSafe@@UAIXPBD0H@Z
        vfunc f15_WriteObject;            // from zCArchiverBinSafe  ?WriteObject@zCArchiverBinSafe@@MAIXPBDAAVzCObject@@@Z
        vfunc f16_WriteObject;            // from zCArchiverBinSafe  ?WriteObject@zCArchiverBinSafe@@UAIXPBDPAVzCObject@@@Z
        vfunc f17_WriteObject;            // from zCArchiverBinSafe  ?WriteObject@zCArchiverBinSafe@@UAIXPAVzCObject@@@Z
        vfunc f18_WriteChunkStart;        // from zCArchiverBinSafe  ?WriteChunkStart@zCArchiverBinSafe@@MAIXPBD0GK@Z
        vfunc f19_WriteChunkStart;        // from zCArchiverBinSafe  ?WriteChunkStart@zCArchiverBinSafe@@UAIXPBDG@Z
        vfunc f20_WriteChunkEnd;          // from zCArchiverBinSafe  ?WriteChunkEnd@zCArchiverBinSafe@@UAIXXZ
        vfunc f21_WriteGroupBegin;        // from zCArchiverBinSafe  ?WriteGroupBegin@zCArchiverBinSafe@@UAIXPBD@Z
        vfunc f22_WriteGroupEnd;          // from zCArchiverBinSafe  ?WriteGroupEnd@zCArchiverBinSafe@@UAIXPBD@Z
        vfunc f23_ReadInt;                // from zCArchiverBinSafe  ?ReadInt@zCArchiverBinSafe@@UAIHPBD@Z
        vfunc f24_ReadInt;                // from zCArchiverBinSafe  ?ReadInt@zCArchiverBinSafe@@UAIXPBDAAH@Z
        vfunc f25_ReadByte;               // from zCArchiverBinSafe  ?ReadByte@zCArchiverBinSafe@@UAIEPBD@Z
        vfunc f26_ReadByte;               // from zCArchiverBinSafe  ?ReadByte@zCArchiverBinSafe@@UAIXPBDAAE@Z
        vfunc f27_ReadWord;               // from zCArchiverBinSafe  ?ReadWord@zCArchiverBinSafe@@UAIGPBD@Z
        vfunc f28_ReadWord;               // from zCArchiverBinSafe  ?ReadWord@zCArchiverBinSafe@@UAIXPBDAAG@Z
        vfunc f29_ReadFloat;              // from zCArchiverBinSafe  ?ReadFloat@zCArchiverBinSafe@@UAIMPBD@Z
        vfunc f30_ReadFloat;              // from zCArchiverBinSafe  ?ReadFloat@zCArchiverBinSafe@@UAIXPBDAAM@Z
        vfunc f31_ReadBool;               // from zCArchiverBinSafe  ?ReadBool@zCArchiverBinSafe@@UAIHPBD@Z
        vfunc f32_ReadBool;               // from zCArchiverBinSafe  ?ReadBool@zCArchiverBinSafe@@UAIXPBDAAH@Z
        vfunc f33_ReadString;             // from zCArchiverBinSafe  ?ReadString@zCArchiverBinSafe@@UAI?AVzSTRING@@PBD@Z
        vfunc f34_ReadString;             // from zCArchiverBinSafe  ?ReadString@zCArchiverBinSafe@@UAIXPBDAAVzSTRING@@@Z
        vfunc f35_ReadVec3;               // from zCArchiverBinSafe  ?ReadVec3@zCArchiverBinSafe@@UAI?AVzVEC3@@PBD@Z
        vfunc f36_ReadVec3;               // from zCArchiverBinSafe  ?ReadVec3@zCArchiverBinSafe@@UAIXPBDAAVzVEC3@@@Z
        vfunc f37_ReadColor;              // from zCArchiverBinSafe  ?ReadColor@zCArchiverBinSafe@@UAI?AUzCOLOR@@PBD@Z
        vfunc f38_ReadColor;              // from zCArchiverBinSafe  ?ReadColor@zCArchiverBinSafe@@UAIXPBDAAUzCOLOR@@@Z
        vfunc f39_ReadEnum;               // from zCArchiverBinSafe  ?ReadEnum@zCArchiverBinSafe@@UAIHPBD@Z
        vfunc f40_ReadEnum;               // from zCArchiverBinSafe  ?ReadEnum@zCArchiverBinSafe@@UAIXPBDAAH@Z
        vfunc f41_ReadRaw;                // from zCArchiverBinSafe  ?ReadRaw@zCArchiverBinSafe@@UAIXPBDPAXK@Z
        vfunc f42_ReadRawFloat;           // from zCArchiverBinSafe  ?ReadRawFloat@zCArchiverBinSafe@@UAIXPBDPAXK@Z
        vfunc f43_ReadObject;             // from zCArchiverBinSafe  ?ReadObject@zCArchiverBinSafe@@UAIPAVzCObject@@PBDPAV2@@Z
        vfunc f44_ReadObject;             // from zCArchiverBinSafe  ?ReadObject@zCArchiverBinSafe@@UAIPAVzCObject@@PAV2@@Z
        vfunc f45_ReadObjectAccount;      // from zCArchiver         ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDH0PAV2@@Z
        vfunc f46_ReadObjectAccount;      // from zCArchiver         ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDHPAV2@@Z
        vfunc f47_ReadChunkStart;         // from zCArchiverBinSafe  ?ReadChunkStart@zCArchiverBinSafe@@MAIHPBD@Z
        vfunc f48_ReadChunkStart;         // from zCArchiverBinSafe  ?ReadChunkStart@zCArchiverBinSafe@@UAIHAAVzSTRING@@AAG@Z
        vfunc f49_ReadChunkStartNamed;    // from zCArchiverBinSafe  ?ReadChunkStartNamed@zCArchiverBinSafe@@UAIHPBDAAG@Z
        vfunc f50_SkipOpenChunk;          // from zCArchiverBinSafe  ?SkipOpenChunk@zCArchiverBinSafe@@UAIXXZ
        vfunc f51_GetCurrentChunkVersion; // from zCArchiverBinSafe  ?GetCurrentChunkVersion@zCArchiverBinSafe@@UAIGXZ
        vfunc f52_GetFile;                // from zCArchiverBinSafe  ?GetFile@zCArchiverBinSafe@@UBEPAVzFILE@@XZ
        vfunc f53_GetBufferString;        // from zCArchiverBinSafe  ?GetBufferString@zCArchiverBinSafe@@UAIXAAVzSTRING@@@Z
        vfunc f54_GetBuffer;              // from zCArchiverBinSafe  ?GetBuffer@zCArchiverBinSafe@@UAIPAVzCBuffer@@XZ
        vfunc f55_EndOfArchive;           // from zCArchiverBinSafe  ?EndOfArchive@zCArchiverBinSafe@@UAIHXZ
        vfunc f56_Close;                  // from zCArchiverBinSafe  ?Close@zCArchiverBinSafe@@UAEXXZ
        vfunc f57_SetStringEOL;           // from zCArchiverBinSafe  ?SetStringEOL@zCArchiverBinSafe@@UAEXABVzSTRING@@@Z
        vfunc f58_GetStringEOL;           // from zCArchiverBinSafe  ?GetStringEOL@zCArchiverBinSafe@@UBE?AVzSTRING@@XZ
        vfunc f59_IsStringValid;          // from zCArchiverBinSafe  ?IsStringValid@zCArchiverBinSafe@@UAEHPBD@Z
        vfunc f60_GetChecksumEnabled;     // from zCArchiverBinSafe  ?GetChecksumEnabled@zCArchiverBinSafe@@UBEHXZ
        vfunc f61_SetChecksumEnabled;     // from zCArchiverBinSafe  ?SetChecksumEnabled@zCArchiverBinSafe@@UAEXH@Z
        vfunc f62_SetNoReadSearchCycles;  // from zCArchiverBinSafe  ?SetNoReadSearchCycles@zCArchiverBinSafe@@UAEXH@Z
        vfunc f63_InProperties;           // from zCArchiverBinSafe  ?InProperties@zCArchiverBinSafe@@UBEHXZ
        vfunc f64_InSaveGame;             // from zCArchiverBinSafe  ?InSaveGame@zCArchiverBinSafe@@UBEHXZ
        vfunc f65_InBinaryMode;           // from zCArchiverBinSafe  ?InBinaryMode@zCArchiverBinSafe@@UBEHXZ
        vfunc f66_GetParentObject;        // from zCArchiverBinSafe  ?GetParentObject@zCArchiverBinSafe@@UAIPAVzCObject@@XZ
        vfunc f67_OpenWriteBuffer;        // from zCArchiverBinSafe  ?OpenWriteBuffer@zCArchiverBinSafe@@MAEHPAVzCBuffer@@W4zTArchiveMode@@HHH@Z
        vfunc f68_OpenWriteFile;          // from zCArchiverBinSafe  ?OpenWriteFile@zCArchiverBinSafe@@MAEXPAVzFILE@@W4zTArchiveMode@@HHH@Z
        vfunc f69_WriteHeader;            // from zCArchiverBinSafe  ?WriteHeader@zCArchiverBinSafe@@MAIXH@Z
        vfunc f70_WriteHeaderNumObj;      // from zCArchiverBinSafe  ?WriteHeaderNumObj@zCArchiverBinSafe@@MAIXXZ
        vfunc f71_WriteASCIILine;         // from zCArchiverBinSafe  ?WriteASCIILine@zCArchiverBinSafe@@MAIXPBD0ABVzSTRING@@@Z
        vfunc f72_StoreBuffer;            // from zCArchiverBinSafe  ?StoreBuffer@zCArchiverBinSafe@@MAIXPAXK@Z
        vfunc f73_StoreString;            // from zCArchiverBinSafe  ?StoreString@zCArchiverBinSafe@@MAIXPBD@Z
        vfunc f74_StoreStringEOL;         // from zCArchiverBinSafe  ?StoreStringEOL@zCArchiverBinSafe@@MAIXPBD@Z
        vfunc f75_StoreGetPos;            // from zCArchiverBinSafe  ?StoreGetPos@zCArchiverBinSafe@@MAIKXZ
        vfunc f76_StoreSeek;              // from zCArchiverBinSafe  ?StoreSeek@zCArchiverBinSafe@@MAIXK@Z
        vfunc f77_OpenReadBuffer;         // from zCArchiverBinSafe  ?OpenReadBuffer@zCArchiverBinSafe@@MAEHAAVzCBuffer@@W4zTArchiveMode@@HH@Z
        vfunc f78_OpenReadFile;           // from zCArchiverBinSafe  ?OpenReadFile@zCArchiverBinSafe@@MAEXPAVzFILE@@W4zTArchiveMode@@HHH@Z
        vfunc f79_GetClassDefByString;    // from zCArchiverBinSafe  ?GetClassDefByString@zCArchiverBinSafe@@MAIPAVzCClassDef@@ABVzSTRING@@@Z
        vfunc f80_CreateObject;           // from zCArchiverBinSafe  ?CreateObject@zCArchiverBinSafe@@MAIPAVzCObject@@ABVzSTRING@@@Z
        vfunc f81_SkipChunk;              // from zCArchiverBinSafe  ?SkipChunk@zCArchiverBinSafe@@MAIXH@Z
        vfunc f82_ReadChunkStartASCII;    // from zCArchiverBinSafe  ?ReadChunkStartASCII@zCArchiverBinSafe@@MAIXPBDAAVzSTRING@@@Z
        vfunc f83_ReadChunkEnd;           // from zCArchiverBinSafe  ?ReadChunkEnd@zCArchiverBinSafe@@MAIXXZ
        vfunc f84_ReadEntryASCII;         // from zCArchiverBinSafe  ?ReadEntryASCII@zCArchiverBinSafe@@MAIHPBDAAVzSTRING@@@Z
        vfunc f85_ReadHeader;             // from zCArchiverBinSafe  ?ReadHeader@zCArchiverBinSafe@@MAIXXZ
        vfunc f86_RestoreBuffer;          // from zCArchiverBinSafe  ?RestoreBuffer@zCArchiverBinSafe@@MAIXPAXK@Z
        vfunc f87_RestoreStringEOL;       // from zCArchiverBinSafe  ?RestoreStringEOL@zCArchiverBinSafe@@MAIXAAVzSTRING@@@Z
        vfunc f88_RestoreString0;         // from zCArchiverBinSafe  ?RestoreString0@zCArchiverBinSafe@@MAIXAAVzSTRING@@@Z
        vfunc f89_RestoreGetPos;          // from zCArchiverBinSafe  ?RestoreGetPos@zCArchiverBinSafe@@MAIKXZ
        vfunc f90_RestoreSeek;            // from zCArchiverBinSafe  ?RestoreSeek@zCArchiverBinSafe@@MAIXK@Z
        vfunc f91_DeleteBuffer;           // from zCArchiverBinSafe  ?DeleteBuffer@zCArchiverBinSafe@@MAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008316D4;
    }

    static uint GetFuncsNum() {
      return 92;
    }

    static vftable_zCArchiverBinSafe& GetTable() {
      MemUnlock;
      return *(vftable_zCArchiverBinSafe*)GetAddress();
    }
  };


  struct vftable_zCArchiver {
    union {
      vfunc array[92];
      group {
        vfunc f00_GetClassDef;            // from zCArchiver  ?_GetClassDef@zCArchiver@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;              // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;      // from base        
        vfunc f04_WriteInt;               // from this        purecall
        vfunc f05_WriteByte;              // from this        purecall
        vfunc f06_WriteWord;              // from this        purecall
        vfunc f07_WriteFloat;             // from this        purecall
        vfunc f08_WriteBool;              // from this        purecall
        vfunc f09_WriteString;            // from this        purecall
        vfunc f10_WriteVec3;              // from this        purecall
        vfunc f11_WriteColor;             // from this        purecall
        vfunc f12_WriteRaw;               // from this        purecall
        vfunc f13_WriteRawFloat;          // from this        purecall
        vfunc f14_WriteEnum;              // from this        purecall
        vfunc f15_WriteObject;            // from this        purecall
        vfunc f16_WriteObject;            // from this        purecall
        vfunc f17_WriteObject;            // from this        purecall
        vfunc f18_WriteChunkStart;        // from this        purecall
        vfunc f19_WriteChunkStart;        // from this        purecall
        vfunc f20_WriteChunkEnd;          // from this        purecall
        vfunc f21_WriteGroupBegin;        // from this        purecall
        vfunc f22_WriteGroupEnd;          // from this        purecall
        vfunc f23_ReadInt;                // from this        purecall
        vfunc f24_ReadInt;                // from this        purecall
        vfunc f25_ReadByte;               // from this        purecall
        vfunc f26_ReadByte;               // from this        purecall
        vfunc f27_ReadWord;               // from this        purecall
        vfunc f28_ReadWord;               // from this        purecall
        vfunc f29_ReadFloat;              // from this        purecall
        vfunc f30_ReadFloat;              // from this        purecall
        vfunc f31_ReadBool;               // from this        purecall
        vfunc f32_ReadBool;               // from this        purecall
        vfunc f33_ReadString;             // from this        purecall
        vfunc f34_ReadString;             // from this        purecall
        vfunc f35_ReadVec3;               // from this        purecall
        vfunc f36_ReadVec3;               // from this        purecall
        vfunc f37_ReadColor;              // from this        purecall
        vfunc f38_ReadColor;              // from this        purecall
        vfunc f39_ReadEnum;               // from this        purecall
        vfunc f40_ReadEnum;               // from this        purecall
        vfunc f41_ReadRaw;                // from this        purecall
        vfunc f42_ReadRawFloat;           // from this        purecall
        vfunc f43_ReadObject;             // from this        purecall
        vfunc f44_ReadObject;             // from this        purecall
        vfunc f45_ReadObjectAccount;      // from zCArchiver  ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDH0PAV2@@Z
        vfunc f46_ReadObjectAccount;      // from zCArchiver  ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDHPAV2@@Z
        vfunc f47_ReadChunkStart;         // from this        purecall
        vfunc f48_ReadChunkStart;         // from this        purecall
        vfunc f49_ReadChunkStartNamed;    // from this        purecall
        vfunc f50_SkipOpenChunk;          // from this        purecall
        vfunc f51_GetCurrentChunkVersion; // from this        purecall
        vfunc f52_GetFile;                // from this        purecall
        vfunc f53_GetBufferString;        // from this        purecall
        vfunc f54_GetBuffer;              // from this        purecall
        vfunc f55_EndOfArchive;           // from this        purecall
        vfunc f56_Close;                  // from this        purecall
        vfunc f57_SetStringEOL;           // from this        purecall
        vfunc f58_GetStringEOL;           // from this        purecall
        vfunc f59_IsStringValid;          // from this        purecall
        vfunc f60_GetChecksumEnabled;     // from this        purecall
        vfunc f61_SetChecksumEnabled;     // from this        purecall
        vfunc f62_SetNoReadSearchCycles;  // from this        purecall
        vfunc f63_InProperties;           // from this        purecall
        vfunc f64_InSaveGame;             // from this        purecall
        vfunc f65_InBinaryMode;           // from this        purecall
        vfunc f66_GetParentObject;        // from this        purecall
        vfunc f67_OpenWriteBuffer;        // from this        purecall
        vfunc f68_OpenWriteFile;          // from this        purecall
        vfunc f69_WriteHeader;            // from this        purecall
        vfunc f70_WriteHeaderNumObj;      // from this        purecall
        vfunc f71_WriteASCIILine;         // from this        purecall
        vfunc f72_StoreBuffer;            // from this        purecall
        vfunc f73_StoreString;            // from this        purecall
        vfunc f74_StoreStringEOL;         // from this        purecall
        vfunc f75_StoreGetPos;            // from this        purecall
        vfunc f76_StoreSeek;              // from this        purecall
        vfunc f77_OpenReadBuffer;         // from this        purecall
        vfunc f78_OpenReadFile;           // from this        purecall
        vfunc f79_GetClassDefByString;    // from this        purecall
        vfunc f80_CreateObject;           // from this        purecall
        vfunc f81_SkipChunk;              // from this        purecall
        vfunc f82_ReadChunkStartASCII;    // from this        purecall
        vfunc f83_ReadChunkEnd;           // from this        purecall
        vfunc f84_ReadEntryASCII;         // from this        purecall
        vfunc f85_ReadHeader;             // from this        purecall
        vfunc f86_RestoreBuffer;          // from this        purecall
        vfunc f87_RestoreStringEOL;       // from this        purecall
        vfunc f88_RestoreString0;         // from this        purecall
        vfunc f89_RestoreGetPos;          // from this        purecall
        vfunc f90_RestoreSeek;            // from this        purecall
        vfunc f91_DeleteBuffer;           // from this        purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0083184C;
    }

    static uint GetFuncsNum() {
      return 92;
    }

    static vftable_zCArchiver& GetTable() {
      MemUnlock;
      return *(vftable_zCArchiver*)GetAddress();
    }
  };


  struct vftable_zCArchiverGeneric {
    union {
      vfunc array[92];
      group {
        vfunc f00_GetClassDef;            // from zCArchiverGeneric  ?_GetClassDef@zCArchiverGeneric@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                // from zCObject           ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;              // from zCObject           ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;      // from base               
        vfunc f04_WriteInt;               // from zCArchiverGeneric  ?WriteInt@zCArchiverGeneric@@UAIXPBDH@Z
        vfunc f05_WriteByte;              // from zCArchiverGeneric  ?WriteByte@zCArchiverGeneric@@UAIXPBDE@Z
        vfunc f06_WriteWord;              // from zCArchiverGeneric  ?WriteWord@zCArchiverGeneric@@UAIXPBDG@Z
        vfunc f07_WriteFloat;             // from zCArchiverGeneric  ?WriteFloat@zCArchiverGeneric@@UAIXPBDM@Z
        vfunc f08_WriteBool;              // from zCArchiverGeneric  ?WriteBool@zCArchiverGeneric@@UAIXPBDH@Z
        vfunc f09_WriteString;            // from zCArchiverGeneric  ?WriteString@zCArchiverGeneric@@UAIXPBDABVzSTRING@@@Z
        vfunc f10_WriteVec3;              // from zCArchiverGeneric  ?WriteVec3@zCArchiverGeneric@@UAIXPBDABVzVEC3@@@Z
        vfunc f11_WriteColor;             // from zCArchiverGeneric  ?WriteColor@zCArchiverGeneric@@UAIXPBDABUzCOLOR@@@Z
        vfunc f12_WriteRaw;               // from zCArchiverGeneric  ?WriteRaw@zCArchiverGeneric@@UAIXPBDPAXK@Z
        vfunc f13_WriteRawFloat;          // from zCArchiverGeneric  ?WriteRawFloat@zCArchiverGeneric@@UAIXPBDPAXK@Z
        vfunc f14_WriteEnum;              // from zCArchiverGeneric  ?WriteEnum@zCArchiverGeneric@@UAIXPBD0H@Z
        vfunc f15_WriteObject;            // from zCArchiverGeneric  ?WriteObject@zCArchiverGeneric@@MAIXPBDAAVzCObject@@@Z
        vfunc f16_WriteObject;            // from zCArchiverGeneric  ?WriteObject@zCArchiverGeneric@@UAIXPBDPAVzCObject@@@Z
        vfunc f17_WriteObject;            // from zCArchiverGeneric  ?WriteObject@zCArchiverGeneric@@UAIXPAVzCObject@@@Z
        vfunc f18_WriteChunkStart;        // from zCArchiverGeneric  ?WriteChunkStart@zCArchiverGeneric@@MAIXPBD0GK@Z
        vfunc f19_WriteChunkStart;        // from zCArchiverGeneric  ?WriteChunkStart@zCArchiverGeneric@@UAIXPBDG@Z
        vfunc f20_WriteChunkEnd;          // from zCArchiverGeneric  ?WriteChunkEnd@zCArchiverGeneric@@UAIXXZ
        vfunc f21_WriteGroupBegin;        // from zCArchiverGeneric  ?WriteGroupBegin@zCArchiverGeneric@@UAIXPBD@Z
        vfunc f22_WriteGroupEnd;          // from zCArchiverGeneric  ?WriteGroupEnd@zCArchiverGeneric@@UAIXPBD@Z
        vfunc f23_ReadInt;                // from zCArchiverGeneric  ?ReadInt@zCArchiverGeneric@@UAIHPBD@Z
        vfunc f24_ReadInt;                // from zCArchiverGeneric  ?ReadInt@zCArchiverGeneric@@UAIXPBDAAH@Z
        vfunc f25_ReadByte;               // from zCArchiverGeneric  ?ReadByte@zCArchiverGeneric@@UAIEPBD@Z
        vfunc f26_ReadByte;               // from zCArchiverGeneric  ?ReadByte@zCArchiverGeneric@@UAIXPBDAAE@Z
        vfunc f27_ReadWord;               // from zCArchiverGeneric  ?ReadWord@zCArchiverGeneric@@UAIGPBD@Z
        vfunc f28_ReadWord;               // from zCArchiverGeneric  ?ReadWord@zCArchiverGeneric@@UAIXPBDAAG@Z
        vfunc f29_ReadFloat;              // from zCArchiverGeneric  ?ReadFloat@zCArchiverGeneric@@UAIMPBD@Z
        vfunc f30_ReadFloat;              // from zCArchiverGeneric  ?ReadFloat@zCArchiverGeneric@@UAIXPBDAAM@Z
        vfunc f31_ReadBool;               // from zCArchiverGeneric  ?ReadBool@zCArchiverGeneric@@UAIHPBD@Z
        vfunc f32_ReadBool;               // from zCArchiverGeneric  ?ReadBool@zCArchiverGeneric@@UAIXPBDAAH@Z
        vfunc f33_ReadString;             // from zCArchiverGeneric  ?ReadString@zCArchiverGeneric@@UAI?AVzSTRING@@PBD@Z
        vfunc f34_ReadString;             // from zCArchiverGeneric  ?ReadString@zCArchiverGeneric@@UAIXPBDAAVzSTRING@@@Z
        vfunc f35_ReadVec3;               // from zCArchiverGeneric  ?ReadVec3@zCArchiverGeneric@@UAI?AVzVEC3@@PBD@Z
        vfunc f36_ReadVec3;               // from zCArchiverGeneric  ?ReadVec3@zCArchiverGeneric@@UAIXPBDAAVzVEC3@@@Z
        vfunc f37_ReadColor;              // from zCArchiverGeneric  ?ReadColor@zCArchiverGeneric@@UAI?AUzCOLOR@@PBD@Z
        vfunc f38_ReadColor;              // from zCArchiverGeneric  ?ReadColor@zCArchiverGeneric@@UAIXPBDAAUzCOLOR@@@Z
        vfunc f39_ReadEnum;               // from zCArchiverGeneric  ?ReadEnum@zCArchiverGeneric@@UAIHPBD@Z
        vfunc f40_ReadEnum;               // from zCArchiverGeneric  ?ReadEnum@zCArchiverGeneric@@UAIXPBDAAH@Z
        vfunc f41_ReadRaw;                // from zCArchiverGeneric  ?ReadRaw@zCArchiverGeneric@@UAIXPBDPAXK@Z
        vfunc f42_ReadRawFloat;           // from zCArchiverGeneric  ?ReadRawFloat@zCArchiverGeneric@@UAIXPBDPAXK@Z
        vfunc f43_ReadObject;             // from zCArchiverGeneric  ?ReadObject@zCArchiverGeneric@@UAIPAVzCObject@@PBDPAV2@@Z
        vfunc f44_ReadObject;             // from zCArchiverGeneric  ?ReadObject@zCArchiverGeneric@@UAIPAVzCObject@@PAV2@@Z
        vfunc f45_ReadObjectAccount;      // from zCArchiver         ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDH0PAV2@@Z
        vfunc f46_ReadObjectAccount;      // from zCArchiver         ?ReadObjectAccount@zCArchiver@@UAIPAVzCObject@@PBDHPAV2@@Z
        vfunc f47_ReadChunkStart;         // from zCArchiverGeneric  ?ReadChunkStart@zCArchiverGeneric@@MAIHPBD@Z
        vfunc f48_ReadChunkStart;         // from zCArchiverGeneric  ?ReadChunkStart@zCArchiverGeneric@@UAIHAAVzSTRING@@AAG@Z
        vfunc f49_ReadChunkStartNamed;    // from zCArchiverGeneric  ?ReadChunkStartNamed@zCArchiverGeneric@@UAIHPBDAAG@Z
        vfunc f50_SkipOpenChunk;          // from zCArchiverGeneric  ?SkipOpenChunk@zCArchiverGeneric@@UAIXXZ
        vfunc f51_GetCurrentChunkVersion; // from zCArchiverGeneric  ?GetCurrentChunkVersion@zCArchiverGeneric@@UAIGXZ
        vfunc f52_GetFile;                // from zCArchiverGeneric  ?GetFile@zCArchiverGeneric@@UBEPAVzFILE@@XZ
        vfunc f53_GetBufferString;        // from zCArchiverGeneric  ?GetBufferString@zCArchiverGeneric@@UAIXAAVzSTRING@@@Z
        vfunc f54_GetBuffer;              // from zCArchiverGeneric  ?GetBuffer@zCArchiverGeneric@@UAIPAVzCBuffer@@XZ
        vfunc f55_EndOfArchive;           // from zCArchiverGeneric  ?EndOfArchive@zCArchiverGeneric@@UAIHXZ
        vfunc f56_Close;                  // from zCArchiverGeneric  ?Close@zCArchiverGeneric@@UAEXXZ
        vfunc f57_SetStringEOL;           // from zCArchiverGeneric  ?SetStringEOL@zCArchiverGeneric@@UAEXABVzSTRING@@@Z
        vfunc f58_GetStringEOL;           // from zCArchiverGeneric  ?GetStringEOL@zCArchiverGeneric@@UBE?AVzSTRING@@XZ
        vfunc f59_IsStringValid;          // from zCArchiverGeneric  ?IsStringValid@zCArchiverGeneric@@UAEHPBD@Z
        vfunc f60_GetChecksumEnabled;     // from zCArchiverGeneric  ?GetChecksumEnabled@zCArchiverGeneric@@UBEHXZ
        vfunc f61_SetChecksumEnabled;     // from zCArchiverGeneric  ?SetChecksumEnabled@zCArchiverGeneric@@UAEXH@Z
        vfunc f62_SetNoReadSearchCycles;  // from zCArchiverGeneric  ?SetNoReadSearchCycles@zCArchiverGeneric@@UAEXH@Z
        vfunc f63_InProperties;           // from zCArchiverGeneric  ?InProperties@zCArchiverGeneric@@UBEHXZ
        vfunc f64_InSaveGame;             // from zCArchiverGeneric  ?InSaveGame@zCArchiverGeneric@@UBEHXZ
        vfunc f65_InBinaryMode;           // from zCArchiverGeneric  ?InBinaryMode@zCArchiverGeneric@@UBEHXZ
        vfunc f66_GetParentObject;        // from zCArchiverGeneric  ?GetParentObject@zCArchiverGeneric@@UAIPAVzCObject@@XZ
        vfunc f67_OpenWriteBuffer;        // from zCArchiverGeneric  ?OpenWriteBuffer@zCArchiverGeneric@@MAEHPAVzCBuffer@@W4zTArchiveMode@@HHH@Z
        vfunc f68_OpenWriteFile;          // from zCArchiverGeneric  ?OpenWriteFile@zCArchiverGeneric@@MAEXPAVzFILE@@W4zTArchiveMode@@HHH@Z
        vfunc f69_WriteHeader;            // from zCArchiverGeneric  ?WriteHeader@zCArchiverGeneric@@MAIXH@Z
        vfunc f70_WriteHeaderNumObj;      // from zCArchiverGeneric  ?WriteHeaderNumObj@zCArchiverGeneric@@MAIXXZ
        vfunc f71_WriteASCIILine;         // from zCArchiverGeneric  ?WriteASCIILine@zCArchiverGeneric@@MAIXPBD0ABVzSTRING@@@Z
        vfunc f72_StoreBuffer;            // from zCArchiverGeneric  ?StoreBuffer@zCArchiverGeneric@@MAIXPAXK@Z
        vfunc f73_StoreString;            // from zCArchiverGeneric  ?StoreString@zCArchiverGeneric@@MAIXPBD@Z
        vfunc f74_StoreStringEOL;         // from zCArchiverGeneric  ?StoreStringEOL@zCArchiverGeneric@@MAIXPBD@Z
        vfunc f75_StoreGetPos;            // from zCArchiverGeneric  ?StoreGetPos@zCArchiverGeneric@@MAIKXZ
        vfunc f76_StoreSeek;              // from zCArchiverGeneric  ?StoreSeek@zCArchiverGeneric@@MAIXK@Z
        vfunc f77_OpenReadBuffer;         // from zCArchiverGeneric  ?OpenReadBuffer@zCArchiverGeneric@@MAEHAAVzCBuffer@@W4zTArchiveMode@@HH@Z
        vfunc f78_OpenReadFile;           // from zCArchiverGeneric  ?OpenReadFile@zCArchiverGeneric@@MAEXPAVzFILE@@W4zTArchiveMode@@HHH@Z
        vfunc f79_GetClassDefByString;    // from zCArchiverGeneric  ?GetClassDefByString@zCArchiverGeneric@@MAIPAVzCClassDef@@ABVzSTRING@@@Z
        vfunc f80_CreateObject;           // from zCArchiverGeneric  ?CreateObject@zCArchiverGeneric@@MAIPAVzCObject@@ABVzSTRING@@@Z
        vfunc f81_SkipChunk;              // from zCArchiverGeneric  ?SkipChunk@zCArchiverGeneric@@MAIXH@Z
        vfunc f82_ReadChunkStartASCII;    // from zCArchiverGeneric  ?ReadChunkStartASCII@zCArchiverGeneric@@MAIXPBDAAVzSTRING@@@Z
        vfunc f83_ReadChunkEnd;           // from zCArchiverGeneric  ?ReadChunkEnd@zCArchiverGeneric@@MAIXXZ
        vfunc f84_ReadEntryASCII;         // from zCArchiverGeneric  ?ReadEntryASCII@zCArchiverGeneric@@MAIHPBDAAVzSTRING@@@Z
        vfunc f85_ReadHeader;             // from zCArchiverGeneric  ?ReadHeader@zCArchiverGeneric@@MAIXXZ
        vfunc f86_RestoreBuffer;          // from zCArchiverGeneric  ?RestoreBuffer@zCArchiverGeneric@@MAIXPAXK@Z
        vfunc f87_RestoreStringEOL;       // from zCArchiverGeneric  ?RestoreStringEOL@zCArchiverGeneric@@MAIXAAVzSTRING@@@Z
        vfunc f88_RestoreString0;         // from zCArchiverGeneric  ?RestoreString0@zCArchiverGeneric@@MAIXAAVzSTRING@@@Z
        vfunc f89_RestoreGetPos;          // from zCArchiverGeneric  ?RestoreGetPos@zCArchiverGeneric@@MAIKXZ
        vfunc f90_RestoreSeek;            // from zCArchiverGeneric  ?RestoreSeek@zCArchiverGeneric@@MAIXK@Z
        vfunc f91_DeleteBuffer;           // from zCArchiverGeneric  ?DeleteBuffer@zCArchiverGeneric@@MAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008319DC;
    }

    static uint GetFuncsNum() {
      return 92;
    }

    static vftable_zCArchiverGeneric& GetTable() {
      MemUnlock;
      return *(vftable_zCArchiverGeneric*)GetAddress();
    }
  };


  struct vftable_zCRndAlphaSortObject_Vob {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base                      
        vfunc f01_Draw;              // from zCRndAlphaSortObject_Vob  ?Draw@zCRndAlphaSortObject_Vob@@UAEXH@Z
        vfunc f02_IsAlphaPoly;       // from zCRndAlphaSortObject      ?IsAlphaPoly@zCRndAlphaSortObject@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831BA4;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCRndAlphaSortObject_Vob& GetTable() {
      MemUnlock;
      return *(vftable_zCRndAlphaSortObject_Vob*)GetAddress();
    }
  };


  struct vftable_zCRndAlphaSortObject {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base                  
        vfunc f01_Draw;              // from base                  purecall
        vfunc f02_IsAlphaPoly;       // from zCRndAlphaSortObject  ?IsAlphaPoly@zCRndAlphaSortObject@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831BB4;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCRndAlphaSortObject& GetTable() {
      MemUnlock;
      return *(vftable_zCRndAlphaSortObject*)GetAddress();
    }
  };


  struct vftable_zCCollisionReport {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00831D44;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCCollisionReport& GetTable() {
      MemUnlock;
      return *(vftable_zCCollisionReport*)GetAddress();
    }
  };


  struct vftable_zCCollisionDetector {
    union {
      vfunc array[5];
      group {
        vfunc f00_scalar_destructor;               // from base                 
        vfunc f01_DetectCollisions;                // from zCCollisionDetector  ?DetectCollisions@zCCollisionDetector@@UAIXPAVzCCollisionObject@@ABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f02_RegisterStaticIntersectionTest;  // from zCCollisionDetector  ?RegisterStaticIntersectionTest@zCCollisionDetector@@UAIXPAVzCCollisionObjectDef@@0P6AHMPAVzCCollisionObject@@ABVzMAT4@@12PAPAVzCCollisionReport@@@Z@Z
        vfunc f03_RegisterDynamicIntersectionTest; // from zCCollisionDetector  ?RegisterDynamicIntersectionTest@zCCollisionDetector@@UAIXPAVzCCollisionObjectDef@@0P6AHPAVzCCollisionObject@@1PAPAVzCCollisionReport@@@Z@Z
        vfunc f04_CanCollide;                      // from zCCollisionDetector  ?CanCollide@zCCollisionDetector@@UAIHPAVzCCollisionObjectDef@@0@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831D4C;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_zCCollisionDetector& GetTable() {
      MemUnlock;
      return *(vftable_zCCollisionDetector*)GetAddress();
    }
  };


  struct vftable_zCCollisionObject {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollisionObject  ?GetCollObjClass@zCCollisionObject@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base               
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject  ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject  ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject  ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject  ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollisionObject  ?GetLargestBBox3DLocal@zCCollisionObject@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831D78;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollisionObject& GetTable() {
      MemUnlock;
      return *(vftable_zCCollisionObject*)GetAddress();
    }
  };


  struct vftable_zCCollObjectUndef {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectUndef  ?GetCollObjClass@zCCollObjectUndef@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base               
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject  ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject  ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject  ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject  ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase   ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831DAC;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectUndef& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectUndef*)GetAddress();
    }
  };


  struct vftable_zCCollObjectLevelPolys {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectLevelPolys  ?GetCollObjClass@zCCollObjectLevelPolys@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                    
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject       ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject       ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject       ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject       ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase        ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831DCC;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectLevelPolys& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectLevelPolys*)GetAddress();
    }
  };


  struct vftable_zCCollObjectPoint {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectPoint  ?GetCollObjClass@zCCollObjectPoint@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base               
        vfunc f02_DetectCollisionsSelf;      // from zCCollObjectPoint  ?DetectCollisionsSelf@zCCollObjectPoint@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollObjectPoint  ?CollisionResponse@zCCollObjectPoint@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject  ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject  ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectPoint  ?GetLargestBBox3DLocal@zCCollObjectPoint@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831DEC;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectPoint& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectPoint*)GetAddress();
    }
  };


  struct vftable_zCCollObjectProjectile {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectProjectile  ?GetCollObjClass@zCCollObjectProjectile@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                    
        vfunc f02_DetectCollisionsSelf;      // from zCCollObjectPoint       ?DetectCollisionsSelf@zCCollObjectPoint@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollObjectPoint       ?CollisionResponse@zCCollObjectPoint@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject       ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject       ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectPoint       ?GetLargestBBox3DLocal@zCCollObjectPoint@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831E0C;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectProjectile& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectProjectile*)GetAddress();
    }
  };


  struct vftable_zCCollObjectComplex {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectComplex  ?GetCollObjClass@zCCollObjectComplex@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                 
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject    ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollObjectComplex  ?CollisionResponse@zCCollObjectComplex@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollObjectComplex  ?GetAdaptiveStepSize@zCCollObjectComplex@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject    ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase     ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831E2C;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectComplex& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectComplex*)GetAddress();
    }
  };


  struct vftable_zCCollObjectBoxBlocker {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectBoxBlocker  ?GetCollObjClass@zCCollObjectBoxBlocker@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                    
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject       ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject       ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject       ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject       ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase        ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831E4C;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectBoxBlocker& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectBoxBlocker*)GetAddress();
    }
  };


  struct vftable_zCCollObjectBoxPassThrough {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectBoxPassThrough  ?GetCollObjClass@zCCollObjectBoxPassThrough@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                        
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject           ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject           ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject           ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollObjectBoxPassThrough  ?SuppressCollisionResponse@zCCollObjectBoxPassThrough@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase            ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831E6C;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectBoxPassThrough& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectBoxPassThrough*)GetAddress();
    }
  };


  struct vftable_zCCollObjectCharacter {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollObjectCharacter  ?GetCollObjClass@zCCollObjectCharacter@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                   
        vfunc f02_DetectCollisionsSelf;      // from zCCollObjectCharacter  ?DetectCollisionsSelf@zCCollObjectCharacter@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollObjectCharacter  ?CollisionResponse@zCCollObjectCharacter@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollObjectCharacter  ?GetAdaptiveStepSize@zCCollObjectCharacter@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject      ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectCharacter  ?GetLargestBBox3DLocal@zCCollObjectCharacter@@UAIXAAUzTBBox3D@@@Z
        vfunc f07_GetPrimitiveCC;            // from zCCollObjectCharacter  ?GetPrimitiveCC@zCCollObjectCharacter@@UBEPAVzCConvexPrimitive@@XZ
        vfunc f08_IsDead;                    // from zCCollObjectCharacter  ?IsDead@zCCollObjectCharacter@@UBEHXZ
        vfunc f09_DontLetHimComeNearer;      // from zCCollObjectCharacter  ?DontLetHimComeNearer@zCCollObjectCharacter@@UBEHPBVzCVob@@@Z
        vfunc f10_TurnSpeed;                 // from zCCollObjectCharacter  ?TurnSpeed@zCCollObjectCharacter@@MBEMXZ
        vfunc f11_PushAround;                // from zCCollObjectCharacter  ?PushAround@zCCollObjectCharacter@@MAEXABVzVEC3@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831EA0;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCCollObjectCharacter& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectCharacter*)GetAddress();
    }
  };


  struct vftable_zCCollObjectBase {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetCollObjClass;           // from zCCollisionObject  ?GetCollObjClass@zCCollisionObject@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base               
        vfunc f02_DetectCollisionsSelf;      // from zCCollisionObject  ?DetectCollisionsSelf@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollisionObject  ?CollisionResponse@zCCollisionObject@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollisionObject  ?GetAdaptiveStepSize@zCCollisionObject@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject  ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectBase   ?GetLargestBBox3DLocal@zCCollObjectBase@@UAIXAAUzTBBox3D@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00831ED4;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCCollObjectBase& GetTable() {
      MemUnlock;
      return *(vftable_zCCollObjectBase*)GetAddress();
    }
  };


  struct vftable_zCConvexPrimitiveUnitSphere {
    union {
      vfunc array[8];
      group {
        vfunc f00_vector_destructor;        // from base                         
        vfunc f01_PointNearestToPlaneLocal; // from zCConvexPrimitiveUnitSphere  ?PointNearestToPlaneLocal@zCConvexPrimitiveUnitSphere@@UBEXABVzVEC3@@AAV2@@Z
        vfunc f02_GetCenterLocal;           // from zCConvexPrimitive            ?GetCenterLocal@zCConvexPrimitive@@UBEXAAVzVEC3@@@Z
        vfunc f03_PointIsInLocal;           // from zCConvexPrimitiveUnitSphere  ?PointIsInLocal@zCConvexPrimitiveUnitSphere@@UBEHABVzVEC3@@@Z
        vfunc f04_SymetrySphere;            // from zCConvexPrimitiveUnitSphere  ?SymetrySphere@zCConvexPrimitiveUnitSphere@@UBEHXZ
        vfunc f05_SymetryRotation;          // from zCConvexPrimitiveUnitSphere  ?SymetryRotation@zCConvexPrimitiveUnitSphere@@UBEHAAVzVEC3@@@Z
        vfunc f06_UpdateBBox;               // from zCConvexPrimitiveUnitSphere  ?UpdateBBox@zCConvexPrimitiveUnitSphere@@UAEXXZ
        vfunc f07_DrawVirtual;              // from zCConvexPrimitiveUnitSphere  ?DrawVirtual@zCConvexPrimitiveUnitSphere@@UBEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831F54;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCConvexPrimitiveUnitSphere& GetTable() {
      MemUnlock;
      return *(vftable_zCConvexPrimitiveUnitSphere*)GetAddress();
    }
  };


  struct vftable_zCConvexPrimitive {
    union {
      vfunc array[8];
      group {
        vfunc f00_scalar_destructor;        // from base               
        vfunc f01_PointNearestToPlaneLocal; // from base               purecall
        vfunc f02_GetCenterLocal;           // from zCConvexPrimitive  ?GetCenterLocal@zCConvexPrimitive@@UBEXAAVzVEC3@@@Z
        vfunc f03_PointIsInLocal;           // from base               purecall
        vfunc f04_SymetrySphere;            // from zCConvexPrimitive  ?SymetrySphere@zCConvexPrimitive@@UBEHXZ
        vfunc f05_SymetryRotation;          // from zCConvexPrimitive  ?SymetryRotation@zCConvexPrimitive@@UBEHAAVzVEC3@@@Z
        vfunc f06_UpdateBBox;               // from zCConvexPrimitive  ?UpdateBBox@zCConvexPrimitive@@UAEXXZ
        vfunc f07_DrawVirtual;              // from zCConvexPrimitive  ?DrawVirtual@zCConvexPrimitive@@UBEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831F78;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCConvexPrimitive& GetTable() {
      MemUnlock;
      return *(vftable_zCConvexPrimitive*)GetAddress();
    }
  };


  struct vftable_zCConvexPrimitiveScaleTrans {
    union {
      vfunc array[8];
      group {
        vfunc f00_vector_destructor;        // from base                         
        vfunc f01_PointNearestToPlaneLocal; // from zCConvexPrimitiveScaleTrans  ?PointNearestToPlaneLocal@zCConvexPrimitiveScaleTrans@@UBEXABVzVEC3@@AAV2@@Z
        vfunc f02_GetCenterLocal;           // from zCConvexPrimitiveScaleTrans  ?GetCenterLocal@zCConvexPrimitiveScaleTrans@@UBEXAAVzVEC3@@@Z
        vfunc f03_PointIsInLocal;           // from zCConvexPrimitiveScaleTrans  ?PointIsInLocal@zCConvexPrimitiveScaleTrans@@UBEHABVzVEC3@@@Z
        vfunc f04_SymetrySphere;            // from zCConvexPrimitive            ?SymetrySphere@zCConvexPrimitive@@UBEHXZ
        vfunc f05_SymetryRotation;          // from zCConvexPrimitive            ?SymetryRotation@zCConvexPrimitive@@UBEHAAVzVEC3@@@Z
        vfunc f06_UpdateBBox;               // from zCConvexPrimitiveScaleTrans  ?UpdateBBox@zCConvexPrimitiveScaleTrans@@UAEXXZ
        vfunc f07_DrawVirtual;              // from zCConvexPrimitiveScaleTrans  ?DrawVirtual@zCConvexPrimitiveScaleTrans@@UBEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831FA4;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCConvexPrimitiveScaleTrans& GetTable() {
      MemUnlock;
      return *(vftable_zCConvexPrimitiveScaleTrans*)GetAddress();
    }
  };


  struct vftable_zCConvexPrimitiveEllipsoid {
    union {
      vfunc array[8];
      group {
        vfunc f00_scalar_destructor;        // from base                         
        vfunc f01_PointNearestToPlaneLocal; // from zCConvexPrimitiveScaleTrans  ?PointNearestToPlaneLocal@zCConvexPrimitiveScaleTrans@@UBEXABVzVEC3@@AAV2@@Z
        vfunc f02_GetCenterLocal;           // from zCConvexPrimitiveScaleTrans  ?GetCenterLocal@zCConvexPrimitiveScaleTrans@@UBEXAAVzVEC3@@@Z
        vfunc f03_PointIsInLocal;           // from zCConvexPrimitiveScaleTrans  ?PointIsInLocal@zCConvexPrimitiveScaleTrans@@UBEHABVzVEC3@@@Z
        vfunc f04_SymetrySphere;            // from zCConvexPrimitive            ?SymetrySphere@zCConvexPrimitive@@UBEHXZ
        vfunc f05_SymetryRotation;          // from zCConvexPrimitiveEllipsoid   ?SymetryRotation@zCConvexPrimitiveEllipsoid@@UBEHAAVzVEC3@@@Z
        vfunc f06_UpdateBBox;               // from zCConvexPrimitiveScaleTrans  ?UpdateBBox@zCConvexPrimitiveScaleTrans@@UAEXXZ
        vfunc f07_DrawVirtual;              // from zCConvexPrimitiveScaleTrans  ?DrawVirtual@zCConvexPrimitiveScaleTrans@@UBEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00831FC8;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCConvexPrimitiveEllipsoid& GetTable() {
      MemUnlock;
      return *(vftable_zCConvexPrimitiveEllipsoid*)GetAddress();
    }
  };


  struct vftable_zCDecal {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCDecal   ?_GetClassDef@zCDecal@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCDecal   ?Archive@zCDecal@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCDecal   ?Unarchive@zCDecal@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_Render;                  // from zCDecal   ?Render@zCDecal@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCDecal   ?IsBBox3DLocal@zCDecal@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCDecal   ?GetBBox3D@zCDecal@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual  ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCDecal   ?GetVisualName@zCDecal@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual  ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCDecal   ?SetVisualUsedBy@zCDecal@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCDecal   ?DynLightVisual@zCDecal@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCDecal   ?GetRenderSortKey@zCDecal@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual  ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual  ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual  ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual  ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCDecal   ?GetFileExtension@zCDecal@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual  ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCDecal   ?GetAlphaTestingEnabled@zCDecal@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual  ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCDecal   ?LoadVisualVirtual@zCDecal@@MBEPAVzCVisual@@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832084;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCDecal& GetTable() {
      MemUnlock;
      return *(vftable_zCDecal*)GetAddress();
    }
  };


  struct vftable_zCEngine {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00832100;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCEngine& GetTable() {
      MemUnlock;
      return *(vftable_zCEngine*)GetAddress();
    }
  };


  struct vftable_zCFFT {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x00832128;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCFFT& GetTable() {
      MemUnlock;
      return *(vftable_zCFFT*)GetAddress();
    }
  };


  struct vftable_zCLensFlareFX {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCLensFlareFX  ?_GetClassDef@zCLensFlareFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCLensFlareFX  ?Archive@zCLensFlareFX@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCLensFlareFX  ?Unarchive@zCLensFlareFX@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base           
      } names;
    };

    static uint GetAddress() {
      return 0x008321E4;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCLensFlareFX& GetTable() {
      MemUnlock;
      return *(vftable_zCLensFlareFX*)GetAddress();
    }
  };


  struct vftable_zCMaterial {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCMaterial  ?_GetClassDef@zCMaterial@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCMaterial  ?Archive@zCMaterial@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCMaterial  ?Unarchive@zCMaterial@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base        
      } names;
    };

    static uint GetAddress() {
      return 0x00832214;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCMaterial& GetTable() {
      MemUnlock;
      return *(vftable_zCMaterial*)GetAddress();
    }
  };


  struct vftable_zCMalloc {
    union {
      vfunc array[12];
      group {
        vfunc f00_scalar_destructor; // from base      
        vfunc f01_Malloc;            // from base      purecall
        vfunc f02_Malloc;            // from base      purecall
        vfunc f03_Realloc;           // from base      purecall
        vfunc f04_Free;              // from base      purecall
        vfunc f05_GetStats;          // from zCMalloc  ?GetStats@zCMalloc@@UAEHAAUzTMallocStats@@@Z
        vfunc f06_GetProcessStats;   // from zCMalloc  ?GetProcessStats@zCMalloc@@UAEHAAUzTMallocProcessStats@@@Z
        vfunc f07_DumpHeap;          // from zCMalloc  ?DumpHeap@zCMalloc@@UAEHW4zTMallocDumpHeapMode@@@Z
        vfunc f08_CheckHeap;         // from zCMalloc  ?CheckHeap@zCMalloc@@UAEHXZ
        vfunc f09_CheckPtr;          // from zCMalloc  ?CheckPtr@zCMalloc@@UAE?AW4zTMallocCheckPtrError@@PAX@Z
        vfunc f10_Init;              // from base      purecall
        vfunc f11_Shutdown;          // from base      purecall
      } names;
    };

    static uint GetAddress() {
      return 0x00832228;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCMalloc& GetTable() {
      MemUnlock;
      return *(vftable_zCMalloc*)GetAddress();
    }
  };


  struct vftable_zCMallocGeneric {
    union {
      vfunc array[12];
      group {
        vfunc f00_scalar_destructor; // from base             
        vfunc f01_Malloc;            // from zCMallocGeneric  ?Malloc@zCMallocGeneric@@UAEPAXIPBD0H@Z
        vfunc f02_Malloc;            // from zCMallocGeneric  ?Malloc@zCMallocGeneric@@UAEPAXI@Z
        vfunc f03_Realloc;           // from zCMallocGeneric  ?Realloc@zCMallocGeneric@@UAEPAXPAXI@Z
        vfunc f04_Free;              // from zCMallocGeneric  ?Free@zCMallocGeneric@@UAEXPAX@Z
        vfunc f05_GetStats;          // from zCMallocGeneric  ?GetStats@zCMallocGeneric@@UAEHAAUzTMallocStats@@@Z
        vfunc f06_GetProcessStats;   // from zCMalloc         ?GetProcessStats@zCMalloc@@UAEHAAUzTMallocProcessStats@@@Z
        vfunc f07_DumpHeap;          // from zCMalloc         ?DumpHeap@zCMalloc@@UAEHW4zTMallocDumpHeapMode@@@Z
        vfunc f08_CheckHeap;         // from zCMalloc         ?CheckHeap@zCMalloc@@UAEHXZ
        vfunc f09_CheckPtr;          // from zCMalloc         ?CheckPtr@zCMalloc@@UAE?AW4zTMallocCheckPtrError@@PAX@Z
        vfunc f10_Init;              // from zCMallocGeneric  ?Init@zCMallocGeneric@@UAEHH@Z
        vfunc f11_Shutdown;          // from zCMallocGeneric  ?Shutdown@zCMallocGeneric@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083225C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCMallocGeneric& GetTable() {
      MemUnlock;
      return *(vftable_zCMallocGeneric*)GetAddress();
    }
  };


  struct vftable_zCVolatileMemoryBase {
    union {
      vfunc array[1];
      group {
        vfunc f00_Destroyed; // from zCVolatileMemoryBase  ?Destroyed@zCVolatileMemoryBase@@MAEXPAX@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832290;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCVolatileMemoryBase& GetTable() {
      MemUnlock;
      return *(vftable_zCVolatileMemoryBase*)GetAddress();
    }
  };


  struct vftable_zCMesh {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCMesh    ?_GetClassDef@zCMesh@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_Render;                  // from zCMesh    ?Render@zCMesh@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCVisual  ?IsBBox3DLocal@zCVisual@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCMesh    ?GetBBox3D@zCMesh@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCMesh    ?GetOBBox3D@zCMesh@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCMesh    ?GetVisualName@zCMesh@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual  ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual  ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCMesh    ?DynLightVisual@zCMesh@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual  ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCMesh    ?CanTraceRay@zCMesh@@UBEHXZ
        vfunc f14_TraceRay;                // from zCMesh    ?TraceRay@zCMesh@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual  ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual  ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCMesh    ?GetFileExtension@zCMesh@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual  ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCMesh    ?GetAlphaTestingEnabled@zCMesh@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCMesh    ?SetAlphaTestingEnabled@zCMesh@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCMesh    ?LoadVisualVirtual@zCMesh@@MBEPAVzCVisual@@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008322BC;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCMesh& GetTable() {
      MemUnlock;
      return *(vftable_zCMesh*)GetAddress();
    }
  };


  struct vftable_zCModel {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;             // from zCModel   ?_GetClassDef@zCModel@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_Render;                  // from zCModel   ?Render@zCModel@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCModel   ?IsBBox3DLocal@zCModel@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCModel   ?GetBBox3D@zCModel@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual  ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCModel   ?GetVisualName@zCModel@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual  ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCModel   ?SetVisualUsedBy@zCModel@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual  ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCModel   ?GetRenderSortKey@zCModel@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCModel   ?CanTraceRay@zCModel@@UBEHXZ
        vfunc f14_TraceRay;                // from zCModel   ?TraceRay@zCModel@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCModel   ?HostVobRemovedFromWorld@zCModel@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual  ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCModel   ?GetFileExtension@zCModel@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual  ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual  ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual  ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCModel   ?LoadVisualVirtual@zCModel@@MBEPAVzCVisual@@ABVzSTRING@@@Z
        vfunc f22_StartAnimation;          // from zCModel   ?StartAnimation@zCModel@@UAEXABVzSTRING@@@Z
        vfunc f23_StopAnimation;           // from zCModel   ?StopAnimation@zCModel@@UAEXABVzSTRING@@@Z
        vfunc f24_IsAnimationActive;       // from zCModel   ?IsAnimationActive@zCModel@@UAEHABVzSTRING@@@Z
        vfunc f25_GetAnyAnimation;         // from zCModel   ?GetAnyAnimation@zCModel@@UAEPBVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083234C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_zCModel& GetTable() {
      MemUnlock;
      return *(vftable_zCModel*)GetAddress();
    }
  };


  struct vftable_zCVisualAnimate {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;             // from zCVisualAnimate  ?_GetClassDef@zCVisualAnimate@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_Render;                  // from base             purecall
        vfunc f05_IsBBox3DLocal;           // from zCVisual         ?IsBBox3DLocal@zCVisual@@UAEHXZ
        vfunc f06_GetBBox3D;               // from base             purecall
        vfunc f07_GetOBBox3D;              // from zCVisual         ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from base             purecall
        vfunc f09_GetVisualDied;           // from zCVisual         ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual         ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual         ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual         ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual         ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual         ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual         ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual         ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual         ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual         ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual         ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual         ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual         ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
        vfunc f22_StartAnimation;          // from base             purecall
        vfunc f23_StopAnimation;           // from base             purecall
        vfunc f24_IsAnimationActive;       // from base             purecall
        vfunc f25_GetAnyAnimation;         // from base             purecall
      } names;
    };

    static uint GetAddress() {
      return 0x008323BC;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_zCVisualAnimate& GetTable() {
      MemUnlock;
      return *(vftable_zCVisualAnimate*)GetAddress();
    }
  };


  struct vftable_zCModelMeshLib {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCModelMeshLib  ?_GetClassDef@zCModelMeshLib@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject        ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject        ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base            
      } names;
    };

    static uint GetAddress() {
      return 0x00832438;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCModelMeshLib& GetTable() {
      MemUnlock;
      return *(vftable_zCModelMeshLib*)GetAddress();
    }
  };


  struct vftable_zCModelAni {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCModelAni  ?_GetClassDef@zCModelAni@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base        
      } names;
    };

    static uint GetAddress() {
      return 0x00832498;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCModelAni& GetTable() {
      MemUnlock;
      return *(vftable_zCModelAni*)GetAddress();
    }
  };


  struct vftable_zCModelConvertFileHandler {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base                       
        vfunc f01_HandleFile;        // from zCModelConvertFileHandler  ?HandleFile@zCModelConvertFileHandler@@UAEHABVzSTRING@@PBDU_finddata_t@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008324B0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCModelConvertFileHandler& GetTable() {
      MemUnlock;
      return *(vftable_zCModelConvertFileHandler*)GetAddress();
    }
  };


  struct vftable_zCMorphMesh {
    union {
      vfunc array[20];
      group {
        vfunc f00_GetClassDef;             // from zCMorphMesh  ?_GetClassDef@zCMorphMesh@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_Render;                  // from zCMorphMesh  ?Render@zCMorphMesh@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCMorphMesh  ?IsBBox3DLocal@zCMorphMesh@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCMorphMesh  ?GetBBox3D@zCMorphMesh@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCMorphMesh  ?GetOBBox3D@zCMorphMesh@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCMorphMesh  ?GetVisualName@zCMorphMesh@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual     ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual     ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual     ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCMorphMesh  ?GetRenderSortKey@zCMorphMesh@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCMorphMesh  ?CanTraceRay@zCMorphMesh@@UBEHXZ
        vfunc f14_TraceRay;                // from zCMorphMesh  ?TraceRay@zCMorphMesh@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual     ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual     ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCMorphMesh  ?GetFileExtension@zCMorphMesh@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual     ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCMorphMesh  ?GetAlphaTestingEnabled@zCMorphMesh@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008324D4;
    }

    static uint GetFuncsNum() {
      return 20;
    }

    static vftable_zCMorphMesh& GetTable() {
      MemUnlock;
      return *(vftable_zCMorphMesh*)GetAddress();
    }
  };


  struct vftable_zCMorphMeshConvertFileHandler {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base                           
        vfunc f01_HandleFile;        // from zCMorphMeshConvertFileHandler  ?HandleFile@zCMorphMeshConvertFileHandler@@UAEHABVzSTRING@@PBDU_finddata_t@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832544;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCMorphMeshConvertFileHandler& GetTable() {
      MemUnlock;
      return *(vftable_zCMorphMeshConvertFileHandler*)GetAddress();
    }
  };


  struct vftable_zCParticleFX {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCParticleFX  ?_GetClassDef@zCParticleFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject      ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject      ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_Render;                  // from zCParticleFX  ?Render@zCParticleFX@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCParticleFX  ?IsBBox3DLocal@zCParticleFX@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCParticleFX  ?GetBBox3D@zCParticleFX@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual      ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCParticleFX  ?GetVisualName@zCParticleFX@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCParticleFX  ?GetVisualDied@zCParticleFX@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCParticleFX  ?SetVisualUsedBy@zCParticleFX@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual      ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCParticleFX  ?GetRenderSortKey@zCParticleFX@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual      ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual      ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCParticleFX  ?HostVobRemovedFromWorld@zCParticleFX@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCParticleFX  ?HostVobAddedToWorld@zCParticleFX@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCParticleFX  ?GetFileExtension@zCParticleFX@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual      ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual      ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual      ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCParticleFX  ?LoadVisualVirtual@zCParticleFX@@MBEPAVzCVisual@@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008325C4;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCParticleFX& GetTable() {
      MemUnlock;
      return *(vftable_zCParticleFX*)GetAddress();
    }
  };


  struct vftable_zCPFXPerFrameCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_DoWorldPerFrameCallback; // from zCPFXPerFrameCallback  ?DoWorldPerFrameCallback@zCPFXPerFrameCallback@@UAEXPAVzCWorld@@PAVzCCamera@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832620;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCPFXPerFrameCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCPFXPerFrameCallback*)GetAddress();
    }
  };


  struct vftable_zCPolyStrip {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;             // from zCPolyStrip  ?_GetClassDef@zCPolyStrip@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_Render;                  // from zCPolyStrip  ?Render@zCPolyStrip@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCPolyStrip  ?IsBBox3DLocal@zCPolyStrip@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCPolyStrip  ?GetBBox3D@zCPolyStrip@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual     ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCPolyStrip  ?GetVisualName@zCPolyStrip@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual     ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCPolyStrip  ?SetVisualUsedBy@zCPolyStrip@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual     ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual     ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual     ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual     ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual     ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual     ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual     ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual     ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual     ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual     ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual     ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
        vfunc f22_FreeResources;           // from zCPolyStrip  ?FreeResources@zCPolyStrip@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008326B4;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCPolyStrip& GetTable() {
      MemUnlock;
      return *(vftable_zCPolyStrip*)GetAddress();
    }
  };


  struct vftable_zCLightning_zCBolt {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;             // from zCPolyStrip  ?_GetClassDef@zCPolyStrip@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_Render;                  // from zCLightning  ?Render@zCBolt@zCLightning@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCPolyStrip  ?IsBBox3DLocal@zCPolyStrip@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCPolyStrip  ?GetBBox3D@zCPolyStrip@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual     ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCPolyStrip  ?GetVisualName@zCPolyStrip@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual     ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCPolyStrip  ?SetVisualUsedBy@zCPolyStrip@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual     ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual     ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual     ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual     ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual     ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual     ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual     ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual     ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual     ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual     ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual     ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
        vfunc f22_FreeResources;           // from zCLightning  ?FreeResources@zCBolt@zCLightning@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083271C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCLightning_zCBolt& GetTable() {
      MemUnlock;
      return *(vftable_zCLightning_zCBolt*)GetAddress();
    }
  };


  struct vftable_zCMeshSoftSkin {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;             // from zCMeshSoftSkin   ?_GetClassDef@zCMeshSoftSkin@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_Render;                  // from zCProgMeshProto  ?Render@zCProgMeshProto@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCProgMeshProto  ?IsBBox3DLocal@zCProgMeshProto@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCProgMeshProto  ?GetBBox3D@zCProgMeshProto@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCProgMeshProto  ?GetOBBox3D@zCProgMeshProto@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCProgMeshProto  ?GetVisualName@zCProgMeshProto@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual         ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual         ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCProgMeshProto  ?DynLightVisual@zCProgMeshProto@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCProgMeshProto  ?GetRenderSortKey@zCProgMeshProto@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCProgMeshProto  ?CanTraceRay@zCProgMeshProto@@UBEHXZ
        vfunc f14_TraceRay;                // from zCProgMeshProto  ?TraceRay@zCProgMeshProto@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual         ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual         ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCProgMeshProto  ?GetFileExtension@zCProgMeshProto@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual         ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCProgMeshProto  ?GetAlphaTestingEnabled@zCProgMeshProto@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCProgMeshProto  ?SetAlphaTestingEnabled@zCProgMeshProto@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCProgMeshProto  ?LoadVisualVirtual@zCProgMeshProto@@MBEPAVzCVisual@@ABVzSTRING@@@Z
        vfunc f22_Load;                    // from zCMeshSoftSkin   ?Load@zCMeshSoftSkin@@UAEHAAVzCFileBIN@@@Z
        vfunc f23_Save;                    // from zCMeshSoftSkin   ?Save@zCMeshSoftSkin@@UAEHAAVzCFileBIN@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832964;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCMeshSoftSkin& GetTable() {
      MemUnlock;
      return *(vftable_zCMeshSoftSkin*)GetAddress();
    }
  };


  struct vftable_zCProgMeshProto {
    union {
      vfunc array[24];
      group {
        vfunc f00_GetClassDef;             // from zCProgMeshProto  ?_GetClassDef@zCProgMeshProto@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_Render;                  // from zCProgMeshProto  ?Render@zCProgMeshProto@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCProgMeshProto  ?IsBBox3DLocal@zCProgMeshProto@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCProgMeshProto  ?GetBBox3D@zCProgMeshProto@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCProgMeshProto  ?GetOBBox3D@zCProgMeshProto@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCProgMeshProto  ?GetVisualName@zCProgMeshProto@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual         ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual         ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCProgMeshProto  ?DynLightVisual@zCProgMeshProto@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCProgMeshProto  ?GetRenderSortKey@zCProgMeshProto@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCProgMeshProto  ?CanTraceRay@zCProgMeshProto@@UBEHXZ
        vfunc f14_TraceRay;                // from zCProgMeshProto  ?TraceRay@zCProgMeshProto@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual         ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual         ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCProgMeshProto  ?GetFileExtension@zCProgMeshProto@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual         ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCProgMeshProto  ?GetAlphaTestingEnabled@zCProgMeshProto@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCProgMeshProto  ?SetAlphaTestingEnabled@zCProgMeshProto@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCProgMeshProto  ?LoadVisualVirtual@zCProgMeshProto@@MBEPAVzCVisual@@ABVzSTRING@@@Z
        vfunc f22_Load;                    // from zCProgMeshProto  ?Load@zCProgMeshProto@@UAEHAAVzCFileBIN@@@Z
        vfunc f23_Save;                    // from zCProgMeshProto  ?Save@zCProgMeshProto@@UAEHAAVzCFileBIN@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008329CC;
    }

    static uint GetFuncsNum() {
      return 24;
    }

    static vftable_zCProgMeshProto& GetTable() {
      MemUnlock;
      return *(vftable_zCProgMeshProto*)GetAddress();
    }
  };


  struct vftable_zCProgMeshConvertFileHandler {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base                          
        vfunc f01_HandleFile;        // from zCProgMeshConvertFileHandler  ?HandleFile@zCProgMeshConvertFileHandler@@UAEHABVzSTRING@@PBDU_finddata_t@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832A3C;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCProgMeshConvertFileHandler& GetTable() {
      MemUnlock;
      return *(vftable_zCProgMeshConvertFileHandler*)GetAddress();
    }
  };


  struct vftable_zCQuadMark {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCQuadMark  ?_GetClassDef@zCQuadMark@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_Render;                  // from zCQuadMark  ?Render@zCQuadMark@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCQuadMark  ?IsBBox3DLocal@zCQuadMark@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCQuadMark  ?GetBBox3D@zCQuadMark@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual    ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCQuadMark  ?GetVisualName@zCQuadMark@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCVisual    ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCQuadMark  ?SetVisualUsedBy@zCQuadMark@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual    ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual    ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual    ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual    ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual    ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual    ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual    ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual    ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual    ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual    ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual    ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832A64;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCQuadMark& GetTable() {
      MemUnlock;
      return *(vftable_zCQuadMark*)GetAddress();
    }
  };


  struct vftable_zCRndAlphaSortObject_WorldPoly {
    union {
      vfunc array[3];
      group {
        vfunc f00_vector_destructor; // from base                            
        vfunc f01_Draw;              // from zCRndAlphaSortObject_WorldPoly  ?Draw@zCRndAlphaSortObject_WorldPoly@@UAEXH@Z
        vfunc f02_IsAlphaPoly;       // from zCRndAlphaSortObject            ?IsAlphaPoly@zCRndAlphaSortObject@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832BC8;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCRndAlphaSortObject_WorldPoly& GetTable() {
      MemUnlock;
      return *(vftable_zCRndAlphaSortObject_WorldPoly*)GetAddress();
    }
  };


  struct vftable_zCResource {
    union {
      vfunc array[8];
      group {
        vfunc f00_GetClassDef;         // from zCResource  ?_GetClassDef@zCResource@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base        
        vfunc f04_LoadResourceData;    // from zCResource  ?LoadResourceData@zCResource@@UAEHXZ
        vfunc f05_ReleaseResourceData; // from zCResource  ?ReleaseResourceData@zCResource@@UAEHXZ
        vfunc f06_GetResSizeBytes;     // from zCResource  ?GetResSizeBytes@zCResource@@UAEKXZ
        vfunc f07_GetCacheConfig;      // from zCResource  ?GetCacheConfig@zCResource@@UAEXAAK0@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832BE8;
    }

    static uint GetFuncsNum() {
      return 8;
    }

    static vftable_zCResource& GetTable() {
      MemUnlock;
      return *(vftable_zCResource*)GetAddress();
    }
  };


  struct vftable_zCResourceManager {
    union {
      vfunc array[9];
      group {
        vfunc f00_scalar_destructor;       // from base               
        vfunc f01_BeginThread;             // from zCThread           ?BeginThread@zCThread@@UAEXXZ
        vfunc f02_EndThread;               // from zCThread           ?EndThread@zCThread@@UAEXXZ
        vfunc f03_IsThreadRunning;         // from zCThread           ?IsThreadRunning@zCThread@@UAEHXZ
        vfunc f04_SuspendThread;           // from zCThread           ?SuspendThread@zCThread@@UAEHXZ
        vfunc f05_ResumeThread;            // from zCThread           ?ResumeThread@zCThread@@UAEHXZ
        vfunc f06_GetTerminationRequested; // from zCThread           ?GetTerminationRequested@zCThread@@UBEHXZ
        vfunc f07_SetTerminationRequested; // from zCThread           ?SetTerminationRequested@zCThread@@UAEXH@Z
        vfunc f08_ThreadProc;              // from zCResourceManager  ?ThreadProc@zCResourceManager@@MAEKXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832C0C;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCResourceManager& GetTable() {
      MemUnlock;
      return *(vftable_zCResourceManager*)GetAddress();
    }
  };


  struct vftable_zCSession {
    union {
      vfunc array[22];
      group {
        vfunc f00_HandleEvent;        // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
        vfunc f01_scalar_destructor;  // from base             
        vfunc f02_Init;               // from zCSession        ?Init@zCSession@@UAEXXZ
        vfunc f03_Done;               // from zCSession        ?Done@zCSession@@UAEXXZ
        vfunc f04_Render;             // from zCSession        ?Render@zCSession@@UAEXXZ
        vfunc f05_RenderBlit;         // from zCSession        ?RenderBlit@zCSession@@UAEXXZ
        vfunc f06_CamInit;            // from zCSession        ?CamInit@zCSession@@UAEXPAVzCVob@@PAVzCCamera@@@Z
        vfunc f07_CamInit;            // from zCSession        ?CamInit@zCSession@@UAEXXZ
        vfunc f08_SetCamera;          // from zCSession        ?SetCamera@zCSession@@UAEXPAVzCCamera@@@Z
        vfunc f09_GetCamera;          // from zCSession        ?GetCamera@zCSession@@UBEPAVzCCamera@@XZ
        vfunc f10_GetCameraAI;        // from zCSession        ?GetCameraAI@zCSession@@UBEPAVzCAICamera@@XZ
        vfunc f11_GetCameraVob;       // from zCSession        ?GetCameraVob@zCSession@@UBEPAVzCVob@@XZ
        vfunc f12_GetViewport;        // from zCSession        ?GetViewport@zCSession@@UBEPAVzCView@@XZ
        vfunc f13_GetWorld;           // from zCSession        ?GetWorld@zCSession@@UAEPAVzCWorld@@XZ
        vfunc f14_SaveWorld;          // from zCSession        ?SaveWorld@zCSession@@UAEXABVzSTRING@@W4zTWorldSaveMode@zCWorld@@HH@Z
        vfunc f15_LoadWorld;          // from zCSession        ?LoadWorld@zCSession@@UAEHABVzSTRING@@W4zTWorldLoadMode@zCWorld@@@Z
        vfunc f16_GetCutsceneManager; // from zCSession        ?GetCutsceneManager@zCSession@@UAEPAVzCCSManager@@XZ
        vfunc f17_SetTime;            // from zCSession        ?SetTime@zCSession@@UAEXHHH@Z
        vfunc f18_GetTime;            // from zCSession        ?GetTime@zCSession@@UAEXAAH00@Z
        vfunc f19_SetWorld;           // from zCSession        ?SetWorld@zCSession@@MAEXPAVzCWorld@@@Z
        vfunc f20_DesktopInit;        // from zCSession        ?DesktopInit@zCSession@@MAEXXZ
        vfunc f21_CutsceneSystemInit; // from zCSession        ?CutsceneSystemInit@zCSession@@MAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832C4C;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCSession& GetTable() {
      MemUnlock;
      return *(vftable_zCSession*)GetAddress();
    }
  };


  struct vftable_zCSkyControler_Indoor {
    union {
      vfunc array[36];
      group {
        vfunc f00_GetClassDef;                   // from zCSkyControler_Indoor  ?_GetClassDef@zCSkyControler_Indoor@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                       // from zCObject               ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                     // from zCObject               ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;             // from base                   
        vfunc f04_SetTime;                       // from zCSkyControler_Indoor  ?SetTime@zCSkyControler_Indoor@@UAEXM@Z
        vfunc f05_GetTime;                       // from zCSkyControler_Indoor  ?GetTime@zCSkyControler_Indoor@@UBEMXZ
        vfunc f06_ResetTime;                     // from zCSkyControler_Indoor  ?ResetTime@zCSkyControler_Indoor@@UAEXXZ
        vfunc f07_SetFarZ;                       // from zCSkyControler_Indoor  ?SetFarZ@zCSkyControler_Indoor@@UAEXM@Z
        vfunc f08_GetFarZ;                       // from zCSkyControler_Indoor  ?GetFarZ@zCSkyControler_Indoor@@UBEMXZ
        vfunc f09_SetFarZScalability;            // from zCSkyControler_Indoor  ?SetFarZScalability@zCSkyControler_Indoor@@UAEXM@Z
        vfunc f10_GetFarZScalability;            // from zCSkyControler_Indoor  ?GetFarZScalability@zCSkyControler_Indoor@@UBEMXZ
        vfunc f11_SetBackgroundColor;            // from zCSkyControler_Indoor  ?SetBackgroundColor@zCSkyControler_Indoor@@UAEXUzCOLOR@@@Z
        vfunc f12_GetBackgroundColor;            // from zCSkyControler_Indoor  ?GetBackgroundColor@zCSkyControler_Indoor@@UBE?AUzCOLOR@@XZ
        vfunc f13_GetBackgroundColorDef;         // from zCSkyControler_Indoor  ?GetBackgroundColorDef@zCSkyControler_Indoor@@UBE?AUzCOLOR@@XZ
        vfunc f14_SetOverrideColor;              // from zCSkyControler_Indoor  ?SetOverrideColor@zCSkyControler_Indoor@@UAEXVzVEC3@@@Z
        vfunc f15_SetOverrideColorFlag;          // from zCSkyControler_Indoor  ?SetOverrideColorFlag@zCSkyControler_Indoor@@UAEXH@Z
        vfunc f16_GetCloudShadowScale;           // from zCSkyControler         ?GetCloudShadowScale@zCSkyControler@@UBEMXZ
        vfunc f17_SetCloudShadowScale;           // from zCSkyControler         ?SetCloudShadowScale@zCSkyControler@@UAEXM@Z
        vfunc f18_SetFillBackground;             // from zCSkyControler         ?SetFillBackground@zCSkyControler@@UAEXH@Z
        vfunc f19_GetFillBackground;             // from zCSkyControler         ?GetFillBackground@zCSkyControler@@UBEHXZ
        vfunc f20_SetUnderwaterFX;               // from zCSkyControler_Mid     ?SetUnderwaterFX@zCSkyControler_Mid@@UAEXH@Z
        vfunc f21_GetUnderwaterFX;               // from zCSkyControler_Mid     ?GetUnderwaterFX@zCSkyControler_Mid@@UBEHXZ
        vfunc f22_UpdateWorldDependencies;       // from zCSkyControler_Indoor  ?UpdateWorldDependencies@zCSkyControler_Indoor@@UAEXXZ
        vfunc f23_SetLightDirty;                 // from zCSkyControler         ?SetLightDirty@zCSkyControler@@UAEXXZ
        vfunc f24_SetRelightTime;                // from zCSkyControler         ?SetRelightTime@zCSkyControler@@UAEXM@Z
        vfunc f25_GetRelightCtr;                 // from zCSkyControler         ?GetRelightCtr@zCSkyControler@@UAEHXZ
        vfunc f26_GetDaylightColorFromIntensity; // from zCSkyControler         ?GetDaylightColorFromIntensity@zCSkyControler@@UAE?AUzCOLOR@@H@Z
        vfunc f27_RenderSkyPre;                  // from zCSkyControler_Indoor  ?RenderSkyPre@zCSkyControler_Indoor@@UAEXXZ
        vfunc f28_RenderSkyPost;                 // from zCSkyControler_Indoor  ?RenderSkyPost@zCSkyControler_Indoor@@UAEXH@Z
        vfunc f29_GetGlobalWindVec;              // from zCSkyControler         ?GetGlobalWindVec@zCSkyControler@@UAEHAAVzVEC3@@W4zTAnimationMode@@@Z
        vfunc f30_SetGlobalSkyScale;             // from zCSkyControler         ?SetGlobalSkyScale@zCSkyControler@@UAEXM@Z
        vfunc f31_GetGlobalSkyScale;             // from zCSkyControler         ?GetGlobalSkyScale@zCSkyControler@@UBEMXZ
        vfunc f32_GetGlobalSkyScaleChanged;      // from zCSkyControler         ?GetGlobalSkyScaleChanged@zCSkyControler@@UBEHXZ
        vfunc f33_SetCameraLocationHint;         // from zCSkyControler         ?SetCameraLocationHint@zCSkyControler@@UAEXW4zTCamLocationHint@1@@Z
        vfunc f34_SetWeatherType;                // from zCSkyControler         ?SetWeatherType@zCSkyControler@@UAEXW4zTWeather@@@Z
        vfunc f35_GetWeatherType;                // from zCSkyControler         ?GetWeatherType@zCSkyControler@@UBE?AW4zTWeather@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832CBC;
    }

    static uint GetFuncsNum() {
      return 36;
    }

    static vftable_zCSkyControler_Indoor& GetTable() {
      MemUnlock;
      return *(vftable_zCSkyControler_Indoor*)GetAddress();
    }
  };


  struct vftable_zCSkyControler_Mid {
    union {
      vfunc array[36];
      group {
        vfunc f00_GetClassDef;                   // from zCSkyControler_Mid  ?_GetClassDef@zCSkyControler_Mid@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                       // from zCObject            ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                     // from zCObject            ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;             // from base                
        vfunc f04_SetTime;                       // from base                purecall
        vfunc f05_GetTime;                       // from base                purecall
        vfunc f06_ResetTime;                     // from base                purecall
        vfunc f07_SetFarZ;                       // from base                purecall
        vfunc f08_GetFarZ;                       // from base                purecall
        vfunc f09_SetFarZScalability;            // from base                purecall
        vfunc f10_GetFarZScalability;            // from base                purecall
        vfunc f11_SetBackgroundColor;            // from base                purecall
        vfunc f12_GetBackgroundColor;            // from base                purecall
        vfunc f13_GetBackgroundColorDef;         // from base                purecall
        vfunc f14_SetOverrideColor;              // from base                purecall
        vfunc f15_SetOverrideColorFlag;          // from base                purecall
        vfunc f16_GetCloudShadowScale;           // from zCSkyControler      ?GetCloudShadowScale@zCSkyControler@@UBEMXZ
        vfunc f17_SetCloudShadowScale;           // from zCSkyControler      ?SetCloudShadowScale@zCSkyControler@@UAEXM@Z
        vfunc f18_SetFillBackground;             // from zCSkyControler      ?SetFillBackground@zCSkyControler@@UAEXH@Z
        vfunc f19_GetFillBackground;             // from zCSkyControler      ?GetFillBackground@zCSkyControler@@UBEHXZ
        vfunc f20_SetUnderwaterFX;               // from zCSkyControler_Mid  ?SetUnderwaterFX@zCSkyControler_Mid@@UAEXH@Z
        vfunc f21_GetUnderwaterFX;               // from zCSkyControler_Mid  ?GetUnderwaterFX@zCSkyControler_Mid@@UBEHXZ
        vfunc f22_UpdateWorldDependencies;       // from base                purecall
        vfunc f23_SetLightDirty;                 // from zCSkyControler      ?SetLightDirty@zCSkyControler@@UAEXXZ
        vfunc f24_SetRelightTime;                // from zCSkyControler      ?SetRelightTime@zCSkyControler@@UAEXM@Z
        vfunc f25_GetRelightCtr;                 // from zCSkyControler      ?GetRelightCtr@zCSkyControler@@UAEHXZ
        vfunc f26_GetDaylightColorFromIntensity; // from zCSkyControler      ?GetDaylightColorFromIntensity@zCSkyControler@@UAE?AUzCOLOR@@H@Z
        vfunc f27_RenderSkyPre;                  // from zCSkyControler_Mid  ?RenderSkyPre@zCSkyControler_Mid@@UAEXXZ
        vfunc f28_RenderSkyPost;                 // from zCSkyControler_Mid  ?RenderSkyPost@zCSkyControler_Mid@@UAEXH@Z
        vfunc f29_GetGlobalWindVec;              // from zCSkyControler      ?GetGlobalWindVec@zCSkyControler@@UAEHAAVzVEC3@@W4zTAnimationMode@@@Z
        vfunc f30_SetGlobalSkyScale;             // from zCSkyControler      ?SetGlobalSkyScale@zCSkyControler@@UAEXM@Z
        vfunc f31_GetGlobalSkyScale;             // from zCSkyControler      ?GetGlobalSkyScale@zCSkyControler@@UBEMXZ
        vfunc f32_GetGlobalSkyScaleChanged;      // from zCSkyControler      ?GetGlobalSkyScaleChanged@zCSkyControler@@UBEHXZ
        vfunc f33_SetCameraLocationHint;         // from zCSkyControler      ?SetCameraLocationHint@zCSkyControler@@UAEXW4zTCamLocationHint@1@@Z
        vfunc f34_SetWeatherType;                // from zCSkyControler      ?SetWeatherType@zCSkyControler@@UAEXW4zTWeather@@@Z
        vfunc f35_GetWeatherType;                // from zCSkyControler      ?GetWeatherType@zCSkyControler@@UBE?AW4zTWeather@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832D54;
    }

    static uint GetFuncsNum() {
      return 36;
    }

    static vftable_zCSkyControler_Mid& GetTable() {
      MemUnlock;
      return *(vftable_zCSkyControler_Mid*)GetAddress();
    }
  };


  struct vftable_zCSkyControler {
    union {
      vfunc array[36];
      group {
        vfunc f00_GetClassDef;                   // from zCSkyControler  ?_GetClassDef@zCSkyControler@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                       // from zCObject        ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                     // from zCObject        ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;             // from base            
        vfunc f04_SetTime;                       // from base            purecall
        vfunc f05_GetTime;                       // from base            purecall
        vfunc f06_ResetTime;                     // from base            purecall
        vfunc f07_SetFarZ;                       // from base            purecall
        vfunc f08_GetFarZ;                       // from base            purecall
        vfunc f09_SetFarZScalability;            // from base            purecall
        vfunc f10_GetFarZScalability;            // from base            purecall
        vfunc f11_SetBackgroundColor;            // from base            purecall
        vfunc f12_GetBackgroundColor;            // from base            purecall
        vfunc f13_GetBackgroundColorDef;         // from base            purecall
        vfunc f14_SetOverrideColor;              // from base            purecall
        vfunc f15_SetOverrideColorFlag;          // from base            purecall
        vfunc f16_GetCloudShadowScale;           // from zCSkyControler  ?GetCloudShadowScale@zCSkyControler@@UBEMXZ
        vfunc f17_SetCloudShadowScale;           // from zCSkyControler  ?SetCloudShadowScale@zCSkyControler@@UAEXM@Z
        vfunc f18_SetFillBackground;             // from zCSkyControler  ?SetFillBackground@zCSkyControler@@UAEXH@Z
        vfunc f19_GetFillBackground;             // from zCSkyControler  ?GetFillBackground@zCSkyControler@@UBEHXZ
        vfunc f20_SetUnderwaterFX;               // from base            purecall
        vfunc f21_GetUnderwaterFX;               // from base            purecall
        vfunc f22_UpdateWorldDependencies;       // from base            purecall
        vfunc f23_SetLightDirty;                 // from zCSkyControler  ?SetLightDirty@zCSkyControler@@UAEXXZ
        vfunc f24_SetRelightTime;                // from zCSkyControler  ?SetRelightTime@zCSkyControler@@UAEXM@Z
        vfunc f25_GetRelightCtr;                 // from zCSkyControler  ?GetRelightCtr@zCSkyControler@@UAEHXZ
        vfunc f26_GetDaylightColorFromIntensity; // from zCSkyControler  ?GetDaylightColorFromIntensity@zCSkyControler@@UAE?AUzCOLOR@@H@Z
        vfunc f27_RenderSkyPre;                  // from base            purecall
        vfunc f28_RenderSkyPost;                 // from base            purecall
        vfunc f29_GetGlobalWindVec;              // from zCSkyControler  ?GetGlobalWindVec@zCSkyControler@@UAEHAAVzVEC3@@W4zTAnimationMode@@@Z
        vfunc f30_SetGlobalSkyScale;             // from zCSkyControler  ?SetGlobalSkyScale@zCSkyControler@@UAEXM@Z
        vfunc f31_GetGlobalSkyScale;             // from zCSkyControler  ?GetGlobalSkyScale@zCSkyControler@@UBEMXZ
        vfunc f32_GetGlobalSkyScaleChanged;      // from zCSkyControler  ?GetGlobalSkyScaleChanged@zCSkyControler@@UBEHXZ
        vfunc f33_SetCameraLocationHint;         // from zCSkyControler  ?SetCameraLocationHint@zCSkyControler@@UAEXW4zTCamLocationHint@1@@Z
        vfunc f34_SetWeatherType;                // from zCSkyControler  ?SetWeatherType@zCSkyControler@@UAEXW4zTWeather@@@Z
        vfunc f35_GetWeatherType;                // from zCSkyControler  ?GetWeatherType@zCSkyControler@@UBE?AW4zTWeather@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832DEC;
    }

    static uint GetFuncsNum() {
      return 36;
    }

    static vftable_zCSkyControler& GetTable() {
      MemUnlock;
      return *(vftable_zCSkyControler*)GetAddress();
    }
  };


  struct vftable_zCUnderwaterPFX {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCParticleFX     ?_GetClassDef@zCParticleFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_Render;                  // from zCUnderwaterPFX  ?Render@zCUnderwaterPFX@@UAEHAAUzTRenderContext@@@Z
        vfunc f05_IsBBox3DLocal;           // from zCParticleFX     ?IsBBox3DLocal@zCParticleFX@@UAEHXZ
        vfunc f06_GetBBox3D;               // from zCParticleFX     ?GetBBox3D@zCParticleFX@@UAE?AUzTBBox3D@@XZ
        vfunc f07_GetOBBox3D;              // from zCVisual         ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from zCParticleFX     ?GetVisualName@zCParticleFX@@UAE?AVzSTRING@@XZ
        vfunc f09_GetVisualDied;           // from zCParticleFX     ?GetVisualDied@zCParticleFX@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCParticleFX     ?SetVisualUsedBy@zCParticleFX@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual         ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCParticleFX     ?GetRenderSortKey@zCParticleFX@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual         ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual         ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCParticleFX     ?HostVobRemovedFromWorld@zCParticleFX@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCParticleFX     ?HostVobAddedToWorld@zCParticleFX@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCParticleFX     ?GetFileExtension@zCParticleFX@@MAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual         ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual         ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual         ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCParticleFX     ?LoadVisualVirtual@zCParticleFX@@MBEPAVzCVisual@@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00832E84;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCUnderwaterPFX& GetTable() {
      MemUnlock;
      return *(vftable_zCUnderwaterPFX*)GetAddress();
    }
  };


  struct vftable_zCSkyControler_Outdoor {
    union {
      vfunc array[37];
      group {
        vfunc f00_GetClassDef;                   // from zCSkyControler_Outdoor  ?_GetClassDef@zCSkyControler_Outdoor@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                       // from zCSkyControler_Outdoor  ?Archive@zCSkyControler_Outdoor@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                     // from zCSkyControler_Outdoor  ?Unarchive@zCSkyControler_Outdoor@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;             // from base                    
        vfunc f04_SetTime;                       // from zCSkyControler_Outdoor  ?SetTime@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f05_GetTime;                       // from zCSkyControler_Outdoor  ?GetTime@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f06_ResetTime;                     // from zCSkyControler_Outdoor  ?ResetTime@zCSkyControler_Outdoor@@UAEXXZ
        vfunc f07_SetFarZ;                       // from zCSkyControler_Outdoor  ?SetFarZ@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f08_GetFarZ;                       // from zCSkyControler_Outdoor  ?GetFarZ@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f09_SetFarZScalability;            // from zCSkyControler_Outdoor  ?SetFarZScalability@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f10_GetFarZScalability;            // from zCSkyControler_Outdoor  ?GetFarZScalability@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f11_SetBackgroundColor;            // from zCSkyControler_Outdoor  ?SetBackgroundColor@zCSkyControler_Outdoor@@UAEXUzCOLOR@@@Z
        vfunc f12_GetBackgroundColor;            // from zCSkyControler_Outdoor  ?GetBackgroundColor@zCSkyControler_Outdoor@@UBE?AUzCOLOR@@XZ
        vfunc f13_GetBackgroundColorDef;         // from zCSkyControler_Outdoor  ?GetBackgroundColorDef@zCSkyControler_Outdoor@@UBE?AUzCOLOR@@XZ
        vfunc f14_SetOverrideColor;              // from zCSkyControler_Outdoor  ?SetOverrideColor@zCSkyControler_Outdoor@@UAEXVzVEC3@@@Z
        vfunc f15_SetOverrideColorFlag;          // from zCSkyControler_Outdoor  ?SetOverrideColorFlag@zCSkyControler_Outdoor@@UAEXH@Z
        vfunc f16_GetCloudShadowScale;           // from zCSkyControler_Outdoor  ?GetCloudShadowScale@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f17_SetCloudShadowScale;           // from zCSkyControler_Outdoor  ?SetCloudShadowScale@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f18_SetFillBackground;             // from zCSkyControler          ?SetFillBackground@zCSkyControler@@UAEXH@Z
        vfunc f19_GetFillBackground;             // from zCSkyControler          ?GetFillBackground@zCSkyControler@@UBEHXZ
        vfunc f20_SetUnderwaterFX;               // from zCSkyControler_Mid      ?SetUnderwaterFX@zCSkyControler_Mid@@UAEXH@Z
        vfunc f21_GetUnderwaterFX;               // from zCSkyControler_Mid      ?GetUnderwaterFX@zCSkyControler_Mid@@UBEHXZ
        vfunc f22_UpdateWorldDependencies;       // from zCSkyControler_Outdoor  ?UpdateWorldDependencies@zCSkyControler_Outdoor@@UAEXXZ
        vfunc f23_SetLightDirty;                 // from zCSkyControler          ?SetLightDirty@zCSkyControler@@UAEXXZ
        vfunc f24_SetRelightTime;                // from zCSkyControler          ?SetRelightTime@zCSkyControler@@UAEXM@Z
        vfunc f25_GetRelightCtr;                 // from zCSkyControler          ?GetRelightCtr@zCSkyControler@@UAEHXZ
        vfunc f26_GetDaylightColorFromIntensity; // from zCSkyControler_Outdoor  ?GetDaylightColorFromIntensity@zCSkyControler_Outdoor@@UAE?AUzCOLOR@@H@Z
        vfunc f27_RenderSkyPre;                  // from zCSkyControler_Outdoor  ?RenderSkyPre@zCSkyControler_Outdoor@@UAEXXZ
        vfunc f28_RenderSkyPost;                 // from zCSkyControler_Outdoor  ?RenderSkyPost@zCSkyControler_Outdoor@@UAEXH@Z
        vfunc f29_GetGlobalWindVec;              // from zCSkyControler_Outdoor  ?GetGlobalWindVec@zCSkyControler_Outdoor@@UAEHAAVzVEC3@@W4zTAnimationMode@@@Z
        vfunc f30_SetGlobalSkyScale;             // from zCSkyControler_Outdoor  ?SetGlobalSkyScale@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f31_GetGlobalSkyScale;             // from zCSkyControler_Outdoor  ?GetGlobalSkyScale@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f32_GetGlobalSkyScaleChanged;      // from zCSkyControler_Outdoor  ?GetGlobalSkyScaleChanged@zCSkyControler_Outdoor@@UBEHXZ
        vfunc f33_SetCameraLocationHint;         // from zCSkyControler_Outdoor  ?SetCameraLocationHint@zCSkyControler_Outdoor@@UAEXW4zTCamLocationHint@zCSkyControler@@@Z
        vfunc f34_SetWeatherType;                // from zCSkyControler_Outdoor  ?SetWeatherType@zCSkyControler_Outdoor@@UAEXW4zTWeather@@@Z
        vfunc f35_GetWeatherType;                // from zCSkyControler          ?GetWeatherType@zCSkyControler@@UBE?AW4zTWeather@@XZ
        vfunc f36_GetRenderLightning;            // from zCSkyControler_Outdoor  ?GetRenderLightning@zCSkyControler_Outdoor@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00832F54;
    }

    static uint GetFuncsNum() {
      return 37;
    }

    static vftable_zCSkyControler_Outdoor& GetTable() {
      MemUnlock;
      return *(vftable_zCSkyControler_Outdoor*)GetAddress();
    }
  };


  struct vftable_zCSparseArrayBase {
    union {
      vfunc array[13];
      group {
        vfunc f00_scalar_destructor; // from base               
        vfunc f01_SizeIndex;         // from base               purecall
        vfunc f02_SizeData;          // from base               purecall
        vfunc f03_SizeAll;           // from zCSparseArrayBase  ?SizeAll@zCSparseArrayBase@@MBEKXZ
        vfunc f04_IndexPtr;          // from zCSparseArrayBase  ?IndexPtr@zCSparseArrayBase@@MBEPAXK@Z
        vfunc f05_DataPtr;           // from zCSparseArrayBase  ?DataPtr@zCSparseArrayBase@@MBEPAXK@Z
        vfunc f06_ManDatPtr;         // from zCSparseArrayBase  ?ManDatPtr@zCSparseArrayBase@@MBEPAVzCSparseArrayManDat@@K@Z
        vfunc f07_IndexIsEqual;      // from zCSparseArrayBase  ?IndexIsEqual@zCSparseArrayBase@@MBEHPBX0@Z
        vfunc f08_CopyIndex;         // from zCSparseArrayBase  ?CopyIndex@zCSparseArrayBase@@MBEXPAXPBX@Z
        vfunc f09_DestructIndex;     // from zCSparseArrayBase  ?DestructIndex@zCSparseArrayBase@@MBEXPAX@Z
        vfunc f10_Hash;              // from zCSparseArrayBase  ?Hash@zCSparseArrayBase@@MBEXPBXAAK1@Z
        vfunc f11_ConstructData;     // from zCSparseArrayBase  ?ConstructData@zCSparseArrayBase@@MBEXPAX@Z
        vfunc f12_DestructData;      // from zCSparseArrayBase  ?DestructData@zCSparseArrayBase@@MBEXPAX@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00833024;
    }

    static uint GetFuncsNum() {
      return 13;
    }

    static vftable_zCSparseArrayBase& GetTable() {
      MemUnlock;
      return *(vftable_zCSparseArrayBase*)GetAddress();
    }
  };


  struct vftable_zCCacheBase {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base  
        vfunc f01_PurgeCache;        // from base  purecall
        vfunc f02_ClearCache;        // from base  purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0083305C;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCCacheBase& GetTable() {
      MemUnlock;
      return *(vftable_zCCacheBase*)GetAddress();
    }
  };


  struct vftable_zCTextureFileFormatTGA {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;       // from zCTextureFileFormatTGA  ?_GetClassDef@zCTextureFileFormatTGA@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject                ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject                ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base                    
        vfunc f04_LoadTexture;       // from zCTextureFileFormatTGA  ?LoadTexture@zCTextureFileFormatTGA@@UAEHAAVzFILE@@PAVzCTextureExchange@@@Z
        vfunc f05_LoadTexture;       // from zCTextureFileFormatTGA  ?LoadTexture@zCTextureFileFormatTGA@@UAEHABVzSTRING@@PAVzCTextureExchange@@@Z
        vfunc f06_SaveTexture;       // from zCTextureFileFormatTGA  ?SaveTexture@zCTextureFileFormatTGA@@UAEHAAVzFILE@@PAVzCTextureExchange@@@Z
        vfunc f07_SaveTexture;       // from zCTextureFileFormatTGA  ?SaveTexture@zCTextureFileFormatTGA@@UAEHABVzSTRING@@PAVzCTextureExchange@@@Z
        vfunc f08_GetFileExtension;  // from zCTextureFileFormatTGA  ?GetFileExtension@zCTextureFileFormatTGA@@UBEABVzSTRING@@XZ
        vfunc f09_CanSave;           // from zCTextureFileFormatTGA  ?CanSave@zCTextureFileFormatTGA@@UBEHXZ
        vfunc f10_CanLoad;           // from zCTextureFileFormatTGA  ?CanLoad@zCTextureFileFormatTGA@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00833078;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTextureFileFormatTGA& GetTable() {
      MemUnlock;
      return *(vftable_zCTextureFileFormatTGA*)GetAddress();
    }
  };


  struct vftable_zCTextureFileFormatInternal {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;       // from zCTextureFileFormatInternal  ?_GetClassDef@zCTextureFileFormatInternal@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject                     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject                     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_vector_destructor; // from base                         
        vfunc f04_LoadTexture;       // from zCTextureFileFormatInternal  ?LoadTexture@zCTextureFileFormatInternal@@UAEHAAVzFILE@@PAVzCTextureExchange@@@Z
        vfunc f05_LoadTexture;       // from zCTextureFileFormatInternal  ?LoadTexture@zCTextureFileFormatInternal@@UAEHABVzSTRING@@PAVzCTextureExchange@@@Z
        vfunc f06_SaveTexture;       // from zCTextureFileFormatInternal  ?SaveTexture@zCTextureFileFormatInternal@@UAEHAAVzFILE@@PAVzCTextureExchange@@@Z
        vfunc f07_SaveTexture;       // from zCTextureFileFormatInternal  ?SaveTexture@zCTextureFileFormatInternal@@UAEHABVzSTRING@@PAVzCTextureExchange@@@Z
        vfunc f08_GetFileExtension;  // from zCTextureFileFormatInternal  ?GetFileExtension@zCTextureFileFormatInternal@@UBEABVzSTRING@@XZ
        vfunc f09_CanSave;           // from zCTextureFileFormatInternal  ?CanSave@zCTextureFileFormatInternal@@UBEHXZ
        vfunc f10_CanLoad;           // from zCTextureFileFormatInternal  ?CanLoad@zCTextureFileFormatInternal@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008330A8;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTextureFileFormatInternal& GetTable() {
      MemUnlock;
      return *(vftable_zCTextureFileFormatInternal*)GetAddress();
    }
  };


  struct vftable_zCTextureFileFormat {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;       // from zCTextureFileFormat  ?_GetClassDef@zCTextureFileFormat@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject             ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject             ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base                 
        vfunc f04_LoadTexture;       // from base                 purecall
        vfunc f05_LoadTexture;       // from base                 purecall
        vfunc f06_SaveTexture;       // from base                 purecall
        vfunc f07_SaveTexture;       // from base                 purecall
        vfunc f08_GetFileExtension;  // from base                 purecall
        vfunc f09_CanSave;           // from base                 purecall
        vfunc f10_CanLoad;           // from base                 purecall
      } names;
    };

    static uint GetAddress() {
      return 0x008330D8;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTextureFileFormat& GetTable() {
      MemUnlock;
      return *(vftable_zCTextureFileFormat*)GetAddress();
    }
  };


  struct vftable_zCTexture_for_zCTextureExchange {
    union {
      vfunc array[11];
      group {
        vfunc f00_vector_destructor; // from base               
        vfunc f01_Lock;              // from base               purecall
        vfunc f02_Unlock;            // from base               purecall
        vfunc f03_SetTextureInfo;    // from base               purecall
        vfunc f04_GetPaletteBuffer;  // from base               purecall
        vfunc f05_GetTextureBuffer;  // from base               purecall
        vfunc f06_GetTextureInfo;    // from base               purecall
        vfunc f07_CopyPaletteDataTo; // from base               purecall
        vfunc f08_CopyTextureDataTo; // from base               purecall
        vfunc f09_HasAlpha;          // from zCTexture          ?HasAlpha@zCTexture@@UAEHXZ
        vfunc f10_GetRGBAAtTexel;    // from zCTextureExchange  ?GetRGBAAtTexel@zCTextureExchange@@UAE?AVzVEC4@@MM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083311C;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTexture_for_zCTextureExchange& GetTable() {
      MemUnlock;
      return *(vftable_zCTexture_for_zCTextureExchange*)GetAddress();
    }
  };


  struct vftable_zCTexture_for_zCResource {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;            // from zCTexture  ?_GetClassDef@zCTexture@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                // from zCObject   ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;              // from zCObject   ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;      // from base       
        vfunc f04_LoadResourceData;       // from zCTexture  ?LoadResourceData@zCTexture@@UAEHXZ
        vfunc f05_ReleaseResourceData;    // from zCTexture  ?ReleaseResourceData@zCTexture@@UAEHXZ
        vfunc f06_GetResSizeBytes;        // from zCTexture  ?GetResSizeBytes@zCTexture@@UAEKXZ
        vfunc f07_GetCacheConfig;         // from zCTexture  ?GetCacheConfig@zCTexture@@UAEXAAK0@Z
        vfunc f08_GetChromaKeyingEnabled; // from zCTexture  ?GetChromaKeyingEnabled@zCTexture@@UBEHXZ
        vfunc f09_SetChromaKeyingEnabled; // from zCTexture  ?SetChromaKeyingEnabled@zCTexture@@UAEXH@Z
        vfunc f10_ReleaseData;            // from base       purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0083314C;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTexture_for_zCResource& GetTable() {
      MemUnlock;
      return *(vftable_zCTexture_for_zCResource*)GetAddress();
    }
  };


  struct vftable_zCTextureExchange {
    union {
      vfunc array[11];
      group {
        vfunc f00_scalar_destructor; // from base               
        vfunc f01_Lock;              // from base               purecall
        vfunc f02_Unlock;            // from base               purecall
        vfunc f03_SetTextureInfo;    // from base               purecall
        vfunc f04_GetPaletteBuffer;  // from base               purecall
        vfunc f05_GetTextureBuffer;  // from base               purecall
        vfunc f06_GetTextureInfo;    // from base               purecall
        vfunc f07_CopyPaletteDataTo; // from base               purecall
        vfunc f08_CopyTextureDataTo; // from base               purecall
        vfunc f09_HasAlpha;          // from base               purecall
        vfunc f10_GetRGBAAtTexel;    // from zCTextureExchange  ?GetRGBAAtTexel@zCTextureExchange@@UAE?AVzVEC4@@MM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083317C;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTextureExchange& GetTable() {
      MemUnlock;
      return *(vftable_zCTextureExchange*)GetAddress();
    }
  };


  struct vftable_zCLightMap {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCLightMap  ?_GetClassDef@zCLightMap@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base        
      } names;
    };

    static uint GetAddress() {
      return 0x008331B4;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCLightMap& GetTable() {
      MemUnlock;
      return *(vftable_zCLightMap*)GetAddress();
    }
  };


  struct vftable_zCThread {
    union {
      vfunc array[5];
      group {
        vfunc f00_scalar_destructor; // from base      
        vfunc f01_BeginThread;       // from zCThread  ?BeginThread@zCThread@@UAEXXZ
        vfunc f02_EndThread;         // from zCThread  ?EndThread@zCThread@@UAEXXZ
        vfunc f03_IsThreadRunning;   // from zCThread  ?IsThreadRunning@zCThread@@UAEHXZ
        vfunc f04_SuspendThread;     // from zCThread  ?SuspendThread@zCThread@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008331C8;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_zCThread& GetTable() {
      MemUnlock;
      return *(vftable_zCThread*)GetAddress();
    }
  };


  struct vftable_zCCriticalSection {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base               
        vfunc f01_Lock;              // from zCCriticalSection  ?Lock@zCCriticalSection@@UAEHK@Z
        vfunc f02_Unlock;            // from zCCriticalSection  ?Unlock@zCCriticalSection@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x008331F0;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCCriticalSection& GetTable() {
      MemUnlock;
      return *(vftable_zCCriticalSection*)GetAddress();
    }
  };


  struct vftable_zCSyncObject {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base  
        vfunc f01_Lock;              // from base  purecall
        vfunc f02_Unlock;            // from base  purecall
      } names;
    };

    static uint GetAddress() {
      return 0x00833200;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCSyncObject& GetTable() {
      MemUnlock;
      return *(vftable_zCSyncObject*)GetAddress();
    }
  };


  struct vftable_zCMutex {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base     
        vfunc f01_Lock;              // from zCMutex  ?Lock@zCMutex@@UAEHK@Z
        vfunc f02_Unlock;            // from zCMutex  ?Unlock@zCMutex@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x00833210;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zCMutex& GetTable() {
      MemUnlock;
      return *(vftable_zCMutex*)GetAddress();
    }
  };


  struct vftable_zCVertexBuffer {
    union {
      vfunc array[18];
      group {
        vfunc f00_GetClassDef;       // from zCVertexBuffer  ?_GetClassDef@zCVertexBuffer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject        ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject        ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base            
        vfunc f04_Create;            // from zCVertexBuffer  ?Create@zCVertexBuffer@@UAEHKKK@Z
        vfunc f05_Destroy;           // from zCVertexBuffer  ?Destroy@zCVertexBuffer@@UAEHXZ
        vfunc f06_Lock;              // from zCVertexBuffer  ?Lock@zCVertexBuffer@@UAEHK@Z
        vfunc f07_Unlock;            // from zCVertexBuffer  ?Unlock@zCVertexBuffer@@UAEHXZ
        vfunc f08_IsLocked;          // from zCVertexBuffer  ?IsLocked@zCVertexBuffer@@UAEHXZ
        vfunc f09_Optimize;          // from zCVertexBuffer  ?Optimize@zCVertexBuffer@@UAEHXZ
        vfunc f10_SetPrimitiveType;  // from zCVertexBuffer  ?SetPrimitiveType@zCVertexBuffer@@UAEHW4zTVBufferPrimitiveType@@@Z
        vfunc f11_GetPrimitiveType;  // from zCVertexBuffer  ?GetPrimitiveType@zCVertexBuffer@@UAE?AW4zTVBufferPrimitiveType@@XZ
        vfunc f12_GetVertexFormat;   // from zCVertexBuffer  ?GetVertexFormat@zCVertexBuffer@@UAEKXZ
        vfunc f13_GetVertexType;     // from zCVertexBuffer  ?GetVertexType@zCVertexBuffer@@UAE?AW4zTVBufferVertexType@@XZ
        vfunc f14_SetIndexList;      // from zCVertexBuffer  ?SetIndexList@zCVertexBuffer@@UAEHABV?$zCArray@G@@@Z
        vfunc f15_SetIndexListSize;  // from zCVertexBuffer  ?SetIndexListSize@zCVertexBuffer@@UAEHK@Z
        vfunc f16_GetIndexListSize;  // from zCVertexBuffer  ?GetIndexListSize@zCVertexBuffer@@UAEKXZ
        vfunc f17_GetIndexListPtr;   // from zCVertexBuffer  ?GetIndexListPtr@zCVertexBuffer@@UAEPAGXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083988C;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_zCVertexBuffer& GetTable() {
      MemUnlock;
      return *(vftable_zCVertexBuffer*)GetAddress();
    }
  };


  struct vftable_zCVobLightPreset {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCVobLightPreset  ?_GetClassDef@zCVobLightPreset@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCVobLightPreset  ?Archive@zCVobLightPreset@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCVobLightPreset  ?Unarchive@zCVobLightPreset@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base              
      } names;
    };

    static uint GetAddress() {
      return 0x008398EC;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCVobLightPreset& GetTable() {
      MemUnlock;
      return *(vftable_zCVobLightPreset*)GetAddress();
    }
  };


  struct vftable_zCVobLevelCompo {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobLevelCompo  ?_GetClassDef@zCVobLevelCompo@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobLevelCompo  ?Archive@zCVobLevelCompo@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobLevelCompo  ?Unarchive@zCVobLevelCompo@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_OnTrigger;               // from zCVob            ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob            ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob            ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob            ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob            ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob            ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob            ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob            ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob            ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob            ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob            ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob            ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob            ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob            ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob            ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVobLevelCompo  ?SetVisual@zCVobLevelCompo@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVobLevelCompo  ?SetVisual@zCVobLevelCompo@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob            ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob            ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob            ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob            ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob            ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob            ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob            ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839904;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobLevelCompo& GetTable() {
      MemUnlock;
      return *(vftable_zCVobLevelCompo*)GetAddress();
    }
  };


  struct vftable_zCVob {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVob  ?_GetClassDef@zCVob@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob  ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob  ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base   
        vfunc f04_OnTrigger;               // from zCVob  ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob  ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob  ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob  ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob  ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob  ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob  ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob  ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob  ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob  ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob  ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob  ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob  ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob  ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob  ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob  ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob  ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob  ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob  ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob  ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob  ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob  ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob  ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob  ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083997C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVob& GetTable() {
      MemUnlock;
      return *(vftable_zCVob*)GetAddress();
    }
  };


  struct vftable_zCVisual {
    union {
      vfunc array[22];
      group {
        vfunc f00_GetClassDef;             // from zCVisual  ?_GetClassDef@zCVisual@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base      
        vfunc f04_Render;                  // from base      purecall
        vfunc f05_IsBBox3DLocal;           // from zCVisual  ?IsBBox3DLocal@zCVisual@@UAEHXZ
        vfunc f06_GetBBox3D;               // from base      purecall
        vfunc f07_GetOBBox3D;              // from zCVisual  ?GetOBBox3D@zCVisual@@UAEPAVzCOBBox3D@@XZ
        vfunc f08_GetVisualName;           // from base      purecall
        vfunc f09_GetVisualDied;           // from zCVisual  ?GetVisualDied@zCVisual@@UAEHXZ
        vfunc f10_SetVisualUsedBy;         // from zCVisual  ?SetVisualUsedBy@zCVisual@@UAEXPAVzCVob@@@Z
        vfunc f11_DynLightVisual;          // from zCVisual  ?DynLightVisual@zCVisual@@UAEXABV?$zCArray@PAVzCVobLight@@@@PAVzMAT4@@@Z
        vfunc f12_GetRenderSortKey;        // from zCVisual  ?GetRenderSortKey@zCVisual@@UBEKXZ
        vfunc f13_CanTraceRay;             // from zCVisual  ?CanTraceRay@zCVisual@@UBEHXZ
        vfunc f14_TraceRay;                // from zCVisual  ?TraceRay@zCVisual@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f15_HostVobRemovedFromWorld; // from zCVisual  ?HostVobRemovedFromWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f16_HostVobAddedToWorld;     // from zCVisual  ?HostVobAddedToWorld@zCVisual@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f17_GetFileExtension;        // from zCVisual  ?GetFileExtension@zCVisual@@UAEPBVzSTRING@@H@Z
        vfunc f18_GetLODVisualAndAlpha;    // from zCVisual  ?GetLODVisualAndAlpha@zCVisual@@UAEXMAAPAV1@AAM@Z
        vfunc f19_GetAlphaTestingEnabled;  // from zCVisual  ?GetAlphaTestingEnabled@zCVisual@@UBEHXZ
        vfunc f20_SetAlphaTestingEnabled;  // from zCVisual  ?SetAlphaTestingEnabled@zCVisual@@UAEXH@Z
        vfunc f21_LoadVisualVirtual;       // from zCVisual  ?LoadVisualVirtual@zCVisual@@MBEPAV1@ABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839A04;
    }

    static uint GetFuncsNum() {
      return 22;
    }

    static vftable_zCVisual& GetTable() {
      MemUnlock;
      return *(vftable_zCVisual*)GetAddress();
    }
  };


  struct vftable_zCVobLight {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobLight  ?_GetClassDef@zCVobLight@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobLight  ?Archive@zCVobLight@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobLight  ?Unarchive@zCVobLight@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_OnTrigger;               // from zCVobLight  ?OnTrigger@zCVobLight@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVobLight  ?OnUntrigger@zCVobLight@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob       ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob       ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVobLight  ?EndMovement@zCVobLight@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob       ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVobLight  ?ThisVobAddedToWorld@zCVobLight@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839A74;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobLight& GetTable() {
      MemUnlock;
      return *(vftable_zCVobLight*)GetAddress();
    }
  };


  struct vftable_zCVobStair {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobStair  ?_GetClassDef@zCVobStair@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob       ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob       ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_OnTrigger;               // from zCVob       ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob       ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob       ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob       ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob       ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob       ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839B4C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobStair& GetTable() {
      MemUnlock;
      return *(vftable_zCVobStair*)GetAddress();
    }
  };


  struct vftable_zCTriggerUntouch {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCTriggerUntouch  ?_GetClassDef@zCTriggerUntouch@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTriggerBase     ?Archive@zCTriggerBase@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTriggerBase     ?Unarchive@zCTriggerBase@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base              
        vfunc f04_OnTrigger;               // from zCTriggerUntouch  ?OnTrigger@zCTriggerUntouch@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTriggerUntouch  ?OnUntrigger@zCTriggerUntouch@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTriggerUntouch  ?OnTouch@zCTriggerUntouch@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTriggerUntouch  ?OnUntouch@zCTriggerUntouch@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob             ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob             ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob             ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob             ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob             ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob             ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob             ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob             ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob             ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob             ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob             ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob             ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob             ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob             ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob             ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase     ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob             ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob             ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839BC4;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCTriggerUntouch& GetTable() {
      MemUnlock;
      return *(vftable_zCTriggerUntouch*)GetAddress();
    }
  };


  struct vftable_zCTriggerBase {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCTriggerBase  ?_GetClassDef@zCTriggerBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTriggerBase  ?Archive@zCTriggerBase@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTriggerBase  ?Unarchive@zCTriggerBase@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCTriggerBase  ?OnTrigger@zCTriggerBase@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTriggerBase  ?OnUntrigger@zCTriggerBase@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTriggerBase  ?OnTouch@zCTriggerBase@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTriggerBase  ?OnUntouch@zCTriggerBase@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob          ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob          ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase  ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839C3C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCTriggerBase& GetTable() {
      MemUnlock;
      return *(vftable_zCTriggerBase*)GetAddress();
    }
  };


  struct vftable_zCMessageFilter {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCMessageFilter  ?_GetClassDef@zCMessageFilter@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCMessageFilter  ?Archive@zCMessageFilter@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCMessageFilter  ?Unarchive@zCMessageFilter@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_OnTrigger;               // from zCMessageFilter  ?OnTrigger@zCMessageFilter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCMessageFilter  ?OnUntrigger@zCMessageFilter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCMessageFilter  ?OnTouch@zCMessageFilter@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCMessageFilter  ?OnUntouch@zCMessageFilter@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob            ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob            ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob            ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob            ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob            ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob            ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob            ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob            ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob            ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob            ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob            ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob            ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob            ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob            ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob            ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase    ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob            ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob            ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839CB4;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCMessageFilter& GetTable() {
      MemUnlock;
      return *(vftable_zCMessageFilter*)GetAddress();
    }
  };


  struct vftable_zCCodeMaster {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCCodeMaster  ?_GetClassDef@zCCodeMaster@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCCodeMaster  ?Archive@zCCodeMaster@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCCodeMaster  ?Unarchive@zCCodeMaster@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_OnTrigger;               // from zCCodeMaster  ?OnTrigger@zCCodeMaster@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCCodeMaster  ?OnUntrigger@zCCodeMaster@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCCodeMaster  ?OnTouch@zCCodeMaster@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCCodeMaster  ?OnUntouch@zCCodeMaster@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob         ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob         ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCCodeMaster  ?OnMessage@zCCodeMaster@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob         ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob         ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob         ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob         ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob         ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob         ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob         ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob         ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob         ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob         ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob         ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob         ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob         ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob         ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCCodeMaster  ?GetTriggerTarget@zCCodeMaster@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob         ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob         ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839D2C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCCodeMaster& GetTable() {
      MemUnlock;
      return *(vftable_zCCodeMaster*)GetAddress();
    }
  };


  struct vftable_zCMoverControler {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCMoverControler  ?_GetClassDef@zCMoverControler@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCMoverControler  ?Archive@zCMoverControler@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCMoverControler  ?Unarchive@zCMoverControler@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base              
        vfunc f04_OnTrigger;               // from zCMoverControler  ?OnTrigger@zCMoverControler@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCMoverControler  ?OnUntrigger@zCMoverControler@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCMoverControler  ?OnTouch@zCMoverControler@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCMoverControler  ?OnUntouch@zCMoverControler@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob             ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob             ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob             ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob             ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob             ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob             ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob             ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob             ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob             ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob             ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob             ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob             ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob             ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob             ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob             ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase     ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob             ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob             ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839DA4;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCMoverControler& GetTable() {
      MemUnlock;
      return *(vftable_zCMoverControler*)GetAddress();
    }
  };


  struct vftable_zCTriggerWorldStart {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCTriggerWorldStart  ?_GetClassDef@zCTriggerWorldStart@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTriggerWorldStart  ?Archive@zCTriggerWorldStart@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTriggerWorldStart  ?Unarchive@zCTriggerWorldStart@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                 
        vfunc f04_OnTrigger;               // from zCTriggerWorldStart  ?OnTrigger@zCTriggerWorldStart@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTriggerWorldStart  ?OnUntrigger@zCTriggerWorldStart@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTriggerWorldStart  ?OnTouch@zCTriggerWorldStart@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTriggerWorldStart  ?OnUntouch@zCTriggerWorldStart@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob                ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob                ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob                ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob                ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCTriggerWorldStart  ?PostLoad@zCTriggerWorldStart@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob                ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob                ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob                ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase        ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob                ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob                ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839E1C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCTriggerWorldStart& GetTable() {
      MemUnlock;
      return *(vftable_zCTriggerWorldStart*)GetAddress();
    }
  };


  struct vftable_zCTriggerList {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from zCTriggerList  ?_GetClassDef@zCTriggerList@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTriggerList  ?Archive@zCTriggerList@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTriggerList  ?Unarchive@zCTriggerList@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCTrigger      ?OnTrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTrigger      ?OnUntrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTrigger      ?OnTouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger      ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger      ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger      ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTriggerList  ?OnTimer@zCTriggerList@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerList  ?GetTriggerTarget@zCTriggerList@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from zCTriggerList  ?TriggerTarget@zCTriggerList@@MAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from zCTriggerList  ?UntriggerTarget@zCTriggerList@@MAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger      ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839E94;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_zCTriggerList& GetTable() {
      MemUnlock;
      return *(vftable_zCTriggerList*)GetAddress();
    }
  };


  struct vftable_zCTriggerTeleport {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from zCTriggerTeleport  ?_GetClassDef@zCTriggerTeleport@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTriggerTeleport  ?Archive@zCTriggerTeleport@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTriggerTeleport  ?Unarchive@zCTriggerTeleport@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from zCTriggerTeleport  ?OnTrigger@zCTriggerTeleport@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTriggerTeleport  ?OnUntrigger@zCTriggerTeleport@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTriggerTeleport  ?OnTouch@zCTriggerTeleport@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger          ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger          ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger          ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger          ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob              ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob              ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase      ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob              ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob              ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from zCTrigger          ?TriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from zCTrigger          ?UntriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger          ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839F14;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_zCTriggerTeleport& GetTable() {
      MemUnlock;
      return *(vftable_zCTriggerTeleport*)GetAddress();
    }
  };


  struct vftable_zCEarthquake {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCEarthquake  ?_GetClassDef@zCEarthquake@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCEarthquake  ?Archive@zCEarthquake@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCEarthquake  ?Unarchive@zCEarthquake@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_OnTrigger;               // from zCEarthquake  ?OnTrigger@zCEarthquake@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCEarthquake  ?OnUntrigger@zCEarthquake@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob         ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob         ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob         ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob         ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob         ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob         ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob         ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob         ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob         ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob         ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob         ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob         ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob         ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob         ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob         ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob         ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob         ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob         ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob         ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob         ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob         ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob         ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00839F94;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCEarthquake& GetTable() {
      MemUnlock;
      return *(vftable_zCEarthquake*)GetAddress();
    }
  };


  struct vftable_zCPFXControler {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCPFXControler  ?_GetClassDef@zCPFXControler@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCPFXControler  ?Archive@zCPFXControler@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCPFXControler  ?Unarchive@zCPFXControler@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base            
        vfunc f04_OnTrigger;               // from zCPFXControler  ?OnTrigger@zCPFXControler@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCPFXControler  ?OnUntrigger@zCPFXControler@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob           ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob           ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob           ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob           ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob           ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob           ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob           ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCPFXControler  ?PostLoad@zCPFXControler@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob           ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob           ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob           ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob           ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob           ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob           ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob           ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob           ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob           ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob           ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob           ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob           ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob           ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob           ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A00C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCPFXControler& GetTable() {
      MemUnlock;
      return *(vftable_zCPFXControler*)GetAddress();
    }
  };


  struct vftable_zCTouchDamage {
    union {
      vfunc array[29];
      group {
        vfunc f00_GetClassDef;             // from zCTouchDamage  ?_GetClassDef@zCTouchDamage@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTouchDamage  ?Archive@zCTouchDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTouchDamage  ?Unarchive@zCTouchDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCVob          ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob          ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCTouchDamage  ?OnTouch@zCTouchDamage@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTouchDamage  ?OnUntouch@zCTouchDamage@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob          ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob          ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTouchDamage  ?OnTimer@zCTouchDamage@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCTouchDamage  ?SetVisual@zCTouchDamage@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob          ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_GetDamageTypeArcEnum;    // from zCTouchDamage  ?GetDamageTypeArcEnum@zCTouchDamage@@MAEPBDK@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A084;
    }

    static uint GetFuncsNum() {
      return 29;
    }

    static vftable_zCTouchDamage& GetTable() {
      MemUnlock;
      return *(vftable_zCTouchDamage*)GetAddress();
    }
  };


  struct vftable_zCTouchAnimate {
    union {
      vfunc array[29];
      group {
        vfunc f00_GetClassDef;             // from zCTouchAnimate  ?_GetClassDef@zCTouchAnimate@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTouchAnimate  ?Archive@zCTouchAnimate@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTouchAnimate  ?Unarchive@zCTouchAnimate@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base            
        vfunc f04_OnTrigger;               // from zCVob           ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob           ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCTouchAnimate  ?OnTouch@zCTouchAnimate@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTouchAnimate  ?OnUntouch@zCTouchAnimate@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob           ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob           ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob           ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCTouchAnimate  ?OnTick@zCTouchAnimate@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob           ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob           ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob           ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob           ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob           ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob           ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob           ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob           ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCTouchAnimate  ?SetVisual@zCTouchAnimate@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob           ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob           ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob           ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob           ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob           ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob           ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob           ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_GetSoundName;            // from zCTouchAnimate  ?GetSoundName@zCTouchAnimate@@MAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A0FC;
    }

    static uint GetFuncsNum() {
      return 29;
    }

    static vftable_zCTouchAnimate& GetTable() {
      MemUnlock;
      return *(vftable_zCTouchAnimate*)GetAddress();
    }
  };


  struct vftable_zCTouchAnimateSound {
    union {
      vfunc array[29];
      group {
        vfunc f00_GetClassDef;             // from zCTouchAnimateSound  ?_GetClassDef@zCTouchAnimateSound@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTouchAnimateSound  ?Archive@zCTouchAnimateSound@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTouchAnimateSound  ?Unarchive@zCTouchAnimateSound@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                 
        vfunc f04_OnTrigger;               // from zCVob                ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob                ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCTouchAnimate       ?OnTouch@zCTouchAnimate@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTouchAnimate       ?OnUntouch@zCTouchAnimate@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob                ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob                ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCTouchAnimate       ?OnTick@zCTouchAnimate@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob                ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob                ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob                ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob                ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCTouchAnimate       ?SetVisual@zCTouchAnimate@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob                ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob                ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob                ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_GetSoundName;            // from zCTouchAnimateSound  ?GetSoundName@zCTouchAnimateSound@@MAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A174;
    }

    static uint GetFuncsNum() {
      return 29;
    }

    static vftable_zCTouchAnimateSound& GetTable() {
      MemUnlock;
      return *(vftable_zCTouchAnimateSound*)GetAddress();
    }
  };


  struct vftable_zCVobAnimate {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobAnimate  ?_GetClassDef@zCVobAnimate@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobAnimate  ?Archive@zCVobAnimate@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobAnimate  ?Unarchive@zCVobAnimate@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_OnTrigger;               // from zCVobAnimate  ?OnTrigger@zCVobAnimate@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVobAnimate  ?OnUntrigger@zCVobAnimate@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob         ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob         ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob         ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob         ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob         ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob         ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob         ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob         ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob         ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob         ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob         ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob         ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob         ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob         ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVobAnimate  ?SetVisual@zCVobAnimate@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob         ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob         ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob         ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob         ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob         ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob         ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob         ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A1EC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobAnimate& GetTable() {
      MemUnlock;
      return *(vftable_zCVobAnimate*)GetAddress();
    }
  };


  struct vftable_zCVobLensFlare {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobLensFlare  ?_GetClassDef@zCVobLensFlare@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobLensFlare  ?Archive@zCVobLensFlare@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobLensFlare  ?Unarchive@zCVobLensFlare@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base            
        vfunc f04_OnTrigger;               // from zCVob           ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob           ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob           ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob           ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob           ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob           ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob           ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob           ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob           ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob           ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob           ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob           ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob           ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob           ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVobLensFlare  ?Render@zCVobLensFlare@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob           ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob           ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob           ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob           ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob           ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob           ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob           ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob           ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob           ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A264;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobLensFlare& GetTable() {
      MemUnlock;
      return *(vftable_zCVobLensFlare*)GetAddress();
    }
  };


  struct vftable_zCEventCommon {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventCommon   ?_GetClassDef@zCEventCommon@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMessage  ?Archive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMessage  ?Unarchive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from zCEventMessage  ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventCommon   ?IsNetRelevant@zCEventCommon@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage  ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage  ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage  ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage  ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage  ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage  ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventCommon   ?MD_GetNumOfSubTypes@zCEventCommon@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventCommon   ?MD_GetSubTypeString@zCEventCommon@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A2DC;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventCommon& GetTable() {
      MemUnlock;
      return *(vftable_zCEventCommon*)GetAddress();
    }
  };


  struct vftable_zCEventMover {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventMover    ?_GetClassDef@zCEventMover@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMessage  ?Archive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMessage  ?Unarchive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from zCEventMessage  ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMover    ?IsNetRelevant@zCEventMover@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage  ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage  ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage  ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage  ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage  ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage  ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventMover    ?MD_GetNumOfSubTypes@zCEventMover@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventMover    ?MD_GetSubTypeString@zCEventMover@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A33C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventMover& GetTable() {
      MemUnlock;
      return *(vftable_zCEventMover*)GetAddress();
    }
  };


  struct vftable_zCEventScreenFX {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventScreenFX  ?_GetClassDef@zCEventScreenFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventScreenFX  ?Archive@zCEventScreenFX@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventScreenFX  ?Unarchive@zCEventScreenFX@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base             
        vfunc f04_IsOverlay;             // from zCEventMessage   ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage   ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage   ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage   ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage   ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage   ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage   ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage   ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage   ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage   ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventScreenFX  ?MD_GetNumOfSubTypes@zCEventScreenFX@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventScreenFX  ?MD_GetSubTypeString@zCEventScreenFX@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage   ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage   ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage   ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventScreenFX  ?MD_GetTimeBehavior@zCEventScreenFX@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventScreenFX  ?MD_GetMinTime@zCEventScreenFX@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventScreenFX  ?Pack@zCEventScreenFX@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventScreenFX  ?Unpack@zCEventScreenFX@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A39C;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventScreenFX& GetTable() {
      MemUnlock;
      return *(vftable_zCEventScreenFX*)GetAddress();
    }
  };


  struct vftable_zCTrigger {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from zCTrigger      ?_GetClassDef@zCTrigger@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTrigger      ?Archive@zCTrigger@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTrigger      ?Unarchive@zCTrigger@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCTrigger      ?OnTrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCTrigger      ?OnUntrigger@zCTrigger@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCTrigger      ?OnTouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger      ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCTrigger      ?OnDamage@zCTrigger@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCTrigger      ?OnMessage@zCTrigger@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger      ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase  ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from zCTrigger      ?TriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from zCTrigger      ?UntriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger      ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A3FC;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_zCTrigger& GetTable() {
      MemUnlock;
      return *(vftable_zCTrigger*)GetAddress();
    }
  };


  struct vftable_zCMover {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;             // from zCMover        ?_GetClassDef@zCMover@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCMover        ?Archive@zCMover@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCMover        ?Unarchive@zCMover@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCMover        ?OnTrigger@zCMover@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCMover        ?OnUntrigger@zCMover@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCMover        ?OnTouch@zCMover@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTrigger      ?OnUntouch@zCTrigger@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCMover        ?OnDamage@zCMover@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCMover        ?OnMessage@zCMover@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCMover        ?OnTick@zCMover@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTrigger      ?OnTimer@zCTrigger@@UAEXXZ
        vfunc f13_PostLoad;                // from zCMover        ?PostLoad@zCMover@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCMover        ?CanThisCollideWith@zCMover@@UAEHPAVzCVob@@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCMover        ?SetVisual@zCMover@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCTriggerBase  ?GetTriggerTarget@zCTriggerBase@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_TriggerTarget;           // from zCTrigger      ?TriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f29_UntriggerTarget;         // from zCTrigger      ?UntriggerTarget@zCTrigger@@MAEXPAVzCVob@@@Z
        vfunc f30_CanBeActivatedNow;       // from zCTrigger      ?CanBeActivatedNow@zCTrigger@@MAEHPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A47C;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_zCMover& GetTable() {
      MemUnlock;
      return *(vftable_zCMover*)GetAddress();
    }
  };


  struct vftable_zCVobScreenFX {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobScreenFX  ?_GetClassDef@zCVobScreenFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobScreenFX  ?Archive@zCVobScreenFX@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobScreenFX  ?Unarchive@zCVobScreenFX@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCVob          ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob          ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob          ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob          ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob          ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVobScreenFX  ?OnMessage@zCVobScreenFX@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVobScreenFX  ?OnTick@zCVobScreenFX@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob          ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A4FC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobScreenFX& GetTable() {
      MemUnlock;
      return *(vftable_zCVobScreenFX*)GetAddress();
    }
  };


  struct vftable_zCWorld {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;              // from zCWorld  ?_GetClassDef@zCWorld@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from zCWorld  ?Archive@zCWorld@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from zCWorld  ?Unarchive@zCWorld@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base     
        vfunc f04_LoadWorld;                // from zCWorld  ?LoadWorld@zCWorld@@UAEHABVzSTRING@@W4zTWorldLoadMode@1@@Z
        vfunc f05_SaveWorld;                // from zCWorld  ?SaveWorld@zCWorld@@UAEHABVzSTRING@@W4zTWorldSaveMode@1@HH@Z
        vfunc f06_MergeVobSubtree;          // from zCWorld  ?MergeVobSubtree@zCWorld@@UAEPAVzCVob@@ABVzSTRING@@PAV2@W4zTWorldLoadMergeMode@1@@Z
        vfunc f07_SaveVobSubtree;           // from zCWorld  ?SaveVobSubtree@zCWorld@@UAEHABVzSTRING@@PAVzCVob@@HH@Z
        vfunc f08_DisposeWorld;             // from zCWorld  ?DisposeWorld@zCWorld@@UAEXXZ
        vfunc f09_DisposeVobs;              // from zCWorld  ?DisposeVobs@zCWorld@@UAEHPAV?$zCTree@VzCVob@@@@@Z
        vfunc f10_DisposeVobsDbg;           // from zCWorld  ?DisposeVobsDbg@zCWorld@@UAEHPAV?$zCTree@VzCVob@@@@@Z
        vfunc f11_DisposeStaticWorld;       // from zCWorld  ?DisposeStaticWorld@zCWorld@@UAEXXZ
        vfunc f12_AddVobAsChild;            // from zCWorld  ?AddVobAsChild@zCWorld@@UAEPAV?$zCTree@VzCVob@@@@PAVzCVob@@PAV2@@Z
        vfunc f13_RemoveVob;                // from zCWorld  ?RemoveVob@zCWorld@@UAEXPAVzCVob@@@Z
        vfunc f14_RemoveVobSubtree;         // from zCWorld  ?RemoveVobSubtree@zCWorld@@UAEXPAVzCVob@@@Z
        vfunc f15_MoveVobSubtreeTo;         // from zCWorld  ?MoveVobSubtreeTo@zCWorld@@UAEXPAVzCVob@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f16_GetPlayerGroup;           // from zCWorld  ?GetPlayerGroup@zCWorld@@UAEPAVzCPlayerGroup@@XZ
        vfunc f17_SearchVob;                // from zCWorld  ?SearchVob@zCWorld@@UAEPAVzCVob@@PAV2@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f18_SearchVobByID;            // from zCWorld  ?SearchVobByID@zCWorld@@UAEPAVzCVob@@KPAV?$zCTree@VzCVob@@@@@Z
        vfunc f19_SearchVobByName;          // from zCWorld  ?SearchVobByName@zCWorld@@UAEPAVzCVob@@ABVzSTRING@@@Z
        vfunc f20_SearchVobListByName;      // from zCWorld  ?SearchVobListByName@zCWorld@@UAEXABVzSTRING@@AAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f21_SearchVobListByClass;     // from zCWorld  ?SearchVobListByClass@zCWorld@@UAEXPAVzCClassDef@@AAV?$zCArray@PAVzCVob@@@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f22_SearchVobListByBaseClass; // from zCWorld  ?SearchVobListByBaseClass@zCWorld@@UAEXPAVzCClassDef@@AAV?$zCArray@PAVzCVob@@@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f23_VobAddedToWorld;          // from zCWorld  ?VobAddedToWorld@zCWorld@@MAEXPAVzCVob@@@Z
        vfunc f24_VobRemovedFromWorld;      // from zCWorld  ?VobRemovedFromWorld@zCWorld@@MAEXPAVzCVob@@@Z
        vfunc f25_RenderWaynet;             // from zCWorld  ?RenderWaynet@zCWorld@@MAEXPAVzCCamera@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A5A4;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_zCWorld& GetTable() {
      MemUnlock;
      return *(vftable_zCWorld*)GetAddress();
    }
  };


  struct vftable_zCBBox3DSorterBase_zTBoxSortHandle {
    union {
      vfunc array[4];
      group {
        vfunc f00_scalar_destructor; // from base                
        vfunc f01_AddActive;         // from base                purecall
        vfunc f02_DelActive;         // from base                purecall
        vfunc f03_ClearActive;       // from zCBBox3DSorterBase  ?ClearActive@zTBoxSortHandle@zCBBox3DSorterBase@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A630;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCBBox3DSorterBase_zTBoxSortHandle& GetTable() {
      MemUnlock;
      return *(vftable_zCBBox3DSorterBase_zTBoxSortHandle*)GetAddress();
    }
  };


  struct vftable_zCSoundSystemDummy {
    union {
      vfunc array[32];
      group {
        vfunc f00_scalar_destructor;       // from base                
        vfunc f01_LoadSoundFX;             // from zCSoundSystemDummy  ?LoadSoundFX@zCSoundSystemDummy@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f02_LoadSoundFXScript;       // from zCSoundSystem       ?LoadSoundFXScript@zCSoundSystem@@UAEPAVzCSoundFX@@ABVzSTRING@@@Z
        vfunc f03_GetSFXParser;            // from zCSoundSystem       ?GetSFXParser@zCSoundSystem@@UAEPAVzCParser@@XZ
        vfunc f04_GetPlayingTimeMSEC;      // from zCSoundSystem       ?GetPlayingTimeMSEC@zCSoundSystem@@UAEMABVzSTRING@@@Z
        vfunc f05_SetSound3DDefaultRadius; // from zCSoundSystem       ?SetSound3DDefaultRadius@zCSoundSystem@@UAEXM@Z
        vfunc f06_GetSound3DDefaultRadius; // from zCSoundSystem       ?GetSound3DDefaultRadius@zCSoundSystem@@UBEMXZ
        vfunc f07_SetMasterVolume;         // from zCSoundSystem       ?SetMasterVolume@zCSoundSystem@@UAEXM@Z
        vfunc f08_GetMasterVolume;         // from zCSoundSystem       ?GetMasterVolume@zCSoundSystem@@UAEMXZ
        vfunc f09_PlaySound;               // from zCSoundSystemDummy  ?PlaySound@zCSoundSystemDummy@@UAEHPAVzCSoundFX@@HHMM@Z
        vfunc f10_PlaySound;               // from zCSoundSystemDummy  ?PlaySound@zCSoundSystemDummy@@UAEHPAVzCSoundFX@@H@Z
        vfunc f11_PlaySound3D;             // from zCSoundSystemDummy  ?PlaySound3D@zCSoundSystemDummy@@UAEHABVzSTRING@@PAVzCVob@@HPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f12_PlaySound3D;             // from zCSoundSystemDummy  ?PlaySound3D@zCSoundSystemDummy@@UAEHPAVzCSoundFX@@PAVzCVob@@HPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f13_StopSound;               // from zCSoundSystem       ?StopSound@zCSoundSystem@@UAEXABH@Z
        vfunc f14_StopAllSounds;           // from zCSoundSystem       ?StopAllSounds@zCSoundSystem@@UAEXXZ
        vfunc f15_GetSound3DProps;         // from zCSoundSystemDummy  ?GetSound3DProps@zCSoundSystemDummy@@UAEHABHAAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f16_UpdateSound3D;           // from zCSoundSystemDummy  ?UpdateSound3D@zCSoundSystemDummy@@UAEHABHPAUzTSound3DParams@zCSoundSystem@@@Z
        vfunc f17_GetSoundProps;           // from zCSoundSystem       ?GetSoundProps@zCSoundSystem@@UAEXABHAAHAAM2@Z
        vfunc f18_UpdateSoundProps;        // from zCSoundSystem       ?UpdateSoundProps@zCSoundSystem@@UAEXABHHMM@Z
        vfunc f19_IsSoundActive;           // from zCSoundSystem       ?IsSoundActive@zCSoundSystem@@UAEHABH@Z
        vfunc f20_DoSoundUpdate;           // from zCSoundSystemDummy  ?DoSoundUpdate@zCSoundSystemDummy@@UAEXXZ
        vfunc f21_SetListener;             // from zCSoundSystem       ?SetListener@zCSoundSystem@@UAEXPAVzCVob@@@Z
        vfunc f22_SetGlobalReverbPreset;   // from zCSoundSystem       ?SetGlobalReverbPreset@zCSoundSystem@@UAEXHM@Z
        vfunc f23_SetReverbEnabled;        // from zCSoundSystem       ?SetReverbEnabled@zCSoundSystem@@UAEXH@Z
        vfunc f24_GetReverbEnabled;        // from zCSoundSystem       ?GetReverbEnabled@zCSoundSystem@@UAEHXZ
        vfunc f25_GetNumProvider;          // from zCSoundSystem       ?GetNumProvider@zCSoundSystem@@UAEHXZ
        vfunc f26_GetProviderName;         // from zCSoundSystem       ?GetProviderName@zCSoundSystem@@UAEPBVzSTRING@@H@Z
        vfunc f27_SetProvider;             // from zCSoundSystem       ?SetProvider@zCSoundSystem@@UAEHH@Z
        vfunc f28_SetSpeakerType;          // from zCSoundSystem       ?SetSpeakerType@zCSoundSystem@@UAEXW4zTSpeakerType@1@@Z
        vfunc f29_GetSpeakerType;          // from zCSoundSystem       ?GetSpeakerType@zCSoundSystem@@UAE?AW4zTSpeakerType@1@XZ
        vfunc f30_SetGlobalOcclusion;      // from zCSoundSystemDummy  ?SetGlobalOcclusion@zCSoundSystemDummy@@UAEXM@Z
        vfunc f31_GetCPULoad;              // from zCSoundSystem       ?GetCPULoad@zCSoundSystem@@UAEMXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A6A4;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCSoundSystemDummy& GetTable() {
      MemUnlock;
      return *(vftable_zCSoundSystemDummy*)GetAddress();
    }
  };


  struct vftable_zCMusicSys_Dummy {
    union {
      vfunc array[21];
      group {
        vfunc f00_scalar_destructor;       // from base              
        vfunc f01_PlayThemeByScript;       // from zCMusicSystem     ?PlayThemeByScript@zCMusicSystem@@UAEXABVzSTRING@@HPAH@Z
        vfunc f02_LoadThemeByScript;       // from zCMusicSys_Dummy  ?LoadThemeByScript@zCMusicSys_Dummy@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f03_LoadTheme;               // from zCMusicSys_Dummy  ?LoadTheme@zCMusicSys_Dummy@@UAEPAVzCMusicTheme@@ABVzSTRING@@@Z
        vfunc f04_PlayTheme;               // from zCMusicSystem     ?PlayTheme@zCMusicSystem@@UAEXPAVzCMusicTheme@@ABMABW4zTMus_TransType@@ABW4zTMus_TransSubType@@@Z
        vfunc f05_GetActiveTheme;          // from zCMusicSystem     ?GetActiveTheme@zCMusicSystem@@UAEPAVzCMusicTheme@@XZ
        vfunc f06_PlayJingleByScript;      // from zCMusicSystem     ?PlayJingleByScript@zCMusicSystem@@UAEHABVzSTRING@@@Z
        vfunc f07_StopJingleByScript;      // from zCMusicSystem     ?StopJingleByScript@zCMusicSystem@@UAEXABVzSTRING@@@Z
        vfunc f08_LoadJingleByScript;      // from zCMusicSys_Dummy  ?LoadJingleByScript@zCMusicSys_Dummy@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f09_LoadJingle;              // from zCMusicSys_Dummy  ?LoadJingle@zCMusicSys_Dummy@@UAEPAVzCMusicJingle@@ABVzSTRING@@@Z
        vfunc f10_PlayJingle;              // from zCMusicSystem     ?PlayJingle@zCMusicSystem@@UAEHPBVzCMusicJingle@@ABMABW4zTMus_TransSubType@@@Z
        vfunc f11_StopJingle;              // from zCMusicSystem     ?StopJingle@zCMusicSystem@@UAEXABH@Z
        vfunc f12_IsJingleActive;          // from zCMusicSystem     ?IsJingleActive@zCMusicSystem@@UAEHABH@Z
        vfunc f13_DoMusicUpdate;           // from zCMusicSys_Dummy  ?DoMusicUpdate@zCMusicSys_Dummy@@UAEXXZ
        vfunc f14_AddEventCallBackFunc;    // from zCMusicSystem     ?AddEventCallBackFunc@zCMusicSystem@@UAEXABW4zTMus_EventType@@P6AX0@Z@Z
        vfunc f15_RemoveEventCallBackFunc; // from zCMusicSystem     ?RemoveEventCallBackFunc@zCMusicSystem@@UAEXP6AXABW4zTMus_EventType@@@Z@Z
        vfunc f16_Mute;                    // from zCMusicSystem     ?Mute@zCMusicSystem@@UAEXXZ
        vfunc f17_Stop;                    // from zCMusicSystem     ?Stop@zCMusicSystem@@UAEXXZ
        vfunc f18_SetVolume;               // from zCMusicSystem     ?SetVolume@zCMusicSystem@@UAEXM@Z
        vfunc f19_GetVolume;               // from zCMusicSystem     ?GetVolume@zCMusicSystem@@UBEMXZ
        vfunc f20_IsAvailable;             // from zCMusicSystem     ?IsAvailable@zCMusicSystem@@UAEHABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A72C;
    }

    static uint GetFuncsNum() {
      return 21;
    }

    static vftable_zCMusicSys_Dummy& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicSys_Dummy*)GetAddress();
    }
  };


  struct vftable_zCSoundFXDummy {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;         // from zCSoundFX   ?_GetClassDef@zCSoundFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;             // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;           // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;   // from base        
        vfunc f04_LoadResourceData;    // from zCResource  ?LoadResourceData@zCResource@@UAEHXZ
        vfunc f05_ReleaseResourceData; // from zCResource  ?ReleaseResourceData@zCResource@@UAEHXZ
        vfunc f06_GetResSizeBytes;     // from zCResource  ?GetResSizeBytes@zCResource@@UAEKXZ
        vfunc f07_GetCacheConfig;      // from zCSoundFX   ?GetCacheConfig@zCSoundFX@@UAEXAAK0@Z
        vfunc f08_GetNumChannels;      // from zCSoundFX   ?GetNumChannels@zCSoundFX@@UBEHXZ
        vfunc f09_GetNumChannelFrames; // from zCSoundFX   ?GetNumChannelFrames@zCSoundFX@@UBEHH@Z
        vfunc f10_GetChannelFrame;     // from zCSoundFX   ?GetChannelFrame@zCSoundFX@@UBEXHH@Z
        vfunc f11_SetChannelFrame;     // from zCSoundFX   ?SetChannelFrame@zCSoundFX@@UAEXHH@Z
        vfunc f12_GetPlayingTimeMSEC;  // from zCSoundFX   ?GetPlayingTimeMSEC@zCSoundFX@@UBEMXZ
        vfunc f13_GetPan;              // from zCSoundFX   ?GetPan@zCSoundFX@@UBEMXZ
        vfunc f14_SetPan;              // from zCSoundFX   ?SetPan@zCSoundFX@@UAEXM@Z
        vfunc f15_GetVolume;           // from zCSoundFX   ?GetVolume@zCSoundFX@@UBEMXZ
        vfunc f16_SetVolume;           // from zCSoundFX   ?SetVolume@zCSoundFX@@UAEXM@Z
        vfunc f17_GetFrequency;        // from zCSoundFX   ?GetFrequency@zCSoundFX@@UBEHXZ
        vfunc f18_SetFrequency;        // from zCSoundFX   ?SetFrequency@zCSoundFX@@UAEXH@Z
        vfunc f19_SetLooping;          // from zCSoundFX   ?SetLooping@zCSoundFX@@UAEXH@Z
        vfunc f20_IsLooping;           // from zCSoundFX   ?IsLooping@zCSoundFX@@UBEHXZ
        vfunc f21_SetIsFixed;          // from zCSoundFX   ?SetIsFixed@zCSoundFX@@UAEXH@Z
        vfunc f22_GetIsFixed;          // from zCSoundFX   ?GetIsFixed@zCSoundFX@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A784;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCSoundFXDummy& GetTable() {
      MemUnlock;
      return *(vftable_zCSoundFXDummy*)GetAddress();
    }
  };


  struct vftable_zCVobCallback_PrintBigBBox {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleVob; // from zCVobCallback_PrintBigBBox  ?HandleVob@zCVobCallback_PrintBigBBox@@UAEXPAVzCVob@@PAX@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A7E4;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCVobCallback_PrintBigBBox& GetTable() {
      MemUnlock;
      return *(vftable_zCVobCallback_PrintBigBBox*)GetAddress();
    }
  };


  struct vftable_zCZoneZFogDefault {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneZFogDefault  ?_GetClassDef@zCZoneZFogDefault@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneZFog         ?Archive@zCZoneZFog@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneZFogDefault  ?Unarchive@zCZoneZFogDefault@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from zCVob              ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob              ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob              ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob              ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob              ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob              ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob              ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone             ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob              ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZoneZFogDefault  ?ThisVobAddedToWorld@zCZoneZFogDefault@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone             ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneZFog         ?ProcessZoneList@zCZoneZFog@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone             ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneZFog         ?GetDefaultZoneClass@zCZoneZFog@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone             ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A7FC;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneZFogDefault& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneZFogDefault*)GetAddress();
    }
  };


  struct vftable_zCShowMemCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_DoWorldPerFrameCallback; // from zCShowMemCallback  ?DoWorldPerFrameCallback@zCShowMemCallback@@UAEXPAVzCWorld@@PAVzCCamera@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083A880;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCShowMemCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCShowMemCallback*)GetAddress();
    }
  };


  struct vftable_zCZoneReverb {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneReverb  ?_GetClassDef@zCZoneReverb@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneReverb  ?Archive@zCZoneReverb@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneReverb  ?Unarchive@zCZoneReverb@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_OnTrigger;               // from zCVob         ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob         ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob         ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob         ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob         ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob         ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob         ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob         ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob         ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob         ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob         ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob         ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone        ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob         ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob         ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone        ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone        ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob         ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob         ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob         ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob         ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob         ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone        ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone        ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneReverb  ?ProcessZoneList@zCZoneReverb@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone        ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneReverb  ?GetDefaultZoneClass@zCZoneReverb@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZoneReverb  ?GetDebugDescString@zCZoneReverb@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A89C;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneReverb& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneReverb*)GetAddress();
    }
  };


  struct vftable_zCZone {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZone  ?_GetClassDef@zCZone@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob   ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZone  ?Unarchive@zCZone@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base    
        vfunc f04_OnTrigger;               // from zCVob   ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob   ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob   ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob   ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob   ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob   ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob   ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob   ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob   ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob   ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob   ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob   ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone  ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob   ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob   ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone  ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone  ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob   ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob   ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob   ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob   ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob   ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone  ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone  ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZone  ?ProcessZoneList@zCZone@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone  ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZone  ?GetDefaultZoneClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone  ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A924;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZone& GetTable() {
      MemUnlock;
      return *(vftable_zCZone*)GetAddress();
    }
  };


  struct vftable_zCZoneReverbDefault {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneReverbDefault  ?_GetClassDef@zCZoneReverbDefault@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneReverb         ?Archive@zCZoneReverb@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneReverbDefault  ?Unarchive@zCZoneReverbDefault@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                 
        vfunc f04_OnTrigger;               // from zCVob                ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob                ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob                ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob                ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob                ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob                ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob                ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob                ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob                ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone               ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone               ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone               ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob                ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZoneReverbDefault  ?ThisVobAddedToWorld@zCZoneReverbDefault@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone               ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneReverbDefault  ?ProcessZoneList@zCZoneReverbDefault@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone               ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneReverb         ?GetDefaultZoneClass@zCZoneReverb@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZoneReverb         ?GetDebugDescString@zCZoneReverb@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083A9AC;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneReverbDefault& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneReverbDefault*)GetAddress();
    }
  };


  struct vftable_zCZoneVobFarPlane {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneVobFarPlane  ?_GetClassDef@zCZoneVobFarPlane@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneVobFarPlane  ?Archive@zCZoneVobFarPlane@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneVobFarPlane  ?Unarchive@zCZoneVobFarPlane@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from zCVob              ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob              ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob              ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob              ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob              ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob              ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob              ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone             ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob              ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone             ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone             ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneVobFarPlane  ?ProcessZoneList@zCZoneVobFarPlane@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone             ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneVobFarPlane  ?GetDefaultZoneClass@zCZoneVobFarPlane@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone             ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083AA34;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneVobFarPlane& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneVobFarPlane*)GetAddress();
    }
  };


  struct vftable_zCZoneVobFarPlaneDefault {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneVobFarPlaneDefault  ?_GetClassDef@zCZoneVobFarPlaneDefault@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneVobFarPlane         ?Archive@zCZoneVobFarPlane@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneVobFarPlaneDefault  ?Unarchive@zCZoneVobFarPlaneDefault@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                      
        vfunc f04_OnTrigger;               // from zCVob                     ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob                     ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob                     ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob                     ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                     ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob                     ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob                     ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob                     ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob                     ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob                     ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                     ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                     ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone                    ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                     ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                     ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone                    ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone                    ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                     ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                     ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                     ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                     ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob                     ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZoneVobFarPlaneDefault  ?ThisVobAddedToWorld@zCZoneVobFarPlaneDefault@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone                    ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneVobFarPlane         ?ProcessZoneList@zCZoneVobFarPlane@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone                    ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneVobFarPlane         ?GetDefaultZoneClass@zCZoneVobFarPlane@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone                    ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083AABC;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneVobFarPlaneDefault& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneVobFarPlaneDefault*)GetAddress();
    }
  };


  struct vftable_zCZoneMusic {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneMusic  ?_GetClassDef@zCZoneMusic@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob        ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZone       ?Unarchive@zCZone@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_OnTrigger;               // from zCVob        ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob        ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob        ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob        ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob        ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob        ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob        ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob        ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob        ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob        ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob        ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob        ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone       ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob        ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob        ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone       ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone       ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob        ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob        ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob        ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob        ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob        ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone       ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone       ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZone       ?ProcessZoneList@zCZone@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone       ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZone       ?GetDefaultZoneClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone       ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083AB44;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneMusic& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneMusic*)GetAddress();
    }
  };


  struct vftable_zCZoneZFog {
    union {
      vfunc array[32];
      group {
        vfunc f00_GetClassDef;             // from zCZoneZFog  ?_GetClassDef@zCZoneZFog@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCZoneZFog  ?Archive@zCZoneZFog@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCZoneZFog  ?Unarchive@zCZoneZFog@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_OnTrigger;               // from zCVob       ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob       ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob       ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob       ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone      ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob       ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone      ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone      ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone      ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone      ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCZoneZFog  ?ProcessZoneList@zCZoneZFog@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone      ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZoneZFog  ?GetDefaultZoneClass@zCZoneZFog@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCZone      ?GetDebugDescString@zCZone@@UAE?AVzSTRING@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083ABCC;
    }

    static uint GetFuncsNum() {
      return 32;
    }

    static vftable_zCZoneZFog& GetTable() {
      MemUnlock;
      return *(vftable_zCZoneZFog*)GetAddress();
    }
  };


  struct vftable_zCVobSoundDaytime {
    union {
      vfunc array[33];
      group {
        vfunc f00_GetClassDef;             // from zCVobSoundDaytime  ?_GetClassDef@zCVobSoundDaytime@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobSoundDaytime  ?Archive@zCVobSoundDaytime@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobSoundDaytime  ?Unarchive@zCVobSoundDaytime@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_OnTrigger;               // from zCVobSound         ?OnTrigger@zCVobSound@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVobSound         ?OnUntrigger@zCVobSound@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob              ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob              ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob              ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob              ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVobSound         ?OnMessage@zCVobSound@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob              ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob              ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob              ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob              ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob              ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVobSound         ?EndMovement@zCVobSound@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob              ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob              ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone             ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob              ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob              ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob              ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob              ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob              ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVobSound         ?ThisVobAddedToWorld@zCVobSound@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVobSound         ?ThisVobRemovedFromWorld@zCVobSound@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCVobSound         ?ProcessZoneList@zCVobSound@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCVobSoundDaytime  ?GetZoneMotherClass@zCVobSoundDaytime@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZone             ?GetDefaultZoneClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCVobSoundDaytime  ?GetDebugDescString@zCVobSoundDaytime@@UAE?AVzSTRING@@XZ
        vfunc f32_DoSoundUpdate;           // from zCVobSoundDaytime  ?DoSoundUpdate@zCVobSoundDaytime@@MAEXM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083AC54;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCVobSoundDaytime& GetTable() {
      MemUnlock;
      return *(vftable_zCVobSoundDaytime*)GetAddress();
    }
  };


  struct vftable_zCBBox3DSorterBase {
    union {
      vfunc array[2];
      group {
        vfunc f00_scalar_destructor; // from base  
        vfunc f01_GetBBox;           // from base  purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0083ACDC;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_zCBBox3DSorterBase& GetTable() {
      MemUnlock;
      return *(vftable_zCBBox3DSorterBase*)GetAddress();
    }
  };


  struct vftable_zCVobSound {
    union {
      vfunc array[33];
      group {
        vfunc f00_GetClassDef;             // from zCVobSound  ?_GetClassDef@zCVobSound@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVobSound  ?Archive@zCVobSound@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVobSound  ?Unarchive@zCVobSound@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_OnTrigger;               // from zCVobSound  ?OnTrigger@zCVobSound@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVobSound  ?OnUntrigger@zCVobSound@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                 // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob       ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVobSound  ?OnMessage@zCVobSound@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob       ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVobSound  ?EndMovement@zCVobSound@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob       ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob       ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone      ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone      ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob       ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob       ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVobSound  ?ThisVobAddedToWorld@zCVobSound@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVobSound  ?ThisVobRemovedFromWorld@zCVobSound@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from zCVobSound  ?ProcessZoneList@zCVobSound@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone      ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from zCZone      ?GetDefaultZoneClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from zCVobSound  ?GetDebugDescString@zCVobSound@@UAE?AVzSTRING@@XZ
        vfunc f32_DoSoundUpdate;           // from zCVobSound  ?DoSoundUpdate@zCVobSound@@MAEXM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083ACEC;
    }

    static uint GetFuncsNum() {
      return 33;
    }

    static vftable_zCVobSound& GetTable() {
      MemUnlock;
      return *(vftable_zCVobSound*)GetAddress();
    }
  };


  struct vftable_oCZoneMusic {
    union {
      vfunc array[34];
      group {
        vfunc f00_GetClassDef;             // from oCZoneMusic  ?_GetClassDef@oCZoneMusic@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCZoneMusic  ?Archive@oCZoneMusic@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCZoneMusic  ?Unarchive@oCZoneMusic@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_OnTrigger;               // from zCVob        ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob        ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob        ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob        ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob        ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob        ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob        ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob        ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob        ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob        ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob        ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob        ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone       ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob        ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob        ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone       ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone       ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob        ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob        ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob        ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob        ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob        ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone       ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone       ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from oCZoneMusic  ?ProcessZoneList@oCZoneMusic@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone       ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from oCZoneMusic  ?GetDefaultZoneClass@oCZoneMusic@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from oCZoneMusic  ?GetDebugDescString@oCZoneMusic@@UAE?AVzSTRING@@XZ
        vfunc f32_OnTrigger;               // from oCZoneMusic  ?OnTrigger@oCZoneMusic@@UAEXPAVzCVob@@@Z
        vfunc f33_OnUntrigger;             // from oCZoneMusic  ?OnUntrigger@oCZoneMusic@@UAEXPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083AD8C;
    }

    static uint GetFuncsNum() {
      return 34;
    }

    static vftable_oCZoneMusic& GetTable() {
      MemUnlock;
      return *(vftable_oCZoneMusic*)GetAddress();
    }
  };


  struct vftable_oCZoneMusicDefault {
    union {
      vfunc array[34];
      group {
        vfunc f00_GetClassDef;             // from oCZoneMusicDefault  ?_GetClassDef@oCZoneMusicDefault@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCZoneMusic         ?Archive@oCZoneMusic@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCZoneMusic         ?Unarchive@oCZoneMusic@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                
        vfunc f04_OnTrigger;               // from zCVob               ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob               ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob               ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob               ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob               ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob               ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob               ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob               ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob               ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob               ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob               ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob               ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCZone              ?EndMovement@zCZone@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob               ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob               ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCZone              ?SetVisual@zCZone@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCZone              ?SetVisual@zCZone@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob               ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob               ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob               ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob               ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob               ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCZone              ?ThisVobAddedToWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCZone              ?ThisVobRemovedFromWorld@zCZone@@UAEXPAVzCWorld@@@Z
        vfunc f28_ProcessZoneList;         // from oCZoneMusic         ?ProcessZoneList@oCZoneMusic@@UAEXABV?$zCArraySort@PAVzCZone@@@@0PAVzCWorld@@@Z
        vfunc f29_GetZoneMotherClass;      // from zCZone              ?GetZoneMotherClass@zCZone@@UBEPAVzCClassDef@@XZ
        vfunc f30_GetDefaultZoneClass;     // from oCZoneMusic         ?GetDefaultZoneClass@oCZoneMusic@@UBEPAVzCClassDef@@XZ
        vfunc f31_GetDebugDescString;      // from oCZoneMusic         ?GetDebugDescString@oCZoneMusic@@UAE?AVzSTRING@@XZ
        vfunc f32_OnTrigger;               // from oCZoneMusic         ?OnTrigger@oCZoneMusic@@UAEXPAVzCVob@@@Z
        vfunc f33_OnUntrigger;             // from oCZoneMusic         ?OnUntrigger@oCZoneMusic@@UAEXPAVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083AE1C;
    }

    static uint GetFuncsNum() {
      return 34;
    }

    static vftable_oCZoneMusicDefault& GetTable() {
      MemUnlock;
      return *(vftable_oCZoneMusicDefault*)GetAddress();
    }
  };


  struct vftable_zCMusicControler {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCMusicControler  ?_GetClassDef@zCMusicControler@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob             ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob             ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base              
        vfunc f04_OnTrigger;               // from zCVob             ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob             ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob             ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob             ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob             ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob             ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCMusicControler  ?OnMessage@zCMusicControler@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                  // from zCVob             ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob             ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob             ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob             ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob             ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob             ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob             ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob             ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob             ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob             ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob             ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob             ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob             ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob             ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob             ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCMusicControler  ?ThisVobRemovedFromWorld@zCMusicControler@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083AEBC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCMusicControler& GetTable() {
      MemUnlock;
      return *(vftable_zCMusicControler*)GetAddress();
    }
  };


  struct vftable_zCEventMusicControler {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from zCEventMusicControler  ?_GetClassDef@zCEventMusicControler@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMusicControler  ?Archive@zCEventMusicControler@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMusicControler  ?Unarchive@zCEventMusicControler@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base                   
        vfunc f04_IsOverlay;             // from zCEventMessage         ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage         ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage         ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage         ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage         ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage         ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage         ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage         ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage         ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage         ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventMusicControler  ?MD_GetNumOfSubTypes@zCEventMusicControler@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventMusicControler  ?MD_GetSubTypeString@zCEventMusicControler@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage         ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage         ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage         ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMusicControler  ?MD_GetTimeBehavior@zCEventMusicControler@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMusicControler  ?MD_GetMinTime@zCEventMusicControler@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage         ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage         ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083AF34;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_zCEventMusicControler& GetTable() {
      MemUnlock;
      return *(vftable_zCEventMusicControler*)GetAddress();
    }
  };


  struct vftable_zCRnd_D3D {
    union {
      vfunc array[103];
      group {
        vfunc f00_scalar_destructor;             // from base       
        vfunc f01_BeginFrame;                    // from zCRnd_D3D  ?BeginFrame@zCRnd_D3D@@UAEXXZ
        vfunc f02_EndFrame;                      // from zCRnd_D3D  ?EndFrame@zCRnd_D3D@@UAEXXZ
        vfunc f03_FlushPolys;                    // from zCRnd_D3D  ?FlushPolys@zCRnd_D3D@@UAEXXZ
        vfunc f04_DrawPoly;                      // from zCRnd_D3D  ?DrawPoly@zCRnd_D3D@@UAEXPAVzCPolygon@@@Z
        vfunc f05_DrawLightmapList;              // from zCRnd_D3D  ?DrawLightmapList@zCRnd_D3D@@UAEXPAPAVzCPolygon@@H@Z
        vfunc f06_DrawLine;                      // from zCRnd_D3D  ?DrawLine@zCRnd_D3D@@UAEXMMMMUzCOLOR@@@Z
        vfunc f07_DrawLineZ;                     // from zCRnd_D3D  ?DrawLineZ@zCRnd_D3D@@UAEXMMMMMMUzCOLOR@@@Z
        vfunc f08_SetPixel;                      // from zCRnd_D3D  ?SetPixel@zCRnd_D3D@@UAEXMMUzCOLOR@@@Z
        vfunc f09_DrawPolySimple;                // from zCRnd_D3D  ?DrawPolySimple@zCRnd_D3D@@UAEXPAVzCTexture@@PAUzTRndSimpleVertex@@H@Z
        vfunc f10_SetFog;                        // from zCRnd_D3D  ?SetFog@zCRnd_D3D@@UAEXH@Z
        vfunc f11_GetFog;                        // from zCRnd_D3D  ?GetFog@zCRnd_D3D@@UBEHXZ
        vfunc f12_SetRadialFog;                  // from zCRnd_D3D  ?SetRadialFog@zCRnd_D3D@@UAEXH@Z
        vfunc f13_GetRadialFog;                  // from zCRnd_D3D  ?GetRadialFog@zCRnd_D3D@@UBEHXZ
        vfunc f14_SetFogColor;                   // from zCRnd_D3D  ?SetFogColor@zCRnd_D3D@@UAEXABUzCOLOR@@@Z
        vfunc f15_GetFogColor;                   // from zCRnd_D3D  ?GetFogColor@zCRnd_D3D@@UBE?AUzCOLOR@@XZ
        vfunc f16_SetFogRange;                   // from zCRnd_D3D  ?SetFogRange@zCRnd_D3D@@UAEXMMW4zTRnd_FogMode@@@Z
        vfunc f17_GetFogRange;                   // from zCRnd_D3D  ?GetFogRange@zCRnd_D3D@@UAEXAAM0AAW4zTRnd_FogMode@@@Z
        vfunc f18_GetPolyDrawMode;               // from zCRnd_D3D  ?GetPolyDrawMode@zCRnd_D3D@@UBE?AW4zTRnd_PolyDrawMode@@XZ
        vfunc f19_SetPolyDrawMode;               // from zCRnd_D3D  ?SetPolyDrawMode@zCRnd_D3D@@UAEXABW4zTRnd_PolyDrawMode@@@Z
        vfunc f20_GetSurfaceLost;                // from zCRnd_D3D  ?GetSurfaceLost@zCRnd_D3D@@UBEHXZ
        vfunc f21_SetSurfaceLost;                // from zCRnd_D3D  ?SetSurfaceLost@zCRnd_D3D@@UAEXH@Z
        vfunc f22_GetSyncOnAmbientCol;           // from zCRnd_D3D  ?GetSyncOnAmbientCol@zCRnd_D3D@@UBEHXZ
        vfunc f23_SetSyncOnAmbientCol;           // from zCRnd_D3D  ?SetSyncOnAmbientCol@zCRnd_D3D@@UAEXH@Z
        vfunc f24_SetTextureWrapEnabled;         // from zCRnd_D3D  ?SetTextureWrapEnabled@zCRnd_D3D@@UAEXH@Z
        vfunc f25_GetTextureWrapEnabled;         // from zCRnd_D3D  ?GetTextureWrapEnabled@zCRnd_D3D@@UBEHXZ
        vfunc f26_SetBilerpFilterEnabled;        // from zCRnd_D3D  ?SetBilerpFilterEnabled@zCRnd_D3D@@UAEXH@Z
        vfunc f27_GetBilerpFilterEnabled;        // from zCRnd_D3D  ?GetBilerpFilterEnabled@zCRnd_D3D@@UBEHXZ
        vfunc f28_SetDitherEnabled;              // from zCRnd_D3D  ?SetDitherEnabled@zCRnd_D3D@@UAEXH@Z
        vfunc f29_GetDitherEnabled;              // from zCRnd_D3D  ?GetDitherEnabled@zCRnd_D3D@@UBEHXZ
        vfunc f30_GetPolySortMode;               // from zCRnd_D3D  ?GetPolySortMode@zCRnd_D3D@@UBE?AW4zTRnd_PolySortMode@@XZ
        vfunc f31_SetPolySortMode;               // from zCRnd_D3D  ?SetPolySortMode@zCRnd_D3D@@UAEXABW4zTRnd_PolySortMode@@@Z
        vfunc f32_GetZBufferWriteEnabled;        // from zCRnd_D3D  ?GetZBufferWriteEnabled@zCRnd_D3D@@UBEHXZ
        vfunc f33_SetZBufferWriteEnabled;        // from zCRnd_D3D  ?SetZBufferWriteEnabled@zCRnd_D3D@@UAEXH@Z
        vfunc f34_SetZBias;                      // from zCRnd_D3D  ?SetZBias@zCRnd_D3D@@UAEXH@Z
        vfunc f35_GetZBias;                      // from zCRnd_D3D  ?GetZBias@zCRnd_D3D@@UBEHXZ
        vfunc f36_GetZBufferCompare;             // from zCRnd_D3D  ?GetZBufferCompare@zCRnd_D3D@@UAE?AW4zTRnd_ZBufferCmp@@XZ
        vfunc f37_SetZBufferCompare;             // from zCRnd_D3D  ?SetZBufferCompare@zCRnd_D3D@@UAEXABW4zTRnd_ZBufferCmp@@@Z
        vfunc f38_GetPixelWriteEnabled;          // from zCRnd_D3D  ?GetPixelWriteEnabled@zCRnd_D3D@@UBEHXZ
        vfunc f39_SetPixelWriteEnabled;          // from zCRnd_D3D  ?SetPixelWriteEnabled@zCRnd_D3D@@UAEXH@Z
        vfunc f40_SetAlphaBlendSource;           // from zCRnd_D3D  ?SetAlphaBlendSource@zCRnd_D3D@@UAEXABW4zTRnd_AlphaBlendSource@@@Z
        vfunc f41_GetAlphaBlendSource;           // from zCRnd_D3D  ?GetAlphaBlendSource@zCRnd_D3D@@UBE?AW4zTRnd_AlphaBlendSource@@XZ
        vfunc f42_SetAlphaBlendFunc;             // from zCRnd_D3D  ?SetAlphaBlendFunc@zCRnd_D3D@@UAEXABW4zTRnd_AlphaBlendFunc@@@Z
        vfunc f43_GetAlphaBlendFunc;             // from zCRnd_D3D  ?GetAlphaBlendFunc@zCRnd_D3D@@UBE?AW4zTRnd_AlphaBlendFunc@@XZ
        vfunc f44_GetAlphaBlendFactor;           // from zCRnd_D3D  ?GetAlphaBlendFactor@zCRnd_D3D@@UBEMXZ
        vfunc f45_SetAlphaBlendFactor;           // from zCRnd_D3D  ?SetAlphaBlendFactor@zCRnd_D3D@@UAEXABM@Z
        vfunc f46_SetAlphaReference;             // from zCRnd_D3D  ?SetAlphaReference@zCRnd_D3D@@UAEXK@Z
        vfunc f47_GetAlphaReference;             // from zCRnd_D3D  ?GetAlphaReference@zCRnd_D3D@@UBEKXZ
        vfunc f48_GetCacheAlphaPolys;            // from zCRnd_D3D  ?GetCacheAlphaPolys@zCRnd_D3D@@UBEHXZ
        vfunc f49_SetCacheAlphaPolys;            // from zCRnd_D3D  ?SetCacheAlphaPolys@zCRnd_D3D@@UAEXH@Z
        vfunc f50_GetAlphaLimitReached;          // from zCRnd_D3D  ?GetAlphaLimitReached@zCRnd_D3D@@UBEHXZ
        vfunc f51_AddAlphaPoly;                  // from zCRnd_D3D  ?AddAlphaPoly@zCRnd_D3D@@UAEXPBVzCPolygon@@@Z
        vfunc f52_FlushAlphaPolys;               // from zCRnd_D3D  ?FlushAlphaPolys@zCRnd_D3D@@UAEXXZ
        vfunc f53_SetRenderMode;                 // from zCRnd_D3D  ?SetRenderMode@zCRnd_D3D@@UAEXW4zTRnd_RenderMode@@@Z
        vfunc f54_GetRenderMode;                 // from zCRnd_D3D  ?GetRenderMode@zCRnd_D3D@@UBE?AW4zTRnd_RenderMode@@XZ
        vfunc f55_HasCapability;                 // from zCRnd_D3D  ?HasCapability@zCRnd_D3D@@UBEHW4zTRnd_Capability@@@Z
        vfunc f56_GetGuardBandBorders;           // from zCRnd_D3D  ?GetGuardBandBorders@zCRnd_D3D@@UAEXAAM000@Z
        vfunc f57_ResetZTest;                    // from zCRnd_D3D  ?ResetZTest@zCRnd_D3D@@UAEXXZ
        vfunc f58_HasPassedZTest;                // from zCRnd_D3D  ?HasPassedZTest@zCRnd_D3D@@UAEHXZ
        vfunc f59_CreateTexture;                 // from zCRnd_D3D  ?CreateTexture@zCRnd_D3D@@UAEPAVzCTexture@@XZ
        vfunc f60_CreateTextureConvert;          // from zCRnd_D3D  ?CreateTextureConvert@zCRnd_D3D@@UAEPAVzCTextureConvert@@XZ
        vfunc f61_GetTotalTextureMem;            // from zCRnd_D3D  ?GetTotalTextureMem@zCRnd_D3D@@UAEHXZ
        vfunc f62_SupportsTextureFormat;         // from zCRnd_D3D  ?SupportsTextureFormat@zCRnd_D3D@@UAEHW4zTRnd_TextureFormat@@@Z
        vfunc f63_SupportsTextureFormatHardware; // from zCRnd_D3D  ?SupportsTextureFormatHardware@zCRnd_D3D@@UAEHW4zTRnd_TextureFormat@@@Z
        vfunc f64_GetMaxTextureSize;             // from zCRnd_D3D  ?GetMaxTextureSize@zCRnd_D3D@@UAEHXZ
        vfunc f65_GetStatistics;                 // from zCRnd_D3D  ?GetStatistics@zCRnd_D3D@@UAEXAAUzTRnd_Stats@@@Z
        vfunc f66_ResetStatistics;               // from zCRnd_D3D  ?ResetStatistics@zCRnd_D3D@@UAEXXZ
        vfunc f67_Vid_Blit;                      // from zCRnd_D3D  ?Vid_Blit@zCRnd_D3D@@UAEXHPAUtagRECT@@0@Z
        vfunc f68_Vid_Clear;                     // from zCRnd_D3D  ?Vid_Clear@zCRnd_D3D@@UAEXAAUzCOLOR@@H@Z
        vfunc f69_Vid_Lock;                      // from zCRnd_D3D  ?Vid_Lock@zCRnd_D3D@@UAEHAAUzTRndSurfaceDesc@@@Z
        vfunc f70_Vid_Unlock;                    // from zCRnd_D3D  ?Vid_Unlock@zCRnd_D3D@@UAEHXZ
        vfunc f71_Vid_IsLocked;                  // from zCRnd_D3D  ?Vid_IsLocked@zCRnd_D3D@@UAEHXZ
        vfunc f72_Vid_GetFrontBufferCopy;        // from zCRnd_D3D  ?Vid_GetFrontBufferCopy@zCRnd_D3D@@UAEHAAVzCTextureConvert@@@Z
        vfunc f73_Vid_GetNumDevices;             // from zCRnd_D3D  ?Vid_GetNumDevices@zCRnd_D3D@@UAEHXZ
        vfunc f74_Vid_GetActiveDeviceNr;         // from zCRnd_D3D  ?Vid_GetActiveDeviceNr@zCRnd_D3D@@UAEHXZ
        vfunc f75_Vid_SetDevice;                 // from zCRnd_D3D  ?Vid_SetDevice@zCRnd_D3D@@UAEHH@Z
        vfunc f76_Vid_GetDeviceInfo;             // from zCRnd_D3D  ?Vid_GetDeviceInfo@zCRnd_D3D@@UAEHAAUzTRnd_DeviceInfo@@H@Z
        vfunc f77_Vid_GetNumModes;               // from zCRnd_D3D  ?Vid_GetNumModes@zCRnd_D3D@@UAEHXZ
        vfunc f78_Vid_GetModeInfo;               // from zCRnd_D3D  ?Vid_GetModeInfo@zCRnd_D3D@@UAEHAAUzTRnd_VidModeInfo@@H@Z
        vfunc f79_Vid_GetActiveModeNr;           // from zCRnd_D3D  ?Vid_GetActiveModeNr@zCRnd_D3D@@UAEHXZ
        vfunc f80_Vid_SetMode;                   // from zCRnd_D3D  ?Vid_SetMode@zCRnd_D3D@@UAEHHPAPAUHWND_@@@Z
        vfunc f81_Vid_SetScreenMode;             // from zCRnd_D3D  ?Vid_SetScreenMode@zCRnd_D3D@@UAEXW4zTRnd_ScreenMode@@@Z
        vfunc f82_Vid_GetScreenMode;             // from zCRnd_D3D  ?Vid_GetScreenMode@zCRnd_D3D@@UAE?AW4zTRnd_ScreenMode@@XZ
        vfunc f83_Vid_SetGammaCorrection;        // from zCRnd_D3D  ?Vid_SetGammaCorrection@zCRnd_D3D@@UAEXMMM@Z
        vfunc f84_Vid_GetGammaCorrection;        // from zCRnd_D3D  ?Vid_GetGammaCorrection@zCRnd_D3D@@UAEMXZ
        vfunc f85_Vid_BeginLfbAccess;            // from zCRnd_D3D  ?Vid_BeginLfbAccess@zCRnd_D3D@@UAEXXZ
        vfunc f86_Vid_EndLfbAccess;              // from zCRnd_D3D  ?Vid_EndLfbAccess@zCRnd_D3D@@UAEXXZ
        vfunc f87_Vid_SetLfbAlpha;               // from zCRnd_D3D  ?Vid_SetLfbAlpha@zCRnd_D3D@@UAEXH@Z
        vfunc f88_Vid_SetLfbAlphaFunc;           // from zCRnd_D3D  ?Vid_SetLfbAlphaFunc@zCRnd_D3D@@UAEXABW4zTRnd_AlphaBlendFunc@@@Z
        vfunc f89_SetTransform;                  // from zCRnd_D3D  ?SetTransform@zCRnd_D3D@@UAEHW4zTRnd_TrafoType@@ABVzMAT4@@@Z
        vfunc f90_SetViewport;                   // from zCRnd_D3D  ?SetViewport@zCRnd_D3D@@UAEHHHHH@Z
        vfunc f91_SetLight;                      // from zCRnd_D3D  ?SetLight@zCRnd_D3D@@UAEHKPAVzCRenderLight@@@Z
        vfunc f92_GetMaterial;                   // from zCRnd_D3D  ?GetMaterial@zCRnd_D3D@@UAEHAAUzTMaterial@zCRenderer@@@Z
        vfunc f93_SetMaterial;                   // from zCRnd_D3D  ?SetMaterial@zCRnd_D3D@@UAEHABUzTMaterial@zCRenderer@@@Z
        vfunc f94_SetTexture;                    // from zCRnd_D3D  ?SetTexture@zCRnd_D3D@@UAEHKPAVzCTexture@@@Z
        vfunc f95_SetTextureStageState;          // from zCRnd_D3D  ?SetTextureStageState@zCRnd_D3D@@UAEHKW4zTRnd_TextureStageState@@K@Z
        vfunc f96_SetAlphaBlendFuncImmed;        // from zCRnd_D3D  ?SetAlphaBlendFuncImmed@zCRnd_D3D@@UAEHW4zTRnd_AlphaBlendFunc@@@Z
        vfunc f97_SetRenderState;                // from zCRnd_D3D  ?SetRenderState@zCRnd_D3D@@UAEHW4zTRnd_RenderStateType@@K@Z
        vfunc f98_GetRenderState;                // from zCRnd_D3D  ?GetRenderState@zCRnd_D3D@@UAEKW4zTRnd_RenderStateType@@@Z
        vfunc f99_AddAlphaSortObject;            // from zCRnd_D3D  ?AddAlphaSortObject@zCRnd_D3D@@UAEXPAVzCRndAlphaSortObject@@@Z
        vfunc f100_RenderAlphaSortList;          // from zCRnd_D3D  ?RenderAlphaSortList@zCRnd_D3D@@UAEXXZ
        vfunc f101_DrawVertexBuffer;             // from zCRnd_D3D  ?DrawVertexBuffer@zCRnd_D3D@@UAEHPAVzCVertexBuffer@@HHPAGK@Z
        vfunc f102_CreateVertexBuffer;           // from zCRnd_D3D  ?CreateVertexBuffer@zCRnd_D3D@@UAEPAVzCVertexBuffer@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B0C4;
    }

    static uint GetFuncsNum() {
      return 103;
    }

    static vftable_zCRnd_D3D& GetTable() {
      MemUnlock;
      return *(vftable_zCRnd_D3D*)GetAddress();
    }
  };


  struct vftable_zCRenderer {
    union {
      vfunc array[103];
      group {
        vfunc f00_scalar_destructor;             // from base        
        vfunc f01_BeginFrame;                    // from base        purecall
        vfunc f02_EndFrame;                      // from base        purecall
        vfunc f03_FlushPolys;                    // from base        purecall
        vfunc f04_DrawPoly;                      // from base        purecall
        vfunc f05_DrawLightmapList;              // from zCRenderer  ?DrawLightmapList@zCRenderer@@UAEXPAPAVzCPolygon@@H@Z
        vfunc f06_DrawLine;                      // from base        purecall
        vfunc f07_DrawLineZ;                     // from zCRenderer  ?DrawLineZ@zCRenderer@@UAEXMMMMMMUzCOLOR@@@Z
        vfunc f08_SetPixel;                      // from base        purecall
        vfunc f09_DrawPolySimple;                // from zCRenderer  ?DrawPolySimple@zCRenderer@@UAEXPAVzCTexture@@PAUzTRndSimpleVertex@@H@Z
        vfunc f10_SetFog;                        // from base        purecall
        vfunc f11_GetFog;                        // from zCRenderer  ?GetFog@zCRenderer@@UBEHXZ
        vfunc f12_SetRadialFog;                  // from base        purecall
        vfunc f13_GetRadialFog;                  // from zCRenderer  ?GetRadialFog@zCRenderer@@UBEHXZ
        vfunc f14_SetFogColor;                   // from base        purecall
        vfunc f15_GetFogColor;                   // from zCRenderer  ?GetFogColor@zCRenderer@@UBE?AUzCOLOR@@XZ
        vfunc f16_SetFogRange;                   // from base        purecall
        vfunc f17_GetFogRange;                   // from zCRenderer  ?GetFogRange@zCRenderer@@UAEXAAM0AAW4zTRnd_FogMode@@@Z
        vfunc f18_GetPolyDrawMode;               // from zCRenderer  ?GetPolyDrawMode@zCRenderer@@UBE?AW4zTRnd_PolyDrawMode@@XZ
        vfunc f19_SetPolyDrawMode;               // from zCRenderer  ?SetPolyDrawMode@zCRenderer@@UAEXABW4zTRnd_PolyDrawMode@@@Z
        vfunc f20_GetSurfaceLost;                // from zCRenderer  ?GetSurfaceLost@zCRenderer@@UBEHXZ
        vfunc f21_SetSurfaceLost;                // from zCRenderer  ?SetSurfaceLost@zCRenderer@@UAEXH@Z
        vfunc f22_GetSyncOnAmbientCol;           // from zCRenderer  ?GetSyncOnAmbientCol@zCRenderer@@UBEHXZ
        vfunc f23_SetSyncOnAmbientCol;           // from zCRenderer  ?SetSyncOnAmbientCol@zCRenderer@@UAEXH@Z
        vfunc f24_SetTextureWrapEnabled;         // from zCRenderer  ?SetTextureWrapEnabled@zCRenderer@@UAEXH@Z
        vfunc f25_GetTextureWrapEnabled;         // from zCRenderer  ?GetTextureWrapEnabled@zCRenderer@@UBEHXZ
        vfunc f26_SetBilerpFilterEnabled;        // from base        purecall
        vfunc f27_GetBilerpFilterEnabled;        // from base        purecall
        vfunc f28_SetDitherEnabled;              // from zCRenderer  ?SetDitherEnabled@zCRenderer@@UAEXH@Z
        vfunc f29_GetDitherEnabled;              // from zCRenderer  ?GetDitherEnabled@zCRenderer@@UBEHXZ
        vfunc f30_GetPolySortMode;               // from zCRenderer  ?GetPolySortMode@zCRenderer@@UBE?AW4zTRnd_PolySortMode@@XZ
        vfunc f31_SetPolySortMode;               // from zCRenderer  ?SetPolySortMode@zCRenderer@@UAEXABW4zTRnd_PolySortMode@@@Z
        vfunc f32_GetZBufferWriteEnabled;        // from zCRenderer  ?GetZBufferWriteEnabled@zCRenderer@@UBEHXZ
        vfunc f33_SetZBufferWriteEnabled;        // from zCRenderer  ?SetZBufferWriteEnabled@zCRenderer@@UAEXH@Z
        vfunc f34_SetZBias;                      // from zCRenderer  ?SetZBias@zCRenderer@@UAEXH@Z
        vfunc f35_GetZBias;                      // from zCRenderer  ?GetZBias@zCRenderer@@UBEHXZ
        vfunc f36_GetZBufferCompare;             // from zCRenderer  ?GetZBufferCompare@zCRenderer@@UAE?AW4zTRnd_ZBufferCmp@@XZ
        vfunc f37_SetZBufferCompare;             // from zCRenderer  ?SetZBufferCompare@zCRenderer@@UAEXABW4zTRnd_ZBufferCmp@@@Z
        vfunc f38_GetPixelWriteEnabled;          // from zCRenderer  ?GetPixelWriteEnabled@zCRenderer@@UBEHXZ
        vfunc f39_SetPixelWriteEnabled;          // from zCRenderer  ?SetPixelWriteEnabled@zCRenderer@@UAEXH@Z
        vfunc f40_SetAlphaBlendSource;           // from zCRenderer  ?SetAlphaBlendSource@zCRenderer@@UAEXABW4zTRnd_AlphaBlendSource@@@Z
        vfunc f41_GetAlphaBlendSource;           // from zCRenderer  ?GetAlphaBlendSource@zCRenderer@@UBE?AW4zTRnd_AlphaBlendSource@@XZ
        vfunc f42_SetAlphaBlendFunc;             // from zCRenderer  ?SetAlphaBlendFunc@zCRenderer@@UAEXABW4zTRnd_AlphaBlendFunc@@@Z
        vfunc f43_GetAlphaBlendFunc;             // from zCRenderer  ?GetAlphaBlendFunc@zCRenderer@@UBE?AW4zTRnd_AlphaBlendFunc@@XZ
        vfunc f44_GetAlphaBlendFactor;           // from zCRenderer  ?GetAlphaBlendFactor@zCRenderer@@UBEMXZ
        vfunc f45_SetAlphaBlendFactor;           // from zCRenderer  ?SetAlphaBlendFactor@zCRenderer@@UAEXABM@Z
        vfunc f46_SetAlphaReference;             // from zCRenderer  ?SetAlphaReference@zCRenderer@@UAEXK@Z
        vfunc f47_GetAlphaReference;             // from zCRenderer  ?GetAlphaReference@zCRenderer@@UBEKXZ
        vfunc f48_GetCacheAlphaPolys;            // from zCRenderer  ?GetCacheAlphaPolys@zCRenderer@@UBEHXZ
        vfunc f49_SetCacheAlphaPolys;            // from zCRenderer  ?SetCacheAlphaPolys@zCRenderer@@UAEXH@Z
        vfunc f50_GetAlphaLimitReached;          // from zCRenderer  ?GetAlphaLimitReached@zCRenderer@@UBEHXZ
        vfunc f51_AddAlphaPoly;                  // from zCRenderer  ?AddAlphaPoly@zCRenderer@@UAEXPBVzCPolygon@@@Z
        vfunc f52_FlushAlphaPolys;               // from zCRenderer  ?FlushAlphaPolys@zCRenderer@@UAEXXZ
        vfunc f53_SetRenderMode;                 // from zCRenderer  ?SetRenderMode@zCRenderer@@UAEXW4zTRnd_RenderMode@@@Z
        vfunc f54_GetRenderMode;                 // from zCRenderer  ?GetRenderMode@zCRenderer@@UBE?AW4zTRnd_RenderMode@@XZ
        vfunc f55_HasCapability;                 // from zCRenderer  ?HasCapability@zCRenderer@@UBEHW4zTRnd_Capability@@@Z
        vfunc f56_GetGuardBandBorders;           // from zCRenderer  ?GetGuardBandBorders@zCRenderer@@UAEXAAM000@Z
        vfunc f57_ResetZTest;                    // from zCRenderer  ?ResetZTest@zCRenderer@@UAEXXZ
        vfunc f58_HasPassedZTest;                // from zCRenderer  ?HasPassedZTest@zCRenderer@@UAEHXZ
        vfunc f59_CreateTexture;                 // from base        purecall
        vfunc f60_CreateTextureConvert;          // from zCRenderer  ?CreateTextureConvert@zCRenderer@@UAEPAVzCTextureConvert@@XZ
        vfunc f61_GetTotalTextureMem;            // from base        purecall
        vfunc f62_SupportsTextureFormat;         // from zCRenderer  ?SupportsTextureFormat@zCRenderer@@UAEHW4zTRnd_TextureFormat@@@Z
        vfunc f63_SupportsTextureFormatHardware; // from zCRenderer  ?SupportsTextureFormatHardware@zCRenderer@@UAEHW4zTRnd_TextureFormat@@@Z
        vfunc f64_GetMaxTextureSize;             // from zCRenderer  ?GetMaxTextureSize@zCRenderer@@UAEHXZ
        vfunc f65_GetStatistics;                 // from base        purecall
        vfunc f66_ResetStatistics;               // from base        purecall
        vfunc f67_Vid_Blit;                      // from base        purecall
        vfunc f68_Vid_Clear;                     // from base        purecall
        vfunc f69_Vid_Lock;                      // from base        purecall
        vfunc f70_Vid_Unlock;                    // from base        purecall
        vfunc f71_Vid_IsLocked;                  // from base        purecall
        vfunc f72_Vid_GetFrontBufferCopy;        // from base        purecall
        vfunc f73_Vid_GetNumDevices;             // from base        purecall
        vfunc f74_Vid_GetActiveDeviceNr;         // from base        purecall
        vfunc f75_Vid_SetDevice;                 // from base        purecall
        vfunc f76_Vid_GetDeviceInfo;             // from base        purecall
        vfunc f77_Vid_GetNumModes;               // from base        purecall
        vfunc f78_Vid_GetModeInfo;               // from base        purecall
        vfunc f79_Vid_GetActiveModeNr;           // from base        purecall
        vfunc f80_Vid_SetMode;                   // from base        purecall
        vfunc f81_Vid_SetScreenMode;             // from base        purecall
        vfunc f82_Vid_GetScreenMode;             // from base        purecall
        vfunc f83_Vid_SetGammaCorrection;        // from base        purecall
        vfunc f84_Vid_GetGammaCorrection;        // from base        purecall
        vfunc f85_Vid_BeginLfbAccess;            // from base        purecall
        vfunc f86_Vid_EndLfbAccess;              // from base        purecall
        vfunc f87_Vid_SetLfbAlpha;               // from base        purecall
        vfunc f88_Vid_SetLfbAlphaFunc;           // from base        purecall
        vfunc f89_SetTransform;                  // from zCRenderer  ?SetTransform@zCRenderer@@UAEHW4zTRnd_TrafoType@@ABVzMAT4@@@Z
        vfunc f90_SetViewport;                   // from zCRenderer  ?SetViewport@zCRenderer@@UAEHHHHH@Z
        vfunc f91_SetLight;                      // from zCRenderer  ?SetLight@zCRenderer@@UAEHKPAVzCRenderLight@@@Z
        vfunc f92_GetMaterial;                   // from zCRenderer  ?GetMaterial@zCRenderer@@UAEHAAUzTMaterial@1@@Z
        vfunc f93_SetMaterial;                   // from zCRenderer  ?SetMaterial@zCRenderer@@UAEHABUzTMaterial@1@@Z
        vfunc f94_SetTexture;                    // from zCRenderer  ?SetTexture@zCRenderer@@UAEHKPAVzCTexture@@@Z
        vfunc f95_SetTextureStageState;          // from zCRenderer  ?SetTextureStageState@zCRenderer@@UAEHKW4zTRnd_TextureStageState@@K@Z
        vfunc f96_SetAlphaBlendFuncImmed;        // from zCRenderer  ?SetAlphaBlendFuncImmed@zCRenderer@@UAEHW4zTRnd_AlphaBlendFunc@@@Z
        vfunc f97_SetRenderState;                // from zCRenderer  ?SetRenderState@zCRenderer@@UAEHW4zTRnd_RenderStateType@@K@Z
        vfunc f98_GetRenderState;                // from zCRenderer  ?GetRenderState@zCRenderer@@UAEKW4zTRnd_RenderStateType@@@Z
        vfunc f99_AddAlphaSortObject;            // from zCRenderer  ?AddAlphaSortObject@zCRenderer@@UAEXPAVzCRndAlphaSortObject@@@Z
        vfunc f100_RenderAlphaSortList;          // from zCRenderer  ?RenderAlphaSortList@zCRenderer@@UAEXXZ
        vfunc f101_DrawVertexBuffer;             // from base        purecall
        vfunc f102_CreateVertexBuffer;           // from base        purecall
      } names;
    };

    static uint GetAddress() {
      return 0x0083B264;
    }

    static uint GetFuncsNum() {
      return 103;
    }

    static vftable_zCRenderer& GetTable() {
      MemUnlock;
      return *(vftable_zCRenderer*)GetAddress();
    }
  };


  struct vftable_zD3D_alphaPoly {
    union {
      vfunc array[3];
      group {
        vfunc f00_scalar_destructor; // from base            
        vfunc f01_Draw;              // from zD3D_alphaPoly  ?Draw@zD3D_alphaPoly@@UAEXH@Z
        vfunc f02_IsAlphaPoly;       // from zD3D_alphaPoly  ?IsAlphaPoly@zD3D_alphaPoly@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B404;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_zD3D_alphaPoly& GetTable() {
      MemUnlock;
      return *(vftable_zD3D_alphaPoly*)GetAddress();
    }
  };


  struct vftable_zCTex_D3D_for_zCTextureExchange {
    union {
      vfunc array[11];
      group {
        vfunc f00_vector_destructor; // from base               
        vfunc f01_Lock;              // from zCTex_D3D          ?Lock@zCTex_D3D@@UAEHH@Z
        vfunc f02_Unlock;            // from zCTex_D3D          ?Unlock@zCTex_D3D@@UAEHXZ
        vfunc f03_SetTextureInfo;    // from zCTex_D3D          ?SetTextureInfo@zCTex_D3D@@UAEHABVzCTextureInfo@@@Z
        vfunc f04_GetPaletteBuffer;  // from zCTex_D3D          ?GetPaletteBuffer@zCTex_D3D@@UAEPAXXZ
        vfunc f05_GetTextureBuffer;  // from zCTex_D3D          ?GetTextureBuffer@zCTex_D3D@@UAEHHAAPAXAAH@Z
        vfunc f06_GetTextureInfo;    // from zCTex_D3D          ?GetTextureInfo@zCTex_D3D@@UAE?AVzCTextureInfo@@XZ
        vfunc f07_CopyPaletteDataTo; // from zCTex_D3D          ?CopyPaletteDataTo@zCTex_D3D@@UAEHPAX@Z
        vfunc f08_CopyTextureDataTo; // from zCTex_D3D          ?CopyTextureDataTo@zCTex_D3D@@UAEHHPAXH@Z
        vfunc f09_HasAlpha;          // from zCTexture          ?HasAlpha@zCTexture@@UAEHXZ
        vfunc f10_GetRGBAAtTexel;    // from zCTextureExchange  ?GetRGBAAtTexel@zCTextureExchange@@UAE?AVzVEC4@@MM@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B454;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTex_D3D_for_zCTextureExchange& GetTable() {
      MemUnlock;
      return *(vftable_zCTex_D3D_for_zCTextureExchange*)GetAddress();
    }
  };


  struct vftable_zCTex_D3D_for_zCResource {
    union {
      vfunc array[11];
      group {
        vfunc f00_GetClassDef;            // from zCTexture  ?_GetClassDef@zCTexture@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                // from zCObject   ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;              // from zCObject   ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;      // from base       
        vfunc f04_LoadResourceData;       // from zCTexture  ?LoadResourceData@zCTexture@@UAEHXZ
        vfunc f05_ReleaseResourceData;    // from zCTexture  ?ReleaseResourceData@zCTexture@@UAEHXZ
        vfunc f06_GetResSizeBytes;        // from zCTexture  ?GetResSizeBytes@zCTexture@@UAEKXZ
        vfunc f07_GetCacheConfig;         // from zCTexture  ?GetCacheConfig@zCTexture@@UAEXAAK0@Z
        vfunc f08_GetChromaKeyingEnabled; // from zCTexture  ?GetChromaKeyingEnabled@zCTexture@@UBEHXZ
        vfunc f09_SetChromaKeyingEnabled; // from zCTexture  ?SetChromaKeyingEnabled@zCTexture@@UAEXH@Z
        vfunc f10_ReleaseData;            // from zCTex_D3D  ?ReleaseData@zCTex_D3D@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B484;
    }

    static uint GetFuncsNum() {
      return 11;
    }

    static vftable_zCTex_D3D_for_zCResource& GetTable() {
      MemUnlock;
      return *(vftable_zCTex_D3D_for_zCResource*)GetAddress();
    }
  };


  struct vftable_zCVertexBuffer_D3D {
    union {
      vfunc array[18];
      group {
        vfunc f00_GetClassDef;       // from zCVertexBuffer      ?_GetClassDef@zCVertexBuffer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject            ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject            ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base                
        vfunc f04_Create;            // from zCVertexBuffer_D3D  ?Create@zCVertexBuffer_D3D@@UAEHKKK@Z
        vfunc f05_Destroy;           // from zCVertexBuffer_D3D  ?Destroy@zCVertexBuffer_D3D@@UAEHXZ
        vfunc f06_Lock;              // from zCVertexBuffer_D3D  ?Lock@zCVertexBuffer_D3D@@UAEHK@Z
        vfunc f07_Unlock;            // from zCVertexBuffer_D3D  ?Unlock@zCVertexBuffer_D3D@@UAEHXZ
        vfunc f08_IsLocked;          // from zCVertexBuffer_D3D  ?IsLocked@zCVertexBuffer_D3D@@UAEHXZ
        vfunc f09_Optimize;          // from zCVertexBuffer_D3D  ?Optimize@zCVertexBuffer_D3D@@UAEHXZ
        vfunc f10_SetPrimitiveType;  // from zCVertexBuffer_D3D  ?SetPrimitiveType@zCVertexBuffer_D3D@@UAEHW4zTVBufferPrimitiveType@@@Z
        vfunc f11_GetPrimitiveType;  // from zCVertexBuffer_D3D  ?GetPrimitiveType@zCVertexBuffer_D3D@@UAE?AW4zTVBufferPrimitiveType@@XZ
        vfunc f12_GetVertexFormat;   // from zCVertexBuffer_D3D  ?GetVertexFormat@zCVertexBuffer_D3D@@UAEKXZ
        vfunc f13_GetVertexType;     // from zCVertexBuffer_D3D  ?GetVertexType@zCVertexBuffer_D3D@@UAE?AW4zTVBufferVertexType@@XZ
        vfunc f14_SetIndexList;      // from zCVertexBuffer_D3D  ?SetIndexList@zCVertexBuffer_D3D@@UAEHABV?$zCArray@G@@@Z
        vfunc f15_SetIndexListSize;  // from zCVertexBuffer_D3D  ?SetIndexListSize@zCVertexBuffer_D3D@@UAEHK@Z
        vfunc f16_GetIndexListSize;  // from zCVertexBuffer_D3D  ?GetIndexListSize@zCVertexBuffer_D3D@@UAEKXZ
        vfunc f17_GetIndexListPtr;   // from zCVertexBuffer_D3D  ?GetIndexListPtr@zCVertexBuffer_D3D@@UAEPAGXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B4CC;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_zCVertexBuffer_D3D& GetTable() {
      MemUnlock;
      return *(vftable_zCVertexBuffer_D3D*)GetAddress();
    }
  };


  struct vftable_zCTexConGeneric {
    union {
      vfunc array[13];
      group {
        vfunc f00_scalar_destructor;    // from base               
        vfunc f01_Lock;                 // from zCTexConGeneric    ?Lock@zCTexConGeneric@@UAEHH@Z
        vfunc f02_Unlock;               // from zCTexConGeneric    ?Unlock@zCTexConGeneric@@UAEHXZ
        vfunc f03_SetTextureInfo;       // from zCTexConGeneric    ?SetTextureInfo@zCTexConGeneric@@UAEHABVzCTextureInfo@@@Z
        vfunc f04_GetPaletteBuffer;     // from zCTexConGeneric    ?GetPaletteBuffer@zCTexConGeneric@@UAEPAXXZ
        vfunc f05_GetTextureBuffer;     // from zCTexConGeneric    ?GetTextureBuffer@zCTexConGeneric@@UAEHHAAPAXAAH@Z
        vfunc f06_GetTextureInfo;       // from zCTexConGeneric    ?GetTextureInfo@zCTexConGeneric@@UAE?AVzCTextureInfo@@XZ
        vfunc f07_CopyPaletteDataTo;    // from zCTexConGeneric    ?CopyPaletteDataTo@zCTexConGeneric@@UAEHPAX@Z
        vfunc f08_CopyTextureDataTo;    // from zCTexConGeneric    ?CopyTextureDataTo@zCTexConGeneric@@UAEHHPAXH@Z
        vfunc f09_HasAlpha;             // from zCTexConGeneric    ?HasAlpha@zCTexConGeneric@@UAEHXZ
        vfunc f10_GetRGBAAtTexel;       // from zCTextureExchange  ?GetRGBAAtTexel@zCTextureExchange@@UAE?AVzVEC4@@MM@Z
        vfunc f11_ConvertTextureFormat; // from zCTexConGeneric    ?ConvertTextureFormat@zCTexConGeneric@@UAEHABVzCTextureInfo@@@Z
        vfunc f12_SetDetailTextureMode; // from zCTexConGeneric    ?SetDetailTextureMode@zCTexConGeneric@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B544;
    }

    static uint GetFuncsNum() {
      return 13;
    }

    static vftable_zCTexConGeneric& GetTable() {
      MemUnlock;
      return *(vftable_zCTexConGeneric*)GetAddress();
    }
  };


  struct vftable_oCCollObjectCharacter {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetCollObjClass;           // from oCCollObjectCharacter  ?GetCollObjClass@oCCollObjectCharacter@@UBEPAVzCCollisionObjectDef@@XZ
        vfunc f01_scalar_destructor;         // from base                   
        vfunc f02_DetectCollisionsSelf;      // from zCCollObjectCharacter  ?DetectCollisionsSelf@zCCollObjectCharacter@@UAIXABV?$zCArray@PAVzCCollisionObject@@@@AAV?$zCArray@PAVzCCollisionReport@@@@@Z
        vfunc f03_CollisionResponse;         // from zCCollObjectCharacter  ?CollisionResponse@zCCollObjectCharacter@@UAIXABV?$zCArray@PAVzCCollisionReport@@@@AAH@Z
        vfunc f04_GetAdaptiveStepSize;       // from zCCollObjectCharacter  ?GetAdaptiveStepSize@zCCollObjectCharacter@@UAIMXZ
        vfunc f05_SuppressCollisionResponse; // from zCCollisionObject      ?SuppressCollisionResponse@zCCollisionObject@@UAIHXZ
        vfunc f06_GetLargestBBox3DLocal;     // from zCCollObjectCharacter  ?GetLargestBBox3DLocal@zCCollObjectCharacter@@UAIXAAUzTBBox3D@@@Z
        vfunc f07_GetPrimitiveCC;            // from oCCollObjectCharacter  ?GetPrimitiveCC@oCCollObjectCharacter@@UBEPAVzCConvexPrimitive@@XZ
        vfunc f08_IsDead;                    // from oCCollObjectCharacter  ?IsDead@oCCollObjectCharacter@@MBEHXZ
        vfunc f09_DontLetHimComeNearer;      // from oCCollObjectCharacter  ?DontLetHimComeNearer@oCCollObjectCharacter@@MBEHPBVzCVob@@@Z
        vfunc f10_TurnSpeed;                 // from oCCollObjectCharacter  ?TurnSpeed@oCCollObjectCharacter@@MBEMXZ
        vfunc f11_PushAround;                // from oCCollObjectCharacter  ?PushAround@oCCollObjectCharacter@@MAEXABVzVEC3@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B5A8;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCCollObjectCharacter& GetTable() {
      MemUnlock;
      return *(vftable_oCCollObjectCharacter*)GetAddress();
    }
  };


  struct vftable_oCDocumentManager {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCDocumentManager  ?HandleEvent@oCDocumentManager@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B69C;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCDocumentManager& GetTable() {
      MemUnlock;
      return *(vftable_oCDocumentManager*)GetAddress();
    }
  };


  struct vftable_oCViewDialogInventory {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCViewDialogInventory  ?HandleEvent@oCViewDialogInventory@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B74C;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDialogInventory& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogInventory*)GetAddress();
    }
  };


  struct vftable_oCViewDialogInventory_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B754;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDialogInventory_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogInventory_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDialogInventory_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from oCViewDialogInventory  ?_GetClassDef@oCViewDialogInventory@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject               ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject               ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                   
        vfunc f04_EvaluateTexturePosition; // from zCViewFX               ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw             ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint            ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint            ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint            ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint            ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog           ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from oCViewDialogInventory  ?Activate@oCViewDialogInventory@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog           ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from oCViewDialogInventory  ?StartSelection@oCViewDialogInventory@@UAIXXZ
        vfunc f14_StopSelection;           // from oCViewDialogInventory  ?StopSelection@oCViewDialogInventory@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B77C;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCViewDialogInventory_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogInventory_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItem {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B7D0;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDialogItem& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItem*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItem_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B7D8;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDialogItem_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItem_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItem_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from oCViewDialogItem  ?_GetClassDef@oCViewDialogItem@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject          ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject          ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base              
        vfunc f04_EvaluateTexturePosition; // from zCViewFX          ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw        ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from oCViewDialogItem  ?Blit@oCViewDialogItem@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint       ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint       ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint       ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog      ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog      ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog      ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from zCViewDialog      ?StartSelection@zCViewDialog@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialog      ?StopSelection@zCViewDialog@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B804;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCViewDialogItem_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItem_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItemContainer {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCViewDialogItemContainer  ?HandleEvent@oCViewDialogItemContainer@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B858;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDialogItemContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItemContainer*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItemContainer_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B860;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDialogItemContainer_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItemContainer_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDialogItemContainer_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from oCViewDialogItemContainer  ?_GetClassDef@oCViewDialogItemContainer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject                   ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject                   ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_vector_destructor;       // from base                       
        vfunc f04_EvaluateTexturePosition; // from zCViewFX                   ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw                 ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint                ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint                ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint                ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint                ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog               ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from oCViewDialogItemContainer  ?Activate@oCViewDialogItemContainer@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog               ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from oCViewDialogItemContainer  ?StartSelection@oCViewDialogItemContainer@@UAIXXZ
        vfunc f14_StopSelection;           // from oCViewDialogItemContainer  ?StopSelection@oCViewDialogItemContainer@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B88C;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCViewDialogItemContainer_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogItemContainer_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDialogStealContainer {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCViewDialogStealContainer  ?HandleEvent@oCViewDialogStealContainer@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B8E4;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDialogStealContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogStealContainer*)GetAddress();
    }
  };


  struct vftable_oCViewDialogStealContainer_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B8EC;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDialogStealContainer_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogStealContainer_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDialogStealContainer_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from oCViewDialogStealContainer  ?_GetClassDef@oCViewDialogStealContainer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject                    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject                    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                        
        vfunc f04_EvaluateTexturePosition; // from zCViewFX                    ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw                  ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint                 ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint                 ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint                 ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint                 ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog                ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from oCViewDialogStealContainer  ?Activate@oCViewDialogStealContainer@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog                ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from oCViewDialogStealContainer  ?StartSelection@oCViewDialogStealContainer@@UAIXXZ
        vfunc f14_StopSelection;           // from oCViewDialogStealContainer  ?StopSelection@oCViewDialogStealContainer@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083B914;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCViewDialogStealContainer_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogStealContainer_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDialogTrade {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCViewDialogTrade  ?HandleEvent@oCViewDialogTrade@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B970;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDialogTrade& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogTrade*)GetAddress();
    }
  };


  struct vftable_oCViewDialogTrade_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B978;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDialogTrade_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogTrade_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDialogTrade_for_zCObject {
    union {
      vfunc array[18];
      group {
        vfunc f00_GetClassDef;             // from oCViewDialogTrade  ?_GetClassDef@oCViewDialogTrade@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject           ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject           ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_EvaluateTexturePosition; // from zCViewFX           ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw         ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint        ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint        ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint        ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint        ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog       ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog       ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog       ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from oCViewDialogTrade  ?StartSelection@oCViewDialogTrade@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialog       ?StopSelection@zCViewDialog@@UAIXXZ
        vfunc f15_GetTransferCount;        // from oCViewDialogTrade  ?GetTransferCount@oCViewDialogTrade@@UAEFXZ
        vfunc f16_SetTransferCount;        // from oCViewDialogTrade  ?SetTransferCount@oCViewDialogTrade@@UAEXF@Z
        vfunc f17_IncTransferCount;        // from oCViewDialogTrade  ?IncTransferCount@oCViewDialogTrade@@UAEXF@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083B9A4;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCViewDialogTrade_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDialogTrade_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDocument {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BA08;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDocument& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocument*)GetAddress();
    }
  };


  struct vftable_oCViewDocument_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BA10;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDocument_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocument_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDocument_for_zCObject {
    union {
      vfunc array[16];
      group {
        vfunc f00_GetClassDef;             // from zCViewDialog    ?_GetClassDef@zCViewDialog@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject        ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject        ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base            
        vfunc f04_EvaluateTexturePosition; // from zCViewFX        ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw      ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint     ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint     ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint     ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint     ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog    ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog    ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog    ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from zCViewDialog    ?StartSelection@zCViewDialog@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialog    ?StopSelection@zCViewDialog@@UAIXXZ
        vfunc f15_SetPage;                 // from oCViewDocument  ?SetPage@oCViewDocument@@UAIPAV1@HAAVzSTRING@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BA3C;
    }

    static uint GetFuncsNum() {
      return 16;
    }

    static vftable_oCViewDocument_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocument_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCViewDocumentMap {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BA9C;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewDocumentMap& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocumentMap*)GetAddress();
    }
  };


  struct vftable_oCViewDocumentMap_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BAA4;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_oCViewDocumentMap_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocumentMap_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCViewDocumentMap_for_zCObject {
    union {
      vfunc array[16];
      group {
        vfunc f00_GetClassDef;             // from zCViewDialog       ?_GetClassDef@zCViewDialog@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject           ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject           ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base               
        vfunc f04_EvaluateTexturePosition; // from zCViewFX           ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw         ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint        ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint        ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint        ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint        ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog       ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog       ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog       ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from zCViewDialog       ?StartSelection@zCViewDialog@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialog       ?StopSelection@zCViewDialog@@UAIXXZ
        vfunc f15_SetPage;                 // from oCViewDocumentMap  ?SetPage@oCViewDocumentMap@@UAIPAVoCViewDocument@@HAAVzSTRING@@H@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BACC;
    }

    static uint GetFuncsNum() {
      return 16;
    }

    static vftable_oCViewDocumentMap_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_oCViewDocumentMap_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewBase  ?anx@zCViewBase@@UAEHH@Z
        vfunc f01_any;         // from zCViewBase  ?any@zCViewBase@@UAEHH@Z
        vfunc f02_nax;         // from zCViewBase  ?nax@zCViewBase@@UAEHH@Z
        vfunc f03_nay;         // from zCViewBase  ?nay@zCViewBase@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewBase  ?ClipLine@zCViewBase@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewBase  ?Line@zCViewBase@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewBase  ?GetViewport@zCViewBase@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase  ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewBase  ?GetCode@zCViewBase@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BB48;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewDialog_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BB84;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewDialog_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialog_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewDialog_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from zCViewDialog  ?_GetClassDef@zCViewDialog@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject      ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject      ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base          
        vfunc f04_EvaluateTexturePosition; // from zCViewFX      ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw    ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint   ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint   ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint   ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint   ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog  ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog  ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog  ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from zCViewDialog  ?StartSelection@zCViewDialog@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialog  ?StopSelection@zCViewDialog@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BBAC;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_zCViewDialog_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialog_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewDialog {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BBEC;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewDialog& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialog*)GetAddress();
    }
  };


  struct vftable_zCViewDialogChoice {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCViewDialogChoice  ?HandleEvent@zCViewDialogChoice@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BC08;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewDialogChoice& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialogChoice*)GetAddress();
    }
  };


  struct vftable_zCViewDialogChoice_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BC10;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewDialogChoice_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialogChoice_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewDialogChoice_for_zCObject {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;             // from zCViewDialogChoice  ?_GetClassDef@zCViewDialogChoice@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject            ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject            ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                
        vfunc f04_EvaluateTexturePosition; // from zCViewFX            ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw          ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint         ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewDialogChoice  ?BlitText@zCViewDialogChoice@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint         ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint         ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
        vfunc f10_IsActive;                // from zCViewDialog        ?IsActive@zCViewDialog@@UAIHXZ
        vfunc f11_Activate;                // from zCViewDialog        ?Activate@zCViewDialog@@UAIXH@Z
        vfunc f12_HasFinished;             // from zCViewDialog        ?HasFinished@zCViewDialog@@UAIHXZ
        vfunc f13_StartSelection;          // from zCViewDialogChoice  ?StartSelection@zCViewDialogChoice@@UAIXXZ
        vfunc f14_StopSelection;           // from zCViewDialogChoice  ?StopSelection@zCViewDialogChoice@@UAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BC3C;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_zCViewDialogChoice_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDialogChoice_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewDraw_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BC90;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewDraw_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDraw_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewDraw_for_zCObject {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetClassDef;             // from zCViewDraw  ?_GetClassDef@zCViewDraw@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_EvaluateTexturePosition; // from zCViewDraw  ?EvaluateTexturePosition@zCViewDraw@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw  ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewDraw  ?Blit@zCViewDraw@@MAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BCB8;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCViewDraw_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewDraw_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewFX_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BCEC;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewFX_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewFX_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewFX_for_zCObject {
    union {
      vfunc array[7];
      group {
        vfunc f00_GetClassDef;             // from zCViewFX    ?_GetClassDef@zCViewFX@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base        
        vfunc f04_EvaluateTexturePosition; // from zCViewFX    ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw  ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewFX    ?Blit@zCViewFX@@MAIXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BD14;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCViewFX_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewFX_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewObject_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BD48;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewObject_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewObject_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewObject_for_zCObject {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCViewObject  ?_GetClassDef@zCViewObject@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCObject      ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCObject      ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base          
      } names;
    };

    static uint GetAddress() {
      return 0x0083BD70;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCViewObject_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewObject_for_zCObject*)GetAddress();
    }
  };


  struct vftable_zCViewPrint_for_zCViewBase {
    union {
      vfunc array[9];
      group {
        vfunc f00_anx;         // from zCViewObject  ?anx@zCViewObject@@UAEHH@Z
        vfunc f01_any;         // from zCViewObject  ?any@zCViewObject@@UAEHH@Z
        vfunc f02_nax;         // from zCViewObject  ?nax@zCViewObject@@UAEHH@Z
        vfunc f03_nay;         // from zCViewObject  ?nay@zCViewObject@@UAEHH@Z
        vfunc f04_ClipLine;    // from zCViewObject  ?ClipLine@zCViewObject@@UAEHAAH000@Z
        vfunc f05_Line;        // from zCViewObject  ?Line@zCViewObject@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport; // from zCViewObject  ?GetViewport@zCViewObject@@UAIXAAH000@Z
        vfunc f07_FillZBuffer; // from zCViewBase    ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;     // from zCViewObject  ?GetCode@zCViewObject@@MAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BD98;
    }

    static uint GetFuncsNum() {
      return 9;
    }

    static vftable_zCViewPrint_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCViewPrint_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewPrint_for_zCObject {
    union {
      vfunc array[10];
      group {
        vfunc f00_GetClassDef;             // from zCViewPrint  ?_GetClassDef@zCViewPrint@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCObject     ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCObject     ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base         
        vfunc f04_EvaluateTexturePosition; // from zCViewFX     ?EvaluateTexturePosition@zCViewFX@@MAIXXZ
        vfunc f05_BlitTexture;             // from zCViewDraw   ?BlitTexture@zCViewDraw@@MAIXXZ
        vfunc f06_Blit;                    // from zCViewPrint  ?Blit@zCViewPrint@@MAIXXZ
        vfunc f07_BlitText;                // from zCViewPrint  ?BlitText@zCViewPrint@@MAIXXZ
        vfunc f08_BlitTextLine;            // from zCViewPrint  ?BlitTextLine@zCViewPrint@@MAIXPAVzCViewText2@@@Z
        vfunc f09_BlitTextCharacters;      // from zCViewPrint  ?BlitTextCharacters@zCViewPrint@@MAIXPAVzCViewText2@@PAVzCFont@@AAUzCOLOR@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BDC0;
    }

    static uint GetFuncsNum() {
      return 10;
    }

    static vftable_zCViewPrint_for_zCObject& GetTable() {
      MemUnlock;
      return *(vftable_zCViewPrint_for_zCObject*)GetAddress();
    }
  };


  struct vftable_oCAIHuman {
    union {
      vfunc array[18];
      group {
        vfunc f00_GetClassDef;                     // from oCAIHuman        ?_GetClassDef@oCAIHuman@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIHuman        ?Archive@oCAIHuman@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIHuman        ?Unarchive@oCAIHuman@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base             
        vfunc f04_DoAI;                            // from oCAIHuman        ?DoAI@oCAIHuman@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from oCAIHuman        ?CanThisCollideWith@oCAIHuman@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase         ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase         ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase         ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIPlayer       ?HostVobRemovedFromWorld@zCAIPlayer@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase         ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase         ?GetIsProjectile@zCAIBase@@UAEHXZ
        vfunc f12_StartStandAni;                   // from oCAniCtrl_Human  ?StartStandAni@oCAniCtrl_Human@@UAEXXZ
        vfunc f13_StartFallDownAni;                // from oCAniCtrl_Human  ?StartFallDownAni@oCAniCtrl_Human@@UAEXXZ
        vfunc f14_Init;                            // from oCAIHuman        ?Init@oCAIHuman@@UAEXPAVoCNpc@@@Z
        vfunc f15_AddIgnoreCD;                     // from oCAIHuman        ?AddIgnoreCD@oCAIHuman@@UAEXPAVzCVob@@@Z
        vfunc f16_SubIgnoreCD;                     // from oCAIHuman        ?SubIgnoreCD@oCAIHuman@@UAEXPAVzCVob@@@Z
        vfunc f17_DoHackSpecials;                  // from oCAIHuman        ?DoHackSpecials@oCAIHuman@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BE2C;
    }

    static uint GetFuncsNum() {
      return 18;
    }

    static vftable_oCAIHuman& GetTable() {
      MemUnlock;
      return *(vftable_oCAIHuman*)GetAddress();
    }
  };


  struct vftable_oCAICamera {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAICamera  ?_GetClassDef@oCAICamera@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject    ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject    ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base        
        vfunc f04_DoAI;                            // from oCAICamera  ?DoAI@oCAICamera@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase    ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase    ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from oCAICamera  ?HasAIDetectedCollision@oCAICamera@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase    ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase    ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase    ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase    ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BE7C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAICamera& GetTable() {
      MemUnlock;
      return *(vftable_oCAICamera*)GetAddress();
    }
  };


  struct vftable_oCAIHuman_Stand {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAIHuman_Stand  ?_GetClassDef@oCAIHuman_Stand@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject         ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject         ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base             
        vfunc f04_DoAI;                            // from oCAIHuman_Stand  ?DoAI@oCAIHuman_Stand@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase         ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase         ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase         ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase         ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase         ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase         ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase         ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BEB0;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAIHuman_Stand& GetTable() {
      MemUnlock;
      return *(vftable_oCAIHuman_Stand*)GetAddress();
    }
  };


  struct vftable_oCAIVobMove {
    union {
      vfunc array[13];
      group {
        vfunc f00_GetClassDef;                     // from oCAIVobMove  ?_GetClassDef@oCAIVobMove@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIVobMove  ?Archive@oCAIVobMove@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIVobMove  ?Unarchive@oCAIVobMove@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base         
        vfunc f04_DoAI;                            // from oCAIVobMove  ?DoAI@oCAIVobMove@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from oCAIVobMove  ?CanThisCollideWith@oCAIVobMove@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCAIVobMove  ?ReportCollisionToAI@oCAIVobMove@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase     ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase     ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase     ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase     ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase     ?GetIsProjectile@zCAIBase@@UAEHXZ
        vfunc f12_Init;                            // from oCAIVobMove  ?Init@oCAIVobMove@@UAEXPAVzCVob@@0AAVzVEC3@@MMPAVzMAT4@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BF00;
    }

    static uint GetFuncsNum() {
      return 13;
    }

    static vftable_oCAIVobMove& GetTable() {
      MemUnlock;
      return *(vftable_oCAIVobMove*)GetAddress();
    }
  };


  struct vftable_oCAISound {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAISound  ?_GetClassDef@oCAISound@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject   ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject   ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base       
        vfunc f04_DoAI;                            // from base       purecall
        vfunc f05_CanThisCollideWith;              // from zCAIBase   ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase   ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase   ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase   ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase   ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase   ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase   ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BF38;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAISound& GetTable() {
      MemUnlock;
      return *(vftable_oCAISound*)GetAddress();
    }
  };


  struct vftable_oCAIVobMoveTorch {
    union {
      vfunc array[13];
      group {
        vfunc f00_GetClassDef;                     // from oCAIVobMoveTorch  ?_GetClassDef@oCAIVobMoveTorch@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIVobMove       ?Archive@oCAIVobMove@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIVobMove       ?Unarchive@oCAIVobMove@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base              
        vfunc f04_DoAI;                            // from oCAIVobMoveTorch  ?DoAI@oCAIVobMoveTorch@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from oCAIVobMove       ?CanThisCollideWith@oCAIVobMove@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCAIVobMove       ?ReportCollisionToAI@oCAIVobMove@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase          ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase          ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase          ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase          ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase          ?GetIsProjectile@zCAIBase@@UAEHXZ
        vfunc f12_Init;                            // from oCAIVobMoveTorch  ?Init@oCAIVobMoveTorch@@UAEXPAVzCVob@@0AAVzVEC3@@MMPAVzMAT4@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083BF6C;
    }

    static uint GetFuncsNum() {
      return 13;
    }

    static vftable_oCAIVobMoveTorch& GetTable() {
      MemUnlock;
      return *(vftable_oCAIVobMoveTorch*)GetAddress();
    }
  };


  struct vftable_oCAIArrowBase {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAIArrowBase  ?_GetClassDef@oCAIArrowBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIArrowBase  ?Archive@oCAIArrowBase@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIArrowBase  ?Unarchive@oCAIArrowBase@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base           
        vfunc f04_DoAI;                            // from oCAIArrowBase  ?DoAI@oCAIArrowBase@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase       ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCAIArrowBase  ?ReportCollisionToAI@oCAIArrowBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from oCAIArrowBase  ?HasAIDetectedCollision@oCAIArrowBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from oCAIArrowBase  ?AICollisionResponseSelfDetected@oCAIArrowBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase       ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase       ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from oCAIArrowBase  ?GetIsProjectile@oCAIArrowBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BFA4;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAIArrowBase& GetTable() {
      MemUnlock;
      return *(vftable_oCAIArrowBase*)GetAddress();
    }
  };


  struct vftable_oCAIArrow {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAIArrow      ?_GetClassDef@oCAIArrow@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIArrow      ?Archive@oCAIArrow@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIArrow      ?Unarchive@oCAIArrow@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base           
        vfunc f04_DoAI;                            // from oCAIArrow      ?DoAI@oCAIArrow@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from oCAIArrow      ?CanThisCollideWith@oCAIArrow@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCAIArrow      ?ReportCollisionToAI@oCAIArrow@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from oCAIArrowBase  ?HasAIDetectedCollision@oCAIArrowBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from oCAIArrowBase  ?AICollisionResponseSelfDetected@oCAIArrowBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase       ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase       ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from oCAIArrowBase  ?GetIsProjectile@oCAIArrowBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083BFDC;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAIArrow& GetTable() {
      MemUnlock;
      return *(vftable_oCAIArrow*)GetAddress();
    }
  };


  struct vftable_oCAIDrop {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from oCAIDrop  ?_GetClassDef@oCAIDrop@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAIDrop  ?Archive@oCAIDrop@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAIDrop  ?Unarchive@oCAIDrop@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base      
        vfunc f04_DoAI;                            // from oCAIDrop  ?DoAI@oCAIDrop@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from oCAIDrop  ?CanThisCollideWith@oCAIDrop@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from oCAIDrop  ?ReportCollisionToAI@oCAIDrop@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from oCAIDrop  ?HasAIDetectedCollision@oCAIDrop@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase  ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase  ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase  ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase  ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C010;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAIDrop& GetTable() {
      MemUnlock;
      return *(vftable_oCAIDrop*)GetAddress();
    }
  };


  struct vftable_oCAniCtrl_Human {
    union {
      vfunc array[15];
      group {
        vfunc f00_GetClassDef;                     // from oCAniCtrl_Human  ?_GetClassDef@oCAniCtrl_Human@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from oCAniCtrl_Human  ?Archive@oCAniCtrl_Human@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from oCAniCtrl_Human  ?Unarchive@oCAniCtrl_Human@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base             
        vfunc f04_DoAI;                            // from zCAIPlayer       ?DoAI@zCAIPlayer@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase         ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase         ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase         ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase         ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIPlayer       ?HostVobRemovedFromWorld@zCAIPlayer@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase         ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase         ?GetIsProjectile@zCAIBase@@UAEHXZ
        vfunc f12_StartStandAni;                   // from oCAniCtrl_Human  ?StartStandAni@oCAniCtrl_Human@@UAEXXZ
        vfunc f13_StartFallDownAni;                // from oCAniCtrl_Human  ?StartFallDownAni@oCAniCtrl_Human@@UAEXXZ
        vfunc f14_Init;                            // from oCAniCtrl_Human  ?Init@oCAniCtrl_Human@@UAEXPAVoCNpc@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C064;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCAniCtrl_Human& GetTable() {
      MemUnlock;
      return *(vftable_oCAniCtrl_Human*)GetAddress();
    }
  };


  struct vftable_oCSkyControler_Barrier {
    union {
      vfunc array[37];
      group {
        vfunc f00_GetClassDef;                   // from zCSkyControler_Outdoor  ?_GetClassDef@zCSkyControler_Outdoor@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                       // from zCSkyControler_Outdoor  ?Archive@zCSkyControler_Outdoor@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                     // from zCSkyControler_Outdoor  ?Unarchive@zCSkyControler_Outdoor@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;             // from base                    
        vfunc f04_SetTime;                       // from zCSkyControler_Outdoor  ?SetTime@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f05_GetTime;                       // from zCSkyControler_Outdoor  ?GetTime@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f06_ResetTime;                     // from zCSkyControler_Outdoor  ?ResetTime@zCSkyControler_Outdoor@@UAEXXZ
        vfunc f07_SetFarZ;                       // from zCSkyControler_Outdoor  ?SetFarZ@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f08_GetFarZ;                       // from zCSkyControler_Outdoor  ?GetFarZ@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f09_SetFarZScalability;            // from zCSkyControler_Outdoor  ?SetFarZScalability@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f10_GetFarZScalability;            // from zCSkyControler_Outdoor  ?GetFarZScalability@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f11_SetBackgroundColor;            // from zCSkyControler_Outdoor  ?SetBackgroundColor@zCSkyControler_Outdoor@@UAEXUzCOLOR@@@Z
        vfunc f12_GetBackgroundColor;            // from zCSkyControler_Outdoor  ?GetBackgroundColor@zCSkyControler_Outdoor@@UBE?AUzCOLOR@@XZ
        vfunc f13_GetBackgroundColorDef;         // from zCSkyControler_Outdoor  ?GetBackgroundColorDef@zCSkyControler_Outdoor@@UBE?AUzCOLOR@@XZ
        vfunc f14_SetOverrideColor;              // from zCSkyControler_Outdoor  ?SetOverrideColor@zCSkyControler_Outdoor@@UAEXVzVEC3@@@Z
        vfunc f15_SetOverrideColorFlag;          // from zCSkyControler_Outdoor  ?SetOverrideColorFlag@zCSkyControler_Outdoor@@UAEXH@Z
        vfunc f16_GetCloudShadowScale;           // from zCSkyControler_Outdoor  ?GetCloudShadowScale@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f17_SetCloudShadowScale;           // from zCSkyControler_Outdoor  ?SetCloudShadowScale@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f18_SetFillBackground;             // from zCSkyControler          ?SetFillBackground@zCSkyControler@@UAEXH@Z
        vfunc f19_GetFillBackground;             // from zCSkyControler          ?GetFillBackground@zCSkyControler@@UBEHXZ
        vfunc f20_SetUnderwaterFX;               // from zCSkyControler_Mid      ?SetUnderwaterFX@zCSkyControler_Mid@@UAEXH@Z
        vfunc f21_GetUnderwaterFX;               // from zCSkyControler_Mid      ?GetUnderwaterFX@zCSkyControler_Mid@@UBEHXZ
        vfunc f22_UpdateWorldDependencies;       // from zCSkyControler_Outdoor  ?UpdateWorldDependencies@zCSkyControler_Outdoor@@UAEXXZ
        vfunc f23_SetLightDirty;                 // from zCSkyControler          ?SetLightDirty@zCSkyControler@@UAEXXZ
        vfunc f24_SetRelightTime;                // from zCSkyControler          ?SetRelightTime@zCSkyControler@@UAEXM@Z
        vfunc f25_GetRelightCtr;                 // from zCSkyControler          ?GetRelightCtr@zCSkyControler@@UAEHXZ
        vfunc f26_GetDaylightColorFromIntensity; // from zCSkyControler_Outdoor  ?GetDaylightColorFromIntensity@zCSkyControler_Outdoor@@UAE?AUzCOLOR@@H@Z
        vfunc f27_RenderSkyPre;                  // from oCSkyControler_Barrier  ?RenderSkyPre@oCSkyControler_Barrier@@UAEXXZ
        vfunc f28_RenderSkyPost;                 // from zCSkyControler_Outdoor  ?RenderSkyPost@zCSkyControler_Outdoor@@UAEXH@Z
        vfunc f29_GetGlobalWindVec;              // from zCSkyControler_Outdoor  ?GetGlobalWindVec@zCSkyControler_Outdoor@@UAEHAAVzVEC3@@W4zTAnimationMode@@@Z
        vfunc f30_SetGlobalSkyScale;             // from zCSkyControler_Outdoor  ?SetGlobalSkyScale@zCSkyControler_Outdoor@@UAEXM@Z
        vfunc f31_GetGlobalSkyScale;             // from zCSkyControler_Outdoor  ?GetGlobalSkyScale@zCSkyControler_Outdoor@@UBEMXZ
        vfunc f32_GetGlobalSkyScaleChanged;      // from zCSkyControler_Outdoor  ?GetGlobalSkyScaleChanged@zCSkyControler_Outdoor@@UBEHXZ
        vfunc f33_SetCameraLocationHint;         // from zCSkyControler_Outdoor  ?SetCameraLocationHint@zCSkyControler_Outdoor@@UAEXW4zTCamLocationHint@zCSkyControler@@@Z
        vfunc f34_SetWeatherType;                // from zCSkyControler_Outdoor  ?SetWeatherType@zCSkyControler_Outdoor@@UAEXW4zTWeather@@@Z
        vfunc f35_GetWeatherType;                // from zCSkyControler          ?GetWeatherType@zCSkyControler@@UBE?AW4zTWeather@@XZ
        vfunc f36_GetRenderLightning;            // from zCSkyControler_Outdoor  ?GetRenderLightning@zCSkyControler_Outdoor@@UBEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C10C;
    }

    static uint GetFuncsNum() {
      return 37;
    }

    static vftable_oCSkyControler_Barrier& GetTable() {
      MemUnlock;
      return *(vftable_oCSkyControler_Barrier*)GetAddress();
    }
  };


  struct vftable_oCAskBox {
    union {
      vfunc array[12];
      group {
        vfunc f00_GetClassDef;                     // from zCAIBase  ?_GetClassDef@zCAIBase@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                         // from zCObject  ?Archive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                       // from zCObject  ?Unarchive@zCObject@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;               // from base      
        vfunc f04_DoAI;                            // from oCAskBox  ?DoAI@oCAskBox@@UAEXPAVzCVob@@AAH@Z
        vfunc f05_CanThisCollideWith;              // from zCAIBase  ?CanThisCollideWith@zCAIBase@@UAEHPAVzCVob@@@Z
        vfunc f06_ReportCollisionToAI;             // from zCAIBase  ?ReportCollisionToAI@zCAIBase@@UAEXABVzCCollisionReport@@@Z
        vfunc f07_HasAIDetectedCollision;          // from zCAIBase  ?HasAIDetectedCollision@zCAIBase@@UAEHXZ
        vfunc f08_AICollisionResponseSelfDetected; // from zCAIBase  ?AICollisionResponseSelfDetected@zCAIBase@@UAEXABVzVEC3@@AAH@Z
        vfunc f09_HostVobRemovedFromWorld;         // from zCAIBase  ?HostVobRemovedFromWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f10_HostVobAddedToWorld;             // from zCAIBase  ?HostVobAddedToWorld@zCAIBase@@UAEXPAVzCVob@@PAVzCWorld@@@Z
        vfunc f11_GetIsProjectile;                 // from zCAIBase  ?GetIsProjectile@zCAIBase@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C1C8;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCAskBox& GetTable() {
      MemUnlock;
      return *(vftable_oCAskBox*)GetAddress();
    }
  };


  struct vftable_oCDoc_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from oCDoc  ?HandleEvent@oCDoc@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C218;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCDoc_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_oCDoc_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_oCDoc_for_zCViewBase {
    union {
      vfunc array[12];
      group {
        vfunc f00_anx;               // from zCView      ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView      ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView      ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView      ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView      ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView      ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView      ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase  ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView      ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base        
        vfunc f10_Blit;              // from zCView      ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView      ?DrawItems@zCView@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C220;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_oCDoc_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCDoc_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCGame {
    union {
      vfunc array[53];
      group {
        vfunc f00_HandleEvent;            // from oCGame     ?HandleEvent@oCGame@@EAEHH@Z
        vfunc f01_scalar_destructor;      // from base       
        vfunc f02_Init;                   // from oCGame     ?Init@oCGame@@UAEXXZ
        vfunc f03_Done;                   // from oCGame     ?Done@oCGame@@UAEXXZ
        vfunc f04_Render;                 // from oCGame     ?Render@oCGame@@UAEXXZ
        vfunc f05_RenderBlit;             // from oCGame     ?RenderBlit@oCGame@@UAEXXZ
        vfunc f06_CamInit;                // from oCGame     ?CamInit@oCGame@@UAEXPAVzCVob@@PAVzCCamera@@@Z
        vfunc f07_CamInit;                // from oCGame     ?CamInit@oCGame@@UAEXXZ
        vfunc f08_SetCamera;              // from zCSession  ?SetCamera@zCSession@@UAEXPAVzCCamera@@@Z
        vfunc f09_GetCamera;              // from zCSession  ?GetCamera@zCSession@@UBEPAVzCCamera@@XZ
        vfunc f10_GetCameraAI;            // from zCSession  ?GetCameraAI@zCSession@@UBEPAVzCAICamera@@XZ
        vfunc f11_GetCameraVob;           // from zCSession  ?GetCameraVob@zCSession@@UBEPAVzCVob@@XZ
        vfunc f12_GetViewport;            // from zCSession  ?GetViewport@zCSession@@UBEPAVzCView@@XZ
        vfunc f13_GetWorld;               // from zCSession  ?GetWorld@zCSession@@UAEPAVzCWorld@@XZ
        vfunc f14_SaveWorld;              // from oCGame     ?SaveWorld@oCGame@@UAEXABVzSTRING@@W4zTWorldSaveMode@zCWorld@@HH@Z
        vfunc f15_LoadWorld;              // from oCGame     ?LoadWorld@oCGame@@UAEHABVzSTRING@@W4zTWorldLoadMode@zCWorld@@@Z
        vfunc f16_GetCutsceneManager;     // from zCSession  ?GetCutsceneManager@zCSession@@UAEPAVzCCSManager@@XZ
        vfunc f17_SetTime;                // from oCGame     ?SetTime@oCGame@@UAEXHHH@Z
        vfunc f18_GetTime;                // from oCGame     ?GetTime@oCGame@@UAEXAAH00@Z
        vfunc f19_SetWorld;               // from zCSession  ?SetWorld@zCSession@@MAEXPAVzCWorld@@@Z
        vfunc f20_DesktopInit;            // from oCGame     ?DesktopInit@oCGame@@EAEXXZ
        vfunc f21_CutsceneSystemInit;     // from zCSession  ?CutsceneSystemInit@zCSession@@MAEXXZ
        vfunc f22_EnterWorld;             // from oCGame     ?EnterWorld@oCGame@@UAEXPAVoCNpc@@HABVzSTRING@@@Z
        vfunc f23_Pause;                  // from oCGame     ?Pause@oCGame@@UAEXH@Z
        vfunc f24_Unpause;                // from oCGame     ?Unpause@oCGame@@UAEXXZ
        vfunc f25_SetDrawWaynet;          // from oCGame     ?SetDrawWaynet@oCGame@@UAEXH@Z
        vfunc f26_GetDrawWaynet;          // from oCGame     ?GetDrawWaynet@oCGame@@UAEHXZ
        vfunc f27_RenderWaynet;           // from oCGame     ?RenderWaynet@oCGame@@UAEXXZ
        vfunc f28_EnvironmentInit;        // from oCGame     ?EnvironmentInit@oCGame@@UAEXXZ
        vfunc f29_SetRanges;              // from oCGame     ?SetRanges@oCGame@@UAEXXZ
        vfunc f30_SetRangesByCommandLine; // from oCGame     ?SetRangesByCommandLine@oCGame@@UAEXXZ
        vfunc f31_GetStartPos;            // from oCGame     ?GetStartPos@oCGame@@UAE?AVzVEC3@@XZ
        vfunc f32_SetGameInfo;            // from oCGame     ?SetGameInfo@oCGame@@UAEXPAVoCGameInfo@@@Z
        vfunc f33_LoadParserFile;         // from oCGame     ?LoadParserFile@oCGame@@UAEHABVzSTRING@@@Z
        vfunc f34_TriggerChangeLevel;     // from oCGame     ?TriggerChangeLevel@oCGame@@UAEXABVzSTRING@@0@Z
        vfunc f35_GetGameWorld;           // from oCGame     ?GetGameWorld@oCGame@@UAEPAVoCWorld@@XZ
        vfunc f36_GetGameInfo;            // from oCGame     ?GetGameInfo@oCGame@@UAEPAVoCGameInfo@@XZ
        vfunc f37_GetTextView;            // from oCGame     ?GetTextView@oCGame@@UAEPAVzCView@@XZ
        vfunc f38_OpenLoadscreen;         // from oCGame     ?OpenLoadscreen@oCGame@@UAEX_NVzSTRING@@@Z
        vfunc f39_OpenSavescreen;         // from oCGame     ?OpenSavescreen@oCGame@@UAEX_N@Z
        vfunc f40_CloseLoadscreen;        // from oCGame     ?CloseLoadscreen@oCGame@@UAEXXZ
        vfunc f41_CloseSavescreen;        // from oCGame     ?CloseSavescreen@oCGame@@UAEXXZ
        vfunc f42_ChangeLevel;            // from oCGame     ?ChangeLevel@oCGame@@EAEXABVzSTRING@@0@Z
        vfunc f43_LoadWorldStartup;       // from oCGame     ?LoadWorldStartup@oCGame@@EAEXABVzSTRING@@@Z
        vfunc f44_LoadWorldStat;          // from oCGame     ?LoadWorldStat@oCGame@@EAEXVzSTRING@@@Z
        vfunc f45_LoadWorldDyn;           // from oCGame     ?LoadWorldDyn@oCGame@@EAEXABVzSTRING@@@Z
        vfunc f46_InitWorldSavegame;      // from oCGame     ?InitWorldSavegame@oCGame@@EAEXAAHAAVzSTRING@@@Z
        vfunc f47_CheckIfSavegameExists;  // from oCGame     ?CheckIfSavegameExists@oCGame@@EAEHABVzSTRING@@@Z
        vfunc f48_CompileWorld;           // from oCGame     ?CompileWorld@oCGame@@EAEXXZ
        vfunc f49_WorldInit;              // from oCGame     ?WorldInit@oCGame@@EAEXXZ
        vfunc f50_NpcInit;                // from oCGame     ?NpcInit@oCGame@@EAEXPAV?$zCTree@VzCVob@@@@@Z
        vfunc f51_NpcInit;                // from oCGame     ?NpcInit@oCGame@@EAEXXZ
        vfunc f52_SetAsPlayer;            // from oCGame     ?SetAsPlayer@oCGame@@EAEXABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C28C;
    }

    static uint GetFuncsNum() {
      return 53;
    }

    static vftable_oCGame& GetTable() {
      MemUnlock;
      return *(vftable_oCGame*)GetAddress();
    }
  };


  struct vftable_oCViewGothicProgressBar_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C364;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCViewGothicProgressBar_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_oCViewGothicProgressBar_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_oCViewGothicProgressBar_for_zCViewBase {
    union {
      vfunc array[15];
      group {
        vfunc f00_anx;               // from zCView                   ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView                   ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView                   ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView                   ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView                   ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView                   ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView                   ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase               ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView                   ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base                     
        vfunc f10_Blit;              // from zCView                   ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView                   ?DrawItems@zCView@@UAEXXZ
        vfunc f12_Init;              // from oCViewGothicProgressBar  ?Init@oCViewGothicProgressBar@@UAEXXZ
        vfunc f13_HandleChange;      // from oCViewGothicProgressBar  ?HandleChange@oCViewGothicProgressBar@@UAEXXZ
        vfunc f14_Draw;              // from zCViewProgressBar        ?Draw@zCViewProgressBar@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C36C;
    }

    static uint GetFuncsNum() {
      return 15;
    }

    static vftable_oCViewGothicProgressBar_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_oCViewGothicProgressBar_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_oCInfoManager {
    union {
      vfunc array[3];
      group {
        vfunc f00_Archive;                // from oCInfoManager  ?Archive@oCInfoManager@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive;              // from oCInfoManager  ?Unarchive@oCInfoManager@@UAEXAAVzCArchiver@@@Z
        vfunc f02_RestoreParserInstances; // from oCInfoManager  ?RestoreParserInstances@oCInfoManager@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C43C;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_oCInfoManager& GetTable() {
      MemUnlock;
      return *(vftable_oCInfoManager*)GetAddress();
    }
  };


  struct vftable_oCInfo {
    union {
      vfunc array[3];
      group {
        vfunc f00_Archive;               // from oCInfo  ?Archive@oCInfo@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive;             // from oCInfo  ?Unarchive@oCInfo@@UAEXAAVzCArchiver@@@Z
        vfunc f02_RestoreParserInstance; // from oCInfo  ?RestoreParserInstance@oCInfo@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C44C;
    }

    static uint GetFuncsNum() {
      return 3;
    }

    static vftable_oCInfo& GetTable() {
      MemUnlock;
      return *(vftable_oCInfo*)GetAddress();
    }
  };


  struct vftable_oCItemContainer {
    union {
      vfunc array[47];
      group {
        vfunc f00_HandleEvent;                    // from oCItemContainer  ?HandleEvent@oCItemContainer@@MAEHH@Z
        vfunc f01_scalar_destructor;              // from base             
        vfunc f02_Open;                           // from oCItemContainer  ?Open@oCItemContainer@@UAEXHHH@Z
        vfunc f03_OpenPassive;                    // from oCItemContainer  ?OpenPassive@oCItemContainer@@UAEXHHH@Z
        vfunc f04_GetName;                        // from oCItemContainer  ?GetName@oCItemContainer@@UAE?AVzSTRING@@XZ
        vfunc f05_SetName;                        // from oCItemContainer  ?SetName@oCItemContainer@@UAEXAAVzSTRING@@@Z
        vfunc f06_GetMode;                        // from oCItemContainer  ?GetMode@oCItemContainer@@UAEHXZ
        vfunc f07_SetMode;                        // from oCItemContainer  ?SetMode@oCItemContainer@@UAEXH@Z
        vfunc f08_Close;                          // from oCItemContainer  ?Close@oCItemContainer@@UAEXXZ
        vfunc f09_Activate;                       // from oCItemContainer  ?Activate@oCItemContainer@@UAEXXZ
        vfunc f10_Deactivate;                     // from oCItemContainer  ?Deactivate@oCItemContainer@@UAEXXZ
        vfunc f11_IsOpen;                         // from oCItemContainer  ?IsOpen@oCItemContainer@@UAEHXZ
        vfunc f12_IsActive;                       // from oCItemContainer  ?IsActive@oCItemContainer@@UAEHXZ
        vfunc f13_IsEmpty;                        // from oCItemContainer  ?IsEmpty@oCItemContainer@@UAEHXZ
        vfunc f14_IsSplitScreen;                  // from oCItemContainer  ?IsSplitScreen@oCItemContainer@@UAEHXZ
        vfunc f15_SetContents;                    // from oCItemContainer  ?SetContents@oCItemContainer@@UAEXPAV?$zCListSort@VoCItem@@@@@Z
        vfunc f16_GetContents;                    // from oCItemContainer  ?GetContents@oCItemContainer@@UAEPAV?$zCListSort@VoCItem@@@@XZ
        vfunc f17_Insert;                         // from oCItemContainer  ?Insert@oCItemContainer@@UAEPAVoCItem@@PAV2@@Z
        vfunc f18_Remove;                         // from oCItemContainer  ?Remove@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f19_Remove;                         // from oCItemContainer  ?Remove@oCItemContainer@@UAEXPAVoCItem@@@Z
        vfunc f20_RemoveByPtr;                    // from oCItemContainer  ?RemoveByPtr@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f21_GetSelectedItem;                // from oCItemContainer  ?GetSelectedItem@oCItemContainer@@UAEPAVoCItem@@XZ
        vfunc f22_GetSelectedItemCount;           // from oCItemContainer  ?GetSelectedItemCount@oCItemContainer@@UAEHXZ
        vfunc f23_GetSize;                        // from oCItemContainer  ?GetSize@oCItemContainer@@UAEXAAH0@Z
        vfunc f24_DisableManipulateItems;         // from oCItemContainer  ?DisableManipulateItems@oCItemContainer@@UAEXH@Z
        vfunc f25_CanManipulateItems;             // from oCItemContainer  ?CanManipulateItems@oCItemContainer@@UAEHXZ
        vfunc f26_DisableTransferMoreThanOneItem; // from oCItemContainer  ?DisableTransferMoreThanOneItem@oCItemContainer@@UAEXH@Z
        vfunc f27_CanTransferMoreThanOneItem;     // from oCItemContainer  ?CanTransferMoreThanOneItem@oCItemContainer@@UAEHXZ
        vfunc f28_IsPassive;                      // from oCItemContainer  ?IsPassive@oCItemContainer@@UAEHXZ
        vfunc f29_GetTransferCount;               // from oCItemContainer  ?GetTransferCount@oCItemContainer@@UAEFXZ
        vfunc f30_SetTransferCount;               // from oCItemContainer  ?SetTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f31_IncTransferCount;               // from oCItemContainer  ?IncTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f32_Archive;                        // from oCItemContainer  ?Archive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f33_Unarchive;                      // from oCItemContainer  ?Unarchive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f34_Init;                           // from oCItemContainer  ?Init@oCItemContainer@@MAEXHHH@Z
        vfunc f35_GetPosition;                    // from oCItemContainer  ?GetPosition@oCItemContainer@@MAEXAAH0@Z
        vfunc f36_LoadGrafix;                     // from oCItemContainer  ?LoadGrafix@oCItemContainer@@MAEXXZ
        vfunc f37_DeleteContents;                 // from oCItemContainer  ?DeleteContents@oCItemContainer@@MAEXXZ
        vfunc f38_NextItem;                       // from oCItemContainer  ?NextItem@oCItemContainer@@MAEXXZ
        vfunc f39_NextItemLine;                   // from oCItemContainer  ?NextItemLine@oCItemContainer@@MAEXXZ
        vfunc f40_PrevItem;                       // from oCItemContainer  ?PrevItem@oCItemContainer@@MAEXXZ
        vfunc f41_PrevItemLine;                   // from oCItemContainer  ?PrevItemLine@oCItemContainer@@MAEXXZ
        vfunc f42_CheckSelectedItem;              // from oCItemContainer  ?CheckSelectedItem@oCItemContainer@@MAEXXZ
        vfunc f43_TransferItem;                   // from oCItemContainer  ?TransferItem@oCItemContainer@@MAEHHH@Z
        vfunc f44_Draw;                           // from oCItemContainer  ?Draw@oCItemContainer@@MAEXXZ
        vfunc f45_DrawCategory;                   // from oCItemContainer  ?DrawCategory@oCItemContainer@@MAEXXZ
        vfunc f46_DrawItemInfo;                   // from oCItemContainer  ?DrawItemInfo@oCItemContainer@@MAEXPAVoCItem@@PAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C4AC;
    }

    static uint GetFuncsNum() {
      return 47;
    }

    static vftable_oCItemContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCItemContainer*)GetAddress();
    }
  };


  struct vftable_oCStealContainer {
    union {
      vfunc array[50];
      group {
        vfunc f00_HandleEvent;                    // from oCStealContainer  ?HandleEvent@oCStealContainer@@UAEHH@Z
        vfunc f01_scalar_destructor;              // from base              
        vfunc f02_Open;                           // from oCItemContainer   ?Open@oCItemContainer@@UAEXHHH@Z
        vfunc f03_OpenPassive;                    // from oCItemContainer   ?OpenPassive@oCItemContainer@@UAEXHHH@Z
        vfunc f04_GetName;                        // from oCItemContainer   ?GetName@oCItemContainer@@UAE?AVzSTRING@@XZ
        vfunc f05_SetName;                        // from oCItemContainer   ?SetName@oCItemContainer@@UAEXAAVzSTRING@@@Z
        vfunc f06_GetMode;                        // from oCItemContainer   ?GetMode@oCItemContainer@@UAEHXZ
        vfunc f07_SetMode;                        // from oCItemContainer   ?SetMode@oCItemContainer@@UAEXH@Z
        vfunc f08_Close;                          // from oCItemContainer   ?Close@oCItemContainer@@UAEXXZ
        vfunc f09_Activate;                       // from oCItemContainer   ?Activate@oCItemContainer@@UAEXXZ
        vfunc f10_Deactivate;                     // from oCItemContainer   ?Deactivate@oCItemContainer@@UAEXXZ
        vfunc f11_IsOpen;                         // from oCItemContainer   ?IsOpen@oCItemContainer@@UAEHXZ
        vfunc f12_IsActive;                       // from oCItemContainer   ?IsActive@oCItemContainer@@UAEHXZ
        vfunc f13_IsEmpty;                        // from oCItemContainer   ?IsEmpty@oCItemContainer@@UAEHXZ
        vfunc f14_IsSplitScreen;                  // from oCItemContainer   ?IsSplitScreen@oCItemContainer@@UAEHXZ
        vfunc f15_SetContents;                    // from oCItemContainer   ?SetContents@oCItemContainer@@UAEXPAV?$zCListSort@VoCItem@@@@@Z
        vfunc f16_GetContents;                    // from oCItemContainer   ?GetContents@oCItemContainer@@UAEPAV?$zCListSort@VoCItem@@@@XZ
        vfunc f17_Insert;                         // from oCItemContainer   ?Insert@oCItemContainer@@UAEPAVoCItem@@PAV2@@Z
        vfunc f18_Remove;                         // from oCItemContainer   ?Remove@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f19_Remove;                         // from oCItemContainer   ?Remove@oCItemContainer@@UAEXPAVoCItem@@@Z
        vfunc f20_RemoveByPtr;                    // from oCItemContainer   ?RemoveByPtr@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f21_GetSelectedItem;                // from oCItemContainer   ?GetSelectedItem@oCItemContainer@@UAEPAVoCItem@@XZ
        vfunc f22_GetSelectedItemCount;           // from oCItemContainer   ?GetSelectedItemCount@oCItemContainer@@UAEHXZ
        vfunc f23_GetSize;                        // from oCItemContainer   ?GetSize@oCItemContainer@@UAEXAAH0@Z
        vfunc f24_DisableManipulateItems;         // from oCItemContainer   ?DisableManipulateItems@oCItemContainer@@UAEXH@Z
        vfunc f25_CanManipulateItems;             // from oCItemContainer   ?CanManipulateItems@oCItemContainer@@UAEHXZ
        vfunc f26_DisableTransferMoreThanOneItem; // from oCItemContainer   ?DisableTransferMoreThanOneItem@oCItemContainer@@UAEXH@Z
        vfunc f27_CanTransferMoreThanOneItem;     // from oCItemContainer   ?CanTransferMoreThanOneItem@oCItemContainer@@UAEHXZ
        vfunc f28_IsPassive;                      // from oCItemContainer   ?IsPassive@oCItemContainer@@UAEHXZ
        vfunc f29_GetTransferCount;               // from oCItemContainer   ?GetTransferCount@oCItemContainer@@UAEFXZ
        vfunc f30_SetTransferCount;               // from oCItemContainer   ?SetTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f31_IncTransferCount;               // from oCItemContainer   ?IncTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f32_Archive;                        // from oCItemContainer   ?Archive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f33_Unarchive;                      // from oCItemContainer   ?Unarchive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f34_Init;                           // from oCItemContainer   ?Init@oCItemContainer@@MAEXHHH@Z
        vfunc f35_GetPosition;                    // from oCItemContainer   ?GetPosition@oCItemContainer@@MAEXAAH0@Z
        vfunc f36_LoadGrafix;                     // from oCItemContainer   ?LoadGrafix@oCItemContainer@@MAEXXZ
        vfunc f37_DeleteContents;                 // from oCItemContainer   ?DeleteContents@oCItemContainer@@MAEXXZ
        vfunc f38_NextItem;                       // from oCItemContainer   ?NextItem@oCItemContainer@@MAEXXZ
        vfunc f39_NextItemLine;                   // from oCItemContainer   ?NextItemLine@oCItemContainer@@MAEXXZ
        vfunc f40_PrevItem;                       // from oCItemContainer   ?PrevItem@oCItemContainer@@MAEXXZ
        vfunc f41_PrevItemLine;                   // from oCItemContainer   ?PrevItemLine@oCItemContainer@@MAEXXZ
        vfunc f42_CheckSelectedItem;              // from oCItemContainer   ?CheckSelectedItem@oCItemContainer@@MAEXXZ
        vfunc f43_TransferItem;                   // from oCItemContainer   ?TransferItem@oCItemContainer@@MAEHHH@Z
        vfunc f44_Draw;                           // from oCItemContainer   ?Draw@oCItemContainer@@MAEXXZ
        vfunc f45_DrawCategory;                   // from oCItemContainer   ?DrawCategory@oCItemContainer@@MAEXXZ
        vfunc f46_DrawItemInfo;                   // from oCItemContainer   ?DrawItemInfo@oCItemContainer@@MAEXPAVoCItem@@PAVzCWorld@@@Z
        vfunc f47_SetOwner;                       // from oCStealContainer  ?SetOwner@oCStealContainer@@UAEXPAVoCNpc@@@Z
        vfunc f48_GetOwner;                       // from oCStealContainer  ?GetOwner@oCStealContainer@@UAEPAVoCNpc@@XZ
        vfunc f49_CreateList;                     // from oCStealContainer  ?CreateList@oCStealContainer@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C574;
    }

    static uint GetFuncsNum() {
      return 50;
    }

    static vftable_oCStealContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCStealContainer*)GetAddress();
    }
  };


  struct vftable_oCNpcContainer {
    union {
      vfunc array[50];
      group {
        vfunc f00_HandleEvent;                    // from oCNpcContainer    ?HandleEvent@oCNpcContainer@@UAEHH@Z
        vfunc f01_scalar_destructor;              // from base              
        vfunc f02_Open;                           // from oCItemContainer   ?Open@oCItemContainer@@UAEXHHH@Z
        vfunc f03_OpenPassive;                    // from oCItemContainer   ?OpenPassive@oCItemContainer@@UAEXHHH@Z
        vfunc f04_GetName;                        // from oCItemContainer   ?GetName@oCItemContainer@@UAE?AVzSTRING@@XZ
        vfunc f05_SetName;                        // from oCItemContainer   ?SetName@oCItemContainer@@UAEXAAVzSTRING@@@Z
        vfunc f06_GetMode;                        // from oCItemContainer   ?GetMode@oCItemContainer@@UAEHXZ
        vfunc f07_SetMode;                        // from oCItemContainer   ?SetMode@oCItemContainer@@UAEXH@Z
        vfunc f08_Close;                          // from oCItemContainer   ?Close@oCItemContainer@@UAEXXZ
        vfunc f09_Activate;                       // from oCItemContainer   ?Activate@oCItemContainer@@UAEXXZ
        vfunc f10_Deactivate;                     // from oCItemContainer   ?Deactivate@oCItemContainer@@UAEXXZ
        vfunc f11_IsOpen;                         // from oCItemContainer   ?IsOpen@oCItemContainer@@UAEHXZ
        vfunc f12_IsActive;                       // from oCItemContainer   ?IsActive@oCItemContainer@@UAEHXZ
        vfunc f13_IsEmpty;                        // from oCItemContainer   ?IsEmpty@oCItemContainer@@UAEHXZ
        vfunc f14_IsSplitScreen;                  // from oCItemContainer   ?IsSplitScreen@oCItemContainer@@UAEHXZ
        vfunc f15_SetContents;                    // from oCItemContainer   ?SetContents@oCItemContainer@@UAEXPAV?$zCListSort@VoCItem@@@@@Z
        vfunc f16_GetContents;                    // from oCItemContainer   ?GetContents@oCItemContainer@@UAEPAV?$zCListSort@VoCItem@@@@XZ
        vfunc f17_Insert;                         // from oCNpcContainer    ?Insert@oCNpcContainer@@UAEPAVoCItem@@PAV2@@Z
        vfunc f18_Remove;                         // from oCItemContainer   ?Remove@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f19_Remove;                         // from oCNpcContainer    ?Remove@oCNpcContainer@@UAEXPAVoCItem@@@Z
        vfunc f20_RemoveByPtr;                    // from oCItemContainer   ?RemoveByPtr@oCItemContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f21_GetSelectedItem;                // from oCItemContainer   ?GetSelectedItem@oCItemContainer@@UAEPAVoCItem@@XZ
        vfunc f22_GetSelectedItemCount;           // from oCItemContainer   ?GetSelectedItemCount@oCItemContainer@@UAEHXZ
        vfunc f23_GetSize;                        // from oCItemContainer   ?GetSize@oCItemContainer@@UAEXAAH0@Z
        vfunc f24_DisableManipulateItems;         // from oCItemContainer   ?DisableManipulateItems@oCItemContainer@@UAEXH@Z
        vfunc f25_CanManipulateItems;             // from oCItemContainer   ?CanManipulateItems@oCItemContainer@@UAEHXZ
        vfunc f26_DisableTransferMoreThanOneItem; // from oCItemContainer   ?DisableTransferMoreThanOneItem@oCItemContainer@@UAEXH@Z
        vfunc f27_CanTransferMoreThanOneItem;     // from oCItemContainer   ?CanTransferMoreThanOneItem@oCItemContainer@@UAEHXZ
        vfunc f28_IsPassive;                      // from oCItemContainer   ?IsPassive@oCItemContainer@@UAEHXZ
        vfunc f29_GetTransferCount;               // from oCItemContainer   ?GetTransferCount@oCItemContainer@@UAEFXZ
        vfunc f30_SetTransferCount;               // from oCItemContainer   ?SetTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f31_IncTransferCount;               // from oCItemContainer   ?IncTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f32_Archive;                        // from oCItemContainer   ?Archive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f33_Unarchive;                      // from oCItemContainer   ?Unarchive@oCItemContainer@@UAEXAAVzCArchiver@@@Z
        vfunc f34_Init;                           // from oCItemContainer   ?Init@oCItemContainer@@MAEXHHH@Z
        vfunc f35_GetPosition;                    // from oCItemContainer   ?GetPosition@oCItemContainer@@MAEXAAH0@Z
        vfunc f36_LoadGrafix;                     // from oCItemContainer   ?LoadGrafix@oCItemContainer@@MAEXXZ
        vfunc f37_DeleteContents;                 // from oCItemContainer   ?DeleteContents@oCItemContainer@@MAEXXZ
        vfunc f38_NextItem;                       // from oCItemContainer   ?NextItem@oCItemContainer@@MAEXXZ
        vfunc f39_NextItemLine;                   // from oCItemContainer   ?NextItemLine@oCItemContainer@@MAEXXZ
        vfunc f40_PrevItem;                       // from oCItemContainer   ?PrevItem@oCItemContainer@@MAEXXZ
        vfunc f41_PrevItemLine;                   // from oCItemContainer   ?PrevItemLine@oCItemContainer@@MAEXXZ
        vfunc f42_CheckSelectedItem;              // from oCItemContainer   ?CheckSelectedItem@oCItemContainer@@MAEXXZ
        vfunc f43_TransferItem;                   // from oCItemContainer   ?TransferItem@oCItemContainer@@MAEHHH@Z
        vfunc f44_Draw;                           // from oCItemContainer   ?Draw@oCItemContainer@@MAEXXZ
        vfunc f45_DrawCategory;                   // from oCItemContainer   ?DrawCategory@oCItemContainer@@MAEXXZ
        vfunc f46_DrawItemInfo;                   // from oCItemContainer   ?DrawItemInfo@oCItemContainer@@MAEXPAVoCItem@@PAVzCWorld@@@Z
        vfunc f47_SetOwner;                       // from oCStealContainer  ?SetOwner@oCStealContainer@@UAEXPAVoCNpc@@@Z
        vfunc f48_GetOwner;                       // from oCStealContainer  ?GetOwner@oCStealContainer@@UAEPAVoCNpc@@XZ
        vfunc f49_CreateList;                     // from oCNpcContainer    ?CreateList@oCNpcContainer@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C644;
    }

    static uint GetFuncsNum() {
      return 50;
    }

    static vftable_oCNpcContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCNpcContainer*)GetAddress();
    }
  };


  struct vftable_oCNpcInventory {
    union {
      vfunc array[53];
      group {
        vfunc f00_HandleEvent;                    // from oCNpcInventory   ?HandleEvent@oCNpcInventory@@UAEHH@Z
        vfunc f01_scalar_destructor;              // from base             
        vfunc f02_Open;                           // from oCNpcInventory   ?Open@oCNpcInventory@@UAEXHHH@Z
        vfunc f03_OpenPassive;                    // from oCItemContainer  ?OpenPassive@oCItemContainer@@UAEXHHH@Z
        vfunc f04_GetName;                        // from oCItemContainer  ?GetName@oCItemContainer@@UAE?AVzSTRING@@XZ
        vfunc f05_SetName;                        // from oCItemContainer  ?SetName@oCItemContainer@@UAEXAAVzSTRING@@@Z
        vfunc f06_GetMode;                        // from oCItemContainer  ?GetMode@oCItemContainer@@UAEHXZ
        vfunc f07_SetMode;                        // from oCItemContainer  ?SetMode@oCItemContainer@@UAEXH@Z
        vfunc f08_Close;                          // from oCNpcInventory   ?Close@oCNpcInventory@@UAEXXZ
        vfunc f09_Activate;                       // from oCItemContainer  ?Activate@oCItemContainer@@UAEXXZ
        vfunc f10_Deactivate;                     // from oCItemContainer  ?Deactivate@oCItemContainer@@UAEXXZ
        vfunc f11_IsOpen;                         // from oCItemContainer  ?IsOpen@oCItemContainer@@UAEHXZ
        vfunc f12_IsActive;                       // from oCItemContainer  ?IsActive@oCItemContainer@@UAEHXZ
        vfunc f13_IsEmpty;                        // from oCItemContainer  ?IsEmpty@oCItemContainer@@UAEHXZ
        vfunc f14_IsSplitScreen;                  // from oCItemContainer  ?IsSplitScreen@oCItemContainer@@UAEHXZ
        vfunc f15_SetContents;                    // from oCItemContainer  ?SetContents@oCItemContainer@@UAEXPAV?$zCListSort@VoCItem@@@@@Z
        vfunc f16_GetContents;                    // from oCItemContainer  ?GetContents@oCItemContainer@@UAEPAV?$zCListSort@VoCItem@@@@XZ
        vfunc f17_Insert;                         // from oCNpcInventory   ?Insert@oCNpcInventory@@UAEPAVoCItem@@PAV2@@Z
        vfunc f18_Remove;                         // from oCNpcInventory   ?Remove@oCNpcInventory@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f19_Remove;                         // from oCNpcInventory   ?Remove@oCNpcInventory@@UAEXPAVoCItem@@@Z
        vfunc f20_RemoveByPtr;                    // from oCNpcInventory   ?RemoveByPtr@oCNpcInventory@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f21_GetSelectedItem;                // from oCItemContainer  ?GetSelectedItem@oCItemContainer@@UAEPAVoCItem@@XZ
        vfunc f22_GetSelectedItemCount;           // from oCItemContainer  ?GetSelectedItemCount@oCItemContainer@@UAEHXZ
        vfunc f23_GetSize;                        // from oCItemContainer  ?GetSize@oCItemContainer@@UAEXAAH0@Z
        vfunc f24_DisableManipulateItems;         // from oCItemContainer  ?DisableManipulateItems@oCItemContainer@@UAEXH@Z
        vfunc f25_CanManipulateItems;             // from oCItemContainer  ?CanManipulateItems@oCItemContainer@@UAEHXZ
        vfunc f26_DisableTransferMoreThanOneItem; // from oCItemContainer  ?DisableTransferMoreThanOneItem@oCItemContainer@@UAEXH@Z
        vfunc f27_CanTransferMoreThanOneItem;     // from oCItemContainer  ?CanTransferMoreThanOneItem@oCItemContainer@@UAEHXZ
        vfunc f28_IsPassive;                      // from oCItemContainer  ?IsPassive@oCItemContainer@@UAEHXZ
        vfunc f29_GetTransferCount;               // from oCItemContainer  ?GetTransferCount@oCItemContainer@@UAEFXZ
        vfunc f30_SetTransferCount;               // from oCItemContainer  ?SetTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f31_IncTransferCount;               // from oCItemContainer  ?IncTransferCount@oCItemContainer@@UAEXF@Z
        vfunc f32_Archive;                        // from oCNpcInventory   ?Archive@oCNpcInventory@@UAEXAAVzCArchiver@@@Z
        vfunc f33_Unarchive;                      // from oCNpcInventory   ?Unarchive@oCNpcInventory@@UAEXAAVzCArchiver@@@Z
        vfunc f34_Init;                           // from oCItemContainer  ?Init@oCItemContainer@@MAEXHHH@Z
        vfunc f35_GetPosition;                    // from oCItemContainer  ?GetPosition@oCItemContainer@@MAEXAAH0@Z
        vfunc f36_LoadGrafix;                     // from oCItemContainer  ?LoadGrafix@oCItemContainer@@MAEXXZ
        vfunc f37_DeleteContents;                 // from oCItemContainer  ?DeleteContents@oCItemContainer@@MAEXXZ
        vfunc f38_NextItem;                       // from oCItemContainer  ?NextItem@oCItemContainer@@MAEXXZ
        vfunc f39_NextItemLine;                   // from oCItemContainer  ?NextItemLine@oCItemContainer@@MAEXXZ
        vfunc f40_PrevItem;                       // from oCItemContainer  ?PrevItem@oCItemContainer@@MAEXXZ
        vfunc f41_PrevItemLine;                   // from oCItemContainer  ?PrevItemLine@oCItemContainer@@MAEXXZ
        vfunc f42_CheckSelectedItem;              // from oCItemContainer  ?CheckSelectedItem@oCItemContainer@@MAEXXZ
        vfunc f43_TransferItem;                   // from oCItemContainer  ?TransferItem@oCItemContainer@@MAEHHH@Z
        vfunc f44_Draw;                           // from oCNpcInventory   ?Draw@oCNpcInventory@@MAEXXZ
        vfunc f45_DrawCategory;                   // from oCNpcInventory   ?DrawCategory@oCNpcInventory@@MAEXXZ
        vfunc f46_DrawItemInfo;                   // from oCItemContainer  ?DrawItemInfo@oCItemContainer@@MAEXPAVoCItem@@PAVzCWorld@@@Z
        vfunc f47_Remove;                         // from oCNpcInventory   ?Remove@oCNpcInventory@@UAEPAVoCItem@@ABVzSTRING@@H@Z
        vfunc f48_Remove;                         // from oCNpcInventory   ?Remove@oCNpcInventory@@UAEPAVoCItem@@HH@Z
        vfunc f49_IsIn;                           // from oCNpcInventory   ?IsIn@oCNpcInventory@@UAEPAVoCItem@@ABVzSTRING@@H@Z
        vfunc f50_IsIn;                           // from oCNpcInventory   ?IsIn@oCNpcInventory@@UAEPAVoCItem@@HH@Z
        vfunc f51_IsIn;                           // from oCNpcInventory   ?IsIn@oCNpcInventory@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f52_IsEmpty;                        // from oCNpcInventory   ?IsEmpty@oCNpcInventory@@UAEHHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C714;
    }

    static uint GetFuncsNum() {
      return 53;
    }

    static vftable_oCNpcInventory& GetTable() {
      MemUnlock;
      return *(vftable_oCNpcInventory*)GetAddress();
    }
  };


  struct vftable_oCItem {
    union {
      vfunc array[39];
      group {
        vfunc f00_GetClassDef;             // from oCItem  ?_GetClassDef@oCItem@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCItem  ?Archive@oCItem@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCItem  ?Unarchive@oCItem@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base    
        vfunc f04_OnTrigger;               // from zCVob   ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob   ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob   ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob   ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob   ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob   ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob   ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob   ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob   ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob   ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob   ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob   ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob   ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob   ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from oCItem  ?Render@oCItem@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob   ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from oCItem  ?SetVisual@oCItem@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from oCItem  ?GetScriptInstance@oCItem@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from oCItem  ?SetByScriptInstance@oCItem@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from oCVob   ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob   ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob   ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from oCItem  ?ThisVobAddedToWorld@oCItem@@MAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from oCItem  ?ThisVobRemovedFromWorld@oCItem@@MAEXPAVzCWorld@@@Z
        vfunc f28_Init;                    // from oCItem  ?Init@oCItem@@UAEXXZ
        vfunc f29_ShowDebugInfo;           // from oCVob   ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;             // from oCItem  ?GetInstance@oCItem@@UAEHXZ
        vfunc f31_GetInstanceName;         // from oCItem  ?GetInstanceName@oCItem@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;          // from oCItem  ?IsOwnedByGuild@oCItem@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;            // from oCItem  ?IsOwnedByNpc@oCItem@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;        // from oCVob   ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;            // from oCItem  ?GetAIVobMove@oCItem@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;     // from oCItem  ?GetSoundMaterial_AM@oCItem@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;        // from oCVob   ?SetSoundMaterial@oCVob@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;        // from oCItem  ?GetSoundMaterial@oCItem@@UAE?AW4oTSndMaterial@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083C804;
    }

    static uint GetFuncsNum() {
      return 39;
    }

    static vftable_oCItem& GetTable() {
      MemUnlock;
      return *(vftable_oCItem*)GetAddress();
    }
  };


  struct vftable_oCMissionManager {
    union {
      vfunc array[2];
      group {
        vfunc f00_Archive;   // from oCMissionManager  ?Archive@oCMissionManager@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive; // from oCMissionManager  ?Unarchive@oCMissionManager@@UAEXAAVzCArchiver@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C8E0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_oCMissionManager& GetTable() {
      MemUnlock;
      return *(vftable_oCMissionManager*)GetAddress();
    }
  };


  struct vftable_oCMission {
    union {
      vfunc array[2];
      group {
        vfunc f00_Archive;   // from oCMission  ?Archive@oCMission@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive; // from oCMission  ?Unarchive@oCMission@@UAEPAV1@AAVzCArchiver@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C8EC;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_oCMission& GetTable() {
      MemUnlock;
      return *(vftable_oCMission*)GetAddress();
    }
  };


  struct vftable_oCMobBed {
    union {
      vfunc array[72];
      group {
        vfunc f00_GetClassDef;              // from oCMobBed    ?_GetClassDef@oCMobBed@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobInter  ?Archive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobInter  ?Unarchive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base        
        vfunc f04_OnTrigger;                // from oCMobInter  ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter  ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter  ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter  ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter  ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB       ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob       ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter  ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob       ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter  ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob       ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob       ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob       ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob       ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB       ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB       ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob       ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob       ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB       ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB       ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB       ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB       ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB       ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB       ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobBed    ?GetScemeName@oCMobBed@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB       ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB       ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter  ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter  ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter  ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter  ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter  ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter  ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter  ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobInter  ?Interact@oCMobInter@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter  ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter  ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter  ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobInter  ?CanInteractWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter  ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter  ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter  ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter  ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter  ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobBed    ?StartInteraction@oCMobBed@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter  ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter  ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter  ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter  ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobBed    ?OnBeginStateChange@oCMobBed@@MAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobBed    ?OnEndStateChange@oCMobBed@@MAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter  ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter  ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobBed    ?SearchFreePosition@oCMobBed@@MAEPAUTMobOptPos@@PAVoCNpc@@M@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083C914;
    }

    static uint GetFuncsNum() {
      return 72;
    }

    static vftable_oCMobBed& GetTable() {
      MemUnlock;
      return *(vftable_oCMobBed*)GetAddress();
    }
  };


  struct vftable_oCMobSwitch {
    union {
      vfunc array[72];
      group {
        vfunc f00_GetClassDef;              // from oCMobSwitch  ?_GetClassDef@oCMobSwitch@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobSwitch  ?Archive@oCMobSwitch@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobSwitch  ?Unarchive@oCMobSwitch@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base         
        vfunc f04_OnTrigger;                // from oCMobInter   ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter   ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob        ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob        ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob        ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter   ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter   ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter   ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob        ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob        ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob        ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob        ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob        ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB        ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob        ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob        ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter   ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob        ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob        ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob        ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob        ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter   ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob        ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob        ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob        ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob        ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob        ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob        ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB        ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB        ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob        ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob        ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB        ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB        ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB        ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB        ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB        ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB        ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter   ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB        ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB        ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter   ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter   ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter   ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter   ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter   ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter   ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter   ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobInter   ?Interact@oCMobInter@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter   ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter   ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter   ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobInter   ?CanInteractWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter   ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter   ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter   ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter   ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter   ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter   ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter   ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter   ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter   ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter   ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter   ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobInter   ?OnEndStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter   ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter   ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter   ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083CA3C;
    }

    static uint GetFuncsNum() {
      return 72;
    }

    static vftable_oCMobSwitch& GetTable() {
      MemUnlock;
      return *(vftable_oCMobSwitch*)GetAddress();
    }
  };


  struct vftable_oCMobContainer {
    union {
      vfunc array[84];
      group {
        vfunc f00_GetClassDef;              // from oCMobContainer  ?_GetClassDef@oCMobContainer@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobContainer  ?Archive@oCMobContainer@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobContainer  ?Unarchive@oCMobContainer@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base            
        vfunc f04_OnTrigger;                // from oCMobInter      ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter      ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob           ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob           ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob           ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter      ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobContainer  ?OnMessage@oCMobContainer@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter      ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob           ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob           ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob           ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob           ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob           ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB           ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob           ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob           ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter      ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob           ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob           ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob           ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob           ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter      ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob           ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob           ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob           ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob           ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob           ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob           ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB           ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB           ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob           ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob           ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB           ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB           ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB           ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB           ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB           ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB           ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter      ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMobContainer  ?Destroy@oCMobContainer@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB           ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter      ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter      ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter      ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter      ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter      ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter      ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobContainer  ?Reset@oCMobContainer@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobLockable   ?Interact@oCMobLockable@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter      ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter      ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter      ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobLockable   ?CanInteractWith@oCMobLockable@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter      ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter      ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter      ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobContainer  ?IsIn@oCMobContainer@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter      ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter      ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter      ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter      ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobLockable   ?CanChangeState@oCMobLockable@@MAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter      ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter      ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobLockable   ?OnEndStateChange@oCMobLockable@@MAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter      ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter      ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter      ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
        vfunc f72_SetLocked;                // from oCMobLockable   ?SetLocked@oCMobLockable@@UAEXH@Z
        vfunc f73_SetKeyInstance;           // from oCMobLockable   ?SetKeyInstance@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f74_SetPickLockStr;           // from oCMobLockable   ?SetPickLockStr@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f75_Open;                     // from oCMobContainer  ?Open@oCMobContainer@@MAEXPAVoCNpc@@@Z
        vfunc f76_Close;                    // from oCMobContainer  ?Close@oCMobContainer@@UAEXPAVoCNpc@@@Z
        vfunc f77_Lock;                     // from oCMobLockable   ?Lock@oCMobLockable@@MAEXPAVoCNpc@@@Z
        vfunc f78_Unlock;                   // from oCMobLockable   ?Unlock@oCMobLockable@@MAEXPAVoCNpc@@H@Z
        vfunc f79_PickLock;                 // from oCMobLockable   ?PickLock@oCMobLockable@@MAEHPAVoCNpc@@D@Z
        vfunc f80_Insert;                   // from oCMobContainer  ?Insert@oCMobContainer@@UAEXPAVoCItem@@@Z
        vfunc f81_Remove;                   // from oCMobContainer  ?Remove@oCMobContainer@@UAEPAVoCItem@@PAV2@H@Z
        vfunc f82_Remove;                   // from oCMobContainer  ?Remove@oCMobContainer@@UAEXPAVoCItem@@@Z
        vfunc f83_CreateContents;           // from oCMobContainer  ?CreateContents@oCMobContainer@@UAEXABVzSTRING@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083CB64;
    }

    static uint GetFuncsNum() {
      return 84;
    }

    static vftable_oCMobContainer& GetTable() {
      MemUnlock;
      return *(vftable_oCMobContainer*)GetAddress();
    }
  };


  struct vftable_oCMobLockable {
    union {
      vfunc array[80];
      group {
        vfunc f00_GetClassDef;              // from oCMobLockable  ?_GetClassDef@oCMobLockable@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobLockable  ?Archive@oCMobLockable@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobLockable  ?Unarchive@oCMobLockable@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base           
        vfunc f04_OnTrigger;                // from oCMobInter     ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter     ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob          ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob          ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter     ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobLockable  ?OnMessage@oCMobLockable@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter     ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB          ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob          ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter     ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob          ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter     ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob          ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob          ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob          ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob          ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB          ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB          ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob          ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob          ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB          ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB          ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB          ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB          ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB          ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB          ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter     ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB          ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB          ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter     ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter     ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter     ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter     ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter     ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter     ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter     ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobLockable  ?Interact@oCMobLockable@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter     ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter     ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter     ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobLockable  ?CanInteractWith@oCMobLockable@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter     ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter     ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter     ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter     ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter     ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter     ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter     ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter     ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobLockable  ?CanChangeState@oCMobLockable@@MAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter     ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter     ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobLockable  ?OnEndStateChange@oCMobLockable@@MAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter     ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter     ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter     ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
        vfunc f72_SetLocked;                // from oCMobLockable  ?SetLocked@oCMobLockable@@UAEXH@Z
        vfunc f73_SetKeyInstance;           // from oCMobLockable  ?SetKeyInstance@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f74_SetPickLockStr;           // from oCMobLockable  ?SetPickLockStr@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f75_Open;                     // from base           purecall
        vfunc f76_Close;                    // from base           purecall
        vfunc f77_Lock;                     // from oCMobLockable  ?Lock@oCMobLockable@@MAEXPAVoCNpc@@@Z
        vfunc f78_Unlock;                   // from oCMobLockable  ?Unlock@oCMobLockable@@MAEXPAVoCNpc@@H@Z
        vfunc f79_PickLock;                 // from oCMobLockable  ?PickLock@oCMobLockable@@MAEHPAVoCNpc@@D@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083CCBC;
    }

    static uint GetFuncsNum() {
      return 80;
    }

    static vftable_oCMobLockable& GetTable() {
      MemUnlock;
      return *(vftable_oCMobLockable*)GetAddress();
    }
  };


  struct vftable_oCMobWheel {
    union {
      vfunc array[72];
      group {
        vfunc f00_GetClassDef;              // from oCMobWheel  ?_GetClassDef@oCMobWheel@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobInter  ?Archive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobInter  ?Unarchive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base        
        vfunc f04_OnTrigger;                // from oCMobWheel  ?OnTrigger@oCMobWheel@@MAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobWheel  ?OnUntrigger@oCMobWheel@@MAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter  ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter  ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter  ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB       ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob       ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter  ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob       ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter  ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob       ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob       ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob       ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob       ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB       ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB       ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob       ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob       ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB       ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB       ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB       ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB       ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB       ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB       ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter  ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB       ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB       ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter  ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter  ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter  ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter  ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter  ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter  ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter  ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobWheel  ?Interact@oCMobWheel@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter  ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter  ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter  ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobInter  ?CanInteractWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter  ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter  ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter  ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter  ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter  ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter  ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter  ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter  ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter  ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter  ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter  ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobInter  ?OnEndStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter  ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter  ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter  ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083CE04;
    }

    static uint GetFuncsNum() {
      return 72;
    }

    static vftable_oCMobWheel& GetTable() {
      MemUnlock;
      return *(vftable_oCMobWheel*)GetAddress();
    }
  };


  struct vftable_oCMobLadder {
    union {
      vfunc array[72];
      group {
        vfunc f00_GetClassDef;              // from oCMobLadder  ?_GetClassDef@oCMobLadder@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobInter   ?Archive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobInter   ?Unarchive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base         
        vfunc f04_OnTrigger;                // from oCMobInter   ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter   ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob        ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob        ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob        ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter   ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter   ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter   ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob        ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob        ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob        ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob        ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob        ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB        ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob        ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob        ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter   ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob        ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob        ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob        ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob        ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter   ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob        ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob        ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob        ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob        ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob        ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob        ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB        ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB        ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCMobLadder  ?DoFocusCheckBBox@oCMobLadder@@MAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob        ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB        ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB        ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB        ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB        ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB        ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB        ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter   ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB        ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB        ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter   ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter   ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter   ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter   ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter   ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter   ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter   ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobLadder  ?Interact@oCMobLadder@@MAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobLadder  ?EndInteraction@oCMobLadder@@MAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter   ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter   ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobLadder  ?CanInteractWith@oCMobLadder@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter   ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter   ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter   ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter   ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter   ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobLadder  ?StartInteraction@oCMobLadder@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter   ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter   ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobLadder  ?CanChangeState@oCMobLadder@@MAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter   ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter   ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobInter   ?OnEndStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter   ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter   ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobLadder  ?SearchFreePosition@oCMobLadder@@MAEPAUTMobOptPos@@PAVoCNpc@@M@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083CF2C;
    }

    static uint GetFuncsNum() {
      return 72;
    }

    static vftable_oCMobLadder& GetTable() {
      MemUnlock;
      return *(vftable_oCMobLadder*)GetAddress();
    }
  };


  struct vftable_oCMobDoor {
    union {
      vfunc array[80];
      group {
        vfunc f00_GetClassDef;              // from oCMobDoor      ?_GetClassDef@oCMobDoor@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobLockable  ?Archive@oCMobLockable@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobLockable  ?Unarchive@oCMobLockable@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base           
        vfunc f04_OnTrigger;                // from oCMobInter     ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter     ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob          ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob          ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter     ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobLockable  ?OnMessage@oCMobLockable@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter     ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB          ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob          ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter     ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob          ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter     ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob          ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob          ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob          ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob          ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB          ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB          ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob          ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob          ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB          ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB          ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB          ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB          ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB          ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB          ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobDoor      ?GetScemeName@oCMobDoor@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB          ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB          ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter     ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter     ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter     ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter     ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter     ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter     ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter     ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobLockable  ?Interact@oCMobLockable@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter     ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter     ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter     ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobLockable  ?CanInteractWith@oCMobLockable@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter     ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter     ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter     ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter     ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter     ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter     ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter     ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter     ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobLockable  ?CanChangeState@oCMobLockable@@MAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter     ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter     ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobLockable  ?OnEndStateChange@oCMobLockable@@MAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter     ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter     ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobDoor      ?SearchFreePosition@oCMobDoor@@MAEPAUTMobOptPos@@PAVoCNpc@@M@Z
        vfunc f72_SetLocked;                // from oCMobLockable  ?SetLocked@oCMobLockable@@UAEXH@Z
        vfunc f73_SetKeyInstance;           // from oCMobLockable  ?SetKeyInstance@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f74_SetPickLockStr;           // from oCMobLockable  ?SetPickLockStr@oCMobLockable@@UAEXABVzSTRING@@@Z
        vfunc f75_Open;                     // from oCMobDoor      ?Open@oCMobDoor@@MAEXPAVoCNpc@@@Z
        vfunc f76_Close;                    // from oCMobDoor      ?Close@oCMobDoor@@MAEXPAVoCNpc@@@Z
        vfunc f77_Lock;                     // from oCMobLockable  ?Lock@oCMobLockable@@MAEXPAVoCNpc@@@Z
        vfunc f78_Unlock;                   // from oCMobLockable  ?Unlock@oCMobLockable@@MAEXPAVoCNpc@@H@Z
        vfunc f79_PickLock;                 // from oCMobLockable  ?PickLock@oCMobLockable@@MAEHPAVoCNpc@@D@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D054;
    }

    static uint GetFuncsNum() {
      return 80;
    }

    static vftable_oCMobDoor& GetTable() {
      MemUnlock;
      return *(vftable_oCMobDoor*)GetAddress();
    }
  };


  struct vftable_oCMobFire {
    union {
      vfunc array[74];
      group {
        vfunc f00_GetClassDef;              // from oCMobFire   ?_GetClassDef@oCMobFire@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobFire   ?Archive@oCMobFire@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobFire   ?Unarchive@oCMobFire@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base        
        vfunc f04_OnTrigger;                // from oCMobFire   ?OnTrigger@oCMobFire@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobFire   ?OnUntrigger@oCMobFire@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobFire   ?OnDamage@oCMobFire@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter  ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter  ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB       ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob       ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter  ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob       ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter  ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob       ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob       ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob       ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob       ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB       ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB       ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob       ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob       ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB       ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB       ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB       ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB       ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB       ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB       ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter  ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB       ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB       ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter  ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter  ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter  ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter  ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter  ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter  ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter  ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobInter  ?Interact@oCMobInter@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter  ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter  ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter  ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobInter  ?CanInteractWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter  ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter  ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter  ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter  ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter  ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter  ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter  ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter  ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter  ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter  ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter  ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobFire   ?OnEndStateChange@oCMobFire@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter  ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter  ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter  ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
        vfunc f72_PreSave;                  // from oCMobFire   ?PreSave@oCMobFire@@UAEXXZ
        vfunc f73_PostSave;                 // from oCMobFire   ?PostSave@oCMobFire@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083D19C;
    }

    static uint GetFuncsNum() {
      return 74;
    }

    static vftable_oCMobFire& GetTable() {
      MemUnlock;
      return *(vftable_oCMobFire*)GetAddress();
    }
  };


  struct vftable_oCMobItemSlot {
    union {
      vfunc array[75];
      group {
        vfunc f00_GetClassDef;              // from oCMobItemSlot  ?_GetClassDef@oCMobItemSlot@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobItemSlot  ?Archive@oCMobItemSlot@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobItemSlot  ?Unarchive@oCMobItemSlot@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base           
        vfunc f04_OnTrigger;                // from oCMobInter     ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter     ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob          ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob          ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter     ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter     ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter     ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB          ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob          ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter     ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob          ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter     ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob          ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob          ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob          ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob          ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB          ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB          ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob          ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob          ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB          ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB          ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB          ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB          ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB          ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB          ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter     ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB          ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB          ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter     ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter     ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter     ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter     ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter     ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobItemSlot  ?GetUseWithItem@oCMobItemSlot@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter     ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobInter     ?Interact@oCMobInter@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter     ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter     ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter     ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobItemSlot  ?CanInteractWith@oCMobItemSlot@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter     ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter     ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter     ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobItemSlot  ?IsIn@oCMobItemSlot@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter     ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter     ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter     ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter     ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter     ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter     ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter     ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobInter     ?OnEndStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter     ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter     ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter     ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
        vfunc f72_GetInsertedItem;          // from oCMobItemSlot  ?GetInsertedItem@oCMobItemSlot@@UAEPAVoCItem@@XZ
        vfunc f73_PlaceItem;                // from oCMobItemSlot  ?PlaceItem@oCMobItemSlot@@UAEHPAVoCItem@@@Z
        vfunc f74_RemoveItem;               // from oCMobItemSlot  ?RemoveItem@oCMobItemSlot@@UAEPAVoCItem@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083D2CC;
    }

    static uint GetFuncsNum() {
      return 75;
    }

    static vftable_oCMobItemSlot& GetTable() {
      MemUnlock;
      return *(vftable_oCMobItemSlot*)GetAddress();
    }
  };


  struct vftable_oCDummyVobGenerator {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from oCDummyVobGenerator  ?_GetClassDef@oCDummyVobGenerator@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob                ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob                ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base                 
        vfunc f04_OnTrigger;               // from oCDummyVobGenerator  ?OnTrigger@oCDummyVobGenerator@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;             // from zCVob                ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob                ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob                ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob                ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob                ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob                ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob                ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob                ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob                ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob                ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob                ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob                ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob                ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob                ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob                ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob                ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob                ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob                ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob                ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob                ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob                ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob                ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob                ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D3FC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_oCDummyVobGenerator& GetTable() {
      MemUnlock;
      return *(vftable_oCDummyVobGenerator*)GetAddress();
    }
  };


  struct vftable_oCMobMsg {
    union {
      vfunc array[23];
      group {
        vfunc f00_GetClassDef;           // from oCMobMsg        ?_GetClassDef@oCMobMsg@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from zCEventMessage  ?Archive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from zCEventMessage  ?Unarchive@zCEventMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from zCEventMessage  ?IsOverlay@zCEventMessage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMobMsg        ?IsNetRelevant@oCMobMsg@@UAEHXZ
        vfunc f06_IsHighPriority;        // from zCEventMessage  ?IsHighPriority@zCEventMessage@@UAEHXZ
        vfunc f07_IsJob;                 // from zCEventMessage  ?IsJob@zCEventMessage@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from zCEventMessage  ?GetIgnoreCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f09_Delete;                // from zCEventMessage  ?Delete@zCEventMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from zCEventMessage  ?IsDeleteable@zCEventMessage@@UAEHXZ
        vfunc f11_IsDeleted;             // from zCEventMessage  ?IsDeleted@zCEventMessage@@UAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMobMsg        ?MD_GetNumOfSubTypes@oCMobMsg@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMobMsg        ?MD_GetSubTypeString@oCMobMsg@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from oCMobMsg        ?Pack@oCMobMsg@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMobMsg        ?Unpack@oCMobMsg@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D474;
    }

    static uint GetFuncsNum() {
      return 23;
    }

    static vftable_oCMobMsg& GetTable() {
      MemUnlock;
      return *(vftable_oCMobMsg*)GetAddress();
    }
  };


  struct vftable_oCMOB {
    union {
      vfunc array[45];
      group {
        vfunc f00_GetClassDef;              // from oCMOB  ?_GetClassDef@oCMOB@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMOB  ?Archive@oCMOB@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMOB  ?Unarchive@oCMOB@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base   
        vfunc f04_OnTrigger;                // from zCVob  ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;              // from zCVob  ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                  // from zCVob  ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob  ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob  ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMOB  ?OnDamage@oCMOB@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMOB  ?OnMessage@oCMOB@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from zCVob  ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob  ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob  ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob  ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob  ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob  ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB  ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob  ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob  ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMOB  ?SetVisual@oCMOB@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob  ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob  ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob  ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob  ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from zCVob  ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob  ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob  ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob  ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob  ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob  ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob  ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB  ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB  ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob  ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob  ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB  ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB  ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB  ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB  ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB  ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB  ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMOB  ?GetScemeName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB  ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB  ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083D4D4;
    }

    static uint GetFuncsNum() {
      return 45;
    }

    static vftable_oCMOB& GetTable() {
      MemUnlock;
      return *(vftable_oCMOB*)GetAddress();
    }
  };


  struct vftable_oCMobInter {
    union {
      vfunc array[72];
      group {
        vfunc f00_GetClassDef;              // from oCMobInter  ?_GetClassDef@oCMobInter@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCMobInter  ?Archive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCMobInter  ?Unarchive@oCMobInter@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base        
        vfunc f04_OnTrigger;                // from oCMobInter  ?OnTrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;              // from oCMobInter  ?OnUntrigger@oCMobInter@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;                  // from zCVob       ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;                // from zCVob       ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob       ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCMobInter  ?OnDamage@oCMobInter@@MAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCMobInter  ?OnMessage@oCMobInter@@MAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from oCMobInter  ?OnTick@oCMobInter@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob       ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob       ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from zCVob       ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;          // from zCVob       ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob       ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from oCMOB       ?CanThisCollideWith@oCMOB@@MAEHPAVzCVob@@@Z
        vfunc f18_Render;                   // from oCVob       ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob       ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCMobInter  ?SetVisual@oCMobInter@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from zCVob       ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from zCVob       ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCVob       ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob       ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from oCMobInter  ?GetTriggerTarget@oCMobInter@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from zCVob       ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from zCVob       ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob       ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCVob       ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCVob       ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCVob       ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCMOB       ?IsOwnedByGuild@oCMOB@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCMOB       ?IsOwnedByNpc@oCMOB@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob       ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob       ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCMOB       ?GetSoundMaterial_AM@oCMOB@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCMOB       ?SetSoundMaterial@oCMOB@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCMOB       ?GetSoundMaterial@oCMOB@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetName;                  // from oCMOB       ?SetName@oCMOB@@UAEXABVzSTRING@@@Z
        vfunc f40_GetName;                  // from oCMOB       ?GetName@oCMOB@@UAE?AVzSTRING@@XZ
        vfunc f41_GetModel;                 // from oCMOB       ?GetModel@oCMOB@@UAEPAVzCModel@@XZ
        vfunc f42_GetScemeName;             // from oCMobInter  ?GetScemeName@oCMobInter@@UAE?AVzSTRING@@XZ
        vfunc f43_Destroy;                  // from oCMOB       ?Destroy@oCMOB@@UAEXXZ
        vfunc f44_AllowDiscardingOfSubtree; // from oCMOB       ?AllowDiscardingOfSubtree@oCMOB@@UAEHXZ
        vfunc f45_GetState;                 // from oCMobInter  ?GetState@oCMobInter@@UAEHXZ
        vfunc f46_GetStateNum;              // from oCMobInter  ?GetStateNum@oCMobInter@@UAEHXZ
        vfunc f47_GetDirection;             // from oCMobInter  ?GetDirection@oCMobInter@@UAE?AW4TMobInterDirection@1@XZ
        vfunc f48_SetDirection;             // from oCMobInter  ?SetDirection@oCMobInter@@UAEXW4TMobInterDirection@1@@Z
        vfunc f49_SetUseWithItem;           // from oCMobInter  ?SetUseWithItem@oCMobInter@@UAEXABVzSTRING@@@Z
        vfunc f50_GetUseWithItem;           // from oCMobInter  ?GetUseWithItem@oCMobInter@@UAEHXZ
        vfunc f51_Reset;                    // from oCMobInter  ?Reset@oCMobInter@@UAEXXZ
        vfunc f52_Interact;                 // from oCMobInter  ?Interact@oCMobInter@@UAEXPAVoCNpc@@HHHHH@Z
        vfunc f53_EndInteraction;           // from oCMobInter  ?EndInteraction@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f54_InterruptInteraction;     // from oCMobInter  ?InterruptInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f55_StopInteraction;          // from oCMobInter  ?StopInteraction@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f56_CanInteractWith;          // from oCMobInter  ?CanInteractWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f57_IsInteractingWith;        // from oCMobInter  ?IsInteractingWith@oCMobInter@@UAEHPAVoCNpc@@@Z
        vfunc f58_IsOccupied;               // from oCMobInter  ?IsOccupied@oCMobInter@@UAEHXZ
        vfunc f59_AI_UseMobToState;         // from oCMobInter  ?AI_UseMobToState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f60_IsIn;                     // from oCMobInter  ?IsIn@oCMobInter@@UAEHH@Z
        vfunc f61_IsInState;                // from oCMobInter  ?IsInState@oCMobInter@@UAEHPAVoCNpc@@H@Z
        vfunc f62_StartInteraction;         // from oCMobInter  ?StartInteraction@oCMobInter@@MAEXPAVoCNpc@@@Z
        vfunc f63_StartStateChange;         // from oCMobInter  ?StartStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f64_CheckStateChange;         // from oCMobInter  ?CheckStateChange@oCMobInter@@UAEXPAVoCNpc@@@Z
        vfunc f65_CanChangeState;           // from oCMobInter  ?CanChangeState@oCMobInter@@UAEHPAVoCNpc@@HH@Z
        vfunc f66_GetTransitionNames;       // from oCMobInter  ?GetTransitionNames@oCMobInter@@UAEXHHAAVzSTRING@@0@Z
        vfunc f67_OnBeginStateChange;       // from oCMobInter  ?OnBeginStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f68_OnEndStateChange;         // from oCMobInter  ?OnEndStateChange@oCMobInter@@UAEXPAVoCNpc@@HH@Z
        vfunc f69_CallOnStateFunc;          // from oCMobInter  ?CallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f70_SendCallOnStateFunc;      // from oCMobInter  ?SendCallOnStateFunc@oCMobInter@@UAEXPAVoCNpc@@H@Z
        vfunc f71_SearchFreePosition;       // from oCMobInter  ?SearchFreePosition@oCMobInter@@UAEPAUTMobOptPos@@PAVoCNpc@@M@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D58C;
    }

    static uint GetFuncsNum() {
      return 72;
    }

    static vftable_oCMobInter& GetTable() {
      MemUnlock;
      return *(vftable_oCMobInter*)GetAddress();
    }
  };


  struct vftable_oCNewsMemory {
    union {
      vfunc array[2];
      group {
        vfunc f00_Archive;   // from oCNewsMemory  ?Archive@oCNewsMemory@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive; // from oCNewsMemory  ?Unarchive@oCNewsMemory@@UAEXAAVzCArchiver@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D6D0;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_oCNewsMemory& GetTable() {
      MemUnlock;
      return *(vftable_oCNewsMemory*)GetAddress();
    }
  };


  struct vftable_oCNews {
    union {
      vfunc array[2];
      group {
        vfunc f00_Archive;   // from oCNews  ?Archive@oCNews@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive; // from oCNews  ?Unarchive@oCNews@@UAEXAAVzCArchiver@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083D6DC;
    }

    static uint GetFuncsNum() {
      return 2;
    }

    static vftable_oCNews& GetTable() {
      MemUnlock;
      return *(vftable_oCNews*)GetAddress();
    }
  };


  struct vftable_oCNpcTalent {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from oCNpcTalent  ?_GetClassDef@oCNpcTalent@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from oCNpcTalent  ?Archive@oCNpcTalent@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from oCNpcTalent  ?Unarchive@oCNpcTalent@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base         
      } names;
    };

    static uint GetAddress() {
      return 0x0083D710;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_oCNpcTalent& GetTable() {
      MemUnlock;
      return *(vftable_oCNpcTalent*)GetAddress();
    }
  };


  struct vftable_oCNpc {
    union {
      vfunc array[76];
      group {
        vfunc f00_GetClassDef;              // from oCNpc  ?_GetClassDef@oCNpc@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCNpc  ?Archive@oCNpc@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCNpc  ?Unarchive@oCNpc@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base   
        vfunc f04_OnTrigger;                // from zCVob  ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;              // from zCVob  ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                  // from oCNpc  ?OnTouch@oCNpc@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;                // from zCVob  ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;             // from zCVob  ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                 // from oCNpc  ?OnDamage@oCNpc@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;                // from oCNpc  ?OnMessage@oCNpc@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_OnTick;                   // from zCVob  ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                  // from zCVob  ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                 // from zCVob  ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;        // from oCNpc  ?GetCharacterClass@oCNpc@@UAE?AW4zTVobCharClass@zCVob@@XZ
        vfunc f15_SetSleepingMode;          // from zCVob  ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;              // from zCVob  ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;       // from zCVob  ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                   // from oCVob  ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;                // from zCVob  ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;                // from oCNpc  ?SetVisual@oCNpc@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;        // from oCNpc  ?GetScriptInstance@oCNpc@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;      // from oCNpc  ?SetByScriptInstance@oCNpc@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;          // from oCNpc  ?GetCSStateFlags@oCNpc@@UAEHXZ
        vfunc f24_TraceRay;                 // from zCVob  ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;         // from zCVob  ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;      // from oCNpc  ?ThisVobAddedToWorld@oCNpc@@MAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld;  // from oCNpc  ?ThisVobRemovedFromWorld@oCNpc@@MAEXPAVzCWorld@@@Z
        vfunc f28_Init;                     // from oCVob  ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;            // from oCNpc  ?ShowDebugInfo@oCNpc@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;              // from oCNpc  ?GetInstance@oCNpc@@UAEHXZ
        vfunc f31_GetInstanceName;          // from oCNpc  ?GetInstanceName@oCNpc@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;           // from oCVob  ?IsOwnedByGuild@oCVob@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;             // from oCVob  ?IsOwnedByNpc@oCVob@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;         // from oCVob  ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;             // from oCVob  ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;      // from oCNpc  ?GetSoundMaterial_AM@oCNpc@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;         // from oCVob  ?SetSoundMaterial@oCVob@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;         // from oCVob  ?GetSoundMaterial@oCVob@@UAE?AW4oTSndMaterial@@XZ
        vfunc f39_SetWeaponMode;            // from oCNpc  ?SetWeaponMode@oCNpc@@UAEXH@Z
        vfunc f40_SetWeaponMode2;           // from oCNpc  ?SetWeaponMode2@oCNpc@@UAEXH@Z
        vfunc f41_DoDie;                    // from oCNpc  ?DoDie@oCNpc@@UAEXPAV1@@Z
        vfunc f42_DoInsertMunition;         // from oCNpc  ?DoInsertMunition@oCNpc@@UAEPAVoCItem@@ABVzSTRING@@@Z
        vfunc f43_DoRemoveMunition;         // from oCNpc  ?DoRemoveMunition@oCNpc@@UAEXXZ
        vfunc f44_DoSetToFightMode;         // from oCNpc  ?DoSetToFightMode@oCNpc@@UAEHPAVoCItem@@@Z
        vfunc f45_DoShootArrow;             // from oCNpc  ?DoShootArrow@oCNpc@@UAEHH@Z
        vfunc f46_OnDamage;                 // from oCNpc  ?OnDamage@oCNpc@@UAEXAAUoSDamageDescriptor@1@@Z
        vfunc f47_ResetPos;                 // from oCNpc  ?ResetPos@oCNpc@@UAEXAAVzVEC3@@@Z
        vfunc f48_EmergencyResetPos;        // from oCNpc  ?EmergencyResetPos@oCNpc@@UAEXAAVzVEC3@@@Z
        vfunc f49_InitByScript;             // from oCNpc  ?InitByScript@oCNpc@@UAEXHH@Z
        vfunc f50_Disable;                  // from oCNpc  ?Disable@oCNpc@@UAEXXZ
        vfunc f51_Enable;                   // from oCNpc  ?Enable@oCNpc@@UAEXAAVzVEC3@@@Z
        vfunc f52_InitHumanAI;              // from oCNpc  ?InitHumanAI@oCNpc@@UAEXXZ
        vfunc f53_IsMoreImportant;          // from oCNpc  ?IsMoreImportant@oCNpc@@UAEHPAVzCVob@@0@Z
        vfunc f54_DoDoAniEvents;            // from oCNpc  ?DoDoAniEvents@oCNpc@@UAEHXZ
        vfunc f55_DoModelSwapMesh;          // from oCNpc  ?DoModelSwapMesh@oCNpc@@UAEHABVzSTRING@@0@Z
        vfunc f56_DoTakeVob;                // from oCNpc  ?DoTakeVob@oCNpc@@UAEHPAVzCVob@@@Z
        vfunc f57_DoDropVob;                // from oCNpc  ?DoDropVob@oCNpc@@UAEHPAVzCVob@@@Z
        vfunc f58_DoRemoveFromInventory;    // from oCNpc  ?DoRemoveFromInventory@oCNpc@@UAEHPAVoCItem@@@Z
        vfunc f59_DoPutInInventory;         // from oCNpc  ?DoPutInInventory@oCNpc@@UAEHPAVoCItem@@@Z
        vfunc f60_DoThrowVob;               // from oCNpc  ?DoThrowVob@oCNpc@@UAEHPAVzCVob@@M@Z
        vfunc f61_DoExchangeTorch;          // from oCNpc  ?DoExchangeTorch@oCNpc@@UAEHXZ
        vfunc f62_GetSoundMaterial_MA;      // from oCNpc  ?GetSoundMaterial_MA@oCNpc@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@VzSTRING@@@Z
        vfunc f63_GetSoundMaterial_MH_HM;   // from oCNpc  ?GetSoundMaterial_MH_HM@oCNpc@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@@Z
        vfunc f64_IsAPlayer;                // from oCNpc  ?IsAPlayer@oCNpc@@UAEHXZ
        vfunc f65_IsSelfPlayer;             // from oCNpc  ?IsSelfPlayer@oCNpc@@UAEHXZ
        vfunc f66_SetAsPlayer;              // from oCNpc  ?SetAsPlayer@oCNpc@@UAEXXZ
        vfunc f67_IsMonster;                // from oCNpc  ?IsMonster@oCNpc@@UAEHXZ
        vfunc f68_IsHuman;                  // from oCNpc  ?IsHuman@oCNpc@@UAEHXZ
        vfunc f69_IsGoblin;                 // from oCNpc  ?IsGoblin@oCNpc@@UAEHXZ
        vfunc f70_IsOrc;                    // from oCNpc  ?IsOrc@oCNpc@@UAEHXZ
        vfunc f71_IsSkeleton;               // from oCNpc  ?IsSkeleton@oCNpc@@UAEHXZ
        vfunc f72_GetPlayerNumber;          // from oCNpc  ?GetPlayerNumber@oCNpc@@UAEHXZ
        vfunc f73_IsAniMessageRunning;      // from oCNpc  ?IsAniMessageRunning@oCNpc@@UAEHXZ
        vfunc f74_ProcessNpc;               // from oCNpc  ?ProcessNpc@oCNpc@@UAEXXZ
        vfunc f75_AllowDiscardingOfSubtree; // from oCNpc  ?AllowDiscardingOfSubtree@oCNpc@@MAEHXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083D724;
    }

    static uint GetFuncsNum() {
      return 76;
    }

    static vftable_oCNpc& GetTable() {
      MemUnlock;
      return *(vftable_oCNpc*)GetAddress();
    }
  };


  struct vftable_oCNpcMessage {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCNpcMessage    ?_GetClassDef@oCNpcMessage@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCNpcMessage    ?Archive@oCNpcMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCNpcMessage    ?Unarchive@oCNpcMessage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCNpcMessage    ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage  ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventMessage  ?MD_GetNumOfSubTypes@zCEventMessage@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventMessage  ?MD_GetSubTypeString@zCEventMessage@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DA8C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCNpcMessage& GetTable() {
      MemUnlock;
      return *(vftable_oCNpcMessage*)GetAddress();
    }
  };


  struct vftable_oCMsgDamage {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgDamage     ?_GetClassDef@oCMsgDamage@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgDamage     ?Archive@oCMsgDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgDamage     ?Unarchive@oCMsgDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCMsgDamage     ?IsOverlay@oCMsgDamage@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMsgDamage     ?IsNetRelevant@oCMsgDamage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCMsgDamage     ?IsHighPriority@oCMsgDamage@@UAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCMsgDamage     ?IsDeleteable@oCMsgDamage@@UAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgDamage     ?MD_GetNumOfSubTypes@oCMsgDamage@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgDamage     ?MD_GetSubTypeString@oCMsgDamage@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from oCMsgDamage     ?Pack@oCMsgDamage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMsgDamage     ?Unpack@oCMsgDamage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DAFC;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgDamage& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgDamage*)GetAddress();
    }
  };


  struct vftable_oCMsgWeapon {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgWeapon     ?_GetClassDef@oCMsgWeapon@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgWeapon     ?Archive@oCMsgWeapon@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgWeapon     ?Unarchive@oCMsgWeapon@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCNpcMessage    ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage  ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgWeapon     ?MD_GetNumOfSubTypes@oCMsgWeapon@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgWeapon     ?MD_GetSubTypeString@oCMsgWeapon@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from oCMsgWeapon     ?MD_GetTimeBehavior@oCMsgWeapon@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from oCMsgWeapon     ?MD_GetMinTime@oCMsgWeapon@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DB6C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgWeapon& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgWeapon*)GetAddress();
    }
  };


  struct vftable_oCMsgMovement {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgMovement   ?_GetClassDef@oCMsgMovement@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgMovement   ?Archive@oCMsgMovement@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgMovement   ?Unarchive@oCMsgMovement@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCNpcMessage    ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage  ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCMsgMovement   ?Delete@oCMsgMovement@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgMovement   ?MD_GetNumOfSubTypes@oCMsgMovement@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgMovement   ?MD_GetSubTypeString@oCMsgMovement@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from oCMsgMovement   ?MD_GetVobRefName@oCMsgMovement@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from oCMsgMovement   ?MD_SetVobRefName@oCMsgMovement@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from oCMsgMovement   ?MD_SetVobParam@oCMsgMovement@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from oCMsgMovement   ?MD_GetTimeBehavior@oCMsgMovement@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from oCMsgMovement   ?MD_GetMinTime@oCMsgMovement@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DBDC;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgMovement& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgMovement*)GetAddress();
    }
  };


  struct vftable_oCMsgAttack {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgAttack     ?_GetClassDef@oCMsgAttack@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgAttack     ?Archive@oCMsgAttack@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgAttack     ?Unarchive@oCMsgAttack@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCMsgAttack     ?IsOverlay@oCMsgAttack@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMsgAttack     ?IsNetRelevant@oCMsgAttack@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgAttack     ?MD_GetNumOfSubTypes@oCMsgAttack@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgAttack     ?MD_GetSubTypeString@oCMsgAttack@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from oCMsgAttack     ?Pack@oCMsgAttack@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMsgAttack     ?Unpack@oCMsgAttack@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DC4C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgAttack& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgAttack*)GetAddress();
    }
  };


  struct vftable_oCMsgUseItem {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgUseItem    ?_GetClassDef@oCMsgUseItem@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgUseItem    ?Archive@oCMsgUseItem@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgUseItem    ?Unarchive@oCMsgUseItem@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCNpcMessage    ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMsgUseItem    ?IsNetRelevant@oCMsgUseItem@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from zCEventMessage  ?MD_GetNumOfSubTypes@zCEventMessage@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from zCEventMessage  ?MD_GetSubTypeString@zCEventMessage@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from oCMsgUseItem    ?Pack@oCMsgUseItem@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMsgUseItem    ?Unpack@oCMsgUseItem@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DCBC;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgUseItem& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgUseItem*)GetAddress();
    }
  };


  struct vftable_oCMsgState {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgState      ?_GetClassDef@oCMsgState@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgState      ?Archive@oCMsgState@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgState      ?Unarchive@oCMsgState@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCMsgState      ?IsOverlay@oCMsgState@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage  ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage    ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage    ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgState      ?MD_GetNumOfSubTypes@oCMsgState@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgState      ?MD_GetSubTypeString@oCMsgState@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from oCMsgState      ?MD_GetTimeBehavior@oCMsgState@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from oCMsgState      ?MD_GetMinTime@oCMsgState@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage  ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage  ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DD2C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgState& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgState*)GetAddress();
    }
  };


  struct vftable_oCMsgManipulate {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgManipulate  ?_GetClassDef@oCMsgManipulate@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgManipulate  ?Archive@oCMsgManipulate@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgManipulate  ?Unarchive@oCMsgManipulate@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base             
        vfunc f04_IsOverlay;             // from oCNpcMessage     ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMsgManipulate  ?IsNetRelevant@oCMsgManipulate@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage     ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage     ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage     ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage     ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage     ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage     ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage   ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage   ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgManipulate  ?MD_GetNumOfSubTypes@oCMsgManipulate@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgManipulate  ?MD_GetSubTypeString@oCMsgManipulate@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from oCMsgManipulate  ?MD_GetVobRefName@oCMsgManipulate@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from oCMsgManipulate  ?MD_SetVobRefName@oCMsgManipulate@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from oCMsgManipulate  ?MD_SetVobParam@oCMsgManipulate@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from oCMsgManipulate  ?MD_GetTimeBehavior@oCMsgManipulate@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from oCMsgManipulate  ?MD_GetMinTime@oCMsgManipulate@@UAEMXZ
        vfunc f21_Pack;                  // from oCMsgManipulate  ?Pack@oCMsgManipulate@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMsgManipulate  ?Unpack@oCMsgManipulate@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage     ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage     ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage     ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DD9C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgManipulate& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgManipulate*)GetAddress();
    }
  };


  struct vftable_oCMsgConversation {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgConversation  ?_GetClassDef@oCMsgConversation@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgConversation  ?Archive@oCMsgConversation@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgConversation  ?Unarchive@oCMsgConversation@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base               
        vfunc f04_IsOverlay;             // from oCMsgConversation  ?IsOverlay@oCMsgConversation@@UAEHXZ
        vfunc f05_IsNetRelevant;         // from zCEventMessage     ?IsNetRelevant@zCEventMessage@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCNpcMessage       ?IsHighPriority@oCNpcMessage@@MAEHXZ
        vfunc f07_IsJob;                 // from oCNpcMessage       ?IsJob@oCNpcMessage@@MAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage       ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCMsgConversation  ?Delete@oCMsgConversation@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage       ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage       ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage     ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage     ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgConversation  ?MD_GetNumOfSubTypes@oCMsgConversation@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgConversation  ?MD_GetSubTypeString@oCMsgConversation@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from oCMsgConversation  ?MD_GetVobRefName@oCMsgConversation@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from oCMsgConversation  ?MD_SetVobRefName@oCMsgConversation@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from oCMsgConversation  ?MD_SetVobParam@oCMsgConversation@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from oCMsgConversation  ?MD_GetTimeBehavior@oCMsgConversation@@UAE?AW4zTTimeBehavior@zCEventMessage@@XZ
        vfunc f20_MD_GetMinTime;         // from oCMsgConversation  ?MD_GetMinTime@oCMsgConversation@@UAEMXZ
        vfunc f21_Pack;                  // from zCEventMessage     ?Pack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from zCEventMessage     ?Unpack@zCEventMessage@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage       ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage       ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage       ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DE0C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgConversation& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgConversation*)GetAddress();
    }
  };


  struct vftable_oCMsgMagic {
    union {
      vfunc array[26];
      group {
        vfunc f00_GetClassDef;           // from oCMsgMagic      ?_GetClassDef@oCMsgMagic@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;               // from oCMsgMagic      ?Archive@oCMsgMagic@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;             // from oCMsgMagic      ?Unarchive@oCMsgMagic@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;     // from base            
        vfunc f04_IsOverlay;             // from oCNpcMessage    ?IsOverlay@oCNpcMessage@@MAEHXZ
        vfunc f05_IsNetRelevant;         // from oCMsgMagic      ?IsNetRelevant@oCMsgMagic@@UAEHXZ
        vfunc f06_IsHighPriority;        // from oCMsgMagic      ?IsHighPriority@oCMsgMagic@@UAEHXZ
        vfunc f07_IsJob;                 // from oCMsgMagic      ?IsJob@oCMsgMagic@@UAEHXZ
        vfunc f08_GetIgnoreCutsceneMode; // from oCNpcMessage    ?GetIgnoreCutsceneMode@oCNpcMessage@@UAEHXZ
        vfunc f09_Delete;                // from oCNpcMessage    ?Delete@oCNpcMessage@@UAEXXZ
        vfunc f10_IsDeleteable;          // from oCNpcMessage    ?IsDeleteable@oCNpcMessage@@MAEHXZ
        vfunc f11_IsDeleted;             // from oCNpcMessage    ?IsDeleted@oCNpcMessage@@MAEHXZ
        vfunc f12_SetCutsceneMode;       // from zCEventMessage  ?SetCutsceneMode@zCEventMessage@@UAEXH@Z
        vfunc f13_GetCutsceneMode;       // from zCEventMessage  ?GetCutsceneMode@zCEventMessage@@UAEHXZ
        vfunc f14_MD_GetNumOfSubTypes;   // from oCMsgMagic      ?MD_GetNumOfSubTypes@oCMsgMagic@@UAEHXZ
        vfunc f15_MD_GetSubTypeString;   // from oCMsgMagic      ?MD_GetSubTypeString@oCMsgMagic@@UAE?AVzSTRING@@H@Z
        vfunc f16_MD_GetVobRefName;      // from zCEventMessage  ?MD_GetVobRefName@zCEventMessage@@UAE?AVzSTRING@@XZ
        vfunc f17_MD_SetVobRefName;      // from zCEventMessage  ?MD_SetVobRefName@zCEventMessage@@UAEXABVzSTRING@@@Z
        vfunc f18_MD_SetVobParam;        // from zCEventMessage  ?MD_SetVobParam@zCEventMessage@@UAEXPAVzCVob@@@Z
        vfunc f19_MD_GetTimeBehavior;    // from zCEventMessage  ?MD_GetTimeBehavior@zCEventMessage@@UAE?AW4zTTimeBehavior@1@XZ
        vfunc f20_MD_GetMinTime;         // from zCEventMessage  ?MD_GetMinTime@zCEventMessage@@UAEMXZ
        vfunc f21_Pack;                  // from oCMsgMagic      ?Pack@oCMsgMagic@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f22_Unpack;                // from oCMsgMagic      ?Unpack@oCMsgMagic@@MAEXAAVzCBuffer@@PAVzCEventManager@@@Z
        vfunc f23_SetInUse;              // from oCNpcMessage    ?SetInUse@oCNpcMessage@@UAEXH@Z
        vfunc f24_IsInUse;               // from oCNpcMessage    ?IsInUse@oCNpcMessage@@UAEHXZ
        vfunc f25_SetHighPriority;       // from oCNpcMessage    ?SetHighPriority@oCNpcMessage@@UAEXH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DE7C;
    }

    static uint GetFuncsNum() {
      return 26;
    }

    static vftable_oCMsgMagic& GetTable() {
      MemUnlock;
      return *(vftable_oCMsgMagic*)GetAddress();
    }
  };


  struct vftable_oCNpc_States {
    union {
      vfunc array[4];
      group {
        vfunc f00_Archive;     // from oCNpc_States  ?Archive@oCNpc_States@@UAEXAAVzCArchiver@@@Z
        vfunc f01_Unarchive;   // from oCNpc_States  ?Unarchive@oCNpc_States@@UAEXAAVzCArchiver@@@Z
        vfunc f02_PackState;   // from oCNpc_States  ?PackState@oCNpc_States@@UAEXAAVzCBuffer@@@Z
        vfunc f03_UnpackState; // from oCNpc_States  ?UnpackState@oCNpc_States@@UAEXAAVzCBuffer@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083DF08;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_oCNpc_States& GetTable() {
      MemUnlock;
      return *(vftable_oCNpc_States*)GetAddress();
    }
  };


  struct vftable_oCRtnCutscene {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0083DF80;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_oCRtnCutscene& GetTable() {
      MemUnlock;
      return *(vftable_oCRtnCutscene*)GetAddress();
    }
  };


  struct vftable_oCVob {
    union {
      vfunc array[39];
      group {
        vfunc f00_GetClassDef;             // from oCVob  ?_GetClassDef@oCVob@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from oCVob  ?Archive@oCVob@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from oCVob  ?Unarchive@oCVob@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base   
        vfunc f04_OnTrigger;               // from zCVob  ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob  ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob  ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob  ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob  ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob  ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob  ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob  ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob  ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob  ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob  ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob  ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob  ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob  ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from oCVob  ?Render@oCVob@@MAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob  ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob  ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob  ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob  ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from oCVob  ?GetCSStateFlags@oCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob  ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob  ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob  ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob  ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_Init;                    // from oCVob  ?Init@oCVob@@UAEXXZ
        vfunc f29_ShowDebugInfo;           // from oCVob  ?ShowDebugInfo@oCVob@@UAEXPAVzCCamera@@@Z
        vfunc f30_GetInstance;             // from oCVob  ?GetInstance@oCVob@@UAEHXZ
        vfunc f31_GetInstanceName;         // from oCVob  ?GetInstanceName@oCVob@@UAE?AVzSTRING@@XZ
        vfunc f32_IsOwnedByGuild;          // from oCVob  ?IsOwnedByGuild@oCVob@@UAEHH@Z
        vfunc f33_IsOwnedByNpc;            // from oCVob  ?IsOwnedByNpc@oCVob@@UAEHH@Z
        vfunc f34_DoFocusCheckBBox;        // from oCVob  ?DoFocusCheckBBox@oCVob@@UAEHXZ
        vfunc f35_GetAIVobMove;            // from oCVob  ?GetAIVobMove@oCVob@@UAEPAVoCAIVobMove@@XZ
        vfunc f36_GetSoundMaterial_AM;     // from oCVob  ?GetSoundMaterial_AM@oCVob@@UAEXAAW4zTSndManMedium@zCSoundManager@@AAW4oTSndMaterial@@H@Z
        vfunc f37_SetSoundMaterial;        // from oCVob  ?SetSoundMaterial@oCVob@@UAEXW4oTSndMaterial@@@Z
        vfunc f38_GetSoundMaterial;        // from oCVob  ?GetSoundMaterial@oCVob@@UAE?AW4oTSndMaterial@@XZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083DFE4;
    }

    static uint GetFuncsNum() {
      return 39;
    }

    static vftable_oCVob& GetTable() {
      MemUnlock;
      return *(vftable_oCVob*)GetAddress();
    }
  };


  struct vftable_oCTouchDamage {
    union {
      vfunc array[29];
      group {
        vfunc f00_GetClassDef;             // from oCTouchDamage  ?_GetClassDef@oCTouchDamage@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCTouchDamage  ?Archive@zCTouchDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCTouchDamage  ?Unarchive@zCTouchDamage@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCVob          ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob          ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCTouchDamage  ?OnTouch@zCTouchDamage@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;               // from zCTouchDamage  ?OnUntouch@zCTouchDamage@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob          ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob          ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCTouchDamage  ?OnTimer@zCTouchDamage@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCTouchDamage  ?SetVisual@zCTouchDamage@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob          ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f28_GetDamageTypeArcEnum;    // from oCTouchDamage  ?GetDamageTypeArcEnum@oCTouchDamage@@EAEPBDK@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E08C;
    }

    static uint GetFuncsNum() {
      return 29;
    }

    static vftable_oCTouchDamage& GetTable() {
      MemUnlock;
      return *(vftable_oCTouchDamage*)GetAddress();
    }
  };


  struct vftable_oCWaypoint {
    union {
      vfunc array[5];
      group {
        vfunc f00_GetClassDef;       // from zCWaypoint  ?_GetClassDef@zCWaypoint@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCWaypoint  ?Archive@zCWaypoint@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCWaypoint  ?Unarchive@zCWaypoint@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base        
        vfunc f04_CanBeUsed;         // from oCWaypoint  ?CanBeUsed@oCWaypoint@@UAEHPBVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E120;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_oCWaypoint& GetTable() {
      MemUnlock;
      return *(vftable_oCWaypoint*)GetAddress();
    }
  };


  struct vftable_oCWay {
    union {
      vfunc array[7];
      group {
        vfunc f00_scalar_destructor; // from base   
        vfunc f01_Init;              // from oCWay  ?Init@oCWay@@UAEXPAVzCWaypoint@@0@Z
        vfunc f02_CalcProperties;    // from zCWay  ?CalcProperties@zCWay@@UAEXPAVzCWorld@@@Z
        vfunc f03_GetChasm;          // from zCWay  ?GetChasm@zCWay@@UAEMXZ
        vfunc f04_CanJump;           // from zCWay  ?CanJump@zCWay@@UAEHXZ
        vfunc f05_CanBeUsed;         // from oCWay  ?CanBeUsed@oCWay@@UAEHPBVzCVob@@@Z
        vfunc f06_IsObjectOnWay;     // from oCWay  ?IsObjectOnWay@oCWay@@UAEHPBVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E138;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_oCWay& GetTable() {
      MemUnlock;
      return *(vftable_oCWay*)GetAddress();
    }
  };


  struct vftable_oCWorld {
    union {
      vfunc array[31];
      group {
        vfunc f00_GetClassDef;              // from oCWorld  ?_GetClassDef@oCWorld@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                  // from oCWorld  ?Archive@oCWorld@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;                // from oCWorld  ?Unarchive@oCWorld@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;        // from base     
        vfunc f04_LoadWorld;                // from oCWorld  ?LoadWorld@oCWorld@@UAEHABVzSTRING@@W4zTWorldLoadMode@zCWorld@@@Z
        vfunc f05_SaveWorld;                // from oCWorld  ?SaveWorld@oCWorld@@UAEHABVzSTRING@@W4zTWorldSaveMode@zCWorld@@HH@Z
        vfunc f06_MergeVobSubtree;          // from zCWorld  ?MergeVobSubtree@zCWorld@@UAEPAVzCVob@@ABVzSTRING@@PAV2@W4zTWorldLoadMergeMode@1@@Z
        vfunc f07_SaveVobSubtree;           // from zCWorld  ?SaveVobSubtree@zCWorld@@UAEHABVzSTRING@@PAVzCVob@@HH@Z
        vfunc f08_DisposeWorld;             // from oCWorld  ?DisposeWorld@oCWorld@@UAEXXZ
        vfunc f09_DisposeVobs;              // from zCWorld  ?DisposeVobs@zCWorld@@UAEHPAV?$zCTree@VzCVob@@@@@Z
        vfunc f10_DisposeVobsDbg;           // from zCWorld  ?DisposeVobsDbg@zCWorld@@UAEHPAV?$zCTree@VzCVob@@@@@Z
        vfunc f11_DisposeStaticWorld;       // from zCWorld  ?DisposeStaticWorld@zCWorld@@UAEXXZ
        vfunc f12_AddVobAsChild;            // from oCWorld  ?AddVobAsChild@oCWorld@@UAEPAV?$zCTree@VzCVob@@@@PAVzCVob@@PAV2@@Z
        vfunc f13_RemoveVob;                // from oCWorld  ?RemoveVob@oCWorld@@UAEXPAVzCVob@@@Z
        vfunc f14_RemoveVobSubtree;         // from zCWorld  ?RemoveVobSubtree@zCWorld@@UAEXPAVzCVob@@@Z
        vfunc f15_MoveVobSubtreeTo;         // from zCWorld  ?MoveVobSubtreeTo@zCWorld@@UAEXPAVzCVob@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f16_GetPlayerGroup;           // from zCWorld  ?GetPlayerGroup@zCWorld@@UAEPAVzCPlayerGroup@@XZ
        vfunc f17_SearchVob;                // from oCWorld  ?SearchVob@oCWorld@@UAEPAVzCVob@@PAV2@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f18_SearchVobByID;            // from oCWorld  ?SearchVobByID@oCWorld@@UAEPAVzCVob@@KPAV?$zCTree@VzCVob@@@@@Z
        vfunc f19_SearchVobByName;          // from oCWorld  ?SearchVobByName@oCWorld@@UAEPAVzCVob@@ABVzSTRING@@@Z
        vfunc f20_SearchVobListByName;      // from oCWorld  ?SearchVobListByName@oCWorld@@UAEXABVzSTRING@@AAV?$zCArray@PAVzCVob@@@@@Z
        vfunc f21_SearchVobListByClass;     // from zCWorld  ?SearchVobListByClass@zCWorld@@UAEXPAVzCClassDef@@AAV?$zCArray@PAVzCVob@@@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f22_SearchVobListByBaseClass; // from zCWorld  ?SearchVobListByBaseClass@zCWorld@@UAEXPAVzCClassDef@@AAV?$zCArray@PAVzCVob@@@@PAV?$zCTree@VzCVob@@@@@Z
        vfunc f23_VobAddedToWorld;          // from zCWorld  ?VobAddedToWorld@zCWorld@@MAEXPAVzCVob@@@Z
        vfunc f24_VobRemovedFromWorld;      // from zCWorld  ?VobRemovedFromWorld@zCWorld@@MAEXPAVzCVob@@@Z
        vfunc f25_RenderWaynet;             // from zCWorld  ?RenderWaynet@zCWorld@@MAEXPAVzCCamera@@@Z
        vfunc f26_CreateVob;                // from oCWorld  ?CreateVob@oCWorld@@UAEPAVoCVob@@W4zTVobType@@H@Z
        vfunc f27_InsertVobInWorld;         // from oCWorld  ?InsertVobInWorld@oCWorld@@UAEXPAVzCVob@@@Z
        vfunc f28_EnableVob;                // from oCWorld  ?EnableVob@oCWorld@@UAEXPAVzCVob@@0@Z
        vfunc f29_DisableVob;               // from oCWorld  ?DisableVob@oCWorld@@UAEXPAVzCVob@@@Z
        vfunc f30_TraverseVobList;          // from oCWorld  ?TraverseVobList@oCWorld@@UAEXAAVzCVobCallback@@PAX@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E174;
    }

    static uint GetFuncsNum() {
      return 31;
    }

    static vftable_oCWorld& GetTable() {
      MemUnlock;
      return *(vftable_oCWorld*)GetAddress();
    }
  };


  struct vftable_zCConsole {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCConsole  ?HandleEvent@zCConsole@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E220;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCConsole& GetTable() {
      MemUnlock;
      return *(vftable_zCConsole*)GetAddress();
    }
  };


  struct vftable_zCEventManager {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;        // from zCEventManager  ?_GetClassDef@zCEventManager@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;            // from zCEventManager  ?Archive@zCEventManager@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;          // from zCEventManager  ?Unarchive@zCEventManager@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;  // from base            
        vfunc f04_OnTrigger;          // from zCEventManager  ?OnTrigger@zCEventManager@@UAEXPAVzCVob@@0@Z
        vfunc f05_OnUntrigger;        // from zCEventManager  ?OnUntrigger@zCEventManager@@UAEXPAVzCVob@@0@Z
        vfunc f06_OnTouch;            // from zCEventManager  ?OnTouch@zCEventManager@@UAEXPAVzCVob@@@Z
        vfunc f07_OnUntouch;          // from zCEventManager  ?OnUntouch@zCEventManager@@UAEXPAVzCVob@@@Z
        vfunc f08_OnTouchLevel;       // from zCEventManager  ?OnTouchLevel@zCEventManager@@UAEXXZ
        vfunc f09_OnDamage;           // from zCEventManager  ?OnDamage@zCEventManager@@UAEXPAVzCVob@@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;          // from zCEventManager  ?OnMessage@zCEventManager@@UAEXPAVzCEventMessage@@PAVzCVob@@@Z
        vfunc f11_Clear;              // from zCEventManager  ?Clear@zCEventManager@@UAEXXZ
        vfunc f12_IsEmpty;            // from zCEventManager  ?IsEmpty@zCEventManager@@UAEHH@Z
        vfunc f13_GetCutsceneMode;    // from zCEventManager  ?GetCutsceneMode@zCEventManager@@UAEHXZ
        vfunc f14_SetCutscene;        // from zCEventManager  ?SetCutscene@zCEventManager@@UAEXPAVzCCutscene@@@Z
        vfunc f15_GetCutscene;        // from zCEventManager  ?GetCutscene@zCEventManager@@UAEPAVzCCutscene@@XZ
        vfunc f16_IsRunning;          // from zCEventManager  ?IsRunning@zCEventManager@@UAEHPAVzCEventMessage@@@Z
        vfunc f17_SetActive;          // from zCEventManager  ?SetActive@zCEventManager@@UAEXH@Z
        vfunc f18_GetNumMessages;     // from zCEventManager  ?GetNumMessages@zCEventManager@@UAEHXZ
        vfunc f19_GetEventMessage;    // from zCEventManager  ?GetEventMessage@zCEventManager@@UAEPAVzCEventMessage@@H@Z
        vfunc f20_GetActiveMessage;   // from zCEventManager  ?GetActiveMessage@zCEventManager@@UAEPAVzCEventMessage@@XZ
        vfunc f21_ShowList;           // from zCEventManager  ?ShowList@zCEventManager@@UAEXHH@Z
        vfunc f22_GetNetVobControl;   // from zCEventManager  ?GetNetVobControl@zCEventManager@@UAEPAVzCNetVobControl@@H@Z
        vfunc f23_RemoveFromList;     // from zCEventManager  ?RemoveFromList@zCEventManager@@MAEXPAVzCEventMessage@@@Z
        vfunc f24_InsertInList;       // from zCEventManager  ?InsertInList@zCEventManager@@MAEXPAVzCEventMessage@@@Z
        vfunc f25_ProcessMessageList; // from zCEventManager  ?ProcessMessageList@zCEventManager@@MAEXXZ
        vfunc f26_SendMessageToHost;  // from zCEventManager  ?SendMessageToHost@zCEventManager@@MAEXPAVzCEventMessage@@PAVzCVob@@1@Z
        vfunc f27_Delete;             // from zCEventManager  ?Delete@zCEventManager@@MAEXPAVzCEventMessage@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E23C;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCEventManager& GetTable() {
      MemUnlock;
      return *(vftable_zCEventManager*)GetAddress();
    }
  };


  struct vftable_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E2FC;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCView_for_zCInputCallback {
    union {
      vfunc array[1];
      group {
        vfunc f00_HandleEvent; // from zCInputCallback  ?HandleEvent@zCInputCallback@@UAEHH@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E304;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCView_for_zCInputCallback& GetTable() {
      MemUnlock;
      return *(vftable_zCView_for_zCInputCallback*)GetAddress();
    }
  };


  struct vftable_zCView_for_zCViewBase {
    union {
      vfunc array[12];
      group {
        vfunc f00_anx;               // from zCView      ?anx@zCView@@UAEHH@Z
        vfunc f01_any;               // from zCView      ?any@zCView@@UAEHH@Z
        vfunc f02_nax;               // from zCView      ?nax@zCView@@UAEHH@Z
        vfunc f03_nay;               // from zCView      ?nay@zCView@@UAEHH@Z
        vfunc f04_ClipLine;          // from zCView      ?ClipLine@zCView@@UAEHAAH000@Z
        vfunc f05_Line;              // from zCView      ?Line@zCView@@UAEXHHHHABUzCOLOR@@@Z
        vfunc f06_GetViewport;       // from zCView      ?GetViewport@zCView@@UAIXAAH000@Z
        vfunc f07_FillZBuffer;       // from zCViewBase  ?FillZBuffer@zCViewBase@@UAEXXZ
        vfunc f08_GetCode;           // from zCView      ?GetCode@zCView@@EAEHHH@Z
        vfunc f09_scalar_destructor; // from base        
        vfunc f10_Blit;              // from zCView      ?Blit@zCView@@UAEXXZ
        vfunc f11_DrawItems;         // from zCView      ?DrawItems@zCView@@UAEXXZ
      } names;
    };

    static uint GetAddress() {
      return 0x0083E30C;
    }

    static uint GetFuncsNum() {
      return 12;
    }

    static vftable_zCView_for_zCViewBase& GetTable() {
      MemUnlock;
      return *(vftable_zCView_for_zCViewBase*)GetAddress();
    }
  };


  struct vftable_zCViewText {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0083E344;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCViewText& GetTable() {
      MemUnlock;
      return *(vftable_zCViewText*)GetAddress();
    }
  };


  struct vftable_zCVobWaypoint {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobWaypoint  ?_GetClassDef@zCVobWaypoint@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob          ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob          ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base           
        vfunc f04_OnTrigger;               // from zCVob          ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob          ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob          ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob          ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob          ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob          ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob          ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob          ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob          ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob          ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob          ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob          ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob          ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob          ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob          ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob          ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob          ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob          ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob          ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob          ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob          ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob          ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob          ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E364;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobWaypoint& GetTable() {
      MemUnlock;
      return *(vftable_zCVobWaypoint*)GetAddress();
    }
  };


  struct vftable_zCWayNet {
    union {
      vfunc array[4];
      group {
        vfunc f00_GetClassDef;       // from zCWayNet  ?_GetClassDef@zCWayNet@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCWayNet  ?Archive@zCWayNet@@UAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCWayNet  ?Unarchive@zCWayNet@@UAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base      
      } names;
    };

    static uint GetAddress() {
      return 0x0083E3D8;
    }

    static uint GetFuncsNum() {
      return 4;
    }

    static vftable_zCWayNet& GetTable() {
      MemUnlock;
      return *(vftable_zCWayNet*)GetAddress();
    }
  };


  struct vftable_zCWay {
    union {
      vfunc array[7];
      group {
        vfunc f00_scalar_destructor; // from base   
        vfunc f01_Init;              // from zCWay  ?Init@zCWay@@UAEXPAVzCWaypoint@@0@Z
        vfunc f02_CalcProperties;    // from zCWay  ?CalcProperties@zCWay@@UAEXPAVzCWorld@@@Z
        vfunc f03_GetChasm;          // from zCWay  ?GetChasm@zCWay@@UAEMXZ
        vfunc f04_CanJump;           // from zCWay  ?CanJump@zCWay@@UAEHXZ
        vfunc f05_CanBeUsed;         // from zCWay  ?CanBeUsed@zCWay@@UAEHPBVzCVob@@@Z
        vfunc f06_IsObjectOnWay;     // from zCWay  ?IsObjectOnWay@zCWay@@UAEHPBVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E3EC;
    }

    static uint GetFuncsNum() {
      return 7;
    }

    static vftable_zCWay& GetTable() {
      MemUnlock;
      return *(vftable_zCWay*)GetAddress();
    }
  };


  struct vftable_zCWaypoint {
    union {
      vfunc array[5];
      group {
        vfunc f00_GetClassDef;       // from zCWaypoint  ?_GetClassDef@zCWaypoint@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;           // from zCWaypoint  ?Archive@zCWaypoint@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;         // from zCWaypoint  ?Unarchive@zCWaypoint@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor; // from base        
        vfunc f04_CanBeUsed;         // from zCWaypoint  ?CanBeUsed@zCWaypoint@@UAEHPBVzCVob@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E410;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_zCWaypoint& GetTable() {
      MemUnlock;
      return *(vftable_zCWaypoint*)GetAddress();
    }
  };


  struct vftable_zCRoute {
    union {
      vfunc array[1];
      group {
        vfunc f00_scalar_destructor; // from base  
      } names;
    };

    static uint GetAddress() {
      return 0x0083E428;
    }

    static uint GetFuncsNum() {
      return 1;
    }

    static vftable_zCRoute& GetTable() {
      MemUnlock;
      return *(vftable_zCRoute*)GetAddress();
    }
  };


  struct vftable_zCVobSpot {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobSpot  ?_GetClassDef@zCVobSpot@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob      ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob      ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base       
        vfunc f04_OnTrigger;               // from zCVob      ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob      ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob      ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob      ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob      ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob      ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob      ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob      ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob      ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob      ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob      ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob      ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob      ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob      ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob      ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob      ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob      ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob      ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob      ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob      ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob      ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob      ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob      ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob      ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E434;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobSpot& GetTable() {
      MemUnlock;
      return *(vftable_zCVobSpot*)GetAddress();
    }
  };


  struct vftable_zCVobStartpoint {
    union {
      vfunc array[28];
      group {
        vfunc f00_GetClassDef;             // from zCVobStartpoint  ?_GetClassDef@zCVobStartpoint@@EBEPAVzCClassDef@@XZ
        vfunc f01_Archive;                 // from zCVob            ?Archive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f02_Unarchive;               // from zCVob            ?Unarchive@zCVob@@MAEXAAVzCArchiver@@@Z
        vfunc f03_scalar_destructor;       // from base             
        vfunc f04_OnTrigger;               // from zCVob            ?OnTrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f05_OnUntrigger;             // from zCVob            ?OnUntrigger@zCVob@@UAEXPAV1@0@Z
        vfunc f06_OnTouch;                 // from zCVob            ?OnTouch@zCVob@@UAEXPAV1@@Z
        vfunc f07_OnUntouch;               // from zCVob            ?OnUntouch@zCVob@@UAEXPAV1@@Z
        vfunc f08_OnTouchLevel;            // from zCVob            ?OnTouchLevel@zCVob@@UAEXXZ
        vfunc f09_OnDamage;                // from zCVob            ?OnDamage@zCVob@@UAEXPAV1@0MHABVzVEC3@@@Z
        vfunc f10_OnMessage;               // from zCVob            ?OnMessage@zCVob@@UAEXPAVzCEventMessage@@PAV1@@Z
        vfunc f11_OnTick;                  // from zCVob            ?OnTick@zCVob@@UAEXXZ
        vfunc f12_OnTimer;                 // from zCVob            ?OnTimer@zCVob@@UAEXXZ
        vfunc f13_PostLoad;                // from zCVob            ?PostLoad@zCVob@@UAEXXZ
        vfunc f14_GetCharacterClass;       // from zCVob            ?GetCharacterClass@zCVob@@UAE?AW4zTVobCharClass@1@XZ
        vfunc f15_SetSleepingMode;         // from zCVob            ?SetSleepingMode@zCVob@@UAEXW4zTVobSleepingMode@@@Z
        vfunc f16_EndMovement;             // from zCVob            ?EndMovement@zCVob@@UAEXH@Z
        vfunc f17_CanThisCollideWith;      // from zCVob            ?CanThisCollideWith@zCVob@@UAEHPAV1@@Z
        vfunc f18_Render;                  // from zCVob            ?Render@zCVob@@UAIHAAUzTRenderContext@@@Z
        vfunc f19_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXABVzSTRING@@@Z
        vfunc f20_SetVisual;               // from zCVob            ?SetVisual@zCVob@@UAEXPAVzCVisual@@@Z
        vfunc f21_GetScriptInstance;       // from zCVob            ?GetScriptInstance@zCVob@@UAEHAAPAVzSTRING@@AAH@Z
        vfunc f22_SetByScriptInstance;     // from zCVob            ?SetByScriptInstance@zCVob@@UAEHPBVzSTRING@@H@Z
        vfunc f23_GetCSStateFlags;         // from zCVob            ?GetCSStateFlags@zCVob@@UAEHXZ
        vfunc f24_TraceRay;                // from zCVob            ?TraceRay@zCVob@@UAEHABVzVEC3@@0HAAUzTTraceRayReport@@@Z
        vfunc f25_GetTriggerTarget;        // from zCVob            ?GetTriggerTarget@zCVob@@UBEPBVzSTRING@@H@Z
        vfunc f26_ThisVobAddedToWorld;     // from zCVob            ?ThisVobAddedToWorld@zCVob@@UAEXPAVzCWorld@@@Z
        vfunc f27_ThisVobRemovedFromWorld; // from zCVob            ?ThisVobRemovedFromWorld@zCVob@@UAEXPAVzCWorld@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x0083E4AC;
    }

    static uint GetFuncsNum() {
      return 28;
    }

    static vftable_zCVobStartpoint& GetTable() {
      MemUnlock;
      return *(vftable_zCVobStartpoint*)GetAddress();
    }
  };


  struct vftable_CSurfaceFormatList {
    union {
      vfunc array[5];
      group {
        vfunc f00_CleanupList;                 // from ListT<CSurfaceFormatNode>  ?CleanupList@?$ListT@VCSurfaceFormatNode@@@@UAEXXZ
        vfunc f01_Prepend;                     // from ListT<CSurfaceFormatNode>  ?Prepend@?$ListT@VCSurfaceFormatNode@@@@UAEXPAVCSurfaceFormatNode@@@Z
        vfunc f02_Unlink;                      // from ListT<CSurfaceFormatNode>  ?Unlink@?$ListT@VCSurfaceFormatNode@@@@UAEXPAVCSurfaceFormatNode@@@Z
        vfunc f03_LeftBelongsCloserToListHead; // from ListT<CSurfaceFormatNode>  ?LeftBelongsCloserToListHead@?$ListT@VCSurfaceFormatNode@@@@UAEHPAVCSurfaceFormatNode@@0@Z
        vfunc f04_OrderedInsert;               // from ListT<CSurfaceFormatNode>  ?OrderedInsert@?$ListT@VCSurfaceFormatNode@@@@UAEXPAVCSurfaceFormatNode@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00842368;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_CSurfaceFormatList& GetTable() {
      MemUnlock;
      return *(vftable_CSurfaceFormatList*)GetAddress();
    }
  };


  struct vftable_CD3duDeviceList {
    union {
      vfunc array[5];
      group {
        vfunc f00_CleanupList;                 // from ListT<CD3duDeviceNode>  ?CleanupList@?$ListT@VCD3duDeviceNode@@@@UAEXXZ
        vfunc f01_Prepend;                     // from ListT<CD3duDeviceNode>  ?Prepend@?$ListT@VCD3duDeviceNode@@@@UAEXPAVCD3duDeviceNode@@@Z
        vfunc f02_Unlink;                      // from ListT<CD3duDeviceNode>  ?Unlink@?$ListT@VCD3duDeviceNode@@@@UAEXPAVCD3duDeviceNode@@@Z
        vfunc f03_LeftBelongsCloserToListHead; // from ListT<CD3duDeviceNode>  ?LeftBelongsCloserToListHead@?$ListT@VCD3duDeviceNode@@@@UAEHPAVCD3duDeviceNode@@0@Z
        vfunc f04_OrderedInsert;               // from ListT<CD3duDeviceNode>  ?OrderedInsert@?$ListT@VCD3duDeviceNode@@@@UAEXPAVCD3duDeviceNode@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008423FC;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_CD3duDeviceList& GetTable() {
      MemUnlock;
      return *(vftable_CD3duDeviceList*)GetAddress();
    }
  };


  struct vftable_CRefreshRateList {
    union {
      vfunc array[5];
      group {
        vfunc f00_CleanupList;                 // from ListT<CRefreshRateNode>  ?CleanupList@?$ListT@VCRefreshRateNode@@@@UAEXXZ
        vfunc f01_Prepend;                     // from ListT<CRefreshRateNode>  ?Prepend@?$ListT@VCRefreshRateNode@@@@UAEXPAVCRefreshRateNode@@@Z
        vfunc f02_Unlink;                      // from ListT<CRefreshRateNode>  ?Unlink@?$ListT@VCRefreshRateNode@@@@UAEXPAVCRefreshRateNode@@@Z
        vfunc f03_LeftBelongsCloserToListHead; // from CRefreshRateList         ?LeftBelongsCloserToListHead@CRefreshRateList@@UAEHPAVCRefreshRateNode@@0@Z
        vfunc f04_OrderedInsert;               // from ListT<CRefreshRateNode>  ?OrderedInsert@?$ListT@VCRefreshRateNode@@@@UAEXPAVCRefreshRateNode@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00842584;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_CRefreshRateList& GetTable() {
      MemUnlock;
      return *(vftable_CRefreshRateList*)GetAddress();
    }
  };


  struct vftable_CD3duContextList {
    union {
      vfunc array[5];
      group {
        vfunc f00_CleanupList;                 // from ListT<CD3duContextNode>  ?CleanupList@?$ListT@VCD3duContextNode@@@@UAEXXZ
        vfunc f01_Prepend;                     // from ListT<CD3duContextNode>  ?Prepend@?$ListT@VCD3duContextNode@@@@UAEXPAVCD3duContextNode@@@Z
        vfunc f02_Unlink;                      // from ListT<CD3duContextNode>  ?Unlink@?$ListT@VCD3duContextNode@@@@UAEXPAVCD3duContextNode@@@Z
        vfunc f03_LeftBelongsCloserToListHead; // from ListT<CD3duContextNode>  ?LeftBelongsCloserToListHead@?$ListT@VCD3duContextNode@@@@UAEHPAVCD3duContextNode@@0@Z
        vfunc f04_OrderedInsert;               // from ListT<CD3duContextNode>  ?OrderedInsert@?$ListT@VCD3duContextNode@@@@UAEXPAVCD3duContextNode@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00842598;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_CD3duContextList& GetTable() {
      MemUnlock;
      return *(vftable_CD3duContextList*)GetAddress();
    }
  };


  struct vftable_CD3duContext {
    union {
      vfunc array[25];
      group {
        vfunc f00_QueryInterface;    // from CD3duContext  ?QueryInterface@CD3duContext@@UAGJABU_GUID@@PAPAX@Z
        vfunc f01_AddRef;            // from CD3duContext  ?AddRef@CD3duContext@@UAGKXZ
        vfunc f02_Release;           // from CD3duContext  ?Release@CD3duContext@@UAGKXZ
        vfunc f03_GetDD;             // from CD3duContext  ?GetDD@CD3duContext@@UAGPAUIDirectDraw7@@XZ
        vfunc f04_GetD3D;            // from CD3duContext  ?GetD3D@CD3duContext@@UAGPAUIDirect3D7@@XZ
        vfunc f05_GetD3DDevice;      // from CD3duContext  ?GetD3DDevice@CD3duContext@@UAGPAUIDirect3DDevice7@@XZ
        vfunc f06_GetPrimary;        // from CD3duContext  ?GetPrimary@CD3duContext@@UAGPAUIDirectDrawSurface7@@XZ
        vfunc f07_GetZBuffer;        // from CD3duContext  ?GetZBuffer@CD3duContext@@UAGPAUIDirectDrawSurface7@@XZ
        vfunc f08_GetBackBuffer;     // from CD3duContext  ?GetBackBuffer@CD3duContext@@UAGPAUIDirectDrawSurface7@@K@Z
        vfunc f09_GetWindow;         // from CD3duContext  ?GetWindow@CD3duContext@@UAGPAUHWND_@@XZ
        vfunc f10_GetFocusWindow;    // from CD3duContext  ?GetFocusWindow@CD3duContext@@UAGPAUHWND_@@XZ
        vfunc f11_GetDeviceIndex;    // from CD3duContext  ?GetDeviceIndex@CD3duContext@@UAGJPAK0@Z
        vfunc f12_GetNumBackBuffers; // from CD3duContext  ?GetNumBackBuffers@CD3duContext@@UAGKXZ
        vfunc f13_GetNumBits;        // from CD3duContext  ?GetNumBits@CD3duContext@@UAGJPAK000@Z
        vfunc f14_GetBufferSize;     // from CD3duContext  ?GetBufferSize@CD3duContext@@UAGJPAK0@Z
        vfunc f15_GetCreationFlags;  // from CD3duContext  ?GetCreationFlags@CD3duContext@@UAGKXZ
        vfunc f16_GetRefreshRate;    // from CD3duContext  ?GetRefreshRate@CD3duContext@@UAGKXZ
        vfunc f17_RestoreSurfaces;   // from CD3duContext  ?RestoreSurfaces@CD3duContext@@UAGJXZ
        vfunc f18_Resize;            // from CD3duContext  ?Resize@CD3duContext@@UAGJKK@Z
        vfunc f19_UpdateFrame;       // from CD3duContext  ?UpdateFrame@CD3duContext@@UAGJK@Z
        vfunc f20_DrawDebugText;     // from CD3duContext  ?DrawDebugText@CD3duContext@@UAGJMMKPAD@Z
        vfunc f21_Clear;             // from CD3duContext  ?Clear@CD3duContext@@UAGJK@Z
        vfunc f22_SetClearColor;     // from CD3duContext  ?SetClearColor@CD3duContext@@UAGJK@Z
        vfunc f23_SetClearDepth;     // from CD3duContext  ?SetClearDepth@CD3duContext@@UAGJM@Z
        vfunc f24_SetClearStencil;   // from CD3duContext  ?SetClearStencil@CD3duContext@@UAGJK@Z
      } names;
    };

    static uint GetAddress() {
      return 0x00842AF8;
    }

    static uint GetFuncsNum() {
      return 25;
    }

    static vftable_CD3duContext& GetTable() {
      MemUnlock;
      return *(vftable_CD3duContext*)GetAddress();
    }
  };


  struct vftable_CVideoModeList {
    union {
      vfunc array[5];
      group {
        vfunc f00_CleanupList;                 // from ListT<CVideoModeNode>  ?CleanupList@?$ListT@VCVideoModeNode@@@@UAEXXZ
        vfunc f01_Prepend;                     // from ListT<CVideoModeNode>  ?Prepend@?$ListT@VCVideoModeNode@@@@UAEXPAVCVideoModeNode@@@Z
        vfunc f02_Unlink;                      // from ListT<CVideoModeNode>  ?Unlink@?$ListT@VCVideoModeNode@@@@UAEXPAVCVideoModeNode@@@Z
        vfunc f03_LeftBelongsCloserToListHead; // from CVideoModeList         ?LeftBelongsCloserToListHead@CVideoModeList@@UAEHPAVCVideoModeNode@@0@Z
        vfunc f04_OrderedInsert;               // from ListT<CVideoModeNode>  ?OrderedInsert@?$ListT@VCVideoModeNode@@@@UAEXPAVCVideoModeNode@@@Z
      } names;
    };

    static uint GetAddress() {
      return 0x008437D8;
    }

    static uint GetFuncsNum() {
      return 5;
    }

    static vftable_CVideoModeList& GetTable() {
      MemUnlock;
      return *(vftable_CVideoModeList*)GetAddress();
    }
  };

} // namespace Gothic_II_Addon

#undef MemUnlock
#endif // __VFTABLE_STRUCTS_H__VER3__
#endif // __G2A