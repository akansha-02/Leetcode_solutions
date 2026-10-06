class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //adjancency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        
        //source node
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto [next,wt]:adj[node]){
                if(d+wt<dist[next]){
                    dist[next]=d+wt;
                    pq.push({dist[next],next});
                }       
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};