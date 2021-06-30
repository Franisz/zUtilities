// Supported with union (c) 2018 Union team

#ifndef __ZCONTAINER_H__VER3__
#define __ZCONTAINER_H__VER3__

namespace Gothic_II_Addon {
  const int zARRAY_START_ALLOC = 16;

  template <class T>
  class zCArray {
  protected:
    T *parray;
    int numAlloc;
    int numInArray;
  public:
    zCArray() {
      numInArray = 0;
      numAlloc = 0;
      parray = 0;
    }

    zCArray( const int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      parray = 0;
      if( startSize > 0 ) {
        parray = new T[startSize];
      }
    }

    zCArray( const zCArray<T>& array2 ) {
      numInArray = 0;
      numAlloc = 0;
      parray = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ ) {
        parray[i] = array2.parray[i];
      }
    }

    ~zCArray() {
      delete[] parray;
      parray = 0;
    }

    T* GetArray() const {
      return parray;
    }

    void ZeroFill() {
      if( parray ) {
        memset( parray, 0, sizeof( T )*numAlloc );
      }
    }

    void AllocDelta( const int numDelta ) {
      if( numDelta <= 0 ) return;
      T *newArray = new T[numAlloc + numDelta];
      if( numInArray > 0 ) {
        for( int i = 0; i < numInArray; i++ ) {
          newArray[i] = parray[i];
        }
      }
      delete[] parray;
      parray = newArray;
      numAlloc += numDelta;
    }

    void AllocAbs( const int size ) {
      if( numAlloc >= size ) {
        return;
      }
      AllocDelta( size - numAlloc );
    }

    void MarkNumAllocUsed() {
      numInArray = numAlloc;
    }

    void ShrinkToFit() {
      if( numInArray <= 0 ) {
        DeleteList();
        return;
      }
      if( numAlloc > numInArray ) {
        T *newArray = new T[numInArray];
        for( int i = 0; i < numInArray; i++ ) {
          newArray[i] = parray[i];
        }
        delete[] parray;
        parray = newArray;
        numAlloc = numInArray;
      }
    }

    void operator = ( const zCArray<T>& array2 ) {
      EmptyList();
      AllocAbs( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ ) {
        parray[i] = array2.parray[i];
      }
    }

    const T& operator [] ( const int nr ) const {
      return parray[nr];
    }

    T& operator [] ( const int nr ) {
      return parray[nr];
    }

