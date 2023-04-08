#ifndef ONE_PLAYER_H
#define ONE_PLAYER_H

#include "sdl_init.h"
#include "game_func.h"
#define ARROW_WIDTH 70
#define ARROW_HEIGHT 50

int minimax(int board[3][3], int depth, int mx, int mn, bool isMaximize);
void bot_move(Game &game, SDL_Renderer* renderer);
int difficulty(SDL_Renderer* renderer, Game &game);

#endif // ONE_PLAYER_H
