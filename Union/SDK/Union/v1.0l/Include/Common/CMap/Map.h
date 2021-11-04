// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_MAP_H__
#define __UNION_MAP_H__

namespace Common {

  template<class KEY, class VALUE>
  class MapPair {
    KEY Key;
    VALUE Value;
  public:

    MapPair();
    MapPair( const KEY& key, const VALUE& value );
    bool operator == ( const KEY& key ) const;
    bool operator <  ( const KEY& key ) const;
    bool operator >  ( const KEY& key ) const;
    bool operator == ( const MapPair& pair ) const;
    bool operator <  ( const MapPair& pair ) const;
    bool operator >  ( const MapPair& pair ) const;

    operator VALUE& ();
    operator const VALUE& () const;

    bool IsNull() const;
    KEY& GetKey();
    VALUE& GetValue();
    const KEY& GetKey() const;
    const VALUE& GetValue() const;
    void Delete();
    void Release();
  };



  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>::MapPair() {
  }

  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>::MapPair( const KEY& key, const VALUE& value ) {
    Key = key;
    Value = value;
  }

#pragma warning(disable:4800)
  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator == ( const KEY& key ) const {
    return Key == key;
  }

  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator < ( const KEY& key ) const {
    return Key < key;
  }

  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator > ( const KEY& key ) const {
    return Key > key;
  }

  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator == ( const MapPair& pair ) const {
    return Key == pair.Key;
  }

  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator < ( const MapPair& pair ) const {
    return Key < pair.Key;
  }

  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::operator > ( const MapPair& pair ) const {
    return Key > pair.Key;
  }
#pragma warning(disable:4800)


  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>::operator VALUE& () {
    return Value;
  }


  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>::operator const VALUE& () const {
    return Value;
  }


  template<class KEY, class VALUE>
  bool MapPair<KEY, VALUE>::IsNull() const {
    return this == Null;
  }


  template<class KEY, class VALUE>
  KEY& MapPair<KEY, VALUE>::GetKey() {
    return Key;
  }


  template<class KEY, class VALUE>
  VALUE& MapPair<KEY, VALUE>::GetValue() {
    return Value;
  }


  template<class KEY, class VALUE>
  const KEY& MapPair<KEY, VALUE>::GetKey() const {
    return Key;
  }


  template<class KEY, class VALUE>
  const VALUE& MapPair<KEY, VALUE>::GetValue() const {
    return Value;
  }


  template<class KEY, class VALUE>
  void MapPair<KEY, VALUE>::Delete() {
    delete Value;
  }


  template<class KEY, class VALUE>
  void MapPair<KEY, VALUE>::Release() {
    Value->Release();
  }






  template<class KEY, class VALUE>
  class Map {
    Array<MapPair<KEY, VALUE>> Pairs;
  public:

    void Insert( const KEY& key, const VALUE& value );
    bool Remove( const KEY& key );
    bool Delete( const KEY& key );
    bool Release( const KEY& key );
    MapPair<KEY, VALUE>& operator [] ( const KEY& key );
    const MapPair<KEY, VALUE>& operator [] ( const KEY& key ) const;
    uint GetNum() const;
    bool IsEmpty() const;
    const Array<MapPair<KEY, VALUE>>& GetArray() const;
    void Clear();

    MapPair<KEY, VALUE>* begin();
    MapPair<KEY, VALUE>* end();
    const MapPair<KEY, VALUE>* begin() const;
    const MapPair<KEY, VALUE>* end() const;
  };


  template<class KEY, class VALUE>
  void Map<KEY, VALUE>::Insert( const KEY& key, const VALUE& value ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid ) {
      Pairs[index].GetValue() = value;
      return;
    }

