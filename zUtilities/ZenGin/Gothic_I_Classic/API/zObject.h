// Supported with union (c) 2018-2021 Union team

#ifndef __ZOBJECT_H__VER0__
#define __ZOBJECT_H__VER0__

namespace Gothic_I_Classic {

  enum zTClassFlags {
    zCLASS_FLAG_SHARED_OBJECTS = 1 << 0,
    zCLASS_FLAG_TRANSIENT      = 1 << 1,
    zCLASS_FLAG_RESOURCE       = 1 << 2
  };

  // sizeof 0Ch
  class zCLivingObjectsState {
  public:
    zCArray<int> numList; // sizeof 0Ch    offset 00h

    zCLivingObjectsState() {}

    // user API
    #include "zCLivingObjectsState.inl"
  };

  // sizeof 6Ch
  class zCClassDef {
  public:
    zSTRING className;                             // sizeof 14h    offset 00h
    zSTRING baseClassName;                         // sizeof 14h    offset 14h
    zSTRING scriptClassName;                       // sizeof 14h    offset 28h
    zCClassDef* baseClassDef;                      // sizeof 04h    offset 3Ch
    zCObject*( *createNewInstance )( void );       // sizeof 04h    offset 40h
    zCObject*( *createNewInstanceBackup )( void ); // sizeof 04h    offset 44h
    unsigned long classFlags;                      // sizeof 04h    offset 48h
    unsigned long classSize;                       // sizeof 04h    offset 4Ch
    int numLivingObjects;                          // sizeof 04h    offset 50h
    int numCtorCalled;                             // sizeof 04h    offset 54h
    zCObject** hashTable;                          // sizeof 04h    offset 58h
    zCArray<zCObject*> objectList;                 // sizeof 0Ch    offset 5Ch
    unsigned short archiveVersion;                 // sizeof 02h    offset 68h
    unsigned short archiveVersionSum;              // sizeof 02h    offset 6Ah

    void zCClassDef_OnInit()                                                                                                                                 zCall( 0x0058A770 );
    void zCClassDef_OnInit( zSTRING const&, zSTRING const&, zCObject*( __cdecl* )(), unsigned long, unsigned long, unsigned short, zSTRING const& )          zCall( 0x0058AD70 );
    zCClassDef()                                                                                                                                             zInit( zCClassDef_OnInit() );
    void Init()                                                                                                                                              zCall( 0x0058A900 );
    ~zCClassDef()                                                                                                                                            zCall( 0x0058AAB0 );
    zCClassDef( zSTRING const& a0, zSTRING const& a1, zCObject*( __cdecl* a2 )(), unsigned long a3, unsigned long a4, unsigned short a5, zSTRING const& a6 ) zInit( zCClassDef_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    zCObject* CreateNewInstance() const                                                                                                                      zCall( 0x0058B050 );
    void OverwriteCreateNewInstance( zCClassDef* )                                                                                                           zCall( 0x0058B110 );
    void ResetCreateNewInstance()                                                                                                                            zCall( 0x0058B130 );
    unsigned short GetClassID()                                                                                                                              zCall( 0x0058B140 );
    unsigned long GetHashIndex( zSTRING const& )                                                                                                             zCall( 0x0058B1D0 );
    unsigned long GetHashIndex( zCObject* )                                                                                                                  zCall( 0x0058B200 );
    void InsertHashTable( zCObject* )                                                                                                                        zCall( 0x0058B230 );
    void RemoveHashTable( zCObject* )                                                                                                                        zCall( 0x0058B270 );
    zCObject* SearchHashTable( zSTRING const& )                                                                                                              zCall( 0x0058B2B0 );
    float CalcHashTableSpread()                                                                                                                              zCall( 0x0058B340 );
    void ReportLeaks()                                                                                                                                       zCall( 0x0058B640 );
    static int CompareClassDefNames( void const*, void const* )                                                                                              zCall( 0x0058A410 );
    static zCClassDef* GetClassDef( zSTRING const& )                                                                                                         zCall( 0x0058A470 );
    static zCClassDef* GetClassDefTypeInsensitive( zSTRING const& )                                                                                          zCall( 0x0058A590 );
    static void EndStartup()                                                                                                                                 zCall( 0x0058AC30 );
    static zCObject* CreateNewInstanceID( unsigned short )                                                                                                   zCall( 0x0058B1B0 );
    static void ObjectCreated( zCObject*, zCClassDef* )                                                                                                      zCall( 0x0058B380 );
    static void ObjectDeleted( zCObject*, zCClassDef* )                                                                                                      zCall( 0x0058B4A0 );
    static void ObjectCreated( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x0058B540 );
    static void ObjectDeleted( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x0058B580 );
    static void GetLivingObjectsState( zCLivingObjectsState& )                                                                                               zCall( 0x0058B9D0 );
    static void CompareLivingObjectsState( zCLivingObjectsState const& )                                                                                     zCall( 0x0058BA80 );
    static void ObjectCreated( zCObject*, zCClassDef*, char const*, int )                                                                                    zCall( 0x0075A250 );

    static zCArraySort<zCClassDef*>*& classDefList;
    static zCClassDef*& classDefSearchDummy;
    static int& startupFinished;

    // user API
    #include "zCClassDef.inl"
  };

