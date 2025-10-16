class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

        // Step 1: Reduce each number to its modulo (0 to value-1)
        for (int num : nums) {
            int r = ((num % value) + value) % value; // handles negatives correctly
            freq[r]++;
        }

        // Step 2: Find the MEX (minimum excluded)
        int x = 0;
        while (true) {
            int r = x % value;
            if (freq[r] == 0) {
                return x;
            }
            freq[r]--; // "use up" one occurrence of this remainder
            x++;
        }

        return -1; // theoretically unreachable
    }
};
