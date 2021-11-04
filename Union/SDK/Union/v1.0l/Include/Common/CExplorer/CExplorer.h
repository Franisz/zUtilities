// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_EXPLORER_H__
#define __UNION_EXPLORER_H__

namespace Common
{
  typedef class ASTAPI CExplorer
  {
    friend class CExplorerMasked;
    CString   sFilter;
    WIN32_FIND_DATA mExplorer;
    HANDLE   hFile;

  public:

    CExplorer( CString );
    void Init( CString );                   // build thread by format
    bool FindBegin();                       // check current transaction validity
    bool FindNext();                        // find next hendler
    void FindEnd();                         // find stop
    text FileName();                        // name of found file
    bool IsFolder( bool intoOnly = true );  // check folder flag
    bool IsFile();                          // check file flag
    ~CExplorer();

  } WIN32FINDEXPLORER;

  class ASTAPI CExploreInfo
  {
    CString sRoot;
    CString sName;
    bool32 bIsDirectory;
    bool32 bIsEnd;
    uint32 ulFiles;
  public:
    CExploreInfo( WIN32_FIND_DATA& findData, const CString& root = NullStr );
    void SetBreakFlag() { bIsEnd = True; };
    bool32 GetBreakFlag() const { 
      return bIsEnd; 
    };
    void AddFile() { 
      ulFiles++; 
    };
    uint32 GetFilesCount() const { 
      return ulFiles; 
    };

    CString GetName() const;
    CString GetRoot() const;
    CString GetFullName() const;
    bool32 IsFile() const;
    bool32 IsDirectory() const;
  };

  class ASTAPI CExplorerMasked
  {
    CArrayOld<CExploreInfo*> arrFinded;
    CString sRoot;
    CString sFormat;

    void FindFiles( const CString& root, const CString& format );
  public:

    CExplorerMasked( const CString& root, const CString& format );
    void Begin();
    uint32 GetNum();
    const CExploreInfo* GetFileInfo( const uint32& index );
    ~CExplorerMasked();
  };
} // namespace Common

#endif // __UNION_EXPLORER_H__