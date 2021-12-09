#include "Config.h"

inline int stringToInt(const char *string, const int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + (string[i] - '0');
    }
    return result;
}

void loadConfig(Config& config){
    std::ifstream configFile("config.ini");

    if (!configFile.is_open()) {
        std::cerr << "Couldn't open config file\n";
    }

    std::string line;
    while (getline(configFile, line)) {
        line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());

        if(line[0] == '#' || line.empty()) continue;

        auto delimiterPos = line.find("=");
        std::string name = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        
        if (name == "hunterBulletsAmount") {
            config.hunterBulletsAmount = stringToInt(value.c_str(), 
                                                     value.length()-1);
        }
    }
}