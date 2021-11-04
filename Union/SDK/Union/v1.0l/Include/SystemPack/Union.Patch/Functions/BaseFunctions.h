// Supported with union (c) 2018-2021 Union team

#ifndef __SYSTEMPACK_PATCH_BASE_FUNCTIONS_H__
#define __SYSTEMPACK_PATCH_BASE_FUNCTIONS_H__

namespace SystemPack
{
	struct ASTAPI CPatchFuncSqrt : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncSqrt);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncMessageBox : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncMessageBox);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncPrintScreen : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncPrintScreen);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncAllocPage : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncAllocPage);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncFreePage : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncFreePage);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncGetHexSize : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncGetHexSize);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncSetHexSize : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncSetHexSize);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncSetHexAutoSize : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncSetHexAutoSize);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncLoadLibrary : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncLoadLibrary);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncModuleBase : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncModuleBase);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncMin : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncMin);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncMax : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncMax);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI CPatchFuncLim : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncLim);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncHexViewBox : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncHexViewBox);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncFindAndReplace : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncFindAndReplace);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncOptionDef : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncOptionDef);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncModuleSize : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncModuleSize);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncShowCmd : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncShowCmd);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncHideCmd : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncHideCmd);
		virtual	CPatchType*	Execute();
	};

	struct ASTAPI  CPatchFuncImportSymbol : public CPatchFunction
	{
		PATCH_CLASS_DECLARATION(CPatchFuncImportSymbol);
		virtual	CPatchType*	Execute();
	};
} // namespace SystemPack

#endif // __SYSTEMPACK_PATCH_BASE_FUNCTIONS_H__