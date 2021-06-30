#include "UnionAfx.h"

namespace Gothic_II_Classic {
#ifdef __ZPROTO_B_VER2__
  zCEngine*&             zengine          = *(zCEngine**)            0x008B439C;
  zCOption*&             zoptions         = *(zCOption**)            0x008BF378;
  zCOption*&             zgameoptions     =  zoptions;
  zCTimer*               ztimer           =  (zCTimer*)              0x00974C7C;
  oCGame*&               ogame            = *(oCGame**)              0x009813DC;
  zCInput*&              zinput           = *(zCInput**)             0x008C2FF8;
  zCRenderer*&           zrenderer        = *(zCRenderer**)          0x0095C7B8;
  zCLineCache*           zlineCache       =  (zCLineCache*)          0x008C5CC0;
  zERROR*                zerr             =  (zERROR*)               0x008BF6B8;
  zCSoundSystem*&        zsound           = *(zCSoundSystem**)       0x009748E4;
  zCMusicSystem*&        zmusic           = *(zCMusicSystem**)       0x008C38B4;
  oCItem*&               offer            = *(oCItem**)              0x00981048;
  oCDoc*&                document         = *(oCDoc**)               0x00981128;
  zCMallocGeneric*       zmalloc          =  (zCMallocGeneric*)      0x008CA0F8;
  zTEngineStats*         zengineStats     =  (zTEngineStats*)        0x008C5D0C;
  zCScanDir*             dirScanner       =  (zCScanDir*)            0x008BF41C;
  oCObjectFactory*&      zfactory         = *(oCObjectFactory**)     0x008CA720;
  zCArchiverFactory*     zarcFactory      =  (zCArchiverFactory*)    0x008C60F4;
  oCNpc*&                player           = *(oCNpc**)               0x009831DC;
  oCNpc*&                stealnpc         = *(oCNpc**)               0x00983324;
  zCVob*&                speaker          = *(zCVob**)               0x008C07F4;
  zCVob*&                listener         = *(zCVob**)               0x008C07F8;
  zCView*&               screen           = *(zCView**)              0x00985FB0;
  zCView*&               messages         = *(zCView**)              0x008C2B64;
  zCConsole*             zcon             =  (zCConsole*)            0x009843A8;
  zCConsole*&            game_species_con = *(zCConsole**)           0x009813F0;
  zCConsole*&            game_fight_con   = *(zCConsole**)           0x009813F4;
  zCConsole*&            edit_con         = *(zCConsole**)           0x009813F8;
  zCConsole*&            game_cam_con     = *(zCConsole**)           0x009813FC;
  zCConsole*&            game_aiConsole   = *(zCConsole**)           0x00981400;
  zCNet*&                znet             = *(zCNet**)               0x008BA9D0;
  zCNetManager*&         znetman          = *(zCNetManager**)        0x008BEC90;
  CGameManager*&         gameMan          = *(CGameManager**)        0x008B4398;
  zCFontMan*&            zfontman         = *(zCFontMan**)           0x0098451C;
  oCRtnManager*          rtnMan           =  (oCRtnManager*)         0x00983D10;
  oCMissionManager*      misMan           =  (oCMissionManager*)     0x00981ED8;
  zCRenderManager*       zrenderMan       =  (zCRenderManager*)      0x009742F8;
  zCResourceManager*&    zresMan          = *(zCResourceManager**)   0x009743E0;
  zCSoundManager*&       zsndMan          = *(zCSoundManager**)      0x00974958;
  zCVertexBufferManager* zvertexBufferMan =  (zCVertexBufferManager*)0x009A341C;
  zCParser*              parser           =  (zCParser* )            0x00984C08;
  zCParser*&             parserSoundFX    = *(zCParser**)            0x008C442C;
  zCParser*&             parserParticleFX = *(zCParser**)            0x008CAB60;
  zCParser*&             parserVisualFX   = *(zCParser**)            0x008C008C;
  zCParser*&             parserCamera     = *(zCParser**)            0x008C0468;
  zCParser*&             parserMenu       = *(zCParser**)            0x008C3808;
  zCParser*&             parserMusic      = *(zCParser**)            0x008C3AF4;
  zCFPUControler*        zfpuControler    =  (zCFPUControler*)       0x00974CA4;
  oCParticleControl*&    pfxc             = *(oCParticleControl**)   0x009813E4;
  HINSTANCE&             hInstApp         = *(HINSTANCE*)            0x008C5BE8;
  HDC&                   dcScreen         = *(HDC*)                  0x008C5BEC;
  HICON&                 hIconApp         = *(HICON*)                0x008C5BF0;
  HWND&                  hWndApp          = *(HWND*)                 0x008C5BF4;

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
      zCOption*& Game   = zoptions;
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

#endif // __ZPROTO_B_VER2__
} // Gothic_II_Classic