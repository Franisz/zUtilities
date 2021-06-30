// Supported with union (c) 2018 Union team

#ifndef __ZPARSER__SYMBOL_H__VER2__
#define __ZPARSER__SYMBOL_H__VER2__

namespace Gothic_II_Classic {

  class zCPar_StringTable {
  public:
    zCArray<zSTRING*> array;

    zCPar_StringTable() {}
    void zCPar_StringTable_OnInit( int ) zCall( 0x00741470 );
    zCPar_StringTable( int a0 )          zInit( zCPar_StringTable_OnInit( a0 ));
    ~zCPar_StringTable()                 zCall( 0x00741510 );
    void Clear()                         zCall( 0x00741590 );
    zSTRING* Insert( zSTRING& )          zCall( 0x007415C0 );
    int GetLastEntry()                   zCall( 0x00741710 );
    zSTRING* GetString( int )            zCall( 0x00741720 );
    void Save( zSTRING& )                zCall( 0x00741740 );
    void Load( zSTRING& )                zCall( 0x00741860 );
    void ShrinkToFit()                   zCall( 0x00741A40 );
    void Show()                          zCall( 0x00741AC0 );

    // user API
    #include "zCPar_StringTable.inl"
  };

  class zCPar_Symbol {
  public:
    zSTRING name;
    zCPar_Symbol* next;
    union {
      void* adr;
      int* intdata;
      float* floatdata;
      zSTRING* stringdata;
      int single_intdata;
      float single_floatdata;
    };

    int offset;
    unsigned int ele      : 12;
    unsigned int type     : 4;
    unsigned int flags    : 6;
    int space             : 1;
    unsigned int filenr   : 19;
    unsigned int line     : 19;
    unsigned int line_anz : 19;
    unsigned int pos_beg  : 24;
    unsigned int pos_anz  : 24;
    zCPar_Symbol* parent;

    void zCPar_Symbol_OnInit()                  zCall( 0x00741C50 );
    zCPar_Symbol()                              zInit( zCPar_Symbol_OnInit() );
    ~zCPar_Symbol()                             zCall( 0x00741CB0 );
    void AllocSpace()                           zCall( 0x00741D80 );
    void* GetDataAdr( int )                     zCall( 0x00742000 );
    void SetDataAdr( void* )                    zCall( 0x00742300 );
    void SetFlag( int )                         zCall( 0x00742310 );
    int HasFlag( int )                          zCall( 0x00742340 );
    void SetParent( zCPar_Symbol* )             zCall( 0x00742360 );
    zCPar_Symbol* GetParent()                   zCall( 0x00742370 );
    void* GetInstanceAdr()                      zCall( 0x00742380 );
    zCPar_Symbol* GetNext()                     zCall( 0x00742390 );
    int ArrayCheck( int )                       zCall( 0x007423A0 );
    void GetStackPos( int&, int )               zCall( 0x007423D0 );
    void SetStackPos( int, int )                zCall( 0x007423E0 );
    void SetValue( int, int )                   zCall( 0x007423F0 );
    void SetValue( float, int )                 zCall( 0x00742420 );
    void SetValue( zSTRING&, int )              zCall( 0x00742450 );
    void GetValue( int&, int )                  zCall( 0x007425A0 );
    void GetValue( float&, int )                zCall( 0x007425D0 );
    void GetValue( zSTRING&, int )              zCall( 0x00742600 );
    void SetLineData( int, int, int, int )      zCall( 0x00742750 );
    void GetLineData( int&, int&, int&, int& )  zCall( 0x00742B10 );
    void SetFileNr( int )                       zCall( 0x00742B50 );
    void Save( zFILE* )                         zCall( 0x00742CE0 );
    void SaveFull( zFILE* )                     zCall( 0x00742F00 );
    void LoadFull( zFILE* )                     zCall( 0x00743160 );
    void Load( zFILE* )                         zCall( 0x00743330 );
    void SetOffset( int )                       zCall( 0x007434E0 );
    int GetOffset()                             zCall( 0x007434F0 );
    void SetClassOffset( int )                  zCall( 0x00743500 );
    int GetClassOffset()                        zCall( 0x00743510 );
    static void SetUseInstance( zCPar_Symbol* ) zCall( 0x00741B10 );
    static void SetUseInstanceAdr( void* )      zCall( 0x00741C30 );
    static void* GetUseInstance()               zCall( 0x00741C40 );

    // static properties
    static zCPar_Symbol*& instance_sym;
    static void*& instance_adr;

    // user API
    #include "zCPar_Symbol.inl"
  };

  class zCPar_SymbolTable {
  public:
    zCPar_Symbol* preAllocatedSymbols;
    int nextPreAllocated;
    zCArray<zCPar_Symbol*> table;
    zCArraySort<int> tablesort;
    zCPar_Symbol* lastsym;
    zCPar_Symbol* firstsym;

