// Supported with union (c) 2018 Union team

#ifndef __ZPARSER_H__VER2__
#define __ZPARSER_H__VER2__

#include "zParser_Symbol.h"
#include "zDisk.h"

namespace Gothic_II_Classic {
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

    void zCPar_TreeNode_OnInit()                                                   zCall( 0x00737F40 );
    void zCPar_TreeNode_OnInit( int, int )                                         zCall( 0x00737F80 );
    void zCPar_TreeNode_OnInit( int, zSTRING&, int )                               zCall( 0x00737FD0 );
    zCPar_TreeNode()                                                               zInit( zCPar_TreeNode_OnInit() );
    zCPar_TreeNode( int a0, int a1 )                                               zInit( zCPar_TreeNode_OnInit( a0, a1 ));
    zCPar_TreeNode( int a0, zSTRING& a1, int a2 )                                  zInit( zCPar_TreeNode_OnInit( a0, a1, a2 ));
    ~zCPar_TreeNode()                                                              zCall( 0x00738160 );
    void SetLeft( zCPar_TreeNode* )                                                zCall( 0x00738220 );
    void SetRight( zCPar_TreeNode* )                                               zCall( 0x00738230 );
    void SetNext( zCPar_TreeNode* )                                                zCall( 0x00738240 );
    static zCPar_TreeNode* SeekEndTree( zCPar_TreeNode* )                          zCall( 0x00738250 );
    static zCPar_TreeNode* MakeDyadicNode( zCPar_TreeNode*, int, zCPar_TreeNode* ) zCall( 0x00738270 );
    static zCPar_TreeNode* MakeMonadicNode( int, zCPar_TreeNode* )                 zCall( 0x007382E0 );

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

