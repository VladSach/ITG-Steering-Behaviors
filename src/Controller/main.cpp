#include "Config.h"

int main(){
    Config config;
    loadConfig(config);

    std::cout << config.hunterBulletsAmount << std::endl;
    return 0;
}