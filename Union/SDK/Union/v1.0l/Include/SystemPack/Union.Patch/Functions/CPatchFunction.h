// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_PATCH_FUNCTION_H__
#define __SYSTEMPACK_PATCH_FUNCTION_H__

namespace SystemPack
{
  typedef CArray<CPatchType*> TParameters;

  class ASTAPI CPatchFunction : public CPatchSymbol
  {
  protected:
    TParameters arrParameters;
  public:
    void  PushParameter( CPatchType* sym );
    void  CreateParameters( const CString& line );
    virtual CPatchType* Execute() = 0;
    ~CPatchFunction();
  };
} // namespace SystemPack

#include "BaseFunctions.h"

#endif // __SYSTEMPACK_PARSER_FILTERS_H__