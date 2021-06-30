// Supported with union (c) 2018 Union team

#ifndef __ZSESSION_H__VER0__
#define __ZSESSION_H__VER0__

namespace Gothic_I_Classic {

  class zCSession : public zCInputCallback {
  public:
    zCCSManager* csMan;
    zCWorld* world;
    zCCamera* camera;
    zCAICamera* aiCam;
    zCVob* camVob;
    zCView* viewport;

    void zCSession_OnInit()                                                      zCall( 0x005B7230 );
    zCSession()                                                                  zInit( zCSession_OnInit() );
    virtual ~zCSession()                                                         zCall( 0x005B72E0 );
    virtual void Init()                                                          zCall( 0x005B73F0 );
    virtual void Done()                                                          zCall( 0x005B7330 );
    virtual void Render()                                                        zCall( 0x005B74F0 );
    virtual void RenderBlit()                                                    zCall( 0x005B7540 );
    virtual void CamInit()                                                       zCall( 0x005B7560 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x005B7720 );
    virtual void SetCamera( zCCamera* )                                          zCall( 0x005B7260 );
    virtual zCCamera* GetCamera() const                                          zCall( 0x005B7270 );
    virtual zCAICamera* GetCameraAI() const                                      zCall( 0x005B7280 );
    virtual zCVob* GetCameraVob() const                                          zCall( 0x005B7290 );
    virtual zCView* GetViewport() const                                          zCall( 0x005B72A0 );
    virtual zCWorld* GetWorld()                                                  zCall( 0x005B7790 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x005B77A0 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x005B77B0 );
    virtual zCCSManager* GetCutsceneManager()                                    zCall( 0x005B72B0 );
    virtual void SetTime( int, int, int )                                        zCall( 0x005B77C0 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x005B77D0 );
    virtual void SetWorld( zCWorld* )                                            zCall( 0x005B77E0 );
    virtual void DesktopInit()                                                   zCall( 0x005B7430 );
    virtual void CutsceneSystemInit()                                            zCall( 0x005B74C0 );

    // user API
    #include "zCSession.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSESSION_H__VER0__