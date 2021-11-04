// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_OPTION_H__
#define __UNION_OPTION_H__

namespace Common
{
  class ASTAPI COption
  {
    bool32 bIsInit;
    bool32 bIsPhysical;

  public:
    CDocumentA mDocument;
    CString  sConfigName;

    struct ASTAPI OptBlock
    {
      OptBlock( CString );
      CString sBlockName;
      struct OptValue
      {
        OptValue( CString, CString );
        CString sValueName;
        CString sValue;
      };
      CList <OptValue> lstValues;
    };
    CList <OptBlock> lstBlocks;

    typedef OptBlock   TBlock;
    typedef OptBlock::OptValue TValue;

    TBlock* AddBlock( CString );
    TValue* AddValue( TBlock*, CString, CString );
    void ChangeValue( CString, CString, CString );

  public:

    COption();
    COption(   CString, bool physical_only = false );
    void Init( CString, bool physical_only = false );
    void Exit();
    void SaveAll();

    bool32 IsInit();
    bool32 IsPhysicalOnly();
    bool32 IsExists( CString sec, CString val = NullStr );

    void32 GetValue( CString sec, CString val );
    void SetValue(   CString sec, CString val, HBuffer buf, uint32 size );

    void Write( const bool&,    CString sec, CString val );
    void Write( const byte&,    CString sec, CString val );
    void Write( const int32&,   CString sec, CString val );
    void Write( const real32&,  CString sec, CString val );
    void Write( const CString&, CString sec, CString val );

    void Read( bool&,    CString sec, CString val, bool    default = false );
    void Read( byte&,    CString sec, CString val, byte    default = 0 );
    void Read( int32&,   CString sec, CString val, int32   default = 0 );
    void Read( real32&,  CString sec, CString val, real32  default = 0.0f );
    void Read( CString&, CString sec, CString val, CString default = NullStr );

    ~COption();
  };
} // namespace Common

#endif // __UNION_OPTION_H__