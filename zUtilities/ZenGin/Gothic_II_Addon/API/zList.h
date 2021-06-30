// Supported with union (c) 2018 Union team

#ifndef __ZLIST_H__VER3__
#define __ZLIST_H__VER3__

#include "zContainer.h"
#include "zObject.h"

namespace Gothic_II_Addon {

  template <class T>
  class zCPQueue {
  public:
    T *array;
    int numAlloc;
    int numInArray;

    int( *Compare )( T ele1, T ele2 );
    BOOL allow_double_entrys;
  public:
    zCPQueue() {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      allow_double_entrys = True;
    };
    zCPQueue( int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      array = zNEW_ARRAY( T, startSize );
      allow_double_entrys = True;
    };
    zCPQueue( const zCPQueue<T>& array2 ) {

      numInArray = 0;
      numAlloc = 0;
      array = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      if( numInArray > 0 )
        memcpy( array, array2.array, sizeof( T )*numInArray );
      allow_double_entrys = True;
    };
    ~zCPQueue() {
      delete[] array;
      array = 0;
    };

    void SetAllowDouble( BOOL allow )
    {
      allow_double_entrys = allow;
    };

    void SetCompare( int( *Cmp )( T ele1, T ele2 ) )
    {
      Compare = Cmp;
    };
    void AllocDelta( const int numDelta ) {
      T *newArray = zNEW_ARRAY( T, numAlloc + numDelta );
      if( numInArray > 0 )
        memcpy( newArray, array, sizeof( T )*numInArray );
      delete[] array;
      array = newArray;
      numAlloc += numDelta;
    };
    void AllocAbs( const int size ) {
      if( numAlloc > size ) return;
      AllocDelta( size - numAlloc );
    };
    void ShrinkToFit() {
      if( numInArray == 0 ) { DeleteList(); return; };
      if( numAlloc > numInArray ) {
        T *newArray = zNEW_ARRAY( T, numInArray );
        memcpy( newArray, array, sizeof( T )*numInArray );
        delete[] array;
        array = newArray;
        numAlloc = numInArray;
      };
    };
    void operator = ( const zCPQueue<T>& array2 ) {
      DeleteList();
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      if( numInArray > 0 )
        memcpy( array, array2.array, sizeof( T )*numInArray );
    };
    T& operator [] ( int nr ) {
      assert( numInArray > 0 );
      assert( numAlloc > 0 );
      assert( ( nr >= 0 ) && ( nr < numInArray ) );
      return array[nr];
    };
    T operator [] ( int nr ) const {
      assert( numInArray > 0 );
      assert( numAlloc > 0 );
      assert( ( nr >= 0 ) && ( nr < numInArray ) );
      return array[nr];
    };
    T& GetSafe( int nr ) const {
      assert( numInArray > 0 );
      assert( numAlloc > 0 );
      assert( ( nr >= 0 ) && ( nr < numInArray ) );
      if( numInArray <= 0 ) Message::Fatal( "D: zTree(zCPQueue::GetSafe): numInArray<=0" );
      if( numAlloc <= 0 ) Message::Fatal( "D: zTree(zCPQueue::GetSafe): numAlloc <=0" );
      if( nr < 0 ) nr = 0; else
        if( nr >= numInArray ) nr = numInArray - 1;
      return array[nr];
    };

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc == 0 ) AllocDelta( 16 );
        else AllocDelta( numAlloc / 2 );
      };
      array[numInArray++] = ins;
    };

    BOOL Insert( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc == 0 ) AllocDelta( 16 );
        else AllocDelta( numAlloc / 2 );
      };

      int ind_low = 0;
      int ind_high = numInArray;

      int index = ind_low + ( ind_low + ind_high ) / 2;
      int erg;

      do {
        if( ind_high <= ind_low ) {

          if( index >= numInArray ) {
            array[index] = ins;
            numInArray++;
            return True;
          }
          else {
            erg = Compare( ins, array[index] );
            if( erg > 0 ) index++;
            if( ( erg == 0 ) && ( !allow_double_entrys ) ) return False;
          };

          memmove( &array[index + 1], &array[index], sizeof( T ) * ( numInArray - index ) );
          array[index] = ins;
          numInArray++;
          return True;
        }

        erg = Compare( ins, array[index] );

        if( erg > 0 )
          ind_low = index + 1;
        else
          ind_high = index - 1;

        index = ind_low + ( ind_high - ind_low ) / 2;

      } while( 1 );

      return False;
    };

    void Remove( const T& rem ) {
      if( numInArray == 0 ) return;
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          numInArray--;
          if( i != numInArray ) array[i] = array[numInArray];
          return;
        };
      };
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          if( i != numInArray - 1 )
            for( int j = i; j < numInArray; j++ ) array[j] = array[j + 1];
          numInArray--;
          return;
        };
      };
    };
    void DeleteList() {
      delete[] array;
      array = 0;
      numAlloc = 0;
      numInArray = 0;
    };
    void EmptyList() { numInArray = 0; };
    BOOL IsInList( const T& data ) const {
      if( numInArray == 0 ) return False;

      return False;
    };
    int GetNumInList() const { return numInArray; };
    BOOL IsEmpty() const { return ( numInArray == 0 ); };

    // user API
    #include "zCPQueue.inl"
  };

  
  template <class T>
  class zCListSort {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCListSort, 0x008D83B4 )

    int( *Compare )( T *ele1, T *ele2 );
    T *data;
    zCListSort *next;
  public:

    zCListSort() {
      next = 0;
      data = 0;
    }

    ~zCListSort() {

      if( next ) {
        delete next;
        next = 0;
      };
    };

    void DeleteList() {
      if( next ) {

        delete next;
        next = 0;
      };
    };

    void DeleteListDatas() {
      if( data ) {
        data->Release();
        data = 0;
      };

      if( next ) {
        next->DeleteListDatas();
        delete next;
        next = 0;
      };
    };

    void Replace( T *ins ) { data = ins; };

    void Insert( T *ins ) {
      zCListSort *newItem = zNEW( zCListSort );
      newItem->data = ins;
      newItem->next = next;
      next = newItem;
    }

    void InsertSort( T *ins ) {
      zCListSort* newItem = zNEW( zCListSort );
      newItem->data = ins;
      newItem->next = next;

      zCListSort* ele = this;
      while( ele->next ) {
        if( Compare( ins, ele->next->data ) < 0 ) {

          newItem->next = ele->next;
          ele->next = newItem;
          return;
        }
        ele = ele->next;
      }

      newItem->next = Null;
      ele->next = newItem;
    };

    void Remove( T *rem ) {
      zCListSort *item = this;

      while( item->next != 0 ) {
        if( item->next->data == rem ) {
          zCListSort *tmp = item->next;
          item->next = item->next->next;
          tmp->next = 0;
          delete tmp;
          return;
        }
        item = item->next;
      }
    };

    T* Get( int nr ) const {
      zCListSort *item = next;
      int c = 0;
      while( item != 0 ) {
        if( c == nr ) return( item->data );
        item = item->next;
        c++;
      }
      return 0;
    };

    T* operator [] ( int nr ) const {
      return Get( nr );
    };

    zCListSort* GetNextInList() const { return next; };
    T* GetData() const { return data; };

    bool32 InList( T *data ) const {
      zCListSort *item = next;
      while( item != 0 ) {
        if( item->data == data ) return True;
        item = item->next;
      }
      return False;
    }
    bool32 IsInList( T *data ) const {
      zCListSort *item = next;
      while( item != 0 ) {
        if( item->data == data ) return True;
        item = item->next;
      }
      return False;
    }

    int GetNumInList() const {
      int count = 0;
      zCListSort *item = next;
      while( item != 0 ) {
        count++;
        item = item->next;
      }
      return count;
    };

    void SetCompare( int( *Cmp )( T *ele1, T *ele2 ) )
    {
      Compare = Cmp;
    };

    // user API
    #include "zCListSort.inl"
  };

  template <class T>
  class zCList2
  {
  protected:

    int count;
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCList2, 0x008D8398 )

    T *root;

    zCList2()
    {
      root = 0;
      count = 0;
    }

    void DeleteList()
    {
      T *item, *help;
      item = root;
      while( item != 0 ) {
        help = item;
        item = item->next;
        delete( help );
      }
      root = 0;
      count = 0;
    };

    void Insert( T *ins )
    {
      ins->next = root;
      root = ins;
      count++;
    }

    void Remove( T *rem )
    {
      T *item = root;

      if( item == 0 ) return;
      if( item == rem ) {
        root = item->next;
        count--;
      }
      else {
        while( item->next != 0 ) {
          if( item->next == rem ) {
            item->next = rem->next;
            count--;
            return;
          }
          item = item->next;
        }
      }
    }

    void Delete( T *rem )
    {
      T *item = root;

      if( item == 0 ) return;
      if( item == rem ) {
        root = item->next;
        delete( item );
        count--;
      }
      else {
        while( item->next != 0 ) {
          if( item->next == rem ) {
            item->next = rem->next;
            delete( rem );
            count--;
            return;
          }
          item = item->next;
        }
      }
    }

    T* Get( int nr ) const {
      T *item = root;
      int c = 0;

      while( item != 0 ) {

        if( c == nr ) return( item );
        item = item->next;
        c++;
      }
      return 0;
    };

    bool32 InList( T *ele2 ) const
    {
      T *item = root;

      while( item != 0 ) {
        if( item == ele2 ) return True;
        item = item->next;
      }
      return False;
    }

    int GetNumInList() const
    {
      return count;
    }
  };

  template < class KEY, class ELEMENT > class zTRayTurboValMap
  {
  protected:

  public:
    struct zSNode
    {
      KEY m_Key;
      ELEMENT m_Element;
      unsigned long m_u32Hash;
      zSNode* m_pNext;
    };
  protected:
    zCArray<zSNode*> m_arrNodes;
  public:
    bool32 IsEmpty( void ) const
    {
      return ( 0 == this->GetCount() );
    }

    bool32 IsValidKey( const KEY& a_Key ) const
    {
      unsigned long u32Hash;
      const zSNode* pNode = this->GetNode( a_Key, u32Hash );

      if( Null == pNode )
        return False;

      return True;
    }

    bool32 Contains( const ELEMENT& a_Element ) const
    {
      return ( -1 != this->GetIndex( a_Element ) );
    }

  public:

    void Clear( void )
    {
      this->RemoveAll();
    }

  public:

    const zCArray<zSNode*>& GetData( void ) const
    {
      return this->m_arrNodes;
    }

  protected:

    zSNode* AccessNode( const KEY& a_Key, unsigned long& a_u32Hash )
    {
      a_u32Hash = ::g_GetHashValue< KEY >( a_Key ) % this->m_arrNodes.GetNum();
      int iIndex = static_cast<int> ( a_u32Hash );

      if( this->m_arrNodes.IsEmpty() )
        return Null;

      zSNode* pNode = this->m_arrNodes[iIndex];

      while( Null != pNode )
      {
        if( a_Key == pNode->m_Key )
          return pNode;

        pNode = pNode->m_pNext;
      }
      return Null;
    }

    const zSNode* GetNode( const KEY& a_Key, unsigned long& a_u32Hash ) const
    {
      a_u32Hash = ::g_GetHashValue< KEY >( a_Key ) % this->m_arrNodes.GetNum();
      int iIndex = static_cast<int> ( a_u32Hash );

      if( this->m_arrNodes.IsEmpty() )
        return Null;

      zSNode* pNode = this->m_arrNodes[iIndex];

      while( Null != pNode )
      {
        if( a_Key == pNode->m_Key )
          return pNode;

        pNode = pNode->m_pNext;
      }

      return Null;
    }

  public:
    ELEMENT& AccessAt( const KEY& a_Key )
    {
      unsigned long u32Hash;
      zSNode* pNode = this->AccessNode( a_Key, u32Hash );

      if( Null != pNode )
        return pNode->m_Element;

      pNode = new zSNode;

      pNode->m_Key = a_Key;
      pNode->m_u32Hash = u32Hash;
      pNode->m_pNext = this->m_arrNodes[u32Hash];

      this->m_arrNodes[u32Hash] = pNode;

      return pNode->m_Element;
    }

    const ELEMENT& GetAt( const KEY& a_Key ) const
    {
      unsigned long u32Hash;
      const zSNode* pNode = this->GetNode( a_Key, u32Hash );

      return pNode->m_Element;
    }

    bool32 GetAt( const KEY& a_Key, ELEMENT& a_Element ) const
    {
      unsigned long u32Hash;
      const zSNode* pNode = this->GetNode( a_Key, u32Hash );

      if( Null != pNode )
      {
        a_Element = pNode->m_Element;
        return True;
      }

      return False;
    }

    void SetAt( const KEY& a_Key, const ELEMENT& a_Element )
    {
      this->AccessAt( a_Key ) = a_Element;
    }

    bool32 RemoveAt( const KEY& a_Key )
    {
      unsigned long u32Hash = ::g_GetHashValue< KEY >( a_Key ) % this->m_arrNodes.GetNum();
      int iIndex = static_cast<int> ( u32Hash );

      if( True == this->m_arrNodes.IsEmpty() )
        return GEFalse;

      zSNode* pNode = this->m_arrNodes[iIndex];

      if( a_Key == pNode->m_Key )
      {
        this->m_arrNodes[iIndex] = pNode->m_pNext;
        delete pNode;

        return True;
      }

      while( Null != pNode->m_pNext )
      {
        if( a_Key == pNode->m_pNext->m_Key )
        {
          zSNode* pOldNode = pNode->m_pNext;
          pNode->m_pNext = pNode->m_pNext->m_pNext;

          delete pOldNode;
          return True;
        }

        pNode = pNode->m_pNext;
      }

      return False;
    }

    void DeleteAll( void )
    {
      int iIndex = 0;
      for( iIndex = 0; iIndex < this->m_arrNodes.GetNum(); iIndex++ )
      {
        zSNode* pNode = this->m_arrNodes[iIndex];
        zSNode* pNext = Null;

        while( Null != pNode )
        {
          pNext = pNode->m_pNext;
          delete pNode->m_Element;
          delete pNode;

          pNode = pNext;
        }
      }

      this->m_arrNodes.EmptyList();
      this->Init();
    }

    void RemoveAll( void )
    {
      int iIndex = 0;
      for( iIndex = 0; iIndex < this->m_arrNodes.GetNum(); iIndex++ )
      {
        zSNode* pNode = this->m_arrNodes[iIndex];
        zSNode* pNext = Null;

        while( Null != pNode )
        {
          pNext = pNode->m_pNext;
          delete pNode;
          pNode = pNext;
        }
      }

      this->m_arrNodes.EmptyList();
      this->Init();
    }

  public:
    const ELEMENT& operator [] ( const KEY& a_Key ) const
    {
      return this->GetAt( a_Key );
    }

    ELEMENT& operator [] ( const KEY& a_Key )
    {
      return this->AccessAt( a_Key );
    }

  protected:
    void Init( void )
    {
      this->InitHashTable( 97 );
    }
  public:
    void InitHashTable( unsigned long a_u32HashCount )
    {

      this->m_arrNodes.DeleteList();
      this->m_arrNodes.AllocAbs( a_u32HashCount );

      for( int iNode = 0; iNode < static_cast<int> ( a_u32HashCount ); iNode++ )
      {
        zSNode* pDummyNode = Null;
        this->m_arrNodes.Insert( pDummyNode );
      }
    }

  private:
    zTRayTurboValMap( const zTRayTurboValMap< KEY, ELEMENT >& a_Source ) {}
  public:
    zTRayTurboValMap( void )
    {
      this->Init();
    }

    ~zTRayTurboValMap( void )
    {
      this->RemoveAll();
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZLIST_H__VER3__