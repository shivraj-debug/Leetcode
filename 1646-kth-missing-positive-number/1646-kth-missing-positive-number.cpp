class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        // Binary search to find how many numbers are missing before arr[mid]
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Missing numbers before arr[mid] = arr[mid] - (mid + 1)
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1; // need to go right
            } else {
                right = mid - 1; // go left
            }
        }

        // After binary search:
        // `right` is the index of the last element where missing < k
        // kth missing = k + right + 1
        return k + right + 1;
    }
};
