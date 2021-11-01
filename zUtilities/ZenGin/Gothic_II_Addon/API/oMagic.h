// Supported with union (c) 2018-2021 Union team

#ifndef __OMAGIC_H__VER3__
#define __OMAGIC_H__VER3__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_II_Addon {

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

    void oCMag_Book_OnInit()                        zCall( 0x004753F0 );
    oCMag_Book()                                    zInit( oCMag_Book_OnInit() );
    ~oCMag_Book()                                   zCall( 0x004755C0 );
    void CheckConsistency()                         zCall( 0x00475720 );
    void SetOwner( zCVob* )                         zCall( 0x00475A50 );
    void SetWorld( zCWorld* )                       zCall( 0x00475AC0 );
    int Register( oCSpell*, int )                   zCall( 0x00475AD0 );
    int Register( oCItem*, int )                    zCall( 0x00475BB0 );
    int DeRegister( oCItem* )                       zCall( 0x00475CC0 );
    int DeRegister( int )                           zCall( 0x00475DA0 );
    oCSpell* CreateNewSpell( int )                  zCall( 0x00475E50 );
    int Register( int, int )                        zCall( 0x00475FE0 );
    int IsIn( int )                                 zCall( 0x00476220 );
    void Spell_Setup( int, oCNpc*, zCVob* )         zCall( 0x00476260 );
    void Spell_Setup( oCNpc*, zCVob*, int )         zCall( 0x004763A0 );
    void Spell_Invest()                             zCall( 0x00476530 );
    void StartInvestEffect( zCVob*, int, int, int ) zCall( 0x004766B0 );
    void Spell_Cast()                               zCall( 0x004767A0 );
    void StartCastEffect( zCVob*, zVEC3 const& )    zCall( 0x00476E60 );
    int Spell_InCast()                              zCall( 0x00476F50 );
    void Open( int )                                zCall( 0x00476F60 );
    void Close( int )                               zCall( 0x00477270 );
    float Ease( float, float, float )               zCall( 0x004773E0 );
    zVEC3 EasePos( float, zVEC3&, zVEC3& )          zCall( 0x00477410 );
    float GetAngle( zCVob* )                        zCall( 0x00477490 );
    int IsInMovement()                              zCall( 0x00477760 );
    int IsActive()                                  zCall( 0x00477770 );
    oCSpell* GetSelectedSpell()                     zCall( 0x00477780 );
    int GetSelectedSpellNr()                        zCall( 0x004777D0 );
    void Spell_Open( int )                          zCall( 0x004777E0 );
    void StopSelectedSpell()                        zCall( 0x00477910 );
    void KillSelectedSpell()                        zCall( 0x00477A90 );
    void Spell_Stop( int )                          zCall( 0x00477D50 );
    void Left()                                     zCall( 0x00477FC0 );
    void Right()                                    zCall( 0x00478020 );
    zVEC3 CalcPos( zCVob*, float )                  zCall( 0x00478070 );
    int DoOpen()                                    zCall( 0x00478460 );
    int DoClose()                                   zCall( 0x004785E0 );
    void SetFrontSpell( int )                       zCall( 0x004789C0 );
    int DoTurn()                                    zCall( 0x00478D50 );
    void ShowHandSymbol()                           zCall( 0x00478E50 );
    void SetShowHandSymbol( int )                   zCall( 0x00478FD0 );
    void DoPerFrame()                               zCall( 0x00479330 );
    int GetNoOfSpells()                             zCall( 0x00479B60 );
    oCSpell* GetSpell( oCItem*, int& )              zCall( 0x00479B70 );
    oCSpell* GetSpell( int )                        zCall( 0x00479BC0 );
    oCItem* GetSpellItem( int )                     zCall( 0x00479BE0 );
    oCItem* GetSpellItem( oCSpell* )                zCall( 0x00479C00 );
    void NextRegisterAt( int )                      zCall( 0x00479C40 );
    oCSpell* GetSpellByKey( int )                   zCall( 0x00479C60 );
    oCItem* GetSpellItemByKey( int )                zCall( 0x00479CA0 );
    int GetNoOfSpellByKey( int )                    zCall( 0x00479CE0 );
    int GetKeyByItem( oCItem* )                     zCall( 0x00479D30 );

    // user API
    #include "oCMag_Book.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMAGIC_H__VER3__