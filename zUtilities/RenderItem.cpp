// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

  HOOK Hook_CMovementTracker_UpdatePlayerPos PATCH( &zCMovementTracker::UpdatePlayerPos, &zCMovementTracker::UpdatePlayerPos_Union );
  void zCMovementTracker::UpdatePlayerPos_Union( zVEC3 const& position ) {

    if ( bRenderInvItems && player->inventory2.IsOpen() && !player->inventory2.GetNextContainerLeft( &player->inventory2 ) ) {
      zVEC3 rightVector = camVob->GetRightVectorWorld() * 115.0f;
      THISCALL( Hook_CMovementTracker_UpdatePlayerPos )(position + rightVector);
      return;
    }

    THISCALL( Hook_CMovementTracker_UpdatePlayerPos )(position);
  }

  HOOK Hook_oCItem_RenderItem PATCH( &oCItem::RenderItem, &oCItem::RenderItem_Union );
  void oCItem::RenderItem_Union( zCWorld* wld, zCViewBase* view, float rotate ) {

    if ( !bRenderInvItems ) {
      THISCALL( Hook_oCItem_RenderItem )(wld, view, rotate);
      return;
    }

    bool IsCenterItem = FALSE;
    auto list = oCItemContainer::contList.GetNextInList();

    while ( list != nullptr ) {
      oCItemContainer* container = list->GetData();
      list = list->GetNextInList();

      if ( container->viewItemInfoItem != view ) continue;

      zCView* itemView = static_cast<zCView*>(view);
      IsCenterItem = TRUE;

      // Item scale
      float scale = 2.5;
      itemView->psizex *= scale;
      itemView->psizey *= scale;

      // Position
      itemView->pposy = (zrenderer->vid_ydim - itemView->psizey) / 2;
      itemView->pposx = (zrenderer->vid_xdim - itemView->psizex) / 2;

#if ENGINE < Engine_G2
      // Moves item when trading
      if ( player->trader )
        if ( container->right )
          itemView->pposx = (zrenderer->vid_xdim - itemView->psizex) * 4 / 5;
        else
          itemView->pposx = (zrenderer->vid_xdim - itemView->psizex) / 5;
#else
      // G2 Item rotation
      if ( inv_animate ) {
        rotate = 1.0f;
        RotateForInventory( 1 );
      }
#endif
    }

#if ENGINE >= Engine_G2
    // Disables rotation of item in inventory slot
    if ( !IsCenterItem )
      rotate = 0.0f;
#endif

    THISCALL( Hook_oCItem_RenderItem )(wld, view, rotate);
  }

}