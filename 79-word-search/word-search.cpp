class Solution {
public:
    bool dfs(vector<vector<char>>& board,string& word, int r, int c, int index ){
        int m=board.size();
        int n=board[0].size();

        //word found
        if(index==word.size()) return true;
    
        //Invalid
        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!=word[index]) return false;

        //mark visited
        char temp=board[r][c];
        board[r][c]='#';

        //dfs
        bool found= dfs(board,word,r-1,c,index+1) ||
                    dfs(board,word,r+1,c,index+1) ||
                    dfs(board,word,r,c-1,index+1) ||
                    dfs(board,word,r,c+1,index+1);

        //backtrack
        board[r][c]=temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                   if(dfs(board,word,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};