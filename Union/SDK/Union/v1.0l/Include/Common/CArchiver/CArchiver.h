// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_ARCHIVER_H__
#define __UNION_ARCHIVER_H__

namespace Common {

  enum
  {
    ARC_NONE  = 0,
    ARC_READ  = 1,
    ARC_WRITE = 2
  };

  typedef uint32 OMODE;

  typedef struct _tagInf
  {
    char data[32];

    _tagInf() {
      ZeroMemory( data, sizeof( data ) );
    };

    void operator = ( const char * vec ) {
      memcpy( data, vec, 32 );
    };

    operator char* ( ) {
      return data;
    };

  } TName, TDesc, TInfo;

  typedef struct _tagOfile
  {
    uint32 ulHandler;

    template <typename T>
    operator T& ( ) {
      return (T&)ulHandler;
    };

    template <typename T>
    _tagOfile& operator = ( T hf ) {
      ulHandler = (uint32&)hf;
      return *this;
    };

    operator bool() {
      return ulHandler != 0;
    };

  } OFILE;

  class ASTAPI CArchiver
  {
    OFILE oFile;
    OMODE oMode;

  public:

    CArchiver();

    bool Open( const CString&, const uint32& );
    virtual void Close();

    virtual bool Read( void32, const uint32& );
    virtual CObject* ReadClass();
    virtual bool ReadString( CString& );
    virtual bool ReadArray( CArrayBase& arr );
    virtual void Write( void32, const uint32& );
    virtual void WriteClass( CObject* );
    virtual void WriteString( CString& );
    virtual void WriteArray( CArrayBase& arr );

    template <typename T>
    bool Read( T& arg ) {
      return Read( &arg, sizeof( T ) );
    };

    template <typename T>
    void Write( T& arg ) {
      Write( &arg, sizeof( T ) );
    };

    static bool Save( const CString& );
    static bool Load( const CString& );

    ~CArchiver();
  };
} // namespace Common

#endif // __UNION_ARCHIVER_H__