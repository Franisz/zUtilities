#include "UnionAfx.h"

namespace Gothic_II_Addon {
#ifdef __ZPROTO_B_VER3__
  zCEngine*&             zengine          = *(zCEngine**)            0x008C295C;
  zCOption*&             zoptions         = *(zCOption**)            0x008CD988;
  zCOption*&             zgameoptions     = *(zCOption**)            0x008CD98C;
  zCTimer*               ztimer           =  (zCTimer*)              0x0099B3D4;
  oCGame*&               ogame            = *(oCGame**)              0x00AB0884;
  zCInput*&              zinput           = *(zCInput**)             0x008D1650;
  zCRenderer*&           zrenderer        = *(zCRenderer**)          0x00982F08;
  zCLineCache*           zlineCache       =  (zCLineCache*)          0x008D42F8;
  zERROR*                zerr             =  (zERROR*)               0x008CDCD0;
  zCSoundSystem*&        zsound           = *(zCSoundSystem**)       0x0099B03C;
  zCMusicSystem*&        zmusic           = *(zCMusicSystem**)       0x008D1F14;
  oCItem*&               offer            = *(oCItem**)              0x00AB04F0;
  oCDoc*&                document         = *(oCDoc**)               0x00AB05D0;
  zCMallocGeneric*       zmalloc          =  (zCMallocGeneric*)      0x008D8778;
  zTEngineStats*         zengineStats     =  (zTEngineStats*)        0x008D4344;
  zCScanDir*             dirScanner       =  (zCScanDir*)            0x008CDA34;
  oCObjectFactory*&      zfactory         = *(oCObjectFactory**)     0x008D8DF0;
  zCArchiverFactory*     zarcFactory      =  (zCArchiverFactory*)    0x008D472C;
  oCNpc*&                player           = *(oCNpc**)               0x00AB2684;
  oCNpc*&                stealnpc         = *(oCNpc**)               0x00AB27D4;
  zCVob*&                speaker          = *(zCVob**)               0x008CEE4C;
  zCVob*&                listener         = *(zCVob**)               0x008CEE50;
  zCView*&               screen           = *(zCView**)              0x00AB6468;
  zCView*&               messages         = *(zCView**)              0x008D11BC;
  zCConsole*             zcon             =  (zCConsole*)            0x00AB3860;
  zCConsole*&            game_species_con = *(zCConsole**)           0x00AB0898;
  zCConsole*&            game_fight_con   = *(zCConsole**)           0x00AB089C;
  zCConsole*&            edit_con         = *(zCConsole**)           0x00AB08A0;
  zCConsole*&            game_cam_con     = *(zCConsole**)           0x00AB08A4;
  zCConsole*&            game_aiConsole   = *(zCConsole**)           0x00AB08A8;
  zCNet*&                znet             = *(zCNet**)               0x008C8F90;
  zCNetManager*&         znetman          = *(zCNetManager**)        0x008CD250;
  CGameManager*&         gameMan          = *(CGameManager**)        0x008C2958;
  zCFontMan*&            zfontman         = *(zCFontMan**)           0x00AB39D4;
  oCRtnManager*          rtnMan           =  (oCRtnManager*)         0x00AB31C8;
  oCMissionManager*      misMan           =  (oCMissionManager*)     0x00AB1384;
  zCRenderManager*       zrenderMan       =  (zCRenderManager*)      0x0099AA44;
  zCResourceManager*&    zresMan          = *(zCResourceManager**)   0x0099AB30;
  zCSoundManager*&       zsndMan          = *(zCSoundManager**)      0x0099B0B0;
  zCVertexBufferManager* zvertexBufferMan =  (zCVertexBufferManager*)0x009A341C;
  zCParser*              parser           =  (zCParser* )            0x00AB40C0;
  zCParser*&             parserSoundFX    = *(zCParser**)            0x008D2A64;
  zCParser*&             parserParticleFX = *(zCParser**)            0x008D9234;
  zCParser*&             parserVisualFX   = *(zCParser**)            0x008CE6EC;
  zCParser*&             parserCamera     = *(zCParser**)            0x008CEAC8;
  zCParser*&             parserMenu       = *(zCParser**)            0x008D1E68;
  zCParser*&             parserMusic      = *(zCParser**)            0x008D2140;
  zCFPUControler*        zfpuControler    =  (zCFPUControler*)       0x0099B3FC;
  oCParticleControl*&    pfxc             = *(oCParticleControl**)   0x00AB088C;
  HINSTANCE&             hInstApp         = *(HINSTANCE*)            0x008D4220;
  HDC&                   dcScreen         = *(HDC*)                  0x008D4224;
  HICON&                 hIconApp         = *(HICON*)                0x008D4228;
  HWND&                  hWndApp          = *(HWND*)                 0x008D422C;

