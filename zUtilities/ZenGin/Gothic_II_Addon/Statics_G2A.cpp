#include "UnionAfx.h"

namespace Gothic_II_Addon {

#ifdef __OAI_HUMAN_H__VER3__
  zSTRING& oCAIHuman::Cam_Normal = *(zSTRING*)0x00AAD5F8;
  zSTRING& oCAIHuman::Cam_Run    = *(zSTRING*)0x00AAD560;
  zSTRING& oCAIHuman::Cam_Fight  = *(zSTRING*)0x00AAD5E4;
#endif // __OAI_HUMAN_H__VER3__

#ifdef __OCOLLISION_OBJECT_MISC_CHAR_H__VER3__
  zCCollisionObjectDef& oCCollObjectCharacter::s_oCollObjClass = *(zCCollisionObjectDef*)0x00AAC26C;
#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER3__

#ifdef __ODOC_H__VER3__
  zCView*& oCDoc::posView = *(zCView**)0x00AB05D4;
#endif // __ODOC_H__VER3__

#ifdef __OFOCUS_H__VER3__
  oCNpcFocus*& oCNpcFocus::focus             = *(oCNpcFocus**)0x00AB0738;
  oCNpcFocus**& oCNpcFocus::focuslist        = *(oCNpcFocus***)0x00AB06F8;
  int& oCNpcFocus::s_iHightlightMeleeFocus   = *(int*)0x00AB073C;
  int& oCNpcFocus::s_bHighlightInteractFocus = *(int*)0x008B20F4;
  oCVisualFX*& oCNpcFocus::highLightFX       = *(oCVisualFX**)0x00AB0740;
  int& oCNpcFocus::isHighLighted             = *(int*)0x00AB0744;
#endif // __OFOCUS_H__VER3__

#ifdef __OGAME_H__VER3__
  int& oCGame::s_bUseOldControls    = *(int*)0x008B21C0;
  float& oCGame::s_fUseSpeechReverb = *(float*)0x008B21C4;
  int& oCGame::s_bUseOnlineHelp     = *(int*)0x008B21C8;
  int& oCGame::s_bUsePotionKeys     = *(int*)0x008B21CC;
  int& oCGame::s_bUseQuickSave      = *(int*)0x008B21D0;
#endif // __OGAME_H__VER3__

#ifdef __OINFO_H__VER3__
  int& oCInfoManager::size_checked = *(int*)0x00AB0E64;
#endif // __OINFO_H__VER3__

#ifdef __OINVENTORY_H__VER3__
  zCList<oCItemContainer>& oCItemContainer::contList = *(zCList<oCItemContainer>*)0x00AB0FF4;
  int& oCItemContainer::gfx_loaded                   = *(int*)0x00AB10F0;
  zCGfx*& oCItemContainer::gfx_cat                   = *(zCGfx**)0x00AB10F4;
  zCGfx*& oCItemContainer::gfx_equip                 = *(zCGfx**)0x00AB10F8;
  zCGfx*& oCItemContainer::gfx_cursor                = *(zCGfx**)0x00AB10FC;
  zCGfx*& oCItemContainer::gfx_cursor_equip          = *(zCGfx**)0x00AB1100;
  zCGfx**& oCItemContainer::gfx_arrow                = *(zCGfx***)0x00AB1104;
  zCGfx*& oCNpcInventory::gfx_title                  = *(zCGfx**)0x00AB1124;
#endif // __OINVENTORY_H__VER3__

#ifdef __OITEM_H__VER3__
  int& oCItem::s_bItemEffectEnabled      = *(int*)0x008B7460;
  float& oCItem::s_fGlobalItemZBiasScale = *(float*)0x00AB11E8;
#endif // __OITEM_H__VER3__

#ifdef __OITEM_REACT_H__VER3__
  int& oCTradeManager::size_checked = *(int*)0x00AB12D0;
#endif // __OITEM_REACT_H__VER3__

#ifdef __ONEWS_H__VER3__
  int& oCNews::news_counter = *(int*)0x00AB1B84;
#endif // __ONEWS_H__VER3__

#ifdef __ONPC_H__VER3__
  zSTRING*& oCNpc::FightAIInstances        = *(zSTRING**)0x00AAC698;
  oCNpc::oEBloodMode& oCNpc::modeBlood     = *(oEBloodMode*)0x008B0404;
  int& oCNpc::isEnabledDamageDebug         = *(int*)0x00AAC60C;
  oCStealContainer*& oCNpc::stealcontainer = *(oCStealContainer**)0x00AB27DC;
  int& oCNpc::s_bEnabledDialogCamStop      = *(int*)0x00AB2688;
  int& oCNpc::s_bTargetLocked              = *(int*)0x00AB2680;
  zMAT4& oCNpc::s_playerPositionMatrix     = *(zMAT4*)0x00AB26D8;
  oCNpc*& oCNpc::player                    = *(oCNpc**)0x00AB2684;
  int& oCNpc::godmode                      = *(int*)0x00AB2660;
  int& oCNpc::angle_near                   = *(int*)0x008B8120;
  int& oCNpc::angle_far_up                 = *(int*)0x008B8124;
  int& oCNpc::angle_far_side               = *(int*)0x008B8128;
  int& oCNpc::game_mode                    = *(int*)0x00AB27D0;
  oCNpc*& oCNpc::dontArchiveThisNpc        = *(oCNpc**)0x00AB268C;
  int*& oCNpc::bodyStateList               = *(int**)0x00AB1FE0;
  int& oCNpc::ai_disabled                  = *(int*)0x00AB2664;
  float& oCNpc::ai_messagesSkip            = *(float*)0x00AB2668;
  float& oCNpc::ai_messagesSkipTimer       = *(float*)0x00AB266C;
  float& oCNpc::ai_scriptStateSkip         = *(float*)0x00AB2670;
  float& oCNpc::ai_scriptStateSkipTimer    = *(float*)0x00AB2674;
  int& oCNpc::ai_baseEnabled               = *(int*)0x008B8110;
  int& oCNpc::isEnabledTalkBox             = *(int*)0x008B8114;
  int& oCNpc::isEnabledTalkBoxPlayer       = *(int*)0x008B8118;
  int& oCNpc::isEnabledTalkBoxAmbient      = *(int*)0x00AB2678;
  int& oCNpc::isEnabledTalkBoxNoise        = *(int*)0x00AB267C;
#endif // __ONPC_H__VER3__

#ifdef __OTEXT_H__VER3__
  zCView*& oCText::output           = *(zCView**)0x00AB3348;
  int& oCText::TXT_GUILD            = *(int*)0x00AB334C;
  int& oCText::TXT_ATTRIBUTE        = *(int*)0x00AB3350;
  int& oCText::TXT_FIGHT_TALENT     = *(int*)0x00AB3354;
  int& oCText::TXT_TALENT           = *(int*)0x00AB3358;
  int& oCText::TXT_DAYTIME          = *(int*)0x00AB335C;
  int*& oCText::TXT_ATR             = *(int**)0x00AB3330;
  int& oCText::TXT_ATR_HP           = *(int*)0x00AB3360;
  int& oCText::TXT_SPELL            = *(int*)0x00AB3368;
  int& oCText::TXT_ATTITUDE         = *(int*)0x00AB3364;
  int& oCText::TXT_PC_GREETING      = *(int*)0x00AB336C;
  int& oCText::TXT_PC_FIRST_PHRASE  = *(int*)0x00AB3370;
  int& oCText::TXT_PC_SECOND_PHRASE = *(int*)0x00AB3374;
  int& oCText::TXT_PC_TRADE_PHRASE  = *(int*)0x00AB3378;
  int& oCText::TXT_NPC_LAST_PHRASE  = *(int*)0x00AB337C;
  int& oCText::TXT_PC_TRADE_THREAT  = *(int*)0x00AB3380;
  int& oCText::TXT_NPC_TRADE_THREAT = *(int*)0x00AB3384;
  int& oCText::TXT_PC_INFO_THREAT   = *(int*)0x00AB3388;
  int& oCText::TXT_NPC_INFO_THREAT  = *(int*)0x00AB338C;
  int& oCText::TXT_NEWS_INTRO       = *(int*)0x00AB3394;
  int& oCText::TXT_NEWS_STOLE       = *(int*)0x00AB3398;
  int& oCText::TXT_NEWS_STOLE_10    = *(int*)0x00AB339C;
  int& oCText::TXT_NEWS_STOLE_30    = *(int*)0x00AB33A0;
  int& oCText::TXT_NEWS_STOLE_50    = *(int*)0x00AB33A4;
  int& oCText::TXT_NEWS_STOLE_70    = *(int*)0x00AB33A8;
  int& oCText::TXT_NEWS_STOLE_90    = *(int*)0x00AB33AC;
  int& oCText::TXT_NEWS_STOLE_100   = *(int*)0x00AB33B0;
  int& oCText::TXT_NEWS_ATTACKED    = *(int*)0x00AB33B4;
  int& oCText::TXT_NEWS_KILLED      = *(int*)0x00AB33B8;
  int& oCText::TXT_YNEWS_INTRO      = *(int*)0x00AB33BC;
  int& oCText::TXT_YNEWS_STOLE      = *(int*)0x00AB33C0;
  int& oCText::TXT_YNEWS_STOLE_10   = *(int*)0x00AB33C4;
  int& oCText::TXT_YNEWS_STOLE_30   = *(int*)0x00AB33C8;
  int& oCText::TXT_YNEWS_STOLE_50   = *(int*)0x00AB33CC;
  int& oCText::TXT_YNEWS_STOLE_70   = *(int*)0x00AB33D0;
  int& oCText::TXT_YNEWS_STOLE_90   = *(int*)0x00AB33D4;
  int& oCText::TXT_YNEWS_STOLE_100  = *(int*)0x00AB33D8;
  int& oCText::TXT_YNEWS_ATTACKED   = *(int*)0x00AB33DC;
  int& oCText::TXT_YNEWS_KILLED     = *(int*)0x00AB33E0;
  int& oCText::TXT_INTIMIDATION     = *(int*)0x00AB3390;
  int& oCText::TXT_INVCAT           = *(int*)0x00AB33E4;
  int& oCText::TXT_HELP             = *(int*)0x00AB33E8;
#endif // __OTEXT_H__VER3__

#ifdef __OVIS_FX_H__VER3__
  zCParser*& oCVisualFX::fxParser = *(zCParser**)0x008CE6EC;
  oCVisualFX*& oCVisualFX::actFX  = *(oCVisualFX**)0x008CE7EC;
#endif // __OVIS_FX_H__VER3__

#ifdef __Z3D_H__VER3__
  zCCamera*& zCCamera::activeCam                                                     = *(zCCamera**)0x008D7F94;
  zVEC3& zCCamera::activeCamPos                                                      = *(zVEC3*)0x008D7F88;
  zCVertex*& zCPolygon::s_clipVertScene                                              = *(zCVertex**)0x00921338;
  int& zCPolygon::s_numClipVertScene                                                 = *(int*)0x00949338;
  zCVertFeature*& zCPolygon::s_clipFeatScene                                         = *(zCVertFeature**)0x008E9270;
  int& zCPolygon::s_numClipFeatScene                                                 = *(int*)0x00921334;
  int& zCPolygon::s_numVertListScene                                                 = *(int*)0x009593F8;
  int& zCPolygon::s_numFeatListScene                                                 = *(int*)0x0094934C;
  zCVertex**& zCPolygon::s_actClipVert                                               = *(zCVertex***)0x009594D0;
  int& zCPolygon::s_actNumClipVert                                                   = *(int*)0x009594D4;
  zCArraySort<zCPolygon::zSVertexSavedValues>& zCPolygon::morphedVerticesList_Height = *(zCArraySort<zSVertexSavedValues>*)0x00959418;
  zCArraySort<zCPolygon::zSVertexSavedValues>& zCPolygon::morphedVerticesList_Wall   = *(zCArraySort<zSVertexSavedValues>*)0x009593FC;
  zCArraySort<zCPolygon::zSFeatureSavedValues>& zCPolygon::morphedFeatureList        = *(zCArraySort<zSFeatureSavedValues>*)0x0094933C;
  zCArray<zCPolygon::zSPolySavedValues>& zCPolygon::morphedPolysSavedValuesList      = *(zCArray<zSPolySavedValues>*)0x0095940C;
  zCMaterial*& zCPortal::portalDummyMaterial                                         = *(zCMaterial**)0x008D7EA8;
#endif // __Z3D_H__VER3__

#ifdef __ZACCOUNT_H__VER3__
  int& zCAccount::s_actCounter = *(int*)0x00AAC31C;
#endif // __ZACCOUNT_H__VER3__

#ifdef __ZAI_CAMERA_H__VER3__
  short int& zCAICamera::s_iLookAroundSgn         = *(short int*)0x00897BA0;
  zCArray<zCCSCamera*>& zCAICamera::dialogCamList = *(zCArray<zCCSCamera*>*)0x008CE9BC;
  float& zCAICamera::lookingCamLastAzi            = *(float*)0x008CEAC0;
  int& zCAICamera::lookingCamAziGoalReached       = *(int*)0x008CEAC4;
  zCAICamera*& zCAICamera::current                = *(zCAICamera**)0x008CEAB8;
  int& zCAICamera::bCreated                       = *(int*)0x008CEABC;
  int& zCAICamera::bCamChanges                    = *(int*)0x00897B94;
#endif // __ZAI_CAMERA_H__VER3__

#ifdef __ZAI_PLAYER_H__VER3__
  int& zCAIPlayer::s_bShowWeaponTrails = *(int*)0x0089EC90;
#endif // __ZAI_PLAYER_H__VER3__

#ifdef __ZARCHIVER_H__VER3__
  zSTRING& zCArchiver::stringEOL = *(zSTRING*)0x008D4898;
#endif // __ZARCHIVER_H__VER3__

#ifdef __ZBSP_H__VER3__
  int& zCRayTurboAdmin::s_iPolyTreshold                     = *(int*)0x0089FE9C;
  int& zCBspTree::s_showPortals                             = *(int*)0x008D7EAC;
  int& zCBspTree::s_renderAllPortals                        = *(int*)0x008D7EB0;
  int& zCBspSector::s_sectorsRendered                       = *(int*)0x008D49E4;
  int& zCBspSector::s_startPointOutdoor                     = *(int*)0x008D49A8;
  int& zCBspSector::s_outdoorPortal                         = *(int*)0x008D49F4;
  zCArray<zCBspSector*>& zCBspSector::s_activeSectorList    = *(zCArray<zCBspSector*>*)0x008D49F8;
  zCArray<zTBBox2D>& zCBspSector::s_activeOutdoorPortals    = *(zCArray<zTBBox2D>*)0x008D4960;
#endif // __ZBSP_H__VER3__

#ifdef __ZBVOLUME_H__VER3__
  zMAT4& zCOBBox3D::trafoB2ToThis = *(zMAT4*)0x008D7F08;
#endif // __ZBVOLUME_H__VER3__

#ifdef __ZCCS_CONTEXT_H__VER3__
  int& zCCSCutsceneContext::playDisabled = *(int*)0x008C218C;
#endif // __ZCCS_CONTEXT_H__VER3__

#ifdef __ZCOLLISION_DETECTOR_H__VER3__
  unsigned long& zCCollisionDetector::s_iCollisionDetectorFrameCtr = *(unsigned long*)0x008D82E8;
  int& zCCollisionDetector::s_iCurrentCollReport                   = *(int*)0x008D82EC;
  zCCollisionReport*& zCCollisionDetector::s_aoCollReportList      = *(zCCollisionReport**)0x008D7FA8;
#endif // __ZCOLLISION_DETECTOR_H__VER3__

#ifdef __ZCOLLISION_OBJECT_H__VER3__
  zCArray<zCCollisionObjectDef*>*& zCCollisionObjectDef::s_aoCollObjClassList = *(zCArray<zCCollisionObjectDef*>**)0x008D8304;
#endif // __ZCOLLISION_OBJECT_H__VER3__

#ifdef __ZCONSOLE_H__VER3__
  zCList<zCConsole>& zCConsole::active_consoles = *(zCList<zCConsole>*)0x00AB393C;
  zCConsole*& zCConsole::cur_console            = *(zCConsole**)0x00AB3944;
#endif // __ZCONSOLE_H__VER3__

#ifdef __ZCONVEX_COLLISION_H__VER3__
  zCConvexPrimitiveUnitSphere& zCConvexPrimitiveUnitSphere::s_unitSphere = *(zCConvexPrimitiveUnitSphere*)0x008D8448;
#endif // __ZCONVEX_COLLISION_H__VER3__

#ifdef __ZCS_CAMERA_H__VER3__
  int& zCCSCamera::playing        = *(int*)0x008D11B0;
  int& zCCSCamera::draw           = *(int*)0x008D11B4;
  int& zCCSCamera::evaluateAvgFPS = *(int*)0x008D11B8;
#endif // __ZCS_CAMERA_H__VER3__

#ifdef __ZDISK_H__VER3__
  int& zFILE::s_numFilesOpen                         = *(int*)0x008C34B0;
  int& zFILE::s_maxFilesOpen                         = *(int*)0x008C34B4;
  zCCriticalSection*& zFILE::s_dirscanCiticalSection = *(zCCriticalSection**)0x008C34AC;
  zFILE*& zFILE::s_virtPath                          = *(zFILE**)0x008C3490;
  zSTRING& zFILE::s_virtPathString                   = *(zSTRING*)0x008C3494;
  zSTRING& zFILE::s_physPathString                   = *(zSTRING*)0x008C347C;
  zSTRING& zFILE::s_rootDirString                    = *(zSTRING*)0x008C3468;
  bool& zFILE::s_initialized                         = *(bool*)0x008C34B8;
  zCBuffer**& zFILE::bufferList                      = *(zCBuffer***)0x008C3434;
  int*& zFILE::bufferFlag                            = *(int**)0x008C344C;
#endif // __ZDISK_H__VER3__

#ifdef __ZDISK__VDFS_H__VER3__
  bool& zFILE_VDFS::s_vdfsInitialized               = *(bool*)0x008C34C4;
  bool& zFILE_VDFS::s_physical_first                = *(bool*)0x008C34C5;
  zCCriticalSection*& zFILE_VDFS::s_criticalSection = *(zCCriticalSection**)0x008C34C8;
#endif // __ZDISK__VDFS_H__VER3__

#ifdef __ZEIGEN_H__VER3__
  int& zCMgcEigenD::verbose                          = *(int*)0x008D8544;
  unsigned int& zCMgcEigenD::error                   = *(unsigned int*)0x008D8548;
  const unsigned int& zCMgcEigenD::invalid_size      = *(const unsigned int*)0x008320DC;
  const unsigned int& zCMgcEigenD::allocation_failed = *(const unsigned int*)0x008320E0;
  const unsigned int& zCMgcEigenD::ql_exceeded       = *(const unsigned int*)0x008320E4;
  const char**& zCMgcEigenD::message                 = *(const char***)0x008A13D8;
#endif // __ZEIGEN_H__VER3__

#ifdef __ZEVENT_MAN_H__VER3__
  int& zCEventManager::disableEventManagers          = *(int*)0x00AB39C8;
  zCArray<zCEventManager*>& zCEventManager::activeEM = *(zCArray<zCEventManager*>*)0x00AB39BC;
  int& zCEventManager::showMsgCommunication          = *(int*)0x00AB39CC;
#endif // __ZEVENT_MAN_H__VER3__

#ifdef __ZFFT_H__VER3__
  zCFFT& zCFFT::s_fft     = *(zCFFT*)0x008D85A0;
  zCFFT& zCFFT::s_fftSlow = *(zCFFT*)0x008D8558;
  zCFFT& zCFFT::s_fftFast = *(zCFFT*)0x008D8574;
#endif // __ZFFT_H__VER3__

#ifdef __ZFONTS_H__VER3__
  zCTextureConvert*& zCFont::texConv = *(zCTextureConvert**)0x00AB39D8;
#endif // __ZFONTS_H__VER3__

#ifdef __ZGRAFIX_H__VER3__
  zCGfx*& zCGfx::Gfx_List = *(zCGfx**)0x00AB4090;
  int& zCGfx::gfxcount    = *(int*)0x00AB4094;
#endif // __ZGRAFIX_H__VER3__

#ifdef __ZINPUT_H__VER3__
  zCArray<zSCtrlValue>& zCInput::values = *(zCArray<zSCtrlValue>*)0x008D1640;
#endif // __ZINPUT_H__VER3__

#ifdef __ZLENSFLARE_H__VER3__
  zCMesh*& zCLensFlareFX::s_lensFlareMesh = *(zCMesh**)0x008D8664;
  zCMesh*& zCLensFlareFX::s_coronaMesh    = *(zCMesh**)0x008D8668;
  zCMesh*& zCLensFlareFX::s_glowMesh      = *(zCMesh**)0x008D866C;
#endif // __ZLENSFLARE_H__VER3__

#ifdef __ZMATERIAL_H__VER3__
  unsigned long& zCTexAniCtrl::masterFrameCtr  = *(unsigned long*)0x008D8774;
  unsigned char& zCMaterial::s_matUsageDefault = *(unsigned char*)0x008A2264;
#endif // __ZMATERIAL_H__VER3__

#ifdef __ZMATH_TOOLS_H__VER3__
  zMAT4& zCPose::tmpMat = *(zMAT4*)0x008D1DF0;
#endif // __ZMATH_TOOLS_H__VER3__

#ifdef __ZMEM_POOL_H__VER3__
  const char*& zCMemPoolBase::s_className = *(const char**)0x008D8780;
  const char*& zCMemPoolBase::s_fileName  = *(const char**)0x008D8784;
  int& zCMemPoolBase::s_line              = *(int*)0x008D8788;
  int& zCMemPoolBase::s_disablePools      = *(int*)0x008A2558;
#endif // __ZMEM_POOL_H__VER3__

#ifdef __ZMENU_H__VER3__
  zCParser*& zCMenu::menuParser          = *(zCParser**)0x008D1E68;
  zCTimer*& zCMenu::timer                = *(zCTimer**)0x008D1E74;
  zCArraySort<zCMenu*>& zCMenu::menuList = *(zCArraySort<zCMenu*>*)0x008D1E44;
  zCArray<zCMenu*>& zCMenu::activeList   = *(zCArray<zCMenu*>*)0x008D1E38;
  zCSoundFX*& zCMenu::browseSnd          = *(zCSoundFX**)0x008D1E88;
  zCSoundFX*& zCMenu::selectSnd          = *(zCSoundFX**)0x008D1E8C;
  zCSoundFX*& zCMenu::escSnd             = *(zCSoundFX**)0x008D1E90;
  zCVob*& zCMenu::soundSourceVob         = *(zCVob**)0x008D1E94;
  zCWorld*& zCMenu::world                = *(zCWorld**)0x008D1E6C;
  zCCamera*& zCMenu::camera              = *(zCCamera**)0x008D1E70;
  int& zCMenu::inGameMenu                = *(int*)0x008D1E78;
#endif // __ZMENU_H__VER3__

#ifdef __ZMENU__ITEM_H__VER3__
  zCArraySort<zCMenuItem*>& zCMenuItem::itemList = *(zCArraySort<zCMenuItem*>*)0x008D1EFC;
  zCMenuItem*& zCMenuItem::tmp                   = *(zCMenuItem**)0x008D1F0C;
#endif // __ZMENU__ITEM_H__VER3__

#ifdef __ZMODEL_H__VER3__
  float& zTMdl_AniSample::samplePosScaler          = *(float*)0x008D8AAC;
  float& zTMdl_AniSample::samplePosRangeMin        = *(float*)0x008D8BAC;
  int& zCModelPrototype::s_ignoreAnis              = *(int*)0x008D8BE8;
  int& zCModelPrototype::s_autoConvertAnis         = *(int*)0x008A31F8;
  int& zCModelPrototype::s_autoConvertMeshes       = *(int*)0x008D8BEC;
  zCModelPrototype*& zCModelPrototype::s_modelRoot = *(zCModelPrototype**)0x008D8BF0;
  int& zCModel::s_drawSkeleton                     = *(int*)0x008D8A84;
  int& zCModel::s_bSmoothRootNode                  = *(int*)0x008A2D50;
  int*& zCModel::s_iNumSoftSkinPoly                = *(int**)0x008D8A20;
#endif // __ZMODEL_H__VER3__

#ifdef __ZMORPH_MESH_H__VER3__
  int& zCMorphMeshProto::autoConvertBinaryFile   = *(int*)0x008D8CC8;
  zCMorphMeshProto*& zCMorphMeshProto::morphRoot = *(zCMorphMeshProto**)0x008D8CC4;
#endif // __ZMORPH_MESH_H__VER3__

#ifdef __ZMUSIC_H__VER3__
  int& zCMusicSystem::s_musicSystemDisabled = *(int*)0x008D1F18;
#endif // __ZMUSIC_H__VER3__

#ifdef __ZNET_HOST_H__VER3__
  unsigned char& zCNetHost::iter   = *(unsigned char*)0x008CD1A8;
  zCNetHost*& zCNetHost::localhost = *(zCNetHost**)0x008CD1AC;
#endif // __ZNET_HOST_H__VER3__

#ifdef __ZPARSER_H__VER3__
  int& zCParser::enableParsing    = *(int*)0x00AB6284;
  zCParser*& zCParser::cur_parser = *(zCParser**)0x00AB628C;
#endif // __ZPARSER_H__VER3__

#ifdef __ZPARSER__SYMBOL_H__VER3__
  zCPar_Symbol*& zCPar_Symbol::instance_sym        = *(zCPar_Symbol**)0x00AB6430;
  void*& zCPar_Symbol::instance_adr                = *(void**)0x00AB6434;
  zCPar_SymbolTable*& zCPar_SymbolTable::cur_table = *(zCPar_SymbolTable**)0x00AB6428;
#endif // __ZPARSER__SYMBOL_H__VER3__

#ifdef __ZPARTICLE_H__VER3__
  zCParser*& zCParticleFX::s_pfxParser                               = *(zCParser**)0x008D9234;
  zCArraySort<zCParticleEmitter*>& zCParticleFX::s_emitterPresetList = *(zCArraySort<zCParticleEmitter*>*)0x008D8E0C;
  zCParticleEmitter& zCParticleFX::s_emitterDummyDefault             = *(zCParticleEmitter*)0x008D8E20;
  int& zCParticleFX::s_bAmbientPFXEnabled                            = *(int*)0x008A4E48;
  int& zCParticleFX::s_globNumPart                                   = *(int*)0x008D9220;
  zTParticle*& zCParticleFX::s_globPartList                          = *(zTParticle**)0x008D9224;
  zTParticle*& zCParticleFX::s_globFreePart                          = *(zTParticle**)0x008D9228;
  zCMesh*& zCParticleFX::s_partMeshTri                               = *(zCMesh**)0x008D922C;
  zCMesh*& zCParticleFX::s_partMeshQuad                              = *(zCMesh**)0x008D9230;
  int& zCParticleFX::s_showDebugInfo                                 = *(int*)0x008D9238;
  zCParticleFX::zCStaticPfxList& zCParticleFX::s_pfxList             = *(zCStaticPfxList*)0x008D9214;
#endif // __ZPARTICLE_H__VER3__

#ifdef __ZPLAYER_GROUP_H__VER3__
  zCPlayerGroup& zCPlayerGroup::allPlayerGroup     = *(zCPlayerGroup*)0x008CD9B4;
  zCList<zCPlayerGroup>& zCPlayerGroup::group_list = *(zCList<zCPlayerGroup>*)0x008CD998;
#endif // __ZPLAYER_GROUP_H__VER3__

#ifdef __ZPLAYER_INFO_H__VER3__
  zCArray<int>& zCPlayerInfo::free_ids      = *(zCArray<int>*)0x008CD9F4;
  unsigned char& zCPlayerInfo::next_id      = *(unsigned char*)0x00894FF0;
  zCPlayerInfo*& zCPlayerInfo::activePlayer = *(zCPlayerInfo**)0x008CDA28;
#endif // __ZPLAYER_INFO_H__VER3__

#ifdef __ZPROG_MESH_H__VER3__
  zTFrameCtr& zCProgMeshProto::s_frameCtr                   = *(zTFrameCtr*)0x008A532C;
  unsigned short int*& zCProgMeshProto::s_wedgeRemap        = *(unsigned short int**)0x0095CA10;
  zVEC3*& zCProgMeshProto::s_posCacheList                   = *(zVEC3**)0x0096AA78;
  zVEC3*& zCProgMeshProto::s_posNormalCSList                = *(zVEC3**)0x00970B10;
  zCArray<unsigned short>& zCProgMeshProto::s_workIndexList = *(zCArray<unsigned short>*)0x00982B10;
  int& zCProgMeshProto::s_subMeshRenderDir                  = *(int*)0x008A5330;
  zVEC3*& zCProgMeshProto::s_posCacheListLOD                = *(zVEC3**)0x0095EA10;
  int*& zCProgMeshProto::s_posCacheListLODIndices           = *(int**)0x00976B10;
  int& zCProgMeshProto::s_posCacheCount                     = *(int*)0x00982BF0;
  int& zCProgMeshProto::s_posCacheCountLOD                  = *(int*)0x00982BF4;
  int& zCProgMeshProto::s_posCacheIndex                     = *(int*)0x00982BF8;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferColor    = *(zCVertexBufferDyn**)0x00982C08;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferNormal   = *(zCVertexBufferDyn**)0x00982C0C;
  float& zCProgMeshProto::s_lodParamStrengthOverride        = *(float*)0x008A5334;
  float& zCProgMeshProto::s_lodParamStrengthModifier        = *(float*)0x008A5338;
  int& zCProgMeshProto::s_markMeshMaterials                 = *(int*)0x00982C04;
  int& zCProgMeshProto::s_autoSubdivEnabled                 = *(int*)0x00982BE8;
  unsigned long& zCProgMeshProto::s_classCtorCtr            = *(unsigned long*)0x00982BEC;
#endif // __ZPROG_MESH_H__VER3__

#ifdef __ZRAY_CACHE_H__VER3__
  zCRayCacheElement*& zCRayCache::s_current = *(zCRayCacheElement**)0x00982E7C;
  zVEC3& zCRayCache::s_start                = *(zVEC3*)0x00982C9C;
  zVEC3& zCRayCache::s_stop                 = *(zVEC3*)0x00982CA8;
  zCRayCache*& zCRayCache::s_anchor         = *(zCRayCache**)0x00982E78;
#endif // __ZRAY_CACHE_H__VER3__

#ifdef __ZRENDER_MANAGER_H__VER3__
  zCShader*& zCRenderManager::s_shaderList                        = *(zCShader**)0x00985F88;
  zCShaderStage*& zCRenderManager::s_shaderStageList              = *(zCShaderStage**)0x00982F88;
  int& zCRenderManager::s_currentShader                           = *(int*)0x0099AA84;
  int& zCRenderManager::s_currentShaderStage                      = *(int*)0x0099AA88;
  int& zCRenderManager::s_useRendererTNL                          = *(int*)0x008A5A00;
  int& zCRenderManager::s_detailTexturesEnabled                   = *(int*)0x008A5A04;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex1       = *(zCVertexBufferDyn2**)0x0099AA8C;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2       = *(zCVertexBufferDyn2**)0x0099AA90;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2Normal = *(zCVertexBufferDyn2**)0x0099AA94;
#endif // __ZRENDER_MANAGER_H__VER3__

#ifdef __ZRND_D3D_H__VER3__
  zCVertexBufferDyn*& zD3D_alphaPoly::vertexbufferdyn                           = *(zCVertexBufferDyn**)0x009FCA04;
  zCVertexBuffer*& zD3D_alphaPoly::vertexbuffer                                 = *(zCVertexBuffer**)0x009FCA08;
  int& zD3D_alphaPoly::locked                                                   = *(int*)0x009FCA0C;
  unsigned long& zD3D_alphaPoly::startvertex                                    = *(unsigned long*)0x009FCA10;
  unsigned long& zD3D_alphaPoly::actvertex                                      = *(unsigned long*)0x009FCA14;
  int& zD3D_alphaPoly::numberofvertices                                         = *(int*)0x009FCA18;
  int& zD3D_alphaPoly::actnov                                                   = *(int*)0x009FCA1C;
  struct ID3DXContext*& zCRnd_D3D::xd3d_pd3dx                                   = *(struct ID3DXContext**)0x009FC9E8;
  IDirectDraw7*& zCRnd_D3D::xd3d_pdd7                                           = *(IDirectDraw7**)0x009FC9EC;
  IDirect3D7*& zCRnd_D3D::xd3d_pd3d7                                            = *(IDirect3D7**)0x009FC9F0;
  IDirect3DDevice7*& zCRnd_D3D::xd3d_pd3dDevice7                                = *(IDirect3DDevice7**)0x009FC9F4;
  unsigned long& zCRnd_D3D::xd3d_actFrameNumber                                 = *(unsigned long*)0x009FCA00;
  int& zCRnd_D3D::xd3d_dd7inuse                                                 = *(int*)0x009FC9F8;
  int& zCRnd_D3D::xd3d_palsupp                                                  = *(int*)0x009FC9FC;
  zCSurfaceCache_D3D::zD3D_SlotHeader**& zCSurfaceCache_D3D::xsc_listofsurfaces = *(zCSurfaceCache_D3D::zD3D_SlotHeader***)0x009D2FE8;
  int& zCSurfaceCache_D3D::xsc_listposition                                     = *(int*)0x009FCA20;
  zCArray<zCVertexBuffer_D3D*>& zCVertexBuffer_D3D::xvb_vertexbufferList        = *(zCArray<zCVertexBuffer_D3D*>*)0x009FCA3C;
#endif // __ZRND_D3D_H__VER3__

#ifdef __ZSKY_H__VER3__
  zCSkyControler*& zCSkyControler::s_activeSkyControler = *(zCSkyControler**)0x0099AC8C;
  int& zCSkyControler::s_skyEffectsEnabled              = *(int*)0x008A5DB0;
#endif // __ZSKY_H__VER3__

#ifdef __ZSND_MSS_H__VER3__
  zCArraySort<zCActiveSnd*>& zCActiveSnd::activeSndList = *(zCArraySort<zCActiveSnd*>*)0x008D2198;
  unsigned long& zCActiveSnd::lastHandle                = *(unsigned long*)0x008D2A58;
  int& zCActiveSnd::maxChannels                         = *(int*)0x0089B388;
  int& zCActiveSnd::autoUpdate3D                        = *(int*)0x008D2A5C;
  zCArray<zCActiveSnd*>& zCActiveSnd::preAllocedSndList = *(zCArray<zCActiveSnd*>*)0x008D2A20;
  zCActiveSnd*& zCActiveSnd::nextFreeSnd                = *(zCActiveSnd**)0x008D2A54;
  zCDrvProperties_MSS& zCSndSys_MSS::prefs              = *(zCDrvProperties_MSS*)0x008D22E8;
#endif // __ZSND_MSS_H__VER3__

#ifdef __ZSOUND_MAN_H__VER3__
  zCSoundManager::zTScriptSoundData& zCSoundManager::scriptSoundData = *(zTScriptSoundData*)0x0099B04C;
  zSTRING& zCSoundManager::mediumIDList                              = *(zSTRING*)0x0099B088;
  zSTRING& zCSoundManager::prefixProto                               = *(zSTRING*)0x0099B09C;
#endif // __ZSOUND_MAN_H__VER3__

#ifdef __ZTEXTURE_H__VER3__
  zSTRING& zCTexture::zTEX_DEFAULT_TEXTURE_FILE           = *(zSTRING*)0x0099B2C0;
  zTTexScaleSize& zCTexture::s_texScaleSize               = *(zTTexScaleSize*)0x008A6AAC;
  zTTexScaleBPP& zCTexture::s_texScaleBPP                 = *(zTTexScaleBPP*)0x008A6AB0;
  unsigned long& zCTexture::s_texSupportedFormats         = *(unsigned long*)0x0099B3B8;
  char& zCTexture::s_useDefaultTex                        = *(char*)0x008A6AA8;
  char& zCTexture::s_globalLoadTextures                   = *(char*)0x008A6AA9;
  unsigned long& zCTexture::s_texMaxPixelSize             = *(unsigned long*)0x0099B3BC;
  zSTRING*& zCTexture::s_texDesiredBPPSuffix              = *(zSTRING**)0x0099B368;
  zTRnd_TextureFormat*& zCTexture::s_texDesiredBPPDefault = *(zTRnd_TextureFormat**)0x008A6ABC;
  float& zCTexture::s_texRefRAM                           = *(float*)0x008A6AB4;
  zCTexture::zTTexFileDesiredBPP& zCTexture::s_texRefBPP  = *(zCTexture::zTTexFileDesiredBPP*)0x008A6AB8;
#endif // __ZTEXTURE_H__VER3__

#ifdef __ZSPARSE_ARRAY_H__VER3__
  int& zCCacheBase::s_currentFrame    = *(int*)0x00974968;
  zCCacheBase*& zCCacheBase::s_anchor = *(zCCacheBase**)0x0097496C;
  zCCacheBase*& zCCacheBase::s_run    = *(zCCacheBase**)0x00974970;
#endif // __ZSPARSE_ARRAY_H__VER3__

#ifdef __ZTOOLS_H__VER3__
  unsigned long& zCTimer::s_forcedMaxFrameTime = *(unsigned long*)0x0099B404;
#endif // __ZTOOLS_H__VER3__

#ifdef __ZVERTEX_BUFFER_H__VER3__
  unsigned long& zCVertexBuffer::s_classCtorCtr = *(unsigned long*)0x009A34A8;
#endif // __ZVERTEX_BUFFER_H__VER3__

#ifdef __ZVIEW_BASE_H__VER3__
  const unsigned short& zCViewBase::ViewVirtualWidth  = *(const unsigned short*)0x0083BB40;
  const unsigned short& zCViewBase::ViewVirtualHeight = *(const unsigned short*)0x0083BB42;
#endif // __ZVIEW_BASE_H__VER3__

#ifdef __ZVISUAL_H__VER3__
  zCArray<zCVisual*>& zCVisual::s_visualClassList = *(zCArray<zCVisual*>*)0x009A34CC;
  zCMesh*& zCDecal::decalMesh1Sided               = *(zCMesh**)0x008D8538;
  zCMesh*& zCDecal::decalMesh2Sided               = *(zCMesh**)0x008D853C;
  int& zCMesh::s_autoConvertMeshes                = *(int*)0x008D8868;
  int& zCMesh::s_usesVertexCache                  = *(int*)0x008D886C;
  int& zCMesh::s_numMeshes                        = *(int*)0x008D8860;
  zCMesh*& zCMesh::s_meshRoot                     = *(zCMesh**)0x008D8864;
  zCArraySort<zCVertex*>& zCMesh::s_vertexCache   = *(zCArraySort<zCVertex*>*)0x008D87B8;
#endif // __ZVISUAL_H__VER3__

#ifdef __ZVOB_H__VER3__
  int& zCVob::s_ignoreVisuals                             = *(int*)0x009A37F0;
  zCMesh*& zCVob::s_shadowMesh                            = *(zCMesh**)0x009A37E8;
  unsigned long& zCVob::s_nextFreeID                      = *(unsigned long*)0x009A37EC;
  int& zCVob::s_vobAlreadyInMovement                      = *(int*)0x009A37E4;
  int& zCVob::s_renderVobs                                = *(int*)0x008A7634;
  int& zCVob::s_showHelperVisuals                         = *(int*)0x009A37F4;
  int& zCVob::s_enableAnimations                          = *(int*)0x008A7638;
  zCCollisionDetector*& zCVob::s_poCollisionDetector      = *(zCCollisionDetector**)0x009A37F8;
  zCArray<zCVobLightPreset*>& zCVobLight::lightPresetList = *(zCArray<zCVobLightPreset*>*)0x009A387C;
  int& zCVobLight::renderLightVisuals                     = *(int*)0x009A3888;
  int& zCVobLevelCompo::unarcIgnoreVisuals                = *(int*)0x009A37FC;
#endif // __ZVOB_H__VER3__

#ifdef __ZOBJECT_H__VER3__
  zCArraySort<zCClassDef*>*& zCClassDef::classDefList = *(zCArraySort<zCClassDef*>**)0x008D8DE0;
  zCClassDef*& zCClassDef::classDefSearchDummy        = *(zCClassDef**)0x008D8DE8;
  int& zCClassDef::startupFinished                    = *(int*)0x008D8DE4;
#endif
  
#ifdef __ZZONE_H__VER3__
  zCBBox3DSorterBase*& zCBBox3DSorterBase::s_currentSorter = *(zCBBox3DSorterBase**)0x009A4684;
  int& zCBBox3DSorterBase::s_currentDimension              = *(int*)0x009A46F4;
  int& zCZoneMusic::s_autochange                           = *(int*)0x008AAF6C;
  int& zCZoneMusic::s_canruleautochange                    = *(int*)0x009A4924;
#endif

#ifdef __OMUSIC_ZONE_H__VER3__
  long& oCZoneMusic::s_lastzonechange       = *(long*)0x009A4A1C;
  int& oCZoneMusic::s_zonetime              = *(int*)0x008AB2DC;
  int& oCZoneMusic::s_daytime               = *(int*)0x008AB2E0;
  oHEROSTATUS& oCZoneMusic::s_herostatus    = *(oHEROSTATUS*)0x009A4A20;
  oCZoneMusic*& oCZoneMusic::s_musiczone    = *(oCZoneMusic**)0x009A4A24;
  oCZoneMusic*& oCZoneMusic::s_oldmusiczone = *(oCZoneMusic**)0x009A4A28;
#endif

#ifdef __ZALGEBRA_H__VER3__
  zMAT3& zMAT3::s_identity = *(zMAT3*)0x008D4628;
  zMAT4& zMAT4::s_identity = *(zMAT4*)0x008D45E8;
#endif

#ifdef __ZVIEW_H__VER3__
  zCList<zCInputCallback>& zCInputCallback::inputList = *(zCList<zCInputCallback>*)0x00AB6460;
  zCView*& zCView::stdoutput                          = *(zCView**)0x00AB646C;
  zCView*& zCView::modal                              = *(zCView**)0x00AB6470;
  int& zCView::showDebug                              = *(int*)0x00AB6474;
  float& zCView::s_fViewTimePerChar                   = *(float*)0x008BC868;
#endif

#ifdef __ZWORLD_H__VER3__
  zCWorld::zTWorldLoadMode& zCWorld::s_worldLoadMode       = *(zCWorld::zTWorldLoadMode*)0x009A435C;
  zCWorld::zTWorldSaveMode& zCWorld::s_worldSaveMode       = *(zCWorld::zTWorldSaveMode*)0x009A438C;
  zCWorld::zTWorldLoadMergeMode& zCWorld::s_worldMergeMode = *(zCWorld::zTWorldLoadMergeMode*)0x009A4364;
  int& zCWorld::s_bFadeOutFarVerts                         = *(int*)0x008A8AB8;
  int& zCWorld::s_bWaveAnisEnabled                         = *(int*)0x008A8ABC;
  int& zCWorld::s_bAlternateRenderOrder                    = *(int*)0x009A4424;
  int& zCWorld::s_bEnvMappingEnabled                       = *(int*)0x008A8AC4;
  int& zCWorld::s_bAmbientVobsEnabled                      = *(int*)0x008A8AC0;
  int& zCWorld::showTextureStats                           = *(int*)0x009A4420;
#endif

#ifdef __OLOG_MANAGER_H__VER3__
  char**& oCLogTopic::ms_strSections = *(char***)0x008AF6BC;
  char**& oCLogTopic::ms_strStati    = *(char***)0x008AF6C8;
#endif // __OLOG_MANAGER_H__VER3__

#ifdef __ZCOLLISION_OBJECT_MISC_H__VER3__
  zCCollisionObjectDef* zCCollisionObject::s_oCollObjClass          = (zCCollisionObjectDef*)0x008D82F4;
  zCCollisionObjectDef* zCCollObjectUndef::s_oCollObjClass          = (zCCollisionObjectDef*)0x008D8314;
  zCCollisionObjectDef* zCCollObjectPoint::s_oCollObjClass          = (zCCollisionObjectDef*)0x008D8320;
  zCCollisionObjectDef* zCCollObjectBoxPassThrough::s_oCollObjClass = (zCCollisionObjectDef*)0x008D832C;
  zCCollisionObjectDef* zCCollObjectComplex::s_oCollObjClass        = (zCCollisionObjectDef*)0x008D8338;
  zCCollisionObjectDef* zCCollObjectBoxBlocker::s_oCollObjClass     = (zCCollisionObjectDef*)0x008D8344;
  zCCollisionObjectDef* zCCollObjectLevelPolys::s_oCollObjClass     = (zCCollisionObjectDef*)0x008D8350;
  zCCollisionObjectDef* zCCollObjectCharacter::s_oCollObjClass      = (zCCollisionObjectDef*)0x008D835C;
  zCCollisionObjectDef* zCCollObjectProjectile::s_oCollObjClass     = (zCCollisionObjectDef*)0x008D8368;
#endif // __ZCOLLISION_OBJECT_MISC_H__VER3__

} // namespace Gothic_II_Addon