class Solution {
public:

    vector<int> dp;
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
       return  minJumps(nums,0);
         
    }

    int minJumps(vector<int>& nums, int position) {
    
        if (position >= nums.size() - 1) return 0;

        if (nums[position] == 0) return INT_MAX;

        if(dp[position]!=-1) return dp[position];

        int minStep = INT_MAX;

        for (int jump = 1; jump <= nums[position]; ++jump) {
            int subResult = minJumps(nums, position + jump);

            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return dp[position]=minStep;
    }
};