// Supported with union (c) 2018-2021 Union team

#ifndef __ZSPARSE_ARRAY_H__VER3__
#define __ZSPARSE_ARRAY_H__VER3__

namespace Gothic_II_Addon {

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
    void zCSparseArrayBase_OnInit( unsigned long )                         zCall( 0x005EF2B0 );
    zCSparseArrayBase( unsigned long a0 )                                  zInit( zCSparseArrayBase_OnInit( a0 ));
    void Destroy()                                                         zCall( 0x005EF430 );
    void* Element( void const* ) const                                     zCall( 0x005EF560 );
    void* Insert( void const* )                                            zCall( 0x005EF5B0 );
    void Delete( void const* )                                             zCall( 0x005EF820 );
    void Clear()                                                           zCall( 0x005EF930 );
    unsigned long Find( void const* ) const                                zCall( 0x005EF9F0 );
    void Create( unsigned long )                                           zCall( 0x005EFB70 );
    void Resize( unsigned long )                                           zCall( 0x005EFBE0 );
    void* DataPtr_novt( unsigned long, void* ) const                       zCall( 0x005F0070 );
    void AddRef( zCSparseArrayManDat* ) const                              zCall( 0x005F00A0 );
    void Release( zCSparseArrayManDat* ) const                             zCall( 0x005F0100 );
    void CheckResize() const                                               zCall( 0x005F0150 );
    virtual ~zCSparseArrayBase()                                           zCall( 0x005EF3F0 );
    virtual unsigned long SizeIndex() const                                zPureCall;
    virtual unsigned long SizeData() const                                 zPureCall;
    virtual unsigned long SizeAll() const                                  zCall( 0x005EF340 );
    virtual void* IndexPtr( unsigned long ) const                          zCall( 0x005EF360 );
    virtual void* DataPtr( unsigned long ) const                           zCall( 0x005EF380 );
    virtual zCSparseArrayManDat* ManDatPtr( unsigned long ) const          zCall( 0x005EF3A0 );
    virtual int IndexIsEqual( void const*, void const* ) const             zCall( 0x005EF970 );
    virtual void CopyIndex( void*, void const* ) const                     zCall( 0x005EF990 );
    virtual void DeIndex( void* ) const                                    zCall( 0x005EF3C0 );
    virtual void Hash( void const*, unsigned long&, unsigned long& ) const zCall( 0x005EF9C0 );
    virtual void ConData( void* ) const                                    zCall( 0x005EF3D0 );
    virtual void DeData( void* ) const                                     zCall( 0x005EF3E0 );

    // user API
    #include "zCSparseArrayBase.inl"
  };

  class zCSparseArrayIterator {
  public:
    int count;
    zCSparseArrayBase* array;
    int registered;

    void Reset()                                zCall( 0x0050C900 );
    ~zCSparseArrayIterator()                    zCall( 0x0050C960 );
    void Next()                                 zCall( 0x005122A0 );
    void Register()                             zCall( 0x005122D0 );
    void DeRegister()                           zCall( 0x005122F0 );
    operator int()                              zCall( 0x00512490 );
    zCSparseArrayIterator( zCSparseArrayBase& ) zCall( 0x0073B670 );

    // user API
    #include "zCSparseArrayIterator.inl"
  };

  template <class T, class Data>
  class zCSparseArray : public zCSparseArrayBase {
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

    // user API
    #include "zCSparseArray.inl"
  };

  class zCCacheBase {
  public:
    int timeout;
    zCCacheBase* next;
    zCCacheBase** anchor;
    
    void zCCacheBase_OnInit()    zCall( 0x005F0240 );
    zCCacheBase()                zInit( zCCacheBase_OnInit() );
    static void S_PurgeCaches()  zCall( 0x005F0300 );
    static void S_ClearCaches()  zCall( 0x005F0340 );
    virtual ~zCCacheBase()       zCall( 0x005F0270 );
    virtual void PurgeCache()    zPureCall;
    virtual void ClearCache()    zPureCall;

    // static properties
    static int& s_currentFrame;
    static zCCacheBase*& s_anchor;
    static zCCacheBase*& s_run;

    // user API
    #include "zCCacheBase.inl"
  };

  template <class Index, class Data>
  class zCCacheData {
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

    // user API
    #include "zCCacheData.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSPARSE_ARRAY_H__VER3__