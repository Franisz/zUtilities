// Supported with union (c) 2018-2021 Union team

#ifndef __ZPARSER__SYMBOL_H__VER3__
#define __ZPARSER__SYMBOL_H__VER3__

namespace Gothic_II_Addon {
  const int zMAX_SYM_DATASTACK = 2048;

  // sizeof 0Ch
  class zCPar_StringTable {
  public:
    zCArray<zSTRING*> array; // sizeof 0Ch    offset 00h

    zCPar_StringTable() {}
    void zCPar_StringTable_OnInit( int ) zCall( 0x007A0EB0 );
    zCPar_StringTable( int a0 )          zInit( zCPar_StringTable_OnInit( a0 ));
    ~zCPar_StringTable()                 zCall( 0x007A0F50 );
    void Clear()                         zCall( 0x007A0FD0 );
    zSTRING* Insert( zSTRING& )          zCall( 0x007A1000 );
    int GetLastEntry()                   zCall( 0x007A1150 );
    zSTRING* GetString( int )            zCall( 0x007A1160 );
    void Save( zSTRING& )                zCall( 0x007A1180 );
    void Load( zSTRING& )                zCall( 0x007A12A0 );
    void ShrinkToFit()                   zCall( 0x007A1480 );
    void Show()                          zCall( 0x007A1500 );

    // user API
    #include "zCPar_StringTable.inl"
  };

  // sizeof 3Ch
  class zCPar_Symbol {
  public:
    zSTRING name;               // sizeof 14h    offset 00h
    zCPar_Symbol* next;         // sizeof 04h    offset 14h
    union {
      void* adr;
      int* intdata;
      float* floatdata;
      zSTRING* stringdata;
      int single_intdata;
      float single_floatdata;
    };

    int offset;                 // sizeof 04h    offset 1Ch
    unsigned int ele      : 12; // sizeof 0Ch    offset bit
    unsigned int type     : 4;  // sizeof 04h    offset bit
    unsigned int flags    : 6;  // sizeof 06h    offset bit
    int space             : 1;  // sizeof 01h    offset bit
    unsigned int filenr   : 19; // sizeof 13h    offset bit
    unsigned int line     : 19; // sizeof 13h    offset bit
    unsigned int line_anz : 19; // sizeof 13h    offset bit
    unsigned int pos_beg  : 24; // sizeof 18h    offset bit
    unsigned int pos_anz  : 24; // sizeof 18h    offset bit
    zCPar_Symbol* parent;       // sizeof 04h    offset 38h

    void zCPar_Symbol_OnInit()                  zCall( 0x007A1690 );
    zCPar_Symbol()                              zInit( zCPar_Symbol_OnInit() );
    ~zCPar_Symbol()                             zCall( 0x007A16F0 );
    void AllocSpace()                           zCall( 0x007A17C0 );
    void* GetDataAdr( int )                     zCall( 0x007A1A40 );
    void SetDataAdr( void* )                    zCall( 0x007A1D40 );
    void SetFlag( int )                         zCall( 0x007A1D50 );
    int HasFlag( int )                          zCall( 0x007A1D80 );
    void SetParent( zCPar_Symbol* )             zCall( 0x007A1DA0 );
    zCPar_Symbol* GetParent()                   zCall( 0x007A1DB0 );
    void* GetInstanceAdr()                      zCall( 0x007A1DC0 );
    zCPar_Symbol* GetNext()                     zCall( 0x007A1DD0 );
    int ArrayCheck( int )                       zCall( 0x007A1DE0 );
    void GetStackPos( int&, int )               zCall( 0x007A1E10 );
    void SetStackPos( int, int )                zCall( 0x007A1E20 );
    void SetValue( int, int )                   zCall( 0x007A1E30 );
    void SetValue( float, int )                 zCall( 0x007A1E60 );
    void SetValue( zSTRING&, int )              zCall( 0x007A1E90 );
    void GetValue( int&, int )                  zCall( 0x007A1FE0 );
    void GetValue( float&, int )                zCall( 0x007A2010 );
    void GetValue( zSTRING&, int )              zCall( 0x007A2040 );
    void SetLineData( int, int, int, int )      zCall( 0x007A2190 );
    void GetLineData( int&, int&, int&, int& )  zCall( 0x007A2550 );
    void SetFileNr( int )                       zCall( 0x007A2590 );
    void Save( zFILE* )                         zCall( 0x007A2720 );
    void SaveFull( zFILE* )                     zCall( 0x007A2940 );
    void LoadFull( zFILE* )                     zCall( 0x007A2BA0 );
    void Load( zFILE* )                         zCall( 0x007A2D70 );
    void SetOffset( int )                       zCall( 0x007A2F20 );
    int GetOffset()                             zCall( 0x007A2F30 );
    void SetClassOffset( int )                  zCall( 0x007A2F40 );
    int GetClassOffset()                        zCall( 0x007A2F50 );
    static void SetUseInstance( zCPar_Symbol* ) zCall( 0x007A1550 );
    static void SetUseInstanceAdr( void* )      zCall( 0x007A1670 );
    static void* GetUseInstance()               zCall( 0x007A1680 );

    // static properties
    static zCPar_Symbol*& instance_sym;
    static void*& instance_adr;

    // user API
    #include "zCPar_Symbol.inl"
  };

