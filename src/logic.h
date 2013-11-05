#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QString>
#include <QStringList>

class Logic : public QObject
{
    Q_OBJECT

    friend class Helpers;
public:
    static Logic &instance();

    void autoload();
    void call_prolog_function(const QString &function, const QStringList &args);

private:
    explicit Logic(QObject *parent = 0);
    virtual ~Logic() {}
    Q_DISABLE_COPY(Logic)
    
signals:
    void gotPayload(const QString &text);
    void gotException(const QString &text);
    
public slots:
    
};

#endif // LOGIC_H
