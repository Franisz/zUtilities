// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_MAN_H__VER2__
#define __ZSOUND_MAN_H__VER2__

namespace Gothic_II_Classic {
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

      void zTScriptSoundData_OnInit() zCall( 0x005E5670 );
      ~zTScriptSoundData()            zCall( 0x005E55F0 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    struct zCSoundEventData {
      zSTRING name;
      zCSoundFX* sound;
      zCParticleEmitter* pfxEmitter;

      void zCSoundEventData_OnInit()                                   zCall( 0x005E6860 );
      ~zCSoundEventData()                                              zCall( 0x00402D30 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005E69B0 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005E6A90 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    class zCMediumType {
    public:
      int nameInt;
      zSTRING contents;

      void zCMediumType_OnInit() zCall( 0x005E82A0 );
      ~zCMediumType()            zCall( 0x005E5AC0 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;
      zCArraySort<zCSoundEventData> collSndSubTable;

      void zCTableEntry_OnInit() zCall( 0x005E5750 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x0062B400 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND];
    zCArraySort<zCSoundEventData> slideSndTable;
    zCArraySort<zCSoundEventData> destSndTable;
    int debugMessageEnabled;

    zCSoundManager() {}
    void DebugMessage( zSTRING const& )                                                              zCall( 0x005E56B0 );
    zSTRING SearchMediumTypeIDList( int, int )                                                       zCall( 0x005E58F0 );
    int GetMediumIndex( char )                                                                       zCall( 0x005E5B10 );
    int GetCollSndTableIndex( zSTRING const& )                                                       zCall( 0x005E5BF0 );
    void StartHitSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int, zCCollisionReport const* ) zCall( 0x005E5D30 );
    void StartAttackSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int )                        zCall( 0x005E6AF0 );
    int StartSlideSound( zCVob*, int )                                                               zCall( 0x005E70B0 );
    void StartDestructionSound( zCVob*, int )                                                        zCall( 0x005E7310 );
    void Init()                                                                                      zCall( 0x005E7640 );
    ~zCSoundManager()                                                                                zCall( 0x00631910 );

    // static properties
    static zTScriptSoundData& scriptSoundData;
    static zSTRING& mediumIDList;
    static zSTRING& prefixProto;

    // user API
    #include "zCSoundManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSOUND_MAN_H__VER2__