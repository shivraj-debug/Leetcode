#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, totalSum;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int idx, int currSum, int target) {
        if (idx == n) {
            return (currSum == target) ? 1 : 0;
        }

        int offset = totalSum;
        int dpIdx = currSum + offset;

        if (dp[idx][dpIdx] != -1) 
            return dp[idx][dpIdx];

        // Add current number
        int add = solve(nums, idx + 1, currSum + nums[idx], target);

        // Subtract current number
        int subtract = solve(nums, idx + 1, currSum - nums[idx], target);

        return dp[idx][dpIdx] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is out of possible range, return 0 directly
        if (abs(target) > totalSum) return 0;

        int width = 2 * totalSum + 1; // sum range [-totalSum, totalSum]
        dp.assign(n, vector<int>(width, -1));

        return solve(nums, 0, 0, target);
    }
};


