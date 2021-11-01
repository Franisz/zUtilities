// Supported with union (c) 2018-2021 Union team

#ifndef __ZALGEBRA_H__VER0__
#define __ZALGEBRA_H__VER0__

namespace Gothic_I_Classic {
  const double PI_LONG     = 3.14159265359;
  const double RAD_LONG    = PI_LONG / 180.0f;
  const double DEGREE_LONG = 180.0 / PI_LONG;

  const float PI     = PI_LONG;
  const float PI2    = PI * 2.0f;
  const float RAD    = RAD_LONG;
  const float DEGREE = DEGREE_LONG;
  const float RAD45  = 45.0f  / DEGREE;
  const float RAD90  = 90.0f  / DEGREE;
  const float RAD135 = 135.0f / DEGREE;
  const float RAD180 = 180.0f / DEGREE;
  const float RAD225 = 225.0f / DEGREE;
  const float RAD270 = 270.0f / DEGREE;
  const float RAD315 = 315.0f / DEGREE;
  const float RAD360 = 360.0f / DEGREE;

  const float AVERAGE_SMOOTH_FRAME_TIME = 0.025f;

  enum {
    VX,
    VY,
    VZ,
    VW
  };

  enum {
    VA,
    VB,
    VC,
    VD
  };

  enum {
    PA,
    PB,
    PC,
    PD
  };

  enum {
    RED,
    GREEN,
    BLUE
  };

  enum {
    KA,
    KD,
    KS,
    ES
  };

  class zVEC2 {
  public:
    float n[2];

    zVEC2()
    {
      n[0] = 0;
      n[1] = 0;
    }

    zVEC2( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
    }

    zVEC2( const float& a0, const float& a1 )
    {
      n[0] = a0;
      n[1] = a1;
    }

    zVEC2( const zVEC2& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1];
    }

