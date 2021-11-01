// Supported with union (c) 2018-2021 Union team

#ifndef __OSAVEGAME_H__VER3__
#define __OSAVEGAME_H__VER3__

#include "zBuffer.h"

namespace Gothic_II_Addon {

  // sizeof B4h
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
    int m_verMajor;        // sizeof 04h    offset 88h
    int m_verMinor;        // sizeof 04h    offset 8Ch
    int m_PlayTimeSeconds; // sizeof 04h    offset 90h
    int m_verPoint;        // sizeof 04h    offset 94h
    int m_verInt;          // sizeof 04h    offset 98h
    zSTRING m_verName;     // sizeof 14h    offset 9Ch
    int m_notCompatible;   // sizeof 04h    offset B0h

    void oCSavegameInfo_OnInit()             zCall( 0x00436BA0 );
    void oCSavegameInfo_OnInit( int )        zCall( 0x00436D70 );
    zSTRING GetName()                        zCall( 0x0042A610 );
    zSTRING GetWorldName()                   zCall( 0x0042A660 );
    zSTRING GetSaveTime()                    zCall( 0x0042F130 );
    oCSavegameInfo()                         zInit( oCSavegameInfo_OnInit() );
    oCSavegameInfo( int a0 )                 zInit( oCSavegameInfo_OnInit( a0 ));
    void Init()                              zCall( 0x00436F10 );
    int DoesSavegameExist()                  zCall( 0x004370E0 );
    void UpdateThumbPic( zCTextureConvert* ) zCall( 0x004370F0 );
    zSTRING GetDir()                         zCall( 0x00437310 );
    void ReloadResources()                   zCall( 0x00437360 );
    void CleanResources()                    zCall( 0x00437550 );
    void SetSlot( int )                      zCall( 0x00437580 );
    zSTRING GetGameTime()                    zCall( 0x00438440 );
    static zCObject* _CreateNewInstance()    zCall( 0x00436B20 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00436D30 );
    virtual void Archive( zCArchiver& )      zCall( 0x00437970 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00437EC0 );
    virtual ~oCSavegameInfo()                zCall( 0x00437810 );

    // user API
    #include "oCSavegameInfo.inl"
  };

  // sizeof 18h
  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList; // sizeof 0Ch    offset 04h
    oCSavegameInfo* localInfo;         // sizeof 04h    offset 10h
    bool initialized;                  // sizeof 01h    offset 14h

    void oCSavegameManager_OnInit()                  zCall( 0x004386F0 );
    oCSavegameManager()                              zInit( oCSavegameManager_OnInit() );
    void Init()                                      zCall( 0x00438990 );
    void Reinit()                                    zCall( 0x00439070 );
    void CleanResources()                            zCall( 0x00439080 );
    void SetAndWriteSavegame( int, oCSavegameInfo* ) zCall( 0x004390E0 );
    oCSavegameInfo* GetSavegame( int )               zCall( 0x004392E0 );
    void CopyToCurrent( int )                        zCall( 0x00439310 );
    void CopyFromCurrent( int )                      zCall( 0x004394C0 );
    void ClearCurrent()                              zCall( 0x00439670 );
    zSTRING GetSlotDirName( int )                    zCall( 0x004397B0 );
    virtual ~oCSavegameManager()                     zCall( 0x004388D0 );

    // user API
    #include "oCSavegameManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OSAVEGAME_H__VER3__