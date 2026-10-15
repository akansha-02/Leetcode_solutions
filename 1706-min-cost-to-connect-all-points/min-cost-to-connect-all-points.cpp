class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> visited(n,false);
        vector<int> minDis(n,INT_MAX);

        minDis[0]=0;
        int totalCost=0;

        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!visited[j] && (u==-1 || minDis[j]<minDis[u])){
                    u=j;
                }
            }

            visited[u]=true;
            totalCost+=minDis[u];

            for(int v=0;v<n;v++){
                if(!visited[v]){
                    int distance= abs(points[u][0]-points[v][0])+ abs(points[u][1]-points[v][1]);

                    minDis[v] = min(minDis[v], distance);
                }
            }
        }
        return totalCost;
    }
};