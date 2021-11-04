// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_STRING_H__
#define __UNION_STRING_H__

/*
 * ISO 8859-1 (Latin-1), 
 * ISO 8859-15 (Latin-9), 
 * OEM 850, OEM 858, 
 * OEM 860:Portuguese, 
 * OEM 863:French, 
 * OEM-US. 
 * ------------------------
 * North & Western European
 */
#define               ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN 1252
#define CP_ICELANDIC  ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 15 */
#define CP_DANISH     ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1030 */
#define CP_GERMAN     ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1031 */
#define CP_ENGLISH    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1033 */
#define CP_SPANISH    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1034 & 3082 */
#define CP_FINNISH    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1035 */
#define CP_FRENCH     ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1036 */
#define CP_ITALIAN    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1040 */
#define CP_DUTCH      ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1043 */
#define CP_NORWEGIAN  ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1044 */
#define CP_PORTUGUESE ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1046 & 2070 */
#define CP_SWEDISH    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1053 */
#define CP_ESTONIAN   ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1061 */
#define CP_AFRIKAANS  ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1078 */
#define CP_SWAHILI    ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1089 */
#define CP_GALICIAN   ANSI_COPEDAGE_NORTHORWESTERN_EUROPEAN /* 1110 */

/*
 * ISO 8859-2 (Latin 2), 
 * OEM 852. 
 * --------------------------
 * Central & Eastern European
 */
#define                 ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN 1250
#define CP_CZECH        ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1029 */
#define CP_HUNGARIAN    ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1038 */
#define CP_POLISH       ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1045 */
#define CP_ROMANIAN     ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1048 */
#define CP_CROATIAN     ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1050 */
#define CP_SLOVAK       ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1051 */
#define CP_ALBANIAN     ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1052 */
#define CP_SLOVENIAN    ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 1060 */
#define CP_SERBIANLATIN ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 2074 */
#define CP_BOSNIAN      ANSI_COPEDAGE_CENTRALOREASTERN_EUROPEAN /* 5146 */

/*
 * ISO 8859-3 (Latin-3), 
 * ISO 8859-9 (Latin-5), 
 * OEM 857. 
 * --------
 * Turkish
 */
#define              ANSI_COPEDAGE_TURKISH 1254
#define CP_TURKISH   ANSI_COPEDAGE_TURKISH /* 1055 */
#define CP_ESPERANTO ANSI_COPEDAGE_TURKISH /* 9998 */
#define CP_KURDISH   ANSI_COPEDAGE_TURKISH /* 9999 */

/*
 * ISO 8859-4 (Latin-4), 
 * ISO 8859-13 (Latin-7), 
 * OEM 775.
 * ------
 * Baltic
 */
#define               ANSI_CODEPAGE_BALTIC 1257
#define CP_ESTONIAN   ANSI_CODEPAGE_BALTIC /* 1061 */
#define CP_LATVIAN    ANSI_CODEPAGE_BALTIC /* 1062 */
#define CP_LITHUANIAN ANSI_CODEPAGE_BALTIC /* 1063 */

/*
 * ISO 8859-5 (Latin/Cyrillic), 
 * KOI8-R, KOI8-U, 
 * Macintosh, 
 * OEM 855, 
 * OEM 856. 
 * --------
 * Cyrillic
 */
#define               ANSI_CODEPAGE_CYRILLIC 1251
#define CP_BULGARIAN  ANSI_CODEPAGE_CYRILLIC /* 1026 */
#define CP_RUSSIAN    ANSI_CODEPAGE_CYRILLIC /* 1049 */
#define CP_UKRAINIAN  ANSI_CODEPAGE_CYRILLIC /* 1058 */
#define CP_BELARUSIAN ANSI_CODEPAGE_CYRILLIC /* 1059 */
#define CP_MACEDONIAN ANSI_CODEPAGE_CYRILLIC /* 1071 */
#define CP_SERBIAN    ANSI_CODEPAGE_CYRILLIC /* 3098 */

/*
 * ISO 8859-6 (Latin/Arabic), 
 * OEM 720. 
 * ------
 * Arabic
 */
