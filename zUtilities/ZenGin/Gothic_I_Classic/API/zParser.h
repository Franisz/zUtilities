// Supported with union (c) 2018 Union team

#ifndef __ZPARSER_H__VER0__
#define __ZPARSER_H__VER0__

#include "zParser_Symbol.h"
#include "zDisk.h"

namespace Gothic_I_Classic {
  const int zPAR_INDEX_UNDEF = -1;

  class zCPar_TreeNode {
  public:
    zSTRING name;
    unsigned char token;
    union {
      int value;
      float fvalue;
    };

    int info;
    zCPar_TreeNode* left;
    zCPar_TreeNode* right;
    zCPar_TreeNode* next;
    int cNr;

    void zCPar_TreeNode_OnInit()                                                   zCall( 0x006EDE40 );
    void zCPar_TreeNode_OnInit( int, int )                                         zCall( 0x006EDE80 );
    void zCPar_TreeNode_OnInit( int, zSTRING&, int )                               zCall( 0x006EDED0 );
    zCPar_TreeNode()                                                               zInit( zCPar_TreeNode_OnInit() );
    zCPar_TreeNode( int a0, int a1 )                                               zInit( zCPar_TreeNode_OnInit( a0, a1 ));
    zCPar_TreeNode( int a0, zSTRING& a1, int a2 )                                  zInit( zCPar_TreeNode_OnInit( a0, a1, a2 ));
    ~zCPar_TreeNode()                                                              zCall( 0x006EE060 );
    void SetLeft( zCPar_TreeNode* )                                                zCall( 0x006EE120 );
    void SetRight( zCPar_TreeNode* )                                               zCall( 0x006EE130 );
    void SetNext( zCPar_TreeNode* )                                                zCall( 0x006EE140 );
    static zCPar_TreeNode* SeekEndTree( zCPar_TreeNode* )                          zCall( 0x006EE150 );
    static zCPar_TreeNode* MakeDyadicNode( zCPar_TreeNode*, int, zCPar_TreeNode* ) zCall( 0x006EE170 );
    static zCPar_TreeNode* MakeMonadicNode( int, zCPar_TreeNode* )                 zCall( 0x006EE1F0 );

    // user API
    #include "zCPar_TreeNode.inl"
  };

  class zCPar_File {
  public:
    int fileid;
    zSTRING name;
    char* begin_adr;
    int size;
    int labels;
    int treeload;
    zCPar_TreeNode* tree;

    void zCPar_File_OnInit()                         zCall( 0x006E3DC0 );
    zCPar_File()                                     zInit( zCPar_File_OnInit() );
    ~zCPar_File()                                    zCall( 0x006E3DF0 );
    int IsNewerDate( zDATE&, zDATE& )                zCall( 0x006E3E90 );
    int IsExactDate( zDATE&, zDATE& )                zCall( 0x006E3F10 );
    void SetFileNumber( int )                        zCall( 0x006E3F90 );
    int GetFileNumber()                              zCall( 0x006E3FA0 );
    zSTRING GetName()                                zCall( 0x006E3FB0 );
    void EnableTreeLoad( int )                       zCall( 0x006E4000 );
    int Load( zSTRING&, zCPar_SymbolTable&, zDATE& ) zCall( 0x006E4010 );
    char* GetStartAddress()                          zCall( 0x006E42A0 );
    char* GetEndAddress()                            zCall( 0x006E42B0 );
    void Dispose()                                   zCall( 0x006E42C0 );
    void SetTree( zCPar_TreeNode* )                  zCall( 0x006E42E0 );
    zCPar_TreeNode* GetTree()                        zCall( 0x006E4320 );
    void SetLabelCount( int )                        zCall( 0x006E4330 );
    int GetLabelCount()                              zCall( 0x006E4340 );
    void SaveTree( int, zCPar_Symbol*, zDATE& )      zCall( 0x006E4350 );
    void SaveTreeNode( zFILE*, zCPar_TreeNode* )     zCall( 0x006E45D0 );
    zCPar_TreeNode* LoadTreeNode( zFILE* )           zCall( 0x006E4740 );
    int LoadTree( zFILE_STATS&, zCPar_SymbolTable& ) zCall( 0x006E4880 );
    void DeleteTree()                                zCall( 0x006E4C60 );

    // user API
    #include "zCPar_File.inl"
  };

