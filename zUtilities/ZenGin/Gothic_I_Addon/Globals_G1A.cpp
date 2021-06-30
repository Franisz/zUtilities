#include "UnionAfx.h"

namespace Gothic_I_Addon {
#ifdef __ZPROTO_B_VER1__
  zCEngine*&             zengine          = *(zCEngine**)            0x008A31DC;
  zCOption*&             zoptions         = *(zCOption**)            0x008AE3AC;
  zCOption*&             zgameoptions     =  zoptions;
  zCTimer*               ztimer           =  (zCTimer*)              0x009150C0;
  oCGame*&               ogame            = *(oCGame**)              0x00920D8C;
  zCInput*&              zinput           = *(zCInput**)             0x008B2798;
  zCRenderer*&           zrenderer        = *(zCRenderer**)          0x0090BD90;
  zCLineCache*           zlineCache       =  (zCLineCache*)          0x008B51C0;
  zERROR*                zerr             =  (zERROR*)               0x008AE718;
  zCSoundSystem*&        zsound           = *(zCSoundSystem**)       0x00914D14;
  zCMusicSystem*&        zmusic           = *(zCMusicSystem**)       0x008B2FB8;
  oCItem*&               offer            = *(oCItem**)              0x009209BC;
  oCDoc*&                document         = *(oCDoc**)               0x00920B1C;
  zCMallocGeneric*       zmalloc          =  (zCMallocGeneric*)      0x008B9678;
  zTEngineStats*         zengineStats     =  (zTEngineStats*)        0x008B5218;
  zCScanDir*             dirScanner       =  (zCScanDir*)            0x008AE468;
  oCObjectFactory*&      zfactory         = *(oCObjectFactory**)     0x008B9E00;
  zCArchiverFactory*     zarcFactory      =  (zCArchiverFactory*)    0x008B561C;
  oCNpc*&                player           = *(oCNpc**)               0x00923134;
  oCNpc*&                stealnpc         = *(oCNpc**)               0x009232F0;
  zCView*&               screen           = *(zCView**)              0x00926414;
  zCView*&               messages         = *(zCView**)              0x008B22F8;
  zCConsole*             zcon             =  (zCConsole*)            0x009247D8;
  zCConsole*&            game_species_con = *(zCConsole**)           0x00920DA8;
  zCConsole*&            game_fight_con   = *(zCConsole**)           0x00920DAC;
  zCConsole*&            edit_con         = *(zCConsole**)           0x00920DB0;
  zCConsole*&            game_cam_con     = *(zCConsole**)           0x00920DB4;
  zCConsole*&            game_aiConsole   = *(zCConsole**)           0x00920DB8;
  zCNet*&                znet             = *(zCNet**)               0x008A99D4;
  zCNetManager*&         znetman          = *(zCNetManager**)        0x008ADCAC;
  CGameManager*&         gameMan          = *(CGameManager**)        0x008A31D8;
  zCFontMan*&            zfontman         = *(zCFontMan**)           0x00924958;
  oCRtnManager*          rtnMan           =  (oCRtnManager*)         0x00923F38;
  oCMissionManager*      misMan           =  (oCMissionManager*)     0x00921C50;
  zCRenderManager*       zrenderMan       =  (zCRenderManager*)      0x009147C8;
  zCResourceManager*&    zresMan          = *(zCResourceManager**)   0x00914898;
  zCSoundManager*&       zsndMan          = *(zCSoundManager**)      0x00914D8C;
  zCVertexBufferManager* zvertexBufferMan =  (zCVertexBufferManager*)0x0091D0F8;
  zCParser*              parser           =  (zCParser* )            0x00925048;
  zCParser*&             parserSoundFX    = *(zCParser**)            0x008B38C0;
  zCParser*&             parserParticleFX = *(zCParser**)            0x008BA204;
  zCParser*&             parserVisualFX   = *(zCParser**)            0x008AF4EC;
  zCParser*&             parserCamera     = *(zCParser**)            0x008AFB5C;
  zCParser*&             parserMenu       = *(zCParser**)            0x008B2F04;
  zCParser*&             parserMusic      = *(zCParser**)            0x008B31FC;
  zCFPUControler*        zfpuControler    =  (zCFPUControler*)       0x009150E0;
  oCParticleControl*&    pfxc             = *(oCParticleControl**)   0x00920D90;
  HINSTANCE&             hInstApp         = *(HINSTANCE*)            0x008B50C8;
  HDC&                   dcScreen         = *(HDC*)                  0x008B50CC;
  HICON&                 hIconApp         = *(HICON*)                0x008B50D0;
  HWND&                  hWndApp          = *(HWND*)                 0x008B50D4;

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

#endif // __ZPROTO_B_VER1__
} // Gothic_I_Addon