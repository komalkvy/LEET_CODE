class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<vector<int>> adj(n + 1);
        for (auto &d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        queue<int>q;
        vector<int> vis(n+1,-1);
        for(int i =1 ; i<=n ; i++){
            if(vis[i]==-1){
                q.push(i);vis[i]=0;
                while(!q.empty()){
                    int node = q.front();q.pop();
                    for(auto j:adj[node]){
                        if(vis[j]==-1){
                            vis[j]=1-vis[node];
                            q.push(j);
                        }
                        else if(vis[j]==vis[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};