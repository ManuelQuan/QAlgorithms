#pragma once

#include <QtCore/qglobal.h>
#ifndef BUILD_STATIC
# if defined(DATA_STRUCTURES_EXPORT)
#  define DATA_STRUCTURES_EXPORT Q_DECL_EXPORT
# else
#  define DATA_STRUCTURES_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATA_STRUCTURES_EXPORT
#endif
