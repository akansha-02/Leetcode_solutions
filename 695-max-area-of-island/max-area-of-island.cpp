class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int maxArea=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    grid[i][j]=0;

                    int area=0;

                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        area++;
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];

                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                                grid[nr][nc]=0;
                                q.push({nr,nc});
                            }
                        }
                    }
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};