  class zCParser {
  public:
    void( *msgfunc )( zSTRING );
    zCArray<zCPar_File*> file;
    zCPar_SymbolTable symtab;
    zCPar_StringTable stringtab;
    zCPar_Stack stack;
    zCPar_DataStack datastack;
    zCPar_Symbol* self;
    zSTRING fname;
    zSTRING mainfile;
    int compiled;
    int treesave;
    int datsave;
    int parse_changed;
    int treeload;
    int mergemode;
    int linkingnr;
    int linec;
    int line_start;
    int ext_parse;
    char* pc_start;
    char* pc;
    char* oldpc;
    char* pc_stop;
    char* oldpc_stop;
    int params;
    int in_funcnr;
    int in_classnr;
    int stringcount;
    zCPar_Symbol* in_func;
    zCPar_Symbol* in_class;
    int error;
    int stop_on_error;
    int errorline;
    char* prevword_index[16];
    int prevline_index[16];
    int prevword_nr;
    zSTRING aword;
    int instance;
    int instance_help;
    zCViewProgressBar* progressBar;
    zCPar_TreeNode* tree;
    zCPar_TreeNode* treenode;
    zCView* win_code;
    int debugmode;
    int curfuncnr;
    int labelcount;
    int* labelpos;
    zCList<zSTRING>* add_funclist;
    zSTRING add_filename;
    int add_created;

