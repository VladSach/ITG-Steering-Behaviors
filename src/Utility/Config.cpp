#include "Config.h"

Config *Config::config_ = nullptr;

Config *Config::GetInstance() {
    if (config_ == nullptr) {
        config_ = new Config();
    }

    return config_;
}

void Config::loadConfig(){
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
            hunterBulletsAmount = stringToInt(value.c_str(), 
                                                     value.length());
        } else if (name == "Rabbits") {
            rabbitsAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "Does") {
            doesAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "Wolves") {
            wolvesAmount = stringToInt(value.c_str(), value.length());
        } else if (name == "DoesPerFlock") {
            doesPerFlock = stringToInt(value.c_str(), value.length());
        } else if (name == "WindowHeight") {
            mainWindowHeight = stringToInt(value.c_str(), value.length());
        } else if (name == "WindowWidth") {
            mainWindowWidth = stringToInt(value.c_str(), value.length());
        }
    }
}