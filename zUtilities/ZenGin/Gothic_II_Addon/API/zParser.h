// Supported with union (c) 2018-2021 Union team

#ifndef __ZPARSER_H__VER3__
#define __ZPARSER_H__VER3__

#include "zParser_Symbol.h"
#include "zDisk.h"

namespace Gothic_II_Addon {
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

    void zCPar_TreeNode_OnInit()                                                   zCall( 0x00797980 );
    void zCPar_TreeNode_OnInit( int, int )                                         zCall( 0x007979C0 );
    void zCPar_TreeNode_OnInit( int, zSTRING&, int )                               zCall( 0x00797A10 );
    zCPar_TreeNode()                                                               zInit( zCPar_TreeNode_OnInit() );
    zCPar_TreeNode( int a0, int a1 )                                               zInit( zCPar_TreeNode_OnInit( a0, a1 ));
    zCPar_TreeNode( int a0, zSTRING& a1, int a2 )                                  zInit( zCPar_TreeNode_OnInit( a0, a1, a2 ));
    ~zCPar_TreeNode()                                                              zCall( 0x00797BA0 );
    void SetLeft( zCPar_TreeNode* )                                                zCall( 0x00797C60 );
    void SetRight( zCPar_TreeNode* )                                               zCall( 0x00797C70 );
    void SetNext( zCPar_TreeNode* )                                                zCall( 0x00797C80 );
    static zCPar_TreeNode* SeekEndTree( zCPar_TreeNode* )                          zCall( 0x00797C90 );
    static zCPar_TreeNode* MakeDyadicNode( zCPar_TreeNode*, int, zCPar_TreeNode* ) zCall( 0x00797CB0 );
    static zCPar_TreeNode* MakeMonadicNode( int, zCPar_TreeNode* )                 zCall( 0x00797D20 );

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

    void zCPar_File_OnInit()                         zCall( 0x0078D020 );
    zCPar_File()                                     zInit( zCPar_File_OnInit() );
    ~zCPar_File()                                    zCall( 0x0078D050 );
    int IsNewerDate( zDATE&, zDATE& )                zCall( 0x0078D0F0 );
    int IsExactDate( zDATE&, zDATE& )                zCall( 0x0078D170 );
    void SetFileNumber( int )                        zCall( 0x0078D1F0 );
    int GetFileNumber()                              zCall( 0x0078D200 );
    zSTRING GetName()                                zCall( 0x0078D210 );
    void EnableTreeLoad( int )                       zCall( 0x0078D260 );
    int Load( zSTRING&, zCPar_SymbolTable&, zDATE& ) zCall( 0x0078D270 );
    char* GetStartAddress()                          zCall( 0x0078D4F0 );
    char* GetEndAddress()                            zCall( 0x0078D500 );
    void Dispose()                                   zCall( 0x0078D510 );
    void SetTree( zCPar_TreeNode* )                  zCall( 0x0078D530 );
    zCPar_TreeNode* GetTree()                        zCall( 0x0078D570 );
    void SetLabelCount( int )                        zCall( 0x0078D580 );
    int GetLabelCount()                              zCall( 0x0078D590 );
    void SaveTree( int, zCPar_Symbol*, zDATE& )      zCall( 0x0078D5A0 );
    void SaveTreeNode( zFILE*, zCPar_TreeNode* )     zCall( 0x0078D820 );
    zCPar_TreeNode* LoadTreeNode( zFILE* )           zCall( 0x0078D990 );
    int LoadTree( zFILE_STATS&, zCPar_SymbolTable& ) zCall( 0x0078DAC0 );
    void DeleteTree()                                zCall( 0x0078DE90 );

