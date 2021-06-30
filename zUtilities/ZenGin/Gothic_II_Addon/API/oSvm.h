// Supported with union (c) 2018 Union team

#ifndef __OSVM_H__VER3__
#define __OSVM_H__VER3__

namespace Gothic_II_Addon {

  class oCSVMManager {
  public:
    int svm_max;
    oCSVM* sv_module;

    void oCSVMManager_OnInit()       zCall( 0x00779B70 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x00779E10 );
    int GetOU( zSTRING const&, int ) zCall( 0x00779E50 );

    // user API
    #include "oCSVMManager.inl"
  };

  class oCSVM {
  public:
    int number;
    int classindex;
    zSTRING* entry;

    void oCSVM_OnInit()         zCall( 0x0077A260 );
    oCSVM()                     zInit( oCSVM_OnInit() );
    ~oCSVM()                    zCall( 0x0077A270 );
    void InitByScript( int )    zCall( 0x0077A290 );
    int GetOU( zSTRING const& ) zCall( 0x0077A540 );

    // user API
    #include "oCSVM.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OSVM_H__VER3__