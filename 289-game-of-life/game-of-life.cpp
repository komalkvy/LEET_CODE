class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> directions = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
        int m = board.size();
        int n = board[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                int ones_cnt = 0;
                for(auto dir : directions){
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                        if(board[nr][nc] == 1 || board[nr][nc] == -1) ones_cnt++;
                    }
                }
                if(board[r][c] == 0 && ones_cnt == 3){
                    board[r][c] = 2; // 2: dead -> live
                }
                else if(board[r][c] == 1 && (ones_cnt < 2 || ones_cnt > 3)){
                    board[r][c] = -1; // -1: live -> dead
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};