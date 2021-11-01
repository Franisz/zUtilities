// Supported with union (c) 2018-2021 Union team

#ifndef __OSAVEGAME_H__VER0__
#define __OSAVEGAME_H__VER0__

#include "zBuffer.h"

namespace Gothic_I_Classic {

  // sizeof 90h
  class oCSavegameInfo : public zCObject {
  public:
    zCLASS_DECLARATION( oCSavegameInfo )

    zSTRING m_Dir;         // sizeof 14h    offset 24h
    zCTexture* m_ThumbTex; // sizeof 04h    offset 38h
    int m_SlotNr;          // sizeof 04h    offset 3Ch
    zSTRING m_Name;        // sizeof 14h    offset 40h
    zSTRING m_WorldName;   // sizeof 14h    offset 54h
    int m_TimeDay;         // sizeof 04h    offset 68h
    int m_TimeHour;        // sizeof 04h    offset 6Ch
    int m_TimeMin;         // sizeof 04h    offset 70h
    zSTRING m_SaveDate;    // sizeof 14h    offset 74h
    int m_PlayTimeSeconds; // sizeof 04h    offset 88h
    int m_notCompatible;   // sizeof 04h    offset 8Ch

    void oCSavegameInfo_OnInit()                                        zCall( 0x00433E00 );
    void oCSavegameInfo_OnInit( int )                                   zCall( 0x00433F30 );
    zSTRING GetName()                                                   zCall( 0x00428A60 );
    zSTRING GetWorldName()                                              zCall( 0x00428AB0 );
    zSTRING GetSaveTime()                                               zCall( 0x0042C7E0 );
    oCSavegameInfo()                                                    zInit( oCSavegameInfo_OnInit() );
    oCSavegameInfo( int a0 )                                            zInit( oCSavegameInfo_OnInit( a0 ));
    void Init()                                                         zCall( 0x004340D0 );
    int DoesSavegameExist()                                             zCall( 0x004340F0 );
    void UpdateThumbPic( zCTextureConvert* )                            zCall( 0x00434100 );
    zSTRING GetDir()                                                    zCall( 0x00434330 );
    void ReloadResources()                                              zCall( 0x00434380 );
    void CleanResources()                                               zCall( 0x00434580 );
    void SetSlot( int )                                                 zCall( 0x004345B0 );
    zSTRING GetGameTime()                                               zCall( 0x00435050 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00433C90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00433DF0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00434850 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00434C40 );
    virtual ~oCSavegameInfo()                                           zCall( 0x00434710 );

    // user API
    #include "oCSavegameInfo.inl"
  };

  // sizeof 18h
  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList; // sizeof 0Ch    offset 04h
    oCSavegameInfo* localInfo;         // sizeof 04h    offset 10h
    bool initialized;                  // sizeof 01h    offset 14h

    void oCSavegameManager_OnInit()                  zCall( 0x004352C0 );
    oCSavegameManager()                              zInit( oCSavegameManager_OnInit() );
    void Init()                                      zCall( 0x004355B0 );
    void Reinit()                                    zCall( 0x00435B20 );
    void CleanResources()                            zCall( 0x00435B30 );
    void SetAndWriteSavegame( int, oCSavegameInfo* ) zCall( 0x00435B90 );
    oCSavegameInfo* GetSavegame( int )               zCall( 0x00435D90 );
    void CopyToCurrent( int )                        zCall( 0x00435DC0 );
    void CopyFromCurrent( int )                      zCall( 0x00435F70 );
    void ClearCurrent()                              zCall( 0x00436120 );
    zSTRING GetSlotDirName( int )                    zCall( 0x00436260 );
    virtual ~oCSavegameManager()                     zCall( 0x004354F0 );

    // user API
    #include "oCSavegameManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OSAVEGAME_H__VER0__