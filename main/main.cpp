#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    while (true) {
        Game* game = new Game;
        game->run();
        if (game->restart == 1) {
            while (true) {
                Game* game_1 = new Game;
                game_1->game_loop();
                if (game_1->restart == 2) {
                    game->restart = 2;
                    break;
                }
                if (game_1->restart == 1) {
                    delete game_1;
                }
                if (game_1->restart == 3) {
                    break;
                }
            }
        }
        if (game->restart == 3) {
            delete game;
        }
        if (game->restart == 2) {
            break;
        }
    }
    return 0;
}