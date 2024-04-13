// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{

  void __fastcall zCMovementTracker_UpdatePlayerPos(zCMovementTracker *_this, void *vtable, zVEC3 const &position);
  auto Hook_zCMovementTracker_UpdatePlayerPos = CreateHook(reinterpret_cast<void *>(zSwitch(0x004AD3E0, 0x004BB530, 0x004B3800, 0x004B5D30)), &zCMovementTracker_UpdatePlayerPos);
  void __fastcall zCMovementTracker_UpdatePlayerPos(zCMovementTracker *_this, void *vtable, zVEC3 const &position)
  {
    if (Options::CenterInvItems && player->inventory2.IsOpen() && !player->inventory2.GetNextContainerLeft(&player->inventory2))
    {
      zVEC3 rightVector = ogame->camera->connectedVob->GetRightVectorWorld() * 115.0f;

      Hook_zCMovementTracker_UpdatePlayerPos(_this, vtable, position + rightVector);
      return;
    }

    Hook_zCMovementTracker_UpdatePlayerPos(_this, vtable, position);
  }

  zCWorld *renderWld = nullptr;
  zCViewBase *renderView = nullptr;
  float renderRotate = 0;
  bool renderNow = false;

  void __fastcall oCItem_RenderItem(oCItem *_this, void *vtable, zCWorld *wld, zCViewBase *view, float rotate);
  auto Hook_oCItem_RenderItem = CreateHook(reinterpret_cast<void *>(zSwitch(0x00672F70, 0x006A0A20, 0x006B5A30, 0x00713AC0)), &oCItem_RenderItem);
  void __fastcall oCItem_RenderItem(oCItem *_this, void *vtable, zCWorld *wld, zCViewBase *view, float rotate)
  {
    // Hook_oCItem_RenderItem(_this, vtable, wld, view, rotate);

    if (Options::CenterInvItems)
    {
      bool IsCenterItem = false;
      auto list = oCItemContainer::contList.GetNextInList();

      while (list != nullptr)
      {
        oCItemContainer *container = list->GetData();
        list = list->GetNextInList();

        if (container->viewItemInfoItem != view)
          continue;

        zCView *itemView = static_cast<zCView *>(view);
        IsCenterItem = true;

        if (!renderNow)
        {
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
        if (player->trader)
          if (container->right)
            itemView->pposx = (zrenderer->vid_xdim - itemView->psizex) * 4 / 5;
          else
            itemView->pposx = (zrenderer->vid_xdim - itemView->psizex) / 5;
#else
        // G2 Item rotation
        if (_this->inv_animate)
        {
          rotate = 1.0f;
          _this->RotateForInventory(1);
        }
#endif
        renderNow = false;
      }

#if ENGINE >= Engine_G2
      // Disables rotation of item in inventory slot
      if (!IsCenterItem)
        rotate = 0.0f;
#endif
    }

    // Draw item label
    if (Options::LabelItems)
    {
      if (!Options::PutLabelBehind)
      {
        Hook_oCItem_RenderItem(_this, vtable, wld, view, rotate);
        ItemLabel label = ItemLabel(_this, view);
        return;
      }

      ItemLabel label = ItemLabel(_this, view);
    }

    Hook_oCItem_RenderItem(_this, vtable, wld, view, rotate);
  }

  void RenderSelectedItem()
  {
    if (!Options::CenterInvItems)
      return;

    if (player->inventory2.IsOpen())
    {
      oCItemContainer *leftInv = player->inventory2.GetNextContainerLeft(&player->inventory2);
      oCItem *item = (leftInv && leftInv->IsActive()) ? leftInv->GetSelectedItem() : player->inventory2.GetSelectedItem();

      renderNow = true;
      if (item && renderWld && renderView)
      {
        item->RenderItem(renderWld, renderView, renderRotate);
        zrenderer->SetViewport(0, 0, zrenderer->vid_xdim, zrenderer->vid_ydim);
      }
    }

    renderWld = nullptr;
    renderView = nullptr;
    renderRotate = 0;
  }
}