#include <iostream>
#include <cstring>
#include <cstdio>

#include "chessboard.h"
#include "ai.h"

using namespace std;

ChessBoard chess;

AI bot(&chess, BLACK);

int main() {
    int x, y;
    while (!chess.isEnd()) {
        int player = chess.nextPlayer();
        printf("=======White: %d, Black: %d, Player: %s=======\n", chess.white, chess.black, (player == WHITE) ? "White" : "Black");
        chess.print();
        if (player == BLACK) {
            bot.play();
        }
        else {
            scanf("%d%d", &x, &y);
            if (chess.play(x, y, player, true) == 0)
                printf("invalid play!\n");
        }
    }
    chess.statistic();
    if (chess.getWinner() == WHITE)
        printf("White(You) wins!\n");
    else if (chess.getWinner() == BLACK)
        printf("Black(AI) wins!\n");
    else
        printf("Tie!\n");
    return 0;
}
