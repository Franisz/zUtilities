// Supported with union (c) 2018 Union team

#ifndef __OCOLLISION_OBJECT_MISC_CHAR_H__VER3__
#define __OCOLLISION_OBJECT_MISC_CHAR_H__VER3__

namespace Gothic_II_Addon {

  class oCCollObjectCharacter : public zCCollObjectCharacter {
  public:
    int comeNearerCounter;
    const zCVob* mustNotComeNearer;

    void oCCollObjectCharacter_OnInit()                    zCall( 0x0065D0F0 );
    oCCollObjectCharacter()                                zInit( oCCollObjectCharacter_OnInit() );
    static zCCollisionObject* _CreateNewInstance()         zCall( 0x0065D060 );
    static void S_RegisterCollisionTestFuncs()             zCall( 0x0065D260 );
    virtual zCCollisionObjectDef* GetCollObjClass() const  zCall( 0x0065D0E0 );
    virtual ~oCCollObjectCharacter()                       zCall( 0x0065D140 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const      zCall( 0x0065D220 );
    virtual int IsDead() const                             zCall( 0x0065D190 );
    virtual int DontLetHimComeNearer( zCVob const* ) const zCall( 0x0065D1F0 );
    virtual float TurnSpeed() const                        zCall( 0x0065D150 );
    virtual void PushAround( zVEC3 const& )                zCall( 0x0065D1C0 );

    // static properties
    static zCCollisionObjectDef& s_oCollObjClass;

    // user API
    #include "oCCollObjectCharacter.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER3__