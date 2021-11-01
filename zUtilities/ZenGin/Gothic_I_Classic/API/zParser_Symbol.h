// Supported with union (c) 2018-2021 Union team

#ifndef __ZPARSER__SYMBOL_H__VER0__
#define __ZPARSER__SYMBOL_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 0Ch
  class zCPar_StringTable {
  public:
    zCArray<zSTRING*> array; // sizeof 0Ch    offset 00h

    zCPar_StringTable() {}
    void zCPar_StringTable_OnInit( int ) zCall( 0x006F7520 );
    zCPar_StringTable( int a0 )          zInit( zCPar_StringTable_OnInit( a0 ));
    ~zCPar_StringTable()                 zCall( 0x006F75D0 );
    void Clear()                         zCall( 0x006F7650 );
    zSTRING* Insert( zSTRING& )          zCall( 0x006F7680 );
    int GetLastEntry()                   zCall( 0x006F7800 );
    zSTRING* GetString( int )            zCall( 0x006F7810 );
    void Save( zSTRING& )                zCall( 0x006F7830 );
    void Load( zSTRING& )                zCall( 0x006F7950 );
    void ShrinkToFit()                   zCall( 0x006F7B00 );
    void Show()                          zCall( 0x006F7B90 );

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

    void zCPar_Symbol_OnInit()                  zCall( 0x006F7D20 );
    zCPar_Symbol()                              zInit( zCPar_Symbol_OnInit() );
    ~zCPar_Symbol()                             zCall( 0x006F7D80 );
    void AllocSpace()                           zCall( 0x006F7E50 );
    void* GetDataAdr( int )                     zCall( 0x006F8140 );
    void SetDataAdr( void* )                    zCall( 0x006F8440 );
    void SetFlag( int )                         zCall( 0x006F8450 );
    int HasFlag( int )                          zCall( 0x006F8480 );
    void SetParent( zCPar_Symbol* )             zCall( 0x006F84A0 );
    zCPar_Symbol* GetParent()                   zCall( 0x006F84B0 );
    void* GetInstanceAdr()                      zCall( 0x006F84C0 );
    zCPar_Symbol* GetNext()                     zCall( 0x006F84D0 );
    int ArrayCheck( int )                       zCall( 0x006F84E0 );
    void GetStackPos( int&, int )               zCall( 0x006F8510 );
    void SetStackPos( int, int )                zCall( 0x006F8520 );
    void SetValue( int, int )                   zCall( 0x006F8530 );
    void SetValue( float, int )                 zCall( 0x006F8560 );
    void SetValue( zSTRING&, int )              zCall( 0x006F8590 );
    void GetValue( int&, int )                  zCall( 0x006F86E0 );
    void GetValue( float&, int )                zCall( 0x006F8710 );
    void GetValue( zSTRING&, int )              zCall( 0x006F8740 );
    void SetLineData( int, int, int, int )      zCall( 0x006F8890 );
    void GetLineData( int&, int&, int&, int& )  zCall( 0x006F8B00 );
    void SetFileNr( int )                       zCall( 0x006F8B40 );
    void Save( zFILE* )                         zCall( 0x006F8C00 );
    void SaveFull( zFILE* )                     zCall( 0x006F8E20 );
    void LoadFull( zFILE* )                     zCall( 0x006F9080 );
    void Load( zFILE* )                         zCall( 0x006F9250 );
    void SetOffset( int )                       zCall( 0x006F9400 );
    int GetOffset()                             zCall( 0x006F9410 );
    void SetClassOffset( int )                  zCall( 0x006F9420 );
    int GetClassOffset()                        zCall( 0x006F9430 );
    static void SetUseInstance( zCPar_Symbol* ) zCall( 0x006F7BE0 );
    static void SetUseInstanceAdr( void* )      zCall( 0x006F7D00 );
    static void* GetUseInstance()               zCall( 0x006F7D10 );

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
    void zCPar_SymbolTable_OnInit( int )              zCall( 0x006F9440 );
    zCPar_SymbolTable( int a0 )                       zInit( zCPar_SymbolTable_OnInit( a0 ));
    ~zCPar_SymbolTable()                              zCall( 0x006F9590 );
    void Clear()                                      zCall( 0x006F9600 );
    void PreAlloc( int )                              zCall( 0x006F96F0 );
    void Save( zFILE* )                               zCall( 0x006F97F0 );
    void Load( zFILE* )                               zCall( 0x006F9970 );
    int IsIn( zCPar_Symbol* )                         zCall( 0x006F9D80 );
    int IsIn( zSTRING const& )                        zCall( 0x006F9E90 );
    int GetIndex( zCPar_Symbol* )                     zCall( 0x006F9FA0 );
    int GetIndex( zSTRING const& )                    zCall( 0x006FA090 );
    int GetIndex( zSTRING const&, int )               zCall( 0x006FA180 );
    int __fastcall Search( zSTRING const&, int, int ) zCall( 0x006FA290 );
    zCPar_Symbol* GetSymbol( zSTRING const& )         zCall( 0x006FA370 );
    zCPar_Symbol* GetSymbol( int )                    zCall( 0x006FA410 );
    int Insert( zCPar_Symbol* )                       zCall( 0x006FA430 );
    void InsertEnd( zCPar_Symbol* )                   zCall( 0x006FA690 );
    void ShrinkToFit()                                zCall( 0x006FA8B0 );
    void SetSize( int )                               zCall( 0x006FA9A0 );
    int GetNumInList()                                zCall( 0x006FAA70 );
    zCPar_Symbol* GetLastSymbol()                     zCall( 0x006FAA80 );
    zCPar_Symbol* GetFirstSymbol()                    zCall( 0x006FAA90 );
    void Show()                                       zCall( 0x006FAAA0 );
    static int Compare( void const*, void const* )    zCall( 0x006F9770 );

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
    void zCPar_Stack_OnInit( int )  zCall( 0x006FB000 );
    zCPar_Stack( int a0 )           zInit( zCPar_Stack_OnInit( a0 ));
    ~zCPar_Stack()                  zCall( 0x006FB040 );
    int GetPopPos()                 zCall( 0x006FB060 );
    void SetPopPos( int )           zCall( 0x006FB070 );
    int GetDynSize()                zCall( 0x006FB080 );
    int GetStatSize()               zCall( 0x006FB090 );
    void PushByte( unsigned char )  zCall( 0x006FB0A0 );
    void PushWord( unsigned short ) zCall( 0x006FB0C0 );
    void PushInt( int )             zCall( 0x006FB0E0 );
    void PushString( zSTRING& )     zCall( 0x006FB100 );
    unsigned char PopByte()         zCall( 0x006FB170 );
    unsigned short PopWord()        zCall( 0x006FB180 );
    int PopInt()                    zCall( 0x006FB190 );
    void PopString( zSTRING& )      zCall( 0x006FB1A0 );
    void CheckOverflow( int )       zCall( 0x006FB360 );
    void Set( int, int )            zCall( 0x006FB3E0 );
    int ReachedEnd()                zCall( 0x006FB3F0 );
    void Clear()                    zCall( 0x006FB400 );
    void Save( zFILE* )             zCall( 0x006FB410 );
    void Load( zFILE* )             zCall( 0x006FB450 );

    // user API
    #include "zCPar_Stack.inl"
  };

  // sizeof 1004h
  class zCPar_DataStack {
  public:
    int stack[1024]; // sizeof 1000h  offset 00h
    int sptr;        // sizeof 04h    offset 1000h

    void zCPar_DataStack_OnInit() zCall( 0x006FB4C0 );
    zCPar_DataStack()             zInit( zCPar_DataStack_OnInit() );
    ~zCPar_DataStack()            zCall( 0x006FB4E0 );
    void Push( int )              zCall( 0x006FB4F0 );
    int Pop()                     zCall( 0x006FB510 );
    float PopFloat()              zCall( 0x006FB530 );
    int IsEmpty()                 zCall( 0x006FB550 );
    void Clear()                  zCall( 0x006FB560 );

    // user API
    #include "zCPar_DataStack.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPARSER__SYMBOL_H__VER0__