    // user API
    #include "zCPar_File.inl"
  };

  // sizeof 21C4h
  class zCParser {
  public:
    void( *msgfunc )( zSTRING );    // sizeof 04h    offset 00h
    zCArray<zCPar_File*> file;      // sizeof 0Ch    offset 04h
    zCPar_SymbolTable symtab;       // sizeof 2Ch    offset 10h
    zCPar_StringTable stringtab;    // sizeof 0Ch    offset 3Ch
    zCPar_Stack stack;              // sizeof 10h    offset 48h
    zCPar_DataStack datastack;      // sizeof 2004h  offset 58h
    zCPar_Symbol* self;             // sizeof 04h    offset 205Ch
    zSTRING fname;                  // sizeof 14h    offset 2060h
    zSTRING mainfile;               // sizeof 14h    offset 2074h
    int compiled;                   // sizeof 04h    offset 2088h
    int treesave;                   // sizeof 04h    offset 208Ch
    int datsave;                    // sizeof 04h    offset 2090h
    int parse_changed;              // sizeof 04h    offset 2094h
    int treeload;                   // sizeof 04h    offset 2098h
    int mergemode;                  // sizeof 04h    offset 209Ch
    int linkingnr;                  // sizeof 04h    offset 20A0h
    int linec;                      // sizeof 04h    offset 20A4h
    int line_start;                 // sizeof 04h    offset 20A8h
    int ext_parse;                  // sizeof 04h    offset 20ACh
    char* pc_start;                 // sizeof 04h    offset 20B0h
    char* pc;                       // sizeof 04h    offset 20B4h
    char* oldpc;                    // sizeof 04h    offset 20B8h
    char* pc_stop;                  // sizeof 04h    offset 20BCh
    char* oldpc_stop;               // sizeof 04h    offset 20C0h
    int params;                     // sizeof 04h    offset 20C4h
    int in_funcnr;                  // sizeof 04h    offset 20C8h
    int in_classnr;                 // sizeof 04h    offset 20CCh
    int stringcount;                // sizeof 04h    offset 20D0h
    zCPar_Symbol* in_func;          // sizeof 04h    offset 20D4h
    zCPar_Symbol* in_class;         // sizeof 04h    offset 20D8h
    int error;                      // sizeof 04h    offset 20DCh
    int stop_on_error;              // sizeof 04h    offset 20E0h
    int errorline;                  // sizeof 04h    offset 20E4h
    char* prevword_index[16];       // sizeof 40h    offset 20E8h
    int prevline_index[16];         // sizeof 40h    offset 2128h
    int prevword_nr;                // sizeof 04h    offset 2168h
    zSTRING aword;                  // sizeof 14h    offset 216Ch
    int instance;                   // sizeof 04h    offset 2180h
    int instance_help;              // sizeof 04h    offset 2184h
    zCViewProgressBar* progressBar; // sizeof 04h    offset 2188h
    zCPar_TreeNode* tree;           // sizeof 04h    offset 218Ch
    zCPar_TreeNode* treenode;       // sizeof 04h    offset 2190h
    zCView* win_code;               // sizeof 04h    offset 2194h
    int debugmode;                  // sizeof 04h    offset 2198h
    int curfuncnr;                  // sizeof 04h    offset 219Ch
    int labelcount;                 // sizeof 04h    offset 21A0h
    int* labelpos;                  // sizeof 04h    offset 21A4h
    zCList<zSTRING>* add_funclist;  // sizeof 04h    offset 21A8h
    zSTRING add_filename;           // sizeof 14h    offset 21ACh
    int add_created;                // sizeof 04h    offset 21C0h

    zCParser() {}
    void zCParser_OnInit( int )                                                     zCall( 0x0078DED0 );
    zCParser( int a0 )                                                              zInit( zCParser_OnInit( a0 ));
    ~zCParser()                                                                     zCall( 0x0078DFF0 );
    void SetMessageFunc( void( __cdecl* )( zSTRING ))                               zCall( 0x0078E250 );
    void SetStopOnError( int )                                                      zCall( 0x0078E260 );
    void Error( zSTRING&, int )                                                     zCall( 0x0078E270 );
    void Message( zSTRING& )                                                        zCall( 0x0078E5F0 );
    int Error()                                                                     zCall( 0x0078E730 );
    int SaveDat( zSTRING& )                                                         zCall( 0x0078E740 );
    int LoadDat( zSTRING& )                                                         zCall( 0x0078E900 );
    int Parse( zSTRING )                                                            zCall( 0x0078EBA0 );
    int ParseSource( zSTRING& )                                                     zCall( 0x0078EE20 );
    int ParseFile( zSTRING& )                                                       zCall( 0x0078F660 );
    void ParseBlock()                                                               zCall( 0x0078FE30 );
    void CreatePCode()                                                              zCall( 0x007900E0 );
    void ShowSymbols()                                                              zCall( 0x00790810 );
    void PushTree( zCPar_TreeNode* )                                                zCall( 0x00790820 );
    zCPar_TreeNode* PushOnStack( zCPar_TreeNode* )                                  zCall( 0x00790840 );
    void SolveLabels( zCPar_TreeNode* )                                             zCall( 0x007915F0 );
    int MergeFile( zSTRING& )                                                       zCall( 0x00791650 );
    int PopDataValue()                                                              zCall( 0x007918B0 );
    float PopFloatValue()                                                           zCall( 0x007918E0 );
    int* PopVarAddress()                                                            zCall( 0x00791910 );
    zSTRING* PopString()                                                            zCall( 0x00791940 );
    void DoStack( int )                                                             zCall( 0x00791960 );
    void* CallFunc( zSTRING const& )                                                zCall( 0x007929D0 );
    void* __cdecl CallFunc( int, ... )                                              zCall( 0x007929F0 );
    int GetCurrentFunc()                                                            zCall( 0x00792F10 );
    int CreateInstance( zSTRING&, void* )                                           zCall( 0x00792F20 );
    int CreateInstance( int, void* )                                                zCall( 0x00792FA0 );
    int CreatePrototype( zSTRING&, void* )                                          zCall( 0x00793010 );
    int CreatePrototype( int, void* )                                               zCall( 0x00793090 );
    void Reset()                                                                    zCall( 0x00793100 );
    void SetPercentDone( int )                                                      zCall( 0x00793270 );
    void CreateHelpers()                                                            zCall( 0x007932D0 );
    void EnableTreeSave( int )                                                      zCall( 0x00793440 );
    void EnableDatSave( int )                                                       zCall( 0x00793450 );
    void EnableTreeLoad( int )                                                      zCall( 0x00793460 );
    int GetIndex( zSTRING const& )                                                  zCall( 0x00793470 );
    int MatchClass( int, zSTRING const& )                                           zCall( 0x00793530 );
    int GetBaseClass( zCPar_Symbol* )                                               zCall( 0x007935B0 );
    int GetBaseClass( int )                                                         zCall( 0x00793610 );
    int GetBase( int )                                                              zCall( 0x00793670 );
    int GetPrototype( int, int )                                                    zCall( 0x007936C0 );
    int GetInstance( int, int )                                                     zCall( 0x00793730 );
    zSTRING GetSymbolInfo( int, int&, int& )                                        zCall( 0x007937F0 );
    zCPar_Symbol* GetSymbolInfo( int )                                              zCall( 0x007938B0 );
    zCPar_Symbol* GetSymbol( int )                                                  zCall( 0x007938C0 );
    zCPar_Symbol* GetSymbol( zSTRING const& )                                       zCall( 0x007938D0 );
    zSTRING GetClassVarInfo( int, int, int&, int& )                                 zCall( 0x00793990 );
    void GetClassVarInfo( int, zSTRING&, int&, int& )                               zCall( 0x00793BB0 );
    zSTRING GetText( zSTRING&, int )                                                zCall( 0x00793D70 );
    zSTRING GetText( int, int )                                                     zCall( 0x00793DB0 );
    int GetInt( int, int )                                                          zCall( 0x00793E90 );
    zSTRING GetInstanceValue( zSTRING&, int, void*, int )                           zCall( 0x00793EE0 );
    zSTRING GetInstanceValue( int, int, void*, int )                                zCall( 0x00793FD0 );
    int IsValid( zSTRING&, void*, zSTRING& )                                        zCall( 0x007942E0 );
    int CheckClassSize( zSTRING&, int )                                             zCall( 0x00794450 );
    int CheckClassSize( int, int )                                                  zCall( 0x00794470 );
    void AddClassOffset( zSTRING&, int )                                            zCall( 0x00794730 );
    int SetInstance( zSTRING const&, void* )                                        zCall( 0x00794870 );
    int SetInstance( int, void* )                                                   zCall( 0x00794910 );
    int AutoCompletion( zSTRING& )                                                  zCall( 0x00794950 );
    int GetNumFiles()                                                               zCall( 0x00794B60 );
    zSTRING GetFileName( int )                                                      zCall( 0x00794B70 );
    int IsStackFull()                                                               zCall( 0x00794C10 );
    int GetLastErrorLine()                                                          zCall( 0x00794C20 );
    void Reparse( zSTRING& )                                                        zCall( 0x00794C30 );
    int SaveInstance( zSTRING&, void* )                                             zCall( 0x00794D40 );
    int SaveInstance( int, void* )                                                  zCall( 0x00794D70 );
    void CloseViews()                                                               zCall( 0x00795A30 );
    void ShowCode( int )                                                            zCall( 0x00795A60 );
    void SaveInfoFile( zSTRING )                                                    zCall( 0x00795BB0 );
    void SetInfoFile( zCList<zSTRING>*, zSTRING const& )                            zCall( 0x00796200 );
    int IsInAdditionalInfo( zSTRING const& )                                        zCall( 0x00796390 );
    int WriteAdditionalInfo( zSTRING&, int, int )                                   zCall( 0x00796540 );
    int ClearAllInstanceRefs()                                                      zCall( 0x007968D0 );
    int ClearInstanceRefs( void* )                                                  zCall( 0x00796940 );
    int ResetGlobalVars()                                                           zCall( 0x007969C0 );
    void CreateVarReferenceList( zSTRING const&, zCArray<int>& )                    zCall( 0x00796A40 );
    void ResetWithVarReferenceList( zCArray<int>&, void* )                          zCall( 0x00796BC0 );
    int SaveGlobalVars( zCArchiver& )                                               zCall( 0x00796C40 );
    int LoadGlobalVars( zCArchiver& )                                               zCall( 0x00797170 );
    void GetOperatorString( int, zSTRING& )                                         zCall( 0x00797D80 );
    void FindNext( char* )                                                          zCall( 0x00798310 );
    void PrevWord()                                                                 zCall( 0x00798480 );
    void ReadWord( zSTRING& )                                                       zCall( 0x007984B0 );
    void Match( zSTRING& )                                                          zCall( 0x00798720 );
    int ReadVarType()                                                               zCall( 0x007988B0 );
    int ReadFuncType()                                                              zCall( 0x00798AE0 );
    int ReadInt()                                                                   zCall( 0x00798D00 );
    float ReadFloat()                                                               zCall( 0x00798FA0 );
    void ReadString( zSTRING& )                                                     zCall( 0x007992E0 );
    int ReadArray()                                                                 zCall( 0x007995C0 );
    zCPar_TreeNode* CreateLeaf( int, zCPar_TreeNode* )                              zCall( 0x007997C0 );
    zCPar_TreeNode* CreateStringLeaf()                                              zCall( 0x00799820 );
    zCPar_TreeNode* CreateFloatLeaf()                                               zCall( 0x00799A70 );
    int GetNextToken()                                                              zCall( 0x00799C10 );
    zCPar_TreeNode* Parse_Expression_Primary( int& )                                zCall( 0x0079A390 );
    zCPar_TreeNode* Parse_Expression( int&, int )                                   zCall( 0x0079A940 );
    zCPar_TreeNode* ParseExpressionEx( zSTRING& )                                   zCall( 0x0079AB50 );
    zCPar_TreeNode* ParseExpression()                                               zCall( 0x0079ABC0 );
    int EvalLeaf( zCPar_TreeNode*, int )                                            zCall( 0x0079ABE0 );
    void DeclareVar( int )                                                          zCall( 0x0079B0A0 );
    void DeclareClass()                                                             zCall( 0x0079C3D0 );
    void DeclareInstance()                                                          zCall( 0x0079C5A0 );
    void DeclarePrototype()                                                         zCall( 0x0079CD80 );
    void DeclareIf()                                                                zCall( 0x0079D270 );
    void DeclareAssign( zSTRING& )                                                  zCall( 0x0079D6D0 );
    void DeclareAssignFunc( zSTRING& )                                              zCall( 0x0079DE50 );
    void DeclareFunc()                                                              zCall( 0x0079E140 );
    void DeclareReturn()                                                            zCall( 0x0079E5D0 );
    void DeclareFuncCall( zSTRING&, int )                                           zCall( 0x0079E7B0 );
    zCPar_Symbol* SearchFuncWithStartAddress( int )                                 zCall( 0x0079F180 );
    void GetNextCommand( zSTRING& )                                                 zCall( 0x0079F1F0 );
    void ShowPCodeSpy( zSTRING& )                                                   zCall( 0x0079FE10 );
    void ShowPCode( int, zCView*, int )                                             zCall( 0x0079FF40 );
    void __cdecl DefineExternal( zSTRING const&, int( __cdecl* )(), int, int, ... ) zCall( 0x007A0190 );
    void DefineExternalVar( zSTRING const&, void*, int, int )                       zCall( 0x007A0550 );
    void GetParameter( int& )                                                       zCall( 0x007A0760 );
    void GetParameter( float& )                                                     zCall( 0x007A0770 );
    void GetParameter( zSTRING& )                                                   zCall( 0x007A07B0 );
    void* GetInstance()                                                             zCall( 0x007A08F0 );
    void* GetInstanceAndIndex( int& )                                               zCall( 0x007A0920 );
    void SetReturn( int )                                                           zCall( 0x007A0960 );
    void SetReturn( float )                                                         zCall( 0x007A0980 );
    void SetReturn( void* )                                                         zCall( 0x007A09A0 );
    void SetReturn( zSTRING& )                                                      zCall( 0x007A09D0 );
    int FindInstanceVar( zSTRING& )                                                 zCall( 0x007A09F0 );
    int GetLastInstance()                                                           zCall( 0x007A0BD0 );
    int FindIndex( zSTRING& )                                                       zCall( 0x007A0BE0 );
    static void SetVersion( unsigned char )                                         zCall( 0x0078D000 );
    static unsigned char GetVersion()                                               zCall( 0x0078D010 );
    static zCParser* GetParser()                                                    zCall( 0x0078DEC0 );

    // static properties
    static int& enableParsing;
    static zCParser*& cur_parser;

    // user API
    #include "zCParser.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPARSER_H__VER3__