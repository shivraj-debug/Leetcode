class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        vector<int> ans;
        int maxlen = 1, ind = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
            if(dp[i]>=maxlen) {
                maxlen = dp[i];
                ind = i;
            }
        }

        for(int i = ind; i >= 0;) {
            ans.push_back(nums[i]);
            i = prev[i];
        }

        return ans;
    }

};