class ChessBoard {
    public:
        static const int row = 8;
        static const int column = 8;
        static const int BLACK = -1;
        static const int WHITE = 1;
        static const int EMPTY = 0;
        static const int TIE = 0;
        static const int direction = 8;
        static const int dx[]; 
        static const int dy[];
       
        int disks[row][column];

        ChessBoard();
        void initialize();
        void statistic();
        void print();
        bool isEnd();
        int play(int, int, int);
        int getWinner();
        int nextPlayer();
        
    
    private:
        int lastPlayer;
        int black;
        int white;

        bool isPlayable(int, int, int);
};
