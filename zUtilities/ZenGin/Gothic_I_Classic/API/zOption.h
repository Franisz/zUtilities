// Supported with union (c) 2018-2021 Union team

#ifndef __ZOPTION_H__VER0__
#define __ZOPTION_H__VER0__

namespace Gothic_I_Classic {

  enum zTOptionPaths {
    DIR_SYSTEM,
    DIR_WEB,
    DIR_SAVEGAMES,
    DIR_DATA,
    DIR_ANIMS,
    DIR_CUTSCENES,
    DIR_MESHES,
    DIR_SCRIPTS,
    DIR_SOUND,
    DIR_VIDEO,
    DIR_MUSIC,
    DIR_TEX,
    DIR_TEX_DESKTOP,
    DIR_WORLD,
    DIR_PRESETS,
    DIR_TOOLS_DATA,
    DIR_COMPILED_ANIMS,
    DIR_COMPILED_MESHES,
    DIR_COMPILED_SCRIPTS,
    DIR_COMPILED_TEXTURES,
    DIR_TOOLS_CONFIG,
    SUBDIR_INTERN,
    NUM_PATHS,
    DIR_ROOT,
    DIR_EXECUTABLE,
    NUM_ENTRIES
  };

  // sizeof 50h
  class zCOptionEntry {
  public:
    int changed;                                  // sizeof 04h    offset 00h
    zCArray<bool32(*)( zCOptionEntry& )> ccbList; // sizeof 0Ch    offset 04h
    zSTRING varName;                              // sizeof 14h    offset 10h
    zSTRING varValue;                             // sizeof 14h    offset 24h
    zSTRING varValueTemp;                         // sizeof 14h    offset 38h
    int varFlag;                                  // sizeof 04h    offset 4Ch

    zCOptionEntry() {}
    void zCOptionEntry_OnInit( zSTRING const&, zSTRING const& ) zCall( 0x0045A880 );
    zCOptionEntry( zSTRING const& a0, zSTRING const& a1 )       zInit( zCOptionEntry_OnInit( a0, a1 ));
    ~zCOptionEntry()                                            zCall( 0x0045B180 );

    // user API
    #include "zCOptionEntry.inl"
  };

  // sizeof 20h
  class zCOptionSection {
  public:
    zSTRING secName;                   // sizeof 14h    offset 00h
    zCArray<zCOptionEntry*> entryList; // sizeof 0Ch    offset 14h

    zCOptionSection() {}
    void zCOptionSection_OnInit( zSTRING const& ) zCall( 0x0045AB00 );
    zCOptionSection( zSTRING const& a0 )          zInit( zCOptionSection_OnInit( a0 ));
    ~zCOptionSection()                            zCall( 0x0045ACC0 );

    // user API
    #include "zCOptionSection.inl"
  };

  // sizeof 280h
  class zCOption {
  public:
    int m_bReadTemp;                       // sizeof 04h    offset 04h
    zCArray<zCOptionSection*> sectionList; // sizeof 0Ch    offset 08h
    zFILE*( directory )[NUM_ENTRIES];      // sizeof 64h    offset 14h
    zSTRING dir_string[NUM_ENTRIES];       // sizeof 1F4h   offset 78h
    zSTRING commandline;                   // sizeof 14h    offset 26Ch

