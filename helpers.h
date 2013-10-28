#ifndef HELPERS_H
#define HELPERS_H

#include <SWI-cpp.h>

#include <QString>

#ifndef PL_USE_WCHARS
#define PL_USE_WCHARS 1
#endif

class Helpers
{
public:
    Helpers();

#if PL_USE_WCHARS
    static QString fromPlString(wchar_t * s);
    static const wchar_t * toPlString(QString s);
#else
    static QString fromPlString(char * s);
    static const char * toPlString(QString s);
#endif
};

#endif // HELPERS_H
