// Supported with union (c) 2018-2021 Union team

#ifndef __OCOLLISION_OBJECT_MISC_CHAR_H__VER1__
#define __OCOLLISION_OBJECT_MISC_CHAR_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 144h
  class oCCollObjectCharacter : public zCCollObjectCharacter {
  public:
    int comeNearerCounter;          // sizeof 04h    offset 13Ch
    const zCVob* mustNotComeNearer; // sizeof 04h    offset 140h

    void oCCollObjectCharacter_OnInit()                    zCall( 0x0079D430 );
    oCCollObjectCharacter()                                zInit( oCCollObjectCharacter_OnInit() );
    static zCCollisionObject* _CreateNewInstance()         zCall( 0x0079D390 );
    static void S_RegisterCollisionTestFuncs()             zCall( 0x0079D590 );
    virtual zCCollisionObjectDef* GetCollObjClass() const  zCall( 0x0079D420 );
    virtual ~oCCollObjectCharacter()                       zCall( 0x0079D480 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const      zCall( 0x0079D560 );
    virtual int IsDead() const                             zCall( 0x0079D4D0 );
    virtual int DontLetHimComeNearer( zCVob const* ) const zCall( 0x0079D530 );
    virtual float TurnSpeed() const                        zCall( 0x0079D490 );
    virtual void PushAround( zVEC3 const& )                zCall( 0x0079D500 );

    // static properties
    static zCCollisionObjectDef& s_oCollObjClass;

    // user API
    #include "oCCollObjectCharacter.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER1__