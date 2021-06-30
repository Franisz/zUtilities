#include "UnionAfx.h"

namespace Gothic_I_Addon {

#ifdef __OAI_HUMAN_H__VER1__
  zSTRING& oCAIHuman::Cam_Normal = *(zSTRING*)0x0091E828;
  zSTRING& oCAIHuman::Cam_Run    = *(zSTRING*)0x0091E788;
  zSTRING& oCAIHuman::Cam_Fight  = *(zSTRING*)0x0091E810;
#endif // __OAI_HUMAN_H__VER1__

#ifdef __OCOLLISION_OBJECT_MISC_CHAR_H__VER1__
  zCCollisionObjectDef& oCCollObjectCharacter::s_oCollObjClass = *(zCCollisionObjectDef*)0x00A22CA8;
#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER1__

#ifdef __ODOC_H__VER1__
  zCView*& oCDoc::posView = *(zCView**)0x00920B20;
#endif // __ODOC_H__VER1__

#ifdef __OFOCUS_H__VER1__
  oCNpcFocus*& oCNpcFocus::focus      = *(oCNpcFocus**)0x00920BC0;
  oCNpcFocus**& oCNpcFocus::focuslist = *(oCNpcFocus***)0x00920BA8;
#endif // __OFOCUS_H__VER1__

#ifdef __OINFO_H__VER1__
  int& oCInfoManager::size_checked = *(int*)0x00921624;
#endif // __OINFO_H__VER1__

#ifdef __OINVENTORY_H__VER1__
  zCList<oCItemContainer>& oCItemContainer::contList = *(zCList<oCItemContainer>*)0x00921820;
  int& oCItemContainer::gfx_loaded                   = *(int*)0x009218D4;
  zCGfx*& oCItemContainer::gfx_cat                   = *(zCGfx**)0x009218D8;
  zCGfx*& oCItemContainer::gfx_equip                 = *(zCGfx**)0x009218DC;
  zCGfx*& oCItemContainer::gfx_cursor                = *(zCGfx**)0x009218E0;
  zCGfx*& oCItemContainer::gfx_cursor_equip          = *(zCGfx**)0x009218E4;
  zCGfx**& oCItemContainer::gfx_arrow                = *(zCGfx***)0x009218E8;
  zCGfx**& oCNpcInventory::gfx_cats                  = *(zCGfx***)0x009218FC;
#endif // __OINVENTORY_H__VER1__

#ifdef __OITEM_REACT_H__VER1__
  int& oCTradeManager::size_checked = *(int*)0x00921B3C;
#endif // __OITEM_REACT_H__VER1__

#ifdef __OMUSIC_ZONE_H__VER1__
  long& oCZoneMusic::s_lastzonechange       = *(long*)0x0092675C;
  int& oCZoneMusic::s_zonetime              = *(int*)0x008996D4;
  int& oCZoneMusic::s_daytime               = *(int*)0x008996D8;
  oHEROSTATUS& oCZoneMusic::s_herostatus    = *(oHEROSTATUS*)0x00926760;
  oCZoneMusic*& oCZoneMusic::s_musiczone    = *(oCZoneMusic**)0x00926764;
  oCZoneMusic*& oCZoneMusic::s_oldmusiczone = *(oCZoneMusic**)0x00926768;
#endif // __OMUSIC_ZONE_H__VER1__

#ifdef __ONEWS_H__VER1__
  int& oCNews::news_counter = *(int*)0x0092258C;
#endif // __ONEWS_H__VER1__

#ifdef __ONPC_H__VER1__
  zSTRING*& oCNpc::FightAIInstances        = *(zSTRING**)0x00A225B8;
  oCNpc::oEBloodMode& oCNpc::modeBlood     = *(oCNpc::oEBloodMode*)0x0089E9E4;
  int& oCNpc::isEnabledDamageDebug         = *(int*)0x00A22514;
  oCStealContainer*& oCNpc::stealcontainer = *(oCStealContainer**)0x009232F8;
  int& oCNpc::s_bEnabledDialogCamStop      = *(int*)0x00923138;
  zMAT4& oCNpc::s_playerPositionMatrix     = *(zMAT4*)0x00923178;
  oCNpc*& oCNpc::player                    = *(oCNpc**)0x00923134;
  int& oCNpc::godmode                      = *(int*)0x0092311C;
  int& oCNpc::angle_near                   = *(int*)0x00893F90;
  int& oCNpc::angle_far_up                 = *(int*)0x00893F94;
  int& oCNpc::angle_far_side               = *(int*)0x00893F98;
  int& oCNpc::game_mode                    = *(int*)0x009232EC;
  oCNpc*& oCNpc::dontArchiveThisNpc        = *(oCNpc**)0x0092313C;
  int*& oCNpc::bodyStateList               = *(int**)0x00922A48;
  int& oCNpc::ai_disabled                  = *(int*)0x00923120;
  float& oCNpc::ai_messagesSkip            = *(float*)0x00923124;
  float& oCNpc::ai_messagesSkipTimer       = *(float*)0x00923128;
  float& oCNpc::ai_scriptStateSkip         = *(float*)0x0092312C;
  float& oCNpc::ai_scriptStateSkipTimer    = *(float*)0x00923130;
  int& oCNpc::ai_baseEnabled               = *(int*)0x00893F84;
  int& oCNpc::isEnabledTalkBox             = *(int*)0x00893F88;
#endif // __ONPC_H__VER1__

#ifdef __OTEXT_H__VER1__
  zCView*& oCText::output           = *(zCView**)0x0092414C;
  int& oCText::TXT_GUILD            = *(int*)0x00924150;
  int& oCText::TXT_ATTRIBUTE        = *(int*)0x00924154;
  int& oCText::TXT_FIGHT_TALENT     = *(int*)0x00924158;
  int& oCText::TXT_TALENT           = *(int*)0x0092415C;
  int& oCText::TXT_DAYTIME          = *(int*)0x00924160;
  int*& oCText::TXT_ATR             = *(int**)0x00924134;
  int& oCText::TXT_ATR_HP           = *(int*)0x00924164;
  int& oCText::TXT_SPELL            = *(int*)0x0092416C;
  int& oCText::TXT_ATTITUDE         = *(int*)0x00924168;
  int& oCText::TXT_PC_GREETING      = *(int*)0x00924170;
  int& oCText::TXT_PC_FIRST_PHRASE  = *(int*)0x00924174;
  int& oCText::TXT_PC_SECOND_PHRASE = *(int*)0x00924178;
  int& oCText::TXT_PC_TRADE_PHRASE  = *(int*)0x0092417C;
  int& oCText::TXT_NPC_LAST_PHRASE  = *(int*)0x00924180;
  int& oCText::TXT_PC_TRADE_THREAT  = *(int*)0x00924184;
  int& oCText::TXT_NPC_TRADE_THREAT = *(int*)0x00924188;
  int& oCText::TXT_PC_INFO_THREAT   = *(int*)0x0092418C;
  int& oCText::TXT_NPC_INFO_THREAT  = *(int*)0x00924190;
  int& oCText::TXT_NEWS_INTRO       = *(int*)0x00924198;
  int& oCText::TXT_NEWS_STOLE       = *(int*)0x0092419C;
  int& oCText::TXT_NEWS_STOLE_10    = *(int*)0x009241A0;
  int& oCText::TXT_NEWS_STOLE_30    = *(int*)0x009241A4;
  int& oCText::TXT_NEWS_STOLE_50    = *(int*)0x009241A8;
  int& oCText::TXT_NEWS_STOLE_70    = *(int*)0x009241AC;
  int& oCText::TXT_NEWS_STOLE_90    = *(int*)0x009241B0;
  int& oCText::TXT_NEWS_STOLE_100   = *(int*)0x009241B4;
  int& oCText::TXT_NEWS_ATTACKED    = *(int*)0x009241B8;
  int& oCText::TXT_NEWS_KILLED      = *(int*)0x009241BC;
  int& oCText::TXT_YNEWS_INTRO      = *(int*)0x009241C0;
  int& oCText::TXT_YNEWS_STOLE      = *(int*)0x009241C4;
  int& oCText::TXT_YNEWS_STOLE_10   = *(int*)0x009241C8;
  int& oCText::TXT_YNEWS_STOLE_30   = *(int*)0x009241CC;
  int& oCText::TXT_YNEWS_STOLE_50   = *(int*)0x009241D0;
  int& oCText::TXT_YNEWS_STOLE_70   = *(int*)0x009241D4;
  int& oCText::TXT_YNEWS_STOLE_90   = *(int*)0x009241D8;
  int& oCText::TXT_YNEWS_STOLE_100  = *(int*)0x009241DC;
  int& oCText::TXT_YNEWS_ATTACKED   = *(int*)0x009241E0;
  int& oCText::TXT_YNEWS_KILLED     = *(int*)0x009241E4;
  int& oCText::TXT_INTIMIDATION     = *(int*)0x00924194;
  int& oCText::TXT_INVCAT           = *(int*)0x009241E8;
  int& oCText::TXT_HELP             = *(int*)0x009241EC;
#endif // __OTEXT_H__VER1__

#ifdef __OVIS_FX_H__VER1__
  zCParser*& oCVisualFX::fxParser = *(zCParser**)0x008AF4EC;
  oCVisualFX*& oCVisualFX::actFX  = *(oCVisualFX**)0x008AF66C;
#endif // __OVIS_FX_H__VER1__

#ifdef __Z3D_H__VER1__
  zCCamera*& zCCamera::activeCam                         = *(zCCamera**)0x008B8EE4;
  zVEC3& zCCamera::activeCamPos                          = *(zVEC3*)0x008B8ED8;
  zCVertex*& zCPolygon::s_clipVertScene                  = *(zCVertex**)0x008E2318;
  int& zCPolygon::s_numClipVertScene                     = *(int*)0x008F2318;
  zCVertFeature*& zCPolygon::s_clipFeatScene             = *(zCVertFeature**)0x008C2240;
  int& zCPolygon::s_numClipFeatScene                     = *(int*)0x008E230C;
  int& zCPolygon::s_numVertListScene                     = *(int*)0x008FA3C8;
  int& zCPolygon::s_numFeatListScene                     = *(int*)0x008F231C;
  zCVertex**& zCPolygon::s_actClipVert                   = *(zCVertex***)0x008FA3CC;
  int& zCPolygon::s_actNumClipVert                       = *(int*)0x008FA3D0;
  zCMaterial*& zCPortal::portalDummyMaterial             = *(zCMaterial**)0x008B8D28;
#endif // __Z3D_H__VER1__

#ifdef __ZACCOUNT_H__VER1__
  int& zCAccount::s_actCounter = *(int*)0x00A22C2C;
#endif // __ZACCOUNT_H__VER1__

#ifdef __ZAI_CAMERA_H__VER1__
  short int& zCAICamera::s_iLookAroundSgn         = *(short int*)0x00879D64;
  zCArray<zCCSCamera*>& zCAICamera::dialogCamList = *(zCArray<zCCSCamera*>*)0x008AFA08;
  float& zCAICamera::lookingCamLastAzi            = *(float*)0x008AFB54;
  int& zCAICamera::lookingCamAziGoalReached       = *(int*)0x008AFB58;
  zCAICamera*& zCAICamera::current                = *(zCAICamera**)0x008AFB4C;
  int& zCAICamera::bCreated                       = *(int*)0x008AFB50;
  int& zCAICamera::bCamChanges                    = *(int*)0x00879D58;
#endif // __ZAI_CAMERA_H__VER1__

#ifdef __ZARCHIVER_H__VER1__
  zSTRING& zCArchiver::stringEOL = *(zSTRING*)0x008B5798;
#endif // __ZARCHIVER_H__VER1__

#ifdef __ZBSP_H__VER1__
  int& zCBspTree::s_showPortals                             = *(int*)0x008B8D2C;
  int& zCBspSector::s_sectorsRendered                       = *(int*)0x008B5894;
  int& zCBspSector::s_startPointOutdoor                     = *(int*)0x008B588C;
  int& zCBspSector::s_outdoorPortal                         = *(int*)0x008B589C;
  zCArray<zCBspSector*>& zCBspSector::s_activeSectorList    = *(zCArray<zCBspSector*>*)0x008B58A8;
  zCArray<zTBBox2D>& zCBspSector::s_activeOutdoorPortals    = *(zCArray<zTBBox2D>*)0x008B5860;
#endif // __ZBSP_H__VER1__

#ifdef __ZBVOLUME_H__VER1__
  zMAT4& zCOBBox3D::trafoB2ToThis = *(zMAT4*)0x008B8D90;
#endif // __ZBVOLUME_H__VER1__

#ifdef __ZCCS_CONTEXT_H__VER1__
  int& zCCSCutsceneContext::playDisabled = *(int*)0x008A296C;
#endif // __ZCCS_CONTEXT_H__VER1__

#ifdef __ZCOLLISION_DETECTOR_H__VER1__
  unsigned long& zCCollisionDetector::s_iCollisionDetectorFrameCtr = *(unsigned long*)0x008B9230;
  int& zCCollisionDetector::s_iCurrentCollReport                   = *(int*)0x008B9234;
  zCCollisionReport*& zCCollisionDetector::s_aoCollReportList      = *(zCCollisionReport**)0x008B8EF0;
#endif // __ZCOLLISION_DETECTOR_H__VER1__

#ifdef __ZCOLLISION_OBJECT_H__VER1__
  zCArray<zCCollisionObjectDef*>*& zCCollisionObjectDef::s_aoCollObjClassList = *(zCArray<zCCollisionObjectDef*>**)0x008B9250;
#endif // __ZCOLLISION_OBJECT_H__VER1__

#ifdef __ZCONSOLE_H__VER1__
  zCList<zCConsole>& zCConsole::active_consoles = *(zCList<zCConsole>*)0x009248B8;
  zCConsole*& zCConsole::cur_console            = *(zCConsole**)0x009248C0;
#endif // __ZCONSOLE_H__VER1__

#ifdef __ZCONVEX_COLLISION_H__VER1__
  zCConvexPrimitiveUnitSphere& zCConvexPrimitiveUnitSphere::s_unitSphere = *(zCConvexPrimitiveUnitSphere*)0x008B93D0;
#endif // __ZCONVEX_COLLISION_H__VER1__

#ifdef __ZCS_CAMERA_H__VER1__
  int& zCCSCamera::playing        = *(int*)0x008B22EC;
  int& zCCSCamera::draw           = *(int*)0x008B22F0;
  int& zCCSCamera::evaluateAvgFPS = *(int*)0x008B22F4;
#endif // __ZCS_CAMERA_H__VER1__

#ifdef __ZDISK_H__VER1__
  int& zFILE::s_numFilesOpen                         = *(int*)0x008A3EE4;
  int& zFILE::s_maxFilesOpen                         = *(int*)0x008A3EE8;
  zCCriticalSection*& zFILE::s_dirscanCiticalSection = *(zCCriticalSection**)0x008A3EE0;
  zFILE*& zFILE::s_virtPath                          = *(zFILE**)0x008A3EC4;
  zSTRING& zFILE::s_virtPathString                   = *(zSTRING*)0x008A3EC8;
  zSTRING& zFILE::s_physPathString                   = *(zSTRING*)0x008A3EB0;
  zSTRING& zFILE::s_rootDirString                    = *(zSTRING*)0x008A3E98;
  bool& zFILE::s_initialized                         = *(bool*)0x008A3EEC;
  zCBuffer**& zFILE::bufferList                      = *(zCBuffer***)0x008A3E60;
  int*& zFILE::bufferFlag                            = *(int**)0x008A3E78;
#endif // __ZDISK_H__VER1__

#ifdef __ZDISK__VDFS_H__VER1__
  bool& zFILE_VDFS::s_vdfsInitialized               = *(bool*)0x008A3EF8;
  zCCriticalSection*& zFILE_VDFS::s_criticalSection = *(zCCriticalSection**)0x008A3EFC;
#endif // __ZDISK__VDFS_H__VER1__

#ifdef __ZEIGEN_H__VER1__
  int& zCMgcEigenD::verbose                          = *(int*)0x008B94CC;
  unsigned int& zCMgcEigenD::error                   = *(unsigned int*)0x008B94D0;
  const unsigned int& zCMgcEigenD::invalid_size      = *(const unsigned int*)0x00816E1C;
  const unsigned int& zCMgcEigenD::allocation_failed = *(const unsigned int*)0x00816E20;
  const unsigned int& zCMgcEigenD::ql_exceeded       = *(const unsigned int*)0x00816E24;
  const char**& zCMgcEigenD::message                 = *(const char***)0x00883478;
#endif // __ZEIGEN_H__VER1__

#ifdef __ZEVENT_MAN_H__VER1__
  int& zCEventManager::disableEventManagers          = *(int*)0x0092494C;
  zCArray<zCEventManager*>& zCEventManager::activeEM = *(zCArray<zCEventManager*>*)0x00924940;
  int& zCEventManager::showMsgCommunication          = *(int*)0x00924950;
#endif // __ZEVENT_MAN_H__VER1__

#ifdef __ZFONTS_H__VER1__
  zCTextureConvert*& zCFont::texConv = *(zCTextureConvert**)0x0092495C;
#endif // __ZFONTS_H__VER1__

#ifdef __ZINPUT_H__VER1__
  zCArray<zSCtrlValue>& zCInput::values = *(zCArray<zSCtrlValue>*)0x008B2788;
#endif // __ZINPUT_H__VER1__

#ifdef __ZLENSFLARE_H__VER1__
  zCMesh*& zCLensFlareFX::s_lensFlareMesh = *(zCMesh**)0x008B957C;
  zCMesh*& zCLensFlareFX::s_coronaMesh    = *(zCMesh**)0x008B9580;
  zCMesh*& zCLensFlareFX::s_glowMesh      = *(zCMesh**)0x008B9584;
#endif // __ZLENSFLARE_H__VER1__

#ifdef __ZMATERIAL_H__VER1__
  unsigned long& zCTexAniCtrl::masterFrameCtr  = *(unsigned long*)0x008B9674;
  unsigned char& zCMaterial::s_matUsageDefault = *(unsigned char*)0x008843D0;
#endif // __ZMATERIAL_H__VER1__

#ifdef __ZMATH_TOOLS_H__VER1__
  zMAT4& zCPose::tmpMat = *(zMAT4*)0x008B2E88;
#endif // __ZMATH_TOOLS_H__VER1__

#ifdef __ZMEM_POOL_H__VER1__
  const char*& zCMemPoolBase::s_className = *(const char**)0x008B9680;
  const char*& zCMemPoolBase::s_fileName  = *(const char**)0x008B9684;
  int& zCMemPoolBase::s_line              = *(int*)0x008B9688;
  int& zCMemPoolBase::s_disablePools      = *(int*)0x00884588;
#endif // __ZMEM_POOL_H__VER1__

#ifdef __ZMENU_H__VER1__
  zCParser*& zCMenu::menuParser          = *(zCParser**)0x008B2F04;
  zCTimer*& zCMenu::timer                = *(zCTimer**)0x008B2F10;
  zCArraySort<zCMenu*>& zCMenu::menuList = *(zCArraySort<zCMenu*>*)0x008B2EE0;
  zCArray<zCMenu*>& zCMenu::activeList   = *(zCArray<zCMenu*>*)0x008B2ED0;
  zCSoundFX*& zCMenu::browseSnd          = *(zCSoundFX**)0x008B2F24;
  zCSoundFX*& zCMenu::selectSnd          = *(zCSoundFX**)0x008B2F28;
  zCSoundFX*& zCMenu::escSnd             = *(zCSoundFX**)0x008B2F2C;
  zCVob*& zCMenu::soundSourceVob         = *(zCVob**)0x008B2F30;
  zCWorld*& zCMenu::world                = *(zCWorld**)0x008B2F08;
  zCCamera*& zCMenu::camera              = *(zCCamera**)0x008B2F0C;
  int& zCMenu::inGameMenu                = *(int*)0x008B2F14;
#endif // __ZMENU_H__VER1__

#ifdef __ZMENU__ITEM_H__VER1__
  zCArraySort<zCMenuItem*>& zCMenuItem::itemList = *(zCArraySort<zCMenuItem*>*)0x008B2FA0;
  zCMenuItem*& zCMenuItem::tmp                   = *(zCMenuItem**)0x008B2FB0;
#endif // __ZMENU__ITEM_H__VER1__

#ifdef __ZMODEL_H__VER1__
  int& zCModelPrototype::s_ignoreAnis              = *(int*)0x008B9BDC;
  int& zCModelPrototype::s_autoConvertAnis         = *(int*)0x008852A0;
  int& zCModelPrototype::s_autoConvertMeshes       = *(int*)0x008B9BE0;
  zCModelPrototype*& zCModelPrototype::s_modelRoot = *(zCModelPrototype**)0x008B9BE4;
  int& zCModel::s_drawSkeleton                     = *(int*)0x008B9A64;
#endif // __ZMODEL_H__VER1__

#ifdef __ZMORPH_MESH_H__VER1__
  int& zCMorphMeshProto::autoConvertBinaryFile   = *(int*)0x008B9CCC;
  zCMorphMeshProto*& zCMorphMeshProto::morphRoot = *(zCMorphMeshProto**)0x008B9CC8;
#endif // __ZMORPH_MESH_H__VER1__

#ifdef __ZMUSIC_H__VER1__
  int& zCMusicSystem::s_musicSystemDisabled = *(int*)0x008B2FBC;
#endif // __ZMUSIC_H__VER1__

#ifdef __ZNET_HOST_H__VER1__
  unsigned char& zCNetHost::iter   = *(unsigned char*)0x008ADBFC;
  zCNetHost*& zCNetHost::localhost = *(zCNetHost**)0x008ADC00;
#endif // __ZNET_HOST_H__VER1__

#ifdef __ZPARSER_H__VER1__
  int& zCParser::enableParsing    = *(int*)0x0092620C;
  zCParser*& zCParser::cur_parser = *(zCParser**)0x00926214;
#endif // __ZPARSER_H__VER1__

#ifdef __ZPARSER__SYMBOL_H__VER1__
  zCPar_Symbol*& zCPar_Symbol::instance_sym        = *(zCPar_Symbol**)0x009263D8;
  void*& zCPar_Symbol::instance_adr                = *(void**)0x009263DC;
  zCPar_SymbolTable*& zCPar_SymbolTable::cur_table = *(zCPar_SymbolTable**)0x009263D4;
#endif // __ZPARSER__SYMBOL_H__VER1__

#ifdef __ZPARTICLE_H__VER1__
  zCParser*& zCParticleFX::s_pfxParser                               = *(zCParser**)0x008BA204;
  zCArraySort<zCParticleEmitter*>& zCParticleFX::s_emitterPresetList = *(zCArraySort<zCParticleEmitter*>*)0x008B9E18;
  zCParticleEmitter& zCParticleFX::s_emitterDummyDefault             = *(zCParticleEmitter*)0x008B9E28;
  int& zCParticleFX::s_globNumPart                                   = *(int*)0x008BA1F0;
  zTParticle*& zCParticleFX::s_globPartList                          = *(zTParticle**)0x008BA1F4;
  zTParticle*& zCParticleFX::s_globFreePart                          = *(zTParticle**)0x008BA1F8;
  zCMesh*& zCParticleFX::s_partMeshTri                               = *(zCMesh**)0x008BA1FC;
  zCMesh*& zCParticleFX::s_partMeshQuad                              = *(zCMesh**)0x008BA200;
  int& zCParticleFX::s_showDebugInfo                                 = *(int*)0x008BA208;
  zCParticleFX::zCStaticPfxList& zCParticleFX::s_pfxList             = *(zCParticleFX::zCStaticPfxList*)0x008BA1E0;
#endif // __ZPARTICLE_H__VER1__

#ifdef __ZPLAYER_GROUP_H__VER1__
  zCPlayerGroup& zCPlayerGroup::allPlayerGroup     = *(zCPlayerGroup*)0x008AE3D8;
  zCList<zCPlayerGroup>& zCPlayerGroup::group_list = *(zCList<zCPlayerGroup>*)0x008AE3B8;
#endif // __ZPLAYER_GROUP_H__VER1__

#ifdef __ZPLAYER_INFO_H__VER1__
  zCArray<int>& zCPlayerInfo::free_ids      = *(zCArray<int>*)0x008AE420;
  unsigned char& zCPlayerInfo::next_id      = *(unsigned char*)0x00876F88;
  zCPlayerInfo*& zCPlayerInfo::activePlayer = *(zCPlayerInfo**)0x008AE45C;
#endif // __ZPLAYER_INFO_H__VER1__

#ifdef __ZPROG_MESH_H__VER1__
  zTFrameCtr& zCProgMeshProto::s_frameCtr                   = *(zTFrameCtr*)0x008874B8;
  unsigned short int*& zCProgMeshProto::s_wedgeRemap        = *(unsigned short int**)0x008FD950;
  zVEC3*& zCProgMeshProto::s_posCacheList                   = *(zVEC3**)0x008FF958;
  zVEC3*& zCProgMeshProto::s_posNormalCSList                = *(zVEC3**)0x009059E8;
  zCArray<unsigned short>& zCProgMeshProto::s_workIndexList = *(zCArray<unsigned short>*)0x0090B9E8;
  int& zCProgMeshProto::s_subMeshRenderDir                  = *(int*)0x008874BC;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferColor    = *(zCVertexBufferDyn**)0x0090BA98;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferNormal   = *(zCVertexBufferDyn**)0x0090BA9C;
  float& zCProgMeshProto::s_lodParamStrengthOverride        = *(float*)0x008874C0;
  float& zCProgMeshProto::s_lodParamStrengthModifier        = *(float*)0x008874C4;
  int& zCProgMeshProto::s_markMeshMaterials                 = *(int*)0x0090BA94;
  int& zCProgMeshProto::s_autoSubdivEnabled                 = *(int*)0x0090BA8C;
  unsigned long& zCProgMeshProto::s_classCtorCtr            = *(unsigned long*)0x0090BA90;
#endif // __ZPROG_MESH_H__VER1__

#ifdef __ZRAY_CACHE_H__VER1__
  zCRayCacheElement*& zCRayCache::s_current = *(zCRayCacheElement**)0x0090BD00;
  zVEC3& zCRayCache::s_start                = *(zVEC3*)0x0090BB20;
  zVEC3& zCRayCache::s_stop                 = *(zVEC3*)0x0090BB30;
  zCRayCache*& zCRayCache::s_anchor         = *(zCRayCache**)0x0090BCFC;
#endif // __ZRAY_CACHE_H__VER1__

#ifdef __ZRENDER_MANAGER_H__VER1__
  zCShader*& zCRenderManager::s_shaderList                        = *(zCShader**)0x0090EE38;
  zCShaderStage*& zCRenderManager::s_shaderStageList              = *(zCShaderStage**)0x0090BE30;
  int& zCRenderManager::s_currentShader                           = *(int*)0x009147FC;
  int& zCRenderManager::s_currentShaderStage                      = *(int*)0x00914800;
  int& zCRenderManager::s_useRendererTNL                          = *(int*)0x00887B18;
  int& zCRenderManager::s_detailTexturesEnabled                   = *(int*)0x009147F8;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex1       = *(zCVertexBufferDyn2**)0x00914804;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2       = *(zCVertexBufferDyn2**)0x00914808;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2Normal = *(zCVertexBufferDyn2**)0x0091480C;
#endif // __ZRENDER_MANAGER_H__VER1__

#ifdef __ZSKY_H__VER1__
  zCSkyControler*& zCSkyControler::s_activeSkyControler = *(zCSkyControler**)0x00914A80;
  int& zCSkyControler::s_skyEffectsEnabled              = *(int*)0x00887EDC;
#endif // __ZSKY_H__VER1__

#ifdef __ZSND_MSS_H__VER1__
  zCArraySort<zCActiveSnd*>& zCActiveSnd::activeSndList = *(zCArraySort<zCActiveSnd*>*)0x008B3260;
  unsigned long& zCActiveSnd::lastHandle                = *(unsigned long*)0x008B38B4;
  int& zCActiveSnd::maxChannels                         = *(int*)0x0087D438;
  int& zCActiveSnd::autoUpdate3D                        = *(int*)0x008B38B8;
  zCArray<zCActiveSnd*>& zCActiveSnd::preAllocedSndList = *(zCArray<zCActiveSnd*>*)0x008B3870;
  zCActiveSnd*& zCActiveSnd::nextFreeSnd                = *(zCActiveSnd**)0x008B38B0;
  zCDrvProperties_MSS& zCSndSys_MSS::prefs              = *(zCDrvProperties_MSS*)0x008B33D0;
#endif // __ZSND_MSS_H__VER1__

#ifdef __ZSOUND_MAN_H__VER1__
  zCSoundManager::zTScriptSoundData& zCSoundManager::scriptSoundData = *(zCSoundManager::zTScriptSoundData*)0x00914D20;
  zSTRING& zCSoundManager::mediumIDList                              = *(zSTRING*)0x00914D60;
  zSTRING& zCSoundManager::prefixProto                               = *(zSTRING*)0x00914D78;
#endif // __ZSOUND_MAN_H__VER1__

#ifdef __ZTEXTURE_H__VER1__
  zSTRING& zCTexture::zTEX_DEFAULT_TEXTURE_FILE           = *(zSTRING*)0x00914FA8;
  zTTexScaleSize& zCTexture::s_texScaleSize               = *(zTTexScaleSize*)0x0088896C;
  zTTexScaleBPP& zCTexture::s_texScaleBPP                 = *(zTTexScaleBPP*)0x00888970;
  unsigned long& zCTexture::s_texSupportedFormats         = *(unsigned long*)0x009150A4;
  char& zCTexture::s_useDefaultTex                        = *(char*)0x00888968;
  char& zCTexture::s_globalLoadTextures                   = *(char*)0x00888969;
  unsigned long& zCTexture::s_texMaxPixelSize             = *(unsigned long*)0x009150A8;
  zSTRING*& zCTexture::s_texDesiredBPPSuffix              = *(zSTRING**)0x00915050;
  zTRnd_TextureFormat*& zCTexture::s_texDesiredBPPDefault = *(zTRnd_TextureFormat**)0x0088897C;
  float& zCTexture::s_texRefRAM                           = *(float*)0x00888974;
  zCTexture::zTTexFileDesiredBPP& zCTexture::s_texRefBPP  = *(zCTexture::zTTexFileDesiredBPP*)0x00888978;
#endif // __ZTEXTURE_H__VER1__

#ifdef __ZVERTEX_BUFFER_H__VER1__
  unsigned long& zCVertexBuffer::s_classCtorCtr = *(unsigned long*)0x0091D188;
#endif // __ZVERTEX_BUFFER_H__VER1__

#ifdef __ZVIEW_BASE_H__VER1__
  const unsigned short& zCViewBase::ViewVirtualWidth  = *(const unsigned short*)0x0082273C;
  const unsigned short& zCViewBase::ViewVirtualHeight = *(const unsigned short*)0x0082273E;
#endif // __ZVIEW_BASE_H__VER1__

#ifdef __ZVISUAL_H__VER1__
  zCArray<zCVisual*>& zCVisual::s_visualClassList = *(zCArray<zCVisual*>*)0x0091D1B0;
  zCMesh*& zCDecal::decalMesh1Sided               = *(zCMesh**)0x008B94C0;
  zCMesh*& zCDecal::decalMesh2Sided               = *(zCMesh**)0x008B94C4;
  int& zCMesh::s_autoConvertMeshes                = *(int*)0x008B9744;
  int& zCMesh::s_numMeshes                        = *(int*)0x008B973C;
  zCMesh*& zCMesh::s_meshRoot                     = *(zCMesh**)0x008B9740;
#endif // __ZVISUAL_H__VER1__

#ifdef __ZVOB_H__VER1__
  int& zCVob::s_ignoreVisuals                             = *(int*)0x0091D4D8;
  zCMesh*& zCVob::s_shadowMesh                            = *(zCMesh**)0x0091D4D0;
  unsigned long& zCVob::s_nextFreeID                      = *(unsigned long*)0x0091D4D4;
  int& zCVob::s_vobAlreadyInMovement                      = *(int*)0x0091D4CC;
  int& zCVob::s_renderVobs                                = *(int*)0x008893BC;
  int& zCVob::s_showHelperVisuals                         = *(int*)0x0091D4DC;
  zCCollisionDetector*& zCVob::s_poCollisionDetector      = *(zCCollisionDetector**)0x0091D4E0;
  zCArray<zCVobLightPreset*>& zCVobLight::lightPresetList = *(zCArray<zCVobLightPreset*>*)0x0091D568;
  int& zCVobLight::renderLightVisuals                     = *(int*)0x0091D574;
  int& zCVobLevelCompo::unarcIgnoreVisuals                = *(int*)0x0091D4E4;
#endif // __ZVOB_H__VER1__

#ifdef __ZWORLD_H__VER1__
  zCWorld::zTWorldLoadMode& zCWorld::s_worldLoadMode       = *(zCWorld::zTWorldLoadMode*)0x0091E050;
  zCWorld::zTWorldSaveMode& zCWorld::s_worldSaveMode       = *(zCWorld::zTWorldSaveMode*)0x0091E078;
  zCWorld::zTWorldLoadMergeMode& zCWorld::s_worldMergeMode = *(zCWorld::zTWorldLoadMergeMode*)0x0091E058;
#endif // __ZWORLD_H__VER1__

#ifdef __ZALGEBRA_H__VER1__
  zMAT3& zMAT3::s_identity = *(zMAT3*)0x008B5518;
  zMAT4& zMAT4::s_identity = *(zMAT4*)0x008B54D8;
#endif // __ZALGEBRA_H__VER1__

#ifdef __ZVIEW_H__VER1__
  zCList<zCInputCallback>& zCInputCallback::inputList = *(zCList<zCInputCallback>*)0x00926408;
  zCView*& zCView::stdoutput                          = *(zCView**)0x00926418;
  zCView*& zCView::modal                              = *(zCView**)0x0092641C;
  int& zCView::showDebug                              = *(int*)0x00926438;
#endif // __ZVIEW_H__VER1__

#ifdef __ZRND_D3D_H__VER1__
  zCVertexBufferDyn*& zD3D_alphaPoly::vertexbufferdyn                           = *(zCVertexBufferDyn**)0x00971FC4;
  zCVertexBuffer*& zD3D_alphaPoly::vertexbuffer                                 = *(zCVertexBuffer**)0x00971FC8;
  int& zD3D_alphaPoly::locked                                                   = *(int*)0x00971FCC;
  unsigned long& zD3D_alphaPoly::startvertex                                    = *(unsigned long*)0x00971FD0;
  unsigned long& zD3D_alphaPoly::actvertex                                      = *(unsigned long*)0x00971FD4;
  int& zD3D_alphaPoly::numberofvertices                                         = *(int*)0x00971FD8;
  int& zD3D_alphaPoly::actnov                                                   = *(int*)0x00971FDC;
  struct ID3DXContext*& zCRnd_D3D::xd3d_pd3dx                                   = *(struct ID3DXContext**)0x00971FA8;
  IDirectDraw7*& zCRnd_D3D::xd3d_pdd7                                           = *(IDirectDraw7**)0x00971FAC;
  IDirect3D7*& zCRnd_D3D::xd3d_pd3d7                                            = *(IDirect3D7**)0x00971FB0;
  IDirect3DDevice7*& zCRnd_D3D::xd3d_pd3dDevice7                                = *(IDirect3DDevice7**)0x00971FB4;
  unsigned long& zCRnd_D3D::xd3d_actFrameNumber                                 = *(unsigned long*)0x00971FC0;
  int& zCRnd_D3D::xd3d_dd7inuse                                                 = *(int*)0x00971FB8;
  int& zCRnd_D3D::xd3d_palsupp                                                  = *(int*)0x00971FBC;
  zCSurfaceCache_D3D::zD3D_SlotHeader**& zCSurfaceCache_D3D::xsc_listofsurfaces = *(zCSurfaceCache_D3D::zD3D_SlotHeader***)0x009485A8;
  int& zCSurfaceCache_D3D::xsc_listposition                                     = *(int*)0x00971FE0;
  zCArray<zCVertexBuffer_D3D*>& zCVertexBuffer_D3D::xvb_vertexbufferList        = *(zCArray<zCVertexBuffer_D3D*>*)0x00972000;
#endif // __ZRND_D3D_H__VER1__

#ifdef __ZZONE_H__VER1__
  zCBBox3DSorterBase*& zCBBox3DSorterBase::s_currentSorter = *(zCBBox3DSorterBase**)0x0091E364;
  int& zCBBox3DSorterBase::s_currentDimension              = *(int*)0x0091E3D4;
  int& zCZoneMusic::s_autochange                           = *(int*)0x0088CC7C;
  int& zCZoneMusic::s_canruleautochange                    = *(int*)0x0091E604;
#endif // __ZZONE_H__VER1__

#ifdef __ZSPARSE_ARRAY_H__VER1__
  int& zCCacheBase::s_currentFrame    = *(int*)0x00914D9C;
  zCCacheBase*& zCCacheBase::s_anchor = *(zCCacheBase**)0x00914DA0;
  zCCacheBase*& zCCacheBase::s_run    = *(zCCacheBase**)0x00914DA4;
#endif // __ZSPARSE_ARRAY_H__VER1__

#ifdef __ZOBJECT_H__VER1__
  zCArraySort<zCClassDef*>*& zCClassDef::classDefList = *(zCArraySort<zCClassDef*>**)0x008B9DF0;
  zCClassDef*& zCClassDef::classDefSearchDummy        = *(zCClassDef**)0x008B9DF8;
  int& zCClassDef::startupFinished                    = *(int*)0x008B9DF4;
#endif // __ZOBJECT_H__VER1__

#ifdef __ZGRAFIX_H__VER1__
  zCGfx*& zCGfx::Gfx_List = *(zCGfx**)0x00925010;
  int& zCGfx::gfxcount    = *(int*)0x00925014;
#endif // __ZGRAFIX_H__VER1__

#ifdef __OLOG_MANAGER_H__VER1__
  char**& oCLogTopic::ms_strSections = *(char***)0x0089DAC0;
  char**& oCLogTopic::ms_strStati    = *(char***)0x0089DACC;
#endif // __OLOG_MANAGER_H__VER1__

#ifdef __ZCOLLISION_OBJECT_MISC_H__VER1__
  zCCollisionObjectDef* zCCollisionObject::s_oCollObjClass          = (zCCollisionObjectDef*)0x008B9240;
  zCCollisionObjectDef* zCCollObjectUndef::s_oCollObjClass          = (zCCollisionObjectDef*)0x008B92B8;
  zCCollisionObjectDef* zCCollObjectPoint::s_oCollObjClass          = (zCCollisionObjectDef*)0x008B92A8;
  zCCollisionObjectDef* zCCollObjectBoxPassThrough::s_oCollObjClass = (zCCollisionObjectDef*)0x008B9268;
  zCCollisionObjectDef* zCCollObjectComplex::s_oCollObjClass        = (zCCollisionObjectDef*)0x008B92C8;
  zCCollisionObjectDef* zCCollObjectBoxBlocker::s_oCollObjClass     = (zCCollisionObjectDef*)0x008B9278;
  zCCollisionObjectDef* zCCollObjectLevelPolys::s_oCollObjClass     = (zCCollisionObjectDef*)0x008B9298;
  zCCollisionObjectDef* zCCollObjectCharacter::s_oCollObjClass      = (zCCollisionObjectDef*)0x008B92D8;
  zCCollisionObjectDef* zCCollObjectProjectile::s_oCollObjClass     = (zCCollisionObjectDef*)0x008B9288;
#endif // __ZCOLLISION_OBJECT_MISC_H__VER1__


} // namespace Gothic_I_Addon