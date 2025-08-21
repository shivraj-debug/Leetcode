class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         rec(board);
    }

    bool rec(vector<vector<char>>& board){
       
       for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char num='1';num<='9';num++){
                        if(valid(row,col,num,board)){
                            board[row][col]=num;
                            if(rec(board)) return true;
                            board[row][col]='.';
                        }
                    }

                    return false;
                }

            }
       }    

       return true;   
    }

    bool valid(int row,int col,char num,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==num || board[i][col]==num) return false;
        }

        int startrow=(row/3)*3;
        int startcol=(col/3)*3;

        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==num) return false;
            }
        }

        return true;
    }

};