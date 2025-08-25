class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0;
        int j=0;

        int n=mat.size();
        int m=mat[0].size();

        vector<int> ans;

        bool ulta=false;

        while(i<n && j<m){
            vector<int> temp;

            int k=i;
            int l=j;

            while(k>=0 && l<m){
                temp.push_back(mat[k][l]);
                k--;
                l++;
            }

           if(ulta) reverse(temp.begin(),temp.end());

            for(auto& val:temp){
                ans.push_back(val);
            }

            if(i+1<n){
                i++;
            }else{
                j++;
            }

            ulta=!ulta;
        }

        return ans;
    }
};