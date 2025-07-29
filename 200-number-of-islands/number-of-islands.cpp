class Solution {
private:
    void dfs(int i, int j, int row, int col, vector<vector<char>>& grid,vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> dist = {{0,1},{1,0},{-1,0},{0,-1}};
        visited[i][j] = true;
        q.push({i,j});
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(auto [dr,dc] : dist){ // for each val of dist 
                int newRow = r +dr;
                int newCol = c +dc;
                // check :
                // 1) 0 <= newRow < row  [check newRow is within bound ]
                // 2) 0 <= newCol < col [ same above reason ]
                // 3) !visited[newRow][newCol]  [check if same location is not visited]
                // 4) grid[newRow][newCol] == '1' [value at present postion should be '1' else we'll skip it]
                
                if( (0<= newRow && newRow < row) && (0<= newCol && newCol < col) && !visited[newRow][newCol] && grid[newRow][newCol] == '1'){
                    q.push({newRow,newCol});
                    visited[newRow][newCol]  = true;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(
            row, vector<bool>(col, false)); // 2d bool matrix
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, row, col, grid, visited);
                }
            }
        }
        return count;
    }
};