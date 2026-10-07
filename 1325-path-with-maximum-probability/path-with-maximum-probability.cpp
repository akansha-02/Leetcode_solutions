class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> prob(n,0.0);
        prob[start_node]=1.0;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto[currProb,node]=pq.top();
            pq.pop();

            if(node==end_node)
                return currProb;

            if(currProb<prob[node])
                continue;
            
            for(auto [next,edgeProb] : adj[node]){
                double newProb=currProb*edgeProb;

                if(newProb>prob[next]){
                    prob[next]=newProb;
                    pq.push({newProb,next});
                }      
            }
        }
        return 0.0;
    }
};