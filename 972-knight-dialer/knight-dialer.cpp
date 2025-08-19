class Solution {
public:
    const int MOD = 1e9 + 7;

private:
    int solve(int n, map<int, vector<int>> &mp, int node, vector<vector<int>> &dp){
        if (n == 1) return 1;
        if (dp[n][node] != -1) return dp[n][node];

        int res = 0;
        for (auto &child : mp[node]){
            res = (res + solve(n - 1, mp, child, dp)) % MOD;
        }

        return dp[n][node] = res;
    }

public:
    int knightDialer(int n) {
        map<int, vector<int>> mp;
        mp[0] = {4,6};
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,3,9};
        mp[5] = {}; 
        mp[6] = {0,1,7};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {2,4};

        vector<vector<int>> dp(n+1, vector<int>(10, -1));
        int ans = 0;

        for (int i = 0; i <= 9; i++) {
            ans = (ans + solve(n, mp, i, dp)) % MOD;
        }

        return ans;
    }
};