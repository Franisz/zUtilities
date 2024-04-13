// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int choiceTextLine = 0;

  HOOK Hook_zCViewPrint_Blit PATCH( &zCViewPrint::Blit, &zCViewPrint::Blit_Union );
  void zCViewPrint::Blit_Union() {
    if ( !Options::AlternativeDialogueBoxes || this != oCInformationManager::GetInformationManager().DlgChoice ) {
      THISCALL( Hook_zCViewPrint_Blit )();
      return;
    }

    if ( VirtualPosition.X != 0 ) {
      VirtualPosition.X = 0;
      SetVirtualPosition( VirtualPosition );
    }

    if ( VirtualSize.X != 8192 ) {
      VirtualSize.X = 8192;
      SetVirtualSize( VirtualSize );
    }

    choiceTextLine = 0;

    THISCALL( Hook_zCViewPrint_Blit )();
  }

  HOOK Hook_zCViewPrint_BlitTextCharacters PATCH( &zCViewPrint::BlitTextCharacters, &zCViewPrint::BlitTextCharacters_Union );
  void zCViewPrint::BlitTextCharacters_Union( zCViewText2* a1, zCFont* a2, zCOLOR& a3 ) {
    if ( !Options::AlternativeDialogueBoxes || this != oCInformationManager::GetInformationManager().DlgChoice ) {
      THISCALL( Hook_zCViewPrint_BlitTextCharacters )(a1, a2, a3);
      return;
    }

    int vx = VirtualSize.X / 2 - screen->FontSize( a1->Text ) / 2;
    int px = screen->nax( vx );
    a1->PixelPosition.X = px;

    bool offLimits = VirtualSize.Y - SizeMargin[0].Y - SizeMargin[1].Y - screen->FontY() * (ListTextLines.GetNumInList() + 1) < 0;
    if ( !offLimits ) {
      int vy = VirtualSize.Y / 2 - screen->FontY() / 2 * ListTextLines.GetNumInList();
      vy += screen->FontY() * choiceTextLine;
      choiceTextLine++;

      int py = screen->nay( vy );
      a1->PixelPosition.Y = py;
    }

    THISCALL( Hook_zCViewPrint_BlitTextCharacters )(a1, a2, a3);
  }

  HOOK Hook_zCView_DialogMessageCXY PATCH( &zCView::DialogMessageCXY, &zCView::DialogMessageCXY_Union );
  void zCView::DialogMessageCXY_Union( zSTRING const& a1, zSTRING const& a2, float a3, zCOLOR& a4 ) {
    if ( !Options::AlternativeDialogueBoxes || !playerHelper.IsInInfo() ) {
      THISCALL( Hook_zCView_DialogMessageCXY )(a1, a2, a3, a4);
      return;
    }

    if ( vposy < 2048 ) {
      SetPos( 0, 0 );
      SetSize( 8192, vsizey );
    }

    THISCALL( Hook_zCView_DialogMessageCXY )(a1, a2, a3, a4);
  }
}