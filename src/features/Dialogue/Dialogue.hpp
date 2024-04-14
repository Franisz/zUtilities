// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_NAMESPACE
{
  int choiceTextLine = 0;

  void __fastcall zCViewPrint_Blit(zCViewPrint *_this);
  auto Hook_zCViewPrint_Blit = CreateHook(reinterpret_cast<void *>(zSwitch(0x00756970, 0x00798DF0, 0x007A36F0, 0x006934A0)), &zCViewPrint_Blit);
  void __fastcall zCViewPrint_Blit(zCViewPrint *_this)
  {
    if (!zUtilitiesOptions->AlternativeDialogueBoxes || _this != oCInformationManager::GetInformationManager().DlgChoice)
    {
      Hook_zCViewPrint_Blit(_this);
      return;
    }

    if (_this->VirtualPosition.X != 0)
    {
      _this->VirtualPosition.X = 0;
      _this->SetVirtualPosition(_this->VirtualPosition);
    }

    if (_this->VirtualSize.X != 8192)
    {
      _this->VirtualSize.X = 8192;
      _this->SetVirtualSize(_this->VirtualSize);
    }

    choiceTextLine = 0;

    Hook_zCViewPrint_Blit(_this);
  }

  void __fastcall zCViewPrint_BlitTextCharacters(zCViewPrint *_this, zCViewText2 *a1, zCFont *a2, struct zCOLOR &a3);
  auto Hook_zCViewPrint_BlitTextCharacters = CreateHook(reinterpret_cast<void *>(zSwitch(0x00756B20, 0x00798FB0, 0x007A38A0, 0x00693650)), &zCViewPrint_BlitTextCharacters);
  void __fastcall zCViewPrint_BlitTextCharacters(zCViewPrint *_this, zCViewText2 *a1, zCFont *a2, struct zCOLOR &a3)
  {
    if (!zUtilitiesOptions->AlternativeDialogueBoxes || _this != oCInformationManager::GetInformationManager().DlgChoice)
    {
      Hook_zCViewPrint_BlitTextCharacters(_this, a1, a2, a3);
      return;
    }

    int vx = _this->VirtualSize.X / 2 - screen->FontSize(a1->Text) / 2;
    int px = screen->nax(vx);
    a1->PixelPosition.X = px;

    bool offLimits = _this->VirtualSize.Y - _this->SizeMargin[0].Y - _this->SizeMargin[1].Y - screen->FontY() * (_this->ListTextLines.GetNumInList() + 1) < 0;
    if (!offLimits)
    {
      int vy = _this->VirtualSize.Y / 2 - screen->FontY() / 2 * _this->ListTextLines.GetNumInList();
      vy += screen->FontY() * choiceTextLine;
      choiceTextLine++;

      int py = screen->nay(vy);
      a1->PixelPosition.Y = py;
    }

    Hook_zCViewPrint_BlitTextCharacters(_this, a1, a2, a3);
  }

  void __fastcall zCView_DialogMessageCXY(zCView *_this, void *vtable, zSTRING const &a1, zSTRING const &a2, float a3, struct zCOLOR &a4);
  auto Hook_zCView_DialogMessageCXY = CreateHook(reinterpret_cast<void *>(zSwitch(0x006FF6B0, 0x00739C70, 0x00749740, 0x007A9240)), &zCView_DialogMessageCXY);
  void __fastcall zCView_DialogMessageCXY(zCView *_this, void *vtable, zSTRING const &a1, zSTRING const &a2, float a3, struct zCOLOR &a4)
  {
    if (!zUtilitiesOptions->AlternativeDialogueBoxes || !PlayerHelper::IsInInfo())
    {
      Hook_zCView_DialogMessageCXY(_this, vtable, a1, a2, a3, a4);
      return;
    }

    if (_this->vposy < 2048)
    {
      _this->SetPos(0, 0);
      _this->SetSize(8192, _this->vsizey);
    }

    Hook_zCView_DialogMessageCXY(_this, vtable, a1, a2, a3, a4);
  }
}