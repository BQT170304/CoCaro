#include "game_func.h"

bool check_select (int xm, int ym, const Text &t) {
    if ((xm > t.x && xm < t.x + t.w) && (ym > t.y && ym < t.y + t.h))
        return true;
    return false;
}

int start_menu(SDL_Renderer* renderer) {
    setColor(renderer, MENU_COLOR);
    SDL_RenderClear(renderer);
    TTF_Font *title_font = TTF_OpenFont("font/Branda-yolq.ttf", 90);
    TTF_Font *choice_font = TTF_OpenFont("font/Branda-yolq.ttf", 40);
    Text title; title.set_Text("Tic Tac Toe", BLACK_COLOR, SCREEN_WIDTH/4, 100, SCREEN_WIDTH/2, 100);
    title.create_Text_texture(title_font, renderer);
    Text choices[3];
    choices[0].set_Text("One Player", BLACK_COLOR, SCREEN_WIDTH*3/8, 250, SCREEN_WIDTH/4, 48);
    choices[1].set_Text("Two Player", BLACK_COLOR, SCREEN_WIDTH*3/8, 350, SCREEN_WIDTH/4, 48);
    choices[2].set_Text("Exit", BLACK_COLOR, SCREEN_WIDTH*7/16, 450, SCREEN_WIDTH/8, 48);
    for (int i=0;i<3;i++)
        choices[i].create_Text_texture(choice_font, renderer);
    SDL_RenderPresent(renderer);
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e)) {
            SDL_Delay(100);
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int xm = e.button.x, ym = e.button.y;
                for (int i=0;i<3;i++) {
                    if (check_select(xm, ym, choices[i]))
                        return i;
                }
            } else if (e.type == SDL_QUIT)
                return EXIT;
        }
    }
}

int game_menu(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/menu.png");
    SDL_Texture* menu = SDL_CreateTextureFromSurface(renderer, surface);
    renderTexture(renderer, menu, SCREEN_WIDTH/2-MENU_WIDTH/2,
                   SCREEN_HEIGHT/2-MENU_HEIGHT/2-50, MENU_WIDTH, MENU_HEIGHT);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(menu);
    TTF_Font *choice_font = TTF_OpenFont("font/Branda-yolq.ttf", 48);
    Text choices[2];
    choices[0].set_Text("Play again", WHITE_COLOR, SCREEN_WIDTH*3/8, 200, SCREEN_WIDTH/4, 56);
    choices[1].set_Text("Menu", WHITE_COLOR, SCREEN_WIDTH*7/16, 300 - 24, SCREEN_WIDTH/8, 56);
    choices[2].set_Text("Exit", WHITE_COLOR, SCREEN_WIDTH*7/16, 400 - 48, SCREEN_WIDTH/8, 56);
    for (int i=0;i<3;i++)
        choices[i].create_Text_texture(choice_font, renderer);
    SDL_RenderPresent(renderer);
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e)) {
            SDL_Delay(100);
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int xm = e.button.x, ym = e.button.y;
                for (int i=0;i<3;i++) {
                    if (check_select(xm, ym, choices[i]))
                        return i;
                }
            } else if (e.type == SDL_QUIT)
                return EXIT;
        }
    }
}

void new_game(SDL_Renderer *renderer, Game &game) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) game.board[i][j]=EMPTY;
    }
    game.player = X;
    game.state = RUNNING;
    load_background(renderer);
    draw_board(renderer);
}

void reset_game(SDL_Renderer *renderer, Game &game) {
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    new_game(renderer, game);
}

void click_on_cell(Game &game, SDL_Renderer *renderer, SDL_Texture *texture, int row, int col) {
    if (game.state == RUNNING) {
        if (game.board[row][col] == EMPTY) {
            game.board[row][col] = game.player;
            draw_cells(renderer, texture, game.board);
            switch_player(game);
        }
    }
}

void switch_player (Game &game) {
    if (game.player == X) game.player = O;
    else game.player = X;
}

void load_background(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/background.jfif");
    SDL_Texture* background = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(background);
}

