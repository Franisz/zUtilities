// Supported with union (c) 2018-2021 Union team

#ifndef __ZPARSER_H__VER1__
#define __ZPARSER_H__VER1__

#include "zParser_Symbol.h"
#include "zDisk.h"

namespace Gothic_I_Addon {
  const int zPAR_INDEX_UNDEF = -1;

  // sizeof 30h
  class zCPar_TreeNode {
  public:
    zSTRING name;          // sizeof 14h    offset 00h
    unsigned char token;   // sizeof 01h    offset 14h
    union {
      int value;
      float fvalue;
    };

    int info;              // sizeof 04h    offset 1Ch
    zCPar_TreeNode* left;  // sizeof 04h    offset 20h
    zCPar_TreeNode* right; // sizeof 04h    offset 24h
    zCPar_TreeNode* next;  // sizeof 04h    offset 28h
    int cNr;               // sizeof 04h    offset 2Ch

    void zCPar_TreeNode_OnInit()                                                   zCall( 0x00727490 );
    void zCPar_TreeNode_OnInit( int, int )                                         zCall( 0x007274D0 );
    void zCPar_TreeNode_OnInit( int, zSTRING&, int )                               zCall( 0x00727520 );
    zCPar_TreeNode()                                                               zInit( zCPar_TreeNode_OnInit() );
    zCPar_TreeNode( int a0, int a1 )                                               zInit( zCPar_TreeNode_OnInit( a0, a1 ));
    zCPar_TreeNode( int a0, zSTRING& a1, int a2 )                                  zInit( zCPar_TreeNode_OnInit( a0, a1, a2 ));
    ~zCPar_TreeNode()                                                              zCall( 0x007276A0 );
    void SetLeft( zCPar_TreeNode* )                                                zCall( 0x00727770 );
    void SetRight( zCPar_TreeNode* )                                               zCall( 0x00727780 );
    void SetNext( zCPar_TreeNode* )                                                zCall( 0x00727790 );
    static zCPar_TreeNode* SeekEndTree( zCPar_TreeNode* )                          zCall( 0x007277A0 );
    static zCPar_TreeNode* MakeDyadicNode( zCPar_TreeNode*, int, zCPar_TreeNode* ) zCall( 0x007277C0 );
    static zCPar_TreeNode* MakeMonadicNode( int, zCPar_TreeNode* )                 zCall( 0x00727840 );

    // user API
    #include "zCPar_TreeNode.inl"
  };

  // sizeof 2Ch
  class zCPar_File {
  public:
    int fileid;           // sizeof 04h    offset 00h
    zSTRING name;         // sizeof 14h    offset 04h
    char* begin_adr;      // sizeof 04h    offset 18h
    int size;             // sizeof 04h    offset 1Ch
    int labels;           // sizeof 04h    offset 20h
    int treeload;         // sizeof 04h    offset 24h
    zCPar_TreeNode* tree; // sizeof 04h    offset 28h

    void zCPar_File_OnInit()                         zCall( 0x0071C6A0 );
    zCPar_File()                                     zInit( zCPar_File_OnInit() );
    ~zCPar_File()                                    zCall( 0x0071C6D0 );
    int IsNewerDate( zDATE&, zDATE& )                zCall( 0x0071C780 );
    int IsExactDate( zDATE&, zDATE& )                zCall( 0x0071C820 );
    void SetFileNumber( int )                        zCall( 0x0071C8B0 );
    int GetFileNumber()                              zCall( 0x0071C8C0 );
    zSTRING GetName()                                zCall( 0x0071C8D0 );
    void EnableTreeLoad( int )                       zCall( 0x0071C920 );
    int Load( zSTRING&, zCPar_SymbolTable&, zDATE& ) zCall( 0x0071C930 );
    char* GetStartAddress()                          zCall( 0x0071CBB0 );
    char* GetEndAddress()                            zCall( 0x0071CBC0 );
    void Dispose()                                   zCall( 0x0071CBD0 );
    void SetTree( zCPar_TreeNode* )                  zCall( 0x0071CBF0 );
    zCPar_TreeNode* GetTree()                        zCall( 0x0071CC30 );
    void SetLabelCount( int )                        zCall( 0x0071CC40 );
    int GetLabelCount()                              zCall( 0x0071CC50 );
    void SaveTree( int, zCPar_Symbol*, zDATE& )      zCall( 0x0071CC60 );
    void SaveTreeNode( zFILE*, zCPar_TreeNode* )     zCall( 0x0071CF10 );
    zCPar_TreeNode* LoadTreeNode( zFILE* )           zCall( 0x0071D080 );
    int LoadTree( zFILE_STATS&, zCPar_SymbolTable& ) zCall( 0x0071D1C0 );
    void DeleteTree()                                zCall( 0x0071D630 );

