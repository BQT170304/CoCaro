#ifndef TEXT_OBJ_H
#define TEXT_OBJ_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_init.h"
using namespace std;
struct Text {
    string text_val;
    SDL_Color text_color;
    int x,y,w,h;
    void set_Text(string _text_val, SDL_Color _text_color, int _x, int _y, int _w, int _h);
    void create_Text_texture(TTF_Font* font, SDL_Renderer *renderer);
};

#endif // TEXT_OBJ_H
