// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_FILE_H__
#define __PATCH_FILE_H__

#include "Filters\Filters.h"
#include "MemPage\CMemPage.h"
#include "Symbol\CPatchSymbol.h"
#include "Stack\CPatchStack.h"
#include "Region\CPatchRegion.h"

namespace SystemPack {
  class ASTAPI CPatchFile {
    CString   sFileName;
    CDocument sFileData;
  protected:
    CPatchFile( const CString& fileName );
  public:
    CPatchRegion* CreateEngineBlock( const uint32& hash );
    void CloseFile();
    static CPatchFile* LoadFile( const CString& fileName );
  };

  class ASTAPI CPatch {
    CString sName;

    static CArrayOld<CPatch*> arrPatches;
  public:
    CPatch( const CString& name );
    void Execute();
    static void ExecuteResource( HMODULE module, LPCSTR resourceName, LPCSTR type );
    static void ExecuteAll();
    static bool32 HasPatch( const char* name );
  };
}


// force path execute
// from c++ source file
#define PATCH_EXECUTE( p )                                                            \
{                                                                                     \
  string source = A "#engine\n#patch\n" + #p + "\n#/patch\n#/engine";                 \
  CDocument doc = source.Replace( "; ", "\n" );                                       \
  SystemPack::CPatchRegion* region = SystemPack::CPatchRegion::DefineBlock( doc, 0 ); \
  region->ExecuteRegion();                                                            \
  delete region;                                                                      \
}

#endif // __PATCH_FILE_H__