#pragma once
#include <stdlib.h>


inline int rand_range(int min, int max) { return min + rand() % (max + 1 - min); }