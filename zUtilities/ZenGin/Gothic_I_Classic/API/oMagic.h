// Supported with union (c) 2018 Union team

#ifndef __OMAGIC_H__VER0__
#define __OMAGIC_H__VER0__

#include "zParser.h"
#include "z3d.h"
#include "zModel.h"
#include "oSpell.h"
#include "oItem.h"

namespace Gothic_I_Classic {

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