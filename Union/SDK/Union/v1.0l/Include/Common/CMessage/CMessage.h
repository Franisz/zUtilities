// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_MESSAGE_H__
#define __UNION_MESSAGE_H__

namespace Common 
{
  EXTERN_C
  {
  typedef struct ASTAPI CMessageA {
    static int32  Box     (HWND hwnd, const CStringA& msg, const CStringA& title, UINT uType);
    static void   Box     (const CStringA& msg, const CStringA& title = "Union",          bool32 TopMost = False);
    static void   Info    (const CStringA& msg, const CStringA& title = "Union Info",     bool32 TopMost = False);
    static void   Error   (const CStringA& msg, const CStringA& title = "Union Error",    bool32 TopMost = True );
    static void   Warning (const CStringA& msg, const CStringA& title = "Union Warning",  bool32 TopMost = True );
    static bool32 Choice  (const CStringA& msg, const CStringA& title = "Union Choice",   bool32 TopMost = False);
    static bool32 Question(const CStringA& msg, const CStringA& title = "Union Question", bool32 TopMost = False);
    static bool32 Retry   (const CStringA& msg, const CStringA& title = "Union Retry",    bool32 TopMost = False);
    static void   Fatal   (const CStringA& msg, const CStringA& title = "Union Fatal",    bool32 TopMost = True );
  } 
  SayA, MessageA;


  typedef struct ASTAPI CMessageW {
    static int32  Box      (HWND hwnd, const CStringW& msg, const CStringW& title, UINT uType);
    static void   Box     (const CStringW& msg, const CStringW& title = L"Union",          bool32 TopMost = False);
    static void   Info    (const CStringW& msg, const CStringW& title = L"Union Info",     bool32 TopMost = False);
    static void   Error   (const CStringW& msg, const CStringW& title = L"Union Error",    bool32 TopMost = True );
    static void   Warning (const CStringW& msg, const CStringW& title = L"Union Warning",  bool32 TopMost = True );
    static bool32 Choice  (const CStringW& msg, const CStringW& title = L"Union Choice",   bool32 TopMost = False);
    static bool32 Question(const CStringW& msg, const CStringW& title = L"Union Question", bool32 TopMost = False);
    static bool32 Retry   (const CStringW& msg, const CStringW& title = L"Union Retry",    bool32 TopMost = False);
    static void   Fatal   (const CStringW& msg, const CStringW& title = L"Union Fatal",    bool32 TopMost = True );
  } 
  SayW, MessageW;

#ifdef UNICODE
  typedef CMessageW Say, Message;
#else
  typedef CMessageA Say, Message;
#endif
  }
} // namespace Common

#endif // __UNION_MESSAGE_H__