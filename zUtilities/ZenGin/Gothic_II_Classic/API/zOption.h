// Supported with union (c) 2018 Union team

#ifndef __ZOPTION_H__VER2__
#define __ZOPTION_H__VER2__

namespace Gothic_II_Classic {

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

  class zCOptionEntry {
  public:
    int changed;
    zCArray<bool32(*)( zCOptionEntry& )> ccbList;
    zSTRING varName;
    zSTRING varValue;
    zSTRING varValueTemp;
    int varFlag;

    zCOptionEntry() {}
    void zCOptionEntry_OnInit( zSTRING const&, zSTRING const& ) zCall( 0x0045F5F0 );
    zCOptionEntry( zSTRING const& a0, zSTRING const& a1 )       zInit( zCOptionEntry_OnInit( a0, a1 ));
    ~zCOptionEntry()                                            zCall( 0x0045FEE0 );

    // user API
    #include "zCOptionEntry.inl"
  };

  class zCOptionSection {
  public:
    zSTRING secName;
    zCArray<zCOptionEntry*> entryList;

    zCOptionSection() {}
    void zCOptionSection_OnInit( zSTRING const& ) zCall( 0x0045F870 );
    zCOptionSection( zSTRING const& a0 )          zInit( zCOptionSection_OnInit( a0 ));
    ~zCOptionSection()                            zCall( 0x0045FA30 );

    // user API
    #include "zCOptionSection.inl"
  };

  class zCOption {
  public:
    int m_bReadTemp;
    zCArray<zCOptionSection*> sectionList;
    zFILE*( directory )[NUM_ENTRIES];
    zSTRING dir_string[NUM_ENTRIES];
    zSTRING commandline;

    void zCOption_OnInit()                                                                    zCall( 0x0045FB40 );
    zCOption()                                                                                zInit( zCOption_OnInit() );
    int Load( zSTRING )                                                                       zCall( 0x0045FFA0 );
    int Save( zSTRING )                                                                       zCall( 0x00460EB0 );
    int WriteBool( zSTRING const&, char const*, int, int )                                    zCall( 0x004615D0 );
    int WriteInt( zSTRING const&, char const*, int, int )                                     zCall( 0x00461620 );
    int WriteDWord( zSTRING const&, char const*, unsigned long, int )                         zCall( 0x00461650 );
    int WriteReal( zSTRING const&, char const*, float, int )                                  zCall( 0x00461780 );
    int WriteString( zSTRING const&, char const*, zSTRING, int )                              zCall( 0x004617C0 );
    int ReadBool( zSTRING const&, char const*, int )                                          zCall( 0x00461950 );
    int ReadInt( zSTRING const&, char const*, int )                                           zCall( 0x00461B80 );
    unsigned long ReadDWord( zSTRING const&, char const*, unsigned long )                     zCall( 0x00461CE0 );
    float ReadReal( zSTRING const&, char const*, float )                                      zCall( 0x00461E40 );
    zSTRING ReadString( zSTRING const&, char const*, char const* )                            zCall( 0x00461FD0 );
    int EntryExists( zSTRING const&, char const* )                                            zCall( 0x00462140 );
    unsigned short GetNumEntries( zCOptionSection* )                                          zCall( 0x00462210 );
    zCOptionEntry* GetEntry( zCOptionSection*, int )                                          zCall( 0x00462230 );
    int RemoveEntry( zSTRING const&, char const* )                                            zCall( 0x00462260 );
    void SetFlag( zSTRING const&, char const*, int )                                          zCall( 0x00462400 );
    zCOptionEntry* GetEntryByName( zCOptionSection*, zSTRING const&, int )                    zCall( 0x00462500 );
    zCOptionSection* GetSectionByName( zSTRING const&, int )                                  zCall( 0x004627F0 );
    int SectionExists( zSTRING const& )                                                       zCall( 0x00462A40 );
    unsigned short GetNumSections()                                                           zCall( 0x00462A60 );
    zCOptionSection* GetSection( int )                                                        zCall( 0x00462A70 );
    int RemoveSection( zSTRING const& )                                                       zCall( 0x00462AA0 );
    void InsertChangeHandler( zSTRING const&, char const*, int( __cdecl* )( zCOptionEntry& )) zCall( 0x00462B00 );
    int WriteRaw( zSTRING const&, char const*, void*, int, int )                              zCall( 0x00462CD0 );
    int ReadRaw( zSTRING const&, char const*, void*&, void*, int )                            zCall( 0x00462EB0 );
    int WriteBool( zSTRING const&, zSTRING const&, int, int )                                 zCall( 0x00463090 );
    int WriteInt( zSTRING const&, zSTRING const&, int, int )                                  zCall( 0x004630B0 );
    int WriteDWord( zSTRING const&, zSTRING const&, unsigned long, int )                      zCall( 0x004630D0 );
    int WriteReal( zSTRING const&, zSTRING const&, float, int )                               zCall( 0x004630F0 );
    int WriteString( zSTRING const&, zSTRING const&, zSTRING, int )                           zCall( 0x00463120 );
    int WriteRaw( zSTRING const&, zSTRING const&, void*, int, int )                           zCall( 0x004631D0 );
    int ReadBool( zSTRING const&, zSTRING const&, int )                                       zCall( 0x004631F0 );
    int ReadInt( zSTRING const&, zSTRING const&, int )                                        zCall( 0x00463210 );
    unsigned long ReadDWord( zSTRING const&, zSTRING const&, unsigned long )                  zCall( 0x00463230 );
    float ReadReal( zSTRING const&, zSTRING const&, float )                                   zCall( 0x00463250 );
    zSTRING ReadString( zSTRING const&, zSTRING const&, char const* )                         zCall( 0x00463280 );
    int ReadRaw( zSTRING const&, zSTRING const&, void*, int )                                 zCall( 0x004632C0 );
    int Init( zSTRING )                                                                       zCall( 0x004632F0 );
    void ChangeDir( zTOptionPaths )                                                           zCall( 0x00464530 );
    zFILE* GetDir( zTOptionPaths )                                                            zCall( 0x00464620 );
    zSTRING& GetDirString( zTOptionPaths )                                                    zCall( 0x00464630 );
    int Parm( zSTRING const& )                                                                zCall( 0x00464640 );
    zSTRING ParmValue( zSTRING const& )                                                       zCall( 0x00464750 );
    zSTRING ParmValueRaw( zSTRING const& )                                                    zCall( 0x00464950 );
    int ParmValueInt( zSTRING const& )                                                        zCall( 0x00464B50 );
    float ParmValueFloat( zSTRING const& )                                                    zCall( 0x00464D10 );
    virtual ~zCOption()                                                                       zCall( 0x0045FD60 );

    // user API
    #include "zCOption.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZOPTION_H__VER2__