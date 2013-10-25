#include "app.h"
#include "ui_app.h"

#include "swipl_container.h"

#include <QDebug>
#include <QFile>

App::App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);

    // Run main logic here
    // Not the best place but it'll work for now

    qDebug() << "Initializtion finished!";

    SWIPLContainer & swipl = SWIPLContainer::instance();

    QString autoload_filename("autoload.pl"); // hardcoding this so far

    // Catch errors and show them to user
    if(QFile(autoload_filename).exists())
    {
        qDebug() << "Trying to autoload file:" << autoload_filename;
        try
        {
            // Load init file
            if(swipl.consult(autoload_filename)) qDebug() << "Database autoloaded successfully!";
        }
        catch ( PlException & ex )
        {
            qDebug() << "Prolog has thrown an exception during database autoload: " << QString(ex);
        }
    }

}

App::~App()
{
    delete ui;
}
