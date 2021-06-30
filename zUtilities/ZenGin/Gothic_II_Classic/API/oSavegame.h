// Supported with union (c) 2018 Union team

#ifndef __OSAVEGAME_H__VER2__
#define __OSAVEGAME_H__VER2__

#include "zBuffer.h"

namespace Gothic_II_Classic {

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

    void oCSavegameInfo_OnInit()             zCall( 0x004366A0 );
    void oCSavegameInfo_OnInit( int )        zCall( 0x00436870 );
    zSTRING GetName()                        zCall( 0x0042A2F0 );
    zSTRING GetWorldName()                   zCall( 0x0042A340 );
    zSTRING GetSaveTime()                    zCall( 0x0042EE10 );
    oCSavegameInfo()                         zInit( oCSavegameInfo_OnInit() );
    oCSavegameInfo( int a0 )                 zInit( oCSavegameInfo_OnInit( a0 ));
    void Init()                              zCall( 0x00436A10 );
    int DoesSavegameExist()                  zCall( 0x00436BE0 );
    void UpdateThumbPic( zCTextureConvert* ) zCall( 0x00436BF0 );
    zSTRING GetDir()                         zCall( 0x00436E10 );
    void ReloadResources()                   zCall( 0x00436E60 );
    void CleanResources()                    zCall( 0x00437050 );
    void SetSlot( int )                      zCall( 0x00437080 );
    zSTRING GetGameTime()                    zCall( 0x00437F40 );
    static zCObject* _CreateNewInstance()    zCall( 0x00436620 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00436830 );
    virtual void Archive( zCArchiver& )      zCall( 0x00437470 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x004379C0 );
    virtual ~oCSavegameInfo()                zCall( 0x00437310 );

    // user API
    #include "oCSavegameInfo.inl"
  };

  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList;
    oCSavegameInfo* localInfo;
    bool initialized;

    void oCSavegameManager_OnInit()                  zCall( 0x004381F0 );
    oCSavegameManager()                              zInit( oCSavegameManager_OnInit() );
    void Init()                                      zCall( 0x00438490 );
    void Reinit()                                    zCall( 0x00438A40 );
    void CleanResources()                            zCall( 0x00438A50 );
    void SetAndWriteSavegame( int, oCSavegameInfo* ) zCall( 0x00438AB0 );
    oCSavegameInfo* GetSavegame( int )               zCall( 0x00438CB0 );
    void CopyToCurrent( int )                        zCall( 0x00438CE0 );
    void CopyFromCurrent( int )                      zCall( 0x00438E90 );
    void ClearCurrent()                              zCall( 0x00439040 );
    zSTRING GetSlotDirName( int )                    zCall( 0x00439180 );
    virtual ~oCSavegameManager()                     zCall( 0x004383D0 );

    // user API
    #include "oCSavegameManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OSAVEGAME_H__VER2__