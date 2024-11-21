#pragma once

#include <QtCore/qglobal.h>
#ifndef BUILD_STATIC
# if defined(GENERAL_ALGORITHMS_EXPORT)
#  define GENERAL_ALGORITHMS_EXPORT Q_DECL_EXPORT
# else
#  define GENERAL_ALGORITHMS_EXPORT Q_DECL_IMPORT
# endif
#else
# define GENERAL_ALGORITHMS_EXPORT
#endif
