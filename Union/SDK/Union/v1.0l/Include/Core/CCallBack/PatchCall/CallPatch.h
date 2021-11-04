// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_CALLPATCH_H__
#define __UNION_CALLPATCH_H__

#define PATCH( from, to ) = AutoModulePatchCallInvoker_BySignature( #from, to )
#define PATCH_IF( from, to, cond ) = AutoModulePatchCallInvoker_BySignature( #from, to, cond )
#define FASTHOOK_PATCH( Class, Func ) HOOK Hook_##Class##_##Func PATCH( &##Class::##Func, &##Class::##Func##_Union )
#define FASTHOOK_PATCH_IF( Class, Func, Cond ) HOOK Hook_##Class##_##Func PATCH( &##Class::##Func, &##Class::##Func##_Union, Cond )

namespace UnionCore {

  struct ModuleRange {
    HMODULE module;
    uint base;
    uint length;
  };



  struct ModuleCallCollision {
    ModuleRange moduleRange;
    byte instruction;
    byte* memory;
    uint address;
  };



  class ASTAPI ModulePatchCallInfo {
    static Array<ModulePatchCallInfo*> patches;
    Array<ModuleCallCollision> collisions;
    ModulePatchCallInfo* prev;
    ModulePatchCallInfo* next;
    uint origin;
    uint address;
    uint References;

    void DisableCallPatch();
    void EnableCallPatch();
  public:

    ModulePatchCallInfo();
    void SetCallPatch( uint from, uint to );
    void SetTemporary( uint from, uint to );
    void RemoveCallPatch();
    void AddRef();
    void Release();

    ModulePatchCallInfo* GetFirst();
    ModulePatchCallInfo* GetLast();
    uint GetOrigin();
    uint GetAddress();
    uint GetReturnAddress();
    ~ModulePatchCallInfo();

    static ModulePatchCallInfo* FindPatchedCallInfo( uint address );
  };



  ModuleRange ASTAPI GetModuleRange( HMODULE module );
  bool ASTAPI CheckModuleCallCollision( ModuleRange& moduleRange, byte* memory, uint address, ModuleCallCollision& collision );
  Array<ModuleCallCollision> ASTAPI GetModuleCallCollisions( HMODULE module, uint address );
  void ASTAPI SetModuleCallPatch( const ModuleCallCollision& collision, uint newAddress );
  void ASTAPI SetModuleCallPatch( const Array<ModuleCallCollision>& collisions, uint newAddress );
  void ASTAPI RestorePatchedModuleCall( const ModuleCallCollision& collision );
  void ASTAPI RestorePatchedModuleCall( const Array<ModuleCallCollision>& collisions );

  template<class T>
  T SelectModuleCallPatchFunction( T same, uint address ) {
    ModulePatchCallInfo* patch = ModulePatchCallInfo::FindPatchedCallInfo( address );
    if( patch ) {
      uint64 returnAddress = patch->GetLast()->GetAddress();
      return *(T*)&returnAddress;
    }

    return same;
  }




  template<class T>
  class ModulePatchCallInvoker {
    ModulePatchCallInfo* patch;
  public:

    ModulePatchCallInvoker();
    ModulePatchCallInvoker( const ModulePatchCallInvoker<T>& other );
    ModulePatchCallInvoker( TInstance from, TInstance to, bool commit = true );
    void Attach( TInstance from, TInstance to, bool commit = true );
    void Detach( bool release = false );
    void Commit();
    operator T();
    T CastToPointer() const;
    ModulePatchCallInfo* GetModulePatchCallInfo();
    ~ModulePatchCallInvoker();
  };



  template<class T>
  ModulePatchCallInvoker<T>::ModulePatchCallInvoker() {
    patch = new ModulePatchCallInfo();
  }



  template<class T>
  ModulePatchCallInvoker<T>::ModulePatchCallInvoker( const ModulePatchCallInvoker<T>& other ) {
    patch = other.patch;
    patch->AddRef();
  }



  template<class T>
  ModulePatchCallInvoker<T>::ModulePatchCallInvoker( TInstance from, TInstance to, bool commit ) {
    Attach( from, to, commit );
  }



  template<class T>
  void ModulePatchCallInvoker<T>::Attach( TInstance from, TInstance to, bool commit ) {
    if( from.data == Null || to.data == Null )
      return;

    if( patch )
      Detach();

    patch = new ModulePatchCallInfo();

    if( commit ) patch->SetCallPatch( (uint)from.data, (uint)to.data );
    else         patch->SetTemporary( (uint)from.data, (uint)to.data );
  }



  template<class T>
  void ModulePatchCallInvoker<T>::Detach( bool release ) {
    patch->RemoveCallPatch();
    if( release ) {
      patch->Release();
      patch = Null;
    }
  }



  template<class T>
  void ModulePatchCallInvoker<T>::Commit() {
    uint origin  = patch->GetOrigin();
    uint address = patch->GetAddress();
    if( origin == 0 || address == 0 )
      return;

    patch->SetCallPatch( origin, address );
  }



  template<class T>
  ModulePatchCallInvoker<T>::operator T() {
    return CastToPointer();
  }



  template<class T>
  ModulePatchCallInfo* ModulePatchCallInvoker<T>::GetModulePatchCallInfo() {
    return patch;
  }



  template<class T>
  T ModulePatchCallInvoker<T>::CastToPointer() const {
    uint64 returnAddress = patch ? patch->GetReturnAddress() : 0;
    return *(T*)&returnAddress;
  }



  //
  template<class T>
  ModulePatchCallInvoker<T>::~ModulePatchCallInvoker() {
    if( patch )
      patch->Release();
  }



  template <typename T, typename O>
  inline ModulePatchCallInvoker<T> AutoModulePatchCallInvoker( O oldfunc, T newfunc ) {
    void* oldfunc_pointer = (void*&)oldfunc;
    void* newfunc_pointer = (void*&)newfunc;
    return ModulePatchCallInvoker<T>( oldfunc_pointer, newfunc_pointer );
  }
}

#endif // __UNION_CALLPATCH_H__