    void zCOption_OnInit()                                                                    zCall( 0x0045ADD0 );
    zCOption()                                                                                zInit( zCOption_OnInit() );
    int Load( zSTRING )                                                                       zCall( 0x0045B240 );
    int Save( zSTRING )                                                                       zCall( 0x0045C1E0 );
    int WriteBool( zSTRING const&, char const*, int, int )                                    zCall( 0x0045C900 );
    int WriteInt( zSTRING const&, char const*, int, int )                                     zCall( 0x0045C950 );
    int WriteDWord( zSTRING const&, char const*, unsigned long, int )                         zCall( 0x0045C980 );
    int WriteReal( zSTRING const&, char const*, float, int )                                  zCall( 0x0045C9B0 );
    int WriteString( zSTRING const&, char const*, zSTRING, int )                              zCall( 0x0045C9F0 );
    int ReadBool( zSTRING const&, char const*, int )                                          zCall( 0x0045CB80 );
    int ReadInt( zSTRING const&, char const*, int )                                           zCall( 0x0045CDB0 );
    unsigned long ReadDWord( zSTRING const&, char const*, unsigned long )                     zCall( 0x0045CEA0 );
    float ReadReal( zSTRING const&, char const*, float )                                      zCall( 0x0045CF90 );
    zSTRING ReadString( zSTRING const&, char const*, char const* )                            zCall( 0x0045D080 );
    int EntryExists( zSTRING const&, char const* )                                            zCall( 0x0045D1F0 );
    unsigned short GetNumEntries( zCOptionSection* )                                          zCall( 0x0045D2C0 );
    zCOptionEntry* GetEntry( zCOptionSection*, int )                                          zCall( 0x0045D2E0 );
    int RemoveEntry( zSTRING const&, char const* )                                            zCall( 0x0045D310 );
    void SetFlag( zSTRING const&, char const*, int )                                          zCall( 0x0045D4B0 );
    zCOptionEntry* GetEntryByName( zCOptionSection*, zSTRING const&, int )                    zCall( 0x0045D5B0 );
    zCOptionSection* GetSectionByName( zSTRING const&, int )                                  zCall( 0x0045D8D0 );
    int SectionExists( zSTRING const& )                                                       zCall( 0x0045DB30 );
    unsigned short GetNumSections()                                                           zCall( 0x0045DB50 );
    zCOptionSection* GetSection( int )                                                        zCall( 0x0045DB60 );
    int RemoveSection( zSTRING const& )                                                       zCall( 0x0045DB90 );
    void InsertChangeHandler( zSTRING const&, char const*, int( __cdecl* )( zCOptionEntry& )) zCall( 0x0045DBF0 );
    int WriteRaw( zSTRING const&, char const*, void*, int, int )                              zCall( 0x0045DDE0 );
    int ReadRaw( zSTRING const&, char const*, void*&, void*, int )                            zCall( 0x0045DFC0 );
    int WriteBool( zSTRING const&, zSTRING const&, int, int )                                 zCall( 0x0045E1B0 );
    int WriteInt( zSTRING const&, zSTRING const&, int, int )                                  zCall( 0x0045E1D0 );
    int WriteDWord( zSTRING const&, zSTRING const&, unsigned long, int )                      zCall( 0x0045E1F0 );
    int WriteReal( zSTRING const&, zSTRING const&, float, int )                               zCall( 0x0045E210 );
    int WriteString( zSTRING const&, zSTRING const&, zSTRING, int )                           zCall( 0x0045E240 );
    int WriteRaw( zSTRING const&, zSTRING const&, void*, int, int )                           zCall( 0x0045E2F0 );
    int ReadBool( zSTRING const&, zSTRING const&, int )                                       zCall( 0x0045E310 );
    int ReadInt( zSTRING const&, zSTRING const&, int )                                        zCall( 0x0045E330 );
    unsigned long ReadDWord( zSTRING const&, zSTRING const&, unsigned long )                  zCall( 0x0045E350 );
    float ReadReal( zSTRING const&, zSTRING const&, float )                                   zCall( 0x0045E370 );
    zSTRING ReadString( zSTRING const&, zSTRING const&, char const* )                         zCall( 0x0045E3A0 );
    int ReadRaw( zSTRING const&, zSTRING const&, void*, int )                                 zCall( 0x0045E3E0 );
    int AddParameters( zSTRING )                                                              zCall( 0x0045E4B0 );
    int Init( zSTRING, bool )                                                                 zCall( 0x0045E5D0 );
    void ChangeDir( zTOptionPaths )                                                           zCall( 0x0045FB00 );
    zFILE* GetDir( zTOptionPaths )                                                            zCall( 0x0045FBF0 );
    zSTRING& GetDirString( zTOptionPaths )                                                    zCall( 0x0045FC00 );
    int Parm( zSTRING const& )                                                                zCall( 0x0045FC10 );
    zSTRING ParmValue( zSTRING const& )                                                       zCall( 0x0045FD20 );
    zSTRING ParmValueRaw( zSTRING const& )                                                    zCall( 0x0045FF20 );
    int ParmValueInt( zSTRING const& )                                                        zCall( 0x00460120 );
    float ParmValueFloat( zSTRING const& )                                                    zCall( 0x004602E0 );
    virtual ~zCOption()                                                                       zCall( 0x0045B000 );

    // static properties
    static int& trade_amount;

    // user API
    #include "zCOption.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZOPTION_H__VER0__