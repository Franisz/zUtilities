// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_VDFS_H__
#define __UNION_VDFS_H__

namespace Vdfs32 {
#define VDF_VIRTUAL       (1)
#define VDF_PHYSICAL      (2)
#define VDF_PHYSICALFIRST (4)
#define VDF_DEFAULT VDF_VIRTUAL | VDF_PHYSICAL


  // open file and return handle
  VDFAPI long32 vdf_fopen( text fullfname, long32 flags );


  // close file
  VDFAPI long32 vdf_fclose( long32 handle );


  // read file to the buffer. return the real readed size in bytes
  VDFAPI long32 vdf_fread( long32 handle, HBuffer buffer, long32 size );


  // move the reading cursor to specified position
  VDFAPI long32 vdf_fseek( long32 handle, long32 pos );


  // get the reading cursor
  VDFAPI long32 vdf_ftell( long32 handle );


  // check the file by full name. flags - is prefer file mode - physical 
  // or virtual. if choose both, system will return the highest-priority 
  // flag of the file. or Null if file does not exists.
  VDFAPI long32 vdf_fexists( text fullfname, long32 flags );


  // finds files by relative path. second argument - the
  // found fullname if return value is not false.
  VDFAPI long32 vdf_searchfile( text filename, text fullfilename );


  // return size of file
  VDFAPI long32 vdf_ffilesize( long32 handle );


  // for union vdfs this parms unused
  VDFAPI long32 vdf_initall( long32 numdisks = None, text cdid = None, long32* cddrives = None, long32* disksfound = None );


  // collects a physical files list and returns their count
  VDFAPI long32 vdf_filelist_physical( char**& list );


  // collects a virtual files list and returns their count
  VDFAPI long32 vdf_filelist_virtual( char**& list );


  //
  ASTAPI long32 vdf_regvol( const char* volname );


  // collects a physical files list and returns their count
  VDFAPI long32 vdf_filelist_physical( char**& list );


  // collects a virtual files list and returns their count
  VDFAPI long32 vdf_filelist_virtual( char**& list );


  // get last system error in VDFS
  VDFAPI long32 vdf_getlasterror( char* error );


  // get FILE handler of virtual stream
  VDFAPI long32 vdf_getfilehandle( long32 handle, long32& offset );


  // async copy full ogg data in memory
  VDFAPI long32 vdf_unpackogg( char* fullname, long32 flags );


  // clear ogg data from memory
  VDFAPI long32 vdf_packogg( char* fullname, long32 flags );


  // import vdf volume
  VDFAPI long32 vdf_import(char* volname);


  // set allow unzip multi-threading
  VDFAPI long32 vdf_set_unzip_multithreading(long32 allow);


  // update physical file list
  VDFAPI long32 vdf_updatephysicaltable();


  class VirtualFile {
    long Handler;
    long Flow;
    CStringA Name;

  public:
    VirtualFile();
    VirtualFile( const CStringA& name, const long& flow = VDF_DEFAULT, const uint& index = 0 );
    bool Open( const CStringA name, const long& flow = VDF_DEFAULT, const uint& index = 0 );

  public:
    long Read( char* buff, const long& length );
    long ReadToEnd( char* buff );

    template <class T>
    long Read( T buff, const long& length ) {
      return Read( (char*)buff, length );
    }

    template <class T>
    long ReadToEnd( T& buff ) {
      return ReadToEnd( (char*&)buff );
    }

    long ReadString( CStringA& str );
    long Size();
    long Tell();
    void Seek( const long& pos );
    bool IsVirtual();
    bool IsExists();
    void Close();
    operator bool();
    virtual ~VirtualFile();
  };

  inline VirtualFile::VirtualFile() {
    Handler = Invalid;
  }

  inline VirtualFile::VirtualFile( const CStringA& name, const long& flow, const uint& index ) {
    Handler = Invalid;
    Open( name, flow, index );
  }

  inline bool VirtualFile::Open( CStringA name, const long& flow, const uint& index ) {
    if( index > 0 ) {
      char NameBuffer[1024];
      if( !vdf_searchfile( name.ToChar(), NameBuffer ) )
        return false;

      CStringA Names = NameBuffer;
      Name = Names.GetWord( "|", index );
      if( Name.IsEmpty() )
        return false;

      Flow = vdf_fexists( Name.ToChar(), flow );
      Handler = vdf_fopen( Name.ToChar(), Flow );
    }
    else {
      Name = name;
      Flow = vdf_fexists( Name.ToChar(), flow );
      if( Flow == 0 )
        return false;

      Handler = vdf_fopen( Name.ToChar(), Flow );
    }

    return true;
  }

  inline long VirtualFile::Read( char* buff, const long& length ) {
    return vdf_fread( Handler, buff, length );
  }

  inline long VirtualFile::ReadToEnd( char* buff ) {
    long tell = Tell();
    long size = Size();
    Seek( 0 );
    long readed = vdf_fread( Handler, buff, size );
    Seek( tell );
    return readed;
  }

  inline long VirtualFile::ReadString( CStringA& str ) {
    long tell = Tell();
    long size = Size();
    Seek( 0 );
    char* buff = new char[size];
    long readed = vdf_fread( Handler, buff, size );
    str = CStringA( buff, readed );
    delete [] buff;
    Seek( tell );
    return readed;
  }

  inline long VirtualFile::Size() {
    return vdf_ffilesize( Handler );
  }

  inline long VirtualFile::Tell() {
    return vdf_ftell( Handler );
  }

  inline void VirtualFile::Seek( const long& pos ) {
    vdf_fseek( Handler, pos );
  }

  inline bool VirtualFile::IsVirtual() {
    if( Flow & VDF_PHYSICALFIRST )
      return (Flow & VDF_PHYSICAL) == 0;

    return Flow & VDF_VIRTUAL;
  }

  inline bool VirtualFile::IsExists() {
    return Handler != Invalid;
  }

  inline void VirtualFile::Close() {
    if( Handler != Invalid ) {
      vdf_fclose( Handler );
      Handler = Invalid;
    }
  }

  inline VirtualFile::operator bool() {
    return IsExists();
  }

  inline VirtualFile::~VirtualFile() {
    Close();
  }
}

#endif // __UNION_VDFS_H__