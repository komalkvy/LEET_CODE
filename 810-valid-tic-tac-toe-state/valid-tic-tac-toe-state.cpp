class Solution {
public:
    bool win(vector<string>& b, char p) {
        for (int i = 0; i < 3; ++i){
            if ((b[i][0] == p && b[i][1] == p && b[i][2] == p) ||
                (b[0][i] == p && b[1][i] == p && b[2][i] == p))
                return true;
        }
        return (b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
               (b[0][2] == p && b[1][1] == p && b[2][0] == p); 
    }
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O = 0;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') ++X;
                else if (board[i][j] == 'O') ++O;
            }
        }
        if (O > X || X - O > 1) return false;
        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');
        if (xWin && oWin) return false;
        if (xWin && X != O + 1) return false;
        if (oWin && X != O) return false;
        return true;
    }
};