// Supported with union (c) 2018 Union team

#ifndef __ZOBJECT_H__VER2__
#define __ZOBJECT_H__VER2__

namespace Gothic_II_Classic {

  enum zTClassFlags {
    zCLASS_FLAG_SHARED_OBJECTS = 1 << 0,
    zCLASS_FLAG_TRANSIENT      = 1 << 1,
    zCLASS_FLAG_RESOURCE       = 1 << 2
  };

  class zCLivingObjectsState {
  public:
    zCArray<int> numList;

    zCLivingObjectsState() {}

    // user API
    #include "zCLivingObjectsState.inl"
  };

  class zCClassDef {
  public:
    zSTRING className;
    zSTRING baseClassName;
    zSTRING scriptClassName;
    zCClassDef* baseClassDef;
    zCObject*( *createNewInstance )( void );
    zCObject*( *createNewInstanceBackup )( void );
    unsigned long classFlags;
    unsigned long classSize;
    int numLivingObjects;
    int numCtorCalled;
    zCObject** hashTable;
    zCArray<zCObject*> objectList;
    unsigned short archiveVersion;
    unsigned short archiveVersionSum;

    void zCClassDef_OnInit()                                                                                                                                 zCall( 0x005A4D80 );
    void zCClassDef_OnInit( zSTRING const&, zSTRING const&, zCObject*( __cdecl* )(), unsigned long, unsigned long, unsigned short, zSTRING const& )          zCall( 0x005A5380 );
    zCClassDef()                                                                                                                                             zInit( zCClassDef_OnInit() );
    void Init()                                                                                                                                              zCall( 0x005A4F10 );
    ~zCClassDef()                                                                                                                                            zCall( 0x005A50C0 );
    zCClassDef( zSTRING const& a0, zSTRING const& a1, zCObject*( __cdecl* a2 )(), unsigned long a3, unsigned long a4, unsigned short a5, zSTRING const& a6 ) zInit( zCClassDef_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    zCObject* CreateNewInstance() const                                                                                                                      zCall( 0x005A5620 );
    void OverwriteCreateNewInstance( zCClassDef* )                                                                                                           zCall( 0x005A56E0 );
    void ResetCreateNewInstance()                                                                                                                            zCall( 0x005A5700 );
    unsigned short GetClassID()                                                                                                                              zCall( 0x005A5710 );
    unsigned long GetHashIndex( zSTRING const& )                                                                                                             zCall( 0x005A57A0 );
    unsigned long GetHashIndex( zCObject* )                                                                                                                  zCall( 0x005A57D0 );
    void InsertHashTable( zCObject* )                                                                                                                        zCall( 0x005A5800 );
    void RemoveHashTable( zCObject* )                                                                                                                        zCall( 0x005A5840 );
    zCObject* SearchHashTable( zSTRING const& )                                                                                                              zCall( 0x005A5880 );
    float CalcHashTableSpread()                                                                                                                              zCall( 0x005A5910 );
    void ReportLeaks()                                                                                                                                       zCall( 0x005A5C10 );
    static int CompareClassDefNames( void const*, void const* )                                                                                              zCall( 0x005A4A20 );
    static zCClassDef* GetClassDef( zSTRING const& )                                                                                                         zCall( 0x005A4A80 );
    static zCClassDef* GetClassDefTypeInsensitive( zSTRING const& )                                                                                          zCall( 0x005A4BA0 );
    static void EndStartup()                                                                                                                                 zCall( 0x005A5240 );
    static zCObject* CreateNewInstanceID( unsigned short )                                                                                                   zCall( 0x005A5780 );
    static void ObjectCreated( zCObject*, zCClassDef* )                                                                                                      zCall( 0x005A5950 );
    static void ObjectDeleted( zCObject*, zCClassDef* )                                                                                                      zCall( 0x005A5A70 );
    static void ObjectCreated( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x005A5B10 );
    static void ObjectDeleted( zCObject*, int, zCClassDef* )                                                                                                 zCall( 0x005A5B50 );
    static void GetLivingObjectsState( zCLivingObjectsState& )                                                                                               zCall( 0x005A6030 );
    static void CompareLivingObjectsState( zCLivingObjectsState const& )                                                                                     zCall( 0x005A60D0 );
    static void ObjectCreated( zCObject*, zCClassDef*, char const*, int )                                                                                    zCall( 0x007A71A0 );

    // static properties
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

  class zCObject {
  public:
    zCLASS_DECLARATION( zCObject )

    int refCtr;
    unsigned short hashIndex;
    zCObject* hashNext;
    zSTRING objectName;

    void zCObject_OnInit()                                              zCall( 0x00401D60 );
    zCObject()                                                          zInit( zCObject_OnInit() );
    int Release()                                                       zCall( 0x0040C310 );
    zCObject* CreateCopy()                                              zCall( 0x005A3B40 );
    zSTRING const& GetObjectName() const                                zCall( 0x005A4770 );
    int SetObjectName( zSTRING const& )                                 zCall( 0x005A4780 );
    static int CheckInheritance( zCClassDef const*, zCClassDef const* ) zCall( 0x00475A90 );
    static int CheckInheritance( zCObject const*, zCObject const* )     zCall( 0x005A38A0 );
    static int CheckInheritance( zSTRING const&, zSTRING const& )       zCall( 0x005A38E0 );
    static zCObject* CreateNewInstance( zSTRING const& )                zCall( 0x005A3A10 );
    static void PrintClassHierarchy( int, zCClassDef*, int, int )       zCall( 0x005A3C00 );
    static void GetMemStats( int&, int&, zCClassDef* )                  zCall( 0x005A4700 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00401EC0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00401ED0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00401EE0 );
    virtual ~zCObject()                                                 zCall( 0x005A36F0 );
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

  class zCObjectFactory : public zCObject {
  public:
    zCLASS_DECLARATION( zCObjectFactory )

    zCObjectFactory() {}
    static zCObject* _CreateNewInstance()                  zCall( 0x005A35A0 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x00426940 );
    virtual ~zCObjectFactory()                             zCall( 0x004269A0 );
    virtual zCEventManager* CreateEventManager( zCVob* )   zCall( 0x005A6450 );
    virtual zFILE* CreateZFile( zSTRING const& )           zCall( 0x005A63E0 );
    virtual zCSession* CreateSession()                     zCall( 0x005A6870 );
    virtual zCCSManager* CreateCSManager()                 zCall( 0x005A68D0 );
    virtual zCNetVobControl* CreateNetVobControl( zCVob* ) zCall( 0x005A65D0 );
    virtual zCGameInfo* CreateGameInfo()                   zCall( 0x00426950 );
    virtual zCPlayerInfo* CreatePlayerInfo()               zCall( 0x00426960 );
    virtual zCWorld* CreateWorld()                         zCall( 0x005A6990 );
    virtual zCWaypoint* CreateWaypoint()                   zCall( 0x005A66A0 );
    virtual zCWay* CreateWay()                             zCall( 0x005A6810 );

    // user API
    #include "zCObjectFactory.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZOBJECT_H__VER2__