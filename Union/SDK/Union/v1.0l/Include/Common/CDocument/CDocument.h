// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_DOCUMENT_H__
#define __UNION_DOCUMENT_H__

namespace Common {

  class ASTAPI CLineA {
    friend class CDocumentA;

    CDocumentA* pParent;
    CStringA    sLine;
    CLineA*     pPrev;
    CLineA*     pNext;
  public:
    CDocumentA* GetParent();
    CLineA*&    GetPrev();
    CLineA*&    GetNext();
    CStringA&   GetData();
    operator CStringA&( );

    const CDocumentA* GetParent() const;
    const CLineA*&    GetPrev() const;
    const CLineA*&    GetNext() const;
    const CStringA&   GetData() const;
    operator const CStringA&( ) const;

    CLineA( CDocumentA* parent );
    ~CLineA();
  };

  class ASTAPI CDocumentA
  {
    CArrayOld<CLineA*> arrLines;
  protected:
    void InsertLine( CLineA* line, const uint32& idx );
  public:
    CLineA* GetLine( const uint32& idx ) const;
    CLineA* GetLineBySym( const uint32& idx ) const;
    uint32  GetLineIndex( const CLineA& ln ) const;
    char    GetSym( const uint32& idx ) const;
    void    SetSym( const char& sym, const uint32& idx );
    CLineA* InsertLines( const CStringA& str );
    CLineA* InsertLinesAt( const CStringA& str, const uint32& idx );
    void    RemoveLines( CLineA& ln, const uint32& len = 1 );
    void    RemoveLinesAt( const uint32& idx, const uint32& len = 1 );
    CLineA& operator [] ( const uint32& idx ) const;
    void    operator = ( const CStringA& str );
    CLineA* operator += ( const CStringA& str );
    uint32  GetNum() const;
    void    ToString( CStringA& str, const ELineBreak& ansi = LB_CRLF ) const;
    bool32  ReadFromFile( const CStringA& );
    bool32  WriteToFile( const CStringA&, const ELineBreak& ansi = LB_CRLF );
    void    Clear();
    CDocumentA();
    CDocumentA( const CStringA& data );
    virtual ~CDocumentA();
  };





  class ASTAPI CLineW {
    friend class CDocumentW;

    CDocumentW* pParent;
    CStringW    sLine;
    CLineW*     pPrev;
    CLineW*     pNext;
  public:
    CDocumentW* GetParent();
    CLineW*&    GetPrev();
    CLineW*&    GetNext();
    CStringW&   GetData();
    operator CStringW&();

    const CDocumentW* GetParent() const;
    const CLineW*&    GetPrev() const;
    const CLineW*&    GetNext() const;
    const CStringW&   GetData() const;
    operator const CStringW&() const;

    CLineW( CDocumentW* parent );
    ~CLineW();
  };

  class ASTAPI CDocumentW
  {
    CArrayOld<CLineW*> arrLines;
  protected:
    void InsertLine( CLineW* line, const uint32& idx );
  public:
    CLineW* GetLine( const uint32& idx ) const;
    CLineW* GetLineBySym( const uint32& idx ) const;
    uint32  GetLineIndex( const CLineW& ln ) const;
    wchar_t GetSym( const uint32& idx ) const;
    void    SetSym( const wchar_t& sym, const uint32& idx );
    CLineW* InsertLines( const CStringW& str );
    CLineW* InsertLinesAt( const CStringW& str, const uint32& idx );
    void    RemoveLines( CLineW& ln, const uint32& len = 1 );
    void    RemoveLinesAt( const uint32& idx, const uint32& len = 1 );
    CLineW& operator [] ( const uint32& idx ) const;
    void    operator = ( const CStringW& str );
    CLineW* operator += ( const CStringW& str );
    uint32  GetNum() const;
    void    ToString( CStringW& str, const ELineBreak& ansi = LB_CRLF ) const;
    bool32  ReadFromFile( const CStringW& );
    bool32  WriteToFile( const CStringW&, const ELineBreak& ansi = LB_CRLF );
    void    Clear();
    CDocumentW();
    CDocumentW( const CStringW& data );
    virtual ~CDocumentW();
  };

#ifdef UNICODE
  typedef CDocumentW CDocument;
  typedef CLineW CLine;
#else
  typedef CDocumentA CDocument, rowString;
  typedef CLineA CLine;
#endif
} // namespace Common

#endif // __UNION_DOCUMENT_H__