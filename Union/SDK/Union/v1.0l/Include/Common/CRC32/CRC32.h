// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_CRC_32_H__
#define __UNION_CRC_32_H__

namespace Common
{
  struct ASTAPI CCRC32
  {
    struct TCRC32META
    {
      CStringA sFileName;
      uint32  ulFileSize;
      uint32  ulCRC32;
    } meta;

    static const uint32* InitCRC32_Table();
    void InitCRC32( CStringA sFileName );

  public:

    CCRC32( HMODULE  hModule );
    CCRC32( CStringA sFileName );
    const TCRC32META& GetCRC32() const;
  };

  typedef CCRC32::TCRC32META CRC32Meta;
} // namespace Common

#endif // __UNION_CRC_32_H__