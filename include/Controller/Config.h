#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

struct Config {
    int hunterBulletsAmount = 0;
};

void loadConfig(Config& config);

#endif // CONFIG_H