class Solution {
public:
    
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        dp.resize(n+2,vector<int>(n+2,-1));

        return solve(1,n,nums);
    }

    int solve(int left,int right,vector<int>& nums){
        if(left>right) return 0;

        if(dp[left][right]!=-1) return dp[left][right];

        int maxcoins=0;

        for(int i=left;i<=right;i++){
            int coins=nums[left-1]*nums[i]*nums[right+1];

            coins+=solve(left,i-1,nums);
            coins+=solve(i+1,right,nums);

            maxcoins=max(coins,maxcoins);

        }

        return dp[left][right]=maxcoins;
    }
};