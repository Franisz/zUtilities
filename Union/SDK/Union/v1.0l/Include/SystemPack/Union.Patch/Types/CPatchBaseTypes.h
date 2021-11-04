// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_PATCH_BASE_TYPES_H__
#define __SYSTEMPACK_PATCH_BASE_TYPES_H__

namespace SystemPack
{
  class ASTAPI CPatchInteger : public CPatchType
  {
    int32* pValue;

    PATCH_CLASS_DECLARATION( CPatchInteger );
  public:

    virtual void    Init( const uint32& address = 0 );
    virtual  CPatchType*  Execute();
    virtual void32    GetData();
    virtual uint32    GetSize();

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

    void  SetValue( const int32& val );
    int32 GetValue();
  };

  class ASTAPI CPatchFloat : public CPatchType
  {
    real32* pValue;

    PATCH_CLASS_DECLARATION( CPatchFloat );
  public:

    virtual void    Init( const uint32& address = 0 );
    virtual  CPatchType*  Execute();
    virtual void32    GetData();
    virtual uint32    GetSize();

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

    void   SetValue( const real32& val );
    real32 GetValue();
  };

  class ASTAPI CPatchBool : public CPatchType
  {
    bool32* pValue;
    bool32  bValAnsi;

    PATCH_CLASS_DECLARATION( CPatchBool );
  public:

    virtual void        Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32      GetData();
    virtual uint32      GetSize();

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

    void   SetValue( const bool32& val );
    bool32 GetValue();
    void   SetAnsi( bool32 bl );
    bool32 GetAnsi();
  };

  class ASTAPI CPatchHex : public CPatchType
  {
    void32 pValue;
    uint32 ulSize;

    PATCH_CLASS_DECLARATION( CPatchHex );
  public:

    virtual void        Init( const uint32& address = 0 );
    virtual CPatchType* Execute();
    virtual void32      GetData();
    virtual uint32      GetSize();

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

    void   SetValue( void32 val, const uint32& size );
    void32 GetValue();
    void   SetSize( const uint32& size );
    void32 GetCopy();
    void   AutoSize();
  };
} // namespace SystemPack

#endif // __SYSTEMPACK_PATCH_BASE_TYPES_H__