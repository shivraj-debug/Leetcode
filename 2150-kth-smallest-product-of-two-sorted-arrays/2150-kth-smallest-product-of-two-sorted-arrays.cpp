class Solution {
public:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        long long count = 0;
        int n = nums2.size();

        for (int a : nums1) {
            if (a > 0) {
                // Count how many nums2[j] such that a * nums2[j] <= x
                int l = 0, r = n - 1, pos = -1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if ((long long)a * nums2[m] <= x) {
                        pos = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                count += pos + 1;
            } else if (a < 0) {
                // a * nums2[j] <= x --> nums2[j] >= ceil(x / a)
                int l = 0, r = n - 1, pos = n;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if ((long long)a * nums2[m] <= x) {
                        pos = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                count += n - pos;
            } else {
                // a == 0
                if (x >= 0) count += n;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long count = countLessEqual(nums1, nums2, mid);
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
