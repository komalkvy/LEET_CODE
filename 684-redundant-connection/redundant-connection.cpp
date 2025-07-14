class DisjointSet {
public:
    vector<int> parent,size;
    DisjointSet(int n) {
        size.resize(n+1,1);
        parent.resize(n+1);
        for (int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node) {
        if (parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v) {
        int pu=findUPar(u);
        int pv=findUPar(v);
        if (pu==pv) return;
        if (size[pu]<size[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        vector<int> ans(2);
        for (auto i:edges){
            int u=ds.findUPar(i[0]);
            int v=ds.findUPar(i[1]);
            if (u==v) {
                ans[0]=i[0];
                ans[1]=i[1];
            }
            else ds.unionBySize(u,v);
        }
        return ans;
    }
};