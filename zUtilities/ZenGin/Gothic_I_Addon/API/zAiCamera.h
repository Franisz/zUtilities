// Supported with union (c) 2018-2021 Union team

#ifndef __ZAI_CAMERA_H__VER1__
#define __ZAI_CAMERA_H__VER1__

#include "zAi.h"
#include "zBVolume.h"

namespace Gothic_I_Addon {
  const int MAX_CTRL_VOBS = 80;

  // sizeof 294h
  class zCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( zCAICamera )

    int d_showDots;                          // sizeof 04h    offset 24h
    int pathDetectCollision;                 // sizeof 04h    offset 28h
    float bestRange;                         // sizeof 04h    offset 2Ch
    float minRange;                          // sizeof 04h    offset 30h
    float maxRange;                          // sizeof 04h    offset 34h
    float bestRotX;                          // sizeof 04h    offset 38h
    float minRotX;                           // sizeof 04h    offset 3Ch
    float maxRotX;                           // sizeof 04h    offset 40h
    float bestRotY;                          // sizeof 04h    offset 44h
    float minRotY;                           // sizeof 04h    offset 48h
    float maxRotY;                           // sizeof 04h    offset 4Ch
    float bestRotZ;                          // sizeof 04h    offset 50h
    float minRotZ;                           // sizeof 04h    offset 54h
    float maxRotZ;                           // sizeof 04h    offset 58h
    float rotOffsetX;                        // sizeof 04h    offset 5Ch
    float rotOffsetY;                        // sizeof 04h    offset 60h
    float rotOffsetZ;                        // sizeof 04h    offset 64h
    float focusOffsetX;                      // sizeof 04h    offset 68h
    float focusOffsetY;                      // sizeof 04h    offset 6Ch
    float focusOffsetZ;                      // sizeof 04h    offset 70h
    float veloTrans;                         // sizeof 04h    offset 74h
    float veloRot;                           // sizeof 04h    offset 78h
    int translate;                           // sizeof 04h    offset 7Ch
    int rotate;                              // sizeof 04h    offset 80h
    int collision;                           // sizeof 04h    offset 84h
    unsigned char endOfDScript;              // sizeof 01h    offset 88h
    zCArray<zCVob*> targetVobList;           // sizeof 0Ch    offset 8Ch
    zCVob* camVob;                           // sizeof 04h    offset 98h
    zCVob* target;                           // sizeof 04h    offset 9Ch
    int numTargets;                          // sizeof 04h    offset A0h
    zSTRING oldCamSys;                       // sizeof 14h    offset A4h
    int sysChanged;                          // sizeof 04h    offset B8h
    int playerIsMovable;                     // sizeof 04h    offset BCh
    int followIdealPos;                      // sizeof 04h    offset C0h
    float dialogCamDuration;                 // sizeof 04h    offset C4h
    int numOUsSpoken;                        // sizeof 04h    offset C8h
    int numDialogCamTakes;                   // sizeof 04h    offset CCh
    int lastNumDialogCamTakes;               // sizeof 04h    offset D0h
    int lastDialogCamSide;                   // sizeof 04h    offset D4h
    int firstSpeakerWasPC;                   // sizeof 04h    offset D8h
    zCCSCamera* dialogCam;                   // sizeof 04h    offset DCh
    zSTRING lastPresetName;                  // sizeof 14h    offset E0h
    int raysCasted;                          // sizeof 04h    offset F4h
    int underWater;                          // sizeof 04h    offset F8h
    int inCutsceneMode;                      // sizeof 04h    offset FCh
    zSTRING debugS;                          // sizeof 14h    offset 100h
    int showPath;                            // sizeof 04h    offset 114h
    zCVob* focusVob;                         // sizeof 04h    offset 118h
    zCVob* ctrlDot[MAX_CTRL_VOBS];           // sizeof 140h   offset 11Ch
    zCPathSearch* pathSearch;                // sizeof 04h    offset 25Ch
    zCMovementTracker* moveTracker;          // sizeof 04h    offset 260h
    zSPathSearchResult* evasionSearchReport; // sizeof 04h    offset 264h
    zSTRING curcammode;                      // sizeof 14h    offset 268h
    float npcVolumeRangeOffset;              // sizeof 04h    offset 27Ch
    float camDistOffset;                     // sizeof 04h    offset 280h
    zVEC3 camSysFirstPos;                    // sizeof 0Ch    offset 284h
    int firstPerson;                         // sizeof 04h    offset 290h

