class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int wordSize=word.size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        // vector<vector<int>>vis1(n,vector<int>(m,0));
        // vector<int>vis2(wordSize,0);
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]==word[0]){
                    if(dfs(board,i,j,0,word,dr,dc,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>&board,int row,int col,int index,string word,int dr[],int dc[],int n,int m){
       if(index>=word.size()-1) return true;
       
        char ch=board[row][col];
        board[row][col]='#';

        for (int i=0;i<4;i++){
            int newr=row+dr[i];
            int newc=col+dc[i];
            if (newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]==word[index+1]){
                if(dfs(board,newr,newc,index+1,word,dr,dc,n,m))return true;
            }
        }
        
        board[row][col]=ch;
        

        return false;
        
    }


};