    zVEC2& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= len : *this = 0.0f;
    }

    float Distance( const zVEC2& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    zVEC2& operator += ( const zVEC2& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      return *this;
    }

    zVEC2& operator -= ( const zVEC2& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      return *this;
    }

    zVEC2& operator *= ( const zVEC2& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      return *this;
    }

    zVEC2& operator /= ( const zVEC2& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      return *this;
    }

    zVEC2& operator = ( const zVEC2& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      return *this;
    }

    bool32 operator == ( const zVEC2& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1];
    }

    bool32 operator != ( const zVEC2& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1];
    }

    zVEC2 operator + ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) += a0;
    }

    zVEC2 operator - ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) -= a0;
    }

    zVEC2 operator * ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) *= a0;
    }

    zVEC2 operator / ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }

    zVEC2 operator - () const {
      zVEC2 v;
      v[0] = -n[0];
      v[1] = -n[1];
      return v;
    }

    float GetAngle()
    {
      CalcAngle( n[0], n[1] );
    }

    zVEC2& Rotate( const float& rad )
    {
      RotAngle( n[0], n[1], );
    }

    // user API
    #include "zVEC2.inl"
  };

  class zVEC3 {
  public:
    float n[3];

    zVEC3()
    {
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
    }

    zVEC3( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
      n[2] = a0;
    }

    zVEC3( const float& a0, const float& a1, const float& a2 )
    {
      n[0] = a0;
      n[1] = a1;
      n[2] = a2;
    }

    zVEC3( const zVEC3& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
    }

    float LengthApprox() const
    {
      float ix = n[VX];
      float iy = n[VY];
      float iz = n[VZ];

      if( ix < 0.0f ) ix *= -1.0;
      if( iy < 0.0f ) iy *= -1.0;
      if( iz < 0.0f ) iz *= -1.0;

      if( ix < iy ) {
        float it = ix;
        ix = iy;
        iy = it;
      }

      if( ix < iz ) {
        float it = ix;
        ix = iz;
        iz = it;
      }

      float t = iy + iz;
      return ix - (ix * (1.0f / 16.0f)) + (t * (1.0f / 4.0f)) + (t * (1.0f / 8.0f));
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
    }

    zVEC3& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= len : *this = 0.0f;
    }

    float Distance( const zVEC3& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    float Dot( const zVEC3& a0 ) const
    {
      return n[VX] * a0.n[VX] + n[VY] * a0.n[VY] + n[VZ] * a0.n[VZ];
    }

    zVEC3 Cross( const zVEC3& a0 ) const
    {
      return zVEC3(
        n[VY] * a0.n[VZ] - n[VZ] * a0.n[VY],
        n[VZ] * a0.n[VX] - n[VX] * a0.n[VZ],
        n[VX] * a0.n[VY] - n[VY] * a0.n[VX] );
    }

    zVEC3& operator += ( const zVEC3& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      n[2] += a0[2];
      return *this;
    }

    zVEC3& operator -= ( const zVEC3& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      n[2] -= a0[2];
      return *this;
    }

    zVEC3& operator *= ( const zVEC3& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      n[2] *= a0[2];
      return *this;
    }

    zVEC3& operator /= ( const zVEC3& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      n[2] /= a0[2];
      return *this;
    }

    zVEC3& operator =  ( const zVEC3& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      return *this;
    }

    bool32 operator == ( const zVEC3& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1] && n[2] == a0[2];
    }

    bool32 operator != ( const zVEC3& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1] || n[2] != a0[2];
    }

    zVEC3 operator +  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) += a0;
    }

    zVEC3  operator -  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) -= a0;
    }

    zVEC3  operator *  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) *= a0;
    }

    zVEC3  operator /  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }

    zVEC3 operator - () const {
      zVEC3 v;
      v[0] = -n[0];
      v[1] = -n[1];
      v[2] = -n[2];
      return v;
    }

    operator zVEC2 () {
      return zVEC2(
        n[VX] / n[VZ],
        n[VY] / n[VZ]
      );
    }

	  float GetAngleXZ() {
      CalcAngle(n[0], n[2]);
    }

    float GetAngleXY() {
      CalcAngle(n[0], n[1]);
    }

    float GetAngleYZ() {
      CalcAngle(n[1], n[2]);
    }

    zVEC3& RotateXZ( const float& rad ) {
      RotAngle(n[0], n[2], XZ);
    }

    zVEC3& RotateXY( const float& rad ) {
      RotAngle(n[0], n[1], XY);
    }

    zVEC3& RotateYZ( const float& rad ) {
      RotAngle(n[1], n[2], YZ);
    }

    // user API
    #include "zVEC3.inl"
  };

  class zVEC4 {
  public:
    float n[4];

    zVEC4()
    {
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
      n[3] = 0;
    }

    zVEC4( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
      n[2] = a0;
      n[3] = a0;
    }

    zVEC4( const float& a0, const float& a1, const float& a2, const float& a3 )
    {
      n[0] = a0;
      n[1] = a1;
      n[2] = a2;
      n[3] = a3;
    }

    zVEC4( const zVEC4& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      n[3] = a0[3];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1] + n[2] * n[2] + n[3] * n[3];
    }

    zVEC4& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= len : *this = 0.0f;
    }

    float Distance( const zVEC4& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    float Dot( const zVEC4& a0 ) const
    {
      return n[VX] * a0.n[VX] + n[VY] * a0.n[VY] + n[VZ] * a0.n[VZ] + n[VW] * a0.n[VW];
    }

    zVEC3 Cross( const zVEC4& a0 ) const
    {
      return zVEC3(
        n[VY] * a0.n[VZ] - n[VZ] * a0.n[VY],
        n[VZ] * a0.n[VX] - n[VX] * a0.n[VZ],
        n[VX] * a0.n[VY] - n[VY] * a0.n[VX] );
    }

    zVEC4& operator += ( const zVEC4& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      n[2] += a0[2];
      n[3] += a0[3];
      return *this;
    }

    zVEC4& operator -= ( const zVEC4& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      n[2] -= a0[2];
      n[3] -= a0[3];
      return *this;
    }

    zVEC4& operator *= ( const zVEC4& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      n[2] *= a0[2];
      n[3] *= a0[3];
      return *this;
    }

    zVEC4& operator /= ( const zVEC4& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      n[2] /= a0[2];
      n[3] /= a0[3];
      return *this;
    }

    zVEC4& operator =  ( const zVEC4& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      n[3] = a0[3];
      return *this;
    }

    bool32 operator == ( const zVEC4& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1] && n[2] == a0[2] && n[3] == a0[3];
    }

    bool32 operator != ( const zVEC4& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1] || n[2] != a0[2] || n[3] != a0[3];
    }

    zVEC4 operator + ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) += a0;
    }

    zVEC4 operator - ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) -= a0;
    }

    zVEC4 operator * ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) *= a0;
    }

    zVEC4 operator / ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }

    zVEC4 operator - () const {
      zVEC4 v;
      v[0] = -n[0];
      v[1] = -n[1];
      v[2] = -n[2];
      v[3] = -n[3];
      return v;
    }

    // user API
    #include "zVEC4.inl"
  };

  class zMAT3 {
  public:
    zVEC3 v[3];

    zMAT3()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
    }

    zMAT3( const zVEC3& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
    }

    zMAT3( const zVEC3& a0, const zVEC3& a1, const zVEC3& a2 )
    {
      v[0] = a0;
      v[1] = a1;
      v[2] = a2;
    }

    zMAT3( const float& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
    }

    zMAT3( const zMAT3& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
    }

    static const zMAT3& GetIdentity()
    {
      return s_identity;
    }

    void MakeIdentity()
    {
      *this = GetIdentity();
    }

    void MakeZero()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
    }

    zMAT3 Transpose() const            zCall( 0x00503FC0 );
    zMAT3 Inverse( float* det = Null ) zCall( 0x00504050 );

    zVEC2 GetUpVector() const
    {
      return zVEC2( v[0][1], v[1][1] );
    }

    zVEC2 GetRightVector() const
    {
      return zVEC2( v[0][0], v[1][0] );
    }
    
    void SetUpVector( const zVEC2& a0 )
    {
      v[0][2] = a0.n[VX];
      v[1][2] = a0.n[VY];
    }

    void SetRightVector( const zVEC2& a0 )
    {
      v[0][1] = a0.n[VX];
      v[1][1] = a0.n[VY];
    }

    zVEC2 GetTranslation() const
    {
      return zVEC2( v[0][2], v[1][2] );
    };

    zMAT3& SetTranslation( zVEC2 const& a0 )
    {
      v[0][2] = a0[VX];
      v[1][2] = a0[VY];
      return *this;
    };

    zMAT3& Translate( zVEC2 const& a0 )
    {
      v[0][2] += a0[VX];
      v[1][2] += a0[VY];
      return *this;
    }

    zVEC2 ExtractScaling() const {
      return zVEC2(
        sqrt( v[0][0] * v[0][0] + v[1][0] * v[1][0] ),
        sqrt( v[0][1] * v[0][1] + v[1][1] * v[1][1] )
      );
    }

    friend inline zMAT3 Alg_Scaling2D( zVEC2& );
    friend inline zMAT3 Alg_Rotation2D( zVEC2&, float );
    zMAT3 ExtractRotation() const {
      float a = v[1][0] * v[1][0];
      float b = v[1][1] * v[1][1];
      float angle = atan( SafeDiv( a, b ) );
      return Alg_Rotation2D( zVEC2( 0.0f ), angle * DEGREE );
    }

    float ExtractAngle() const {
      float a     = v[1][0] * v[1][0];
      float b     = v[1][1] * v[1][1];
      float angle = atan( SafeDiv( a, b ) );

      bool cs = v[1][1] < 0.0f;
      bool sn = v[1][0] < 0.0f;

      if( cs && sn ) return RAD180 + angle;
      if( sn )       return RAD360 - angle;
      if( cs )       return RAD180 - angle;
                     return          angle;
    }

    zMAT3& operator=( zMAT3 const& )  zCall( 0x00503DF0 );
    zMAT3& operator+=( zMAT3 const& ) zCall( 0x00503E40 );
    zMAT3& operator-=( zMAT3 const& ) zCall( 0x00503EA0 );
    zMAT3& operator*=( float )        zCall( 0x00503F00 );
    zMAT3& operator/=( float )        zCall( 0x00503F60 );

