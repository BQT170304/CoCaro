#include "one_player.h"

// Player: +10, Bot: -10, Tie: 0
int scores[4] = {0, 10, -10, 0};
int pos[2];
int depth = 8;
bool easy = false;


int minimax(int board[3][3], int depth, int mx, int mn, bool isMaximize) {
    if (depth==0 || check_win(board)!=RUNNING) {
        return scores[check_win(board)];
    }
    if (isMaximize) {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = X;
                    int score = minimax(board, depth-1, mx, mn, false);
                    board[i][j] = EMPTY;
                    if (score > mx) {
                        mx = score;
                    }
                }
                if (mx >= mn) break;
            }
        }
        return mx;
    }
    else {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = O;
                    int score = minimax(board, depth-1, mx, mn, true);
                    board[i][j] = EMPTY;
                    if (score < mn) {
                        mn = score;
                        pos[0] = i; pos[1] = j;
                    }
                }
                if (mx >= mn) break;
            }
        }
        return mn;
    }
}

void bot_move(Game &game, SDL_Renderer* renderer) {
    if (easy) {
        srand(time(NULL));
        int cell = 0;
        while (game.board[cell/3][cell%3] != EMPTY
               && empty_cells(game)!=0) {
            cell = rand()%9;
        }
        click_on_cell(game, renderer, cell/3, cell%3);
    }
    else {
        int bestMove = minimax(game.board, depth, -100, 100, false);
        click_on_cell(game, renderer, pos[0], pos[1]);
    }
}

int difficulty(SDL_Renderer* renderer, Game &game) {
    load_start_background(renderer);
    SDL_Surface *buf = IMG_Load("image/arrow.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, buf);
    renderTexture(renderer, texture, 10, 20, ARROW_WIDTH, ARROW_HEIGHT);
    TTF_Font *choice_font = TTF_OpenFont("font/MangataRegular-ZVBaK.ttf", 40);
    Text choices[3];
    choices[0].set_Text("EASY", WHITE_COLOR, SCREEN_WIDTH*3/8, 200, SCREEN_WIDTH/4, 48);
    choices[1].set_Text("MEDIUM", WHITE_COLOR, SCREEN_WIDTH*5/16, 300, SCREEN_WIDTH*3/8, 48);
    choices[2].set_Text("HARD", WHITE_COLOR, SCREEN_WIDTH*3/8, 400, SCREEN_WIDTH/4, 48);
    for (int i=0;i<3;i++)
        choices[i].create_Text_texture(choice_font, renderer);
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(buf);
    SDL_DestroyTexture(texture);
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int xm = e.button.x, ym = e.button.y;
                if (check_select(xm, ym, 0, 0, ARROW_WIDTH, ARROW_HEIGHT))
                    return start_menu(renderer, game);
                for (int i=0;i<3;i++) {
                    if (check_select(xm, ym, choices[i])) {
                        if (i==1) {
                            scores[3] = 0;
                            depth = 2;
                        }
                        else if (i==2) {
                            scores[3] = -10;
                            depth = 8;
                        }
                        if (i==0) easy = true;
                        else easy = false;
                        new_game(renderer, game);
                        return ONE_PLAYER;
                    }
                }
            } else if (e.type == SDL_QUIT)
                return EXIT;
        }
    }
}

