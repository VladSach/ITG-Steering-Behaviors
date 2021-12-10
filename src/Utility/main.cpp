#include "Config.h"
#include "MainWindow.h"
#include "Game.h"
#include "Controller.h"

int main(){
    Config config;
    loadConfig(config);

    Game game(config);
    MainWindow window(&game, config);

    Controller controller(&game, &window);
    controller.start();
    
    return 0;
}