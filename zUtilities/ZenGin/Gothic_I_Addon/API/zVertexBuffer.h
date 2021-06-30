// Supported with union (c) 2018 Union team

#ifndef __ZVERTEX_BUFFER_H__VER1__
#define __ZVERTEX_BUFFER_H__VER1__

namespace Gothic_I_Addon {

  enum zTVBufferPrimitiveType {
    zVBUFFER_PT_TRIANGLELIST,
    zVBUFFER_PT_TRIANGLESTRIP,
    zVBUFFER_PT_TRIANGLEFAN,
    zVBUFFER_PT_POINTLIST,
    zVBUFFER_PT_LINELIST,
    zVBUFFER_PT_LINESTRIP
  };

  enum zTVBufferCreateFlags {
    zVBUFFER_CREATE_FLAG_DONOTCLIP    = 1,
    zVBUFFER_CREATE_FLAG_OPTIMIZED    = 2,
    zVBUFFER_CREATE_FLAG_SYSTEMMEMORY = 4,
    zVBUFFER_CREATE_FLAG_WRITEONLY    = 8
  };

  enum zTVBufferLockFlags {
    zVBUFFER_LOCK_FLAG_READONLY         = 1,
    zVBUFFER_LOCK_FLAG_SURFACEMEMORYPTR = 2,
    zVBUFFER_LOCK_FLAG_WAIT             = 4,
    zVBUFFER_LOCK_FLAG_WRITEONLY        = 8,
    zVBUFFER_LOCK_FLAG_DISCARDCONTENTS  = 16,
    zVBUFFER_LOCK_FLAG_NOOVERWRITE      = 32,
    zVBUFFER_LOCK_FLAG_NOSYSLOCK        = 64
  };

  enum zTVBufferVertexFormat {
    zVBUFFER_VERTFORMAT_XYZ    = 1,
    zVBUFFER_VERTFORMAT_XYZRHW = 2,
    zVBUFFER_VERTFORMAT_NORMAL = 4,
    zVBUFFER_VERTFORMAT_COLOR  = 8,
    zVBUFFER_VERTFORMAT_TEXUV1 = 16,
    zVBUFFER_VERTFORMAT_TEXUV2 = 32,
    zVBUFFER_VERTFORMAT_TEXUV3 = 64,
    zVBUFFER_VERTFORMAT_TEXUV4 = 128
  };

  enum zTVBufferVertexType {
    zVBUFFER_VERTTYPE_UT_UL,
    zVBUFFER_VERTTYPE_UT_L,
    zVBUFFER_VERTTYPE_T_L
  };

  class zCVertexBuffer : public zCObject {
  public:
    zCLASS_DECLARATION( zCVertexBuffer )

    struct zCVertexBufferDummy0 {
      unsigned char* basePtr;
      zVEC3* XYZPtr;
      zVEC4* XYZRHWPtr;
      zVEC3* normalPtr;
      zCOLOR* colorPtr;
      union {
        group {
          zVEC2* texUV0Ptr;
          zVEC2* texUV1Ptr;
          zVEC2* texUV2Ptr;
          zVEC2* texUV3Ptr;
        };
      };
    };

    struct zTCallbackData {
      void* recreateLostVBCallback;
      void* recreateLostVBCallbackData;

      zTCallbackData() {}

      // user API
      #include "zCVertexBuffer_zTCallbackData.inl"
    };

    unsigned long numVertex;
    unsigned long arrayStride;
    zCVertexBufferDummy0 array;
    int numVertsFilled;
    unsigned long createFlags;
    zCArray<zTCallbackData> callbackList;
    unsigned long vertexBufferID;

