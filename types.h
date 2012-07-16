#pragma once

#include <array>
#include <vector>
#include "constants.h"

using std::array;
using std::vector;

typedef int int32;
typedef unsigned char byte;

typedef array<int, COLORS_COUNT> Hystogram;

struct LevelsDistribution {
    byte background;
    byte foreground;
};

typedef vector<vector<LevelsDistribution> > GlobalLevelsDistribution;
