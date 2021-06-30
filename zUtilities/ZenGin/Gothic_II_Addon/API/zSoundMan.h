// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_MAN_H__VER3__
#define __ZSOUND_MAN_H__VER3__

#include "zSound.h"
#include "zParser_Const.h"
#include "zParticle.h"
#include "zParser.h"

namespace Gothic_II_Addon {
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

      void zTScriptSoundData_OnInit() zCall( 0x005EC420 );
      ~zTScriptSoundData()            zCall( 0x005EC3A0 );
      zTScriptSoundData()             zInit( zTScriptSoundData_OnInit() );

      // user API
      #include "zCSoundManager_zTScriptSoundData.inl"
    };

    struct zCSoundEventData {
      zSTRING name;
      zCSoundFX* sound;
      zCParticleEmitter* pfxEmitter;

      void zCSoundEventData_OnInit()                                   zCall( 0x005ED610 );
      ~zCSoundEventData()                                              zCall( 0x00402D30 );
      zCSoundEventData()                                               zInit( zCSoundEventData_OnInit() );
      void GetData( zSTRING const&, zCSoundFX*&, zCParticleEmitter*& ) zCall( 0x005ED760 );
      void GetData( zCSoundFX*&, zCParticleEmitter*& )                 zCall( 0x005ED840 );

      // user API
      #include "zCSoundManager_zCSoundEventData.inl"
    };

    class zCMediumType {
    public:
      int nameInt;
      zSTRING contents;

      void zCMediumType_OnInit() zCall( 0x005EF050 );
      ~zCMediumType()            zCall( 0x005EC870 );
      zCMediumType()             zInit( zCMediumType_OnInit() );

      // user API
      #include "zCSoundManager_zCMediumType.inl"
    };

    class zCTableEntry {
    public:
      zCSoundEventData defaultSoundEventData;
      zCArraySort<zCSoundEventData> collSndSubTable;

      void zCTableEntry_OnInit() zCall( 0x005EC500 );
      zCTableEntry()             zInit( zCTableEntry_OnInit() );
      ~zCTableEntry()            zCall( 0x00632BD0 );

      // user API
      #include "zCSoundManager_zCTableEntry.inl"
    };

    zCArraySort<zCMediumType> mediumTypeIDList;
    zCTableEntry collSndTable[zSND_MAN_NUM_COLL_SND];
    zCArraySort<zCSoundEventData> slideSndTable;
    zCArraySort<zCSoundEventData> destSndTable;
    int debugMessageEnabled;

    zCSoundManager() {}
    void DebugMessage( zSTRING const& )                                                              zCall( 0x005EC460 );
    zSTRING SearchMediumTypeIDList( int, int )                                                       zCall( 0x005EC6A0 );
    int GetMediumIndex( char )                                                                       zCall( 0x005EC8C0 );
    int GetCollSndTableIndex( zSTRING const& )                                                       zCall( 0x005EC9A0 );
    void StartHitSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int, zCCollisionReport const* ) zCall( 0x005ECAE0 );
    void StartAttackSound( zCVob*, zTSndManMedium, zTSndManMedium, int, int )                        zCall( 0x005ED8A0 );
    int StartSlideSound( zCVob*, int )                                                               zCall( 0x005EDE60 );
    void StartDestructionSound( zCVob*, int )                                                        zCall( 0x005EE0C0 );
    void Init()                                                                                      zCall( 0x005EE3F0 );
    ~zCSoundManager()                                                                                zCall( 0x006390E0 );

    // static properties
    static zTScriptSoundData& scriptSoundData;
    static zSTRING& mediumIDList;
    static zSTRING& prefixProto;

    // user API
    #include "zCSoundManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSOUND_MAN_H__VER3__