  // sizeof 2Ch
  class zCPar_SymbolTable {
  public:
    zCPar_Symbol* preAllocatedSymbols; // sizeof 04h    offset 00h
    int nextPreAllocated;              // sizeof 04h    offset 04h
    zCArray<zCPar_Symbol*> table;      // sizeof 0Ch    offset 08h
    zCArraySort<int> tablesort;        // sizeof 10h    offset 14h
    zCPar_Symbol* lastsym;             // sizeof 04h    offset 24h
    zCPar_Symbol* firstsym;            // sizeof 04h    offset 28h

    zCPar_SymbolTable() {}
    void zCPar_SymbolTable_OnInit( int )              zCall( 0x007A2F60 );
    zCPar_SymbolTable( int a0 )                       zInit( zCPar_SymbolTable_OnInit( a0 ));
    ~zCPar_SymbolTable()                              zCall( 0x007A3090 );
    void Clear()                                      zCall( 0x007A3100 );
    void PreAlloc( int )                              zCall( 0x007A31F0 );
    void Save( zFILE* )                               zCall( 0x007A32E0 );
    void Load( zFILE* )                               zCall( 0x007A3460 );
    int IsIn( zCPar_Symbol* )                         zCall( 0x007A3850 );
    int IsIn( zSTRING const& )                        zCall( 0x007A3960 );
    int GetIndex( zCPar_Symbol* )                     zCall( 0x007A3A70 );
    int GetIndex( zSTRING const& )                    zCall( 0x007A3B60 );
    int GetIndex( zSTRING const&, int )               zCall( 0x007A3C50 );
    int __fastcall Search( zSTRING const&, int, int ) zCall( 0x007A3D60 );
    zCPar_Symbol* GetSymbol( zSTRING const& )         zCall( 0x007A3E40 );
    zCPar_Symbol* GetSymbol( int )                    zCall( 0x007A3EE0 );
    int Insert( zCPar_Symbol* )                       zCall( 0x007A3F00 );
    void InsertEnd( zCPar_Symbol* )                   zCall( 0x007A4140 );
    void ShrinkToFit()                                zCall( 0x007A4350 );
    void SetSize( int )                               zCall( 0x007A4430 );
    int GetNumInList()                                zCall( 0x007A44E0 );
    zCPar_Symbol* GetLastSymbol()                     zCall( 0x007A44F0 );
    zCPar_Symbol* GetFirstSymbol()                    zCall( 0x007A4500 );
    void Show()                                       zCall( 0x007A4510 );
    static int Compare( void const*, void const* )    zCall( 0x007A3260 );

    // static properties
    static zCPar_SymbolTable*& cur_table;

    // user API
    #include "zCPar_SymbolTable.inl"
  };

  // sizeof 10h
  class zCPar_Stack {
  public:
    unsigned char* stack; // sizeof 04h    offset 00h
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

    int stacksize;        // sizeof 04h    offset 0Ch

    zCPar_Stack() {}
    void zCPar_Stack_OnInit( int )  zCall( 0x007A4AC0 );
    zCPar_Stack( int a0 )           zInit( zCPar_Stack_OnInit( a0 ));
    ~zCPar_Stack()                  zCall( 0x007A4AF0 );
    int GetPopPos()                 zCall( 0x007A4B10 );
    void SetPopPos( int )           zCall( 0x007A4B20 );
    int GetDynSize()                zCall( 0x007A4B30 );
    int GetStatSize()               zCall( 0x007A4B40 );
    void PushByte( unsigned char )  zCall( 0x007A4B50 );
    void PushWord( unsigned short ) zCall( 0x007A4B70 );
    void PushInt( int )             zCall( 0x007A4B90 );
    void PushString( zSTRING& )     zCall( 0x007A4BB0 );
    unsigned char PopByte()         zCall( 0x007A4C20 );
    unsigned short PopWord()        zCall( 0x007A4C30 );
    int PopInt()                    zCall( 0x007A4C40 );
    void PopString( zSTRING& )      zCall( 0x007A4C50 );
    void CheckOverflow( int )       zCall( 0x007A4E10 );
    void Set( int, int )            zCall( 0x007A4E80 );
    int ReachedEnd()                zCall( 0x007A4E90 );
    void Clear()                    zCall( 0x007A4EA0 );
    void Save( zFILE* )             zCall( 0x007A4EB0 );
    void Load( zFILE* )             zCall( 0x007A4EF0 );

    // user API
    #include "zCPar_Stack.inl"
  };

  // sizeof 2004h
  class zCPar_DataStack {
  public:

    int stack[zMAX_SYM_DATASTACK]; // sizeof 2000h  offset 00h
    int sptr;                      // sizeof 04h    offset 2000h

    void zCPar_DataStack_OnInit() zCall( 0x007A4F50 );
    zCPar_DataStack()             zInit( zCPar_DataStack_OnInit() );
    ~zCPar_DataStack()            zCall( 0x007A4F70 );
    void Push( int )              zCall( 0x007A4F80 );
    int Pop()                     zCall( 0x007A5070 );
    float PopFloat()              zCall( 0x007A5090 );
    int IsEmpty()                 zCall( 0x007A5170 );
    void Clear()                  zCall( 0x007A5180 );

    // user API
    #include "zCPar_DataStack.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPARSER__SYMBOL_H__VER3__