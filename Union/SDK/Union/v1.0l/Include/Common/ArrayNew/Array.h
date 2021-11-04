// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARRAY_H__
#define __UNION_ARRAY_H__

namespace Common {
  template <class T>
  class ArrayLocator {
    T* Vector;
    uint Count;
    uint FullCount;
    uint MemoryUsed;
    uint MemoryAllocated;
    uint AllocMultiplier;
    uint refCrt;
  protected:

    void AllocArray( const uint& newCount );
    void ReduceArray( const uint& newCount );
    void InitArray();
  public:

    uint AddReference();
    uint Release();
    const uint GetRefCrf() const;

    ArrayLocator();
    T* AllocEnd( const uint& count = 1 );
    T* AllocFront( const uint& count = 1 );
    T* AllocAt( const uint& index, const uint& count = 1 );
    void FreeEnd( const uint& count = 1 );
    void FreeFront( const uint& count = 1 );
    void FreeAt( const uint& index, const uint& count = 1 );
    void FastFreeAt( const uint& index, const uint& count = 1 );

    T& operator [] ( const uint& index );
    const T& operator [] ( const uint& index ) const;

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;

    uint GetNum() const;
    uint GetUsedMemory() const;
    uint GetAllocatedMemory() const;
    void SetLocatorMultiplier( const uint& rate );
    void PrepareToReserveArray( const uint& count );
    void ActivateAllocatedMemory();
    void ShrinkToFit();
    ~ArrayLocator();
  };


  // A dynamic object constructor for arrays
  template <class T>
  struct TObjectLocator {
    T refObject;

    template <class O>
    TObjectLocator( const O& obj );
    TObjectLocator();

    static void* operator new    (size_t size, ArrayLocator<T>& allocator);
    static void* operator new    (size_t size, ArrayLocator<T>& allocator, const uint& index);
    static void* operator new[]( size_t size, ArrayLocator<T>& allocator );
    static void* operator new[]( size_t size, ArrayLocator<T>& allocator, const uint& index );
    static void operator delete  (void* mem);
    static void operator delete  (void* mem, ArrayLocator<T>& allocator);
    static void operator delete  (void* mem, ArrayLocator<T>& allocator, const uint& index);
    static void operator delete[]( void* mem, ArrayLocator<T>& allocator );
    static void operator delete[]( void* mem, ArrayLocator<T>& allocator, const uint& index );
  };


#pragma warning(disable:4521)
  // A dynamic array interface
  template <class T>
  class Array {
    ArrayLocator<T>* Allocator;
    ArrayLocator<T>& GetAllocator();
    const ArrayLocator<T>& GetAllocator() const;
    void* SortFunc;
  public:

    Array();
    Array( T* copy, const uint& count = Invalid );
    Array( Array& other );       // !!! Reference
    Array( const Array& other ); // !!! Copy

    template <class O>
    T& Create( O init );
    T& Create();
    T& InsertEnd( const T& obj );
    T& Insert( const T& obj );
    T& InsertAt( const T& obj, const uint& index );
    T& InsertFront( const T& obj );


    void Remove( const T& obj );
    void RemoveAt( const uint& index );
    void FastRemove( const T& obj );
    void FastRemoveAt( const uint& index );
    void RemoveAtBounds( const uint& index, const uint& count );
    void Clear();


    void Delete( const T& obj );
    void DeleteAt( const uint& index );
    void FastDelete( const T& obj );
    void FastDeleteAt( const uint& index );
    void DeleteAtBounds( const uint& index, const uint& count );
    void DeleteData();

  public:
    void MergeArray( const Array& other );
    void MergeArrayAt( const Array& other, const uint& index );


    Array& operator += ( const T& obj );
    Array& operator += ( const Array& other );
    Array& operator |= ( const T& obj );
    Array& operator |= ( const Array& other );
    Array& operator -= ( const T& obj );
    Array& operator -= ( const Array& other );
    Array& operator ^= ( const T& obj );
    Array& operator ^= ( const Array& other );
    Array& operator = ( const Array& other );
    bool operator == ( const Array& other ) const;
    bool operator & ( const T& obj ) const;


    bool CompareLinear( const Array& other ) const;
    bool CompareInsorted( const Array& other ) const;
    Array& Normalize();


    const T& operator[]( const uint& index ) const;
    T& operator[]( const uint& index );
    const T* GetSafe( const uint& index ) const;
    T* GetSafe( const uint& index );
    const T& GetFirst() const;
    T& GetFirst();
    const T& GetLast() const;
    T& GetLast();


    template<class O>
    bool HasEqual( const O& obj ) const;

    template<class O>
    uint SearchEqual( const O& obj, const uint& begin = 0 ) const;

