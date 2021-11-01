// Supported with union (c) 2018-2021 Union team

#ifndef __OSVM_H__VER0__
#define __OSVM_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 08h
  class oCSVMManager {
  public:
    int svm_max;      // sizeof 04h    offset 00h
    oCSVM* sv_module; // sizeof 04h    offset 04h

    void oCSVMManager_OnInit()       zCall( 0x006D1240 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x006D14E0 );
    int GetOU( zSTRING const&, int ) zCall( 0x006D1520 );

    // user API
    #include "oCSVMManager.inl"
  };

  // sizeof 0Ch
  class oCSVM {
  public:
    int number;     // sizeof 04h    offset 00h
    int classindex; // sizeof 04h    offset 04h
    zSTRING* entry; // sizeof 04h    offset 08h

    void oCSVM_OnInit()         zCall( 0x006D18B0 );
    oCSVM()                     zInit( oCSVM_OnInit() );
    ~oCSVM()                    zCall( 0x006D18C0 );
    void InitByScript( int )    zCall( 0x006D18E0 );
    int GetOU( zSTRING const& ) zCall( 0x006D1B70 );

    // user API
    #include "oCSVM.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OSVM_H__VER0__