  template<class T>
  T* zDYNAMIC_CAST( zCObject const* pObject ) {
    if( !pObject ) {
      return Null;
    }
    zCClassDef* pDef = pObject->_GetClassDef();
    if( zCObject::CheckInheritance( T::classDef, pDef ) ) {
      return (T*)pObject;
    }
    return dynamic_cast<T*>((zCObject*)pObject);
  }

  // sizeof 24h
  class zCObject {
  public:
    zCLASS_DECLARATION( zCObject )

    int refCtr;               // sizeof 04h    offset 04h
    unsigned short hashIndex; // sizeof 02h    offset 08h
    zCObject* hashNext;       // sizeof 04h    offset 0Ch
    zSTRING objectName;       // sizeof 14h    offset 10h

    void zCObject_OnInit()                                              zCall( 0x00401C20 );
    zCObject()                                                          zInit( zCObject_OnInit() );
    int Release()                                                       zCall( 0x0042AC30 );
    zCObject* CreateCopy()                                              zCall( 0x00589630 );
    zSTRING const& GetObjectName() const                                zCall( 0x0058A160 );
    int SetObjectName( zSTRING const& )                                 zCall( 0x0058A170 );
    static int CheckInheritance( zCClassDef const*, zCClassDef const* ) zCall( 0x00470130 );
    static int CheckInheritance( zCObject const*, zCObject const* )     zCall( 0x00589390 );
    static int CheckInheritance( zSTRING const&, zSTRING const& )       zCall( 0x005893D0 );
    static zCObject* CreateNewInstance( zSTRING const& )                zCall( 0x00589500 );
    static void PrintClassHierarchy( int, zCClassDef*, int, int )       zCall( 0x005896F0 );
    static void GetMemStats( int&, int&, zCClassDef* )                  zCall( 0x0058A0F0 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00401D80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00401D90 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00401DA0 );
    virtual ~zCObject( void )                                           zCall( 0x005891E0 );
    void AddRef() { refCtr++; }

    template<class T>
    T* CastTo() {
      return zDYNAMIC_CAST<T>( this );
    }

    template<class T>
    const T* CastTo() const {
      return zDYNAMIC_CAST<T>( this );
    }

    // user API
    #include "zCObject.inl"
  };

  // sizeof 24h
  class zCObjectFactory : public zCObject {
  public:
    zCLASS_DECLARATION( zCObjectFactory )

    zCObjectFactory() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005890A0 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00425DA0 );
    virtual ~zCObjectFactory( void )                                    zCall( 0x00425E00 );
    virtual zCEventManager* CreateEventManager( zCVob* )                zCall( 0x0058BDE0 );
    virtual zFILE* CreateZFile( zSTRING const& )                        zCall( 0x0058BD60 );
    virtual zCSession* CreateSession( void )                            zCall( 0x0058C130 );
    virtual zCCSManager* CreateCSManager( void )                        zCall( 0x0058C1A0 );
    virtual zCNetVobControl* CreateNetVobControl( zCVob* )              zCall( 0x0058BF10 );
    virtual zCGameInfo* CreateGameInfo( void )                          zCall( 0x00425DB0 );
    virtual zCPlayerInfo* CreatePlayerInfo( void )                      zCall( 0x00425DC0 );
    virtual zCWorld* CreateWorld( void )                                zCall( 0x0058C210 );
    virtual zCWaypoint* CreateWaypoint( void )                          zCall( 0x0058BFA0 );
    virtual zCWay* CreateWay( void )                                    zCall( 0x0058C0C0 );

    // user API
    #include "zCObjectFactory.inl"
  };
} // namespace Gothic_I_Classic

#endif // __ZOBJECT_H__VER0__