#define           ANSI_CODEPAGE_ARABIC 1256
#define CP_ARABIC ANSI_CODEPAGE_ARABIC /* 1025 */

/*
 * ISO 8859-7 (Latin/Greek), 
 * OEM 737, 
 * OEM 869. 
 * -----
 * Greek
 */
#define          ANSI_CODEPAGE_GREEK 1253
#define CP_GREEK ANSI_CODEPAGE_GREEK /* 1032 */

/*
 * ISO 8859-8 (Latin/Hebrew), 
 * OEM 862. 
 * ------
 * Hebrew
 */
#define           ANSI_CODEPAGE_HEBREW 1255
#define CP_HEBREW ANSI_CODEPAGE_HEBREW /* 1037 */

/*
 * ISO 8859-11 (Latin/Thai), 
 * TIS-620. 
 * ----
 * Thai
 */
#define         ANSI_CODEPAGE_THAI 874
#define CP_THAI ANSI_CODEPAGE_THAI /* 1054 */

/*
 * ISO 8859-14 (Latin-8). 
 * ------
 * Celtic
 */
#define           ANSI_CODEPAGE_CELTIC 1252
#define CP_WELSH  ANSI_CODEPAGE_CELTIC /* 1106 */
#define CP_BRETON ANSI_CODEPAGE_CELTIC /* 1150 */
#define CP_IRISH  ANSI_CODEPAGE_CELTIC /* 2108 */

/*
 * Shift-JIS. 
 * --------
 * Japanese
 */
#define             ANSI_CODEPAGE_JAPANESE 932
#define CP_JAPANESE ANSI_CODEPAGE_JAPANESE /* 1041 */

/*
 * EUC-KR. Korean
*/
#define           ANSI_CODEPAGE_KOREAN 949
#define CP_KOREAN ANSI_CODEPAGE_KOREAN /* 1042 */

/*
 * Big5(Traditional), 
 * GB2312(Simplified). 
 * -------
 * Chinese
*/
#define                ANSI_CODEPAGE_TRADCHINESE 950
#define CP_TRADCHINESE ANSI_CODEPAGE_TRADCHINESE /* 1028 */

/*
 * Vietnamese
 */
#define               ANSI_CODEPAGE_VIETNAMESE 1258
#define CP_VIETNAMESE ANSI_CODEPAGE_VIETNAMESE /* 1066 */

// #define ANSI_CODEPAGE_DEFAULT ANSI_CODEPAGE_CYRILLIC


namespace Common {
  ASTAPI uint ANSI_CODEPAGE_DEFAULT;

  class CStringA;
  class CStringW;

  class ASTAPI CStringBase
  {
    friend class CStringA;
    friend class CStringW;

  protected:
    uint32  ulRange;
    void32  lpPtr;
    uint32  ulLength;
    uint32  ulReserved;

  public:
    CStringBase ();

    virtual bool_t IsA () const=0;
    virtual bool_t IsW () const=0;

    // реинтерпретаторы [unsafe]
    UNSAFE const CStringA& ReinterpretToA () const;
    UNSAFE       CStringA& ReinterpretToA ();
    UNSAFE const CStringW& ReinterpretToW () const;
    UNSAFE       CStringW& ReinterpretToW ();

    virtual ~CStringBase ();
  };

  class ASTAPI CStringA : public CStringBase
  {
    friend class CDocumentA;

  protected:
    void Allocate();
    void Free();

  public:
    CStringA();
    CStringA( const CStringA& str );
    CStringA( const char& sym );
    CStringA( const char* vec );
    CStringA( const char* vec, const uint32& len );

    CStringA( const byte&    sym );
    CStringA( const int32&   val, const uint32& rad = 10 );
    CStringA( const uint32&  val, const uint32& rad = 10 );
    CStringA( const long32&  val, const uint32& rad = 10 );
    CStringA( const ulong32& val, const uint32& rad = 10 );
    CStringA( const int64&   val, const uint32& rad = 10 );
    CStringA( const uint64&  val, const uint32& rad = 10 );
    CStringA( const real32&  val, const uint32& dig = 3 );
    CStringA( const real64&  val, const uint32& dig = 3 );

