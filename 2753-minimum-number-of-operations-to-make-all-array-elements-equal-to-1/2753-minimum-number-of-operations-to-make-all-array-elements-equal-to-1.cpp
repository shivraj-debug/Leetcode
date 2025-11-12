class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        // Case 1: If already have ones, only need to make others 1
        if (ones > 0) return n - ones;

        int minLen = INT_MAX;

        // Case 2: Find smallest subarray with GCD = 1
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        if (minLen == INT_MAX) return -1; // no subarray with gcd 1

        // total operations = (make 1) + (spread to all)
        return (minLen - 1) + (n - 1);
    }
};
