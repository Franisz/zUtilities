// Supported with union (c) 2018 Union team

#ifndef __OSVM_H__VER2__
#define __OSVM_H__VER2__

namespace Gothic_II_Classic {

  class oCSVMManager {
  public:
    int svm_max;
    oCSVM* sv_module;

    void oCSVMManager_OnInit()       zCall( 0x0071A130 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x0071A3D0 );
    int GetOU( zSTRING const&, int ) zCall( 0x0071A410 );

    // user API
    #include "oCSVMManager.inl"
  };

  class oCSVM {
  public:
    int number;
    int classindex;
    zSTRING* entry;

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