//#include <cstdio>
//#include <cstring>
//#include <algorithm>

#include <cstdio>

#include "chessboard.h"
#include "ai.h"


const int corners = 4;
const int cornerX[] = {0, 0, row - 1, row - 1};
const int cornerY[] = {0, column - 1, 0, column - 1};

AI::AI() {
    chess = NULL;
    player = 0;
}

AI::AI(ChessBoard *chess, const int player) {
    this->chess = chess;
    this->player = player;
}

void AI::play() {
    if (checkCorners()) return;
    if (checkEdges()) return;

    int best = 0;
    int bestX, bestY;
    for (int x = 1; x < row - 1; ++ x)
        for (int y = 1; y < column - 1; ++ y) {
            int gain = chess->play(x, y, player, false);
            if (gain > best) {
                best = gain;
                bestX = x;
                bestY = y;
            }
        }
    chess->play(bestX, bestY, player, true);
}

bool AI::checkCorners() {
    int best = 0;
    int bestX, bestY;
    for (int i = 0; i < corners; ++ i) {
        int gain = chess->play(cornerX[i], cornerY[i], player, false);
        if (gain > best) {
            best = gain;
            bestX = cornerX[i];
            bestY = cornerY[i];
        }
    }
    if (best == 0) return false;

    chess->play(bestX, bestY, player, true);
    return true;
}

bool AI::checkEdges() {
    int x, y, gain;
    int best = 0;
    int bestX, bestY;

    for (x = 0; x < row; ++ x) {
        y = 0;
        gain = chess->play(x, y, player, false);
        if (gain > best) {
            best = gain;
            bestX = x; bestY = y;
        }

        y = column - 1;
        gain = chess->play(x, y, player, false);
        if (gain > best) {
            best = gain;
            bestX = x; bestY = y;
        }
    }

    for (y = 0; y < column; ++ y) {
        x = 0;
        gain = chess->play(x, y, player, false);
        if (gain > best) {
            best = gain;
            bestX = x; bestY = y;
        }

        x = row - 1;
        gain = chess->play(x, y, player, false);
        if (gain > best) {
            best = gain;
            bestX = x; bestY = y;
        }
    }

    if (best == 0) return false;

    chess->play(bestX, bestY, player, true);
    return true;
}
