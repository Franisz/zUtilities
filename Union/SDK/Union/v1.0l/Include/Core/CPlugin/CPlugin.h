// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_PLUGIN_H__
#define __UNION_PLUGIN_H__

namespace UnionCore
{
  class CPlugin
  {
    CStringA sPluginDLL;
    HPLUGIN  hModule;

    CPlugin();
    ~CPlugin();

  public:
    ASTAPI CStringA GetName() const;
    ASTAPI HPLUGIN GetModule() const;
           
           static void    LoadModules( CStringA );
           static void    ExitModules();
    ASTAPI static HMODULE GetGothicModule();
    ASTAPI static HMODULE GetAgamaModule();
    ASTAPI static HMODULE FindModule( CStringA );
           static void    ClearStorage();

    ASTAPI static const CList<CPlugin>& GetPluginList();
    ASTAPI static const CPlugin*        GetCurrentPlugin();
  };

  HPLUGIN ASTAPI LoadLibraryAST( const CStringA& name );
} // namespace UnionCore

#endif // __UNION_PLUGIN_H__