    void zCPar_File_OnInit()                         zCall( 0x0072D5E0 );
    zCPar_File()                                     zInit( zCPar_File_OnInit() );
    ~zCPar_File()                                    zCall( 0x0072D610 );
    int IsNewerDate( zDATE&, zDATE& )                zCall( 0x0072D6B0 );
    int IsExactDate( zDATE&, zDATE& )                zCall( 0x0072D730 );
    void SetFileNumber( int )                        zCall( 0x0072D7B0 );
    int GetFileNumber()                              zCall( 0x0072D7C0 );
    zSTRING GetName()                                zCall( 0x0072D7D0 );
    void EnableTreeLoad( int )                       zCall( 0x0072D820 );
    int Load( zSTRING&, zCPar_SymbolTable&, zDATE& ) zCall( 0x0072D830 );
    char* GetStartAddress()                          zCall( 0x0072DAB0 );
    char* GetEndAddress()                            zCall( 0x0072DAC0 );
    void Dispose()                                   zCall( 0x0072DAD0 );
    void SetTree( zCPar_TreeNode* )                  zCall( 0x0072DAF0 );
    zCPar_TreeNode* GetTree()                        zCall( 0x0072DB30 );
    void SetLabelCount( int )                        zCall( 0x0072DB40 );
    int GetLabelCount()                              zCall( 0x0072DB50 );
    void SaveTree( int, zCPar_Symbol*, zDATE& )      zCall( 0x0072DB60 );
    void SaveTreeNode( zFILE*, zCPar_TreeNode* )     zCall( 0x0072DDE0 );
    zCPar_TreeNode* LoadTreeNode( zFILE* )           zCall( 0x0072DF50 );
    int LoadTree( zFILE_STATS&, zCPar_SymbolTable& ) zCall( 0x0072E080 );
    void DeleteTree()                                zCall( 0x0072E450 );

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
    void zCParser_OnInit( int )                                                     zCall( 0x0072E490 );
    zCParser( int a0 )                                                              zInit( zCParser_OnInit( a0 ));
    ~zCParser()                                                                     zCall( 0x0072E5B0 );
    void SetMessageFunc( void( __cdecl* )( zSTRING ))                               zCall( 0x0072E810 );
    void SetStopOnError( int )                                                      zCall( 0x0072E820 );
    void Error( zSTRING&, int )                                                     zCall( 0x0072E830 );
    void Message( zSTRING& )                                                        zCall( 0x0072EBB0 );
    int Error()                                                                     zCall( 0x0072ECF0 );
    int SaveDat( zSTRING& )                                                         zCall( 0x0072ED00 );
    int LoadDat( zSTRING& )                                                         zCall( 0x0072EEC0 );
    int Parse( zSTRING )                                                            zCall( 0x0072F160 );
    int ParseSource( zSTRING& )                                                     zCall( 0x0072F3E0 );
    int ParseFile( zSTRING& )                                                       zCall( 0x0072FC20 );
    void ParseBlock()                                                               zCall( 0x007303F0 );
    void CreatePCode()                                                              zCall( 0x007306A0 );
    void ShowSymbols()                                                              zCall( 0x00730DD0 );
    void PushTree( zCPar_TreeNode* )                                                zCall( 0x00730DE0 );
    zCPar_TreeNode* PushOnStack( zCPar_TreeNode* )                                  zCall( 0x00730E00 );
    void SolveLabels( zCPar_TreeNode* )                                             zCall( 0x00731BB0 );
    int MergeFile( zSTRING& )                                                       zCall( 0x00731C10 );
    int PopDataValue()                                                              zCall( 0x00731E70 );
    float PopFloatValue()                                                           zCall( 0x00731EA0 );
    int* PopVarAddress()                                                            zCall( 0x00731ED0 );
    zSTRING* PopString()                                                            zCall( 0x00731F00 );
    void DoStack( int )                                                             zCall( 0x00731F20 );
    void* CallFunc( zSTRING const& )                                                zCall( 0x00732F90 );
    void* __cdecl CallFunc( int, ... )                                              zCall( 0x00732FB0 );
    int GetCurrentFunc()                                                            zCall( 0x007334D0 );
    int CreateInstance( zSTRING&, void* )                                           zCall( 0x007334E0 );
    int CreateInstance( int, void* )                                                zCall( 0x00733560 );
    int CreatePrototype( zSTRING&, void* )                                          zCall( 0x007335D0 );
    int CreatePrototype( int, void* )                                               zCall( 0x00733650 );
    void Reset()                                                                    zCall( 0x007336C0 );
    void SetPercentDone( int )                                                      zCall( 0x00733830 );
    void CreateHelpers()                                                            zCall( 0x00733890 );
    void EnableTreeSave( int )                                                      zCall( 0x00733A00 );
    void EnableDatSave( int )                                                       zCall( 0x00733A10 );
    void EnableTreeLoad( int )                                                      zCall( 0x00733A20 );
    int GetIndex( zSTRING const& )                                                  zCall( 0x00733A30 );
    int MatchClass( int, zSTRING const& )                                           zCall( 0x00733AF0 );
    int GetBaseClass( zCPar_Symbol* )                                               zCall( 0x00733B70 );
    int GetBaseClass( int )                                                         zCall( 0x00733BD0 );
    int GetBase( int )                                                              zCall( 0x00733C30 );
    int GetPrototype( int, int )                                                    zCall( 0x00733C80 );
    int GetInstance( int, int )                                                     zCall( 0x00733CF0 );
    zSTRING GetSymbolInfo( int, int&, int& )                                        zCall( 0x00733DB0 );
    zCPar_Symbol* GetSymbolInfo( int )                                              zCall( 0x00733E70 );
    zCPar_Symbol* GetSymbol( int )                                                  zCall( 0x00733E80 );
    zCPar_Symbol* GetSymbol( zSTRING const& )                                       zCall( 0x00733E90 );
    zSTRING GetClassVarInfo( int, int, int&, int& )                                 zCall( 0x00733F50 );
    void GetClassVarInfo( int, zSTRING&, int&, int& )                               zCall( 0x00734170 );
    zSTRING GetText( zSTRING&, int )                                                zCall( 0x00734330 );
    zSTRING GetText( int, int )                                                     zCall( 0x00734370 );
    int GetInt( int, int )                                                          zCall( 0x00734450 );
    zSTRING GetInstanceValue( zSTRING&, int, void*, int )                           zCall( 0x007344A0 );
    zSTRING GetInstanceValue( int, int, void*, int )                                zCall( 0x00734590 );
    int IsValid( zSTRING&, void*, zSTRING& )                                        zCall( 0x007348A0 );
    int CheckClassSize( zSTRING&, int )                                             zCall( 0x00734A10 );
    int CheckClassSize( int, int )                                                  zCall( 0x00734A30 );
    void AddClassOffset( zSTRING&, int )                                            zCall( 0x00734CF0 );
    int SetInstance( zSTRING const&, void* )                                        zCall( 0x00734E30 );
    int SetInstance( int, void* )                                                   zCall( 0x00734ED0 );
    int AutoCompletion( zSTRING& )                                                  zCall( 0x00734F10 );
    int GetNumFiles()                                                               zCall( 0x00735120 );
    zSTRING GetFileName( int )                                                      zCall( 0x00735130 );
    int IsStackFull()                                                               zCall( 0x007351D0 );
    int GetLastErrorLine()                                                          zCall( 0x007351E0 );
    void Reparse( zSTRING& )                                                        zCall( 0x007351F0 );
    int SaveInstance( zSTRING&, void* )                                             zCall( 0x00735300 );
    int SaveInstance( int, void* )                                                  zCall( 0x00735330 );
    void CloseViews()                                                               zCall( 0x00735FF0 );
    void ShowCode( int )                                                            zCall( 0x00736020 );
    void SaveInfoFile( zSTRING )                                                    zCall( 0x00736170 );
    void SetInfoFile( zCList<zSTRING>*, zSTRING const& )                            zCall( 0x007367C0 );
    int IsInAdditionalInfo( zSTRING const& )                                        zCall( 0x00736950 );
    int WriteAdditionalInfo( zSTRING&, int, int )                                   zCall( 0x00736B00 );
    int ClearAllInstanceRefs()                                                      zCall( 0x00736E90 );
    int ClearInstanceRefs( void* )                                                  zCall( 0x00736F00 );
    int ResetGlobalVars()                                                           zCall( 0x00736F80 );
    void CreateVarReferenceList( zSTRING const&, zCArray<int>& )                    zCall( 0x00737000 );
    void ResetWithVarReferenceList( zCArray<int>&, void* )                          zCall( 0x00737180 );
    int SaveGlobalVars( zCArchiver& )                                               zCall( 0x00737200 );
    int LoadGlobalVars( zCArchiver& )                                               zCall( 0x00737730 );
    void GetOperatorString( int, zSTRING& )                                         zCall( 0x00738340 );
    void FindNext( char* )                                                          zCall( 0x007388D0 );
    void PrevWord()                                                                 zCall( 0x00738A40 );
    void ReadWord( zSTRING& )                                                       zCall( 0x00738A70 );
    void Match( zSTRING& )                                                          zCall( 0x00738CE0 );
    int ReadVarType()                                                               zCall( 0x00738E70 );
    int ReadFuncType()                                                              zCall( 0x007390A0 );
    int ReadInt()                                                                   zCall( 0x007392C0 );
    float ReadFloat()                                                               zCall( 0x00739560 );
    void ReadString( zSTRING& )                                                     zCall( 0x007398A0 );
    int ReadArray()                                                                 zCall( 0x00739B80 );
    zCPar_TreeNode* CreateLeaf( int, zCPar_TreeNode* )                              zCall( 0x00739D80 );
    zCPar_TreeNode* CreateStringLeaf()                                              zCall( 0x00739DE0 );
    zCPar_TreeNode* CreateFloatLeaf()                                               zCall( 0x0073A030 );
    int GetNextToken()                                                              zCall( 0x0073A1D0 );
    zCPar_TreeNode* Parse_Expression_Primary( int& )                                zCall( 0x0073A950 );
    zCPar_TreeNode* Parse_Expression( int&, int )                                   zCall( 0x0073AF00 );
    zCPar_TreeNode* ParseExpressionEx( zSTRING& )                                   zCall( 0x0073B110 );
    zCPar_TreeNode* ParseExpression()                                               zCall( 0x0073B180 );
    int EvalLeaf( zCPar_TreeNode*, int )                                            zCall( 0x0073B1A0 );
    void DeclareVar( int )                                                          zCall( 0x0073B660 );
    void DeclareClass()                                                             zCall( 0x0073C990 );
    void DeclareInstance()                                                          zCall( 0x0073CB60 );
    void DeclarePrototype()                                                         zCall( 0x0073D340 );
    void DeclareIf()                                                                zCall( 0x0073D830 );
    void DeclareAssign( zSTRING& )                                                  zCall( 0x0073DC90 );
    void DeclareAssignFunc( zSTRING& )                                              zCall( 0x0073E410 );
    void DeclareFunc()                                                              zCall( 0x0073E700 );
    void DeclareReturn()                                                            zCall( 0x0073EB90 );
    void DeclareFuncCall( zSTRING&, int )                                           zCall( 0x0073ED70 );
    zCPar_Symbol* SearchFuncWithStartAddress( int )                                 zCall( 0x0073F740 );
    void GetNextCommand( zSTRING& )                                                 zCall( 0x0073F7B0 );
    void ShowPCodeSpy( zSTRING& )                                                   zCall( 0x007403D0 );
    void ShowPCode( int, zCView*, int )                                             zCall( 0x00740500 );
    void __cdecl DefineExternal( zSTRING const&, int( __cdecl* )(), int, int, ... ) zCall( 0x00740750 );
    void DefineExternalVar( zSTRING const&, void*, int, int )                       zCall( 0x00740B10 );
    void GetParameter( int& )                                                       zCall( 0x00740D20 );
    void GetParameter( float& )                                                     zCall( 0x00740D30 );
    void GetParameter( zSTRING& )                                                   zCall( 0x00740D70 );
    void* GetInstance()                                                             zCall( 0x00740EB0 );
    void* GetInstanceAndIndex( int& )                                               zCall( 0x00740EE0 );
    void SetReturn( int )                                                           zCall( 0x00740F20 );
    void SetReturn( float )                                                         zCall( 0x00740F40 );
    void SetReturn( void* )                                                         zCall( 0x00740F60 );
    void SetReturn( zSTRING& )                                                      zCall( 0x00740F90 );
    int FindInstanceVar( zSTRING& )                                                 zCall( 0x00740FB0 );
    int GetLastInstance()                                                           zCall( 0x00741190 );
    int FindIndex( zSTRING& )                                                       zCall( 0x007411A0 );
    void DoEvent( const zSTRING& eventName );
    int GetEventIndex( const zSTRING& eventName );
    static void SetVersion( unsigned char )                                         zCall( 0x0072D5C0 );
    static unsigned char GetVersion()                                               zCall( 0x0072D5D0 );
    static zCParser* GetParser()                                                    zCall( 0x0072E480 );

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

} // namespace Gothic_II_Classic

#endif // __ZPARSER_H__VER2__