// Supported with union (c) 2018-2021 Union team

#ifndef __OMAGIC_H__VER1__
#define __OMAGIC_H__VER1__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_I_Addon {

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

    void oCMag_Book_OnInit()                        zCall( 0x00477750 );
    oCMag_Book()                                    zInit( oCMag_Book_OnInit() );
    ~oCMag_Book()                                   zCall( 0x00477930 );
    void CheckConsistency()                         zCall( 0x00477A90 );
    void SetOwner( zCVob* )                         zCall( 0x00477CA0 );
    void SetWorld( zCWorld* )                       zCall( 0x00477D10 );
    int Register( oCSpell*, int )                   zCall( 0x00477D20 );
    int Register( oCItem*, int )                    zCall( 0x00477E20 );
    int DeRegister( oCItem* )                       zCall( 0x00477F40 );
    int DeRegister( int )                           zCall( 0x00478010 );
    oCSpell* CreateNewSpell( int )                  zCall( 0x004780C0 );
    int Register( int, int )                        zCall( 0x00478270 );
    int IsIn( int )                                 zCall( 0x00478510 );
    void Spell_Setup( int, oCNpc*, zCVob* )         zCall( 0x00478550 );
    void Spell_Setup( oCNpc*, zCVob* )              zCall( 0x004786A0 );
    void Spell_Invest()                             zCall( 0x00478830 );
    void StartInvestEffect( zCVob*, int, int, int ) zCall( 0x004789B0 );
    void Spell_Cast()                               zCall( 0x00478AA0 );
    void StartCastEffect( zCVob*, zVEC3 const& )    zCall( 0x00479060 );
    int Spell_InCast()                              zCall( 0x00479150 );
    void Open( int )                                zCall( 0x00479160 );
    void Close( int )                               zCall( 0x00479490 );
    float Ease( float, float, float )               zCall( 0x00479610 );
    zVEC3 EasePos( float, zVEC3&, zVEC3& )          zCall( 0x00479640 );
    float GetAngle( zCVob* )                        zCall( 0x004796E0 );
    int IsInMovement()                              zCall( 0x004799F0 );
    int IsActive()                                  zCall( 0x00479A00 );
    oCSpell* GetSelectedSpell()                     zCall( 0x00479A10 );
    int GetSelectedSpellNr()                        zCall( 0x00479A70 );
    void Spell_Open( int )                          zCall( 0x00479A80 );
    void StopSelectedSpell()                        zCall( 0x00479BC0 );
    void KillSelectedSpell()                        zCall( 0x00479D40 );
    void Spell_Stop( int )                          zCall( 0x0047A000 );
    void Left()                                     zCall( 0x0047A290 );
    void Right()                                    zCall( 0x0047A2F0 );
    zVEC3 CalcPos( zCVob*, float )                  zCall( 0x0047A340 );
    int DoOpen()                                    zCall( 0x0047A800 );
    int DoClose()                                   zCall( 0x0047A9F0 );
    void SetFrontSpell( int )                       zCall( 0x0047AE00 );
    int DoTurn()                                    zCall( 0x0047B1C0 );
    void ShowHandSymbol()                           zCall( 0x0047B2D0 );
    void SetShowHandSymbol( int )                   zCall( 0x0047B4C0 );
    void DoPerFrame()                               zCall( 0x0047B880 );
    int GetNoOfSpells()                             zCall( 0x0047C040 );
    oCSpell* GetSpell( oCItem*, int& )              zCall( 0x0047C050 );
    oCSpell* GetSpell( int )                        zCall( 0x0047C0B0 );
    oCItem* GetSpellItem( int )                     zCall( 0x0047C0D0 );
    oCItem* GetSpellItem( oCSpell* )                zCall( 0x0047C0F0 );
    void NextRegisterAt( int )                      zCall( 0x0047C130 );
    oCSpell* GetSpellByKey( int )                   zCall( 0x0047C150 );
    oCItem* GetSpellItemByKey( int )                zCall( 0x0047C190 );
    int GetNoOfSpellByKey( int )                    zCall( 0x0047C1D0 );
    int GetKeyByItem( oCItem* )                     zCall( 0x0047C220 );

    // user API
    #include "oCMag_Book.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMAGIC_H__VER1__