    Pairs.InsertSorted( MapPair<KEY, VALUE>( key, value ) );
  }


  template<class KEY, class VALUE>
  bool Map<KEY, VALUE>::Remove( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return false;

    Pairs.RemoveAt( index );
    return true;
  }


  template<class KEY, class VALUE>
  bool Map<KEY, VALUE>::Delete( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return false;

    Pairs[index].Delete();
    Pairs.RemoveAt( index );
    return true;
  }


  template<class KEY, class VALUE>
  bool Map<KEY, VALUE>::Release( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return false;

    Pairs[index].Release();
    Pairs.RemoveAt( index );
    return true;
  }


  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>& Map<KEY, VALUE>::operator [] ( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return *(MapPair<KEY, VALUE>*)Null;

    return Pairs[index];
  }


  template<class KEY, class VALUE>
  const MapPair<KEY, VALUE>& Map<KEY, VALUE>::operator [] ( const KEY& key ) const {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return *(MapPair<KEY, VALUE>*)Null;

    return Pairs[index];
  }


  template<class KEY, class VALUE>
  uint Map<KEY, VALUE>::GetNum() const {
    return Pairs.GetNum();
  }


  template<class KEY, class VALUE>
  bool Map<KEY, VALUE>::IsEmpty() const {
    return Pairs.GetNum() == 0;
  }


  template<class KEY, class VALUE>
  const Array<MapPair<KEY, VALUE>>& Map<KEY, VALUE>::GetArray() const {
    return Pairs;
  }

  template<class KEY, class VALUE>
  void Map<KEY, VALUE>::Clear() {
    Pairs.Clear();
  }

  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>* Map<KEY, VALUE>::begin() {
    return Pairs.begin();
  }


  template<class KEY, class VALUE>
  MapPair<KEY, VALUE>* Map<KEY, VALUE>::end() {
    return Pairs.end();
  }


  template<class KEY, class VALUE>
  const MapPair<KEY, VALUE>* Map<KEY, VALUE>::begin() const {
    return Pairs.begin();
  }


  template<class KEY, class VALUE>
  const MapPair<KEY, VALUE>* Map<KEY, VALUE>::end() const {
    return Pairs.end();
  }















  template<class KEY, class VALUE>
  class MapArrayPair {
    KEY Key;
    Array<VALUE> Values;
  public:

    MapArrayPair();
    MapArrayPair( const KEY& key, const VALUE& value );
    bool operator == ( const KEY& key ) const;
    bool operator <  ( const KEY& key ) const;
    bool operator >  ( const KEY& key ) const;
    bool operator == ( const MapArrayPair& pair ) const;
    bool operator <  ( const MapArrayPair& pair ) const;
    bool operator >  ( const MapArrayPair& pair ) const;

    VALUE* begin();
    VALUE* end();
    const VALUE* begin() const;
    const VALUE* end() const;

    operator Array<VALUE>& ();
    operator const Array<VALUE>& () const;
    VALUE& operator [] ( const uint& index );
    const VALUE& operator [] ( const uint& index ) const;

    bool IsNull() const;
    uint GetNum() const;
    bool IsEmpty() const;
    KEY& GetKey();
    Array<VALUE>& GetValues();
    const KEY& GetKey() const;
    const Array<VALUE>& GetValues() const;
    void Delete();
    void Release();
  };



  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>::MapArrayPair() {
  }

  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>::MapArrayPair( const KEY& key, const VALUE& value ) {
    Key = key;
    Values.Insert( value );
  }

#pragma warning(disable:4800)
  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator == ( const KEY& key ) const {
    return Key == key;
  }

  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator < ( const KEY& key ) const {
    return Key < key;
  }

  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator > ( const KEY& key ) const {
    return Key > key;
  }

  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator == ( const MapArrayPair& pair ) const {
    return Key == pair.Key;
  }

  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator < ( const MapArrayPair& pair ) const {
    return Key < pair.Key;
  }

  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::operator > ( const MapArrayPair& pair ) const {
    return Key > pair.Key;
  }