    // user API
    #include "zCPar_File.inl"
  };

  // sizeof 11C4h
  class zCParser {
  public:
    void( *msgfunc )( zSTRING );    // sizeof 04h    offset 00h
    zCArray<zCPar_File*> file;      // sizeof 0Ch    offset 04h
    zCPar_SymbolTable symtab;       // sizeof 2Ch    offset 10h
    zCPar_StringTable stringtab;    // sizeof 0Ch    offset 3Ch
    zCPar_Stack stack;              // sizeof 10h    offset 48h
    zCPar_DataStack datastack;      // sizeof 1004h  offset 58h
    zCPar_Symbol* self;             // sizeof 04h    offset 105Ch
    zSTRING fname;                  // sizeof 14h    offset 1060h
    zSTRING mainfile;               // sizeof 14h    offset 1074h
    int compiled;                   // sizeof 04h    offset 1088h
    int treesave;                   // sizeof 04h    offset 108Ch
    int datsave;                    // sizeof 04h    offset 1090h
    int parse_changed;              // sizeof 04h    offset 1094h
    int treeload;                   // sizeof 04h    offset 1098h
    int mergemode;                  // sizeof 04h    offset 109Ch
    int linkingnr;                  // sizeof 04h    offset 10A0h
    int linec;                      // sizeof 04h    offset 10A4h
    int line_start;                 // sizeof 04h    offset 10A8h
    int ext_parse;                  // sizeof 04h    offset 10ACh
    char* pc_start;                 // sizeof 04h    offset 10B0h
    char* pc;                       // sizeof 04h    offset 10B4h
    char* oldpc;                    // sizeof 04h    offset 10B8h
    char* pc_stop;                  // sizeof 04h    offset 10BCh
    char* oldpc_stop;               // sizeof 04h    offset 10C0h
    int params;                     // sizeof 04h    offset 10C4h
    int in_funcnr;                  // sizeof 04h    offset 10C8h
    int in_classnr;                 // sizeof 04h    offset 10CCh
    int stringcount;                // sizeof 04h    offset 10D0h
    zCPar_Symbol* in_func;          // sizeof 04h    offset 10D4h
    zCPar_Symbol* in_class;         // sizeof 04h    offset 10D8h
    int error;                      // sizeof 04h    offset 10DCh
    int stop_on_error;              // sizeof 04h    offset 10E0h
    int errorline;                  // sizeof 04h    offset 10E4h
    char* prevword_index[16];       // sizeof 40h    offset 10E8h
    int prevline_index[16];         // sizeof 40h    offset 1128h
    int prevword_nr;                // sizeof 04h    offset 1168h
    zSTRING aword;                  // sizeof 14h    offset 116Ch
    int instance;                   // sizeof 04h    offset 1180h
    int instance_help;              // sizeof 04h    offset 1184h
    zCViewProgressBar* progressBar; // sizeof 04h    offset 1188h
    zCPar_TreeNode* tree;           // sizeof 04h    offset 118Ch
    zCPar_TreeNode* treenode;       // sizeof 04h    offset 1190h
    zCView* win_code;               // sizeof 04h    offset 1194h
    int debugmode;                  // sizeof 04h    offset 1198h
    int curfuncnr;                  // sizeof 04h    offset 119Ch
    int labelcount;                 // sizeof 04h    offset 11A0h
    int* labelpos;                  // sizeof 04h    offset 11A4h
    zCList<zSTRING>* add_funclist;  // sizeof 04h    offset 11A8h
    zSTRING add_filename;           // sizeof 14h    offset 11ACh
    int add_created;                // sizeof 04h    offset 11C0h

