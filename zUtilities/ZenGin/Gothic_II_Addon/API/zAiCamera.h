// Supported with union (c) 2018-2021 Union team

#ifndef __ZAI_CAMERA_H__VER3__
#define __ZAI_CAMERA_H__VER3__

#include "zAi.h"
#include "zGrafix.h"
#include "zBVolume.h"

namespace Gothic_II_Addon {
  const int MAX_CTRL_VOBS = 80;

  // sizeof 29Ch
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
    float targetAlpha;                       // sizeof 04h    offset A0h
    int numTargets;                          // sizeof 04h    offset A4h
    zSTRING oldCamSys;                       // sizeof 14h    offset A8h
    int sysChanged;                          // sizeof 04h    offset BCh
    int playerIsMovable;                     // sizeof 04h    offset C0h
    int followIdealPos;                      // sizeof 04h    offset C4h
    float dialogCamDuration;                 // sizeof 04h    offset C8h
    int numOUsSpoken;                        // sizeof 04h    offset CCh
    int numDialogCamTakes;                   // sizeof 04h    offset D0h
    int lastNumDialogCamTakes;               // sizeof 04h    offset D4h
    int lastDialogCamSide;                   // sizeof 04h    offset D8h
    int firstSpeakerWasPC;                   // sizeof 04h    offset DCh
    zCCSCamera* dialogCam;                   // sizeof 04h    offset E0h
    zSTRING lastPresetName;                  // sizeof 14h    offset E4h
    int raysCasted;                          // sizeof 04h    offset F8h
    int underWater;                          // sizeof 04h    offset FCh
    int inCutsceneMode;                      // sizeof 04h    offset 100h
    zSTRING debugS;                          // sizeof 14h    offset 104h
    int showPath;                            // sizeof 04h    offset 118h
    zCVob* focusVob;                         // sizeof 04h    offset 11Ch
    zCVob* ctrlDot[MAX_CTRL_VOBS];           // sizeof 140h   offset 120h
    zCPathSearch* pathSearch;                // sizeof 04h    offset 260h
    zCMovementTracker* moveTracker;          // sizeof 04h    offset 264h
    zSPathSearchResult* evasionSearchReport; // sizeof 04h    offset 268h
    zSTRING curcammode;                      // sizeof 14h    offset 26Ch
    float npcVolumeRangeOffset;              // sizeof 04h    offset 280h
    float camDistOffset;                     // sizeof 04h    offset 284h
    zVEC3 camSysFirstPos;                    // sizeof 0Ch    offset 288h
    int firstPerson;                         // sizeof 04h    offset 294h
    int targetInPortalRoom;                  // sizeof 04h    offset 298h

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