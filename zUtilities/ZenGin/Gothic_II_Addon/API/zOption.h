// Supported with union (c) 2018 Union team

#ifndef __ZOPTION_H__VER3__
#define __ZOPTION_H__VER3__

namespace Gothic_II_Addon {

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
    void zCOptionEntry_OnInit( zSTRING const&, zSTRING const& ) zCall( 0x0045FE00 );
    zCOptionEntry( zSTRING const& a0, zSTRING const& a1 )       zInit( zCOptionEntry_OnInit( a0, a1 ));
    ~zCOptionEntry()                                            zCall( 0x004606F0 );

    // user API
    #include "zCOptionEntry.inl"
  };

  class zCOptionSection {
  public:
    zSTRING secName;
    zCArray<zCOptionEntry*> entryList;

    zCOptionSection() {}
    void zCOptionSection_OnInit( zSTRING const& ) zCall( 0x00460080 );
    zCOptionSection( zSTRING const& a0 )          zInit( zCOptionSection_OnInit( a0 ));
    ~zCOptionSection()                            zCall( 0x00460240 );

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

    void zCOption_OnInit()                                                                    zCall( 0x00460350 );
    zCOption()                                                                                zInit( zCOption_OnInit() );
    int Load( zSTRING )                                                                       zCall( 0x004607B0 );
    int Save( zSTRING )                                                                       zCall( 0x004616C0 );
    int WriteBool( zSTRING const&, char const*, int, int )                                    zCall( 0x00461DE0 );
    int WriteInt( zSTRING const&, char const*, int, int )                                     zCall( 0x00461E30 );
    int WriteDWord( zSTRING const&, char const*, unsigned long, int )                         zCall( 0x00461E60 );
    int WriteReal( zSTRING const&, char const*, float, int )                                  zCall( 0x00461F90 );
    int WriteString( zSTRING const&, char const*, zSTRING, int )                              zCall( 0x00461FD0 );
    int ReadBool( zSTRING const&, char const*, int )                                          zCall( 0x00462160 );
    int ReadInt( zSTRING const&, char const*, int )                                           zCall( 0x00462390 );
    unsigned long ReadDWord( zSTRING const&, char const*, unsigned long )                     zCall( 0x004624F0 );
    float ReadReal( zSTRING const&, char const*, float )                                      zCall( 0x00462650 );
    zSTRING ReadString( zSTRING const&, char const*, char const* )                            zCall( 0x004627E0 );
    int EntryExists( zSTRING const&, char const* )                                            zCall( 0x00462950 );
    unsigned short GetNumEntries( zCOptionSection* )                                          zCall( 0x00462A20 );
    zCOptionEntry* GetEntry( zCOptionSection*, int )                                          zCall( 0x00462A40 );
    int RemoveEntry( zSTRING const&, char const* )                                            zCall( 0x00462A70 );
    void SetFlag( zSTRING const&, char const*, int )                                          zCall( 0x00462C10 );
    zCOptionEntry* GetEntryByName( zCOptionSection*, zSTRING const&, int )                    zCall( 0x00462D10 );
    zCOptionSection* GetSectionByName( zSTRING const&, int )                                  zCall( 0x00463000 );
    int SectionExists( zSTRING const& )                                                       zCall( 0x00463250 );
    unsigned short GetNumSections()                                                           zCall( 0x00463270 );
    zCOptionSection* GetSection( int )                                                        zCall( 0x00463280 );
    int RemoveSection( zSTRING const& )                                                       zCall( 0x004632B0 );
    void InsertChangeHandler( zSTRING const&, char const*, int( __cdecl* )( zCOptionEntry& )) zCall( 0x00463310 );
    int WriteRaw( zSTRING const&, char const*, void*, int, int )                              zCall( 0x004634E0 );
    int ReadRaw( zSTRING const&, char const*, void*&, void*, int )                            zCall( 0x004636C0 );
    int WriteBool( zSTRING const&, zSTRING const&, int, int )                                 zCall( 0x004638A0 );
    int WriteInt( zSTRING const&, zSTRING const&, int, int )                                  zCall( 0x004638C0 );
    int WriteDWord( zSTRING const&, zSTRING const&, unsigned long, int )                      zCall( 0x004638E0 );
    int WriteReal( zSTRING const&, zSTRING const&, float, int )                               zCall( 0x00463900 );
    int WriteString( zSTRING const&, zSTRING const&, zSTRING, int )                           zCall( 0x00463930 );
    int WriteRaw( zSTRING const&, zSTRING const&, void*, int, int )                           zCall( 0x004639E0 );
    int ReadBool( zSTRING const&, zSTRING const&, int )                                       zCall( 0x00463A00 );
    int ReadInt( zSTRING const&, zSTRING const&, int )                                        zCall( 0x00463A20 );
    unsigned long ReadDWord( zSTRING const&, zSTRING const&, unsigned long )                  zCall( 0x00463A40 );
    float ReadReal( zSTRING const&, zSTRING const&, float )                                   zCall( 0x00463A60 );
    zSTRING ReadString( zSTRING const&, zSTRING const&, char const* )                         zCall( 0x00463A90 );
    int ReadRaw( zSTRING const&, zSTRING const&, void*, int )                                 zCall( 0x00463AD0 );
    int AddParameters( zSTRING )                                                              zCall( 0x00463B00 );
    int Init( zSTRING, bool )                                                                 zCall( 0x00463C20 );
    void ChangeDir( zTOptionPaths )                                                           zCall( 0x00465160 );
    zFILE* GetDir( zTOptionPaths )                                                            zCall( 0x00465250 );
    zSTRING& GetDirString( zTOptionPaths )                                                    zCall( 0x00465260 );
    int Parm( zSTRING const& )                                                                zCall( 0x00465270 );
    zSTRING ParmValue( zSTRING const& )                                                       zCall( 0x00465380 );
    zSTRING ParmValueRaw( zSTRING const& )                                                    zCall( 0x00465580 );
    int ParmValueInt( zSTRING const& )                                                        zCall( 0x00465780 );
    float ParmValueFloat( zSTRING const& )                                                    zCall( 0x00465940 );
    virtual ~zCOption()                                                                       zCall( 0x00460570 );

    // user API
    #include "zCOption.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZOPTION_H__VER3__