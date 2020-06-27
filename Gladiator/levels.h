#ifndef __LEVELS_H__
#define __LEVELS_H__

#include<vector>

#include "gladiator.h"

typedef bool (*level_t)(Gladiator&);

std::vector<level_t> load_levels();

#endif // !__LEVELS_H__


