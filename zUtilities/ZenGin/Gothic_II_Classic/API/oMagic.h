// Supported with union (c) 2018 Union team

#ifndef __OMAGIC_H__VER2__
#define __OMAGIC_H__VER2__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_II_Classic {

  class oCMag_Book {
  public:
    zCArray<oCSpell*> spells;
    zCArray<oCItem*> spellitems;
    zCWorld* wld;
    zCVob* owner;
    zCModel* model;
    int spellnr;
    float MAG_HEIGHT;
    int active;
    int remove_all;
    int in_movement;
    int show_handsymbol;
    float step;
    int action;
    int fullangle;
    int open;
    float open_delay_timer;
    int show_particles;
    float targetdir;
    float t1;
    zVEC3 targetpos;
    zVEC3 startpos;
    int nextRegister;
    unsigned int keys;

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