// Supported with union (c) 2018-2021 Union team

#ifndef __ZSESSION_H__VER1__
#define __ZSESSION_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 1Ch
  class zCSession : public zCInputCallback {
  public:
    zCCSManager* csMan; // sizeof 04h    offset 04h
    zCWorld* world;     // sizeof 04h    offset 08h
    zCCamera* camera;   // sizeof 04h    offset 0Ch
    zCAICamera* aiCam;  // sizeof 04h    offset 10h
    zCVob* camVob;      // sizeof 04h    offset 14h
    zCView* viewport;   // sizeof 04h    offset 18h

    void zCSession_OnInit()                                                      zCall( 0x005D4BA0 );
    zCSession()                                                                  zInit( zCSession_OnInit() );
    virtual ~zCSession()                                                         zCall( 0x005D4C50 );
    virtual void Init()                                                          zCall( 0x005D4D70 );
    virtual void Done()                                                          zCall( 0x005D4CA0 );
    virtual void Render()                                                        zCall( 0x005D4E70 );
    virtual void RenderBlit()                                                    zCall( 0x005D4EC0 );
    virtual void CamInit()                                                       zCall( 0x005D4EE0 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x005D50A0 );
    virtual void SetCamera( zCCamera* )                                          zCall( 0x005D4BD0 );
    virtual zCCamera* GetCamera() const                                          zCall( 0x005D4BE0 );
    virtual zCAICamera* GetCameraAI() const                                      zCall( 0x005D4BF0 );
    virtual zCVob* GetCameraVob() const                                          zCall( 0x005D4C00 );
    virtual zCView* GetViewport() const                                          zCall( 0x005D4C10 );
    virtual zCWorld* GetWorld()                                                  zCall( 0x005D5110 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x005D5120 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x005D5130 );
    virtual zCCSManager* GetCutsceneManager()                                    zCall( 0x005D4C20 );
    virtual void SetTime( int, int, int )                                        zCall( 0x005D5140 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x005D5150 );
    virtual void SetWorld( zCWorld* )                                            zCall( 0x005D5160 );
    virtual void DesktopInit()                                                   zCall( 0x005D4DB0 );
    virtual void CutsceneSystemInit()                                            zCall( 0x005D4E40 );

    // user API
    #include "zCSession.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSESSION_H__VER1__