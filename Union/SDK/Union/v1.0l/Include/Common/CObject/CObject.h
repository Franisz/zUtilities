// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_OBJECT_H__
#define __UNION_OBJECT_H__

namespace Common {

  class CObject;
  struct CClassDef;

  typedef CObject* ( _cdecl* TClassInit ) ( );
  typedef CList <CClassDef> TDefList;
  typedef CList <CObject> TObjectList;
  typedef uint32 CID;

  class ASTAPI CClassDef
  {
    CString sClassName;
    TClassInit pCreateObject;
  public:
    CClassDef( const CString&, TClassInit );
    CString GetName();
    static TDefList lstDefs;
    static CObject* CreateClass( const CString& );
    static CObject* CreateClass( CClassDef* );
  };

  class ASTAPI CObject
  {
    friend class CArchiveSection;
    friend class CArchiver;
  protected:
    static TObjectList lstObjects;
    uint32 ulRef;

  public:
    CObject();
    virtual void Archive( CArchiver& )   = 0;
    virtual void Unarchive( CArchiver& ) = 0;
    virtual CClassDef* GetClassDef()     = 0;
    void AddRef();
    void Release();
    virtual ~CObject();
  };

#define COBJECT_CLASS_DELARATE(className)                         \
protected:                                                        \
 static CClassDef* classDef;                                      \
public:                                                           \
 static  CObject* CreateObject()        { return new className; } \
 static  CClassDef* GetClassDef_Class() { return classDef; }      \
 virtual CClassDef* GetClassDef()       { return classDef; }      \
private:

#define COBJECT_CLASS_DEFINE(className)   \
  CClassDef* className::classDef =        \
  new CClassDef(#className, &CreateObject);

#define GET_CLASS_CID(className) \
  (CID)className::GetClassDef_Class()

#define GET_OBJECT_CID(object) \
  (CID)(object)->GetClassDef()

#define GET_CLASSDEF(object) \
  (object)->GetClassDef()

} // namespace Common

#endif // __UNION_OBJECT_H__