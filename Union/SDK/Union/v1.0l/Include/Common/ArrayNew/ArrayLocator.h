// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARRAYLOCATOR_H__
#define __UNION_ARRAYLOCATOR_H__

namespace Common {
  template <class T>
  void ArrayLocator<T>::AllocArray( const uint& newCount ) {
    if( newCount > FullCount ) {
      FullCount       = newCount  * AllocMultiplier;
      MemoryUsed      = newCount  * sizeof( T );
      MemoryAllocated = FullCount * sizeof( T );
      Vector          = (T*)shi_realloc( Vector, MemoryAllocated );
    }

    Count = newCount;
  }

  template <class T>
  void ArrayLocator<T>::ReduceArray( const uint& newCount ) {
    if( newCount < FullCount / 2 ) {
      FullCount       = newCount  * AllocMultiplier;
      MemoryUsed      = newCount  * sizeof( T );
      MemoryAllocated = FullCount * sizeof( T );
      Vector          = (T*)shi_realloc( Vector, MemoryAllocated );
    }

    Count = newCount;
  }

  template <class T>
  void ArrayLocator<T>::InitArray() {
    Vector          = (T*)shi_malloc( 0 );
    Count           = 0;
    FullCount       = 0;
    MemoryUsed      = 0;
    MemoryAllocated = 0;
    AllocMultiplier = 2;
  }

  template <class T>
  uint ArrayLocator<T>::AddReference() {
    return ++refCrt;
  }

  template <class T>
  uint ArrayLocator<T>::Release() {
    if( --refCrt == 0 ) {
      delete this;
      return 0;
    }

    return refCrt;
  }

  template <class T>
  const uint ArrayLocator<T>::GetRefCrf() const {
    return refCrt;
  }

  template <class T>
  ArrayLocator<T>::ArrayLocator() {
    refCrt = 1u;
    InitArray();
  }

  template <class T>
  T* ArrayLocator<T>::AllocEnd( const uint& count ) {
    uint index = Count;
    AllocArray( Count + count );
    return &Vector[index];
  }

  template <class T>
  T* ArrayLocator<T>::AllocFront( const uint& count ) {
    uint length = Count * sizeof( T );
    AllocArray( Count + count );
    memcpy( &Vector[count], &Vector[0], length );
    return &Vector[0];
  }

  template <class T>
  T* ArrayLocator<T>::AllocAt( const uint& index, const uint& count ) {
    if( index == 0 )
      return AllocFront( count );
    
    if( index != Count ) {
      uint moveLength = (Count - index)  * sizeof( T );
      AllocArray( Count + count );
      memcpy( &Vector[index + count], &Vector[index], moveLength );
    }
    else
      AllocArray( Count + count );

    return &Vector[index];
  }

  template <class T>
  void ArrayLocator<T>::FreeFront( const uint& count ) {
    uint length = (Count - count) * sizeof( T );
    ReduceArray( Count - count );
    memcpy( &Vector[0], &Vector[count], length );
  }

  template <class T>
  void ArrayLocator<T>::FreeEnd( const uint& count ) {
    ReduceArray( Count - count );
  }

  template <class T>
  void ArrayLocator<T>::FreeAt( const uint& index, const uint& count ) {
    if( Count <= count )
      return ReduceArray( 0 );

    if( index == 0 )
      return FreeFront( count );

    if( index == Count - 1 )
      return FreeEnd( count );

    uint length = (Count - index - count) * sizeof( T );
    memcpy( &Vector[index], &Vector[index + count], length );
    ReduceArray( Count - count );
  }

  template <class T>
  void ArrayLocator<T>::FastFreeAt( const uint& index, const uint& count ) {
    if( Count <= count )
      return ReduceArray( 0 );

    if( index == Count - 1 )
      return FreeEnd( count );

    if( Count > 1 )
      memcpy( &Vector[index], &Vector[Count - count], sizeof( T ) );
    ReduceArray( Count - count );
  }

  template <class T>
  T& ArrayLocator<T>::operator []( const uint& index ) {
    return Vector[index];
  }

  template <class T>
  const T& ArrayLocator<T>::operator []( const uint& index ) const {
    return Vector[index];
  }


  template <class T>
  T* ArrayLocator<T>::begin() {
    return &Vector[0];
  }

  template <class T>
  T* ArrayLocator<T>::end() {
    return &Vector[GetNum()];
  }

  template <class T>
  const T* ArrayLocator<T>::begin() const {
    return &Vector[0];
  }

  template <class T>
  const T* ArrayLocator<T>::end() const {
    return &Vector[GetNum()];
  }

  template <class T>
  uint ArrayLocator<T>::GetNum() const {
    return Count;
  }

  template <class T>
  uint ArrayLocator<T>::GetUsedMemory() const {
    return MemoryUsed;
  }

  template <class T>
  uint ArrayLocator<T>::GetAllocatedMemory() const {
    return MemoryAllocated;
  }

  template <class T>
  void ArrayLocator<T>::SetLocatorMultiplier( const uint& rate ) {
    AllocMultiplier = rate;
  }

  template <class T>
  void ArrayLocator<T>::PrepareToReserveArray( const uint& count ) {
    uint NewFullCount = Count + count;
    if( NewFullCount > FullCount ) {
      FullCount = NewFullCount;
      MemoryAllocated = FullCount * sizeof( T );
      Vector = (T*)shi_realloc( Vector, MemoryAllocated );
    }
  }

  template <class T>
  void ArrayLocator<T>::ActivateAllocatedMemory() {
    if( Count < FullCount )
      Count = FullCount;
  }

  template <class T>
  void ArrayLocator<T>::ShrinkToFit() {
    if( Count < FullCount ) {
      FullCount = Count;
      MemoryAllocated = MemoryUsed;
      Vector = (T*)shi_realloc( Vector, MemoryAllocated );
    }
  }

  template <class T>
  ArrayLocator<T>::~ArrayLocator() {
    shi_free( Vector );
  }
}

#endif // __UNION_ARRAYLOCATOR_H__