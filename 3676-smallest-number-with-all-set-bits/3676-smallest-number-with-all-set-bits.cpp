class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;

        // Keep doubling x until (x - 1) >= n
        while ((x - 1) < n) {
            x <<= 1; // same as x = x * 2
        }

        return x - 1;
    }
};
