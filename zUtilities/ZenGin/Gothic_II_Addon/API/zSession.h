// Supported with union (c) 2018 Union team

#ifndef __ZSESSION_H__VER3__
#define __ZSESSION_H__VER3__

namespace Gothic_II_Addon {

  class zCSession : public zCInputCallback {
  public:
    zCCSManager* csMan;
    zCWorld* world;
    zCCamera* camera;
    zCAICamera* aiCam;
    zCVob* camVob;
    zCView* viewport;

    void zCSession_OnInit()                                                      zCall( 0x005DE750 );
    zCSession()                                                                  zInit( zCSession_OnInit() );
    virtual ~zCSession()                                                         zCall( 0x005DE800 );
    virtual void Init()                                                          zCall( 0x005DE910 );
    virtual void Done()                                                          zCall( 0x005DE850 );
    virtual void Render()                                                        zCall( 0x005DEA10 );
    virtual void RenderBlit()                                                    zCall( 0x005DEA60 );
    virtual void CamInit()                                                       zCall( 0x005DEA80 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x005DEC80 );
    virtual void SetCamera( zCCamera* )                                          zCall( 0x005DE780 );
    virtual zCCamera* GetCamera() const                                          zCall( 0x005DE790 );
    virtual zCAICamera* GetCameraAI() const                                      zCall( 0x005DE7A0 );
    virtual zCVob* GetCameraVob() const                                          zCall( 0x005DE7B0 );
    virtual zCView* GetViewport() const                                          zCall( 0x005DE7C0 );
    virtual zCWorld* GetWorld()                                                  zCall( 0x005DECF0 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x005DED00 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x005DED10 );
    virtual zCCSManager* GetCutsceneManager()                                    zCall( 0x005DE7D0 );
    virtual void SetTime( int, int, int )                                        zCall( 0x005DED20 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x005DED30 );
    virtual void SetWorld( zCWorld* )                                            zCall( 0x005DED40 );
    virtual void DesktopInit()                                                   zCall( 0x005DE950 );
    virtual void CutsceneSystemInit()                                            zCall( 0x005DE9E0 );

    // user API
    #include "zCSession.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSESSION_H__VER3__