void draw_board(SDL_Renderer *renderer) {
    setColor(renderer, BLACK_COLOR);
    for (int i=1;i<=3;i++) {
        SDL_RenderDrawLine(renderer, i*CELLWIDTH, 0, i*CELLWIDTH, SCREEN_HEIGHT);
        SDL_RenderDrawLine(renderer, 0, i*CELLWIDTH, SCREEN_HEIGHT, i*CELLWIDTH);
    }
}

void draw_cells(SDL_Renderer *renderer, SDL_Texture *texture, int board[3][3]) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            switch (board[i][j]) {
                case X:
                    draw_X(renderer, texture, i*CELLWIDTH, j*CELLWIDTH, CELLWIDTH, CELLWIDTH);
                    break;
                case O:
                    draw_O(renderer, texture, i*CELLWIDTH, j*CELLWIDTH, CELLWIDTH, CELLWIDTH);
                    break;
                default: {}
            }
        }
    }
    SDL_DestroyTexture(texture);
}

void draw_X(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Surface *buf = IMG_Load("image/X.png");
    texture = SDL_CreateTextureFromSurface(renderer, buf);
    renderTexture(renderer, texture, x, y, w, h);
    SDL_FreeSurface(buf);
}

void draw_O(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Surface *buf = IMG_Load("image/O.png");
    texture = SDL_CreateTextureFromSurface(renderer, buf);
    renderTexture(renderer, texture, x, y, w, h);
    SDL_FreeSurface(buf);
}

int check_win(int board[3][3]) {
    for (int i=0;i<3;i++) {
        if (board[i][0]>0 && (board[i][0]==board[i][1]) && (board[i][0]==board[i][2]))
            return board[i][0];
        if (board[0][i]>0 && (board[0][i]==board[1][i]) && (board[0][i]==board[2][i]))
            return board[0][i];
    }
    if (board[0][0]>0 && (board[0][0]==board[1][1]) && (board[0][0]==board[2][2]))
        return board[0][0];
    if (board[0][2]>0 && (board[0][2]==board[1][1]) && (board[0][2]==board[2][0]))
        return board[0][2];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[i][j] == 0) return RUNNING;
        }
    }
    return TIE;
}

int game_state (SDL_Renderer* renderer, Game &game) {
    if (game.state == RUNNING) return 1;
    SDL_Delay(1000);
    SDL_RenderClear(renderer);
    load_background(renderer);
    TTF_Font *state_font = TTF_OpenFont("font/ChocoChici-2OMyW.ttf", 90);
    if (game.state == X_WIN)
        X_win_state(renderer, state_font);
    else if (game.state == O_WIN)
        O_win_state(renderer, state_font);
    else if (game.state == TIE)
        tie_state(renderer, state_font);
    SDL_Delay(3000);
    int choice = game_menu(renderer);
    if (choice == 0) reset_game(renderer, game);
    return choice;
    //SDL_RenderPresent(renderer);
}

void X_win_state (SDL_Renderer* renderer, TTF_Font* font) {
    Text text_X;
    text_X.set_Text("X  WIN", RED_COLOR, SCREEN_WIDTH/4, SCREEN_HEIGHT/2 - 50, SCREEN_WIDTH/2, 100);
    text_X.create_Text_texture(font, renderer);
    SDL_RenderPresent(renderer);
}

void O_win_state (SDL_Renderer* renderer, TTF_Font* font) {
    Text text_O;
    text_O.set_Text("O  WIN", BLUE_COLOR, SCREEN_WIDTH/4, SCREEN_HEIGHT/2 - 50, SCREEN_WIDTH/2, 100);
    text_O.create_Text_texture(font, renderer);
    SDL_RenderPresent(renderer);
}

void tie_state (SDL_Renderer* renderer, TTF_Font* font) {
    Text text_tie;
    text_tie.set_Text("TIE", GREY_COLOR, SCREEN_WIDTH/4, SCREEN_HEIGHT/2 - 50, SCREEN_WIDTH/2, 100);
    text_tie.create_Text_texture(font, renderer);
    SDL_RenderPresent(renderer);
}
