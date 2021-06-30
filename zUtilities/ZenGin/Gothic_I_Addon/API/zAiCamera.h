// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA_H__VER1__
#define __ZAI_CAMERA_H__VER1__

#include "zAi.h"
#include "zBVolume.h"

namespace Gothic_I_Addon {
  const int MAX_CTRL_VOBS = 80;

  class zCAICamera : public zCAIBase {
  public:
    zCLASS_DECLARATION( zCAICamera )

    int d_showDots;
    int pathDetectCollision;
    float bestRange;
    float minRange;
    float maxRange;
    float bestRotX;
    float minRotX;
    float maxRotX;
    float bestRotY;
    float minRotY;
    float maxRotY;
    float bestRotZ;
    float minRotZ;
    float maxRotZ;
    float rotOffsetX;
    float rotOffsetY;
    float rotOffsetZ;
    float focusOffsetX;
    float focusOffsetY;
    float focusOffsetZ;
    float veloTrans;
    float veloRot;
    int translate;
    int rotate;
    int collision;
    unsigned char endOfDScript;
    zCArray<zCVob*> targetVobList;
    zCVob* camVob;
    zCVob* target;
    int numTargets;
    zSTRING oldCamSys;
    int sysChanged;
    int playerIsMovable;
    int followIdealPos;
    float dialogCamDuration;
    int numOUsSpoken;
    int numDialogCamTakes;
    int lastNumDialogCamTakes;
    int lastDialogCamSide;
    int firstSpeakerWasPC;
    zCCSCamera* dialogCam;
    zSTRING lastPresetName;
    int raysCasted;
    int underWater;
    int inCutsceneMode;
    zSTRING debugS;
    int showPath;
    zCVob* focusVob;
    zCVob* ctrlDot[MAX_CTRL_VOBS];
    zCPathSearch* pathSearch;
    zCMovementTracker* moveTracker;
    zSPathSearchResult* evasionSearchReport;
    zSTRING curcammode;
    float npcVolumeRangeOffset;
    float camDistOffset;
    zVEC3 camSysFirstPos;
    int firstPerson;

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