    T& GetSafe( int nr ) const {
      if( numInArray <= 0 ) {
        Message::Fatal( "D: zTree(zCArray::GetSafe): numInArray<=0" );
      }
      if( numAlloc <= 0 ) {
        Message::Fatal( "D: zTree(zCArray::GetSafe): numAlloc <=0" );
      }
      if( nr < 0 ) {
        nr = 0;
      }
      else if( nr >= numInArray ) {
        nr = numInArray - 1;
      }
      return parray[nr];
    }

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC ) {
          AllocDelta( zARRAY_START_ALLOC );
        }
        else {
          AllocDelta( numAlloc / 2 );
        }
      }
      parray[numInArray++] = ins;
    }

    void InsertFront( const T& ins ) {
      InsertAtPos( ins, 0 );
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC ) {
          AllocDelta( zARRAY_START_ALLOC );
        }
        else {
          AllocDelta( numAlloc / 2 );
        }
      }
      memmove( &parray[pos + 1], &parray[pos], sizeof( T ) * ( numInArray - pos ) );
      parray[pos] = ins;
      numInArray++;
    }

    void Remove( const T& rem ) {
      if( numInArray == 0 ) {
        return;
      }
      for( int i = 0; i < numInArray; i++ ) {
        if( parray[i] == rem ) {
          numInArray--;
          if( i != numInArray ) {
            parray[i] = parray[numInArray];
          }
          return;
        }
      }
    }

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 ) {
        return;
      }
      numInArray--;
      if( index != numInArray ) {
        parray[index] = parray[numInArray];
      }
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( parray[i] == rem ) {
          RemoveOrderIndex( i );
          return;
        }
      }
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray ) {
        return;
      }
      if( index != numInArray - 1 ) {
        for( int j = index; j < numInArray - 1; j++ ) {
          parray[j] = parray[j + 1];
        }
      }
      numInArray--;
    }

    void DeleteList() {
      delete[] parray;
      parray = 0;
      numAlloc = 0;
      numInArray = 0;
    }

    void EmptyList() {
      numInArray = 0;
    }

    int Search( const T& data ) const {
      if( numInArray > 0 ) {
        for( int i = 0; i < numInArray; i++ ) {
          if( parray[i] == data ) {
            return i;
          }
        }
      }
      return Invalid;
    }

    int IsInList( const T& data ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( parray[i] == data ) {
          return True;
        }
      }
      return False;
    }

    int GetNumInList() const {
      return numInArray;
    }

    int GetNum() const {
      return numInArray;
    }

    bool32 IsEmpty() const {
      return ( numInArray <= 0 );
    }

    void InsertArray( const zCArray<T>& other ) {
      AllocAbs( other.GetNumInList() + GetNumInList() );
      for( int i = 0; i < other.GetNumInList(); i++ ) {
        parray[numInArray++] = other[i];
      }
    }

    bool32 CheckDoubles() {
      for( int i = 0; i < GetNumInList() - 1; i++ ) {
        for( int j = i + 1; j < GetNumInList(); j++ ) {
          if( parray[i] == parray[j] ) {
            return True;
          }
        }
      }
      return False;
    }

    void RemoveDoubles() {
      for( int i = 0; i < GetNumInList() - 1; i++ ) {
        for( int j = i + 1; j < GetNumInList(); j++ ) {
          if( parray[i] == parray[j] ) {
            parray[j] = parray[numInArray - 1];
            numInArray--;
            j--;
          }
        }
      }
      return False;
    }

    void DeleteListDatas() {
      for( int i = 0; i != numInArray; ++i ) {
        SAFE_DELETE( parray[i] );
      }
      DeleteList();
    }

    // user API
    #include "zCArray.inl"
  };

  inline int zArraySortDefaultCompare( const void* ele1, const void* ele2 ) {
    if( *( (unsigned int*)ele1 ) < ( *(unsigned int*)ele2 ) ) return -1;
    if( *( (unsigned int*)ele1 ) > ( *(unsigned int*)ele2 ) ) return +1;
    else return 0;
  }

  template <class T>
  class zCArraySort {
  protected:
    T *array;
    int numAlloc;
    int numInArray;

    int( *Compare )( const void* ele1, const void* ele2 );
  public:
    zCArraySort() {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      SetCompare( zArraySortDefaultCompare );
    }

    zCArraySort( const int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      array = 0;
      if( startSize > 0 ) {
        array = new T()[startSize];
      }
      SetCompare( zArraySortDefaultCompare );
    }

    zCArraySort( const zCArraySort<T>& array2 ) {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ ) {
        array[i] = array2.array[i];
      }
      SetCompare( array2.Compare );
    }

    ~zCArraySort() {
      delete[] array;
      array = 0;
    }

    T* GetArray() const {
      return array;
    }

    void SetCompare( int( *Cmp )( const void* ele1, const void* ele2 ) ) {
      Compare = Cmp;
    }

    void AllocDelta( const int numDelta ) {
      if( numDelta <= 0 ) {
        return;
      }
      T *newArray = new T[numAlloc + numDelta];
      if( numInArray > 0 ) {
        for( int i = 0; i < numInArray; i++ ) {
          newArray[i] = array[i];
        }
      }
      delete[] array;
      array = newArray;
      numAlloc += numDelta;
    }

    void AllocAbs( const int size ) {
      if( numAlloc >= size ) {
        return;
      }
      AllocDelta( size - numAlloc );
    }

    void ShrinkToFit() {
      if( numInArray <= 0 ) {
        DeleteList();
        return;
      }
      if( numAlloc > numInArray ) {
        T *newArray = new T()[numInArray];
        for( int i = 0; i < numInArray; i++ ) {
          newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        numAlloc = numInArray;
      }
    }

    void operator = ( const zCArraySort<T>& array2 ) {
      EmptyList();
      AllocAbs( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ ) {
        array[i] = array2.array[i];
      }
    }

    const T& operator [] ( const int nr ) const {
      return array[nr];
    }

    T& operator [] ( const int nr ) {
      return array[nr];
    }

    T& GetSafe( int nr ) const {
      if( numInArray <= 0 ) Message::Fatal( "D: zTree(zCArraySort::GetSafe): numInArray<=0" );
      if( numAlloc <= 0 ) Message::Fatal( "D: zTree(zCArraySort::GetSafe): numAlloc <=0" );
      if( nr < 0 ) {
        nr = 0;
      }
      else if( nr >= numInArray ) {
        nr = numInArray - 1;
      }
      return array[nr];
    }

    T& Get( const int nr ) const {
      return array[nr];
    }

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC ) {
          AllocDelta( zARRAY_START_ALLOC );
        }
        else {
          AllocDelta( numAlloc / 2 );
        }
      }
      array[numInArray++] = ins;
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC ) {
          AllocDelta( zARRAY_START_ALLOC );
        }
        else {
          AllocDelta( numAlloc / 2 );
        }
      }
      memmove( &array[pos + 1], &array[pos], sizeof( T ) * ( numInArray - pos ) );
      array[pos] = ins;
      numInArray++;
    }

    void InsertSort( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC ) {
          AllocDelta( zARRAY_START_ALLOC );
        }
        else {
          AllocDelta( numAlloc / 2 );
        }
      }
      int ind_low = 0;
      int ind_high = numInArray - 1;
      int index = ( ind_low + ind_high ) / 2;
      int erg;

      do {
        if( ind_high <= ind_low ) {
          if( index >= numInArray ) {
            array[index] = ins;
            numInArray++;
            return;
          }
          else {
            erg = Compare( &ins, &( array[index] ) );
            if( erg > 0 ) {
              index++;
            }
          }
          memmove( &array[index + 1], &array[index], sizeof( T ) * ( numInArray - index ) );
          array[index] = ins;
          numInArray++;
          return;
        }
        erg = Compare( &ins, &( array[index] ) );

        if( erg > 0 ) {
          ind_low = index + 1;
        }
        else {
          ind_high = index - 1;
        }
        index = ( ind_low + ind_high ) / 2;
      } while( true );
    }

    int Search( const T& ins ) const {
      if( numInArray <= 0 ) {
        return Invalid;
      }
      int ind_low = 0;
      int ind_high = numInArray - 1;
      int index = ( ind_low + ind_high ) / 2;
      int erg;

      do {
        erg = Compare( &ins, &( array[index] ) );
        if( ind_high <= ind_low ) {
          if( erg == 0 ) {
            return index;
          }
          return Invalid;
        }
        if( erg > 0 ) {
          ind_low = index + 1;
        }
        else if( erg < 0 ) {
          ind_high = index - 1;
        }
        else {
          return index;
        }
        index = ( ind_low + ind_high ) / 2;
      } while( true );
    }

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 ) {
        return;
      }
      numInArray--;
      if( index != numInArray ) {
        array[index] = array[numInArray];
      }
    }

    void Remove( const T& rem ) {
      if( numInArray == 0 ) {
        return;
      }
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          numInArray--;
          if( i != numInArray ) {
            array[i] = array[numInArray];
          }
          return;
        }
      }
    }

    void RemoveOrder( const T& rem ) {
      int i = Search( rem );
      if( i != Invalid ) {
        RemoveOrderIndex( i );
      }
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray ) {
        return;
      }
      if( index != numInArray - 1 ) {
        for( int j = index; j < numInArray - 1; j++ ) {
          array[j] = array[j + 1];
        }
      }
      numInArray--;
    }
    void DeleteList() {
      delete[] array;
      array = 0;
      numAlloc = 0;
      numInArray = 0;
    }
    void EmptyList() {
      numInArray = 0;
    }

    int IsInList( const T& data ) const {
      int i = Search( data );
      if( i == Invalid ) {
        return False;
      }
      return True;
    }

    void MarkNumAllocUsed() {
      numInArray = numAlloc;
    }

    int GetNumInList() const {
      return numInArray;
    }

    int GetNum() const {
      return numInArray;
    }

    bool32 IsEmpty() const {
      return ( numInArray <= 0 );
    }

    void QuickSort() {
      qsort( array, GetNumInList(), sizeof( T ), Compare );
    }

    void InsertionSort() {
      insertionsort( array, GetNumInList(), sizeof( T ), Compare, False );
    }

    void BestSort() {
      insertionsort( array, GetNumInList(), sizeof( T ), Compare, True );
    }

    // user API
    #include "zCArraySort.inl"
  };


  template <class T>
  class zCArrayAdapt {
  protected:
    T *array;
    int numInArray;
  public:
    zCArrayAdapt() {
      numInArray = 0;
      array = 0;
    }

    ~zCArrayAdapt() {
      array = 0;
    }

    T* GetArray() const {
      return array;
    }

    DWORD GetSizeBytes() const {
      return sizeof( T )*numInArray;
    }

    DWORD SetArray( void* ptr, const int num ) {
      array = (T*)ptr;
      numInArray = num;
      return sizeof( T )*numInArray;
    }

    void SetNumInArray( const int num ) {
      numInArray = num;
    }

    void EmptyList() {
      numInArray = 0;
    }

    int GetNum() const {
      return numInArray;
    }

    bool32 IsEmpty() const {
      return ( numInArray <= 0 );
    }

    const T& operator [] ( const int nr ) const {
      return array[nr];
    }

    T& operator [] ( const int nr ) {
      return array[nr];
    }

    T& GetSafe( int nr ) const {
      if( numInArray <= 0 ) {
        Message::Fatal( "D: (zCArrayAdapt::GetSafe): numInArray<=0" );
      }
      if( nr < 0 ) {
        nr = 0;
      }
      else if( nr >= numInArray ) {
        nr = numInArray - 1;
      }
      return array[nr];
    }

    void InsertEnd( const T& ins ) {
      array[numInArray++] = ins;
    }

    void InsertFront( const T& ins ) {
      InsertAtPos( ins, 0 );
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      memmove( &array[pos + 1], &array[pos], sizeof( T ) * ( numInArray - pos ) );
      array[pos] = ins;
      numInArray++;
    }

    void Remove( const T& rem ) {
      if( numInArray == 0 ) {
        return;
      }
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          numInArray--;
          if( i != numInArray ) {
            array[i] = array[numInArray];
          }
          return;
        }
      }
    }

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 ) {
        return;
      }
      numInArray--;
      if( index != numInArray ) {
        array[index] = array[numInArray];
      }
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          RemoveOrderIndex( i );
          return;
        }
      }
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray ) {
        return;
      }
      if( index != numInArray - 1 ) {
        for( int j = index; j < numInArray - 1; j++ ) {
          array[j] = array[j + 1];
        }
      }
      numInArray--;
    }

    int Search( const T& data ) const {
      if( numInArray > 0 ) {
        for( int i = 0; i < numInArray; i++ ) {
          if( array[i] == data ) {
            return i;
          }
        }
      }
      return Invalid;
    }
    int IsInList( const T& data ) const {
      if( numInArray > 0 ) {
        for( int i = 0; i < numInArray; i++ ) {
          if( array[i] == data ) {
            return True;
          }
        }
      }
      return False;
    }

    // user API
    #include "zCArrayAdapt.inl"
  };

  template <class T, int SIZE> class zCMatrixStack {
    int pos;
    T stack[SIZE];
  public:
    zCMatrixStack() : pos( 0 ) {}

    void Push( const T& m ) {
      if( pos >= SIZE ) {
        Message::Fatal( "D: (zCMatrixStack::Push): curPos>=numInArray" );
      }
      stack[pos++] = m;
    }
    T Pop( void ) {
      if( pos < 0 ) {
        Message::Fatal( "D: (zCMatrixStack::Pop): curPos<0" );
      }
      return stack[--pos];
    }
  };

  template <class T>
  class zCTree {
  protected:
    zMEMPOOL_DECLARATION_TEMPLATE( zCTree, 0x008D837C )

      zCTree* parent;
    zCTree* firstChild;
    zCTree* next;
    zCTree* prev;
    T* data;

    void RemoveChild() {
      if( prev ) {
        prev->next = next;
      }
      if( next ) {
        next->prev = prev;
      }
      if( parent ) {
        if( this == parent->firstChild ) {
          parent->firstChild = next;
        }
      }
    }

  public:
    zCTree() {
      firstChild = parent = next = prev = 0;
      data = 0;
    }

    ~zCTree() {
      data = 0;
      while( firstChild ) {
        delete firstChild;
      }
      RemoveChild();
    }

    void DeleteDataSubtree() {
      if( data ) {
        delete data;
        data = 0;
      }
      zCTree* child = GetFirstChild();
      while( child ) {
        child->DeleteDataSubtree();
        child = child->GetNextChild();
      }
    }
    void DeleteChilds() {
      while( firstChild ) {
        delete firstChild;
      }
      RemoveChild();
    }

    T** GetPtrToData() const {
      return &data;
    }

    T* GetData() const {
      return data;
    }

    void SetData( T* d ) {
      data = d;
    }

    zCTree* AddChild( T* d ) {
      zCTree* newNode = new zCTree;
      newNode->parent = this;
      newNode->prev = 0;
      newNode->next = firstChild;
      newNode->data = d;
      firstChild = newNode;
      if( newNode->next != 0 ) {
        newNode->next->prev = newNode;
      }
      return newNode;
    }

    zCTree* AddChild( zCTree* node ) {
      node->parent = this;
      node->prev = 0;
      node->next = firstChild;
      firstChild = node;
      if( node->next != 0 ) {
        node->next->prev = node;
      }
      return node;
    }
    zCTree* GetParent() {
      return parent;
    }

    zCTree* GetFirstChild() {
      return firstChild;
    }

    zCTree* GetNextChild() {
      return next;
    }

    zCTree* GetPrevChild() {
      return prev;
    }

    int GetNumChilds() {
      int num = 0;
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        num++;
        child = child->GetNextChild();
      }
      return num;
    }

    zCTree* Search( T* d ) {
      if( data == d ) {
        return this;
      }
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        zCTree* res = child->Search( d );
        if( res != 0 ) {
          return res;
        }
        child = child->GetNextChild();
      }
      return Null;
    }

    int Search( const zCTree* node ) {
      if( this == node ) {
        return True;
      }
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        if( child->Search( node ) ) {
          return True;
        }
        child = child->GetNextChild();
      }
      return False;
    }

    int CountNodes() {
      int a, b;
      a = b = 0;
      if( firstChild != 0 ) {
        a = firstChild->CountNodes();
      }
      if( next != 0 ) {
        b = next->CountNodes();
      }
      return a + b + 1;
    }

    void RemoveSubtree() {
      if( parent && parent->firstChild == this ) {
        parent->firstChild = next;
      }

      if( prev != 0 ) {
        prev->next = next;
      }
      if( next != 0 ) {
        next->prev = prev;
      }
      prev = next = 0;
    }

    void MoveSubtreeTo( zCTree* destParent ) {
      RemoveSubtree();
      if( destParent ) {
        destParent->AddChild( this );
      }
      else parent = 0;
    }

    // user API
    #include "zCTree.inl"
  };

  template <class obj> class zList {
    int( *Compare )( obj *ele1, obj *ele2 );
    int count;
    obj *last;
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCList, 0x008D8398 );

    obj *root;

    zList() {
      last = 0;
      root = Null;
      count = 0;
    }

    void SetCompare( int( *Cmp )( obj *ele1, obj *ele2 ) ) {
      Compare = Cmp;
    }

    void Clear() {
      obj *ele, *help;
      ele = root;
      while( ele != Null ) {
        help = ele;
        ele = ele->next;
        delete( help );
      }
      last = Null;
      root = Null;
      count = 0;
    }

    void Insert( obj *ins ) {
      if( IsIn( ins ) ) {
        return;
      }
      if( root == Null ) {
        last = ins;
      }
      ins->next = root;
      root = ins;
      count++;
    }

    void InsertLast( obj *ins ) {
      if( IsIn( ins ) ) {
        return;
      }
      count++;
      ins->next = Null;
      if( root == Null ) {
        last = ins;
        root = ins;
      }
      else {
        last->next = ins;
        ins->next = Null;
        last = ins;
      }
    }

    bool32 InsertAsNext( obj* object, obj* ins ) {
      if( IsIn( ins ) ) {
        return False;
      }

      if( ( !object ) || ( !ins ) ) {
        return False;
      }
      ins->next = object->next;
      object->next = ins;

      count++;
      return True;
    }

    bool32 InsertAsPrevious( obj* ins, obj* object ) {
      if( IsIn( ins ) ) {
        return False;
      }

      if( ( !object ) || ( !ins ) ) {
        return False;
      }
      if( root == object ) {
        ins->next = root;
        root = ins;
        count++;
        return True;
      }

      obj* ele = root;
      while( ele != Null ) {
        if( ele->next == object ) {
          ins->next = object;
          ele->next = ins;
          count++;
          return True;
        }
        ele = ele->next;
      }
      return False;
    }

    void InsertSort( obj *ins ) {
      obj *ele;
      if( IsIn( ins ) ) {
        return;
      }

      if( ( root == Null ) || ( Compare( ins, root ) < 0 ) ) {
        ins->next = root;
        root = ins;
        count++;
      }
      else {
        ele = root;
        while( ele->next != Null ) {
          if( Compare( ins, ele->next ) <= 0 ) {

            ins->next = ele->next;
            ele->next = ins;
            count++;
            return;
          }
          ele = ele->next;
        }

        ele->next = ins;
        ins->next = Null;
        last = ins;
        count++;
      }
    }

    void Remove( obj *rem ) {
      obj *ele = root;

      if( ele == Null ) {
        return;
      }
      if( ele == rem ) {
        root = ele->next;
        if( root == Null ) {
          last = Null;
        }
        count--;
        if( count < 0 ) {
          Message::Fatal( "U: LIST: Count is less than 0" );
        }
      }
      else {
        while( ele->next != Null ) {
          if( ele->next == rem ) {
            if( rem->next == Null ) last = ele;
            ele->next = rem->next;
            count--;
            if( count < 0 ) {
              Message::Fatal( "U: LIST: Count is less than 0" );
            }
            return;
          }

          if( ele == ele->next ) {
            ele->next = Null;
          }
          else {
            ele = ele->next;
          }
        }
      }
    }

    void Delete( obj *rem ) {
      obj *ele = root;

      if( ele == Null ) {
        return;
      }
      if( ele == rem ) {
        root = ele->next;
        if( root == Null ) {
          last = Null;
        }
        delete( ele );
        count--;
        if( count < 0 ) {
          Message::Fatal( "U: LIST: Count is less than 0" );
        }
      }
      else {
        while( ele->next != Null ) {
          if( ele->next == rem ) {
            if( rem->next == Null ) {
              last = ele;
            }
            ele->next = rem->next;
            delete( rem );
            count--;
            if( count < 0 ) {
              Message::Fatal( "U: LIST: Count is less than 0" );
            }
            return;
          }
          ele = ele->next;
        }
      }
    }

    obj* Get( int nr ) {
      obj *ele = root;
      int c = 0;

      while( ele != Null ) {
        c++;
        if( c == nr ) {
          return( ele );
        }
        ele = ele->next;
      }
      return Null;
    }

    obj *GetLast() {
      return last;
    }

    BOOL IsIn( obj *ele2 ) {
      obj *ele = root;

      while( ele != Null ) {
        if( ele == ele2 ) {
          return True;
        }
        ele = ele->next;
      }
      return False;
    }

    int Count() {
      return count;
    }
  };

  template <class T>
  class zCList {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCList, 0x008D8398 );

    T *data;
    zCList *next;
  public:
    zCList() {
      next = 0;
      data = 0;
    }

    ~zCList() {
      if( next ) {
        delete next;
        next = 0;
      }
      data = 0;
    }

    void DeleteList() {
      if( next ) {
        delete next;
        next = 0;
      }
    }

    void DeleteListDatas() {
      if( data ) {
        delete data;
        data = 0;
      }

      if( next ) {
        next->DeleteListDatas();
        delete next;
        next = 0;
      }
    }

    void Replace( T *ins ) {
      data = ins;
    }

    void Insert( T *ins ) {
      zCList *newItem = new zCList();
      newItem->data = ins;
      newItem->next = next;
      next = newItem;
    }

    void InsertFront( T *ins ) {
      zCList *newItem = new zCList();
      newItem->data = ins;
      newItem->next = next;
      next = newItem;
    }

    void Remove( T *rem ) {
      zCList *item = this;

      while( item->next != 0 ) {
        if( item->next->data == rem ) {
          zCList *tmp = item->next;
          item->next = item->next->next;
          tmp->next = 0;
          delete tmp;
          return;
        }
        item = item->next;
      }
    }

    T* Get( const int nr ) const {
      zCList *item = next;
      int c = 0;
      while( item ) {
        if( c == nr ) {
          return item->data;
        }
        item = item->next;
        c++;
      }
      return 0;
    }

    T* operator [] ( const int nr ) const {
      return Get( nr );
    }

    zCList* GetNextInList() const {
      return next;
    }

    T* GetData() const {
      return data;
    }

    bool32 InList( T *data ) const {
      zCList *item = next;
      while( item != 0 ) {
        if( item->data == data ) {
          return True;
        }
        item = item->next;
      }
      return False;
    }

    bool32 IsInList( T *data ) const {
      zCList *item = next;
      while( item != 0 ) {
        if( item->data == data ) {
          return True;
        }
        item = item->next;
      }
      return False;
    }

    int GetNumInList() const {
      int count = 0;
      zCList *item = next;
      while( item != 0 ) {
        count++;
        item = item->next;
      }
      return count;
    }
    int GetNum() const {
      return GetNumInList();
    }

    // user API
    #include "zCList.inl"
  };

  template <class T>
  class GETSmallArrayNative {
  private:
    unsigned long Entries;

    void Grow() {
      int delta;
      if( Used >= Entries ) {
        if( Entries > 64 ) delta = Entries / 4;
        else {
          if( Entries > 8 ) delta = 16;
          else delta = 4;
        }
        Entries += delta;
        T* newEntry = (T*)zmalloc.Realloc( Entry, sizeof( T )*Entries );
        Entry = newEntry;
      }
    }

  public:
    unsigned long Used;
    T *Entry;

    GETSmallArrayNative() {
      Entries = 1;
      Entry = (T*)zmalloc.Malloc( sizeof( T )*Entries );
      memset( Entry, 0, sizeof( T )*Entries );
      Used = 0;
    }

    GETSmallArrayNative( int entries ) {
      Entries = entries;
      Entry = (T*)zmalloc.Malloc( sizeof( T )*Entries );
      memset( Entry, 0, sizeof( T )*Entries );
      Used = 0;
    }

    GETSmallArrayNative<T> &operator=( GETSmallArrayNative<T> &classItem ) {
      if( Entries == classItem.GetAllocatedEntries() ) {
        Used = classItem.Used;
        memcpy( &Entry[0], &classItem.Entry[0], sizeof( T )*classItem.Used );
      }
      else {
        Used = classItem.Used;
        zmalloc.Free( Entry );
        Entry = (T*)zmalloc.Malloc( sizeof( T ) * ( classItem.Used + 1 ) );
        memcpy( &Entry[0], &classItem.Entry[0], sizeof( T )*classItem.Used );
      }
      return *this;
    }

    unsigned long GetAllocatedEntries() {
      return Entries;
    }

    bool32 Reserve( unsigned long entries ) {
      if( entries < Entries )
        return False;
      Entries = entries;
      T* newEntry = (T*)zmalloc.Realloc( Entry, sizeof( T )*Entries );
      Entry = newEntry;
      return True;
    }

    unsigned long Add( T &item ) {
      Grow();
      Entry[Used] = item;
      Used++;
      return Used - 1;
    }

    void Remove( unsigned long ref ) {
      if( Used == 0 ) {
        return;
      }
      unsigned long i = Used - ( ref + 1 );
      memmove( &Entry[ref], &Entry[ref + 1], i * sizeof( T ) );
      Used--;
    }

    ~GETSmallArrayNative() {
      zmalloc.Free( Entry );
    }
  };
} // namespace Gothic_II_Addon


#endif // __ZCONTAINER_H__VER3__