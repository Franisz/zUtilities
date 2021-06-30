// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA_H__VER2__
#define __ZAI_CAMERA_H__VER2__

#include "zAi.h"
#include "zBVolume.h"

namespace Gothic_II_Classic {
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
    int targetInPortalRoom;

    void zCAICamera_OnInit()                                                          zCall( 0x0049D9D0 );
    zCAICamera()                                                                      zInit( zCAICamera_OnInit() );
    void StartUp()                                                                    zCall( 0x0049DEC0 );
    void CleanUp()                                                                    zCall( 0x0049E370 );
    float GetBestRange()                                                              zCall( 0x0049E410 );
    float GetMinRange()                                                               zCall( 0x0049E4C0 );
    float GetMaxRange()                                                               zCall( 0x0049E4D0 );
    void SetMode( zSTRING&, zCArray<zCVob*> )                                         zCall( 0x0049E4E0 );
    zSTRING GetMode()                                                                 zCall( 0x0049E860 );
    int IsModeActive( zSTRING& )                                                      zCall( 0x0049E8B0 );
    int IsModeAvailable( zSTRING const& )                                             zCall( 0x0049E930 );
    void ReceiveMsg( zTAICamMsg const& )                                              zCall( 0x0049E950 );
    void SetVob( zCVob* )                                                             zCall( 0x0049E980 );
    void SetTarget( zCVob* )                                                          zCall( 0x0049EC40 );
    void SetTargetList( zCArray<zCVob*> )                                             zCall( 0x0049F0D0 );
    void ClearTargetList()                                                            zCall( 0x0049F390 );
    void AddTarget( zCVob* )                                                          zCall( 0x0049F410 );
    void SubTarget( zCVob* )                                                          zCall( 0x0049F560 );
    int Console_EvalFunc( zSTRING const&, zSTRING& )                                  zCall( 0x0049F5F0 );
    void ParameterChanged()                                                           zCall( 0x0049FED0 );
    void CalcFirstPosition()                                                          zCall( 0x004A0070 );
    int SetByScript( zSTRING& )                                                       zCall( 0x004A0200 );
    zSTRING SetByScriptLine( zSTRING& )                                               zCall( 0x004A0850 );
    void CreateInstance( zSTRING& )                                                   zCall( 0x004A1190 );
    void AI_LookingCam()                                                              zCall( 0x004A11B0 );
    void AI_FirstPerson()                                                             zCall( 0x004A1C00 );
    void AI_Normal()                                                                  zCall( 0x004A1E90 );
    zVEC3& GetCamSysFirstPos()                                                        zCall( 0x004A2090 );
    void SetHintTargetInPortalRoom( int )                                             zCall( 0x004A20A0 );
    void CheckKeys()                                                                  zCall( 0x004A20E0 );
    void SetRotateEnabled( int )                                                      zCall( 0x004A2FD0 );
    void StartupDialogCam()                                                           zCall( 0x004AF410 );
    void InitDialogCam()                                                              zCall( 0x004AF9B0 );
    void SetDialogCamDuration( float )                                                zCall( 0x004AF9F0 );
    void ReleaseLastDialogCam()                                                       zCall( 0x004AFA00 );
    zCCSCamera* PickPreset( zSTRING, zCArray<zCCSCamera*> const& )                    zCall( 0x004AFAC0 );
    void StartDialogCam( int )                                                        zCall( 0x004AFBC0 );
    int DialogPresetIsValid( zCCSCamera* )                                            zCall( 0x004B1D60 );
    void InitHelperVobs()                                                             zCall( 0x004B8F30 );
    void DeleteHelperVobs()                                                           zCall( 0x004B91D0 );
    void ShowDebug()                                                                  zCall( 0x004B9240 );
    void DrawClipLine( zVEC3 const&, zVEC3 const&, zCOLOR )                           zCall( 0x004BA690 );
    zTBSphere3D CalcMinimumBSphere( zCArray<zVEC3>& )                                 zCall( 0x004BA8F0 );
    int CheckUnderWaterFX()                                                           zCall( 0x004BAD70 );
    zVEC3& CalcAziElevRange( float const&, float const&, float const&, zMAT4 const& ) zCall( 0x004BB280 );
    zSTRING GetPreviousMode()                                                         zCall( 0x00641030 );
    static zCAICamera* GetCurrent()                                                   zCall( 0x0049D9C0 );
    static zCAICamera* Create()                                                       zCall( 0x0049DE10 );
    static void GlobalStartUp()                                                       zCall( 0x0049E3A0 );
    static void GlobalCleanUp()                                                       zCall( 0x0049E3B0 );
    static zCObject* _CreateNewInstance()                                             zCall( 0x004A31D0 );
    static void GlobalDialogCamCleanUp()                                              zCall( 0x004AF8B0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x0049DC10 );
    virtual ~zCAICamera()                                                             zCall( 0x0049DC50 );
    virtual void DoAI( zCVob*, int& )                                                 zCall( 0x004A2AD0 );

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

} // namespace Gothic_II_Classic

#endif // __ZAI_CAMERA_H__VER2__