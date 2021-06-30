// Supported with union (c) 2018 Union team

#ifndef __OSAVEGAME_H__VER0__
#define __OSAVEGAME_H__VER0__

#include "zBuffer.h"

namespace Gothic_I_Classic {

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
    int m_PlayTimeSeconds;
    int m_notCompatible;

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

  class oCSavegameManager {
  public:
    zCArray<oCSavegameInfo*> infoList;
    oCSavegameInfo* localInfo;
    bool initialized;

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