#include "app.h"
#include "ui_app.h"

#include "logger.h"
#include "logic.h"

#include <QDebug>

App::App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);

    // Connect UI logger
    QObject::connect(Logger::current(), SIGNAL(onLog(QString)), this, SLOT(writeLog(QString)));

    // Connect logic
    QObject::connect(&Logic::instance(), SIGNAL(gotPayload(QString)), this, SLOT(writePayload(QString)));
    QObject::connect(&Logic::instance(), SIGNAL(gotException(QString)), this, SLOT(writePayloadException(QString)));

    // We're done initilializing app's core
    qDebug() << "Initializtion finished!";

    // Try to autoload file now
    Logic::instance().autoload();
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

void App::writePayloadException(const QString &text)
{
    ui->payloadResult->appendHtml(QString("<i>%1</i>").arg(text));
}

void App::on_payloadCalculate_clicked()
{
    Logic::instance()
            .call_prolog_function("external_app_call",
                                  QStringList() << ui->payloadInput->text());
}
