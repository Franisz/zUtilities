// Supported with union (c) 2018-2021 Union team

#ifndef __OCOLLISION_OBJECT_MISC_CHAR_H__VER0__
#define __OCOLLISION_OBJECT_MISC_CHAR_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 144h
  class oCCollObjectCharacter : public zCCollObjectCharacter {
  public:
    int comeNearerCounter;          // sizeof 04h    offset 13Ch
    const zCVob* mustNotComeNearer; // sizeof 04h    offset 140h

    void oCCollObjectCharacter_OnInit()                    zCall( 0x0075AB30 );
    oCCollObjectCharacter()                                zInit( oCCollObjectCharacter_OnInit() );
    static zCCollisionObject* _CreateNewInstance()         zCall( 0x0075AA90 );
    static void S_RegisterCollisionTestFuncs()             zCall( 0x0075AC70 );
    virtual zCCollisionObjectDef* GetCollObjClass() const  zCall( 0x0075AB20 );
    virtual ~oCCollObjectCharacter()                       zCall( 0x0075AB80 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const      zCall( 0x0075AC40 );
    virtual int IsDead() const                             zCall( 0x0075ABD0 );
    virtual int DontLetHimComeNearer( zCVob const* ) const zCall( 0x0075AC10 );
    virtual float TurnSpeed() const                        zCall( 0x0075AB90 );
    virtual void PushAround( zVEC3 const& )                zCall( 0x0075AC00 );

    // static properties
    static zCCollisionObjectDef& s_oCollObjClass;

    // user API
    #include "oCCollObjectCharacter.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER0__