#pragma warning(disable:4800)


  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>::operator Array<VALUE>& () {
    return Values;
  }


  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>::operator const Array<VALUE>& () const {
    return Values;
  }


  template<class KEY, class VALUE>
  VALUE& MapArrayPair<KEY, VALUE>::operator [] ( const uint& index ) {
    return Values[index];
  }


  template<class KEY, class VALUE>
  const VALUE& MapArrayPair<KEY, VALUE>::operator [] ( const uint& index ) const {
    return Values[index];
  }


  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::IsNull() const {
    return this == Null;
  }


  template<class KEY, class VALUE>
  uint MapArrayPair<KEY, VALUE>::GetNum() const {
    return Values.GetNum();
  }


  template<class KEY, class VALUE>
  bool MapArrayPair<KEY, VALUE>::IsEmpty() const {
    return Values.GetNum() == 0;
  }


  template<class KEY, class VALUE>
  KEY& MapArrayPair<KEY, VALUE>::GetKey() {
    return Key;
  }


  template<class KEY, class VALUE>
  Array<VALUE>& MapArrayPair<KEY, VALUE>::GetValues() {
    return Values;
  }


  template<class KEY, class VALUE>
  const KEY& MapArrayPair<KEY, VALUE>::GetKey() const {
    return Key;
  }


  template<class KEY, class VALUE>
  const Array<VALUE>& MapArrayPair<KEY, VALUE>::GetValues() const {
    return Values;
  }


  template<class KEY, class VALUE>
  VALUE* MapArrayPair<KEY, VALUE>::begin() {
    return Values.begin();
  }


  template<class KEY, class VALUE>
  VALUE* MapArrayPair<KEY, VALUE>::end() {
    return Values.end();
  }


  template<class KEY, class VALUE>
  const VALUE* MapArrayPair<KEY, VALUE>::begin() const {
    return Values.begin();
  }


  template<class KEY, class VALUE>
  const VALUE* MapArrayPair<KEY, VALUE>::end() const {
    return Values.end();
  }


  template<class KEY, class VALUE>
  void MapArrayPair<KEY, VALUE>::Delete() {
    for( uint i = 0; i < Values.GetNum(); i++ )
      delete Values[i];
  }


  template<class KEY, class VALUE>
  void MapArrayPair<KEY, VALUE>::Release() {
    for( uint i = 0; i < Values.GetNum(); i++ )
      Values[i]->Release();
  }






  template<class KEY, class VALUE>
  class MapArray {
    Array<MapArrayPair<KEY, VALUE>> Pairs;
  public:

    void Insert( const KEY& key, const VALUE& value );
    void Remove( const KEY& key );
    void Remove( const KEY& key, const VALUE& value );
    void Delete( const KEY& key );
    void Delete( const KEY& key, const VALUE& value );
    void Release( const KEY& key );
    void Release( const KEY& key, const VALUE& value );
    MapArrayPair<KEY, VALUE>& operator [] ( const KEY& key );
    const MapArrayPair<KEY, VALUE>& operator [] ( const KEY& key ) const;
    uint GetNum() const;
    const Array<MapArrayPair<KEY, VALUE>>& GetArray() const;
    void Clear();

    MapArrayPair<KEY, VALUE>* begin();
    MapArrayPair<KEY, VALUE>* end();
    const MapArrayPair<KEY, VALUE>* begin() const;
    const MapArrayPair<KEY, VALUE>* end() const;
  };


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Insert( const KEY& key, const VALUE& value ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid ) {
      Pairs[index].GetValues().Insert( value );
      return;
    }

    Pairs.InsertSorted( MapArrayPair<KEY, VALUE>( key, value ) );
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Remove( const KEY& key ) {
    Pairs.RemoveSorted( key );
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Remove( const KEY& key, const VALUE& value ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid )
      Pairs[index].GetValues().Remove( value );
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Delete( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid ) {
      Pairs[index].Delete();
      Pairs.RemoveAt( key );
    }
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Delete( const KEY& key, const VALUE& value ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid )
      Pairs[index].GetValues().Delete( value );
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Release( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid ) {
      Pairs[index].Release();
      Pairs.RemoveAt( key );
    }
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Release( const KEY& key, const VALUE& value ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index != Invalid ) {
      value->Release();
      Pairs[index].GetValues().Remove( value );
    }
  }


  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>& MapArray<KEY, VALUE>::operator [] ( const KEY& key ) {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return *(MapArrayPair<KEY, VALUE>*)Null;

    return Pairs[index];
  }


  template<class KEY, class VALUE>
  const MapArrayPair<KEY, VALUE>& MapArray<KEY, VALUE>::operator [] ( const KEY& key ) const {
    uint index = Pairs.SearchEqualSorted( key );
    if( index == Invalid )
      return *(MapArrayPair<KEY, VALUE>*)Null;

    return Pairs[index];
  }


  template<class KEY, class VALUE>
  uint MapArray<KEY, VALUE>::GetNum() const {
    return Pairs.GetNum();
  }


  template<class KEY, class VALUE>
  const Array<MapArrayPair<KEY, VALUE>>& MapArray<KEY, VALUE>::GetArray() const {
    return Pairs;
  }


  template<class KEY, class VALUE>
  void MapArray<KEY, VALUE>::Clear() {
    return Pairs.Clear();
  }


  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>* MapArray<KEY, VALUE>::begin() {
    return Pairs.begin();
  }


  template<class KEY, class VALUE>
  MapArrayPair<KEY, VALUE>* MapArray<KEY, VALUE>::end() {
    return Pairs.end();
  }


  template<class KEY, class VALUE>
  const MapArrayPair<KEY, VALUE>* MapArray<KEY, VALUE>::begin() const {
    return Pairs.begin();
  }


  template<class KEY, class VALUE>
  const MapArrayPair<KEY, VALUE>* MapArray<KEY, VALUE>::end() const {
    return Pairs.end();
  }
}

#endif // __UNION_MAP_H__