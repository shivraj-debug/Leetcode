class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='.') continue;

                if(!valid(i,j,n,m,board)){
                    return false;
                }
            }
        }

        return true;
    }

    bool valid(int row,int col,int n,int m,vector<vector<char>>& board){
        int x=board[row][col];

        for(int i=0;i<m;i++){
            if(i==col) continue;
                if(board[row][i]==x) return false;
        }
        for(int i=0;i<n;i++){
            if(i==row) continue;
                if(board[i][col]==x) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int r = startRow + i;
                int c = startCol + j;
                if (r == row && c == col) continue;
                if (board[r][c] == x) return false;
            }
        }
        
        return true;

    }
};