    // + += = == []
    CStringA operator +   ( const CStringA& str ) const;
    CStringA operator +   ( const char*     var ) const;
    CStringA& operator += ( const CStringA& str );
    CStringA& operator += ( const char*     vec );
    CStringA& operator =  ( const CStringA& str );
    CStringA& operator =  ( const char*     vec );
    bool_t operator ==    ( const CStringA& str ) const;
    bool_t operator ==    ( const char*     vec ) const;
    bool_t operator !=    ( const CStringA& str ) const;
    bool_t operator !=    ( const char*     vec ) const;
    bool operator >       ( const CStringA& str ) const;
    bool operator <       ( const CStringA& str ) const;

    char& First();
    const char& First() const;
    char& Last();
    const char& Last() const;

    virtual bool_t IsA() const;
    virtual bool_t IsW() const;

    char& operator       [] ( const int32& idx );
    const char& operator [] ( const int32& idx ) const;
    operator const char* ( ) const;

    //
    uint32 ToInt32( const uint32& fromRad = 10 ) const;
    uint64 ToInt64( const uint32& fromRad = 10 ) const;
    real32 ToReal32() const;
    real64 ToReal64() const;
    bool_t IsNumber() const;
    bool_t IsHexNumber() const;

    // 
    text ToChar();
    const char* GetVector() const;
    uint32 Length() const;
    uint32 Allocated() const;
    bool_t IsEmpty() const;

    // I - no case sensitive
    bool_t Compare ( const CStringA& str ) const;
    bool_t Compare ( const char*     vec ) const;
    bool_t CompareI( const CStringA& str ) const;
    bool_t CompareI( const char*     vec ) const;

    bool_t CompareMasked ( const CStringA& str ) const;
    bool_t CompareMaskedI( const CStringA& str ) const;

