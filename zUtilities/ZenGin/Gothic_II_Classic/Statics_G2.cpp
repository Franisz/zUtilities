#include "UnionAfx.h"

namespace Gothic_II_Classic {
  
#ifdef __OAI_HUMAN_H__VER2__
  zSTRING& oCAIHuman::Cam_Normal = *(zSTRING*)0x0097E3C8;
  zSTRING& oCAIHuman::Cam_Run    = *(zSTRING*)0x0097E330;
  zSTRING& oCAIHuman::Cam_Fight  = *(zSTRING*)0x0097E3B4;
#endif // __OAI_HUMAN_H__VER2__

#ifdef __OCOLLISION_OBJECT_MISC_CHAR_H__VER2__
  zCCollisionObjectDef& oCCollObjectCharacter::s_oCollObjClass = *(zCCollisionObjectDef*)0x00A824D0;
#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER2__

#ifdef __ODOC_H__VER2__
  zCView*& oCDoc::posView = *(zCView**)0x0098112C;
#endif // __ODOC_H__VER2__

#ifdef __OFOCUS_H__VER2__
  oCNpcFocus*& oCNpcFocus::focus             = *(oCNpcFocus**)0x00981290;
  oCNpcFocus**& oCNpcFocus::focuslist        = *(oCNpcFocus***)0x00981250;
  int& oCNpcFocus::s_iHightlightMeleeFocus   = *(int*)0x00981294;
  int& oCNpcFocus::s_bHighlightInteractFocus = *(int*)0x0089E450;
  oCVisualFX*& oCNpcFocus::highLightFX       = *(oCVisualFX**)0x00981298;
  int& oCNpcFocus::isHighLighted             = *(int*)0x0098129C;
#endif // __OFOCUS_H__VER2__

#ifdef __OGAME_H__VER2__
  int& oCGame::s_bUseOldControls    = *(int*)0x0089E520;
  float& oCGame::s_fUseSpeechReverb = *(float*)0x0089E524;
  int& oCGame::s_bUseOnlineHelp     = *(int*)0x0089E528;
  int& oCGame::s_bUsePotionKeys     = *(int*)0x0089E52C;
  int& oCGame::s_bUseQuickSave      = *(int*)0x0089E530;
#endif // __OGAME_H__VER2__

#ifdef __OINFO_H__VER2__
  int& oCInfoManager::size_checked = *(int*)0x009819B0;
#endif // __OINFO_H__VER2__

#ifdef __OINVENTORY_H__VER2__
  zCList<oCItemContainer>& oCItemContainer::contList = *(zCList<oCItemContainer>*)0x00981B40;
  int& oCItemContainer::gfx_loaded                   = *(int*)0x00981C3C;
  zCGfx*& oCItemContainer::gfx_cat                   = *(zCGfx**)0x00981C40;
  zCGfx*& oCItemContainer::gfx_equip                 = *(zCGfx**)0x00981C44;
  zCGfx*& oCItemContainer::gfx_cursor                = *(zCGfx**)0x00981C48;
  zCGfx*& oCItemContainer::gfx_cursor_equip          = *(zCGfx**)0x00981C4C;
  zCGfx**& oCItemContainer::gfx_arrow                = *(zCGfx***)0x00981C50;
  zCGfx*& oCNpcInventory::gfx_title                  = *(zCGfx**)0x00981C70;
#endif // __OINVENTORY_H__VER2__

#ifdef __OITEM_H__VER2__
  float& oCItem::s_fGlobalItemZBiasScale = *(float*)0x00981D3C;
#endif // __OITEM_H__VER2__

#ifdef __OITEM_REACT_H__VER2__
  int& oCTradeManager::size_checked = *(int*)0x00981E24;
#endif // __OITEM_REACT_H__VER2__

#ifdef __OMUSIC_ZONE_H__VER2__
  long& oCZoneMusic::s_lastzonechange       = *(long*)0x009862F4;
  int& oCZoneMusic::s_zonetime              = *(int*)0x008A8EE0;
  int& oCZoneMusic::s_daytime               = *(int*)0x008A8EE4;
  oHEROSTATUS& oCZoneMusic::s_herostatus    = *(oHEROSTATUS*)0x009862F8;
  oCZoneMusic*& oCZoneMusic::s_musiczone    = *(oCZoneMusic**)0x009862FC;
  oCZoneMusic*& oCZoneMusic::s_oldmusiczone = *(oCZoneMusic**)0x00986300;
#endif // __OMUSIC_ZONE_H__VER2__

#ifdef __ONEWS_H__VER2__
  int& oCNews::news_counter = *(int*)0x009826DC;
#endif // __ONEWS_H__VER2__

#ifdef __ONPC_H__VER2__
  zSTRING*& oCNpc::FightAIInstances        = *(zSTRING**)0x00A81D40;
  oCNpc::oEBloodMode& oCNpc::modeBlood     = *(oCNpc::oEBloodMode*)0x008ADDF8;
  int& oCNpc::isEnabledDamageDebug         = *(int*)0x00A81CB8;
  oCStealContainer*& oCNpc::stealcontainer = *(oCStealContainer**)0x0098332C;
  int& oCNpc::s_bEnabledDialogCamStop      = *(int*)0x009831E0;
  int& oCNpc::s_bTargetLocked              = *(int*)0x009831D8;
  zMAT4& oCNpc::s_playerPositionMatrix     = *(zMAT4*)0x00983228;
  oCNpc*& oCNpc::player                    = *(oCNpc**)0x009831DC;
  int& oCNpc::godmode                      = *(int*)0x009831B8;
  int& oCNpc::angle_near                   = *(int*)0x008A42F8;
  int& oCNpc::angle_far_up                 = *(int*)0x008A42FC;
  int& oCNpc::angle_far_side               = *(int*)0x008A4300;
  int& oCNpc::game_mode                    = *(int*)0x00983320;
  oCNpc*& oCNpc::dontArchiveThisNpc        = *(oCNpc**)0x009831E4;
  int*& oCNpc::bodyStateList               = *(int**)0x00982B38;
  int& oCNpc::ai_disabled                  = *(int*)0x009831BC;
  float& oCNpc::ai_messagesSkip            = *(float*)0x009831C0;
  float& oCNpc::ai_messagesSkipTimer       = *(float*)0x009831C4;
  float& oCNpc::ai_scriptStateSkip         = *(float*)0x009831C8;
  float& oCNpc::ai_scriptStateSkipTimer    = *(float*)0x009831CC;
  int& oCNpc::ai_baseEnabled               = *(int*)0x008A42E8;
  int& oCNpc::isEnabledTalkBox             = *(int*)0x008A42EC;
  int& oCNpc::isEnabledTalkBoxPlayer       = *(int*)0x008A42F0;
  int& oCNpc::isEnabledTalkBoxAmbient      = *(int*)0x009831D0;
  int& oCNpc::isEnabledTalkBoxNoise        = *(int*)0x009831D4;
#endif // __ONPC_H__VER2__

#ifdef __OTEXT_H__VER2__
  zCView*& oCText::output           = *(zCView**)0x00983E90;
  int& oCText::TXT_GUILD            = *(int*)0x00983E94;
  int& oCText::TXT_ATTRIBUTE        = *(int*)0x00983E98;
  int& oCText::TXT_FIGHT_TALENT     = *(int*)0x00983E9C;
  int& oCText::TXT_TALENT           = *(int*)0x00983EA0;
  int& oCText::TXT_DAYTIME          = *(int*)0x00983EA4;
  int*& oCText::TXT_ATR             = *(int**)0x00983E78;
  int& oCText::TXT_ATR_HP           = *(int*)0x00983EA8;
  int& oCText::TXT_SPELL            = *(int*)0x00983EB0;
  int& oCText::TXT_ATTITUDE         = *(int*)0x00983EAC;
  int& oCText::TXT_PC_GREETING      = *(int*)0x00983EB4;
  int& oCText::TXT_PC_FIRST_PHRASE  = *(int*)0x00983EB8;
  int& oCText::TXT_PC_SECOND_PHRASE = *(int*)0x00983EBC;
  int& oCText::TXT_PC_TRADE_PHRASE  = *(int*)0x00983EC0;
  int& oCText::TXT_NPC_LAST_PHRASE  = *(int*)0x00983EC4;
  int& oCText::TXT_PC_TRADE_THREAT  = *(int*)0x00983EC8;
  int& oCText::TXT_NPC_TRADE_THREAT = *(int*)0x00983ECC;
  int& oCText::TXT_PC_INFO_THREAT   = *(int*)0x00983ED0;
  int& oCText::TXT_NPC_INFO_THREAT  = *(int*)0x00983ED4;
  int& oCText::TXT_NEWS_INTRO       = *(int*)0x00983EDC;
  int& oCText::TXT_NEWS_STOLE       = *(int*)0x00983EE0;
  int& oCText::TXT_NEWS_STOLE_10    = *(int*)0x00983EE4;
  int& oCText::TXT_NEWS_STOLE_30    = *(int*)0x00983EE8;
  int& oCText::TXT_NEWS_STOLE_50    = *(int*)0x00983EEC;
  int& oCText::TXT_NEWS_STOLE_70    = *(int*)0x00983EF0;
  int& oCText::TXT_NEWS_STOLE_90    = *(int*)0x00983EF4;
  int& oCText::TXT_NEWS_STOLE_100   = *(int*)0x00983EF8;
  int& oCText::TXT_NEWS_ATTACKED    = *(int*)0x00983EFC;
  int& oCText::TXT_NEWS_KILLED      = *(int*)0x00983F00;
  int& oCText::TXT_YNEWS_INTRO      = *(int*)0x00983F04;
  int& oCText::TXT_YNEWS_STOLE      = *(int*)0x00983F08;
  int& oCText::TXT_YNEWS_STOLE_10   = *(int*)0x00983F0C;
  int& oCText::TXT_YNEWS_STOLE_30   = *(int*)0x00983F10;
  int& oCText::TXT_YNEWS_STOLE_50   = *(int*)0x00983F14;
  int& oCText::TXT_YNEWS_STOLE_70   = *(int*)0x00983F18;
  int& oCText::TXT_YNEWS_STOLE_90   = *(int*)0x00983F1C;
  int& oCText::TXT_YNEWS_STOLE_100  = *(int*)0x00983F20;
  int& oCText::TXT_YNEWS_ATTACKED   = *(int*)0x00983F24;
  int& oCText::TXT_YNEWS_KILLED     = *(int*)0x00983F28;
  int& oCText::TXT_INTIMIDATION     = *(int*)0x00983ED8;
  int& oCText::TXT_INVCAT           = *(int*)0x00983F2C;
  int& oCText::TXT_HELP             = *(int*)0x00983F30;
#endif // __OTEXT_H__VER2__

#ifdef __OVIS_FX_H__VER2__
  zCParser*& oCVisualFX::fxParser = *(zCParser**)0x008C008C;
  oCVisualFX*& oCVisualFX::actFX  = *(oCVisualFX**)0x008C018C;
#endif // __OVIS_FX_H__VER2__

#ifdef __Z3D_H__VER2__
  zCCamera*& zCCamera::activeCam                                                     = *(zCCamera**)0x008C9914;
  zVEC3& zCCamera::activeCamPos                                                      = *(zVEC3*)0x008C9908;
  zCVertex*& zCPolygon::s_clipVertScene                                              = *(zCVertex**)0x00912C68;
  int& zCPolygon::s_numClipVertScene                                                 = *(int*)0x0093AC68;
  zCVertFeature*& zCPolygon::s_clipFeatScene                                         = *(zCVertFeature**)0x008DABA0;
  int& zCPolygon::s_numClipFeatScene                                                 = *(int*)0x00912C64;
  int& zCPolygon::s_numVertListScene                                                 = *(int*)0x0094AD28;
  int& zCPolygon::s_numFeatListScene                                                 = *(int*)0x0093AC7C;
  zCVertex**& zCPolygon::s_actClipVert                                               = *(zCVertex***)0x0094AE00;
  int& zCPolygon::s_actNumClipVert                                                   = *(int*)0x0094AE04;
  zCArraySort<zCPolygon::zSVertexSavedValues>& zCPolygon::morphedVerticesList_Height = *(zCArraySort<zCPolygon::zSVertexSavedValues>*)0x0094AD48;
  zCArraySort<zCPolygon::zSVertexSavedValues>& zCPolygon::morphedVerticesList_Wall   = *(zCArraySort<zCPolygon::zSVertexSavedValues>*)0x0094AD2C;
  zCArraySort<zCPolygon::zSFeatureSavedValues>& zCPolygon::morphedFeatureList        = *(zCArraySort<zCPolygon::zSFeatureSavedValues>*)0x0093AC6C;
  zCArray<zCPolygon::zSPolySavedValues>& zCPolygon::morphedPolysSavedValuesList      = *(zCArray<zCPolygon::zSPolySavedValues>*)0x0094AD3C;
  zCMaterial*& zCPortal::portalDummyMaterial                                         = *(zCMaterial**)0x008C9828;
#endif // __Z3D_H__VER2__

#ifdef __ZACCOUNT_H__VER2__
  int& zCAccount::s_actCounter = *(int*)0x00A82474;
#endif // __ZACCOUNT_H__VER2__

#ifdef __ZAI_CAMERA_H__VER2__
  short int& zCAICamera::s_iLookAroundSgn         = *(short int*)0x00889A34;
  zCArray<zCCSCamera*>& zCAICamera::dialogCamList = *(zCArray<zCCSCamera*>*)0x008C035C;
  float& zCAICamera::lookingCamLastAzi            = *(float*)0x008C0460;
  int& zCAICamera::lookingCamAziGoalReached       = *(int*)0x008C0464;
  zCAICamera*& zCAICamera::current                = *(zCAICamera**)0x008C0458;
  int& zCAICamera::bCreated                       = *(int*)0x008C045C;
  int& zCAICamera::bCamChanges                    = *(int*)0x00889A28;
#endif // __ZAI_CAMERA_H__VER2__

#ifdef __ZALGEBRA_H__VER2__
  zMAT3& zMAT3::s_identity = *(zMAT3*)0x008C5FF0;
  zMAT4& zMAT4::s_identity = *(zMAT4*)0x008C5FB0;
#endif // __ZALGEBRA_H__VER2__

#ifdef __ZARCHIVER_H__VER2__
  zSTRING& zCArchiver::stringEOL = *(zSTRING*)0x008C6260;
#endif // __ZARCHIVER_H__VER2__

#ifdef __ZBSP_H__VER2__
  int& zCBspTree::s_showPortals                             = *(int*)0x008C982C;
  int& zCBspTree::s_renderAllPortals                        = *(int*)0x008C9830;
  int& zCBspSector::s_sectorsRendered                       = *(int*)0x008C6384;
  int& zCBspSector::s_startPointOutdoor                     = *(int*)0x008C6354;
  int& zCBspSector::s_outdoorPortal                         = *(int*)0x008C6390;
  zCArray<zCBspSector*>& zCBspSector::s_activeSectorList    = *(zCArray<zCBspSector*>*)0x008C6394;
  zCArray<zTBBox2D>& zCBspSector::s_activeOutdoorPortals    = *(zCArray<zTBBox2D>*)0x008C631C;
#endif // __ZBSP_H__VER2__

#ifdef __ZBVOLUME_H__VER2__
  zMAT4& zCOBBox3D::trafoB2ToThis = *(zMAT4*)0x008C9888;
#endif // __ZBVOLUME_H__VER2__

#ifdef __ZCCS_CONTEXT_H__VER2__
  int& zCCSCutsceneContext::playDisabled = *(int*)0x008B3BCC;
#endif // __ZCCS_CONTEXT_H__VER2__

#ifdef __ZCOLLISION_DETECTOR_H__VER2__
  unsigned long& zCCollisionDetector::s_iCollisionDetectorFrameCtr = *(unsigned long*)0x008C9C68;
  int& zCCollisionDetector::s_iCurrentCollReport                   = *(int*)0x008C9C6C;
  zCCollisionReport*& zCCollisionDetector::s_aoCollReportList      = *(zCCollisionReport**)0x008C9928;
#endif // __ZCOLLISION_DETECTOR_H__VER2__

#ifdef __ZCOLLISION_OBJECT_H__VER2__
  zCArray<zCCollisionObjectDef*>*& zCCollisionObjectDef::s_aoCollObjClassList = *(zCArray<zCCollisionObjectDef*>**)0x008C9C84;
#endif // __ZCOLLISION_OBJECT_H__VER2__

#ifdef __ZCONSOLE_H__VER2__
  zCList<zCConsole>& zCConsole::active_consoles = *(zCList<zCConsole>*)0x00984484;
  zCConsole*& zCConsole::cur_console            = *(zCConsole**)0x0098448C;
#endif // __ZCONSOLE_H__VER2__

#ifdef __ZCONVEX_COLLISION_H__VER2__
  zCConvexPrimitiveUnitSphere& zCConvexPrimitiveUnitSphere::s_unitSphere = *(zCConvexPrimitiveUnitSphere*)0x008C9DC8;
#endif // __ZCONVEX_COLLISION_H__VER2__

#ifdef __ZCS_CAMERA_H__VER2__
  int& zCCSCamera::playing        = *(int*)0x008C2B58;
  int& zCCSCamera::draw           = *(int*)0x008C2B5C;
  int& zCCSCamera::evaluateAvgFPS = *(int*)0x008C2B60;
#endif // __ZCS_CAMERA_H__VER2__

#ifdef __ZDISK_H__VER2__
  int& zFILE::s_numFilesOpen                         = *(int*)0x008B4EF0;
  int& zFILE::s_maxFilesOpen                         = *(int*)0x008B4EF4;
  zCCriticalSection*& zFILE::s_dirscanCiticalSection = *(zCCriticalSection**)0x008B4EEC;
  zFILE*& zFILE::s_virtPath                          = *(zFILE**)0x008B4ED0;
  zSTRING& zFILE::s_virtPathString                   = *(zSTRING*)0x008B4ED4;
  zSTRING& zFILE::s_physPathString                   = *(zSTRING*)0x008B4EBC;
  zSTRING& zFILE::s_rootDirString                    = *(zSTRING*)0x008B4EA8;
  bool& zFILE::s_initialized                         = *(bool*)0x008B4EF8;
  zCBuffer**& zFILE::bufferList                      = *(zCBuffer***)0x008B4E74;
  int*& zFILE::bufferFlag                            = *(int**)0x008B4E8C;
#endif // __ZDISK_H__VER2__

#ifdef __ZDISK__VDFS_H__VER2__
  bool& zFILE_VDFS::s_vdfsInitialized               = *(bool*)0x008B4F04;
  zCCriticalSection*& zFILE_VDFS::s_criticalSection = *(zCCriticalSection**)0x008B4F08;
#endif // __ZDISK__VDFS_H__VER2__

#ifdef __ZEIGEN_H__VER2__
  int& zCMgcEigenD::verbose                          = *(int*)0x008C9EC4;
  unsigned int& zCMgcEigenD::error                   = *(unsigned int*)0x008C9EC8;
  const unsigned int& zCMgcEigenD::invalid_size      = *(const unsigned int*)0x008240A4;
  const unsigned int& zCMgcEigenD::allocation_failed = *(const unsigned int*)0x008240A8;
  const unsigned int& zCMgcEigenD::ql_exceeded       = *(const unsigned int*)0x008240AC;
  const char**& zCMgcEigenD::message                 = *(const char***)0x008931C8;
#endif // __ZEIGEN_H__VER2__

#ifdef __ZEVENT_MAN_H__VER2__
  int& zCEventManager::disableEventManagers          = *(int*)0x00984510;
  zCArray<zCEventManager*>& zCEventManager::activeEM = *(zCArray<zCEventManager*>*)0x00984504;
  int& zCEventManager::showMsgCommunication          = *(int*)0x00984514;
#endif // __ZEVENT_MAN_H__VER2__

#ifdef __ZFONTS_H__VER2__
  zCTextureConvert*& zCFont::texConv = *(zCTextureConvert**)0x00984520;
#endif // __ZFONTS_H__VER2__

#ifdef __ZGRAFIX_H__VER2__
  zCGfx*& zCGfx::Gfx_List = *(zCGfx**)0x00984BD8;
  int& zCGfx::gfxcount    = *(int*)0x00984BDC;
#endif // __ZGRAFIX_H__VER2__

#ifdef __ZINPUT_H__VER2__
  zCArray<zSCtrlValue>& zCInput::values = *(zCArray<zSCtrlValue>*)0x008C2FE8;
#endif // __ZINPUT_H__VER2__

#ifdef __ZLENSFLARE_H__VER2__
  zCMesh*& zCLensFlareFX::s_lensFlareMesh = *(zCMesh**)0x008C9FE4;
  zCMesh*& zCLensFlareFX::s_coronaMesh    = *(zCMesh**)0x008C9FE8;
  zCMesh*& zCLensFlareFX::s_glowMesh      = *(zCMesh**)0x008C9FEC;
#endif // __ZLENSFLARE_H__VER2__

#ifdef __ZMATERIAL_H__VER2__
  unsigned long& zCTexAniCtrl::masterFrameCtr  = *(unsigned long*)0x008CA0F4;
  unsigned char& zCMaterial::s_matUsageDefault = *(unsigned char*)0x00894064;
#endif // __ZMATERIAL_H__VER2__

#ifdef __ZMATH_TOOLS_H__VER2__
  zMAT4& zCPose::tmpMat = *(zMAT4*)0x008C3790;
#endif // __ZMATH_TOOLS_H__VER2__

#ifdef __ZMEM_POOL_H__VER2__
  const char*& zCMemPoolBase::s_className = *(const char**)0x008CA100;
  const char*& zCMemPoolBase::s_fileName  = *(const char**)0x008CA104;
  int& zCMemPoolBase::s_line              = *(int*)0x008CA108;
  int& zCMemPoolBase::s_disablePools      = *(int*)0x00894360;
#endif // __ZMEM_POOL_H__VER2__

#ifdef __ZMENU_H__VER2__
  zCParser*& zCMenu::menuParser          = *(zCParser**)0x008C3808;
  zCTimer*& zCMenu::timer                = *(zCTimer**)0x008C3814;
  zCArraySort<zCMenu*>& zCMenu::menuList = *(zCArraySort<zCMenu*>*)0x008C37E4;
  zCArray<zCMenu*>& zCMenu::activeList   = *(zCArray<zCMenu*>*)0x008C37D8;
  zCSoundFX*& zCMenu::browseSnd          = *(zCSoundFX**)0x008C3828;
  zCSoundFX*& zCMenu::selectSnd          = *(zCSoundFX**)0x008C382C;
  zCSoundFX*& zCMenu::escSnd             = *(zCSoundFX**)0x008C3830;
  zCVob*& zCMenu::soundSourceVob         = *(zCVob**)0x008C3834;
  zCWorld*& zCMenu::world                = *(zCWorld**)0x008C380C;
  zCCamera*& zCMenu::camera              = *(zCCamera**)0x008C3810;
  int& zCMenu::inGameMenu                = *(int*)0x008C3818;
#endif // __ZMENU_H__VER2__

#ifdef __ZMENU__ITEM_H__VER2__
  zCArraySort<zCMenuItem*>& zCMenuItem::itemList = *(zCArraySort<zCMenuItem*>*)0x008C389C;
  zCMenuItem*& zCMenuItem::tmp                   = *(zCMenuItem**)0x008C38AC;
#endif // __ZMENU__ITEM_H__VER2__

#ifdef __ZMODEL_H__VER2__
  float& zTMdl_AniSample::samplePosScaler          = *(float*)0x008D8AAC;
  float& zTMdl_AniSample::samplePosRangeMin        = *(float*)0x008D8BAC;
  int& zCModelPrototype::s_ignoreAnis              = *(int*)0x008CA518;
  int& zCModelPrototype::s_autoConvertAnis         = *(int*)0x00895010;
  int& zCModelPrototype::s_autoConvertMeshes       = *(int*)0x008CA51C;
  zCModelPrototype*& zCModelPrototype::s_modelRoot = *(zCModelPrototype**)0x008CA520;
  int& zCModel::s_drawSkeleton                     = *(int*)0x008CA3B0;
  int& zCModel::s_bSmoothRootNode                  = *(int*)0x00894B64;
#endif // __ZMODEL_H__VER2__

#ifdef __ZMORPH_MESH_H__VER2__
  int& zCMorphMeshProto::autoConvertBinaryFile   = *(int*)0x008CA5F8;
  zCMorphMeshProto*& zCMorphMeshProto::morphRoot = *(zCMorphMeshProto**)0x008CA5F4;
#endif // __ZMORPH_MESH_H__VER2__

#ifdef __ZMUSIC_H__VER2__
  int& zCMusicSystem::s_musicSystemDisabled = *(int*)0x008C38B8;
#endif // __ZMUSIC_H__VER2__

#ifdef __ZNET_HOST_H__VER2__
  unsigned char& zCNetHost::iter   = *(unsigned char*)0x008BEBE8;
  zCNetHost*& zCNetHost::localhost = *(zCNetHost**)0x008BEBEC;
#endif // __ZNET_HOST_H__VER2__

#ifdef __ZOBJECT_H__VER2__
  zCArraySort<zCClassDef*>*& zCClassDef::classDefList = *(zCArraySort<zCClassDef*>**)0x008CA710;
  zCClassDef*& zCClassDef::classDefSearchDummy        = *(zCClassDef**)0x008CA718;
  int& zCClassDef::startupFinished                    = *(int*)0x008CA714;
#endif // __ZOBJECT_H__VER2__

#ifdef __ZPARSER_H__VER2__
  int& zCParser::enableParsing    = *(int*)0x00985DCC;
  zCParser*& zCParser::cur_parser = *(zCParser**)0x00985DD4;
#endif // __ZPARSER_H__VER2__

#ifdef __ZPARSER__SYMBOL_H__VER2__
  zCPar_Symbol*& zCPar_Symbol::instance_sym        = *(zCPar_Symbol**)0x00985F78;
  void*& zCPar_Symbol::instance_adr                = *(void**)0x00985F7C;
  zCPar_SymbolTable*& zCPar_SymbolTable::cur_table = *(zCPar_SymbolTable**)0x00985F70;
#endif // __ZPARSER__SYMBOL_H__VER2__

#ifdef __ZPARTICLE_H__VER2__
  zCParser*& zCParticleFX::s_pfxParser                               = *(zCParser**)0x008CAB60;
  zCArraySort<zCParticleEmitter*>& zCParticleFX::s_emitterPresetList = *(zCArraySort<zCParticleEmitter*>*)0x008CA738;
  zCParticleEmitter& zCParticleFX::s_emitterDummyDefault             = *(zCParticleEmitter*)0x008CA750;
  int& zCParticleFX::s_bAmbientPFXEnabled                            = *(int*)0x00896C60;
  int& zCParticleFX::s_globNumPart                                   = *(int*)0x008CAB4C;
  zTParticle*& zCParticleFX::s_globPartList                          = *(zTParticle**)0x008CAB50;
  zTParticle*& zCParticleFX::s_globFreePart                          = *(zTParticle**)0x008CAB54;
  zCMesh*& zCParticleFX::s_partMeshTri                               = *(zCMesh**)0x008CAB58;
  zCMesh*& zCParticleFX::s_partMeshQuad                              = *(zCMesh**)0x008CAB5C;
  int& zCParticleFX::s_showDebugInfo                                 = *(int*)0x008CAB64;
  zCParticleFX::zCStaticPfxList& zCParticleFX::s_pfxList             = *(zCParticleFX::zCStaticPfxList*)0x008CAB40;
#endif // __ZPARTICLE_H__VER2__

#ifdef __ZPLAYER_GROUP_H__VER2__
  zCPlayerGroup& zCPlayerGroup::allPlayerGroup     = *(zCPlayerGroup*)0x008BF3A0;
  zCList<zCPlayerGroup>& zCPlayerGroup::group_list = *(zCList<zCPlayerGroup>*)0x008BF384;
#endif // __ZPLAYER_GROUP_H__VER2__

#ifdef __ZPLAYER_INFO_H__VER2__
  zCArray<int>& zCPlayerInfo::free_ids      = *(zCArray<int>*)0x008BF3E0;
  unsigned char& zCPlayerInfo::next_id      = *(unsigned char*)0x00886F94;
  zCPlayerInfo*& zCPlayerInfo::activePlayer = *(zCPlayerInfo**)0x008BF414;
#endif // __ZPLAYER_INFO_H__VER2__

#ifdef __ZPROG_MESH_H__VER2__
  zTFrameCtr& zCProgMeshProto::s_frameCtr                   = *(zTFrameCtr*)0x0089715C;
  unsigned short int*& zCProgMeshProto::s_wedgeRemap        = *(unsigned short int**)0x0094E340;
  zVEC3*& zCProgMeshProto::s_posCacheList                   = *(zVEC3**)0x00950378;
  zVEC3*& zCProgMeshProto::s_posNormalCSList                = *(zVEC3**)0x009563E8;
  zCArray<unsigned short>& zCProgMeshProto::s_workIndexList = *(zCArray<unsigned short>*)0x0095C3E8;
  int& zCProgMeshProto::s_subMeshRenderDir                  = *(int*)0x00897160;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferColor    = *(zCVertexBufferDyn**)0x0095C4C4;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferNormal   = *(zCVertexBufferDyn**)0x0095C4C8;
  float& zCProgMeshProto::s_lodParamStrengthOverride        = *(float*)0x00897164;
  float& zCProgMeshProto::s_lodParamStrengthModifier        = *(float*)0x00897168;
  int& zCProgMeshProto::s_markMeshMaterials                 = *(int*)0x0095C4C0;
  int& zCProgMeshProto::s_autoSubdivEnabled                 = *(int*)0x0095C4B0;
  unsigned long& zCProgMeshProto::s_classCtorCtr            = *(unsigned long*)0x0095C4B4;
#endif // __ZPROG_MESH_H__VER2__

#ifdef __ZRAY_CACHE_H__VER2__
  zCRayCacheElement*& zCRayCache::s_current = *(zCRayCacheElement**)0x0095C72C;
  zVEC3& zCRayCache::s_start                = *(zVEC3*)0x0095C54C;
  zVEC3& zCRayCache::s_stop                 = *(zVEC3*)0x0095C558;
  zCRayCache*& zCRayCache::s_anchor         = *(zCRayCache**)0x0095C728;
#endif // __ZRAY_CACHE_H__VER2__

#ifdef __ZRENDER_MANAGER_H__VER2__
  zCShader*& zCRenderManager::s_shaderList                        = *(zCShader**)0x0095F838;
  zCShaderStage*& zCRenderManager::s_shaderStageList              = *(zCShaderStage**)0x0095C838;
  int& zCRenderManager::s_currentShader                           = *(int*)0x00974338;
  int& zCRenderManager::s_currentShaderStage                      = *(int*)0x0097433C;
  int& zCRenderManager::s_useRendererTNL                          = *(int*)0x00897838;
  int& zCRenderManager::s_detailTexturesEnabled                   = *(int*)0x0089783C;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex1       = *(zCVertexBufferDyn2**)0x00974340;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2       = *(zCVertexBufferDyn2**)0x00974344;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2Normal = *(zCVertexBufferDyn2**)0x00974348;
#endif // __ZRENDER_MANAGER_H__VER2__

#ifdef __ZRND_D3D_H__VER2__
  zCVertexBufferDyn*& zD3D_alphaPoly::vertexbufferdyn                           = *(zCVertexBufferDyn**)0x009D1B5C;
  zCVertexBuffer*& zD3D_alphaPoly::vertexbuffer                                 = *(zCVertexBuffer**)0x009D1B60;
  int& zD3D_alphaPoly::locked                                                   = *(int*)0x009D1B64;
  unsigned long& zD3D_alphaPoly::startvertex                                    = *(unsigned long*)0x009D1B68;
  unsigned long& zD3D_alphaPoly::actvertex                                      = *(unsigned long*)0x009D1B6C;
  int& zD3D_alphaPoly::numberofvertices                                         = *(int*)0x009D1B70;
  int& zD3D_alphaPoly::actnov                                                   = *(int*)0x009D1B74;
  struct ID3DXContext*& zCRnd_D3D::xd3d_pd3dx                                   = *(struct ID3DXContext**)0x009D1B40;
  IDirectDraw7*& zCRnd_D3D::xd3d_pdd7                                           = *(IDirectDraw7**)0x009D1B44;
  IDirect3D7*& zCRnd_D3D::xd3d_pd3d7                                            = *(IDirect3D7**)0x009D1B48;
  IDirect3DDevice7*& zCRnd_D3D::xd3d_pd3dDevice7                                = *(IDirect3DDevice7**)0x009D1B4C;
  unsigned long& zCRnd_D3D::xd3d_actFrameNumber                                 = *(unsigned long*)0x009D1B58;
  int& zCRnd_D3D::xd3d_dd7inuse                                                 = *(int*)0x009D1B50;
  int& zCRnd_D3D::xd3d_palsupp                                                  = *(int*)0x009D1B54;
  zCSurfaceCache_D3D::zD3D_SlotHeader**& zCSurfaceCache_D3D::xsc_listofsurfaces = *(zCSurfaceCache_D3D::zD3D_SlotHeader***)0x009A8140;
  int& zCSurfaceCache_D3D::xsc_listposition                                     = *(int*)0x009D1B78;
  zCArray<zCVertexBuffer_D3D*>& zCVertexBuffer_D3D::xvb_vertexbufferList        = *(zCArray<zCVertexBuffer_D3D*>*)0x009D1B94;
#endif // __ZRND_D3D_H__VER2__

#ifdef __ZSKY_H__VER2__
  zCSkyControler*& zCSkyControler::s_activeSkyControler = *(zCSkyControler**)0x0097453C;
  int& zCSkyControler::s_skyEffectsEnabled              = *(int*)0x00897BF8;
#endif // __ZSKY_H__VER2__

#ifdef __ZSND_MSS_H__VER2__
  zCArraySort<zCActiveSnd*>& zCActiveSnd::activeSndList = *(zCArraySort<zCActiveSnd*>*)0x008C3B54;
  unsigned long& zCActiveSnd::lastHandle                = *(unsigned long*)0x008C4420;
  int& zCActiveSnd::maxChannels                         = *(int*)0x0088D140;
  int& zCActiveSnd::autoUpdate3D                        = *(int*)0x008C4424;
  zCArray<zCActiveSnd*>& zCActiveSnd::preAllocedSndList = *(zCArray<zCActiveSnd*>*)0x008C43E8;
  zCActiveSnd*& zCActiveSnd::nextFreeSnd                = *(zCActiveSnd**)0x008C441C;
  zCDrvProperties_MSS& zCSndSys_MSS::prefs              = *(zCDrvProperties_MSS*)0x008C3C98;
#endif // __ZSND_MSS_H__VER2__

#ifdef __ZSOUND_MAN_H__VER2__
  zCSoundManager::zTScriptSoundData& zCSoundManager::scriptSoundData = *(zCSoundManager::zTScriptSoundData*)0x009748F4;
  zSTRING& zCSoundManager::mediumIDList                              = *(zSTRING*)0x00974930;
  zSTRING& zCSoundManager::prefixProto                               = *(zSTRING*)0x00974944;
#endif // __ZSOUND_MAN_H__VER2__

#ifdef __ZSPARSE_ARRAY_H__VER2__
  int& zCCacheBase::s_currentFrame    = *(int*)0x00974968;
  zCCacheBase*& zCCacheBase::s_anchor = *(zCCacheBase**)0x0097496C;
  zCCacheBase*& zCCacheBase::s_run    = *(zCCacheBase**)0x00974970;
#endif // __ZSPARSE_ARRAY_H__VER2__

#ifdef __ZTEXTURE_H__VER2__
  zSTRING& zCTexture::zTEX_DEFAULT_TEXTURE_FILE           = *(zSTRING*)0x00974B68;
  zTTexScaleSize& zCTexture::s_texScaleSize               = *(zTTexScaleSize*)0x008988DC;
  zTTexScaleBPP& zCTexture::s_texScaleBPP                 = *(zTTexScaleBPP*)0x008988E0;
  unsigned long& zCTexture::s_texSupportedFormats         = *(unsigned long*)0x00974C60;
  char& zCTexture::s_useDefaultTex                        = *(char*)0x008988D8;
  char& zCTexture::s_globalLoadTextures                   = *(char*)0x008988D9;
  unsigned long& zCTexture::s_texMaxPixelSize             = *(unsigned long*)0x00974C64;
  zSTRING*& zCTexture::s_texDesiredBPPSuffix              = *(zSTRING**)0x00974C10;
  zTRnd_TextureFormat*& zCTexture::s_texDesiredBPPDefault = *(zTRnd_TextureFormat**)0x008988EC;
  float& zCTexture::s_texRefRAM                           = *(float*)0x008988E4;
  zCTexture::zTTexFileDesiredBPP& zCTexture::s_texRefBPP  = *(zCTexture::zTTexFileDesiredBPP*)0x008988E8;
#endif // __ZTEXTURE_H__VER2__

#ifdef __ZTOOLS_H__VER2__
  unsigned long& zCTimer::s_forcedMaxFrameTime = *(unsigned long*)0x00974CAC;
#endif // __ZTOOLS_H__VER2__

#ifdef __ZVERTEX_BUFFER_H__VER2__
  unsigned long& zCVertexBuffer::s_classCtorCtr = *(unsigned long*)0x0097CD50;
#endif // __ZVERTEX_BUFFER_H__VER2__

#ifdef __ZVIEW_H__VER2__
  zCList<zCInputCallback>& zCInputCallback::inputList = *(zCList<zCInputCallback>*)0x00985FA8;
  zCView*& zCView::stdoutput                          = *(zCView**)0x00985FB4;
  zCView*& zCView::modal                              = *(zCView**)0x00985FB8;
  int& zCView::showDebug                              = *(int*)0x00985FBC;
  float& zCView::s_fViewTimePerChar                   = *(float*)0x008A8A1C;
#endif // __ZVIEW_H__VER2__

#ifdef __ZVIEW_BASE_H__VER2__
  const unsigned short& zCViewBase::ViewVirtualWidth  = *(const unsigned short*)0x00830128;
  const unsigned short& zCViewBase::ViewVirtualHeight = *(const unsigned short*)0x0083012A;
#endif // __ZVIEW_BASE_H__VER2__

#ifdef __ZVISUAL_H__VER2__
  zCArray<zCVisual*>& zCVisual::s_visualClassList = *(zCArray<zCVisual*>*)0x0097CD74;
  zCMesh*& zCDecal::decalMesh1Sided               = *(zCMesh**)0x008C9EB8;
  zCMesh*& zCDecal::decalMesh2Sided               = *(zCMesh**)0x008C9EBC;
  int& zCMesh::s_autoConvertMeshes                = *(int*)0x008CA1E8;
  int& zCMesh::s_usesVertexCache                  = *(int*)0x008CA1EC;
  int& zCMesh::s_numMeshes                        = *(int*)0x008CA1E0;
  zCMesh*& zCMesh::s_meshRoot                     = *(zCMesh**)0x008CA1E4;
  zCArraySort<zCVertex*>& zCMesh::s_vertexCache   = *(zCArraySort<zCVertex*>*)0x008CA138;
#endif // __ZVISUAL_H__VER2__

#ifdef __ZVOB_H__VER2__
  int& zCVob::s_ignoreVisuals                             = *(int*)0x0097D098;
  zCMesh*& zCVob::s_shadowMesh                            = *(zCMesh**)0x0097D090;
  unsigned long& zCVob::s_nextFreeID                      = *(unsigned long*)0x0097D094;
  int& zCVob::s_vobAlreadyInMovement                      = *(int*)0x0097D08C;
  int& zCVob::s_renderVobs                                = *(int*)0x00899474;
  int& zCVob::s_showHelperVisuals                         = *(int*)0x0097D09C;
  int& zCVob::s_enableAnimations                          = *(int*)0x00899478;
  zCCollisionDetector*& zCVob::s_poCollisionDetector      = *(zCCollisionDetector**)0x0097D0A0;
  zCArray<zCVobLightPreset*>& zCVobLight::lightPresetList = *(zCArray<zCVobLightPreset*>*)0x0097D124;
  int& zCVobLight::renderLightVisuals                     = *(int*)0x0097D130;
  int& zCVobLevelCompo::unarcIgnoreVisuals                = *(int*)0x0097D0A4;
#endif // __ZVOB_H__VER2__

#ifdef __ZWORLD_H__VER2__
  zCWorld::zTWorldLoadMode& zCWorld::s_worldLoadMode       = *(zCWorld::zTWorldLoadMode*)0x0097DC14;
  zCWorld::zTWorldSaveMode& zCWorld::s_worldSaveMode       = *(zCWorld::zTWorldSaveMode*)0x0097DC44;
  zCWorld::zTWorldLoadMergeMode& zCWorld::s_worldMergeMode = *(zCWorld::zTWorldLoadMergeMode*)0x0097DC1C;
  int& zCWorld::s_bFadeOutFarVerts                         = *(int*)0x0089A8F8;
  int& zCWorld::s_bWaveAnisEnabled                         = *(int*)0x0089A8FC;
  int& zCWorld::s_bAlternateRenderOrder                    = *(int*)0x0097DCD8;
  int& zCWorld::s_bEnvMappingEnabled                       = *(int*)0x0089A904;
  int& zCWorld::s_bAmbientVobsEnabled                      = *(int*)0x0089A900;
#endif // __ZWORLD_H__VER2__

#ifdef __ZZONE_H__VER2__
  zCBBox3DSorterBase*& zCBBox3DSorterBase::s_currentSorter = *(zCBBox3DSorterBase**)0x0097DF34;
  int& zCBBox3DSorterBase::s_currentDimension              = *(int*)0x0097DFA4;
  int& zCZoneMusic::s_autochange                           = *(int*)0x0089CDA0;
  int& zCZoneMusic::s_canruleautochange                    = *(int*)0x0097E1D4;
#endif // __ZZONE_H__VER2__

#ifdef __OLOG_MANAGER_H__VER2__
  char**& oCLogTopic::ms_strSections = *(char***)0x008AD100;
  char**& oCLogTopic::ms_strStati    = *(char***)0x008AD10C;
#endif // __OLOG_MANAGER_H__VER2__

#ifdef __ZCOLLISION_OBJECT_MISC_H__VER2__
  zCCollisionObjectDef* zCCollisionObject::s_oCollObjClass          = (zCCollisionObjectDef*)0x008C9C74;
  zCCollisionObjectDef* zCCollObjectUndef::s_oCollObjClass          = (zCCollisionObjectDef*)0x008C9C94;
  zCCollisionObjectDef* zCCollObjectPoint::s_oCollObjClass          = (zCCollisionObjectDef*)0x008C9CA0;
  zCCollisionObjectDef* zCCollObjectBoxPassThrough::s_oCollObjClass = (zCCollisionObjectDef*)0x008C9CAC;
  zCCollisionObjectDef* zCCollObjectComplex::s_oCollObjClass        = (zCCollisionObjectDef*)0x008C9CB8;
  zCCollisionObjectDef* zCCollObjectBoxBlocker::s_oCollObjClass     = (zCCollisionObjectDef*)0x008C9CC4;
  zCCollisionObjectDef* zCCollObjectLevelPolys::s_oCollObjClass     = (zCCollisionObjectDef*)0x008C9CD0;
  zCCollisionObjectDef* zCCollObjectCharacter::s_oCollObjClass      = (zCCollisionObjectDef*)0x008C9CDC;
  zCCollisionObjectDef* zCCollObjectProjectile::s_oCollObjClass     = (zCCollisionObjectDef*)0x008C9CE8;
#endif // __ZCOLLISION_OBJECT_MISC_H__VER2__

} // namespace Gothic_II_Classic