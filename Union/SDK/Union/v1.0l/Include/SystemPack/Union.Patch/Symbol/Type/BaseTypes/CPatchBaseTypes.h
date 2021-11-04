// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_BASETYPES_H__
#define __PATCH_BASETYPES_H__

namespace SystemPack {
  class ASTAPI CPatchInteger : public CPatchType {
    PATCH_CLASS_DECLARATION( CPatchInteger );

    int32* pValue;
  public:
    void SetValue( const int32& val );
    int32 GetValue();

    virtual void Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32 GetData();
    virtual uint32 GetSize();
    virtual CPatchType* operator =  ( CPatchType* symbol );
    virtual CPatchType* operator +  ( CPatchType* symbol );
    virtual CPatchType* operator -  ( CPatchType* symbol );
    virtual CPatchType* operator *  ( CPatchType* symbol );
    virtual CPatchType* operator /  ( CPatchType* symbol );
    virtual CPatchType* operator ^  ( CPatchType* symbol );
    virtual CPatchType* operator += ( CPatchType* symbol );
    virtual CPatchType* operator -= ( CPatchType* symbol );
    virtual CPatchType* operator *= ( CPatchType* symbol );
    virtual CPatchType* operator /= ( CPatchType* symbol );
    virtual CPatchType* operator ^= ( CPatchType* symbol );
    virtual CPatchType* operator !  ();
    virtual CPatchType* operator == ( CPatchType* symbol );
    virtual CPatchType* operator != ( CPatchType* symbol );
    virtual CPatchType* operator <  ( CPatchType* symbol );
    virtual CPatchType* operator <= ( CPatchType* symbol );
    virtual CPatchType* operator >  ( CPatchType* symbol );
    virtual CPatchType* operator >= ( CPatchType* symbol );
    virtual void ReadOption();
    virtual void WriteOption();
  };



  class ASTAPI CPatchFloat : public CPatchType {
    PATCH_CLASS_DECLARATION( CPatchFloat );

    real32* pValue;
  public:
    void SetValue( const real32& val );
    real32 GetValue();

    virtual void Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32 GetData();
    virtual uint32 GetSize();
    virtual CPatchType* operator =  ( CPatchType* symbol );
    virtual CPatchType* operator +  ( CPatchType* symbol );
    virtual CPatchType* operator -  ( CPatchType* symbol );
    virtual CPatchType* operator *  ( CPatchType* symbol );
    virtual CPatchType* operator /  ( CPatchType* symbol );
    virtual CPatchType* operator ^  ( CPatchType* symbol );
    virtual CPatchType* operator += ( CPatchType* symbol );
    virtual CPatchType* operator -= ( CPatchType* symbol );
    virtual CPatchType* operator *= ( CPatchType* symbol );
    virtual CPatchType* operator /= ( CPatchType* symbol );
    virtual CPatchType* operator ^= ( CPatchType* symbol );
    virtual CPatchType* operator !  ();
    virtual CPatchType* operator == ( CPatchType* symbol );
    virtual CPatchType* operator != ( CPatchType* symbol );
    virtual CPatchType* operator <  ( CPatchType* symbol );
    virtual CPatchType* operator <= ( CPatchType* symbol );
    virtual CPatchType* operator >  ( CPatchType* symbol );
    virtual CPatchType* operator >= ( CPatchType* symbol );
    virtual void ReadOption();
    virtual void WriteOption();
  };



  class ASTAPI CPatchBool : public CPatchType {
    PATCH_CLASS_DECLARATION( CPatchBool );

    bool32* pValue;
    bool32 bValAnsi;
  public:
    void SetValue( const bool32& val );
    bool32 GetValue();
    void SetAnsi( bool32 bl );
    bool32 GetAnsi();

    virtual void Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32 GetData();
    virtual uint32 GetSize();
    virtual CPatchType* operator =  ( CPatchType* symbol );
    virtual CPatchType* operator +  ( CPatchType* symbol );
    virtual CPatchType* operator -  ( CPatchType* symbol );
    virtual CPatchType* operator *  ( CPatchType* symbol );
    virtual CPatchType* operator /  ( CPatchType* symbol );
    virtual CPatchType* operator ^  ( CPatchType* symbol );
    virtual CPatchType* operator += ( CPatchType* symbol );
    virtual CPatchType* operator -= ( CPatchType* symbol );
    virtual CPatchType* operator *= ( CPatchType* symbol );
    virtual CPatchType* operator /= ( CPatchType* symbol );
    virtual CPatchType* operator ^= ( CPatchType* symbol );
    virtual CPatchType* operator !  ();
    virtual CPatchType* operator == ( CPatchType* symbol );
    virtual CPatchType* operator != ( CPatchType* symbol );
    virtual CPatchType* operator <  ( CPatchType* symbol );
    virtual CPatchType* operator <= ( CPatchType* symbol );
    virtual CPatchType* operator >  ( CPatchType* symbol );
    virtual CPatchType* operator >= ( CPatchType* symbol );
    virtual void ReadOption();
    virtual void WriteOption();
  };



  class ASTAPI CPatchHex : public CPatchType {
    PATCH_CLASS_DECLARATION( CPatchHex );

    void32 pValue;
    uint32 ulSize;
  public:
    void SetValue( void32 val, const uint32& size );
    void32 GetValue();
    void SetSize( const uint32& size );
    void32 GetCopy();
    void AutoSize();

    virtual void Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32 GetData();
    virtual uint32 GetSize();
    virtual CPatchType* operator =  ( CPatchType* symbol );
    virtual CPatchType* operator +  ( CPatchType* symbol );
    virtual CPatchType* operator -  ( CPatchType* symbol );
    virtual CPatchType* operator *  ( CPatchType* symbol );
    virtual CPatchType* operator /  ( CPatchType* symbol );
    virtual CPatchType* operator ^  ( CPatchType* symbol );
    virtual CPatchType* operator += ( CPatchType* symbol );
    virtual CPatchType* operator -= ( CPatchType* symbol );
    virtual CPatchType* operator *= ( CPatchType* symbol );
    virtual CPatchType* operator /= ( CPatchType* symbol );
    virtual CPatchType* operator ^= ( CPatchType* symbol );
    virtual CPatchType* operator !  ();
    virtual CPatchType* operator == ( CPatchType* symbol );
    virtual CPatchType* operator != ( CPatchType* symbol );
    virtual CPatchType* operator <  ( CPatchType* symbol );
    virtual CPatchType* operator <= ( CPatchType* symbol );
    virtual CPatchType* operator >  ( CPatchType* symbol );
    virtual CPatchType* operator >= ( CPatchType* symbol );
    virtual void ReadOption();
    virtual void WriteOption();
  };
}

#endif // __PATCH_BASETYPES_H__