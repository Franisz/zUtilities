#include "UnionAfx.h"

namespace Gothic_I_Classic {

#ifdef __OAI_HUMAN_H__VER0__
  zSTRING& oCAIHuman::Cam_Normal = *(zSTRING*)0x008D8890;
  zSTRING& oCAIHuman::Cam_Run    = *(zSTRING*)0x008D87FC;
  zSTRING& oCAIHuman::Cam_Fight  = *(zSTRING*)0x008D887C;
#endif // __OAI_HUMAN_H__VER0__

#ifdef __OCOLLISION_OBJECT_MISC_CHAR_H__VER0__
  zCCollisionObjectDef& oCCollObjectCharacter::s_oCollObjClass = *(zCCollisionObjectDef*)0x009D9D00;
#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER0__

#ifdef __ODOC_H__VER0__
  zCView*& oCDoc::posView = *(zCView**)0x008DA5AC;
#endif // __ODOC_H__VER0__

#ifdef __OFOCUS_H__VER0__
  oCNpcFocus*& oCNpcFocus::focus      = *(oCNpcFocus**)0x008DA648;
  oCNpcFocus**& oCNpcFocus::focuslist = *(oCNpcFocus***)0x008DA630;
#endif // __OFOCUS_H__VER0__

#ifdef __OINFO_H__VER0__
  int& oCInfoManager::size_checked = *(int*)0x008DA8A0;
#endif // __OINFO_H__VER0__

#ifdef __OINVENTORY_H__VER0__
  zCList<oCItemContainer>& oCItemContainer::contList = *(zCList<oCItemContainer>*)0x008DA9A0;
  int& oCItemContainer::gfx_loaded                   = *(int*)0x008DAA04;
  zCGfx*& oCItemContainer::gfx_cat                   = *(zCGfx**)0x008DAA08;
  zCGfx*& oCItemContainer::gfx_equip                 = *(zCGfx**)0x008DAA0C;
  zCGfx*& oCItemContainer::gfx_cursor                = *(zCGfx**)0x008DAA10;
  zCGfx*& oCItemContainer::gfx_cursor_equip          = *(zCGfx**)0x008DAA14;
  zCGfx**& oCItemContainer::gfx_arrow                = *(zCGfx***)0x008DAA18;
  zCGfx**& oCNpcInventory::gfx_cats                  = *(zCGfx***)0x008DAA2C;
#endif // __OINVENTORY_H__VER0__

#ifdef __OITEM_REACT_H__VER0__
  int& oCTradeManager::size_checked = *(int*)0x008DAB18;
#endif // __OITEM_REACT_H__VER0__

#ifdef __OMUSIC_ZONE_H__VER0__
  long& oCZoneMusic::s_lastzonechange       = *(long*)0x008DE504;
  int& oCZoneMusic::s_zonetime              = *(int*)0x00853330;
  int& oCZoneMusic::s_daytime               = *(int*)0x00853334;
  oHEROSTATUS& oCZoneMusic::s_herostatus    = *(oHEROSTATUS*)0x008DE508;
  oCZoneMusic*& oCZoneMusic::s_musiczone    = *(oCZoneMusic**)0x008DE50C;
  oCZoneMusic*& oCZoneMusic::s_oldmusiczone = *(oCZoneMusic**)0x008DE510;
#endif // __OMUSIC_ZONE_H__VER0__

#ifdef __ONEWS_H__VER0__
  int& oCNews::news_counter = *(int*)0x008DB180;
#endif // __ONEWS_H__VER0__

#ifdef __ONPC_H__VER0__
  zSTRING*& oCNpc::FightAIInstances        = *(zSTRING**)0x009D9898;
  oCNpc::oEBloodMode& oCNpc::modeBlood     = *(oCNpc::oEBloodMode*)0x0085862C;
  int& oCNpc::isEnabledDamageDebug         = *(int*)0x009D987C;
  oCStealContainer*& oCNpc::stealcontainer = *(oCStealContainer**)0x008DBC30;
  int& oCNpc::s_bEnabledDialogCamStop      = *(int*)0x008DBBB4;
  zMAT4& oCNpc::s_playerPositionMatrix     = *(zMAT4*)0x008DBBE0;
  oCNpc*& oCNpc::player                    = *(oCNpc**)0x008DBBB0;
  int& oCNpc::godmode                      = *(int*)0x008DBB98;
  int& oCNpc::angle_near                   = *(int*)0x0084DE44;
  int& oCNpc::angle_far_up                 = *(int*)0x0084DE48;
  int& oCNpc::angle_far_side               = *(int*)0x0084DE4C;
  int& oCNpc::game_mode                    = *(int*)0x008DBC24;
  oCNpc*& oCNpc::dontArchiveThisNpc        = *(oCNpc**)0x008DBBB8;
  int*& oCNpc::bodyStateList               = *(int**)0x008DB550;
  int& oCNpc::ai_disabled                  = *(int*)0x008DBB9C;
  float& oCNpc::ai_messagesSkip            = *(float*)0x008DBBA0;
  float& oCNpc::ai_messagesSkipTimer       = *(float*)0x008DBBA4;
  float& oCNpc::ai_scriptStateSkip         = *(float*)0x008DBBA8;
  float& oCNpc::ai_scriptStateSkipTimer    = *(float*)0x008DBBAC;
  int& oCNpc::ai_baseEnabled               = *(int*)0x0084DE38;
  int& oCNpc::isEnabledTalkBox             = *(int*)0x0084DE3C;
#endif // __ONPC_H__VER0__

#ifdef __OTEXT_H__VER0__
  zCView*& oCText::output           = *(zCView**)0x008DC2D8;
  int& oCText::TXT_GUILD            = *(int*)0x008DC2DC;
  int& oCText::TXT_ATTRIBUTE        = *(int*)0x008DC2E0;
  int& oCText::TXT_FIGHT_TALENT     = *(int*)0x008DC2E4;
  int& oCText::TXT_TALENT           = *(int*)0x008DC2E8;
  int& oCText::TXT_DAYTIME          = *(int*)0x008DC2EC;
  int*& oCText::TXT_ATR             = *(int**)0x008DC2C0;
  int& oCText::TXT_ATR_HP           = *(int*)0x008DC2F0;
  int& oCText::TXT_SPELL            = *(int*)0x008DC2F8;
  int& oCText::TXT_ATTITUDE         = *(int*)0x008DC2F4;
  int& oCText::TXT_PC_GREETING      = *(int*)0x008DC2FC;
  int& oCText::TXT_PC_FIRST_PHRASE  = *(int*)0x008DC300;
  int& oCText::TXT_PC_SECOND_PHRASE = *(int*)0x008DC304;
  int& oCText::TXT_PC_TRADE_PHRASE  = *(int*)0x008DC308;
  int& oCText::TXT_NPC_LAST_PHRASE  = *(int*)0x008DC30C;
  int& oCText::TXT_PC_TRADE_THREAT  = *(int*)0x008DC310;
  int& oCText::TXT_NPC_TRADE_THREAT = *(int*)0x008DC314;
  int& oCText::TXT_PC_INFO_THREAT   = *(int*)0x008DC318;
  int& oCText::TXT_NPC_INFO_THREAT  = *(int*)0x008DC31C;
  int& oCText::TXT_NEWS_INTRO       = *(int*)0x008DC324;
  int& oCText::TXT_NEWS_STOLE       = *(int*)0x008DC328;
  int& oCText::TXT_NEWS_STOLE_10    = *(int*)0x008DC32C;
  int& oCText::TXT_NEWS_STOLE_30    = *(int*)0x008DC330;
  int& oCText::TXT_NEWS_STOLE_50    = *(int*)0x008DC334;
  int& oCText::TXT_NEWS_STOLE_70    = *(int*)0x008DC338;
  int& oCText::TXT_NEWS_STOLE_90    = *(int*)0x008DC33C;
  int& oCText::TXT_NEWS_STOLE_100   = *(int*)0x008DC340;
  int& oCText::TXT_NEWS_ATTACKED    = *(int*)0x008DC344;
  int& oCText::TXT_NEWS_KILLED      = *(int*)0x008DC348;
  int& oCText::TXT_YNEWS_INTRO      = *(int*)0x008DC34C;
  int& oCText::TXT_YNEWS_STOLE      = *(int*)0x008DC350;
  int& oCText::TXT_YNEWS_STOLE_10   = *(int*)0x008DC354;
  int& oCText::TXT_YNEWS_STOLE_30   = *(int*)0x008DC358;
  int& oCText::TXT_YNEWS_STOLE_50   = *(int*)0x008DC35C;
  int& oCText::TXT_YNEWS_STOLE_70   = *(int*)0x008DC360;
  int& oCText::TXT_YNEWS_STOLE_90   = *(int*)0x008DC364;
  int& oCText::TXT_YNEWS_STOLE_100  = *(int*)0x008DC368;
  int& oCText::TXT_YNEWS_ATTACKED   = *(int*)0x008DC36C;
  int& oCText::TXT_YNEWS_KILLED     = *(int*)0x008DC370;
  int& oCText::TXT_INTIMIDATION     = *(int*)0x008DC320;
  int& oCText::TXT_INVCAT           = *(int*)0x008DC374;
  int& oCText::TXT_HELP             = *(int*)0x008DC378;
#endif // __OTEXT_H__VER0__

#ifdef __OVIS_FX_H__VER0__
  zCParser*& oCVisualFX::fxParser = *(zCParser**)0x00869E6C;
  oCVisualFX*& oCVisualFX::actFX  = *(oCVisualFX**)0x00869EA4;
#endif // __OVIS_FX_H__VER0__

#ifdef __Z3D_H__VER0__
  zCCamera*& zCCamera::activeCam                         = *(zCCamera**)0x00873240;
  zVEC3& zCCamera::activeCamPos                          = *(zVEC3*)0x00873234;
  zCVertex*& zCPolygon::s_clipVertScene                  = *(zCVertex**)0x0089C490;
  int& zCPolygon::s_numClipVertScene                     = *(int*)0x008AC490;
  zCVertFeature*& zCPolygon::s_clipFeatScene             = *(zCVertFeature**)0x0087C3C0;
  int& zCPolygon::s_numClipFeatScene                     = *(int*)0x0089C488;
  int& zCPolygon::s_numVertListScene                     = *(int*)0x008B4540;
  int& zCPolygon::s_numFeatListScene                     = *(int*)0x008AC494;
  zCVertex**& zCPolygon::s_actClipVert                   = *(zCVertex***)0x008B4548;
  int& zCPolygon::s_actNumClipVert                       = *(int*)0x008B454C;
  zCMaterial*& zCPortal::portalDummyMaterial             = *(zCMaterial**)0x00873090;
#endif // __Z3D_H__VER0__

#ifdef __ZACCOUNT_H__VER0__
  int& zCAccount::s_actCounter = *(int*)0x009D9CF4;
#endif // __ZACCOUNT_H__VER0__

#ifdef __ZAI_CAMERA_H__VER0__
  short int& zCAICamera::s_iLookAroundSgn         = *(short int*)0x008341DC;
  zCArray<zCCSCamera*>& zCAICamera::dialogCamList = *(zCArray<zCCSCamera*>*)0x0086A0D4;
  float& zCAICamera::lookingCamLastAzi            = *(float*)0x0086A1D8;
  int& zCAICamera::lookingCamAziGoalReached       = *(int*)0x0086A1DC;
  zCAICamera*& zCAICamera::current                = *(zCAICamera**)0x0086A1D0;
  int& zCAICamera::bCreated                       = *(int*)0x0086A1D4;
  int& zCAICamera::bCamChanges                    = *(int*)0x008341D0;
#endif // __ZAI_CAMERA_H__VER0__

#ifdef __ZARCHIVER_H__VER0__
  zSTRING& zCArchiver::stringEOL = *(zSTRING*)0x0086FB18;
#endif // __ZARCHIVER_H__VER0__

#ifdef __ZBSP_H__VER0__
  int& zCBspTree::s_showPortals                             = *(int*)0x00873094;
  int& zCBspSector::s_sectorsRendered                       = *(int*)0x0086FC08;
  int& zCBspSector::s_startPointOutdoor                     = *(int*)0x0086FC00;
  int& zCBspSector::s_outdoorPortal                         = *(int*)0x0086FC10;
  zCArray<zCBspSector*>& zCBspSector::s_activeSectorList    = *(zCArray<zCBspSector*>*)0x0086FC14;
  zCArray<zTBBox2D>& zCBspSector::s_activeOutdoorPortals    = *(zCArray<zTBBox2D>*)0x0086FBD4;
#endif // __ZBSP_H__VER0__

#ifdef __ZBVOLUME_H__VER0__
  zMAT4& zCOBBox3D::trafoB2ToThis = *(zMAT4*)0x008730F0;
#endif // __ZBVOLUME_H__VER0__

#ifdef __ZCCS_CONTEXT_H__VER0__
  int& zCCSCutsceneContext::playDisabled = *(int*)0x0085E2F4;
#endif // __ZCCS_CONTEXT_H__VER0__

#ifdef __ZCOLLISION_DETECTOR_H__VER0__
  unsigned long& zCCollisionDetector::s_iCollisionDetectorFrameCtr = *(unsigned long*)0x00873590;
  int& zCCollisionDetector::s_iCurrentCollReport                   = *(int*)0x00873594;
  zCCollisionReport*& zCCollisionDetector::s_aoCollReportList      = *(zCCollisionReport**)0x00873250;
#endif // __ZCOLLISION_DETECTOR_H__VER0__

#ifdef __ZCOLLISION_OBJECT_H__VER0__
  zCArray<zCCollisionObjectDef*>*& zCCollisionObjectDef::s_aoCollObjClassList = *(zCArray<zCCollisionObjectDef*>**)0x008735AC;
#endif // __ZCOLLISION_OBJECT_H__VER0__

#ifdef __ZCONSOLE_H__VER0__
  zCList<zCConsole>& zCConsole::active_consoles = *(zCList<zCConsole>*)0x008DC680;
  zCConsole*& zCConsole::cur_console            = *(zCConsole**)0x008DC688;
#endif // __ZCONSOLE_H__VER0__

#ifdef __ZCONVEX_COLLISION_H__VER0__
  zCConvexPrimitiveUnitSphere& zCConvexPrimitiveUnitSphere::s_unitSphere = *(zCConvexPrimitiveUnitSphere*)0x008736F0;
#endif // __ZCONVEX_COLLISION_H__VER0__

#ifdef __ZCS_CAMERA_H__VER0__
  int& zCCSCamera::playing        = *(int*)0x0086C800;
  int& zCCSCamera::draw           = *(int*)0x0086C804;
  int& zCCSCamera::evaluateAvgFPS = *(int*)0x0086C808;
#endif // __ZCS_CAMERA_H__VER0__

#ifdef __ZDISK_H__VER0__
  int& zFILE::s_numFilesOpen                         = *(int*)0x0085F2B8;
  int& zFILE::s_maxFilesOpen                         = *(int*)0x0085F2BC;
  zCCriticalSection*& zFILE::s_dirscanCiticalSection = *(zCCriticalSection**)0x0085F2B4;
  zFILE*& zFILE::s_virtPath                          = *(zFILE**)0x0085F298;
  zSTRING& zFILE::s_virtPathString                   = *(zSTRING*)0x0085F29C;
  zSTRING& zFILE::s_physPathString                   = *(zSTRING*)0x0085F284;
  zSTRING& zFILE::s_rootDirString                    = *(zSTRING*)0x0085F270;
  bool& zFILE::s_initialized                         = *(bool*)0x0085F2C0;
  zCBuffer**& zFILE::bufferList                      = *(zCBuffer***)0x0085F23C;
  int*& zFILE::bufferFlag                            = *(int**)0x0085F254;
#endif // __ZDISK_H__VER0__

#ifdef __ZDISK__VDFS_H__VER0__
  bool& zFILE_VDFS::s_physical_first                = *(bool*)0x0085F2CD;
  bool& zFILE_VDFS::s_vdfsInitialized               = *(bool*)0x0085F2CC;
  zCCriticalSection*& zFILE_VDFS::s_criticalSection = *(zCCriticalSection**)0x0085F2D0;
#endif // __ZDISK__VDFS_H__VER0__

#ifdef __ZEIGEN_H__VER0__
  int& zCMgcEigenD::verbose                          = *(int*)0x008737EC;
  unsigned int& zCMgcEigenD::error                   = *(unsigned int*)0x008737F0;
  const unsigned int& zCMgcEigenD::invalid_size      = *(const unsigned int*)0x007D3E54;
  const unsigned int& zCMgcEigenD::allocation_failed = *(const unsigned int*)0x007D3E58;
  const unsigned int& zCMgcEigenD::ql_exceeded       = *(const unsigned int*)0x007D3E5C;
  const char**& zCMgcEigenD::message                 = *(const char***)0x0083D874;
#endif // __ZEIGEN_H__VER0__

#ifdef __ZEVENT_MAN_H__VER0__
  int& zCEventManager::disableEventManagers          = *(int*)0x008DC710;
  zCArray<zCEventManager*>& zCEventManager::activeEM = *(zCArray<zCEventManager*>*)0x008DC704;
  int& zCEventManager::showMsgCommunication          = *(int*)0x008DC714;
#endif // __ZEVENT_MAN_H__VER0__

#ifdef __ZFONTS_H__VER0__
  zCTextureConvert*& zCFont::texConv = *(zCTextureConvert**)0x008DC720;
#endif // __ZFONTS_H__VER0__

#ifdef __ZGRAFIX_H__VER0__
  zCGfx*& zCGfx::Gfx_List = *(zCGfx**)0x008DCDD8;
  int& zCGfx::gfxcount    = *(int*)0x008DCDDC;
#endif // __ZGRAFIX_H__VER0__

#ifdef __ZINPUT_H__VER0__
  zCArray<zSCtrlValue>& zCInput::values = *(zCArray<zSCtrlValue>*)0x0086CC90;
#endif // __ZINPUT_H__VER0__

#ifdef __ZLENSFLARE_H__VER0__
  zCMesh*& zCLensFlareFX::s_lensFlareMesh = *(zCMesh**)0x0087389C;
  zCMesh*& zCLensFlareFX::s_coronaMesh    = *(zCMesh**)0x008738A0;
  zCMesh*& zCLensFlareFX::s_glowMesh      = *(zCMesh**)0x008738A4;
#endif // __ZLENSFLARE_H__VER0__

#ifdef __ZMATERIAL_H__VER0__
  unsigned long& zCTexAniCtrl::masterFrameCtr  = *(unsigned long*)0x00873994;
  unsigned char& zCMaterial::s_matUsageDefault = *(unsigned char*)0x0083E7B8;
#endif // __ZMATERIAL_H__VER0__

#ifdef __ZMATH_TOOLS_H__VER0__
  zMAT4& zCPose::tmpMat = *(zMAT4*)0x0086D360;
#endif // __ZMATH_TOOLS_H__VER0__

#ifdef __ZMEM_POOL_H__VER0__
  const char*& zCMemPoolBase::s_className = *(const char**)0x008739A0;
  const char*& zCMemPoolBase::s_fileName  = *(const char**)0x008739A4;
  int& zCMemPoolBase::s_line              = *(int*)0x008739A8;
  int& zCMemPoolBase::s_disablePools      = *(int*)0x0083E964;
#endif // __ZMEM_POOL_H__VER0__

#ifdef __ZMENU_H__VER0__
  zCParser*& zCMenu::menuParser          = *(zCParser**)0x0086D3D8;
  zCTimer*& zCMenu::timer                = *(zCTimer**)0x0086D3E4;
  zCArraySort<zCMenu*>& zCMenu::menuList = *(zCArraySort<zCMenu*>*)0x0086D3B4;
  zCArray<zCMenu*>& zCMenu::activeList   = *(zCArray<zCMenu*>*)0x0086D3A8;
  zCSoundFX*& zCMenu::browseSnd          = *(zCSoundFX**)0x0086D3F8;
  zCSoundFX*& zCMenu::selectSnd          = *(zCSoundFX**)0x0086D3FC;
  zCSoundFX*& zCMenu::escSnd             = *(zCSoundFX**)0x0086D400;
  zCVob*& zCMenu::soundSourceVob         = *(zCVob**)0x0086D404;
  zCWorld*& zCMenu::world                = *(zCWorld**)0x0086D3DC;
  zCCamera*& zCMenu::camera              = *(zCCamera**)0x0086D3E0;
  int& zCMenu::inGameMenu                = *(int*)0x0086D3E8;
#endif // __ZMENU_H__VER0__

#ifdef __ZMENU__ITEM_H__VER0__
  zCArraySort<zCMenuItem*>& zCMenuItem::itemList = *(zCArraySort<zCMenuItem*>*)0x0086D464;
  zCMenuItem*& zCMenuItem::tmp                   = *(zCMenuItem**)0x0086D474;
#endif // __ZMENU__ITEM_H__VER0__

#ifdef __ZMODEL_H__VER0__
  float& zTMdl_AniSample::samplePosScaler          = *(float*)0x00873C4C;
  float& zTMdl_AniSample::samplePosRangeMin        = *(float*)0x00873D4C;
  int& zCModelPrototype::s_ignoreAnis              = *(int*)0x00873D84;
  int& zCModelPrototype::s_autoConvertAnis         = *(int*)0x0083F680;
  int& zCModelPrototype::s_autoConvertMeshes       = *(int*)0x00873D88;
  zCModelPrototype*& zCModelPrototype::s_modelRoot = *(zCModelPrototype**)0x00873D8C;
  int& zCModel::s_drawSkeleton                     = *(int*)0x00873C20;
#endif // __ZMODEL_H__VER0__

#ifdef __ZMORPH_MESH_H__VER0__
  int& zCMorphMeshProto::autoConvertBinaryFile   = *(int*)0x00873E60;
  zCMorphMeshProto*& zCMorphMeshProto::morphRoot = *(zCMorphMeshProto**)0x00873E5C;
#endif // __ZMORPH_MESH_H__VER0__

#ifdef __ZMUSIC_H__VER0__
  int& zCMusicSystem::s_musicSystemDisabled = *(int*)0x0086D480;
#endif // __ZMUSIC_H__VER0__

#ifdef __ZNET_HOST_H__VER0__
  unsigned char& zCNetHost::iter   = *(unsigned char*)0x00868FB4;
  zCNetHost*& zCNetHost::localhost = *(zCNetHost**)0x00868FB8;
#endif // __ZNET_HOST_H__VER0__

#ifdef __ZOPTION_H__VER0__
  int& zCOption::trade_amount = *(int*)0x00830BA8;
#endif // __ZOPTION_H__VER0__

#ifdef __ZPARSER_H__VER0__
  int& zCParser::enableParsing    = *(int*)0x008DDFCC;
  zCParser*& zCParser::cur_parser = *(zCParser**)0x008DDFD4;
#endif // __ZPARSER_H__VER0__

#ifdef __ZPARSER__SYMBOL_H__VER0__
  zCPar_Symbol*& zCPar_Symbol::instance_sym        = *(zCPar_Symbol**)0x008DE178;
  void*& zCPar_Symbol::instance_adr                = *(void**)0x008DE17C;
  zCPar_SymbolTable*& zCPar_SymbolTable::cur_table = *(zCPar_SymbolTable**)0x008DE174;
#endif // __ZPARSER__SYMBOL_H__VER0__

#ifdef __ZPARTICLE_H__VER0__
  zCParser*& zCParticleFX::s_pfxParser                               = *(zCParser**)0x00874380;
  zCArraySort<zCParticleEmitter*>& zCParticleFX::s_emitterPresetList = *(zCArraySort<zCParticleEmitter*>*)0x00873FA0;
  zCParticleEmitter& zCParticleFX::s_emitterDummyDefault             = *(zCParticleEmitter*)0x00873FB0;
  int& zCParticleFX::s_globNumPart                                   = *(int*)0x0087436C;
  zTParticle*& zCParticleFX::s_globPartList                          = *(zTParticle**)0x00874370;
  zTParticle*& zCParticleFX::s_globFreePart                          = *(zTParticle**)0x00874374;
  zCMesh*& zCParticleFX::s_partMeshTri                               = *(zCMesh**)0x00874378;
  zCMesh*& zCParticleFX::s_partMeshQuad                              = *(zCMesh**)0x0087437C;
  int& zCParticleFX::s_showDebugInfo                                 = *(int*)0x00874384;
  zCParticleFX::zCStaticPfxList& zCParticleFX::s_pfxList             = *(zCParticleFX::zCStaticPfxList*)0x00874360;
#endif // __ZPARTICLE_H__VER0__

#ifdef __ZPLAYER_GROUP_H__VER0__
  zCPlayerGroup& zCPlayerGroup::allPlayerGroup     = *(zCPlayerGroup*)0x008696C0;
  zCList<zCPlayerGroup>& zCPlayerGroup::group_list = *(zCList<zCPlayerGroup>*)0x008696A4;
#endif // __ZPLAYER_GROUP_H__VER0__

#ifdef __ZPLAYER_INFO_H__VER0__
  zCArray<int>& zCPlayerInfo::free_ids      = *(zCArray<int>*)0x00869700;
  unsigned char& zCPlayerInfo::next_id      = *(unsigned char*)0x008313F8;
  zCPlayerInfo*& zCPlayerInfo::activePlayer = *(zCPlayerInfo**)0x00869734;
#endif // __ZPLAYER_INFO_H__VER0__

#ifdef __ZPROG_MESH_H__VER0__
  zTFrameCtr& zCProgMeshProto::s_frameCtr                   = *(zTFrameCtr*)0x008418B4;
  unsigned short int*& zCProgMeshProto::s_wedgeRemap        = *(unsigned short int**)0x008B7AA0;
  zVEC3*& zCProgMeshProto::s_posCacheList                   = *(zVEC3**)0x008B9AA0;
  zVEC3*& zCProgMeshProto::s_posNormalCSList                = *(zVEC3**)0x008BFB38;
  zCArray<unsigned short>& zCProgMeshProto::s_workIndexList = *(zCArray<unsigned short>*)0x008C5B38;
  int& zCProgMeshProto::s_subMeshRenderDir                  = *(int*)0x008418B8;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferColor    = *(zCVertexBufferDyn**)0x008C5BE0;
  zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferNormal   = *(zCVertexBufferDyn**)0x008C5BE4;
  float& zCProgMeshProto::s_lodParamStrengthOverride        = *(float*)0x008418BC;
  float& zCProgMeshProto::s_lodParamStrengthModifier        = *(float*)0x008418C0;
  int& zCProgMeshProto::s_markMeshMaterials                 = *(int*)0x008C5BDC;
  int& zCProgMeshProto::s_autoSubdivEnabled                 = *(int*)0x008C5BD4;
  unsigned long& zCProgMeshProto::s_classCtorCtr            = *(unsigned long*)0x008C5BD8;
#endif // __ZPROG_MESH_H__VER0__

#ifdef __ZRAY_CACHE_H__VER0__
  zCRayCacheElement*& zCRayCache::s_current = *(zCRayCacheElement**)0x008C5E44;
  zVEC3& zCRayCache::s_start                = *(zVEC3*)0x008C5C64;
  zVEC3& zCRayCache::s_stop                 = *(zVEC3*)0x008C5C70;
  zCRayCache*& zCRayCache::s_anchor         = *(zCRayCache**)0x008C5E40;
#endif // __ZRAY_CACHE_H__VER0__

#ifdef __ZRENDER_MANAGER_H__VER0__
  zCShader*& zCRenderManager::s_shaderList                        = *(zCShader**)0x008C8F70;
  zCShaderStage*& zCRenderManager::s_shaderStageList              = *(zCShaderStage**)0x008C5F68;
  int& zCRenderManager::s_currentShader                           = *(int*)0x008CE934;
  int& zCRenderManager::s_currentShaderStage                      = *(int*)0x008CE938;
  int& zCRenderManager::s_useRendererTNL                          = *(int*)0x00841EF8;
  int& zCRenderManager::s_detailTexturesEnabled                   = *(int*)0x008CE930;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex1       = *(zCVertexBufferDyn2**)0x008CE93C;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2       = *(zCVertexBufferDyn2**)0x008CE940;
  zCVertexBufferDyn2*& zCRenderManager::s_vertBufferDynTex2Normal = *(zCVertexBufferDyn2**)0x008CE944;
#endif // __ZRENDER_MANAGER_H__VER0__

#ifdef __ZRND_D3D_H__VER0__
  zCVertexBufferDyn*& zD3D_alphaPoly::vertexbufferdyn                           = *(zCVertexBufferDyn**)0x00929D6C;
  zCVertexBuffer*& zD3D_alphaPoly::vertexbuffer                                 = *(zCVertexBuffer**)0x00929D70;
  int& zD3D_alphaPoly::locked                                                   = *(int*)0x00929D74;
  unsigned long& zD3D_alphaPoly::startvertex                                    = *(unsigned long*)0x00929D78;
  unsigned long& zD3D_alphaPoly::actvertex                                      = *(unsigned long*)0x00929D7C;
  int& zD3D_alphaPoly::numberofvertices                                         = *(int*)0x00929D80;
  int& zD3D_alphaPoly::actnov                                                   = *(int*)0x00929D84;
  struct ID3DXContext*& zCRnd_D3D::xd3d_pd3dx                                   = *(struct ID3DXContext**)0x00929D50;
  IDirectDraw7*& zCRnd_D3D::xd3d_pdd7                                           = *(IDirectDraw7**)0x00929D54;
  IDirect3D7*& zCRnd_D3D::xd3d_pd3d7                                            = *(IDirect3D7**)0x00929D58;
  IDirect3DDevice7*& zCRnd_D3D::xd3d_pd3dDevice7                                = *(IDirect3DDevice7**)0x00929D5C;
  unsigned long& zCRnd_D3D::xd3d_actFrameNumber                                 = *(unsigned long*)0x00929D68;
  int& zCRnd_D3D::xd3d_dd7inuse                                                 = *(int*)0x00929D60;
  int& zCRnd_D3D::xd3d_palsupp                                                  = *(int*)0x00929D64;
  zCSurfaceCache_D3D::zD3D_SlotHeader**& zCSurfaceCache_D3D::xsc_listofsurfaces = *(zCSurfaceCache_D3D::zD3D_SlotHeader***)0x00900350;
  int& zCSurfaceCache_D3D::xsc_listposition                                     = *(int*)0x00929D88;
  zCArray<zCVertexBuffer_D3D*>& zCVertexBuffer_D3D::xvb_vertexbufferList        = *(zCArray<zCVertexBuffer_D3D*>*)0x00929DA4;
#endif // __ZRND_D3D_H__VER0__

#ifdef __ZSKY_H__VER0__
  zCSkyControler*& zCSkyControler::s_activeSkyControler = *(zCSkyControler**)0x008CEBB8;
  int& zCSkyControler::s_skyEffectsEnabled              = *(int*)0x008422A0;
#endif // __ZSKY_H__VER0__

#ifdef __ZSND_MSS_H__VER0__
  zCArraySort<zCActiveSnd*>& zCActiveSnd::activeSndList = *(zCArraySort<zCActiveSnd*>*)0x0086D700;
  unsigned long& zCActiveSnd::lastHandle                = *(unsigned long*)0x0086DCF0;
  int& zCActiveSnd::maxChannels                         = *(int*)0x00837830;
  int& zCActiveSnd::autoUpdate3D                        = *(int*)0x0086DCF4;
  zCArray<zCActiveSnd*>& zCActiveSnd::preAllocedSndList = *(zCArray<zCActiveSnd*>*)0x0086DCB8;
  zCActiveSnd*& zCActiveSnd::nextFreeSnd                = *(zCActiveSnd**)0x0086DCEC;
  zCDrvProperties_MSS& zCSndSys_MSS::prefs              = *(zCDrvProperties_MSS*)0x0086D848;
#endif // __ZSND_MSS_H__VER0__

#ifdef __ZSOUND_MAN_H__VER0__
  zCSoundManager::zTScriptSoundData& zCSoundManager::scriptSoundData = *(zCSoundManager::zTScriptSoundData*)0x008CEE58;
  zSTRING& zCSoundManager::mediumIDList                              = *(zSTRING*)0x008CEE94;
  zSTRING& zCSoundManager::prefixProto                               = *(zSTRING*)0x008CEEA8;
#endif // __ZSOUND_MAN_H__VER0__

#ifdef __ZTEXTURE_H__VER0__
  zSTRING& zCTexture::zTEX_DEFAULT_TEXTURE_FILE           = *(zSTRING*)0x008CF0DC;
  zTTexScaleSize& zCTexture::s_texScaleSize               = *(zTTexScaleSize*)0x00842D04;
  zTTexScaleBPP& zCTexture::s_texScaleBPP                 = *(zTTexScaleBPP*)0x00842D08;
  unsigned long& zCTexture::s_texSupportedFormats         = *(unsigned long*)0x008CF1D0;
  char& zCTexture::s_useDefaultTex                        = *(char*)0x00842D00;
  char& zCTexture::s_globalLoadTextures                   = *(char*)0x00842D01;
  unsigned long& zCTexture::s_texMaxPixelSize             = *(unsigned long*)0x008CF1D4;
  zSTRING*& zCTexture::s_texDesiredBPPSuffix              = *(zSTRING**)0x008CF180;
  zTRnd_TextureFormat*& zCTexture::s_texDesiredBPPDefault = *(zTRnd_TextureFormat**)0x00842D14;
  float& zCTexture::s_texRefRAM                           = *(float*)0x00842D0C;
  zCTexture::zTTexFileDesiredBPP& zCTexture::s_texRefBPP  = *(zCTexture::zTTexFileDesiredBPP*)0x00842D10;
#endif // __ZTEXTURE_H__VER0__

#ifdef __ZVERTEX_BUFFER_H__VER0__
  unsigned long& zCVertexBuffer::s_classCtorCtr = *(unsigned long*)0x008D72A8;
#endif // __ZVERTEX_BUFFER_H__VER0__

#ifdef __ZVIEW_H__VER0__
  zCList<zCInputCallback>& zCInputCallback::inputList = *(zCList<zCInputCallback>*)0x008DE1A4;
  zCView*& zCView::stdoutput                          = *(zCView**)0x008DE1C0;
  zCView*& zCView::modal                              = *(zCView**)0x008DE1C4;
  int& zCView::showDebug                              = *(int*)0x008DE1C8;
#endif // __ZVIEW_H__VER0__

#ifdef __ZVIEW_BASE_H__VER0__
  const unsigned short& zCViewBase::ViewVirtualWidth  = *(const unsigned short*)0x007DF790;
  const unsigned short& zCViewBase::ViewVirtualHeight = *(const unsigned short*)0x007DF792;
#endif // __ZVIEW_BASE_H__VER0__

#ifdef __ZVISUAL_H__VER0__
  zCArray<zCVisual*>& zCVisual::s_visualClassList = *(zCArray<zCVisual*>*)0x008D72CC;
  zCMesh*& zCDecal::decalMesh1Sided               = *(zCMesh**)0x008737E0;
  zCMesh*& zCDecal::decalMesh2Sided               = *(zCMesh**)0x008737E4;
  int& zCMesh::s_autoConvertMeshes                = *(int*)0x00873A60;
  int& zCMesh::s_numMeshes                        = *(int*)0x00873A58;
  zCMesh*& zCMesh::s_meshRoot                     = *(zCMesh**)0x00873A5C;
#endif // __ZVISUAL_H__VER0__

#ifdef __ZVOB_H__VER0__
  int& zCVob::s_ignoreVisuals                             = *(int*)0x008D75F0;
  zCMesh*& zCVob::s_shadowMesh                            = *(zCMesh**)0x008D75E8;
  unsigned long& zCVob::s_nextFreeID                      = *(unsigned long*)0x008D75EC;
  int& zCVob::s_vobAlreadyInMovement                      = *(int*)0x008D75E4;
  int& zCVob::s_renderVobs                                = *(int*)0x00843734;
  int& zCVob::s_showHelperVisuals                         = *(int*)0x008D75F4;
  zCCollisionDetector*& zCVob::s_poCollisionDetector      = *(zCCollisionDetector**)0x008D75F8;
  zCArray<zCVobLightPreset*>& zCVobLight::lightPresetList = *(zCArray<zCVobLightPreset*>*)0x008D767C;
  int& zCVobLight::renderLightVisuals                     = *(int*)0x008D7688;
  int& zCVobLevelCompo::unarcIgnoreVisuals                = *(int*)0x008D75FC;
#endif // __ZVOB_H__VER0__

#ifdef __ZWORLD_H__VER0__
  zCWorld::zTWorldLoadMode& zCWorld::s_worldLoadMode       = *(zCWorld::zTWorldLoadMode*)0x008D8168;
  zCWorld::zTWorldSaveMode& zCWorld::s_worldSaveMode       = *(zCWorld::zTWorldSaveMode*)0x008D817C;
  zCWorld::zTWorldLoadMergeMode& zCWorld::s_worldMergeMode = *(zCWorld::zTWorldLoadMergeMode*)0x008D8170;
#endif // __ZWORLD_H__VER0__

#ifdef __ZOBJECT_H__VER0__
  zCArraySort<zCClassDef*>*& zCClassDef::classDefList = *(zCArraySort<zCClassDef*>**)0x00873F78;
  zCClassDef*& zCClassDef::classDefSearchDummy        = *(zCClassDef**)0x00873F80;
  int& zCClassDef::startupFinished                    = *(int*)0x00873F7C;
#endif // __ZOBJECT_H__VER0__

#ifdef __ZZONE_H__VER0__
  zCBBox3DSorterBase*& zCBBox3DSorterBase::s_currentSorter = *(zCBBox3DSorterBase**)0x009A4684;
  int& zCBBox3DSorterBase::s_currentDimension              = *(int*)0x009A46F4;
  int& zCZoneMusic::s_autochange                           = *(int*)0x008AAF6C;
  int& zCZoneMusic::s_canruleautochange                    = *(int*)0x009A4924;
#endif // __ZZONE_H__VER0__

#ifdef __ZALGEBRA_H__VER0__
  zMAT3& zMAT3::s_identity = *(zMAT3*)0x0086F8A8;
  zMAT4& zMAT4::s_identity = *(zMAT4*)0x0086F868;
#endif // __ZALGEBRA_H__VER0__

#ifdef __OLOG_MANAGER_H__VER0__
  char**& oCLogTopic::ms_strSections = *(char***)0x00857708;
  char**& oCLogTopic::ms_strStati    = *(char***)0x00857714;
#endif // __OLOG_MANAGER_H__VER0__

#ifdef __ZCOLLISION_OBJECT_MISC_H__VER0__
  zCCollisionObjectDef* zCCollisionObject::s_oCollObjClass          = (zCCollisionObjectDef*)0x0087359C;
  zCCollisionObjectDef* zCCollObjectUndef::s_oCollObjClass          = (zCCollisionObjectDef*)0x008735F8;
  zCCollisionObjectDef* zCCollObjectPoint::s_oCollObjClass          = (zCCollisionObjectDef*)0x008735EC;
  zCCollisionObjectDef* zCCollObjectBoxPassThrough::s_oCollObjClass = (zCCollisionObjectDef*)0x008735BC;
  zCCollisionObjectDef* zCCollObjectComplex::s_oCollObjClass        = (zCCollisionObjectDef*)0x00873604;
  zCCollisionObjectDef* zCCollObjectBoxBlocker::s_oCollObjClass     = (zCCollisionObjectDef*)0x008735C8;
  zCCollisionObjectDef* zCCollObjectLevelPolys::s_oCollObjClass     = (zCCollisionObjectDef*)0x008735E0;
  zCCollisionObjectDef* zCCollObjectCharacter::s_oCollObjClass      = (zCCollisionObjectDef*)0x00873610;
  zCCollisionObjectDef* zCCollObjectProjectile::s_oCollObjClass     = (zCCollisionObjectDef*)0x008735D4;
#endif // __ZCOLLISION_OBJECT_MISC_H__VER0__

} // namespace Gothic_I_Classic