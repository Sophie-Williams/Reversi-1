const int row = 8;
const int column = 8;
const int BLACK = -1;
const int WHITE = 1;
const int EMPTY = 0;
const int TIE = 0;
const int direction = 8;
const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, -1, 0, 1, -1, 0, 1};

class ChessBoard {
    public:
        int disks[row][column];
        int black;
        int white;

        ChessBoard();
        ChessBoard(const ChessBoard &chessBoard);
        void initialize();
        void statistic();
        void print();
        bool isEnd();
        int play(int x, int y, int player, bool place);
        int getWinner();
        int nextPlayer();
        
    
    private:
        int lastPlayer;

        bool isPlayable(int x, int y, int player);
};
