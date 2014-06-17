#include <iostream>
#include <cstring>
#include <cstdio>

#include "chessboard.h"

using namespace std;

ChessBoard chess;

int main() {
    int x, y;
    while (!chess.isEnd()) {
        chess.print();
        int player = chess.nextPlayer();
        printf("next player = %d\n", player);
        scanf("%d%d", &x, &y);
        if (chess.play(x, y, player) == 0)
            printf("invalid play!\n");
    }
    chess.statistic();
    if (chess.getWinner() == chess.WHITE)
        printf("White wins!\n");
    else if (chess.getWinner() == chess.BLACK)
        printf("Black wins!\n");
    else
        printf("Tie!\n");
    return 0;
}