    template<class O>
    uint CountOfEqual( const O& obj ) const;
    void ReleaseData();




    T& InsertSorted( const T& obj );

    void MergeArraySorted( const Array& other );

    template<class O>
    T& CreateSorted( const O& byObj );

    template<class O>
    bool HasEqualSorted( const O& obj ) const;

    template<class O>
    uint SearchEqualSorted( const O& obj ) const;

    template<class O>
    void RemoveSorted( const O& obj );

    template<class O>
    void DeleteSorted( const O& obj );

    template<class O>
    uint FindIndexForObject( const O& obj ) const;

  protected:
    void QuickSort( uint low, uint hight );

  public:
    Array& QuickSort();


    void Copy( T** ppmem, const uint& index, const uint& count );
    uint GetNum() const;
    bool IsEmpty() const;
    uint GetTypeSize() const;


    void SetLocatorMultiplier( const uint& rate );
    void ShrinkToFit();


    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;


    const ArrayLocator<T>& GetArrayLocator() const;
    virtual ~Array();
  };
#pragma warning(default:4521)



#pragma warning(disable:4521)
  template <class T, bool( __cdecl* FUNC )(const T&, const T&)>
  class ArraySorted {
  protected:
    ArrayLocator<T>* Allocator;
    ArrayLocator<T>& GetAllocator();
    const ArrayLocator<T>& GetAllocator() const;
    void* SortFunc;
  public:

    ArraySorted();
    ArraySorted( T* copy, const uint& count = Invalid );
    ArraySorted( ArraySorted& other );       // !!! Reference
    ArraySorted( const ArraySorted& other ); // !!! Copy
    ArraySorted( const Array<T>& other );    // !!! Copy


    T& Insert( const T& obj );

    template<void* LAMBDA, class O>
    T& Create( const O& byObj );


    template<void* LAMBDA, class O>
    void Remove( const O& obj );
    void Remove( const T& obj );
    void RemoveAt( const uint& index );
    void RemoveAtBounds( const uint& index, const uint& count );
    void Clear();


    template<void* LAMBDA, class O>
    void Delete( const O& obj );
    void Delete( const T& obj );
    void DeleteAt( const uint& index );
    void DeleteAtBounds( const uint& index, const uint& count );
    void DeleteData();


    void MergeArray( const ArraySorted& other );
    void MergeArray( const Array<T>& other );


    ArraySorted& operator += ( const T& obj );
    ArraySorted& operator += ( const ArraySorted& other );
    ArraySorted& operator |= ( const T& obj );
    ArraySorted& operator |= ( const ArraySorted& other );
    ArraySorted& operator -= ( const T& obj );
    ArraySorted& operator -= ( const ArraySorted& other );
    ArraySorted& operator ^= ( const T& obj );
    ArraySorted& operator ^= ( const ArraySorted& other );
    ArraySorted& operator = ( const ArraySorted& other );
    ArraySorted& operator = ( const Array<T>& other );
    bool operator == ( const ArraySorted& other ) const;
    bool operator & ( const T& obj ) const;


    bool Compare( const ArraySorted& other ) const;
    ArraySorted& Normalize();


    T& operator[]( const uint& index );
    T* GetSafe( const uint& index );
    T& GetFirst();
    T& GetLast();


    const T& operator[]( const uint& index ) const;
    const T* GetSafe( const uint& index ) const;
    const T& GetFirst() const;
    const T& GetLast() const;


    template<void* LAMBDA, class O>
    bool HasEqual( const O& obj ) const;
    bool HasEqual( const T& obj ) const;

    template<void* LAMBDA, class O>
    uint SearchEqual( const O& obj, const uint& begin = 0 ) const;
    uint SearchEqual( const T& obj, const uint& begin = 0 ) const;

    template<void* LAMBDA, class O>
    uint CountOfEqual( const O& obj ) const;
    uint CountOfEqual( const T& obj ) const;


    void ReleaseData();


    template<void* LAMBDA, class O>
    uint FindIndexForObject( const O& obj ) const;
    uint FindIndexForObject( const T& obj ) const;


  protected:
    void QuickSort( uint low, uint hight );

  public:
    ArraySorted& QuickSort();


    void Copy( T** ppmem, const uint& index, const uint& count );
    uint GetNum() const;
    bool IsEmpty() const;
    uint GetTypeSize() const;


    void SetLocatorMultiplier( const uint& rate );
    void ShrinkToFit();


    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;


    const ArrayLocator<T>& GetArrayLocator() const;
    virtual ~ArraySorted();
  };
#pragma warning(default:4521)
}

#include "ArrayLocator.h"
#include "ObjectLocator.h"
#include "ArrayInterface.h"
#include "ArraySortedInterface.h"

#endif // __UNION_ARRAY_H__