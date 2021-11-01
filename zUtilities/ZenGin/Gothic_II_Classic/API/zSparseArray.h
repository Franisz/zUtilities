// Supported with union (c) 2018-2021 Union team

#ifndef __ZSPARSE_ARRAY_H__VER2__
#define __ZSPARSE_ARRAY_H__VER2__

namespace Gothic_II_Classic {
  
  class zCSparseArrayManDat {
  public:
    int refCtr   : 31;
    int occupied : 1;

    // user API
    #include "zCSparseArrayManDat.inl"
  };

  class zCSparseArrayBase {
    friend class zCSparseArrayIterator;

  public:
    unsigned long numberOfIterators;
    unsigned long size;
    unsigned long min_size;
    void* table;
    unsigned long used;
    unsigned long maxRefCtr;
    int requestResize;

    zCSparseArrayBase() {}
    void zCSparseArrayBase_OnInit( unsigned long )                         zCall( 0x005E8500 );
    zCSparseArrayBase( unsigned long a0 )                                  zInit( zCSparseArrayBase_OnInit( a0 ));
    void Destroy()                                                         zCall( 0x005E8680 );
    void* Element( void const* ) const                                     zCall( 0x005E87B0 );
    void* Insert( void const* )                                            zCall( 0x005E8800 );
    void Delete( void const* )                                             zCall( 0x005E8A70 );
    void Clear()                                                           zCall( 0x005E8B80 );
    unsigned long Find( void const* ) const                                zCall( 0x005E8C40 );
    void Create( unsigned long )                                           zCall( 0x005E8DC0 );
    void Resize( unsigned long )                                           zCall( 0x005E8E30 );
    void* DataPtr_novt( unsigned long, void* ) const                       zCall( 0x005E92C0 );
    void AddRef( zCSparseArrayManDat* ) const                              zCall( 0x005E92F0 );
    void Release( zCSparseArrayManDat* ) const                             zCall( 0x005E9350 );
    void CheckResize() const                                               zCall( 0x005E93A0 );
    virtual ~zCSparseArrayBase()                                           zCall( 0x005E8670 );
    virtual unsigned long SizeIndex() const                                zPureCall;
    virtual unsigned long SizeData() const                                 zPureCall;
    virtual unsigned long SizeAll() const                                  zCall( 0x005E8590 );
    virtual void* IndexPtr( unsigned long ) const                          zCall( 0x005E85B0 );
    virtual void* DataPtr( unsigned long ) const                           zCall( 0x005E85D0 );
    virtual zCSparseArrayManDat* ManDatPtr( unsigned long ) const          zCall( 0x005E85F0 );
    virtual int IndexIsEqual( void const*, void const* ) const             zCall( 0x005E8BC0 );
    virtual void CopyIndex( void*, void const* ) const                     zCall( 0x005E8BE0 );
    virtual void DestructIndex( void* ) const                              zCall( 0x005E8610 );
    virtual void Hash( void const*, unsigned long&, unsigned long& ) const zCall( 0x005E8C10 );
    virtual void ConstructData( void* ) const                              zCall( 0x005E8620 );
    virtual void DestructData( void* ) const                               zCall( 0x005E8630 );

    // user API
    #include "zCSparseArrayBase.inl"
  };

  class zCSparseArrayIterator {
  public:
    int count;
    zCSparseArrayBase* array;
    int registered;

    zCSparseArrayIterator() {}
    void zCSparseArrayIterator_OnInit( zCSparseArrayBase& ) zCall( 0x006DCEB0 );
    void Reset()                                            zCall( 0x00509B50 );
    ~zCSparseArrayIterator()                                zCall( 0x00509BB0 );
    void Next()                                             zCall( 0x0050F4D0 );
    void Register()                                         zCall( 0x0050F500 );
    void DeRegister()                                       zCall( 0x0050F520 );
    operator int()                                          zCall( 0x0050F6C0 );
    zCSparseArrayIterator( zCSparseArrayBase& a0 )          zInit( zCSparseArrayIterator_OnInit( a0 ));

    // user API
    #include "zCSparseArrayIterator.inl"
  };

