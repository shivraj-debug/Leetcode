class Solution {
public:

    vector<vector<int>> dp;

    bool isPalindrome(int i,int j,string& s){
        if(i>=j){
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=isPalindrome(i+1,j-1,s);
        }

        return dp[i][j]=false;
    }

    string longestPalindrome(string s) {
       int maxLen=INT_MIN;
       int idx;

       dp.assign(s.size(),vector<int>(s.size(),-1));

       for(int i=0;i<s.size();i++){
           for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                // maxLen=max(maxLen,j-i+1);
                if(maxLen<j-i+1){
                    maxLen=j-i+1;
                    idx=i;
                }
            }
          }
       }

       return s.substr(idx,maxLen);
    }
};