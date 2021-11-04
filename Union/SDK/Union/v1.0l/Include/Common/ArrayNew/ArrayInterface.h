// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARRAYINTERFACE_H__
#define __UNION_ARRAYINTERFACE_H__

namespace Common {
  template <class T>
  Array<T>::Array() {
    Allocator = new ArrayLocator<T>();
  }

  template <class T>
  Array<T>::Array( T* copy, const uint& count ) {
    Allocator = new ArrayLocator<T>();

    uint _count = count != Invalid ? count :
      shi_msize( copy ) / sizeof( T );

    Allocator->PrepareToReserveArray(count);
    for( uint i = 0; i < count; i++ )
      new(GetAllocator()) TObjectLocator<T>( copy[i] );
  }

  template <class T>
  Array<T>::Array( Array& other ) {
    Allocator = &other.GetAllocator();
    Allocator->AddReference();
  }

  template <class T>
  Array<T>::Array( const Array& other ) {
    Allocator = new ArrayLocator<T>();
    MergeArray( other );
  }

  template <class T>
  ArrayLocator<T>& Array<T>::GetAllocator() {
    return *Allocator;
  }

  template <class T>
  const ArrayLocator<T>& Array<T>::GetAllocator() const {
    return *Allocator;
  }

  template <class T>
  T& Array<T>::Create() {
    return (new(GetAllocator()) TObjectLocator<T>())->refObject;
  }

  template <class T>
  template <class O>
  T& Array<T>::Create( O init ) {
    return (new(GetAllocator()) TObjectLocator<T>( init ))->refObject;
  }

  template <class T>
  T& Array<T>::InsertEnd( const T& obj ) {
    return (new(GetAllocator()) TObjectLocator<T>( obj ))->refObject;
  }

  template <class T>
  T& Array<T>::Insert( const T& obj ) {
    return (new(GetAllocator()) TObjectLocator<T>( obj ))->refObject;
  }

  template <class T>
  T& Array<T>::InsertAt( const T& obj, const uint& index ) {
    return (new(GetAllocator(), index) TObjectLocator<T>( obj ))->refObject;
  }

  template <class T>
  T& Array<T>::InsertFront( const T& obj ) {
    return (new(GetAllocator(), 0) TObjectLocator<T>( obj ))->refObject;
  }

  template <class T>
  void Array<T>::Remove( const T& obj ) {
    uint index = SearchEqual( obj );
    if( index != Invalid ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
      delete Locator;
      GetAllocator().FreeAt( index );
    }
  }

