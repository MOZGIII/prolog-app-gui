#ifndef SWIPL_CONTAINER_H
#define SWIPL_CONTAINER_H

#include "prolog-api.h"

#include <SWI-cpp.h>

#include <QString>
#include <QStringList>

// Singleton class
// Responds for prolog engine interaction
class SWIPLContainer
{
public:
    virtual ~SWIPLContainer();

    // Singleton
    static SWIPLContainer &instance(void);
    static void unload(void);

    int call(const QString &command);
    bool consult(const QString &filename);

private:
    // Singleton
    SWIPLContainer();
    SWIPLContainer(int argc, char **argv);
    SWIPLContainer(const QStringList &args);
    Q_DISABLE_COPY(SWIPLContainer)

    void __init(int argc, char **argv);

    static SWIPLContainer * __instance;

};

#endif // SWIPL_CONTAINER_H
