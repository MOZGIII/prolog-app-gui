#include "app.h"
#include "ui_app.h"

#include "logger.h"
#include "logic.h"
#include "settings_manager.h"

#include <QDebug>

App::App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);

    // Set monospace font
    QFont monospace_font("Monospace");
    monospace_font.setStyleHint(QFont::TypeWriter);
    ui->logText->setFont(monospace_font);

    // Connect UI logger
    QObject::connect(Logger::current(), SIGNAL(onLog(QString)), this, SLOT(writeLog(QString)));

    // Connect logic
    QObject::connect(&Logic::instance(), SIGNAL(gotPayload(QString)), this, SLOT(writePayload(QString)));
    QObject::connect(&Logic::instance(), SIGNAL(gotException(QString)), this, SLOT(writePayloadException(QString)));

    // Load settings
    loadSettings();

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
    ui->payloadResult->appendHtml(text);
}

void App::writePayloadException(const QString &text)
{
    ui->payloadResult->appendHtml(QString("<i>%1</i>").arg(text));
}

void App::on_payloadCalculate_clicked()
{
    if(ui->settingsAutoReload->isChecked())
    {
        Logic::instance().autoload();
    }

    Logic::instance()
            .call_prolog_function("external_app_call",
                                  QStringList() << ui->payloadInput->text());
}

void App::loadSettings()
{
    ui->settingsAutoReload->setChecked(SettingsManager::instance().autoReload());
}

void App::on_settingsAutoReload_toggled(bool checked)
{
    SettingsManager::instance().setAutoReload(checked);
}
