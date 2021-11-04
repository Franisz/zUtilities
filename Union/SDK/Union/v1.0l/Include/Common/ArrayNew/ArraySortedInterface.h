// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARRAYSORTEDINTERFACE_H__
#define __UNION_ARRAYSORTEDINTERFACE_H__

namespace Common {
  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArrayLocator<T>& ArraySorted<T, FUNC>::GetAllocator() {
    return *Allocator;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const ArrayLocator<T>& ArraySorted<T, FUNC>::GetAllocator() const {
    return *Allocator;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::ArraySorted() {
    Allocator = new ArrayLocator<T>();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::ArraySorted( T* copy, const uint& count ) {
    Allocator = new ArrayLocator<T>();
    ArrayLocator<T>& allocator = *Allocator;

    uint _count = count != Invalid ? count :
      shi_msize( copy ) / sizeof( T );

    allocator.PrepareToReserveArray( _count );
    for( uint i = 0; i < _count; i++ )
      new(allocator) TObjectLocator<T>( copy[i] );

    QuickSort();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::ArraySorted( ArraySorted& other ) {
    Allocator = &other.GetAllocator();
    Allocator->AddReference();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::ArraySorted( const ArraySorted& other ) {
    Allocator = new ArrayLocator<T>();
    MergeArray( other );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::ArraySorted( const Array<T>& other ) {
    Allocator = new ArrayLocator<T>();
    MergeArray( other );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T& ArraySorted<T, FUNC>::Insert( const T& obj ) {
    uint index = FindIndexForObject<FUNC>( obj );
    //if( index == Invalid )
    //  return (new(GetAllocator()) TObjectLocator<T>( obj ))->refObject;

    return (new(GetAllocator(), index) TObjectLocator<T>( obj ))->refObject;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  T& ArraySorted<T, FUNC>::Create( const O& byObj ) {
    uint index = FindIndexForObject( byObj );
    return (new(GetAllocator(), index) TObjectLocator<T>())->refObject;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::Remove( const T& obj ) {
    Remove<FUNC>( obj );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  void ArraySorted<T, FUNC>::Remove( const O& obj ) {
    uint Index = FindIndexForObject<FUNC>( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      RemoveAt( Index );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::RemoveAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator;
    GetAllocator().FreeAt( index );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::RemoveAtBounds( const uint& index, const uint& count ) {
    for( uint i = 0; i < count; i++ ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index + i]);
      delete Locator;
    }

    GetAllocator().FreeAt( index, count );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::Clear() {
    RemoveAtBounds( 0, GetNum() );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::Delete( const T& obj ) {
    Remove<FUNC>( obj );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  void ArraySorted<T, FUNC>::Delete( const O& obj ) {
    uint Index = FindIndexForObject<FUNC>( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      DeleteAt( Index );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::DeleteAt( const uint& index ) {
    TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index]);
    delete Locator->refObject;
    delete Locator;
    GetAllocator().FreeAt( index );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::DeleteAtBounds( const uint& index, const uint& count ) {
    for( uint i = 0; i < count; i++ ) {
      TObjectLocator<T>* Locator = reinterpret_cast<TObjectLocator<T>*>(&GetAllocator()[index + i]);
      delete Locator->refObject;
      delete Locator;
    }

    GetAllocator().FreeAt( index, count );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::DeleteData() {
    DeleteAtBounds( 0, GetNum() );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::MergeArray( const ArraySorted& other ) {
    Allocator->PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      new(GetAllocator()) TObjectLocator<T>( other[i] );

    QuickSort();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::MergeArray( const Array<T>& other ) {
    Allocator->PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      new(GetAllocator()) TObjectLocator<T>( other[i] );

    QuickSort();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator += ( const T& obj ) {
    Insert( obj );
    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator += ( const ArraySorted& other ) {
    MergeArray( other );
    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator |= ( const T& obj ) {
    if( !HasEqual( obj ) )
      Insert( obj );

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator |= ( const ArraySorted& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      (*this) |= other[i];

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator -= ( const T& obj ) {
    Remove<FUNC>( obj );
    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator -= ( const ArraySorted& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      Remove<FUNC>( other[i] );

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator ^= ( const T& obj ) {
    uint index = SearchEqual<FUNC>( obj );
    while( index != Invalid ) {
      RemoveAt( index );
      index = SearchEqual<FUNC>( obj, index );
    }

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator ^= ( const ArraySorted& other ) {
    for( uint i = 0; i < other.GetNum(); i++ )
      (*this) ^= other[i];

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator = ( const ArraySorted& other ) {
    Clear();
    GetAllocator().PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      Insert( other[i] );

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::operator = ( const Array<T>& other ) {
    Clear();
    GetAllocator().PrepareToReserveArray( other.GetNum() );
    for( uint i = 0; i < other.GetNum(); i++ )
      Insert( other[i] );

    QuickSort();
    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  bool ArraySorted<T, FUNC>::operator == ( const ArraySorted& other ) const {
    return Compare( other );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  bool ArraySorted<T, FUNC>::operator & ( const T& obj ) const {
    return HasEqual<FUNC>( obj );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  bool ArraySorted<T, FUNC>::Compare( const ArraySorted& other ) const {
    if( GetNum() != other.GetNum() )
      return false;

    for( uint i = 0; i < GetNum(); i++ )
      if( GetAllocator()[i] != other[i] )
        return false;

    return true;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::Normalize() {
    for( uint i = 0; i < GetNum() - 1; i++ )
      for( uint j = i + 1; j < GetNum(); j++ )
        if( GetAllocator()[i] == GetAllocator()[j] )
          RemoveAt( j-- );

    return *this;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T& ArraySorted<T, FUNC>::GetFirst() {
    return GetAllocator()[0];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T& ArraySorted<T, FUNC>::GetLast() {
    return GetAllocator()[GetNum() - 1];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T& ArraySorted<T, FUNC>::GetFirst() const {
    return GetAllocator()[0];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T& ArraySorted<T, FUNC>::GetLast() const {
    return GetAllocator()[GetNum() - 1];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T* ArraySorted<T, FUNC>::GetSafe( const uint& index ) {
    if( index >= GetNum() )
      return Null;

    return &GetAllocator()[index];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T* ArraySorted<T, FUNC>::GetSafe( const uint& index ) const {
    if( index >= GetNum() )
      return Null;

    return &GetAllocator()[index];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T& ArraySorted<T, FUNC>::operator []( const uint& index ) {
    return GetAllocator()[index];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T& ArraySorted<T, FUNC>::operator []( const uint& index ) const {
    return GetAllocator()[index];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  bool ArraySorted<T, FUNC>::HasEqual( const T& obj ) const {
    return SearchEqual<FUNC>( obj, 0 ) != Invalid;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  bool ArraySorted<T, FUNC>::HasEqual( const O& obj ) const {
    return SearchEqual<FUNC>( obj, 0 ) != Invalid;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  uint ArraySorted<T, FUNC>::SearchEqual( const T& obj, const uint& begin ) const {
    return SearchEqual<FUNC>( obj, begin );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  uint ArraySorted<T, FUNC>::SearchEqual( const O& obj, const uint& begin ) const {
    if( GetNum() == 0 )
      return Invalid;

    uint Index = FindIndexForObject<FUNC>( obj );
    if( Index < GetNum() && GetAllocator()[Index] == obj )
      return Index;

    return Invalid;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  uint ArraySorted<T, FUNC>::CountOfEqual( const T& obj ) const {
    return CountOfEqual<FUNC>( obj );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  uint ArraySorted<T, FUNC>::CountOfEqual( const O& obj ) const {
    uint count = 0;
    for( uint i = 0; i < GetNum(); i++ )
      if( obj == GetAllocator()[i] )
        count++;

    return count;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::ReleaseData() {
    for( uint i = GetNum() - 1; i != Invalid; i-- )
      GetAllocator()[i]->Release();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  uint ArraySorted<T, FUNC>::FindIndexForObject( const T& obj ) const {
    return FindIndexForObject<FUNC>( obj );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)> template<void* LAMBDA, class O>
  uint ArraySorted<T, FUNC>::FindIndexForObject( const O& object ) const {
    typedef bool( __cdecl* LPFUNC )(const O&, const T&);
    static LPFUNC Lambda = (LPFUNC)LAMBDA;

    if( GetNum() == 0 )
      return 0;

    ArrayLocator<T>& allocator = *Allocator;

    uint l = 0;
    uint r = GetNum();

    while( true ) {
      int pivot = (l + r) / 2;
      if( allocator[pivot] == object )
        return pivot;

      bool upper = Lambda( object, allocator[pivot] );

      if( r - l <= 1 )
        return upper ? r : l;

      if( upper )
        l = pivot;
      else
        r = pivot;
    }

#if 0
    if( GetNum() == 0 )
      return 0;

    ArrayLocator<T>& allocator = *Allocator;

    uint left = 0;
    uint right = GetNum();
    while( true ) {
      uint index = (left + right) / 2;

      const T& Object = allocator[index];
      bool swap = Lambda( obj, Object );

      // if object is on range of closest elements
      if( right - left <= 1 )
        return swap ? right : left;

      swap ?
        left = index :
        right = index;

      // if array belong to group of equal objects
      if( allocator[index] == obj )
        return index;
    }
#endif
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::Copy( T** ppmem, const uint& index, const uint& count ) {
    *ppmem = new T[count];
    for( uint i = 0; i < count; i++ )
      (*ppmem)[i] = GetAllocator()[index + i];
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  uint ArraySorted<T, FUNC>::GetNum() const {
    return GetAllocator().GetNum();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  bool ArraySorted<T, FUNC>::IsEmpty() const {
    return GetAllocator().GetNum() == 0;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  uint ArraySorted<T, FUNC>::GetTypeSize() const {
    return sizeof( T );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::SetLocatorMultiplier( const uint& rate ) {
    GetAllocator().SetLocatorMultiplier( rate );
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::ShrinkToFit() {
    GetAllocator().ShrinkToFit();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T* ArraySorted<T, FUNC>::begin() {
    return &GetFirst();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  T* ArraySorted<T, FUNC>::end() {
    return &GetLast() + 1;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T* ArraySorted<T, FUNC>::begin() const {
    return &GetFirst();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const T* ArraySorted<T, FUNC>::end() const {
    return &GetLast() + 1;
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  const ArrayLocator<T>& ArraySorted<T, FUNC>::GetArrayLocator() const {
    return GetAllocator();
  }



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>::~ArraySorted() {
    if( GetAllocator().GetRefCrf() == 1 )
      Clear();

    GetAllocator().Release();
  }



#pragma warning(disable:4244)
  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  void ArraySorted<T, FUNC>::QuickSort( uint low, uint hight ) {
    static const size_t sizeT = sizeof( T );

    ArrayLocator<T>& allocator = *Allocator;

    int64 i = low;
    int64 j = hight;

    T pivot = allocator[(i + j) / 2];
    byte temp[sizeT];

    while( i <= j ) {
      while( FUNC( pivot, allocator[i] ) )
        i++;

      while( FUNC( allocator[j], pivot ) )
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



  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  ArraySorted<T, FUNC>& ArraySorted<T, FUNC>::QuickSort() {
    if( GetNum() > 1 )
      QuickSort( 0, GetNum() - 1 );

    return *this;
  }
}

#endif // __UNION_ARRAYSORTEDINTERFACE_H__