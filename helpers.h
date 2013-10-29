#ifndef HELPERS_H
#define HELPERS_H

#include <SWI-cpp.h>

#include <QString>

#ifndef PL_USE_WCHARS
#define PL_USE_WCHARS 0
#endif

class Helpers
{
public:
    Helpers();

#if PL_USE_WCHARS != 0
#   define PR_CHAR_T wchar_t*
#   define toPlString(s) (s.toStdWString().c_str())  // allocates string on heap!
#else
#   define PR_CHAR_T char*
#   define toPlString(s) (s.toStdString().c_str())  // allocates string on heap!
#endif

    static QString fromPlString(PR_CHAR_T s);
};

#endif // HELPERS_H
