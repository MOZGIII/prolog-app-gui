#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QSettings>

class SettingsManager
{
public:
    static SettingsManager &instance();

    QSettings settings;

    bool autoReload();
    void setAutoReload(bool val);

private:
    SettingsManager();
    virtual ~SettingsManager() {}
    Q_DISABLE_COPY(SettingsManager)

};

#endif // SETTINGS_MANAGER_H
