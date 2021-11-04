// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARRAY_BASE_H__
#define __UNION_ARRAY_BASE_H__

#define _rcast(t, v) reinterpret_cast<t>(v)
#define _dcast(t, v) dynamic_cast<t>(v)
#define _ccast(t, v) const_cast<t>(v)
#define _scast(t, v) static_cast<t>(v)

namespace Common {
  class ASTAPI CArrayBase
  {
    friend class CArchiver;
  protected:
    void32  vector;
    uint32  unMalloc;
    uint32  unSize;
    uint32  unSizeof;
    uint32  unReserveRatio;

  private:
    void AllocDelta();
    void AllocArray( const uint32& unSize );

  public:
    CArrayBase( const uint32& unitSize );
    CArrayBase( const uint32& unitSize, const void32 dst );

  protected:
    void InsertEnd( const void32 obj );
    void Insert( const void32 obj );
    void InsertAt( const uint32& idx, const void32 obj );
    void InsertFront( const void32 obj );

    void Merge( CArrayBase* arr );
    void MergeAt( CArrayBase* arr, const uint32& );

    void Remove( const void32 obj );
    void RemoveAt( const uint32& idx );
    void FastRemove( const void32 obj );
    void FastRemoveAt( const uint32& idx );

    void Delete( const void32 obj );
    void DeleteAt( const uint32& idx );
    void FastDelete( const void32 obj );
    void FastDeleteAt( const uint32& idx );

  public:
    void RemoveAtBounds( const uint32& idx, const uint32& length );
    void DeleteAtBounds( const uint32& idx, const uint32& length );

  protected:
    uint32 Search( const void32 obj ) const;
    void32 CopyAtBounds( const uint32& idx, const uint32& length ) const;
    void32 operator [] ( const uint32& idx );
    const void32 operator [] ( const uint32& idx ) const;

  public:
    uint32 GetNum() const;
    uint32 GetElmSizeof() const;
    void SetReserveRatio( const uint32& val = 2 );
    void Compress();
    const uint32 GetRealSizeof() const;
    const uint32 GetUsedSizeof() const;
    void Clear();
    void DeleteData();
    bool32 IsIn( const void32 obj ) const;
    bool32 HasDoubles() const;
    void RemoveDoubles();
    void32 GetItem( const uint32& index );
    const void32 GetItem( const uint32& index ) const;
    void32 ReserveArray( const uint32& num );
    virtual ~CArrayBase();
  };
} // namespace Common

#endif // __UNION_ARRAY_BASE_H__