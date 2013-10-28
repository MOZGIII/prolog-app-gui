#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0);

    // The main logging method
    void log(const QString &text);

    // The default logger object
    static Logger main;

    // Init function
    static void init();

    // Qt's Handler
    static void messageHandler(QtMsgType type, const char *msg);

    // Helpers
    static Logger *current();
    static bool connect(const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::UniqueConnection);
    
signals:
    void onLog(const QString &text);
    
public slots:
    void logToStderr(const QString &text);
    
};

#endif // LOGGER_H
