// Supported with union (c) 2018-2021 Union team

#ifndef __OMAGIC_H__VER2__
#define __OMAGIC_H__VER2__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_II_Classic {

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

    void oCMag_Book_OnInit()                        zCall( 0x00474050 );
    oCMag_Book()                                    zInit( oCMag_Book_OnInit() );
    ~oCMag_Book()                                   zCall( 0x00474220 );
    void CheckConsistency()                         zCall( 0x00474380 );
    void SetOwner( zCVob* )                         zCall( 0x004746B0 );
    void SetWorld( zCWorld* )                       zCall( 0x00474720 );
    int Register( oCSpell*, int )                   zCall( 0x00474730 );
    int Register( oCItem*, int )                    zCall( 0x00474810 );
    int DeRegister( oCItem* )                       zCall( 0x00474920 );
    int DeRegister( int )                           zCall( 0x00474A00 );
    oCSpell* CreateNewSpell( int )                  zCall( 0x00474AB0 );
    int Register( int, int )                        zCall( 0x00474C40 );
    int IsIn( int )                                 zCall( 0x00474E80 );
    void Spell_Setup( int, oCNpc*, zCVob* )         zCall( 0x00474EC0 );
    void Spell_Setup( oCNpc*, zCVob*, int )         zCall( 0x00475000 );
    void Spell_Invest()                             zCall( 0x00475190 );
    void StartInvestEffect( zCVob*, int, int, int ) zCall( 0x00475310 );
    void Spell_Cast()                               zCall( 0x00475400 );
    void StartCastEffect( zCVob*, zVEC3 const& )    zCall( 0x00475AC0 );
    int Spell_InCast()                              zCall( 0x00475BB0 );
    void Open( int )                                zCall( 0x00475BC0 );
    void Close( int )                               zCall( 0x00475ED0 );
    float Ease( float, float, float )               zCall( 0x00476040 );
    zVEC3 EasePos( float, zVEC3&, zVEC3& )          zCall( 0x00476070 );
    float GetAngle( zCVob* )                        zCall( 0x004760F0 );
    int IsInMovement()                              zCall( 0x004763C0 );
    int IsActive()                                  zCall( 0x004763D0 );
    oCSpell* GetSelectedSpell()                     zCall( 0x004763E0 );
    int GetSelectedSpellNr()                        zCall( 0x00476430 );
    void Spell_Open( int )                          zCall( 0x00476440 );
    void StopSelectedSpell()                        zCall( 0x00476570 );
    void KillSelectedSpell()                        zCall( 0x004766F0 );
    void Spell_Stop( int )                          zCall( 0x004769B0 );
    void Left()                                     zCall( 0x00476C20 );
    void Right()                                    zCall( 0x00476C80 );
    zVEC3 CalcPos( zCVob*, float )                  zCall( 0x00476CD0 );
    int DoOpen()                                    zCall( 0x004770C0 );
    int DoClose()                                   zCall( 0x00477240 );
    void SetFrontSpell( int )                       zCall( 0x00477620 );
    int DoTurn()                                    zCall( 0x004779B0 );
    void ShowHandSymbol()                           zCall( 0x00477AB0 );
    void SetShowHandSymbol( int )                   zCall( 0x00477C30 );
    void DoPerFrame()                               zCall( 0x00477F90 );
    int GetNoOfSpells()                             zCall( 0x004787C0 );
    oCSpell* GetSpell( oCItem*, int& )              zCall( 0x004787D0 );
    oCSpell* GetSpell( int )                        zCall( 0x00478820 );
    oCItem* GetSpellItem( int )                     zCall( 0x00478840 );
    oCItem* GetSpellItem( oCSpell* )                zCall( 0x00478860 );
    void NextRegisterAt( int )                      zCall( 0x004788A0 );
    oCSpell* GetSpellByKey( int )                   zCall( 0x004788C0 );
    oCItem* GetSpellItemByKey( int )                zCall( 0x00478900 );
    int GetNoOfSpellByKey( int )                    zCall( 0x00478940 );
    int GetKeyByItem( oCItem* )                     zCall( 0x00478990 );

    // user API
    #include "oCMag_Book.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMAGIC_H__VER2__