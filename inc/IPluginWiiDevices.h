/* WiiDevices_Plugin - for licensing and copyright see license.txt */

#include <IPluginBase.h>

#pragma once

/**
* @brief WiiDevices Plugin Namespace
*/
namespace WiiDevicesPlugin
{
    /**
    * @brief plugin WiiDevices concrete interface
    */
    struct IPluginWiiDevices
    {
        /**
        * @brief Get Plugin base interface
        */
        virtual PluginManager::IPluginBase* GetBase() = 0;

        // TODO: Add your concrete interface declaration here
    };
};