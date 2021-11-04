// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_SPLASH_H__
#define __UNION_SPLASH_H__

namespace UnionCore
{
  class CSplash;

  typedef CSplash*(__cdecl* LPSPLASHCREATIONFUNC)();

  class ASTAPI CSplash {
    static CList<CSplash> SplashList;

    HWND     Window;
    WNDCLASS WindowClass;
    HMODULE  Module;
    bool     UseAlpha;
    uint     AlphaColor;
    HBITMAP  BitmapDIB;

    static LPSPLASHCREATIONFUNC SplashCreationFunc;

  public:
    CSplash();
    bool RegisterWindowClass();
    bool CreateSplashWindow();
    HWND GetWindow();
    int GetWidth();
    int Getheight();
    int GetPosX();
    int GetPosY();
    long Alpha;
    void Show();
    void Hide();
    void SetUseAlpha( const bool& use, const uint& color );
    bool LoadBitmapFromResource( HMODULE module, const uint& resource );
    bool LoadBitmapFromFile( const CStringA& file );

    void PrintText(
      const CStringW& text,
      const long& size,
      const long& x,
      const long& y,
      const CStringW& font = L"Times New Roman",
      const uint& color = RGB( 255, 255, 255 ),
      const uint& dtAlign = DT_LEFT | DT_BOTTOM
      );

    void PrintText(
      const CStringW& text,
      const long& size,
      const long& x,
      const long& y,
      const uint& dtAlign = DT_LEFT | DT_BOTTOM
      );


    static void DrawProc( CSplash* splash );
    static void Create( CSplash*& splash );
    static CSplash* CreateAsync();
    static long32 __stdcall SplashWindowProc( HWND hwnd, uint msg, uint wpar, long32 lpar );
    static HBITMAP GetBitmap( HWND hwnd );
    static LPSPLASHCREATIONFUNC GetSplashCreationFunc();
    static void SetSplashCreationFunc( LPSPLASHCREATIONFUNC );
    ~CSplash();
  };
}

#endif // __UNION_SPLASH_H__