    void zCVertexBuffer_OnInit()                                                          zCall( 0x005EFD90 );
    zCVertexBuffer()                                                                      zInit( zCVertexBuffer_OnInit() );
    void AddRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* )    zCall( 0x005F0050 );
    void RemoveRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* ) zCall( 0x005F0190 );
    int CallRecreateLostVBCallbacks()                                                     zCall( 0x005F01F0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x005EFEC0 );
    virtual ~zCVertexBuffer()                                                             zCall( 0x005EFFE0 );
    virtual int Create( unsigned long, unsigned long, unsigned long )                     zCall( 0x005EFED0 );
    virtual int Destroy()                                                                 zCall( 0x005EFEE0 );
    virtual int Lock( unsigned long )                                                     zCall( 0x005EFEF0 );
    virtual int Unlock()                                                                  zCall( 0x005EFF00 );
    virtual int IsLocked()                                                                zCall( 0x005EFF10 );
    virtual int Optimize()                                                                zCall( 0x005EFF20 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )                                zCall( 0x005EFF30 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                                     zCall( 0x005EFF40 );
    virtual unsigned long GetVertexFormat()                                               zCall( 0x005EFF50 );
    virtual zTVBufferVertexType GetVertexType()                                           zCall( 0x005EFF60 );
    virtual int SetIndexList( zCArray<unsigned short> const& )                            zCall( 0x005EFF70 );
    virtual int SetIndexListSize( unsigned long )                                         zCall( 0x005EFF80 );
    virtual unsigned long GetIndexListSize()                                              zCall( 0x005EFF90 );
    virtual unsigned short* GetIndexListPtr()                                             zCall( 0x005EFFA0 );


    // static properties
    static unsigned long& s_classCtorCtr;

    // user API
    #include "zCVertexBuffer.inl"
  };

  class zCVertexBufferDyn {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;
    unsigned long vertexFormat;
    unsigned long numVert;
    unsigned long vertexSizeBytes;
    unsigned long currentPos;
    int locked;
    int flush;

    zCVertexBufferDyn() {}
    void zCVertexBufferDyn_OnInit( unsigned long, unsigned long ) zCall( 0x005F0310 );
    zCVertexBufferDyn( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn_OnInit( a0, a1 ));
    ~zCVertexBufferDyn()                                          zCall( 0x005F0360 );
    void* Lock( unsigned long, unsigned long& )                   zCall( 0x005F03A0 );
    void Unlock()                                                 zCall( 0x005F04F0 );

    // user API
    #include "zCVertexBufferDyn.inl"
  };

  class zCVertexBufferDyn2 {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;
    unsigned long vertexFormat;
    unsigned long numVert;
    unsigned long vertexSizeBytes;
    unsigned long currentPos;
    int locked;
    int flush;

    zCVertexBufferDyn2() {}
    void zCVertexBufferDyn2_OnInit( unsigned long, unsigned long ) zCall( 0x005F0510 );
    zCVertexBufferDyn2( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn2_OnInit( a0, a1 ));
    ~zCVertexBufferDyn2()                                          zCall( 0x005F0560 );
    void ReserveVerts( unsigned long )                             zCall( 0x005F05B0 );
    void* Lock( unsigned long& )                                   zCall( 0x005F05D0 );
    void Unlock( unsigned long )                                   zCall( 0x005F0630 );

    // user API
    #include "zCVertexBufferDyn2.inl"
  };

  class zCVertexBufferManager {
  public:
    zCArray<zCVertexBuffer*> openVBList;
    zCArray<zCVertexBuffer*> closedVBList;
    int changeWorldHintSet;

    void zCVertexBufferManager_OnInit()                                                                     zCall( 0x005F0690 );
    zCVertexBufferManager()                                                                                 zInit( zCVertexBufferManager_OnInit() );
    ~zCVertexBufferManager()                                                                                zCall( 0x005F06C0 );
    zCVertexBuffer* AcquireVertexBuffer( unsigned long, unsigned long, unsigned long, unsigned long, int& ) zCall( 0x005F0720 );
    int ReleaseVertexBuffer( zCVertexBuffer* )                                                              zCall( 0x005F0960 );
    void UnlockOpenVertexBuffers()                                                                          zCall( 0x005F0A40 );
    void StartChangeWorld()                                                                                 zCall( 0x005F0C10 );
    void EndChangeWorld()                                                                                   zCall( 0x005F0C20 );

    // user API
    #include "zCVertexBufferManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVERTEX_BUFFER_H__VER1__