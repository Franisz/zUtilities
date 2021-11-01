// Supported with union (c) 2018-2021 Union team

#ifndef __ZMACRO_H__VER1__
#define __ZMACRO_H__VER1__

namespace Gothic_I_Addon {

#define zRELEASE( obj ) { (obj)->Release(); obj = Null; }
#define zADDREF( obj )  (obj)->AddRef()
#define zNEW( obj ) new obj
#define zDELETE( obj ) delete obj
#ifndef SAFE_DELETE
#define SAFE_DELETE( obj ) if( obj ) { delete obj; obj = 0; }
#endif
#define zCall( address ) { XCALL( address ); }
#define zInit( call ) { if( Union.GetEngineVersion() == Engine_G1A ) call; }
#define zRTTI( type ) { return type; }
#ifndef __DONT_USE_VTABLE__
#define zPureCall = 0;
#else
#define zPureCall ;
#define virtual
#endif
#define group struct
#define RGBA(r,g,b,a)   ((zUINT32)(zUINT8)(r)|(zUINT32)(zUINT8)(g)<<8|(zUINT32)(zUINT8)(b)<<16|(zUINT32)(zUINT8)(a)<<24)
#define EXTRACT_R(rgba) (rgba       & 0xff)
#define EXTRACT_G(rgba) (rgba >> 8  & 0xff)
#define EXTRACT_B(rgba) (rgba >> 16 & 0xff)
#define EXTRACT_A(rgba) (rgba >> 24 & 0xff)
#define zMEMPOOL_VOLATILE_DECLARATION( className )


#define SafeDiv( a, b ) \
    ( b == 0.0 ? 0.0 : a / b )


#define sqr(a) (a * a)


#define CalcAngle(a, b)                     \
    if( b == 0.0f ) {                       \
      if( a == 0.0f )                       \
        return 0.0f;                        \
                                            \
      if( a > 0 )                           \
        return RAD90;                       \
      return RAD270;                        \
     }                                      \
                                            \
    if( a == 0.0f ) {                       \
      if( b > 0.0f )                        \
        return 0.0f;                        \
      return RAD180;                        \
    }                                       \
                                            \
    float angle = atan( SafeDiv( a, b ) );  \
    if( b < 0.0f )                          \
      angle += RAD180;                      \
    else if( a < 0.0f )                     \
      angle += RAD360;                      \
                                            \
    return angle;


#define RotAngle(a, b, c)                     \
    float radAngle = GetAngle##c();           \
    float length   = sqrt(sqr(a) + sqr(b));   \
    radAngle      += rad;                     \
    a              = sin(radAngle) * length;  \
    b              = cos(radAngle) * length;  \
    return *this;




  // ZMEMPOOL INTERFACE
  // memory pool declaration for gothic api containers
#define zMEMPOOL_DECLARATION_TEMPLATE( classname, address )                                         \
    void *operator new( size_t s ) {                                                                \
      return ((zCMemPoolBase*)address)->Alloc();                                                    \
    }                                                                                               \
    void operator delete( void *p ) {                                                               \
      ((zCMemPoolBase*)address)->Free( p );                                                         \
    }                                                                                               \
    void* operator new( unsigned int size, const char* classn, const char *file, int l ) {          \
      zCMemPoolBase::SetMemDebug( classn, file, l );                                                \
      return operator new( size );                                                                  \
    }                                                                                               \
    void operator delete( void* ptr, const char* classn, const char* file, int line ) {             \
      operator delete( ptr );                                                                       \
    }                                                                                               \
    static void PreAlloc( size_t num, zBOOL force_oneblock = False ){                               \
      ((zCMemPoolBase*)address)->PreAlloc( num, force_oneblock );                                   \
    }



