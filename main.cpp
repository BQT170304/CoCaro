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
	if (sound == NULL)
	{
		cout << Mix_GetError();
		exit(1);
	}
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
                    if(choice == ONE_PLAYER) {
                        bot_move(game, renderer);
                    }
                    SDL_RenderPresent(renderer);
                }
                break;
            default: {}
            }
        }
        if (choice == EXIT) break;
        SDL_RenderPresent(renderer);
        game.state = check_win(game.board);
        choice = game_state(renderer, game, choice);
    }
    quit(window, renderer);
    return 0;
}


