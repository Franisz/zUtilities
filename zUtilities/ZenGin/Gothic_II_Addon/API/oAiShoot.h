// Supported with union (c) 2018-2021 Union team

#ifndef __OAI_SHOOT_H__VER3__
#define __OAI_SHOOT_H__VER3__

#include "z3d.h"
#include "zAi.h"
#include "zSoundMan.h"
#include "zArchiver.h"
#include "zCollisionDetector.h"

namespace Gothic_II_Addon {

  // sizeof 2Ch
  class oCAISound : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAISound )

    int slideSoundHandle; // sizeof 04h    offset 24h
    char slideSoundOn;    // sizeof 01h    offset 28h

    oCAISound() {}
    void RemoveSlideSound()                                         zCall( 0x0069EE80 );
    void CheckSlideSound( zCVob* )                                  zCall( 0x0069EEA0 );
    int GetSoundMaterial( zCVob*, zCSoundManager::zTSndManMedium& ) zCall( 0x0069EF30 );
    void StartCollisionSound( zCVob*, zCCollisionReport const& )    zCall( 0x0069F0B0 );
    virtual zCClassDef* _GetClassDef() const                        zCall( 0x0069F490 );
    virtual ~oCAISound()                                            zCall( 0x0069F4A0 );
    virtual void DoAI( zCVob*, int& )                               zPureCall;

    // user API
    #include "oCAISound.inl"
  };

  // sizeof 58h
  class oCAIArrowBase : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIArrowBase )

    zCList<zCVob> ignoreVobList; // sizeof 08h    offset 2Ch
    int collisionOccured;        // sizeof 04h    offset 34h
    float timeLeft;              // sizeof 04h    offset 38h
    zCVob* vob;                  // sizeof 04h    offset 3Ch
    int startDustFX;             // sizeof 04h    offset 40h
    zCVob* trailVob;             // sizeof 04h    offset 44h
    zCPolyStrip* trailStrip;     // sizeof 04h    offset 48h
    int trailActive;             // sizeof 04h    offset 4Ch
    float trailTime;             // sizeof 04h    offset 50h
    int hasHit;                  // sizeof 04h    offset 54h

    void oCAIArrowBase_OnInit()                                        zCall( 0x006A0120 );
    oCAIArrowBase()                                                    zInit( oCAIArrowBase_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                      zCall( 0x006A0390 );
    void ClearIgnoreCDVob()                                            zCall( 0x006A03B0 );
    void CreateTrail( zCVob* )                                         zCall( 0x006A0420 );
    static zCObject* _CreateNewInstance()                              zCall( 0x006A2AF0 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x006A0210 );
    virtual void Archive( zCArchiver& )                                zCall( 0x006A0CD0 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x006A0D50 );
    virtual ~oCAIArrowBase()                                           zCall( 0x006A0280 );
    virtual void DoAI( zCVob*, int& )                                  zCall( 0x006A0640 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )       zCall( 0x006A09C0 );
    virtual int HasAIDetectedCollision()                               zCall( 0x006A0220 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& ) zCall( 0x006A0230 );
    virtual int GetIsProjectile()                                      zCall( 0x006A0240 );

    // user API
    #include "oCAIArrowBase.inl"
  };

  // sizeof 68h
  class oCAIArrow : public oCAIArrowBase {
  public:
    zCLASS_DECLARATION( oCAIArrow )

    oCItem* arrow;    // sizeof 04h    offset 58h
    oCNpc* owner;     // sizeof 04h    offset 5Ch
    int removeVob;    // sizeof 04h    offset 60h
    zCVob* targetNPC; // sizeof 04h    offset 64h

    void oCAIArrow_OnInit()                                      zCall( 0x006A0E10 );
    oCAIArrow()                                                  zInit( oCAIArrow_OnInit() );
    void SetTarget( zCVob* )                                     zCall( 0x006A0FF0 );
    void ClearUsedVobs()                                         zCall( 0x006A1030 );
    void SetupAIVob( zCVob*, zCVob*, zCVob* )                    zCall( 0x006A10E0 );
    static zCObject* _CreateNewInstance()                        zCall( 0x006A2DC0 );
    virtual zCClassDef* _GetClassDef() const                     zCall( 0x006A0EC0 );
    virtual void Archive( zCArchiver& )                          zCall( 0x006A1CC0 );
    virtual void Unarchive( zCArchiver& )                        zCall( 0x006A1D90 );
    virtual ~oCAIArrow()                                         zCall( 0x006A0F00 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x006A1460 );
    virtual int CanThisCollideWith( zCVob* )                     zCall( 0x006A1490 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x006A1530 );

    // user API
    #include "oCAIArrow.inl"
  };

  // sizeof 48h
  class oCAIDrop : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIDrop )

    zCList<zCVob> ignoreVobList; // sizeof 08h    offset 2Ch
    zCVob* vob;                  // sizeof 04h    offset 34h
    zCVob* owner;                // sizeof 04h    offset 38h
    int collisionOccured;        // sizeof 04h    offset 3Ch
    float timer;                 // sizeof 04h    offset 40h
    float count;                 // sizeof 04h    offset 44h

    void oCAIDrop_OnInit()                                       zCall( 0x006A1EA0 );
    oCAIDrop()                                                   zInit( oCAIDrop_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                zCall( 0x006A2130 );
    void ClearIgnoreCDVob()                                      zCall( 0x006A2150 );
    void SetupAIVob( zCVob*, zCVob* )                            zCall( 0x006A21C0 );
    void SetVelocity( float, float )                             zCall( 0x006A24E0 );
    void SetStartPosition( zVEC3& )                              zCall( 0x006A2590 );
    static zCObject* _CreateNewInstance()                        zCall( 0x006A30A0 );
    virtual zCClassDef* _GetClassDef() const                     zCall( 0x006A1F80 );
    virtual void Archive( zCArchiver& )                          zCall( 0x006A2710 );
    virtual void Unarchive( zCArchiver& )                        zCall( 0x006A2720 );
    virtual ~oCAIDrop()                                          zCall( 0x006A2010 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x006A2420 );
    virtual int CanThisCollideWith( zCVob* )                     zCall( 0x006A1FA0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x006A2490 );
    virtual int HasAIDetectedCollision()                         zCall( 0x006A1F90 );

    // user API
    #include "oCAIDrop.inl"
  };

  // sizeof 3Ch
  class oCAIVobMove : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIVobMove )

    zCVob* vob;                  // sizeof 04h    offset 2Ch
    zCVob* owner;                // sizeof 04h    offset 30h
    zCList<zCVob> ignoreVobList; // sizeof 08h    offset 34h

    void oCAIVobMove_OnInit()                                         zCall( 0x0069F220 );
    oCAIVobMove()                                                     zInit( oCAIVobMove_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                     zCall( 0x0069FBD0 );
    void ClearIgnoreCDVob()                                           zCall( 0x0069FBF0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x006A3360 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x0069F2F0 );
    virtual void Archive( zCArchiver& )                               zCall( 0x0069FA80 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x0069FAE0 );
    virtual ~oCAIVobMove()                                            zCall( 0x0069F370 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x0069F8C0 );
    virtual int CanThisCollideWith( zCVob* )                          zCall( 0x0069F300 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )      zCall( 0x0069FA30 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* ) zCall( 0x0069F540 );

    // user API
    #include "oCAIVobMove.inl"
  };

  // sizeof 40h
  class oCAIVobMoveTorch : public oCAIVobMove {
  public:
    zCLASS_DECLARATION( oCAIVobMoveTorch )

    float timer; // sizeof 04h    offset 3Ch

    void oCAIVobMoveTorch_OnInit()                                    zCall( 0x0069FC60 );
    oCAIVobMoveTorch()                                                zInit( oCAIVobMoveTorch_OnInit() );
    int CheckWater()                                                  zCall( 0x0069FE90 );
    void BurnedOut()                                                  zCall( 0x0069FF40 );
    static zCObject* _CreateNewInstance()                             zCall( 0x006A3620 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x0069FCF0 );
    virtual ~oCAIVobMoveTorch()                                       zCall( 0x0069FD30 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x0069FE60 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* ) zCall( 0x0069FE40 );

    // user API
    #include "oCAIVobMoveTorch.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OAI_SHOOT_H__VER3__