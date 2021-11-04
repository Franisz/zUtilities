// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_STACK_H__
#define __PATCH_STACK_H__

namespace SystemPack {
  class ASTAPI CPatchStack {
    CPatchStack *pPrev, *pNext;
    CPatchSymbol *pObject;
  public:
    CPatchStack();
    CPatchSymbol* Execute();
    void PushNext( CPatchStack* stack );
    void PushBack( CPatchStack* stack );
    void Destroy();
    CPatchStack* Prev();
    CPatchStack* Next();
    uint32 Num();
    CPatchSymbol* GetData();
    void SetData( CPatchSymbol* object );
    ~CPatchStack();

    static CPatchStack* CreateStack( const CString& line );
  };
}

#endif // __PATCH_STACK_H__