#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include "sdl_init.h"
#include "text_obj.h"
#include "game_func.h"
#include "one_player.h"
using namespace std;

int main(int argc, char* argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer = nullptr;
    Mix_Chunk *sound = nullptr;
    init(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE.c_str());
    sound = Mix_LoadWAV("sound/tap_sound.wav");
    Game game;
    int choice = start_menu(renderer, game);
    SDL_Event e;
    while (choice != EXIT) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                choice = EXIT;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (game.board[e.button.x/CELLWIDTH][e.button.y/CELLWIDTH] == EMPTY) {
                    Mix_PlayChannel(-1, sound, 0);
                    click_on_cell(game, renderer, e.button.x/CELLWIDTH, e.button.y/CELLWIDTH);
                    SDL_RenderPresent(renderer);
                    game.state = check_win(game.board, game.cur_move);
                    if (game.state!=RUNNING) {
                        choice = game_state(renderer, game, choice);
                        continue;
                    }
                    if(choice == ONE_PLAYER) {
                        bot_move(game, renderer);
                    }
                    SDL_RenderPresent(renderer);
                }
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_r:
                        new_game(renderer, game);
                        SDL_RenderPresent(renderer);
                        break;
                    case SDLK_ESCAPE:
                        choice = EXIT;
                        break;
                }
            default: {}
            }
        }
        if (choice == EXIT) break;
        SDL_RenderPresent(renderer);
        game.state = check_win(game.board, game.cur_move);
        choice = game_state(renderer, game, choice);
    }
    quit(window, renderer);
    return 0;
}


