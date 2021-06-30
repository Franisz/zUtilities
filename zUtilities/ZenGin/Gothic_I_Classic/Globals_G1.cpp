#include "UnionAfx.h"

namespace Gothic_I_Classic {
#ifdef __ZPROTO_B_VER0__
  zCEngine*&             zengine          = *(zCEngine**)            0x0085E9E8;
  zCOption*&             zoptions         = *(zCOption**)            0x00869694;
  zCOption*&             zgameoptions     = *(zCOption**)            0x00869698;
  zCTimer*               ztimer           =  (zCTimer*)              0x008CF1E8;
  oCGame*&               ogame            = *(oCGame**)              0x008DA6BC;
  zCInput*&              zinput           = *(zCInput**)             0x0086CCA0;
  zCRenderer*&           zrenderer        = *(zCRenderer**)          0x008C5ED0;
  zCLineCache*           zlineCache       =  (zCLineCache*)          0x0086F580;
  zERROR*                zerr             =  (zERROR*)               0x008699D8;
  zCSoundSystem*&        zsound           = *(zCSoundSystem**)       0x008CEE4C;
  zCMusicSystem*&        zmusic           = *(zCMusicSystem**)       0x0086D47C;
  oCItem*&               offer            = *(oCItem**)              0x008DA590;
  oCDoc*&                document         = *(oCDoc**)               0x008DA5A8;
  zCMallocGeneric*       zmalloc          =  (zCMallocGeneric*)      0x00873998;
  zTEngineStats*         zengineStats     =  (zTEngineStats*)        0x0086F5CC;
  zCScanDir*             dirScanner       =  (zCScanDir*)            0x0086973C;
  oCObjectFactory*&      zfactory         = *(oCObjectFactory**)     0x00873F88;
  zCArchiverFactory*     zarcFactory      =  (zCArchiverFactory*)    0x0086F9AC;
  oCNpc*&                player           = *(oCNpc**)               0x008DBBB0;
  oCNpc*&                stealnpc         = *(oCNpc**)               0x008DBC28;
  zCView*&               screen           = *(zCView**)              0x008DE1BC;
  zCView*&               messages         = *(zCView**)              0x0086C80C;
  zCConsole*             zcon             =  (zCConsole*)            0x008DC5A0;
  zCConsole*&            game_species_con = *(zCConsole**)           0x008DA6D4;
  zCConsole*&            game_fight_con   = *(zCConsole**)           0x008DA6D8;
  zCConsole*&            edit_con         = *(zCConsole**)           0x008DA6DC;
  zCConsole*&            game_cam_con     = *(zCConsole**)           0x008DA6E0;
  zCConsole*&            game_aiConsole   = *(zCConsole**)           0x008DA6E4;
  zCNet*&                znet             = *(zCNet**)               0x00864D98;
  zCNetManager*&         znetman          = *(zCNetManager**)        0x00869060;
  CGameManager*&         gameMan          = *(CGameManager**)        0x0085E9E4;
  zCFontMan*&            zfontman         = *(zCFontMan**)           0x008DC71C;
  oCRtnManager*          rtnMan           =  (oCRtnManager*)         0x008DC220;
  oCMissionManager*      misMan           =  (oCMissionManager*)     0x008DAB2C;
  zCRenderManager*       zrenderMan       =  (zCRenderManager*)      0x008CE900;
  zCResourceManager*&    zresMan          = *(zCResourceManager**)   0x008CE9D0;
  zCSoundManager*&       zsndMan          = *(zCSoundManager**)      0x008CEEBC;
  zCVertexBufferManager* zvertexBufferMan =  (zCVertexBufferManager*)0x008D721C;
  zCParser*              parser           =  (zCParser* )            0x008DCE08;
  zCParser*&             parserSoundFX    = *(zCParser**)            0x0086DCFC;
  zCParser*&             parserParticleFX = *(zCParser**)            0x00874380;
  zCParser*&             parserVisualFX   = *(zCParser**)            0x00869E6C;
  zCParser*&             parserCamera     = *(zCParser**)            0x0086A1E0;
  zCParser*&             parserMenu       = *(zCParser**)            0x0086D3D8;
  zCParser*&             parserMusic      = *(zCParser**)            0x0086D6A8;
  zCFPUControler*        zfpuControler    =  (zCFPUControler*)       0x008CF204;
  oCParticleControl*&    pfxc             = *(oCParticleControl**)   0x008DA6C0;
  HINSTANCE&             hInstApp         = *(HINSTANCE*)            0x0086F4AC;
  HDC&                   dcScreen         = *(HDC*)                  0x0086F4B0;
  HICON&                 hIconApp         = *(HICON*)                0x0086F4B4;
  HWND&                  hWndApp          = *(HWND*)                 0x0086F4B8;

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
      oCNpc*& Player   = player;
      oCNpc*& StealNpc = stealnpc;
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
#endif // __ZPROTO_B_VER0__
} // Gothic_I_Classic