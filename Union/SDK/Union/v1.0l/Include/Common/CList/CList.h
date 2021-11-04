// Supported with union (c) 2018-2021 Union team

#include "CListBase.h"

#ifndef __UNION_LIST_H__
#define __UNION_LIST_H__

namespace Common {
  template <class T>
  class CList : public CListBase
  {
  public:
    const CList* GetNext() const;
    CList* GetNext();
    const T* GetData() const;
    T*& GetData();
    void Insert( T* obj );
    void Remove( T* obj );
    void Delete( T* obj );
    const CList* GetAt( const uint32& idx ) const;
    CList* GetAt( const uint32& idx );
    const CList& operator [] ( const uint32& idx ) const;
    CList& operator [] ( const uint32& idx );
  };

  template <class T>
  const CList<T>* CList<T>::GetNext() const {
    return reinterpret_cast<CList<T>*>( next );
  }

  template <class T>
  CList<T>* CList<T>::GetNext() {
    return reinterpret_cast<CList<T>*>( next );
  }

  template <class T>
  const T* CList<T>::GetData() const {
    return reinterpret_cast<T*>( data );
  }

  template <class T>
  T*& CList<T>::GetData() {
    return reinterpret_cast<T*&>( data );
  }

  template <class T>
  void CList<T>::Insert( T* obj ) {
    CListBase::Insert( obj );
  }

  template <class T>
  void CList<T>::Remove( T* obj ) {
    CListBase::Remove( obj );
  }

  template <class T>
  void CList<T>::Delete( T* obj ) {
    CListBase::Remove( obj );
    delete obj;
  }

  template <class T> // safe
  const CList<T>* CList<T>::GetAt( const uint32& idx ) const
  {
    return reinterpret_cast<CList<T>*>(const_cast<CListBase*>(CListBase::GetAt( idx )));
  }

  template <class T> // safe
  CList<T>* CList<T>::GetAt( const uint32& idx )
  {
    return reinterpret_cast<CList<T>*>( CListBase::GetAt( idx ) );
  }

  template <class T> // Unsafe
  const CList<T>& CList<T>::operator[] ( const uint32& idx ) const
  {
    return *reinterpret_cast<CList<T>*>(const_cast<CListBase*>(CListBase::GetAt( idx )));
  }

  template <class T> // Unsafe
  CList<T>& CList<T>::operator[] ( const uint32& idx )
  {
    return *reinterpret_cast<CList<T>*>( CListBase::GetAt( idx ) );
  }
} // namespace Common

#endif // __UNION_LIST_H__