class Solution {
public:
    int climbStairs(int n) {
        vector<int> mp(n+1,-1);
        return helper(n,mp);
    }
    int helper(int n , vector<int> &mp){
        if (n==0 || n==1) return 1;
            
        if(mp[n]!=-1) return mp[n];
        
        return mp[n] =  helper(n-1 ,mp) + helper(n-2 , mp);

    }
};