    uint32 Search        ( const CStringA& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchI       ( const CStringA& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchReverse ( const CStringA& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchReverseI( const CStringA& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    bool_t HasWord       ( const CStringA& cmp  ) const;
    bool_t HasWordI      ( const CStringA& cmp  ) const;
    bool_t MatchesMask   ( const CStringA& mask ) const;
    bool_t StartWith     ( const CStringA& cmp  ) const;
    bool_t EndWith       ( const CStringA& cmp  ) const;

    CStringA GetWord  ( const CStringA& mask = " \t", const int32& num = 1 ) const;
    CStringA GetWordEx( const CStringA& mask = " \t", const int32& num = 1, const uint32& offset = 0, uint32* idx = Null ) const;

    CStringA GetPattern  ( const CStringA& lmask, const CStringA& rmask, const int32& num = 1 ) const;
    CStringA GetPatternEx( const CStringA& lmask, const CStringA& rmask, const int32& num = 1, const uint32& offset = 0, uint32* idx = Null ) const;
    Array<CStringA> Split( const CStringA& separator ) const;

    CStringA GetWordSmart  ( const int& word_index = 1, const bool& groupSymbols = false ) const;
    CStringA GetWordSmartEx( const int& word_index = 1, const bool& groupSymbols = false, const uint& offset = 0, uint* word_offset = Null ) const;

    CStringA GetSymbol  ( const CStringA* separators, const uint32& sep_num, const uint32& word_index = 1, uint32* inline_index = Null ) const;
    CStringA GetSymbolEx( const CStringA* separators, const uint32& sep_num, const CStringA** brackets, const uint32& br_num, const uint32& word_index = 1, uint32* inline_index = Null ) const;

    //
    CStringA& Reverse();
    void Clear();
    CStringA Copy( const uint32&   idx, const uint32& len ) const;
    CStringA& Cut( const uint32&   len );
    CStringA& Cut( const uint32&   idx, const uint32& len );
    CStringA& Put( const CStringA& str, const uint32& idx );
    CStringA& Put( const char*     vec, const uint32& idx );
    CStringA& Put( const CStringA& str, const uint32& idx, const uint32 count );
    CStringA& Put( const char*     vec, const uint32& idx, const uint32 count );
    CStringA& Replace( const CStringA& ptr1, const CStringA& ptr2, bool looped = false );

    CStringA& Shrink();
    CStringA& Shrink( char sym );
    CStringA& ShrinkFront();
    CStringA& ShrinkFront( char sym );
    CStringA& ShrinkBack();
    CStringA& ShrinkBack( char sym );

    CStringW AToW( const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT ) const;

    //
    CStringA& Upper();
    CStringA& Lower();
    CStringA& LowerFirstUpper();
  
    Array<CStringA> Regex_Search ( const CStringA& pattern ) const;
    CStringA        Regex_Match  ( const CStringA& pattern ) const;
    void            Regex_Replace( const CStringA& pattern, const CStringA& newSubStr );

    bool_t WriteToFile    ( const CStringA& fname, const bool_t& createDirs = True ) const;
    bool_t WriteToFileUTF8( const CStringA& fname, const bool_t& createDirs = True ) const;
    bool_t ReadFromFile   ( const CStringA& fname );
    bool_t ReadFromFile   ( const CStringW& fname );
    bool_t ReadFromVdf    ( const CStringA& fname, const long32& flags );

    static CStringA Hex32( const uint32& val );
    static CStringA Hex64( const uint64& val );
    static CStringA Combine( const text format ... );

    virtual ~CStringA();
  };

  class ASTAPI CStringW : public CStringBase
  {
    friend class CDocumentW;

  protected:
    void Allocate();
    void Free();

  public:
    CStringW();
    CStringW( const CStringW& str );
    CStringW( const wchar_t&  sym );
    CStringW( const wchar_t*  vec );
    CStringW( const wchar_t*  vec, const uint32& len );

    CStringW( const byte&    sym );
    CStringW( const int32&   val, const uint32& rad = 10 );
    CStringW( const uint32&  val, const uint32& rad = 10 );
    CStringW( const long32&  val, const uint32& rad = 10 );
    CStringW( const ulong32& val, const uint32& rad = 10 );
    CStringW( const int64&   val, const uint32& rad = 10 );
    CStringW( const uint64&  val, const uint32& rad = 10 );
    CStringW( const real32&  val, const uint32& dig = 3 );
    CStringW( const real64&  val, const uint32& dig = 3 );

    // + += = == []
    CStringW operator +   ( const CStringW& str ) const;
    CStringW operator +   ( const wchar_t*  var ) const;
    CStringW& operator += ( const CStringW& str );
    CStringW& operator += ( const wchar_t*  vec );
    CStringW& operator =  ( const CStringW& str );
    CStringW& operator =  ( const wchar_t*  vec );
    bool_t operator ==    ( const CStringW& str ) const;
    bool_t operator ==    ( const wchar_t*  vec ) const;
    bool_t operator !=    ( const CStringW& str ) const;
    bool_t operator !=    ( const wchar_t*  vec ) const;
    bool operator >       ( const CStringW& str ) const;
    bool operator <       ( const CStringW& str ) const;

          wchar_t& First();
    const wchar_t& First() const;
          wchar_t& Last();
    const wchar_t& Last()  const;

    virtual bool_t IsA() const;
    virtual bool_t IsW() const;

    wchar_t& operator       [] ( const int32& idx );
    const wchar_t& operator [] ( const int32& idx ) const;
    operator const wchar_t*    ( ) const;

    int32  ToInt32 ( const uint32& fromRad = 10 ) const;
    int64  ToInt64 ( const uint32& fromRad = 10 ) const;
    real32 ToReal32() const;
    real64 ToReal64() const;
    bool_t IsNumber() const;
    bool_t IsHexNumber() const;

    wtext ToWChar();
    const wchar_t* GetVector() const;
    uint32 Length() const;
    uint32 Allocated() const;
    bool_t IsEmpty() const;

    // I - no case sensitive
    bool_t Compare ( const CStringW& str ) const;
    bool_t Compare ( const wchar_t*  vec ) const;
    bool_t CompareI( const CStringW& str ) const;
    bool_t CompareI( const wchar_t*  vec ) const;

    bool_t CompareMasked ( const CStringW& str ) const;
    bool_t CompareMaskedI( const CStringW& str ) const;

    uint32 Search        ( const CStringW& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchI       ( const CStringW& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchReverse ( const CStringW& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    uint32 SearchReverseI( const CStringW& cmp, const uint32& pos = 0, const bool_t& end = False ) const;
    bool_t HasWord       ( const CStringW& cmp  ) const;
    bool_t HasWordI      ( const CStringW& cmp  ) const;
    bool_t MatchesMask   ( const CStringW& mask ) const;
    bool_t StartWith     ( const CStringW& cmp  ) const;
    bool_t EndWith       ( const CStringW& cmp  ) const;

    CStringW GetWord  ( const CStringW& mask = L" \t", const int32& num = 1 ) const;
    CStringW GetWordEx( const CStringW& mask = L" \t", const int32& num = 1, const uint32& offset = 0, uint32* idx = Null ) const;

    CStringW GetPattern  ( const CStringW& lmask, const CStringW& rmask, const int32& num = 1 ) const;
    CStringW GetPatternEx( const CStringW& lmask, const CStringW& rmask, const int32& num = 1, const uint32& offset = 0, uint32* idx = Null ) const;
    Array<CStringW> Split( const CStringW& separator ) const;

    CStringW GetWordSmart  ( const int& word_index = 1, const bool& groupSymbols = false ) const;
    CStringW GetWordSmartEx( const int& word_index = 1, const bool& groupSymbols = false, const uint& offset = 0, uint* word_offset = Null ) const;

    CStringW GetSymbol  ( const CStringW* separators, const uint32& sep_num, const uint32& word_index = 1, uint32* inline_index = Null ) const;
    CStringW GetSymbolEx( const CStringW* separators, const uint32& sep_num, const CStringW** brackets, const uint32& br_num, const uint32& word_index = 1, uint32* inline_index = Null ) const;

    //
    CStringW& Reverse();
    void Clear();
    CStringW Copy( const uint32& idx, const uint32& len ) const;
    CStringW& Cut( const uint32& idx, const uint32& len );
    CStringW& Cut( const uint32& len );
    CStringW& Put( const CStringW& str, const uint32& idx );
    CStringW& Put( const wchar_t*  vec, const uint32& idx );
    CStringW& Put( const CStringW& str, const uint32& idx, const uint32 count );
    CStringW& Put( const wchar_t*  vec, const uint32& idx, const uint32 count );
    CStringW& Replace( const CStringW& ptr1, const CStringW& ptr2, bool looped = false );

    CStringW& Shrink();
    CStringW& Shrink( wchar_t sym );
    CStringW& ShrinkFront();
    CStringW& ShrinkFront( wchar_t sym );
    CStringW& ShrinkBack();
    CStringW& ShrinkBack( wchar_t sym );

    CStringA WToA( const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT ) const;

    //
    CStringW& Upper();
    CStringW& Lower();
    CStringW& LowerFirstUpper();
  
    Array<CStringW> Regex_Search ( const CStringW& pattern ) const;
    CStringW        Regex_Match  ( const CStringW& pattern ) const;
    void            Regex_Replace( const CStringW& pattern, const CStringW& newSubStr );

    bool_t WriteToFile    ( const CStringW& fname, const uint32& srcCodePage, const bool_t& createDirs = True ) const;
    bool_t WriteToFile    ( const CStringW& fname, const bool_t& createDirs = True ) const;
    bool_t WriteToFile    ( const CStringA& fname, const bool_t& createDirs = True ) const;
    bool_t WriteToFileUTF8( const CStringW& fname, const bool_t& createDirs = True ) const;
    bool_t ReadFromFile   ( const CStringW& fname, const uint32& srcCodePage );
    bool_t ReadFromFile   ( const CStringW& fname );
    bool_t ReadFromFile   ( const CStringA& fname );
    bool_t ReadFromVdf    ( const CStringW& fname, const long32& flags, const uint32& srcCodePage );
    bool_t ReadFromVdf    ( const CStringW& fname, const long32& flags );

    static CStringW Hex32( const uint32& val );
    static CStringW Hex64( const uint64& val );
    static CStringW Combine( const wtext format ... );

    virtual ~CStringW();
  };




  enum ELineBreak {
    LB_CR,   // 0x0D          carriage return
    LB_LF,   // 0x0A          line feed
    LB_CRLF, // 0x0D + 0x0A   
    LB_NEL,  // 0x85          next line
    LB_LS,   // Unicode 2028  line separator
    LB_PS,   // Unicode 2029  paragraph separator
    LB_EOF,  // 0x0           End of file
    LB_Unknown = -1
  };




  struct ASTAPI UTF8Char {
    byte octet[4];

    UTF8Char();
    UTF8Char( byte* memory );
    UTF8Char( uint uni );
    UTF8Char( wchar uni );
    UTF8Char( char ansi );

    wchar ToUnicode16();
    uint  ToUnicode24();

    operator wchar();
    byte operator []( uint i );

    uint Length();
    void Show();
    void Reset();
    void ToUTF8( byte* memory );
    void ToUTF8( uint uniw );

    static uint CharSize( uint uni24 );
    static uint CharSize( wchar uni16 );

  protected:
    uint LengthByOctets();
  };




  class ASTAPI UTF8StringConverter {
    Array<byte> utf8;
  public:

    void ToUTF8   ( CStringA src, const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT );
    void ToUTF8   ( CStringW src );
    void ToUnicode( CStringW& dst );
    void ToAnsi   ( CStringA& dst, const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT );

    bool_t WriteToFile ( CStringA fileName, const ELineBreak& lb = LB_CRLF );
    bool_t WriteToFile ( CStringW fileName, const ELineBreak& lb = LB_CRLF );
    bool_t ReadFromFile( CStringA fileName );
    bool_t ReadFromFile( CStringW fileName, const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT );
    bool_t ReadFromVdf ( CStringA fileName, const long& flags );
    bool_t ReadFromVdf ( CStringW fileName, const long& flags, const uint32& srcCodePage = ANSI_CODEPAGE_DEFAULT );
  };






  #ifdef UNICODE
  typedef CStringW CString, wstring;
  #else
  typedef CStringA CString, string;
  #endif
  
  typedef CStringA astring;
  typedef CStringW wstring;

  #define A (CStringA)
  #define W (CStringW)
  #define Z (zSTRING)
  #define AHEX32(v) CStringA::Hex32( (uint32)v )
  #define AHEX64(v) CStringA::Hex64( (uint64)v )
  #define WHEX32(v) CStringW::Hex32( (uint32)v )
  #define WHEX64(v) CStringW::Hex64( (uint64)v )


  enum EStringFormat : byte
  {
    FMT_SINT32  = (char)'i',  // signed long
    FMT_SINT64  = (char)'I',  // signed long long
    FMT_UINT32  = (char)'u',  // unsigned long
    FMT_UINT64  = (char)'U',  // unsigned long long
    FMT_HEX32   = (char)'x',  // 10 to 16 system x32
    FMT_HEX64   = (char)'X',  // 10 to 16 system x64
    FMT_REAL32  = (char)'f',  // float
    FMT_REAL64  = (char)'F',  // double
    FMT_BOOL    = (char)'b',  // boolean
    FMT_CHAR    = (char)'c',  // char
    FMT_BYTE    = (char)'B',  // byte
    FMT_TEXT    = (char)'t',  // char array
    FMT_STRING  = (char)'s',  // string
    FMT_TITLE   = (char)'r',  // running title
    FMT_ZSTRING = (char)'z'   // ansi strings
  };
} // namespace Common

#include "CStringOperators.inl"

#endif // __UNION_STRING_H__