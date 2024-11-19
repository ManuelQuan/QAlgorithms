#pragma once

#include <QtCore/qglobal.h>
#ifndef BUILD_STATIC
# if defined(LEETCODE_LIB)
#  define LEETCODE_EXPORT Q_DECL_EXPORT
# else
#  define LEETCODE_EXPORT Q_DECL_IMPORT
# endif
#else
# define LEETCODE_EXPORT
#endif
