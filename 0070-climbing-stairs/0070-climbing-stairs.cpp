class Solution {
public:
    int climbStairs(int n) {
        vector<int> mp(n+1,0);

        mp[0]=1;
        mp[1]=1;

        for(int i=2;i<=n;i++){
            mp[i]=mp[i-1]+mp[i-2];
        }

        return mp[n];
        
    }
    int helper(int n , vector<int> &mp){
        if (n==0 || n==1) return 1;
            
        if(mp[n]!=-1) return mp[n];
        
        return mp[n] =  helper(n-1 ,mp) + helper(n-2 , mp);

    }
};