  namespace Gothic {
    namespace Managers {
      CGameManager*&          Game         = gameMan;
      zCFontMan*&             Font         = zfontman;
      oCRtnManager*&          Routine      = rtnMan;
      oCMissionManager*&      Mission      = misMan;
      zCRenderManager*&       Render       = zrenderMan;
      zCResourceManager*&     Resource     = zresMan;
      zCSoundManager*&        Sound        = zsndMan;
      zCVertexBufferManager*& VertexBuffer = zvertexBufferMan;
    }

    namespace Parsers {
      zCParser*& Game   = parser;
      zCParser*& SFX    = parserSoundFX;
      zCParser*& PFX    = parserParticleFX;
      zCParser*& VFX    = parserVisualFX;
      zCParser*& Camera = parserCamera;
      zCParser*& Menu   = parserMenu;
      zCParser*& Music  = parserMusic;
    }

    namespace Network {
      zCNet*&        Net     = znet;
      zCNetManager*& Manager = znetman;
    }

    namespace Entities {
      oCNpc*& Player      = player;
      oCNpc*& StealNpc    = stealnpc;
      zCVob*& VobSpeaker  = speaker;
      zCVob*& VobListener = listener;
    }

    namespace Consoles {
      zCConsole*& Main      = zcon;
      zCConsole*& Species   = game_species_con;
      zCConsole*& Fight     = game_fight_con;
      zCConsole*& Abilities = edit_con;
      zCConsole*& Camera    = game_cam_con;
      zCConsole*& AI        = game_aiConsole;
    }

    namespace Factories {
      oCObjectFactory*&   Objects  = zfactory;
      zCArchiverFactory*& Archives = zarcFactory;
    }

    namespace Views {
      zCView*& Screen   = screen;
      zCView*& Messages = messages;
    }

    namespace Options {
      zCOption*& Gothic = zoptions;
      zCOption*& Game   = zgameoptions;
    }

    namespace Game {
      zCTimer*&       Timer        = ztimer;
      oCGame*&        Session      = ogame;
      zCInput*&       Input        = zinput;
      zCRenderer*&    Renderer     = zrenderer;
      zCLineCache*&   LineCache    = zlineCache;
      zERROR*&        Error        = zerr;
      zCSoundSystem*& Sound        = zsound;
      zCMusicSystem*& Music        = zmusic;
      zTEngineStats*& EngineStatus = zengineStats;
    }

    namespace Other {
      zCEngine*&          EnginePointer     = zengine;
      oCItem*&            OfferItem         = offer;
      oCDoc*&             Document          = document;
      zCMallocGeneric*&   Malloc            = zmalloc;
      zCScanDir*&         DirectoryExplorer = dirScanner;
      zCFPUControler*&    FPUController     = zfpuControler;
      oCParticleControl*& PartivleFXControl = pfxc;
    }

    namespace Application {
      HINSTANCE& Instance = hInstApp;
      HDC&       ScreenDC = dcScreen;
      HICON&     Icon     = hIconApp;
      HWND&      Window   = hWndApp;
    }
  }

#endif // __ZPROTO_B_VER3__
} // Gothic_II_Addon