// Supported with union (c) 2018 Union team

#ifndef __ZBVOLUME_UTIL_H__VER0__
#define __ZBVOLUME_UTIL_H__VER0__

namespace Gothic_I_Classic {
  template <class VOB> class zCVobBBox3DSorter : public zCBBox3DSorterBase {
  public:

    class zTBoxSortHandle : public zCBBox3DSorterBase::zTBoxSortHandle {

    public:
      virtual ~zTBoxSortHandle() {}

      virtual void AddActive( void* data ) {
        if( !activeList.IsInList( (VOB*)data ) )
          activeList.Insert( (VOB*)data );
      }
      virtual void DelActive( void *data ) {
        activeList.Remove( (VOB*)data );
      }
      virtual void ClearActive() {
        activeList.DeleteList();
      }
      int GetNum() {
        return activeList.GetNum();
      }
      VOB* GetElement( int i ) {
        return activeList[i];
      }
      zCArray<VOB*> activeList;

      // user API
      #include "zCOBBox3D_zTBoxSortHandle.inl"
    };

    virtual ~zCVobBBox3DSorter() {
    }
    void Insert( VOB* inData ) {
      zCBBox3DSorterBase::Insert( (void *)inData );
    }
    void Update( VOB* inData ) {
      zCBBox3DSorterBase::Update( (void *)inData );
    }
    void Remove( VOB* inData ) {
      zCBBox3DSorterBase::Remove( (void *)inData );
    }
    void GetActiveList( const zTBBox3D& bbox3D, zTBoxSortHandle& outHandle ) {
      zCBBox3DSorterBase::GetActiveList( bbox3D, outHandle );
    }
    void UpdateActiveList( const zTBBox3D& bbox3D, zTBoxSortHandle& handle ) {
      zCBBox3DSorterBase::GetActiveList( bbox3D, handle );
    }
    void GetActiveList( const zTBBox3D& bbox3D, zTBoxSortHandle& outHandle, zCArraySort<VOB*> &list ) {
      zCBBox3DSorterBase::GetActiveList( bbox3D, outHandle );
      list.EmptyList();
      for( int i = outHandle.GetNum() - 1; i >= 0; i-- ) {
        list.Insert( outHandle.GetElement( i ) );
      }
    }
    void UpdateActiveList( const zTBBox3D& bbox3D, zTBoxSortHandle& handle, zCArraySort<VOB*> &list ) {
      zCBBox3DSorterBase::UpdateActiveList( bbox3D, handle );
      list.EmptyList();
      for( int i = handle.GetNum() - 1; i >= 0; i-- ) {
        list.Insert( handle.GetElement( i ) );
      }
    }
    virtual const zTBBox3D& GetBBox( const zTNode *node ) {
      return ( (VOB*)node->data )->bbox3D;
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZBVOLUME_UTIL_H__VER0__