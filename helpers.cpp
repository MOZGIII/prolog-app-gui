#include "helpers.h"

Helpers::Helpers()
{
}

#if PL_USE_WCHARS
QString Helpers::fromPlString(wchar_t * s)
{
    return QString::fromWCharArray((wchar_t *) s);
}
const wchar_t * Helpers::toPlString(QString s)
{
    return s.toStdWString().c_str();
}
#else
QString Helpers::fromPlString(char * s)
{
    return QString(s);
}
const char * Helpers::toPlString(QString s)
{
    return s.toLocal8Bit();
}
#endif
