#pragma once
#include <iostream>

#ifndef INLINE
#define INLINE __INLINE
#endif


#pragma region operators
namespace Common {

  INLINE CStringA operator + ( const CStringA str, const int32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const int32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const long32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const long32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const uint32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const uint32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const ulong32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const ulong32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const int64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const int64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const uint64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const uint64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const real32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const real32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const real64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const real64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const char* val, const CStringA& str ) {
    return CStringA( val ) + str;
  }

  INLINE CStringW operator + ( const wchar_t* val, const CStringW& str ) {
    return CStringW( val ) + str;
  }



  INLINE void DoDigitExceptionA( const CStringA& a1 ) {
    if( !a1.IsNumber() ) {
      throw std::runtime_error( "CString object is not number: " + a1 );
    }
  }

  INLINE void DoDigitExceptionW( const CStringW& a1 ) {
    if( !a1.IsNumber() ) {
      throw std::runtime_error( "CString object is not number: " + a1.WToA() );
    }
  }


#if 0
  // +
  INLINE int32 operator + ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + a2.ToInt32();
  }

  INLINE int64 operator + ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + a2.ToInt64();
  }

  INLINE uint32 operator + ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + (uint32)a2.ToInt32();
  }

  INLINE uint64 operator + ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + (uint64)a2.ToInt64();
  }

  INLINE real32 operator + ( const real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + a2.ToReal32();
  }

  INLINE real64 operator + ( const real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 + a2.ToReal64();
  }

  // -
  INLINE int32 operator - ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - a2.ToInt32();
  }

  INLINE int64 operator - ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - a2.ToInt64();
  }

  INLINE uint32 operator - ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - (uint32)a2.ToInt32();
  }

  INLINE uint64 operator - ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - (uint64)a2.ToInt64();
  }

  INLINE real32 operator - ( const real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - a2.ToReal32();
  }

  INLINE real64 operator - ( const real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 - a2.ToReal64();
  }

  // *
  INLINE int32 operator * ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * a2.ToInt32();
  }

  INLINE int64 operator * ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * a2.ToInt64();
  }

  INLINE uint32 operator * ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * (uint32)a2.ToInt32();
  }

  INLINE uint64 operator * ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * (uint64)a2.ToInt64();
  }

  INLINE real32 operator * ( const real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * a2.ToReal32();
  }

  INLINE real64 operator * ( const real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 * a2.ToReal64();
  }

  // /
  INLINE int32 operator / ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / a2.ToInt32();
  }

  INLINE int64 operator / ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / a2.ToInt64();
  }

  INLINE uint32 operator / ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / (uint32)a2.ToInt32();
  }

  INLINE uint64 operator / ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / (uint64)a2.ToInt64();
  }

  INLINE real32 operator / ( const real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / a2.ToReal32();
  }

  INLINE real64 operator / ( const real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 / a2.ToReal64();
  }

  // |
  INLINE int32 operator | ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 | a2.ToInt32();
  }

  INLINE int64 operator | ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 | a2.ToInt64();
  }

  INLINE uint32 operator | ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 | (uint32)a2.ToInt32();
  }

  INLINE uint64 operator | ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 | (uint64)a2.ToInt64();
  }

  // ^
  INLINE int32 operator ^ ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^ a2.ToInt32();
  }

  INLINE int64 operator ^ ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^ a2.ToInt64();
  }

  INLINE uint32 operator ^ ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^ (uint32)a2.ToInt32();
  }

  INLINE uint64 operator ^ ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^ (uint64)a2.ToInt64();
  }

  // %
  INLINE int32 operator % ( const int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 % a2.ToInt32();
  }

  INLINE int64 operator % ( const int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 % a2.ToInt64();
  }

  INLINE uint32 operator % ( const uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 % (uint32)a2.ToInt32();
  }

  INLINE uint64 operator % ( const uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 % (uint64)a2.ToInt64();
  }

  // +=
  INLINE int32& operator += ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += a2.ToInt32();
  }

  INLINE int64& operator += ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += a2.ToInt64();
  }

  INLINE uint32& operator += ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += (uint32)a2.ToInt32();
  }

  INLINE uint64& operator += ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += (uint64)a2.ToInt64();
  }

  INLINE real32& operator += ( real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += a2.ToReal32();
  }

  INLINE real64& operator += ( real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 += a2.ToReal64();
  }

  // -=
  INLINE int32& operator -= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= a2.ToInt32();
  }

  INLINE int64& operator -= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= a2.ToInt64();
  }

  INLINE uint32& operator -= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator -= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= (uint64)a2.ToInt64();
  }

  INLINE real32& operator -= ( real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= a2.ToReal32();
  }

  INLINE real64& operator -= ( real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 -= a2.ToReal64();
  }

  // *=
  INLINE int32& operator *= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= a2.ToInt32();
  }

  INLINE int64& operator *= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= a2.ToInt64();
  }

  INLINE uint32& operator *= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator *= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= (uint64)a2.ToInt64();
  }

  INLINE real32& operator *= ( real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= a2.ToReal32();
  }

  INLINE real64& operator *= ( real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 *= a2.ToReal64();
  }

  // /=
  INLINE int32& operator /= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= a2.ToInt32();
  }

  INLINE int64& operator /= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= a2.ToInt64();
  }

  INLINE uint32& operator /= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator /= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= (uint64)a2.ToInt64();
  }

  INLINE real32& operator /= ( real32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= a2.ToReal32();
  }

  INLINE real64& operator /= ( real64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 /= a2.ToReal64();
  }

  // |=
  INLINE int32& operator |= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 |= a2.ToInt32();
  }

  INLINE int64& operator |= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 |= a2.ToInt64();
  }

  INLINE uint32& operator |= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 |= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator |= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 |= (uint64)a2.ToInt64();
  }

  // ^
  INLINE int32& operator ^= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^= a2.ToInt32();
  }

  INLINE int64& operator ^= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^= a2.ToInt64();
  }

  INLINE uint32& operator ^= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator ^= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 ^= (uint64)a2.ToInt64();
  }

  // %
  INLINE int32& operator %= ( int32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 %= a2.ToInt32();
  }

  INLINE int64& operator %= ( int64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 %= a2.ToInt64();
  }

  INLINE uint32& operator %= ( uint32& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 %= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator %= ( uint64& a1, const CStringA& a2 ) {
    DoDigitExceptionA( a2 );
    return a1 %= (uint64)a2.ToInt64();
  }



  // +
  INLINE int32 operator + ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + a2.ToInt32();
  }

  INLINE int64 operator + ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + a2.ToInt64();
  }

  INLINE uint32 operator + ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + (uint32)a2.ToInt32();
  }

  INLINE uint64 operator + ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + (uint64)a2.ToInt64();
  }

  INLINE real32 operator + ( const real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + a2.ToReal32();
  }

  INLINE real64 operator + ( const real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 + a2.ToReal64();
  }

  // -
  INLINE int32 operator - ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - a2.ToInt32();
  }

  INLINE int64 operator - ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - a2.ToInt64();
  }

  INLINE uint32 operator - ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - (uint32)a2.ToInt32();
  }

  INLINE uint64 operator - ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - (uint64)a2.ToInt64();
  }

  INLINE real32 operator - ( const real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - a2.ToReal32();
  }

  INLINE real64 operator - ( const real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 - a2.ToReal64();
  }

  // *
  INLINE int32 operator * ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * a2.ToInt32();
  }

  INLINE int64 operator * ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * a2.ToInt64();
  }

  INLINE uint32 operator * ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * (uint32)a2.ToInt32();
  }

  INLINE uint64 operator * ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * (uint64)a2.ToInt64();
  }

  INLINE real32 operator * ( const real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * a2.ToReal32();
  }

  INLINE real64 operator * ( const real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 * a2.ToReal64();
  }

  // /
  INLINE int32 operator / ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / a2.ToInt32();
  }

  INLINE int64 operator / ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / a2.ToInt64();
  }

  INLINE uint32 operator / ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / (uint32)a2.ToInt32();
  }

  INLINE uint64 operator / ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / (uint64)a2.ToInt64();
  }

  INLINE real32 operator / ( const real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / a2.ToReal32();
  }

  INLINE real64 operator / ( const real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 / a2.ToReal64();
  }

  // |
  INLINE int32 operator | ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 | a2.ToInt32();
  }

  INLINE int64 operator | ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 | a2.ToInt64();
  }

  INLINE uint32 operator | ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 | (uint32)a2.ToInt32();
  }

  INLINE uint64 operator | ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 | (uint64)a2.ToInt64();
  }

  // ^
  INLINE int32 operator ^ ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^ a2.ToInt32();
  }

  INLINE int64 operator ^ ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^ a2.ToInt64();
  }

  INLINE uint32 operator ^ ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^ (uint32)a2.ToInt32();
  }

  INLINE uint64 operator ^ ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^ (uint64)a2.ToInt64();
  }

  // %
  INLINE int32 operator % ( const int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 % a2.ToInt32();
  }

  INLINE int64 operator % ( const int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 % a2.ToInt64();
  }

  INLINE uint32 operator % ( const uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 % (uint32)a2.ToInt32();
  }

  INLINE uint64 operator % ( const uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 % (uint64)a2.ToInt64();
  }

  // +=
  INLINE int32& operator += ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += a2.ToInt32();
  }

  INLINE int64& operator += ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += a2.ToInt64();
  }

  INLINE uint32& operator += ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += (uint32)a2.ToInt32();
  }

  INLINE uint64& operator += ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += (uint64)a2.ToInt64();
  }

  INLINE real32& operator += ( real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += a2.ToReal32();
  }

  INLINE real64& operator += ( real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 += a2.ToReal64();
  }

  // -=
  INLINE int32& operator -= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= a2.ToInt32();
  }

  INLINE int64& operator -= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= a2.ToInt64();
  }

  INLINE uint32& operator -= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator -= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= (uint64)a2.ToInt64();
  }

  INLINE real32& operator -= ( real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= a2.ToReal32();
  }

  INLINE real64& operator -= ( real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 -= a2.ToReal64();
  }

  // *=
  INLINE int32& operator *= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= a2.ToInt32();
  }

  INLINE int64& operator *= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= a2.ToInt64();
  }

  INLINE uint32& operator *= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator *= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= (uint64)a2.ToInt64();
  }

  INLINE real32& operator *= ( real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= a2.ToReal32();
  }

  INLINE real64& operator *= ( real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 *= a2.ToReal64();
  }

  // /=
  INLINE int32& operator /= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= a2.ToInt32();
  }

  INLINE int64& operator /= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= a2.ToInt64();
  }

  INLINE uint32& operator /= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator /= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= (uint64)a2.ToInt64();
  }

  INLINE real32& operator /= ( real32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= a2.ToReal32();
  }

  INLINE real64& operator /= ( real64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 /= a2.ToReal64();
  }

  // |=
  INLINE int32& operator |= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 |= a2.ToInt32();
  }

  INLINE int64& operator |= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 |= a2.ToInt64();
  }

  INLINE uint32& operator |= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 |= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator |= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 |= (uint64)a2.ToInt64();
  }

  // ^
  INLINE int32& operator ^= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^= a2.ToInt32();
  }

  INLINE int64& operator ^= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^= a2.ToInt64();
  }

  INLINE uint32& operator ^= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator ^= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 ^= (uint64)a2.ToInt64();
  }

  // %
  INLINE int32& operator %= ( int32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 %= a2.ToInt32();
  }

  INLINE int64& operator %= ( int64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 %= a2.ToInt64();
  }

  INLINE uint32& operator %= ( uint32& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 %= (uint32)a2.ToInt32();
  }

  INLINE uint64& operator %= ( uint64& a1, const CStringW& a2 ) {
    DoDigitExceptionW( a2 );
    return a1 %= (uint64)a2.ToInt64();
  }
#endif
}
#pragma endregion operators
