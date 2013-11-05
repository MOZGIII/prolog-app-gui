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
#   define PL_CHAR_T wchar_t*
#   define PL_STDSTRING_T std::wstring
#   define toPlStdString(s) (s.toStdWString())  // allocates string on heap!
#else
#   define PL_CHAR_T char*
#   define PL_STDSTRING_T std::string
#   define toPlStdString(s) (s.toStdString())  // allocates string on heap!
#endif

    #define toPlString(s) (s.toStdString().c_str())  // allocates string on heap!
    static QString fromPlString(PL_CHAR_T s);

    static void writePayload(const QString &text);
};

#endif // HELPERS_H
