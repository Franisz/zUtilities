// Supported with union (c) 2018 Union team

#ifndef __OAI_SHOOT_H__VER2__
#define __OAI_SHOOT_H__VER2__

#include "z3d.h"
#include "zAi.h"
#include "zSoundMan.h"
#include "zArchiver.h"
#include "zCollisionDetector.h"

namespace Gothic_II_Classic {

  class oCAISound : public zCAIBase {
  public:
    zCLASS_DECLARATION( oCAISound )

    int slideSoundHandle;
    char slideSoundOn;

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

  class oCAIArrowBase : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIArrowBase )

    zCList<zCVob> ignoreVobList;
    int collisionOccured;
    float timeLeft;
    zCVob* vob;
    int startDustFX;
    zCVob* trailVob;
    zCPolyStrip* trailStrip;
    int trailActive;
    float trailTime;
    int hasHit;

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

  class oCAIArrow : public oCAIArrowBase {
  public:
    zCLASS_DECLARATION( oCAIArrow )

    oCItem* arrow;
    oCNpc* owner;
    int removeVob;
    zCVob* targetNPC;

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

  class oCAIDrop : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIDrop )

    zCList<zCVob> ignoreVobList;
    zCVob* vob;
    zCVob* owner;
    int collisionOccured;
    float timer;
    float count;

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

  class oCAIVobMove : public oCAISound {
  public:
    zCLASS_DECLARATION( oCAIVobMove )

    zCVob* vob;
    zCVob* owner;
    zCList<zCVob> ignoreVobList;

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

  class oCAIVobMoveTorch : public oCAIVobMove {
  public:
    zCLASS_DECLARATION( oCAIVobMoveTorch )

    float timer;

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