class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        queue<pair<int,int>> q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        //push boundary '0' to the queue
        for(int i=0;i<m;i++){
            for(int j: {0,n-1}){
                if(board[i][j]=='O'){
                    board[i][j]='S';
                    q.push({i,j});
                }
            }
        }

        for(int j=0;j<n;j++){
            for(int i: {0,m-1}){
                if(board[i][j]=='O'){
                    board[i][j]='S';
                    q.push({i,j});
                }
            }
        }

        //bfs to find all safe cells
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O'){
                    board[nr][nc]='S';
                    q.push({nr,nc});
                }
            }
        }

        //capture surrounded O and change it to X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='S')
                    board[i][j]='O';
            }
        }
    }
};