    void zCAICamera_OnInit()                                                          zCall( 0x004A59C0 );
    zCAICamera()                                                                      zInit( zCAICamera_OnInit() );
    void StartUp()                                                                    zCall( 0x004A5F10 );
    void CleanUp()                                                                    zCall( 0x004A6460 );
    float GetBestRange()                                                              zCall( 0x004A6520 );
    float GetMinRange()                                                               zCall( 0x004A6580 );
    float GetMaxRange()                                                               zCall( 0x004A6590 );
    void SetMode( zSTRING&, zCArray<zCVob*> )                                         zCall( 0x004A65A0 );
    zSTRING GetMode()                                                                 zCall( 0x004A68E0 );
    int IsModeActive( zSTRING& )                                                      zCall( 0x004A6930 );
    int IsModeAvailable( zSTRING const& )                                             zCall( 0x004A69B0 );
    void ReceiveMsg( zTAICamMsg const& )                                              zCall( 0x004A69D0 );
    void SetVob( zCVob* )                                                             zCall( 0x004A6A00 );
    void SetTarget( zCVob* )                                                          zCall( 0x004A6CE0 );
    void SetTargetList( zCArray<zCVob*> )                                             zCall( 0x004A7120 );
    void ClearTargetList()                                                            zCall( 0x004A7400 );
    void AddTarget( zCVob* )                                                          zCall( 0x004A7490 );
    void SubTarget( zCVob* )                                                          zCall( 0x004A75F0 );
    int Console_EvalFunc( zSTRING const&, zSTRING& )                                  zCall( 0x004A7680 );
    void ParameterChanged()                                                           zCall( 0x004A8030 );
    void CalcFirstPosition()                                                          zCall( 0x004A81C0 );
    int SetByScript( zSTRING& )                                                       zCall( 0x004A8330 );
    zSTRING SetByScriptLine( zSTRING& )                                               zCall( 0x004A8A70 );
    void CreateInstance( zSTRING& )                                                   zCall( 0x004A9460 );
    void AI_LookingCam()                                                              zCall( 0x004A9480 );
    void AI_FirstPerson()                                                             zCall( 0x004A9E30 );
    void AI_Normal()                                                                  zCall( 0x004A9EC0 );
    zVEC3& GetCamSysFirstPos()                                                        zCall( 0x004AA2B0 );
    void CheckKeys()                                                                  zCall( 0x004AA2C0 );
    void SetRotateEnabled( int )                                                      zCall( 0x004AB370 );
    void StartupDialogCam()                                                           zCall( 0x004B7650 );
    void InitDialogCam()                                                              zCall( 0x004B79D0 );
    void SetDialogCamDuration( float )                                                zCall( 0x004B7A10 );
    void ReleaseLastDialogCam()                                                       zCall( 0x004B7A20 );
    zCCSCamera* PickPreset( zSTRING, zCArray<zCCSCamera*> const& )                    zCall( 0x004B7AE0 );
    void StartDialogCam( int )                                                        zCall( 0x004B7C30 );
    int DialogPresetIsValid( zCCSCamera* )                                            zCall( 0x004B98D0 );
    void InitHelperVobs()                                                             zCall( 0x004C1050 );
    void DeleteHelperVobs()                                                           zCall( 0x004C1310 );
    void ShowDebug()                                                                  zCall( 0x004C1380 );
    void DrawClipLine( zVEC3 const&, zVEC3 const&, zCOLOR )                           zCall( 0x004C2920 );
    zTBSphere3D CalcMinimumBSphere( zCArray<zVEC3>& )                                 zCall( 0x004C2B80 );
    int CheckUnderWaterFX()                                                           zCall( 0x004C3060 );
    zVEC3& CalcAziElevRange( float const&, float const&, float const&, zMAT4 const& ) zCall( 0x004C35B0 );
    static zCAICamera* GetCurrent()                                                   zCall( 0x004A59B0 );
    static zCAICamera* Create()                                                       zCall( 0x004A5E40 );
    static void GlobalStartUp()                                                       zCall( 0x004A64A0 );
    static void GlobalCleanUp()                                                       zCall( 0x004A64B0 );
    static zCObject* _CreateNewInstance()                                             zCall( 0x004AB590 );
    static void GlobalDialogCamCleanUp()                                              zCall( 0x004B78D0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x004A5C10 );
    virtual ~zCAICamera()                                                             zCall( 0x004A5C50 );
    virtual void DoAI( zCVob*, int& )                                                 zCall( 0x004AADF0 );


    // static properties
    static short int& s_iLookAroundSgn;
    static zCArray<zCCSCamera*>& dialogCamList;
    static float& lookingCamLastAzi;
    static int& lookingCamAziGoalReached;
    static zCAICamera*& current;
    static int& bCreated;
    static int& bCamChanges;

    // user API
    #include "zCAICamera.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZAI_CAMERA_H__VER1__