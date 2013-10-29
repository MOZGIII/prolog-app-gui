#include "app.h"
#include "ui_app.h"

#include "swipl_container.h"
#include "logger.h"

#include <QDebug>
#include <QFile>

App::App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);

    // Connect UI logger
    QObject::connect(Logger::current(), SIGNAL(onLog(QString)), this, SLOT(writeLog(QString)));

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
        catch (PlException &ex)
        {
            qDebug() << "Prolog has thrown an exception during database autoload:" << QString(ex);
        }
    }

}

App::~App()
{
    delete ui;
}

void App::writeLog(const QString &text)
{
    ui->logText->appendPlainText(text);
}

void App::writePayload(const QString &text)
{
    ui->payloadResult->appendPlainText(text);
}

void App::on_payloadCalculate_clicked()
{
    // We must store input parameter on heap util Prolog returns
    // Allocate byte array here so it exists for the whole execution
    QByteArray storage(ui->payloadInput->text().toLocal8Bit());

    try
    {
        PlTermv av(2);
        av[0] = PlCompound(storage.constData());

        PlQuery q("external_app_call", av);

        while(q.next_solution())
            emit writePayload(Helpers::fromPlString(av[1]));

    }
    catch(PlException &ex)
    {
        qDebug() << "Prolog exception:" << QString(ex);
    }
}
