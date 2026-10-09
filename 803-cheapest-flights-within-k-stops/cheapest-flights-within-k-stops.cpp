class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            int u=f[0];
            int v=f[1];
            int price=f[2];

            adj[u].push_back({v,price});
        }

        vector<int> dist(n,INT_MAX);
        queue<tuple<int,int,int>> pq;

        pq.push({0,src,0});
        dist[src]=0;

        while(!pq.empty()){
            auto[cost,node,stops]=pq.front();
            pq.pop();

            if(stops>k) continue;

            for(auto[next,price]:adj[node]){
                int newCost=cost+price;
                if(newCost<dist[next]){
                    dist[next]=newCost;
                    pq.push({newCost,next,stops+1});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};