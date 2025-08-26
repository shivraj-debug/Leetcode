class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // balanced BST
        for (int i = 0; i < nums.size(); i++) {
            // Find the smallest number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
            if (window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};
