#include "one_player.h"

int attack[6] = {0, 3, 24, 192, 1536, 12288};
int defense[6] = {0, 1, 9, 81, 729, 6534};
int pos[2];
bool easy = false;

int getAtkScore(int board[N][N], pair<int,int> cur_move) {
    int score = 0;
    // Ngang
    int cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first][i]==O)
            cntO++;
        else if (board[cur_move.first][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first][i]==O)
            cntO++;
        else if (board[cur_move.first][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    if (!(cntO<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += (attack[cntO] - defense[cntX+1]);

    //Doc
    cntX = 0, cntO = 0;
    for (int i=cur_move.first-1;i>=0;i--) {
        if (board[i][cur_move.second]==O)
            cntO++;
        else if (board[i][cur_move.second]==X) {
            cntX++;
            break;
        }
        else break;
    }
    for (int i=cur_move.first+1;i<N;i++) {
        if (board[i][cur_move.second]==O)
            cntO++;
        else if (board[i][cur_move.second]==X) {
            cntX++;
            break;
        }
        else break;
    }
    if (!(cntO<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += (attack[cntO] - defense[cntX+1]);

    // Cheo chinh
    cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first+(i-cur_move.second)][i]==O)
            cntO++;
        else if (board[cur_move.first+(i-cur_move.second)][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first+(i-cur_move.second)][i]==O)
            cntO++;
        else if (board[cur_move.first+(i-cur_move.second)][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    if (!(cntO<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += (attack[cntO] - defense[cntX+1]);

    // Cheo phu
    cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first-(i-cur_move.second)][i]==O)
            cntO++;
        else if (board[cur_move.first-(i-cur_move.second)][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first-(i-cur_move.second)][i]==O)
            cntO++;
        else if (board[cur_move.first-(i-cur_move.second)][i]==X) {
            cntX++;
            break;
        }
        else break;
    }
    if (!(cntO<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += (attack[cntO] - defense[cntX+1]);
    return score;
}

int getDefScore(int board[N][N], pair<int,int> cur_move) {
    int score = 0;
    // Ngang
    int cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first][i]==X)
            cntX++;
        else if (board[cur_move.first][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first][i]==X)
            cntX++;
        else if (board[cur_move.first][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    if (!(cntX<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += defense[cntX];
    if (cntO!=0 && cntX>=3)
        score -= attack[cntO];

    //Doc
    cntX = 0, cntO = 0;
    for (int i=cur_move.first-1;i>=0;i--) {
        if (board[i][cur_move.second]==X)
            cntX++;
        else if (board[i][cur_move.second]==O) {
            cntO++;
            break;
        }
        else break;
    }
    for (int i=cur_move.first+1;i<N;i++) {
        if (board[i][cur_move.second]==X)
            cntX++;
        else if (board[i][cur_move.second]==O) {
            cntO++;
            break;
        }
        else break;
    }
    if (!(cntX<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += defense[cntX];
    if (cntO!=0 && cntX>=3)
        score -= attack[cntO];

    // Cheo chinh
    cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first+(i-cur_move.second)][i]==X)
            cntX++;
        else if (board[cur_move.first+(i-cur_move.second)][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first+(i-cur_move.second)][i]==X)
            cntX++;
        else if (board[cur_move.first+(i-cur_move.second)][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    if (!(cntX<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += defense[cntX];
    if (cntO!=0 && cntX>=3)
        score -= attack[cntO];

    // Cheo phu
    cntX = 0, cntO = 0;
    for (int i=cur_move.second-1;i>=0;i--) {
        if (board[cur_move.first-(i-cur_move.second)][i]==X)
            cntX++;
        else if (board[cur_move.first-(i-cur_move.second)][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    for (int i=cur_move.second+1;i<N;i++) {
        if (board[cur_move.first-(i-cur_move.second)][i]==X)
            cntX++;
        else if (board[cur_move.first-(i-cur_move.second)][i]==O) {
            cntO++;
            break;
        }
        else break;
    }
    if (!(cntX<4 && (cur_move.first==0 || cur_move.first==N-1 || cur_move.second==0 || cur_move.second==N-1)))
        score += defense[cntX];
    if (cntO!=0 && cntX>=3)
        score -= attack[cntO];
    return score;
}

void bot_move(Game &game, SDL_Renderer* renderer) {
    int x = game.cur_move.first, y = game.cur_move.second;
    if (empty_cells(game.board)==N*N-1) {
        if (x<N/2 && y<N/2) click_on_cell(game, renderer, x+1, y+1);
        else if (x<N/2 && y>=N/2) click_on_cell(game, renderer, x+1, y-1);
        else if (x>=N/2 && y<N/2) click_on_cell(game, renderer, x-1, y+1);
        else click_on_cell(game, renderer, x-1, y-1);
        return;
    }
    if (easy) {
        srand(time(NULL));
        int dx = rand()%3 - 1;
        int dy = rand()%3 - 1;
        while (game.board[x+dx][y+dy] != EMPTY
               && empty_cells(game.board)!=0) {
            dx = rand()%3 - 1;
            dy = rand()%3 - 1;
        }
        click_on_cell(game, renderer, x+dx, y+dy);
    }
    else {
        int max_score = 0;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (game.board[i][j]==EMPTY) {
                    int atk_score = getAtkScore(game.board, {i,j});
                    if (i==0 || i==N-1 || j==0 || j==N-1)
                        atk_score /= 2;
                    int def_score = getDefScore(game.board, {i,j});
                    int tmp_score = max(atk_score, def_score);
                    if (tmp_score>max_score) {
                        max_score = tmp_score;
                        pos[0] = i; pos[1] = j;
                    }
                }
            }
        }
        click_on_cell(game, renderer, pos[0], pos[1]);
    }
}

int difficulty(SDL_Renderer* renderer, Game &game) {
    load_start_background(renderer);
    SDL_Surface *buf = IMG_Load("image/arrow.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, buf);
    renderTexture(renderer, texture, 10, 20, ARROW_WIDTH, ARROW_HEIGHT);
    TTF_Font *choice_font = TTF_OpenFont("font/MangataRegular-ZVBaK.ttf", 40);
    Text choices[2];
    choices[0].set_Text("EASY", WHITE_COLOR, SCREEN_WIDTH*3/8, 225, SCREEN_WIDTH/4, 48);
    choices[1].set_Text("HARD", WHITE_COLOR, SCREEN_WIDTH*3/8, 350, SCREEN_WIDTH/4, 48);
    for (int i=0;i<2;i++)
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

