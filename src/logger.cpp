#include "logger.h"

#include <stdio.h>

Logger Logger::main;

Logger::Logger(QObject *parent) :
    QObject(parent)
{
}

void Logger::messageHandler(QtMsgType type, const char *msg)
{
    Q_UNUSED(type);
    main.log(QString::fromUtf8(msg));
}

void Logger::log(const QString &text)
{
    emit onLog(text);
}

Logger * Logger::current()
{
    return &main;
}

void Logger::init()
{
    // Connect stderr logger
    connect(current(), SLOT(logToStderr(QString)));

    // Register handler
    qInstallMsgHandler(messageHandler);
}

bool Logger::connect(const QObject *receiver, const char *method, Qt::ConnectionType type)
{
    return QObject::connect(current(), SIGNAL(onLog(QString)), receiver, method, type);
}

void Logger::logToStderr(const QString &text)
{
    fprintf(stderr, "%s\n", text.toLocal8Bit().constData());
    fflush(stderr);
}
