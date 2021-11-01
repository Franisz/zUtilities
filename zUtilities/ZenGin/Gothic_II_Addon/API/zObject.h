// Supported with union (c) 2018-2021 Union team

#ifndef __ZOBJECT_H__VER3__
#define __ZOBJECT_H__VER3__

namespace Gothic_II_Addon {

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

    void zCClassDef_OnInit()                                                                                                                                 zCall( 0x005AA2E0 );
    void zCClassDef_OnInit( zSTRING const&, zSTRING const&, zCObject*( __cdecl* )(), unsigned long, unsigned long, unsigned short, zSTRING const& )          zCall( 0x005AA8E0 );
    zCClassDef()                                                                                                                                             zInit( zCClassDef_OnInit() );
    void Init()                                                                                                                                              zCall( 0x005AA470 );
    ~zCClassDef()                                                                                                                                            zCall( 0x005AA620 );
    zCClassDef( zSTRING const& a0, zSTRING const& a1, zCObject*( __cdecl* a2 )(), unsigned long a3, unsigned long a4, unsigned short a5, zSTRING const& a6 ) zInit( zCClassDef_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    zCObject* CreateNewInstance() const                                                                                                                      zCall( 0x005AAB80 );
    void OverwriteCreateNewInstance( zCClassDef* )                                                                                                           zCall( 0x005AAC40 );
    void ResetCreateNewInstance()                                                                                                                            zCall( 0x005AAC60 );
    unsigned short GetClassID()                                                                                                                              zCall( 0x005AAC70 );
    unsigned long GetHashIndex( zSTRING const& )                                                                                                             zCall( 0x005AAD00 );
    unsigned long GetHashIndex( zCObject* )                                                                                                                  zCall( 0x005AAD30 );
    void InsertHashTable( zCObject* )                                                                                                                        zCall( 0x005AAD60 );
    void RemoveHashTable( zCObject* )                                                                                                                        zCall( 0x005AADA0 );
    zCObject* SearchHashTable( zSTRING const& )                                                                                                              zCall( 0x005AADE0 );
    float CalcHashTableSpread()                                                                                                                              zCall( 0x005AAE70 );
    void ReportLeaks()                                                                                                                                       zCall( 0x005AB170 );
    static int CompareClassDefNames( void const*, void const* )                                                                                              zCall( 0x005A9F80 );
    static zCClassDef* GetClassDef( zSTRING const& )                                                                                                         zCall( 0x005A9FE0 );
    static zCClassDef* GetClassDefTypeInsensitive( zSTRING const& )                                                                                          zCall( 0x005AA100 );
    static void EndStartup()                                                                                                                                 zCall( 0x005AA7A0 );
    static zCObject* CreateNewInstanceID( unsigned short )                                                                                                   zCall( 0x005AACE0 );
    static void ObjectCreated( zCObject*, zCClassDef* )                                                                                                      zCall( 0x005AAEB0 );
    static void ObjectDeleted( zCObject*, zCClassDef* )                                                                                                      zCall( 0x005AAFD0 );
    static void ObjectCreated( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x005AB070 );
    static void ObjectDeleted( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x005AB0B0 );
    static void GetLivingObjectsState( zCLivingObjectsState& )                                                                                               zCall( 0x005AB590 );
    static void CompareLivingObjectsState( zCLivingObjectsState const& )                                                                                     zCall( 0x005AB630 );
    static void ObjectCreated( zCObject*, zCClassDef*, char const*, int )                                                                                    zCall( 0x0065DD10 );

    static zCArraySort<zCClassDef*>*& classDefList;
    static zCClassDef*& classDefSearchDummy;
    static int& startupFinished;

    // user API
    #include "zCClassDef.inl"
  };

  template<class T>
  T* zDYNAMIC_CAST( zCObject const* pObject )
  {
    if( !pObject ) {
      return Null;
    }
    zCClassDef* pDef = pObject->_GetClassDef();
    if( zCObject::CheckInheritance( T::classDef, pDef )) {
      return (T*)pObject;
    }
    return dynamic_cast<T*>( (zCObject*)pObject );
  }

  // sizeof 24h
  class zCObject {
    friend zCClassDef;

  public:
    zCLASS_DECLARATION( zCObject )

    int refCtr;               // sizeof 04h    offset 04h
    unsigned short hashIndex; // sizeof 02h    offset 08h
    zCObject* hashNext;       // sizeof 04h    offset 0Ch
    zSTRING objectName;       // sizeof 14h    offset 10h

    void zCObject_OnInit()                                              zCall( 0x00401D60 );
    zCObject()                                                          zInit( zCObject_OnInit() );
    int Release()                                                       zCall( 0x0040C310 );
    zCObject* CreateCopy()                                              zCall( 0x005A90A0 );
    zSTRING const& GetObjectName() const                                zCall( 0x005A9CD0 );
    int SetObjectName( zSTRING const& )                                 zCall( 0x005A9CE0 );
    static int CheckInheritance( zCClassDef const*, zCClassDef const* ) zCall( 0x00476E30 );
    static int CheckInheritance( zCObject const*, zCObject const* )     zCall( 0x005A8E00 );
    static int CheckInheritance( zSTRING const&, zSTRING const& )       zCall( 0x005A8E40 );
    static zCObject* CreateNewInstance( zSTRING const& )                zCall( 0x005A8F70 );
    static void PrintClassHierarchy( int, zCClassDef*, int, int )       zCall( 0x005A9160 );
    static void GetMemStats( int&, int&, zCClassDef* )                  zCall( 0x005A9C60 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00401EC0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00401ED0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00401EE0 );
    virtual ~zCObject( void )                                           zCall( 0x005A8C50 );
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
    static zCObject* _CreateNewInstance()                  zCall( 0x005A8B00 );
    virtual zCClassDef* _GetClassDef( void ) const         zCall( 0x00426C80 );
    virtual ~zCObjectFactory( void )                       zCall( 0x00426CE0 );
    virtual zCEventManager* CreateEventManager( zCVob* )   zCall( 0x005AB9B0 );
    virtual zFILE* CreateZFile( zSTRING const& )           zCall( 0x005AB940 );
    virtual zCSession* CreateSession( void )               zCall( 0x005ABDD0 );
    virtual zCCSManager* CreateCSManager( void )           zCall( 0x005ABE30 );
    virtual zCNetVobControl* CreateNetVobControl( zCVob* ) zCall( 0x005ABB30 );
    virtual zCGameInfo* CreateGameInfo( void )             zCall( 0x00426C90 );
    virtual zCPlayerInfo* CreatePlayerInfo( void )         zCall( 0x00426CA0 );
    virtual zCWorld* CreateWorld( void )                   zCall( 0x005ABEF0 );
    virtual zCWaypoint* CreateWaypoint( void )             zCall( 0x005ABC00 );
    virtual zCWay* CreateWay( void )                       zCall( 0x005ABD70 );

    // user API
    #include "zCObjectFactory.inl"
  };

  
} // namespace Gothic_II_Addon

#endif // __ZOBJECT_H__VER3__