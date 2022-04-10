// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int DamagePopupMode, DamagePopupShowIcons, DamagePopupColorDmgTypes, DamagePopupColorOnlyIcon;
    float DamagePopupScale;

    void DamagePopup() {
      DamagePopupMode = zoptions->ReadInt( PLUGIN_NAME, "DamagePopupMode", 1 );
      DamagePopupScale = zoptions->ReadReal( PLUGIN_NAME, "DamagePopupScale", 1.1f );
      DamagePopupShowIcons = zoptions->ReadBool( PLUGIN_NAME, "DamagePopupShowIcons", true );
      DamagePopupColorDmgTypes = zoptions->ReadBool( PLUGIN_NAME, "DamagePopupColorDmgTypes", true );
      DamagePopupColorOnlyIcon = zoptions->ReadBool( PLUGIN_NAME, "DamagePopupColorOnlyIcon", false );
    }
  }

  class DamagePopup {
  private:
    const float timeLimitInSecs = 3.0f;
    const float prolongationInSecs = 1.5f;

    float horizontalMoveDist;
    float horizontalMoveTime;
    float verticalMoveDist;
    float anchorStartPosMultiplier;

    zVEC3 anchorPos;
    zVEC3 offset;
    tagRECT vpPos;
    zVEC2 vpOffset;
    float creationTimeInSecs;
    float lastAnchorUpdate;
    float currentLifetimeLimit;

    oCNpc::oSDamageDescriptor* desc;
    oCNpc* target;
    bool isCrit;
    int mode;
    int dmgAmount;
    int dmgIndex;
    zSTRING icon;
    zCOLOR color = zCOLOR( 240, 220, 194 );
    float alpha = 255.0f;
    float scale;

    int GetTopDmgIndex();
    void SetMoveMode();
    void SetColor();
    void SetIcon();
    void SetScale();
    float GetRandomDist( float start, int random, bool invertable );
    bool WorldToView( const zVEC3& worldPos, zCView* view, zVEC2& pos );
    float Scale( float p, float max );
    void CalcOffset( float lifetime );
    void CalcViewport( zSTRING& text, zCView* view, zVEC2 viewPos, const zVEC2& scaling );
    void Print( zCView* view, const zVEC3& pos, const zVEC2& scaling );

  public:
    enum PopupMode {
      Disabled,
      AlterDamage,
      NewWorld
    };

    void Update();
    DamagePopup( oCNpc* targetNpc, oCNpc::oSDamageDescriptor& desc, int dmgAmount, bool isCrit );
    ~DamagePopup();
  };
}