    zCParser() {}
    void zCParser_OnInit( int )                                                     zCall( 0x006E4CA0 );
    zCParser( int a0 )                                                              zInit( zCParser_OnInit( a0 ));
    ~zCParser()                                                                     zCall( 0x006E4DC0 );
    void SetMessageFunc( void( __cdecl* )( zSTRING ))                               zCall( 0x006E5020 );
    void SetStopOnError( int )                                                      zCall( 0x006E5030 );
    void Error( zSTRING&, int )                                                     zCall( 0x006E5040 );
    void Message( zSTRING& )                                                        zCall( 0x006E5370 );
    int Error()                                                                     zCall( 0x006E54B0 );
    int SaveDat( zSTRING& )                                                         zCall( 0x006E54C0 );
    int LoadDat( zSTRING& )                                                         zCall( 0x006E5680 );
    int Parse( zSTRING )                                                            zCall( 0x006E5920 );
    int ParseSource( zSTRING& )                                                     zCall( 0x006E5BA0 );
    int ParseFile( zSTRING& )                                                       zCall( 0x006E63E0 );
    void ParseBlock()                                                               zCall( 0x006E6C00 );
    void CreatePCode()                                                              zCall( 0x006E6EB0 );
    void ShowSymbols()                                                              zCall( 0x006E7570 );
    void PushTree( zCPar_TreeNode* )                                                zCall( 0x006E7580 );
    zCPar_TreeNode* PushOnStack( zCPar_TreeNode* )                                  zCall( 0x006E75A0 );
    void SolveLabels( zCPar_TreeNode* )                                             zCall( 0x006E8290 );
    int MergeFile( zSTRING& )                                                       zCall( 0x006E82F0 );
    int PopDataValue()                                                              zCall( 0x006E8550 );
    float PopFloatValue()                                                           zCall( 0x006E8580 );
    int* PopVarAddress()                                                            zCall( 0x006E85B0 );
    zSTRING* PopString()                                                            zCall( 0x006E85E0 );
    void DoStack( int )                                                             zCall( 0x006E8600 );
    void* CallFunc( zSTRING const& )                                                zCall( 0x006E9670 );
    void* __cdecl CallFunc( int, ... )                                              zCall( 0x006E9690 );
    int GetCurrentFunc()                                                            zCall( 0x006E9B50 );
    int CreateInstance( zSTRING&, void* )                                           zCall( 0x006E9B60 );
    int CreateInstance( int, void* )                                                zCall( 0x006E9BE0 );
    int CreatePrototype( zSTRING&, void* )                                          zCall( 0x006E9C50 );
    int CreatePrototype( int, void* )                                               zCall( 0x006E9CD0 );
    void Reset()                                                                    zCall( 0x006E9D40 );
    void SetPercentDone( int )                                                      zCall( 0x006E9EB0 );
    void CreateHelpers()                                                            zCall( 0x006E9F10 );
    void EnableTreeSave( int )                                                      zCall( 0x006EA090 );
    void EnableDatSave( int )                                                       zCall( 0x006EA0A0 );
    void EnableTreeLoad( int )                                                      zCall( 0x006EA0B0 );
    int GetIndex( zSTRING const& )                                                  zCall( 0x006EA0C0 );
    int MatchClass( int, zSTRING const& )                                           zCall( 0x006EA180 );
    int GetBaseClass( zCPar_Symbol* )                                               zCall( 0x006EA200 );
    int GetBaseClass( int )                                                         zCall( 0x006EA260 );
    int GetBase( int )                                                              zCall( 0x006EA2C0 );
    int GetPrototype( int, int )                                                    zCall( 0x006EA310 );
    int GetInstance( int, int )                                                     zCall( 0x006EA380 );
    zSTRING GetSymbolInfo( int, int&, int& )                                        zCall( 0x006EA440 );
    zCPar_Symbol* GetSymbolInfo( int )                                              zCall( 0x006EA500 );
    zCPar_Symbol* GetSymbol( int )                                                  zCall( 0x006EA510 );
    zCPar_Symbol* GetSymbol( zSTRING const& )                                       zCall( 0x006EA520 );
    zSTRING GetClassVarInfo( int, int, int&, int& )                                 zCall( 0x006EA5E0 );
    void GetClassVarInfo( int, zSTRING&, int&, int& )                               zCall( 0x006EA800 );
    zSTRING GetText( zSTRING&, int )                                                zCall( 0x006EA9C0 );
    zSTRING GetText( int, int )                                                     zCall( 0x006EAA00 );
    int GetInt( int, int )                                                          zCall( 0x006EAAE0 );
    zSTRING GetInstanceValue( zSTRING&, int, void*, int )                           zCall( 0x006EAB30 );
    zSTRING GetInstanceValue( int, int, void*, int )                                zCall( 0x006EAC20 );
    int IsValid( zSTRING&, void*, zSTRING& )                                        zCall( 0x006EAE80 );
    int CheckClassSize( zSTRING&, int )                                             zCall( 0x006EAFF0 );
    int CheckClassSize( int, int )                                                  zCall( 0x006EB010 );
    void AddClassOffset( zSTRING&, int )                                            zCall( 0x006EB280 );
    int SetInstance( zSTRING const&, void* )                                        zCall( 0x006EB3C0 );
    int SetInstance( int, void* )                                                   zCall( 0x006EB400 );
    int AutoCompletion( zSTRING& )                                                  zCall( 0x006EB440 );
    int GetNumFiles()                                                               zCall( 0x006EB650 );
    zSTRING GetFileName( int )                                                      zCall( 0x006EB660 );
    int IsStackFull()                                                               zCall( 0x006EB700 );
    int GetLastErrorLine()                                                          zCall( 0x006EB710 );
    void Reparse( zSTRING& )                                                        zCall( 0x006EB720 );
    int SaveInstance( zSTRING&, void* )                                             zCall( 0x006EB830 );
    int SaveInstance( int, void* )                                                  zCall( 0x006EB860 );
    void CloseViews()                                                               zCall( 0x006EC420 );
    void ShowCode( int )                                                            zCall( 0x006EC450 );
    void SaveInfoFile( zSTRING )                                                    zCall( 0x006EC5B0 );
    void SetInfoFile( zCList<zSTRING>*, zSTRING const& )                            zCall( 0x006ECBF0 );
    int IsInAdditionalInfo( zSTRING const& )                                        zCall( 0x006ECD80 );
    int WriteAdditionalInfo( zSTRING&, int, int )                                   zCall( 0x006ECF30 );
    int ClearAllInstanceRefs()                                                      zCall( 0x006ED250 );
    int ClearInstanceRefs( void* )                                                  zCall( 0x006ED2C0 );
    int ResetGlobalVars()                                                           zCall( 0x006ED340 );
    void CreateVarReferenceList( zSTRING const&, zCArray<int>& )                    zCall( 0x006ED3A0 );
    void ResetWithVarReferenceList( zCArray<int>&, void* )                          zCall( 0x006ED540 );
    int SaveGlobalVars( zCArchiver& )                                               zCall( 0x006ED5C0 );
    int LoadGlobalVars( zCArchiver& )                                               zCall( 0x006ED8C0 );
    void GetOperatorString( int, zSTRING& )                                         zCall( 0x006EE260 );
    void FindNext( char* )                                                          zCall( 0x006EE7F0 );
    void PrevWord()                                                                 zCall( 0x006EE960 );
    void ReadWord( zSTRING& )                                                       zCall( 0x006EE990 );
    void Match( zSTRING& )                                                          zCall( 0x006EEC00 );
    int ReadVarType()                                                               zCall( 0x006EED90 );
    int ReadFuncType()                                                              zCall( 0x006EEFC0 );
    int ReadInt()                                                                   zCall( 0x006EF1E0 );
    float ReadFloat()                                                               zCall( 0x006EF480 );
    void ReadString( zSTRING& )                                                     zCall( 0x006EF780 );
    int ReadArray()                                                                 zCall( 0x006EFA60 );
    zCPar_TreeNode* CreateLeaf( int, zCPar_TreeNode* )                              zCall( 0x006EFC60 );
    zCPar_TreeNode* CreateStringLeaf()                                              zCall( 0x006EFCD0 );
    zCPar_TreeNode* CreateFloatLeaf()                                               zCall( 0x006EFF30 );
    int GetNextToken()                                                              zCall( 0x006F00D0 );
    zCPar_TreeNode* Parse_Expression_Primary( int& )                                zCall( 0x006F0850 );
    zCPar_TreeNode* Parse_Expression( int&, int )                                   zCall( 0x006F0E80 );
    zCPar_TreeNode* ParseExpressionEx( zSTRING& )                                   zCall( 0x006F10A0 );
    zCPar_TreeNode* ParseExpression()                                               zCall( 0x006F1110 );
    int EvalLeaf( zCPar_TreeNode*, int )                                            zCall( 0x006F1130 );
    void DeclareVar( int )                                                          zCall( 0x006F15F0 );
    void DeclareClass()                                                             zCall( 0x006F2AB0 );
    void DeclareInstance()                                                          zCall( 0x006F2C90 );
    void DeclarePrototype()                                                         zCall( 0x006F34C0 );
    void DeclareIf()                                                                zCall( 0x006F39D0 );
    void DeclareAssign( zSTRING& )                                                  zCall( 0x006F3E40 );
    void DeclareAssignFunc( zSTRING& )                                              zCall( 0x006F45E0 );
    void DeclareFunc()                                                              zCall( 0x006F48E0 );
    void DeclareReturn()                                                            zCall( 0x006F4D90 );
    void DeclareFuncCall( zSTRING&, int )                                           zCall( 0x006F4F80 );
    zCPar_Symbol* SearchFuncWithStartAddress( int )                                 zCall( 0x006F5970 );
    void GetNextCommand( zSTRING& )                                                 zCall( 0x006F59E0 );
    void ShowPCodeSpy( zSTRING& )                                                   zCall( 0x006F64C0 );
    void ShowPCode( int, zCView*, int )                                             zCall( 0x006F65F0 );
    void __cdecl DefineExternal( zSTRING const&, int( __cdecl* )(), int, int, ... ) zCall( 0x006F6840 );
    void DefineExternalVar( zSTRING const&, void*, int, int )                       zCall( 0x006F6BD0 );
    void GetParameter( int& )                                                       zCall( 0x006F6DF0 );
    void GetParameter( float& )                                                     zCall( 0x006F6E00 );
    void GetParameter( zSTRING& )                                                   zCall( 0x006F6E40 );
    void* GetInstance()                                                             zCall( 0x006F6F80 );
    void SetReturn( int )                                                           zCall( 0x006F6FB0 );
    void SetReturn( float )                                                         zCall( 0x006F6FD0 );
    void SetReturn( void* )                                                         zCall( 0x006F6FF0 );
    void SetReturn( zSTRING& )                                                      zCall( 0x006F7020 );
    int FindInstanceVar( zSTRING& )                                                 zCall( 0x006F7040 );
    int GetLastInstance()                                                           zCall( 0x006F7220 );
    int FindIndex( zSTRING& )                                                       zCall( 0x006F7230 );
    void DoEvent( const zSTRING& eventName );
    int GetEventIndex( const zSTRING& eventName );
    static void SetVersion( unsigned char )                                         zCall( 0x006E3DA0 );
    static unsigned char GetVersion()                                               zCall( 0x006E3DB0 );
    static zCParser* GetParser()                                                    zCall( 0x006E4C90 );

    // static properties
    static int& enableParsing;
    static zCParser*& cur_parser;

    // user API
    #include "zCParser.inl"
  };

  inline void zCParser::DoEvent( const zSTRING& eventName ) {
    int index = GetEventIndex( eventName );
    if( index == Invalid )
      return;

    int indexSort = symtab.tablesort.Search( index );
    while( true ) {
      index = symtab.tablesort[++indexSort];
      zCPar_Symbol* sym = GetSymbol( index );
      if( sym == Null )
        break;

      if( !sym->name.HasWord( "EVENT." + eventName + "." ) )
        break;

      CallFunc( index );
    }
  }

  inline int zCParser::GetEventIndex( const zSTRING& eventName ) {
    int index = GetIndex( "EVENT." + eventName + ".START" );
    return index;
  }

} // namespace Gothic_I_Classic

#endif // __ZPARSER_H__VER0__