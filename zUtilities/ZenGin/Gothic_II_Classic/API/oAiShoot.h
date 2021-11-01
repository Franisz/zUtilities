// Supported with union (c) 2018-2021 Union team

#ifndef __OAI_SHOOT_H__VER2__
#define __OAI_SHOOT_H__VER2__

#include "z3d.h"
#include "zAi.h"
#include "zSoundMan.h"
#include "zArchiver.h"
#include "zCollisionDetector.h"

namespace Gothic_II_Classic {

  // sizeof 2Ch
  class oCAISound : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAISound )

    int slideSoundHandle; // sizeof 04h    offset 24h
    char slideSoundOn;    // sizeof 01h    offset 28h

    oCAISound() {}
    void RemoveSlideSound()                                         zCall( 0x006426B0 );
    void CheckSlideSound( zCVob* )                                  zCall( 0x006426D0 );
    int GetSoundMaterial( zCVob*, zCSoundManager::zTSndManMedium& ) zCall( 0x00642760 );
    void StartCollisionSound( zCVob*, zCCollisionReport const& )    zCall( 0x006428E0 );
    virtual zCClassDef* _GetClassDef() const                        zCall( 0x00642CC0 );
    virtual ~oCAISound()                                            zCall( 0x00642CD0 );
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

    void oCAIArrowBase_OnInit()                                        zCall( 0x00643950 );
    oCAIArrowBase()                                                    zInit( oCAIArrowBase_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                      zCall( 0x00643BB0 );
    void ClearIgnoreCDVob()                                            zCall( 0x00643BD0 );
    void CreateTrail( zCVob* )                                         zCall( 0x00643C40 );
    static zCObject* _CreateNewInstance()                              zCall( 0x00646270 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x00643A40 );
    virtual void Archive( zCArchiver& )                                zCall( 0x00644470 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x006444F0 );
    virtual ~oCAIArrowBase()                                           zCall( 0x00643AA0 );
    virtual void DoAI( zCVob*, int& )                                  zCall( 0x00643E60 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )       zCall( 0x00644160 );
    virtual int HasAIDetectedCollision()                               zCall( 0x00643A50 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& ) zCall( 0x00643A60 );

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

    void oCAIArrow_OnInit()                                      zCall( 0x006445B0 );
    oCAIArrow()                                                  zInit( oCAIArrow_OnInit() );
    void SetTarget( zCVob* )                                     zCall( 0x00644790 );
    void ClearUsedVobs()                                         zCall( 0x006447D0 );
    void SetupAIVob( zCVob*, zCVob*, zCVob* )                    zCall( 0x00644880 );
    static zCObject* _CreateNewInstance()                        zCall( 0x00646540 );
    virtual zCClassDef* _GetClassDef() const                     zCall( 0x00644660 );
    virtual void Archive( zCArchiver& )                          zCall( 0x00645440 );
    virtual void Unarchive( zCArchiver& )                        zCall( 0x00645510 );
    virtual ~oCAIArrow()                                         zCall( 0x006446A0 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x00644BE0 );
    virtual int CanThisCollideWith( zCVob* )                     zCall( 0x00644C10 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x00644CB0 );

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

    void oCAIDrop_OnInit()                                       zCall( 0x00645620 );
    oCAIDrop()                                                   zInit( oCAIDrop_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                zCall( 0x006458B0 );
    void ClearIgnoreCDVob()                                      zCall( 0x006458D0 );
    void SetupAIVob( zCVob*, zCVob* )                            zCall( 0x00645940 );
    void SetVelocity( float, float )                             zCall( 0x00645C60 );
    void SetStartPosition( zVEC3& )                              zCall( 0x00645D10 );
    static zCObject* _CreateNewInstance()                        zCall( 0x00646820 );
    virtual zCClassDef* _GetClassDef() const                     zCall( 0x00645700 );
    virtual void Archive( zCArchiver& )                          zCall( 0x00645E90 );
    virtual void Unarchive( zCArchiver& )                        zCall( 0x00645EA0 );
    virtual ~oCAIDrop()                                          zCall( 0x00645790 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x00645BA0 );
    virtual int CanThisCollideWith( zCVob* )                     zCall( 0x00645720 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x00645C10 );
    virtual int HasAIDetectedCollision()                         zCall( 0x00645710 );

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

    void oCAIVobMove_OnInit()                                         zCall( 0x00642A50 );
    oCAIVobMove()                                                     zInit( oCAIVobMove_OnInit() );
    void AddIgnoreCDVob( zCVob* )                                     zCall( 0x00643400 );
    void ClearIgnoreCDVob()                                           zCall( 0x00643420 );
    static zCObject* _CreateNewInstance()                             zCall( 0x00646AE0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00642B20 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006432B0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00643310 );
    virtual ~oCAIVobMove()                                            zCall( 0x00642BA0 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x006430F0 );
    virtual int CanThisCollideWith( zCVob* )                          zCall( 0x00642B30 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )      zCall( 0x00643260 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* ) zCall( 0x00642D70 );

    // user API
    #include "oCAIVobMove.inl"
  };

  // sizeof 40h
  class oCAIVobMoveTorch : public oCAIVobMove {
  public:
    zCLASS_DECLARATION( oCAIVobMoveTorch )

    float timer; // sizeof 04h    offset 3Ch

    void oCAIVobMoveTorch_OnInit()                                    zCall( 0x00643490 );
    oCAIVobMoveTorch()                                                zInit( oCAIVobMoveTorch_OnInit() );
    int CheckWater()                                                  zCall( 0x006436C0 );
    void BurnedOut()                                                  zCall( 0x00643770 );
    static zCObject* _CreateNewInstance()                             zCall( 0x00646DA0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00643520 );
    virtual ~oCAIVobMoveTorch()                                       zCall( 0x00643560 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x00643690 );
    virtual void Init( zCVob*, zCVob*, zVEC3&, float, float, zMAT4* ) zCall( 0x00643670 );

    // user API
    #include "oCAIVobMoveTorch.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OAI_SHOOT_H__VER2__