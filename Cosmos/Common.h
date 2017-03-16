#ifndef COMMON_H
#define COMMON_H

#ifdef WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#pragma comment(lib, "libmysql.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "secur32.lib")

#endif

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "mysql.h"

#endif
