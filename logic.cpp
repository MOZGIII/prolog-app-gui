#include "logic.h"

#include "swipl_container.h"
#include "helpers.h"

#include <QDebug>
#include <QFileInfo>
#include <QProcessEnvironment>
#include <QList>

Logic & Logic::instance()
{
    static Logic _instance;
    return _instance;
}

Logic::Logic(QObject *parent) :
    QObject(parent)
{
}

void Logic::autoload()
{
    SWIPLContainer & swipl = SWIPLContainer::instance();

    QFileInfo autoload_file(QProcessEnvironment::systemEnvironment().value("PL_AUTOLOAD_PATH", "autoload.pl"));

    // Catch errors and show them to user
    if(autoload_file.exists())
    {
        qDebug() << "Trying to autoload file:" << autoload_file.absoluteFilePath();
        try
        {
            // Load init file
            if(swipl.consult(autoload_file.absoluteFilePath()))
                qDebug() << "Database autoloaded successfully!";
            else
                qDebug() << "Database autoload returned false!";
        }
        catch (PlException &ex)
        {
            qDebug() << "Prolog has thrown an exception during database autoload:" << QString(ex);
        }
    }
    else
    {
        qDebug() << "No autoload file was found at" << autoload_file.absoluteFilePath();
    }
}

// Calls function with arity equal to input list size + 1 and takes the last argument as an answer
void Logic::call_prolog_function(const QString &function, const QStringList &args)
{
    // We must store input parameter on heap util Prolog returns
    // Allocate byte array here so it exists for the whole execution

    PL_STDSTRING_T function_storage(toPlStdString(function));

    QList<PL_STDSTRING_T> args_storage;
    args_storage.reserve(args.size());

    for(int i = 0; i < args.size(); i++)
    {
        args_storage << toPlStdString(args.at(i));
    }

    try
    {
        PlTermv av(args_storage.size() + 1);
        for(int i = 0; i < args_storage.size(); i++)
        {
            av[i] = PlCompound(args_storage.at(i).c_str());
        }

        PlQuery q(function_storage.c_str(), av);

        while(q.next_solution())
            emit gotPayload(Helpers::fromPlString(av[args_storage.size()]));

    }
    catch(PlException &ex)
    {
        QString ex_text(ex);
        qDebug() << "Prolog exception:" << ex_text;
        emit gotException(ex_text);
    }
}
