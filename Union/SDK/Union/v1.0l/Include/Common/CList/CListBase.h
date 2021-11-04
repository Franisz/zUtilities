// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_LIST_BASE_H__
#define __UNION_LIST_BASE_H__

namespace Common {
  class ASTAPI CListBase
  {
  protected:
    void32 data;
    CListBase* next;

    CListBase();
    CListBase* GetNext();
    const CListBase* GetNext() const;
    void32 GetData();
    const void32 GetData() const;
    void Insert( void32 obj );
    void Remove( void32 obj );
    void Delete( void32 obj );
    CListBase* GetAt( const uint32& idx );
    const CListBase*  GetAt( const uint32& idx ) const;
    CListBase&  operator [] ( const uint32& idx );
    const CListBase& operator [] ( const uint32& idx ) const;

  public:
    BOOL IsInList( void32 obj ) const;
    uint32 GetNumInList() const;
    operator const void32() const;
    operator void32();
    void DeleteList();
    void DeleteListDatas();
    ~CListBase();
  };
} // namespace Common

#endif // __UNION_LIST_BASE_H__