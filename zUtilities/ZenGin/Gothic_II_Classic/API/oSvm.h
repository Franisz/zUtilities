// Supported with union (c) 2018-2021 Union team

#ifndef __OSVM_H__VER2__
#define __OSVM_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 08h
  class oCSVMManager {
  public:
    int svm_max;      // sizeof 04h    offset 00h
    oCSVM* sv_module; // sizeof 04h    offset 04h

    void oCSVMManager_OnInit()       zCall( 0x0071A130 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x0071A3D0 );
    int GetOU( zSTRING const&, int ) zCall( 0x0071A410 );

    // user API
    #include "oCSVMManager.inl"
  };

  // sizeof 0Ch
  class oCSVM {
  public:
    int number;     // sizeof 04h    offset 00h
    int classindex; // sizeof 04h    offset 04h
    zSTRING* entry; // sizeof 04h    offset 08h

    void oCSVM_OnInit()         zCall( 0x0071A820 );
    oCSVM()                     zInit( oCSVM_OnInit() );
    ~oCSVM()                    zCall( 0x0071A830 );
    void InitByScript( int )    zCall( 0x0071A850 );
    int GetOU( zSTRING const& ) zCall( 0x0071AB00 );

    // user API
    #include "oCSVM.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OSVM_H__VER2__