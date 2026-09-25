class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto &p:points){
            int x=p[0];
            int y=p[1];
            int dist=x*x + y*y;
            pq.push({dist,{x,y}});

            if(pq.size()>k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            ans.push_back({p.second.first,p.second.second});
        }
        return ans;
    }
};