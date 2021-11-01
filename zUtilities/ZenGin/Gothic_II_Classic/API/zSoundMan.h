// Supported with union (c) 2018-2021 Union team

#ifndef __ZSOUND_MAN_H__VER2__
#define __ZSOUND_MAN_H__VER2__

namespace Gothic_II_Classic {
  const int zSND_MAN_NUM_COLL_SND = 17;

  // sizeof 320h
  class zCSoundManager {
  public:
    enum zTSndManMedium {
      zSND_MAN_MEDIUM_MODEL,
      zSND_MAN_MEDIUM_ITEM,
      zSND_MAN_MEDIUM_OBJECT,
      zSND_MAN_MEDIUM_LEVEL
    };

    // sizeof 3Ch
    struct zTScriptSoundData {
      zSTRING file;      // sizeof 14h    offset 00h
      int pitchOff;      // sizeof 04h    offset 14h
      int pitchVar;      // sizeof 04h    offset 18h
      int vol;           // sizeof 04h    offset 1Ch
      int loop;          // sizeof 04h    offset 20h
      float reverbLevel; // sizeof 04h    offset 24h
      zSTRING pfxName;   // sizeof 14h    offset 28h

      void zTScriptSoundData_OnInit() zCall( 0x005E5670 );
      ~zTScriptSoundData()            zCall( 0x005E55F0 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    // sizeof 1Ch
    struct zCSoundEventData {
      zSTRING name;                  // sizeof 14h    offset 00h
      zCSoundFX* sound;              // sizeof 04h    offset 14h
      zCParticleEmitter* pfxEmitter; // sizeof 04h    offset 18h

      void zCSoundEventData_OnInit()                                   zCall( 0x005E6860 );
      ~zCSoundEventData()                                              zCall( 0x00402D30 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005E69B0 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005E6A90 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    // sizeof 18h
    class zCMediumType {
    public:
      int nameInt;      // sizeof 04h    offset 00h
      zSTRING contents; // sizeof 14h    offset 04h

      void zCMediumType_OnInit() zCall( 0x005E82A0 );
      ~zCMediumType()            zCall( 0x005E5AC0 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    // sizeof 2Ch
    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;        // sizeof 1Ch    offset 00h
      zCArraySort<zCSoundEventData> collSndSubTable; // sizeof 10h    offset 1Ch

      void zCTableEntry_OnInit() zCall( 0x005E5750 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x0062B400 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;       // sizeof 10h    offset 00h
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND]; // sizeof 2ECh   offset 10h
    zCArraySort<zCSoundEventData> slideSndTable;      // sizeof 10h    offset 2FCh
    zCArraySort<zCSoundEventData> destSndTable;       // sizeof 10h    offset 30Ch
    int debugMessageEnabled;                          // sizeof 04h    offset 31Ch

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