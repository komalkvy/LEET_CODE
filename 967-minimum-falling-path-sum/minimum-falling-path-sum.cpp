class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: first row same as matrix
        for (int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int down = dp[row-1][col];
                int left=INT_MAX,right=INT_MAX;
                if(col > 0){
                left = dp[row-1][col-1] ;
                }
                if(col < n-1){
                right =dp[row-1][col+1] ;
                }  

                dp[row][col] = matrix[row][col] + min({down, left, right});
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};