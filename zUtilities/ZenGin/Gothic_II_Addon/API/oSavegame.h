// Supported with union (c) 2018 Union team

#ifndef __OSAVEGAME_H__VER3__
#define __OSAVEGAME_H__VER3__

#include "zBuffer.h"

namespace Gothic_II_Addon {

  class oCSavegameInfo : public zCObject {
  public:
    zCLASS_DECLARATION( oCSavegameInfo )

    zSTRING m_Dir;
    zCTexture* m_ThumbTex;
    int m_SlotNr;
    zSTRING m_Name;
    zSTRING m_WorldName;
    int m_TimeDay;
    int m_TimeHour;
    int m_TimeMin;
    zSTRING m_SaveDate;
    int m_verMajor;
    int m_verMinor;
    int m_PlayTimeSeconds;
    int m_verPoint;
    int m_verInt;
    zSTRING m_verName;
    int m_notCompatible;

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

  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList;
    oCSavegameInfo* localInfo;
    bool initialized;

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