  // memory pool declaration for gothic api classes
#define zMEMPOOL_DECLARATION( classname, address )                                                  \
    void* operator new( size_t s ){                                                                 \
      return ((zCMemPoolBase*)address)->Alloc();                                                    \
    }                                                                                               \
    void operator delete( void* p ) {                                                               \
      ((zCMemPoolBase*)address)->Free( p );                                                         \
    }                                                                                               \
    void* operator new( unsigned int size, const char* classn, const char* file, int l ) {          \
      zCMemPoolBase::SetMemDebug( classn, file, l );                                                \
      return operator new(size);                                                                    \
    }                                                                                               \
    void  operator delete( void* ptr,const char *classn,const char *file,int line) {                \
      operator delete(ptr);                                                                         \
    }                                                                                               \
    static void PreAlloc( size_t num, bool32 force_oneblock = False ) {                             \
      ((zCMemPoolBase*)address)->PreAlloc( num, force_oneblock );                                   \
    }                                                                                               \
    static void PoolAdd( classname *mem, int num_objects, bool32 free = False ) {                   \
      ((zCMemPoolBase*)address)->PoolAdd( mem, num_objects, free );                                 \
    }



  // ZOBJECT INTERFACE
  // class declaration for gothic api zobject classes
#define zCLASS_DECLARATION( className )                               \
  static zCClassDef* classDef;                                        \
  void* className::operator new( size_t size ) {                      \
    void* mem = ::operator new( size );                               \
  zCClassDef::ObjectCreated( (zCObject*)mem, className::classDef );   \
  return mem;                                                         \
  };                                                                  \
  void className::operator delete( void* mem ) {                      \
    zCClassDef::ObjectDeleted( (zCObject*)mem, className::classDef ); \
    ::operator delete( mem );                                         \
  };



  // class declaration for union zobject classes
#define zCLASS_UNION_DECLARATION( className )                \
  static zCClassDef* className::classDef;                    \
  static zCObject* className::_CreateNewInstance( void );    \
  virtual zCClassDef* className::_GetClassDef( void ) const; \
  void* className::operator new(size_t size);                \
  void className::operator delete(void* mem);



  // class definition for union zobject classes
#define zCLASS_UNION_DEFINITION( className, baseClassName, classFlags, archiveVersion )                                                         \
  zCClassDef* className::classDef = !CHECK_THIS_ENGINE ? Null :                                                                                 \
                                    new zCClassDef( #className, #baseClassName, className::_CreateNewInstance, sizeof( className ), 0, 0, "" ); \
  zCObject* className::_CreateNewInstance( void ) {                                                                                             \
    return new className;                                                                                                                       \
  }                                                                                                                                             \
  zCClassDef* className::_GetClassDef( void ) const {                                                                                           \
    return className::classDef;                                                                                                                 \
  };                                                                                                                                            \
  void* className::operator new( size_t size ) {                                                                                                \
    void* mem = ::operator new( size );                                                                                                         \
  zCClassDef::ObjectCreated( (zCObject*)mem, className::classDef );                                                                             \
  return mem;                                                                                                                                   \
  };                                                                                                                                            \
  void className::operator delete( void* mem ) {                                                                                                \
    zCClassDef::ObjectDeleted( (zCObject*)mem, className::classDef );                                                                           \
    ::operator delete( mem );                                                                                                                   \
  };



  // COLLISION INTERFACE
  // class declaration for gothic api collision object classes
#define zCOLLISION_OBJECT_DECLARATION( className )                    \
    static zCCollisionObjectDef* className::S_GetCollObjClass(void) { \
      return className::s_oCollObjClass;                              \
    };                                                                \
    static zCCollisionObjectDef* className::s_oCollObjClass; 


  // class declaration for union collision object classes
#define zCOLLISION_OBJECT_UNION_DECLARATION( className )                                                           \
  static  zCCollisionObjectDef* className::S_GetCollObjClass(void)      { return &(className::s_oCollObjClass); }; \
  virtual zCCollisionObjectDef* className::GetCollObjClass(void) const  { return &(className::s_oCollObjClass); }; \
  static  zCCollisionObjectDef  className::s_oCollObjClass;                                                        \
  static  zCCollisionObject*    className::_CreateNewInstance(void);


  // class definition for union collision object classes
#define zCOLLISION_OBJECT_UNION_DEFINITION( className, isVolatile )                           \
  zCCollisionObjectDef className::s_oCollObjClass(isVolatile, className::_CreateNewInstance); \
  zCCollisionObject* className::_CreateNewInstance(void) {                                    \
    return new className;                                                                     \
  }

} // namespace Gothic_II_Addon

#endif // __ZMACRO_H__VER1__