class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++; indeg[e[1]]++;
        }
        queue<int> q;
        vector<int> ans;

        // inserting leaves to queue
        for(int i=0;i<n;i++)if(indeg[i]<=1)q.push(i); 

        while(n>2){ // the n becomes nodes left to process
            int z=q.size();
            n-=z;   // removing node that will be processed in this round
            while(z--){
                int node=q.front();
                q.pop();
                for(auto& child:adj[node]){
                    indeg[child]--;
                    if(indeg[child]==1)q.push(child); // new leaves
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};