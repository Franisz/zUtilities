// Supported with union (c) 2018-2021 Union team

#ifndef __OAI_SHOOT_H__VER1__
#define __OAI_SHOOT_H__VER1__

#include "z3d.h"
#include "zAi.h"
#include "zSoundMan.h"
#include "zArchiver.h"
#include "zCollisionDetector.h"

namespace Gothic_I_Addon {

  // sizeof 2Ch
  class oCAISound : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAISound )

    int slideSoundHandle; // sizeof 04h    offset 24h
    char slideSoundOn;    // sizeof 01h    offset 28h

    oCAISound() {}
    void RemoveSlideSound()                                         zCall( 0x0063A7C0 );
    void CheckSlideSound( zCVob* )                                  zCall( 0x0063A7E0 );
    int GetSoundMaterial( zCVob*, zCSoundManager::zTSndManMedium& ) zCall( 0x0063A870 );
    void StartCollisionSound( zCVob*, zCCollisionReport const& )    zCall( 0x0063A940 );
    virtual zCClassDef* _GetClassDef() const                        zCall( 0x0063ABD0 );
    virtual ~oCAISound()                                            zCall( 0x0063ABE0 );
    virtual void DoAI( zCVob*, int& )                               zPureCall;

    // user API
    #include "oCAISound.inl"
  };

  // sizeof 54h
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

    void oCAIArrowBase_OnInit()                                         zCall( 0x0063B8E0 );
    oCAIArrowBase()                                                     zInit( oCAIArrowBase_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x0063BB40 );
    void ClearIgnoreCDVob()                                             zCall( 0x0063BB60 );
    void CreateTrail( zCVob* )                                          zCall( 0x0063BBD0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0063DCB0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0063B9C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0063C1E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0063C260 );
    virtual ~oCAIArrowBase()                                            zCall( 0x0063BA20 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x0063BE70 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x0063C160 );
    virtual int HasAIDetectedCollision()                                zCall( 0x0063B9D0 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& )  zCall( 0x0063B9E0 );

    // user API
    #include "oCAIArrowBase.inl"
  };

  // sizeof 64h
  class oCAIArrow : public oCAIArrowBase {
  public:
    zCLASS_DECLARATION( oCAIArrow )

    oCItem* arrow;    // sizeof 04h    offset 54h
    oCNpc* owner;     // sizeof 04h    offset 58h
    int removeVob;    // sizeof 04h    offset 5Ch
    zCVob* targetNPC; // sizeof 04h    offset 60h

    void oCAIArrow_OnInit()                                             zCall( 0x0063C330 );
    oCAIArrow()                                                         zInit( oCAIArrow_OnInit() );
    void SetTarget( zCVob* )                                            zCall( 0x0063C520 );
    void ClearUsedVobs()                                                zCall( 0x0063C560 );
    void SetupAIVob( zCVob*, zCVob*, zCVob* )                           zCall( 0x0063C620 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0063DFC0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0063C3E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0063CDA0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0063CE70 );
    virtual ~oCAIArrow()                                                zCall( 0x0063C420 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x0063C9E0 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x0063CA10 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x0063CAA0 );

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

    void oCAIDrop_OnInit()                                              zCall( 0x0063CF90 );
    oCAIDrop()                                                          zInit( oCAIDrop_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x0063D230 );
    void ClearIgnoreCDVob()                                             zCall( 0x0063D250 );
    void SetupAIVob( zCVob*, zCVob* )                                   zCall( 0x0063D2C0 );
    void SetVelocity( float, float )                                    zCall( 0x0063D620 );
    void SetStartPosition( zVEC3& )                                     zCall( 0x0063D710 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0063E2E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0063D070 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0063D890 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0063D8A0 );
    virtual ~oCAIDrop()                                                 zCall( 0x0063D100 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x0063D560 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x0063D090 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x0063D5D0 );
    virtual int HasAIDetectedCollision()                                zCall( 0x0063D080 );

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

    void oCAIVobMove_OnInit()                                           zCall( 0x0063A950 );
    oCAIVobMove()                                                       zInit( oCAIVobMove_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x0063B320 );
    void ClearIgnoreCDVob()                                             zCall( 0x0063B340 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0063E5E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0063AA20 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0063B1C0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0063B220 );
    virtual ~oCAIVobMove()                                              zCall( 0x0063AAA0 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x0063B000 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x0063AA30 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x0063B170 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* )   zCall( 0x0063AC80 );

    // user API
    #include "oCAIVobMove.inl"
  };

  // sizeof 40h
  class oCAIVobMoveTorch : public oCAIVobMove {
  public:
    zCLASS_DECLARATION( oCAIVobMoveTorch )

    float timer; // sizeof 04h    offset 3Ch

    void oCAIVobMoveTorch_OnInit()                                      zCall( 0x0063B3B0 );
    oCAIVobMoveTorch()                                                  zInit( oCAIVobMoveTorch_OnInit() );
    int CheckWater()                                                    zCall( 0x0063B600 );
    void BurnedOut()                                                    zCall( 0x0063B6E0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0063E8E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0063B440 );
    virtual ~oCAIVobMoveTorch()                                         zCall( 0x0063B480 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x0063B5D0 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* )   zCall( 0x0063B5A0 );

    // user API
    #include "oCAIVobMoveTorch.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OAI_SHOOT_H__VER1__