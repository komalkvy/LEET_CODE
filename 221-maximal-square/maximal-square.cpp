class Solution {
public:
    int dfs(int i, int j, vector<vector<char>>& matrix,
            vector<vector<int>>& dp) {
                int m = matrix.size();
                int n = matrix[0].size();
                if((i>=m) || (j>=n) || (matrix[i][j] == '0')) return 0;

                if(dp[i][j] != -1) return dp[i][j];

                
                int right = dfs(i, j+1, matrix, dp);
                int down = dfs(i+1, j, matrix, dp);
                int cross = dfs(i+1,j+1, matrix, dp);
                
                
                int addTerm = min({right, down, cross});/*smtms right could be 2, down be 1, and cross could form 4 sized sqaure bur, from our cell we can only form min(1,2,4) i.e., 1 + 1 sized square since it has to be a square!!*/
                 

                return dp[i][j] = 1 + addTerm; 
                
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (matrix[i][j] == '1') {
                    maxLen = max(maxLen, dfs(i, j, matrix, dp));
                }
            }
        }

        return maxLen*maxLen;
    }
};