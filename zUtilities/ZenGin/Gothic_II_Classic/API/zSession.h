// Supported with union (c) 2018-2021 Union team

#ifndef __ZSESSION_H__VER2__
#define __ZSESSION_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 1Ch
  class zCSession : public zCInputCallback {
  public:
    zCCSManager* csMan; // sizeof 04h    offset 04h
    zCWorld* world;     // sizeof 04h    offset 08h
    zCCamera* camera;   // sizeof 04h    offset 0Ch
    zCAICamera* aiCam;  // sizeof 04h    offset 10h
    zCVob* camVob;      // sizeof 04h    offset 14h
    zCView* viewport;   // sizeof 04h    offset 18h

    void zCSession_OnInit()                                                      zCall( 0x005D7990 );
    zCSession()                                                                  zInit( zCSession_OnInit() );
    virtual ~zCSession()                                                         zCall( 0x005D7A40 );
    virtual void Init()                                                          zCall( 0x005D7B50 );
    virtual void Done()                                                          zCall( 0x005D7A90 );
    virtual void Render()                                                        zCall( 0x005D7C50 );
    virtual void RenderBlit()                                                    zCall( 0x005D7CA0 );
    virtual void CamInit()                                                       zCall( 0x005D7CC0 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x005D7EC0 );
    virtual void SetCamera( zCCamera* )                                          zCall( 0x005D79C0 );
    virtual zCCamera* GetCamera() const                                          zCall( 0x005D79D0 );
    virtual zCAICamera* GetCameraAI() const                                      zCall( 0x005D79E0 );
    virtual zCVob* GetCameraVob() const                                          zCall( 0x005D79F0 );
    virtual zCView* GetViewport() const                                          zCall( 0x005D7A00 );
    virtual zCWorld* GetWorld()                                                  zCall( 0x005D7F30 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x005D7F40 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x005D7F50 );
    virtual zCCSManager* GetCutsceneManager()                                    zCall( 0x005D7A10 );
    virtual void SetTime( int, int, int )                                        zCall( 0x005D7F60 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x005D7F70 );
    virtual void SetWorld( zCWorld* )                                            zCall( 0x005D7F80 );
    virtual void DesktopInit()                                                   zCall( 0x005D7B90 );
    virtual void CutsceneSystemInit()                                            zCall( 0x005D7C20 );

    // user API
    #include "zCSession.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSESSION_H__VER2__