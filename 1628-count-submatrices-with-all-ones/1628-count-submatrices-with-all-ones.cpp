class Solution {
public:
    int n,m;
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int res=0;

        vector<vector<int>> mp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            int c=0;
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    c++;
                }else{
                    c=0;
                }
                mp[i][j]=c;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=INT_MAX;
                for(int k=i;k<n;k++){
                    x=min(x,mp[k][j]);
                    res+=x;
                }
            }
        }
    
        return res;
    }
};