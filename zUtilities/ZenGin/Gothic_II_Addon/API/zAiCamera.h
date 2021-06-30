// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA_H__VER3__
#define __ZAI_CAMERA_H__VER3__

#include "zAi.h"
#include "zGrafix.h"
#include "zBVolume.h"

namespace Gothic_II_Addon {
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
    float targetAlpha;
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
    int targetInPortalRoom;

    void zCAICamera_OnInit()                                                          zCall( 0x0049FD30 );
    zCAICamera()                                                                      zInit( zCAICamera_OnInit() );
    void StartUp()                                                                    zCall( 0x004A0230 );
    void CleanUp()                                                                    zCall( 0x004A0850 );
    float GetBestRange()                                                              zCall( 0x004A08F0 );
    float GetMinRange()                                                               zCall( 0x004A09A0 );
    float GetMaxRange()                                                               zCall( 0x004A09B0 );
    void SetMode( zSTRING&, zCArray<zCVob*> )                                         zCall( 0x004A09C0 );
    zSTRING GetMode()                                                                 zCall( 0x004A0D40 );
    int IsModeActive( zSTRING& )                                                      zCall( 0x004A0D90 );
    int IsModeAvailable( zSTRING const& )                                             zCall( 0x004A0E10 );
    void ReceiveMsg( zTAICamMsg const& )                                              zCall( 0x004A0E30 );
    void SetVob( zCVob* )                                                             zCall( 0x004A0E60 );
    void SetTarget( zCVob* )                                                          zCall( 0x004A1120 );
    void SetTargetList( zCArray<zCVob*> )                                             zCall( 0x004A15B0 );
    void ClearTargetList()                                                            zCall( 0x004A1870 );
    void AddTarget( zCVob* )                                                          zCall( 0x004A18F0 );
    void SubTarget( zCVob* )                                                          zCall( 0x004A1A40 );
    int Console_EvalFunc( zSTRING const&, zSTRING& )                                  zCall( 0x004A1AD0 );
    void ParameterChanged()                                                           zCall( 0x004A23B0 );
    void CalcFirstPosition()                                                          zCall( 0x004A2550 );
    int SetByScript( zSTRING& )                                                       zCall( 0x004A26E0 );
    zSTRING SetByScriptLine( zSTRING& )                                               zCall( 0x004A2D30 );
    void CreateInstance( zSTRING& )                                                   zCall( 0x004A3670 );
    void AI_LookingCam()                                                              zCall( 0x004A3690 );
    void AI_FirstPerson()                                                             zCall( 0x004A40E0 );
    void AI_Normal()                                                                  zCall( 0x004A4370 );
    zVEC3& GetCamSysFirstPos()                                                        zCall( 0x004A4570 );
    void SetHintTargetInPortalRoom( int )                                             zCall( 0x004A4580 );
    void CheckKeys()                                                                  zCall( 0x004A45C0 );
    void SetRotateEnabled( int )                                                      zCall( 0x004A54E0 );
    void StartupDialogCam()                                                           zCall( 0x004B1940 );
    void InitDialogCam()                                                              zCall( 0x004B1EE0 );
    void SetDialogCamDuration( float )                                                zCall( 0x004B1F20 );
    void ReleaseLastDialogCam()                                                       zCall( 0x004B1F30 );
    zCCSCamera* PickPreset( zSTRING, zCArray<zCCSCamera*> const& )                    zCall( 0x004B1FF0 );
    void StartDialogCam( int )                                                        zCall( 0x004B20F0 );
    int DialogPresetIsValid( zCCSCamera* )                                            zCall( 0x004B4290 );
    void InitHelperVobs()                                                             zCall( 0x004BB4A0 );
    void DeleteHelperVobs()                                                           zCall( 0x004BB740 );
    void ShowDebug()                                                                  zCall( 0x004BB7B0 );
    void DrawClipLine( zVEC3 const&, zVEC3 const&, zCOLOR )                           zCall( 0x004BCC00 );
    zTBSphere3D CalcMinimumBSphere( zCArray<zVEC3>& )                                 zCall( 0x004BCE60 );
    int CheckUnderWaterFX()                                                           zCall( 0x004BD2E0 );
    zVEC3& CalcAziElevRange( float const&, float const&, float const&, zMAT4 const& ) zCall( 0x004BD7F0 );
    zSTRING GetPreviousMode()                                                         zCall( 0x0069D800 );
    static zCAICamera* GetCurrent()                                                   zCall( 0x0049FD20 );
    static zCAICamera* Create()                                                       zCall( 0x004A0180 );
    static void GlobalStartUp()                                                       zCall( 0x004A0880 );
    static void GlobalCleanUp()                                                       zCall( 0x004A0890 );
    static zCObject* _CreateNewInstance()                                             zCall( 0x004A56E0 );
    static void GlobalDialogCamCleanUp()                                              zCall( 0x004B1DE0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x0049FF80 );
    virtual ~zCAICamera()                                                             zCall( 0x0049FFC0 );
    virtual void DoAI( zCVob*, int& )                                                 zCall( 0x004A4FB0 );

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

} // namespace Gothic_II_Addon

#endif // __ZAI_CAMERA_H__VER3__