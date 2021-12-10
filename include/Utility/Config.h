#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "utility.h"

struct Config {
    int hunterBulletsAmount = 0;
    int rabbitsAmount       = 0;
    int doesAmount          = 0;
    int wolvesAmount        = 0;
    int mainWindowWidth     = 0;
    int mainWindowHeight    = 0;
};

void loadConfig(Config& config);

#endif // CONFIG_H