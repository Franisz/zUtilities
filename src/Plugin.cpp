// Disable macro redefinition warning
#pragma warning(disable : 4005)

#include <Union/Hook.h>
#include <ZenGin/zGothicAPI.h>

#ifdef __G1
#define GOTHIC_NAMESPACE Gothic_I_Classic
#define ENGINE Engine_G1
HOOKSPACE(Gothic_I_Classic, GetGameVersion() == ENGINE);
#include "Plugin.hpp"
#endif

#ifdef __G1A
#define GOTHIC_NAMESPACE Gothic_I_Addon
#define ENGINE Engine_G1A
HOOKSPACE(Gothic_I_Addon, GetGameVersion() == ENGINE);
#include "Plugin.hpp"
#endif

#ifdef __G2
#define GOTHIC_NAMESPACE Gothic_II_Classic
#define ENGINE Engine_G2
HOOKSPACE(Gothic_II_Classic, GetGameVersion() == ENGINE);
#include "Plugin.hpp"
#endif

#ifdef __G2A
#define GOTHIC_NAMESPACE Gothic_II_Addon
#define ENGINE Engine_G2A
HOOKSPACE(Gothic_II_Addon, GetGameVersion() == ENGINE);
#include "utils/Randomizer.h"
#include "utils/Colors.h"
#include "utils/Const.h"
#include "utils/User.hpp"
#include "utils/Misc.hpp"
#include "utils/KeyCode.h"
#include "utils/Extensions.h"
#include "features/QuickSave/QuickSave.h"
#include "features/DamagePopup/DamagePopup.h"
#include "utils/PlayerHelper.h"
#include "utils/Options.h"
#include "features/Meatbug/Meatbug.hpp"
#include "features/QuickSave/Quicksave.hpp"
#include "features/DamagePopup/DamagePopup.hpp"
#include "Plugin.hpp"
#endif

HOOKSPACE(Global, true);