// Supported with union (c) 2018 Union team

#ifndef __OMAGIC_H__VER1__
#define __OMAGIC_H__VER1__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_I_Addon {

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