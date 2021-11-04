// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ALLOCATOR_32_H__
#define __UNION_ALLOCATOR_32_H__

#define untyped_ptr  ...
#define memsize(dst) shi_msize(dst)
#define True         (1)
#define False        (0)
#define Yes          True
#define No           False
#define Null         (nullptr)
#define None         (0)
#define Invalid      (-1)
#define HookDelayed  (0)
#define Undefined    Invalid
#define NotFound     Invalid
#define NullStrA     ((char*)None)
#define NullStrW     ((wchar_t*)None)
#define Success      True
#define Failed       False
#define __INLINE     inline
#define Ref          &

#define I32 (int32)
#define I64 (int64)
#define U32 (uint32)
#define U64 (uint64)
#define F32 (real32)
#define F64 (real64)

#define MemDel(obj)       { shi_free(obj); obj = Null; }
#define DeleteObject(obj) { delete obj; obj = Null; }

#ifdef UNICODE
#define NullStr			NullStrW
#else
#define NullStr			NullStrA
#endif

#define zPixelX screen->anx
#define zPixelY screen->any
#define zVirtualX screen->nax
#define zVirtualY screen->nay
#define zNax( v, p ) v->nax( p )
#define zNay( v, p ) v->nay( p )
#define zAnx( v, p ) v->anx( p )
#define zAny( v, p ) v->any( p )

#define zKeyPressed( a ) zinput->KeyPressed(a)
#define zKeyToggled( a ) zinput->KeyToggled(a)
#define zMouseKeyPressed( button ) zinput->GetMouseButtonPressed##button()
#define zMouseKeyToggled( button ) zinput->GetMouseButtonToggled##button()
#define zBindPressed( logic ) zinput->GetState( logic )
#define zBindToggled( logic ) zinput->IsBindedToggled(logic, zinput->GetKey())

#define RGBA(r,g,b,a) ( (zUINT32)(zUINT8)(r)|(zUINT32)(zUINT8)(g)<<8|(zUINT32)(zUINT8)(b)<<16|(zUINT32)(zUINT8)(a)<<24 )
#define EXTRACT_R(rgba) ( rgba		& 0xff  )
#define EXTRACT_G(rgba) ( rgba >> 8	& 0xff  )
#define EXTRACT_B(rgba) ( rgba >> 16 & 0xff )
#define EXTRACT_A(rgba) ( rgba >> 24 & 0xff )

#define VID_MAX_XDIM GetSystemMetrics( SM_CXSCREEN )
#define VID_MAX_YDIM GetSystemMetrics( SM_CYSCREEN )

#define _HUGE_ENUF 1e+300
#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define NAN        ((float)(INFINITY * 0.0F))
#define ISNAN(x)   _isnan(x)
#define THISCALL(a) (this->*a)

#ifndef zCall
#define zCall( address ) { XCALL( address ); }
#define zInit( call ) { call; }
#endif

#define XCALL(uAddr)      \
 __asm { mov esp, ebp   } \
 __asm { pop ebp        } \
 __asm { mov eax, uAddr } \
 __asm { jmp eax        }

#ifndef CORE_SECURE_DISABLE
#define UNSAFE_MESSAGE "Unsafe function. Don't call it or use CORE_SECURE_DISABLE"
#define UNSAFE __declspec(deprecated(UNSAFE_MESSAGE)) 
#else
#define UNSAFE
#endif

#define Enabled(v) (!v) ? 0 : 
#define zEngineDefined( e ) Union.GetEngineVersion() != e ? 0 : 

#define zMouseFix_SetInputWindow(x)                                                          \
  HMODULE zMouseFix = GetModuleHandle( "zMouseFix.dll" );                                    \
  if( zMouseFix ) {                                                                          \
    auto SetInputWindow = ( void( *)( HWND ) )GetProcAddress( zMouseFix, "SetInputWindow" ); \
    if( SetInputWindow )                                                                     \
      SetInputWindow( x );                                                                   \
  }

#endif // __UNION_ALLOCATOR_32_H__