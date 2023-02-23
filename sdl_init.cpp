#include "sdl_init.h"

void init(SDL_Window* &window, SDL_Renderer* &renderer, int screenW, int screenH, const char* windowTitle) {
    if (SDL_Init(SDL_INIT_EVERYTHING)==0 && TTF_Init()==0) {
        window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_SHOWN);
        if (window == nullptr) cout << "Error: Create Window\n";
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) cout << "Error: Create Renderer\n";
        SDL_RenderSetLogicalSize(renderer, screenW, screenH);
    }
    else {
        cout << "Can't initialize window\n";
        exit(1);
    }
}

void quit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture *texture) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_Quit();
}

void setColor(SDL_Renderer *renderer, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}