#define ROWCOL( i, j )    \
  v[i][0] * other[0][j] + \
  v[i][1] * other[1][j] + \
  v[i][2] * other[2][j]

    zMAT3& operator*=( zMAT3 const& other )
    {
      v[0] = zVEC3( ROWCOL( 0, 0 ), ROWCOL( 0, 1 ), ROWCOL( 0, 2 ) );
      v[1] = zVEC3( ROWCOL( 1, 0 ), ROWCOL( 1, 1 ), ROWCOL( 1, 2 ) );
      v[2] = zVEC3( ROWCOL( 2, 0 ), ROWCOL( 2, 1 ), ROWCOL( 2, 2 ) );
      return *this;
    }
#undef ROWCOL

    bool32 operator == ( const zMAT3& a0 ) const
    {
      return v[0] == a0[0] && v[1] == a0[1] && v[2] == a0[2] && v[3] == a0[3];
    }

    bool32 operator != ( const zMAT3& a0 ) const
    {
      return v[0] != a0[0] || v[1] != a0[1] || v[2] != a0[2] || v[3] != a0[3];
    }

    zMAT3  operator + ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) += a0;
    }

    zMAT3  operator - ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) -= a0;
    }

    zMAT3  operator * ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) *= a0;
    }

    zMAT3& Test ( const zMAT3& a0 ) {
      v[0] *= a0.v[0];
      v[1] *= a0.v[1];
      v[2] *= a0.v[2];
      return *this;
    }

    zVEC3& operator [] ( const uint32& index )
    {
      return v[index];
    }

    const zVEC3& operator [] ( const uint32& index ) const
    {
      return v[index];
    }

    zVEC2 operator * ( const zVEC2& a0 ) {
      return zVEC3(
        v[0].n[VX] * a0.n[VX] + v[0].n[VY] * a0.n[VY] + v[0].n[VZ],
        v[1].n[VX] * a0.n[VX] + v[1].n[VY] * a0.n[VY] + v[1].n[VZ],
        v[2].n[VX] * a0.n[VX] + v[2].n[VY] * a0.n[VY] + v[2].n[VZ]
        );
    }

    static zMAT3& s_identity;

    // user API
    #include "zMAT3.inl"
  };

  class zMAT4 {
  public:
    zVEC4 v[4];

    zMAT4()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
      v[3] = 0.0f;
    }

    zMAT4( const zVEC4& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
      v[3] = a0;
    }

    zMAT4( const zVEC4& a0, const zVEC4& a1, const zVEC4& a2, const zVEC4& a3 )
    {
      v[0] = a0;
      v[1] = a1;
      v[2] = a2;
      v[3] = a3;
    }

    zMAT4( const float& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
      v[3] = a0;
    }

    zMAT4( const zMAT4& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
      v[3] = a0[3];
    }

    zMAT4 Inverse()                   zCall( 0x005058F0 );
    void MakeOrthonormal()            zCall( 0x00507640 );
    zMAT3 ExtractRotation() const     zCall( 0x00507500 );
    zVEC3 ExtractScaling() const      zCall( 0x00507480 );
    void PostRotateX( float a0 )      zCall( 0x00507A40 );
    void PostRotateY( float a0 )      zCall( 0x00507A90 );
    void PostRotateZ( float a0 )      zCall( 0x00507AE0 );
    void PreScale( const zVEC3& a0 )  zCall( 0x00507B50 );
    void PostScale( const zVEC3& a0 ) zCall( 0x00507B30 );
    zVEC3 GetEulerAngles() const      zCall( 0x005066A0 );
    void SetByEulerAngles( zVEC3 )    zCall( 0x005066E0 );
    zMAT4 TransposeLinTrafo() const   zCall( 0x00505570 );
    zMAT4 InverseLinTrafo() const     zCall( 0x00505730 );

    static const zMAT4& GetIdentity()
    {
      return s_identity;
    }

    void MakeIdentity()
    {
      *this = GetIdentity();
    }

    zMAT4 Transpose() const
    {
      return zMAT4(
        zVEC4( v[0][0], v[1][0], v[2][0], v[3][0] ),
        zVEC4( v[0][1], v[1][1], v[2][1], v[3][1] ),
        zVEC4( v[0][2], v[1][2], v[2][2], v[3][2] ),
        zVEC4( v[0][3], v[1][3], v[2][3], v[3][3] ) );
    }

    zVEC3 GetUpVector() const
    {
      return zVEC3( v[0][1], v[1][1], v[2][1] );
    }

    zVEC3 GetRightVector() const
    {
      return zVEC3( v[0][0], v[1][0], v[2][0] );
    }

    zVEC3 GetAtVector() const
    {
      return zVEC3( v[0][2], v[1][2], v[2][2] );
    }

    void SetUpVector( const zVEC3& a0 )
    {
      v[0][2] = a0.n[VX];
      v[1][2] = a0.n[VY];
      v[2][2] = a0.n[VZ];
    }

    void SetRightVector( const zVEC3& a0 )
    {
      v[0][1] = a0.n[VX];
      v[1][1] = a0.n[VY];
      v[2][1] = a0.n[VZ];
    }

    void SetAtVector( const zVEC3& a0 )
    {
      v[0][0] = a0.n[VX];
      v[1][0] = a0.n[VY];
      v[2][0] = a0.n[VZ];
    }

    zMAT4& Translate( const zVEC3& a0 )
    {
      v[0][3] += a0.n[VX];
      v[1][3] += a0.n[VY];
      v[2][3] += a0.n[VZ];
      return *this;
    }

    zMAT4& SetTranslation( const zVEC3& a0 )
    {
      v[0][3] = a0.n[VX];
      v[1][3] = a0.n[VY];
      v[2][3] = a0.n[VZ];
      return *this;
    }

    zVEC3 GetTranslation() const
    {
      return zVEC3( v[0][3], v[1][3], v[2][3] );
    }

    void ResetRotation()
    {
      SetRightVector( zVEC3( 1.0f, 0.0f, 0.0f ) );
      SetUpVector   ( zVEC3( 0.0f, 1.0f, 0.0f ) );
      SetAtVector   ( zVEC3( 0.0f, 0.0f, 1.0f ) );
    }

    zVEC3 Rotate( const zVEC3 & a0 )
    {
      return zVEC3(
        v[0].n[0] * a0.n[VX] + v[0].n[1] * a0.n[VY] + v[0].n[2] * a0.n[VZ],
        v[1].n[0] * a0.n[VX] + v[1].n[1] * a0.n[VY] + v[1].n[2] * a0.n[VZ],
        v[2].n[0] * a0.n[VX] + v[2].n[1] * a0.n[VY] + v[2].n[2] * a0.n[VZ]
      );
    }

    zMAT4& operator += ( const zMAT4& a0 )
    {
      v[0] += a0[0];
      v[1] += a0[1];
      v[2] += a0[2];
      v[3] += a0[3];
      return *this;
    }

    zMAT4& operator -= ( const zMAT4& a0 )
    {
      v[0] -= a0[0];
      v[1] -= a0[1];
      v[2] -= a0[2];
      v[3] -= a0[3];
      return *this;
    }

    zMAT4& operator *= ( const float& a0 )
    {
      v[0] *= a0;
      v[1] *= a0;
      v[2] *= a0;
      v[3] *= a0;
      return *this;
    }

    zMAT4& operator /= ( const float& a0 )
    {
      v[0] / a0;
      v[1] /= a0;
      v[2] /= a0;
      v[3] /= a0;
      return *this;
    }

    zMAT4& operator =  ( const zMAT4& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
      v[3] = a0[3];
      return *this;
    }

	#define ROWCOL( i, j )       \
      self[i][0] * other[0][j] + \
      self[i][1] * other[1][j] + \
      self[i][2] * other[2][j] + \
      self[i][3] * other[3][j]

    zMAT4 operator * ( const zMAT4& other ) {
      zMAT4& self = *this;
      return zMAT4(
        zVEC4( ROWCOL( 0, 0 ), ROWCOL( 0, 1 ), ROWCOL( 0, 2 ), ROWCOL( 0, 3 ) ),
        zVEC4( ROWCOL( 1, 0 ), ROWCOL( 1, 1 ), ROWCOL( 1, 2 ), ROWCOL( 1, 3 ) ),
        zVEC4( ROWCOL( 2, 0 ), ROWCOL( 2, 1 ), ROWCOL( 2, 2 ), ROWCOL( 2, 3 ) ),
        zVEC4( ROWCOL( 3, 0 ), ROWCOL( 3, 1 ), ROWCOL( 3, 2 ), ROWCOL( 3, 3 ) )
      );
    }

    bool32 operator == ( const zMAT4& a0 ) const
    {
      return v[0] == a0[0] && v[1] == a0[1] && v[2] == a0[2] && v[3] == a0[3];
    }

    bool32 operator != ( const zMAT4& a0 ) const
    {
      return v[0] != a0[0] || v[1] != a0[1] || v[2] != a0[2] || v[3] != a0[3];
    }

    zMAT4 operator + ( const zMAT4& a0 ) const
    {
      return zMAT4( *this ) += a0;
    }

    zMAT4 operator - ( const zMAT4& a0 ) const
    {
      return zMAT4( *this ) -= a0;
    }

    zMAT4 operator * ( const float& a0 ) const
    {
      return zMAT4( *this ) *= a0;
    }

    zVEC3 operator * ( const zVEC3& a0 ) const
    {
      return zVEC3(
        v[0][0] * a0[VX] + v[0][1] * a0[VY] + v[0][2] * a0[VZ] + v[0][3],
        v[1][0] * a0[VX] + v[1][1] * a0[VY] + v[1][2] * a0[VZ] + v[1][3],
        v[2][0] * a0[VX] + v[2][1] * a0[VY] + v[2][2] * a0[VZ] + v[2][3]
      );
    }

    zVEC4 operator * ( const zVEC4& a0 ) const
    {
      return zVEC4(
        v[0][0] * a0[VX] + v[0][1] * a0[VY] + v[0][2] * a0[VZ] + v[0][3] * a0[VW],
        v[1][0] * a0[VX] + v[1][1] * a0[VY] + v[1][2] * a0[VZ] + v[1][3] * a0[VW],
        v[2][0] * a0[VX] + v[2][1] * a0[VY] + v[2][2] * a0[VZ] + v[2][3] * a0[VW],
        v[3][0] * a0[VX] + v[3][1] * a0[VY] + v[3][2] * a0[VZ] + v[3][3] * a0[VW]
      );
    }

    zMAT4 operator / ( const float& a0 ) const
    {
      return zMAT4( *this ) /= a0;
    }

    zVEC4& operator [] ( const uint32& index )
    {
      return v[index];
    }

    const zVEC4& operator [] ( const uint32& index ) const
    {
      return v[index];
    }

    static zMAT4& s_identity;

    // user API
    #include "zMAT4.inl"
  };

  class zCQuat {
  public:
    float q[4];

    zCQuat()
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = 1.0f;
    }

    zCQuat( const float& a0 )
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = a0;
    }

    zCQuat( const float& a0, const float& a1, const float& a2, const float& a3 )
    {
      q[VX] = a0;
      q[VY] = a1;
      q[VZ] = a2;
      q[VW] = a3;
    }

    void QuatToMatrix3( zMAT3& a0 ) const                                                          zCall( 0x00508770 );
    void Matrix3ToQuat( zMAT3& a0 )                                                                zCall( 0x00508B30 );
    void QuatToMatrix4( zMAT4& a0 ) const                                                          zCall( 0x00508670 );
    void Matrix4ToQuat( zMAT4& a0 )                                                                zCall( 0x00508870 );
    void QuatToEuler( zVEC3& a0) const                                                             zCall( 0x00508DD0 );
    void EulerToQuat( const zVEC3& a0 )                                                            zCall( 0x00508EF0 );
    void QuatToAxisAngle( zVEC3& a0, float& a1 ) const                                             zCall( 0x00508FA0 );
    void Slerp( float a0, const zCQuat& a1, const zCQuat& a2 )                                     zCall( 0x00518D10 );
    void Lerp( float a0, const zCQuat& a1, const zCQuat& a2 )                                      zCall( 0x00518EF0 );
    void Squad( float a0, const zCQuat& a1, const zCQuat& a2, const zCQuat& a3, const zCQuat& a4 ) zCall( 0x00509300 );

    void AxisAngleToQuat( const zVEC3& a0, const float a1 )
    {
      float half = 0.5f * a1;
      float sinh = sin( half );
      q[VW] = cos( half );
      q[VX] = a0[VX] * sinh; q[VY] = a0[VY] * sinh; q[VZ] = a0[VZ] * sinh;
    }

    void Normalize()
    {
      float len = 1.0f / Length_Sqr();
      q[VX] *= len;
      q[VY] *= len;
      q[VZ] *= len;
      q[VW] *= len;
    }

    zCQuat Inverse() const
    {
      return zCQuat( -q[VX], -q[VY], -q[VZ], q[VW] );
    }

    zCQuat InverseNormal() const
    {
      float len = 1.0f / Length_Sqr();
      return zCQuat(
        q[VX] * -len,
        q[VY] * -len,
        q[VZ] * -len,
        q[VW] *  len
      );
    }

    float Dot( const zCQuat& a0 ) const
    {
      return q[VX] * a0.q[VX] + q[VY] * a0.q[VY] + q[VZ] * a0.q[VZ] + q[VW] * a0.q[VW];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return q[VX] * q[VX] + q[VY] * q[VY] + q[VZ] * q[VZ] + q[VW] * q[VW];
    }

    void Identity()
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = 1.0f;
    }

    zCQuat& operator += ( const zCQuat& a0 )
    {
      q[VX] += a0[VX];
      q[VY] += a0[VY];
      q[VZ] += a0[VZ];
      q[VW] += a0[VW];
      return *this;
    }

    zCQuat& operator -= ( const zCQuat& a0 )
    {
      q[VX] -= a0[VX];
      q[VY] -= a0[VY];
      q[VZ] -= a0[VZ];
      q[VW] -= a0[VW];
      return *this;
    }

    zCQuat operator * ( const zCQuat& a0 )
    {
      return zCQuat( 
        q[VW] * a0[VX] + q[VX] * a0[VW] + q[VY] * a0[VZ] - q[VZ] * a0[VY],
        q[VW] * a0[VY] + q[VY] * a0[VW] + q[VZ] * a0[VX] - q[VX] * a0[VZ],
        q[VW] * a0[VZ] + q[VZ] * a0[VW] + q[VX] * a0[VY] - q[VY] * a0[VX],
        q[VW] * a0[VW] - q[VX] * a0[VX] - q[VY] * a0[VY] - q[VZ] * a0[VZ] 
      );
    }

    zCQuat& operator = ( const zCQuat& a0 )
    {
      q[VX] = a0[VX];
      q[VY] = a0[VY];
      q[VZ] = a0[VZ];
      q[VW] = a0[VW];
      return *this;
    }

    bool32 operator == ( const zCQuat& a0 ) const
    {
      return q[VX] == a0[VX] && q[VY] == a0[VY] && q[VZ] == a0[VZ] && q[VW] == a0[VW];
    }

    bool32 operator != ( const zCQuat& a0 ) const
    {
      return q[VX] != a0[VX] || q[VY] != a0[VY] || q[VZ] != a0[VZ] || q[VW] != a0[VW];
    }

    zCQuat operator + ( const zCQuat& a0 ) const
    {
      return zCQuat( *this ) += a0;
    }

    zCQuat operator - ( const zCQuat& a0 ) const
    {
      return zCQuat( *this ) -= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return q[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return q[index];
    }

    // user API
    #include "zCQuat.inl"
  };

  inline float Alg_SqrtInvApprox( float );
  struct zComplex {
    float real;
    float img;
    float mag;
    float phase;

    zComplex() {
      real = 0.0f;
      img = 0.0f;
      EmptyCache();
    };

    zComplex( const float r, const float i ) {
      real = r;
      img = i;
      EmptyCache();
    };

    zComplex( const zComplex& c ) {
      real = c.real;
      img = c.img;
      mag = c.mag;
      phase = c.phase;
    };

    zComplex& operator=( const zComplex& c ) {
      real = c.real;
      img = c.img;
      mag = c.mag;
      phase = c.phase;
      return *this;
    };

    zComplex operator+( const zComplex& c ) {
      return zComplex(
        real + c.real,
        img + c.img
      );
    };

    zComplex operator*( const zComplex& c ) {
      return zComplex(
        real * c.real - img * c.img,
        real * c.img + img * c.real
      );
    };

    void Set( const float r, const float i ) {
      real = r;
      img = i;
      EmptyCache();
    };

    void Get( float& r, float& i ) {
      r = real;
      i = img;
    }

    void EmptyCache() {
      mag = 0.0f;
      phase = 0.0f;
    }

    float Mag() {
      if( mag == 0 ) {
        return mag ? mag * Alg_SqrtInvApprox( mag ) : 0;
      }

      return mag;
    }

    float Phase() {
      if( phase == 0 ) {
        float f1 = _PI / 4.0f;
        float f2 = 3.0f * f1;

        float ay = abs( img ) + 1e-10;
        float angle;

        if( real >= 0 ) angle = f1 - f1 * ((real - ay) / (real + ay));
        else            angle = f2 - f1 * ((real + ay) / (ay - real));

        phase = img < 0 ? -angle : +angle;
      }

      return phase;
    }

    zComplex operator*( const float& c ) {
      return zComplex( real * c, img * c );
    };

    zComplex conj() {
      return zComplex( real, -img );
    }

    zComplex operator-( const zComplex& c ) const {
      return zComplex( real - c.real, img - c.img );
    }

    // user API
    #include "zComplex.inl"
  };

  inline void GetProjection( int& x, int& y, zVEC3 v );
  inline int PixelToVirtualX( int x );
  inline int PixelToVirtualY( int y );
  inline int VirtualToPixelX( int x );
  inline int VirtualToPixelY( int y );
  extern oCGame*& ogame;

  class zCLine2D {
    zVEC2 posA;
    zVEC2 posB;
  public:

    zCLine2D()
    {

    }

    zCLine2D( zVEC2 a, zVEC2 b )
    {
      posA = a;
      posB = b;
    }

    zCLine2D( zVEC3 a, zVEC3 b )
    {
      if( !ogame )
        return;

      int ax, ay, bx, by;
      GetProjection( ax, ay, a );
      GetProjection( bx, by, b );

      posA = zVEC2( ax, ay );
      posB = zVEC2( bx, by );
    }

    zVEC2& operator[] ( uint i )
    {
      return i == 0 ? posA : posB;
    }

    const zVEC2& operator[] ( uint i ) const
    {
      return i == 0 ? posA : posB;
    }

    zCLine2D Dot( float mult ) const
    {
      zVEC2 vector = GetVector() * mult;
      return zCLine2D( posA, posA + vector );
    }

    bool TraceRay( const zCLine2D& line, zVEC2* intersec = Null ) const
    {
      zCLine2D lineSource = line;
      zCLine2D line1      = *this;
      zCLine2D line2      = line;

      float sceneAngle = line1.GetAngle();
      line1.Rotate( sceneAngle, line1[VA] );
      line2.Rotate( sceneAngle, line1[VA] );

      float vx_mid = line1[VA][VX];
      if( line2[VA][VX] > line2[VB][VX] ) {
        lineSource.InverseLinear();
        line2.InverseLinear();
      }

      float vx_min = line2[VA][VX];
      float vx_max = line2[VB][VX];

      if( vx_mid >= vx_min && vx_mid <= vx_max ) {
        float vx_length     = vx_max - vx_min;
        float vx_distance   = vx_mid - vx_min;
        float vx_multiplier = 1.0f / vx_length * vx_distance;

        zCLine2D line3 = line2.Dot( vx_multiplier );

        float vy_mid = line3[VB][VY];
        float vy_min = min( line1[VA][VY], line1[VB][VY] );
        float vy_max = max( line1[VA][VY], line1[VB][VY] );

        if( vy_mid >= vy_min && vy_mid <= vy_max ) {
          if( intersec )
            *intersec = lineSource[VA] + lineSource.GetVector() * vx_multiplier;

          return true;
        }
      }

      return false;
    }

    bool TraceRay( const zVEC2& dot, float depth, zVEC2* intersec = Null ) const
    {
      zVEC2 vector = GetVector().Rotate( RAD90 ).Normalize() * zVEC2( PixelToVirtualX( depth ), PixelToVirtualY( depth ) );
      zCLine2D line( dot - vector, dot + vector );
      return TraceRay( line, intersec );
    }

    float GetAngle() const
    {
      zVEC2 vself = posB - posA;
      return vself.GetAngle();
    }

    zCLine2D& Rotate( float angle )
    {
      return Rotate( angle, posA );
    }

    zCLine2D& Rotate( float angle, const zVEC2& pivot )
    {
      zVEC2 v1 = posA - pivot;
      zVEC2 v2 = posB - pivot;

      posA = pivot + v1.Rotate( angle );
      posB = pivot + v2.Rotate( angle );
      return *this;
    }

    zVEC2 GetVector() const
    {
      return posB - posA;
    }

    zCLine2D& InverseLinear() {
      zVEC2 temp = posA;
      posA       = posB;
      posB       = temp;
      return *this;
    }

    float GetLength() const
    {
      return GetVector().Length();
    }

    // user API
    #include "zCLine2D.inl"
  };

  inline zVEC2 Alg_Min( zVEC2 const &, zVEC2 const & )               zCall( 0x005033B0 );
  inline zVEC3 Alg_Min( zVEC3 const &, zVEC3 const & )               zCall( 0x00503680 );
  inline zVEC4 Alg_Min( zVEC4 const &, zVEC4 const & )               zCall( 0x00503B20 );
  inline zVEC2 Alg_Max( zVEC2 const &, zVEC2 const & )               zCall( 0x00503400 );
  inline zVEC3 Alg_Max( zVEC3 const &, zVEC3 const & )               zCall( 0x005036F0 );
  inline zVEC4 Alg_Max( zVEC4 const &, zVEC4 const & )               zCall( 0x00503BA0 );
  inline zVEC2 Alg_Prod( zVEC2 const &, zVEC2 const & )              zCall( 0x00503450 );
  inline zVEC3 Alg_Prod( zVEC3 const &, zVEC3 const & )              zCall( 0x00503760 );
  inline zVEC4 Alg_Prod( zVEC4 const &, zVEC4 const & )              zCall( 0x00503C20 );
  inline void Alg_Swap( zVEC2 &, zVEC2 & )                           zCall( 0x00503370 );
  inline void Alg_Swap( zVEC3 &, zVEC3 & )                           zCall( 0x00503630 );
  inline void Alg_Swap( zVEC4 &, zVEC4 & )                           zCall( 0x00503AC0 );
  inline void Alg_Swap( zMAT3 &, zMAT3 & )                           zCall( 0x00504AA0 );
  inline void Alg_Swap( zMAT4 &, zMAT4 & )                           zCall( 0x00507350 );
  inline zMAT3 Alg_Identity2D()                                      zCall( 0x00507BB0 );
  inline zMAT3 Alg_Translation2D( zVEC2 & )                          zCall( 0x00507C50 );
  inline zMAT3 Alg_Rotation2D( zVEC2 &, float )                      zCall( 0x00507CF0 );
  inline zMAT3 Alg_Scaling2D( zVEC2 & )                              zCall( 0x00507DC0 );
  inline zMAT4 Alg_Identity3D()                                      zCall( 0x00507E60 );
  inline zMAT4 Alg_Translation3D( zVEC3 const & )                    zCall( 0x00507F70 );
  inline zMAT4 Alg_Rotation3D( zVEC3 const &, float )                zCall( 0x00508080 );
  inline zMAT4 Alg_Rotation3DN( zVEC3 const &, float )               zCall( 0x00508100 );
  inline zMAT4 Alg_Rotation3DRad( zVEC3 const &, float )             zCall( 0x00508130 );
  inline zMAT4 Alg_Rotation3DNRad( zVEC3 const &, float )            zCall( 0x005081A0 );
  inline zMAT4 Alg_Scaling3D( zVEC3 const & )                        zCall( 0x00508320 );
  inline zMAT4 Alg_Perspective3D( float )                            zCall( 0x00508430 );
  inline void Alg_ClipAtZ0( zVEC3 &, zVEC3 & )                       zCall( 0x00508540 );
  inline float Alg_SqrtInvApprox( float )                            zCall( 0x005094C0 );
  inline float Alg_AngleUnitRad( zVEC3 const &, zVEC3 const & )      zCall( 0x0053C800 );
  inline void Alg_CalcAziElevUnit( zVEC3 const &, float &, float & ) zCall( 0x0074C070 );
  inline void Alg_CalcAziElev( zVEC3&, float&, float& )              zCall( 0x00470990 );

  inline zVEC3 Alg_RotationAxis( zVEC3 const& v1, zVEC3 const& v2 ) {
    return v1.Cross( v2 );
  }
} // namespace Gothic_I_Classic

#endif // __ZALGEBRA_H__VER0__