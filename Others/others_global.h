#ifndef OTHERS_GLOBAL_H
#define OTHERS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OTHERS_LIBRARY)
#  define OTHERSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OTHERSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // OTHERS_GLOBAL_H
