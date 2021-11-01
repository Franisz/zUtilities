// Supported with union (c) 2018-2021 Union team

#ifndef __ZOPTION_H__VER1__
#define __ZOPTION_H__VER1__

namespace Gothic_I_Addon {

  enum zTOptionPaths {
    DIR_SYSTEM,
    DIR_WEB,
    DIR_SAVEGAMES,
    DIR_DATA,
    DIR_ANIMS,
    DIR_CUTSCENES,
    DIR_OUTPUTUNITS,
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
    void zCOptionEntry_OnInit( zSTRING const&, zSTRING const& ) zCall( 0x00461C20 );
    zCOptionEntry( zSTRING const& a0, zSTRING const& a1 )       zInit( zCOptionEntry_OnInit( a0, a1 ));
    ~zCOptionEntry()                                            zCall( 0x00462530 );
    void SetValue( zSTRING, int )                               zCall( 0x00464130 );

    // user API
    #include "zCOptionEntry.inl"
  };

  // sizeof 20h
  class zCOptionSection {
  public:
    zSTRING secName;                   // sizeof 14h    offset 00h
    zCArray<zCOptionEntry*> entryList; // sizeof 0Ch    offset 14h

    zCOptionSection() {}
    void zCOptionSection_OnInit( zSTRING const& ) zCall( 0x00461E90 );
    zCOptionSection( zSTRING const& a0 )          zInit( zCOptionSection_OnInit( a0 ));
    ~zCOptionSection()                            zCall( 0x00462050 );

    // user API
    #include "zCOptionSection.inl"
  };

  // sizeof 298h
  class zCOption {
  public:
    int m_bReadTemp;                       // sizeof 04h    offset 04h
    zCArray<zCOptionSection*> sectionList; // sizeof 0Ch    offset 08h
    zFILE*( directory )[NUM_ENTRIES];      // sizeof 68h    offset 14h
    zSTRING dir_string[NUM_ENTRIES];       // sizeof 208h   offset 7Ch
    zSTRING commandline;                   // sizeof 14h    offset 284h

    void zCOption_OnInit()                                                                    zCall( 0x00462190 );
    zCOption()                                                                                zInit( zCOption_OnInit() );
    int Load( zSTRING )                                                                       zCall( 0x00462610 );
    int Save( zSTRING )                                                                       zCall( 0x00463710 );
    int WriteBool( zSTRING const&, char const*, int, int )                                    zCall( 0x00463EC0 );
    int WriteInt( zSTRING const&, char const*, int, int )                                     zCall( 0x00463F10 );
    int WriteDWord( zSTRING const&, char const*, unsigned long, int )                         zCall( 0x00463F40 );
    int WriteReal( zSTRING const&, char const*, float, int )                                  zCall( 0x00463F70 );
    int WriteString( zSTRING const&, char const*, zSTRING, int )                              zCall( 0x00463FB0 );
    int ReadBool( zSTRING const&, char const*, int )                                          zCall( 0x00464330 );
    int ReadInt( zSTRING const&, char const*, int )                                           zCall( 0x004645B0 );
    unsigned long ReadDWord( zSTRING const&, char const*, unsigned long )                     zCall( 0x004646C0 );
    float ReadReal( zSTRING const&, char const*, float )                                      zCall( 0x004647D0 );
    zSTRING ReadString( zSTRING const&, char const*, char const* )                            zCall( 0x004648E0 );
    int EntryExists( zSTRING const&, char const* )                                            zCall( 0x00464A10 );
    unsigned short GetNumEntries( zCOptionSection* )                                          zCall( 0x00464B00 );
    zCOptionEntry* GetEntry( zCOptionSection*, int )                                          zCall( 0x00464B20 );
    int RemoveEntry( zSTRING const&, char const* )                                            zCall( 0x00464B50 );
    void SetFlag( zSTRING const&, char const*, int )                                          zCall( 0x00464D20 );
    zCOptionEntry* GetEntryByName( zCOptionSection*, zSTRING const&, int )                    zCall( 0x00464E30 );
    zCOptionSection* GetSectionByName( zSTRING const&, int )                                  zCall( 0x00465160 );
    int SectionExists( zSTRING const& )                                                       zCall( 0x00465400 );
    unsigned short GetNumSections()                                                           zCall( 0x00465420 );
    zCOptionSection* GetSection( int )                                                        zCall( 0x00465430 );
    int RemoveSection( zSTRING const& )                                                       zCall( 0x00465460 );
    void InsertChangeHandler( zSTRING const&, char const*, int( __cdecl* )( zCOptionEntry& )) zCall( 0x004654C0 );
    int WriteRaw( zSTRING const&, char const*, void*, int, int )                              zCall( 0x004656B0 );
    int ReadRaw( zSTRING const&, char const*, void*&, void*, int )                            zCall( 0x004658C0 );
    int WriteBool( zSTRING const&, zSTRING const&, int, int )                                 zCall( 0x00465A90 );
    int WriteInt( zSTRING const&, zSTRING const&, int, int )                                  zCall( 0x00465AC0 );
    int WriteDWord( zSTRING const&, zSTRING const&, unsigned long, int )                      zCall( 0x00465AF0 );
    int WriteReal( zSTRING const&, zSTRING const&, float, int )                               zCall( 0x00465B20 );
    int WriteString( zSTRING const&, zSTRING const&, zSTRING, int )                           zCall( 0x00465B50 );
    int WriteRaw( zSTRING const&, zSTRING const&, void*, int, int )                           zCall( 0x00465C10 );
    int ReadBool( zSTRING const&, zSTRING const&, int )                                       zCall( 0x00465C40 );
    int ReadInt( zSTRING const&, zSTRING const&, int )                                        zCall( 0x00465C70 );
    unsigned long ReadDWord( zSTRING const&, zSTRING const&, unsigned long )                  zCall( 0x00465CA0 );
    float ReadReal( zSTRING const&, zSTRING const&, float )                                   zCall( 0x00465CD0 );
    zSTRING ReadString( zSTRING const&, zSTRING const&, char const* )                         zCall( 0x00465D00 );
    int ReadRaw( zSTRING const&, zSTRING const&, void*, int )                                 zCall( 0x00465D40 );
    int Init( zSTRING )                                                                       zCall( 0x00465E20 );
    void ChangeDir( zTOptionPaths )                                                           zCall( 0x004672F0 );
    zFILE* GetDir( zTOptionPaths )                                                            zCall( 0x004673F0 );
    zSTRING& GetDirString( zTOptionPaths )                                                    zCall( 0x00467400 );
    int Parm( zSTRING const& )                                                                zCall( 0x00467410 );
    zSTRING ParmValue( zSTRING const& )                                                       zCall( 0x00467540 );
    zSTRING ParmValueRaw( zSTRING const& )                                                    zCall( 0x00467780 );
    int ParmValueInt( zSTRING const& )                                                        zCall( 0x004679C0 );
    float ParmValueFloat( zSTRING const& )                                                    zCall( 0x00467BB0 );
    virtual ~zCOption()                                                                       zCall( 0x004623B0 );

    // user API
    #include "zCOption.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZOPTION_H__VER1__