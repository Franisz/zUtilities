#pragma once

namespace SystemPack {
  typedef CArrayOld<CPatchType*> TParameters;

  class ASTAPI CPatchFunction : public CPatchSymbol {
  protected:
    TParameters arrParameters;
  public:
    void PushParameter( CPatchType* sym );
    void CreateParameters( const CString& line );
    ~CPatchFunction();

    virtual CPatchType* Execute() = 0;
  };
}

#include "BaseFunctions\BaseFunctions.h"