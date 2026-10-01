class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r ,int c){
        int m=heights.size();
        int n=heights[0].size();

        visited[r][c]=true;

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            if(visited[nr][nc]) continue;
            if(heights[nr][nc]<heights[r][c]) continue;
            dfs(heights,visited,nr,nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        //Pacific top row
        for(int j=0;j<n;j++) 
            dfs(heights,pacific,0,j);

        //Pacific left column
        for(int i=0;i<m;i++)
            dfs(heights,pacific,i,0);

        //Atlantic bottom row
        for(int j=0;j<n;j++)
            dfs(heights,atlantic,m-1,j);

        //Atlantic right column
        for(int i=0;i<m;i++)
            dfs(heights,atlantic,i,n-1);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
}; 