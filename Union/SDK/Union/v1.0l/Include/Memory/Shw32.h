// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_MEMORY_H__
#define __UNION_MEMORY_H__
#define SHIEXT EXTERN_C __declspec( dllimport )

// shw32 allocators
SHIEXT void* shi_malloc( unsigned int sz );
SHIEXT void* shi_calloc( unsigned int num, unsigned int sz );
SHIEXT void* shi_realloc( void* mem, unsigned int sz );
SHIEXT void shi_free( void* mem );
SHIEXT void shi_delete( void* mem );
SHIEXT unsigned int shi_msize( void* mem );
SHIEXT int shi_MemInitDefaultPool();

// native engine operators
inline void* operator new ( size_t sz )       { return shi_malloc( sz ); }
inline void* operator new [] ( size_t sz )    { return shi_malloc( sz ); }
inline void  operator delete ( void* mem )    { shi_free( mem ); }
inline void  operator delete [] ( void* mem ) { shi_free( mem ); }

#endif // __UNION_MEMORY_H__