    zCParser() {}
    void zCParser_OnInit( int )                                                     zCall( 0x0071D670 );
    zCParser( int a0 )                                                              zInit( zCParser_OnInit( a0 ));
    ~zCParser()                                                                     zCall( 0x0071D790 );
    void SetMessageFunc( void( __cdecl* )( zSTRING ))                               zCall( 0x0071DA00 );
    void SetStopOnError( int )                                                      zCall( 0x0071DA10 );
    void Error( zSTRING&, int )                                                     zCall( 0x0071DA20 );
    void Message( zSTRING& )                                                        zCall( 0x0071DDD0 );
    int Error()                                                                     zCall( 0x0071DF40 );
    int SaveDat( zSTRING& )                                                         zCall( 0x0071DF50 );
    int LoadDat( zSTRING& )                                                         zCall( 0x0071E130 );
    int Parse( zSTRING )                                                            zCall( 0x0071E400 );
    int ParseSource( zSTRING& )                                                     zCall( 0x0071E6D0 );
    int ParseFile( zSTRING& )                                                       zCall( 0x0071F050 );
    void ParseBlock()                                                               zCall( 0x0071F8E0 );
    void CreatePCode()                                                              zCall( 0x0071FBA0 );
    void ShowSymbols()                                                              zCall( 0x007202C0 );
    void PushTree( zCPar_TreeNode* )                                                zCall( 0x007202D0 );
    zCPar_TreeNode* PushOnStack( zCPar_TreeNode* )                                  zCall( 0x007202F0 );
    void SolveLabels( zCPar_TreeNode* )                                             zCall( 0x00721210 );
    int MergeFile( zSTRING& )                                                       zCall( 0x00721270 );
    int PopDataValue()                                                              zCall( 0x007214F0 );
    float PopFloatValue()                                                           zCall( 0x00721520 );
    int* PopVarAddress()                                                            zCall( 0x00721560 );
    zSTRING* PopString()                                                            zCall( 0x00721590 );
    void DoStack( int )                                                             zCall( 0x007215B0 );
    void* CallFunc( zSTRING const& )                                                zCall( 0x00722640 );
    void* __cdecl CallFunc( int, ... )                                              zCall( 0x00722660 );
    int GetCurrentFunc()                                                            zCall( 0x00722B80 );
    int CreateInstance( zSTRING&, void* )                                           zCall( 0x00722B90 );
    int CreateInstance( int, void* )                                                zCall( 0x00722C10 );
    int CreatePrototype( zSTRING&, void* )                                          zCall( 0x00722C80 );
    int CreatePrototype( int, void* )                                               zCall( 0x00722D00 );
    void Reset()                                                                    zCall( 0x00722D70 );
    void SetPercentDone( int )                                                      zCall( 0x00722EE0 );
    void CreateHelpers()                                                            zCall( 0x00722F50 );
    void EnableTreeSave( int )                                                      zCall( 0x007230F0 );
    void EnableDatSave( int )                                                       zCall( 0x00723100 );
    void EnableTreeLoad( int )                                                      zCall( 0x00723110 );
    int GetIndex( zSTRING const& )                                                  zCall( 0x00723120 );
    int MatchClass( int, zSTRING const& )                                           zCall( 0x007231F0 );
    int GetBaseClass( zCPar_Symbol* )                                               zCall( 0x00723270 );
    int GetBaseClass( int )                                                         zCall( 0x007232D0 );
    int GetBase( int )                                                              zCall( 0x00723330 );
    int GetPrototype( int, int )                                                    zCall( 0x00723380 );
    int GetInstance( int, int )                                                     zCall( 0x007233F0 );
    zSTRING GetSymbolInfo( int, int&, int& )                                        zCall( 0x007234A0 );
    zCPar_Symbol* GetSymbolInfo( int )                                              zCall( 0x00723560 );
    zCPar_Symbol* GetSymbol( int )                                                  zCall( 0x00723570 );
    zCPar_Symbol* GetSymbol( zSTRING const& )                                       zCall( 0x00723580 );
    zSTRING GetClassVarInfo( int, int, int&, int& )                                 zCall( 0x00723650 );
    void GetClassVarInfo( int, zSTRING&, int&, int& )                               zCall( 0x007238C0 );
    zSTRING GetText( zSTRING&, int )                                                zCall( 0x00723AE0 );
    zSTRING GetText( int, int )                                                     zCall( 0x00723B20 );
    int GetInt( int, int )                                                          zCall( 0x00723C30 );
    zSTRING GetInstanceValue( zSTRING&, int, void*, int )                           zCall( 0x00723C80 );
    zSTRING GetInstanceValue( int, int, void*, int )                                zCall( 0x00723D80 );
    int IsValid( zSTRING&, void*, zSTRING& )                                        zCall( 0x00724070 );
    int CheckClassSize( zSTRING&, int )                                             zCall( 0x007241F0 );
    int CheckClassSize( int, int )                                                  zCall( 0x00724210 );
    void AddClassOffset( zSTRING&, int )                                            zCall( 0x007244E0 );
    int SetInstance( zSTRING const&, void* )                                        zCall( 0x00724640 );
    int SetInstance( int, void* )                                                   zCall( 0x00724680 );
    int AutoCompletion( zSTRING& )                                                  zCall( 0x007246C0 );
    int GetNumFiles()                                                               zCall( 0x00724910 );
    zSTRING GetFileName( int )                                                      zCall( 0x00724920 );
    int IsStackFull()                                                               zCall( 0x007249C0 );
    int GetLastErrorLine()                                                          zCall( 0x007249D0 );
    void Reparse( zSTRING& )                                                        zCall( 0x007249E0 );
    int SaveInstance( zSTRING&, void* )                                             zCall( 0x00724B10 );
    int SaveInstance( int, void* )                                                  zCall( 0x00724B40 );
    void CloseViews()                                                               zCall( 0x007258D0 );
    void ShowCode( int )                                                            zCall( 0x00725900 );
    void SaveInfoFile( zSTRING )                                                    zCall( 0x00725A60 );
    void SetInfoFile( zCList<zSTRING>*, zSTRING const& )                            zCall( 0x00726100 );
    int IsInAdditionalInfo( zSTRING const& )                                        zCall( 0x00726270 );
    int WriteAdditionalInfo( zSTRING&, int, int )                                   zCall( 0x00726440 );
    int ClearAllInstanceRefs()                                                      zCall( 0x007267D0 );
    int ClearInstanceRefs( void* )                                                  zCall( 0x00726840 );
    int ResetGlobalVars()                                                           zCall( 0x007268D0 );
    void CreateVarReferenceList( zSTRING const&, zCArray<int>& )                    zCall( 0x00726930 );
    void ResetWithVarReferenceList( zCArray<int>&, void* )                          zCall( 0x00726AD0 );
    int SaveGlobalVars( zCArchiver& )                                               zCall( 0x00726B50 );
    int LoadGlobalVars( zCArchiver& )                                               zCall( 0x00726EA0 );
    void GetOperatorString( int, zSTRING& )                                         zCall( 0x007278B0 );
    void FindNext( char* )                                                          zCall( 0x00727E60 );
    void PrevWord()                                                                 zCall( 0x00727FE0 );
    void ReadWord( zSTRING& )                                                       zCall( 0x00728010 );
    void Match( zSTRING& )                                                          zCall( 0x00728290 );
    int ReadVarType()                                                               zCall( 0x00728460 );
    int ReadFuncType()                                                              zCall( 0x007286B0 );
    int ReadInt()                                                                   zCall( 0x007288F0 );
    float ReadFloat()                                                               zCall( 0x00728BC0 );
    void ReadString( zSTRING& )                                                     zCall( 0x00728F10 );
    int ReadArray()                                                                 zCall( 0x00729230 );
    zCPar_TreeNode* CreateLeaf( int, zCPar_TreeNode* )                              zCall( 0x00729470 );
    zCPar_TreeNode* CreateStringLeaf()                                              zCall( 0x007294E0 );
    zCPar_TreeNode* CreateFloatLeaf()                                               zCall( 0x00729770 );
    int GetNextToken()                                                              zCall( 0x00729920 );
    zCPar_TreeNode* Parse_Expression_Primary( int& )                                zCall( 0x0072A210 );
    zCPar_TreeNode* Parse_Expression( int&, int )                                   zCall( 0x0072A880 );
    zCPar_TreeNode* ParseExpressionEx( zSTRING& )                                   zCall( 0x0072AAB0 );
    zCPar_TreeNode* ParseExpression()                                               zCall( 0x0072AB20 );
    int EvalLeaf( zCPar_TreeNode*, int )                                            zCall( 0x0072AB40 );
    void DeclareVar( int )                                                          zCall( 0x0072B060 );
    void DeclareClass()                                                             zCall( 0x0072C4D0 );
    void DeclareInstance()                                                          zCall( 0x0072C6E0 );
    void DeclarePrototype()                                                         zCall( 0x0072CFD0 );
    void DeclareIf()                                                                zCall( 0x0072D570 );
    void DeclareAssign( zSTRING& )                                                  zCall( 0x0072DA10 );
    void DeclareAssignFunc( zSTRING& )                                              zCall( 0x0072E260 );
    void DeclareFunc()                                                              zCall( 0x0072E570 );
    void DeclareReturn()                                                            zCall( 0x0072EAA0 );
    void DeclareFuncCall( zSTRING&, int )                                           zCall( 0x0072ECA0 );
    zCPar_Symbol* SearchFuncWithStartAddress( int )                                 zCall( 0x0072F700 );
    void GetNextCommand( zSTRING& )                                                 zCall( 0x0072F780 );
    void ShowPCodeSpy( zSTRING& )                                                   zCall( 0x00730450 );
    void ShowPCode( int, zCView*, int )                                             zCall( 0x00730590 );
    void __cdecl DefineExternal( zSTRING const&, int( __cdecl* )(), int, int, ... ) zCall( 0x00730820 );
    void DefineExternalVar( zSTRING const&, void*, int, int )                       zCall( 0x00730C00 );
    void GetParameter( int& )                                                       zCall( 0x00730E40 );
    void GetParameter( float& )                                                     zCall( 0x00730E50 );
    void GetParameter( zSTRING& )                                                   zCall( 0x00730E90 );
    void* GetInstance()                                                             zCall( 0x00730FD0 );
    void SetReturn( int )                                                           zCall( 0x00731000 );
    void SetReturn( float )                                                         zCall( 0x00731020 );
    void SetReturn( void* )                                                         zCall( 0x00731040 );
    void SetReturn( zSTRING& )                                                      zCall( 0x00731080 );
    int FindInstanceVar( zSTRING& )                                                 zCall( 0x007310A0 );
    int GetLastInstance()                                                           zCall( 0x007312F0 );
    int FindIndex( zSTRING& )                                                       zCall( 0x00731300 );
    static void SetVersion( unsigned char )                                         zCall( 0x0071C680 );
    static unsigned char GetVersion()                                               zCall( 0x0071C690 );
    static zCParser* GetParser()                                                    zCall( 0x0071D660 );

    // static properties
    static int& enableParsing;
    static zCParser*& cur_parser;

    // user API
    #include "zCParser.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPARSER_H__VER1__