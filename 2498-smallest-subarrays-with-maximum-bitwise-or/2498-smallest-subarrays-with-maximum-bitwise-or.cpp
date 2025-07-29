class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> lastSeen(32, -1); // track last seen index of each bit

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastSeen[bit] = i;
                }
            }

            int maxLast = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    maxLast = max(maxLast, lastSeen[bit]);
                }
            }

            ans[i] = maxLast - i + 1;
        }

        return ans;
    }
};
