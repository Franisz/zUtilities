// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
#define Invalid (-1)
#define PLUGIN_NAME "ZUTILITIES"
#define VERSION_NUMBER "0.37"
#define printWin(a) ogame->GetTextView()->Printwin(a)
#define del(x)       \
    {                \
        delete x;    \
        x = nullptr; \
    }
}