    zCPar_SymbolTable() {}
    void zCPar_SymbolTable_OnInit( int )              zCall( 0x00743520 );
    zCPar_SymbolTable( int a0 )                       zInit( zCPar_SymbolTable_OnInit( a0 ));
    ~zCPar_SymbolTable()                              zCall( 0x00743650 );
    void Clear()                                      zCall( 0x007436C0 );
    void PreAlloc( int )                              zCall( 0x007437B0 );
    void Save( zFILE* )                               zCall( 0x007438A0 );
    void Load( zFILE* )                               zCall( 0x00743A20 );
    int IsIn( zCPar_Symbol* )                         zCall( 0x00743E10 );
    int IsIn( zSTRING const& )                        zCall( 0x00743F20 );
    int GetIndex( zCPar_Symbol* )                     zCall( 0x00744030 );
    int GetIndex( zSTRING const& )                    zCall( 0x00744120 );
    int GetIndex( zSTRING const&, int )               zCall( 0x00744210 );
    int __fastcall Search( zSTRING const&, int, int ) zCall( 0x00744320 );
    zCPar_Symbol* GetSymbol( zSTRING const& )         zCall( 0x00744400 );
    zCPar_Symbol* GetSymbol( int )                    zCall( 0x007444A0 );
    int Insert( zCPar_Symbol* )                       zCall( 0x007444C0 );
    void InsertEnd( zCPar_Symbol* )                   zCall( 0x00744700 );
    void ShrinkToFit()                                zCall( 0x00744910 );
    void SetSize( int )                               zCall( 0x007449F0 );
    int GetNumInList()                                zCall( 0x00744AA0 );
    zCPar_Symbol* GetLastSymbol()                     zCall( 0x00744AB0 );
    zCPar_Symbol* GetFirstSymbol()                    zCall( 0x00744AC0 );
    void Show()                                       zCall( 0x00744AD0 );
    static int Compare( void const*, void const* )    zCall( 0x00743820 );

    // static properties
    static zCPar_SymbolTable*& cur_table;

    // user API
    #include "zCPar_SymbolTable.inl"
  };

  class zCPar_Stack {
  public:
    unsigned char* stack;
    union {
      unsigned char* stackptr;
      unsigned short* stackptr_w;
      int* stackptr_i;
    };
    union {
      unsigned char* stacklast;
      unsigned short* stacklast_w;
      int* stacklast_i;
    };

    int stacksize;

    zCPar_Stack() {}
    void zCPar_Stack_OnInit( int )  zCall( 0x00745080 );
    zCPar_Stack( int a0 )           zInit( zCPar_Stack_OnInit( a0 ));
    ~zCPar_Stack()                  zCall( 0x007450B0 );
    int GetPopPos()                 zCall( 0x007450D0 );
    void SetPopPos( int )           zCall( 0x007450E0 );
    int GetDynSize()                zCall( 0x007450F0 );
    int GetStatSize()               zCall( 0x00745100 );
    void PushByte( unsigned char )  zCall( 0x00745110 );
    void PushWord( unsigned short ) zCall( 0x00745130 );
    void PushInt( int )             zCall( 0x00745150 );
    void PushString( zSTRING& )     zCall( 0x00745170 );
    unsigned char PopByte()         zCall( 0x007451E0 );
    unsigned short PopWord()        zCall( 0x007451F0 );
    int PopInt()                    zCall( 0x00745200 );
    void PopString( zSTRING& )      zCall( 0x00745210 );
    void CheckOverflow( int )       zCall( 0x007453D0 );
    void Set( int, int )            zCall( 0x00745440 );
    int ReachedEnd()                zCall( 0x00745450 );
    void Clear()                    zCall( 0x00745460 );
    void Save( zFILE* )             zCall( 0x00745470 );
    void Load( zFILE* )             zCall( 0x007454B0 );

    // user API
    #include "zCPar_Stack.inl"
  };

  class zCPar_DataStack {
  public:
    int stack[1024];
    int sptr;

    void zCPar_DataStack_OnInit() zCall( 0x00745510 );
    zCPar_DataStack()             zInit( zCPar_DataStack_OnInit() );
    ~zCPar_DataStack()            zCall( 0x00745530 );
    void Push( int )              zCall( 0x00745540 );
    int Pop()                     zCall( 0x00745630 );
    float PopFloat()              zCall( 0x00745650 );
    int IsEmpty()                 zCall( 0x00745670 );
    void Clear()                  zCall( 0x00745680 );

    // user API
    #include "zCPar_DataStack.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPARSER__SYMBOL_H__VER2__