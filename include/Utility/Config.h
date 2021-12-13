#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "utility.h"

class Config {
protected:
    Config(){};
    static Config *config_;

public:
    int hunterBulletsAmount = 0;
    int rabbitsAmount       = 0;
    int doesAmount          = 0;
    int wolvesAmount        = 0;
    int doesPerFlock        = 0;
    int mainWindowWidth     = 0;
    int mainWindowHeight    = 0;


    Config(Config &other) = delete;
    void operator= (const Config &) = delete;
    static Config *GetInstance();

    void loadConfig();
};


#endif // CONFIG_H