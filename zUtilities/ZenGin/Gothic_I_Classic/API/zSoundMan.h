// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_MAN_H__VER0__
#define __ZSOUND_MAN_H__VER0__

namespace Gothic_I_Classic {
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

      void zTScriptSoundData_OnInit() zCall( 0x005C1B30 );
      ~zTScriptSoundData()            zCall( 0x005C1AB0 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    struct zCSoundEventData {
      zSTRING name;
      zCSoundFX* sound;
      zCParticleEmitter* pfxEmitter;

      void zCSoundEventData_OnInit()                                   zCall( 0x005C2CB0 );
      ~zCSoundEventData()                                              zCall( 0x00402D80 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005C2E00 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005C2EE0 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    class zCMediumType {
    public:
      int nameInt;
      zSTRING contents;

      void zCMediumType_OnInit() zCall( 0x005C4660 );
      ~zCMediumType()            zCall( 0x005C1F80 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;
      zCArraySort<zCSoundEventData> collSndSubTable;

      void zCTableEntry_OnInit() zCall( 0x005C1C10 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x00603870 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND];
    zCArraySort<zCSoundEventData> slideSndTable;
    zCArraySort<zCSoundEventData> destSndTable;
    int debugMessageEnabled;

    zCSoundManager() {}
    void DebugMessage( zSTRING const& )                                                              zCall( 0x005C1B70 );
    zSTRING SearchMediumTypeIDList( int, int )                                                       zCall( 0x005C1DB0 );
    int GetMediumIndex( char )                                                                       zCall( 0x005C1FD0 );
    int GetCollSndTableIndex( zSTRING const& )                                                       zCall( 0x005C20B0 );
    void StartHitSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int, zCCollisionReport const* ) zCall( 0x005C21F0 );
    void StartAttackSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int )                        zCall( 0x005C2F40 );
    int StartSlideSound( zCVob*, int )                                                               zCall( 0x005C3460 );
    void StartDestructionSound( zCVob*, int )                                                        zCall( 0x005C36C0 );
    void Init()                                                                                      zCall( 0x005C3A20 );
    ~zCSoundManager()                                                                                zCall( 0x006089D0 );

    // static properties
    static zTScriptSoundData& scriptSoundData;
    static zSTRING& mediumIDList;
    static zSTRING& prefixProto;

    // user API
    #include "zCSoundManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSOUND_MAN_H__VER0__