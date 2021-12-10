#include "Config.h"

void loadConfig(Config& config){
    std::ifstream configFile("config.ini");

    if (!configFile.is_open()) {
        std::cerr << "Couldn't open config file\n";
    }

    std::string line;
    while (getline(configFile, line)) {
        line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());

        if(line[0] == '#' || line[0] == ';' || line.empty()) 
            continue;

        auto delimiterPos = line.find("=");
        std::string name = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        if (name == "HunterBullets") {
            config.hunterBulletsAmount = stringToInt(value.c_str(), 
                                                     value.length());
        } else if (name == "Rabbits") {
            config.rabbitsAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "Does") {
            config.doesAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "Wolves") {
            config.wolvesAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "WindowHeight") {
            config.mainWindowHeight = stringToInt(value.c_str(), value.length());
        } else if (name == "WindowWidth") {
            config.mainWindowWidth = stringToInt(value.c_str(), value.length());
        }
    }
}