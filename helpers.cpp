#include "helpers.h"

Helpers::Helpers()
{
}

#if PL_USE_WCHARS != 0
QString Helpers::fromPlString(wchar_t * s)
{
    return QString::fromWCharArray((wchar_t *) s);
}
#else
QString Helpers::fromPlString(char * s)
{
    return QString(s);
}
#endif
