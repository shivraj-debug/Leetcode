class Solution {
public:

  vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int n,m;

    class Trie{
        public:
        Trie* children[26];
        string word;

        Trie(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            word="";
        }
    };

    void maketrie(Trie* root,vector<string>& words){

        for(auto& word:words){
             Trie* temp=root;
            for(auto w:word){
                int ch=w-'a';

                if(!temp->children[ch]){
                    temp->children[ch]=new Trie();
                }
                temp=temp->children[ch];
            }

            temp->word=word;
        }
    }

    void dfs(int i,int j,Trie* root,vector<string>& res,vector<vector<char>>& board){
        char ch=board[i][j];

        Trie* nextnode=root->children[ch-'a'];

        if(!nextnode->word.empty()){
            res.push_back(nextnode->word);
            nextnode->word.clear();
        }

        board[i][j]='#';

        for(int k=0;k<4;k++){
            int row=i+dir[k][0];
            int col=j+dir[k][1];

            if(row>=0 && col>=0 && row<n && col<m && board[row][col]!='#' && nextnode->children[board[row][col]-'a']){
                dfs(row,col,nextnode,res,board);
            }
        }
        
        board[i][j]=ch;
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie();

        n=board.size();
        m=board[0].size();

        maketrie(root,words);

        vector<string> res;

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->children[board[i][j]-'a']){
                    dfs(i,j,root,res,board);
                }
            }
        }

        return res;

    }
};
