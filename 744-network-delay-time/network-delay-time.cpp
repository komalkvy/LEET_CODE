using p=pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n+1);
        for(auto e:times){//directed frm u to v only
        int u=e[0]; int v=e[1]; int wt=e[2];
            adj[u].push_back({v,wt});
            // adj[e[1]].push_back({e[0],e[2]});
        }
        const int INF=1e9;
        vector<int> dist(n+1,INF);//dist to each node
        //minheap
        priority_queue<p,vector<p>,greater<>> pq;//{time,node}
        dist[k]=0;//src node has 0 delay
        pq.push({0,k});//initially time=0 & start frm node= k
        while(!pq.empty()){
            auto [time,node]=pq.top(); pq.pop();
            if(time>dist[node]) continue;//skip if nto a better path
            for(auto &[v,w]:adj[node]){
//if new time to reach neigh v (time + w) is smaller than the prev dist[v], update it
                if(dist[v]>time+w){//store the min time
                    dist[v]=time+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int mintime=0;
        for(int i=1;i<=n;i++){//nodes labelled 1 to n
            if(dist[i]==INF) return -1; //if node i's time didnt change-unreachble
            mintime=max(mintime,dist[i]);
        }
        return mintime;
    }
};