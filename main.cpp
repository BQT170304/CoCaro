#include <bits/stdc++.h>
#include <SDL.h>
#include "sdl_init.h"
#include "text_obj.h"
#include "game_func.h"
using namespace std;

int main(int argc, char* argv[]) {
    SDL_Window *window;
    SDL_Texture *texture = nullptr;
    SDL_Renderer *renderer = nullptr;
    Mix_Chunk *sound = nullptr;
    init(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE.c_str());
    sound = Mix_LoadWAV("tap_sound.wav");
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
                if (e.button.x < 3*CELLWIDTH && e.button.y < 3*CELLWIDTH) {
                    Mix_PlayChannel(-1, sound, 0);
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


