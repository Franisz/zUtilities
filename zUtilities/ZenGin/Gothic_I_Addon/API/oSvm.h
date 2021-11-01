// Supported with union (c) 2018-2021 Union team

#ifndef __OSVM_H__VER1__
#define __OSVM_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 08h
  class oCSVMManager {
  public:
    int svm_max;      // sizeof 04h    offset 00h
    oCSVM* sv_module; // sizeof 04h    offset 04h

    void oCSVMManager_OnInit()       zCall( 0x00707DF0 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x007080C0 );
    int GetOU( zSTRING const&, int ) zCall( 0x00708100 );

    // user API
    #include "oCSVMManager.inl"
  };

  // sizeof 0Ch
  class oCSVM {
  public:
    int number;     // sizeof 04h    offset 00h
    int classindex; // sizeof 04h    offset 04h
    zSTRING* entry; // sizeof 04h    offset 08h

    void oCSVM_OnInit()         zCall( 0x00708500 );
    oCSVM()                     zInit( oCSVM_OnInit() );
    ~oCSVM()                    zCall( 0x00708510 );
    void InitByScript( int )    zCall( 0x00708530 );
    int GetOU( zSTRING const& ) zCall( 0x00708800 );

    // user API
    #include "oCSVM.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OSVM_H__VER1__