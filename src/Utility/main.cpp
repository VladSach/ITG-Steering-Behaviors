#include "Config.h"
#include "MainWindow.h"
#include "Game.h"
#include "Controller.h"

int main(){
    Config *config = Config::GetInstance();
    config->loadConfig();

    Game game;
    MainWindow window(&game);

    Controller controller(&game, &window);
    controller.start();
    
    return 0;
}