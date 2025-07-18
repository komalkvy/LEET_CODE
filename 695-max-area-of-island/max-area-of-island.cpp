#define ll long long
class DSU {
private :
    vector<ll> parent, size, edge;
public :
    DSU(ll n) {
        parent.resize(n + 1); size.assign(n + 1, 1);
        edge.assign(n+1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            parent[y] = x; size[x] += size[y];
            edge[x] += edge[y] + 1;
        } else { edge[x]++; }
    }
    ll componentCount(ll n) {
        ll count = 0;
        for(ll i=1;i<=n;i++) { if(find(i) == i) count++; }
        return count;
    }
    bool isSame(ll x, ll y) { return find(x) == find(y); }
    ll getSize(ll x) { return size[find(x)]; }
    ll getEdgeCount(ll x) { return edge[find(x)]; }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ll mx=0;
        int n=grid.size();
        int m=grid[0].size();
        DSU ds(n*m);
        vector<pair<ll,ll>>move={{1,0},{0,1},{-1,0},{0,-1}};
        bool f1=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f1=false;
                    for(int k=0;k<4;k++){
                        ll xf=move[k].first+i;
                        ll yf=move[k].second+j;
                        if(xf<n && yf<m && xf>=0 && yf>=0 && grid[xf][yf]==1 && ds.find(i*m +j+1)!=ds.find(xf*m + yf+1)){
                            ds.unite(i*m +j+1,xf*m + yf+1);
                        }
                    }
                }
            }
        }
        for(int i=0;i<=n*m;i++){
            mx=max(mx,ds.getSize(i));
        }
        if(mx==1 && f1){return 0;}
        return mx;
    }
};