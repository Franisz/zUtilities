// Supported with union (c) 2018-2021 Union team

#ifndef __ZGOTHIC_API_H__
#define __ZGOTHIC_API_H__

#define Engine_G1  1
#define Engine_G1A 2
#define Engine_G2  3
#define Engine_G2A 4


#pragma warning(disable:4244)
// gothic api for Gothic I v1.08k_mod
#define ENGINE Engine_G1
#include "Gothic_I_Classic/API/zEngine.h"
#include "Gothic_I_Classic/VFTable_G1.h"


// gothic api for Gothic Sequel v1.12f (bin)
#define ENGINE Engine_G1A
#include "Gothic_I_Addon/API/zEngine.h"
#include "Gothic_I_Addon/VFTable_G1A.h"


// gothic api for Gothic II classic v1.30
#define ENGINE Engine_G2
#include "Gothic_II_Classic/API/zEngine.h"
#include "Gothic_II_Classic/VFTable_G2.h"


// gothic api for Gothic II NOTR v2.6 (fix)
#define ENGINE Engine_G2A
#include "Gothic_II_Addon/API/zEngine.h"
#include "Gothic_II_Addon/VFTable_G2A.h"
#pragma warning(default:4244)

#endif // __ZGOTHIC_API_H__