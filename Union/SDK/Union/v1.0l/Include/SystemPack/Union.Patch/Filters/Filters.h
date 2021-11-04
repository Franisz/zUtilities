// Supported with union (c) 2018-2021 Union team

#ifndef __PATCH_FILTERS_H__
#define __PATCH_FILTERS_H__

namespace SystemPack {
  extern ASTAPI const CString sDefaultSpace;

  extern ASTAPI const CString sResource_Local;
  extern ASTAPI const CString sResource_Option;
  extern ASTAPI const CString sResource_Number;
  extern ASTAPI const CString sResource_Operator;

  extern ASTAPI const CString sNumber_Integer;
  extern ASTAPI const CString sNumber_PureHex;
  extern ASTAPI const CString sNumber_Float;
  extern ASTAPI const CString sNumber_LineHex;

  extern ASTAPI const CString sBrackets_Round   [2];
  extern ASTAPI const CString sBrackets_Square  [2];
  extern ASTAPI const CString sBrackets_TextLine[2];
  extern ASTAPI const CString sBrackets_HexLine [2];
  extern ASTAPI const CString sBrackets_Comment [2];

  extern ASTAPI const CString sAssociation_Quote     [2];
  extern ASTAPI const CString sAssociation_EndLine   [2];
  extern ASTAPI const CString sAssociation_Tabulation[2];

  const uint32 ulResourceNum    = 24;
  const uint32 ulNumberNum      = 4;
  const uint32 ulBracketsNum    = 5;
  const uint32 ulAssociationNum = 3;

  extern ASTAPI const CString arrResource    [ulResourceNum];
  extern ASTAPI const CString arrNumber      [ulNumberNum];
  extern ASTAPI const CString* arrBrackets   [ulBracketsNum];
  extern ASTAPI const CString* arrAssociation[ulAssociationNum];

  const uint32 ulOperatorNum = 21;

  extern ASTAPI const CString sEngineBlock[2];
  extern ASTAPI const CString sPatchBlock [2];
  extern ASTAPI const CString sOperators  [ulOperatorNum];
}

#endif // __PATCH_FILTERS_H__