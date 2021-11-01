// Supported with union (c) 2018-2021 Union team

#ifndef __ZSOUND_MAN_H__VER0__
#define __ZSOUND_MAN_H__VER0__

namespace Gothic_I_Classic {
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

      void zTScriptSoundData_OnInit() zCall( 0x005C1B30 );
      ~zTScriptSoundData()            zCall( 0x005C1AB0 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    // sizeof 1Ch
    struct zCSoundEventData {
      zSTRING name;                  // sizeof 14h    offset 00h
      zCSoundFX* sound;              // sizeof 04h    offset 14h
      zCParticleEmitter* pfxEmitter; // sizeof 04h    offset 18h

      void zCSoundEventData_OnInit()                                   zCall( 0x005C2CB0 );
      ~zCSoundEventData()                                              zCall( 0x00402D80 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005C2E00 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005C2EE0 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    // sizeof 18h
    class zCMediumType {
    public:
      int nameInt;      // sizeof 04h    offset 00h
      zSTRING contents; // sizeof 14h    offset 04h

      void zCMediumType_OnInit() zCall( 0x005C4660 );
      ~zCMediumType()            zCall( 0x005C1F80 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    // sizeof 2Ch
    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;        // sizeof 1Ch    offset 00h
      zCArraySort<zCSoundEventData> collSndSubTable; // sizeof 10h    offset 1Ch

      void zCTableEntry_OnInit() zCall( 0x005C1C10 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x00603870 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;       // sizeof 10h    offset 00h
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND]; // sizeof 2ECh   offset 10h
    zCArraySort<zCSoundEventData> slideSndTable;      // sizeof 10h    offset 2FCh
    zCArraySort<zCSoundEventData> destSndTable;       // sizeof 10h    offset 30Ch
    int debugMessageEnabled;                          // sizeof 04h    offset 31Ch

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