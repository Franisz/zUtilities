// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#define VERSION_NUMBER "0.13"
#define pluginName "ZUTILITIES"
#define printWin(a) ogame->GetTextView()->Printwin(a)

  int bColorNpcs, bColorChests, bColorDoors, bColorItems, bUseQuickSave, bTrampleMeatbugs, bRenderInvItems, bLabelItems, bPutLabelBehind, bDamagePopupShowIcons, bDamagePopupColorDmgTypes, bDamagePopupColorOnlyIcon;
  float fLabelScale, fDamagePopupScale;
  int iDamagePopupMode;

  void InitOptions() {
    bColorNpcs = zoptions->ReadInt( pluginName, "bColorNpcs", true );
    bColorChests = zoptions->ReadInt( pluginName, "bColorChests", true );
    bColorDoors = zoptions->ReadInt( pluginName, "bColorDoors", true );
    bColorItems = zoptions->ReadInt( pluginName, "bColorItems", true );
    bUseQuickSave = zoptions->ReadInt( pluginName, "bUseQuickSave", true );
    bTrampleMeatbugs = zoptions->ReadInt( pluginName, "bTrampleMeatbugs", true );
    bRenderInvItems = zoptions->ReadInt( pluginName, "bRenderInvItems", true );

    // ItemLabel
    bLabelItems = zoptions->ReadInt( pluginName, "bLabelItems", true );
    bPutLabelBehind = zoptions->ReadInt( pluginName, "bPutLabelBehind", false );
    fLabelScale = zoptions->ReadReal( pluginName, "fLabelScale", 1.25f );

    // DamagePopup
    iDamagePopupMode = zoptions->ReadInt( pluginName, "iDamagePopupMode", DamagePopup::PopupMode::AlterDamage );
    fDamagePopupScale = zoptions->ReadReal( pluginName, "fDamagePopupScale", 1.1f );
    bDamagePopupShowIcons = zoptions->ReadInt( pluginName, "bDamagePopupShowIcons", true );
    bDamagePopupColorDmgTypes = zoptions->ReadInt( pluginName, "bDamagePopupColorDmgTypes", true );
    bDamagePopupColorOnlyIcon = zoptions->ReadInt( pluginName, "bDamagePopupColorOnlyIcon", false );
  }

}