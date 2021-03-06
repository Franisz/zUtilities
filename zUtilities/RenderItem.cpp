// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  HOOK Hook_CMovementTracker_UpdatePlayerPos PATCH( &zCMovementTracker::UpdatePlayerPos, &zCMovementTracker::UpdatePlayerPos_Union );
  void zCMovementTracker::UpdatePlayerPos_Union( zVEC3 const& position ) {
    if ( Options::CenterInvItems && player->inventory2.IsOpen() && !player->inventory2.GetNextContainerLeft( &player->inventory2 ) ) {
      zVEC3 rightVector = camVob->GetRightVectorWorld() * 115.0f;
      THISCALL( Hook_CMovementTracker_UpdatePlayerPos )(position + rightVector);
      return;
    }

    THISCALL( Hook_CMovementTracker_UpdatePlayerPos )(position);
  }

  zCWorld* renderWld = nullptr;
  zCViewBase* renderView = nullptr;
  float renderRotate = 0;
  bool renderNow = false;

  HOOK Hook_oCItem_RenderItem PATCH( &oCItem::RenderItem, &oCItem::RenderItem_Union );
  void oCItem::RenderItem_Union( zCWorld* wld, zCViewBase* view, float rotate ) {
    if ( Options::CenterInvItems ) {
      bool IsCenterItem = false;
      auto list = oCItemContainer::contList.GetNextInList();

      while ( list != nullptr ) {
        oCItemContainer* container = list->GetData();
        list = list->GetNextInList();

        if ( container->viewItemInfoItem != view ) continue;

        zCView* itemView = static_cast<zCView*>(view);
        IsCenterItem = true;

        if ( !renderNow ) {
          renderWld = wld;
          renderView = view;
          renderRotate = rotate;
          return;
        }

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
        renderNow = false;
      }

#if ENGINE >= Engine_G2
      // Disables rotation of item in inventory slot
      if ( !IsCenterItem )
        rotate = 0.0f;
#endif
    }

    // Draw item label
    if ( Options::LabelItems ) {
      if ( !Options::PutLabelBehind ) {
        THISCALL( Hook_oCItem_RenderItem )(wld, view, rotate);
        ItemLabel label = ItemLabel( this, view );
        return;
      }

      ItemLabel label = ItemLabel( this, view );
    }

    THISCALL( Hook_oCItem_RenderItem )(wld, view, rotate);
  }

  void RenderSelectedItem() {
    if ( !Options::CenterInvItems )
      return;

    if ( player->inventory2.IsOpen() ) {
      oCItemContainer* leftInv = player->inventory2.GetNextContainerLeft( &player->inventory2 );
      oCItem* item = (leftInv && leftInv->IsActive()) ? leftInv->GetSelectedItem() : player->inventory2.GetSelectedItem();

      renderNow = true;
      if ( item && renderWld && renderView ) {
        item->RenderItem( renderWld, renderView, renderRotate );
        zrenderer->SetViewport( 0, 0, zrenderer->vid_xdim, zrenderer->vid_ydim );
      }
    }

    renderWld = nullptr;
    renderView = nullptr;
    renderRotate = 0;
  }
}