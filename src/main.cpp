#include "app.h"
#include <QApplication>

#include "logger.h"
#include "swipl_container.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Init logging system
    Logger::init();

    // Init swipl
    SWIPLContainer::instance();

    // Load app
    App w;
    w.show();

    // Remember exitcode
    int result = a.exec();

    // Unload Prolog
    SWIPLContainer::unload();

    // Restore exitcode
    return result;
}
