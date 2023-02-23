#include <bits/stdc++.h>
#include <SDL.h>
#include "sdl_init.h"
#include "text_obj.h"
#include "game_func.h"
using namespace std;

int main(int argc, char* argv[]) {
    SDL_Window *window;
    //SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Renderer *renderer = nullptr;
    init(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE.c_str());
    Game game;
    int choice = start_menu(renderer);
    if (choice != EXIT) new_game(renderer, game);
    SDL_Event e;
    while (choice != EXIT) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                choice = EXIT;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (e.button.x < 3*CELLWIDTH && e.button.y < 3*CELLWIDTH) {
                    click_on_cell(game, renderer, texture, e.button.x/CELLWIDTH, e.button.y/CELLWIDTH);
                }
            default: {}
            }
        }
        if (choice == EXIT) break;
        SDL_RenderPresent(renderer);
        game.state = check_win(game.board);
        choice = game_state(renderer, game);
    }
    quit(window, renderer, texture);
    return 0;
}


