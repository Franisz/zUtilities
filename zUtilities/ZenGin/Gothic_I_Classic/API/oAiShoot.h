// Supported with union (c) 2018-2021 Union team

#ifndef __OAI_SHOOT_H__VER0__
#define __OAI_SHOOT_H__VER0__

#include "z3d.h"
#include "zAi.h"
#include "zSoundMan.h"
#include "zArchiver.h"
#include "zCollisionDetector.h"

namespace Gothic_I_Classic {

  // sizeof 2Ch
  class oCAISound : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAISound )

    int slideSoundHandle; // sizeof 04h    offset 24h
    char slideSoundOn;    // sizeof 01h    offset 28h

    oCAISound() {}
    void RemoveSlideSound()                                         zCall( 0x00617530 );
    void CheckSlideSound( zCVob* )                                  zCall( 0x00617550 );
    int GetSoundMaterial( zCVob*, zCSoundManager::zTSndManMedium& ) zCall( 0x006175E0 );
    void StartCollisionSound( zCVob*, zCCollisionReport const& )    zCall( 0x006176B0 );
    virtual zCClassDef* _GetClassDef() const                        zCall( 0x00617930 );
    virtual ~oCAISound()                                            zCall( 0x00617940 );
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

    void oCAIArrowBase_OnInit()                                         zCall( 0x00618550 );
    oCAIArrowBase()                                                     zInit( oCAIArrowBase_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x006187A0 );
    void ClearIgnoreCDVob()                                             zCall( 0x006187C0 );
    void CreateTrail( zCVob* )                                          zCall( 0x00618830 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0061A680 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00618630 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00618DC0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00618E40 );
    virtual ~oCAIArrowBase()                                            zCall( 0x00618690 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00618A80 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x00618D50 );
    virtual int HasAIDetectedCollision()                                zCall( 0x00618640 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& )  zCall( 0x00618650 );

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

    void oCAIArrow_OnInit()                                             zCall( 0x00618F00 );
    oCAIArrow()                                                         zInit( oCAIArrow_OnInit() );
    void SetTarget( zCVob* )                                            zCall( 0x006190E0 );
    void ClearUsedVobs()                                                zCall( 0x00619120 );
    void SetupAIVob( zCVob*, zCVob*, zCVob* )                           zCall( 0x006191D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0061A970 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00618FB0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00619890 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00619960 );
    virtual ~oCAIArrow()                                                zCall( 0x00618FF0 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00619520 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x00619550 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x006195E0 );

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

    void oCAIDrop_OnInit()                                              zCall( 0x00619A70 );
    oCAIDrop()                                                          zInit( oCAIDrop_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x00619D00 );
    void ClearIgnoreCDVob()                                             zCall( 0x00619D20 );
    void SetupAIVob( zCVob*, zCVob* )                                   zCall( 0x00619D90 );
    void SetVelocity( float, float )                                    zCall( 0x0061A080 );
    void SetStartPosition( zVEC3& )                                     zCall( 0x0061A130 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0061AC70 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00619B50 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0061A2A0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0061A2B0 );
    virtual ~oCAIDrop()                                                 zCall( 0x00619BE0 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00619FD0 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x00619B70 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x0061A040 );
    virtual int HasAIDetectedCollision()                                zCall( 0x00619B60 );

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

    void oCAIVobMove_OnInit()                                           zCall( 0x006176C0 );
    oCAIVobMove()                                                       zInit( oCAIVobMove_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                       zCall( 0x00618010 );
    void ClearIgnoreCDVob()                                             zCall( 0x00618030 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0061AF50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00617790 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00617EC0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00617F20 );
    virtual ~oCAIVobMove()                                              zCall( 0x00617810 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x00617D10 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x006177A0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )        zCall( 0x00617E80 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* )   zCall( 0x006179E0 );

    // user API
    #include "oCAIVobMove.inl"
  };

  // sizeof 40h
  class oCAIVobMoveTorch : public oCAIVobMove {
  public:
    zCLASS_DECLARATION( oCAIVobMoveTorch )

    float timer; // sizeof 04h    offset 3Ch

    void oCAIVobMoveTorch_OnInit()                                      zCall( 0x006180A0 );
    oCAIVobMoveTorch()                                                  zInit( oCAIVobMoveTorch_OnInit() );
    int CheckWater()                                                    zCall( 0x006182D0 );
    void BurnedOut()                                                    zCall( 0x00618380 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0061B220 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00618130 );
    virtual ~oCAIVobMoveTorch()                                         zCall( 0x00618170 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x006182A0 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* )   zCall( 0x00618280 );

    // user API
    #include "oCAIVobMoveTorch.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OAI_SHOOT_H__VER0__