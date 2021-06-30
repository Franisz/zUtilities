// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_MAN_H__VER1__
#define __ZSOUND_MAN_H__VER1__

namespace Gothic_I_Addon {
  const int zSND_MAN_NUM_COLL_SND = 17;

  class zCSoundManager {
  public:
    enum zTSndManMedium {
      zSND_MAN_MEDIUM_MODEL,
      zSND_MAN_MEDIUM_ITEM,
      zSND_MAN_MEDIUM_OBJECT,
      zSND_MAN_MEDIUM_LEVEL
    };

    struct zTScriptSoundData {
      zSTRING file;
      int pitchOff;
      int pitchVar;
      int vol;
      int loop;
      float reverbLevel;
      zSTRING pfxName;

      void zTScriptSoundData_OnInit() zCall( 0x005DFAB0 );
      ~zTScriptSoundData()            zCall( 0x005DFA10 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    struct zCSoundEventData {
      zSTRING name;
      zCSoundFX* sound;
      zCParticleEmitter* pfxEmitter;

      void zCSoundEventData_OnInit()                                   zCall( 0x005E0DE0 );
      ~zCSoundEventData()                                              zCall( 0x004031E0 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005E0F30 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005E1020 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    class zCMediumType {
    public:
      int nameInt;
      zSTRING contents;

      void zCMediumType_OnInit() zCall( 0x005E29B0 );
      ~zCMediumType()            zCall( 0x005DFF60 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;
      zCArraySort<zCSoundEventData> collSndSubTable;

      void zCTableEntry_OnInit() zCall( 0x005DFBA0 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x006258B0 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND];
    zCArraySort<zCSoundEventData> slideSndTable;
    zCArraySort<zCSoundEventData> destSndTable;
    int debugMessageEnabled;

    zCSoundManager() {}
    void DebugMessage( zSTRING const& )                                                              zCall( 0x005DFAF0 );
    zSTRING SearchMediumTypeIDList( int, int )                                                       zCall( 0x005DFD40 );
    int GetMediumIndex( char )                                                                       zCall( 0x005DFFB0 );
    int GetCollSndTableIndex( zSTRING const& )                                                       zCall( 0x005E00B0 );
    void StartHitSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int, zCCollisionReport const* ) zCall( 0x005E01F0 );
    void StartAttackSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int )                        zCall( 0x005E1080 );
    int StartSlideSound( zCVob*, int )                                                               zCall( 0x005E15E0 );
    void StartDestructionSound( zCVob*, int )                                                        zCall( 0x005E18A0 );
    void Init()                                                                                      zCall( 0x005E1C70 );
    ~zCSoundManager()                                                                                zCall( 0x0062AE50 );

    // static properties
    static zTScriptSoundData& scriptSoundData;
    static zSTRING& mediumIDList;
    static zSTRING& prefixProto;

    // user API
    #include "zCSoundManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSOUND_MAN_H__VER1__