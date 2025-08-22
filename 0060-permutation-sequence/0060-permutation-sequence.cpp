class Solution {
public:
    string getPermutation(int n, int k) {
       vector<int> temp;
       for(int i=1;i<=n;i++){
         temp.push_back(i);
       }

       for(int i=0;i<k-1;i++){
          next_permutation(temp.begin(),temp.end());
       }

       string res="";

       for(auto& it:temp){
            res+=('0'+it);
       }

       return res;
    }
};