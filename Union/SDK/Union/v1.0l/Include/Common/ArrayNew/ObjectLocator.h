// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_OBJECTLOCATOR_H__
#define __UNION_OBJECTLOCATOR_H__

namespace Common {
  template <class T>
  TObjectLocator<T>::TObjectLocator() {
  }

  template <class T>
  template <class O>
  TObjectLocator<T>::TObjectLocator( const O& obj ) : refObject( obj ) {
  }

  template <class T>
  void* TObjectLocator<T>::operator new ( size_t size, ArrayLocator<T>& allocator ) {
    return allocator.AllocEnd();
  }

  template <class T>
  void* TObjectLocator<T>::operator new ( size_t size, ArrayLocator<T>& allocator, const uint& index ) {
    return allocator.AllocAt( index );
  }

  template <class T>
  void* TObjectLocator<T>::operator new[] ( size_t size, ArrayLocator<T>& allocator ) {
    return allocator.AllocEnd( size / sizeof( T ) );
  }

  template <class T>
  void* TObjectLocator<T>::operator new[] ( size_t size, ArrayLocator<T>& allocator, const uint& index ) {
    return allocator.AllocAt( index, size / sizeof( T ) );
  }

  template <class T>
  void TObjectLocator<T>::operator delete ( void* mem ) {
    // ~refObject with this destructor
  }

  template <class T>
  void TObjectLocator<T>::operator delete ( void* mem, ArrayLocator<T>& allocator ) {
    allocator.FreeAt( allocator.GetNum() - 1 );
  }

  template <class T>
  void TObjectLocator<T>::operator delete ( void* mem, ArrayLocator<T>& allocator, const uint& index ) {
    allocator.FreeAt( index );
  }

  template <class T>
  void TObjectLocator<T>::operator delete[] ( void* mem, ArrayLocator<T>& allocator ) {
    allocator.FreeAt( allocator.GetNum() - 1 ); // ??
  }

  template <class T>
  void TObjectLocator<T>::operator delete[] ( void* mem, ArrayLocator<T>& allocator, const uint& index ) {
    allocator.FreeAt( index ); // ??
  }
}

#endif // __UNION_OBJECTLOCATOR_H__