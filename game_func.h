#ifndef GAME_FUNC_H
#define GAME_FUNC_H

#include <bits/stdc++.h>
#include <SDL.h>
#include "sdl_init.h"
#include "text_obj.h"

using namespace std;
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define CELLWIDTH 200
#define MENU_WIDTH 540
#define MENU_HEIGHT 540
// define players
#define EMPTY 0
#define X 1
#define O 2
// define game states
#define RUNNING 0
#define X_WIN 1
#define O_WIN 2
#define TIE 3
// define choices
#define ONE_PLAYER 0
#define PLAY_AGAIN 0
#define TWO_PLAYER 1
#define MENU 1
#define EXIT 2
const string WINDOW_TITLE = "Tic Tac Toe 2023";

struct Game {
    int board[3][3];
    int player;
    int state;
};

/*  Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
    Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
*/

bool check_select (int xm, int ym, int x, int y, int w, int h);

bool check_select (int xm, int ym, const Text &t);

int start_menu(SDL_Renderer* renderer, Game &game);

int game_menu(SDL_Renderer* renderer);

void new_game(SDL_Renderer* renderer, Game &game);

void reset_game(SDL_Renderer *renderer, Game &game);

void load_background(SDL_Renderer* renderer);

void load_start_background(SDL_Renderer* renderer);

void draw_board(SDL_Renderer *renderer);

void click_on_cell(Game &game, SDL_Renderer *renderer, int row, int col);

void switch_player (Game &game);

int empty_cells(Game &game);

void draw_cells(SDL_Renderer *renderer, int board[3][3]);

void draw_X(SDL_Renderer *renderer, int x, int y, int w, int h);

void draw_O(SDL_Renderer *renderer, int x, int y, int w, int h);

int check_win(int board[3][3]);

int game_state (SDL_Renderer* renderer, Game &game, int mode);

void X_win_state (SDL_Renderer* renderer, TTF_Font* font);

void O_win_state (SDL_Renderer* renderer, TTF_Font* font);

void tie_state (SDL_Renderer* renderer, TTF_Font* font);

#endif // GAME_FUNC_H