  template <class T, class Data> class zCSparseArray : public zCSparseArrayBase {
  public:
    zCSparseArray( unsigned long size = 1031 ) :zCSparseArrayBase( 0 ) {
      if( size > 0 ) {
        Create( size );
      }
    }

    virtual ~zCSparseArray() {
      Destroy();
    }

    Data *operator[] ( const T& index ) const {
      return (Data *)Element( &index );
    }

    Data *Insert( const T& index ) {
      return (Data *)zCSparseArrayBase::Insert( &index );
    }

    void Delete( const T& index ) {
      zCSparseArrayBase::Delete( &index );
    }

    Data *operator[] ( const zCSparseArrayIterator& iterator ) const {
      return (Data *)DataPtr( iterator.T() );
    }

    Data *IteratorData( const zCSparseArrayIterator& iterator ) const {
      return (Data *)DataPtr( iterator.T() );
    }

    T *IteratorIndex( const zCSparseArrayIterator& iterator ) const {
      return (T *)IndexPtr( iterator.T() );
    }

    void Delete( const zCSparseArrayIterator& iterator ) {
      Delete( *(T *)IndexPtr( iterator.T() ) );
    }

    virtual unsigned long SizeIndex() const {
      return sizeof( T );
    }

    virtual unsigned long SizeData() const {
      return sizeof( Data );
    }

    virtual unsigned long SizeAll() const {
      return sizeof( T ) + sizeof( Data ) + sizeof( zCSparseArrayManDat );
    }

    virtual void *IndexPtr( unsigned long i ) const {
      return ( (char *)table ) + ( sizeof( T ) + sizeof( Data ) + sizeof( zCSparseArrayManDat ) ) * i;
    }
    virtual void *DataPtr( unsigned long i ) const {
      return (char *)IndexPtr( i ) + sizeof( T );
    }
    virtual zCSparseArrayManDat *ManDatPtr( unsigned long i )  const {
      return (zCSparseArrayManDat *)( (char *)DataPtr( i ) + sizeof( Data ) );
    }

    virtual int IndexIsEqual( const void *i1, const void *i2 ) const {
      return ( *(T *)i1 ) == ( *(T *)i2 );
    }

    virtual void CopyIndex( void *idest, const void *isrc ) const {
      idest = new T( *(T *)isrc );
    }

    virtual void DestructIndex( void *index ) const {
      ( (T *)index )->~T();
    }

    virtual void Hash( const void *index, unsigned long &hasha, unsigned long &hashb ) const {
      unsigned long rest1 = 1, rest2 = 0, d = 0;
      hasha = 0;
      hashb = 0;

      unsigned short* run = (unsigned short*)(void*)index;
      for( int i = sizeof( T ) / 2 - 1; i >= 0; i-- ) {
        hasha += ( *run ) * rest1;
        hashb += ( *run ) * rest2;

        d = hasha / sizeof( T );
        hasha -= d * size;
        hashb += d;
        hashb %= size - 1;

        rest1 <<= 16;
        rest2 <<= 16;

        d = rest1 / size;
        rest1 -= d * size;
        rest2 += d;
        rest2 %= size - 1;

        run++;
      }
      hashb++;
    }

    virtual void ConstructData( void *data ) const {
      new Data( *(Data*)data );
    }

    virtual void DestructData( void *data ) const {
      ( (Data*)data )->~Data();
    }
  };

  class zCCacheBase {
  public:
    int timeout;
    zCCacheBase* next;
    zCCacheBase** anchor;

    void zCCacheBase_OnInit()   zCall( 0x005E9490 );
    zCCacheBase()               zInit( zCCacheBase_OnInit() );
    static void S_PurgeCaches() zCall( 0x005E9550 );
    static void S_ClearCaches() zCall( 0x005E9590 );
    virtual ~zCCacheBase()      zCall( 0x005E9510 );
    virtual void PurgeCache()   zPureCall;
    virtual void ClearCache()   zPureCall;

    // static properties
    static int& s_currentFrame;
    static zCCacheBase*& s_anchor;
    static zCCacheBase*& s_run;

    // user API
    #include "zCCacheBase.inl"
  };

  template <class Index, class Data> class zCCacheData {
    Data    *data;
    int      lastFrameUsed;

  public:
    zCCacheData() : data( Null ), lastFrameUsed( zCCacheBase::S_GetCurrentFrame() ) {}
    ~zCCacheData() {
      Clear();
    }

    void  Clear() {
      delete data;
      data = Null;
    }

    Data *GetDataDangerous() {
      return data;
    }

    Data *GetData( const Index &index ) {
      if( !data ) {
        data = new Data( index );
      }
      lastFrameUsed = zCCacheBase::S_GetCurrentFrame();
      return data;
    }

    bool32 Purge( int timeout ) {
      if( zCCacheBase::S_GetCurrentFrame() - lastFrameUsed > timeout ) {
        Clear();
        return True;
      }
      return False;
    }

    Data *GetData( const Index &index, bool32 &neu ) {
      neu = False;
      if( !data ) {
        data = new Data( index );
        neu = True;
      }
      lastFrameUsed = zCCacheBase::S_GetCurrentFrame();
      return data;
    }
  };

} // namespace Gothic_II_Classic

#endif // __ZSPARSE_ARRAY_H__VER2__