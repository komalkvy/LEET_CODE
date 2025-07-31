class Solution {
public:

    bool dfs(vector<int>& c, vector<vector<int>>& adj, int i, int color){
        c[i] = color;
        for(auto &x: adj[i]){
            if(c[x] == -1){
                if(!dfs(c, adj, x, 1-color)) return false;
            }
            else if(c[x] == c[i]){
                return false;
            }
        }
        return true;
    }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto x: dislikes){
            int from = x[0]-1;
            int to =x[1]-1;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        vector<int> c(n,-1);
        for(int i=0;i<n;i++){
            if(c[i] == -1){
                if(!dfs(c, adj, i, 0)) return false;
            }
        }
        return true;
    }
};