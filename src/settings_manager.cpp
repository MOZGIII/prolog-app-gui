#include "settings_manager.h"

SettingsManager &SettingsManager::instance()
{
    static SettingsManager _instance;
    return _instance;
}

SettingsManager::SettingsManager() :
    settings("prolog-app-gui")
{
}

bool SettingsManager::autoReload()
{
    return settings.value("auto_reload", false).toBool();
}
void SettingsManager::setAutoReload(bool val)
{
    settings.setValue("auto_reload", val);
}
