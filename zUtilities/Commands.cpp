// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int (*innerEvalFunc)(const zSTRING&, zSTRING&);

  int GiveAllItems() {
      auto c_item = parser->GetIndex(oCItem::classDef->scriptClassName);
      if (c_item == -1) {
          return 0;
      }

      int itemsCreated = 0;
      for (int i = 0; i < parser->symtab.GetNumInList(); i++) {
          zCPar_Symbol* symbol = parser->symtab.table[i];

          if (symbol->type != zPAR_TYPE_INSTANCE) {
              continue;
          }

          //  Instance isn't global scope
          if (symbol->name.HasWord(".")) {
              continue;
          }

          auto baseClass = parser->GetBaseClass(symbol);

          // Symbol isn't a item class
          if (baseClass != c_item) {
              continue;
          }

          auto item = new oCItem(symbol->name, 1);
          if (item->HasFlag(ITM_FLAG_MULTI)) {
              item->amount = 50;
          }

          player->PutInInv(item);
          itemsCreated++;
      }

      return itemsCreated;
  }

  int ConsoleEvalFunc( const zSTRING& inpstr, zSTRING& msg ) {
    if ( innerEvalFunc && innerEvalFunc( inpstr, msg ) )
      return true;

    zSTRING w1 = inpstr.PickWord_Old( 1, " " );
    if ( w1 != "zUtilities" ) return false;

    zSTRING w2 = inpstr.PickWord_Old( 2, " " );
    if ( w2 == "Version" ) {
      msg = "Currently using zUtilities v" + Z VERSION_NUMBER;
      return true;
    }

    if ( w2 == "Debug" ) {
      Options::UsingDebugHelper = (Options::UsingDebugHelper) ? false : true;
      zSTRING state = (Options::UsingDebugHelper) ? "ON" : "OFF";
      msg = "zUtilites debug helper " + state;
      return true;
    }

    if (w2 == "GiveAllItems") {
        auto result = GiveAllItems();
        msg = "Created " + Z result + " instances.";

        return true;
    }

    return false;
  }

  void RegisterEvalFunc() {
    int evalNum = 0;

    for ( int i = 1; i < zCON_MAX_EVAL; i++ )
      if ( zcon->evalfunc[i] )
        evalNum = i;

    innerEvalFunc = zcon->evalfunc[evalNum];
    zcon->evalfunc[evalNum] = &ConsoleEvalFunc;
  }

  void RegisterCommands() {
    RegisterEvalFunc();
    zcon->Register( "zUtilities Version", "Shows version number" );
    zcon->Register( "zUtilities Debug", "Toggles debug mode" );
    zcon->Register( "zUtilities GiveAllItems", "Gives all items" );
  }
}