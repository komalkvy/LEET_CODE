class Solution {
private:
    void rowFliper(vector<vector<int>>& grid, int row) {
        for (int i = 0; i < grid[0].size(); i++) {
            grid[row][i] = !grid[row][i];
        }
    }

    void colFliper(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); i++) {
            grid[i][col] = !grid[i][col];
        }
    }

public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                rowFliper(grid, i);
            }
        }

        
        for (int j = 1; j < m; j++) {  
            int countZero = 0, countOne = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 0) countZero++;
                else countOne++;
            }
            if (countZero > countOne) {
                colFliper(grid, j);
            }
        }
 
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int rowValue = 0;
            for (int j = 0; j < m; j++) {
                rowValue = (rowValue << 1) | grid[i][j];
            }
            sum += rowValue;
        }

        return sum;
    }
};