class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, cnt_zero = 0;
        int maxi = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) cnt_zero++;

            // shrink window until we have at most 1 zero
            while (cnt_zero > 1) {
                if (nums[left] == 0) cnt_zero--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi - 1; // delete one element
    }
};
