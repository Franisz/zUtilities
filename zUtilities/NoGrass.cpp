// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void NoGrass::Update() {
    auto prevNoGrass = Options::NoGrass;
    auto prevNoGrassRemoveVobsWithDynamicCollisions = Options::NoGrassRemoveVobsWithDynamicCollisions;
    Options::NoGrass = zoptions->ReadBool( PLUGIN_NAME, "NoGrass", false );
    Options::NoGrassDebugShowHidden = zoptions->ReadBool( PLUGIN_NAME, "NoGrassDebugShowHidden", true );
    Options::NoGrassRemoveVobsWithDynamicCollisions = zoptions->ReadBool( PLUGIN_NAME, "NoGrassRemoveVobsWithDynamicCollisions", false );

    if ( !zoptions->EntryExists( PLUGIN_NAME, "NoGrassVisualNames0" ) )
      zoptions->WriteString( PLUGIN_NAME, "NoGrassVisualNames0", "*grass*, *farn*, *bush*, *smallweed*, nw_nature_plant*, nw_nature_sideplant*, *cavewebs*, *mushroom*", 0 );
    // zoptions->WriteString(PLUGIN_NAME, "NoGrassVisualNames0", "NW_NATURE_FARN,NW_NATURE_BUSH,NW_NATURE_SIDEPLANT,NW_NATURE_PLANT,NW_NATURE_SMALLWEED,NW_NATURE_GRASS,NW_NATURE_LONG_BUSH,NW_CAVEWEBS,OW_MUSHROOM,OW_BUSH", 0);
    if ( !zoptions->EntryExists( PLUGIN_NAME, "NoGrassVisualNames1" ) )
      zoptions->WriteString( PLUGIN_NAME, "NoGrassVisualNames1", "kb_grass*, kb_unter*, kb_green*, kb_pflan*, kb_farn*, kb_strauch*, ody_farn*", 0 );
    // zoptions->WriteString(PLUGIN_NAME, "NoGrassVisualNames1", "KB_GRASS,KB_UNTER,KB_GREEN,KB_PFLAN,KB_FARN,KB_STRAUCH,ODY_FARN_GROSS", 0);
    if ( !zoptions->EntryExists( PLUGIN_NAME, "NoGrassVisualNames2" ) )
      zoptions->WriteString( PLUGIN_NAME, "NoGrassVisualNames2", "*duckweed*, *waterlili*", 0 );
    // zoptions->WriteString(PLUGIN_NAME, "NoGrassVisualNames2", "NW_NATURE_WATERGRASS,NW_NATURE_DUCKWEED,NW_NATURE_WATERLILI", 0);

    int vi = 0;
    while ( true ) {
      zSTRING entryName = zSTRING{ "NoGrassVisualNames" } + zSTRING{ vi++ };
      if ( zoptions->EntryExists( PLUGIN_NAME, entryName ) )
        Options::NoGrassVisualNames.push_back( A zoptions->ReadString( PLUGIN_NAME, entryName, "" ) );
      else
        break;
    }

    UpdateVisualsList();
    if ( prevNoGrass != Options::NoGrass || prevNoGrassRemoveVobsWithDynamicCollisions != Options::NoGrassRemoveVobsWithDynamicCollisions )
      UpdateVisuals();
  }

  void NoGrass::UpdateVisualsList() {
    visualsNames.clear();
    for ( auto visualsNamesLists : Options::NoGrassVisualNames ) {
      auto visualsNamesList = visualsNamesLists.Split( "," );
      for ( auto& visualName : visualsNamesList ) {
        visualName.Shrink();
        visualsNames.push_back( visualName );
      }
    }
  }

  bool NoGrass::IsValidVob( zCVob* vob ) {
    if ( !vob )
      return false;

    if ( vob->GetVobType() == zVOB_TYPE_ITEM || vob->GetVobType() == zVOB_TYPE_NSC || vob->GetVobType() == zVOB_TYPE_MOB )
      return false;

    if ( !vob->GetVisual() )
      return false;

    if ( vob->GetVisual()->GetVisualName().IsEmpty() )
      return false;

    if ( vob->GetVisual()->GetVisualName().HasWordI( ".PFX" ) )
      return false;

    return true;
  }

  void NoGrass::RestoreVisibility() {
    zCArray<zCVob*> vobList;
    ogame->GetWorld()->SearchVobListByClass( zCVob::classDef, vobList, nullptr );
    for ( int i = 0; i < vobList.GetNumInList(); i++ ) {
      auto vob = vobList[i];

      if ( !IsValidVob( vob ) )
        continue;

      if ( vob->showVisual )
        continue;

      auto vobVisualName = string( vob->GetVisual()->GetVisualName() );
      if ( std::find( visualsHidden.begin(), visualsHidden.end(), vobVisualName ) != visualsHidden.end() ) {
        vob->showVisual = 1;
      }
    }

    visualsHidden.clear();
  }

  void NoGrass::UpdateVisuals() {
    if ( !ogame || !ogame->GetWorld() )
      return;

    RestoreVisibility();

    if ( !Options::NoGrass )
      return;

    zCArray<zCVob*> vobList;
    ogame->GetWorld()->SearchVobListByClass( zCVob::classDef, vobList, nullptr );
    for ( int i = 0; i < vobList.GetNumInList(); i++ ) {
      auto vob = vobList[i];

      if ( !IsValidVob( vob ) )
        continue;

      if ( !Options::NoGrassRemoveVobsWithDynamicCollisions && vob->collDetectionDynamic )
        continue;

      if ( !vob->showVisual )
        continue;

      auto vobVisualName = string( vob->GetVisual()->GetVisualName() );

      /*if (std::find(visualsNames.begin(), visualsNames.end(), vobVisualName) == visualsNames.end())
        continue;*/

      for ( auto& visualName : visualsNames ) {
        // if (vobVisualName.HasWordI(visualName)) {
        if ( vobVisualName.CompareMaskedI( visualName ) ) {
          vob->showVisual = 0;
          visualsHidden.push_back( vobVisualName );
        }
      }
    }
  }

  void NoGrass::ShowVisualsNames() {
    zCArray<zCVob*> listVobs;
    player->CreateVobList( listVobs, 1000.0f );

    auto screenColor = screen->fontColor;
    auto textColor = GFX_WHITE;

    for ( int i = 0; i < listVobs.GetNumInList(); i++ ) {
      auto vob = listVobs[i];

      if ( !IsValidVob( vob ) )
        continue;

      // if (!Options::NoGrassRemoveVobsWithDynamicCollisions && vob->collDetectionDynamic)
      //   continue;

      if ( !Options::NoGrassDebugShowHidden && !vob->showVisual )
        continue;

      if ( !vob->showVisual )
        textColor = GFX_ORANGE;
      else
        textColor = GFX_WHITE;

      auto vobVisualName = vob->GetVisual()->GetVisualName();
      if ( vob->collDetectionDynamic )
        vobVisualName += zSTRING{ " (dynamic)" };

      zVEC2 viewPos;
      if ( !DamagePopup::WorldToView( vob->GetPositionWorld(), screen, viewPos ) )
        continue;

      screen->SetFontColor( textColor );
      screen->Print( viewPos[VX], viewPos[VY], vobVisualName );
    }

    screen->SetFontColor( screenColor );
  }
} // namespace GOTHIC_ENGINE
