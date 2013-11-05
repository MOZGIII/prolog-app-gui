#ifndef PROLOGAPI_H
#define PROLOGAPI_H

#include "helpers.h"

#include <SWI-cpp.h>

#include <QDebug>
#include <QString>

PREDICATE(log, 1)
{
    qDebug() << "PLLOG:" << Helpers::fromPlString(A1);
    return TRUE;
}

PREDICATE(payload, 1)
{
    Helpers::writePayload(Helpers::fromPlString(A1));
    return TRUE;
}

#endif // PROLOGAPI_H
