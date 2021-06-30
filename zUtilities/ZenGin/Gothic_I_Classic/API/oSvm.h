// Supported with union (c) 2018 Union team

#ifndef __OSVM_H__VER0__
#define __OSVM_H__VER0__

namespace Gothic_I_Classic {

  class oCSVMManager {
  public:
    int svm_max;
    oCSVM* sv_module;

    void oCSVMManager_OnInit()       zCall( 0x006D1240 );
    oCSVMManager()                   zInit( oCSVMManager_OnInit() );
    ~oCSVMManager()                  zCall( 0x006D14E0 );
    int GetOU( zSTRING const&, int ) zCall( 0x006D1520 );

    // user API
    #include "oCSVMManager.inl"
  };

  class oCSVM {
  public:
    int number;
    int classindex;
    zSTRING* entry;

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