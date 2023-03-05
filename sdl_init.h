#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using namespace std;

const SDL_Color MENU_COLOR = {255, 255, 200};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREY_COLOR = {100, 100, 100};

void init(SDL_Window* &window, SDL_Renderer* &renderer, int screenW, int screenH, const char* windowTitle);

void quit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture *texture);

void setColor(SDL_Renderer *renderer, SDL_Color color);

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

#endif
