/* WiiDevices_Plugin - for licensing and copyright see license.txt */

#pragma once

#include <IPluginBase.h>
#include <Game.h>

#include <IPluginManager.h>
#include <CPluginBase.hpp>

#include <IPluginWiiDevices.h>

#define PLUGIN_NAME "WiiDevices"
#define PLUGIN_CONSOLE_PREFIX "[" PLUGIN_NAME " " PLUGIN_TEXT "] " //!< Prefix for Logentries by this plugin

namespace WiiDevicesPlugin
{
    /**
    * @brief Provides information and manages the resources of this plugin.
    */
    class CPluginWiiDevices :
        public PluginManager::CPluginBase,
        public IPluginWiiDevices
    {
        public:
            CPluginWiiDevices();
            ~CPluginWiiDevices();

            // IPluginBase
            bool Release( bool bForce = false );

            int GetInitializationMode() const
            {
                return int( PluginManager::IM_Default );
            };

            bool Init( SSystemGlobalEnvironment& env, SSystemInitParams& startupParams, IPluginBase* pPluginManager, const char* sPluginDirectory );

            bool RegisterTypes( int nFactoryType, bool bUnregister );

            const char* GetVersion() const
            {
                return "1.0.0.0";
            };

            const char* GetName() const
            {
                return PLUGIN_NAME;
            };

            const char* GetCategory() const
            {
                return "Flownode";
            };

            const char* ListAuthors() const
            {
                return "Nicolas Lefevre <nicolas.lefevre at unicaen dot fr>";
            };

            const char* ListCVars() const;

            const char* GetStatus() const;

            const char* GetCurrentConcreteInterfaceVersion() const
            {
                return "1.0";
            };

            void* GetConcreteInterface( const char* sInterfaceVersion )
            {
                return static_cast < IPluginWiiDevices* > ( this );
            };

            // IPluginWiiDevices
            IPluginBase* GetBase()
            {
                return static_cast<IPluginBase*>( this );
            };

            // TODO: Add your concrete interface implementation
    };

    extern CPluginWiiDevices* gPlugin;
}

/**
* @brief This function is required to use the Autoregister Flownode without modification.
* Include the file "CPluginWiiDevices.h" in front of flownode.
*/
inline void GameWarning( const char* sFormat, ... ) PRINTF_PARAMS( 1, 2 );
inline void GameWarning( const char* sFormat, ... )
{
    va_list ArgList;
    va_start( ArgList, sFormat );
    WiiDevicesPlugin::gPlugin->LogV( ILog::eWarningAlways, sFormat, ArgList );
    va_end( ArgList );
};