  template <class T>
  void Array<T>::RemoveAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator;
    GetAllocator().FreeAt( index );
  }

  template <class T>
  void Array<T>::FastRemove( const T& obj ) {
    uint index = SearchEqual( obj );
    if( index != Invalid ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
      delete Locator;
      GetAllocator().FastFreeAt( index );
    }
  }

  template <class T>
  void Array<T>::FastRemoveAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator;
    GetAllocator().FastFreeAt( index );
  }

  template <class T>
  void Array<T>::RemoveAtBounds( const uint& index, const uint& count ) {
    for( uint i = 0; i < count; i++ ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index + i]);
      delete Locator;
    }

    GetAllocator().FreeAt( index, count );
  }

  template <class T>
  void Array<T>::Clear() {
    RemoveAtBounds( 0, GetNum() );
  }

  template <class T>
  void Array<T>::Delete( const T& obj ) {
    uint index = SearchEqual( obj );
    if( index != Invalid ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
      delete Locator->refObject;
      delete Locator;
      GetAllocator().FreeAt( index );
    }
  }

  template <class T>
  void Array<T>::DeleteAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator->refObject;
    delete Locator;
    GetAllocator().FreeAt( index );
  }
  
  template <class T>
  void Array<T>::FastDelete( const T& obj ) {
    uint index = SearchEqual( obj );
    if( index != Invalid ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
      delete Locator->refObject;
      delete Locator;
      GetAllocator().FastFreeAt( index );
    }
  }

  template <class T>
  void Array<T>::FastDeleteAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator->refObject;
    delete Locator;
    GetAllocator().FastFreeAt( index );
  }

  template <class T>
  void Array<T>::DeleteAtBounds( const uint& index, const uint& count ) {
    for( uint i = 0; i < count; i++ ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index + i]);
      delete Locator->refObject;
      delete Locator;
    }

    GetAllocator().FreeAt( index, count );
  }

  template <class T>
  void Array<T>::DeleteData() {
    DeleteAtBounds( 0, GetNum() );
  }

  template <class T>
  void Array<T>::MergeArray( const Array& other ) {
    Allocator->PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      new(GetAllocator()) TObjectLocator<T>( other[i] );
  }

  template <class T>
  void Array<T>::MergeArrayAt( const Array& other, const uint& index ) {
    Allocator->PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      new(GetAllocator(), index + i) TObjectLocator<T>( other[i] );
  }

  template <class T>
  Array<T>& Array<T>::operator += ( const T& obj ) {
    Insert( obj );
    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator += ( const Array& other ) {
    MergeArray( other );
    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator |= ( const T& obj ) {
    if( !HasEqual( obj ) )
      Insert( obj );

    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator |= ( const Array& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      (*this) |= other[i];

    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator -= ( const T& obj ) {
    Remove( obj );
    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator -= ( const Array& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      Remove( other[i] );

    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator ^= ( const T& obj ) {
    uint index = SearchEqual( obj );
    while( index != Invalid ) {
      RemoveAt( index );
      index = SearchEqual( obj, index );
    }

    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator ^= ( const Array& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      (*this) ^= other[i];

    return *this;
  }

  template <class T>
  Array<T>& Array<T>::operator = ( const Array& other ) {
    Clear();
    GetAllocator().PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      Insert( other[i] );

    return *this;
  }

  template <class T>
  bool Array<T>::operator == ( const Array& other ) const {
    return CompareLinear( other );
  }

  template <class T>
  bool Array<T>::operator & ( const T& obj ) const {
    return HasEqual( obj );
  }

  template <class T>
  bool Array<T>::CompareLinear( const Array& other ) const {
    if( GetNum() != other.GetNum() )
      return false;

    for( uint i = 0; i < GetNum(); i++ ) {
      if( GetAllocator()[i] != other[i] )
        return false;
    }

    return true;
  }

  template <class T>
  bool Array<T>::CompareInsorted( const Array& other ) const {
    uint size1 = GetNum();
    uint size2 = other.GetNum();
    if( size1 != size2 )
      return false;

    for( uint i = 0; i < size1; i++ ) {
      T&   Object  = GetAllocator()[i];
      uint Equals1 = NumberOfEqual( Object );
      uint Equals2 = other.NumberOfEqual( Object );
      if( Equals1 != Equals2 )
        return false;
    }

    return true;
  }

  template <class T>
  Array<T>& Array<T>::Normalize() {
    for( uint i = 0; i < GetNum() - 1; i++ )
      for( uint j = i + 1; j < GetNum(); j++ )
        if( GetAllocator()[i] == GetAllocator()[j] )
          RemoveAt( j-- );

    return *this;
  }

  template <class T>
  T& Array<T>::GetFirst() {
    return GetAllocator()[0];
  }

  template <class T>
  T& Array<T>::GetLast() {
    return GetAllocator()[GetNum() - 1];
  }

  template <class T>
  T& Array<T>::operator []( const uint& index ) {
    return GetAllocator()[index];
  }

  template <class T>
  T* Array<T>::GetSafe( const uint& index ) {
    if( index >= GetNum() )
      return Null;
    return &GetAllocator()[index];
  }

  template <class T>
  const T& Array<T>::operator []( const uint& index ) const {
    return GetAllocator()[index];
  }

  template <class T>
  const T* Array<T>::GetSafe( const uint& index ) const {
    if( index >= GetNum() )
      return Null;
    return &GetAllocator()[index];
  }

  template <class T>
  const T& Array<T>::GetFirst() const {
    return GetAllocator()[0];
  }

  template <class T>
  const T& Array<T>::GetLast() const {
    return GetAllocator()[GetNum() - 1];
  }

  template <class T> template<class O>
  bool Array<T>::HasEqual( const O& obj ) const {
    return SearchEqual( obj, 0 ) != Invalid;
  }

  template <class T> template<class O>
  uint Array<T>::SearchEqual( const O& obj, const uint& begin ) const {
    for( uint i = begin; i < GetNum(); i++ )
      if( (T&)GetAllocator()[i] == obj )
        return i;

    return Invalid;
  }

  template <class T> template<class O>
  uint Array<T>::CountOfEqual( const O& obj ) const {
    uint num = 0;
    for( uint i = 0; i < GetNum(); i++ )
      if( (T&)GetAllocator()[i] == obj )
        num++;

    return num;
  }

  template <class T>
  void Array<T>::ReleaseData() {
    for( uint i = GetNum() - 1; i != Invalid; i-- )
      GetAllocator()[i]->Release();
  }

  template <class T>
  T& Array<T>::InsertSorted( const T& obj ) {
    uint index = FindIndexForObject( obj );
    if( index == Invalid )
      return (new(GetAllocator()) TObjectLocator<T>( obj ))->refObject;

    return (new(GetAllocator(), index) TObjectLocator<T>( obj ))->refObject;
  }

  template <class T>
  void Array<T>::MergeArraySorted( const Array& other ) {
    MergeArray( other );
    QuickSort();
  }

  template <class T> template<class O>
  T& Array<T>::CreateSorted( const O& byObj ) {
    uint index = FindIndexForObject( byObj );
    return (new(GetAllocator(), index) TObjectLocator<T>())->refObject;
  }

  template <class T> template<class O>
  bool Array<T>::HasEqualSorted( const O& obj ) const {
    return SearchEqualSorted( obj ) != Invalid;
  }

  template <class T> template<class O>
  uint Array<T>::SearchEqualSorted( const O& obj ) const {
    if( GetNum() == 0 )
      return Invalid;

    uint Index = FindIndexForObject( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      return Index;

    return Invalid;
  }

  template <class T> template<class O>
  void Array<T>::RemoveSorted( const O& obj ) {
    uint Index = FindIndexForObject( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      RemoveAt( Index );
  }

  template <class T> template<class O>
  void Array<T>::DeleteSorted( const O& obj ) {
    uint Index = FindIndexForObject( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      DeleteAt( Index );
  }

  template <class T> template<class O>
  uint Array<T>::FindIndexForObject( const O& object ) const {
    if( GetNum() == 0 )
      return 0;

    ArrayLocator<T>& allocator = *Allocator;

    uint l = 0;
    uint r = GetNum();

#if 1
    while( true ) {
      int pivot = (l + r) / 2;
      if( allocator[pivot] == object )
        return pivot;

      bool upper = allocator[pivot] < object;

      if( r - l <= 1 )
        return upper ? r : l;

      if( upper )
        l = pivot;
      else
        r = pivot;
    }

#else
    uint left  = 0;
    uint right = GetNum();
    while( true ) {
      uint index = (left + right) / 2;
      
      const T& Object = allocator[index];
      bool swap = Object < object;

      // if object is on range of closest elements
      if( right - left <= 1 ) {
        return swap ? right : left;
      }

      swap ?
        left  = index :
        right = index;

      // if array belong to group of equal objects
      if( allocator[index] == object ) {
        return index;
      }
    }
#endif
  }

  template <class T>
  void Array<T>::Copy( T** ppmem, const uint& index, const uint& count ) {
    *ppmem = new T[count];
    for( uint i = 0; i < count; i++ )
      (*ppmem)[i] = GetAllocator()[index + i];
  }

  template <class T>
  uint Array<T>::GetNum() const {
    return GetAllocator().GetNum();
  }

  template <class T>
  bool Array<T>::IsEmpty() const {
    return GetAllocator().GetNum() == 0;
  }

  template <class T>
  uint Array<T>::GetTypeSize() const {
    return sizeof( T );
  }

  template <class T>
  void Array<T>::SetLocatorMultiplier( const uint& rate ) {
    GetAllocator().SetLocatorMultiplier( rate );
  }

  template <class T>
  void Array<T>::ShrinkToFit() {
    GetAllocator().ShrinkToFit();
  }

  template <class T>
  T* Array<T>::begin() {
    return &GetFirst();
  }

  template <class T>
  T* Array<T>::end() {
    return &GetLast() + 1;
  }

  template <class T>
  const T* Array<T>::begin() const {
    return &GetFirst();
  }

  template <class T>
  const T* Array<T>::end() const {
    return &GetLast() + 1;
  }

  template <class T>
  const ArrayLocator<T>& Array<T>::GetArrayLocator() const {
    return GetAllocator();
  }

  template <class T>
  Array<T>::~Array() {
    if( GetAllocator().GetRefCrf() == 1 )
      Clear();

    GetAllocator().Release();
  }

  

#pragma warning(disable:4244)
  template <class T>
  void Array<T>::QuickSort( uint low, uint hight ) {
    static const size_t sizeT = sizeof( T );

    ArrayLocator<T>& allocator = *Allocator;
    
    int64 i = low;
    int64 j = hight;

    T pivot = allocator[ (i + j) / 2 ];
    byte temp[sizeT];

    while( i <= j ) {
      while( allocator[i] < pivot )
        i++;

      while( allocator[j] > pivot )
        j--;

      if( i <= j ) {
        memcpy( temp,          &allocator[i], sizeT );
        memcpy( &allocator[i], &allocator[j], sizeT );
        memcpy( &allocator[j], temp,          sizeT );
        i++;
        j--;
      }
    }

    if( j > low )
      QuickSort( low, j );

    if( i < hight )
      QuickSort( i, hight );
  }
#pragma warning(default:4244)



  template <class T>
  Array<T>& Array<T>::QuickSort() {
    if( GetNum() > 1 )
      QuickSort( 0, GetNum() - 1 );

    return *this;
  }
}

#endif // __UNION_ARRAYINTERFACE_H__