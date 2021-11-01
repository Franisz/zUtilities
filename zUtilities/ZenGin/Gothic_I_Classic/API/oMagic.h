// Supported with union (c) 2018-2021 Union team

#ifndef __OMAGIC_H__VER0__
#define __OMAGIC_H__VER0__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_I_Classic {

  // sizeof 7Ch
  class oCMag_Book {
  public:
    zCArray<oCSpell*> spells;    // sizeof 0Ch    offset 00h
    zCArray<oCItem*> spellitems; // sizeof 0Ch    offset 0Ch
    zCWorld* wld;                // sizeof 04h    offset 18h
    zCVob* owner;                // sizeof 04h    offset 1Ch
    zCModel* model;              // sizeof 04h    offset 20h
    int spellnr;                 // sizeof 04h    offset 24h
    float MAG_HEIGHT;            // sizeof 04h    offset 28h
    int active;                  // sizeof 04h    offset 2Ch
    int remove_all;              // sizeof 04h    offset 30h
    int in_movement;             // sizeof 04h    offset 34h
    int show_handsymbol;         // sizeof 04h    offset 38h
    float step;                  // sizeof 04h    offset 3Ch
    int action;                  // sizeof 04h    offset 40h
    int fullangle;               // sizeof 04h    offset 44h
    int open;                    // sizeof 04h    offset 48h
    float open_delay_timer;      // sizeof 04h    offset 4Ch
    int show_particles;          // sizeof 04h    offset 50h
    float targetdir;             // sizeof 04h    offset 54h
    float t1;                    // sizeof 04h    offset 58h
    zVEC3 targetpos;             // sizeof 0Ch    offset 5Ch
    zVEC3 startpos;              // sizeof 0Ch    offset 68h
    int nextRegister;            // sizeof 04h    offset 74h
    unsigned int keys;           // sizeof 04h    offset 78h

    void oCMag_Book_OnInit()                        zCall( 0x0046E910 );
    oCMag_Book()                                    zInit( oCMag_Book_OnInit() );
    ~oCMag_Book()                                   zCall( 0x0046EAE0 );
    void CheckConsistency()                         zCall( 0x0046EC40 );
    void SetOwner( zCVob* )                         zCall( 0x0046EE50 );
    void SetWorld( zCWorld* )                       zCall( 0x0046EEC0 );
    int Register( oCSpell*, int )                   zCall( 0x0046EED0 );
    int Register( oCItem*, int )                    zCall( 0x0046EFD0 );
    int DeRegister( oCItem* )                       zCall( 0x0046F0E0 );
    int DeRegister( int )                           zCall( 0x0046F1C0 );
    oCSpell* CreateNewSpell( int )                  zCall( 0x0046F270 );
    int Register( int, int )                        zCall( 0x0046F410 );
    int IsIn( int )                                 zCall( 0x0046F680 );
    void Spell_Setup( int, oCNpc*, zCVob* )         zCall( 0x0046F6C0 );
    void Spell_Setup( oCNpc*, zCVob* )              zCall( 0x0046F800 );
    void Spell_Invest()                             zCall( 0x0046F990 );
    void StartInvestEffect( zCVob*, int, int, int ) zCall( 0x0046FB10 );
    void Spell_Cast()                               zCall( 0x0046FC00 );
    void StartCastEffect( zCVob*, zVEC3 const& )    zCall( 0x004701A0 );
    int Spell_InCast()                              zCall( 0x00470290 );
    void Open( int )                                zCall( 0x004702A0 );
    void Close( int )                               zCall( 0x004705B0 );
    float Ease( float, float, float )               zCall( 0x00470720 );
    zVEC3 EasePos( float, zVEC3&, zVEC3& )          zCall( 0x00470750 );
    float GetAngle( zCVob* )                        zCall( 0x004707D0 );
    int IsInMovement()                              zCall( 0x00470AA0 );
    int IsActive()                                  zCall( 0x00470AB0 );
    oCSpell* GetSelectedSpell()                     zCall( 0x00470AC0 );
    int GetSelectedSpellNr()                        zCall( 0x00470B10 );
    void Spell_Open( int )                          zCall( 0x00470B20 );
    void StopSelectedSpell()                        zCall( 0x00470C50 );
    void KillSelectedSpell()                        zCall( 0x00470DD0 );
    void Spell_Stop( int )                          zCall( 0x00471090 );
    void Left()                                     zCall( 0x00471300 );
    void Right()                                    zCall( 0x00471360 );
    zVEC3 CalcPos( zCVob*, float )                  zCall( 0x004713B0 );
    int DoOpen()                                    zCall( 0x004717A0 );
    int DoClose()                                   zCall( 0x00471920 );
    void SetFrontSpell( int )                       zCall( 0x00471D00 );
    int DoTurn()                                    zCall( 0x00472090 );
    void ShowHandSymbol()                           zCall( 0x00472190 );
    void SetShowHandSymbol( int )                   zCall( 0x00472310 );
    void DoPerFrame()                               zCall( 0x00472670 );
    int GetNoOfSpells()                             zCall( 0x00472DA0 );
    oCSpell* GetSpell( oCItem*, int& )              zCall( 0x00472DB0 );
    oCSpell* GetSpell( int )                        zCall( 0x00472E00 );
    oCItem* GetSpellItem( int )                     zCall( 0x00472E20 );
    oCItem* GetSpellItem( oCSpell* )                zCall( 0x00472E40 );
    void NextRegisterAt( int )                      zCall( 0x00472E80 );
    oCSpell* GetSpellByKey( int )                   zCall( 0x00472EA0 );
    oCItem* GetSpellItemByKey( int )                zCall( 0x00472EE0 );
    int GetNoOfSpellByKey( int )                    zCall( 0x00472F20 );
    int GetKeyByItem( oCItem* )                     zCall( 0x00472F70 );

    // user API
    #include "oCMag_Book.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMAGIC_H__VER0__