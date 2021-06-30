// Supported with union (c) 2018 Union team

#ifndef __ZSPARSE_ARRAY_H__VER0__
#define __ZSPARSE_ARRAY_H__VER0__

namespace Gothic_I_Classic {

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
    void zCSparseArrayBase_OnInit( unsigned long )                         zCall( 0x005C4A50 );
    zCSparseArrayBase( unsigned long a0 )                                  zInit( zCSparseArrayBase_OnInit( a0 ));
    void Destroy()                                                         zCall( 0x005C4B80 );
    void* Element( void const* ) const                                     zCall( 0x005EF560 );
    void* Insert( void const* )                                            zCall( 0x005C4BD0 );
    void Delete( void const* )                                             zCall( 0x005C4E40 );
    void Clear()                                                           zCall( 0x005C4F50 );
    unsigned long Find( void const* ) const                                zCall( 0x005C5010 );
    void Create( unsigned long )                                           zCall( 0x005C5190 );
    void Resize( unsigned long )                                           zCall( 0x005EFBE0 );
    void* DataPtr_novt( unsigned long, void* ) const                       zCall( 0x005C5210 );
    void AddRef( zCSparseArrayManDat* ) const                              zCall( 0x005C5610 );
    void Release( zCSparseArrayManDat* ) const                             zCall( 0x005C5670 );
    void CheckResize() const                                               zCall( 0x005C56C0 );
    virtual ~zCSparseArrayBase()                                           zCall( 0x005C4A40 );
    virtual unsigned long SizeIndex() const                                zPureCall;
    virtual unsigned long SizeData() const                                 zPureCall;
    virtual unsigned long SizeAll() const                                  zCall( 0x005C4960 );
    virtual void* IndexPtr( unsigned long ) const                          zCall( 0x005C4980 );
    virtual void* DataPtr( unsigned long ) const                           zCall( 0x005C49A0 );
    virtual zCSparseArrayManDat* ManDatPtr( unsigned long ) const          zCall( 0x005C49C0 );
    virtual int IndexIsEqual( void const*, void const* ) const             zCall( 0x005C4F90 );
    virtual void CopyIndex( void*, void const* ) const                     zCall( 0x005C4FB0 );
    virtual void DestructIndex( void* ) const                              zCall( 0x005C49E0 );
    virtual void Hash( void const*, unsigned long&, unsigned long& ) const zCall( 0x005C4FE0 );
    virtual void ConstructData( void* ) const                              zCall( 0x005C49F0 );
    virtual void DestructData( void* ) const                               zCall( 0x005C4A00 );

    // user API
    #include "zCSparseArrayBase.inl"
  };

  class zCSparseArrayIterator {
  public:
    int count;
    zCSparseArrayBase* array;
    int registered;

    void Reset()                                zCall( 0x004FCED0 );
    ~zCSparseArrayIterator()                    zCall( 0x004FCF30 );
    void Next()                                 zCall( 0x00502740 );
    void Register()                             zCall( 0x00502770 );
    void DeRegister()                           zCall( 0x00502790 );
    operator int()                              zCall( 0x00502940 );
    zCSparseArrayIterator( zCSparseArrayBase& ) zCall( 0x00698270 );

    // user API
    #include "zCSparseArrayIterator.inl"
  };

  template <class T, class Data> class zCSparseArray : public zCSparseArrayBase {
  public:
    zCSparseArray( unsigned long size = 1031 ) :zCSparseArrayBase( 0 )  { 
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
      Delete( *(T *)IndexPtr( iterator.T() )); 
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
      return ((char *)table) + (sizeof( T ) + sizeof( Data ) + sizeof( zCSparseArrayManDat )) * i;
    }
    virtual void *DataPtr( unsigned long i ) const { 
      return (char *)IndexPtr( i ) + sizeof( T ); 
    }
    virtual zCSparseArrayManDat *ManDatPtr( unsigned long i )  const {
      return (zCSparseArrayManDat *)((char *)DataPtr( i ) + sizeof( Data )); 
    }

    virtual int IndexIsEqual( const void *i1, const void *i2 ) const { 
      return (*(T *)i1) == (*(T *)i2);
    }

    virtual void CopyIndex( void *idest, const void *isrc ) const { 
      idest = new T( *(T *)isrc );
    }

    virtual void DestructIndex( void *index ) const {
      ((T *)index)->~T();
    }

    virtual void Hash( const void *index, unsigned long &hasha, unsigned long &hashb ) const { 
      unsigned long rest1 = 1, rest2 = 0, d = 0;
      hasha = 0;
      hashb = 0;

      unsigned short* run = (unsigned short*)(void*)index;
      for( int i = sizeof(T) / 2 - 1; i >= 0; i-- ) {
        hasha += (*run) * rest1;
        hashb += (*run) * rest2;

        d = hasha / sizeof(T);
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
      ((Data*)data)->~Data(); 
    }
  };

  class zCCacheBase {
  public:
    int timeout;
    zCCacheBase* next;
    zCCacheBase** anchor;
    
    void zCCacheBase_OnInit()    zCall( 0x005C57B0 );
    zCCacheBase()                zInit( zCCacheBase_OnInit() );
    static void S_PurgeCaches()  zCall( 0x005C5870 );
    static void S_ClearCaches()  zCall( 0x005C58B0 );
    virtual ~zCCacheBase()       zCall( 0x005C5830 );
    virtual void PurgeCache()    zPureCall;
    virtual void ClearCache()    zPureCall;
    
    // static properties
    static int s_currentFrame;
    static zCCacheBase* s_anchor;
    static zCCacheBase* s_run;

    // user API
    #include "zCCacheBase.inl"
  };

  template <class Index, class Data> class zCCacheData {
    Data    *data;
    int      lastFrameUsed;

  public:
    zCCacheData() : data( NULL ), lastFrameUsed( zCCacheBase::S_GetCurrentFrame() ) {}
    ~zCCacheData() { 
      Clear();
    }

    void  Clear() { 
      delete data; 
      data = NULL; 
    }

    Data *GetDataDangerous() { 
      return data; 
    }

    Data *GetData( const Index &index ) { 
      if( !data ) {
        data = zNEW( Data )( index );
      }
      lastFrameUsed = zCCacheBase::S_GetCurrentFrame(); 
      return data; 
    }

    bool32 Purge( int timeout ) { 
      if( zCCacheBase::S_GetCurrentFrame() - lastFrameUsed > timeout ) { 
        Clear(); 
        return TRUE; 
      } 
      return FALSE; 
    }

    Data *GetData( const Index &index, bool32 &neu ) { 
      neu = FALSE; 
      if( !data ) { 
        data = zNEW( Data )(index); 
        neu = TRUE; 
      } 
      lastFrameUsed = zCCacheBase::S_GetCurrentFrame(); 
      return data; 
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZSPARSE_ARRAY_H__VER0__