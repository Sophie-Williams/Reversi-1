#include "chessboard.h"
#include <cstring>
#include <cstdio>

using namespace std;

const int ChessBoard::dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int ChessBoard::dy[] = {1, -1, -1, 0, 1, -1, 0, 1};

// WHITE first
ChessBoard::ChessBoard() {
    memset(disks, EMPTY, sizeof(disks));
    disks[3][3] = disks[4][4] = WHITE;     
    disks[3][4] = disks[4][3] = BLACK;

    lastPlayer = BLACK;
    black = white = 2;
}

void ChessBoard::initialize() {
    memset(disks, EMPTY, sizeof(disks));
    disks[3][3] = disks[4][4] = WHITE;     
    disks[3][4] = disks[4][3] = BLACK;

    lastPlayer = BLACK;
    black = white = 2;
}

void ChessBoard::statistic() {
    black = white = 0;
    for (int i = 0; i < row; ++ i)
        for (int j = 0; j < column; ++ j)
            if (disks[i][j] == BLACK)
                ++ black;
            else if (disks[i][j] == WHITE)
                ++ white;
    printf("White = %d, Black = %d\n", white, black);
}

// return 0, if game over
int ChessBoard::nextPlayer() {
    int next = -lastPlayer;
    for (int i = 0; i < row; ++ i)
        for (int j = 0; j < column; ++ j)
            if (isPlayable(i, j, next))
                return next;
    next = -next;
    for (int i = 0; i < row; ++ i)
        for (int j = 0; j < column; ++ j)
            if (isPlayable(i, j, next))
                return next;
    return 0;
}

bool ChessBoard::isEnd() {
    return (nextPlayer() == 0);
}

int ChessBoard::getWinner() {
    black = white = 0;
    for (int i = 0; i < row; ++ i)
        for (int j = 0; j < column; ++ j)
            if (disks[i][j] == BLACK)
                ++ black;
            else if (disks[i][j] == WHITE)
                ++ white;
    if (white > black)
        return WHITE;
    else if (white < black)
        return BLACK;
    else
        return TIE;
}

// return 0, if failed
int ChessBoard::play(int x, int y, int player) {
    if (!isPlayable(x, y, player)) return 0;

    int opponent = -player;

    for (int i = 0; i < direction; ++ i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        bool flag = false;
        while (nextX >= 0 && nextX < row && nextY >= 0 && nextY < column && disks[nextX][nextY] == opponent) {
            flag = true;
            nextX += dx[i];
            nextY += dy[i];
        }
        if (flag && nextX >= 0 && nextX < row && nextY >= 0 && nextY < column && disks[nextX][nextY] == player) {
            int xx = x;
            int yy = y;
            while (xx != nextX || yy != nextY) {
                disks[xx][yy] = player;
                xx += dx[i];
                yy += dy[i];
            }
        }
    }

    lastPlayer = player;

    return player;
}

void ChessBoard::print() {
    //printf("%d %d\n", row, column);
    //printf(" abcdefgh\n");
    printf(" 01234567\n");
    for (int i = 0; i < row; ++ i) {
        printf("%d", i);
        for (int j = 0; j < column; ++ j)
            if (disks[i][j] == BLACK)
                printf("-");
            else if (disks[i][j] == EMPTY)
                printf(" ");
            else
                printf("+");
        printf("\n");
    }
}

bool ChessBoard::isPlayable(int x, int y, int player) {
    if (x < 0 || x >= row) return false;
    if (y < 0 || y >= column) return false;
    if (disks[x][y] != EMPTY) return false;

    int opponent = -player;

    for (int i = 0; i < direction; ++ i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        bool flag = false;
        while (nextX >= 0 && nextX < row && nextY >= 0 && nextY < column && disks[nextX][nextY] == opponent) {
            flag = true;
            nextX += dx[i];
            nextY += dy[i];
        }
        if (flag && nextX >= 0 && nextX < row && nextY >= 0 && nextY < column && disks[nextX][nextY] == player)
            return true;
    }

    return false;
}
