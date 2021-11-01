// Supported with union (c) 2018-2021 Union team

#ifndef __OSAVEGAME_H__VER1__
#define __OSAVEGAME_H__VER1__

#include "zBuffer.h"

namespace Gothic_I_Addon {

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

    void oCSavegameInfo_OnInit()                                        zCall( 0x00437D70 );
    void oCSavegameInfo_OnInit( int )                                   zCall( 0x00437EA0 );
    zSTRING GetName()                                                   zCall( 0x0042B8B0 );
    zSTRING GetWorldName()                                              zCall( 0x0042B900 );
    zSTRING GetSaveTime()                                               zCall( 0x0042F920 );
    oCSavegameInfo()                                                    zInit( oCSavegameInfo_OnInit() );
    oCSavegameInfo( int a0 )                                            zInit( oCSavegameInfo_OnInit( a0 ));
    void Init()                                                         zCall( 0x00437FB0 );
    int DoesSavegameExist()                                             zCall( 0x00437FD0 );
    void UpdateThumbPic( zCTextureConvert* )                            zCall( 0x00437FE0 );
    zSTRING GetDir()                                                    zCall( 0x00438270 );
    void ReloadResources()                                              zCall( 0x004382C0 );
    void CleanResources()                                               zCall( 0x004384F0 );
    void SetSlot( int )                                                 zCall( 0x00438520 );
    zSTRING GetGameTime()                                               zCall( 0x00439270 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00437C00 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00437D60 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00438920 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00438DC0 );
    virtual ~oCSavegameInfo()                                           zCall( 0x004387A0 );

    // user API
    #include "oCSavegameInfo.inl"
  };

  // sizeof 18h
  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList; // sizeof 0Ch    offset 04h
    oCSavegameInfo* localInfo;         // sizeof 04h    offset 10h
    bool initialized;                  // sizeof 01h    offset 14h

    void oCSavegameManager_OnInit()                  zCall( 0x00439550 );
    oCSavegameManager()                              zInit( oCSavegameManager_OnInit() );
    void Init()                                      zCall( 0x00439850 );
    void Reinit()                                    zCall( 0x00439E80 );
    void CleanResources()                            zCall( 0x00439E90 );
    void SetAndWriteSavegame( int, oCSavegameInfo* ) zCall( 0x00439EF0 );
    oCSavegameInfo* GetSavegame( int )               zCall( 0x0043A130 );
    void CopyToCurrent( int )                        zCall( 0x0043A160 );
    void CopyFromCurrent( int )                      zCall( 0x0043A330 );
    void ClearCurrent()                              zCall( 0x0043A500 );
    zSTRING GetSlotDirName( int )                    zCall( 0x0043A650 );
    virtual ~oCSavegameManager()                     zCall( 0x00439790 );

    // user API
    #include "oCSavegameManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OSAVEGAME_H__VER1__