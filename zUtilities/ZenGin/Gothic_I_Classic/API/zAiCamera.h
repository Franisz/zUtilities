// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA_H__VER0__
#define __ZAI_CAMERA_H__VER0__

#include "zAi.h"
#include "zGrafix.h"
#include "zBVolume.h"

namespace Gothic_I_Classic {
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

    void zCAICamera_OnInit()                                                          zCall( 0x004988F0 );
    zCAICamera()                                                                      zInit( zCAICamera_OnInit() );
    void StartUp()                                                                    zCall( 0x00498DF0 );
    void CleanUp()                                                                    zCall( 0x004993C0 );
    float GetBestRange()                                                              zCall( 0x00499460 );
    float GetMinRange()                                                               zCall( 0x004994C0 );
    float GetMaxRange()                                                               zCall( 0x004994D0 );
    void SetMode( zSTRING&, zCArray<zCVob*> )                                         zCall( 0x004994E0 );
    zSTRING GetMode()                                                                 zCall( 0x004997F0 );
    int IsModeActive( zSTRING& )                                                      zCall( 0x00499840 );
    int IsModeAvailable( zSTRING const& )                                             zCall( 0x004998C0 );
    void ReceiveMsg( zTAICamMsg const& )                                              zCall( 0x004998E0 );
    void SetVob( zCVob* )                                                             zCall( 0x00499910 );
    void SetTarget( zCVob* )                                                          zCall( 0x00499BC0 );
    void SetTargetList( zCArray<zCVob*> )                                             zCall( 0x00499FC0 );
    void ClearTargetList()                                                            zCall( 0x0049A280 );
    void AddTarget( zCVob* )                                                          zCall( 0x0049A300 );
    void SubTarget( zCVob* )                                                          zCall( 0x0049A470 );
    int Console_EvalFunc( zSTRING const&, zSTRING& )                                  zCall( 0x0049A500 );
    void ParameterChanged()                                                           zCall( 0x0049ADD0 );
    void CalcFirstPosition()                                                          zCall( 0x0049AF30 );
    int SetByScript( zSTRING& )                                                       zCall( 0x0049B070 );
    zSTRING SetByScriptLine( zSTRING& )                                               zCall( 0x0049B6A0 );
    void CreateInstance( zSTRING& )                                                   zCall( 0x0049BFC0 );
    void AI_LookingCam()                                                              zCall( 0x0049BFE0 );
    void AI_FirstPerson()                                                             zCall( 0x0049C900 );
    void AI_Normal()                                                                  zCall( 0x0049C990 );
    zVEC3& GetCamSysFirstPos()                                                        zCall( 0x0049CD00 );
    void CheckKeys()                                                                  zCall( 0x0049CD10 );
    void SetRotateEnabled( int )                                                      zCall( 0x0049DBA0 );
    void StartupDialogCam()                                                           zCall( 0x004A9750 );
    void InitDialogCam()                                                              zCall( 0x004A9AB0 );
    void SetDialogCamDuration( float )                                                zCall( 0x004A9AF0 );
    void ReleaseLastDialogCam()                                                       zCall( 0x004A9B00 );
    zCCSCamera* PickPreset( zSTRING, zCArray<zCCSCamera*> const& )                    zCall( 0x004A9BC0 );
    void StartDialogCam( int )                                                        zCall( 0x004A9CC0 );
    int DialogPresetIsValid( zCCSCamera* )                                            zCall( 0x004AB9E0 );
    void InitHelperVobs()                                                             zCall( 0x004B25F0 );
    void DeleteHelperVobs()                                                           zCall( 0x004B28C0 );
    void ShowDebug()                                                                  zCall( 0x004B2930 );
    void DrawClipLine( zVEC3 const&, zVEC3 const&, zCOLOR )                           zCall( 0x004B3B60 );
    zTBSphere3D CalcMinimumBSphere( zCArray<zVEC3>& )                                 zCall( 0x004B3DC0 );
    int CheckUnderWaterFX()                                                           zCall( 0x004B4240 );
    zVEC3& CalcAziElevRange( float const&, float const&, float const&, zMAT4 const& ) zCall( 0x004B4690 );
    static zCAICamera* GetCurrent()                                                   zCall( 0x004988E0 );
    static zCAICamera* Create()                                                       zCall( 0x00498D20 );
    static void GlobalStartUp()                                                       zCall( 0x004993F0 );
    static void GlobalCleanUp()                                                       zCall( 0x00499400 );
    static zCObject* _CreateNewInstance()                                             zCall( 0x0049DDA0 );
    static void GlobalDialogCamCleanUp()                                              zCall( 0x004A99B0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x00498B20 );
    virtual ~zCAICamera()                                                             zCall( 0x00498B60 );
    virtual void DoAI( zCVob*, int& )                                                 zCall( 0x0049D6A0 );


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

} // namespace Gothic_I_Classic

#endif // __ZAI_CAMERA_H__VER0__