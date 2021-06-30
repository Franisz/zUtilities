#include <io.h>
#include <d3d.h>
#include <fstream>
using std::ostream;

#ifdef PlaySound
#undef PlaySound
#endif

#ifdef Success
#undef Success
#endif

#ifdef EVENT_MAX
#undef EVENT_MAX
#endif

#if True
  #define __ZPROTO_B_VER1__
  #include "zPrototypes.h"
  #include "oPrototypes.h"
#endif

// startup
#ifdef __G1A
	#if True
	  #ifdef __ZPROTO_B_VER1__
		#define __ZINIT_B_VER1__
		#include "zMacro.h"
		#include "zInput_Const.h"
		#include "zTypes.h"
		#include "zSpyTypes.h"
		#include "zMemPool.h"
	  #endif
	#endif
#endif

// data, containers, cache, factory
#if True
  #ifdef __ZINIT_B_VER1__
    #define __ZCON_B_VER1__
    #include "zString.h"
    #include "zTools.h"
    #include "zError.h"
    #include "zContainer.h"
    #include "zList.h"
    #include "zAlgebra.h"
    #include "zTypes3d.h"
    #include "zBVolume.h"
    #include "zSparseArray.h"
    #include "zObject.h"
    #include "zThread.h"
    #include "zResource.h"
  #endif
#endif

// input
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZI32_B_VER1__
    #include "zInput_Win32.h"
  #endif
#endif

// z2D views, fonts, fx, etc
#if True
  #ifdef __ZCON_B_VER1__
    #define __Z2D_B_VER1__
    #include "zview.h"
    #include "zViewObject.h"
    #include "zViewDraw.h"
    #include "zViewFx.h"
    #include "zViewPrint_Font.h"
    #include "zViewPrint.h"
    #include "zViewDialog.h"
    #include "zViewDialogChoice.h"
    #include "zFonts.h"
    #include "zConsole.h"
    #include "zGrafix.h"
  #endif
#endif

// o2D inventories, dialogs, documents, menu, etc
#if True
  #ifdef __Z2D_B_VER1__
    #define __O2D_B_VER1__
    #include "oViewDialogInventory.h"
    #include "oViewDialogItem.h"
    #include "oViewDialogItemContainer.h"
    #include "oViewDialogStealContainer.h"
    #include "oViewDialogTrade.h"
    #include "oViewStatusBar.h"
    #include "oDoc.h"
    #include "oDocumentManager.h"
    #include "oHelp.h"
    #include "oInfo.h"
    #include "oInformationManager.h"
    #include "oMenuSavegame.h"
    #include "oViewDocument.h"
    #include "oViewDocumentMap.h"
    #include "oViewProgressbar.h"
    #include "oMenu_Status.h"
    #include "oMenu_Help.h"
  #endif
#endif


// z3D mobs, npcs, zones, worlds, items, etc
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZWLD_B_VER1__
    #include "zScanDir.h"
    #include "zPluecker.h"
    #include "zRayCache.h"
    #include "zCollisionObject.h"
    #include "zCollisionObjectMisc.h"
    #include "zVisual.h"
    #include "oNpc.h"
    #include "zBsp.h"
    #include "oWorld.h"
    #include "oMobInter.h"
    #include "oSpawn.h"
    #include "oObjFactory.h"
  #endif
#endif

// sky
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZSKY_B_VER1__
    #include "zParticle.h"
    #include "zSky.h"
    #include "zSky_Outdoor.h"
    #include "oBarrier.h"
  #endif
#endif


// visual, model, pfx, magic
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZVIS_B_VER1__
    #include "zLensflare.h"
    #include "zMorphMesh.h"
    #include "zPolyStrip.h"
    #include "zFlash.h"
    #include "zProgMesh.h"
    #include "zVertexTransform.h"
    #include "zPolyPool.h"
    #include "oVisFX.h"
    #include "oVisFx_MultiTarget.h"
    #include "oMagic.h"
    #include "oMagFrontier.h"
    #include "oParticleControl.h"
  #endif
#endif

// ai, physic, portals
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZAI_B_VER1__
    #include "zAIPlayer.h"
    #include "zPhysics.h"
    #include "zMoving.h"
    #include "oAIShoot.h"
    #include "oDialog.h"
    #include "oItemReact.h"
    #include "oFocus.h"
    #include "oNpcMessages.h"
    #include "oPortals.h"
    #include "oWaynet.h"
  #endif
#endif

// data system, vdfs
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZFILE_B_VER1__
    #include "zDisk.h"
    #include "zArchiver.h"
    #include "zArchiverGeneric.h"
    #include "zArchiver2.h"
    #include "zDisk_Vdfs.h"
    #include "zFile3d.h"
    #include "zFileCsv.h"
  #endif
#endif


// scripts, gameplay
#if True
  #ifdef __Z2D_B_VER1__
    #define __ZEXT_B_VER1__
    #include "zParser.h"
    #include "zParser_Const.h"
    #include "oSvm.h"
    #include "oText.h"
    #include "oMission.h"
    #include "oGuilds.h"
  #endif
#endif


// net
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZNET_B_VER1__
    #include "zQueue.h"
    #include "zNet.h"
    #include "zNetManager.h"
    #include "zNetEventMan.h"
    #include "zNetVobControl.h"
    #include "zNetVersion.h"
  #endif
#endif

// system, memory
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZHELP_B_VER1__
    #include "zMemory_Base.h"
    #include "zMemory_Win32.h"
    #include "zMemory_Generic.h"
    #include "oSysInfo.h"
  #endif
#endif


// session
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZSES_B_VER1__
    #include "zAccount.h"
    #include "oGameManager.h"
    #include "oGame.h"
    #include "oGameInfo.h"
    #include "oPlayerInfo.h"
    #include "zWorldInfo.h"
  #endif
#endif

// triggers, cutscenes
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZCS_B_VER1__
    #include "zCCsPool.h"
    #include "oCSPlayer.h"
    #include "oCSManager.h"
    #include "oCsProps.h"
    #include "oCsTrigger.h"
    #include "oTrigger.h"
  #endif
#endif

// render
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZRND_B_VER1__
    #include "zScanDir.h"
    #include "zTexture.h"
    #include "zTexConvert.h"
    #include "zMaterial.h"
    #include "zVertexBuffer.h"
    #include "zRndD3d.h"
    #include "zRndD3d_Init.h"
    #include "zRenderManager.h"
    #include "zRenderLightContainer.h"
  #endif
#endif

// sound, music
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZSND_B_VER1__
      #include "zVobMisc.h"
      #include "zMusicCtrl.h"
      #include "zSndMss.h"
  #endif
#endif

// video
#if True
  #ifdef __ZCON_B_VER1__
    #define __ZVID_B_VER1__
    #include "zVideo_Win32.h"
    #include "oBinkPlayer.h"
  #endif
#endif


// collisions
#if True
  #ifdef __ZWLD_B_VER1__
    #define __ZCOLL_B_VER1__
    #include "zPluecker.h"
    #include "zRayCache.h"
    #include "zCollisionObject.h"
    #include "zCollisionObjectMisc.h"
    #include "zConvexCollision.h"
    #include "oCollisionObjectMiscChar.h"
  #endif
#endif

// other
#if True
  #ifdef __ZINIT_B_VER1__
    #define __ZOTHER_B_VER1__
    #include "zEigen.h"
    #include "zVobIdentifier.h"
    #include "zPrime.h"
  #endif
#endif

#include "zGlobal.h"
