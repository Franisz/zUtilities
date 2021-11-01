// Supported with union (c) 2018-2021 Union team

#ifndef __ZVERTEX_BUFFER_H__VER0__
#define __ZVERTEX_BUFFER_H__VER0__

namespace Gothic_I_Classic {

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

  // sizeof 68h
  class zCVertexBuffer : public zCObject {
  public:
    zCLASS_DECLARATION( zCVertexBuffer )

    // sizeof 24h
    struct zCVertexBufferDummy0 {
      unsigned char* basePtr; // sizeof 04h    offset 00h
      zVEC3* XYZPtr;          // sizeof 04h    offset 04h
      zVEC4* XYZRHWPtr;       // sizeof 04h    offset 08h
      zVEC3* normalPtr;       // sizeof 04h    offset 0Ch
      zCOLOR* colorPtr;       // sizeof 04h    offset 10h
      union {
        group {
          zVEC2* texUV0Ptr;   // sizeof 04h    offset 14h
          zVEC2* texUV1Ptr;   // sizeof 04h    offset 18h
          zVEC2* texUV2Ptr;   // sizeof 04h    offset 1Ch
          zVEC2* texUV3Ptr;   // sizeof 04h    offset 20h
        };
      };
    };

    // sizeof 08h
    struct zTCallbackData {
      void* recreateLostVBCallback;     // sizeof 04h    offset 00h
      void* recreateLostVBCallbackData; // sizeof 04h    offset 04h

      zTCallbackData() {}

      // user API
      #include "zCVertexBuffer_zTCallbackData.inl"
    };

    unsigned long numVertex;              // sizeof 04h    offset 24h
    unsigned long arrayStride;            // sizeof 04h    offset 28h
    zCVertexBufferDummy0 array;           // sizeof 24h    offset 2Ch
    int numVertsFilled;                   // sizeof 04h    offset 50h
    unsigned long createFlags;            // sizeof 04h    offset 54h
    zCArray<zTCallbackData> callbackList; // sizeof 0Ch    offset 58h
    unsigned long vertexBufferID;         // sizeof 04h    offset 64h

    void zCVertexBuffer_OnInit()                                                          zCall( 0x005D0C40 );
    zCVertexBuffer()                                                                      zInit( zCVertexBuffer_OnInit() );
    void AddRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* )    zCall( 0x005D0EF0 );
    void RemoveRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* ) zCall( 0x005D1020 );
    int CallRecreateLostVBCallbacks()                                                     zCall( 0x005D1080 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x005D0D60 );
    virtual ~zCVertexBuffer()                                                             zCall( 0x005D0E80 );
    virtual int Create( unsigned long, unsigned long, unsigned long )                     zCall( 0x005D0D70 );
    virtual int Destroy()                                                                 zCall( 0x005D0D80 );
    virtual int Lock( unsigned long )                                                     zCall( 0x005D0D90 );
    virtual int Unlock()                                                                  zCall( 0x005D0DA0 );
    virtual int IsLocked()                                                                zCall( 0x005D0DB0 );
    virtual int Optimize()                                                                zCall( 0x005D0DC0 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )                                zCall( 0x005D0DD0 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                                     zCall( 0x005D0DE0 );
    virtual unsigned long GetVertexFormat()                                               zCall( 0x005D0DF0 );
    virtual zTVBufferVertexType GetVertexType()                                           zCall( 0x005D0E00 );
    virtual int SetIndexList( zCArray<unsigned short> const& )                            zCall( 0x005D0E10 );
    virtual int SetIndexListSize( unsigned long )                                         zCall( 0x005D0E20 );
    virtual unsigned long GetIndexListSize()                                              zCall( 0x005D0E30 );
    virtual unsigned short* GetIndexListPtr()                                             zCall( 0x005D0E40 );


    // static properties
    static unsigned long& s_classCtorCtr;

    // user API
    #include "zCVertexBuffer.inl"
  };

  // sizeof 1Ch
  class zCVertexBufferDyn {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;  // sizeof 04h    offset 00h
    unsigned long vertexFormat;    // sizeof 04h    offset 04h
    unsigned long numVert;         // sizeof 04h    offset 08h
    unsigned long vertexSizeBytes; // sizeof 04h    offset 0Ch
    unsigned long currentPos;      // sizeof 04h    offset 10h
    int locked;                    // sizeof 04h    offset 14h
    int flush;                     // sizeof 04h    offset 18h

    zCVertexBufferDyn() {}
    void zCVertexBufferDyn_OnInit( unsigned long, unsigned long ) zCall( 0x005D11A0 );
    zCVertexBufferDyn( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn_OnInit( a0, a1 ));
    ~zCVertexBufferDyn()                                          zCall( 0x005D11F0 );
    void* Lock( unsigned long, unsigned long& )                   zCall( 0x005D1230 );
    void Unlock()                                                 zCall( 0x005D1360 );

    // user API
    #include "zCVertexBufferDyn.inl"
  };

  // sizeof 1Ch
  class zCVertexBufferDyn2 {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;  // sizeof 04h    offset 00h
    unsigned long vertexFormat;    // sizeof 04h    offset 04h
    unsigned long numVert;         // sizeof 04h    offset 08h
    unsigned long vertexSizeBytes; // sizeof 04h    offset 0Ch
    unsigned long currentPos;      // sizeof 04h    offset 10h
    int locked;                    // sizeof 04h    offset 14h
    int flush;                     // sizeof 04h    offset 18h

    zCVertexBufferDyn2() {}
    void zCVertexBufferDyn2_OnInit( unsigned long, unsigned long ) zCall( 0x005D1380 );
    zCVertexBufferDyn2( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn2_OnInit( a0, a1 ));
    ~zCVertexBufferDyn2()                                          zCall( 0x005D13D0 );
    void ReserveVerts( unsigned long )                             zCall( 0x005D1420 );
    void* Lock( unsigned long& )                                   zCall( 0x005D1440 );
    void Unlock( unsigned long )                                   zCall( 0x005D14A0 );

    // user API
    #include "zCVertexBufferDyn2.inl"
  };

  // sizeof 1Ch
  class zCVertexBufferManager {
  public:
    zCArray<zCVertexBuffer*> openVBList;   // sizeof 0Ch    offset 00h
    zCArray<zCVertexBuffer*> closedVBList; // sizeof 0Ch    offset 0Ch
    int changeWorldHintSet;                // sizeof 04h    offset 18h

    void zCVertexBufferManager_OnInit()                                                                     zCall( 0x005D1500 );
    zCVertexBufferManager()                                                                                 zInit( zCVertexBufferManager_OnInit() );
    ~zCVertexBufferManager()                                                                                zCall( 0x005D1530 );
    zCVertexBuffer* AcquireVertexBuffer( unsigned long, unsigned long, unsigned long, unsigned long, int& ) zCall( 0x005D1590 );
    int ReleaseVertexBuffer( zCVertexBuffer* )                                                              zCall( 0x005D17D0 );
    void UnlockOpenVertexBuffers()                                                                          zCall( 0x005D1890 );
    void StartChangeWorld()                                                                                 zCall( 0x005D1A50 );
    void EndChangeWorld()                                                                                   zCall( 0x005D1A60 );

    // user API
    #include "zCVertexBufferManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVERTEX_BUFFER_H__VER0__