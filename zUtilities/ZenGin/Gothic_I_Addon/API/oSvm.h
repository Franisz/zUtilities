// Supported with union (c) 2018 Union team

#ifndef __OSVM_H__VER1__
#define __OSVM_H__VER1__

namespace Gothic_I_Addon {

  class oCSVMManager {
  public:
    int svm_max;
    oCSVM* sv_module;

    void oCSVMManager_OnInit()       zCall( 0x00707DF0 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x007080C0 );
    int GetOU( zSTRING const&, int ) zCall( 0x00708100 );

    // user API
    #include "oCSVMManager.inl"
  };

  class oCSVM {
  public:
    int number;
    int classindex;
    zSTRING* entry;

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