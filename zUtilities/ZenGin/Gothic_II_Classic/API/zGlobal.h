// Supported with union (c) 2018-2021 Union team

#ifndef __ZGLOBAL_H__VER2__
#define __ZGLOBAL_H__VER2__

namespace Gothic_II_Classic {
  extern zCEngine*&             zengine;
  extern zCOption*&             zoptions;
  extern zCOption*&             zgameoptions;
  extern zCTimer*               ztimer;
  extern oCGame*&               ogame;
  extern zCInput*&              zinput;
  extern zCRenderer*&           zrenderer;
  extern zCLineCache*           zlineCache;
  extern zERROR*                zerr;
  extern zCSoundSystem*&        zsound;
  extern zCMusicSystem*&        zmusic;
  extern oCItem*&               offer;
  extern oCDoc*&                document;
  extern zCMallocGeneric*       zmalloc;
  extern zTEngineStats*         zengineStats;
  extern zCScanDir*             dirScanner;
  extern oCObjectFactory*&      zfactory;
  extern zCArchiverFactory*     zarcFactory;
  extern oCNpc*&                player;
  extern oCNpc*&                stealnpc;
  extern zCVob*&                speaker;
  extern zCVob*&                listener;
  extern zCView*&               screen;
  extern zCView*&               messages;
  extern zCConsole*             zcon;
  extern zCConsole*&            game_species_con;
  extern zCConsole*&            game_fight_con;
  extern zCConsole*&            edit_con;
  extern zCConsole*&            game_cam_con;
  extern zCConsole*&            game_aiConsole;
  extern zCNet*&                znet;
  extern zCNetManager*&         znetman;
  extern CGameManager*&         gameMan;
  extern zCFontMan*&            zfontman;
  extern oCRtnManager*          rtnMan;
  extern oCMissionManager*      misMan;
  extern zCRenderManager*       zrenderMan;
  extern zCResourceManager*&    zresMan;
  extern zCSoundManager*&       zsndMan;
  extern zCVertexBufferManager* zvertexBufferMan;
  extern zCParser*              parser;
  extern zCParser*&             parserSoundFX;
  extern zCParser*&             parserParticleFX;
  extern zCParser*&             parserVisualFX;
  extern zCParser*&             parserCamera;
  extern zCParser*&             parserMenu;
  extern zCParser*&             parserMusic;
  extern zCFPUControler*        zfpuControler;
  extern oCParticleControl*&    pfxc;
  extern HINSTANCE&             hInstApp;
  extern HDC&                   dcScreen;
  extern HICON&                 hIconApp;
  extern HWND&                  hWndApp;

  // References
  namespace Gothic {
    namespace Managers {
      extern CGameManager*&          Game;         // Origin name: gameMan
      extern zCFontMan*&             Font;         // Origin name: zfontman
      extern oCRtnManager*&          Routine;      // Origin name: rtnMan
      extern oCMissionManager*&      Mission;      // Origin name: misMan
      extern zCRenderManager*&       Render;       // Origin name: zrenderMan
      extern zCResourceManager*&     Resource;     // Origin name: zresMan
      extern zCSoundManager*&        Sound;        // Origin name: zsndMan
      extern zCVertexBufferManager*& VertexBuffer; // Origin name: zvertexBufferMan
    }
    namespace Parsers {
      extern zCParser*& Game;   // Origin name: parser
      extern zCParser*& SFX;    // Origin name: parserSoundFX
      extern zCParser*& PFX;    // Origin name: parserParticleFX
      extern zCParser*& VFX;    // Origin name: parserVisualFX
      extern zCParser*& Camera; // Origin name: parserCamera
      extern zCParser*& Menu;   // Origin name: parserMenu
      extern zCParser*& Music;  // Origin name: parserMusic
    }
    namespace Network {
      extern zCNet*&        Net;     // Origin name: parserMusic
      extern zCNetManager*& Manager; // Origin name: znetman
    }
    namespace Entities {
      extern oCNpc*& Player;      // Origin name: player
      extern oCNpc*& StealNpc;    // Origin name: stealnpc
      extern zCVob*& VobSpeaker;  // Origin name: speaker
      extern zCVob*& VobListener; // Origin name: listener
    }
    namespace Consoles {
      extern zCConsole*& Main;      // Origin name: zcon
      extern zCConsole*& Species;   // Origin name: game_species_con
      extern zCConsole*& Fight;     // Origin name: game_fight_con
      extern zCConsole*& Abilities; // Origin name: edit_con
      extern zCConsole*& Camera;    // Origin name: game_cam_con
      extern zCConsole*& AI;        // Origin name: game_aiConsole
    }
    namespace Factories {
      extern oCObjectFactory*&   Objects;  // Origin name: zfactory
      extern zCArchiverFactory*& Archives; // Origin name: zarcFactory
    }
    namespace Views {
      extern zCView*& Screen;   // Origin name: screen
      extern zCView*& Messages; // Origin name: messages
    }
    namespace Options {
      extern zCOption*& Gothic; // Origin name: zoptions
      extern zCOption*& Game;   // Origin name: zgameoptions
    }
    namespace Game {
      extern zCTimer*&       Timer;        // Origin name: ztimer
      extern oCGame*&        Session;      // Origin name: ogame
      extern zCInput*&       Input;        // Origin name: zinput
      extern zCRenderer*&    Renderer;     // Origin name: zrenderer
      extern zCLineCache*&   LineCache;    // Origin name: zlineCache
      extern zERROR*&        Error;        // Origin name: zerr
      extern zCSoundSystem*& Sound;        // Origin name: zsound
      extern zCMusicSystem*& Music;        // Origin name: zmusic
      extern zTEngineStats*& EngineStatus; // Origin name: zengineStats
    }
    namespace Other {
      extern zCEngine*&          EnginePointer;     // Origin name: zengine
      extern oCItem*&            OfferItem;         // Origin name: offer
      extern oCDoc*&             Document;          // Origin name: document
      extern zCMallocGeneric*&   Malloc;            // Origin name: zmalloc
      extern zCScanDir*&         DirectoryExplorer; // Origin name: dirScanner
      extern zCFPUControler*&    FPUController;     // Origin name: zfpuControler
      extern oCParticleControl*& PartivleFXControl; // Origin name: pfxc
    }
  }
  namespace Application {
    extern HINSTANCE& Instance; // Origin name: hInstApp;
    extern HDC&       ScreenDC; // Origin name: dcScreen;
    extern HICON&     Icon;     // Origin name: hIconApp;
    extern HWND&      Window;   // Origin name: hWndApp;
  }
  
  uint ASTAPI FindEngineAddress( CStringA from, CStringA to );

  template <typename T>
  inline CInvoke<T> InvokeAuto_BySignature( const CStringA& sig, T ptr, const uint32& flag = IVK_AUTO ) {
    uint adr = FindEngineAddress( sig, typeid( ptr ).name() );
    return CInvoke<T>( adr, ptr, flag );
  }

  template <typename T>
  inline ModulePatchCallInvoker<T> AutoModulePatchCallInvoker_BySignature( const CStringA& sig, T ptr, bool commit = true ) {
    uint adr = FindEngineAddress( sig, typeid(ptr).name() );
    return ModulePatchCallInvoker<T>( adr, ptr, commit );
  }

} // namespace Gothic_II_Classic

#endif // __ZGLOBAL_H__VER2__