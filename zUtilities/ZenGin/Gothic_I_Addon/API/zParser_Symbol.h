// Supported with union (c) 2018 Union team

#ifndef __ZPARSER__SYMBOL_H__VER1__
#define __ZPARSER__SYMBOL_H__VER1__

namespace Gothic_I_Addon {

  class zCPar_StringTable {
  public:
    zCArray<zSTRING*> array;

    zCPar_StringTable() {}
    void zCPar_StringTable_OnInit( int ) zCall( 0x00731630 );
    zCPar_StringTable( int a0 )          zInit( zCPar_StringTable_OnInit( a0 ));
    ~zCPar_StringTable()                 zCall( 0x00731700 );
    void Clear()                         zCall( 0x00731780 );
    zSTRING* Insert( zSTRING& )          zCall( 0x007317B0 );
    int GetLastEntry()                   zCall( 0x00731930 );
    zSTRING* GetString( int )            zCall( 0x00731940 );
    void Save( zSTRING& )                zCall( 0x00731960 );
    void Load( zSTRING& )                zCall( 0x00731AA0 );
    void ShrinkToFit()                   zCall( 0x00731C70 );
    void Show()                          zCall( 0x00731D00 );

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

    void zCPar_Symbol_OnInit()                  zCall( 0x00731E80 );
    zCPar_Symbol()                              zInit( zCPar_Symbol_OnInit() );
    ~zCPar_Symbol()                             zCall( 0x00731EE0 );
    void AllocSpace()                           zCall( 0x00731FD0 );
    void* GetDataAdr( int )                     zCall( 0x007322E0 );
    void SetDataAdr( void* )                    zCall( 0x007326C0 );
    void SetFlag( int )                         zCall( 0x007326D0 );
    int HasFlag( int )                          zCall( 0x007326F0 );
    void SetParent( zCPar_Symbol* )             zCall( 0x00732710 );
    zCPar_Symbol* GetParent()                   zCall( 0x00732720 );
    void* GetInstanceAdr()                      zCall( 0x00732730 );
    zCPar_Symbol* GetNext()                     zCall( 0x00732740 );
    int ArrayCheck( int )                       zCall( 0x00732750 );
    void GetStackPos( int&, int )               zCall( 0x00732780 );
    void SetStackPos( int, int )                zCall( 0x00732790 );
    void SetValue( int, int )                   zCall( 0x007327A0 );
    void SetValue( float, int )                 zCall( 0x007327D0 );
    void SetValue( zSTRING&, int )              zCall( 0x00732800 );
    void GetValue( int&, int )                  zCall( 0x00732950 );
    void GetValue( float&, int )                zCall( 0x00732980 );
    void GetValue( zSTRING&, int )              zCall( 0x007329B0 );
    void SetLineData( int, int, int, int )      zCall( 0x00732B00 );
    void GetLineData( int&, int&, int&, int& )  zCall( 0x00732DB0 );
    void SetFileNr( int )                       zCall( 0x00732DF0 );
    void Save( zFILE* )                         zCall( 0x00732EC0 );
    void SaveFull( zFILE* )                     zCall( 0x00733130 );
    void LoadFull( zFILE* )                     zCall( 0x007333D0 );
    void Load( zFILE* )                         zCall( 0x007335C0 );
    void SetOffset( int )                       zCall( 0x00733790 );
    int GetOffset()                             zCall( 0x007337A0 );
    void SetClassOffset( int )                  zCall( 0x007337B0 );
    int GetClassOffset()                        zCall( 0x007337C0 );
    static void SetUseInstance( zCPar_Symbol* ) zCall( 0x00731D40 );
    static void SetUseInstanceAdr( void* )      zCall( 0x00731E60 );
    static void* GetUseInstance()               zCall( 0x00731E70 );

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
    void zCPar_SymbolTable_OnInit( int )              zCall( 0x007337D0 );
    zCPar_SymbolTable( int a0 )                       zInit( zCPar_SymbolTable_OnInit( a0 ));
    ~zCPar_SymbolTable()                              zCall( 0x00733920 );
    void Clear()                                      zCall( 0x00733990 );
    void PreAlloc( int )                              zCall( 0x00733A70 );
    void Save( zFILE* )                               zCall( 0x00733B70 );
    void Load( zFILE* )                               zCall( 0x00733CF0 );
    int IsIn( zCPar_Symbol* )                         zCall( 0x00734130 );
    int IsIn( zSTRING const& )                        zCall( 0x00734230 );
    int GetIndex( zCPar_Symbol* )                     zCall( 0x00734330 );
    int GetIndex( zSTRING const& )                    zCall( 0x00734420 );
    int GetIndex( zSTRING const&, int )               zCall( 0x00734510 );
    int __fastcall Search( zSTRING const&, int, int ) zCall( 0x00734620 );
    zCPar_Symbol* GetSymbol( zSTRING const& )         zCall( 0x00734700 );
    zCPar_Symbol* GetSymbol( int )                    zCall( 0x007347A0 );
    int Insert( zCPar_Symbol* )                       zCall( 0x007347C0 );
    void InsertEnd( zCPar_Symbol* )                   zCall( 0x00734A20 );
    void ShrinkToFit()                                zCall( 0x00734C40 );
    void SetSize( int )                               zCall( 0x00734D40 );
    int GetNumInList()                                zCall( 0x00734E10 );
    zCPar_Symbol* GetLastSymbol()                     zCall( 0x00734E20 );
    zCPar_Symbol* GetFirstSymbol()                    zCall( 0x00734E30 );
    void Show()                                       zCall( 0x00734E40 );
    static int Compare( void const*, void const* )    zCall( 0x00733B00 );

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
    void zCPar_Stack_OnInit( int )  zCall( 0x00735450 );
    zCPar_Stack( int a0 )           zInit( zCPar_Stack_OnInit( a0 ));
    ~zCPar_Stack()                  zCall( 0x00735490 );
    int GetPopPos()                 zCall( 0x007354B0 );
    void SetPopPos( int )           zCall( 0x007354C0 );
    int GetDynSize()                zCall( 0x007354D0 );
    int GetStatSize()               zCall( 0x007354E0 );
    void PushByte( unsigned char )  zCall( 0x007354F0 );
    void PushWord( unsigned short ) zCall( 0x00735510 );
    void PushInt( int )             zCall( 0x00735530 );
    void PushString( zSTRING& )     zCall( 0x00735550 );
    unsigned char PopByte()         zCall( 0x007355C0 );
    unsigned short PopWord()        zCall( 0x007355D0 );
    int PopInt()                    zCall( 0x007355E0 );
    void PopString( zSTRING& )      zCall( 0x007355F0 );
    void CheckOverflow( int )       zCall( 0x007357B0 );
    void Set( int, int )            zCall( 0x00735830 );
    int ReachedEnd()                zCall( 0x00735840 );
    void Clear()                    zCall( 0x00735850 );
    void Save( zFILE* )             zCall( 0x00735860 );
    void Load( zFILE* )             zCall( 0x007358A0 );

    // user API
    #include "zCPar_Stack.inl"
  };

  class zCPar_DataStack {
  public:
    int stack[1024];
    int sptr;

    void zCPar_DataStack_OnInit() zCall( 0x00735910 );
    zCPar_DataStack()             zInit( zCPar_DataStack_OnInit() );
    ~zCPar_DataStack()            zCall( 0x00735930 );
    void Push( int )              zCall( 0x00735940 );
    int Pop()                     zCall( 0x00735960 );
    float PopFloat()              zCall( 0x00735980 );
    int IsEmpty()                 zCall( 0x007359A0 );
    void Clear()                  zCall( 0x007359B0 );

    // user API
    #include "zCPar_DataStack.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPARSER__SYMBOL_H__VER1__