#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdlib.h>


inline int rand_range(int min, int max) { return min + rand() % (max + 1 - min); }

#endif // !__UTILS_H__