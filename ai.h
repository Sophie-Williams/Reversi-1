class AI {
    public:
        int player;

        void play();
        AI();
        AI(ChessBoard *chess, const int player);

    private:
        ChessBoard *chess;

        bool checkCorners();
        bool checkEdges();
};
