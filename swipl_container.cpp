#include "swipl_container.h"

#include "helpers.h"

#include <QDebug>
#include <QCoreApplication>

// Implementing singleton
SWIPLContainer * SWIPLContainer::__instance = NULL;

SWIPLContainer & SWIPLContainer::instance(void)
{
    if(__instance == NULL) __instance = new SWIPLContainer();
    return *__instance;
}

void SWIPLContainer::unload(void)
{
    if(__instance != NULL) delete __instance;
    __instance = NULL;
}

// Constructors
SWIPLContainer::SWIPLContainer(const QStringList &args)
{
    char *av[args.size()+1];

    for(int i = 0; i < args.size(); i++) {
        av[i] = (char *)((const char *) args.at(i).toAscii());
    }
    av[args.size()] = NULL;

    __init(args.size(), av);
}

SWIPLContainer::SWIPLContainer()
{
    // Run with empty params by default
    char *argv[] = { (char*) QCoreApplication::argv()[0],
                     (char*) "-g",
                     (char*) "true",
                     NULL };
    __init(3, argv);
}


SWIPLContainer::SWIPLContainer(int argc, char **argv)
{
    __init(argc, argv);
}

void SWIPLContainer::__init(int argc, char **argv)
{
    if ( !PL_initialise(argc, argv) ) {
        qDebug() << "Unable to initialize Prolog engine!";
        PL_halt(1); // will terminate the process!
        return; // we never get here, but still
    }

    qDebug() << "Prolog successfully initialized!";
}

// Destructor
SWIPLContainer::~SWIPLContainer()
{
    qDebug() << "Cleaning up Prolog engine...";
    PL_cleanup(0);
    qDebug() << "Prolog successfully cleaned up!";
}

// Implementation

// Call the arbitrary command
int SWIPLContainer::call(const QString &command)
{
    return PlCall("call", PlTermv(PlCompound(Helpers::toPlString(command))));
}

// Load database into the engine
bool SWIPLContainer::consult(const QString &filename)
{
    return PlCall("consult", PlTerm(Helpers::toPlString(filename)));
}
