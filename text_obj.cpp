#include "text_obj.h"

void Text::set_Text(string _text_val, SDL_Color _text_color, int _x, int _y, int _w, int _h) {
    text_val = _text_val; text_color = _text_color; x = _x; y = _y; w = _w; h = _h;
}

void Text::create_Text_texture(TTF_Font* font, SDL_Renderer *renderer) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text_val.c_str(), text_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    renderTexture(renderer, texture, x, y, w, h);
    SDL_FreeSurface(surface);
}
